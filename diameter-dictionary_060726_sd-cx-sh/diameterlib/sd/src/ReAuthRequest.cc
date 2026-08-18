#include "sd/include/ReAuthRequest.h"

using namespace SD;
BOOLEAN ReAuthRequest::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

ReAuthRequest::ReAuthRequest()
{
	mSessionId = NULL;
	mDRMP = NULL;
	mAuthApplicationId = NULL;
	mOriginHost = NULL;
	mOriginRealm = NULL;
	mDestinationRealm = NULL;
	mDestinationHost = NULL;
	mReAuthRequestType = NULL;
	mSessionReleaseCause = NULL;
	mOriginStateId = NULL;
	mOCSupportedFeaturesGrp = NULL;
	mQoSInformationGrp = NULL;
	mEventTriggerList = NULL;
	mCSGInformationReportingList = NULL;
	mEventReportIndicationGrp = NULL;
	mADCRuleRemoveGrpList = NULL;
	mADCRuleInstallGrpList = NULL;
	mRevalidationTime = NULL;
	mUsageMonitoringInformationGrpList = NULL;
	mProxyInfoGrpList = NULL;
	mRouteRecordList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<21>(string("110111001101111111101"));
	mMandatoryAvpSetVal.reset();
}

ReAuthRequest::~ReAuthRequest()
{
	if(mSessionId != NULL)
		delete mSessionId;
	if(mDRMP != NULL)
		delete mDRMP;
	if(mAuthApplicationId != NULL)
		delete mAuthApplicationId;
	if(mOriginHost != NULL)
		delete mOriginHost;
	if(mOriginRealm != NULL)
		delete mOriginRealm;
	if(mDestinationRealm != NULL)
		delete mDestinationRealm;
	if(mDestinationHost != NULL)
		delete mDestinationHost;
	if(mReAuthRequestType != NULL)
		delete mReAuthRequestType;
	if(mSessionReleaseCause != NULL)
		delete mSessionReleaseCause;
	if(mOriginStateId != NULL)
		delete mOriginStateId;
	if(mOCSupportedFeaturesGrp != NULL)
		delete mOCSupportedFeaturesGrp;
	if(mQoSInformationGrp != NULL)
		delete mQoSInformationGrp;
	if(mEventTriggerList != NULL){
		mEventTriggerIterator = mEventTriggerList->begin();
		while(mEventTriggerIterator != mEventTriggerList->end()){
			delete (*mEventTriggerIterator);
			mEventTriggerIterator++;
		}
		delete mEventTriggerList;
	}
	if(mCSGInformationReportingList != NULL){
		mCSGInformationReportingIterator = mCSGInformationReportingList->begin();
		while(mCSGInformationReportingIterator != mCSGInformationReportingList->end()){
			delete (*mCSGInformationReportingIterator);
			mCSGInformationReportingIterator++;
		}
		delete mCSGInformationReportingList;
	}
	if(mEventReportIndicationGrp != NULL)
		delete mEventReportIndicationGrp;
	if(mADCRuleRemoveGrpList != NULL){
		mADCRuleRemoveGrpIterator = mADCRuleRemoveGrpList->begin();
		while(mADCRuleRemoveGrpIterator != mADCRuleRemoveGrpList->end()){
	if(*mADCRuleRemoveGrpIterator != NULL)
			delete (*mADCRuleRemoveGrpIterator);
			mADCRuleRemoveGrpIterator++;
		}
		delete mADCRuleRemoveGrpList;
	}
	if(mADCRuleInstallGrpList != NULL){
		mADCRuleInstallGrpIterator = mADCRuleInstallGrpList->begin();
		while(mADCRuleInstallGrpIterator != mADCRuleInstallGrpList->end()){
	if(*mADCRuleInstallGrpIterator != NULL)
			delete (*mADCRuleInstallGrpIterator);
			mADCRuleInstallGrpIterator++;
		}
		delete mADCRuleInstallGrpList;
	}
	if(mRevalidationTime != NULL)
		delete mRevalidationTime;
	if(mUsageMonitoringInformationGrpList != NULL){
		mUsageMonitoringInformationGrpIterator = mUsageMonitoringInformationGrpList->begin();
		while(mUsageMonitoringInformationGrpIterator != mUsageMonitoringInformationGrpList->end()){
	if(*mUsageMonitoringInformationGrpIterator != NULL)
			delete (*mUsageMonitoringInformationGrpIterator);
			mUsageMonitoringInformationGrpIterator++;
		}
		delete mUsageMonitoringInformationGrpList;
	}
	if(mProxyInfoGrpList != NULL){
		mProxyInfoGrpIterator = mProxyInfoGrpList->begin();
		while(mProxyInfoGrpIterator != mProxyInfoGrpList->end()){
	if(*mProxyInfoGrpIterator != NULL)
			delete (*mProxyInfoGrpIterator);
			mProxyInfoGrpIterator++;
		}
		delete mProxyInfoGrpList;
	}
	if(mRouteRecordList != NULL){
		mRouteRecordIterator = mRouteRecordList->begin();
		while(mRouteRecordIterator != mRouteRecordList->end()){
			delete (*mRouteRecordIterator);
			mRouteRecordIterator++;
		}
		delete mRouteRecordList;
	}
}

OctetString* ReAuthRequest::setSessionId(){
	mMandatoryAvpSetVal [ReAuthRequest_SESSIONID] = 1;
	if(mSessionId == NULL)
	{
		mSessionId = new OctetString();
		mTagsPresent[ReAuthRequest_SESSIONID] = 1;
		return mSessionId;
	}
	return mSessionId;
}

void ReAuthRequest::resetSessionId(){
	mTagsPresent[ReAuthRequest_SESSIONID] = 0;
	if(mSessionId != NULL)
	{
		delete mSessionId; 
		mSessionId = NULL;
	}
}

DRMP* ReAuthRequest::setDRMP(){
	if(mDRMP == NULL)
	{
		mDRMP = new DRMP();
		mTagsPresent[ReAuthRequest_DRMP] = 1;
		return mDRMP;
	}
	return mDRMP;
}

void ReAuthRequest::resetDRMP(){
	mTagsPresent[ReAuthRequest_DRMP] = 0;
	if(mDRMP != NULL)
	{
		delete mDRMP; 
		mDRMP = NULL;
	}
}

Integer32* ReAuthRequest::setAuthApplicationId(){
	mMandatoryAvpSetVal [ReAuthRequest_AUTHAPPLICATIONID] = 1;
	if(mAuthApplicationId == NULL)
	{
		mAuthApplicationId = new Integer32();
		mTagsPresent[ReAuthRequest_AUTHAPPLICATIONID] = 1;
		return mAuthApplicationId;
	}
	return mAuthApplicationId;
}

void ReAuthRequest::resetAuthApplicationId(){
	mTagsPresent[ReAuthRequest_AUTHAPPLICATIONID] = 0;
	if(mAuthApplicationId != NULL)
	{
		delete mAuthApplicationId; 
		mAuthApplicationId = NULL;
	}
}

OctetString* ReAuthRequest::setOriginHost(){
	mMandatoryAvpSetVal [ReAuthRequest_ORIGINHOST] = 1;
	if(mOriginHost == NULL)
	{
		mOriginHost = new OctetString();
		mTagsPresent[ReAuthRequest_ORIGINHOST] = 1;
		return mOriginHost;
	}
	return mOriginHost;
}

void ReAuthRequest::resetOriginHost(){
	mTagsPresent[ReAuthRequest_ORIGINHOST] = 0;
	if(mOriginHost != NULL)
	{
		delete mOriginHost; 
		mOriginHost = NULL;
	}
}

OctetString* ReAuthRequest::setOriginRealm(){
	mMandatoryAvpSetVal [ReAuthRequest_ORIGINREALM] = 1;
	if(mOriginRealm == NULL)
	{
		mOriginRealm = new OctetString();
		mTagsPresent[ReAuthRequest_ORIGINREALM] = 1;
		return mOriginRealm;
	}
	return mOriginRealm;
}

void ReAuthRequest::resetOriginRealm(){
	mTagsPresent[ReAuthRequest_ORIGINREALM] = 0;
	if(mOriginRealm != NULL)
	{
		delete mOriginRealm; 
		mOriginRealm = NULL;
	}
}

OctetString* ReAuthRequest::setDestinationRealm(){
	mMandatoryAvpSetVal [ReAuthRequest_DESTINATIONREALM] = 1;
	if(mDestinationRealm == NULL)
	{
		mDestinationRealm = new OctetString();
		mTagsPresent[ReAuthRequest_DESTINATIONREALM] = 1;
		return mDestinationRealm;
	}
	return mDestinationRealm;
}

void ReAuthRequest::resetDestinationRealm(){
	mTagsPresent[ReAuthRequest_DESTINATIONREALM] = 0;
	if(mDestinationRealm != NULL)
	{
		delete mDestinationRealm; 
		mDestinationRealm = NULL;
	}
}

OctetString* ReAuthRequest::setDestinationHost(){
	mMandatoryAvpSetVal [ReAuthRequest_DESTINATIONHOST] = 1;
	if(mDestinationHost == NULL)
	{
		mDestinationHost = new OctetString();
		mTagsPresent[ReAuthRequest_DESTINATIONHOST] = 1;
		return mDestinationHost;
	}
	return mDestinationHost;
}

void ReAuthRequest::resetDestinationHost(){
	mTagsPresent[ReAuthRequest_DESTINATIONHOST] = 0;
	if(mDestinationHost != NULL)
	{
		delete mDestinationHost; 
		mDestinationHost = NULL;
	}
}

ReAuthRequestType* ReAuthRequest::setReAuthRequestType(){
	mMandatoryAvpSetVal [ReAuthRequest_REAUTHREQUESTTYPE] = 1;
	if(mReAuthRequestType == NULL)
	{
		mReAuthRequestType = new ReAuthRequestType();
		mTagsPresent[ReAuthRequest_REAUTHREQUESTTYPE] = 1;
		return mReAuthRequestType;
	}
	return mReAuthRequestType;
}

void ReAuthRequest::resetReAuthRequestType(){
	mTagsPresent[ReAuthRequest_REAUTHREQUESTTYPE] = 0;
	if(mReAuthRequestType != NULL)
	{
		delete mReAuthRequestType; 
		mReAuthRequestType = NULL;
	}
}

SessionReleaseCause* ReAuthRequest::setSessionReleaseCause(){
	mMandatoryAvpSetVal [ReAuthRequest_SESSIONRELEASECAUSE] = 1;
	if(mSessionReleaseCause == NULL)
	{
		mSessionReleaseCause = new SessionReleaseCause();
		mTagsPresent[ReAuthRequest_SESSIONRELEASECAUSE] = 1;
		return mSessionReleaseCause;
	}
	return mSessionReleaseCause;
}

void ReAuthRequest::resetSessionReleaseCause(){
	mTagsPresent[ReAuthRequest_SESSIONRELEASECAUSE] = 0;
	if(mSessionReleaseCause != NULL)
	{
		delete mSessionReleaseCause; 
		mSessionReleaseCause = NULL;
	}
}

Unsigned32* ReAuthRequest::setOriginStateId(){
	mMandatoryAvpSetVal [ReAuthRequest_ORIGINSTATEID] = 1;
	if(mOriginStateId == NULL)
	{
		mOriginStateId = new Unsigned32();
		mTagsPresent[ReAuthRequest_ORIGINSTATEID] = 1;
		return mOriginStateId;
	}
	return mOriginStateId;
}

void ReAuthRequest::resetOriginStateId(){
	mTagsPresent[ReAuthRequest_ORIGINSTATEID] = 0;
	if(mOriginStateId != NULL)
	{
		delete mOriginStateId; 
		mOriginStateId = NULL;
	}
}

Time* ReAuthRequest::setRevalidationTime(){
	mMandatoryAvpSetVal [ReAuthRequest_REVALIDATIONTIME] = 1;
	if(mRevalidationTime == NULL)
	{
		mRevalidationTime = new Time();
		mTagsPresent[ReAuthRequest_REVALIDATIONTIME] = 1;
		return mRevalidationTime;
	}
	return mRevalidationTime;
}

void ReAuthRequest::resetRevalidationTime(){
	mTagsPresent[ReAuthRequest_REVALIDATIONTIME] = 0;
	if(mRevalidationTime != NULL)
	{
		delete mRevalidationTime; 
		mRevalidationTime = NULL;
	}
}

OctetString* ReAuthRequest::getSessionId(){
	if(NULL == mSessionId) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SessionId is Null");
		throw lTssDiaMsgException;
	}
	if(!mSessionId->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSessionId->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SessionId is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSessionId->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSessionId->Decode(mspByteArray.get(), mSessionId->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SessionId")     ;
			throw lTssDiaMsgException;
		}
		mSessionId->mAvpDecodedFlag = true;
	}
	return mSessionId;
}

DRMP* ReAuthRequest::getDRMP(){
	if(NULL == mDRMP) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DRMP is Null");
		throw lTssDiaMsgException;
	}
	if(!mDRMP->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mDRMP->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DRMP is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mDRMP->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mDRMP->Decode(mspByteArray.get(), mDRMP->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DRMP")     ;
			throw lTssDiaMsgException;
		}
		mDRMP->mAvpDecodedFlag = true;
	}
	return mDRMP;
}

Integer32* ReAuthRequest::getAuthApplicationId(){
	if(NULL == mAuthApplicationId) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AuthApplicationId is Null");
		throw lTssDiaMsgException;
	}
	if(!mAuthApplicationId->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAuthApplicationId->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AuthApplicationId is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAuthApplicationId->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAuthApplicationId->Decode(mspByteArray.get(), mAuthApplicationId->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AuthApplicationId")     ;
			throw lTssDiaMsgException;
		}
		mAuthApplicationId->mAvpDecodedFlag = true;
	}
	return mAuthApplicationId;
}

OctetString* ReAuthRequest::getOriginHost(){
	if(NULL == mOriginHost) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OriginHost is Null");
		throw lTssDiaMsgException;
	}
	if(!mOriginHost->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mOriginHost->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OriginHost is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mOriginHost->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mOriginHost->Decode(mspByteArray.get(), mOriginHost->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OriginHost")     ;
			throw lTssDiaMsgException;
		}
		mOriginHost->mAvpDecodedFlag = true;
	}
	return mOriginHost;
}

OctetString* ReAuthRequest::getOriginRealm(){
	if(NULL == mOriginRealm) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OriginRealm is Null");
		throw lTssDiaMsgException;
	}
	if(!mOriginRealm->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mOriginRealm->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OriginRealm is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mOriginRealm->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mOriginRealm->Decode(mspByteArray.get(), mOriginRealm->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OriginRealm")     ;
			throw lTssDiaMsgException;
		}
		mOriginRealm->mAvpDecodedFlag = true;
	}
	return mOriginRealm;
}

OctetString* ReAuthRequest::getDestinationRealm(){
	if(NULL == mDestinationRealm) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DestinationRealm is Null");
		throw lTssDiaMsgException;
	}
	if(!mDestinationRealm->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mDestinationRealm->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DestinationRealm is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mDestinationRealm->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mDestinationRealm->Decode(mspByteArray.get(), mDestinationRealm->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DestinationRealm")     ;
			throw lTssDiaMsgException;
		}
		mDestinationRealm->mAvpDecodedFlag = true;
	}
	return mDestinationRealm;
}

OctetString* ReAuthRequest::getDestinationHost(){
	if(NULL == mDestinationHost) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DestinationHost is Null");
		throw lTssDiaMsgException;
	}
	if(!mDestinationHost->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mDestinationHost->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DestinationHost is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mDestinationHost->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mDestinationHost->Decode(mspByteArray.get(), mDestinationHost->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DestinationHost")     ;
			throw lTssDiaMsgException;
		}
		mDestinationHost->mAvpDecodedFlag = true;
	}
	return mDestinationHost;
}

ReAuthRequestType* ReAuthRequest::getReAuthRequestType(){
	if(NULL == mReAuthRequestType) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ReAuthRequestType is Null");
		throw lTssDiaMsgException;
	}
	if(!mReAuthRequestType->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mReAuthRequestType->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ReAuthRequestType is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mReAuthRequestType->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mReAuthRequestType->Decode(mspByteArray.get(), mReAuthRequestType->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ReAuthRequestType")     ;
			throw lTssDiaMsgException;
		}
		mReAuthRequestType->mAvpDecodedFlag = true;
	}
	return mReAuthRequestType;
}

SessionReleaseCause* ReAuthRequest::getSessionReleaseCause(){
	if(NULL == mSessionReleaseCause) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SessionReleaseCause is Null");
		throw lTssDiaMsgException;
	}
	if(!mSessionReleaseCause->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSessionReleaseCause->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SessionReleaseCause is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSessionReleaseCause->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSessionReleaseCause->Decode(mspByteArray.get(), mSessionReleaseCause->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SessionReleaseCause")     ;
			throw lTssDiaMsgException;
		}
		mSessionReleaseCause->mAvpDecodedFlag = true;
	}
	return mSessionReleaseCause;
}

Unsigned32* ReAuthRequest::getOriginStateId(){
	if(NULL == mOriginStateId) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OriginStateId is Null");
		throw lTssDiaMsgException;
	}
	if(!mOriginStateId->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mOriginStateId->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OriginStateId is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mOriginStateId->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mOriginStateId->Decode(mspByteArray.get(), mOriginStateId->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OriginStateId")     ;
			throw lTssDiaMsgException;
		}
		mOriginStateId->mAvpDecodedFlag = true;
	}
	return mOriginStateId;
}

OCSupportedFeatures* ReAuthRequest::getOCSupportedFeatures()
{
	if(mOCSupportedFeaturesGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OCSupportedFeatures is Null");
		throw lTssDiaMsgException;
	}
	if(!mOCSupportedFeaturesGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mOCSupportedFeaturesGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OCSupportedFeatures is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mOCSupportedFeaturesGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mOCSupportedFeaturesGrp->Decode(mspByteArray.get(), mOCSupportedFeaturesGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OCSupportedFeatures")     ;
			throw lTssDiaMsgException;
		}
		mOCSupportedFeaturesGrp->mAvpDecodedFlag = true;
	}
	return mOCSupportedFeaturesGrp;
}

OCSupportedFeatures* ReAuthRequest::setOCSupportedFeatures(){
	if(mOCSupportedFeaturesGrp == NULL)
		mOCSupportedFeaturesGrp = new OCSupportedFeatures();
	mTagsPresent[ReAuthRequest_OCSUPPORTEDFEATURES] = 1;
	return mOCSupportedFeaturesGrp;
}

void ReAuthRequest::resetOCSupportedFeatures(){
	mTagsPresent[ReAuthRequest_OCSUPPORTEDFEATURES] = 0;
	if(mOCSupportedFeaturesGrp != NULL)
		delete mOCSupportedFeaturesGrp;
}

QoSInformation* ReAuthRequest::getQoSInformation()
{
	if(mQoSInformationGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "QoSInformation is Null");
		throw lTssDiaMsgException;
	}
	if(!mQoSInformationGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mQoSInformationGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "QoSInformation is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mQoSInformationGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mQoSInformationGrp->Decode(mspByteArray.get(), mQoSInformationGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding QoSInformation")     ;
			throw lTssDiaMsgException;
		}
		mQoSInformationGrp->mAvpDecodedFlag = true;
	}
	return mQoSInformationGrp;
}

QoSInformation* ReAuthRequest::setQoSInformation(){
	if(mQoSInformationGrp == NULL)
		mQoSInformationGrp = new QoSInformation();
	mTagsPresent[ReAuthRequest_QOSINFORMATION] = 1;
	mMandatoryAvpSetVal[ReAuthRequest_QOSINFORMATION] = 1;
	return mQoSInformationGrp;
}

void ReAuthRequest::resetQoSInformation(){
	mTagsPresent[ReAuthRequest_QOSINFORMATION] = 0;
	if(mQoSInformationGrp != NULL)
		delete mQoSInformationGrp;
}

list<EventTrigger*>* ReAuthRequest::getEventTriggerList()
{
	if(mEventTriggerList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "EventTrigger is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr :* mEventTriggerList)
	{
		if(!itr->mAvpDecodedFlag)
		{
	if(mspByteArray.get() == NULL)
		{
	itr->mAvpDecodedFlag = true;
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "EventTrigger is Null");
		throw lTssDiaMsgException;
	}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding EventTrigger")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mEventTriggerList;
}

list<EventTrigger*>* ReAuthRequest::setEventTriggerList() {
	mTagsPresent[ReAuthRequest_EVENTTRIGGER] = 1;
	if(mEventTriggerList == NULL)
		mEventTriggerList = new list<EventTrigger*>;
	mMandatoryAvpSetVal [ReAuthRequest_EVENTTRIGGER] = 1;
	mEventTriggerList->clear();
	return mEventTriggerList;
}

void ReAuthRequest::resetEventTriggerList(){
	mTagsPresent[ReAuthRequest_EVENTTRIGGER] = 0;
	if(mEventTriggerList != NULL)
		delete mEventTriggerList;
}

list<CSGInformationReporting*>* ReAuthRequest::getCSGInformationReportingList()
{
	if(mCSGInformationReportingList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CSGInformationReporting is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr :* mCSGInformationReportingList)
	{
		if(!itr->mAvpDecodedFlag)
		{
	if(mspByteArray.get() == NULL)
		{
	itr->mAvpDecodedFlag = true;
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CSGInformationReporting is Null");
		throw lTssDiaMsgException;
	}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CSGInformationReporting")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mCSGInformationReportingList;
}

list<CSGInformationReporting*>* ReAuthRequest::setCSGInformationReportingList() {
	mTagsPresent[ReAuthRequest_CSGINFORMATIONREPORTING] = 1;
	if(mCSGInformationReportingList == NULL)
		mCSGInformationReportingList = new list<CSGInformationReporting*>;
	mCSGInformationReportingList->clear();
	return mCSGInformationReportingList;
}

void ReAuthRequest::resetCSGInformationReportingList(){
	mTagsPresent[ReAuthRequest_CSGINFORMATIONREPORTING] = 0;
	if(mCSGInformationReportingList != NULL)
		delete mCSGInformationReportingList;
}

EventReportIndication* ReAuthRequest::getEventReportIndication()
{
	if(mEventReportIndicationGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "EventReportIndication is Null");
		throw lTssDiaMsgException;
	}
	if(!mEventReportIndicationGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mEventReportIndicationGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "EventReportIndication is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mEventReportIndicationGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mEventReportIndicationGrp->Decode(mspByteArray.get(), mEventReportIndicationGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding EventReportIndication")     ;
			throw lTssDiaMsgException;
		}
		mEventReportIndicationGrp->mAvpDecodedFlag = true;
	}
	return mEventReportIndicationGrp;
}

EventReportIndication* ReAuthRequest::setEventReportIndication(){
	if(mEventReportIndicationGrp == NULL)
		mEventReportIndicationGrp = new EventReportIndication();
	mTagsPresent[ReAuthRequest_EVENTREPORTINDICATION] = 1;
	return mEventReportIndicationGrp;
}

void ReAuthRequest::resetEventReportIndication(){
	mTagsPresent[ReAuthRequest_EVENTREPORTINDICATION] = 0;
	if(mEventReportIndicationGrp != NULL)
		delete mEventReportIndicationGrp;
}

list<ADCRuleRemove*>* ReAuthRequest::getADCRuleRemoveGrpList()
{
	if(mADCRuleRemoveGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ADCRuleRemove is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mADCRuleRemoveGrpList)
	{
		if(mADCRuleRemoveGrpList != NULL)
		{
		if(mADCRuleRemoveGrpList->size() == 0)
		{
			mTagsPresent[ReAuthRequest_ADCRULEREMOVE] = 0;
			mADCRuleRemoveGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ADCRuleRemove is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ADCRuleRemove is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleRemove")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mADCRuleRemoveGrpList;
}

list<ADCRuleRemove*>* ReAuthRequest::setADCRuleRemoveGrpList(){
	mTagsPresent[ReAuthRequest_ADCRULEREMOVE] = 1;
	if(mADCRuleRemoveGrpList == NULL)
		mADCRuleRemoveGrpList = new list<ADCRuleRemove*>;
	mMandatoryAvpSetVal[ReAuthRequest_ADCRULEREMOVE] = 1;
	mADCRuleRemoveGrpList->clear();
	return mADCRuleRemoveGrpList;
}

void ReAuthRequest::resetADCRuleRemoveGrpList(){
	mTagsPresent[ReAuthRequest_ADCRULEREMOVE] = 0;
	if(mADCRuleRemoveGrpList != NULL)
		delete mADCRuleRemoveGrpList;
}

list<ADCRuleInstall*>* ReAuthRequest::getADCRuleInstallGrpList()
{
	if(mADCRuleInstallGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ADCRuleInstall is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mADCRuleInstallGrpList)
	{
		if(mADCRuleInstallGrpList != NULL)
		{
		if(mADCRuleInstallGrpList->size() == 0)
		{
			mTagsPresent[ReAuthRequest_ADCRULEINSTALL] = 0;
			mADCRuleInstallGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ADCRuleInstall is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ADCRuleInstall is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleInstall")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mADCRuleInstallGrpList;
}

list<ADCRuleInstall*>* ReAuthRequest::setADCRuleInstallGrpList(){
	mTagsPresent[ReAuthRequest_ADCRULEINSTALL] = 1;
	if(mADCRuleInstallGrpList == NULL)
		mADCRuleInstallGrpList = new list<ADCRuleInstall*>;
	mMandatoryAvpSetVal[ReAuthRequest_ADCRULEINSTALL] = 1;
	mADCRuleInstallGrpList->clear();
	return mADCRuleInstallGrpList;
}

void ReAuthRequest::resetADCRuleInstallGrpList(){
	mTagsPresent[ReAuthRequest_ADCRULEINSTALL] = 0;
	if(mADCRuleInstallGrpList != NULL)
		delete mADCRuleInstallGrpList;
}

Time* ReAuthRequest::getRevalidationTime(){
	if(NULL == mRevalidationTime) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RevalidationTime is Null");
		throw lTssDiaMsgException;
	}
	if(!mRevalidationTime->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRevalidationTime->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RevalidationTime is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRevalidationTime->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRevalidationTime->Decode(mspByteArray.get(), mRevalidationTime->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RevalidationTime")     ;
			throw lTssDiaMsgException;
		}
		mRevalidationTime->mAvpDecodedFlag = true;
	}
	return mRevalidationTime;
}

list<UsageMonitoringInformation*>* ReAuthRequest::getUsageMonitoringInformationGrpList()
{
	if(mUsageMonitoringInformationGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UsageMonitoringInformation is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mUsageMonitoringInformationGrpList)
	{
		if(mUsageMonitoringInformationGrpList != NULL)
		{
		if(mUsageMonitoringInformationGrpList->size() == 0)
		{
			mTagsPresent[ReAuthRequest_USAGEMONITORINGINFORMATION] = 0;
			mUsageMonitoringInformationGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UsageMonitoringInformation is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UsageMonitoringInformation is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UsageMonitoringInformation")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mUsageMonitoringInformationGrpList;
}

list<UsageMonitoringInformation*>* ReAuthRequest::setUsageMonitoringInformationGrpList(){
	mTagsPresent[ReAuthRequest_USAGEMONITORINGINFORMATION] = 1;
	if(mUsageMonitoringInformationGrpList == NULL)
		mUsageMonitoringInformationGrpList = new list<UsageMonitoringInformation*>;
	mUsageMonitoringInformationGrpList->clear();
	return mUsageMonitoringInformationGrpList;
}

void ReAuthRequest::resetUsageMonitoringInformationGrpList(){
	mTagsPresent[ReAuthRequest_USAGEMONITORINGINFORMATION] = 0;
	if(mUsageMonitoringInformationGrpList != NULL)
		delete mUsageMonitoringInformationGrpList;
}

list<SD::ProxyInfo*>* ReAuthRequest::getProxyInfoGrpList()
{
	if(mProxyInfoGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ProxyInfo is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mProxyInfoGrpList)
	{
		if(mProxyInfoGrpList != NULL)
		{
		if(mProxyInfoGrpList->size() == 0)
		{
			mTagsPresent[ReAuthRequest_PROXYINFO] = 0;
			mProxyInfoGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ProxyInfo is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ProxyInfo is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ProxyInfo")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mProxyInfoGrpList;
}

list<SD::ProxyInfo*>* ReAuthRequest::setProxyInfoGrpList(){
	mTagsPresent[ReAuthRequest_PROXYINFO] = 1;
	if(mProxyInfoGrpList == NULL)
		mProxyInfoGrpList = new list<SD::ProxyInfo*>;
	mMandatoryAvpSetVal[ReAuthRequest_PROXYINFO] = 1;
	mProxyInfoGrpList->clear();
	return mProxyInfoGrpList;
}

void ReAuthRequest::resetProxyInfoGrpList(){
	mTagsPresent[ReAuthRequest_PROXYINFO] = 0;
	if(mProxyInfoGrpList != NULL)
		delete mProxyInfoGrpList;
}

list<OctetString*>* ReAuthRequest::getRouteRecordList()
{
	if(mRouteRecordList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RouteRecord is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mRouteRecordList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RouteRecord is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RouteRecord")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mRouteRecordList;
}

list<OctetString*>* ReAuthRequest::setRouteRecordList() {
	mTagsPresent[ReAuthRequest_ROUTERECORD] = 1;
	if(mRouteRecordList == NULL)
		mRouteRecordList = new list<OctetString*>;
	mMandatoryAvpSetVal [ReAuthRequest_ROUTERECORD] = 1;
	mRouteRecordList->clear();
	return mRouteRecordList;
}

void ReAuthRequest::resetRouteRecordList(){
	mTagsPresent[ReAuthRequest_ROUTERECORD] = 0;
	if(mRouteRecordList != NULL)
		delete mRouteRecordList;
}



int ReAuthRequest::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;
	unsigned lLengthOffset = 0;
	array->size=0;
	array->offset = 0;
	memset(array, 0, sizeof(byteArray));
	memcpy(&array->byte[ array->offset++], &mDiameterMsgHeader->mVersion, sizeof(UINT8));
	lLengthOffset = array->offset;
	array->offset +=3;
	UINT8   lCmdFlg = this->getCmdFlag();
	memcpy(&array->byte[ array->offset++], &lCmdFlg, sizeof(UINT8));
	array->byte[array->offset++] = (258>>16) & 0xFF;
	array->byte[array->offset++] = (258>>8) & 0xFF;
	array->byte[array->offset++] = (258) & 0xFF;
	lTempHtonlVar =  htonl(mDiameterMsgHeader->mApplId);
	memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_APPLN_ID_SIZE);
	array->offset += DIA_APPLN_ID_SIZE; 
	lTempHtonlVar =  htonl(mDiameterMsgHeader->mHopByHopId);
	memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_HOP_BY_HOP_ID_SIZE);
	array->offset += DIA_HOP_BY_HOP_ID_SIZE; 
	lTempHtonlVar =  htonl(mDiameterMsgHeader->mEndToEndId);
	memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_END_TO_END_ID_SIZE);
	array->offset += DIA_END_TO_END_ID_SIZE;
	array->size = array->offset;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case ReAuthRequest_SESSIONID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(263);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 64;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(64))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mSessionId->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSessionId->getAvpOffsetLen().first], mSessionId->getAvpOffsetLen().second);
						array->offset += mSessionId->getAvpOffsetLen().second;
						array->size += mSessionId->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mSessionId->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mSessionId->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SessionId");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mSessionId->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mSessionId->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SessionId");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ReAuthRequest_DRMP:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(301);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 0;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(0))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mDRMP->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mDRMP->getAvpOffsetLen().first], mDRMP->getAvpOffsetLen().second);
						array->offset += mDRMP->getAvpOffsetLen().second;
						array->size += mDRMP->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DRMP");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mDRMP->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DRMP");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ReAuthRequest_AUTHAPPLICATIONID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(258);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 64;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(64))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mAuthApplicationId->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAuthApplicationId->getAvpOffsetLen().first], mAuthApplicationId->getAvpOffsetLen().second);
						array->offset += mAuthApplicationId->getAvpOffsetLen().second;
						array->size += mAuthApplicationId->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AuthApplicationId");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mAuthApplicationId->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AuthApplicationId");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ReAuthRequest_ORIGINHOST:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(264);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 64;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(64))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mOriginHost->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mOriginHost->getAvpOffsetLen().first], mOriginHost->getAvpOffsetLen().second);
						array->offset += mOriginHost->getAvpOffsetLen().second;
						array->size += mOriginHost->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mOriginHost->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mOriginHost->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OriginHost");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mOriginHost->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mOriginHost->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OriginHost");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ReAuthRequest_ORIGINREALM:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(296);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 64;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(64))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mOriginRealm->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mOriginRealm->getAvpOffsetLen().first], mOriginRealm->getAvpOffsetLen().second);
						array->offset += mOriginRealm->getAvpOffsetLen().second;
						array->size += mOriginRealm->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mOriginRealm->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mOriginRealm->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OriginRealm");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mOriginRealm->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mOriginRealm->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OriginRealm");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ReAuthRequest_DESTINATIONREALM:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(283);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 64;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(64))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mDestinationRealm->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mDestinationRealm->getAvpOffsetLen().first], mDestinationRealm->getAvpOffsetLen().second);
						array->offset += mDestinationRealm->getAvpOffsetLen().second;
						array->size += mDestinationRealm->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mDestinationRealm->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mDestinationRealm->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DestinationRealm");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mDestinationRealm->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mDestinationRealm->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DestinationRealm");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ReAuthRequest_DESTINATIONHOST:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(293);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 64;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(64))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mDestinationHost->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mDestinationHost->getAvpOffsetLen().first], mDestinationHost->getAvpOffsetLen().second);
						array->offset += mDestinationHost->getAvpOffsetLen().second;
						array->size += mDestinationHost->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mDestinationHost->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mDestinationHost->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DestinationHost");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mDestinationHost->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mDestinationHost->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DestinationHost");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ReAuthRequest_REAUTHREQUESTTYPE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(285);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 64;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(64))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mReAuthRequestType->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mReAuthRequestType->getAvpOffsetLen().first], mReAuthRequestType->getAvpOffsetLen().second);
						array->offset += mReAuthRequestType->getAvpOffsetLen().second;
						array->size += mReAuthRequestType->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ReAuthRequestType");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mReAuthRequestType->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ReAuthRequestType");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ReAuthRequest_SESSIONRELEASECAUSE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1045);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 192;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(192))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mSessionReleaseCause->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSessionReleaseCause->getAvpOffsetLen().first], mSessionReleaseCause->getAvpOffsetLen().second);
						array->offset += mSessionReleaseCause->getAvpOffsetLen().second;
						array->size += mSessionReleaseCause->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SessionReleaseCause");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mSessionReleaseCause->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SessionReleaseCause");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ReAuthRequest_ORIGINSTATEID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(278);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 64;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(64))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mOriginStateId->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mOriginStateId->getAvpOffsetLen().first], mOriginStateId->getAvpOffsetLen().second);
						array->offset += mOriginStateId->getAvpOffsetLen().second;
						array->size += mOriginStateId->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OriginStateId");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mOriginStateId->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OriginStateId");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ReAuthRequest_OCSUPPORTEDFEATURES:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(621);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
				array->size++;
				array->byte[array->offset++] = 0;
				lengthOffset = array->offset; 
				array->offset += 3; 
				array->size += 3; 
				if( true == DiameterTLVUtil::isVenderSpecific(0))
 						{ 
						INT32 venderId=10415;
					array->size+=4;
					lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
						array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
				} 
				if((this->getOCSupportedFeatures()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OCSupportedFeatures");
					throw lTssDiaMsgException;
					}
				}
				break;
			case ReAuthRequest_QOSINFORMATION:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(1016);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
				array->size++;
				array->byte[array->offset++] = 192;
				lengthOffset = array->offset; 
				array->offset += 3; 
				array->size += 3; 
				if( true == DiameterTLVUtil::isVenderSpecific(192))
 						{ 
						INT32 venderId=10415;
					array->size+=4;
					lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
						array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
				} 
				if((this->getQoSInformation()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding QoSInformation");
					throw lTssDiaMsgException;
					}
				}
				break;
			case ReAuthRequest_EVENTTRIGGER:
			{
					if( mEventTriggerList->size() <= 0) {
						break;
					}

					mEventTriggerIterator = this->getEventTriggerList()->begin();
					while(mEventTriggerIterator != mEventTriggerList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(1006);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 192;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(192))
 					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!(*mEventTriggerIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mEventTriggerIterator)->getAvpOffsetLen().first], (*mEventTriggerIterator)->getAvpOffsetLen().second);
						array->offset += (*mEventTriggerIterator)->getAvpOffsetLen().second;
						array->size += (*mEventTriggerIterator)->getAvpOffsetLen().second;
						if(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)
						{
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding EventTrigger");
							throw lTssDiaMsgException;
						}
						mEventTriggerIterator++;
						continue;
					}
					if(((*mEventTriggerIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding EventTrigger");
						throw lTssDiaMsgException;
					}
					mEventTriggerIterator++;
				}
				}
				break;
			case ReAuthRequest_CSGINFORMATIONREPORTING:
			{
					if( mCSGInformationReportingList->size() <= 0) {
						break;
					}

					mCSGInformationReportingIterator = this->getCSGInformationReportingList()->begin();
					while(mCSGInformationReportingIterator != mCSGInformationReportingList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(1071);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
 					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!(*mCSGInformationReportingIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mCSGInformationReportingIterator)->getAvpOffsetLen().first], (*mCSGInformationReportingIterator)->getAvpOffsetLen().second);
						array->offset += (*mCSGInformationReportingIterator)->getAvpOffsetLen().second;
						array->size += (*mCSGInformationReportingIterator)->getAvpOffsetLen().second;
						if(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)
						{
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CSGInformationReporting");
							throw lTssDiaMsgException;
						}
						mCSGInformationReportingIterator++;
						continue;
					}
					if(((*mCSGInformationReportingIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CSGInformationReporting");
						throw lTssDiaMsgException;
					}
					mCSGInformationReportingIterator++;
				}
				}
				break;
			case ReAuthRequest_EVENTREPORTINDICATION:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(1033);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
				array->size++;
				array->byte[array->offset++] = 128;
				lengthOffset = array->offset; 
				array->offset += 3; 
				array->size += 3; 
				if( true == DiameterTLVUtil::isVenderSpecific(128))
 						{ 
						INT32 venderId=10415;
					array->size+=4;
					lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
						array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
				} 
				if((this->getEventReportIndication()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding EventReportIndication");
					throw lTssDiaMsgException;
					}
				}
				break;
			case ReAuthRequest_ADCRULEREMOVE:
			{
				if( mADCRuleRemoveGrpList->size() <= 0) {
					break;
				}

				mADCRuleRemoveGrpIterator = this->getADCRuleRemoveGrpList()->begin();
				while(mADCRuleRemoveGrpIterator != mADCRuleRemoveGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(1093);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 192;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(192))
						{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(((*mADCRuleRemoveGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ADCRuleRemove");
						throw lTssDiaMsgException;
					}
					
					mADCRuleRemoveGrpIterator++;
				}
				}
				break;
			case ReAuthRequest_ADCRULEINSTALL:
			{
				if( mADCRuleInstallGrpList->size() <= 0) {
					break;
				}

				mADCRuleInstallGrpIterator = this->getADCRuleInstallGrpList()->begin();
				while(mADCRuleInstallGrpIterator != mADCRuleInstallGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(1092);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 192;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(192))
						{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(((*mADCRuleInstallGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ADCRuleInstall");
						throw lTssDiaMsgException;
					}
					
					mADCRuleInstallGrpIterator++;
				}
				}
				break;
			case ReAuthRequest_REVALIDATIONTIME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1042);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 192;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(192))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mRevalidationTime->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRevalidationTime->getAvpOffsetLen().first], mRevalidationTime->getAvpOffsetLen().second);
						array->offset += mRevalidationTime->getAvpOffsetLen().second;
						array->size += mRevalidationTime->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mRevalidationTime->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mRevalidationTime->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RevalidationTime");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mRevalidationTime->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mRevalidationTime->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RevalidationTime");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ReAuthRequest_USAGEMONITORINGINFORMATION:
			{
				if( mUsageMonitoringInformationGrpList->size() <= 0) {
					break;
				}

				mUsageMonitoringInformationGrpIterator = this->getUsageMonitoringInformationGrpList()->begin();
				while(mUsageMonitoringInformationGrpIterator != mUsageMonitoringInformationGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(1067);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
						{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(((*mUsageMonitoringInformationGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UsageMonitoringInformation");
						throw lTssDiaMsgException;
					}
					
					mUsageMonitoringInformationGrpIterator++;
				}
				}
				break;
			case ReAuthRequest_PROXYINFO:
			{
				if( mProxyInfoGrpList->size() <= 0) {
					break;
				}

				mProxyInfoGrpIterator = this->getProxyInfoGrpList()->begin();
				while(mProxyInfoGrpIterator != mProxyInfoGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(284);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 64;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(64))
						{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(((*mProxyInfoGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ProxyInfo");
						throw lTssDiaMsgException;
					}
					
					mProxyInfoGrpIterator++;
				}
				}
				break;
			case ReAuthRequest_ROUTERECORD:
			{
					if( mRouteRecordList->size() <= 0) {
						break;
					}

					mRouteRecordIterator = this->getRouteRecordList()->begin();
					while(mRouteRecordIterator != mRouteRecordList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(282);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 64;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(64))
 					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!(*mRouteRecordIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mRouteRecordIterator)->getAvpOffsetLen().first], (*mRouteRecordIterator)->getAvpOffsetLen().second);
						array->offset += (*mRouteRecordIterator)->getAvpOffsetLen().second;
						array->size += (*mRouteRecordIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mRouteRecordIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mRouteRecordIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RouteRecord");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mRouteRecordIterator++;
						continue;
					}
						if(((*mRouteRecordIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mRouteRecordIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RouteRecord");
							throw lTssDiaMsgException;
						}
						mRouteRecordIterator++;
				}
				}
				break;
			default:
				//printf("Unknown Tag received Tag:%d Offset:%d\n", mTagArray[lTemp], array->offset);
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE);
					throw lTssDiaMsgException;
				break;
		}
	}

	if(DiameterTLVUtil::avp_msg_length_encode(lLengthOffset, array) == false){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE);
		throw lTssDiaMsgException;
	}

	return DIAMETER_NO_ERR;
}


int ReAuthRequest::Decode(byteArray *array, INT16 lMLen, UINT16 *parsedBytes)
{
	if(mDiameterMsgHeader == NULL){
		mDiameterMsgHeader = new DiameterMsgHeader();
		if(mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
		}
	}
	mspByteArray = make_shared<byteArray>();
	memcpy(mspByteArray.get(), array, sizeof(byteArray));
	mAvpDecodedFlag = true;
	array->offset = 0;
	UINT32  	lMsgLen = 0;
	UINT8   	lCmdFlag= 0;
	memcpy( &mDiameterMsgHeader->mVersion, &array->byte[0],sizeof(UINT8));
	if( mDiameterMsgHeader->mVersion != 1){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_VERSION_ERR, "Version");
		throw lTssDiaMsgException;
	}

	array->offset++;
	if(false == DiameterTLVUtil::decodeMessageLength(array, mDiameterMsgHeader->mMsgLen))
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
		throw lTssDiaMsgException;
	}

	memcpy( &lCmdFlag, &array->byte[array->offset++],sizeof(UINT8));
	this->setCmdFlag(lCmdFlag)
;	if(false == DiameterTLVUtil::decodeAvpCmdIntegerValue(array, mDiameterMsgHeader->mCmdCode, DIA_CMD_CODE_SIZE))
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
		throw lTssDiaMsgException;
	}

	if(false == DiameterTLVUtil::decodeIntegerValue(array, mDiameterMsgHeader->mApplId, DIA_APPLN_ID_SIZE))
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
		throw lTssDiaMsgException;
	}

	if(false == DiameterTLVUtil::decodeIntegerValue(array, mDiameterMsgHeader->mHopByHopId, DIA_HOP_BY_HOP_ID_SIZE))
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
		throw lTssDiaMsgException;
	}

	if(false == DiameterTLVUtil::decodeIntegerValue(array, mDiameterMsgHeader->mEndToEndId, DIA_END_TO_END_ID_SIZE))
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
		throw lTssDiaMsgException;
	}

	lMsgLen = (mDiameterMsgHeader->mMsgLen-array->offset);
	if( mDiameterMsgHeader->mMsgLen != array->size){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, "Invalid Msg Len");
		throw lTssDiaMsgException;
	}
	mDecodeFlag = true;
	while( lMsgLen > 0)
	{
		UINT32  lAvpCode;
		UINT8   lAvpFlag = 0;
		UINT32  lAvpLen = 0;
		UINT32  lVenderId = 0;
		UINT32  lAvpHeaderLen = 8;
		UINT32  lAvpDataLen = 0;
		if(false == DiameterTLVUtil::decodeIntegerValue(array, lAvpCode, DIA_AVP_CODE_SIZE))
		{
			mDecodeFlag = false;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP code");
			throw lTssDiaMsgException;
		}
		memcpy( &lAvpFlag, &array->byte[array->offset++],sizeof(UINT8));
		if(false == DiameterTLVUtil::decodeAvpCmdIntegerValue(array, lAvpLen, DIA_AVP_LEN_SIZE))
		{
			mDecodeFlag = false;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP length");
			throw lTssDiaMsgException;
		}
		if(lAvpLen == 0)
		{
			mDecodeFlag = false;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP length");
			throw lTssDiaMsgException;
		}
		if( true == DiameterTLVUtil::isVenderSpecific(lAvpFlag))
		{ 
			lAvpHeaderLen = 12;
			if(false == DiameterTLVUtil::decodeIntegerValue(array, lVenderId, DIA_VENDER_SPEC_APPLN_ID_SIZE))
			{
				mDecodeFlag = false;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Vendor Id");
				throw lTssDiaMsgException;
			}

		}
		lAvpDataLen = lAvpLen-lAvpHeaderLen;
		switch(lAvpCode)
		{
			case 263:
				{
						mMandatoryAvpSetVal [ReAuthRequest_SESSIONID] = 1;
					if( NULL == this->setSessionId())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SessionId");
						throw lTssDiaMsgException;
					}
					mSessionId->setAvpCode(263);
					mSessionId->setAvpVendorId(lVenderId);
					mSessionId->SetDataType((DiameterDataType)5);
					mSessionId->mspByteArray = mspByteArray;
					mSessionId->mAvpDecodedFlag = false;
					mSessionId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 301:
				{
					if( NULL == this->setDRMP())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DRMP");
						throw lTssDiaMsgException;
					}
					mDRMP->setAvpCode(301);
					mDRMP->setAvpVendorId(lVenderId);
					mDRMP->SetDataType((DiameterDataType)7);
					mDRMP->mspByteArray = mspByteArray;
					mDRMP->mAvpDecodedFlag = false;
					mDRMP->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 258:
				{
						mMandatoryAvpSetVal [ReAuthRequest_AUTHAPPLICATIONID] = 1;
					if( NULL == this->setAuthApplicationId())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AuthApplicationId");
						throw lTssDiaMsgException;
					}
					mAuthApplicationId->setAvpCode(258);
					mAuthApplicationId->setAvpVendorId(lVenderId);
					mAuthApplicationId->SetDataType((DiameterDataType)1);
					mAuthApplicationId->mspByteArray = mspByteArray;
					mAuthApplicationId->mAvpDecodedFlag = false;
					mAuthApplicationId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 264:
				{
						mMandatoryAvpSetVal [ReAuthRequest_ORIGINHOST] = 1;
					if( NULL == this->setOriginHost())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OriginHost");
						throw lTssDiaMsgException;
					}
					mOriginHost->setAvpCode(264);
					mOriginHost->setAvpVendorId(lVenderId);
					mOriginHost->SetDataType((DiameterDataType)5);
					mOriginHost->mspByteArray = mspByteArray;
					mOriginHost->mAvpDecodedFlag = false;
					mOriginHost->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 296:
				{
						mMandatoryAvpSetVal [ReAuthRequest_ORIGINREALM] = 1;
					if( NULL == this->setOriginRealm())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OriginRealm");
						throw lTssDiaMsgException;
					}
					mOriginRealm->setAvpCode(296);
					mOriginRealm->setAvpVendorId(lVenderId);
					mOriginRealm->SetDataType((DiameterDataType)5);
					mOriginRealm->mspByteArray = mspByteArray;
					mOriginRealm->mAvpDecodedFlag = false;
					mOriginRealm->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 283:
				{
						mMandatoryAvpSetVal [ReAuthRequest_DESTINATIONREALM] = 1;
					if( NULL == this->setDestinationRealm())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DestinationRealm");
						throw lTssDiaMsgException;
					}
					mDestinationRealm->setAvpCode(283);
					mDestinationRealm->setAvpVendorId(lVenderId);
					mDestinationRealm->SetDataType((DiameterDataType)5);
					mDestinationRealm->mspByteArray = mspByteArray;
					mDestinationRealm->mAvpDecodedFlag = false;
					mDestinationRealm->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 293:
				{
						mMandatoryAvpSetVal [ReAuthRequest_DESTINATIONHOST] = 1;
					if( NULL == this->setDestinationHost())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DestinationHost");
						throw lTssDiaMsgException;
					}
					mDestinationHost->setAvpCode(293);
					mDestinationHost->setAvpVendorId(lVenderId);
					mDestinationHost->SetDataType((DiameterDataType)5);
					mDestinationHost->mspByteArray = mspByteArray;
					mDestinationHost->mAvpDecodedFlag = false;
					mDestinationHost->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 285:
				{
						mMandatoryAvpSetVal [ReAuthRequest_REAUTHREQUESTTYPE] = 1;
					if( NULL == this->setReAuthRequestType())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ReAuthRequestType");
						throw lTssDiaMsgException;
					}
					mReAuthRequestType->setAvpCode(285);
					mReAuthRequestType->setAvpVendorId(lVenderId);
					mReAuthRequestType->SetDataType((DiameterDataType)7);
					mReAuthRequestType->mspByteArray = mspByteArray;
					mReAuthRequestType->mAvpDecodedFlag = false;
					mReAuthRequestType->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1045:
				{
						mMandatoryAvpSetVal [ReAuthRequest_SESSIONRELEASECAUSE] = 1;
					if( NULL == this->setSessionReleaseCause())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SessionReleaseCause");
						throw lTssDiaMsgException;
					}
					mSessionReleaseCause->setAvpCode(1045);
					mSessionReleaseCause->setAvpVendorId(lVenderId);
					mSessionReleaseCause->SetDataType((DiameterDataType)7);
					mSessionReleaseCause->mspByteArray = mspByteArray;
					mSessionReleaseCause->mAvpDecodedFlag = false;
					mSessionReleaseCause->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 278:
				{
						mMandatoryAvpSetVal [ReAuthRequest_ORIGINSTATEID] = 1;
					if( NULL == this->setOriginStateId())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OriginStateId");
						throw lTssDiaMsgException;
					}
					mOriginStateId->setAvpCode(278);
					mOriginStateId->setAvpVendorId(lVenderId);
					mOriginStateId->SetDataType((DiameterDataType)3);
					mOriginStateId->mspByteArray = mspByteArray;
					mOriginStateId->mAvpDecodedFlag = false;
					mOriginStateId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 621:
				{
					mTagsPresent[ReAuthRequest_OCSUPPORTEDFEATURES] = 1;
						if( NULL == this->setOCSupportedFeatures()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OCSupportedFeatures");
						throw lTssDiaMsgException;
						}
					mOCSupportedFeaturesGrp->setAvpCode(621);
					mOCSupportedFeaturesGrp->SetDataType((DiameterDataType)6);
					mOCSupportedFeaturesGrp->mspByteArray = mspByteArray;
					mOCSupportedFeaturesGrp->mAvpDecodedFlag = false;
					mOCSupportedFeaturesGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mOCSupportedFeaturesGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1016:
				{
						mMandatoryAvpSetVal [ReAuthRequest_QOSINFORMATION] = 1;
					mTagsPresent[ReAuthRequest_QOSINFORMATION] = 1;
						if( NULL == this->setQoSInformation()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding QoSInformation");
						throw lTssDiaMsgException;
						}
					mQoSInformationGrp->setAvpCode(1016);
					mQoSInformationGrp->SetDataType((DiameterDataType)6);
					mQoSInformationGrp->mspByteArray = mspByteArray;
					mQoSInformationGrp->mAvpDecodedFlag = false;
					mQoSInformationGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mQoSInformationGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1006:
				{
						mMandatoryAvpSetVal [ReAuthRequest_EVENTTRIGGER] = 1;
					mTagsPresent[ReAuthRequest_EVENTTRIGGER] = 1;
					EventTrigger *lEventTrigger = new EventTrigger();
					if( lEventTrigger == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding EventTrigger");
						throw lTssDiaMsgException;
					}
					lEventTrigger->setAvpCode(1006);
					lEventTrigger->setAvpVendorId(lVenderId);
					lEventTrigger->SetDataType((DiameterDataType)7);
					lEventTrigger->mspByteArray = mspByteArray;
					lEventTrigger->mAvpDecodedFlag = false;
					lEventTrigger->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mEventTriggerList == NULL)
						this->setEventTriggerList();
					mEventTriggerList->push_back(lEventTrigger);
					
				}
				break;
			case 1071:
				{
					mTagsPresent[ReAuthRequest_CSGINFORMATIONREPORTING] = 1;
					CSGInformationReporting *lCSGInformationReporting = new CSGInformationReporting();
					if( lCSGInformationReporting == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CSGInformationReporting");
						throw lTssDiaMsgException;
					}
					lCSGInformationReporting->setAvpCode(1071);
					lCSGInformationReporting->setAvpVendorId(lVenderId);
					lCSGInformationReporting->SetDataType((DiameterDataType)7);
					lCSGInformationReporting->mspByteArray = mspByteArray;
					lCSGInformationReporting->mAvpDecodedFlag = false;
					lCSGInformationReporting->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mCSGInformationReportingList == NULL)
						this->setCSGInformationReportingList();
					mCSGInformationReportingList->push_back(lCSGInformationReporting);
					
				}
				break;
			case 1033:
				{
					mTagsPresent[ReAuthRequest_EVENTREPORTINDICATION] = 1;
						if( NULL == this->setEventReportIndication()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding EventReportIndication");
						throw lTssDiaMsgException;
						}
					mEventReportIndicationGrp->setAvpCode(1033);
					mEventReportIndicationGrp->SetDataType((DiameterDataType)6);
					mEventReportIndicationGrp->mspByteArray = mspByteArray;
					mEventReportIndicationGrp->mAvpDecodedFlag = false;
					mEventReportIndicationGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mEventReportIndicationGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1093:
				{
						mMandatoryAvpSetVal [ReAuthRequest_ADCRULEREMOVE] = 1;
					mTagsPresent[ReAuthRequest_ADCRULEREMOVE] = 1;
					ADCRuleRemove *lADCRuleRemove = new ADCRuleRemove();
					if( lADCRuleRemove == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleRemove");
						throw lTssDiaMsgException;
					}
					lADCRuleRemove->setAvpCode(1093);
					lADCRuleRemove->SetDataType((DiameterDataType)6);
					lADCRuleRemove->mspByteArray = mspByteArray;
					lADCRuleRemove->mAvpDecodedFlag = false;
					lADCRuleRemove->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mADCRuleRemoveGrpList == NULL)
						this->setADCRuleRemoveGrpList();
					mADCRuleRemoveGrpList->push_back(lADCRuleRemove);
					mBaseInterfaceList.push_back(lADCRuleRemove);
					
				}
				break;
			case 1092:
				{
						mMandatoryAvpSetVal [ReAuthRequest_ADCRULEINSTALL] = 1;
					mTagsPresent[ReAuthRequest_ADCRULEINSTALL] = 1;
					ADCRuleInstall *lADCRuleInstall = new ADCRuleInstall();
					if( lADCRuleInstall == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleInstall");
						throw lTssDiaMsgException;
					}
					lADCRuleInstall->setAvpCode(1092);
					lADCRuleInstall->SetDataType((DiameterDataType)6);
					lADCRuleInstall->mspByteArray = mspByteArray;
					lADCRuleInstall->mAvpDecodedFlag = false;
					lADCRuleInstall->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mADCRuleInstallGrpList == NULL)
						this->setADCRuleInstallGrpList();
					mADCRuleInstallGrpList->push_back(lADCRuleInstall);
					mBaseInterfaceList.push_back(lADCRuleInstall);
					
				}
				break;
			case 1042:
				{
						mMandatoryAvpSetVal [ReAuthRequest_REVALIDATIONTIME] = 1;
					if( NULL == this->setRevalidationTime())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RevalidationTime");
						throw lTssDiaMsgException;
					}
					mRevalidationTime->setAvpCode(1042);
					mRevalidationTime->setAvpVendorId(lVenderId);
					mRevalidationTime->SetDataType((DiameterDataType)9);
					mRevalidationTime->mspByteArray = mspByteArray;
					mRevalidationTime->mAvpDecodedFlag = false;
					mRevalidationTime->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1067:
				{
					mTagsPresent[ReAuthRequest_USAGEMONITORINGINFORMATION] = 1;
					UsageMonitoringInformation *lUsageMonitoringInformation = new UsageMonitoringInformation();
					if( lUsageMonitoringInformation == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UsageMonitoringInformation");
						throw lTssDiaMsgException;
					}
					lUsageMonitoringInformation->setAvpCode(1067);
					lUsageMonitoringInformation->SetDataType((DiameterDataType)6);
					lUsageMonitoringInformation->mspByteArray = mspByteArray;
					lUsageMonitoringInformation->mAvpDecodedFlag = false;
					lUsageMonitoringInformation->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mUsageMonitoringInformationGrpList == NULL)
						this->setUsageMonitoringInformationGrpList();
					mUsageMonitoringInformationGrpList->push_back(lUsageMonitoringInformation);
					mBaseInterfaceList.push_back(lUsageMonitoringInformation);
					
				}
				break;
			case 284:
				{
						mMandatoryAvpSetVal [ReAuthRequest_PROXYINFO] = 1;
					mTagsPresent[ReAuthRequest_PROXYINFO] = 1;
					ProxyInfo *lProxyInfo = new ProxyInfo();
					if( lProxyInfo == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ProxyInfo");
						throw lTssDiaMsgException;
					}
					lProxyInfo->setAvpCode(284);
					lProxyInfo->SetDataType((DiameterDataType)6);
					lProxyInfo->mspByteArray = mspByteArray;
					lProxyInfo->mAvpDecodedFlag = false;
					lProxyInfo->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mProxyInfoGrpList == NULL)
						this->setProxyInfoGrpList();
					mProxyInfoGrpList->push_back(lProxyInfo);
					mBaseInterfaceList.push_back(lProxyInfo);
					
				}
				break;
			case 282:
				{
						mMandatoryAvpSetVal [ReAuthRequest_ROUTERECORD] = 1;
					mTagsPresent[ReAuthRequest_ROUTERECORD] = 1;
					OctetString *lRouteRecord = new OctetString();
					if( lRouteRecord == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RouteRecord");
						throw lTssDiaMsgException;
					}
					lRouteRecord->setAvpCode(282);
					lRouteRecord->setAvpVendorId(lVenderId);
					lRouteRecord->SetDataType((DiameterDataType)5);
					lRouteRecord->mspByteArray = mspByteArray;
					lRouteRecord->mAvpDecodedFlag = false;
					lRouteRecord->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mRouteRecordList == NULL)
						this->setRouteRecordList();
					mRouteRecordList->push_back(lRouteRecord);
					
				}
				break;
			default:
				array->offset+=lAvpDataLen;
				//printf("Unknown AvpCode received Avp:%d \n", lAvpCode );
					//TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
					//throw lTssDiaMsgException;
				break;
		}

		if( (lAvpLen % 4) == 0 )
		{
			lMsgLen = lMsgLen -lAvpLen;
		}
		else
		{
			lMsgLen = lMsgLen -( lAvpLen + ( 4-(lAvpLen%4)));
			array->offset+= ( 4-(lAvpLen%4));
		}
	}
	return DIAMETER_NO_ERR;
}


DiameterBaseInterface* ReAuthRequest::Find(byteArray *array, UINT32 avpCode)
{
		if(!mDecodeFlag && array != NULL)
			this->Decode(array);

		switch(avpCode)
		{
			case 263:
			{
				if(mSessionId != NULL)
					return mSessionId->Find(array, avpCode);
				else
					return NULL;
			}
			case 301:
			{
				if(mDRMP != NULL)
					return mDRMP->Find(array, avpCode);
				else
					return NULL;
			}
			case 258:
			{
				if(mAuthApplicationId != NULL)
					return mAuthApplicationId->Find(array, avpCode);
				else
					return NULL;
			}
			case 264:
			{
				if(mOriginHost != NULL)
					return mOriginHost->Find(array, avpCode);
				else
					return NULL;
			}
			case 296:
			{
				if(mOriginRealm != NULL)
					return mOriginRealm->Find(array, avpCode);
				else
					return NULL;
			}
			case 283:
			{
				if(mDestinationRealm != NULL)
					return mDestinationRealm->Find(array, avpCode);
				else
					return NULL;
			}
			case 293:
			{
				if(mDestinationHost != NULL)
					return mDestinationHost->Find(array, avpCode);
				else
					return NULL;
			}
			case 285:
			{
				if(mReAuthRequestType != NULL)
					return mReAuthRequestType->Find(array, avpCode);
				else
					return NULL;
			}
			case 1045:
			{
				if(mSessionReleaseCause != NULL)
					return mSessionReleaseCause->Find(array, avpCode);
				else
					return NULL;
			}
			case 278:
			{
				if(mOriginStateId != NULL)
					return mOriginStateId->Find(array, avpCode);
				else
					return NULL;
			}
			case 1006:
			{
				if(mEventTriggerList != NULL && mEventTriggerList->size() > 0)
					return (mEventTriggerList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 1071:
			{
				if(mCSGInformationReportingList != NULL && mCSGInformationReportingList->size() > 0)
					return (mCSGInformationReportingList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 1042:
			{
				if(mRevalidationTime != NULL)
					return mRevalidationTime->Find(array, avpCode);
				else
					return NULL;
			}
			case 282:
			{
				if(mRouteRecordList != NULL && mRouteRecordList->size() > 0)
					return (mRouteRecordList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			default:
			{
				for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
				{
					DiameterBaseInterface* inf = (*itr)->Find(array, avpCode);
					if(inf != NULL)
						return inf;
				}
				return NULL;
			}
		}
}


BOOLEAN ReAuthRequest::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
		if(!mDecodeFlag && array != NULL)
			this->Decode(array);

		switch(avpCode)
		{
			case 263:
			{
				if(mSessionId != NULL)
				{
					DiameterBaseInterface* inf =  mSessionId->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 301:
			{
				if(mDRMP != NULL)
				{
					DiameterBaseInterface* inf =  mDRMP->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 258:
			{
				if(mAuthApplicationId != NULL)
				{
					DiameterBaseInterface* inf =  mAuthApplicationId->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 264:
			{
				if(mOriginHost != NULL)
				{
					DiameterBaseInterface* inf =  mOriginHost->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 296:
			{
				if(mOriginRealm != NULL)
				{
					DiameterBaseInterface* inf =  mOriginRealm->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 283:
			{
				if(mDestinationRealm != NULL)
				{
					DiameterBaseInterface* inf =  mDestinationRealm->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 293:
			{
				if(mDestinationHost != NULL)
				{
					DiameterBaseInterface* inf =  mDestinationHost->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 285:
			{
				if(mReAuthRequestType != NULL)
				{
					DiameterBaseInterface* inf =  mReAuthRequestType->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1045:
			{
				if(mSessionReleaseCause != NULL)
				{
					DiameterBaseInterface* inf =  mSessionReleaseCause->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 278:
			{
				if(mOriginStateId != NULL)
				{
					DiameterBaseInterface* inf =  mOriginStateId->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 621:
			{
				if(mOCSupportedFeaturesGrp != NULL)
				{
						pBaseInterface.push_back(mOCSupportedFeaturesGrp);
				}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1016:
			{
				if(mQoSInformationGrp != NULL)
				{
						pBaseInterface.push_back(mQoSInformationGrp);
				}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1006:
			{
				if(mEventTriggerList != NULL)
				{
					for(auto itr = mEventTriggerList->begin(); itr != mEventTriggerList->end(); ++itr)
					{
						DiameterBaseInterface* inf =  (*itr)->Find(this->mspByteArray.get(), avpCode);
						if(inf != NULL)
						{
							pBaseInterface.push_back(inf);
						}
					}

					if(deepInspect)
					{
						for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 1071:
			{
				if(mCSGInformationReportingList != NULL)
				{
					for(auto itr = mCSGInformationReportingList->begin(); itr != mCSGInformationReportingList->end(); ++itr)
					{
						DiameterBaseInterface* inf =  (*itr)->Find(this->mspByteArray.get(), avpCode);
						if(inf != NULL)
						{
							pBaseInterface.push_back(inf);
						}
					}

					if(deepInspect)
					{
						for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 1033:
			{
				if(mEventReportIndicationGrp != NULL)
				{
						pBaseInterface.push_back(mEventReportIndicationGrp);
				}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1093:
			{
				if(mADCRuleRemoveGrpList != NULL)
				{
					for(auto itr = mADCRuleRemoveGrpList->begin(); itr != mADCRuleRemoveGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

					if(deepInspect)
					{
						for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 1092:
			{
				if(mADCRuleInstallGrpList != NULL)
				{
					for(auto itr = mADCRuleInstallGrpList->begin(); itr != mADCRuleInstallGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

					if(deepInspect)
					{
						for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 1042:
			{
				if(mRevalidationTime != NULL)
				{
					DiameterBaseInterface* inf =  mRevalidationTime->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1067:
			{
				if(mUsageMonitoringInformationGrpList != NULL)
				{
					for(auto itr = mUsageMonitoringInformationGrpList->begin(); itr != mUsageMonitoringInformationGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

					if(deepInspect)
					{
						for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 284:
			{
				if(mProxyInfoGrpList != NULL)
				{
					for(auto itr = mProxyInfoGrpList->begin(); itr != mProxyInfoGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

					if(deepInspect)
					{
						for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 282:
			{
				if(mRouteRecordList != NULL)
				{
					for(auto itr = mRouteRecordList->begin(); itr != mRouteRecordList->end(); ++itr)
					{
						DiameterBaseInterface* inf =  (*itr)->Find(this->mspByteArray.get(), avpCode);
						if(inf != NULL)
						{
							pBaseInterface.push_back(inf);
						}
					}

					if(deepInspect)
					{
						for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			default:
			{
				if(!deepInspect)
					break;
				for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
				{
					(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
				}
			}
		}
		if(pBaseInterface.size() > 0)
			return true;
		else
			return false;
}
std::shared_ptr<byteArray> ReAuthRequest::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN ReAuthRequest::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
		if(!mDecodeFlag && array != NULL)
			this->Decode(array);

	if(avpCodeMap.empty() || key > size)
	{
		return false;
	}
	auto it = avpCodeMap.find(key);
	if( it == avpCodeMap.end())
	{
		return false;
	}
	UINT32 avpCode = it->second;
		switch(avpCode)
		{
			case 263:
			{
				if(mSessionId != NULL)
				{
					DiameterBaseInterface* inf =  mSessionId->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 301:
			{
				if(mDRMP != NULL)
				{
					DiameterBaseInterface* inf =  mDRMP->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 258:
			{
				if(mAuthApplicationId != NULL)
				{
					DiameterBaseInterface* inf =  mAuthApplicationId->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 264:
			{
				if(mOriginHost != NULL)
				{
					DiameterBaseInterface* inf =  mOriginHost->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 296:
			{
				if(mOriginRealm != NULL)
				{
					DiameterBaseInterface* inf =  mOriginRealm->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 283:
			{
				if(mDestinationRealm != NULL)
				{
					DiameterBaseInterface* inf =  mDestinationRealm->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 293:
			{
				if(mDestinationHost != NULL)
				{
					DiameterBaseInterface* inf =  mDestinationHost->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 285:
			{
				if(mReAuthRequestType != NULL)
				{
					DiameterBaseInterface* inf =  mReAuthRequestType->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1045:
			{
				if(mSessionReleaseCause != NULL)
				{
					DiameterBaseInterface* inf =  mSessionReleaseCause->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 278:
			{
				if(mOriginStateId != NULL)
				{
					DiameterBaseInterface* inf =  mOriginStateId->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 621:
			{
				if(mOCSupportedFeaturesGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mOCSupportedFeaturesGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mOCSupportedFeaturesGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
				}
				}
				break;
			}
			case 1016:
			{
				if(mQoSInformationGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mQoSInformationGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mQoSInformationGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
				}
				}
				break;
			}
			case 1006:
			{
				if(mEventTriggerList != NULL)
				{
					for(auto itr = mEventTriggerList->begin(); itr != mEventTriggerList->end(); ++itr)
					{
						DiameterBaseInterface* inf =  (*itr)->Find(this->mspByteArray.get(), avpCode);
						if(inf != NULL)
						{
							pBaseInterface.push_back(inf);
						}
					}

				}
				break;
			}
			case 1071:
			{
				if(mCSGInformationReportingList != NULL)
				{
					for(auto itr = mCSGInformationReportingList->begin(); itr != mCSGInformationReportingList->end(); ++itr)
					{
						DiameterBaseInterface* inf =  (*itr)->Find(this->mspByteArray.get(), avpCode);
						if(inf != NULL)
						{
							pBaseInterface.push_back(inf);
						}
					}

				}
				break;
			}
			case 1033:
			{
				if(mEventReportIndicationGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mEventReportIndicationGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mEventReportIndicationGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
				}
				}
				break;
			}
			case 1093:
			{
				if(mADCRuleRemoveGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mADCRuleRemoveGrpList->begin(); itr != mADCRuleRemoveGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mADCRuleRemoveGrpList->begin(); itr != mADCRuleRemoveGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 1092:
			{
				if(mADCRuleInstallGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mADCRuleInstallGrpList->begin(); itr != mADCRuleInstallGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mADCRuleInstallGrpList->begin(); itr != mADCRuleInstallGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 1042:
			{
				if(mRevalidationTime != NULL)
				{
					DiameterBaseInterface* inf =  mRevalidationTime->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1067:
			{
				if(mUsageMonitoringInformationGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mUsageMonitoringInformationGrpList->begin(); itr != mUsageMonitoringInformationGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mUsageMonitoringInformationGrpList->begin(); itr != mUsageMonitoringInformationGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 284:
			{
				if(mProxyInfoGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mProxyInfoGrpList->begin(); itr != mProxyInfoGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mProxyInfoGrpList->begin(); itr != mProxyInfoGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 282:
			{
				if(mRouteRecordList != NULL)
				{
					for(auto itr = mRouteRecordList->begin(); itr != mRouteRecordList->end(); ++itr)
					{
						DiameterBaseInterface* inf =  (*itr)->Find(this->mspByteArray.get(), avpCode);
						if(inf != NULL)
						{
							pBaseInterface.push_back(inf);
						}
					}

				}
				break;
			}
			default:
			{
					break;
			}
		}
		if(pBaseInterface.size() > 0)
			return true;
		else
			return false;
}




void ReAuthRequest::Display(UINT32 tab)
{
	cout << setw(tab) << "" << "|" << setfill('=') << setw(59) << "|\n" << setfill(' '); 

	cout << setw(tab) << "" << "|"  << left <<  setw(12) << "Version" << ":" << setw(15) << (int)mDiameterMsgHeader->mVersion << "|" << setw(12)  << "MsgLen" << ":" << setw(15) << mDiameterMsgHeader->mMsgLen << "|" << "\n"; 
	TEXT lCmdFlg[100];
	sprintf( lCmdFlg, "%s %s %s %s", ((mDiameterMsgHeader->mCmdFlg.rBit==1)?"Request":"Response"), ((mDiameterMsgHeader->mCmdFlg.pBit==1)?"Proxiable":""), ((mDiameterMsgHeader->mCmdFlg.eBit==1)?"Error":""),((mDiameterMsgHeader->mCmdFlg.tBit ==1)?"Retransmitted":""));
	cout << setw(tab) << "" << "|"  << left <<  setw(12) << "CmdFlag" << ":" << setw(44) << lCmdFlg << "|\n"; 
	cout << setw(tab) << "" <<"|"  << left <<  setw(12) << "CmdCode" << ":" << setw(15) << mDiameterMsgHeader->mCmdCode << "|" << setw(12)  << "ApplnId" << ":" << setw(15) << mDiameterMsgHeader->mApplId << "|\n";
	cout << setw(tab) << "" << "|"  << left <<  setw(12) << "HopByHopId" << ":" << setw(15) << mDiameterMsgHeader->mHopByHopId << "|" << setw(12)  << "EndToEndId" << ":" << setw(15) << mDiameterMsgHeader->mEndToEndId << "|\n";
	cout << setw(tab) << "" << "|" << right << setfill('=') << setw(59) << "|\n" << setfill(' '); 

	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case ReAuthRequest_SESSIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "263" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SessionId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getSessionId()->Display(tab+1);
			}
				break;
			case ReAuthRequest_DRMP:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "301" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DRMP" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getDRMP()->Display(tab+1);
			}
				break;
			case ReAuthRequest_AUTHAPPLICATIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "258" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AuthApplicationId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getAuthApplicationId()->Display(tab+1);
			}
				break;
			case ReAuthRequest_ORIGINHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "264" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginHost()->Display(tab+1);
			}
				break;
			case ReAuthRequest_ORIGINREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "296" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginRealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginRealm()->Display(tab+1);
			}
				break;
			case ReAuthRequest_DESTINATIONREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "283" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DestinationRealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getDestinationRealm()->Display(tab+1);
			}
				break;
			case ReAuthRequest_DESTINATIONHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "293" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DestinationHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getDestinationHost()->Display(tab+1);
			}
				break;
			case ReAuthRequest_REAUTHREQUESTTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "285" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ReAuthRequestType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getReAuthRequestType()->Display(tab+1);
			}
				break;
			case ReAuthRequest_SESSIONRELEASECAUSE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1045" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SessionReleaseCause" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getSessionReleaseCause()->Display(tab+1);
			}
				break;
			case ReAuthRequest_ORIGINSTATEID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "278" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginStateId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginStateId()->Display(tab+1);
			}
				break;
			case ReAuthRequest_OCSUPPORTEDFEATURES:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "621" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OCSupportedFeatures" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getOCSupportedFeatures()->Display(tab+1);
			}
				break;
			case ReAuthRequest_QOSINFORMATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1016" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "QoSInformation" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getQoSInformation()->Display(tab+1);
			}
				break;
			case ReAuthRequest_EVENTTRIGGER:
			{
				if( mEventTriggerList->size() <= 0) {
					break;
				}

				mEventTriggerIterator = this->getEventTriggerList()->begin();
				while(mEventTriggerIterator != this->getEventTriggerList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1006" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "EventTrigger" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mEventTriggerIterator)->Display(tab+1);
					mEventTriggerIterator++;

				};

			}
				break;
			case ReAuthRequest_CSGINFORMATIONREPORTING:
			{
				if( mCSGInformationReportingList->size() <= 0) {
					break;
				}

				mCSGInformationReportingIterator = this->getCSGInformationReportingList()->begin();
				while(mCSGInformationReportingIterator != this->getCSGInformationReportingList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1071" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CSGInformationReporting" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mCSGInformationReportingIterator)->Display(tab+1);
					mCSGInformationReportingIterator++;

				};

			}
				break;
			case ReAuthRequest_EVENTREPORTINDICATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1033" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "EventReportIndication" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getEventReportIndication()->Display(tab+1);
			}
				break;
			case ReAuthRequest_ADCRULEREMOVE:
			{
				if( mADCRuleRemoveGrpList->size() <= 0) {
					break;
				}

				mADCRuleRemoveGrpIterator = this->getADCRuleRemoveGrpList()->begin();
				while(mADCRuleRemoveGrpIterator != this->getADCRuleRemoveGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1093" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ADCRuleRemove" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mADCRuleRemoveGrpIterator)->Display(tab+1);
					mADCRuleRemoveGrpIterator++;

				};

			}
				break;
			case ReAuthRequest_ADCRULEINSTALL:
			{
				if( mADCRuleInstallGrpList->size() <= 0) {
					break;
				}

				mADCRuleInstallGrpIterator = this->getADCRuleInstallGrpList()->begin();
				while(mADCRuleInstallGrpIterator != this->getADCRuleInstallGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1092" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ADCRuleInstall" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mADCRuleInstallGrpIterator)->Display(tab+1);
					mADCRuleInstallGrpIterator++;

				};

			}
				break;
			case ReAuthRequest_REVALIDATIONTIME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1042" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RevalidationTime" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getRevalidationTime()->Display(tab+1);
			}
				break;
			case ReAuthRequest_USAGEMONITORINGINFORMATION:
			{
				if( mUsageMonitoringInformationGrpList->size() <= 0) {
					break;
				}

				mUsageMonitoringInformationGrpIterator = this->getUsageMonitoringInformationGrpList()->begin();
				while(mUsageMonitoringInformationGrpIterator != this->getUsageMonitoringInformationGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1067" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UsageMonitoringInformation" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mUsageMonitoringInformationGrpIterator)->Display(tab+1);
					mUsageMonitoringInformationGrpIterator++;

				};

			}
				break;
			case ReAuthRequest_PROXYINFO:
			{
				if( mProxyInfoGrpList->size() <= 0) {
					break;
				}

				mProxyInfoGrpIterator = this->getProxyInfoGrpList()->begin();
				while(mProxyInfoGrpIterator != this->getProxyInfoGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "284" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ProxyInfo" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
					(*mProxyInfoGrpIterator)->Display(tab+1);
					mProxyInfoGrpIterator++;

				};

			}
				break;
			case ReAuthRequest_ROUTERECORD:
			{
				if( mRouteRecordList->size() <= 0) {
					break;
				}

				mRouteRecordIterator = this->getRouteRecordList()->begin();
				while(mRouteRecordIterator != this->getRouteRecordList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "282" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RouteRecord" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
					(*mRouteRecordIterator)->Display(tab+1);
					mRouteRecordIterator++;

				};

			}
				break;
			default:
				//printf("Unknown Tag received Tag:%d Offset:%d\n", mTagArray[lTemp], array->offset);
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE);
					throw lTssDiaMsgException;
				break;
		}
	}

}


BOOLEAN ReAuthRequest::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<21> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case ReAuthRequest_SESSIONID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 263");
				}
				else
					sprintf(lMissingAvpInfo, "%s,263", lMissingAvpInfo);
			}
				break;
			case ReAuthRequest_DRMP:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 301");
				}
				else
					sprintf(lMissingAvpInfo, "%s,301", lMissingAvpInfo);
			}
				break;
			case ReAuthRequest_AUTHAPPLICATIONID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 258");
				}
				else
					sprintf(lMissingAvpInfo, "%s,258", lMissingAvpInfo);
			}
				break;
			case ReAuthRequest_ORIGINHOST:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 264");
				}
				else
					sprintf(lMissingAvpInfo, "%s,264", lMissingAvpInfo);
			}
				break;
			case ReAuthRequest_ORIGINREALM:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 296");
				}
				else
					sprintf(lMissingAvpInfo, "%s,296", lMissingAvpInfo);
			}
				break;
			case ReAuthRequest_DESTINATIONREALM:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 283");
				}
				else
					sprintf(lMissingAvpInfo, "%s,283", lMissingAvpInfo);
			}
				break;
			case ReAuthRequest_DESTINATIONHOST:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 293");
				}
				else
					sprintf(lMissingAvpInfo, "%s,293", lMissingAvpInfo);
			}
				break;
			case ReAuthRequest_REAUTHREQUESTTYPE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 285");
				}
				else
					sprintf(lMissingAvpInfo, "%s,285", lMissingAvpInfo);
			}
				break;
			case ReAuthRequest_SESSIONRELEASECAUSE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1045");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1045", lMissingAvpInfo);
			}
				break;
			case ReAuthRequest_ORIGINSTATEID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 278");
				}
				else
					sprintf(lMissingAvpInfo, "%s,278", lMissingAvpInfo);
			}
				break;
			case ReAuthRequest_OCSUPPORTEDFEATURES:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 621");
				}
				else
					sprintf(lMissingAvpInfo, "%s,621", lMissingAvpInfo);
			}
				break;
			case ReAuthRequest_QOSINFORMATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1016");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1016", lMissingAvpInfo);
			}
				break;
			case ReAuthRequest_EVENTTRIGGER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1006");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1006", lMissingAvpInfo);
			}
				break;
			case ReAuthRequest_CSGINFORMATIONREPORTING:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1071");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1071", lMissingAvpInfo);
			}
				break;
			case ReAuthRequest_EVENTREPORTINDICATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1033");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1033", lMissingAvpInfo);
			}
				break;
			case ReAuthRequest_ADCRULEREMOVE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1093");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1093", lMissingAvpInfo);
			}
				break;
			case ReAuthRequest_ADCRULEINSTALL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1092");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1092", lMissingAvpInfo);
			}
				break;
			case ReAuthRequest_REVALIDATIONTIME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1042");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1042", lMissingAvpInfo);
			}
				break;
			case ReAuthRequest_USAGEMONITORINGINFORMATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1067");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1067", lMissingAvpInfo);
			}
				break;
			case ReAuthRequest_PROXYINFO:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 284");
				}
				else
					sprintf(lMissingAvpInfo, "%s,284", lMissingAvpInfo);
			}
				break;
			case ReAuthRequest_ROUTERECORD:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 282");
				}
				else
					sprintf(lMissingAvpInfo, "%s,282", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
