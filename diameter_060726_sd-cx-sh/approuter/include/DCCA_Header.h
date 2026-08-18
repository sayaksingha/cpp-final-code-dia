// @(#) $Id: DCCA_Header.h,v 1.1.2.5 2021/01/28 00:05:02 anandhv Exp $
//--------------------------------------------------------------------------------
// NAME           : BreRuleApi.h
//
// COPYRIGHT      : TSS -- Copyright (C) 2012 Tayana Software Solutions Pvt Ltd.,
//                  All rights reserved. No part of this computer program
//                  may be used or reproduced in any form by any
//                  means without prior written permission of
//                  Tayana Software Solutions Pvt Ltd.
//
// Originated     : Nandagopi 
//-------------------------------------------------------------------------------
#ifndef  DCCA_HEADER_H
#define  DCCA_HEADER_H 

#include <iostream>     // std::cout
#include <map>
#include <list>
#include <string>
#include <bitset>
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <cassert>
#include <exception>
#include <sstream>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <cassert>
#include <exception>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <mutex>
#include "Types.h"
#include "framework.h"
#include "aaa_parser_defs.h"
#include "diameter_parser.h"
#include "aaa_peer_table.h"
#include <boost/thread/locks.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <boost/regex.hpp>


using namespace std;
#define DCCA_MAX_ROUTE_BIT_SUPPORTED 32
//1.. locking is required before deleting and inserting rule....

enum DCCA_RouteAvpType
{
   DCCA_INVALID    = 0,
   DCCA_STRING     = 1,
   DCCA_NUMERIC    = 2
};

class DCCA_AvpInfo
{
   public:
      int               mAvpPosition;
      int               mPriority;
      int               mAvpCode;
      string            mAvpName;
      DCCA_RouteAvpType mAvpDataType;
};


//Class used to store input rule which was read from json file.
class DCCA_InputRouteRule  //Used while registration.
{
	public:
		DCCA_InputRouteRule(){};
		~DCCA_InputRouteRule(){};

		int                                 mApplicationId;
		string                              mApplicationName;
		list< map< string, list<string> > > mRuleSetList;
		//map< string, list<string> > mRuleMap;
		//AvpName , List of rule...
};

typedef enum {
     EvInitialRequest,
	  EvInitialRequestRtx,
     EvInitialRequestSuccessful,
     EvInitialRequestUnsuccessful,

     EvUpdateRequest,
     EvUpdateRequestSuccessful,
     EvUpdateRequestUnsuccessful,

     EvTerminationRequest,
     EvTerminationRequestSuccessful,
     EvTerminationRequestUnsuccessful,

     EvEventRequest,
     EvEventRequestSuccessful,
     EvEventRequestUnsuccessful,

     EvRARequest,
     EvRARequestSuccessful,
     EvRARequestUnsuccessful,

     EvASRequest,
     EvASRequestSuccessful,
     EvASRequestUnsuccessful,

     EvTccExpired,
	  EvTxExpired,

     EvSgDisconnect,
     EvSgSessionTimeout,
     EvSgTimeout,

	  EvInternalRspFromProxy

} DiameterCCProxyEvent;

typedef enum {
   EvAARequest,
   EvAARequestSuccessful,
   EvAARequestUnsuccessful,
	
	EvSTRequest,
   EvSTRequestSuccessful,
   EvSTRequestUnsuccessful,
	
	EvASRequestRx,
   EvASRequestSuccessfulRx,
   EvASRequestUnsuccessfulRx,

	EvRARequestRx,
   EvRARequestSuccessfulRx,
   EvRARequestUnsuccessfulRx,

	EvTccExpiredRx
}DiameterRxProxyEvent;



typedef enum {
   EvSLRequest, //0
   EvSLAnswer, //1
   EvSLAnswerSuccessful, //2
   EvSLAnswerUnsuccessful, //3
	
	EvSTRequestSy, //4
   EvSTAnswerSuccessfulSy, //5
   EvSTAnswerUnsuccessfulSy, //6
	
	EvSNRequest, //7
   EvSNAnswer, //8
   EvSNAnswerSuccessful, //9
   EvSNAnswerUnsuccessful, //10

	EvTccExpiredSy, //11
   EvTxExpiredSy //12
}DiameterSyProxyEvent;

typedef enum {
   EvRIRequest, //0
   EvRIAnswer, //1
   EvRIAnswerSuccessful, //2
   EvRIAnswerUnsuccessful, //3

   EvTccExpiredSlh, //11
   EvTxExpiredSlh //12
}DiameterSlhProxyEvent;

//New addition 07-07-26
typedef enum {
   EvTSRequestSd, //0   TDF-Session-Request/Answer
   EvTSAnswerSuccessfulSd, //1
   EvTSAnswerUnsuccessfulSd, //2

   EvCCRequestSd, //3   Credit-Control-Request/Answer
   EvCCAnswerSuccessfulSd, //4
   EvCCAnswerUnsuccessfulSd, //5

   EvRARequestSd, //6   Re-Auth-Request/Answer
   EvRARequestSuccessfulSd, //7
   EvRARequestUnsuccessfulSd, //8

   EvTccExpiredSd, //9
   EvTxExpiredSd //10
} DiameterSdProxyEvent;

typedef enum {
   EvUDRequestSh, //0   User-Data-Request/Answer
   EvUDAnswerSuccessfulSh, //1
   EvUDAnswerUnsuccessfulSh, //2

   EvPURequestSh, //3   Profile-Update-Request/Answer
   EvPUAnswerSuccessfulSh, //4
   EvPUAnswerUnsuccessfulSh, //5

   EvSNRequestSh, //6   Subscribe-Notifications-Request/Answer
   EvSNAnswerSuccessfulSh, //7
   EvSNAnswerUnsuccessfulSh, //8

   EvPNRequestSh, //9   Push-Notification-Request/Answer
   EvPNAnswerSuccessfulSh, //10
   EvPNAnswerUnsuccessfulSh, //11

   EvTccExpiredSh, //12
   EvTxExpiredSh //13
} DiameterShProxyEvent;

typedef enum {
   EvUARequestCx, //0   User-Authorization-Request/Answer
   EvUAAnswerSuccessfulCx, //1
   EvUAAnswerUnsuccessfulCx, //2

   EvSARequestCx, //3   Server-Assignment-Request/Answer
   EvSAAnswerSuccessfulCx, //4
   EvSAAnswerUnsuccessfulCx, //5

   EvLIRequestCx, //6   Location-Info-Request/Answer
   EvLIAnswerSuccessfulCx, //7
   EvLIAnswerUnsuccessfulCx, //8

   EvMARequestCx, //9   Multimedia-Auth-Request/Answer
   EvMAAnswerSuccessfulCx, //10
   EvMAAnswerUnsuccessfulCx, //11

   EvRTRequestCx, //12   Registration-Termination-Request/Answer
   EvRTAnswerSuccessfulCx, //13
   EvRTAnswerUnsuccessfulCx, //14

   EvPPRequestCx, //15   Push-Profile-Request/Answer
   EvPPAnswerSuccessfulCx, //16
   EvPPAnswerUnsuccessfulCx, //17

   EvTccExpiredCx, //18
   EvTxExpiredCx //19
} DiameterCxProxyEvent;



typedef enum 
{
	EvULRequest,//0
	EvULAnswer,//1
	EvULASuccessful,//2
	EvULAUnsuccessful,//3

	EvAIRequest,//4
	EvAIAnswer,//5
	EvAIASuccessful,//6
   EvAIAUnsuccessful,//7

   EvPURequest,//8
   EvPUAnswer,//9
   EvPUASuccessful,//10
   EvPUAUnsuccessful,//11

   EvCLRequest,//12
   EvCLAnswer,//13
   EvCLASuccessful,//14
   EvCLAUnsuccessful,//15

   EvISDRequest,//16
   EvISDAnswer,//17
   EvISDASuccessful,//18
   EvISDAUnsuccessful,//19

   EvResetRequest,
   EvResetAnswer,
   EvResetSuccessful,
   EvResetUnsuccessful,

   EvDSRequest,
   EvDSAnswer,
   EvDSASuccessful,
   EvDSAUnsuccessful,

   EvNORequest,
   EvNOAnswer,
   EvNOASuccessful,
   EvNOAUnsuccessful,
   
   EvTccExpiredS6a,
   EvTxExpiredS6a,

   EvCommonSuccessfulAnswer,
   EvCommonUnsuccessfulAnswer,

}DiameterS6aProxyEvent;

/*
typedef struct {
   char sessionId[150];
   char sourceName[150];
   char destName[150];
	int  appId;
   DiameterCCProxyEvent event;
   SyncOperation        op;
   int                  mModuleId;
} SyncDccaProxySessionData;
*/
class AAA_ProxySessionSyncHdlr
{
   public:
      virtual int SendSyncData(SyncDccaProxySessionData &data) = 0;

      virtual int GetSyncData(SyncDccaProxySessionData &data) = 0;
};

#define DCCA_MIN_STR_LEN				0
#define DCCA_MAX_STR_LEN				200

#define DCCA_MIN_AVP_VALUE				50000
#define DCCA_MAX_AVP_VALUE				100000

#define DCCA_MIN_HOST_STR_LEN			0
#define DCCA_MAX_HOST_STR_LEN			2000

#define DCCA_MIN_PWD_LEN				3
#define DCCA_MAX_PWD_LEN				20

#define DCCA_MIN_CID_VALUE				0
#define DCCA_MAX_CID_VALUE				100000

#define DCCA_MIN_HCU_SIZE				1
#define DCCA_MAX_HCU_SIZE				50

#define DCCA_MIN_BOOL_SIZE				0
#define DCCA_MAX_BOOL_SIZE				1

#endif
