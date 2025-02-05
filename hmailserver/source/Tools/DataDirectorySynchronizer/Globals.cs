// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;

namespace DataDirectorySynchronizer
{
   class Globals
   {
      public enum ModeType
      {
         Import = 1,
         Delete = 2
      };

      public const string AllDomains = "All domains";

      public static ModeType Mode { get; set; }
      public static List<string> SelectedDomains { get; set; }

      private static hMailServer.Application _application;

        // PP aggiunto controllo elaborazione singolo account e dryrun
        public static string gCasella;
        public static bool gDryRun;

      static Globals()
      {
         SelectedDomains = new List<string>();
            // PP 
            gCasella = "";
            gDryRun = false;
      }

      public static void SetApp(hMailServer.Application application)
      {
         _application = application;
      }

      public static hMailServer.Application GetApp()
      {
         return _application;
      }



      public static hMailServer.eDBtype GetDatabaseType(string type)
      {
         switch (type)
         {
            case "MSSQL":
               return hMailServer.eDBtype.hDBTypeMSSQL;
            case "MySQL":
               return hMailServer.eDBtype.hDBTypeMySQL;
            case "PGSQL":
               return hMailServer.eDBtype.hDBTypePostgreSQL;
            default:
               throw new Exception("Unknown database type");

         }
      }


   }
}
