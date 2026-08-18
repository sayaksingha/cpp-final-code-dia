
#include <ace/Singleton.h>
#include <ace/Atomic_Op_T.h>
#include "diameter_cc_proxy_session.h"
#include "diameter_cc_proxy_sd_fsm.h"
#include "diameter_cc_parser.h"
#include "diameter_cc_application.h"
#include "aaa_redis_pool.h"

class DiameterSdProxyAction : public AAA_Action<DiameterSdProxyStateMachine>
{
      virtual void operator()(DiameterSdProxyStateMachine &) = 0;

protected:
      DiameterSdProxyAction() {}
      ~DiameterSdProxyAction() {}
};

/// State table used by DiameterSdProxyStateMachine.
class DiameterSdProxyStateTable_S : public AAA_StateTable<DiameterSdProxyStateMachine>
{
      friend class ACE_Singleton<DiameterSdProxyStateTable_S, ACE_Recursive_Thread_Mutex>;

private:
      // ---- TS opens the session ----
      class AcTSRequest : public DiameterSdProxyAction
      {
              void operator()(DiameterSdProxyStateMachine &sm)
              {
                      if (sm.m_MsgSd)
                      {
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSd);
                              AAA_LOG((LM_INFO, "%T |CC_Sd_FSM| %s TSRequest Process\n", lLogText.c_str()));

                              CancelTccTimerSd(sm);
                              DIAMETER_SESSION_INFO()->lock.lock();
                              if (DIAMETER_SESSION_INFO()->currrentSessions < DIAMETER_CFG_SESSION()->maxSessions)
                                      DIAMETER_SESSION_INFO()->currrentSessions++;
                              DIAMETER_SESSION_INFO()->lock.unlock();

                              AAA_LOG((LM_CRITICAL, "%T |CC_Sd_FSM| %s TSR Received, Session Created (%u/%d)\n",
                                               lLogText.c_str(), unsigned(DIAMETER_SESSION_INFO()->currrentSessions),
                                               DIAMETER_CFG_SESSION()->maxSessions));

                              sm.TSRequest(sm.m_MsgSd, sm.m_SrcSd, *sm.m_DestSd);
                              StartTccTimerSd(sm);
                              sm.SendSyncSessionDataSd(sm, SYNC_OP_ADD, DiameterSdProxyEvent::EvTSRequestSd, false);
                      }
              }
      };

      class AcSuccessfulTSAnswer : public DiameterSdProxyAction
      {
              void operator()(DiameterSdProxyStateMachine &sm)
              {
                      if (sm.m_MsgSd)
                      {
                              CancelTccTimerSd(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSd);
                              AAA_LOG((LM_INFO, "%T |CC_Sd_FSM| %s Successful TSAnswer\n", lLogText.c_str()));
                              sm.TSAnswer(sm.m_MsgSd, sm.m_SrcSd, *sm.m_DestSd);
                              StartTccTimerSd(sm);
                      }
              }
      };

      class AcUnsuccessfulTSAnswer : public DiameterSdProxyAction
      {
              void operator()(DiameterSdProxyStateMachine &sm)
              {
                      if (sm.m_MsgSd)
                      {
                              CancelTccTimerSd(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSd);
                              AAA_LOG((LM_INFO, "%T |CC_Sd_FSM| %s Unsuccessful TSAnswer\n", lLogText.c_str()));
                              sm.TSAnswer(sm.m_MsgSd, sm.m_SrcSd, *sm.m_DestSd);

                              DIAMETER_SESSION_INFO()->lock.lock();
                              if (DIAMETER_SESSION_INFO()->currrentSessions > 0)
                                      DIAMETER_SESSION_INFO()->currrentSessions--;
                              DIAMETER_SESSION_INFO()->lock.unlock();

                              sm.SendSyncSessionDataSd(sm, SYNC_OP_DEL, DiameterSdProxyEvent::EvTccExpiredSd, false);
                              sm.Reset(sm.sessionIdSd, sm.appIdSd);
                      }
              }
      };

      // ---- CC operates mid-session (TDF -> PCRF) ----
      class AcCCRequest : public DiameterSdProxyAction
      {
              void operator()(DiameterSdProxyStateMachine &sm)
              {
                      if (sm.m_MsgSd)
                      {
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSd);
                              AAA_LOG((LM_INFO, "%T |CC_Sd_FSM| %s CCRequest Process\n", lLogText.c_str()));
                              CancelTccTimerSd(sm);
                              sm.CCRequestSd(sm.m_MsgSd, sm.m_SrcSd, *sm.m_DestSd);
                              StartTccTimerSd(sm);
                      }
              }
      };

      class AcSuccessfulCCAnswer : public DiameterSdProxyAction
      {
              void operator()(DiameterSdProxyStateMachine &sm)
              {
                      if (sm.m_MsgSd)
                      {
                              CancelTccTimerSd(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSd);
                              AAA_LOG((LM_INFO, "%T |CC_Sd_FSM| %s Successful CCAnswer\n", lLogText.c_str()));
                              sm.CCAnswerSd(sm.m_MsgSd, sm.m_SrcSd, *sm.m_DestSd);
                              StartTccTimerSd(sm);
                      }
              }
      };

      class AcUnsuccessfulCCAnswer : public DiameterSdProxyAction
      {
              void operator()(DiameterSdProxyStateMachine &sm)
              {
                      if (sm.m_MsgSd)
                      {
                              CancelTccTimerSd(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSd);
                              AAA_LOG((LM_INFO, "%T |CC_Sd_FSM| %s Unsuccessful CCAnswer\n", lLogText.c_str()));
                              sm.CCAnswerSd(sm.m_MsgSd, sm.m_SrcSd, *sm.m_DestSd);
                              StartTccTimerSd(sm);
                      }
              }
      };

      // ---- RA operates mid-session (PCRF -> TDF, re-auth) ----
      class AcRARequest : public DiameterSdProxyAction
      {
              void operator()(DiameterSdProxyStateMachine &sm)
              {
                      if (sm.m_MsgSd)
                      {
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSd);
                              AAA_LOG((LM_INFO, "%T |CC_Sd_FSM| %s RARequest Process\n", lLogText.c_str()));
                              CancelTccTimerSd(sm);
                              sm.RARequestSd(sm.m_MsgSd, sm.m_SrcSd, *sm.m_DestSd);
                              StartTccTimerSd(sm);
                      }
              }
      };

      class AcSuccessfulRAAnswer : public DiameterSdProxyAction
      {
              void operator()(DiameterSdProxyStateMachine &sm)
              {
                      if (sm.m_MsgSd)
                      {
                              CancelTccTimerSd(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSd);
                              AAA_LOG((LM_INFO, "%T |CC_Sd_FSM| %s Successful RAAnswer\n", lLogText.c_str()));
                              sm.RAAnswerSd(sm.m_MsgSd, sm.m_SrcSd, *sm.m_DestSd);
                              StartTccTimerSd(sm);
                      }
              }
      };

      class AcUnsuccessfulRAAnswer : public DiameterSdProxyAction
      {
              void operator()(DiameterSdProxyStateMachine &sm)
              {
                      if (sm.m_MsgSd)
                      {
                              CancelTccTimerSd(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSd);
                              AAA_LOG((LM_INFO, "%T |CC_Sd_FSM| %s Unsuccessful RAAnswer\n", lLogText.c_str()));
                              sm.RAAnswerSd(sm.m_MsgSd, sm.m_SrcSd, *sm.m_DestSd);
                              StartTccTimerSd(sm);
                      }
              }
      };

      // ---- TCC expiry tears the session down ----
      class AcTccExpired : public DiameterSdProxyAction
      {
              void operator()(DiameterSdProxyStateMachine &sm)
              {
                      if (sm.sessionIdSd.size() > 0)
                      {
                              CancelTccTimerSd(sm);
                              DIAMETER_SESSION_INFO()->lock.lock();
                              if (DIAMETER_SESSION_INFO()->currrentSessions > 0)
                                      DIAMETER_SESSION_INFO()->currrentSessions--;
                              DIAMETER_SESSION_INFO()->lock.unlock();
                              AAA_LOG((LM_CRITICAL, "%T |CC_Sd_FSM| sessionId:%s appId:%d Freeing session on expiry, Sessions:(%u/%d)\n",
                                               sm.sessionIdSd.c_str(), sm.appIdSd,
                                               unsigned(DIAMETER_SESSION_INFO()->currrentSessions),
                                               DIAMETER_CFG_SESSION()->maxSessions));

                              sm.SendSyncSessionDataSd(sm, SYNC_OP_DEL, DiameterSdProxyEvent::EvTccExpiredSd, true);
                              sm.Reset(sm.sessionIdSd, sm.appIdSd);
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

      AcTSRequest            acTSRequest;
      AcSuccessfulTSAnswer   acSuccessfulTSAnswer;
      AcUnsuccessfulTSAnswer acUnsuccessfulTSAnswer;

      AcCCRequest            acCCRequest;
      AcSuccessfulCCAnswer   acSuccessfulCCAnswer;
      AcUnsuccessfulCCAnswer acUnsuccessfulCCAnswer;

      AcRARequest            acRARequest;
      AcSuccessfulRAAnswer   acSuccessfulRAAnswer;
      AcUnsuccessfulRAAnswer acUnsuccessfulRAAnswer;

      AcTccExpired           acTccExpired;

      DiameterSdProxyStateTable_S()
      {
              InitialState(StIdle);

              // ========== TSR / TSA — opens the session ==========
              AddStateTableEntry(StIdle,
                      DiameterSdProxyEvent::EvTSRequestSd,
                      StOpen, acTSRequest);

              AddStateTableEntry(StOpen,
                      DiameterSdProxyEvent::EvTSRequestSd,
                      StOpen, acTSRequest);

              AddStateTableEntry(StOpen,
                      DiameterSdProxyEvent::EvTSAnswerSuccessfulSd,
                      StOpen, acSuccessfulTSAnswer);

              AddStateTableEntry(StOpen,
                      DiameterSdProxyEvent::EvTSAnswerUnsuccessfulSd,
                      StIdle, acUnsuccessfulTSAnswer);

              // ========== CCR / CCA — mid-session ==========
              AddStateTableEntry(StOpen,
                      DiameterSdProxyEvent::EvCCRequestSd,
                      StOpen, acCCRequest);

              AddStateTableEntry(StOpen,
                      DiameterSdProxyEvent::EvCCAnswerSuccessfulSd,
                      StOpen, acSuccessfulCCAnswer);

              AddStateTableEntry(StOpen,
                      DiameterSdProxyEvent::EvCCAnswerUnsuccessfulSd,
                      StOpen, acUnsuccessfulCCAnswer);

              // ========== RAR / RAA — mid-session reauth ==========
              AddStateTableEntry(StOpen,
                      DiameterSdProxyEvent::EvRARequestSd,
                      StOpen, acRARequest);

              AddStateTableEntry(StOpen,
                      DiameterSdProxyEvent::EvRARequestSuccessfulSd,
                      StOpen, acSuccessfulRAAnswer);

              AddStateTableEntry(StOpen,
                      DiameterSdProxyEvent::EvRARequestUnsuccessfulSd,
                      StOpen, acUnsuccessfulRAAnswer);

              // ========== TCC expiry tears down ==========
              AddStateTableEntry(StOpen,
                      DiameterSdProxyEvent::EvTccExpiredSd,
                      StIdle, acTccExpired);

              AddStateTableEntry(StIdle,
                      DiameterSdProxyEvent::EvTccExpiredSd,
                      StIdle, acTccExpired);
      }

      ~DiameterSdProxyStateTable_S() {}
};

typedef ACE_Singleton<DiameterSdProxyStateTable_S, ACE_Recursive_Thread_Mutex> DiameterSdProxyStateTable;

DiameterSdProxyStateMachine::DiameterSdProxyStateMachine(DiameterCCProxySession &s, ACE_Reactor &reactor, int lModuleId)
      : AAA_StateMachineWithTimer<DiameterSdProxyStateMachine>(*this, *DiameterSdProxyStateTable::instance(), reactor, "AAA_SD_FSM_PROXY"), sessionSd(s)
{
      m_MsgSd = NULL;
      mModuleIdSd = lModuleId;
}

void DiameterSdProxyStateMachine::SendSyncSessionDataSd(DiameterSdProxyStateMachine &sm, SyncOperation op, DiameterSdProxyEvent event, bool sessionTccExpiry)
{
      if (sm.SdSession().SyncSessionHdlr())
      {
              SyncDccaProxySessionData syncData;
              memset(&syncData, 0, sizeof(SyncDccaProxySessionData));

              syncData.op = op;
              syncData.event = event;
              syncData.mModuleId = sm.mModuleIdSd;

              if (sessionTccExpiry)
              {
                      // On Expiry Redis data will be deleted by Key Expire
              }
              else
              {
                      std::strncpy(syncData.sessionId, sm.m_MsgSd->sessionId.c_str(), sizeof(syncData.sessionId) - 1);
                      syncData.sessionId[sizeof(syncData.sessionId) - 1] = '\0';

                      syncData.appId = sm.m_MsgSd->hdr.mApplId;

                      if (SYNC_OP_ADD == syncData.op)
                      {
                              if (sm.m_SrcSd)
                                      snprintf(syncData.sourceName, 140, "%s", sm.m_SrcSd->PeerData().m_Identity.c_str());
                              if (*sm.m_DestSd)
                                      snprintf(syncData.destName, 140, "%s", (*sm.m_DestSd)->PeerData().m_Identity.c_str());

                              AAA_LOG((LM_DEBUG, "%T |CC_Sd_FSM| SYNC_OP_ADD  SId:%s APPID:%d Mid:%d OH:%s DH:%s \n",  syncData.sessionId, syncData.appId, syncData.mModuleId, syncData.sourceName, syncData.destName));
                      }
                      else
                      {
                              AAA_LOG((LM_DEBUG, "%T |CC_Sd_FSM| SYNC_OP_DEL  SId:%s APPID:%d Mid:%d \n",
                                               syncData.sessionId, syncData.appId, syncData.mModuleId));
                      }

                      if (DIAMETER_CFG_TRANSPORT()->use_sentinel == 1)
                              sm.SdSession().SyncSessionHdlr()->SendSyncData(syncData);
                      else
                              AAA_LOG((LM_DEBUG,"Alert: Enable Sentinel in diameter.cfg & configure DraRedisHA.cfg" ));
              }
      }
      else
      {
              AAA_LOG((LM_DEBUG, "%T |CC_Sd_FSM| Failed to get object"));
      }
}

