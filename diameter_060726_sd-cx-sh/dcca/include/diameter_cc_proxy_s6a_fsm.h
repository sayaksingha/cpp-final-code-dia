// @(#) $Id: diameter_cc_proxy_rx_fsm.h,v 1.1.2.2 2024/03/20 10:41:04 mrafi Exp $
//---------------------------------------------------------------
// NAME : diameter_cc_proxy_fsm.h
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
#ifndef __CC_PROXY_S6A_FSM_H__
#define __CC_PROXY_S6A_FSM_H__

#include "framework.h"
#include "diameter_cc_parser.h"
#include "S6Parser.h"
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
   AAA_LOG((LM_CRITICAL, "%T |CC_FSM| %s %s, Sessions:(%d/%d)\n", \
            lLogText.c_str(),                                     \
            _AdditionalLog.c_str(),                               \
            unsigned(DIAMETER_SESSION_INFO()->currrentSessions),  \
            DIAMETER_CFG_SESSION()->maxSessions));

class DiameterCCProxySession;

class DIAMETER_CC_PROXY_EXPORTS DiameterS6aProxyStateMachine
    : public AAA_StateMachineWithTimer<DiameterS6aProxyStateMachine>
{
public:
   /// Constructor.
   DiameterS6aProxyStateMachine(DiameterCCProxySession &s,
                               ACE_Reactor &reactor, int); // TBC

   ~DiameterS6aProxyStateMachine()
   {
      AAA_StateMachineWithTimer<DiameterS6aProxyStateMachine>::Stop();
   }

   /// Store an event and notify the session.
   inline void S6aNotify(AAA_Event ev)
   {
      Event(ev);
   }

   inline void S6aNotify(AAA_Event ev,
                        DiameterMsg &msg, DiameterPeerEntry *source,
                        DiameterPeerEntry *&dest) // throw (int)
   {
      AAA_MutexScopeLock guard(mMutexS6a);
      m_MsgS6a = &msg;
      m_SrcS6a = source;
      m_DestS6a = &dest;
      m_Dest_asyncS6a = dest;
      Event(ev);
   }

   virtual void Timeout(AAA_Event ev)
   {
      S6aNotify(ev);
   }

   /// This is used for obtaining the reference to the proxy session
   /// object.
   inline DiameterCCProxySession &S6aSession() { return sessionS6a; }

   /// This is used for aborting the state machine.  Usually called
   /// when Notify() fails.
   virtual void Abort() = 0;

   // Update Location Request/Answer (ULR/ULA)
   virtual void ULRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void ULAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;

   // Authentication Information Request/Answer (AIR/AIA)
   virtual void AIRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void AIAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;

   // Purge UE Request/Answer (PUR/PUA)
   virtual void PURequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void PUAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;

   // Cancel Location Request/Answer (CLR/CLA)
   virtual void CLRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void CLAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;

   // Insert Subscriber Data Request/Answer (IDR/IDA)
   virtual void IDRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void IDAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;

   // Delete Subscriber Data Request/Answer (DSR/DSA)
   virtual void DSRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void DSAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;

   // Reset Request/Answer (RSR/RSA)
   virtual void ResetRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void ResetAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;

   // Notify Request/Answer (NOR/NOA)
   virtual void NotifyRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void NotifyAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;

 
bool RejectRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
{
    source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
    std::string lLogText = LOG_DIAMETER_AVPS(*msg);
    
    switch (msg->hdr.mApplId)
    {
        case AAA_ApplicationId::AAA_S6_APP_ID:
        {
            switch (msg->hdr.mCmdCode)
            {
                case AAA_CommandCode::AAA_ULR_MSG:  // 316 - ULR
                {
                    S6A::UpdateLocationAnswer *rsp = new S6A::UpdateLocationAnswer;
                    rsp->setSessionId()->setValue((UINT8*)msg->sessionId.c_str(), msg->sessionId.length());
                    rsp->setOriginRealm()->setValue((UINT8*)msg->destinationRealm.c_str(), msg->destinationRealm.length());
                    rsp->setResultCode()->setValue(AAA_TOO_BUSY);
                    msg->baseClass.reset(rsp);
                    break;
                }
                case AAA_CommandCode::AAA_AIR_MSG:  // 318 - AIR
                {
                    S6A::AuthenticationInformationAnswer *rsp = new S6A::AuthenticationInformationAnswer;
                    rsp->setSessionId()->setValue((UINT8*)msg->sessionId.c_str(), msg->sessionId.length());
                    rsp->setOriginRealm()->setValue((UINT8*)msg->destinationRealm.c_str(), msg->destinationRealm.length());
                    rsp->setResultCode()->setValue(AAA_TOO_BUSY);
                    msg->baseClass.reset(rsp);
                    break;
                }
                case AAA_CommandCode::AAA_PUR_MSG:  // 321 - PUR
                {
                    S6A::PurgeUEAnswer *rsp = new S6A::PurgeUEAnswer;
                    rsp->setSessionId()->setValue((UINT8*)msg->sessionId.c_str(), msg->sessionId.length());
                    rsp->setOriginRealm()->setValue((UINT8*)msg->destinationRealm.c_str(), msg->destinationRealm.length());
                    rsp->setResultCode()->setValue(AAA_TOO_BUSY);
                    msg->baseClass.reset(rsp);
                    break;
                }
                case AAA_CommandCode::AAA_ISDR_MSG:  // 319 - IDR
                {
                    S6A::InsertSubscriberDataAnswer *rsp = new S6A::InsertSubscriberDataAnswer;
                    rsp->setSessionId()->setValue((UINT8*)msg->sessionId.c_str(), msg->sessionId.length());
                    rsp->setOriginRealm()->setValue((UINT8*)msg->destinationRealm.c_str(), msg->destinationRealm.length());
                    rsp->setResultCode()->setValue(AAA_TOO_BUSY);
                    msg->baseClass.reset(rsp);
                    break;
                }
                case AAA_CommandCode::AAA_CLR_MSG:  // 317 - CLR
                {
                    S6A::CancelLocationAnswer *rsp = new S6A::CancelLocationAnswer;
                    rsp->setSessionId()->setValue((UINT8*)msg->sessionId.c_str(), msg->sessionId.length());
                    rsp->setOriginRealm()->setValue((UINT8*)msg->destinationRealm.c_str(), msg->destinationRealm.length());
                    rsp->setResultCode()->setValue(AAA_TOO_BUSY);
                    msg->baseClass.reset(rsp);
                    break;
                }
                case AAA_CommandCode::AAA_RSR_MSG:  // 322 - RSR
                {
                    S6A::ResetAnswer *rsp = new S6A::ResetAnswer;
                    rsp->setSessionId()->setValue((UINT8*)msg->sessionId.c_str(), msg->sessionId.length());
                    rsp->setOriginRealm()->setValue((UINT8*)msg->destinationRealm.c_str(), msg->destinationRealm.length());
                    rsp->setResultCode()->setValue(AAA_TOO_BUSY);
                    msg->baseClass.reset(rsp);
                    break;
                }
                case AAA_CommandCode::AAA_NOR_MSG:  // 323 - NOR
                {
                    S6A::NotifyAnswer *rsp = new S6A::NotifyAnswer;
                    rsp->setSessionId()->setValue((UINT8*)msg->sessionId.c_str(), msg->sessionId.length());
                    rsp->setOriginRealm()->setValue((UINT8*)msg->destinationRealm.c_str(), msg->destinationRealm.length());
                    rsp->setResultCode()->setValue(AAA_TOO_BUSY);
                    msg->baseClass.reset(rsp);
                    break;
                }
                case AAA_CommandCode::AAA_DSR_MSG:  // 320 - DSR
                {
                    S6A::DeleteSubscriberDataAnswer *rsp = new S6A::DeleteSubscriberDataAnswer;
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
            AAA_LOG((LM_ERROR, "%T |CC_FSM| %s Unsupported Application-Id:%d\n", lLogText.c_str(), msg->hdr.mApplId));
            return false;
    }
    
    msg->internalRspFlag = true;
    msg->hdr.mCmdFlg.pBit = DIAMETER_FLAG_SET;
    msg->hdr.mCmdFlg.eBit = DIAMETER_FLAG_SET;
    msg->hdr.mCmdFlg.rBit = DIAMETER_FLAG_CLR;
    return true;
}

	virtual bool Reset(const std::string &sessionId, const int &appId) { return true; };

    // S6a Request/Answer wrapper methods
	bool ULRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
		ULRequestReceived(msg, source, dest);
		return true;
	};

	bool ULAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
		ULAnswerReceived(msg, source, dest);
		return true;
	};

	bool AIRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
		AIRequestReceived(msg, source, dest);
		return true;
	};

	bool AIAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
		AIAnswerReceived(msg, source, dest);
		return true;
	};

	bool PURequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
		PURequestReceived(msg, source, dest);
		return true;
	};

	bool PUAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
		PUAnswerReceived(msg, source, dest);
		return true;
	};

	bool CLRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
		CLRequestReceived(msg, source, dest);
		return true;
	};

	bool CLAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
		CLAnswerReceived(msg, source, dest);
		return true;
	};

	bool IDRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
		IDRequestReceived(msg, source, dest);
		return true;
	};

	bool IDAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
		IDAnswerReceived(msg, source, dest);
		return true;
	};

	bool DSRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
		DSRequestReceived(msg, source, dest);
		return true;
	};

	bool DSAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
		DSAnswerReceived(msg, source, dest);
		return true;
	};

	bool ResetRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
		ResetRequestReceived(msg, source, dest);
		return true;
	};

	bool ResetAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
		ResetAnswerReceived(msg, source, dest);
		return true;
	};

	bool NotifyRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
		NotifyRequestReceived(msg, source, dest);
		return true;
	};

	bool NotifyAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
		NotifyAnswerReceived(msg, source, dest);
		return true;
	};

	inline void SendSyncSessionDataS6a(DiameterS6aProxyStateMachine &sm, SyncOperation op,
			DiameterS6aProxyEvent event, bool sessionTccExpiry = false);

private:
	DiameterCCProxySession &sessionS6a;

public:
	int mModuleIdS6a;
	DiameterMsg *m_MsgS6a = NULL;
	DiameterPeerEntry *m_SrcS6a = NULL;
	DiameterPeerEntry **m_DestS6a = NULL;
	DiameterPeerEntry *m_Dest_asyncS6a = NULL;
	string sessionIdS6a = "";
   int appIdS6a;

   //shared_ptr<DiameterMsg> m_shrS6a;
   ACE_Mutex mMutexS6a;
};

//========================================================================
// To Cancel Timer
//========================================================================
inline void CancelTccTimer(DiameterS6aProxyStateMachine &sm)
{
   sm.CancelTimer(DiameterS6aProxyEvent::EvTccExpiredS6a);
}

//========================================================================
// To Start Timer
//========================================================================
inline void StartTccTimer(DiameterS6aProxyStateMachine &sm)
{
   sm.ScheduleTimer(
       DiameterS6aProxyEvent::EvTccExpiredS6a,
       DIAMETER_CFG_ACCT_SESSION()->sessionTm,
       0,
       DiameterS6aProxyEvent::EvTccExpiredS6a);
}

#endif

