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
#include "diameter_cc_proxy_s6a_fsm.h"
#include "diameter_cc_parser.h"
#include "diameter_cc_application.h"
#include "aaa_redis_pool.h"

class DiameterS6aProxyAction : public AAA_Action<DiameterS6aProxyStateMachine>
{
	virtual void operator()(DiameterS6aProxyStateMachine &) = 0;

    protected:
		DiameterS6aProxyAction() {}
		~DiameterS6aProxyAction() {}
};

/// State table used by DiameterS6aProxyStateMachine.
class DiameterS6aProxyStateTable_S : public AAA_StateTable<DiameterS6aProxyStateMachine>
{
	friend class ACE_Singleton<DiameterS6aProxyStateTable_S, ACE_Recursive_Thread_Mutex>;

private:

    // Common Helper F
    
    template<typename HandlerFunc>
    static void HandleRequest(
        DiameterS6aProxyStateMachine &sm,
        const char* msgType,
        DiameterS6aProxyEvent syncEvent,
        HandlerFunc handler)
    {
        if (!sm.m_MsgS6a)
            return;

        std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgS6a);

        CancelTccTimer(sm);

        DIAMETER_SESSION_INFO()->lock.lock();
        if (DIAMETER_SESSION_INFO()->currrentSessions <
            DIAMETER_CFG_SESSION()->maxSessions)
        {
            DIAMETER_SESSION_INFO()->currrentSessions++;
        }
        DIAMETER_SESSION_INFO()->lock.unlock();

        AAA_LOG((LM_CRITICAL,
                 "%T |CC_S6a_FSM| %s %s Received, Session Created (%u/%d)\n",
                 lLogText.c_str(),
                 msgType,
                 unsigned(DIAMETER_SESSION_INFO()->currrentSessions),
                 DIAMETER_CFG_SESSION()->maxSessions));

        // Call the specific message handler
        handler(sm);

        StartTccTimer(sm);

        sm.SendSyncSessionDataS6a(
            sm,
            SYNC_OP_ADD,
            syncEvent,
            false);
    }

    // Common Answer Handler - Called by all answer actions
    // Decrements session counter, logs, syncs to Redis, resets session
    static void HandleAnswer(
        DiameterS6aProxyStateMachine &sm,
        const char* msgType)
    {
        if (!sm.m_MsgS6a)
            return;

        CancelTccTimer(sm);

        DIAMETER_SESSION_INFO()->lock.lock();
        if (DIAMETER_SESSION_INFO()->currrentSessions > 0)
            DIAMETER_SESSION_INFO()->currrentSessions--;
        DIAMETER_SESSION_INFO()->lock.unlock();

        AAA_LOG((LM_CRITICAL,
                 "%T |CC_S6a_FSM| %s Received, Session Released (%u/%d)\n",
                 msgType,
                 unsigned(DIAMETER_SESSION_INFO()->currrentSessions),
                 DIAMETER_CFG_SESSION()->maxSessions));

        sm.SendSyncSessionDataS6a(
            sm,
            SYNC_OP_DEL,
            DiameterS6aProxyEvent::EvTccExpiredS6a,
            false);

        sm.Reset(sm.sessionIdS6a, sm.appIdS6a);
    }

    // ========== Request Action Classes ==========
    
    // Update Location (ULR)
     class AcULRequest : public DiameterS6aProxyAction
    {
        void operator()(DiameterS6aProxyStateMachine &sm)
        {
            HandleRequest(sm, "ULR", DiameterS6aProxyEvent::EvULRequest,
                [](DiameterS6aProxyStateMachine &s) {
                    s.ULRequest(s.m_MsgS6a, s.m_SrcS6a, *s.m_DestS6a);
                });
        }
    };

    
    // Authentication Information Request (AIR)
    class AcAIRequest : public DiameterS6aProxyAction
    {
        void operator()(DiameterS6aProxyStateMachine &sm)
        {
            HandleRequest(sm, "AIR", DiameterS6aProxyEvent::EvAIRequest,
                [](DiameterS6aProxyStateMachine &s) {
                    s.AIRequest(s.m_MsgS6a, s.m_SrcS6a, *s.m_DestS6a);
                });
        }
    };

    // Insert Subscriber Data Request (IDR)
    class AcIDRequest : public DiameterS6aProxyAction
    {
        void operator()(DiameterS6aProxyStateMachine &sm)
        {
            HandleRequest(sm, "IDR", DiameterS6aProxyEvent::EvISDRequest,
                [](DiameterS6aProxyStateMachine &s) {
                    s.IDRequest(s.m_MsgS6a, s.m_SrcS6a, *s.m_DestS6a);
                });
        }
    };

    // Delete Subscriber Data Request (DSR)
    class AcDSRequest : public DiameterS6aProxyAction
    {
        void operator()(DiameterS6aProxyStateMachine &sm)
        {
            HandleRequest(sm, "DSR", DiameterS6aProxyEvent::EvDSRequest,
                [](DiameterS6aProxyStateMachine &s) {
                    s.DSRequest(s.m_MsgS6a, s.m_SrcS6a, *s.m_DestS6a);
                });
        }
    };

    // Reset Request (RSR)
    class AcResetRequest : public DiameterS6aProxyAction
    {
        void operator()(DiameterS6aProxyStateMachine &sm)
        {
            HandleRequest(sm, "RSR", DiameterS6aProxyEvent::EvResetRequest,
                [](DiameterS6aProxyStateMachine &s) {
                    s.ResetRequest(s.m_MsgS6a, s.m_SrcS6a, *s.m_DestS6a);
                });
        }
    };

    // Notify Request (NOR)
    class AcNotifyRequest : public DiameterS6aProxyAction
    {
        void operator()(DiameterS6aProxyStateMachine &sm)
        {
            HandleRequest(sm, "NOR", DiameterS6aProxyEvent::EvNORequest,
                [](DiameterS6aProxyStateMachine &s) {
                    s.NotifyRequest(s.m_MsgS6a, s.m_SrcS6a, *s.m_DestS6a);
                });
        }
    };
    
    // Purge UE Request (PUR)
    class AcPURequest : public DiameterS6aProxyAction
    {
        void operator()(DiameterS6aProxyStateMachine &sm)
        {
            HandleRequest(sm, "PUR", DiameterS6aProxyEvent::EvPURequest,
                [](DiameterS6aProxyStateMachine &s) {
                    s.PURequest(s.m_MsgS6a, s.m_SrcS6a, *s.m_DestS6a);
                });
        }
    };

    // Cancel Location Request (CLR)
    class AcCLRequest : public DiameterS6aProxyAction
    {
        void operator()(DiameterS6aProxyStateMachine &sm)
        {
            HandleRequest(sm, "CLR", DiameterS6aProxyEvent::EvCLRequest,
                [](DiameterS6aProxyStateMachine &s) {
                    s.CLRequest(s.m_MsgS6a, s.m_SrcS6a, *s.m_DestS6a);
                });
        }
    };

    // ========== Answer Action Classes ==========
    class AcULAnswer : public DiameterS6aProxyAction
    {
        void operator()(DiameterS6aProxyStateMachine &sm)
        {
            HandleAnswer(sm, "ULA");
        }
    };
    // Authentication Information Answer (AIA) - Terminates Session
    class AcAIAnswer : public DiameterS6aProxyAction
    {
        void operator()(DiameterS6aProxyStateMachine &sm)
        {
            HandleAnswer(sm, "AIA");
        }
    };

    // Insert Subscriber Data Answer (IDA) - Terminates Session
    class AcIDAnswer : public DiameterS6aProxyAction
    {
        void operator()(DiameterS6aProxyStateMachine &sm)
        {
            HandleAnswer(sm, "IDA");
        }
    };

    // Delete Subscriber Data Answer (DSA) - Terminates Session
    class AcDSAnswer : public DiameterS6aProxyAction
    {
        void operator()(DiameterS6aProxyStateMachine &sm)
        {
            HandleAnswer(sm, "DSA");
        }
    };

    // Reset Answer (RSA) - Terminates Session
    class AcResetAnswer : public DiameterS6aProxyAction
    {
        void operator()(DiameterS6aProxyStateMachine &sm)
        {
            HandleAnswer(sm, "RSA");
        }
    };

    // Notify Answer (NOA) - Terminates Session
    class AcNotifyAnswer : public DiameterS6aProxyAction
    {
        void operator()(DiameterS6aProxyStateMachine &sm)
        {
            HandleAnswer(sm, "NOA");
        }
    };


    // Notify Answer (NOA) - Terminates Session
    class AcPUAnswer : public DiameterS6aProxyAction
    {
        void operator()(DiameterS6aProxyStateMachine &sm)
        {
            HandleAnswer(sm, "PUA");
        }
    };

    // Notify Answer (NOA) - Terminates Session
    class AcCLAnswer : public DiameterS6aProxyAction
    {
        void operator()(DiameterS6aProxyStateMachine &sm)
        {
            HandleAnswer(sm, "CLA");
        }
    };


    
    // TCC Expiry
    class AcTccExpired : public DiameterS6aProxyAction
    {
        void operator()(DiameterS6aProxyStateMachine &sm)
        {
            if (sm.sessionIdS6a.empty())
                return;

            CancelTccTimer(sm);

            DIAMETER_SESSION_INFO()->lock.lock();
            if (DIAMETER_SESSION_INFO()->currrentSessions > 0)
                DIAMETER_SESSION_INFO()->currrentSessions--;
            DIAMETER_SESSION_INFO()->lock.unlock();

            AAA_LOG((LM_CRITICAL,
                     "%T |CC_S6a_FSM| TCC Expired, Session Freed (%u/%d)\n",
                     unsigned(DIAMETER_SESSION_INFO()->currrentSessions),
                     DIAMETER_CFG_SESSION()->maxSessions));

            sm.SendSyncSessionDataS6a(
                sm,
                SYNC_OP_DEL,
                DiameterS6aProxyEvent::EvTccExpiredS6a,
                true);

            sm.Reset(sm.sessionIdS6a, sm.appIdS6a);
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

    AcULRequest            acULRequest;
    AcAIRequest            acAIRequest;
    AcPURequest            acPURequest;
    AcCLRequest            acCLRequest;
    AcIDRequest            acIDRequest;
    AcDSRequest            acDSRequest;
    AcResetRequest         acResetRequest;
    AcNotifyRequest        acNotifyRequest;

    AcAIAnswer             acAIAnswer;
    AcIDAnswer             acIDAnswer;
    AcDSAnswer             acDSAnswer;
    AcResetAnswer          acResetAnswer;
    AcNotifyAnswer         acNotifyAnswer;
    AcULAnswer             acULAnswer;
    AcPUAnswer             acPUAnswer;
    AcCLAnswer             acCLAnswer;

    AcTccExpired           acTccExpired;
    
    // Constructor – State Table
    DiameterS6aProxyStateTable_S()
    {
          InitialState(StIdle);

        // ========== ULR / ULA ==========
        AddStateTableEntry(StIdle,
            DiameterS6aProxyEvent::EvULRequest,
            StOpen,
            acULRequest);

        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvULRequest,
            StOpen,
            acULRequest);

        // ULA terminates session
        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvULASuccessful,
            StIdle,
            acULAnswer);

        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvULAUnsuccessful,
            StIdle,
            acULAnswer);

        // ========== AIR / AIA ==========
        AddStateTableEntry(StIdle,
            DiameterS6aProxyEvent::EvAIRequest,
            StOpen,
            acAIRequest);

        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvAIRequest,
            StOpen,
            acAIRequest);

        // AIA terminates session
        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvAIASuccessful,
            StIdle,
            acAIAnswer);

        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvAIAUnsuccessful,
            StIdle,
            acAIAnswer);

        // ========== IDR / IDA ==========
        AddStateTableEntry(StIdle,
            DiameterS6aProxyEvent::EvISDRequest,
            StOpen,
            acIDRequest);

        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvISDRequest,
            StOpen,
            acIDRequest);

        // IDA terminates session
        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvISDASuccessful,
            StIdle,
            acIDAnswer);

        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvISDAUnsuccessful,
            StIdle,
            acIDAnswer);

        // ========== DSR / DSA ==========
        AddStateTableEntry(StIdle,
            DiameterS6aProxyEvent::EvDSRequest,
            StOpen,
            acDSRequest);

        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvDSRequest,
            StOpen,
            acDSRequest);

        // DSA terminates session
        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvDSASuccessful,
            StIdle,
            acDSAnswer);

        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvDSAUnsuccessful,
            StIdle,
            acDSAnswer);

        // ========== NOR / NOA ==========
        AddStateTableEntry(StIdle,
            DiameterS6aProxyEvent::EvNORequest,
            StOpen,
            acNotifyRequest);

        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvNORequest,
            StOpen,
            acNotifyRequest);

        // NOA terminates session
        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvNOASuccessful,
            StIdle,
            acNotifyAnswer);

        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvNOAUnsuccessful,
            StIdle,
            acNotifyAnswer);

        // ========== RSR / RSA ==========
        AddStateTableEntry(StIdle,
            DiameterS6aProxyEvent::EvResetRequest,
            StOpen,
            acResetRequest);

        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvResetRequest,
            StOpen,
            acResetRequest);

        // RSA terminates session
        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvResetSuccessful,
            StIdle,
            acResetAnswer);

        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvResetUnsuccessful,
            StIdle,
            acResetAnswer);

        // ========== PUR / PUA ==========
        AddStateTableEntry(StIdle,
            DiameterS6aProxyEvent::EvPURequest,
            StOpen,
            acPURequest);

        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvPURequest,
            StOpen,
            acPURequest);

        // PUA terminates session
        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvPUASuccessful,
            StIdle,
            acPUAnswer);

        // ========== CLR / CLA ==========
        AddStateTableEntry(StIdle,
            DiameterS6aProxyEvent::EvCLRequest,
            StOpen,
            acCLRequest);

        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvCLRequest,
            StOpen,
            acCLRequest);

        // CLA terminates session
        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvCLASuccessful,
            StIdle,
            acCLAnswer);

        AddStateTableEntry(StOpen,
            DiameterS6aProxyEvent::EvTccExpiredS6a,
            StIdle,
            acTccExpired);

        AddStateTableEntry(StIdle,
            DiameterS6aProxyEvent::EvTccExpiredS6a,
            StIdle,
            acTccExpired);
    
    }

    ~DiameterS6aProxyStateTable_S() {}
};

typedef ACE_Singleton<DiameterS6aProxyStateTable_S, ACE_Recursive_Thread_Mutex>
	DiameterS6aProxyStateTable;

DiameterS6aProxyStateMachine::DiameterS6aProxyStateMachine(DiameterCCProxySession &s, ACE_Reactor &reactor, int lModuleId)
	: AAA_StateMachineWithTimer<DiameterS6aProxyStateMachine>(*this, *DiameterS6aProxyStateTable::instance(), reactor, "AAA_S6A_FSM_PROXY"), sessionS6a(s)
{
	m_MsgS6a = NULL;
	mModuleIdS6a = lModuleId; // TBC HV
}

void DiameterS6aProxyStateMachine::SendSyncSessionDataS6a(DiameterS6aProxyStateMachine &sm,
														SyncOperation op, DiameterS6aProxyEvent event, bool sessionTccExpiry)
{
	if (sm.S6aSession().SyncSessionHdlr())
	{
		SyncDccaProxySessionData syncData;
		memset(&syncData, 0, sizeof(SyncDccaProxySessionData));

		syncData.op = op;
		syncData.event = event;
		syncData.mModuleId = sm.mModuleIdS6a;

		if (sessionTccExpiry)
		{
// On Expiry Redis data will be deleted by Key Expire
#if 0
						snprintf(syncData.sessionId, 140 , "%s" , sm.sessionIdS6a.c_str() );
						syncData.appId = sm.appIdS6a;	
						sm.S6aSession().SyncSessionHdlr()->RemoveTimeoutData(syncData);
#endif
		}
		else
		{
			// changed to below 2 lines - snprintf(syncData.sessionId, 140, "%s", sm.m_MsgS6a->sessionId.c_str());
			std::strncpy(syncData.sessionId, sm.m_MsgS6a->sessionId.c_str(), sizeof(syncData.sessionId) - 1);
			syncData.sessionId[sizeof(syncData.sessionId) - 1] = '\0';

			syncData.appId = sm.m_MsgS6a->hdr.mApplId;

			if (SYNC_OP_ADD == syncData.op)
			{
				if (sm.m_SrcS6a)
				{
					snprintf(syncData.sourceName, 140, "%s", sm.m_SrcS6a->PeerData().m_Identity.c_str());
				}

				if (*sm.m_DestS6a)
				{
					snprintf(syncData.destName, 140, "%s", (*sm.m_DestS6a)->PeerData().m_Identity.c_str());
				}
				AAA_LOG((LM_DEBUG, "%T |CC_S6a_FSM| SYNC_OP_ADD  SId:%s APPID:%d Mid:%d OH:%s DH:%s \n",
						 syncData.sessionId, syncData.appId, syncData.mModuleId, syncData.sourceName, syncData.destName));
			}
			else
			{
				AAA_LOG((LM_DEBUG, "%T |CC_S6a_FSM| SYNC_OP_DEL  SId:%s APPID:%d Mid:%d \n",
						 syncData.sessionId, syncData.appId, syncData.mModuleId));
			}

			if (DIAMETER_CFG_TRANSPORT()->use_sentinel == 1)
				sm.S6aSession().SyncSessionHdlr()->SendSyncData(syncData);
			else
            AAA_LOG((LM_DEBUG,"Alert: Enable Sentinel in diameter.cfg & configure DraRedisHA.cfg" ));
				//DIAMETER_SESSION_SYNC()->syncSession(syncData);
		}
	}
	else
	{
		AAA_LOG((LM_DEBUG, "%T |CC_S6a_FSM| Failed to get object"));
	}
}

