// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "ClamAVVirusScanner.h"
#include "AntiVirusConfiguration.h"

#include "../TCPIP/SynchronousConnection.h"
#include "../Util/ByteBuffer.h"

#include "../Application/TimeoutCalculator.h"

#include <Boost/Regex.hpp>
using namespace boost;


#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

namespace HM
{
   ClamAVVirusScanner::ClamAVVirusScanner(void)
   {
   }

   ClamAVVirusScanner::~ClamAVVirusScanner(void)
   {

   }

   VirusScanningResult 
   ClamAVVirusScanner::Scan(const String &sFilename)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   //---------------------------------------------------------------------------()
   {
      AntiVirusConfiguration& config = Configuration::Instance()->GetAntiVirusConfiguration();

      String hostName = config.GetClamAVHost();
      int primaryPort = config.GetClamAVPort();

      return Scan(hostName, primaryPort, sFilename);
   }

   VirusScanningResult
   ClamAVVirusScanner::Scan(const String &hostName, int primaryPort, const String &sFilename)
   {
      LOG_DEBUG("Connecting to ClamAV virus scanner...");

      TimeoutCalculator calculator;

      union
      {
         unsigned int integer;
         unsigned char byte[4];
      } foo;

      SynchronousConnection commandConnection(calculator.Calculate(IniFileSettings::Instance()->GetClamMinTimeout(), IniFileSettings::Instance()->GetClamMaxTimeout()));
      if (!commandConnection.Connect(hostName, primaryPort))
      {
         return VirusScanningResult(_T("ClamAVVirusScanner::Scan"), 
            Formatter::Format("Unable to connect to ClamAV server at {0}:{1}.", hostName, primaryPort));
      }

      LOG_DEBUG("Send the INSTREAM command.");
      if (!commandConnection.Write("nINSTREAM\n"))
         return VirusScanningResult("ClamAVVirusScanner::Scan", "Unable to write STREAM command.");

      // Send the file on the stream socket.
      File oFile;
      if (!oFile.Open(sFilename, File::OTReadOnly))
      {
         String sErrorMsg = Formatter::Format("Could not send file {0} via socket since it does not exist.", sFilename);
         return VirusScanningResult("ClamAVVirusScanner::Scan", sErrorMsg);
      }

      const int STREAM_BLOCK_SIZE = 4096;
      const int maxIterations = 100000;
      for (int i = 0; i < maxIterations; i++)
      {
         std::shared_ptr<ByteBuffer> pBuf = oFile.ReadChunk(STREAM_BLOCK_SIZE);

         if (!pBuf)
            break;

         int iInBufferSize = pBuf->GetSize();
         foo.integer = iInBufferSize;

         // Send the request.
         LOG_DEBUG(Formatter::Format("(loop #{0}) Send <length>(big endian, 4 bytes )" + iInBufferSize, i + 1));
         commandConnection.Write(to_string(foo.byte[3]) + to_string(foo.byte[2]) + to_string(foo.byte[1]) + to_string(foo.byte[0]));

         LOG_DEBUG(Formatter::Format("(loop #{0}) Send the chunk of data corresponding to the above length", i+1));
         commandConnection.Write(*pBuf);
      }

      foo.integer = 0;

      LOG_DEBUG("Send a 0 - length block to mark end of stream");
      commandConnection.Write(to_string(foo.byte[3]) + to_string(foo.byte[2]) + to_string(foo.byte[1]) + to_string(foo.byte[0]));

      AnsiString readData;
      LOG_DEBUG("Get response");
      if (!commandConnection.ReadUntil("\n", readData))
         return VirusScanningResult("ClamAVVirusScanner::Scan", "Unable to read response (after streaming).");

      readData.TrimRight("\n");
      LOG_DEBUG("Got response: " + readData);

      // Parse the response and see if a virus was reported.
      try
      {
         const regex expression("^stream.*: (.*) FOUND$"); 
         cmatch what; 
         if(regex_match(readData.c_str(), what, expression)) 
         {
            LOG_DEBUG("Virus detected: " + what[1]);
            return VirusScanningResult(VirusScanningResult::VirusFound, String(what[1]));
         }
         else
         {
            LOG_DEBUG("No virus detected: " + readData);
            return VirusScanningResult(VirusScanningResult::NoVirusFound, Formatter::Format("Result: {0}", readData));
         }
      }
      catch (std::runtime_error &) // regex_match will throw runtime_error if regexp is too complex.
      {
         return VirusScanningResult("ClamAVVirusScanner::Scan", "Unable to parse regular expression.");
      }

      
   }
}
