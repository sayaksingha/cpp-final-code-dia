#ifndef INCL_SH_PARSER_DEF_H
#define INCL_SH_PARSER_DEF_H

#include "DiaHandleMsg.h"
#include "sh/include/UserDataRequest.h"
#include "sh/include/UserDataAnswer.h"
#include "sh/include/ProfileUpdateRequest.h"
#include "sh/include/ProfileUpdateAnswer.h"
#include "sh/include/SubscribeNotificationsRequest.h"
#include "sh/include/SubscribeNotificationsAnswer.h"
#include "sh/include/PushNotificationRequest.h"
#include "sh/include/PushNotificationAnswer.h"
using namespace SH;

class ShParser : public DiaHandleMsg
{
      public:

              void CreateReqMsg(DiameterMsg &msg)
              {
                      switch(msg.hdr.mCmdCode)
                      {
                              case AAA_SH_UDR_MSG:
                                      DecodeMsg<SH::UserDataRequest>(msg);
                                      break;
                              case AAA_SH_PUR_MSG:
                                      DecodeMsg<SH::ProfileUpdateRequest>(msg);
                                      break;
                              case AAA_SH_SNR_MSG:
                                      DecodeMsg<SH::SubscribeNotificationsRequest>(msg);
                                      break;
                              case AAA_SH_PNR_MSG:
                                      DecodeMsg<SH::PushNotificationRequest>(msg);
                                      break;
                              default:
                                      {
                                              TEXT lErrorText[100] = "";
                                              snprintf(lErrorText,sizeof(lErrorText),"Unsupported Cmd Code:%d", msg.hdr.mCmdCode);
                                              DiameterBaseException lBaseException(DiameterBaseException::UNEXPECTED_FIELD, lErrorText);
                                              throw lBaseException;
                                      }
                                      break;
                      }
                      return;
              }

              void CreateAnsMsg(DiameterMsg &msg)
              {
                      switch(msg.hdr.mCmdCode)
                      {
                              case AAA_SH_UDR_MSG:
                                      DecodeMsg<SH::UserDataAnswer>(msg);
                                      break;
                              case AAA_SH_PUR_MSG:
                                      DecodeMsg<SH::ProfileUpdateAnswer>(msg);
                                      break;
                              case AAA_SH_SNR_MSG:
                                      DecodeMsg<SH::SubscribeNotificationsAnswer>(msg);
                                      break;
                              case AAA_SH_PNR_MSG:
                                      DecodeMsg<SH::PushNotificationAnswer>(msg);
                                      break;
                              default:
                                      {
                                              TEXT lErrorText[100] = "";
                                              snprintf(lErrorText,sizeof(lErrorText),"Unsupported Cmd Code:%d", msg.hdr.mCmdCode);
                                              DiameterBaseException lBaseException(DiameterBaseException::UNEXPECTED_FIELD, lErrorText);
                                              throw lBaseException;
                                      }
                                      break;
                      }
                      return;
              }

              void SetAnswerParam(DiameterMsg &msg, int resultCode)
              {
                      switch(msg.hdr.mCmdCode)
                      {
                              case AAA_SH_UDR_MSG:
                                      CreateInstance<SH::UserDataAnswer>(msg, resultCode);
                                      break;
                              case AAA_SH_PUR_MSG:
                                      CreateInstance<SH::ProfileUpdateAnswer>(msg, resultCode);
                                      break;
                              case AAA_SH_SNR_MSG:
                                      CreateInstance<SH::SubscribeNotificationsAnswer>(msg, resultCode);
                                      break;
                              case AAA_SH_PNR_MSG:
                                      CreateInstance<SH::PushNotificationAnswer>(msg, resultCode);
                                      break;
                              default:
                                      {
                                              TEXT lErrorText[100] = "";
                                              snprintf(lErrorText,sizeof(lErrorText),"Unsupported Cmd Code:%d", msg.hdr.mCmdCode);
                                              DiameterBaseException lBaseException(DiameterBaseException::UNEXPECTED_FIELD, lErrorText);
                                              throw lBaseException;
                                      }
                                      break;
                      }
                      return;
              }
};

#endif

