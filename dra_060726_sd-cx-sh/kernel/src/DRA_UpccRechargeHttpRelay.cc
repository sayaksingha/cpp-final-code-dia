//----------------------------------------------------------------------
// NAME :  DRA_UpccRechargeHttpRelayRouting.cc
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

#include "DRA_UpccRechargeHttpRelay.h"

//-------------------------------------------------------------------------------
// METHOD      : DRA_UpccRechargeHttpRelay
// DESCRIPTION : Parameter Constructor
// PARAMETER   : AAA_Task &task, DRA_UpccRechargeHttpRelayRouting &routing
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
DRA_UpccRechargeHttpRelay::DRA_UpccRechargeHttpRelay(AAA_Task &task, DraRouting &routing, int ModuleId) :
	Dra( task, routing, ModuleId)
{
	mDestPeerEntry   = NULL;
	mSourcePeerEntry = NULL;
	//mRouting         = &routing;
	//mModuleId		  = ModuleId;
}


//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
DRA_UpccRechargeHttpRelay::~DRA_UpccRechargeHttpRelay ()
{
}

//-------------------------------------------------------------------------------
// METHOD      : 
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
DiameterGxProxySession* DRA_UpccRechargeHttpRelay::CreateInstance()
{
	return new DRA_UpccRechargeHttpRelay(mTask, *(mRouting), mModuleId );
	//return new DRA_UpccRechargeHttpRelay();
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DRA_UpccRechargeHttpRelay::ccEventRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
{
	if (mSourcePeerEntry == NULL) // If its not null then its retransmitted message
	{
		std::string lLogText = LOG_DIAMETER_AVPS(*msg);	
		if ( AVP_BASED == mRouting->getRoutingType())
		{
			AAA_LOG((LM_INFO,"%T |DRA_HTTP_APP| %s Routing Configured for the message, Type:AVP_BASED\n", lLogText.c_str()));

			this->GetRoutingDetails(*msg, dest);
			dest->Dump();
		}
		else
		{
			AAA_LOG((LM_INFO,"%T |DRA_HTTP_APP| %s Routing Configured for the message\n", lLogText.c_str()));
			if(!mRouting->getPeer(dest, msg->sessionId))
				AAA_LOG((LM_ERROR,"%T |DRA_HTTP_APP| %s No Active peers\n", lLogText.c_str()));
			dest->Dump();
		}

		mSourcePeerEntry = source;

		if ( true != mRouting->CheckPeerStatus( dest  ) )
			mRouting->getActiveDefPeer( dest, msg->sessionId );
		AAA_LOG((LM_DEBUG, "%T |DRA_APP| got Active Default peer \n ")); //TBC-Anshul	
		mDestPeerEntry   = dest;

		try{
			//msg->baseClass->getDestinationHost()->getValue();
			msg->baseClass->setDestinationRealm()->setValue(const_cast<char*>(dest->GetRealmName().c_str()));
			msg->baseClass->setDestinationHost()->setValue(const_cast<char*>(dest->GetPeerName().c_str()));
		}
		catch(...)
		{
			AAA_LOG((LM_ERROR,"%T |DRA_HTTP_APP|SId:%s Application-Id:%d Failed to set Destination host\n",msg->sessionId.c_str(),msg->hdr.mApplId));
		}
	}
	else
	{
		mSourcePeerEntry = source;
		ccUpdateRequestReceived(msg, source, dest);	
	} 

	//Store request info
	RO::CCRequest *lCCRequest;

	switch(msg->hdr.mApplId)
	{
		case AAA_Ro_APP_ID:
			lCCRequest = reinterpret_cast<RO::CCRequest*>(msg->baseClass.get()); 
			break;
		default:
			AAA_LOG((LM_ERROR,"%T |DRA_HTTP_APP| SId:%s Unsupported Application-Id:%d\n",msg->sessionId.c_str(),msg->hdr.mApplId));
			return ;
	}


	std::shared_ptr<DRA_HttpReq> lDRA_HttpReq(new DRA_HttpReq);

	try
	{
		lDRA_HttpReq->mReqType = lCCRequest->getCCRequestType()->getValue();
		if ( CC_TYPE_EVENT_REQUEST != lDRA_HttpReq->mReqType )
		{
			AAA_LOG((LM_ERROR,"%T |DRA_HTTP_APP| SId:%s Application-Id:%d RT:%d Invalid request type\n",msg->sessionId.c_str(),msg->hdr.mApplId, lDRA_HttpReq->mReqType));
			return;
		}
	}
	DRA_HANDLE_EXCEPTION_EXIT("Error while decoding request type.");


	try
	{
		lDRA_HttpReq->mReferenceid = lCCRequest->getSessionId()->ToString();
	}
	DRA_HANDLE_EXCEPTION_EXIT("Failed to decode session id");

   if ( false == DRA_STORE_RECH_REQ()->Lookup(lDRA_HttpReq->mReferenceid, lDRA_HttpReq))
	{
		bool lSubscriberDataFndFlg = false;
		try
		{
			list<RO::SubscriptionId*>* lSubscriptionIdGrpList = lCCRequest->getSubscriptionIdGrpList();

			for(auto itr : *lSubscriptionIdGrpList)
			{

				if ( 0 == itr->getSubscriptionIdType()->getValue())
				{
					lSubscriberDataFndFlg = true;
					lDRA_HttpReq->mMsisdn = itr->getSubscriptionIdData()->ToString();

				}
			}
		}
		DRA_HANDLE_EXCEPTION_EXIT("Failed to decode subscriber data");

		if ( !lSubscriberDataFndFlg )
		{	
			AAA_LOG((LM_ERROR,"%T |DRA_HTTP_APP| SId:%s Application-Id:%d Subscriber Msisdn not found\n",msg->sessionId.c_str(),msg->hdr.mApplId));
			//print error
			return;
		}

		try{
			//lDRA_HttpReq->mRechargeIdent = to_string(lCCRequest->getServiceInformation()->getINInformation()->getRechargeInformation()->getChargeMoney()->getMoneyValue()->getValue());
		}
		DRA_HANDLE_EXCEPTION_EXIT("Error while decoding Recharge information");

		try{
			time_t lTime = lCCRequest->getEventTimestamp()->getValue();
			struct  tm local_tm;
			localtime_r(&lTime, &local_tm);

			char lTimeStr[DRA_MAX_TIME_LEN] = "" ;
			snprintf( lTimeStr, DRA_MAX_TIME_LEN, "%04d/%02d/%02d %02d:%02d:%02d", 
					(local_tm.tm_year + 1900), (local_tm.tm_mon + 1) , local_tm.tm_mday, local_tm.tm_hour, local_tm.tm_min, local_tm.tm_sec);

			lDRA_HttpReq->mRequestTS.append(lTimeStr);
		}
		DRA_HANDLE_EXCEPTION_CONTINUE("Error while decoding Recharge time stamp");

		DRA_STORE_RECH_REQ()->InsertReq(lDRA_HttpReq->mReferenceid, lDRA_HttpReq); 
		AAA_LOG((LM_DEBUG,"%T |DRA_HTTP_APP|T ReferenceID inserted into DRA store \n "));  //TBC-Anshul-18-dec
	}
	return ;
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DRA_UpccRechargeHttpRelay::ccEventAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
{
	//dest = mDestPeerEntry;
	AAA_LOG((LM_ERROR,"%T |DRA_HTTP_APP| SId:%s EVENT DRA_Http Answer received \n",msg->sessionId.c_str()));

	std::shared_ptr<DRA_HttpReq> lDRA_HttpReq;

	//Store request info
	RO::CCAnswer *lCCAnswer;

	switch(msg->hdr.mApplId)
	{
		case AAA_Ro_APP_ID:
			lCCAnswer = reinterpret_cast<RO::CCAnswer*>(msg->baseClass.get());
			break;
		default:
			AAA_LOG((LM_ERROR,"%T |DRA_HTTP_APP|SId:%s Unsupported Application-Id:%d\n",msg->sessionId.c_str(),msg->hdr.mApplId));
			return ;
	}

	string lRefId = "";
	try
	{
		lRefId = lCCAnswer->getSessionId()->ToString();
	}
	DRA_HANDLE_EXCEPTION_EXIT("Failed to decode session id in CCAnswer");

	INT32 lResultCode = 0;

	try{
		lResultCode = (int) lCCAnswer->getResultCode()->getValue();
	}
	DRA_HANDLE_EXCEPTION_CONTINUE("Failed to decode result code");


	auto it = DRA_CONFIG_HDLR()->mResultCodeMap.find(lResultCode);

	if ( it != DRA_CONFIG_HDLR()->mResultCodeMap.end())
	{
		if (DRA_STORE_RECH_REQ()->Lookup(lRefId, lDRA_HttpReq))
		{
			lDRA_HttpReq->mResultCode = lResultCode;
		}
		else
		{
			AAA_LOG((LM_ERROR,"%T |DRA_HTTP_APP|SId:%s Session is not available\n",msg->sessionId.c_str()));
			//Error
			return;
		}

		if ( lDRA_HttpReq.use_count() != 0)
		{
			DRA_HTTP_REQ_WRITER()->SendReq( lDRA_HttpReq, true); //Need to check this...
			AAA_LOG((LM_INFO, "%T |DRA_HTTP_APP|SId:%s RC:%d EVENT DRA_Http Answer : Url call success\n",msg->sessionId.c_str(), lResultCode));
		}
		else
		{
			AAA_LOG((LM_ERROR,"%T |DRA_HTTP_APP|SId:%s RC:%d EVENT DRA_Http Answer received. Ptr is NULL \n",msg->sessionId.c_str(), lResultCode));
		}
	}
	else
	{
		DRA_STORE_RECH_REQ()->DeleteReq(lRefId, lDRA_HttpReq);
		AAA_LOG((LM_ERROR,"%T |DRA_HTTP_APP|SId:%s RC:%d EVENT DRA_Http Answer: Not relaying message to applicatgion \n",msg->sessionId.c_str(), lResultCode));
	}
	return;
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DRA_UpccRechargeHttpRelay::GenerateFile()
{
	//Taken care in DRA
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DRA_UpccRechargeHttpRelay::SetAlarmForNextDay()
{
	//Taken care in DRA
}


