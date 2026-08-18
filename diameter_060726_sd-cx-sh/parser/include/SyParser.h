// @(#) $Id: SyParser.h,v 1.1.2.1 2021/01/28 02:55:23 shijuc Exp $
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
// Originated: Abhishek Chhabra               Date: 07-04-2025 
//----------------------------------------------------------------
#pragma once

#include "DiaHandleMsg.h"

#include "sy/include/SLRequest.h"
#include "sy/include/SLAnswer.h"
#include "sy/include/SNRequest.h"
#include "sy/include/SNAnswer.h"
#include "sy/include/STRequest.h"
#include "sy/include/STAnswer.h"

using namespace SY;


class SyParser : public DiaHandleMsg
{
	public:

		void CreateReqMsg(DiameterMsg &msg)
		{
			switch(msg.hdr.mCmdCode)
			{
				case AAA_SLR_MSG:
					{
						DecodeMsg<SY::SLRequest>(msg);
					}
					break;
				case AAA_SNR_MSG:
               {
                  DecodeMsg<SY::SNRequest>(msg);
               }
               break;	
				case AAA_STR_MSG:
               {
                  DecodeMsg<SY::STRequest>(msg);
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
				case AAA_SLR_MSG:
					{
						DecodeMsg<SY::SLAnswer>(msg);
					}
					break;
				case AAA_SNR_MSG:
               {
                  DecodeMsg<SY::SNAnswer>(msg);
               }
               break;
				case AAA_STR_MSG:
               {
                  DecodeMsg<SY::STAnswer>(msg);
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
				case AAA_SNR_MSG:
					{
						CreateInstance<SY::SNAnswer>(msg);
					}
					break;
				case AAA_SLR_MSG:
               {
                  CreateInstance<SY::SLAnswer>(msg,resultCode);
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


