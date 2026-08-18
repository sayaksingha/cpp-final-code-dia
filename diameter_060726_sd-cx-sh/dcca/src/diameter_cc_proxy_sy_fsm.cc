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

class DiameterSyProxyAction : public AAA_Action<DiameterSyProxyStateMachine>
{
	virtual void operator()(DiameterSyProxyStateMachine &) = 0;

protected:
	DiameterSyProxyAction() {}
	~DiameterSyProxyAction() {}
};

/// State table used by DiameterSyProxyStateMachine.
class DiameterSyProxyStateTable_S : public AAA_StateTable<DiameterSyProxyStateMachine>
{
	friend class ACE_Singleton<DiameterSyProxyStateTable_S, ACE_Recursive_Thread_Mutex>;

private:
	class AcSNRequest : public DiameterSyProxyAction
	{
		void operator()(DiameterSyProxyStateMachine &sm)
		{
			if (sm.m_MsgSy)
			{
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSy);
				AAA_LOG((LM_INFO, "%T |CC_Sy_FSM| %s [ACT]Process SN Request\n", lLogText.c_str()));

				CancelTccTimer(sm); // This cancels the TCC timer
				sm.SNRequest(sm.m_MsgSy, sm.m_SrcSy, *sm.m_DestSy);
				StartTccTimer(sm); // This starts the TCC timer
			}
		}
	};

	class AcSTRequest : public DiameterSyProxyAction
	{
		void operator()(DiameterSyProxyStateMachine &sm)
		{
			if (sm.m_MsgSy)
			{
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSy);
				AAA_LOG((LM_INFO, "%T |CC_Sy_FSM| %s STRequest Process\n", lLogText.c_str()));

				CancelTccTimer(sm); // This cancels the TCC timer
				sm.STRequest(sm.m_MsgSy, sm.m_SrcSy, *sm.m_DestSy);
				StartTccTimer(sm); // This starts the TCC timer
			}
		}
	};

	class AcSLRequest : public DiameterSyProxyAction
	{
		void operator()(DiameterSyProxyStateMachine &sm)
		{
			if (sm.m_MsgSy)
			{
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSy);

				CancelTccTimer(sm); // This cancels the TCC timer
				DIAMETER_SESSION_INFO()->lock.lock();
				if (DIAMETER_SESSION_INFO()->currrentSessions < DIAMETER_CFG_SESSION()->maxSessions)
					DIAMETER_SESSION_INFO()->currrentSessions++;
				DIAMETER_SESSION_INFO()->lock.unlock();

				AAA_LOG((LM_CRITICAL, "%T |CC_Sy_FSM| %s SLR Received, Started TCC, Created Session,Session:(%u/%d)\n",
						 lLogText.c_str(), unsigned(DIAMETER_SESSION_INFO()->currrentSessions),
						 DIAMETER_CFG_SESSION()->maxSessions));

				bool lReqType = reinterpret_cast<SY::SLRequest *>(sm.m_MsgSy->baseClass.get())->getSLRequestType()->getValue();
				sm.SLRequest(sm.m_MsgSy, sm.m_SrcSy, *sm.m_DestSy, lReqType);
				StartTccTimer(sm); // This starts the TCC timer
				sm.SendSyncSessionDataSy(sm, SYNC_OP_ADD, DiameterSyProxyEvent::EvSLRequest, false);
			}
		}
	};

	class AcSuccessfulASAnswer : public DiameterSyProxyAction
	{
		void operator()(DiameterSyProxyStateMachine &sm)
		{
			if (sm.m_MsgSy)
			{
				CancelTccTimer(sm); // This cancels the TCC timer
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSy);
				AAA_LOG((LM_INFO, "%T |CC_Sy_FSM| %s [ACT]Received Successful SNAnswer\n", lLogText.c_str()));
				sm.SNAnswer(sm.m_MsgSy, sm.m_SrcSy, *sm.m_DestSy);
			}
		}
	};

	class AcUnsuccessfulASAnswer : public DiameterSyProxyAction
	{
		void operator()(DiameterSyProxyStateMachine &sm)
		{
			if (sm.m_MsgSy)
			{
				CancelTccTimer(sm); // This cancels the TCC timer
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSy);
				AAA_LOG((LM_INFO, "%T |CC_Sy_FSM| %s [ACT]Received Unsuccessful SNAnswer\n", lLogText.c_str()));
				sm.SNAnswer(sm.m_MsgSy, sm.m_SrcSy, *sm.m_DestSy);
			}
		}
	};

	class AcTccExpired : public DiameterSyProxyAction
	{
		void operator()(DiameterSyProxyStateMachine &sm)
		{
			if (sm.sessionIdSy.size() > 0)
			{
				CancelTccTimer(sm); // This cancels the TCC timer
				DIAMETER_SESSION_INFO()->lock.lock();
				if (DIAMETER_SESSION_INFO()->currrentSessions > 0)
					DIAMETER_SESSION_INFO()->currrentSessions--;
				DIAMETER_SESSION_INFO()->lock.unlock();
				AAA_LOG((LM_CRITICAL, "%T |CC_Sy_FSM| sessionId:%s appId:%d Freeing session on expiry ,Reset  Sessions:(%u/%d)\n",
						 sm.sessionIdSy.c_str(), sm.appIdSy,
						 unsigned(DIAMETER_SESSION_INFO()->currrentSessions),
						 DIAMETER_CFG_SESSION()->maxSessions));

				sm.SendSyncSessionDataSy(sm, SYNC_OP_DEL, DiameterSyProxyEvent::EvTccExpiredSy, true);
				sm.Reset(sm.sessionIdSy, sm.appIdSy);
			}
		}
	};

	class AcSuccessfulAAAnswer : public DiameterSyProxyAction
	{
		void operator()(DiameterSyProxyStateMachine &sm)
		{
			if (sm.m_MsgSy)
			{
				CancelTccTimer(sm); // This cancels the TCC timer
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSy);
				AAA_LOG((LM_INFO, "%T |CC_Sy_FSM| %s Successful SLAnswer\n", lLogText.c_str()));
				// sm.SLAnswer(sm.m_MsgSy, sm.m_SrcSy, *sm.m_DestSy); Not Required
			}
		}
	};

	class AcUnsuccessfulAAAnswer : public DiameterSyProxyAction
	{
		void operator()(DiameterSyProxyStateMachine &sm)
		{
			if (sm.m_MsgSy)
			{
				CancelTccTimer(sm); // This cancels the TCC timer
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSy);
				AAA_LOG((LM_INFO, "%T |CC_Sy_FSM| %s Unsuccessful SLAnswer\n", lLogText.c_str()));
				// sm.SLAnswer(sm.m_MsgSy, sm.m_SrcSy, *sm.m_DestSy); Not Required
			}
		}
	};

	class AcSuccessfulSTAnswer : public DiameterSyProxyAction
	{
		void operator()(DiameterSyProxyStateMachine &sm)
		{
			if (sm.m_MsgSy)
			{
				CancelTccTimer(sm); // This cancels the TCC timer
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSy);
				AAA_LOG((LM_CRITICAL, "%T |CC_Sy_FSM| %s Successful STAnswer \n", lLogText.c_str()));
				// sm.STAnswer(sm.m_MsgSy, sm.m_SrcSy, *sm.m_DestSy); Not Required

				DIAMETER_SESSION_INFO()->lock.lock();
				if (DIAMETER_SESSION_INFO()->currrentSessions > 0)
					DIAMETER_SESSION_INFO()->currrentSessions--;
				DIAMETER_SESSION_INFO()->lock.unlock();
				AAA_LOG((LM_CRITICAL, "%T |CC_Sy_FSM| sessionId:%s appId:%d Freeing session on STAnswer, Sessions:(%u/%d)\n",
						 sm.sessionIdSy.c_str(), sm.appIdSy,
						 unsigned(DIAMETER_SESSION_INFO()->currrentSessions),
						 DIAMETER_CFG_SESSION()->maxSessions));

				sm.SendSyncSessionDataSy(sm, SYNC_OP_DEL, DiameterSyProxyEvent::EvTccExpiredSy, false);
				sm.Reset(sm.sessionIdSy, sm.appIdSy);
			}
		}
	};

	class AcUnsuccessfulSTAnswer : public DiameterSyProxyAction
	{
		void operator()(DiameterSyProxyStateMachine &sm)
		{
			if (sm.m_MsgSy)
			{
				CancelTccTimer(sm); // This cancels the TCC timer
				std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSy);
				AAA_LOG((LM_INFO, "%T |CC_Sy_FSM| %s Unsuccessful STAnswer \n", lLogText.c_str()));
				// sm.STAnswer(sm.m_MsgSy, sm.m_SrcSy, *sm.m_DestSy); Not Required
				sm.Reset(sm.sessionIdSy, sm.appIdSy);
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

	AcSLRequest acAARequest;
	AcSuccessfulAAAnswer acSuccessfulAAAnswer;
	AcUnsuccessfulAAAnswer acUnsuccessfulAAAnswer;

	AcSNRequest acASRequest;
	AcSuccessfulASAnswer acSuccessfulASAnswer;
	AcUnsuccessfulASAnswer acUnsuccessfulASAnswer;

	AcSTRequest acSTRequest;
	AcSuccessfulSTAnswer acSuccessfulSTAnswer;
	AcUnsuccessfulSTAnswer acUnsuccessfulSTAnswer;

	AcTccExpired acTccExpired;

	// Defined as a leaf class
	DiameterSyProxyStateTable_S()
	{

		AddStateTableEntry(StIdle,
						   DiameterSyProxyEvent::EvSLRequest,
						   StOpen, acAARequest);

		AddStateTableEntry(StOpen,
						   DiameterSyProxyEvent::EvSLRequest,
						   StOpen, acAARequest);

		AddStateTableEntry(StOpen,
						   DiameterSyProxyEvent::EvSLAnswerSuccessful,
						   StOpen, acSuccessfulAAAnswer);

		AddStateTableEntry(StOpen,
						   DiameterSyProxyEvent::EvSLAnswerUnsuccessful,
						   StOpen, acUnsuccessfulAAAnswer);

		AddStateTableEntry(StOpen,
						   DiameterSyProxyEvent::EvSNRequest,
						   StOpen, acASRequest);

				/*AddStateTableEntry(StIdle,
								   DiameterSyProxyEvent::EvSNRequest,
								   StOpen, acASRequest);*/

		AddStateTableEntry(StOpen,
						   DiameterSyProxyEvent::EvSNAnswerSuccessful,
						   StOpen, acSuccessfulASAnswer);

		AddStateTableEntry(StOpen,
						   DiameterSyProxyEvent::EvSNAnswerUnsuccessful,
						   StOpen, acUnsuccessfulASAnswer);

		AddStateTableEntry(StOpen,
						   DiameterSyProxyEvent::EvSTRequestSy,
						   StOpen, acSTRequest);

		AddStateTableEntry(StIdle,
						   DiameterSyProxyEvent::EvSTRequestSy,
						   StOpen, acSTRequest);

		AddStateTableEntry(StOpen,
						   DiameterSyProxyEvent::EvSTAnswerSuccessfulSy,
						   StIdle, acSuccessfulSTAnswer);

		AddStateTableEntry(StOpen,
						   DiameterSyProxyEvent::EvSTAnswerUnsuccessfulSy,
						   StOpen, acUnsuccessfulSTAnswer);

		AddStateTableEntry(StOpen,
						   DiameterSyProxyEvent::EvTccExpiredSy,
						   StIdle, acTccExpired);

		AddStateTableEntry(StIdle,
						   DiameterSyProxyEvent::EvTccExpiredSy,
						   StIdle, acTccExpired);

		InitialState(StIdle);
	}
	~DiameterSyProxyStateTable_S() {}
};

typedef ACE_Singleton<DiameterSyProxyStateTable_S, ACE_Recursive_Thread_Mutex>
	DiameterSyProxyStateTable;

DiameterSyProxyStateMachine::DiameterSyProxyStateMachine(DiameterCCProxySession &s, ACE_Reactor &reactor, int lModuleId)
	: AAA_StateMachineWithTimer<DiameterSyProxyStateMachine>(*this, *DiameterSyProxyStateTable::instance(), reactor, "AAA_SY_FSM_PROXY"), sessionSy(s)
{
	m_MsgSy = NULL;
	mModuleIdSy = lModuleId; // TBC HV
}

void DiameterSyProxyStateMachine::SendSyncSessionDataSy(DiameterSyProxyStateMachine &sm,
														SyncOperation op, DiameterSyProxyEvent event, bool sessionTccExpiry)
{
	if (sm.SySession().SyncSessionHdlr())
	{
		SyncDccaProxySessionData syncData;
		memset(&syncData, 0, sizeof(SyncDccaProxySessionData));

		syncData.op = op;
		syncData.event = event;
		syncData.mModuleId = mModuleIdSy;

		if (sessionTccExpiry)
		{
// On Expiry Redis data will be deleted by Key Expire
#if 0
						snprintf(syncData.sessionId, 140 , "%s" , sm.sessionIdSy.c_str() );
						syncData.appId = sm.appIdSy;	
						sm.SySession().SyncSessionHdlr()->RemoveTimeoutData(syncData);
#endif
		}
		else
		{
			// changed to below 2 lines - snprintf(syncData.sessionId, 140, "%s", sm.m_MsgSy->sessionId.c_str());
			std::strncpy(syncData.sessionId, sm.m_MsgSy->sessionId.c_str(), sizeof(syncData.sessionId) - 1);
			syncData.sessionId[sizeof(syncData.sessionId) - 1] = '\0';

			syncData.appId = sm.m_MsgSy->hdr.mApplId;

			if (SYNC_OP_ADD == syncData.op)
			{
				if (sm.m_SrcSy)
				{
					snprintf(syncData.sourceName, 140, "%s", sm.m_SrcSy->PeerData().m_Identity.c_str());
				}

				if (*sm.m_DestSy)
				{
					snprintf(syncData.destName, 140, "%s", (*sm.m_DestSy)->PeerData().m_Identity.c_str());
				}
				AAA_LOG((LM_DEBUG, "%T |CC_Sy_FSM| SYNC_OP_ADD  SId:%s APPID:%d Mid:%d OH:%s DH:%s \n",
						 syncData.sessionId, syncData.appId, syncData.mModuleId, syncData.sourceName, syncData.destName));
			}
			else
			{
				AAA_LOG((LM_DEBUG, "%T |CC_Sy_FSM| SYNC_OP_DEL  SId:%s APPID:%d Mid:%d \n",
						 syncData.sessionId, syncData.appId, syncData.mModuleId));
			}

			if (DIAMETER_CFG_TRANSPORT()->use_sentinel == 1)
				sm.SySession().SyncSessionHdlr()->SendSyncData(syncData);
			else
            AAA_LOG((LM_DEBUG,"Alert: Enable Sentinel in diameter.cfg & configure Sentinel.cfg" ));
				//DIAMETER_SESSION_SYNC()->syncSession(syncData);
		}
	}
	else
	{
		AAA_LOG((LM_DEBUG, "%T |CC_Sy_FSM| Failed to get object"));
	}
}
