// @(#) $Id: RxParser.h,v 1.1.2.1 2021/01/28 02:55:23 shijuc Exp $
//---------------------------------------------------------------
// NAME : DiaHandleMsg.h
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
// Originated: Pushpa B J
//----------------------------------------------------------------
#ifndef INCL_Rx_PARSER_DEF_H
#define INCL_Rx_PARSER_DEF_H

#include "DiaHandleMsg.h"
//#include "base/include/AbortSessionRequest.h"
//#include "base/include/AbortSessionAnswer.h"

#include "rx/include/AARequest.h"
#include "rx/include/AAAnswer.h"
#include "rx/include/ASRequest.h"
#include "rx/include/ASAnswer.h"
#include "rx/include/RARequest.h"
#include "rx/include/RAAnswer.h"
#include "rx/include/STRequest.h"
#include "rx/include/STAnswer.h"

/*
#include "gx/include/CCRequest.h"
#include "gx/include/CCAnswer.h"
#include "gx/include/RARequest.h"
#include "gx/include/RAAnswer.h"
*/

using namespace RX;


class RxParser : public DiaHandleMsg
{
	public:

		void CreateReqMsg(DiameterMsg &msg)
		{
			switch(msg.hdr.mCmdCode)
			{
				case AAA_ASR_MSG:
					{
						DecodeMsg<RX::ASRequest>(msg);
						//DecodeMsg<BASE::AbortSessionRequest>(msg);
					}
					break;
				case AAA_RAR_MSG:
					{
						DecodeMsg<RX::RARequest>(msg);
					}
					break;
			
				case AAA_AAR_MSG:
               {
                  DecodeMsg<RX::AARequest>(msg);
               }
               break;	
				case AAA_STR_MSG:
               {
                  DecodeMsg<RX::STRequest>(msg);
               }
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
				case AAA_ASR_MSG:
					{
						DecodeMsg<RX::ASAnswer>(msg);
						//DecodeMsg<BASE::AbortSessionAnswer>(msg);
					}
					break;
				case AAA_RAR_MSG:
					{
						DecodeMsg<RX::RAAnswer>(msg);
					}
					break;
				case AAA_AAR_MSG:
               {
                  DecodeMsg<RX::AAAnswer>(msg);
               }
               break;
				case AAA_STR_MSG:
               {
                  DecodeMsg<RX::STAnswer>(msg);
               }
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

		void SetAnswerParam(DiameterMsg &msg,int resultCode)
		{
			switch(msg.hdr.mCmdCode)
			{
				case AAA_ASR_MSG:
					{
						CreateInstance<RX::ASAnswer>(msg);
						//CreateInstance<BASE::AbortSessionAnswer>(msg);
					}
					break;
				case AAA_RAR_MSG:
					{
						CreateInstance<RX::RAAnswer>(msg,resultCode);
					}
					break;
				case AAA_AAR_MSG:
               {
                  CreateInstance<RX::AAAnswer>(msg,resultCode);
               }
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

