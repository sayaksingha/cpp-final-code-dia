#ifndef INCL_SD_PARSER_DEF_H
#define INCL_SD_PARSER_DEF_H

#include "DiaHandleMsg.h"
#include "sd/include/TDFSessionRequest.h"
#include "sd/include/TDFSessionAnswer.h"
#include "sd/include/CreditControlRequest.h"
#include "sd/include/CreditControlAnswer.h"
#include "sd/include/ReAuthRequest.h"
#include "sd/include/ReAuthAnswer.h"
using namespace SD;

class SdParser : public DiaHandleMsg
{
      public:

              void CreateReqMsg(DiameterMsg &msg)
              {
                      switch(msg.hdr.mCmdCode)
                      {
                              case AAA_TSR_MSG:
                                      DecodeMsg<SD::TDFSessionRequest>(msg);
                                      break;
                              case AAA_CCR_MSG:
                                      DecodeMsg<SD::CreditControlRequest>(msg);
                                      break;
                              case AAA_RAR_MSG:
                                      DecodeMsg<SD::ReAuthRequest>(msg);
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
                              case AAA_TSR_MSG:
                                      DecodeMsg<SD::TDFSessionAnswer>(msg);
                                      break;
                              case AAA_CCR_MSG:
                                      DecodeMsg<SD::CreditControlAnswer>(msg);
                                      break;
                              case AAA_RAR_MSG:
                                      DecodeMsg<SD::ReAuthAnswer>(msg);
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
                              case AAA_TSR_MSG:
                                      CreateInstance<SD::TDFSessionAnswer>(msg, resultCode);
                                      break;
                              case AAA_CCR_MSG:
                                      CreateInstance<SD::CreditControlAnswer>(msg, resultCode);
                                      break;
                              case AAA_RAR_MSG:
                                      CreateInstance<SD::ReAuthAnswer>(msg, resultCode);
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

