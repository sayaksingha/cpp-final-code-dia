
#include <ace/Singleton.h>
#include <ace/Atomic_Op_T.h>
#include "diameter_cc_proxy_session.h"
#include "diameter_cc_proxy_cx_fsm.h"
#include "diameter_cc_parser.h"
#include "diameter_cc_application.h"
#include "aaa_redis_pool.h"

class DiameterCxProxyAction : public AAA_Action<DiameterCxProxyStateMachine>
{
      virtual void operator()(DiameterCxProxyStateMachine &) = 0;

protected:
      DiameterCxProxyAction() {}
      ~DiameterCxProxyAction() {}
};

/// State table used by DiameterCxProxyStateMachine.
class DiameterCxProxyStateTable_S : public AAA_StateTable<DiameterCxProxyStateMachine>
{
      friend class ACE_Singleton<DiameterCxProxyStateTable_S, ACE_Recursive_Thread_Mutex>;

private:
      // ---- UAR/UAA — User-Authorization-Request/Answer ----
      class AcUARequest : public DiameterCxProxyAction
      {
              void operator()(DiameterCxProxyStateMachine &sm)
              {
                      if (sm.m_MsgCx)
                      {
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgCx);
                              AAA_LOG((LM_INFO, "%T |CC_Cx_FSM| %s UARequest Process\n", lLogText.c_str()));
                              CancelTccTimerCx(sm);
                              sm.UARequestCx(sm.m_MsgCx, sm.m_SrcCx, *sm.m_DestCx);
                              StartTccTimerCx(sm);
                      }
              }
      };

      class AcSuccessfulUAAnswer : public DiameterCxProxyAction
      {
              void operator()(DiameterCxProxyStateMachine &sm)
              {
                      if (sm.m_MsgCx)
                      {
                              CancelTccTimerCx(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgCx);
                              AAA_LOG((LM_INFO, "%T |CC_Cx_FSM| %s Successful UAAnswer\n", lLogText.c_str()));
                              sm.UAAnswerCx(sm.m_MsgCx, sm.m_SrcCx, *sm.m_DestCx);
                      }
              }
      };

      class AcUnsuccessfulUAAnswer : public DiameterCxProxyAction
      {
              void operator()(DiameterCxProxyStateMachine &sm)
              {
                      if (sm.m_MsgCx)
                      {
                              CancelTccTimerCx(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgCx);
                              AAA_LOG((LM_INFO, "%T |CC_Cx_FSM| %s Unsuccessful UAAnswer\n", lLogText.c_str()));
                              sm.UAAnswerCx(sm.m_MsgCx, sm.m_SrcCx, *sm.m_DestCx);
                      }
              }
      };

      // ---- SAR/SAA — Server-Assignment-Request/Answer ----
      class AcSARequest : public DiameterCxProxyAction
      {
              void operator()(DiameterCxProxyStateMachine &sm)
              {
                      if (sm.m_MsgCx)
                      {
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgCx);
                              AAA_LOG((LM_INFO, "%T |CC_Cx_FSM| %s SARequest Process\n", lLogText.c_str()));
                              CancelTccTimerCx(sm);
                              sm.SARequestCx(sm.m_MsgCx, sm.m_SrcCx, *sm.m_DestCx);
                              StartTccTimerCx(sm);
                      }
              }
      };

      class AcSuccessfulSAAnswer : public DiameterCxProxyAction
      {
              void operator()(DiameterCxProxyStateMachine &sm)
              {
                      if (sm.m_MsgCx)
                      {
                              CancelTccTimerCx(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgCx);
                              AAA_LOG((LM_INFO, "%T |CC_Cx_FSM| %s Successful SAAnswer\n", lLogText.c_str()));
                              sm.SAAnswerCx(sm.m_MsgCx, sm.m_SrcCx, *sm.m_DestCx);
                      }
              }
      };

      class AcUnsuccessfulSAAnswer : public DiameterCxProxyAction
      {
              void operator()(DiameterCxProxyStateMachine &sm)
              {
                      if (sm.m_MsgCx)
                      {
                              CancelTccTimerCx(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgCx);
                              AAA_LOG((LM_INFO, "%T |CC_Cx_FSM| %s Unsuccessful SAAnswer\n", lLogText.c_str()));
                              sm.SAAnswerCx(sm.m_MsgCx, sm.m_SrcCx, *sm.m_DestCx);
                      }
              }
      };

      // ---- LIR/LIA — Location-Info-Request/Answer ----
      class AcLIRequest : public DiameterCxProxyAction
      {
              void operator()(DiameterCxProxyStateMachine &sm)
              {
                      if (sm.m_MsgCx)
                      {
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgCx);
                              AAA_LOG((LM_INFO, "%T |CC_Cx_FSM| %s LIRequest Process\n", lLogText.c_str()));
                              CancelTccTimerCx(sm);
                              sm.LIRequestCx(sm.m_MsgCx, sm.m_SrcCx, *sm.m_DestCx);
                              StartTccTimerCx(sm);
                      }
              }
      };

      class AcSuccessfulLIAnswer : public DiameterCxProxyAction
      {
              void operator()(DiameterCxProxyStateMachine &sm)
              {
                      if (sm.m_MsgCx)
                      {
                              CancelTccTimerCx(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgCx);
                              AAA_LOG((LM_INFO, "%T |CC_Cx_FSM| %s Successful LIAnswer\n", lLogText.c_str()));
                              sm.LIAnswerCx(sm.m_MsgCx, sm.m_SrcCx, *sm.m_DestCx);
                      }
              }
      };

      class AcUnsuccessfulLIAnswer : public DiameterCxProxyAction
      {
              void operator()(DiameterCxProxyStateMachine &sm)
              {
                      if (sm.m_MsgCx)
                      {
                              CancelTccTimerCx(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgCx);
                              AAA_LOG((LM_INFO, "%T |CC_Cx_FSM| %s Unsuccessful LIAnswer\n", lLogText.c_str()));
                              sm.LIAnswerCx(sm.m_MsgCx, sm.m_SrcCx, *sm.m_DestCx);
                      }
              }
      };

      // ---- MAR/MAA — Multimedia-Auth-Request/Answer ----
      class AcMARequest : public DiameterCxProxyAction
      {
              void operator()(DiameterCxProxyStateMachine &sm)
              {
                      if (sm.m_MsgCx)
                      {
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgCx);
                              AAA_LOG((LM_INFO, "%T |CC_Cx_FSM| %s MARequest Process\n", lLogText.c_str()));
                              CancelTccTimerCx(sm);
                              sm.MARequestCx(sm.m_MsgCx, sm.m_SrcCx, *sm.m_DestCx);
                              StartTccTimerCx(sm);
                      }
              }
      };

      class AcSuccessfulMAAnswer : public DiameterCxProxyAction
      {
              void operator()(DiameterCxProxyStateMachine &sm)
              {
                      if (sm.m_MsgCx)
                      {
                              CancelTccTimerCx(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgCx);
                              AAA_LOG((LM_INFO, "%T |CC_Cx_FSM| %s Successful MAAnswer\n", lLogText.c_str()));
                              sm.MAAnswerCx(sm.m_MsgCx, sm.m_SrcCx, *sm.m_DestCx);
                      }
              }
      };

      class AcUnsuccessfulMAAnswer : public DiameterCxProxyAction
      {
              void operator()(DiameterCxProxyStateMachine &sm)
              {
                      if (sm.m_MsgCx)
                      {
                              CancelTccTimerCx(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgCx);
                              AAA_LOG((LM_INFO, "%T |CC_Cx_FSM| %s Unsuccessful MAAnswer\n", lLogText.c_str()));
                              sm.MAAnswerCx(sm.m_MsgCx, sm.m_SrcCx, *sm.m_DestCx);
                      }
              }
      };

      // ---- RTR/RTA — Registration-Termination-Request/Answer (server-initiated) ----
      class AcRTRequest : public DiameterCxProxyAction
      {
              void operator()(DiameterCxProxyStateMachine &sm)
              {
                      if (sm.m_MsgCx)
                      {
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgCx);
                              AAA_LOG((LM_INFO, "%T |CC_Cx_FSM| %s RTRequest Process\n", lLogText.c_str()));
                              CancelTccTimerCx(sm);
                              sm.RTRequestCx(sm.m_MsgCx, sm.m_SrcCx, *sm.m_DestCx);
                              StartTccTimerCx(sm);
                      }
              }
      };

      class AcSuccessfulRTAnswer : public DiameterCxProxyAction
      {
              void operator()(DiameterCxProxyStateMachine &sm)
              {
                      if (sm.m_MsgCx)
                      {
                              CancelTccTimerCx(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgCx);
                              AAA_LOG((LM_INFO, "%T |CC_Cx_FSM| %s Successful RTAnswer\n", lLogText.c_str()));
                              sm.RTAnswerCx(sm.m_MsgCx, sm.m_SrcCx, *sm.m_DestCx);
                      }
              }
      };

      class AcUnsuccessfulRTAnswer : public DiameterCxProxyAction
      {
              void operator()(DiameterCxProxyStateMachine &sm)
              {
                      if (sm.m_MsgCx)
                      {
                              CancelTccTimerCx(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgCx);
                              AAA_LOG((LM_INFO, "%T |CC_Cx_FSM| %s Unsuccessful RTAnswer\n", lLogText.c_str()));
                              sm.RTAnswerCx(sm.m_MsgCx, sm.m_SrcCx, *sm.m_DestCx);
                      }
              }
      };

      // ---- PPR/PPA — Push-Profile-Request/Answer (server-initiated) ----
      class AcPPRequest : public DiameterCxProxyAction
      {
              void operator()(DiameterCxProxyStateMachine &sm)
              {
                      if (sm.m_MsgCx)
                      {
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgCx);
                              AAA_LOG((LM_INFO, "%T |CC_Cx_FSM| %s PPRequest Process\n", lLogText.c_str()));
                              CancelTccTimerCx(sm);
                              sm.PPRequestCx(sm.m_MsgCx, sm.m_SrcCx, *sm.m_DestCx);
                              StartTccTimerCx(sm);
                      }
              }
      };

      class AcSuccessfulPPAnswer : public DiameterCxProxyAction
      {
              void operator()(DiameterCxProxyStateMachine &sm)
              {
                      if (sm.m_MsgCx)
                      {
                              CancelTccTimerCx(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgCx);
                              AAA_LOG((LM_INFO, "%T |CC_Cx_FSM| %s Successful PPAnswer\n", lLogText.c_str()));
                              sm.PPAnswerCx(sm.m_MsgCx, sm.m_SrcCx, *sm.m_DestCx);
                      }
              }
      };

      class AcUnsuccessfulPPAnswer : public DiameterCxProxyAction
      {
              void operator()(DiameterCxProxyStateMachine &sm)
              {
                      if (sm.m_MsgCx)
                      {
                              CancelTccTimerCx(sm);
                              std::string lLogText = LOG_DIAMETER_AVPS(*sm.m_MsgCx);
                              AAA_LOG((LM_INFO, "%T |CC_Cx_FSM| %s Unsuccessful PPAnswer\n", lLogText.c_str()));
                              sm.PPAnswerCx(sm.m_MsgCx, sm.m_SrcCx, *sm.m_DestCx);
                      }
              }
      };

      // ---- TCC expiry tears the session down ----
      class AcTccExpired : public DiameterCxProxyAction
      {
              void operator()(DiameterCxProxyStateMachine &sm)
              {
                      if (sm.sessionIdCx.size() > 0)
                      {
                              CancelTccTimerCx(sm);
                              AAA_LOG((LM_CRITICAL, "%T |CC_Cx_FSM| sessionId:%s appId:%d Freeing session on expiry\n",
                                               sm.sessionIdCx.c_str(), sm.appIdCx));
                              sm.Reset(sm.sessionIdCx, sm.appIdCx);
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

      AcUARequest            acUARequest;
      AcSuccessfulUAAnswer   acSuccessfulUAAnswer;
      AcUnsuccessfulUAAnswer acUnsuccessfulUAAnswer;

      AcSARequest            acSARequest;
      AcSuccessfulSAAnswer   acSuccessfulSAAnswer;
      AcUnsuccessfulSAAnswer acUnsuccessfulSAAnswer;

      AcLIRequest            acLIRequest;
      AcSuccessfulLIAnswer   acSuccessfulLIAnswer;
      AcUnsuccessfulLIAnswer acUnsuccessfulLIAnswer;

      AcMARequest            acMARequest;
      AcSuccessfulMAAnswer   acSuccessfulMAAnswer;
      AcUnsuccessfulMAAnswer acUnsuccessfulMAAnswer;

      AcRTRequest            acRTRequest;
      AcSuccessfulRTAnswer   acSuccessfulRTAnswer;
      AcUnsuccessfulRTAnswer acUnsuccessfulRTAnswer;

      AcPPRequest            acPPRequest;
      AcSuccessfulPPAnswer   acSuccessfulPPAnswer;
      AcUnsuccessfulPPAnswer acUnsuccessfulPPAnswer;

      AcTccExpired           acTccExpired;

      DiameterCxProxyStateTable_S()
      {
              InitialState(StIdle);

              // ========== UAR / UAA ==========
              AddStateTableEntry(StIdle,
                      DiameterCxProxyEvent::EvUARequestCx,
                      StOpen, acUARequest);
              AddStateTableEntry(StOpen,
                      DiameterCxProxyEvent::EvUARequestCx,
                      StOpen, acUARequest);
              AddStateTableEntry(StOpen,
                      DiameterCxProxyEvent::EvUAAnswerSuccessfulCx,
                      StIdle, acSuccessfulUAAnswer);
              AddStateTableEntry(StOpen,
                      DiameterCxProxyEvent::EvUAAnswerUnsuccessfulCx,
                      StIdle, acUnsuccessfulUAAnswer);

              // ========== SAR / SAA ==========
              AddStateTableEntry(StIdle,
                      DiameterCxProxyEvent::EvSARequestCx,
                      StOpen, acSARequest);
              AddStateTableEntry(StOpen,
                      DiameterCxProxyEvent::EvSARequestCx,
                      StOpen, acSARequest);
              AddStateTableEntry(StOpen,
                      DiameterCxProxyEvent::EvSAAnswerSuccessfulCx,
                      StIdle, acSuccessfulSAAnswer);
              AddStateTableEntry(StOpen,
                      DiameterCxProxyEvent::EvSAAnswerUnsuccessfulCx,
                      StIdle, acUnsuccessfulSAAnswer);

              // ========== LIR / LIA ==========
              AddStateTableEntry(StIdle,
                      DiameterCxProxyEvent::EvLIRequestCx,
                      StOpen, acLIRequest);
              AddStateTableEntry(StOpen,
                      DiameterCxProxyEvent::EvLIRequestCx,
                      StOpen, acLIRequest);
              AddStateTableEntry(StOpen,
                      DiameterCxProxyEvent::EvLIAnswerSuccessfulCx,
                      StIdle, acSuccessfulLIAnswer);
              AddStateTableEntry(StOpen,
                      DiameterCxProxyEvent::EvLIAnswerUnsuccessfulCx,
                      StIdle, acUnsuccessfulLIAnswer);

              // ========== MAR / MAA ==========
              AddStateTableEntry(StIdle,
                      DiameterCxProxyEvent::EvMARequestCx,
                      StOpen, acMARequest);
              AddStateTableEntry(StOpen,
                      DiameterCxProxyEvent::EvMARequestCx,
                      StOpen, acMARequest);
              AddStateTableEntry(StOpen,
                      DiameterCxProxyEvent::EvMAAnswerSuccessfulCx,
                      StIdle, acSuccessfulMAAnswer);
              AddStateTableEntry(StOpen,
                      DiameterCxProxyEvent::EvMAAnswerUnsuccessfulCx,
                      StIdle, acUnsuccessfulMAAnswer);

              // ========== RTR / RTA — server-initiated ==========
              AddStateTableEntry(StIdle,
                      DiameterCxProxyEvent::EvRTRequestCx,
                      StOpen, acRTRequest);
              AddStateTableEntry(StOpen,
                      DiameterCxProxyEvent::EvRTRequestCx,
                      StOpen, acRTRequest);
              AddStateTableEntry(StOpen,
                      DiameterCxProxyEvent::EvRTAnswerSuccessfulCx,
                      StIdle, acSuccessfulRTAnswer);
              AddStateTableEntry(StOpen,
                      DiameterCxProxyEvent::EvRTAnswerUnsuccessfulCx,
                      StIdle, acUnsuccessfulRTAnswer);

              // ========== PPR / PPA — server-initiated ==========
              AddStateTableEntry(StIdle,
                      DiameterCxProxyEvent::EvPPRequestCx,
                      StOpen, acPPRequest);
              AddStateTableEntry(StOpen,
                      DiameterCxProxyEvent::EvPPRequestCx,
                      StOpen, acPPRequest);
              AddStateTableEntry(StOpen,
                      DiameterCxProxyEvent::EvPPAnswerSuccessfulCx,
                      StIdle, acSuccessfulPPAnswer);
              AddStateTableEntry(StOpen,
                      DiameterCxProxyEvent::EvPPAnswerUnsuccessfulCx,
                      StIdle, acUnsuccessfulPPAnswer);

              // ========== TCC expiry tears down ==========
              AddStateTableEntry(StOpen,
                      DiameterCxProxyEvent::EvTccExpiredCx,
                      StIdle, acTccExpired);
              AddStateTableEntry(StIdle,
                      DiameterCxProxyEvent::EvTccExpiredCx,
                      StIdle, acTccExpired);
      }

      ~DiameterCxProxyStateTable_S() {}
};

typedef ACE_Singleton<DiameterCxProxyStateTable_S, ACE_Recursive_Thread_Mutex> DiameterCxProxyStateTable;

DiameterCxProxyStateMachine::DiameterCxProxyStateMachine(DiameterCCProxySession &s, ACE_Reactor &reactor, int lModuleId)
      : AAA_StateMachineWithTimer<DiameterCxProxyStateMachine>(*this, *DiameterCxProxyStateTable::instance(), reactor, "AAA_CX_FSM_PROXY"), sessionCx(s)
{
      m_MsgCx = NULL;
      mModuleIdCx = lModuleId;
}

void DiameterCxProxyStateMachine::SendSyncSessionDataCx(DiameterCxProxyStateMachine &sm,
                                                                                                              SyncOperation op, DiameterCxProxyEvent event, bool sessionTccExpiry)
{
      if (sm.CxSession().SyncSessionHdlr())
      {
              SyncDccaProxySessionData syncData;
              memset(&syncData, 0, sizeof(SyncDccaProxySessionData));

              syncData.op = op;
              syncData.event = event;
              syncData.mModuleId = sm.mModuleIdCx;

              if (sessionTccExpiry)
              {
                      // On Expiry Redis data will be deleted by Key Expire
              }
              else
              {
                      std::strncpy(syncData.sessionId, sm.m_MsgCx->sessionId.c_str(), sizeof(syncData.sessionId) - 1);
                      syncData.sessionId[sizeof(syncData.sessionId) - 1] = '\0';

                      syncData.appId = sm.m_MsgCx->hdr.mApplId;

                      if (SYNC_OP_ADD == syncData.op)
                      {
                              if (sm.m_SrcCx)
                                      snprintf(syncData.sourceName, 140, "%s", sm.m_SrcCx->PeerData().m_Identity.c_str());
                              if (*sm.m_DestCx)
                                      snprintf(syncData.destName, 140, "%s", (*sm.m_DestCx)->PeerData().m_Identity.c_str());

                              AAA_LOG((LM_DEBUG, "%T |CC_Cx_FSM| SYNC_OP_ADD  SId:%s APPID:%d Mid:%d OH:%s DH:%s \n",
                                               syncData.sessionId, syncData.appId, syncData.mModuleId, syncData.sourceName, syncData.destName));
                      }
                      else
                      {
                              AAA_LOG((LM_DEBUG, "%T |CC_Cx_FSM| SYNC_OP_DEL  SId:%s APPID:%d Mid:%d \n",
                                               syncData.sessionId, syncData.appId, syncData.mModuleId));
                      }

                      if (DIAMETER_CFG_TRANSPORT()->use_sentinel == 1)
                              sm.CxSession().SyncSessionHdlr()->SendSyncData(syncData);
                      else
                              AAA_LOG((LM_DEBUG,"Alert: Enable Sentinel in diameter.cfg & configure DraRedisHA.cfg" ));
              }
      }
      else
      {
              AAA_LOG((LM_DEBUG, "%T |CC_Cx_FSM| Failed to get object"));
      }
}

