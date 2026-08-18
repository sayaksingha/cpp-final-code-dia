static const char *id = " @(#) $Id: diameter_cc_proxy_fsm.cc,v 1.1.2.1.2.22 2024/05/15 13:03:29 mram Exp $";
//----------------------------------------------------------------------
// NAME
// diameter_cc_proxy_fsm.cc
//
// COPYRIGHT
// Tayana Software Solutions Pvt Ltd -- Copyright(C) 2007
// All rights reserved. No part of this computer program
// may be used or reproduced in any form by any
// means without prior written permission of
// Tayana Software Solutions Pvt Ltd
//
// DESCRIPTION
//
// Originated :                                     Date:
//----------------------------------------------------------------------
#include <ace/Singleton.h>
#include <ace/Atomic_Op_T.h>
#include "diameter_cc_proxy_session.h"
#include "diameter_cc_proxy_fsm.h"
#include "diameter_cc_parser.h"
#include "diameter_cc_application.h"
#include "aaa_redis_pool.h"

class DiameterCCProxyAction : public AAA_Action<DiameterCCProxyStateMachine>
{
	virtual void operator()(DiameterCCProxyStateMachine&) = 0;
	protected:
	DiameterCCProxyAction() {}
	~DiameterCCProxyAction() {}
};

/// State table used by DiameterCCProxyStateMachine.
class DiameterCCProxyStateTable_S : public AAA_StateTable<DiameterCCProxyStateMachine>
{
	friend class ACE_Singleton<DiameterCCProxyStateTable_S, ACE_Recursive_Thread_Mutex>;

	private:

	class AcInitialRequest : public DiameterCCProxyAction 
	{
		void operator()(DiameterCCProxyStateMachine& sm)
		{
			if(sm.m_Msg)
			{
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_Msg);	
				AAA_LOG((LM_INFO,"%T |CC_FSM| %s [ACT]Process Initial Request\n",lLogText.c_str()));
				sm.mInitialRecvFlg = true;			   	
				/*std::unique_lock<std::mutex> lk(DIAMETER_SESSION_INFO()->threadMutex);
				DIAMETER_SESSION_INFO()->cv.wait(lk, []{return !(DIAMETER_SESSION_INFO()->processing);});
				DIAMETER_SESSION_INFO()->processing = true;*/
				DIAMETER_SESSION_INFO()->lock.lock();
				if(DIAMETER_SESSION_INFO()->currrentSessions < DIAMETER_CFG_SESSION()->maxSessions)
				{
					DIAMETER_SESSION_INFO()->currrentSessions++;
					DIAMETER_SESSION_INFO()->lock.unlock();
					AAA_LOG((LM_CRITICAL,"%T |CC_FSM| %s Creating session on Initiation Request, Sessions:(%d/%d)\n",
								lLogText.c_str(),unsigned(DIAMETER_SESSION_INFO()->currrentSessions),DIAMETER_CFG_SESSION()->maxSessions));
					/*DIAMETER_SESSION_INFO()->processing = false;
					lk.unlock();
					DIAMETER_SESSION_INFO()->cv.notify_one();*/
					sm.InitialRequest(sm.m_Msg, sm.m_Src, *sm.m_Dest);
					sm.ScheduleTimer(DiameterCCProxyEvent::EvTccExpired,
							DIAMETER_CFG_ACCT_SESSION()->sessionTm,
							0,
							DiameterCCProxyEvent::EvTccExpired);
					AAA_LOG((LM_DEBUG,"%T |CC_FSM| %s starting TCC timer...\n",lLogText.c_str()));

					sm.SendSyncSessionData(sm, SYNC_OP_ADD, DiameterCCProxyEvent::EvInitialRequest); // Sync
				}
				else
				{
					DIAMETER_SESSION_INFO()->lock.unlock();
					//Diameter Busy Message
					AAA_LOG((LM_ERROR,"%T |CC_FSM| %s [ACT]Process Max Sessions exceeded, Max:%d current:%d\n",
								lLogText.c_str(),DIAMETER_CFG_SESSION()->maxSessions,
								unsigned(DIAMETER_SESSION_INFO()->currrentSessions)));
					/*DIAMETER_SESSION_INFO()->processing = false;
					lk.unlock();
					DIAMETER_SESSION_INFO()->cv.notify_one();*/
					
					sm.RejectRequest(sm.m_Msg, sm.m_Src, *sm.m_Dest);
				}
			}
		}
	};
	
	class AcInitialRequestRtx : public DiameterCCProxyAction 
	{
		void operator()(DiameterCCProxyStateMachine& sm)
		{
			if(sm.m_Msg)
			{
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_Msg);	
				AAA_LOG((LM_INFO,"%T |CC_FSM| %s [ACT]Process ReTxn-Initial Request\n",lLogText.c_str()));
			
				if ( false == sm.mInitialRecvFlg)
				{
					DIAMETER_SESSION_INFO()->lock.lock();
					if(DIAMETER_SESSION_INFO()->currrentSessions < DIAMETER_CFG_SESSION()->maxSessions)
					{
						DIAMETER_SESSION_INFO()->currrentSessions++;
						DIAMETER_SESSION_INFO()->lock.unlock();
						AAA_LOG((LM_CRITICAL,"%T |CC_FSM| %s Creating session on ReTxn-Initiation Request, Sessions:(%d/%d)\n",
									lLogText.c_str(),unsigned(DIAMETER_SESSION_INFO()->currrentSessions),DIAMETER_CFG_SESSION()->maxSessions));
					}
					else
					{
						DIAMETER_SESSION_INFO()->lock.unlock();
						//Diameter Busy Message
						AAA_LOG((LM_ERROR,"%T |CC_FSM| %s ReTxn-I [ACT]Process Max Sessions exceeded, Max:%d current:%d\n",
									lLogText.c_str(),DIAMETER_CFG_SESSION()->maxSessions,
									unsigned(DIAMETER_SESSION_INFO()->currrentSessions)));

						sm.RejectRequest(sm.m_Msg, sm.m_Src, *sm.m_Dest);
						return;
					}
				}

				if ( false == sm.mInitialRecvFlg)
				{
					sm.InitialRequestRtx(sm.m_Msg, sm.m_Src, *sm.m_Dest);
					sm.ScheduleTimer(DiameterCCProxyEvent::EvTccExpired,
							DIAMETER_CFG_ACCT_SESSION()->sessionTm,
							0,
							DiameterCCProxyEvent::EvTccExpired);
					AAA_LOG((LM_DEBUG,"%T |CC_FSM| %s ReTxn-I Starting TCC timer...\n",lLogText.c_str()));
					sm.mInitialRecvFlg = true;	
					sm.SendSyncSessionData(sm, SYNC_OP_ADD, DiameterCCProxyEvent::EvInitialRequestRtx); // Sync
				}
				else
				{
					sm.CancelTimer(DiameterCCProxyEvent::EvTccExpired);
					sm.InitialRequestRtx(sm.m_Msg, sm.m_Src, *sm.m_Dest);
					sm.ScheduleTimer(DiameterCCProxyEvent::EvTccExpired,
							DIAMETER_CFG_ACCT_SESSION()->sessionTm,
							0,
							DiameterCCProxyEvent::EvTccExpired);
					AAA_LOG((LM_DEBUG,"%T |CC_FSM| %s ReTxn-I Udating TCC timer...\n",lLogText.c_str()));
				}
			}
		}
	};

	class AcSuccessfulInitialAnswer : public DiameterCCProxyAction 
	{
		void operator()(DiameterCCProxyStateMachine& sm)
		{
			if(sm.m_Msg)
			{
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_Msg);
				AAA_LOG((LM_INFO,"%T |CC_FSM| %s [ACT]Received Successful Initial Answer\n",lLogText.c_str()));
				sm.InitialAnswer(sm.m_Msg, sm.m_Src, *sm.m_Dest);
		//		sm.SendSyncSessionData(sm, SYNC_OP_ADD, DiameterCCProxyEvent::EvInitialRequestSuccessful); // Sync
			}
		}
	};

	class AcUnsuccessfulInitialAnswer : public DiameterCCProxyAction
	{
		void operator()(DiameterCCProxyStateMachine& sm)
		{
			if(sm.m_Msg)
			{
				sm.CancelTimer(DiameterCCProxyEvent::EvTccExpired);
				
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_Msg);
				AAA_LOG((LM_INFO,"%T |CC_FSM| %s [ACT]Received Unsuccessful Initial Answer\n",lLogText.c_str()));
				sm.InitialAnswer(sm.m_Msg, sm.m_Src, *sm.m_Dest);
				sm.SendSyncSessionData(sm, SYNC_OP_DEL, DiameterCCProxyEvent::EvInitialRequestUnsuccessful); // Sync
				sm.Reset(sm.sessionId,sm.appId);
				
				string lTempLogText = "Freeing session on UnsuccessfulInitialAnswer";
				DIAMETER_DEC_SESSION_CNT(lTempLogText);	

			}
		}
	};

	class AcUpdateRequest : public DiameterCCProxyAction 
	{
		void operator()(DiameterCCProxyStateMachine& sm)
		{
			if(sm.m_Msg)
			{
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_Msg);	
				if (sm.mInitialRecvFlg == false && sm.mUpdateRecvFlg == false)
				{
					DIAMETER_SESSION_INFO()->lock.lock();
					if(DIAMETER_SESSION_INFO()->currrentSessions < DIAMETER_CFG_SESSION()->maxSessions)
					{
						DIAMETER_SESSION_INFO()->currrentSessions++;
						DIAMETER_SESSION_INFO()->lock.unlock();
						AAA_LOG((LM_CRITICAL,"%T |CC_FSM| %s Creating session on Update Request, Sessions:(%d/%d)\n",
									lLogText.c_str(),unsigned(DIAMETER_SESSION_INFO()->currrentSessions),
									DIAMETER_CFG_SESSION()->maxSessions));
					}
					else
					{
						DIAMETER_SESSION_INFO()->lock.unlock();
						AAA_LOG((LM_CRITICAL,"%T |CC_FSM| %s Session:(%d/%d) Rejecting Current Request\n",
									lLogText.c_str(), unsigned(DIAMETER_SESSION_INFO()->currrentSessions),DIAMETER_CFG_SESSION()->maxSessions));
						sm.RejectRequest(sm.m_Msg, sm.m_Src, *sm.m_Dest);
						return;
					}
				}

				AAA_LOG((LM_INFO,"%T |CC_FSM| %s [ACT]Process Update Request\n",lLogText.c_str()));

				sm.CancelTimer(DiameterCCProxyEvent::EvTccExpired);
				sm.UpdateRequest(sm.m_Msg, sm.m_Src, *sm.m_Dest);
				sm.mUpdateRecvFlg = true;
				sm.ScheduleTimer(DiameterCCProxyEvent::EvTccExpired,
						DIAMETER_CFG_ACCT_SESSION()->sessionTm,
						0,
						DiameterCCProxyEvent::EvTccExpired);
				AAA_LOG((LM_DEBUG,"%T |CC_FSM| %s updating TCC timer...\n",lLogText.c_str()));
				sm.SendSyncSessionData(sm, SYNC_OP_ADD, DiameterCCProxyEvent::EvUpdateRequest); // Sync
			}
		}
	};

	class AcSuccessfulUpdateAnswer : public DiameterCCProxyAction 
	{
		void operator()(DiameterCCProxyStateMachine& sm)
		{
			if(sm.m_Msg)
			{
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_Msg);	
				AAA_LOG((LM_INFO,"%T |CC_FSM| %s [ACT]Received Successful Update Answer\n",lLogText.c_str()));
				sm.UpdateAnswer(sm.m_Msg, sm.m_Src, *sm.m_Dest);
				//sm.SendSyncSessionData(sm, SYNC_OP_ADD, DiameterCCProxyEvent::EvUpdateRequestSuccessful); // Sync
			}
		}
	};

	class AcUnsuccessfulUpdateAnswer : public DiameterCCProxyAction 
	{
		void operator()(DiameterCCProxyStateMachine& sm)
		{
			if(sm.m_Msg)
			{
				sm.CancelTimer(DiameterCCProxyEvent::EvTccExpired);

				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_Msg);	
				AAA_LOG((LM_INFO,"%T |CC_FSM| %s [ACT]Received Unsuccessful Update Answer Reset Session\n",lLogText.c_str()));
				sm.UpdateAnswer(sm.m_Msg, sm.m_Src, *sm.m_Dest);
				sm.SendSyncSessionData(sm, SYNC_OP_DEL, DiameterCCProxyEvent::EvUpdateRequestUnsuccessful); // Sync
				// Check for the Error Code List and delte 
				sm.Reset(sm.sessionId,sm.appId);

				string lTempLogText = "Freeing session on UnsuccessfulUpdateAnswer";
				DIAMETER_DEC_SESSION_CNT(lTempLogText);	
			}
		}
	};

	class AcTerminationRequest : public DiameterCCProxyAction 
	{
		void operator()(DiameterCCProxyStateMachine& sm)
		{
			if(sm.m_Msg)
			{
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_Msg);	
				if (sm.mInitialRecvFlg == false && sm.mUpdateRecvFlg == false && sm.mTerminateRecvFlg == false)
                                {
                                        DIAMETER_SESSION_INFO()->lock.lock();
                                        if(DIAMETER_SESSION_INFO()->currrentSessions < DIAMETER_CFG_SESSION()->maxSessions)
                                        {
                                                DIAMETER_SESSION_INFO()->currrentSessions++;
                                                DIAMETER_SESSION_INFO()->lock.unlock();
                                                AAA_LOG((LM_CRITICAL,"%T |CC_FSM| %s Creating session on Terminate Request, Sessions:(%d/%d)\n",
                                                                        lLogText.c_str(),unsigned(DIAMETER_SESSION_INFO()->currrentSessions),
                                                                        DIAMETER_CFG_SESSION()->maxSessions));
                                        }
                                        else
                                        {
                                                DIAMETER_SESSION_INFO()->lock.unlock();
                                                AAA_LOG((LM_CRITICAL,"%T |CC_FSM| %s Session:(%d/%d) Rejecting Current Request\n",
                                                                        lLogText.c_str(), unsigned(DIAMETER_SESSION_INFO()->currrentSessions),DIAMETER_CFG_SESSION()->maxSessions));
                                                sm.RejectRequest(sm.m_Msg, sm.m_Src, *sm.m_Dest);
                                                return;
                                        }
                                }

				AAA_LOG((LM_INFO,"%T |CC_FSM| %s [ACT]Process Termination Request\n",lLogText.c_str()));
				//sm.CancelTimer(DiameterCCProxyEvent::EvTccExpired); // Is we need to cancel timer now ???
				sm.mTerminateRecvFlg = true;
				sm.TerminationRequest(sm.m_Msg, sm.m_Src, *sm.m_Dest);
				sm.SendSyncSessionData(sm, SYNC_OP_ADD, DiameterCCProxyEvent::EvTerminationRequest); // Sync
			}
		}
	};

	class AcSuccessfulTerminationAnswer : public DiameterCCProxyAction 
	{
		void operator()(DiameterCCProxyStateMachine& sm)
		{
			if(sm.m_Msg)
			{
				sm.CancelTimer(DiameterCCProxyEvent::EvTccExpired);

				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_Msg);	
				AAA_LOG((LM_INFO,"%T |CC_FSM| %s [ACT]Received Successful Termination Answer Reset Session \n",lLogText.c_str()));
				sm.TerminationAnswer(sm.m_Msg, sm.m_Src, *sm.m_Dest);
				sm.SendSyncSessionData(sm, SYNC_OP_DEL, DiameterCCProxyEvent::EvTerminationRequestSuccessful); // Sync
				sm.Reset(sm.sessionId,sm.appId);

				string lTempLogText = "Freeing session on SuccessfulTerminationAnswer";
				DIAMETER_DEC_SESSION_CNT(lTempLogText);	
			}
		}
	};

	class AcUnsuccessfulTerminationAnswer : public DiameterCCProxyAction 
	{
		void operator()(DiameterCCProxyStateMachine& sm)
		{
			if(sm.m_Msg)
			{
				sm.CancelTimer(DiameterCCProxyEvent::EvTccExpired);

				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_Msg);	
				AAA_LOG((LM_INFO,"%T |CC_FSM| %s [ACT]Received Unsuccessful Termination Answer Reset Session\n",lLogText.c_str()));
				sm.TerminationAnswer(sm.m_Msg, sm.m_Src, *sm.m_Dest);
				sm.SendSyncSessionData(sm, SYNC_OP_DEL, DiameterCCProxyEvent::EvTerminationRequestUnsuccessful); // Sync
				sm.Reset(sm.sessionId,sm.appId);

				string lTempLogText = "Freeing session on UnsuccessfulTerminationAnswer";
				DIAMETER_DEC_SESSION_CNT(lTempLogText);	
			}
		}
	};

	class AcEventRequest : public DiameterCCProxyAction 
	{
		void operator()(DiameterCCProxyStateMachine& sm)
		{
			if(sm.m_Msg)
			{
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_Msg);	
				AAA_LOG((LM_INFO,"%T |CC_FSM| %s [ACT] Process Event Request\n",lLogText.c_str()));
				sm.EventRequest(sm.m_Msg, sm.m_Src, *sm.m_Dest);

				//sm.CancelTimer(DiameterCCProxyEvent::EvTxExpired);
				sm.ScheduleTimer(DiameterCCProxyEvent::EvTxExpired,
						DIAMETER_CFG_ACCT_SESSION()->txTimeout,
						0,
						DiameterCCProxyEvent::EvTxExpired);

				sm.SendSyncSessionData(sm, SYNC_OP_ADD, DiameterCCProxyEvent::EvEventRequest); // Sync
			}
		}
	};

	class AcEvInternalRspFromProxy : public DiameterCCProxyAction
	{
		void operator()(DiameterCCProxyStateMachine& sm)
		{
			if(sm.m_shr)
			{
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_shr);
				AAA_LOG((LM_INFO,"%T |CC_FSM| %s [ACT] Received Nack From PRS or Deleting for ULR sent\n",lLogText.c_str()));
				sm.CancelTimer(DiameterCCProxyEvent::EvTxExpired);
				sm.Reset(sm.sessionId,sm.appId);
			}
			else
			{
				AAA_LOG((LM_INFO,"%T |CC_FSM| [ACT] Received Nack From PRS, Msg Null\n"));
			}
		}
	};

	class AcSuccessfulEventAnswer : public DiameterCCProxyAction 
	{
		void operator()(DiameterCCProxyStateMachine& sm)
		{
			if(sm.m_Msg)
			{
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_Msg);	
				AAA_LOG((LM_INFO,"%T |CC_FSM| %s [ACT]Received Successful Event Answer Reset \n",lLogText.c_str()));
				sm.EventAnswer(sm.m_Msg, sm.m_Src, *sm.m_Dest);
				sm.CancelTimer(DiameterCCProxyEvent::EvTxExpired);
				sm.SendSyncSessionData(sm, SYNC_OP_DEL, DiameterCCProxyEvent::EvEventRequestSuccessful); // Sync
				sm.Reset(sm.sessionId,sm.appId);
			}
		}
	};

	class AcUnsuccessfulEventAnswer : public DiameterCCProxyAction 
	{
		void operator()(DiameterCCProxyStateMachine& sm)
		{
			if(sm.m_Msg)
			{
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_Msg);	
				AAA_LOG((LM_INFO,"%T |CC_FSM| %s [ACT]Received Unsuccessful Event Answer Reset \n",lLogText.c_str()));
				sm.EventAnswer(sm.m_Msg, sm.m_Src, *sm.m_Dest);
				sm.CancelTimer(DiameterCCProxyEvent::EvTxExpired);
				sm.SendSyncSessionData(sm, SYNC_OP_DEL, DiameterCCProxyEvent::EvEventRequestUnsuccessful); // Sync
				sm.Reset(sm.sessionId,sm.appId);
			}
		}
	};

	class AcASRequest : public DiameterCCProxyAction
	{
		void operator()(DiameterCCProxyStateMachine& sm)
		{
			if(sm.m_Msg)
			{
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_Msg);	
				AAA_LOG((LM_INFO,"%T |CC_FSM| %s [ACT]Process Abort Session Request\n",lLogText.c_str()));
				sm.ASRequest(sm.m_Msg, sm.m_Src, *sm.m_Dest);
				//	sm.SendSyncSessionData(sm, SYNC_OP_ADD, DiameterCCProxyEvent::EvASRequest); // Sync
			}
		}
	};

	class AcSuccessfulASAnswer : public DiameterCCProxyAction
	{
		void operator()(DiameterCCProxyStateMachine& sm)
		{
			if(sm.m_Msg)
			{
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_Msg);	
				AAA_LOG((LM_INFO,"%T |CC_FSM| %s [ACT]Received Successful Abort Session Answer\n",lLogText.c_str()));
				sm.ASAnswer(sm.m_Msg, sm.m_Src, *sm.m_Dest);
				//sm.SendSyncSessionData(sm, SYNC_OP_ADD, DiameterCCProxyEvent::EvASRequestSuccessful); // Sync
			}
		}
	};

	class AcUnsuccessfulASAnswer : public DiameterCCProxyAction
	{
		void operator()(DiameterCCProxyStateMachine& sm)
		{
			if(sm.m_Msg)
			{
				sm.CancelTimer(DiameterCCProxyEvent::EvTccExpired);

				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_Msg);	
				AAA_LOG((LM_INFO,"%T |CC_FSM| %s [ACT]Received Unsuccessful Abort Session Answer Reset \n",lLogText.c_str()));
				sm.ASAnswer(sm.m_Msg, sm.m_Src, *sm.m_Dest);
				sm.SendSyncSessionData(sm, SYNC_OP_DEL, DiameterCCProxyEvent::EvASRequestUnsuccessful); // Sync
				sm.Reset(sm.sessionId,sm.appId);

				string lTempLogText = "Freeing session on UnsuccessfulASAnswer";
				DIAMETER_DEC_SESSION_CNT(lTempLogText);	
			}
		}
	};

	class AcRARequest : public DiameterCCProxyAction
	{
		void operator()(DiameterCCProxyStateMachine& sm)
		{
			if(sm.m_Msg)
			{
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_Msg);	
				AAA_LOG((LM_INFO,"%T |CC_FSM| %s [ACT]Process Re-Authentication Request\n",lLogText.c_str()));
				sm.RARequest(sm.m_Msg, sm.m_Src, *sm.m_Dest);
				//		sm.SendSyncSessionData(sm, SYNC_OP_ADD, DiameterCCProxyEvent::EvRARequest); // Sync
			}
		}
	};

	class AcSuccessfulRAAnswer : public DiameterCCProxyAction
	{
		void operator()(DiameterCCProxyStateMachine& sm)
		{
			if(sm.m_Msg)
			{
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_Msg);	
				AAA_LOG((LM_INFO,"%T |CC_FSM| %s [ACT]Received Successful Re-Authentication Answer\n",lLogText.c_str()));
				sm.RAAnswer(sm.m_Msg, sm.m_Src, *sm.m_Dest);
				//   sm.SendSyncSessionData(sm, SYNC_OP_ADD, DiameterCCProxyEvent::EvRARequestSuccessful); // Sync
			}
		}
	};

	class AcUnsuccessfulRAAnswer : public DiameterCCProxyAction
	{
		void operator()(DiameterCCProxyStateMachine& sm)
		{
			if(sm.m_Msg)
			{
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_Msg);	
				AAA_LOG((LM_INFO,"%T |CC_FSM| %s [ACT]Received Unsuccessful Re-Authentication Answer Reset \n",lLogText.c_str()));
				sm.RAAnswer(sm.m_Msg, sm.m_Src, *sm.m_Dest);
				sm.SendSyncSessionData(sm, SYNC_OP_DEL, DiameterCCProxyEvent::EvRARequestUnsuccessful); // Sync
				//sm.Reset(sm.sessionId,sm.appId); //TBC ----Nandagopi Is we need to delete session ? Not required 
			}
		}
	};

	class AcTccExpired : public DiameterCCProxyAction 
	{
		void operator()(DiameterCCProxyStateMachine& sm)
		{
			if(sm.sessionId.size() > 0)
			{
				sm.CancelTimer(DiameterCCProxyEvent::EvTccExpired);
				AAA_LOG((LM_INFO,"%T |CC_FSM| sessionId:%s appId:%d Tcc Timer Expired\n",sm.sessionId.c_str(),sm.appId));
				
				sm.TccTimeExpired(sm.sessionId, sm.appId);
	
				AAA_LOG((LM_DEBUG,"%T |CC_FSM| sessionId:%s appdId:%d Freeing session on expiry...\n",sm.sessionId.c_str(),sm.appId));

				DIAMETER_SESSION_INFO()->lock.lock();
				if(DIAMETER_SESSION_INFO()->currrentSessions > 0)
					DIAMETER_SESSION_INFO()->currrentSessions--;
				DIAMETER_SESSION_INFO()->lock.unlock();
				AAA_LOG((LM_CRITICAL,"%T |CC_FSM| sessionId:%s appId:%d Freeing session on expiry ,Reset  Sessions:(%u/%d)\n",
							sm.sessionId.c_str(), sm.appId,
							unsigned(DIAMETER_SESSION_INFO()->currrentSessions),DIAMETER_CFG_SESSION()->maxSessions));

				sm.SendSyncSessionData(sm, SYNC_OP_DEL, DiameterCCProxyEvent::EvTccExpired, true);
				sm.Reset(sm.sessionId,sm.appId);
			}
		}
	};

	class AcTxExpired : public DiameterCCProxyAction
	{
		void operator()(DiameterCCProxyStateMachine& sm)
		{
			if(sm.sessionId.size() > 0)
			{	
				sm.CancelTimer(DiameterCCProxyEvent::EvTxExpired);
				AAA_LOG((LM_INFO,"%T |CC_FSM| sessionId:%s appId:%d Tx Timer Expired\n",sm.sessionId.c_str(),sm.appId));	

				sm.SendSyncSessionData(sm, SYNC_OP_DEL, DiameterCCProxyEvent::EvTxExpired, true);
//            sm.SendSyncSessionData(sm, SYNC_OP_DEL, DiameterCCProxyEvent::EvEventRequest); // Sync
            sm.Reset(sm.sessionId,sm.appId);
			}
			//AAA_LOG((LM_INFO,"%T |CC_FSM| TBR-----------  Tx Timer Expired\n"));	
		}
	};

	enum state {
		StIdle,
		StInitialRequest,
		StUpdateRequest,
		StTerminationRequest,
		StEventRequest,
		StRARequest,
		StASRequest,
		StOpen,
		StTerminated
	};

	AAA_State GetOpenState()
	{
		return (AAA_State)StOpen;
	}

	AcInitialRequest acInitialRequest;
	AcInitialRequestRtx acInitialRequestRtx;
	AcSuccessfulInitialAnswer acSuccessfulInitialAnswer;
	AcUnsuccessfulInitialAnswer acUnsuccessfulInitialAnswer;

	AcUpdateRequest acUpdateRequest;
	AcSuccessfulUpdateAnswer acSuccessfulUpdateAnswer;
	AcUnsuccessfulUpdateAnswer acUnsuccessfulUpdateAnswer;

	AcTerminationRequest acTerminationRequest;
	AcSuccessfulTerminationAnswer acSuccessfulTerminationAnswer;
	AcUnsuccessfulTerminationAnswer acUnsuccessfulTerminationAnswer;

	AcEventRequest acEventRequest;
	AcSuccessfulEventAnswer acSuccessfulEventAnswer;
	AcUnsuccessfulEventAnswer acUnsuccessfulEventAnswer;

	AcASRequest acASRequest;
	AcSuccessfulASAnswer acSuccessfulASAnswer;
	AcUnsuccessfulASAnswer acUnsuccessfulASAnswer;

	AcRARequest acRARequest;
	AcSuccessfulRAAnswer acSuccessfulRAAnswer;
	AcUnsuccessfulRAAnswer acUnsuccessfulRAAnswer;

	AcTccExpired acTccExpired;
	AcTxExpired acTxExpired;

	AcEvInternalRspFromProxy acInternalRspFromProxy;

	// Defined as a leaf class
	DiameterCCProxyStateTable_S() 
	{
		//Idle State
		// 1. Initial  -> Initial 
		// 2. Event    -> Event Request
		// 3. Update   -> Open
		// 4. Terminate -> Terminate

		// Initial State 
		// Success -> Open
		// Failure -> Idle 

		// Event 
		// Success  -> Idle 
		// Failed 	-> Idle 

		//TBC ---------NKS added by nandagopi to handle retransmission
		AddStateTableEntry(StInitialRequest, 
				DiameterCCProxyEvent::EvInitialRequestRtx, 
				StInitialRequest, acInitialRequestRtx);

		//TBC ---------NKS added by nandagopi to handle retransmission
		AddStateTableEntry(StOpen, 
				DiameterCCProxyEvent::EvInitialRequestRtx, 
				StInitialRequest, acInitialRequestRtx);

		//TBC ---------NKS added by nandagopi to handle retransmission
		AddStateTableEntry(StIdle, 
				DiameterCCProxyEvent::EvInitialRequestRtx, 
				StInitialRequest, acInitialRequestRtx);

		AddStateTableEntry(StIdle, 
				DiameterCCProxyEvent::EvInitialRequest, 
				StInitialRequest, acInitialRequest);

		AddStateTableEntry(StIdle, 
				DiameterCCProxyEvent::EvEventRequest, 
				StEventRequest, acEventRequest);

		AddStateTableEntry(StEventRequest, 
				DiameterCCProxyEvent::EvEventRequest, //Added for retransmission 
				StEventRequest, acEventRequest);

		AddStateTableEntry(StEventRequest, 
				DiameterCCProxyEvent::EvInternalRspFromProxy,  
				StIdle, acInternalRspFromProxy);

#if 0
		AddStateTableEntry(StIdle, 
				DiameterCCProxyEvent::EvUpdateRequest, 
				StUpdateRequest, acUpdateRequest);

		AddStateTableEntry(StIdle, 
				DiameterCCProxyEvent::EvTerminationRequest, 
				StTerminationRequest, acTerminationRequest);
#endif
		AddStateTableEntry(StIdle, 
				DiameterCCProxyEvent::EvUpdateRequest, 
				StOpen , acUpdateRequest);

		AddStateTableEntry(StIdle, 
				DiameterCCProxyEvent::EvTerminationRequest, 
				StOpen , acTerminationRequest);


		AddStateTableEntry(StInitialRequest,
				DiameterCCProxyEvent::EvInitialRequestSuccessful,
				StOpen, acSuccessfulInitialAnswer);

		// Go Back to Idle 		
		AddStateTableEntry(StInitialRequest,
				DiameterCCProxyEvent::EvInitialRequestUnsuccessful,
				StIdle, acUnsuccessfulInitialAnswer);

		//-------------
		//-------------

		//AddWildcardStateTableEntry(StInitialRequest, StTerminated); //TBR commented by anshul

		AddStateTableEntry(StEventRequest,
				DiameterCCProxyEvent::EvEventRequestSuccessful,
				StIdle, acSuccessfulEventAnswer);

		AddStateTableEntry(StEventRequest,
				DiameterCCProxyEvent::EvEventRequestUnsuccessful,
				StIdle, acUnsuccessfulEventAnswer);

		//AddWildcardStateTableEntry(StEventRequest, StTerminated);

#if 0
		AddStateTableEntry(StOpen,
				DiameterCCProxyEvent::EvUpdateRequest,
				StUpdateRequest, acUpdateRequest);
#endif

		//--------------------------------------------
		AddStateTableEntry(StOpen,
				DiameterCCProxyEvent::EvUpdateRequest,
				StOpen , acUpdateRequest);
		//--------------------------------------------


		AddStateTableEntry(StOpen,
				DiameterCCProxyEvent::EvTerminationRequest,
				StOpen, acTerminationRequest);

		AddStateTableEntry(StOpen,
				DiameterCCProxyEvent::EvTerminationRequestSuccessful,
				StIdle, acSuccessfulTerminationAnswer);

		AddStateTableEntry(StOpen,
				DiameterCCProxyEvent::EvTerminationRequestUnsuccessful,
				StIdle, acUnsuccessfulTerminationAnswer);

#if 0
#endif

		AddStateTableEntry(StOpen,
				DiameterCCProxyEvent::EvTccExpired,
				StIdle, acTccExpired);

		AddStateTableEntry(StInitialRequest,
				DiameterCCProxyEvent::EvTccExpired,
				StIdle, acTccExpired);
		
		/*
		   AddStateTableEntry(StOpen,
		   DiameterCCProxyEvent::EvTxExpired,
		   StIdle, acTxExpired);
		   */

		AddStateTableEntry(StEventRequest,
				DiameterCCProxyEvent::EvTxExpired,
				StIdle, acTxExpired);

		AddStateTableEntry(StOpen,
				DiameterCCProxyEvent::EvRARequest,
				StOpen, acRARequest);

		AddStateTableEntry(StOpen,
				DiameterCCProxyEvent::EvASRequest,
				StOpen, acASRequest);

		//		AddWildcardStateTableEntry(StOpen, StTerminated);


#if 0

		AddStateTableEntry(StUpdateRequest,
				DiameterCCProxyEvent::EvUpdateRequestSuccessful,
				StOpen, acSuccessfulUpdateAnswer);

		AddStateTableEntry(StUpdateRequest,
				DiameterCCProxyEvent::EvUpdateRequestUnsuccessful,
				StIdle, acUnsuccessfulUpdateAnswer);
#endif
		//AddWildcardStateTableEntry(StUpdateRequest, StTerminated);

		//--------------------------------------------
		AddStateTableEntry(StOpen,
				DiameterCCProxyEvent::EvUpdateRequestSuccessful,
				StOpen, acSuccessfulUpdateAnswer);

		AddStateTableEntry(StOpen ,
				DiameterCCProxyEvent::EvUpdateRequestUnsuccessful,
				StIdle, acUnsuccessfulUpdateAnswer);

		//--------------------------------------------

#if 0	
		AddStateTableEntry(StTerminationRequest,
				DiameterCCProxyEvent::EvTerminationRequestSuccessful,
				StIdle, acSuccessfulTerminationAnswer);

		AddStateTableEntry(StTerminationRequest,
				DiameterCCProxyEvent::EvTerminationRequestUnsuccessful,
				StIdle, acUnsuccessfulTerminationAnswer);

		AddWildcardStateTableEntry(StTerminationRequest, StTerminated);
#endif
		AddStateTableEntry(StOpen,
				DiameterCCProxyEvent::EvRARequestSuccessful,
				StOpen, acSuccessfulRAAnswer);

		AddStateTableEntry(StOpen,
				DiameterCCProxyEvent::EvRARequestUnsuccessful,
				StOpen , acUnsuccessfulRAAnswer);

		//      AddWildcardStateTableEntry(StRARequest, StTerminated);

		AddStateTableEntry(StOpen,
				DiameterCCProxyEvent::EvASRequestSuccessful,
				StOpen, acSuccessfulASAnswer); 

		AddStateTableEntry(StOpen,
				DiameterCCProxyEvent::EvASRequestUnsuccessful,
				StIdle, acUnsuccessfulASAnswer);

		//AddWildcardStateTableEntry(StASRequest, StTerminated);

		AddWildcardStateTableEntry(StTerminated, StTerminated);

		//--------------------------- States for Sync --------------------------//

		AddStateTableEntry(StIdle,
				DiameterCCProxyEvent::EvInitialRequestSuccessful,
				StOpen);

		AddStateTableEntry(StIdle,
				DiameterCCProxyEvent::EvInitialRequestUnsuccessful,
				StIdle);

		AddStateTableEntry(StIdle,
				DiameterCCProxyEvent::EvEventRequestSuccessful,
				StIdle);
		AddStateTableEntry(StIdle,
				DiameterCCProxyEvent::EvEventRequestUnsuccessful,
				StIdle);
		/*
		   AddStateTableEntry(StIdle,
		   DiameterCCProxyEvent::EvUpdateRequest,
		   StUpdateRequest);
		   AddStateTableEntry(StIdle,
		   DiameterCCProxyEvent::EvTerminationRequest,
		   StTerminationRequest);
		   */
		AddStateTableEntry(StIdle,
				DiameterCCProxyEvent::EvTccExpired,
				StIdle);

		AddStateTableEntry(StIdle,
				DiameterCCProxyEvent::EvTxExpired,
				StIdle);

		AddStateTableEntry(StIdle,
				DiameterCCProxyEvent::EvUpdateRequestSuccessful,
				StOpen);

		AddStateTableEntry(StIdle,
				DiameterCCProxyEvent::EvUpdateRequestUnsuccessful,
				StIdle);

		AddStateTableEntry(StIdle,
				DiameterCCProxyEvent::EvTerminationRequestSuccessful,
				StIdle);
		AddStateTableEntry(StIdle,
				DiameterCCProxyEvent::EvTerminationRequestUnsuccessful,
				StIdle);

		//---------------------End of States for Sync --------------------------//
		AddWildcardStateTableEntry(StIdle, StTerminated);

		InitialState(StIdle);
	}
	~DiameterCCProxyStateTable_S() {}
};

typedef 
ACE_Singleton<DiameterCCProxyStateTable_S, ACE_Recursive_Thread_Mutex> 
DiameterCCProxyStateTable;

	DiameterCCProxyStateMachine::DiameterCCProxyStateMachine
(DiameterCCProxySession& s, ACE_Reactor &reactor, int lModuleId)
	: AAA_StateMachineWithTimer<DiameterCCProxyStateMachine>
	  (*this, *DiameterCCProxyStateTable::instance(), reactor, "AAA_CC_PROXY"),  session(s)
{
	m_Msg		 = NULL;
	mModuleId = lModuleId; // TBC HV 
}

void DiameterCCProxyStateMachine::SendSyncSessionData(DiameterCCProxyStateMachine& sm, 
		SyncOperation op, DiameterCCProxyEvent event, bool sessionTccExpiry)
{
	//if(sm.Session().SyncSessionHdlr())
	if(DIAMETER_CFG_GENERAL()->sync_session)
	{
		SyncDccaProxySessionData syncData;
		memset(&syncData, 0, sizeof(SyncDccaProxySessionData));

		syncData.op    = op;
		syncData.event = event;
		syncData.mModuleId = mModuleId;

		if ( sessionTccExpiry) 
		{
/* //On Expiry Redis data will be deleted by Key Expire
			snprintf(syncData.sessionId, 140 , "%s" , sm.sessionId.c_str() );
			syncData.appId = sm.appId;

			sm.Session().SyncSessionHdlr()->RemoveTimeoutData(syncData);
*/
		}
		else
		{
			snprintf(syncData.sessionId, 140 , "%s" , sm.m_Msg->sessionId.c_str() );
			syncData.appId = sm.m_Msg->hdr.mApplId;	

			if ( SYNC_OP_ADD == syncData.op ) 
			{
				if ( sm.m_Src )
				{
					snprintf(syncData.sourceName , 140 , "%s", sm.m_Src->PeerData().m_Identity.c_str() );
				}

				if(*sm.m_Dest)
				{
					snprintf(syncData.destName, 140 ,  "%s" , (*sm.m_Dest)->PeerData().m_Identity.c_str() ); 
				}
				AAA_LOG((LM_DEBUG,"%T |CC_FSM| SYNC_OP_ADD  SId:%s APPID:%d Mid:%d OH:%s DH:%s \n", 
							syncData.sessionId, syncData.appId,	syncData.mModuleId , syncData.sourceName ,syncData.destName ));
			}
			else
			{
				AAA_LOG((LM_DEBUG,"%T |CC_FSM| SYNC_OP_DEL  SId:%s APPID:%d Mid:%d \n", 
							syncData.sessionId, syncData.appId,	syncData.mModuleId ));
			}

			if(DIAMETER_CFG_TRANSPORT()->use_sentinel ==1 )
				sm.Session().SyncSessionHdlr()->SendSyncData(syncData);
			else 
				AAA_LOG((LM_DEBUG,"Alert: Enable Sentinel in diameter.cfg & configure DraRedisHA.cfg" ));
				//DIAMETER_SESSION_SYNC()->syncSession(syncData);
		}
	}
}

