// @(#) $Id: diameter_cc_proxy_slh_fsm.h,v 1.1.2.2 2024/03/20 10:41:04 mrafi Exp $
//---------------------------------------------------------------
// NAME : diameter_cc_proxy_slh_fsm.h
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
#ifndef __CC_PROXY_SLH_FSM_H__
#define __CC_PROXY_SLH_FSM_H__

#include "framework.h"
#include "diameter_cc_parser.h"
#include "SlhParser.h"
#include "DCCA_Header.h"

#ifdef WIN32
#if defined(DIAMETER_CC_PROXY_EXPORT)
#define DIAMETER_CC_PROXY_EXPORTS __declspec(dllexport)
#else
#define DIAMETER_CC_PROXY_EXPORTS __declspec(dllimport)
#endif
#else
#define DIAMETER_CC_PROXY_EXPORTS
#define DIAMETER_CC_PROXY_EXPORTS
#endif

#define DIAMETER_DEC_SESSION_CNT(_AdditionalLog)                  \
   DIAMETER_SESSION_INFO()->lock.lock();                          \
   if (DIAMETER_SESSION_INFO()->currrentSessions > 0)             \
      DIAMETER_SESSION_INFO()->currrentSessions--;                \
   DIAMETER_SESSION_INFO()->lock.unlock();                        \
   AAA_LOG((LM_CRITICAL, "%T |SLH_FSM| %s %s, Sessions:(%d/%d)\n", \
            lLogText.c_str(),                                     \
            _AdditionalLog.c_str(),                               \
            unsigned(DIAMETER_SESSION_INFO()->currrentSessions),  \
            DIAMETER_CFG_SESSION()->maxSessions));

class DiameterCCProxySession;

class DIAMETER_CC_PROXY_EXPORTS DiameterSlhProxyStateMachine
    : public AAA_StateMachineWithTimer<DiameterSlhProxyStateMachine>
{
public:
   /// Constructor.
   DiameterSlhProxyStateMachine(DiameterCCProxySession &s,  ACE_Reactor &reactor, int); // TBC

   ~DiameterSlhProxyStateMachine()
   {
      AAA_StateMachineWithTimer<DiameterSlhProxyStateMachine>::Stop();
   }

   /// Store an event and notify the session.
   inline void SlhNotify(AAA_Event ev)
   {
      Event(ev);
   }

   inline void SlhNotify(AAA_Event ev,
                        DiameterMsg &msg, DiameterPeerEntry *source,
                        DiameterPeerEntry *&dest) // throw (int)
   {
      AAA_MutexScopeLock guard(mMutexSlh);
      m_MsgSlh = &msg;
      m_SrcSlh = source;
      m_DestSlh = &dest;
      m_Dest_asyncSlh = dest;
      Event(ev);
   }

   virtual void Timeout(AAA_Event ev)
   {
      SlhNotify(ev);
   }

   /// This is used for obtaining the reference to the proxy session
   /// object.
   inline DiameterCCProxySession &SlhSession() { return sessionSlh; }

   /// This is used for aborting the state machine.  Usually called
   /// when Notify() fails.
   virtual void Abort() = 0;

   virtual void RIRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void RIAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;


 
bool RejectRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
{
    source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
    std::string lLogText = LOG_DIAMETER_AVPS(*msg);
    
    switch (msg->hdr.mApplId)
    {
        case AAA_ApplicationId::AAA_Slh_APP_ID:
        {
            switch (msg->hdr.mCmdCode)
            {
                case AAA_CommandCode::AAA_RIR_MSG:  
                {
                    SLH:: LCSRoutingInfoAnswer *rsp = new SLH::LCSRoutingInfoAnswer;
                    rsp->setSessionId()->setValue((UINT8*)msg->sessionId.c_str(), msg->sessionId.length());
                    rsp->setOriginRealm()->setValue((UINT8*)msg->destinationRealm.c_str(), msg->destinationRealm.length());
                    rsp->setResultCode()->setValue(AAA_TOO_BUSY);
                    msg->baseClass.reset(rsp);
                    break;
                }
                default:
                break;
            }
            break;
        }
        default:
            AAA_LOG((LM_ERROR, "%T |SLH_FSM| %s Unsupported Application-Id:%d\n", lLogText.c_str(), msg->hdr.mApplId));
            return false;
    }
    
    msg->internalRspFlag  = true;
    msg->hdr.mCmdFlg.pBit = DIAMETER_FLAG_SET;
    msg->hdr.mCmdFlg.eBit = DIAMETER_FLAG_SET;
    msg->hdr.mCmdFlg.rBit = DIAMETER_FLAG_CLR;
    return true;
}

   virtual bool Reset(const std::string &sessionId, const int &appId) { return true; };

   // Slh Request/Answer wrapper methods
	bool RIRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
		RIRequestReceived(msg, source, dest);
		return true;
	};

	bool RIAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
		RIAnswerReceived(msg, source, dest);
		return true;
	};

	inline void SendSyncSessionDataSlh(DiameterSlhProxyStateMachine &sm, SyncOperation op,
			DiameterSlhProxyEvent event, bool sessionTccExpiry = false);

private:
	DiameterCCProxySession &sessionSlh;

public:
   int mModuleIdSlh;
	DiameterMsg       *m_MsgSlh = NULL;
	DiameterPeerEntry *m_SrcSlh = NULL;
	DiameterPeerEntry **m_DestSlh = NULL;
	DiameterPeerEntry *m_Dest_asyncSlh = NULL;
	string            sessionIdSlh = "";
   int               appIdSlh;

   //shared_ptr<DiameterMsg> m_shrSlh;
   ACE_Mutex mMutexSlh;
};

//========================================================================
// To Cancel Timer
//========================================================================
inline void CancelTccTimer(DiameterSlhProxyStateMachine &sm)
{
   sm.CancelTimer(DiameterSlhProxyEvent::EvTccExpiredSlh);
}

//========================================================================
// To Start Timer
//========================================================================
inline void StartTccTimer(DiameterSlhProxyStateMachine &sm)
{
   sm.ScheduleTimer(
      DiameterSlhProxyEvent::EvTccExpiredSlh,
      DIAMETER_CFG_ACCT_SESSION()->sessionTm,
      0,
      DiameterSlhProxyEvent::EvTccExpiredSlh);
}

#endif

