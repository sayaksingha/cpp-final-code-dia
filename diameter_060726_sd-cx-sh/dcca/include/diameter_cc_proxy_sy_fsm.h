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
#ifndef __CC_PROXY_SY_FSM_H__
#define __CC_PROXY_SY_FSM_H__

#include "framework.h"
#include "diameter_cc_parser.h"
#include "SyParser.h"
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

class DIAMETER_CC_PROXY_EXPORTS DiameterSyProxyStateMachine
    : public AAA_StateMachineWithTimer<DiameterSyProxyStateMachine>
{
public:
   /// Constructor.
   DiameterSyProxyStateMachine(DiameterCCProxySession &s,
                               ACE_Reactor &reactor, int); // TBC

   ~DiameterSyProxyStateMachine()
   {
      AAA_StateMachineWithTimer<DiameterSyProxyStateMachine>::Stop();
   }

   /// Store an event and notify the session.
   inline void SyNotify(AAA_Event ev)
   {
      Event(ev);
   }

   inline void SyNotify(AAA_Event ev,
                        DiameterMsg &msg, DiameterPeerEntry *source,
                        DiameterPeerEntry *&dest) // throw (int)
   {
      AAA_MutexScopeLock guard(mMutexSy);
      m_MsgSy = &msg;
      m_SrcSy = source;
      m_DestSy = &dest;
      m_Dest_asyncSy = dest;
      Event(ev);
   }

   virtual void Timeout(AAA_Event ev)
   {
      SyNotify(ev);
   }

   /// This is used for obtaining the reference to the proxy session
   /// object.
   inline DiameterCCProxySession &SySession() { return sessionSy; }

   /// This is used for aborting the state machine.  Usually called
   /// when Notify() fails.
   virtual void Abort() = 0;

   virtual void SLRequestInitial(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void SLAnswerInitialSuccess(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void SLAnswerInitialFailed(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;

   virtual void SLRequestIntermediate(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void SLAnswerIntermediateSuccess(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void SLAnswerIntermediateFailed(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;

   virtual void SNRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void SNAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;

   virtual void STRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void STAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;

   bool RejectRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
   {
      source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
      std::string lLogText = LOG_DIAMETER_AVPS(*msg);
      switch (msg->hdr.mApplId)
      {
			case AAA_ApplicationId::AAA_Sy_APP_ID:
				{
					switch (msg->hdr.mCmdCode)
					{
						case AAA_CommandCode::AAA_SLR_MSG:
							{
								SY::SLAnswer *rsp = new SY::SLAnswer;
								rsp->setSessionId()->setValue((UINT8 *)msg->sessionId.c_str(), msg->sessionId.length());
								rsp->setOriginRealm()->setValue((UINT8 *)msg->destinationRealm.c_str(), msg->destinationRealm.length());
								rsp->setResultCode()->setValue(AAA_TOO_BUSY);
								msg->baseClass.reset(rsp);
							}
						case AAA_CommandCode::AAA_STR_MSG:
							{
								SY::STAnswer *rsp = new SY::STAnswer;
								rsp->setSessionId()->setValue((UINT8 *)msg->sessionId.c_str(), msg->sessionId.length());
								rsp->setOriginRealm()->setValue((UINT8 *)msg->destinationRealm.c_str(), msg->destinationRealm.length());
								rsp->setResultCode()->setValue(AAA_TOO_BUSY);
								msg->baseClass.reset(rsp);
							}
							break;
						default:
							break;
					}
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


	bool SLRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest, bool initial = true)
	{
		if (!initial)
			SLRequestInitial(msg, source, dest);
		else
			SLRequestIntermediate(msg, source, dest);
		return true;
	};

	bool SLAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest, bool initial = true, bool success = true)
	{
		if (!initial && success)
			SLAnswerInitialSuccess(msg, source, dest);
		else if (initial && !success)
			SLAnswerInitialFailed(msg, source, dest);
		else if (initial && success)
			SLAnswerIntermediateSuccess(msg, source, dest);
		else
			SLAnswerIntermediateFailed(msg, source, dest);
		return true;
	};

	bool STRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
	{
		STRequestReceived(msg, source, dest);
		return true;
	};

	bool STAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
	{
		STAnswerReceived(msg, source, dest);
		return true;
	};

	bool SNRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
	{
		SNRequestReceived(msg, source, dest);
		return true;
	};

	bool SNAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
	{
		//   SNAnswerReceived(msg, source, dest); Not Requried...
		return true;
	};

	inline void SendSyncSessionDataSy(DiameterSyProxyStateMachine &sm, SyncOperation op,
			DiameterSyProxyEvent event, bool sessionTccExpiry = false);

private:
	DiameterCCProxySession &sessionSy;

public:
	int mModuleIdSy;
	DiameterMsg *m_MsgSy = NULL;
	DiameterPeerEntry *m_SrcSy = NULL;
	DiameterPeerEntry **m_DestSy = NULL;
	DiameterPeerEntry *m_Dest_asyncSy = NULL;
	string sessionIdSy = "";
   int appIdSy;

   //shared_ptr<DiameterMsg> m_shrSy;
   ACE_Mutex mMutexSy;
};

//========================================================================
// To Cancel Timer
//========================================================================
inline void CancelTccTimer(DiameterSyProxyStateMachine &sm)
{
   sm.CancelTimer(DiameterSyProxyEvent::EvTccExpiredSy);
}

//========================================================================
// To Start Timer
//========================================================================
inline void StartTccTimer(DiameterSyProxyStateMachine &sm)
{
   sm.ScheduleTimer(
       DiameterSyProxyEvent::EvTccExpiredSy,
       DIAMETER_CFG_ACCT_SESSION()->sessionTm,
       0,
       DiameterSyProxyEvent::EvTccExpiredSy);
}

#endif
