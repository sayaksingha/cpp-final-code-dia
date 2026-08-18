// @(#) $Id: aaa_application.h,v 1.1.4.1.2.1.2.9 2019/12/27 19:43:31 anandhv Exp $
//---------------------------------------------------------------
// NAME : aaa_application.h
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
// Originated By: Anshul Patel  Originated Date: 01-Mar-2018
//----------------------------------------------------------------
#ifndef __AAA_APPLICATION_H__
#define __AAA_APPLICATION_H__

#include "framework.h"
#include "aaa_session_msg_rx.h"
#include "aaa_peer_interface.h"
#include "aaa_xml_data.h"
#include "aaa_log_facility.h"

// An application identifies itself to the diameter class library by
// an instance of the application core. All other classes are services
// that operates using an instance of the core.
class HostList
{
	public :
	DiameterPeerAcceptorList   m_PeerAccptrList;
};

typedef ACE_Singleton<HostList, ACE_Recursive_Thread_Mutex> HostList_S;
#define DIAMETER_HOST_LIST() HostList_S::instance()


class DIAMETERBASEPROTOCOL_EXPORT DiameterApplication :
	public AAA_JobData
{
	private: // General Timer hanlders
		class ReTransmissionTimerHandler : 
			public ACE_Event_Handler 
	{
		public:
			int handle_timeout(const ACE_Time_Value &tv, 
					const void *arg) 
			{
				//TCB
				DIAMETER_MSG_ROUTER()->ReTransmitEvent();
				return (0);
			}

			long &Handle() 
			{
				return m_TimerHandle;
			}
		private:
			long m_TimerHandle;
	};

	public:
		DiameterApplication(AAA_Task &task,
				AAA_Task &otherTask, AAA_Task &lGCTask, 
				char *cfgfile = NULL) :
			m_Task(task),m_OtherTask ( otherTask), m_GCTask(lGCTask)
	{
		if (cfgfile) {
			if(AAA_ERR_SUCCESS != Open(cfgfile))
				throw std::invalid_argument("Invalid Configuration");
		}
	}


		virtual ~DiameterApplication() 
		{
			//m_ReTxHandler.reactor(NULL);
		}

		// Config file loading/un-loading
		AAAReturnCode Open(char *cfgfile);
		AAAReturnCode Close();

		// Check for active peers
		int NumActivePeers() {
			return DiameterPeerConnector::GetNumOpenPeers();
		}

		void Display () {
			return DiameterPeerConnector::DisplayPeer();
		}

		// Factory Registration
		AAAReturnCode RegisterServerSessionFactory
			(DiameterServerSessionFactory &factory);

		// Factory de-registration
		AAAReturnCode RemoveServerSessionFactory(diameter_unsigned32_t appId);


		// Proxy Handler Registration
		AAAReturnCode RegisterProxyHandler(AAA_ProxyHandler &handler);

		// Proxy Handler De-Registration
		AAAReturnCode RemoveProxyHandler(diameter_unsigned32_t appId);

		// Proxy Sync Hop by Hop Handler Registration
		AAAReturnCode RegisterProxySyncHopByHopId(AAA_SyncHopByHopHandler &handler);

		// Proxy Sync Hop by Hop Handler De-Registration
		AAAReturnCode RemoveProxySyncHopByHopId();

		// Framework task
		AAA_Task& Task() {
			return m_Task;
		}

	private: // Global Classes
		AAA_Task 						  &m_Task;
		AAA_Task 						  &m_OtherTask;
		AAA_Task 						  &m_GCTask;
	
		//DiameterPeerAcceptorList   m_PeerAccptrList;
		DiameterSessionMsgRx 		       m_SessionMsgRx;
		Diameter_IO_SigMask 		          m_IOSigMask;
		//AB-Commented on 30May25; It's not required for Dra. dra will not handle retransmission.
      //ReTransmissionTimerHandler        m_ReTxHandler;
};


class DiameterReadConfig : public ACE_Task<ACE_MT_SYNCH>  
{
	public :
		DiameterReadConfig(AAA_Task &t,char*configFile, AAA_Task &OtherTask)
			:mFileName(configFile),m_Task(t),m_OtherTask(OtherTask)
		{
			if(DIAMETER_CFG_RELOAD()->dynamically_load_peer_flag)
			{
				if(activate()==0)
				{
					AAA_LOG((LM_DEBUG, "%T |APP_BASE| Started Reload Thread\n"));
				}
			}
		}


		~DiameterReadConfig() {}

		ACE_Mutex m_Mutex;
		int mDiameterReadConfig=0;
		char *mFileName;
		

	private :
		int svc()
		{
			AAA_MutexScopeLock guard(m_Mutex);
			TEXT* lCfgFileName = "";

			if(mFileName!= NULL)
				lCfgFileName = mFileName;
			else {
				lCfgFileName = "/opt/dra/etc/config/diameter.xml";
			}

			struct stat lFileStat;

			DiameterPeerAcceptor *lDiameterPeerAcceptor;
			ACE_NEW_NORETURN(lDiameterPeerAcceptor, DiameterPeerAcceptor);

			if (stat(lCfgFileName, &lFileStat ) == 0)
			{
				time_t lFileModifiedTime    = lFileStat.st_mtime;
				time_t lFileLastModifiedTime = lFileStat.st_mtime;

				while(1)
				{
					sleep(5);

					if (stat(lCfgFileName, &lFileStat ) == 0)
					{
						lFileModifiedTime = lFileStat.st_mtime;

						time_t lTimeDiff  = lFileModifiedTime - lFileLastModifiedTime;

						if(lTimeDiff != 0 )
						{
							lFileLastModifiedTime = lFileModifiedTime;
							AAA_LOG((LM_INFO, "%T |APP_BASE| Configuration:%s file is modified\n",lCfgFileName));

							DiameterXMLConfigParser parser;
							//parser.ReLoad(m_OtherTask, (char*)lCfgFileName);
							if (parser.ReLoad(m_Task, (char*)lCfgFileName) != -1)
							{
								DIAMETER_PEER_TABLE()->m_ReloadFlag=0;	
								AAA_LOG((LM_DEBUG, "%T |APP_BASE| ReLoad all Peer Info \n"));

								string lPeerName ;	

								//=========================Remove Peer ===========================
								DiameterPeerEntry *lPeerEntry    = NULL;
								DiameterPeerEntry *lPeerNewEntry = NULL;

								lPeerEntry 		= DIAMETER_PEER_TABLE()->First();

								do
								{
									if(lPeerEntry != NULL)
									{
										lPeerName      = lPeerEntry->GetPeerName();
										lPeerNewEntry 	= DIAMETER_PEER_RELOAD_TABLE()->Lookup(lPeerName);


										if(NULL == lPeerNewEntry ||(1 == lPeerNewEntry->GetConnectionStatus()))
										{
											AAA_LOG((LM_DEBUG,"%T |APP_BASE| Removing Peer :%s from Peer Table \n",lPeerName.c_str()));

											lPeerEntry->Stop(AAA_DISCONNECT_BUSY, true);

											lPeerEntry = DIAMETER_PEER_TABLE()->Next(lPeerEntry);

											DIAMETER_PEER_TABLE()->Remove(lPeerName);

											if(NULL != lPeerNewEntry)
											{
												DIAMETER_PEER_RELOAD_TABLE()->deletePeer(lPeerName);
											}
										}
										else
										{
											lPeerEntry = DIAMETER_PEER_TABLE()->Next(lPeerEntry);

											DIAMETER_PEER_RELOAD_TABLE()->deletePeer(lPeerName);
										}

									}
									else
									{
										AAA_LOG((LM_DEBUG,"%T |APP_BASE| None of Peer is connected \n"));
									}
								}while( NULL != lPeerEntry);


								//=========================Add Peer ===========================
								DiameterPeerEntry *lpeerCheck   = NULL;
								DiameterPeerEntry *lpeerTobeAdd = NULL;

								lpeerTobeAdd = DIAMETER_PEER_RELOAD_TABLE()->First();

								do
								{
									if(lpeerTobeAdd == NULL || (1 == lpeerTobeAdd->GetConnectionStatus()))
									{
										if(lpeerTobeAdd)
										{
											lPeerName = lpeerTobeAdd->GetPeerName();
											AAA_LOG((LM_DEBUG, "%T |APP_BASE| Temporary peer :%s is Disconnected \n",lPeerName.c_str()));
											if(lpeerTobeAdd!=NULL)
											{
												lpeerTobeAdd = DIAMETER_PEER_RELOAD_TABLE()->Next(lpeerTobeAdd);
												DIAMETER_PEER_RELOAD_TABLE()->deletePeer(lPeerName);
											}
										}
									}
									else
									{
										lPeerName  = lpeerTobeAdd->GetPeerName();
										lpeerCheck = DIAMETER_PEER_TABLE()->Lookup(lPeerName);

										if(lpeerCheck == NULL)
										{
											AAA_LOG((LM_DEBUG, "%T |APP_BASE| Starting New peer Connection :%s \n",lPeerName.c_str()));
											DIAMETER_PEER_TABLE()->Add(lpeerTobeAdd);
											lpeerTobeAdd->Start();

											lpeerTobeAdd = DIAMETER_PEER_RELOAD_TABLE()->Next(lpeerTobeAdd);

											DIAMETER_PEER_RELOAD_TABLE()->Remove(lPeerName);
										}
										else
										{
											AAA_LOG((LM_DEBUG, "%T |APP_BASE| Peer:%s already Present in peer Table \n",lPeerName.c_str()));
											lpeerTobeAdd = DIAMETER_PEER_RELOAD_TABLE()->Next(lpeerTobeAdd);
										}

									}
								}while(NULL != lpeerTobeAdd);

								DIAMETER_PEER_RELOAD_TABLE()->Clear();
								AAA_LOG((LM_DEBUG, "%T |APP_BASE| Removed all Peer from Reloaded List\n"));

								/*

								//=========================Remove Host ===========================
								DiameterHostIdData *lHost       = DIAMETER_HOST_ID_TABLE()->First();
								DiameterHostIdData *lReloadHost = NULL;
								do
								{
								if(lHost != NULL)
								{
								string lHostName = lHost->identity;

								lReloadHost = DIAMETER_RELOAD_HOST_ID_TABLE()->Lookup(lHostName);

								if(NULL == lReloadHost ||(1 == lReloadHost->disable_host))
								{
								AAA_LOG((LM_DEBUG,"%T |APP_BASE| Removing Host :%s from Host Table \n",lHostName.c_str()));

								DiameterPeerAcceptorList::iterator it = DIAMETER_HOST_LIST()->m_PeerAccptrList.begin();
								for (; strcmp((*it)->m_hostIdentity.c_str(), lHost->identity.c_str()); it++) 
								{
								printf("TBR : (*it)->m_hostIdentity Not remove: %s\n",(*it)->m_hostIdentity.c_str());
								}
								AAA_LOG((LM_DEBUG,"%T |APP_BASE| Removing Host :%s from Host Table \n",(*it)->m_hostIdentity.c_str()));
								(*it)->Stop();
								DIAMETER_HOST_LIST()->m_PeerAccptrList.erase(it);

								lHost = DIAMETER_HOST_ID_TABLE()->Next(lHost);
								DIAMETER_HOST_ID_TABLE()->Remove(lHostName);

								if(NULL != lHost)
								{
								//delete host
								}
								}
								else
								{
								lHost = DIAMETER_HOST_ID_TABLE()->Next(lHost);
								//delete Host
								}

								}
								else
								{
								AAA_LOG((LM_DEBUG,"%T |APP_BASE| None of Host is connected \n"));
								}
								}while( NULL != lHost);

								//=========================Add Host ===========================

								DiameterHostIdData *lHostCheck = NULL;
								DiameterHostIdData *lHostTobeAdd = NULL;

								lHostTobeAdd = DIAMETER_RELOAD_HOST_ID_TABLE()->First();

								do
								{
								if(lHostTobeAdd == NULL || (1 == lHostTobeAdd->disable_host))
								{
								//AAA_LOG((LM_DEBUG, "%T |APP_BASE| No New Host Id\n"));
								if(lHostTobeAdd)
								{
								AAA_LOG((LM_DEBUG, "%T |APP_BASE| Temporary Host :%s is Disconnected \n",lHostTobeAdd->identity.c_str()));
								if(lHostTobeAdd!=NULL)
								{
								lHostTobeAdd = DIAMETER_RELOAD_HOST_ID_TABLE()->Next(lHostTobeAdd);
								//DIAMETER_RELOAD_HOST_ID_TABLE()->deletePeer(lPeerName);
								}
								}
								}
								else
								{
								string lHostName = lHostTobeAdd->identity;

								lHostCheck = DIAMETER_HOST_ID_TABLE()->Lookup(lHostName);

								if(lHostCheck == NULL)
								{
									AAA_LOG((LM_DEBUG, "%T |APP_BASE| Starting New host Connection :%s \n",lHostName.c_str()));
									DIAMETER_HOST_ID_TABLE()->Add(lHostTobeAdd);

									lDiameterPeerAcceptor->Start(lHostTobeAdd);
									DIAMETER_HOST_LIST()->m_PeerAccptrList.push_back(lDiameterPeerAcceptor);

									printf("TBR:: Size :%d\n",DIAMETER_HOST_LIST()->m_PeerAccptrList.size());

									lHostTobeAdd = DIAMETER_RELOAD_HOST_ID_TABLE()->Next(lHostTobeAdd);

									DIAMETER_RELOAD_HOST_ID_TABLE()->Remove(lHostName);
								}
								else
								{
									AAA_LOG((LM_DEBUG, "%T |APP_BASE| Host:%s already Present in Host Table \n",lHostName.c_str()));
									lHostTobeAdd = DIAMETER_RELOAD_HOST_ID_TABLE()->Next(lHostTobeAdd);
								}
							}

							}while(NULL != lHostTobeAdd);

								DIAMETER_RELOAD_HOST_ID_TABLE()->Clearall();
								*/
									if(DIAMETER_CFG_RELOAD()->changelogs == 1)
									{
										AAA_LOG((LM_INFO, "%T |APP_BASE| Changing No. of Logs, according Criticality \n"));
										DiameterLogFacility::Open(*DIAMETER_CFG_LOG(),m_OtherTask);
									}
									else
									{
										AAA_LOG((LM_INFO, "%T |APP_BASE| Logs are not modified \n"));
									}

							}
						}
						else
						{
							AAA_LOG((LM_INFO, "%T |APP_BASE| configuration File not modified \n"));
						}

					}
				}
			}
			return 1;
		}


	public:
		AAA_Task                   &m_Task;
		AAA_Task                   &m_OtherTask;
};


#endif   // __AAA_APPLICATION_H__ 
