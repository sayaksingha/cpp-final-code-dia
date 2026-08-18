
#include <ace/Singleton.h>
#include <ace/Atomic_Op_T.h>
#include "diameter_cc_proxy_session.h"
#include "diameter_cc_proxy_sh_fsm.h"
#include "diameter_cc_parser.h"
#include "diameter_cc_application.h"
#include "aaa_redis_pool.h"

class DiameterShProxyAction : public AAA_Action<DiameterShProxyStateMachine>
{
      virtual void operator()(DiameterShProxyStateMachine &) = 0;

protected:
      DiameterShProxyAction() {}
      ~DiameterShProxyAction() {}
};

/// State table used by DiameterShProxyStateMachine.
class DiameterShProxyStateTable_S : public AAA_StateTable<DiameterShProxyStateMachine>
{
      friend class ACE_Singleton<DiameterShProxyStateTable_S, ACE_Recursive_Thread_Mutex>;

private:
      // ---- UDR/UDA — User-Data-Request/Answer ----
      class AcUDRequest : public DiameterShProxyAction
      {
              void operator()(DiameterShProxyStateMachine &sm)
              {
                      if (sm.m_MsgSh)
                      {
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSh);
                              AAA_LOG((LM_INFO, "%T |CC_Sh_FSM| %s UDRequest Process\n", lLogText.c_str()));

                              CancelTccTimerSh(sm);
                              DIAMETER_SESSION_INFO()->lock.lock();
                              if (DIAMETER_SESSION_INFO()->currrentSessions < DIAMETER_CFG_SESSION()->maxSessions)
                                      DIAMETER_SESSION_INFO()->currrentSessions++;
                              DIAMETER_SESSION_INFO()->lock.unlock();

                              AAA_LOG((LM_CRITICAL, "%T |CC_Sh_FSM| %s UDR Received, Session Created (%u/%d)\n",
                                               lLogText.c_str(), unsigned(DIAMETER_SESSION_INFO()->currrentSessions),
                                               DIAMETER_CFG_SESSION()->maxSessions));

                              sm.UDRequestSh(sm.m_MsgSh, sm.m_SrcSh, *sm.m_DestSh);
                              StartTccTimerSh(sm);
                              sm.SendSyncSessionDataSh(sm, SYNC_OP_ADD, DiameterShProxyEvent::EvUDRequestSh, false);
                      }
              }
      };

      class AcSuccessfulUDAnswer : public DiameterShProxyAction
      {
              void operator()(DiameterShProxyStateMachine &sm)
              {
                      if (sm.m_MsgSh)
                      {
                              CancelTccTimerSh(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSh);
                              AAA_LOG((LM_INFO, "%T |CC_Sh_FSM| %s Successful UDAnswer\n", lLogText.c_str()));
                              sm.UDAnswerSh(sm.m_MsgSh, sm.m_SrcSh, *sm.m_DestSh);

                              DIAMETER_SESSION_INFO()->lock.lock();
                              if (DIAMETER_SESSION_INFO()->currrentSessions > 0)
                                      DIAMETER_SESSION_INFO()->currrentSessions--;
                              DIAMETER_SESSION_INFO()->lock.unlock();

                              sm.SendSyncSessionDataSh(sm, SYNC_OP_DEL, DiameterShProxyEvent::EvTccExpiredSh, false);
                              sm.Reset(sm.sessionIdSh, sm.appIdSh);
                      }
              }
      };

      class AcUnsuccessfulUDAnswer : public DiameterShProxyAction
      {
              void operator()(DiameterShProxyStateMachine &sm)
              {
                      if (sm.m_MsgSh)
                      {
                              CancelTccTimerSh(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSh);
                              AAA_LOG((LM_INFO, "%T |CC_Sh_FSM| %s Unsuccessful UDAnswer\n", lLogText.c_str()));
                              sm.UDAnswerSh(sm.m_MsgSh, sm.m_SrcSh, *sm.m_DestSh);

                              DIAMETER_SESSION_INFO()->lock.lock();
                              if (DIAMETER_SESSION_INFO()->currrentSessions > 0)
                                      DIAMETER_SESSION_INFO()->currrentSessions--;
                              DIAMETER_SESSION_INFO()->lock.unlock();

                              sm.SendSyncSessionDataSh(sm, SYNC_OP_DEL, DiameterShProxyEvent::EvTccExpiredSh, false);
                              sm.Reset(sm.sessionIdSh, sm.appIdSh);
                      }
              }
      };

      // ---- PUR/PUA — Profile-Update-Request/Answer ----
      class AcPURequest : public DiameterShProxyAction
      {
              void operator()(DiameterShProxyStateMachine &sm)
              {
                      if (sm.m_MsgSh)
                      {
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSh);
                              AAA_LOG((LM_INFO, "%T |CC_Sh_FSM| %s PURequest Process\n", lLogText.c_str()));
                              CancelTccTimerSh(sm);
                              sm.PURequestSh(sm.m_MsgSh, sm.m_SrcSh, *sm.m_DestSh);
                              StartTccTimerSh(sm);
                      }
              }
      };

      class AcSuccessfulPUAnswer : public DiameterShProxyAction
      {
              void operator()(DiameterShProxyStateMachine &sm)
              {
                      if (sm.m_MsgSh)
                      {
                              CancelTccTimerSh(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSh);
                              AAA_LOG((LM_INFO, "%T |CC_Sh_FSM| %s Successful PUAnswer\n", lLogText.c_str()));
                              sm.PUAnswerSh(sm.m_MsgSh, sm.m_SrcSh, *sm.m_DestSh);
                              StartTccTimerSh(sm);
                      }
              }
      };

      class AcUnsuccessfulPUAnswer : public DiameterShProxyAction
      {
              void operator()(DiameterShProxyStateMachine &sm)
              {
                      if (sm.m_MsgSh)
                      {
                              CancelTccTimerSh(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSh);
                              AAA_LOG((LM_INFO, "%T |CC_Sh_FSM| %s Unsuccessful PUAnswer\n", lLogText.c_str()));
                              sm.PUAnswerSh(sm.m_MsgSh, sm.m_SrcSh, *sm.m_DestSh);
                              StartTccTimerSh(sm);
                      }
              }
      };

      // ---- SNR/SNA — Subscribe-Notifications-Request/Answer (opens subscription) ----
      class AcSNRequest : public DiameterShProxyAction
      {
              void operator()(DiameterShProxyStateMachine &sm)
              {
                      if (sm.m_MsgSh)
                      {
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSh);
                              AAA_LOG((LM_INFO, "%T |CC_Sh_FSM| %s SNRequest Process\n", lLogText.c_str()));

                              CancelTccTimerSh(sm);
                              DIAMETER_SESSION_INFO()->lock.lock();
                              if (DIAMETER_SESSION_INFO()->currrentSessions < DIAMETER_CFG_SESSION()->maxSessions)
                                      DIAMETER_SESSION_INFO()->currrentSessions++;
                              DIAMETER_SESSION_INFO()->lock.unlock();

                              AAA_LOG((LM_CRITICAL, "%T |CC_Sh_FSM| %s SNR Received, Session Created (%u/%d)\n",
                                               lLogText.c_str(), unsigned(DIAMETER_SESSION_INFO()->currrentSessions),
                                               DIAMETER_CFG_SESSION()->maxSessions));

                              sm.SNRequestSh(sm.m_MsgSh, sm.m_SrcSh, *sm.m_DestSh);
                              StartTccTimerSh(sm);
                              sm.SendSyncSessionDataSh(sm, SYNC_OP_ADD, DiameterShProxyEvent::EvSNRequestSh, false);
                      }
              }
      };

      class AcSuccessfulSNAnswer : public DiameterShProxyAction
      {
              void operator()(DiameterShProxyStateMachine &sm)
              {
                      if (sm.m_MsgSh)
                      {
                              CancelTccTimerSh(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSh);
                              AAA_LOG((LM_INFO, "%T |CC_Sh_FSM| %s Successful SNAnswer\n", lLogText.c_str()));
                              sm.SNAnswerSh(sm.m_MsgSh, sm.m_SrcSh, *sm.m_DestSh);
                              StartTccTimerSh(sm);
                      }
              }
      };

      class AcUnsuccessfulSNAnswer : public DiameterShProxyAction
      {
              void operator()(DiameterShProxyStateMachine &sm)
              {
                      if (sm.m_MsgSh)
                      {
                              CancelTccTimerSh(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSh);
                              AAA_LOG((LM_INFO, "%T |CC_Sh_FSM| %s Unsuccessful SNAnswer\n", lLogText.c_str()));
                              sm.SNAnswerSh(sm.m_MsgSh, sm.m_SrcSh, *sm.m_DestSh);

                              DIAMETER_SESSION_INFO()->lock.lock();
                              if (DIAMETER_SESSION_INFO()->currrentSessions > 0)
                                      DIAMETER_SESSION_INFO()->currrentSessions--;
                              DIAMETER_SESSION_INFO()->lock.unlock();

                              sm.SendSyncSessionDataSh(sm, SYNC_OP_DEL, DiameterShProxyEvent::EvTccExpiredSh, false);
                              sm.Reset(sm.sessionIdSh, sm.appIdSh);
                      }
              }
      };

      // ---- PNR/PNA — Push-Notification-Request/Answer (server-initiated, mid-subscription) ----
      class AcPNRequest : public DiameterShProxyAction
      {
              void operator()(DiameterShProxyStateMachine &sm)
              {
                      if (sm.m_MsgSh)
                      {
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSh);
                              AAA_LOG((LM_INFO, "%T |CC_Sh_FSM| %s PNRequest Process\n", lLogText.c_str()));
                              CancelTccTimerSh(sm);
                              sm.PNRequestSh(sm.m_MsgSh, sm.m_SrcSh, *sm.m_DestSh);
                              StartTccTimerSh(sm);
                      }
              }
      };

      class AcSuccessfulPNAnswer : public DiameterShProxyAction
      {
              void operator()(DiameterShProxyStateMachine &sm)
              {
                      if (sm.m_MsgSh)
                      {
                              CancelTccTimerSh(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSh);
                              AAA_LOG((LM_INFO, "%T |CC_Sh_FSM| %s Successful PNAnswer\n", lLogText.c_str()));
                              sm.PNAnswerSh(sm.m_MsgSh, sm.m_SrcSh, *sm.m_DestSh);
                              StartTccTimerSh(sm);
                      }
              }
      };

      class AcUnsuccessfulPNAnswer : public DiameterShProxyAction
      {
              void operator()(DiameterShProxyStateMachine &sm)
              {
                      if (sm.m_MsgSh)
                      {
                              CancelTccTimerSh(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgSh);
                              AAA_LOG((LM_INFO, "%T |CC_Sh_FSM| %s Unsuccessful PNAnswer\n", lLogText.c_str()));
                              sm.PNAnswerSh(sm.m_MsgSh, sm.m_SrcSh, *sm.m_DestSh);
                              StartTccTimerSh(sm);
                      }
              }
      };

      // ---- TCC expiry tears the session down ----
      class AcTccExpired : public DiameterShProxyAction
      {
              void operator()(DiameterShProxyStateMachine &sm)
              {
                      if (sm.sessionIdSh.size() > 0)
                      {
                              CancelTccTimerSh(sm);
                              DIAMETER_SESSION_INFO()->lock.lock();
                              if (DIAMETER_SESSION_INFO()->currrentSessions > 0)
                                      DIAMETER_SESSION_INFO()->currrentSessions--;
                              DIAMETER_SESSION_INFO()->lock.unlock();

                              AAA_LOG((LM_CRITICAL, "%T |CC_Sh_FSM| sessionId:%s appId:%d Freeing session on expiry, Sessions:(%u/%d)\n",
                                               sm.sessionIdSh.c_str(), sm.appIdSh,
                                               unsigned(DIAMETER_SESSION_INFO()->currrentSessions),
                                               DIAMETER_CFG_SESSION()->maxSessions));

                              sm.SendSyncSessionDataSh(sm, SYNC_OP_DEL, DiameterShProxyEvent::EvTccExpiredSh, true);
                              sm.Reset(sm.sessionIdSh, sm.appIdSh);
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

      AcUDRequest            acUDRequest;
      AcSuccessfulUDAnswer   acSuccessfulUDAnswer;
      AcUnsuccessfulUDAnswer acUnsuccessfulUDAnswer;

      AcPURequest            acPURequest;
      AcSuccessfulPUAnswer   acSuccessfulPUAnswer;
      AcUnsuccessfulPUAnswer acUnsuccessfulPUAnswer;

      AcSNRequest            acSNRequest;
      AcSuccessfulSNAnswer   acSuccessfulSNAnswer;
      AcUnsuccessfulSNAnswer acUnsuccessfulSNAnswer;

      AcPNRequest            acPNRequest;
      AcSuccessfulPNAnswer   acSuccessfulPNAnswer;
      AcUnsuccessfulPNAnswer acUnsuccessfulPNAnswer;

      AcTccExpired           acTccExpired;

      DiameterShProxyStateTable_S()
      {
              InitialState(StIdle);

              // ========== UDR / UDA — standalone query, closes immediately ==========
              AddStateTableEntry(StIdle,
                      DiameterShProxyEvent::EvUDRequestSh,
                      StOpen, acUDRequest);

              AddStateTableEntry(StOpen,
                      DiameterShProxyEvent::EvUDRequestSh,
                      StOpen, acUDRequest);

              AddStateTableEntry(StOpen,
                      DiameterShProxyEvent::EvUDAnswerSuccessfulSh,
                      StIdle, acSuccessfulUDAnswer);

              AddStateTableEntry(StOpen,
                      DiameterShProxyEvent::EvUDAnswerUnsuccessfulSh,
                      StIdle, acUnsuccessfulUDAnswer);

              // ========== PUR / PUA — standalone update ==========
              AddStateTableEntry(StIdle,
                      DiameterShProxyEvent::EvPURequestSh,
                      StOpen, acPURequest);

              AddStateTableEntry(StOpen,
                      DiameterShProxyEvent::EvPURequestSh,
                      StOpen, acPURequest);

              AddStateTableEntry(StOpen,
                      DiameterShProxyEvent::EvPUAnswerSuccessfulSh,
                      StOpen, acSuccessfulPUAnswer);

              AddStateTableEntry(StOpen,
                      DiameterShProxyEvent::EvPUAnswerUnsuccessfulSh,
                      StOpen, acUnsuccessfulPUAnswer);

              // ========== SNR / SNA — opens the notification subscription ==========
              AddStateTableEntry(StIdle,
                      DiameterShProxyEvent::EvSNRequestSh,
                      StOpen, acSNRequest);

              AddStateTableEntry(StOpen,
                      DiameterShProxyEvent::EvSNRequestSh,
                      StOpen, acSNRequest);

              AddStateTableEntry(StOpen,
                      DiameterShProxyEvent::EvSNAnswerSuccessfulSh,
                      StOpen, acSuccessfulSNAnswer);

              AddStateTableEntry(StOpen,
                      DiameterShProxyEvent::EvSNAnswerUnsuccessfulSh,
                      StIdle, acUnsuccessfulSNAnswer);

              // ========== PNR / PNA — mid-subscription, server-initiated ==========
              AddStateTableEntry(StOpen,
                      DiameterShProxyEvent::EvPNRequestSh,
                      StOpen, acPNRequest);

              AddStateTableEntry(StOpen,
                      DiameterShProxyEvent::EvPNAnswerSuccessfulSh,
                      StOpen, acSuccessfulPNAnswer);

              AddStateTableEntry(StOpen,
                      DiameterShProxyEvent::EvPNAnswerUnsuccessfulSh,
                      StOpen, acUnsuccessfulPNAnswer);

              // ========== TCC expiry tears down ==========
              AddStateTableEntry(StOpen,
                      DiameterShProxyEvent::EvTccExpiredSh,
                      StIdle, acTccExpired);

              AddStateTableEntry(StIdle,
                      DiameterShProxyEvent::EvTccExpiredSh,
                      StIdle, acTccExpired);
      }

      ~DiameterShProxyStateTable_S() {}
};

typedef ACE_Singleton<DiameterShProxyStateTable_S, ACE_Recursive_Thread_Mutex> DiameterShProxyStateTable;

DiameterShProxyStateMachine::DiameterShProxyStateMachine(DiameterCCProxySession &s, ACE_Reactor &reactor, int lModuleId)
      : AAA_StateMachineWithTimer<DiameterShProxyStateMachine>(*this, *DiameterShProxyStateTable::instance(), reactor, "AAA_SH_FSM_PROXY"), sessionSh(s)
{
      m_MsgSh = NULL;
      mModuleIdSh = lModuleId;
}

void DiameterShProxyStateMachine::SendSyncSessionDataSh(DiameterShProxyStateMachine &sm,
                                                                                                              SyncOperation op, DiameterShProxyEvent event, bool sessionTccExpiry)
{
      if (sm.ShSession().SyncSessionHdlr())
      {
              SyncDccaProxySessionData syncData;
              memset(&syncData, 0, sizeof(SyncDccaProxySessionData));

              syncData.op = op;
              syncData.event = event;
              syncData.mModuleId = sm.mModuleIdSh;

              if (sessionTccExpiry)
              {
                      // On Expiry Redis data will be deleted by Key Expire
              }
              else
              {
                      std::strncpy(syncData.sessionId, sm.m_MsgSh->sessionId.c_str(), sizeof(syncData.sessionId) - 1);
                      syncData.sessionId[sizeof(syncData.sessionId) - 1] = '\0';

                      syncData.appId = sm.m_MsgSh->hdr.mApplId;

                      if (SYNC_OP_ADD == syncData.op)
                      {
                              if (sm.m_SrcSh)
                                      snprintf(syncData.sourceName, 140, "%s", sm.m_SrcSh->PeerData().m_Identity.c_str());
                              if (*sm.m_DestSh)
                                      snprintf(syncData.destName, 140, "%s", (*sm.m_DestSh)->PeerData().m_Identity.c_str());

                              AAA_LOG((LM_DEBUG, "%T |CC_Sh_FSM| SYNC_OP_ADD  SId:%s APPID:%d Mid:%d OH:%s DH:%s \n",
                                               syncData.sessionId, syncData.appId, syncData.mModuleId, syncData.sourceName, syncData.destName));
                      }
                      else
                      {
                              AAA_LOG((LM_DEBUG, "%T |CC_Sh_FSM| SYNC_OP_DEL  SId:%s APPID:%d Mid:%d \n",
                                               syncData.sessionId, syncData.appId, syncData.mModuleId));
                      }

                      if (DIAMETER_CFG_TRANSPORT()->use_sentinel == 1)
                              sm.ShSession().SyncSessionHdlr()->SendSyncData(syncData);
                      else
                              AAA_LOG((LM_DEBUG,"Alert: Enable Sentinel in diameter.cfg & configure DraRedisHA.cfg" ));
              }
      }
      else
      {
              AAA_LOG((LM_DEBUG, "%T |CC_Sh_FSM| Failed to get object"));
      }
}

