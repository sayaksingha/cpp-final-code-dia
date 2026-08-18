#ifndef INCL_CX_PARSER_DEF_H
#define INCL_CX_PARSER_DEF_H

#include "DiaHandleMsg.h"
#include "cx/include/UserAuthorizationRequest.h"
#include "cx/include/UserAuthorizationAnswer.h"
#include "cx/include/ServerAssignmentRequest.h"
#include "cx/include/ServerAssignmentAnswer.h"
#include "cx/include/LocationInfoRequest.h"
#include "cx/include/LocationInfoAnswer.h"
#include "cx/include/MultimediaAuthRequest.h"
#include "cx/include/MultimediaAuthAnswer.h"
#include "cx/include/RegistrationTerminationRequest.h"
#include "cx/include/RegistrationTerminationAnswer.h"
#include "cx/include/PushProfileRequest.h"
#include "cx/include/PushProfileAnswer.h"
using namespace CX;

class CxParser : public DiaHandleMsg
{
      public:

              void CreateReqMsg(DiameterMsg &msg)
              {
                      switch(msg.hdr.mCmdCode)
                      {
                              case AAA_UAR_MSG:
                                      DecodeMsg<CX::UserAuthorizationRequest>(msg);
                                      break;
                              case AAA_SAR_MSG:
                                      DecodeMsg<CX::ServerAssignmentRequest>(msg);
                                      break;
                              case AAA_LIR_MSG:
                                      DecodeMsg<CX::LocationInfoRequest>(msg);
                                      break;
                              case AAA_MAR_MSG:
                                      DecodeMsg<CX::MultimediaAuthRequest>(msg);
                                      break;
                              case AAA_RTR_MSG:
                                      DecodeMsg<CX::RegistrationTerminationRequest>(msg);
                                      break;
                              case AAA_PPR_MSG:
                                      DecodeMsg<CX::PushProfileRequest>(msg);
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
                              case AAA_UAR_MSG:
                                      DecodeMsg<CX::UserAuthorizationAnswer>(msg);
                                      break;
                              case AAA_SAR_MSG:
                                      DecodeMsg<CX::ServerAssignmentAnswer>(msg);
                                      break;
                              case AAA_LIR_MSG:
                                      DecodeMsg<CX::LocationInfoAnswer>(msg);
                                      break;
                              case AAA_MAR_MSG:
                                      DecodeMsg<CX::MultimediaAuthAnswer>(msg);
                                      break;
                              case AAA_RTR_MSG:
                                      DecodeMsg<CX::RegistrationTerminationAnswer>(msg);
                                      break;
                              case AAA_PPR_MSG:
                                      DecodeMsg<CX::PushProfileAnswer>(msg);
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
                              case AAA_UAR_MSG:
                                      CreateInstance<CX::UserAuthorizationAnswer>(msg, resultCode);
                                      break;
                              case AAA_SAR_MSG:
                                      CreateInstance<CX::ServerAssignmentAnswer>(msg, resultCode);
                                      break;
                              case AAA_LIR_MSG:
                                      CreateInstance<CX::LocationInfoAnswer>(msg, resultCode);
                                      break;
                              case AAA_MAR_MSG:
                                      CreateInstance<CX::MultimediaAuthAnswer>(msg, resultCode);
                                      break;
                              case AAA_RTR_MSG:
                                      CreateInstance<CX::RegistrationTerminationAnswer>(msg, resultCode);
                                      break;
                              case AAA_PPR_MSG:
                                      CreateInstance<CX::PushProfileAnswer>(msg, resultCode);
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

