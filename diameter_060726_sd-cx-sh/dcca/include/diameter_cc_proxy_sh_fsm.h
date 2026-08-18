
#ifndef __CC_PROXY_SH_FSM_H__
#define __CC_PROXY_SH_FSM_H__

#include "framework.h"
#include "diameter_cc_parser.h"
#include "ShParser.h"
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

#define DIAMETER_DEC_SESSION_CNT_SH(_AdditionalLog)                \
   DIAMETER_SESSION_INFO()->lock.lock();                          \
   if (DIAMETER_SESSION_INFO()->currrentSessions > 0)             \
      DIAMETER_SESSION_INFO()->currrentSessions--;                \
   DIAMETER_SESSION_INFO()->lock.unlock();                        \
   AAA_LOG((LM_CRITICAL, "%T |SH_FSM| %s %s, Sessions:(%d/%d)\n",  \
            lLogText.c_str(),                                     \
            _AdditionalLog.c_str(),                               \
            unsigned(DIAMETER_SESSION_INFO()->currrentSessions),  \
            DIAMETER_CFG_SESSION()->maxSessions));

class DiameterCCProxySession;

class DIAMETER_CC_PROXY_EXPORTS DiameterShProxyStateMachine
    : public AAA_StateMachineWithTimer<DiameterShProxyStateMachine>
{
public:
   DiameterShProxyStateMachine(DiameterCCProxySession &s, ACE_Reactor &reactor, int);

   ~DiameterShProxyStateMachine()
   {
      AAA_StateMachineWithTimer<DiameterShProxyStateMachine>::Stop();
   }

   inline void ShNotify(AAA_Event ev)
   {
      Event(ev);
   }

   inline void ShNotify(AAA_Event ev,
                        DiameterMsg &msg, DiameterPeerEntry *source,
                        DiameterPeerEntry *&dest)
   {
      AAA_MutexScopeLock guard(mMutexSh);
      m_MsgSh = &msg;
      m_SrcSh = source;
      m_DestSh = &dest;
      m_Dest_asyncSh = dest;
      Event(ev);
   }

   virtual void Timeout(AAA_Event ev)
   {
      ShNotify(ev);
   }

   inline DiameterCCProxySession &ShSession() { return sessionSh; }

   virtual void Abort() = 0;

   // Sh Request/Answer virtuals — one pair per message type, overridden in Dra.cc (step 6)
   virtual void UDRequestReceivedSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void UDAnswerReceivedSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void PURequestReceivedSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void PUAnswerReceivedSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void SNRequestReceivedSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void SNAnswerReceivedSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void PNRequestReceivedSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void PNAnswerReceivedSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;

   bool RejectRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
   {
       source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
       std::string lLogText = LOG_DIAMETER_AVPS(*msg);

       switch (msg->hdr.mApplId)
       {
           case AAA_ApplicationId::AAA_Sh_APP_ID:
           {
               switch (msg->hdr.mCmdCode)
               {
                   case AAA_CommandCode::AAA_SH_UDR_MSG:
                   {
                       SH::UserDataAnswer *rsp = new SH::UserDataAnswer;
                       rsp->setSessionId()->setValue((UINT8*)msg->sessionId.c_str(), msg->sessionId.length());
                       rsp->setOriginRealm()->setValue((UINT8*)msg->destinationRealm.c_str(), msg->destinationRealm.length());
                       rsp->setResultCode()->setValue(AAA_TOO_BUSY);
                       msg->baseClass.reset(rsp);
                       break;
                   }
                   case AAA_CommandCode::AAA_SH_PUR_MSG:
                   {
                       SH::ProfileUpdateAnswer *rsp = new SH::ProfileUpdateAnswer;
                       rsp->setSessionId()->setValue((UINT8*)msg->sessionId.c_str(), msg->sessionId.length());
                       rsp->setOriginRealm()->setValue((UINT8*)msg->destinationRealm.c_str(), msg->destinationRealm.length());
                       rsp->setResultCode()->setValue(AAA_TOO_BUSY);
                       msg->baseClass.reset(rsp);
                       break;
                   }
                   case AAA_CommandCode::AAA_SH_SNR_MSG:
                   {
                       SH::SubscribeNotificationsAnswer *rsp = new SH::SubscribeNotificationsAnswer;
                       rsp->setSessionId()->setValue((UINT8*)msg->sessionId.c_str(), msg->sessionId.length());
                       rsp->setOriginRealm()->setValue((UINT8*)msg->destinationRealm.c_str(), msg->destinationRealm.length());
                       rsp->setResultCode()->setValue(AAA_TOO_BUSY);
                       msg->baseClass.reset(rsp);
                       break;
                   }
                   case AAA_CommandCode::AAA_SH_PNR_MSG:
                   {
                       SH::PushNotificationAnswer *rsp = new SH::PushNotificationAnswer;
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
               AAA_LOG((LM_ERROR, "%T |SH_FSM| %s Unsupported Application-Id:%d\n", lLogText.c_str(), msg->hdr.mApplId));
               return false;
       }

       msg->internalRspFlag  = true;
       msg->hdr.mCmdFlg.pBit = DIAMETER_FLAG_SET;
       msg->hdr.mCmdFlg.eBit = DIAMETER_FLAG_SET;
       msg->hdr.mCmdFlg.rBit = DIAMETER_FLAG_CLR;
       return true;
   }

   virtual bool Reset(const std::string &sessionId, const int &appId) { return true; };

   // Sh Request/Answer wrapper methods
   bool UDRequestSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       UDRequestReceivedSh(msg, source, dest);
       return true;
   };
   bool UDAnswerSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       UDAnswerReceivedSh(msg, source, dest);
       return true;
   };
   bool PURequestSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       PURequestReceivedSh(msg, source, dest);
       return true;
   };
   bool PUAnswerSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       PUAnswerReceivedSh(msg, source, dest);
       return true;
   };
   bool SNRequestSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       SNRequestReceivedSh(msg, source, dest);
       return true;
   };
   bool SNAnswerSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       SNAnswerReceivedSh(msg, source, dest);
       return true;
   };
   bool PNRequestSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       PNRequestReceivedSh(msg, source, dest);
       return true;
   };
   bool PNAnswerSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
       PNAnswerReceivedSh(msg, source, dest);
       return true;
   };

   inline void SendSyncSessionDataSh(DiameterShProxyStateMachine &sm, SyncOperation op,
           DiameterShProxyEvent event, bool sessionTccExpiry = false);

private:
   DiameterCCProxySession &sessionSh;

public:
   int mModuleIdSh;
   DiameterMsg       *m_MsgSh = NULL;
   DiameterPeerEntry *m_SrcSh = NULL;
   DiameterPeerEntry **m_DestSh = NULL;
   DiameterPeerEntry *m_Dest_asyncSh = NULL;
   string            sessionIdSh = "";
   int               appIdSh;

   ACE_Mutex mMutexSh;
};

inline void CancelTccTimerSh(DiameterShProxyStateMachine &sm)
{
   sm.CancelTimer(DiameterShProxyEvent::EvTccExpiredSh);
}

inline void StartTccTimerSh(DiameterShProxyStateMachine &sm)
{
   sm.ScheduleTimer(
      DiameterShProxyEvent::EvTccExpiredSh,
      DIAMETER_CFG_ACCT_SESSION()->sessionTm,
      0,
      DiameterShProxyEvent::EvTccExpiredSh);
}

#endif

