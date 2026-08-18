
#ifndef __CC_PROXY_CX_FSM_H__
#define __CC_PROXY_CX_FSM_H__

#include "framework.h"
#include "diameter_cc_parser.h"
#include "CxParser.h"
#include "DCCA_Header.h"

#ifdef WIN32
#if defined(DIAMETER_CC_PROXY_EXPORT)
#define DIAMETER_CC_PROXY_EXPORTS __declspec(dllexport)
#else
#define DIAMETER_CC_PROXY_EXPORTS __declspec(dllimport)
#endif
#else
#define DIAMETER_CC_PROXY_EXPORTS
#endif

#define DIAMETER_DEC_SESSION_CNT_CX(_AdditionalLog)                \
   DIAMETER_SESSION_INFO()->lock.lock();                          \
   if (DIAMETER_SESSION_INFO()->currrentSessions > 0)             \
      DIAMETER_SESSION_INFO()->currrentSessions--;                \
   DIAMETER_SESSION_INFO()->lock.unlock();                        \
   AAA_LOG((LM_CRITICAL, "%T |CX_FSM| %s %s, Sessions:(%d/%d)\n",  \
            lLogText.c_str(),                                     \
            _AdditionalLog.c_str(),                               \
            unsigned(DIAMETER_SESSION_INFO()->currrentSessions),  \
            DIAMETER_CFG_SESSION()->maxSessions));

class DiameterCCProxySession;

class DIAMETER_CC_PROXY_EXPORTS DiameterCxProxyStateMachine
    : public AAA_StateMachineWithTimer<DiameterCxProxyStateMachine>
{
public:
   DiameterCxProxyStateMachine(DiameterCCProxySession &s, ACE_Reactor &reactor, int);

   ~DiameterCxProxyStateMachine()
   {
      AAA_StateMachineWithTimer<DiameterCxProxyStateMachine>::Stop();
   }

   inline void CxNotify(AAA_Event ev)
   {
      Event(ev);
   }

   inline void CxNotify(AAA_Event ev,
                        DiameterMsg &msg, DiameterPeerEntry *source,
                        DiameterPeerEntry *&dest)
   {
      AAA_MutexScopeLock guard(mMutexCx);
      m_MsgCx = &msg;
      m_SrcCx = source;
      m_DestCx = &dest;
      m_Dest_asyncCx = dest;
      Event(ev);
   }

   virtual void Timeout(AAA_Event ev)
   {
      CxNotify(ev);
   }

   inline DiameterCCProxySession &CxSession() { return sessionCx; }

   virtual void Abort() = 0;

   // Cx Request/Answer virtuals — one pair per message type, overridden in Dra.cc (step 6)
   virtual void UARequestReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void UAAnswerReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void SARequestReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void SAAnswerReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void LIRequestReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void LIAnswerReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void MARequestReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void MAAnswerReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void RTRequestReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void RTAnswerReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void PPRequestReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void PPAnswerReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;

   bool RejectRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
   {
       source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
       std::string lLogText = LOG_DIAMETER_AVPS(*msg);

       switch (msg->hdr.mApplId)
       {
           case AAA_ApplicationId::AAA_Cx_APP_ID:
           {
               switch (msg->hdr.mCmdCode)
               {
                   case AAA_CommandCode::AAA_UAR_MSG:
                   {
                       CX::UserAuthorizationAnswer *rsp = new CX::UserAuthorizationAnswer;
                       rsp->setSessionId()->setValue((UINT8*)msg->sessionId.c_str(), msg->sessionId.length());
                       rsp->setOriginRealm()->setValue((UINT8*)msg->destinationRealm.c_str(), msg->destinationRealm.length());
                       rsp->setResultCode()->setValue(AAA_TOO_BUSY);
                       msg->baseClass.reset(rsp);
                       break;
                   }
                   case AAA_CommandCode::AAA_SAR_MSG:
                   {
                       CX::ServerAssignmentAnswer *rsp = new CX::ServerAssignmentAnswer;
                       rsp->setSessionId()->setValue((UINT8*)msg->sessionId.c_str(), msg->sessionId.length());
                       rsp->setOriginRealm()->setValue((UINT8*)msg->destinationRealm.c_str(), msg->destinationRealm.length());
                       rsp->setResultCode()->setValue(AAA_TOO_BUSY);
                       msg->baseClass.reset(rsp);
                       break;
                   }
                   case AAA_CommandCode::AAA_LIR_MSG:
                   {
                       CX::LocationInfoAnswer *rsp = new CX::LocationInfoAnswer;
                       rsp->setSessionId()->setValue((UINT8*)msg->sessionId.c_str(), msg->sessionId.length());
                       rsp->setOriginRealm()->setValue((UINT8*)msg->destinationRealm.c_str(), msg->destinationRealm.length());
                       rsp->setResultCode()->setValue(AAA_TOO_BUSY);
                       msg->baseClass.reset(rsp);
                       break;
                   }
                   case AAA_CommandCode::AAA_MAR_MSG:
                   {
                       CX::MultimediaAuthAnswer *rsp = new CX::MultimediaAuthAnswer;
                       rsp->setSessionId()->setValue((UINT8*)msg->sessionId.c_str(), msg->sessionId.length());
                       rsp->setOriginRealm()->setValue((UINT8*)msg->destinationRealm.c_str(), msg->destinationRealm.length());
                       rsp->setResultCode()->setValue(AAA_TOO_BUSY);
                       msg->baseClass.reset(rsp);
                       break;
                   }
                   case AAA_CommandCode::AAA_RTR_MSG:
                   {
                       CX::RegistrationTerminationAnswer *rsp = new CX::RegistrationTerminationAnswer;
                       rsp->setSessionId()->setValue((UINT8*)msg->sessionId.c_str(), msg->sessionId.length());
                       rsp->setOriginRealm()->setValue((UINT8*)msg->destinationRealm.c_str(), msg->destinationRealm.length());
                       rsp->setResultCode()->setValue(AAA_TOO_BUSY);
                       msg->baseClass.reset(rsp);
                       break;
                   }
                   case AAA_CommandCode::AAA_PPR_MSG:
                   {
                       CX::PushProfileAnswer *rsp = new CX::PushProfileAnswer;
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
               AAA_LOG((LM_ERROR, "%T |CX_FSM| %s Unsupported Application-Id:%d\n", lLogText.c_str(), msg->hdr.mApplId));
               return false;
       }

       msg->internalRspFlag  = true;
       msg->hdr.mCmdFlg.pBit = DIAMETER_FLAG_SET;
       msg->hdr.mCmdFlg.eBit = DIAMETER_FLAG_SET;
       msg->hdr.mCmdFlg.rBit = DIAMETER_FLAG_CLR;
       return true;
   }

   virtual bool Reset(const std::string &sessionId, const int &appId) { return true; };

   // Cx Request/Answer wrapper methods
   bool UARequestCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       UARequestReceivedCx(msg, source, dest);
       return true;
   };
   bool UAAnswerCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       UAAnswerReceivedCx(msg, source, dest);
       return true;
   };
   bool SARequestCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       SARequestReceivedCx(msg, source, dest);
       return true;
   };
   bool SAAnswerCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       SAAnswerReceivedCx(msg, source, dest);
       return true;
   };
   bool LIRequestCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       LIRequestReceivedCx(msg, source, dest);
       return true;
   };
   bool LIAnswerCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       LIAnswerReceivedCx(msg, source, dest);
       return true;
   };
   bool MARequestCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       MARequestReceivedCx(msg, source, dest);
       return true;
   };
   bool MAAnswerCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       MAAnswerReceivedCx(msg, source, dest);
       return true;
   };
   bool RTRequestCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       RTRequestReceivedCx(msg, source, dest);
       return true;
   };
   bool RTAnswerCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       RTAnswerReceivedCx(msg, source, dest);
       return true;
   };
   bool PPRequestCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       PPRequestReceivedCx(msg, source, dest);
       return true;
   };
   bool PPAnswerCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       PPAnswerReceivedCx(msg, source, dest);
       return true;
   };

   inline void SendSyncSessionDataCx(DiameterCxProxyStateMachine &sm, SyncOperation op,
           DiameterCxProxyEvent event, bool sessionTccExpiry = false);

private:
   DiameterCCProxySession &sessionCx;

public:
   int mModuleIdCx;
   DiameterMsg       *m_MsgCx = NULL;
   DiameterPeerEntry *m_SrcCx = NULL;
   DiameterPeerEntry **m_DestCx = NULL;
   DiameterPeerEntry *m_Dest_asyncCx = NULL;
   string            sessionIdCx = "";
   int               appIdCx;

   ACE_Mutex mMutexCx;
};

inline void CancelTccTimerCx(DiameterCxProxyStateMachine &sm)
{
   sm.CancelTimer(DiameterCxProxyEvent::EvTccExpiredCx);
}

inline void StartTccTimerCx(DiameterCxProxyStateMachine &sm)
{
   sm.ScheduleTimer(
      DiameterCxProxyEvent::EvTccExpiredCx,
      DIAMETER_CFG_ACCT_SESSION()->sessionTm,
      0,
      DiameterCxProxyEvent::EvTccExpiredCx);
}

#endif

