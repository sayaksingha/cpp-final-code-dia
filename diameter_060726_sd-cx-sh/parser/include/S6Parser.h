// @(#) $Id: S6Parser.h,v 1.1.2.1.2.3 2019/10/11 22:45:56 mohan Exp $
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
#ifndef INCL_S6_PARSER_DEF_H
#define INCL_S6_PARSER_DEF_H

#include "DiaHandleMsg.h"
#include "s6a/include/UpdateLocationRequest.h"
#include "s6a/include/UpdateLocationAnswer.h"
#include "s6a/include/CancelLocationRequest.h"
#include "s6a/include/CancelLocationAnswer.h"
#include "s6a/include/AuthenticationInformationRequest.h"
#include "s6a/include/AuthenticationInformationAnswer.h"
#include "s6a/include/InsertSubscriberDataRequest.h"
#include "s6a/include/InsertSubscriberDataAnswer.h"
#include "s6a/include/DeleteSubscriberDataRequest.h"
#include "s6a/include/DeleteSubscriberDataAnswer.h"
#include "s6a/include/PurgeUERequest.h"
#include "s6a/include/PurgeUEAnswer.h"
#include "s6a/include/ResetRequest.h"
#include "s6a/include/ResetAnswer.h"
#include "s6a/include/NotifyRequest.h"
#include "s6a/include/NotifyAnswer.h"

using namespace S6A;


class S6Parser : public DiaHandleMsg
{
	public:

		void CreateReqMsg(DiameterMsg &msg)
		{
			switch(msg.hdr.mCmdCode)
			{
				case AAA_ULR_MSG:
					{
						DecodeMsg<UpdateLocationRequest>(msg);
					}
					break;
				case AAA_CLR_MSG:
					{
						DecodeMsg<CancelLocationRequest>(msg);
					}
					break;
				case AAA_AIR_MSG:
					{
						DecodeMsg<AuthenticationInformationRequest>(msg);
					}
					break;
				case AAA_ISDR_MSG:
					{
						DecodeMsg<InsertSubscriberDataRequest>(msg);
					}
					break;
				case AAA_DSR_MSG:
					{
						DecodeMsg<DeleteSubscriberDataRequest>(msg);
					}
					break;
				case AAA_PUR_MSG:
					{
						DecodeMsg<PurgeUERequest>(msg);
					}
					break;
				case AAA_RSR_MSG:
					{
						DecodeMsg<ResetRequest>(msg);
					}
					break;
				case AAA_NOR_MSG:
					{
						DecodeMsg<NotifyRequest>(msg);
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
				case AAA_ULR_MSG:
					{
						DecodeMsg<UpdateLocationAnswer>(msg);
					}
					break;
				case AAA_CLR_MSG:
					{
						DecodeMsg<CancelLocationAnswer>(msg);
					}
					break;
				case AAA_AIR_MSG:
					{
						DecodeMsg<AuthenticationInformationAnswer>(msg);
					}
					break;
				case AAA_ISDR_MSG:
					{
						DecodeMsg<InsertSubscriberDataAnswer>(msg);
					}
					break;
				case AAA_DSR_MSG:
					{
						DecodeMsg<DeleteSubscriberDataAnswer>(msg);
					}
					break;
				case AAA_PUR_MSG:
					{
						DecodeMsg<PurgeUEAnswer>(msg);
					}
					break;
				case AAA_RSR_MSG:
					{
						DecodeMsg<ResetAnswer>(msg);
					}
					break;
				case AAA_NOR_MSG:
					{
						DecodeMsg<NotifyAnswer>(msg);
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
				case AAA_ULR_MSG:
					{
						CreateInstance<UpdateLocationAnswer>(msg, resultCode );
					}
					break;
				case AAA_CLR_MSG:
					{
						CreateInstance<CancelLocationAnswer>(msg, resultCode );
					}
					break;
				case AAA_AIR_MSG:
					{
						CreateInstance<AuthenticationInformationAnswer>(msg, resultCode );
					}
					break;
				case AAA_ISDR_MSG:
					{
						CreateInstance<InsertSubscriberDataAnswer>(msg, resultCode );
					}
					break;
				case AAA_DSR_MSG:
					{
						CreateInstance<DeleteSubscriberDataAnswer>(msg, resultCode );
					}
					break;
				case AAA_PUR_MSG:
					{
						CreateInstance<PurgeUEAnswer>(msg, resultCode );
					}
					break;
				case AAA_RSR_MSG:
					{
						CreateInstance<ResetAnswer>(msg, resultCode );
					}
					break;
				case AAA_NOR_MSG:
					{
						CreateInstance<NotifyAnswer>(msg, resultCode );
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
