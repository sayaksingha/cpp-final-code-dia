//----------------------------------------------------------------------
// NAME :  Dra.cc
//
// COPYRIGHT :  Tayana Software Solutions Pvt Ltd -- Copyright(C) 2018
//              All rights reserved. No part of this computer program
//              may be used or reproduced in any form by any
//              means without prior written permission of
//              Tayana Software Solutions Pvt Ltd
//
// DESCRIPTION
//
// Originated :                                     Date:
//----------------------------------------------------------------------
#ifndef INCL_DRA_UPCC_HTTP_APP_H
#define INCL_DRA_UPCC_HTTP_APP_H

#include "Dra.h"
#include "DRA_Http.h"
#include "DRA_HttpReqProcessor.h"
using namespace GX;
using namespace RO;

class DRA_UpccRechargeHttpRelay : public Dra 
{
	public:

		//Dra(AAA_Task &task, DraRouting &routing);
		DRA_UpccRechargeHttpRelay( AAA_Task &task, DraRouting &routing, int ModuleId);

		~DRA_UpccRechargeHttpRelay ();

		DiameterGxProxySession* CreateInstance() ;

		void ccEventRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);

		void ccEventAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);

		//Dont use below metods. Only added to avoid conflict between DRA & DRA_Http 
		void GenerateFile();

		void SetAlarmForNextDay();

};


#define DRA_HANDLE_EXCEPTION_CONTINUE( _ErrorInfo)\
   catch(TssDiameterMsgException d)\
{\
		AAA_LOG((LM_ERROR,"%T |DRA_HTTP_APP| SID:%s %s\n",msg->sessionId.c_str(), _ErrorInfo));\
}

#define DRA_HANDLE_EXCEPTION_EXIT(_ErrorInfo)\
   catch(TssDiameterMsgException d)\
{\
	AAA_LOG((LM_ERROR,"%T |DRA_HTTP_APP| SID:%s %s\n",msg->sessionId.c_str(), _ErrorInfo ));\
   return;\
}


#endif
