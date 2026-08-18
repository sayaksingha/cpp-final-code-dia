//----------------------------------------------------------------------
// NAME :  DraMain.cc
//
// COPYRIGHT :  Tayana Software Solutions Pvt Ltd -- Copyright(C) 2018
//              All rights reserved. No part of this computer program
//              may be used or reproduced in any form by any
//              means without prior written permission of
//              Tayana Software Solutions Pvt Ltd
//
// DESCRIPTION
//
// Originated :                                     Date:
//----------------------------------------------------------------------

#include "Dra.h"
#include "DRA_UpccRechargeHttpRelay.h"
#include "DCCA_RouteProxyHdlr.h"
#include "DCCA_Router.h"
#include <mutex>
#include "ProcessLock.h"
#include "aaa_redis_pool.h"
#include "TssLogCodes.h"
#include <openssl/ssl.h>
#include <openssl/evp.h>

#define DRA_PROCESS "Dra"
#define MAX_PROCESS_NAME 4

struct timeval gTimeValue;
struct tm *gLocalTime;

TEXT gLogText[MAX_LOGTEXT_LEN];
Log gLog;

UINT16 gMaxLicCount = 0;
BOOLEAN gtimeout = false;
FILE *gLicPeg = nullptr;
FILE *gLicPegRx = nullptr;
FILE *gLicPegSy = nullptr;
FILE *gLicPegS6a = nullptr;
FILE *gLicPegSlh = nullptr;
FILE *gLicPegSd = nullptr;
FILE *gLicPegSh = nullptr;
FILE *gLicPegCx = nullptr;

BOOLEAN gIsRx = false;

TEXT gProcessName[MAX_PROCESS_NAME] = "Dra";

TEXT gLicPegFilePath[MAX_FILE_PATH + 1] = "";
TEXT gLicPegFile[MAX_FILE_NAME + MAX_FILE_PATH + 1] = "";
TEXT gLicPegRxFile[MAX_FILE_NAME + MAX_FILE_PATH + 1] = "";

UINT32 gPegDetails[TSS_DRA_APP_MAX_PEG_EVENTS] = {0};
UINT32 *gPreviousPeg = &gPegDetails[TSS_DRA_APP_MAX_PEG_EVENTS];
LONG maxTps = 0, maxTpsRx = 0, maxTpsSy = 0, maxTpsS6a = 0, maxTpsSlh = 0, maxTpsSd = 0, maxTpsSh = 0, maxTpsCx = 0;
static INT32 gRestCount = 0;
BOOLEAN gClearFlag = false;

CTrace gTrace("TRACE_SENTINEL_DETAIL");
CTrace gCfgReadTrace("DRA");

mutex gMutex;

void FileTimer(int sig)
{
	gtimeout = true;
	signal(SIGALRM, FileTimer);
}

int main(int argc, char *argv[])
{
	if (argc < 4)
	{
      printf("\033[1;33mDRA Version:\033[0m 2.2\n");
      printf("\033[1;33mDiameter Version:\033[0m 3.1\n");
      printf("Usage: TSS_Dra <#ProcessingTasks> <#PeerConn/ReadConfigTasks> <#GCTasks>\n");
		//printf(" Dra Version:2.2\tDiameter Version:3.1\nUsage : < Dra > <No. of Processing Tasks> <No. of PeerConnection/ReadConfig Tasks> <No. of GC Tasks>\n");
		exit(1);
	}
	
   AAA_Task lProcessingTask; // Used for Processing Message [ Its used for peer connection ]
	AAA_Task lGarbageTask;	  // For Deletion of the Message
	AAA_Task lOtherTask;	  // For Other connection [Actually its used for Processing message ]
	AAA_Task lGcTask;		  // For Other connection
	// AAA_Task    lHopByHopIdCleanerTask;		  // For Other connection

	AAA_Task ltgmProcessingTask;
	AAA_Task lOtherTaskPcrf;
	AAA_Task lReloadTask;
	TEXT lLogText[300];

	BOOLEAN lReturnValue = false;
	struct timeval lTimeValue;
	struct timeval lTimeValue_prev;
	INT16 lHbCleanerThreadCnt = 5;

	ProcessLock lProcessLock;


	gLog.SetProcessName(gProcessName);

	if (false == gLog.Init("TSS_DRA"))
	{
		cout << "LogInit Failed\n";
		exit(1);
	}

	lProcessLock.SetProdProcName(DRA_PROCESS, gProcessName);

	if (LOCK_SUCCESS != lProcessLock.Lock())
	{
		printf("%s:\33[31m Process already running. Exiting...\33[0m\n", gProcessName);
		exit(1);
	}

	// Initialize OpenSSL 3.0 to prevent race conditions in worker threads
	OPENSSL_init_ssl(0, NULL);
	// Force load default provider and fetch a cipher to populate internal tables
	EVP_CIPHER *dummy_cipher = EVP_CIPHER_fetch(NULL, "AES-128-CBC", NULL);
	if (dummy_cipher) {
		EVP_CIPHER_free(dummy_cipher);
	}

	lProcessingTask.Start(atoi(argv[1]));

   lGarbageTask.Start(atoi(argv[3]));
//	lGarbageTask.Start(5);

	if (argc < 3)
		lOtherTask.Start(4);
	else
		lOtherTask.Start(atoi(argv[2]));

	// if (argc == 4)
	//{
	//	lHbCleanerThreadCnt = atoi(argv[3]);
	// }

	lGcTask.Start(2);
	// lHopByHopIdCleanerTask.Start(lHbCleanerThreadCnt);
	lReloadTask.Start(1);

	// DIAMETER_HOPBYHOPID_CLEANER_ROOT()->Initialize(lHopByHopIdCleanerTask);

	try
	{
		shared_ptr<DRA_UpccRechargeHttpRelay> lDraHttp;
		string lDiameterFile = DRA_CONFIG_HDLR()->mDiameterConfigFilePath + DRA_CONFIG_HDLR()->mDiameterConfigFileName;
		string lDiameterFilepcrf = DRA_CONFIG_HDLR()->mDiameterConfigFilePath + DRA_CONFIG_HDLR()->mDiameterCfgpcrfFleName;

		string lDictionaryFile = DRA_CONFIG_HDLR()->mDictionaryFilePath + DRA_CONFIG_HDLR()->mDictionaryFileName;
		string lRoutingFile = DRA_CONFIG_HDLR()->mRoutingFilePath + DRA_CONFIG_HDLR()->mRoutingFileName;
		string lTrafficFilePath = DRA_CONFIG_HDLR()->mTrafficFilePath;

		DiameterApplication appCore(lProcessingTask, lOtherTask, lGcTask, (char *)lDiameterFile.c_str());
		if (DIAMETER_CFG_RELOAD()->sendtopcrf == 1)
		{
			// TGM_DiameterApplication    tgmCore(ltgmProcessingTask, lOtherTaskPcrf,  "/opt/dra/etc/config/diameter_tgm.xml");
			ltgmProcessingTask.Start(atoi(argv[1]));
			lOtherTaskPcrf.Start(2);
			TGM_DiameterApplication tgmCore(ltgmProcessingTask, lOtherTaskPcrf, (char *)lDiameterFilepcrf.c_str());
		}
		if (DRA_CONFIG_HDLR()->mRelayDataOnErrToPcrfFlg && (DRA_CONFIG_HDLR()->mRelayMessagetopcrf || DRA_CONFIG_HDLR()->mWriteMessagetofile))
		{
			DRA_PCRF_RELAY();
			DRA_REQ_EVR_WRITER();
		}
		else if (DRA_CONFIG_HDLR()->mLPushtoRedis)
		{
			DRA_REQ_EVR_WRITER();
		}
		else
		{
		}
		DiameterReadConfig ReloadConfig(lReloadTask, (char *)lDiameterFile.c_str(), lOtherTask);
		DraRouting lDraRouting(lDictionaryFile, lRoutingFile, lReturnValue);
		DCCA_PrepareRouteRegData lRegDataReader;

		DCCA_InputRouteRule lInputRules;
		DCCA_InputRouteRule lInputRulesForUpccHttp;

		DRA_HTTP_REQ_WRITER();
		DRA_EVR_WRITER();
		if (false == lRegDataReader.PrepareRouteRegData(DRA_CONFIG_HDLR()->mDRA_ApplnFilePath, DRA_CONFIG_HDLR()->mDRA_ApplnFileName, lInputRules))
		{
			printf("Failed to read registration parameter for DRA...........exitting.....");
			return (1);
		}
		
		DIAMETER_PROXY_SESSION_ROOT()->Initialize(lGarbageTask);
		shared_ptr<Dra> myDraGx(new Dra(lProcessingTask, lDraRouting, lInputRules.mApplicationId));

		// shared_ptr<Dra> myDraRx(new Dra(lProcessingTask, lDraRouting, 1006));
		/*if (DCCA_MAX_BOOL_SIZE == DRA_CONFIG_HDLR()->mStartUpccHttpFlg)
		{
			if (false == lRegDataReader.PrepareRouteRegData(DRA_CONFIG_HDLR()->mDRA_HttpApplnFilePath, DRA_CONFIG_HDLR()->mDRA_HttpApplnFileName, lInputRulesForUpccHttp))
			{
				printf("Failed to read registration parameter for DRA Http upcc relay...........exitting.....");
				return (1);
			}
			shared_ptr<DRA_UpccRechargeHttpRelay> lDraHttpIt(new DRA_UpccRechargeHttpRelay(lProcessingTask, lDraRouting, lInputRulesForUpccHttp.mApplicationId));
			lDraHttp = lDraHttpIt;
		}*/

		/*
				 DraSyncHopByHop        syncH2H;
				 DraSyncSession         syncSession;
		*/
		DraSyncSessionSentnl lDraSyncSessionSentnl;
		//DraSyncHopByHopSentnl lDraSyncHopByHopSentnl;

		/*if (DIAMETER_CFG_GENERAL()->sync_hbh || DIAMETER_CFG_GENERAL()->sync_session)
		{
			DIAMETER_SYNC()->Init();
		}*/
		if (DIAMETER_CFG_GENERAL()->sync_session)
		{
			/*
			if(!syncH2H.StartConn())
			{
				printf("Failed to start Redis H2H...Exiting....\n");
				return(1);
			}
			if(!syncSession.StartConn())
			{
				printf("Failed to start Redis Session ID...Exiting....\n");
				return(1);
			}
			*/
			if (DIAMETER_CFG_TRANSPORT()->use_sentinel == 1 && (!lDraSyncSessionSentnl.StartConn()))
			{
				AAA_LOG((LM_INFO, "%T |DRA_APP| CRITICAL: Failed to start TSSRedis sentianal. Please verify redis functionality."));
			}
			else
			{
				AAA_LOG((LM_INFO, "%T |DRA_APP| TSSRedis Sentinel connected successfully"));
				// lDraSyncSessionSentnl.StartReaper();
				//DIAMETER_SESSION_SYNC()->start(DIAMETER_CFG_GENERAL()->sync_task);
			}
		}
		/*if (DIAMETER_CFG_GENERAL()->sync_hbh)
		{
			if (DIAMETER_CFG_TRANSPORT()->use_sentinel == 1 && (!lDraSyncHopByHopSentnl.StartConn()))
			{
				AAA_LOG((LM_INFO, "%T |DRA_APP| CRITICAL: Failed to start TSSRedis sentianal for HBH storage. Please verify redis functionality."));
			}
			else
			{
				AAA_LOG((LM_INFO, "%T |DRA_APP| HBH - TSSRedis Sentinel connected successfully"));
				DIAMETER_HBH_SYNC()->start(DIAMETER_CFG_GENERAL()->sync_task);
			}
		}*/

		/*if (DRA_CONFIG_HDLR()->mLPushtoRedis)
		{
			if (!DRA_PCRF_RELAY()->StartConn())
			{
				printf("Failed to start Redis LPush PCRF...Exiting....\n");
				snprintf(lLogText, 300, "CRITICAL: Failed to start TSSRedis sentianal for PCRF LPUSH for ASR. Please verify redis functionality.");
			}
		}*/
		/*if (DRA_CONFIG_HDLR()->mDetailedEvrFlag)
		{
			DRA_DETAILED_EVR_WRITER()->start();
		}*/
		if (lReturnValue)
		{

                        DCCA_RouteProxyHdlr lDCCA_RouteProxyHdlr({AAA_Gx_APP_ID, AAA_Ro_APP_ID, AAA_Rx_APP_ID, AAA_Sy_APP_ID, AAA_S6a_APP_ID, AAA_Slh_APP_ID, AAA_Sd_APP_ID, AAA_Sh_APP_ID, AAA_Cx_APP_ID});
			if (DIAMETER_CFG_GENERAL()->sync_session)
			{
				// appCore.RegisterProxySyncHopByHopId(syncH2H);
				// myDraGx->RegisterProxySyncSession(syncSession);
				// lDCCA_RouteProxyHdlr.RegisterSyncHdlr( syncSession);
				myDraGx->RegisterProxySyncSession(lDraSyncSessionSentnl);
				//appCore.RegisterProxySyncHopByHopId(lDraSyncHopByHopSentnl);
				lDCCA_RouteProxyHdlr.RegisterSyncHdlr(lDraSyncSessionSentnl);
			}

			if (!DCCA_PROXY_ROUTE_INSTANCE()->Register(lInputRules, std::dynamic_pointer_cast<DCCA_ProxyHandler>(myDraGx)))
			{
				printf("---Registration failed for DRA...........exitting.....");
				return (1);
			}
			/*   if (!DCCA_PROXY_ROUTE_INSTANCE()->Register(lInputRules, std::dynamic_pointer_cast<DCCA_ProxyHandler>(myDraRx)))
			   {
				 cout<<"!DCCA_PROXY_ROUTE_INSTANCE()->Register failed for RX\n\n\n";
				printf("---Registration failed for DRA...........exitting.....");
			   return (1);
				}*/
			/*if (DCCA_MAX_BOOL_SIZE == DRA_CONFIG_HDLR()->mStartUpccHttpFlg)
			{
				if (!DCCA_PROXY_ROUTE_INSTANCE()->Register(lInputRulesForUpccHttp, std::dynamic_pointer_cast<DCCA_ProxyHandler>(lDraHttp)))
				{
					printf("---Registration failed for DRA Http upcc relay...........exitting.....");
					return (1);
				}
			}*/

			if (AAA_ERR_FAILURE == appCore.RegisterProxyHandler(lDCCA_RouteProxyHdlr))
			{
				printf("REGISTRATION to DiameterBase callback FAILED ---\n");
				return (1);
			}

			gettimeofday(&lTimeValue, NULL);
			usleep(1000000 - lTimeValue.tv_usec + 30000);
			snprintf(gLicPegFilePath, MAX_FILE_PATH, lTrafficFilePath.c_str());

			char mbstr[100] = "";
			std::strftime(mbstr, sizeof(mbstr), "%F %X", std::localtime(&DIAMETER_CFG_STARTUP()->startupTime));

			signal(SIGALRM, FileTimer);
			myDraGx->SetAlarmForNextDay();
			// myDraRx->SetAlarmForNextDay();
			myDraGx->GenerateFile();
			myDraGx->GenerateFileRx();
			myDraGx->GenerateFileSy();

			myDraGx->GenerateFileS6a();
			myDraGx->GenerateFileSlh();
			myDraGx->GenerateFileSd();
                        myDraGx->GenerateFileSh();
		        myDraGx->GenerateFileCx();
			sleep(2);

			// TBC--DRA retransmission should be disabled.
			DIAMETER_CFG_TRANSPORT()->retx_max_count = 0;

			while (1)
			{
				std::lock_guard<std::mutex> lk(gMutex);
				std::list<DiameterPeerEntry *> *lPeerList = DIAMETER_PEER_TABLE()->GetPeerList();
				gettimeofday(&lTimeValue_prev, NULL);
				gettimeofday(&gTimeValue, NULL);
				gLocalTime = localtime(&(gTimeValue.tv_sec));

				fprintf(gLicPeg, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
				fprintf(gLicPeg, "                                              STACK START TIME:%s\n", mbstr);
				fprintf(gLicPeg, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");

				fprintf(gLicPegRx, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
				fprintf(gLicPegRx, "                                              STACK START TIME:%s\n", mbstr);
				fprintf(gLicPegRx, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");

				fprintf(gLicPegSy, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
				fprintf(gLicPegSy, "                                              STACK START TIME:%s\n", mbstr);
				fprintf(gLicPegSy, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");

				fprintf(gLicPegS6a, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
				fprintf(gLicPegS6a, "                                              STACK START TIME:%s\n", mbstr);
				fprintf(gLicPegS6a, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
				
				fprintf(gLicPegSlh, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
				fprintf(gLicPegSlh, "                                              STACK START TIME:%s\n", mbstr);
				fprintf(gLicPegSlh, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
		
				fprintf(gLicPegSd, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
				fprintf(gLicPegSd, "                                              STACK START TIME:%s\n", mbstr);
				fprintf(gLicPegSd, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");

				fprintf(gLicPegSh, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
				fprintf(gLicPegSh, "                                              STACK START TIME:%s\n", mbstr);
				fprintf(gLicPegSh, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
				
				fprintf(gLicPegCx, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
				fprintf(gLicPegCx, "                                              STACK START TIME:%s\n", mbstr);
				fprintf(gLicPegCx, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
				
				int i = 0;
				unsigned long sysErr = 0;
		                unsigned long tps = 0, tpsRx = 0, tpsSy = 0, tpsS6a = 0, tpsSlh = 0, tpsSd = 0, tpsSh = 0, tpsCx = 0;
				size_t lBackLogSize = 0;
                                static unsigned long maxSysTps = 0, maxSysTpsRx = 0, maxSysTpsSy = 0, maxSysTpsS6a = 0, maxSysTpsSlh = 0, maxSysTpsSd = 0, maxSysTpsSh = 0, maxSysTpsCx = 0;			        
				// for ( std::list<DiameterPeerEntry*>::iterator it = lPeerList->begin(); it != lPeerList->end() ; it++,i++ )
				for (std::list<DiameterPeerEntry *>::iterator it = lPeerList->begin(); it != lPeerList->end(); it++, i++)
				{
					lBackLogSize = (*it)->Job().BacklogSize();
					// myDraGx->DisplayPegDetails( (*it), i, tps);
					myDraGx->DisplayPegDetails((*it), i, tps);
					myDraGx->DisplayPegDetailsRx((*it), i, tpsRx);
					myDraGx->DisplayPegDetailsSy((*it), i, tpsSy);
					myDraGx->DisplayPegDetailsS6a((*it), i, tpsS6a);
					myDraGx->DisplayPegDetailsSlh((*it), i, tpsSlh);
				        myDraGx->DisplayPegDetailsSd((*it), i, tpsSd);
                                        myDraGx->DisplayPegDetailsSh((*it), i, tpsSh);
                                        myDraGx->DisplayPegDetailsCx((*it), i, tpsCx);
					//s6a can be added here
					sysErr += (*it)->Peg()->m_sytem_error;
				}

				if (gRestCount > 10)
				{
					if (maxTps < tps)
					{
						maxTps = tps;
						maxSysTps = maxTps;
					}
					if (maxTpsRx < tpsRx)
					{
						maxSysTpsRx = tpsRx;
						maxSysTpsRx = maxTpsRx;
					}
					if (maxTpsSy < tpsSy)
					{
						maxTpsSy = tpsSy;
						maxSysTpsSy = maxTpsSy;
					}
					if (maxTpsS6a < tpsS6a)
					{
						maxTpsS6a = tpsS6a;
						maxSysTpsS6a = maxTpsS6a;
					}
					if (maxTpsSlh < tpsSlh)
					{
						maxTpsSlh = tpsSlh;
						maxSysTpsSlh = maxTpsSlh;
					}
				       if (maxTpsSd < tpsSd)
					  {
					    maxTpsSd = tpsSd;
					    maxSysTpsSd = maxTpsSd;
					  }
				       if (maxTpsSh < tpsSh)
					  {
					    maxTpsSh = tpsSh;
					    maxSysTpsSh = maxTpsSh;
					  }
				       if (maxTpsCx < tpsCx)
					  {
					    maxTpsCx = tpsCx;
					    maxSysTpsCx = maxTpsCx;
					  }
				}
				else
				{
					gRestCount++;
				}

				fprintf(gLicPeg, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
				fprintf(gLicPeg, "|%02d:%02d:%02d|  TPS:%ld   DAY_PEAK:%ld   SYS_PEAK:%ld   SESSIONS:[%d/%d]   JOBS:[%d/%d]   SYS_ERROR:%ld\n",
						gLocalTime->tm_hour, gLocalTime->tm_min, gLocalTime->tm_sec, tps, maxTps, maxSysTps,
						unsigned(DIAMETER_SESSION_INFO()->currrentSessions), DIAMETER_CFG_SESSION()->maxSessions,
						lBackLogSize, DIAMETER_CFG_TRANSPORT()->max_pending_backlog, sysErr);

				fprintf(gLicPegRx, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
				fprintf(gLicPegRx, "|%02d:%02d:%02d|  TPS:%ld   DAY_PEAK:%ld   SYS_PEAK:%ld   SESSIONS:[%d/%d]   JOBS:[%d/%d]   SYS_ERROR:%ld\n",
						gLocalTime->tm_hour, gLocalTime->tm_min, gLocalTime->tm_sec, tpsRx, maxTpsRx, maxSysTpsRx,
						unsigned(DIAMETER_SESSION_INFO()->currrentSessions), DIAMETER_CFG_SESSION()->maxSessions,
						lBackLogSize, DIAMETER_CFG_TRANSPORT()->max_pending_backlog, sysErr);

				fprintf(gLicPegSy, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
				fprintf(gLicPegSy, "|%02d:%02d:%02d|  TPS:%ld   DAY_PEAK:%ld   SYS_PEAK:%ld   SESSIONS:[%d/%d]   JOBS:[%d/%d]   SYS_ERROR:%ld\n",
						gLocalTime->tm_hour, gLocalTime->tm_min, gLocalTime->tm_sec, tpsSy, maxTpsSy, maxSysTpsSy,
						unsigned(DIAMETER_SESSION_INFO()->currrentSessions), DIAMETER_CFG_SESSION()->maxSessions,
						lBackLogSize, DIAMETER_CFG_TRANSPORT()->max_pending_backlog, sysErr);

				fprintf(gLicPegS6a, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
				fprintf(gLicPegS6a, "|%02d:%02d:%02d|  TPS:%ld   DAY_PEAK:%ld   SYS_PEAK:%ld   SESSIONS:[%d/%d]   JOBS:[%d/%d]   SYS_ERROR:%ld\n",
						gLocalTime->tm_hour, gLocalTime->tm_min, gLocalTime->tm_sec, tpsS6a, maxTpsS6a, maxSysTpsS6a,
						unsigned(DIAMETER_SESSION_INFO()->currrentSessions), DIAMETER_CFG_SESSION()->maxSessions,
						lBackLogSize, DIAMETER_CFG_TRANSPORT()->max_pending_backlog, sysErr);

				fprintf(gLicPegSlh, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
				fprintf(gLicPegSlh, "|%02d:%02d:%02d|  TPS:%ld   DAY_PEAK:%ld   SYS_PEAK:%ld   SESSIONS:[%d/%d]   JOBS:[%d/%d]   SYS_ERROR:%ld\n",
						gLocalTime->tm_hour, gLocalTime->tm_min, gLocalTime->tm_sec, tpsSlh, maxTpsSlh, maxSysTpsSlh,
						unsigned(DIAMETER_SESSION_INFO()->currrentSessions), DIAMETER_CFG_SESSION()->maxSessions,
						lBackLogSize, DIAMETER_CFG_TRANSPORT()->max_pending_backlog, sysErr);


				fprintf(gLicPegSd, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
				fprintf(gLicPegSd, "|%02d:%02d:%02d|  TPS:%ld   DAY_PEAK:%ld   SYS_PEAK:%ld   SESSIONS:[%d/%d]   JOBS:[%d/%d]   SYS_ERROR:%ld\n",
				    gLocalTime->tm_hour, gLocalTime->tm_min, gLocalTime->tm_sec, tpsSd, maxTpsSd, maxSysTpsSd,
				    unsigned(DIAMETER_SESSION_INFO()->currrentSessions), DIAMETER_CFG_SESSION()->maxSessions,
				    lBackLogSize, DIAMETER_CFG_TRANSPORT()->max_pending_backlog, sysErr);
				
				fprintf(gLicPegSh, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
				fprintf(gLicPegSh, "|%02d:%02d:%02d|  TPS:%ld   DAY_PEAK:%ld   SYS_PEAK:%ld   SESSIONS:[%d/%d]   JOBS:[%d/%d]   SYS_ERROR:%ld\n",
				    gLocalTime->tm_hour, gLocalTime->tm_min, gLocalTime->tm_sec, tpsSh, maxTpsSh, maxSysTpsSh,
				    unsigned(DIAMETER_SESSION_INFO()->currrentSessions), DIAMETER_CFG_SESSION()->maxSessions,
				    lBackLogSize, DIAMETER_CFG_TRANSPORT()->max_pending_backlog, sysErr);
				
				fprintf(gLicPegCx, "+-----------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
				fprintf(gLicPegCx, "|%02d:%02d:%02d|  TPS:%ld   DAY_PEAK:%ld   SYS_PEAK:%ld   SESSIONS:[%d/%d]   JOBS:[%d/%d]   SYS_ERROR:%ld\n",
				    gLocalTime->tm_hour, gLocalTime->tm_min, gLocalTime->tm_sec, tpsCx, maxTpsCx, maxSysTpsCx,
				    unsigned(DIAMETER_SESSION_INFO()->currrentSessions), DIAMETER_CFG_SESSION()->maxSessions,
				    lBackLogSize, DIAMETER_CFG_TRANSPORT()->max_pending_backlog, sysErr);


				fflush(gLicPeg);
				fflush(gLicPegRx);
				fflush(gLicPegSy);
				fflush(gLicPegS6a);
				fflush(gLicPegSlh);
 			        fflush(gLicPegSd);
 			        fflush(gLicPegSh);			
			        fflush(gLicPegCx);
                        
				if (gtimeout == true)
				{
					gRestCount = 0;
					gtimeout = false;
					alarm(86400 + 5); // Add 5 for Adjustment
					// myDraGx->GenerateFile(mfile);
					myDraGx->GenerateFile();
					myDraGx->GenerateFileRx();
					myDraGx->GenerateFileSy();
					myDraGx->GenerateFileS6a();
					myDraGx->GenerateFileSlh();
			                myDraGx->GenerateFileSd();
                                        myDraGx->GenerateFileSh();
                                        myDraGx->GenerateFileCx();
				}

				gettimeofday(&lTimeValue, NULL);

				if (lTimeValue.tv_sec == lTimeValue_prev.tv_sec)
					usleep(1000000 - lTimeValue.tv_usec + 30000);
				else if (lTimeValue.tv_usec < 30000)
					usleep(30000 - lTimeValue.tv_usec);
			}
		}
		sleep(1);

		appCore.Close();
	}
	catch (const std::logic_error &e)
	{
		printf("%s:\33[31m Error(%s). Exiting...\33[0m\n",
			   argv[0], e.what());
	}
	catch (const std::exception &e)
	{
		printf("%s:\33[31m Error(%s). Exiting...\33[0m\n",
			   argv[0], e.what());
	}
	catch (...)
	{
		AAA_LOG((LM_INFO, "%T |DRA_APP| Failed, log: Unknown Error"));
		printf("%s:\33[31m Error occured. Exiting...\33[0m\n",
			   argv[0]);
	}

	lReloadTask.Stop();

	lProcessingTask.Stop();

	if (DIAMETER_CFG_RELOAD()->sendtopcrf == 1)
	{
		ltgmProcessingTask.Stop();
		lOtherTaskPcrf.Stop();
	}

	lOtherTask.Stop();
	lGarbageTask.Stop();
	AAA_LOG((LM_INFO, "%T |DRA_APP| DRA stoping normally --- aborting"));
};
