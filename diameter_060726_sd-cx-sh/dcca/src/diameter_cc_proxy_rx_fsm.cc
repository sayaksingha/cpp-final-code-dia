//----------------------------------------------------------------------
// NAME
// diameter_cc_proxy_rx_fsm.cc
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
#include "diameter_cc_proxy_rx_fsm.h"
#include "diameter_cc_parser.h"
#include "diameter_cc_application.h"
#include "aaa_redis_pool.h"

class DiameterRxProxyAction : public AAA_Action<DiameterRxProxyStateMachine>
{
	virtual void operator()(DiameterRxProxyStateMachine &) = 0;

protected:
	DiameterRxProxyAction() {}
	~DiameterRxProxyAction() {}
};

/// State table used by DiameterRxProxyStateMachine.
class DiameterRxProxyStateTable_S : public AAA_StateTable<DiameterRxProxyStateMachine>
{
	friend class ACE_Singleton<DiameterRxProxyStateTable_S, ACE_Recursive_Thread_Mutex>;

private:
	class AcASRequest : public DiameterRxProxyAction
	{
		void operator()(DiameterRxProxyStateMachine &sm)
		{
			if (sm.m_MsgRx)
			{
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgRx);
				AAA_LOG((LM_INFO, "%T |CC_Rx_FSM| %s [ACT]Process Abort Session Request\n", lLogText.c_str()));

				CancelTccTimer(sm); // This cancels the TCC timer
				sm.ASRequest(sm.m_MsgRx, sm.m_SrcRx, *sm.m_DestRx);
				StartTccTimer(sm);	// This starts the TCC timer
			}
		}
	};

	class AcSTRequest : public DiameterRxProxyAction
	{
		void operator()(DiameterRxProxyStateMachine &sm)
		{
			if (sm.m_MsgRx)
			{
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgRx);
				AAA_LOG((LM_INFO, "%T |CC_Rx_FSM| %s STRequest Process\n", lLogText.c_str()));

				CancelTccTimer(sm); // This cancels the TCC timer
				sm.STRequest(sm.m_MsgRx, sm.m_SrcRx, *sm.m_DestRx);
				StartTccTimer(sm);	// This starts the TCC timer
			}
		}
	};

	class AcAARequest : public DiameterRxProxyAction
	{
		void operator()(DiameterRxProxyStateMachine &sm)
		{
			if (sm.m_MsgRx)
			{
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgRx);

				CancelTccTimer(sm); // This cancels the TCC timer
				DIAMETER_SESSION_INFO()->lock.lock();
				if (DIAMETER_SESSION_INFO()->currrentSessions < DIAMETER_CFG_SESSION()->maxSessions)
					DIAMETER_SESSION_INFO()->currrentSessions++;
				DIAMETER_SESSION_INFO()->lock.unlock();

				AAA_LOG((LM_CRITICAL, "%T |CC_Rx_FSM| %s AAR Received, Started TCC, Created Session,Session:(%u/%d)\n",
						 lLogText.c_str(), unsigned(DIAMETER_SESSION_INFO()->currrentSessions),
						 DIAMETER_CFG_SESSION()->maxSessions));

				sm.AARequest(sm.m_MsgRx, sm.m_SrcRx, *sm.m_DestRx);
				StartTccTimer(sm);	// This starts the TCC timer
				sm.SendSyncSessionDataRx(sm, SYNC_OP_ADD, DiameterRxProxyEvent::EvAARequest, false);
			}
		}
	};

	class AcSuccessfulASAnswer : public DiameterRxProxyAction
	{
		void operator()(DiameterRxProxyStateMachine &sm)
		{
			if (sm.m_MsgRx)
			{
				CancelTccTimer(sm); // This cancels the TCC timer
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgRx);
				AAA_LOG((LM_INFO, "%T |CC_Rx_FSM| %s [ACT]Received Successful Abort Session Answer\n", lLogText.c_str()));
				sm.ASAnswer(sm.m_MsgRx, sm.m_SrcRx, *sm.m_DestRx);
			}
		}
	};

	class AcUnsuccessfulASAnswer : public DiameterRxProxyAction
	{
		void operator()(DiameterRxProxyStateMachine &sm)
		{
			if (sm.m_MsgRx)
			{
				CancelTccTimer(sm); // This cancels the TCC timer
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgRx);
				AAA_LOG((LM_INFO, "%T |CC_Rx_FSM| %s [ACT]Received Unsuccessful Abort Session Answer\n", lLogText.c_str()));
				sm.ASAnswer(sm.m_MsgRx, sm.m_SrcRx, *sm.m_DestRx);
			}
		}
	};

	class AcRARequest : public DiameterRxProxyAction
	{
		void operator()(DiameterRxProxyStateMachine &sm)
		{
			if (sm.m_MsgRx)
			{
				CancelTccTimer(sm); // This cancels the TCC timer
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgRx);
				AAA_LOG((LM_INFO, "%T |CC_Rx_FSM| %s [ACT]Process Re-Authentication Request\n", lLogText.c_str()));
				sm.RARequest(sm.m_MsgRx, sm.m_SrcRx, *sm.m_DestRx);
				StartTccTimer(sm);	// This starts the TCC timer
			}
		}
	};

	class AcSuccessfulRAAnswer : public DiameterRxProxyAction
	{
		void operator()(DiameterRxProxyStateMachine &sm)
		{
			if (sm.m_MsgRx)
			{
				CancelTccTimer(sm); // This cancels the TCC timer
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgRx);
				AAA_LOG((LM_INFO, "%T |CC_Rx_FSM| %s [ACT]Received Successful Re-Authentication Answer\n", lLogText.c_str()));
				sm.RAAnswer(sm.m_MsgRx, sm.m_SrcRx, *sm.m_DestRx);
			}
		}
	};

	class AcUnsuccessfulRAAnswer : public DiameterRxProxyAction
	{
		void operator()(DiameterRxProxyStateMachine &sm)
		{
			if (sm.m_MsgRx)
			{
				CancelTccTimer(sm); // This cancels the TCC timer
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgRx);
				AAA_LOG((LM_INFO, "%T |CC_Rx_FSM| %s [ACT]Received Unsuccessful Re-Authentication Answer \n", lLogText.c_str()));
				sm.RAAnswer(sm.m_MsgRx, sm.m_SrcRx, *sm.m_DestRx);
			}
		}
	};

	class AcTccExpired : public DiameterRxProxyAction
	{
		void operator()(DiameterRxProxyStateMachine &sm)
		{
			if (sm.sessionIdRx.size() > 0)
			{
				CancelTccTimer(sm); // This cancels the TCC timer
				DIAMETER_SESSION_INFO()->lock.lock();
				if (DIAMETER_SESSION_INFO()->currrentSessions > 0)
					DIAMETER_SESSION_INFO()->currrentSessions--;
				DIAMETER_SESSION_INFO()->lock.unlock();
				AAA_LOG((LM_CRITICAL, "%T |CC_Rx_FSM| sessionId:%s appId:%d Freeing session on expiry ,Reset  Sessions:(%u/%d)\n",
						 sm.sessionIdRx.c_str(), sm.appIdRx,
						 unsigned(DIAMETER_SESSION_INFO()->currrentSessions),
						 DIAMETER_CFG_SESSION()->maxSessions));

				sm.SendSyncSessionDataRx(sm, SYNC_OP_DEL, DiameterRxProxyEvent::EvTccExpiredRx, true);
				sm.Reset(sm.sessionIdRx, sm.appIdRx);
			}
		}
	};

	class AcSuccessfulAAAnswer : public DiameterRxProxyAction
	{
		void operator()(DiameterRxProxyStateMachine &sm)
		{
			if (sm.m_MsgRx)
			{
				CancelTccTimer(sm); // This cancels the TCC timer
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgRx);
				AAA_LOG((LM_INFO, "%T |CC_Rx_FSM| %s Successful AAAnswer\n", lLogText.c_str()));
				sm.AAAnswer(sm.m_MsgRx, sm.m_SrcRx, *sm.m_DestRx);
			}
		}
	};

	class AcUnsuccessfulAAAnswer : public DiameterRxProxyAction
	{
		void operator()(DiameterRxProxyStateMachine &sm)
		{
			if (sm.m_MsgRx)
			{
				CancelTccTimer(sm); // This cancels the TCC timer
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgRx);
				AAA_LOG((LM_INFO, "%T |CC_Rx_FSM| %s Unsuccessful AAAnswer\n", lLogText.c_str()));
				sm.AAAnswer(sm.m_MsgRx, sm.m_SrcRx, *sm.m_DestRx);
			}
		}
	};

	class AcSuccessfulSTAnswer : public DiameterRxProxyAction
	{
		void operator()(DiameterRxProxyStateMachine &sm)
		{
			if (sm.m_MsgRx)
			{
				CancelTccTimer(sm); // This cancels the TCC timer
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgRx);
				AAA_LOG((LM_CRITICAL, "%T |CC_Rx_FSM| %s Successful STAnswer \n", lLogText.c_str()));
				sm.STAnswer(sm.m_MsgRx, sm.m_SrcRx, *sm.m_DestRx);

				DIAMETER_SESSION_INFO()->lock.lock();
				if (DIAMETER_SESSION_INFO()->currrentSessions > 0)
					DIAMETER_SESSION_INFO()->currrentSessions--;
				DIAMETER_SESSION_INFO()->lock.unlock();
				AAA_LOG((LM_CRITICAL, "%T |CC_Rx_FSM| sessionId:%s appId:%d Freeing session on STAnswer, Sessions:(%u/%d)\n",
						 sm.sessionIdRx.c_str(), sm.appIdRx,
						 unsigned(DIAMETER_SESSION_INFO()->currrentSessions),
						 DIAMETER_CFG_SESSION()->maxSessions));

				sm.SendSyncSessionDataRx(sm, SYNC_OP_DEL, DiameterRxProxyEvent::EvTccExpiredRx, false);
				sm.Reset(sm.sessionIdRx, sm.appIdRx);
			}
		}
	};

	class AcUnsuccessfulSTAnswer : public DiameterRxProxyAction
	{
		void operator()(DiameterRxProxyStateMachine &sm)
		{
			if (sm.m_MsgRx)
			{
				CancelTccTimer(sm); // This cancels the TCC timer
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgRx);
				AAA_LOG((LM_INFO, "%T |CC_Rx_FSM| %s Unsuccessful STAnswer \n", lLogText.c_str()));
				sm.STAnswer(sm.m_MsgRx, sm.m_SrcRx, *sm.m_DestRx);
				sm.Reset(sm.sessionIdRx, sm.appIdRx);
			}
		}
	};

	enum state
	{
		StIdle,
		StOpen
	};

	AAA_State GetOpenState()
	{
		return (AAA_State)StOpen;
	}

	AcAARequest acAARequest;
	AcSuccessfulAAAnswer acSuccessfulAAAnswer;
	AcUnsuccessfulAAAnswer acUnsuccessfulAAAnswer;

	AcASRequest acASRequest;
	AcSuccessfulASAnswer acSuccessfulASAnswer;
	AcUnsuccessfulASAnswer acUnsuccessfulASAnswer;

	AcSTRequest acSTRequest;
	AcSuccessfulSTAnswer acSuccessfulSTAnswer;
	AcUnsuccessfulSTAnswer acUnsuccessfulSTAnswer;

	AcRARequest acRARequest;
	AcSuccessfulRAAnswer acSuccessfulRAAnswer;
	AcUnsuccessfulRAAnswer acUnsuccessfulRAAnswer;

	AcTccExpired acTccExpired;

	// Defined as a leaf class
	DiameterRxProxyStateTable_S()
	{

		AddStateTableEntry(StIdle,
						   DiameterRxProxyEvent::EvAARequest,
						   StOpen, acAARequest);

		AddStateTableEntry(StOpen,
						   DiameterRxProxyEvent::EvAARequest,
						   StOpen, acAARequest);

		AddStateTableEntry(StOpen,
						   DiameterRxProxyEvent::EvAARequestSuccessful,
						   StOpen, acSuccessfulAAAnswer);

		AddStateTableEntry(StOpen,
						   DiameterRxProxyEvent::EvAARequestUnsuccessful,
						   StOpen, acUnsuccessfulAAAnswer);

		AddStateTableEntry(StOpen,
						   DiameterRxProxyEvent::EvASRequestRx,
						   StOpen, acASRequest);

		AddStateTableEntry(StOpen,
						   DiameterRxProxyEvent::EvASRequestSuccessfulRx,
						   StOpen, acSuccessfulASAnswer);

		AddStateTableEntry(StOpen,
						   DiameterRxProxyEvent::EvASRequestUnsuccessfulRx,
						   StOpen, acUnsuccessfulASAnswer);

		AddStateTableEntry(StOpen,
						   DiameterRxProxyEvent::EvSTRequest,
						   StOpen, acSTRequest);

		AddStateTableEntry(StOpen,
						   DiameterRxProxyEvent::EvSTRequestSuccessful,
						   StIdle, acSuccessfulSTAnswer);

		AddStateTableEntry(StOpen,
						   DiameterRxProxyEvent::EvSTRequestUnsuccessful,
						   StOpen, acUnsuccessfulSTAnswer);

		AddStateTableEntry(StOpen,
						   DiameterRxProxyEvent::EvRARequestRx,
						   StOpen, acRARequest);

		AddStateTableEntry(StOpen,
						   DiameterRxProxyEvent::EvRARequestSuccessfulRx,
						   StOpen, acSuccessfulRAAnswer);

		AddStateTableEntry(StOpen,
						   DiameterRxProxyEvent::EvRARequestUnsuccessfulRx,
						   StOpen, acUnsuccessfulRAAnswer);

		AddStateTableEntry(StOpen,
						   DiameterRxProxyEvent::EvTccExpiredRx,
						   StIdle, acTccExpired);

		AddStateTableEntry(StIdle,
						   DiameterRxProxyEvent::EvTccExpiredRx,
						   StIdle, acTccExpired);

		InitialState(StIdle);
	}
	~DiameterRxProxyStateTable_S() {}
};

typedef ACE_Singleton<DiameterRxProxyStateTable_S, ACE_Recursive_Thread_Mutex>
	DiameterRxProxyStateTable;

DiameterRxProxyStateMachine::DiameterRxProxyStateMachine(DiameterCCProxySession &s, ACE_Reactor &reactor, int lModuleId)
	: AAA_StateMachineWithTimer<DiameterRxProxyStateMachine>(*this, *DiameterRxProxyStateTable::instance(), reactor, "AAA_CC_RX_PROXY"), sessionRx(s)
{
	m_MsgRx = NULL;
	mModuleIdRx = lModuleId; // TBC HV
}

void DiameterRxProxyStateMachine::SendSyncSessionDataRx(DiameterRxProxyStateMachine &sm,
														SyncOperation op, DiameterRxProxyEvent event, bool sessionTccExpiry)
{
	if (sm.RxSession().SyncSessionHdlr())
	{
		SyncDccaProxySessionData syncData;
		memset(&syncData, 0, sizeof(SyncDccaProxySessionData));

		syncData.op = op;
		syncData.event = event;
		syncData.mModuleId = mModuleIdRx;

		if (sessionTccExpiry)
		{
			// On Expiry Redis data will be deleted by Key Expire
			#if 0
						snprintf(syncData.sessionId, 140 , "%s" , sm.sessionIdRx.c_str() );
						syncData.appId = sm.appIdRx;	
						sm.RxSession().SyncSessionHdlr()->RemoveTimeoutData(syncData);
			#endif
		}
		else
		{
			//changed to below 2 lines - snprintf(syncData.sessionId, 140, "%s", sm.m_MsgRx->sessionId.c_str());
         std::strncpy(syncData.sessionId, sm.m_MsgRx->sessionId.c_str(), sizeof(syncData.sessionId) - 1);
         syncData.sessionId[sizeof(syncData.sessionId) - 1] = '\0';

			syncData.appId = sm.m_MsgRx->hdr.mApplId;

			if (SYNC_OP_ADD == syncData.op)
			{
				if (sm.m_SrcRx)
				{
					snprintf(syncData.sourceName, 140, "%s", sm.m_SrcRx->PeerData().m_Identity.c_str());
				}

				if (*sm.m_DestRx)
				{
					snprintf(syncData.destName, 140, "%s", (*sm.m_DestRx)->PeerData().m_Identity.c_str());
				}
				AAA_LOG((LM_DEBUG, "%T |CC_Rx_FSM| SYNC_OP_ADD  SId:%s APPID:%d Mid:%d OH:%s DH:%s \n",
						 syncData.sessionId, syncData.appId, syncData.mModuleId, syncData.sourceName, syncData.destName));
			}
			else
			{
				AAA_LOG((LM_DEBUG, "%T |CC_Rx_FSM| SYNC_OP_DEL  SId:%s APPID:%d Mid:%d \n",
						 syncData.sessionId, syncData.appId, syncData.mModuleId));
			}

			if (DIAMETER_CFG_TRANSPORT()->use_sentinel == 1)
				sm.RxSession().SyncSessionHdlr()->SendSyncData(syncData);
			else
            AAA_LOG((LM_DEBUG,"Alert: Enable Sentinel in diameter.cfg & configure Sentinel.cfg" ));
				//DIAMETER_SESSION_SYNC()->syncSession(syncData);
		}
	}
	else
	{
		AAA_LOG((LM_DEBUG, "%T |CC_Rx_FSM| Failed to get object"));
	}
}
