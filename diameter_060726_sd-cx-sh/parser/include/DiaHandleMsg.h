// @(#) $Id: DiaHandleMsg.h,v 1.1.2.2.2.4 2021/01/28 00:52:15 anandhv Exp $
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
#ifndef INCL_DIA_HANDLE_MSG_DEF_H
#define INCL_DIA_HANDLE_MSG_DEF_H

#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <mutex>
#include "diameter_parser.h"
#include "aaa_structs.h"
#include "base/include/DiameterBase.h"

using namespace BASE;

class S6Parser;
class GxParser;
class RoParser;
class RxParser;
class SyParser;
class SlhParser;
class SdParser;
class ShParser;
class CxParser;
class DiaHandleMsg
{
        public:

                DiaHandleMsg();
                ~DiaHandleMsg();

                static void DecodeReqMsg(DiameterMsg &msg);
                static void DecodeAnsMsg(DiameterMsg &msg);
                static void DecodeBaseMsg(DiameterMsg &msg);

                static void SetAnswerParam(DiameterMsg &msg,int resultCode=2001);
                template<class DATA>
                        static void DecodeMsg(DiameterMsg &msg);

                template <class DATA>
                        void CreateInstance(DiameterMsg &msg,int resultCode=2001);

                static BOOLEAN EncodeMsg(DiameterMsg &msg,byteArray& rawByte);

                virtual void CreateReqMsg(DiameterMsg &msg) = 0;
                virtual void CreateAnsMsg(DiameterMsg &msg) = 0;

        private :
                static S6Parser m_s6_parser;
                static GxParser m_gx_parser;
                static RoParser m_ro_parser;
                static RxParser m_rx_parser;
                static SyParser m_sy_parser;
                static SlhParser m_slh_parser;
                static SdParser  m_sd_parser;
                static ShParser  m_sh_parser;	
		static CxParser  m_cx_parser;
//		  public:
//					static int AppIDNotSupportedFlag;
};

#include "aaa_data_defs.h"


#endif


