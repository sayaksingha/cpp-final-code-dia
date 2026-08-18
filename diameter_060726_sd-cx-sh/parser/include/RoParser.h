// @(#) $Id: RoParser.h,v 1.1.2.2 2018/07/04 23:24:01 anandhv Exp $
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
#ifndef INCL_Ro_PARSER_DEF_H
#define INCL_Ro_PARSER_DEF_H

#include "DiaHandleMsg.h"
#include "base/include/AbortSessionRequest.h"
#include "base/include/AbortSessionAnswer.h"
#include "ro/include/CCRequest.h"
#include "ro/include/CCAnswer.h"
#include "ro/include/RARequest.h"
#include "ro/include/RAAnswer.h"

using namespace RO;


class RoParser : public DiaHandleMsg
{
	public:

		void CreateReqMsg(DiameterMsg &msg)
		{
			switch(msg.hdr.mCmdCode)
			{
				case AAA_CCR_MSG:
					{
						DecodeMsg<RO::CCRequest>(msg);
					}
					break;
				case AAA_ASR_MSG:
					{
						DecodeMsg<BASE::AbortSessionRequest>(msg);
					}
					break;
				case AAA_RAR_MSG:
					{
						DecodeMsg<RO::RARequest>(msg);
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
				case AAA_CCR_MSG:
					{
						DecodeMsg<RO::CCAnswer>(msg);
					}
					break;
				case AAA_ASR_MSG:
					{
						DecodeMsg<BASE::AbortSessionAnswer>(msg);
					}
					break;
				case AAA_RAR_MSG:
					{
						DecodeMsg<RO::RAAnswer>(msg);
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

		void SetAnswerParam(DiameterMsg &msg, int resultCode)
		{
			switch(msg.hdr.mCmdCode)
			{
				case AAA_CCR_MSG:
					{
						CreateInstance<RO::CCAnswer>(msg,resultCode);
					}
					break;
				case AAA_RAR_MSG:
					{
						CreateInstance<RO::RAAnswer>(msg,resultCode);
					}
					break;
				case AAA_ASR_MSG:
					{
						CreateInstance<BASE::AbortSessionAnswer>(msg);
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
