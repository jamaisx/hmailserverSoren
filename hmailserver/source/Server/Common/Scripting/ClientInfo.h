// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com


#pragma once

namespace HM
{
   class ClientInfo  
   {
   public:
      ClientInfo();
      virtual ~ClientInfo();

      void SetIPAddress(const String &IP) { IPAddress = IP; }
      String GetIPAddress() const { return IPAddress; }

      void SetUsername(const String &sUsernme) { username_ = sUsernme; }
      String GetUsername() const { return username_; }

      void SetPort(long lNewVal) { port_ = lNewVal; }
      long GetPort() const { return port_; }

      void SetHELO(const String &HELO) { helo_ = HELO; }
      String GetHELO() const { return helo_; }

      void SetIsAuthenticated(bool bNewVal) { is_authenticated_ = bNewVal; };
      bool GetIsAuthenticated() const { return is_authenticated_; }

      void SetPasswd(const String &sPasswd) { passwd_ = sPasswd; }
      String GetPasswd() const { return passwd_; }

      void SetIsESMTP(bool bNewVal) { is_esmtp_ = bNewVal; };
      bool GetIsESMTP() const { return is_esmtp_; }

      void SetIsTLS(bool bNewVal) { is_tls_ = bNewVal; };
      bool GetIsTLS() const { return is_tls_; }

   private:

      String IPAddress;
      long port_;
      String username_;
      String helo_;
      bool is_authenticated_;
      String passwd_;
      bool is_esmtp_;
      bool is_tls_;
   };
}
