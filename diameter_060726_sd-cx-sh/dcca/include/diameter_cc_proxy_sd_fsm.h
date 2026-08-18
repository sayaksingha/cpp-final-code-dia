
#ifndef __CC_PROXY_SD_FSM_H__
#define __CC_PROXY_SD_FSM_H__

#include "framework.h"
#include "diameter_cc_parser.h"
#include "SdParser.h"
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

#define DIAMETER_DEC_SESSION_CNT_SD(_AdditionalLog)                \
   DIAMETER_SESSION_INFO()->lock.lock();                          \
   if (DIAMETER_SESSION_INFO()->currrentSessions > 0)             \
      DIAMETER_SESSION_INFO()->currrentSessions--;                \
   DIAMETER_SESSION_INFO()->lock.unlock();                        \
   AAA_LOG((LM_CRITICAL, "%T |SD_FSM| %s %s, Sessions:(%d/%d)\n",  \
            lLogText.c_str(),                                     \
            _AdditionalLog.c_str(),                               \
            unsigned(DIAMETER_SESSION_INFO()->currrentSessions),  \
            DIAMETER_CFG_SESSION()->maxSessions));

class DiameterCCProxySession;

class DIAMETER_CC_PROXY_EXPORTS DiameterSdProxyStateMachine
    : public AAA_StateMachineWithTimer<DiameterSdProxyStateMachine>
{
public:
   DiameterSdProxyStateMachine(DiameterCCProxySession &s, ACE_Reactor &reactor, int);

   ~DiameterSdProxyStateMachine()
   {
      AAA_StateMachineWithTimer<DiameterSdProxyStateMachine>::Stop();
   }

   inline void SdNotify(AAA_Event ev)
   {
      Event(ev);
   }

   inline void SdNotify(AAA_Event ev,
                        DiameterMsg &msg, DiameterPeerEntry *source,
                        DiameterPeerEntry *&dest)
   {
      AAA_MutexScopeLock guard(mMutexSd);
      m_MsgSd = &msg;
      m_SrcSd = source;
      m_DestSd = &dest;
      m_Dest_asyncSd = dest;
      Event(ev);
   }

   virtual void Timeout(AAA_Event ev)
   {
      SdNotify(ev);
   }

   inline DiameterCCProxySession &SdSession() { return sessionSd; }

   virtual void Abort() = 0;

   // Sd Request/Answer virtuals — one pair per message type, overridden in Dra.cc (step 6)
   virtual void TSRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void TSAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void CCRequestReceivedSd(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void CCAnswerReceivedSd(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void RARequestReceivedSd(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void RAAnswerReceivedSd(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;

   bool RejectRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
   {
       source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
       std::string lLogText = LOG_DIAMETER_AVPS(*msg);

       switch (msg->hdr.mApplId)
       {
           case AAA_ApplicationId::AAA_Sd_APP_ID:
           {
               switch (msg->hdr.mCmdCode)
               {
                   case AAA_CommandCode::AAA_TSR_MSG:
                   {
                       SD::TDFSessionAnswer *rsp = new SD::TDFSessionAnswer;
                       rsp->setSessionId()->setValue((UINT8*)msg->sessionId.c_str(), msg->sessionId.length());
                       rsp->setOriginRealm()->setValue((UINT8*)msg->destinationRealm.c_str(), msg->destinationRealm.length());
                       rsp->setResultCode()->setValue(AAA_TOO_BUSY);
                       msg->baseClass.reset(rsp);
                       break;
                   }
                   case AAA_CommandCode::AAA_CCR_MSG:
                   {
                       SD::CreditControlAnswer *rsp = new SD::CreditControlAnswer;
                       rsp->setSessionId()->setValue((UINT8*)msg->sessionId.c_str(), msg->sessionId.length());
                       rsp->setOriginRealm()->setValue((UINT8*)msg->destinationRealm.c_str(), msg->destinationRealm.length());
                       rsp->setResultCode()->setValue(AAA_TOO_BUSY);
                       msg->baseClass.reset(rsp);
                       break;
                   }
                   case AAA_CommandCode::AAA_RAR_MSG:
                   {
                       SD::ReAuthAnswer *rsp = new SD::ReAuthAnswer;
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
               AAA_LOG((LM_ERROR, "%T |SD_FSM| %s Unsupported Application-Id:%d\n", lLogText.c_str(), msg->hdr.mApplId));
               return false;
       }

       msg->internalRspFlag  = true;
       msg->hdr.mCmdFlg.pBit = DIAMETER_FLAG_SET;
       msg->hdr.mCmdFlg.eBit = DIAMETER_FLAG_SET;
       msg->hdr.mCmdFlg.rBit = DIAMETER_FLAG_CLR;
       return true;
   }

   virtual bool Reset(const std::string &sessionId, const int &appId) { return true; };

   // Sd Request/Answer wrapper methods
   bool TSRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       TSRequestReceived(msg, source, dest);
       return true;
   };
   bool TSAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       TSAnswerReceived(msg, source, dest);
       return true;
   };
   bool CCRequestSd(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       CCRequestReceivedSd(msg, source, dest);
       return true;
   };
   bool CCAnswerSd(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       CCAnswerReceivedSd(msg, source, dest);
       return true;
   };
   bool RARequestSd(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       RARequestReceivedSd(msg, source, dest);
       return true;
   };
   bool RAAnswerSd(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       RAAnswerReceivedSd(msg, source, dest);
       return true;
   };

   inline void SendSyncSessionDataSd(DiameterSdProxyStateMachine &sm, SyncOperation op,
           DiameterSdProxyEvent event, bool sessionTccExpiry = false);

private:
   DiameterCCProxySession &sessionSd;

public:
   int mModuleIdSd;
   DiameterMsg       *m_MsgSd = NULL;
   DiameterPeerEntry *m_SrcSd = NULL;
   DiameterPeerEntry **m_DestSd = NULL;
   DiameterPeerEntry *m_Dest_asyncSd = NULL;
   string            sessionIdSd = "";
   int               appIdSd;

   ACE_Mutex mMutexSd;
};

inline void CancelTccTimerSd(DiameterSdProxyStateMachine &sm)
{
   sm.CancelTimer(DiameterSdProxyEvent::EvTccExpiredSd);
}

inline void StartTccTimerSd(DiameterSdProxyStateMachine &sm)
{
   sm.ScheduleTimer(
      DiameterSdProxyEvent::EvTccExpiredSd,
      DIAMETER_CFG_ACCT_SESSION()->sessionTm,
      0,
      DiameterSdProxyEvent::EvTccExpiredSd);
}

#endif

