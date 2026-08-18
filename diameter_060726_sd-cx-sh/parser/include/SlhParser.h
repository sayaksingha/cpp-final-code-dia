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
#ifndef INCL_SLH_PARSER_DEF_H
#define INCL_SLH_PARSER_DEF_H

#include "DiaHandleMsg.h"
#include "slh/include/LCSRoutingInfoAnswer.h"
#include "slh/include/LCSRoutingInfoRequest.h"
//src/diameterlib/slh/includeLCSRoutingInfoAnswer.cc   LCSRoutingInfoRequest.cc  
using namespace SLH;


class SlhParser : public DiaHandleMsg
{
	public:

		void CreateReqMsg(DiameterMsg &msg)
		{
			switch(msg.hdr.mCmdCode)
			{
				case AAA_RIR_MSG:
					{
						DecodeMsg<SLH::LCSRoutingInfoRequest>(msg);
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
				case AAA_RIR_MSG:
					{
						DecodeMsg<SLH::LCSRoutingInfoAnswer>(msg);
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
				case AAA_RIR_MSG:
					{
						CreateInstance<SLH::LCSRoutingInfoAnswer>(msg, resultCode );
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
