#include "sh/include/SubscribeNotificationsRequest.h"

using namespace SH;
BOOLEAN SubscribeNotificationsRequest::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

SubscribeNotificationsRequest::SubscribeNotificationsRequest()
{
	mSessionId = NULL;
	mDRMP = NULL;
	mVendorSpecificApplicationIdGrp = NULL;
	mAuthSessionState = NULL;
	mOriginHost = NULL;
	mOriginRealm = NULL;
	mDestinationHost = NULL;
	mDestinationRealm = NULL;
	mSupportedFeaturesGrpList = NULL;
	mUserIdentityGrp = NULL;
	mWildcardedPublicIdentity = NULL;
	mWildcardedIMPU = NULL;
	mServiceIndicationList = NULL;
	mSendDataIndication = NULL;
	mServerName = NULL;
	mSubsReqType = NULL;
	mDataReferenceList = NULL;
	mIdentitySetList = NULL;
	mExpiryTime = NULL;
	mDSAITagList = NULL;
	mOneTimeNotification = NULL;
	mUserName = NULL;
	mOCSupportedFeaturesGrp = NULL;
	mProxyInfoGrpList = NULL;
	mRouteRecordList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<25>(string("1101010011101001011111101"));
	mMandatoryAvpSetVal.reset();
}

SubscribeNotificationsRequest::~SubscribeNotificationsRequest()
{
	if(mSessionId != NULL)
		delete mSessionId;
	if(mDRMP != NULL)
		delete mDRMP;
	if(mVendorSpecificApplicationIdGrp != NULL)
		delete mVendorSpecificApplicationIdGrp;
	if(mAuthSessionState != NULL)
		delete mAuthSessionState;
	if(mOriginHost != NULL)
		delete mOriginHost;
	if(mOriginRealm != NULL)
		delete mOriginRealm;
	if(mDestinationHost != NULL)
		delete mDestinationHost;
	if(mDestinationRealm != NULL)
		delete mDestinationRealm;
	if(mSupportedFeaturesGrpList != NULL){
		mSupportedFeaturesGrpIterator = mSupportedFeaturesGrpList->begin();
		while(mSupportedFeaturesGrpIterator != mSupportedFeaturesGrpList->end()){
	if(*mSupportedFeaturesGrpIterator != NULL)
			delete (*mSupportedFeaturesGrpIterator);
			mSupportedFeaturesGrpIterator++;
		}
		delete mSupportedFeaturesGrpList;
	}
	if(mUserIdentityGrp != NULL)
		delete mUserIdentityGrp;
	if(mWildcardedPublicIdentity != NULL)
		delete mWildcardedPublicIdentity;
	if(mWildcardedIMPU != NULL)
		delete mWildcardedIMPU;
	if(mServiceIndicationList != NULL){
		mServiceIndicationIterator = mServiceIndicationList->begin();
		while(mServiceIndicationIterator != mServiceIndicationList->end()){
			delete (*mServiceIndicationIterator);
			mServiceIndicationIterator++;
		}
		delete mServiceIndicationList;
	}
	if(mSendDataIndication != NULL)
		delete mSendDataIndication;
	if(mServerName != NULL)
		delete mServerName;
	if(mSubsReqType != NULL)
		delete mSubsReqType;
	if(mDataReferenceList != NULL){
		mDataReferenceIterator = mDataReferenceList->begin();
		while(mDataReferenceIterator != mDataReferenceList->end()){
			delete (*mDataReferenceIterator);
			mDataReferenceIterator++;
		}
		delete mDataReferenceList;
	}
	if(mIdentitySetList != NULL){
		mIdentitySetIterator = mIdentitySetList->begin();
		while(mIdentitySetIterator != mIdentitySetList->end()){
			delete (*mIdentitySetIterator);
			mIdentitySetIterator++;
		}
		delete mIdentitySetList;
	}
	if(mExpiryTime != NULL)
		delete mExpiryTime;
	if(mDSAITagList != NULL){
		mDSAITagIterator = mDSAITagList->begin();
		while(mDSAITagIterator != mDSAITagList->end()){
			delete (*mDSAITagIterator);
			mDSAITagIterator++;
		}
		delete mDSAITagList;
	}
	if(mOneTimeNotification != NULL)
		delete mOneTimeNotification;
	if(mUserName != NULL)
		delete mUserName;
	if(mOCSupportedFeaturesGrp != NULL)
		delete mOCSupportedFeaturesGrp;
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

OctetString* SubscribeNotificationsRequest::setSessionId(){
	mMandatoryAvpSetVal [SubscribeNotificationsRequest_SESSIONID] = 1;
	if(mSessionId == NULL)
	{
		mSessionId = new OctetString();
		mTagsPresent[SubscribeNotificationsRequest_SESSIONID] = 1;
		return mSessionId;
	}
	return mSessionId;
}

void SubscribeNotificationsRequest::resetSessionId(){
	mTagsPresent[SubscribeNotificationsRequest_SESSIONID] = 0;
	if(mSessionId != NULL)
	{
		delete mSessionId; 
		mSessionId = NULL;
	}
}

DRMP* SubscribeNotificationsRequest::setDRMP(){
	if(mDRMP == NULL)
	{
		mDRMP = new DRMP();
		mTagsPresent[SubscribeNotificationsRequest_DRMP] = 1;
		return mDRMP;
	}
	return mDRMP;
}

void SubscribeNotificationsRequest::resetDRMP(){
	mTagsPresent[SubscribeNotificationsRequest_DRMP] = 0;
	if(mDRMP != NULL)
	{
		delete mDRMP; 
		mDRMP = NULL;
	}
}

AuthSessionState* SubscribeNotificationsRequest::setAuthSessionState(){
	mMandatoryAvpSetVal [SubscribeNotificationsRequest_AUTHSESSIONSTATE] = 1;
	if(mAuthSessionState == NULL)
	{
		mAuthSessionState = new AuthSessionState();
		mTagsPresent[SubscribeNotificationsRequest_AUTHSESSIONSTATE] = 1;
		return mAuthSessionState;
	}
	return mAuthSessionState;
}

void SubscribeNotificationsRequest::resetAuthSessionState(){
	mTagsPresent[SubscribeNotificationsRequest_AUTHSESSIONSTATE] = 0;
	if(mAuthSessionState != NULL)
	{
		delete mAuthSessionState; 
		mAuthSessionState = NULL;
	}
}

OctetString* SubscribeNotificationsRequest::setOriginHost(){
	mMandatoryAvpSetVal [SubscribeNotificationsRequest_ORIGINHOST] = 1;
	if(mOriginHost == NULL)
	{
		mOriginHost = new OctetString();
		mTagsPresent[SubscribeNotificationsRequest_ORIGINHOST] = 1;
		return mOriginHost;
	}
	return mOriginHost;
}

void SubscribeNotificationsRequest::resetOriginHost(){
	mTagsPresent[SubscribeNotificationsRequest_ORIGINHOST] = 0;
	if(mOriginHost != NULL)
	{
		delete mOriginHost; 
		mOriginHost = NULL;
	}
}

OctetString* SubscribeNotificationsRequest::setOriginRealm(){
	mMandatoryAvpSetVal [SubscribeNotificationsRequest_ORIGINREALM] = 1;
	if(mOriginRealm == NULL)
	{
		mOriginRealm = new OctetString();
		mTagsPresent[SubscribeNotificationsRequest_ORIGINREALM] = 1;
		return mOriginRealm;
	}
	return mOriginRealm;
}

void SubscribeNotificationsRequest::resetOriginRealm(){
	mTagsPresent[SubscribeNotificationsRequest_ORIGINREALM] = 0;
	if(mOriginRealm != NULL)
	{
		delete mOriginRealm; 
		mOriginRealm = NULL;
	}
}

OctetString* SubscribeNotificationsRequest::setDestinationHost(){
	mMandatoryAvpSetVal [SubscribeNotificationsRequest_DESTINATIONHOST] = 1;
	if(mDestinationHost == NULL)
	{
		mDestinationHost = new OctetString();
		mTagsPresent[SubscribeNotificationsRequest_DESTINATIONHOST] = 1;
		return mDestinationHost;
	}
	return mDestinationHost;
}

void SubscribeNotificationsRequest::resetDestinationHost(){
	mTagsPresent[SubscribeNotificationsRequest_DESTINATIONHOST] = 0;
	if(mDestinationHost != NULL)
	{
		delete mDestinationHost; 
		mDestinationHost = NULL;
	}
}

OctetString* SubscribeNotificationsRequest::setDestinationRealm(){
	mMandatoryAvpSetVal [SubscribeNotificationsRequest_DESTINATIONREALM] = 1;
	if(mDestinationRealm == NULL)
	{
		mDestinationRealm = new OctetString();
		mTagsPresent[SubscribeNotificationsRequest_DESTINATIONREALM] = 1;
		return mDestinationRealm;
	}
	return mDestinationRealm;
}

void SubscribeNotificationsRequest::resetDestinationRealm(){
	mTagsPresent[SubscribeNotificationsRequest_DESTINATIONREALM] = 0;
	if(mDestinationRealm != NULL)
	{
		delete mDestinationRealm; 
		mDestinationRealm = NULL;
	}
}

OctetString* SubscribeNotificationsRequest::setWildcardedPublicIdentity(){
	if(mWildcardedPublicIdentity == NULL)
	{
		mWildcardedPublicIdentity = new OctetString();
		mTagsPresent[SubscribeNotificationsRequest_WILDCARDEDPUBLICIDENTITY] = 1;
		return mWildcardedPublicIdentity;
	}
	return mWildcardedPublicIdentity;
}

void SubscribeNotificationsRequest::resetWildcardedPublicIdentity(){
	mTagsPresent[SubscribeNotificationsRequest_WILDCARDEDPUBLICIDENTITY] = 0;
	if(mWildcardedPublicIdentity != NULL)
	{
		delete mWildcardedPublicIdentity; 
		mWildcardedPublicIdentity = NULL;
	}
}

OctetString* SubscribeNotificationsRequest::setWildcardedIMPU(){
	if(mWildcardedIMPU == NULL)
	{
		mWildcardedIMPU = new OctetString();
		mTagsPresent[SubscribeNotificationsRequest_WILDCARDEDIMPU] = 1;
		return mWildcardedIMPU;
	}
	return mWildcardedIMPU;
}

void SubscribeNotificationsRequest::resetWildcardedIMPU(){
	mTagsPresent[SubscribeNotificationsRequest_WILDCARDEDIMPU] = 0;
	if(mWildcardedIMPU != NULL)
	{
		delete mWildcardedIMPU; 
		mWildcardedIMPU = NULL;
	}
}

SendDataIndication* SubscribeNotificationsRequest::setSendDataIndication(){
	if(mSendDataIndication == NULL)
	{
		mSendDataIndication = new SendDataIndication();
		mTagsPresent[SubscribeNotificationsRequest_SENDDATAINDICATION] = 1;
		return mSendDataIndication;
	}
	return mSendDataIndication;
}

void SubscribeNotificationsRequest::resetSendDataIndication(){
	mTagsPresent[SubscribeNotificationsRequest_SENDDATAINDICATION] = 0;
	if(mSendDataIndication != NULL)
	{
		delete mSendDataIndication; 
		mSendDataIndication = NULL;
	}
}

OctetString* SubscribeNotificationsRequest::setServerName(){
	mMandatoryAvpSetVal [SubscribeNotificationsRequest_SERVERNAME] = 1;
	if(mServerName == NULL)
	{
		mServerName = new OctetString();
		mTagsPresent[SubscribeNotificationsRequest_SERVERNAME] = 1;
		return mServerName;
	}
	return mServerName;
}

void SubscribeNotificationsRequest::resetServerName(){
	mTagsPresent[SubscribeNotificationsRequest_SERVERNAME] = 0;
	if(mServerName != NULL)
	{
		delete mServerName; 
		mServerName = NULL;
	}
}

SubsReqType* SubscribeNotificationsRequest::setSubsReqType(){
	mMandatoryAvpSetVal [SubscribeNotificationsRequest_SUBSREQTYPE] = 1;
	if(mSubsReqType == NULL)
	{
		mSubsReqType = new SubsReqType();
		mTagsPresent[SubscribeNotificationsRequest_SUBSREQTYPE] = 1;
		return mSubsReqType;
	}
	return mSubsReqType;
}

void SubscribeNotificationsRequest::resetSubsReqType(){
	mTagsPresent[SubscribeNotificationsRequest_SUBSREQTYPE] = 0;
	if(mSubsReqType != NULL)
	{
		delete mSubsReqType; 
		mSubsReqType = NULL;
	}
}

Time* SubscribeNotificationsRequest::setExpiryTime(){
	if(mExpiryTime == NULL)
	{
		mExpiryTime = new Time();
		mTagsPresent[SubscribeNotificationsRequest_EXPIRYTIME] = 1;
		return mExpiryTime;
	}
	return mExpiryTime;
}

void SubscribeNotificationsRequest::resetExpiryTime(){
	mTagsPresent[SubscribeNotificationsRequest_EXPIRYTIME] = 0;
	if(mExpiryTime != NULL)
	{
		delete mExpiryTime; 
		mExpiryTime = NULL;
	}
}

OneTimeNotification* SubscribeNotificationsRequest::setOneTimeNotification(){
	if(mOneTimeNotification == NULL)
	{
		mOneTimeNotification = new OneTimeNotification();
		mTagsPresent[SubscribeNotificationsRequest_ONETIMENOTIFICATION] = 1;
		return mOneTimeNotification;
	}
	return mOneTimeNotification;
}

void SubscribeNotificationsRequest::resetOneTimeNotification(){
	mTagsPresent[SubscribeNotificationsRequest_ONETIMENOTIFICATION] = 0;
	if(mOneTimeNotification != NULL)
	{
		delete mOneTimeNotification; 
		mOneTimeNotification = NULL;
	}
}

OctetString* SubscribeNotificationsRequest::setUserName(){
	mMandatoryAvpSetVal [SubscribeNotificationsRequest_USERNAME] = 1;
	if(mUserName == NULL)
	{
		mUserName = new OctetString();
		mTagsPresent[SubscribeNotificationsRequest_USERNAME] = 1;
		return mUserName;
	}
	return mUserName;
}

void SubscribeNotificationsRequest::resetUserName(){
	mTagsPresent[SubscribeNotificationsRequest_USERNAME] = 0;
	if(mUserName != NULL)
	{
		delete mUserName; 
		mUserName = NULL;
	}
}

OctetString* SubscribeNotificationsRequest::getSessionId(){
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

DRMP* SubscribeNotificationsRequest::getDRMP(){
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

SH::VendorSpecificApplicationId* SubscribeNotificationsRequest::getVendorSpecificApplicationId()
{
	if(mVendorSpecificApplicationIdGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "VendorSpecificApplicationId is Null");
		throw lTssDiaMsgException;
	}
	if(!mVendorSpecificApplicationIdGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mVendorSpecificApplicationIdGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "VendorSpecificApplicationId is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mVendorSpecificApplicationIdGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mVendorSpecificApplicationIdGrp->Decode(mspByteArray.get(), mVendorSpecificApplicationIdGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding VendorSpecificApplicationId")     ;
			throw lTssDiaMsgException;
		}
		mVendorSpecificApplicationIdGrp->mAvpDecodedFlag = true;
	}
	return mVendorSpecificApplicationIdGrp;
}

SH::VendorSpecificApplicationId* SubscribeNotificationsRequest::setVendorSpecificApplicationId(){
	if(mVendorSpecificApplicationIdGrp == NULL)
		mVendorSpecificApplicationIdGrp = new VendorSpecificApplicationId();
	mTagsPresent[SubscribeNotificationsRequest_VENDORSPECIFICAPPLICATIONID] = 1;
	mMandatoryAvpSetVal[SubscribeNotificationsRequest_VENDORSPECIFICAPPLICATIONID] = 1;
	return mVendorSpecificApplicationIdGrp;
}

void SubscribeNotificationsRequest::resetVendorSpecificApplicationId(){
	mTagsPresent[SubscribeNotificationsRequest_VENDORSPECIFICAPPLICATIONID] = 0;
	if(mVendorSpecificApplicationIdGrp != NULL)
		delete mVendorSpecificApplicationIdGrp;
}

AuthSessionState* SubscribeNotificationsRequest::getAuthSessionState(){
	if(NULL == mAuthSessionState) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AuthSessionState is Null");
		throw lTssDiaMsgException;
	}
	if(!mAuthSessionState->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAuthSessionState->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AuthSessionState is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAuthSessionState->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAuthSessionState->Decode(mspByteArray.get(), mAuthSessionState->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AuthSessionState")     ;
			throw lTssDiaMsgException;
		}
		mAuthSessionState->mAvpDecodedFlag = true;
	}
	return mAuthSessionState;
}

OctetString* SubscribeNotificationsRequest::getOriginHost(){
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

OctetString* SubscribeNotificationsRequest::getOriginRealm(){
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

OctetString* SubscribeNotificationsRequest::getDestinationHost(){
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

OctetString* SubscribeNotificationsRequest::getDestinationRealm(){
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

list<SupportedFeatures*>* SubscribeNotificationsRequest::getSupportedFeaturesGrpList()
{
	if(mSupportedFeaturesGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SupportedFeatures is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mSupportedFeaturesGrpList)
	{
		if(mSupportedFeaturesGrpList != NULL)
		{
		if(mSupportedFeaturesGrpList->size() == 0)
		{
			mTagsPresent[SubscribeNotificationsRequest_SUPPORTEDFEATURES] = 0;
			mSupportedFeaturesGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SupportedFeatures is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SupportedFeatures is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SupportedFeatures")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mSupportedFeaturesGrpList;
}

list<SupportedFeatures*>* SubscribeNotificationsRequest::setSupportedFeaturesGrpList(){
	mTagsPresent[SubscribeNotificationsRequest_SUPPORTEDFEATURES] = 1;
	if(mSupportedFeaturesGrpList == NULL)
		mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
	mSupportedFeaturesGrpList->clear();
	return mSupportedFeaturesGrpList;
}

void SubscribeNotificationsRequest::resetSupportedFeaturesGrpList(){
	mTagsPresent[SubscribeNotificationsRequest_SUPPORTEDFEATURES] = 0;
	if(mSupportedFeaturesGrpList != NULL)
		delete mSupportedFeaturesGrpList;
}

UserIdentity* SubscribeNotificationsRequest::getUserIdentity()
{
	if(mUserIdentityGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserIdentity is Null");
		throw lTssDiaMsgException;
	}
	if(!mUserIdentityGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUserIdentityGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserIdentity is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUserIdentityGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUserIdentityGrp->Decode(mspByteArray.get(), mUserIdentityGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserIdentity")     ;
			throw lTssDiaMsgException;
		}
		mUserIdentityGrp->mAvpDecodedFlag = true;
	}
	return mUserIdentityGrp;
}

UserIdentity* SubscribeNotificationsRequest::setUserIdentity(){
	if(mUserIdentityGrp == NULL)
		mUserIdentityGrp = new UserIdentity();
	mTagsPresent[SubscribeNotificationsRequest_USERIDENTITY] = 1;
	mMandatoryAvpSetVal[SubscribeNotificationsRequest_USERIDENTITY] = 1;
	return mUserIdentityGrp;
}

void SubscribeNotificationsRequest::resetUserIdentity(){
	mTagsPresent[SubscribeNotificationsRequest_USERIDENTITY] = 0;
	if(mUserIdentityGrp != NULL)
		delete mUserIdentityGrp;
}

OctetString* SubscribeNotificationsRequest::getWildcardedPublicIdentity(){
	if(NULL == mWildcardedPublicIdentity) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "WildcardedPublicIdentity is Null");
		throw lTssDiaMsgException;
	}
	if(!mWildcardedPublicIdentity->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mWildcardedPublicIdentity->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "WildcardedPublicIdentity is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mWildcardedPublicIdentity->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mWildcardedPublicIdentity->Decode(mspByteArray.get(), mWildcardedPublicIdentity->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding WildcardedPublicIdentity")     ;
			throw lTssDiaMsgException;
		}
		mWildcardedPublicIdentity->mAvpDecodedFlag = true;
	}
	return mWildcardedPublicIdentity;
}

OctetString* SubscribeNotificationsRequest::getWildcardedIMPU(){
	if(NULL == mWildcardedIMPU) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "WildcardedIMPU is Null");
		throw lTssDiaMsgException;
	}
	if(!mWildcardedIMPU->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mWildcardedIMPU->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "WildcardedIMPU is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mWildcardedIMPU->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mWildcardedIMPU->Decode(mspByteArray.get(), mWildcardedIMPU->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding WildcardedIMPU")     ;
			throw lTssDiaMsgException;
		}
		mWildcardedIMPU->mAvpDecodedFlag = true;
	}
	return mWildcardedIMPU;
}

list<OctetString*>* SubscribeNotificationsRequest::getServiceIndicationList()
{
	if(mServiceIndicationList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ServiceIndication is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mServiceIndicationList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ServiceIndication is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ServiceIndication")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mServiceIndicationList;
}

list<OctetString*>* SubscribeNotificationsRequest::setServiceIndicationList() {
	mTagsPresent[SubscribeNotificationsRequest_SERVICEINDICATION] = 1;
	if(mServiceIndicationList == NULL)
		mServiceIndicationList = new list<OctetString*>;
	mMandatoryAvpSetVal [SubscribeNotificationsRequest_SERVICEINDICATION] = 1;
	mServiceIndicationList->clear();
	return mServiceIndicationList;
}

void SubscribeNotificationsRequest::resetServiceIndicationList(){
	mTagsPresent[SubscribeNotificationsRequest_SERVICEINDICATION] = 0;
	if(mServiceIndicationList != NULL)
		delete mServiceIndicationList;
}

SendDataIndication* SubscribeNotificationsRequest::getSendDataIndication(){
	if(NULL == mSendDataIndication) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SendDataIndication is Null");
		throw lTssDiaMsgException;
	}
	if(!mSendDataIndication->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSendDataIndication->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SendDataIndication is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSendDataIndication->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSendDataIndication->Decode(mspByteArray.get(), mSendDataIndication->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SendDataIndication")     ;
			throw lTssDiaMsgException;
		}
		mSendDataIndication->mAvpDecodedFlag = true;
	}
	return mSendDataIndication;
}

OctetString* SubscribeNotificationsRequest::getServerName(){
	if(NULL == mServerName) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ServerName is Null");
		throw lTssDiaMsgException;
	}
	if(!mServerName->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mServerName->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ServerName is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mServerName->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mServerName->Decode(mspByteArray.get(), mServerName->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ServerName")     ;
			throw lTssDiaMsgException;
		}
		mServerName->mAvpDecodedFlag = true;
	}
	return mServerName;
}

SubsReqType* SubscribeNotificationsRequest::getSubsReqType(){
	if(NULL == mSubsReqType) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SubsReqType is Null");
		throw lTssDiaMsgException;
	}
	if(!mSubsReqType->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSubsReqType->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SubsReqType is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSubsReqType->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSubsReqType->Decode(mspByteArray.get(), mSubsReqType->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SubsReqType")     ;
			throw lTssDiaMsgException;
		}
		mSubsReqType->mAvpDecodedFlag = true;
	}
	return mSubsReqType;
}

list<DataReference*>* SubscribeNotificationsRequest::getDataReferenceList()
{
	if(mDataReferenceList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DataReference is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr :* mDataReferenceList)
	{
		if(!itr->mAvpDecodedFlag)
		{
	if(mspByteArray.get() == NULL)
		{
	itr->mAvpDecodedFlag = true;
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DataReference is Null");
		throw lTssDiaMsgException;
	}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DataReference")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mDataReferenceList;
}

list<DataReference*>* SubscribeNotificationsRequest::setDataReferenceList() {
	mTagsPresent[SubscribeNotificationsRequest_DATAREFERENCE] = 1;
	if(mDataReferenceList == NULL)
		mDataReferenceList = new list<DataReference*>;
	mMandatoryAvpSetVal [SubscribeNotificationsRequest_DATAREFERENCE] = 1;
	mDataReferenceList->clear();
	return mDataReferenceList;
}

void SubscribeNotificationsRequest::resetDataReferenceList(){
	mTagsPresent[SubscribeNotificationsRequest_DATAREFERENCE] = 0;
	if(mDataReferenceList != NULL)
		delete mDataReferenceList;
}

list<IdentitySet*>* SubscribeNotificationsRequest::getIdentitySetList()
{
	if(mIdentitySetList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "IdentitySet is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr :* mIdentitySetList)
	{
		if(!itr->mAvpDecodedFlag)
		{
	if(mspByteArray.get() == NULL)
		{
	itr->mAvpDecodedFlag = true;
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "IdentitySet is Null");
		throw lTssDiaMsgException;
	}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding IdentitySet")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mIdentitySetList;
}

list<IdentitySet*>* SubscribeNotificationsRequest::setIdentitySetList() {
	mTagsPresent[SubscribeNotificationsRequest_IDENTITYSET] = 1;
	if(mIdentitySetList == NULL)
		mIdentitySetList = new list<IdentitySet*>;
	mIdentitySetList->clear();
	return mIdentitySetList;
}

void SubscribeNotificationsRequest::resetIdentitySetList(){
	mTagsPresent[SubscribeNotificationsRequest_IDENTITYSET] = 0;
	if(mIdentitySetList != NULL)
		delete mIdentitySetList;
}

Time* SubscribeNotificationsRequest::getExpiryTime(){
	if(NULL == mExpiryTime) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExpiryTime is Null");
		throw lTssDiaMsgException;
	}
	if(!mExpiryTime->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mExpiryTime->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExpiryTime is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mExpiryTime->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mExpiryTime->Decode(mspByteArray.get(), mExpiryTime->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExpiryTime")     ;
			throw lTssDiaMsgException;
		}
		mExpiryTime->mAvpDecodedFlag = true;
	}
	return mExpiryTime;
}

list<OctetString*>* SubscribeNotificationsRequest::getDSAITagList()
{
	if(mDSAITagList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DSAITag is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mDSAITagList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DSAITag is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DSAITag")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mDSAITagList;
}

list<OctetString*>* SubscribeNotificationsRequest::setDSAITagList() {
	mTagsPresent[SubscribeNotificationsRequest_DSAITAG] = 1;
	if(mDSAITagList == NULL)
		mDSAITagList = new list<OctetString*>;
	mMandatoryAvpSetVal [SubscribeNotificationsRequest_DSAITAG] = 1;
	mDSAITagList->clear();
	return mDSAITagList;
}

void SubscribeNotificationsRequest::resetDSAITagList(){
	mTagsPresent[SubscribeNotificationsRequest_DSAITAG] = 0;
	if(mDSAITagList != NULL)
		delete mDSAITagList;
}

OneTimeNotification* SubscribeNotificationsRequest::getOneTimeNotification(){
	if(NULL == mOneTimeNotification) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OneTimeNotification is Null");
		throw lTssDiaMsgException;
	}
	if(!mOneTimeNotification->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mOneTimeNotification->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OneTimeNotification is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mOneTimeNotification->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mOneTimeNotification->Decode(mspByteArray.get(), mOneTimeNotification->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OneTimeNotification")     ;
			throw lTssDiaMsgException;
		}
		mOneTimeNotification->mAvpDecodedFlag = true;
	}
	return mOneTimeNotification;
}

OctetString* SubscribeNotificationsRequest::getUserName(){
	if(NULL == mUserName) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserName is Null");
		throw lTssDiaMsgException;
	}
	if(!mUserName->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUserName->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserName is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUserName->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUserName->Decode(mspByteArray.get(), mUserName->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserName")     ;
			throw lTssDiaMsgException;
		}
		mUserName->mAvpDecodedFlag = true;
	}
	return mUserName;
}

OCSupportedFeatures* SubscribeNotificationsRequest::getOCSupportedFeatures()
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

OCSupportedFeatures* SubscribeNotificationsRequest::setOCSupportedFeatures(){
	if(mOCSupportedFeaturesGrp == NULL)
		mOCSupportedFeaturesGrp = new OCSupportedFeatures();
	mTagsPresent[SubscribeNotificationsRequest_OCSUPPORTEDFEATURES] = 1;
	return mOCSupportedFeaturesGrp;
}

void SubscribeNotificationsRequest::resetOCSupportedFeatures(){
	mTagsPresent[SubscribeNotificationsRequest_OCSUPPORTEDFEATURES] = 0;
	if(mOCSupportedFeaturesGrp != NULL)
		delete mOCSupportedFeaturesGrp;
}

list<SH::ProxyInfo*>* SubscribeNotificationsRequest::getProxyInfoGrpList()
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
			mTagsPresent[SubscribeNotificationsRequest_PROXYINFO] = 0;
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

list<SH::ProxyInfo*>* SubscribeNotificationsRequest::setProxyInfoGrpList(){
	mTagsPresent[SubscribeNotificationsRequest_PROXYINFO] = 1;
	if(mProxyInfoGrpList == NULL)
		mProxyInfoGrpList = new list<SH::ProxyInfo*>;
	mMandatoryAvpSetVal[SubscribeNotificationsRequest_PROXYINFO] = 1;
	mProxyInfoGrpList->clear();
	return mProxyInfoGrpList;
}

void SubscribeNotificationsRequest::resetProxyInfoGrpList(){
	mTagsPresent[SubscribeNotificationsRequest_PROXYINFO] = 0;
	if(mProxyInfoGrpList != NULL)
		delete mProxyInfoGrpList;
}

list<OctetString*>* SubscribeNotificationsRequest::getRouteRecordList()
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

list<OctetString*>* SubscribeNotificationsRequest::setRouteRecordList() {
	mTagsPresent[SubscribeNotificationsRequest_ROUTERECORD] = 1;
	if(mRouteRecordList == NULL)
		mRouteRecordList = new list<OctetString*>;
	mMandatoryAvpSetVal [SubscribeNotificationsRequest_ROUTERECORD] = 1;
	mRouteRecordList->clear();
	return mRouteRecordList;
}

void SubscribeNotificationsRequest::resetRouteRecordList(){
	mTagsPresent[SubscribeNotificationsRequest_ROUTERECORD] = 0;
	if(mRouteRecordList != NULL)
		delete mRouteRecordList;
}



int SubscribeNotificationsRequest::Encode(byteArray *array)
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
	array->byte[array->offset++] = (308>>16) & 0xFF;
	array->byte[array->offset++] = (308>>8) & 0xFF;
	array->byte[array->offset++] = (308) & 0xFF;
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
			case SubscribeNotificationsRequest_SESSIONID:
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
			case SubscribeNotificationsRequest_DRMP:
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
			case SubscribeNotificationsRequest_VENDORSPECIFICAPPLICATIONID:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(260);
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
				if((this->getVendorSpecificApplicationId()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding VendorSpecificApplicationId");
					throw lTssDiaMsgException;
					}
				}
				break;
			case SubscribeNotificationsRequest_AUTHSESSIONSTATE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(277);
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
					if(!mAuthSessionState->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAuthSessionState->getAvpOffsetLen().first], mAuthSessionState->getAvpOffsetLen().second);
						array->offset += mAuthSessionState->getAvpOffsetLen().second;
						array->size += mAuthSessionState->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AuthSessionState");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mAuthSessionState->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AuthSessionState");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SubscribeNotificationsRequest_ORIGINHOST:
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
			case SubscribeNotificationsRequest_ORIGINREALM:
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
			case SubscribeNotificationsRequest_DESTINATIONHOST:
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
			case SubscribeNotificationsRequest_DESTINATIONREALM:
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
			case SubscribeNotificationsRequest_SUPPORTEDFEATURES:
			{
				if( mSupportedFeaturesGrpList->size() <= 0) {
					break;
				}

				mSupportedFeaturesGrpIterator = this->getSupportedFeaturesGrpList()->begin();
				while(mSupportedFeaturesGrpIterator != mSupportedFeaturesGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(628);
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
					if(((*mSupportedFeaturesGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SupportedFeatures");
						throw lTssDiaMsgException;
					}
					
					mSupportedFeaturesGrpIterator++;
				}
				}
				break;
			case SubscribeNotificationsRequest_USERIDENTITY:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(700);
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
				if((this->getUserIdentity()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserIdentity");
					throw lTssDiaMsgException;
					}
				}
				break;
			case SubscribeNotificationsRequest_WILDCARDEDPUBLICIDENTITY:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(634);
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
					if(!mWildcardedPublicIdentity->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mWildcardedPublicIdentity->getAvpOffsetLen().first], mWildcardedPublicIdentity->getAvpOffsetLen().second);
						array->offset += mWildcardedPublicIdentity->getAvpOffsetLen().second;
						array->size += mWildcardedPublicIdentity->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mWildcardedPublicIdentity->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mWildcardedPublicIdentity->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding WildcardedPublicIdentity");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mWildcardedPublicIdentity->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mWildcardedPublicIdentity->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding WildcardedPublicIdentity");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SubscribeNotificationsRequest_WILDCARDEDIMPU:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(636);
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
					if(!mWildcardedIMPU->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mWildcardedIMPU->getAvpOffsetLen().first], mWildcardedIMPU->getAvpOffsetLen().second);
						array->offset += mWildcardedIMPU->getAvpOffsetLen().second;
						array->size += mWildcardedIMPU->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mWildcardedIMPU->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mWildcardedIMPU->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding WildcardedIMPU");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mWildcardedIMPU->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mWildcardedIMPU->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding WildcardedIMPU");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SubscribeNotificationsRequest_SERVICEINDICATION:
			{
					if( mServiceIndicationList->size() <= 0) {
						break;
					}

					mServiceIndicationIterator = this->getServiceIndicationList()->begin();
					while(mServiceIndicationIterator != mServiceIndicationList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(704);
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
					if(!(*mServiceIndicationIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mServiceIndicationIterator)->getAvpOffsetLen().first], (*mServiceIndicationIterator)->getAvpOffsetLen().second);
						array->offset += (*mServiceIndicationIterator)->getAvpOffsetLen().second;
						array->size += (*mServiceIndicationIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mServiceIndicationIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mServiceIndicationIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ServiceIndication");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mServiceIndicationIterator++;
						continue;
					}
						if(((*mServiceIndicationIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mServiceIndicationIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ServiceIndication");
							throw lTssDiaMsgException;
						}
						mServiceIndicationIterator++;
				}
				}
				break;
			case SubscribeNotificationsRequest_SENDDATAINDICATION:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(710);
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
					if(!mSendDataIndication->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSendDataIndication->getAvpOffsetLen().first], mSendDataIndication->getAvpOffsetLen().second);
						array->offset += mSendDataIndication->getAvpOffsetLen().second;
						array->size += mSendDataIndication->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SendDataIndication");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mSendDataIndication->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SendDataIndication");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SubscribeNotificationsRequest_SERVERNAME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(602);
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
					if(!mServerName->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mServerName->getAvpOffsetLen().first], mServerName->getAvpOffsetLen().second);
						array->offset += mServerName->getAvpOffsetLen().second;
						array->size += mServerName->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mServerName->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mServerName->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ServerName");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mServerName->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mServerName->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ServerName");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SubscribeNotificationsRequest_SUBSREQTYPE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(705);
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
					if(!mSubsReqType->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSubsReqType->getAvpOffsetLen().first], mSubsReqType->getAvpOffsetLen().second);
						array->offset += mSubsReqType->getAvpOffsetLen().second;
						array->size += mSubsReqType->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SubsReqType");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mSubsReqType->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SubsReqType");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SubscribeNotificationsRequest_DATAREFERENCE:
			{
					if( mDataReferenceList->size() <= 0) {
						break;
					}

					mDataReferenceIterator = this->getDataReferenceList()->begin();
					while(mDataReferenceIterator != mDataReferenceList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(703);
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
					if(!(*mDataReferenceIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mDataReferenceIterator)->getAvpOffsetLen().first], (*mDataReferenceIterator)->getAvpOffsetLen().second);
						array->offset += (*mDataReferenceIterator)->getAvpOffsetLen().second;
						array->size += (*mDataReferenceIterator)->getAvpOffsetLen().second;
						if(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)
						{
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DataReference");
							throw lTssDiaMsgException;
						}
						mDataReferenceIterator++;
						continue;
					}
					if(((*mDataReferenceIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DataReference");
						throw lTssDiaMsgException;
					}
					mDataReferenceIterator++;
				}
				}
				break;
			case SubscribeNotificationsRequest_IDENTITYSET:
			{
					if( mIdentitySetList->size() <= 0) {
						break;
					}

					mIdentitySetIterator = this->getIdentitySetList()->begin();
					while(mIdentitySetIterator != mIdentitySetList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(708);
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
					if(!(*mIdentitySetIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mIdentitySetIterator)->getAvpOffsetLen().first], (*mIdentitySetIterator)->getAvpOffsetLen().second);
						array->offset += (*mIdentitySetIterator)->getAvpOffsetLen().second;
						array->size += (*mIdentitySetIterator)->getAvpOffsetLen().second;
						if(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)
						{
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding IdentitySet");
							throw lTssDiaMsgException;
						}
						mIdentitySetIterator++;
						continue;
					}
					if(((*mIdentitySetIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding IdentitySet");
						throw lTssDiaMsgException;
					}
					mIdentitySetIterator++;
				}
				}
				break;
			case SubscribeNotificationsRequest_EXPIRYTIME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(709);
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
					if(!mExpiryTime->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mExpiryTime->getAvpOffsetLen().first], mExpiryTime->getAvpOffsetLen().second);
						array->offset += mExpiryTime->getAvpOffsetLen().second;
						array->size += mExpiryTime->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mExpiryTime->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mExpiryTime->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExpiryTime");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mExpiryTime->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mExpiryTime->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExpiryTime");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SubscribeNotificationsRequest_DSAITAG:
			{
					if( mDSAITagList->size() <= 0) {
						break;
					}

					mDSAITagIterator = this->getDSAITagList()->begin();
					while(mDSAITagIterator != mDSAITagList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(711);
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
					if(!(*mDSAITagIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mDSAITagIterator)->getAvpOffsetLen().first], (*mDSAITagIterator)->getAvpOffsetLen().second);
						array->offset += (*mDSAITagIterator)->getAvpOffsetLen().second;
						array->size += (*mDSAITagIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mDSAITagIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mDSAITagIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DSAITag");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mDSAITagIterator++;
						continue;
					}
						if(((*mDSAITagIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mDSAITagIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DSAITag");
							throw lTssDiaMsgException;
						}
						mDSAITagIterator++;
				}
				}
				break;
			case SubscribeNotificationsRequest_ONETIMENOTIFICATION:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(712);
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
					if(!mOneTimeNotification->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mOneTimeNotification->getAvpOffsetLen().first], mOneTimeNotification->getAvpOffsetLen().second);
						array->offset += mOneTimeNotification->getAvpOffsetLen().second;
						array->size += mOneTimeNotification->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OneTimeNotification");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mOneTimeNotification->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OneTimeNotification");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SubscribeNotificationsRequest_USERNAME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1);
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
					if(!mUserName->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mUserName->getAvpOffsetLen().first], mUserName->getAvpOffsetLen().second);
						array->offset += mUserName->getAvpOffsetLen().second;
						array->size += mUserName->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mUserName->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mUserName->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserName");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mUserName->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mUserName->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserName");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SubscribeNotificationsRequest_OCSUPPORTEDFEATURES:
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
			case SubscribeNotificationsRequest_PROXYINFO:
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
			case SubscribeNotificationsRequest_ROUTERECORD:
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


int SubscribeNotificationsRequest::Decode(byteArray *array, INT16 lMLen, UINT16 *parsedBytes)
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
						mMandatoryAvpSetVal [SubscribeNotificationsRequest_SESSIONID] = 1;
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
			case 260:
				{
						mMandatoryAvpSetVal [SubscribeNotificationsRequest_VENDORSPECIFICAPPLICATIONID] = 1;
					mTagsPresent[SubscribeNotificationsRequest_VENDORSPECIFICAPPLICATIONID] = 1;
						if( NULL == this->setVendorSpecificApplicationId()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding VendorSpecificApplicationId");
						throw lTssDiaMsgException;
						}
					mVendorSpecificApplicationIdGrp->setAvpCode(260);
					mVendorSpecificApplicationIdGrp->SetDataType((DiameterDataType)6);
					mVendorSpecificApplicationIdGrp->mspByteArray = mspByteArray;
					mVendorSpecificApplicationIdGrp->mAvpDecodedFlag = false;
					mVendorSpecificApplicationIdGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mVendorSpecificApplicationIdGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			case 277:
				{
						mMandatoryAvpSetVal [SubscribeNotificationsRequest_AUTHSESSIONSTATE] = 1;
					if( NULL == this->setAuthSessionState())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AuthSessionState");
						throw lTssDiaMsgException;
					}
					mAuthSessionState->setAvpCode(277);
					mAuthSessionState->setAvpVendorId(lVenderId);
					mAuthSessionState->SetDataType((DiameterDataType)7);
					mAuthSessionState->mspByteArray = mspByteArray;
					mAuthSessionState->mAvpDecodedFlag = false;
					mAuthSessionState->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 264:
				{
						mMandatoryAvpSetVal [SubscribeNotificationsRequest_ORIGINHOST] = 1;
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
						mMandatoryAvpSetVal [SubscribeNotificationsRequest_ORIGINREALM] = 1;
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
			case 293:
				{
						mMandatoryAvpSetVal [SubscribeNotificationsRequest_DESTINATIONHOST] = 1;
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
			case 283:
				{
						mMandatoryAvpSetVal [SubscribeNotificationsRequest_DESTINATIONREALM] = 1;
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
			case 628:
				{
					mTagsPresent[SubscribeNotificationsRequest_SUPPORTEDFEATURES] = 1;
					SupportedFeatures *lSupportedFeatures = new SupportedFeatures();
					if( lSupportedFeatures == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SupportedFeatures");
						throw lTssDiaMsgException;
					}
					lSupportedFeatures->setAvpCode(628);
					lSupportedFeatures->SetDataType((DiameterDataType)6);
					lSupportedFeatures->mspByteArray = mspByteArray;
					lSupportedFeatures->mAvpDecodedFlag = false;
					lSupportedFeatures->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mSupportedFeaturesGrpList == NULL)
						this->setSupportedFeaturesGrpList();
					mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
					mBaseInterfaceList.push_back(lSupportedFeatures);
					
				}
				break;
			case 700:
				{
						mMandatoryAvpSetVal [SubscribeNotificationsRequest_USERIDENTITY] = 1;
					mTagsPresent[SubscribeNotificationsRequest_USERIDENTITY] = 1;
						if( NULL == this->setUserIdentity()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserIdentity");
						throw lTssDiaMsgException;
						}
					mUserIdentityGrp->setAvpCode(700);
					mUserIdentityGrp->SetDataType((DiameterDataType)6);
					mUserIdentityGrp->mspByteArray = mspByteArray;
					mUserIdentityGrp->mAvpDecodedFlag = false;
					mUserIdentityGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mUserIdentityGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			case 634:
				{
					if( NULL == this->setWildcardedPublicIdentity())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding WildcardedPublicIdentity");
						throw lTssDiaMsgException;
					}
					mWildcardedPublicIdentity->setAvpCode(634);
					mWildcardedPublicIdentity->setAvpVendorId(lVenderId);
					mWildcardedPublicIdentity->SetDataType((DiameterDataType)5);
					mWildcardedPublicIdentity->mspByteArray = mspByteArray;
					mWildcardedPublicIdentity->mAvpDecodedFlag = false;
					mWildcardedPublicIdentity->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 636:
				{
					if( NULL == this->setWildcardedIMPU())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding WildcardedIMPU");
						throw lTssDiaMsgException;
					}
					mWildcardedIMPU->setAvpCode(636);
					mWildcardedIMPU->setAvpVendorId(lVenderId);
					mWildcardedIMPU->SetDataType((DiameterDataType)5);
					mWildcardedIMPU->mspByteArray = mspByteArray;
					mWildcardedIMPU->mAvpDecodedFlag = false;
					mWildcardedIMPU->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 704:
				{
						mMandatoryAvpSetVal [SubscribeNotificationsRequest_SERVICEINDICATION] = 1;
					mTagsPresent[SubscribeNotificationsRequest_SERVICEINDICATION] = 1;
					OctetString *lServiceIndication = new OctetString();
					if( lServiceIndication == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ServiceIndication");
						throw lTssDiaMsgException;
					}
					lServiceIndication->setAvpCode(704);
					lServiceIndication->setAvpVendorId(lVenderId);
					lServiceIndication->SetDataType((DiameterDataType)5);
					lServiceIndication->mspByteArray = mspByteArray;
					lServiceIndication->mAvpDecodedFlag = false;
					lServiceIndication->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mServiceIndicationList == NULL)
						this->setServiceIndicationList();
					mServiceIndicationList->push_back(lServiceIndication);
					
				}
				break;
			case 710:
				{
					if( NULL == this->setSendDataIndication())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SendDataIndication");
						throw lTssDiaMsgException;
					}
					mSendDataIndication->setAvpCode(710);
					mSendDataIndication->setAvpVendorId(lVenderId);
					mSendDataIndication->SetDataType((DiameterDataType)7);
					mSendDataIndication->mspByteArray = mspByteArray;
					mSendDataIndication->mAvpDecodedFlag = false;
					mSendDataIndication->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 602:
				{
						mMandatoryAvpSetVal [SubscribeNotificationsRequest_SERVERNAME] = 1;
					if( NULL == this->setServerName())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ServerName");
						throw lTssDiaMsgException;
					}
					mServerName->setAvpCode(602);
					mServerName->setAvpVendorId(lVenderId);
					mServerName->SetDataType((DiameterDataType)5);
					mServerName->mspByteArray = mspByteArray;
					mServerName->mAvpDecodedFlag = false;
					mServerName->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 705:
				{
						mMandatoryAvpSetVal [SubscribeNotificationsRequest_SUBSREQTYPE] = 1;
					if( NULL == this->setSubsReqType())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SubsReqType");
						throw lTssDiaMsgException;
					}
					mSubsReqType->setAvpCode(705);
					mSubsReqType->setAvpVendorId(lVenderId);
					mSubsReqType->SetDataType((DiameterDataType)7);
					mSubsReqType->mspByteArray = mspByteArray;
					mSubsReqType->mAvpDecodedFlag = false;
					mSubsReqType->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 703:
				{
						mMandatoryAvpSetVal [SubscribeNotificationsRequest_DATAREFERENCE] = 1;
					mTagsPresent[SubscribeNotificationsRequest_DATAREFERENCE] = 1;
					DataReference *lDataReference = new DataReference();
					if( lDataReference == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DataReference");
						throw lTssDiaMsgException;
					}
					lDataReference->setAvpCode(703);
					lDataReference->setAvpVendorId(lVenderId);
					lDataReference->SetDataType((DiameterDataType)7);
					lDataReference->mspByteArray = mspByteArray;
					lDataReference->mAvpDecodedFlag = false;
					lDataReference->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mDataReferenceList == NULL)
						this->setDataReferenceList();
					mDataReferenceList->push_back(lDataReference);
					
				}
				break;
			case 708:
				{
					mTagsPresent[SubscribeNotificationsRequest_IDENTITYSET] = 1;
					IdentitySet *lIdentitySet = new IdentitySet();
					if( lIdentitySet == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding IdentitySet");
						throw lTssDiaMsgException;
					}
					lIdentitySet->setAvpCode(708);
					lIdentitySet->setAvpVendorId(lVenderId);
					lIdentitySet->SetDataType((DiameterDataType)7);
					lIdentitySet->mspByteArray = mspByteArray;
					lIdentitySet->mAvpDecodedFlag = false;
					lIdentitySet->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mIdentitySetList == NULL)
						this->setIdentitySetList();
					mIdentitySetList->push_back(lIdentitySet);
					
				}
				break;
			case 709:
				{
					if( NULL == this->setExpiryTime())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExpiryTime");
						throw lTssDiaMsgException;
					}
					mExpiryTime->setAvpCode(709);
					mExpiryTime->setAvpVendorId(lVenderId);
					mExpiryTime->SetDataType((DiameterDataType)9);
					mExpiryTime->mspByteArray = mspByteArray;
					mExpiryTime->mAvpDecodedFlag = false;
					mExpiryTime->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 711:
				{
						mMandatoryAvpSetVal [SubscribeNotificationsRequest_DSAITAG] = 1;
					mTagsPresent[SubscribeNotificationsRequest_DSAITAG] = 1;
					OctetString *lDSAITag = new OctetString();
					if( lDSAITag == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DSAITag");
						throw lTssDiaMsgException;
					}
					lDSAITag->setAvpCode(711);
					lDSAITag->setAvpVendorId(lVenderId);
					lDSAITag->SetDataType((DiameterDataType)5);
					lDSAITag->mspByteArray = mspByteArray;
					lDSAITag->mAvpDecodedFlag = false;
					lDSAITag->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mDSAITagList == NULL)
						this->setDSAITagList();
					mDSAITagList->push_back(lDSAITag);
					
				}
				break;
			case 712:
				{
					if( NULL == this->setOneTimeNotification())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OneTimeNotification");
						throw lTssDiaMsgException;
					}
					mOneTimeNotification->setAvpCode(712);
					mOneTimeNotification->setAvpVendorId(lVenderId);
					mOneTimeNotification->SetDataType((DiameterDataType)7);
					mOneTimeNotification->mspByteArray = mspByteArray;
					mOneTimeNotification->mAvpDecodedFlag = false;
					mOneTimeNotification->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1:
				{
						mMandatoryAvpSetVal [SubscribeNotificationsRequest_USERNAME] = 1;
					if( NULL == this->setUserName())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserName");
						throw lTssDiaMsgException;
					}
					mUserName->setAvpCode(1);
					mUserName->setAvpVendorId(lVenderId);
					mUserName->SetDataType((DiameterDataType)5);
					mUserName->mspByteArray = mspByteArray;
					mUserName->mAvpDecodedFlag = false;
					mUserName->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 621:
				{
					mTagsPresent[SubscribeNotificationsRequest_OCSUPPORTEDFEATURES] = 1;
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
			case 284:
				{
						mMandatoryAvpSetVal [SubscribeNotificationsRequest_PROXYINFO] = 1;
					mTagsPresent[SubscribeNotificationsRequest_PROXYINFO] = 1;
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
						mMandatoryAvpSetVal [SubscribeNotificationsRequest_ROUTERECORD] = 1;
					mTagsPresent[SubscribeNotificationsRequest_ROUTERECORD] = 1;
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


DiameterBaseInterface* SubscribeNotificationsRequest::Find(byteArray *array, UINT32 avpCode)
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
			case 277:
			{
				if(mAuthSessionState != NULL)
					return mAuthSessionState->Find(array, avpCode);
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
			case 293:
			{
				if(mDestinationHost != NULL)
					return mDestinationHost->Find(array, avpCode);
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
			case 634:
			{
				if(mWildcardedPublicIdentity != NULL)
					return mWildcardedPublicIdentity->Find(array, avpCode);
				else
					return NULL;
			}
			case 636:
			{
				if(mWildcardedIMPU != NULL)
					return mWildcardedIMPU->Find(array, avpCode);
				else
					return NULL;
			}
			case 704:
			{
				if(mServiceIndicationList != NULL && mServiceIndicationList->size() > 0)
					return (mServiceIndicationList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 710:
			{
				if(mSendDataIndication != NULL)
					return mSendDataIndication->Find(array, avpCode);
				else
					return NULL;
			}
			case 602:
			{
				if(mServerName != NULL)
					return mServerName->Find(array, avpCode);
				else
					return NULL;
			}
			case 705:
			{
				if(mSubsReqType != NULL)
					return mSubsReqType->Find(array, avpCode);
				else
					return NULL;
			}
			case 703:
			{
				if(mDataReferenceList != NULL && mDataReferenceList->size() > 0)
					return (mDataReferenceList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 708:
			{
				if(mIdentitySetList != NULL && mIdentitySetList->size() > 0)
					return (mIdentitySetList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 709:
			{
				if(mExpiryTime != NULL)
					return mExpiryTime->Find(array, avpCode);
				else
					return NULL;
			}
			case 711:
			{
				if(mDSAITagList != NULL && mDSAITagList->size() > 0)
					return (mDSAITagList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 712:
			{
				if(mOneTimeNotification != NULL)
					return mOneTimeNotification->Find(array, avpCode);
				else
					return NULL;
			}
			case 1:
			{
				if(mUserName != NULL)
					return mUserName->Find(array, avpCode);
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


BOOLEAN SubscribeNotificationsRequest::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
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
			case 260:
			{
				if(mVendorSpecificApplicationIdGrp != NULL)
				{
						pBaseInterface.push_back(mVendorSpecificApplicationIdGrp);
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
			case 277:
			{
				if(mAuthSessionState != NULL)
				{
					DiameterBaseInterface* inf =  mAuthSessionState->Find(this->mspByteArray.get(), avpCode);
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
			case 628:
			{
				if(mSupportedFeaturesGrpList != NULL)
				{
					for(auto itr = mSupportedFeaturesGrpList->begin(); itr != mSupportedFeaturesGrpList->end(); ++itr)
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
			case 700:
			{
				if(mUserIdentityGrp != NULL)
				{
						pBaseInterface.push_back(mUserIdentityGrp);
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
			case 634:
			{
				if(mWildcardedPublicIdentity != NULL)
				{
					DiameterBaseInterface* inf =  mWildcardedPublicIdentity->Find(this->mspByteArray.get(), avpCode);
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
			case 636:
			{
				if(mWildcardedIMPU != NULL)
				{
					DiameterBaseInterface* inf =  mWildcardedIMPU->Find(this->mspByteArray.get(), avpCode);
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
			case 704:
			{
				if(mServiceIndicationList != NULL)
				{
					for(auto itr = mServiceIndicationList->begin(); itr != mServiceIndicationList->end(); ++itr)
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
			case 710:
			{
				if(mSendDataIndication != NULL)
				{
					DiameterBaseInterface* inf =  mSendDataIndication->Find(this->mspByteArray.get(), avpCode);
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
			case 602:
			{
				if(mServerName != NULL)
				{
					DiameterBaseInterface* inf =  mServerName->Find(this->mspByteArray.get(), avpCode);
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
			case 705:
			{
				if(mSubsReqType != NULL)
				{
					DiameterBaseInterface* inf =  mSubsReqType->Find(this->mspByteArray.get(), avpCode);
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
			case 703:
			{
				if(mDataReferenceList != NULL)
				{
					for(auto itr = mDataReferenceList->begin(); itr != mDataReferenceList->end(); ++itr)
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
			case 708:
			{
				if(mIdentitySetList != NULL)
				{
					for(auto itr = mIdentitySetList->begin(); itr != mIdentitySetList->end(); ++itr)
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
			case 709:
			{
				if(mExpiryTime != NULL)
				{
					DiameterBaseInterface* inf =  mExpiryTime->Find(this->mspByteArray.get(), avpCode);
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
			case 711:
			{
				if(mDSAITagList != NULL)
				{
					for(auto itr = mDSAITagList->begin(); itr != mDSAITagList->end(); ++itr)
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
			case 712:
			{
				if(mOneTimeNotification != NULL)
				{
					DiameterBaseInterface* inf =  mOneTimeNotification->Find(this->mspByteArray.get(), avpCode);
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
			case 1:
			{
				if(mUserName != NULL)
				{
					DiameterBaseInterface* inf =  mUserName->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> SubscribeNotificationsRequest::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN SubscribeNotificationsRequest::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
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
			case 260:
			{
				if(mVendorSpecificApplicationIdGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mVendorSpecificApplicationIdGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mVendorSpecificApplicationIdGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
				}
				}
				break;
			}
			case 277:
			{
				if(mAuthSessionState != NULL)
				{
					DiameterBaseInterface* inf =  mAuthSessionState->Find(this->mspByteArray.get(), avpCode);
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
			case 628:
			{
				if(mSupportedFeaturesGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mSupportedFeaturesGrpList->begin(); itr != mSupportedFeaturesGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mSupportedFeaturesGrpList->begin(); itr != mSupportedFeaturesGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 700:
			{
				if(mUserIdentityGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mUserIdentityGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mUserIdentityGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
				}
				}
				break;
			}
			case 634:
			{
				if(mWildcardedPublicIdentity != NULL)
				{
					DiameterBaseInterface* inf =  mWildcardedPublicIdentity->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 636:
			{
				if(mWildcardedIMPU != NULL)
				{
					DiameterBaseInterface* inf =  mWildcardedIMPU->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 704:
			{
				if(mServiceIndicationList != NULL)
				{
					for(auto itr = mServiceIndicationList->begin(); itr != mServiceIndicationList->end(); ++itr)
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
			case 710:
			{
				if(mSendDataIndication != NULL)
				{
					DiameterBaseInterface* inf =  mSendDataIndication->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 602:
			{
				if(mServerName != NULL)
				{
					DiameterBaseInterface* inf =  mServerName->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 705:
			{
				if(mSubsReqType != NULL)
				{
					DiameterBaseInterface* inf =  mSubsReqType->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 703:
			{
				if(mDataReferenceList != NULL)
				{
					for(auto itr = mDataReferenceList->begin(); itr != mDataReferenceList->end(); ++itr)
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
			case 708:
			{
				if(mIdentitySetList != NULL)
				{
					for(auto itr = mIdentitySetList->begin(); itr != mIdentitySetList->end(); ++itr)
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
			case 709:
			{
				if(mExpiryTime != NULL)
				{
					DiameterBaseInterface* inf =  mExpiryTime->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 711:
			{
				if(mDSAITagList != NULL)
				{
					for(auto itr = mDSAITagList->begin(); itr != mDSAITagList->end(); ++itr)
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
			case 712:
			{
				if(mOneTimeNotification != NULL)
				{
					DiameterBaseInterface* inf =  mOneTimeNotification->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1:
			{
				if(mUserName != NULL)
				{
					DiameterBaseInterface* inf =  mUserName->Find(this->mspByteArray.get(), avpCode);
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




void SubscribeNotificationsRequest::Display(UINT32 tab)
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
			case SubscribeNotificationsRequest_SESSIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "263" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SessionId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getSessionId()->Display(tab+1);
			}
				break;
			case SubscribeNotificationsRequest_DRMP:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "301" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DRMP" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getDRMP()->Display(tab+1);
			}
				break;
			case SubscribeNotificationsRequest_VENDORSPECIFICAPPLICATIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "260" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "VendorSpecificApplicationId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getVendorSpecificApplicationId()->Display(tab+1);
			}
				break;
			case SubscribeNotificationsRequest_AUTHSESSIONSTATE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "277" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AuthSessionState" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getAuthSessionState()->Display(tab+1);
			}
				break;
			case SubscribeNotificationsRequest_ORIGINHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "264" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginHost()->Display(tab+1);
			}
				break;
			case SubscribeNotificationsRequest_ORIGINREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "296" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginRealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginRealm()->Display(tab+1);
			}
				break;
			case SubscribeNotificationsRequest_DESTINATIONHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "293" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DestinationHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getDestinationHost()->Display(tab+1);
			}
				break;
			case SubscribeNotificationsRequest_DESTINATIONREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "283" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DestinationRealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getDestinationRealm()->Display(tab+1);
			}
				break;
			case SubscribeNotificationsRequest_SUPPORTEDFEATURES:
			{
				if( mSupportedFeaturesGrpList->size() <= 0) {
					break;
				}

				mSupportedFeaturesGrpIterator = this->getSupportedFeaturesGrpList()->begin();
				while(mSupportedFeaturesGrpIterator != this->getSupportedFeaturesGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "628" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SupportedFeatures" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mSupportedFeaturesGrpIterator)->Display(tab+1);
					mSupportedFeaturesGrpIterator++;

				};

			}
				break;
			case SubscribeNotificationsRequest_USERIDENTITY:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "700" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserIdentity" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getUserIdentity()->Display(tab+1);
			}
				break;
			case SubscribeNotificationsRequest_WILDCARDEDPUBLICIDENTITY:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "634" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "WildcardedPublicIdentity" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getWildcardedPublicIdentity()->Display(tab+1);
			}
				break;
			case SubscribeNotificationsRequest_WILDCARDEDIMPU:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "636" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "WildcardedIMPU" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getWildcardedIMPU()->Display(tab+1);
			}
				break;
			case SubscribeNotificationsRequest_SERVICEINDICATION:
			{
				if( mServiceIndicationList->size() <= 0) {
					break;
				}

				mServiceIndicationIterator = this->getServiceIndicationList()->begin();
				while(mServiceIndicationIterator != this->getServiceIndicationList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "704" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ServiceIndication" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mServiceIndicationIterator)->Display(tab+1);
					mServiceIndicationIterator++;

				};

			}
				break;
			case SubscribeNotificationsRequest_SENDDATAINDICATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "710" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SendDataIndication" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getSendDataIndication()->Display(tab+1);
			}
				break;
			case SubscribeNotificationsRequest_SERVERNAME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "602" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ServerName" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getServerName()->Display(tab+1);
			}
				break;
			case SubscribeNotificationsRequest_SUBSREQTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "705" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SubsReqType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getSubsReqType()->Display(tab+1);
			}
				break;
			case SubscribeNotificationsRequest_DATAREFERENCE:
			{
				if( mDataReferenceList->size() <= 0) {
					break;
				}

				mDataReferenceIterator = this->getDataReferenceList()->begin();
				while(mDataReferenceIterator != this->getDataReferenceList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "703" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DataReference" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mDataReferenceIterator)->Display(tab+1);
					mDataReferenceIterator++;

				};

			}
				break;
			case SubscribeNotificationsRequest_IDENTITYSET:
			{
				if( mIdentitySetList->size() <= 0) {
					break;
				}

				mIdentitySetIterator = this->getIdentitySetList()->begin();
				while(mIdentitySetIterator != this->getIdentitySetList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "708" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "IdentitySet" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mIdentitySetIterator)->Display(tab+1);
					mIdentitySetIterator++;

				};

			}
				break;
			case SubscribeNotificationsRequest_EXPIRYTIME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "709" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ExpiryTime" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getExpiryTime()->Display(tab+1);
			}
				break;
			case SubscribeNotificationsRequest_DSAITAG:
			{
				if( mDSAITagList->size() <= 0) {
					break;
				}

				mDSAITagIterator = this->getDSAITagList()->begin();
				while(mDSAITagIterator != this->getDSAITagList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "711" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DSAITag" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mDSAITagIterator)->Display(tab+1);
					mDSAITagIterator++;

				};

			}
				break;
			case SubscribeNotificationsRequest_ONETIMENOTIFICATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "712" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OneTimeNotification" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getOneTimeNotification()->Display(tab+1);
			}
				break;
			case SubscribeNotificationsRequest_USERNAME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserName" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getUserName()->Display(tab+1);
			}
				break;
			case SubscribeNotificationsRequest_OCSUPPORTEDFEATURES:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "621" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OCSupportedFeatures" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getOCSupportedFeatures()->Display(tab+1);
			}
				break;
			case SubscribeNotificationsRequest_PROXYINFO:
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
			case SubscribeNotificationsRequest_ROUTERECORD:
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


BOOLEAN SubscribeNotificationsRequest::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<25> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case SubscribeNotificationsRequest_SESSIONID:
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
			case SubscribeNotificationsRequest_DRMP:
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
			case SubscribeNotificationsRequest_VENDORSPECIFICAPPLICATIONID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 260");
				}
				else
					sprintf(lMissingAvpInfo, "%s,260", lMissingAvpInfo);
			}
				break;
			case SubscribeNotificationsRequest_AUTHSESSIONSTATE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 277");
				}
				else
					sprintf(lMissingAvpInfo, "%s,277", lMissingAvpInfo);
			}
				break;
			case SubscribeNotificationsRequest_ORIGINHOST:
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
			case SubscribeNotificationsRequest_ORIGINREALM:
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
			case SubscribeNotificationsRequest_DESTINATIONHOST:
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
			case SubscribeNotificationsRequest_DESTINATIONREALM:
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
			case SubscribeNotificationsRequest_SUPPORTEDFEATURES:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 628");
				}
				else
					sprintf(lMissingAvpInfo, "%s,628", lMissingAvpInfo);
			}
				break;
			case SubscribeNotificationsRequest_USERIDENTITY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 700");
				}
				else
					sprintf(lMissingAvpInfo, "%s,700", lMissingAvpInfo);
			}
				break;
			case SubscribeNotificationsRequest_WILDCARDEDPUBLICIDENTITY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 634");
				}
				else
					sprintf(lMissingAvpInfo, "%s,634", lMissingAvpInfo);
			}
				break;
			case SubscribeNotificationsRequest_WILDCARDEDIMPU:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 636");
				}
				else
					sprintf(lMissingAvpInfo, "%s,636", lMissingAvpInfo);
			}
				break;
			case SubscribeNotificationsRequest_SERVICEINDICATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 704");
				}
				else
					sprintf(lMissingAvpInfo, "%s,704", lMissingAvpInfo);
			}
				break;
			case SubscribeNotificationsRequest_SENDDATAINDICATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 710");
				}
				else
					sprintf(lMissingAvpInfo, "%s,710", lMissingAvpInfo);
			}
				break;
			case SubscribeNotificationsRequest_SERVERNAME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 602");
				}
				else
					sprintf(lMissingAvpInfo, "%s,602", lMissingAvpInfo);
			}
				break;
			case SubscribeNotificationsRequest_SUBSREQTYPE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 705");
				}
				else
					sprintf(lMissingAvpInfo, "%s,705", lMissingAvpInfo);
			}
				break;
			case SubscribeNotificationsRequest_DATAREFERENCE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 703");
				}
				else
					sprintf(lMissingAvpInfo, "%s,703", lMissingAvpInfo);
			}
				break;
			case SubscribeNotificationsRequest_IDENTITYSET:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 708");
				}
				else
					sprintf(lMissingAvpInfo, "%s,708", lMissingAvpInfo);
			}
				break;
			case SubscribeNotificationsRequest_EXPIRYTIME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 709");
				}
				else
					sprintf(lMissingAvpInfo, "%s,709", lMissingAvpInfo);
			}
				break;
			case SubscribeNotificationsRequest_DSAITAG:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 711");
				}
				else
					sprintf(lMissingAvpInfo, "%s,711", lMissingAvpInfo);
			}
				break;
			case SubscribeNotificationsRequest_ONETIMENOTIFICATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 712");
				}
				else
					sprintf(lMissingAvpInfo, "%s,712", lMissingAvpInfo);
			}
				break;
			case SubscribeNotificationsRequest_USERNAME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1", lMissingAvpInfo);
			}
				break;
			case SubscribeNotificationsRequest_OCSUPPORTEDFEATURES:
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
			case SubscribeNotificationsRequest_PROXYINFO:
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
			case SubscribeNotificationsRequest_ROUTERECORD:
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
