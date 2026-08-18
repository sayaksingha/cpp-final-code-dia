// @(#) $Id: aaa_log_facility.h,v 1.1.4.1.2.1.2.6 2019/01/21 22:16:12 anandhv Exp $
//---------------------------------------------------------------
// NAME : aaa_log_facility.h
//
// COPYRIGHT
// TSS : - Copyright (C) 2001 Tayana Software Solution Pvt Ltd.,
//         All rights reserved. No part of this computer program
//         may be used or reproduced in any form by any
//         means without prior written permission of
//         Tayana Software Solution Pvt Ltd.
//
// DESCRIPTION
//
// Originated:
//----------------------------------------------------------------
#ifndef __AAA_LOG_FACILITY_H__
#define __AAA_LOG_FACILITY_H__

#include "aaa_data_defs.h"
#include <fstream>

class DiameterLogFacility 
{
   public:
      DiameterLogFacility() {
      }
      DiameterLogFacility(DiameterDataLog &data) {
          //Open(data);
      }

      static inline void Open(DiameterDataLog &data,AAA_Task &task) {
          ACE_TCHAR pname[32];
          AAALogMsg *logger = AAALogMsg_S::instance();
	
          u_long mask = logger->priority_mask(ACE_Log_Msg::PROCESS);
          mask &= ~LM_DEBUG;
          mask &= ~LM_TRACE;
          mask &= ~LM_INFO;
          mask &= ~LM_ERROR;
          mask &= ~LM_EMERGENCY;
          mask &= ~LM_ALERT;
          
          mask |= (data.flags.debug) ? LM_DEBUG : 0;
          mask |= (data.flags.trace) ? LM_TRACE : 0;
          mask |= (data.flags.info)  ? LM_INFO  : 0;

          mask |= (data.flags.critical)  ? LM_ERROR: 0;
          mask |= (data.flags.emergency) ? LM_EMERGENCY: 0;
          mask |= (data.flags.alert)     ? LM_ALERT: 0;

          char maskflagText[100] = "";
	
/*
			 //DEBUG, INFO, WARNING, NOTICE, ERROR, CRITICAL, ALERT, EMERGENCY
          if( data.flags.info && data.flags.critical && data.flags.debug)
             snprintf(maskflagText, sizeof(maskflagText), "INFO|ERROR|DEBUG");
			 else
             snprintf(maskflagText, sizeof(maskflagText), "~INFO|~ERROR");

			 if ( ! data.flags.info )
             snprintf(maskflagText, sizeof(maskflagText), "ERROR|DEBUG");

          if( data.flags.info && data.flags.critical && data.flags.debug)
             snprintf(maskflagText, sizeof(maskflagText), "INFO|ERROR|DEBUG");
  */
          if( data.flags.info && data.flags.critical && data.flags.debug)
             snprintf(maskflagText, sizeof(maskflagText), "INFO|ERROR|DEBUG");
			 
			 if (  !data.flags.info ) 
             snprintf(maskflagText, sizeof(maskflagText), "~INFO|ERROR|DEBUG");

			 if (  !data.flags.debug ) 
             snprintf(maskflagText, sizeof(maskflagText), "INFO|ERROR|~DEBUG");

			if( !data.flags.debug  &&  !data.flags.info  )
             snprintf(maskflagText, sizeof(maskflagText), "~INFO|ERROR|~DEBUG");

            
//          if( data.flags.critical)
//             snprintf(maskflagText, sizeof(maskflagText), "ERROR|~INFO");
//			 else
//             snprintf(maskflagText, sizeof(maskflagText), "~ERROR|~INFO");

				
          logger->priority_mask(mask, ACE_Log_Msg::PROCESS);

          u_long flags = logger->flags();
          flags &= ~ACE_Log_Msg::STDERR;
          flags &= ~ACE_Log_Msg::SYSLOG;
          flags &= ~ACE_Log_Msg::OSTREAM;
          
          flags |= (data.targets.console) ? ACE_Log_Msg::STDERR : 0;
          //flags |= (data.targets.syslog) ? ACE_Log_Msg::SYSLOG : 0;
          flags |= (data.targets.syslog) ? ACE_Log_Msg::OSTREAM : 0;

          ACE_OS::sprintf(pname, "TDS  %d.%d.%d\n", 
                   DIAMETER_VERSION_MAJOR,
                   DIAMETER_VERSION_MINOR,
                   DIAMETER_VERSION_MICRO);
			 logger->open(pname, flags );

			 time_t rawtime;
			 struct tm *tminfo;

			 time ( &rawtime );
			 tminfo = localtime ( &rawtime );

			 char buffer[80];
			 strftime(buffer, 80, "%Y%m%d%H%M%S", tminfo);

			 string logfile = data.logFile + "." + string(buffer);	
			
			 std::ofstream *output =	new std::ofstream ();
			 output->open (logfile,
					 ios::out | ios::trunc);

			 if (!output->is_open())
			 {
				 AAA_LOG((LM_ERROR, "%T |APP_BASE| Failed to open log file %s.\n",
							 data.logFile.c_str()));
				 throw;
			 }

          //logger->msg_ostream(&log_stream, 0); 
          //logger->msg_ostream(output.get(), 0); 
			 // Chek line 113 . 
          logger->msg_ostream (output, 0);

			 unsigned char ls_argc = 13;
          // Updated to below because of alloc-dealloc-mismatch issue - AB 
          //std::unique_ptr<ACE_TCHAR *> ls_argv (new ACE_TCHAR *[ls_argc]);
          //################################################################
          std::unique_ptr<ACE_TCHAR *[]> ls_argv (new ACE_TCHAR *[ls_argc]);
          char flagText[20] = "";

          if(data.targets.console&&data.targets.syslog)
                  snprintf(flagText, sizeof(flagText), "STDERR|OSTREAM");
          else if(data.targets.console)
                  snprintf(flagText, sizeof(flagText), "STDERR");
          else if(data.targets.syslog)
                  snprintf(flagText, sizeof(flagText), "OSTREAM");
          else
                  snprintf(flagText, sizeof(flagText), "SILENT");

          (ls_argv.get ())[0] = "-f";
          (ls_argv.get ())[1] = flagText;
          (ls_argv.get ())[2] = "-s";
          (ls_argv.get ())[3] = const_cast<char*>(logfile.c_str());
          (ls_argv.get ())[4] = "-i";
          (ls_argv.get ())[5] = const_cast<char*>(data.logFileSamplingInterval.c_str());
          (ls_argv.get ())[6] = "-m";
          (ls_argv.get ())[7] = const_cast<char*>(data.maxLogFileSize.c_str());
          (ls_argv.get ())[8] = "-p";
          (ls_argv.get ())[9] = maskflagText;
          (ls_argv.get ())[10] = "-t";
          (ls_argv.get ())[11] = maskflagText;
          (ls_argv.get ())[12] = "-o";

			 if (logging_strategy.init (ls_argc, ls_argv.get ()) == -1)
          {
                AAA_LOG((LM_ERROR,
                  "%T |APP_BASE| Error initializing the ACE_Logging_Strategy.\n"));
                throw;
          }

          logging_strategy.log_msg(logger);

          logging_strategy.reactor (task.reactor());
          task.reactor()->run_reactor_event_loop ();

      }
      static inline void Close() {
      }

      static ACE_Logging_Strategy logging_strategy;	
};

#endif /* __AAA_LOG_FACILITY_H__ */




