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

class DiameterSlhProxyAction : public AAA_Action<DiameterSlhProxyStateMachine>
{
	virtual void operator()(DiameterSlhProxyStateMachine &) = 0;

    protected:
		DiameterSlhProxyAction() {}
		~DiameterSlhProxyAction() {}
};

/// State table used by DiameterSlhProxyStateMachine.
class DiameterSlhProxyStateTable_S : public AAA_StateTable<DiameterSlhProxyStateMachine>
{
	friend class ACE_Singleton<DiameterSlhProxyStateTable_S, ACE_Recursive_Thread_Mutex>;

private:

    // Common Helper F
    
    template<typename HandlerFunc>
    static void HandleRequest(DiameterSlhProxyStateMachine &sm, const char* msgType,
        DiameterSlhProxyEvent syncEvent, HandlerFunc handler)
    {
        if (!sm.m_MsgSlh)
            return;

        std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSlh);

        CancelTccTimer(sm);

        DIAMETER_SESSION_INFO()->lock.lock();
        if (DIAMETER_SESSION_INFO()->currrentSessions < DIAMETER_CFG_SESSION()->maxSessions)
        {
            DIAMETER_SESSION_INFO()->currrentSessions++;
        }
        DIAMETER_SESSION_INFO()->lock.unlock();
        AAA_LOG((LM_INFO,
                 "%T |SLH_FSM| %s %s Received, Session Created (%u/%d)\n",
                 lLogText.c_str(),
                 msgType,
                 unsigned(DIAMETER_SESSION_INFO()->currrentSessions),
                 DIAMETER_CFG_SESSION()->maxSessions));

        // Call the specific message handler
        handler(sm);

        StartTccTimer(sm);

        sm.SendSyncSessionDataSlh(sm, SYNC_OP_ADD, syncEvent, false);
    }

    // Common Answer Handler - Called by all answer actions
    // Decrements session counter, logs, syncs to Redis, resets session
    static void HandleAnswer(DiameterSlhProxyStateMachine &sm, const char* msgType)
    {
        if (!sm.m_MsgSlh)
            return;

        CancelTccTimer(sm);

        DIAMETER_SESSION_INFO()->lock.lock();
        if (DIAMETER_SESSION_INFO()->currrentSessions > 0)
            DIAMETER_SESSION_INFO()->currrentSessions--;
        DIAMETER_SESSION_INFO()->lock.unlock();

        AAA_LOG((LM_CRITICAL,
                 "%T |SLH_FSM| %s Received, Session Released (%u/%d)\n",
                 msgType,
                 unsigned(DIAMETER_SESSION_INFO()->currrentSessions),
                 DIAMETER_CFG_SESSION()->maxSessions));

        sm.SendSyncSessionDataSlh(sm, SYNC_OP_DEL, DiameterSlhProxyEvent::EvTccExpiredSlh, false);

        sm.Reset(sm.sessionIdSlh, sm.appIdSlh);
    }

    // ========== Request Action Classes ==========
    class AcRIRequest : public DiameterSlhProxyAction
    {
        void operator()(DiameterSlhProxyStateMachine &sm)
        {
            HandleRequest(sm, "RIR", DiameterSlhProxyEvent::EvRIRequest,
                [](DiameterSlhProxyStateMachine &s) {
                    s.RIRequest(s.m_MsgSlh, s.m_SrcSlh, *s.m_DestSlh);
                });
        }
    };

    // ========== Answer Action Classes ==========
    class AcRIAnswer : public DiameterSlhProxyAction
    {
        void operator()(DiameterSlhProxyStateMachine &sm)
        {
            HandleAnswer(sm, "RIA");
        }
    };
    
    // TCC Expiry
    class AcTccExpired : public DiameterSlhProxyAction
    {
        void operator()(DiameterSlhProxyStateMachine &sm)
        {
            if (sm.sessionIdSlh.empty())
                return;

            CancelTccTimer(sm);

            DIAMETER_SESSION_INFO()->lock.lock();
            if (DIAMETER_SESSION_INFO()->currrentSessions > 0)
                DIAMETER_SESSION_INFO()->currrentSessions--;
            DIAMETER_SESSION_INFO()->lock.unlock();

            AAA_LOG((LM_CRITICAL,
                     "%T |SLH_FSM| TCC Expired, Session Freed (%u/%d)\n",
                     unsigned(DIAMETER_SESSION_INFO()->currrentSessions),
                     DIAMETER_CFG_SESSION()->maxSessions));

            sm.SendSyncSessionDataSlh(sm, SYNC_OP_DEL, DiameterSlhProxyEvent::EvTccExpiredSlh, true);

            sm.Reset(sm.sessionIdSlh, sm.appIdSlh);
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

    AcRIRequest            acRIRequest;
    AcRIAnswer             acRIAnswer;
    AcTccExpired           acTccExpired;
    
    // Constructor – State Table
    DiameterSlhProxyStateTable_S()
    {
          InitialState(StIdle);

        // ========== RIR / RIA ==========
        AddStateTableEntry(StIdle,
            DiameterSlhProxyEvent::EvRIRequest,
            StOpen,
            acRIRequest);

        AddStateTableEntry(StOpen,
            DiameterSlhProxyEvent::EvRIRequest,
            StOpen,
            acRIRequest);

        //RIA terminates session
        AddStateTableEntry(StOpen,
            DiameterSlhProxyEvent::EvRIAnswerSuccessful,
            StIdle,
            acRIAnswer);

        AddStateTableEntry(StOpen,
            DiameterSlhProxyEvent::EvRIAnswerUnsuccessful,
            StIdle,
            acRIAnswer);

        AddStateTableEntry(StOpen,
            DiameterSlhProxyEvent::EvTccExpiredSlh,
            StIdle,
            acTccExpired);

        AddStateTableEntry(StIdle,
            DiameterSlhProxyEvent::EvTccExpiredSlh,
            StIdle,
            acTccExpired);
    
    }

    ~DiameterSlhProxyStateTable_S() {}
};

typedef ACE_Singleton<DiameterSlhProxyStateTable_S, ACE_Recursive_Thread_Mutex> DiameterSlhProxyStateTable;

DiameterSlhProxyStateMachine::DiameterSlhProxyStateMachine(DiameterCCProxySession &s, ACE_Reactor &reactor, int lModuleId)
	: AAA_StateMachineWithTimer<DiameterSlhProxyStateMachine>(*this, *DiameterSlhProxyStateTable::instance(), reactor, "AAA_SLH_FSM_PROXY"), sessionSlh(s)
{
	m_MsgSlh = NULL;
	mModuleIdSlh = lModuleId; // TBC HV
}

void DiameterSlhProxyStateMachine::SendSyncSessionDataSlh(DiameterSlhProxyStateMachine &sm,
														SyncOperation op, DiameterSlhProxyEvent event, bool sessionTccExpiry)
{
	if (sm.SlhSession().SyncSessionHdlr())
	{
		SyncDccaProxySessionData syncData;
		memset(&syncData, 0, sizeof(SyncDccaProxySessionData));

		syncData.op = op;
		syncData.event = event;
		syncData.mModuleId = sm.mModuleIdSlh;

		if (sessionTccExpiry)
		{
// On Expiry Redis data will be deleted by Key Expire
#if 0
						snprintf(syncData.sessionId, 140 , "%s" , sm.sessionIdSlh.c_str() );
						syncData.appId = sm.appIdSlh;	
						sm.SlhSession().SyncSessionHdlr()->RemoveTimeoutData(syncData);
#endif
		}
		else
		{
			// changed to below 2 lines - snprintf(syncData.sessionId, 140, "%s", sm.m_MsgSlh->sessionId.c_str());
			std::strncpy(syncData.sessionId, sm.m_MsgSlh->sessionId.c_str(), sizeof(syncData.sessionId) - 1);
			syncData.sessionId[sizeof(syncData.sessionId) - 1] = '\0';

			syncData.appId = sm.m_MsgSlh->hdr.mApplId;

			if (SYNC_OP_ADD == syncData.op)
			{
				if (sm.m_SrcSlh)
				{
					snprintf(syncData.sourceName, 140, "%s", sm.m_SrcSlh->PeerData().m_Identity.c_str());
				}

				if (*sm.m_DestSlh)
				{
					snprintf(syncData.destName, 140, "%s", (*sm.m_DestSlh)->PeerData().m_Identity.c_str());
				}
				AAA_LOG((LM_DEBUG, "%T |SLH_FSM| SYNC_OP_ADD  SId:%s APPID:%d Mid:%d OH:%s DH:%s \n",
						 syncData.sessionId, syncData.appId, syncData.mModuleId, syncData.sourceName, syncData.destName));
			}
			else
			{
				AAA_LOG((LM_DEBUG, "%T |SLH_FSM| SYNC_OP_DEL  SId:%s APPID:%d Mid:%d \n",
						 syncData.sessionId, syncData.appId, syncData.mModuleId));
			}

			if (DIAMETER_CFG_TRANSPORT()->use_sentinel == 1)
				sm.SlhSession().SyncSessionHdlr()->SendSyncData(syncData);
			else
            AAA_LOG((LM_DEBUG,"Alert: Enable Sentinel in diameter.cfg & configure DraRedisHA.cfg" ));
				//DIAMETER_SESSION_SYNC()->syncSession(syncData);
		}
	}
	else
	{
		AAA_LOG((LM_DEBUG, "%T |SLH_FSM| Failed to get object"));
	}
}

