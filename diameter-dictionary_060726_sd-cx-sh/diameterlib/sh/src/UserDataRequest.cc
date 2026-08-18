#include "sh/include/UserDataRequest.h"

using namespace SH;
BOOLEAN UserDataRequest::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

UserDataRequest::UserDataRequest()
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
	mServerName = NULL;
	mServiceIndicationList = NULL;
	mDataReferenceList = NULL;
	mIdentitySetList = NULL;
	mRequestedDomain = NULL;
	mCurrentLocation = NULL;
	mDSAITagList = NULL;
	mSessionPriority = NULL;
	mUserName = NULL;
	mRequestedNodes = NULL;
	mServingNodeIndication = NULL;
	mPrepagingSupported = NULL;
	mLocalTimeZoneIndication = NULL;
	mUDRFlags = NULL;
	mCallReferenceInfoGrp = NULL;
	mOCSupportedFeaturesGrp = NULL;
	mProxyInfoGrpList = NULL;
	mRouteRecordList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<30>(string("110000000101110111001011111101"));
	mMandatoryAvpSetVal.reset();
}

UserDataRequest::~UserDataRequest()
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
	if(mServerName != NULL)
		delete mServerName;
	if(mServiceIndicationList != NULL){
		mServiceIndicationIterator = mServiceIndicationList->begin();
		while(mServiceIndicationIterator != mServiceIndicationList->end()){
			delete (*mServiceIndicationIterator);
			mServiceIndicationIterator++;
		}
		delete mServiceIndicationList;
	}
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
	if(mRequestedDomain != NULL)
		delete mRequestedDomain;
	if(mCurrentLocation != NULL)
		delete mCurrentLocation;
	if(mDSAITagList != NULL){
		mDSAITagIterator = mDSAITagList->begin();
		while(mDSAITagIterator != mDSAITagList->end()){
			delete (*mDSAITagIterator);
			mDSAITagIterator++;
		}
		delete mDSAITagList;
	}
	if(mSessionPriority != NULL)
		delete mSessionPriority;
	if(mUserName != NULL)
		delete mUserName;
	if(mRequestedNodes != NULL)
		delete mRequestedNodes;
	if(mServingNodeIndication != NULL)
		delete mServingNodeIndication;
	if(mPrepagingSupported != NULL)
		delete mPrepagingSupported;
	if(mLocalTimeZoneIndication != NULL)
		delete mLocalTimeZoneIndication;
	if(mUDRFlags != NULL)
		delete mUDRFlags;
	if(mCallReferenceInfoGrp != NULL)
		delete mCallReferenceInfoGrp;
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

OctetString* UserDataRequest::setSessionId(){
	mMandatoryAvpSetVal [UserDataRequest_SESSIONID] = 1;
	if(mSessionId == NULL)
	{
		mSessionId = new OctetString();
		mTagsPresent[UserDataRequest_SESSIONID] = 1;
		return mSessionId;
	}
	return mSessionId;
}

void UserDataRequest::resetSessionId(){
	mTagsPresent[UserDataRequest_SESSIONID] = 0;
	if(mSessionId != NULL)
	{
		delete mSessionId; 
		mSessionId = NULL;
	}
}

DRMP* UserDataRequest::setDRMP(){
	if(mDRMP == NULL)
	{
		mDRMP = new DRMP();
		mTagsPresent[UserDataRequest_DRMP] = 1;
		return mDRMP;
	}
	return mDRMP;
}

void UserDataRequest::resetDRMP(){
	mTagsPresent[UserDataRequest_DRMP] = 0;
	if(mDRMP != NULL)
	{
		delete mDRMP; 
		mDRMP = NULL;
	}
}

AuthSessionState* UserDataRequest::setAuthSessionState(){
	mMandatoryAvpSetVal [UserDataRequest_AUTHSESSIONSTATE] = 1;
	if(mAuthSessionState == NULL)
	{
		mAuthSessionState = new AuthSessionState();
		mTagsPresent[UserDataRequest_AUTHSESSIONSTATE] = 1;
		return mAuthSessionState;
	}
	return mAuthSessionState;
}

void UserDataRequest::resetAuthSessionState(){
	mTagsPresent[UserDataRequest_AUTHSESSIONSTATE] = 0;
	if(mAuthSessionState != NULL)
	{
		delete mAuthSessionState; 
		mAuthSessionState = NULL;
	}
}

OctetString* UserDataRequest::setOriginHost(){
	mMandatoryAvpSetVal [UserDataRequest_ORIGINHOST] = 1;
	if(mOriginHost == NULL)
	{
		mOriginHost = new OctetString();
		mTagsPresent[UserDataRequest_ORIGINHOST] = 1;
		return mOriginHost;
	}
	return mOriginHost;
}

void UserDataRequest::resetOriginHost(){
	mTagsPresent[UserDataRequest_ORIGINHOST] = 0;
	if(mOriginHost != NULL)
	{
		delete mOriginHost; 
		mOriginHost = NULL;
	}
}

OctetString* UserDataRequest::setOriginRealm(){
	mMandatoryAvpSetVal [UserDataRequest_ORIGINREALM] = 1;
	if(mOriginRealm == NULL)
	{
		mOriginRealm = new OctetString();
		mTagsPresent[UserDataRequest_ORIGINREALM] = 1;
		return mOriginRealm;
	}
	return mOriginRealm;
}

void UserDataRequest::resetOriginRealm(){
	mTagsPresent[UserDataRequest_ORIGINREALM] = 0;
	if(mOriginRealm != NULL)
	{
		delete mOriginRealm; 
		mOriginRealm = NULL;
	}
}

OctetString* UserDataRequest::setDestinationHost(){
	mMandatoryAvpSetVal [UserDataRequest_DESTINATIONHOST] = 1;
	if(mDestinationHost == NULL)
	{
		mDestinationHost = new OctetString();
		mTagsPresent[UserDataRequest_DESTINATIONHOST] = 1;
		return mDestinationHost;
	}
	return mDestinationHost;
}

void UserDataRequest::resetDestinationHost(){
	mTagsPresent[UserDataRequest_DESTINATIONHOST] = 0;
	if(mDestinationHost != NULL)
	{
		delete mDestinationHost; 
		mDestinationHost = NULL;
	}
}

OctetString* UserDataRequest::setDestinationRealm(){
	mMandatoryAvpSetVal [UserDataRequest_DESTINATIONREALM] = 1;
	if(mDestinationRealm == NULL)
	{
		mDestinationRealm = new OctetString();
		mTagsPresent[UserDataRequest_DESTINATIONREALM] = 1;
		return mDestinationRealm;
	}
	return mDestinationRealm;
}

void UserDataRequest::resetDestinationRealm(){
	mTagsPresent[UserDataRequest_DESTINATIONREALM] = 0;
	if(mDestinationRealm != NULL)
	{
		delete mDestinationRealm; 
		mDestinationRealm = NULL;
	}
}

OctetString* UserDataRequest::setWildcardedPublicIdentity(){
	if(mWildcardedPublicIdentity == NULL)
	{
		mWildcardedPublicIdentity = new OctetString();
		mTagsPresent[UserDataRequest_WILDCARDEDPUBLICIDENTITY] = 1;
		return mWildcardedPublicIdentity;
	}
	return mWildcardedPublicIdentity;
}

void UserDataRequest::resetWildcardedPublicIdentity(){
	mTagsPresent[UserDataRequest_WILDCARDEDPUBLICIDENTITY] = 0;
	if(mWildcardedPublicIdentity != NULL)
	{
		delete mWildcardedPublicIdentity; 
		mWildcardedPublicIdentity = NULL;
	}
}

OctetString* UserDataRequest::setWildcardedIMPU(){
	if(mWildcardedIMPU == NULL)
	{
		mWildcardedIMPU = new OctetString();
		mTagsPresent[UserDataRequest_WILDCARDEDIMPU] = 1;
		return mWildcardedIMPU;
	}
	return mWildcardedIMPU;
}

void UserDataRequest::resetWildcardedIMPU(){
	mTagsPresent[UserDataRequest_WILDCARDEDIMPU] = 0;
	if(mWildcardedIMPU != NULL)
	{
		delete mWildcardedIMPU; 
		mWildcardedIMPU = NULL;
	}
}

OctetString* UserDataRequest::setServerName(){
	mMandatoryAvpSetVal [UserDataRequest_SERVERNAME] = 1;
	if(mServerName == NULL)
	{
		mServerName = new OctetString();
		mTagsPresent[UserDataRequest_SERVERNAME] = 1;
		return mServerName;
	}
	return mServerName;
}

void UserDataRequest::resetServerName(){
	mTagsPresent[UserDataRequest_SERVERNAME] = 0;
	if(mServerName != NULL)
	{
		delete mServerName; 
		mServerName = NULL;
	}
}

RequestedDomain* UserDataRequest::setRequestedDomain(){
	mMandatoryAvpSetVal [UserDataRequest_REQUESTEDDOMAIN] = 1;
	if(mRequestedDomain == NULL)
	{
		mRequestedDomain = new RequestedDomain();
		mTagsPresent[UserDataRequest_REQUESTEDDOMAIN] = 1;
		return mRequestedDomain;
	}
	return mRequestedDomain;
}

void UserDataRequest::resetRequestedDomain(){
	mTagsPresent[UserDataRequest_REQUESTEDDOMAIN] = 0;
	if(mRequestedDomain != NULL)
	{
		delete mRequestedDomain; 
		mRequestedDomain = NULL;
	}
}

CurrentLocation* UserDataRequest::setCurrentLocation(){
	mMandatoryAvpSetVal [UserDataRequest_CURRENTLOCATION] = 1;
	if(mCurrentLocation == NULL)
	{
		mCurrentLocation = new CurrentLocation();
		mTagsPresent[UserDataRequest_CURRENTLOCATION] = 1;
		return mCurrentLocation;
	}
	return mCurrentLocation;
}

void UserDataRequest::resetCurrentLocation(){
	mTagsPresent[UserDataRequest_CURRENTLOCATION] = 0;
	if(mCurrentLocation != NULL)
	{
		delete mCurrentLocation; 
		mCurrentLocation = NULL;
	}
}

SessionPriority* UserDataRequest::setSessionPriority(){
	if(mSessionPriority == NULL)
	{
		mSessionPriority = new SessionPriority();
		mTagsPresent[UserDataRequest_SESSIONPRIORITY] = 1;
		return mSessionPriority;
	}
	return mSessionPriority;
}

void UserDataRequest::resetSessionPriority(){
	mTagsPresent[UserDataRequest_SESSIONPRIORITY] = 0;
	if(mSessionPriority != NULL)
	{
		delete mSessionPriority; 
		mSessionPriority = NULL;
	}
}

OctetString* UserDataRequest::setUserName(){
	mMandatoryAvpSetVal [UserDataRequest_USERNAME] = 1;
	if(mUserName == NULL)
	{
		mUserName = new OctetString();
		mTagsPresent[UserDataRequest_USERNAME] = 1;
		return mUserName;
	}
	return mUserName;
}

void UserDataRequest::resetUserName(){
	mTagsPresent[UserDataRequest_USERNAME] = 0;
	if(mUserName != NULL)
	{
		delete mUserName; 
		mUserName = NULL;
	}
}

Unsigned32* UserDataRequest::setRequestedNodes(){
	if(mRequestedNodes == NULL)
	{
		mRequestedNodes = new Unsigned32();
		mTagsPresent[UserDataRequest_REQUESTEDNODES] = 1;
		return mRequestedNodes;
	}
	return mRequestedNodes;
}

void UserDataRequest::resetRequestedNodes(){
	mTagsPresent[UserDataRequest_REQUESTEDNODES] = 0;
	if(mRequestedNodes != NULL)
	{
		delete mRequestedNodes; 
		mRequestedNodes = NULL;
	}
}

ServingNodeIndication* UserDataRequest::setServingNodeIndication(){
	if(mServingNodeIndication == NULL)
	{
		mServingNodeIndication = new ServingNodeIndication();
		mTagsPresent[UserDataRequest_SERVINGNODEINDICATION] = 1;
		return mServingNodeIndication;
	}
	return mServingNodeIndication;
}

void UserDataRequest::resetServingNodeIndication(){
	mTagsPresent[UserDataRequest_SERVINGNODEINDICATION] = 0;
	if(mServingNodeIndication != NULL)
	{
		delete mServingNodeIndication; 
		mServingNodeIndication = NULL;
	}
}

PrepagingSupported* UserDataRequest::setPrepagingSupported(){
	if(mPrepagingSupported == NULL)
	{
		mPrepagingSupported = new PrepagingSupported();
		mTagsPresent[UserDataRequest_PREPAGINGSUPPORTED] = 1;
		return mPrepagingSupported;
	}
	return mPrepagingSupported;
}

void UserDataRequest::resetPrepagingSupported(){
	mTagsPresent[UserDataRequest_PREPAGINGSUPPORTED] = 0;
	if(mPrepagingSupported != NULL)
	{
		delete mPrepagingSupported; 
		mPrepagingSupported = NULL;
	}
}

LocalTimeZoneIndication* UserDataRequest::setLocalTimeZoneIndication(){
	if(mLocalTimeZoneIndication == NULL)
	{
		mLocalTimeZoneIndication = new LocalTimeZoneIndication();
		mTagsPresent[UserDataRequest_LOCALTIMEZONEINDICATION] = 1;
		return mLocalTimeZoneIndication;
	}
	return mLocalTimeZoneIndication;
}

void UserDataRequest::resetLocalTimeZoneIndication(){
	mTagsPresent[UserDataRequest_LOCALTIMEZONEINDICATION] = 0;
	if(mLocalTimeZoneIndication != NULL)
	{
		delete mLocalTimeZoneIndication; 
		mLocalTimeZoneIndication = NULL;
	}
}

Unsigned32* UserDataRequest::setUDRFlags(){
	if(mUDRFlags == NULL)
	{
		mUDRFlags = new Unsigned32();
		mTagsPresent[UserDataRequest_UDRFLAGS] = 1;
		return mUDRFlags;
	}
	return mUDRFlags;
}

void UserDataRequest::resetUDRFlags(){
	mTagsPresent[UserDataRequest_UDRFLAGS] = 0;
	if(mUDRFlags != NULL)
	{
		delete mUDRFlags; 
		mUDRFlags = NULL;
	}
}

OctetString* UserDataRequest::getSessionId(){
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

DRMP* UserDataRequest::getDRMP(){
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

SH::VendorSpecificApplicationId* UserDataRequest::getVendorSpecificApplicationId()
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

SH::VendorSpecificApplicationId* UserDataRequest::setVendorSpecificApplicationId(){
	if(mVendorSpecificApplicationIdGrp == NULL)
		mVendorSpecificApplicationIdGrp = new VendorSpecificApplicationId();
	mTagsPresent[UserDataRequest_VENDORSPECIFICAPPLICATIONID] = 1;
	mMandatoryAvpSetVal[UserDataRequest_VENDORSPECIFICAPPLICATIONID] = 1;
	return mVendorSpecificApplicationIdGrp;
}

void UserDataRequest::resetVendorSpecificApplicationId(){
	mTagsPresent[UserDataRequest_VENDORSPECIFICAPPLICATIONID] = 0;
	if(mVendorSpecificApplicationIdGrp != NULL)
		delete mVendorSpecificApplicationIdGrp;
}

AuthSessionState* UserDataRequest::getAuthSessionState(){
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

OctetString* UserDataRequest::getOriginHost(){
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

OctetString* UserDataRequest::getOriginRealm(){
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

OctetString* UserDataRequest::getDestinationHost(){
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

OctetString* UserDataRequest::getDestinationRealm(){
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

list<SupportedFeatures*>* UserDataRequest::getSupportedFeaturesGrpList()
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
			mTagsPresent[UserDataRequest_SUPPORTEDFEATURES] = 0;
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

list<SupportedFeatures*>* UserDataRequest::setSupportedFeaturesGrpList(){
	mTagsPresent[UserDataRequest_SUPPORTEDFEATURES] = 1;
	if(mSupportedFeaturesGrpList == NULL)
		mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
	mSupportedFeaturesGrpList->clear();
	return mSupportedFeaturesGrpList;
}

void UserDataRequest::resetSupportedFeaturesGrpList(){
	mTagsPresent[UserDataRequest_SUPPORTEDFEATURES] = 0;
	if(mSupportedFeaturesGrpList != NULL)
		delete mSupportedFeaturesGrpList;
}

UserIdentity* UserDataRequest::getUserIdentity()
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

UserIdentity* UserDataRequest::setUserIdentity(){
	if(mUserIdentityGrp == NULL)
		mUserIdentityGrp = new UserIdentity();
	mTagsPresent[UserDataRequest_USERIDENTITY] = 1;
	mMandatoryAvpSetVal[UserDataRequest_USERIDENTITY] = 1;
	return mUserIdentityGrp;
}

void UserDataRequest::resetUserIdentity(){
	mTagsPresent[UserDataRequest_USERIDENTITY] = 0;
	if(mUserIdentityGrp != NULL)
		delete mUserIdentityGrp;
}

OctetString* UserDataRequest::getWildcardedPublicIdentity(){
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

OctetString* UserDataRequest::getWildcardedIMPU(){
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

OctetString* UserDataRequest::getServerName(){
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

list<OctetString*>* UserDataRequest::getServiceIndicationList()
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

list<OctetString*>* UserDataRequest::setServiceIndicationList() {
	mTagsPresent[UserDataRequest_SERVICEINDICATION] = 1;
	if(mServiceIndicationList == NULL)
		mServiceIndicationList = new list<OctetString*>;
	mMandatoryAvpSetVal [UserDataRequest_SERVICEINDICATION] = 1;
	mServiceIndicationList->clear();
	return mServiceIndicationList;
}

void UserDataRequest::resetServiceIndicationList(){
	mTagsPresent[UserDataRequest_SERVICEINDICATION] = 0;
	if(mServiceIndicationList != NULL)
		delete mServiceIndicationList;
}

list<DataReference*>* UserDataRequest::getDataReferenceList()
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

list<DataReference*>* UserDataRequest::setDataReferenceList() {
	mTagsPresent[UserDataRequest_DATAREFERENCE] = 1;
	if(mDataReferenceList == NULL)
		mDataReferenceList = new list<DataReference*>;
	mMandatoryAvpSetVal [UserDataRequest_DATAREFERENCE] = 1;
	mDataReferenceList->clear();
	return mDataReferenceList;
}

void UserDataRequest::resetDataReferenceList(){
	mTagsPresent[UserDataRequest_DATAREFERENCE] = 0;
	if(mDataReferenceList != NULL)
		delete mDataReferenceList;
}

list<IdentitySet*>* UserDataRequest::getIdentitySetList()
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

list<IdentitySet*>* UserDataRequest::setIdentitySetList() {
	mTagsPresent[UserDataRequest_IDENTITYSET] = 1;
	if(mIdentitySetList == NULL)
		mIdentitySetList = new list<IdentitySet*>;
	mIdentitySetList->clear();
	return mIdentitySetList;
}

void UserDataRequest::resetIdentitySetList(){
	mTagsPresent[UserDataRequest_IDENTITYSET] = 0;
	if(mIdentitySetList != NULL)
		delete mIdentitySetList;
}

RequestedDomain* UserDataRequest::getRequestedDomain(){
	if(NULL == mRequestedDomain) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RequestedDomain is Null");
		throw lTssDiaMsgException;
	}
	if(!mRequestedDomain->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRequestedDomain->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RequestedDomain is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRequestedDomain->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRequestedDomain->Decode(mspByteArray.get(), mRequestedDomain->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RequestedDomain")     ;
			throw lTssDiaMsgException;
		}
		mRequestedDomain->mAvpDecodedFlag = true;
	}
	return mRequestedDomain;
}

CurrentLocation* UserDataRequest::getCurrentLocation(){
	if(NULL == mCurrentLocation) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CurrentLocation is Null");
		throw lTssDiaMsgException;
	}
	if(!mCurrentLocation->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCurrentLocation->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CurrentLocation is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCurrentLocation->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCurrentLocation->Decode(mspByteArray.get(), mCurrentLocation->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CurrentLocation")     ;
			throw lTssDiaMsgException;
		}
		mCurrentLocation->mAvpDecodedFlag = true;
	}
	return mCurrentLocation;
}

list<OctetString*>* UserDataRequest::getDSAITagList()
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

list<OctetString*>* UserDataRequest::setDSAITagList() {
	mTagsPresent[UserDataRequest_DSAITAG] = 1;
	if(mDSAITagList == NULL)
		mDSAITagList = new list<OctetString*>;
	mMandatoryAvpSetVal [UserDataRequest_DSAITAG] = 1;
	mDSAITagList->clear();
	return mDSAITagList;
}

void UserDataRequest::resetDSAITagList(){
	mTagsPresent[UserDataRequest_DSAITAG] = 0;
	if(mDSAITagList != NULL)
		delete mDSAITagList;
}

SessionPriority* UserDataRequest::getSessionPriority(){
	if(NULL == mSessionPriority) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SessionPriority is Null");
		throw lTssDiaMsgException;
	}
	if(!mSessionPriority->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSessionPriority->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SessionPriority is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSessionPriority->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSessionPriority->Decode(mspByteArray.get(), mSessionPriority->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SessionPriority")     ;
			throw lTssDiaMsgException;
		}
		mSessionPriority->mAvpDecodedFlag = true;
	}
	return mSessionPriority;
}

OctetString* UserDataRequest::getUserName(){
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

Unsigned32* UserDataRequest::getRequestedNodes(){
	if(NULL == mRequestedNodes) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RequestedNodes is Null");
		throw lTssDiaMsgException;
	}
	if(!mRequestedNodes->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRequestedNodes->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RequestedNodes is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRequestedNodes->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRequestedNodes->Decode(mspByteArray.get(), mRequestedNodes->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RequestedNodes")     ;
			throw lTssDiaMsgException;
		}
		mRequestedNodes->mAvpDecodedFlag = true;
	}
	return mRequestedNodes;
}

ServingNodeIndication* UserDataRequest::getServingNodeIndication(){
	if(NULL == mServingNodeIndication) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ServingNodeIndication is Null");
		throw lTssDiaMsgException;
	}
	if(!mServingNodeIndication->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mServingNodeIndication->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ServingNodeIndication is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mServingNodeIndication->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mServingNodeIndication->Decode(mspByteArray.get(), mServingNodeIndication->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ServingNodeIndication")     ;
			throw lTssDiaMsgException;
		}
		mServingNodeIndication->mAvpDecodedFlag = true;
	}
	return mServingNodeIndication;
}

PrepagingSupported* UserDataRequest::getPrepagingSupported(){
	if(NULL == mPrepagingSupported) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PrepagingSupported is Null");
		throw lTssDiaMsgException;
	}
	if(!mPrepagingSupported->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPrepagingSupported->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PrepagingSupported is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPrepagingSupported->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPrepagingSupported->Decode(mspByteArray.get(), mPrepagingSupported->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PrepagingSupported")     ;
			throw lTssDiaMsgException;
		}
		mPrepagingSupported->mAvpDecodedFlag = true;
	}
	return mPrepagingSupported;
}

LocalTimeZoneIndication* UserDataRequest::getLocalTimeZoneIndication(){
	if(NULL == mLocalTimeZoneIndication) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "LocalTimeZoneIndication is Null");
		throw lTssDiaMsgException;
	}
	if(!mLocalTimeZoneIndication->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mLocalTimeZoneIndication->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "LocalTimeZoneIndication is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mLocalTimeZoneIndication->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mLocalTimeZoneIndication->Decode(mspByteArray.get(), mLocalTimeZoneIndication->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding LocalTimeZoneIndication")     ;
			throw lTssDiaMsgException;
		}
		mLocalTimeZoneIndication->mAvpDecodedFlag = true;
	}
	return mLocalTimeZoneIndication;
}

Unsigned32* UserDataRequest::getUDRFlags(){
	if(NULL == mUDRFlags) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UDRFlags is Null");
		throw lTssDiaMsgException;
	}
	if(!mUDRFlags->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUDRFlags->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UDRFlags is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUDRFlags->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUDRFlags->Decode(mspByteArray.get(), mUDRFlags->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UDRFlags")     ;
			throw lTssDiaMsgException;
		}
		mUDRFlags->mAvpDecodedFlag = true;
	}
	return mUDRFlags;
}

CallReferenceInfo* UserDataRequest::getCallReferenceInfo()
{
	if(mCallReferenceInfoGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CallReferenceInfo is Null");
		throw lTssDiaMsgException;
	}
	if(!mCallReferenceInfoGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCallReferenceInfoGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CallReferenceInfo is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCallReferenceInfoGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCallReferenceInfoGrp->Decode(mspByteArray.get(), mCallReferenceInfoGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CallReferenceInfo")     ;
			throw lTssDiaMsgException;
		}
		mCallReferenceInfoGrp->mAvpDecodedFlag = true;
	}
	return mCallReferenceInfoGrp;
}

CallReferenceInfo* UserDataRequest::setCallReferenceInfo(){
	if(mCallReferenceInfoGrp == NULL)
		mCallReferenceInfoGrp = new CallReferenceInfo();
	mTagsPresent[UserDataRequest_CALLREFERENCEINFO] = 1;
	return mCallReferenceInfoGrp;
}

void UserDataRequest::resetCallReferenceInfo(){
	mTagsPresent[UserDataRequest_CALLREFERENCEINFO] = 0;
	if(mCallReferenceInfoGrp != NULL)
		delete mCallReferenceInfoGrp;
}

OCSupportedFeatures* UserDataRequest::getOCSupportedFeatures()
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

OCSupportedFeatures* UserDataRequest::setOCSupportedFeatures(){
	if(mOCSupportedFeaturesGrp == NULL)
		mOCSupportedFeaturesGrp = new OCSupportedFeatures();
	mTagsPresent[UserDataRequest_OCSUPPORTEDFEATURES] = 1;
	return mOCSupportedFeaturesGrp;
}

void UserDataRequest::resetOCSupportedFeatures(){
	mTagsPresent[UserDataRequest_OCSUPPORTEDFEATURES] = 0;
	if(mOCSupportedFeaturesGrp != NULL)
		delete mOCSupportedFeaturesGrp;
}

list<SH::ProxyInfo*>* UserDataRequest::getProxyInfoGrpList()
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
			mTagsPresent[UserDataRequest_PROXYINFO] = 0;
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

list<SH::ProxyInfo*>* UserDataRequest::setProxyInfoGrpList(){
	mTagsPresent[UserDataRequest_PROXYINFO] = 1;
	if(mProxyInfoGrpList == NULL)
		mProxyInfoGrpList = new list<SH::ProxyInfo*>;
	mMandatoryAvpSetVal[UserDataRequest_PROXYINFO] = 1;
	mProxyInfoGrpList->clear();
	return mProxyInfoGrpList;
}

void UserDataRequest::resetProxyInfoGrpList(){
	mTagsPresent[UserDataRequest_PROXYINFO] = 0;
	if(mProxyInfoGrpList != NULL)
		delete mProxyInfoGrpList;
}

list<OctetString*>* UserDataRequest::getRouteRecordList()
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

list<OctetString*>* UserDataRequest::setRouteRecordList() {
	mTagsPresent[UserDataRequest_ROUTERECORD] = 1;
	if(mRouteRecordList == NULL)
		mRouteRecordList = new list<OctetString*>;
	mMandatoryAvpSetVal [UserDataRequest_ROUTERECORD] = 1;
	mRouteRecordList->clear();
	return mRouteRecordList;
}

void UserDataRequest::resetRouteRecordList(){
	mTagsPresent[UserDataRequest_ROUTERECORD] = 0;
	if(mRouteRecordList != NULL)
		delete mRouteRecordList;
}



int UserDataRequest::Encode(byteArray *array)
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
	array->byte[array->offset++] = (306>>16) & 0xFF;
	array->byte[array->offset++] = (306>>8) & 0xFF;
	array->byte[array->offset++] = (306) & 0xFF;
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
			case UserDataRequest_SESSIONID:
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
						INT32 venderId=0;
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
			case UserDataRequest_DRMP:
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
						INT32 venderId=0;
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
			case UserDataRequest_VENDORSPECIFICAPPLICATIONID:
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
						INT32 venderId=0;
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
			case UserDataRequest_AUTHSESSIONSTATE:
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
						INT32 venderId=0;
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
			case UserDataRequest_ORIGINHOST:
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
						INT32 venderId=0;
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
			case UserDataRequest_ORIGINREALM:
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
						INT32 venderId=0;
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
			case UserDataRequest_DESTINATIONHOST:
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
						INT32 venderId=0;
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
			case UserDataRequest_DESTINATIONREALM:
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
						INT32 venderId=0;
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
			case UserDataRequest_SUPPORTEDFEATURES:
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
			case UserDataRequest_USERIDENTITY:
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
			case UserDataRequest_WILDCARDEDPUBLICIDENTITY:
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
			case UserDataRequest_WILDCARDEDIMPU:
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
			case UserDataRequest_SERVERNAME:
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
			case UserDataRequest_SERVICEINDICATION:
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
			case UserDataRequest_DATAREFERENCE:
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
			case UserDataRequest_IDENTITYSET:
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
			case UserDataRequest_REQUESTEDDOMAIN:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(706);
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
					if(!mRequestedDomain->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRequestedDomain->getAvpOffsetLen().first], mRequestedDomain->getAvpOffsetLen().second);
						array->offset += mRequestedDomain->getAvpOffsetLen().second;
						array->size += mRequestedDomain->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RequestedDomain");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mRequestedDomain->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RequestedDomain");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UserDataRequest_CURRENTLOCATION:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(707);
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
					if(!mCurrentLocation->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCurrentLocation->getAvpOffsetLen().first], mCurrentLocation->getAvpOffsetLen().second);
						array->offset += mCurrentLocation->getAvpOffsetLen().second;
						array->size += mCurrentLocation->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CurrentLocation");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mCurrentLocation->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CurrentLocation");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UserDataRequest_DSAITAG:
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
			case UserDataRequest_SESSIONPRIORITY:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(650);
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
					if(!mSessionPriority->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSessionPriority->getAvpOffsetLen().first], mSessionPriority->getAvpOffsetLen().second);
						array->offset += mSessionPriority->getAvpOffsetLen().second;
						array->size += mSessionPriority->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SessionPriority");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mSessionPriority->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SessionPriority");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UserDataRequest_USERNAME:
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
			case UserDataRequest_REQUESTEDNODES:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(713);
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
					if(!mRequestedNodes->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRequestedNodes->getAvpOffsetLen().first], mRequestedNodes->getAvpOffsetLen().second);
						array->offset += mRequestedNodes->getAvpOffsetLen().second;
						array->size += mRequestedNodes->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RequestedNodes");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mRequestedNodes->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RequestedNodes");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UserDataRequest_SERVINGNODEINDICATION:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(714);
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
					if(!mServingNodeIndication->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mServingNodeIndication->getAvpOffsetLen().first], mServingNodeIndication->getAvpOffsetLen().second);
						array->offset += mServingNodeIndication->getAvpOffsetLen().second;
						array->size += mServingNodeIndication->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ServingNodeIndication");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mServingNodeIndication->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ServingNodeIndication");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UserDataRequest_PREPAGINGSUPPORTED:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(717);
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
					if(!mPrepagingSupported->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mPrepagingSupported->getAvpOffsetLen().first], mPrepagingSupported->getAvpOffsetLen().second);
						array->offset += mPrepagingSupported->getAvpOffsetLen().second;
						array->size += mPrepagingSupported->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PrepagingSupported");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mPrepagingSupported->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PrepagingSupported");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UserDataRequest_LOCALTIMEZONEINDICATION:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(718);
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
					if(!mLocalTimeZoneIndication->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mLocalTimeZoneIndication->getAvpOffsetLen().first], mLocalTimeZoneIndication->getAvpOffsetLen().second);
						array->offset += mLocalTimeZoneIndication->getAvpOffsetLen().second;
						array->size += mLocalTimeZoneIndication->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding LocalTimeZoneIndication");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mLocalTimeZoneIndication->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding LocalTimeZoneIndication");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UserDataRequest_UDRFLAGS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(719);
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
					if(!mUDRFlags->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mUDRFlags->getAvpOffsetLen().first], mUDRFlags->getAvpOffsetLen().second);
						array->offset += mUDRFlags->getAvpOffsetLen().second;
						array->size += mUDRFlags->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UDRFlags");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mUDRFlags->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UDRFlags");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UserDataRequest_CALLREFERENCEINFO:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(720);
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
				if((this->getCallReferenceInfo()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CallReferenceInfo");
					throw lTssDiaMsgException;
					}
				}
				break;
			case UserDataRequest_OCSUPPORTEDFEATURES:
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
			case UserDataRequest_PROXYINFO:
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
			case UserDataRequest_ROUTERECORD:
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


int UserDataRequest::Decode(byteArray *array, INT16 lMLen, UINT16 *parsedBytes)
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
						mMandatoryAvpSetVal [UserDataRequest_SESSIONID] = 1;
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
						mMandatoryAvpSetVal [UserDataRequest_VENDORSPECIFICAPPLICATIONID] = 1;
					mTagsPresent[UserDataRequest_VENDORSPECIFICAPPLICATIONID] = 1;
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
						mMandatoryAvpSetVal [UserDataRequest_AUTHSESSIONSTATE] = 1;
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
						mMandatoryAvpSetVal [UserDataRequest_ORIGINHOST] = 1;
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
						mMandatoryAvpSetVal [UserDataRequest_ORIGINREALM] = 1;
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
						mMandatoryAvpSetVal [UserDataRequest_DESTINATIONHOST] = 1;
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
						mMandatoryAvpSetVal [UserDataRequest_DESTINATIONREALM] = 1;
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
					mTagsPresent[UserDataRequest_SUPPORTEDFEATURES] = 1;
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
						mMandatoryAvpSetVal [UserDataRequest_USERIDENTITY] = 1;
					mTagsPresent[UserDataRequest_USERIDENTITY] = 1;
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
			case 602:
				{
						mMandatoryAvpSetVal [UserDataRequest_SERVERNAME] = 1;
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
			case 704:
				{
						mMandatoryAvpSetVal [UserDataRequest_SERVICEINDICATION] = 1;
					mTagsPresent[UserDataRequest_SERVICEINDICATION] = 1;
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
			case 703:
				{
						mMandatoryAvpSetVal [UserDataRequest_DATAREFERENCE] = 1;
					mTagsPresent[UserDataRequest_DATAREFERENCE] = 1;
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
					mTagsPresent[UserDataRequest_IDENTITYSET] = 1;
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
			case 706:
				{
						mMandatoryAvpSetVal [UserDataRequest_REQUESTEDDOMAIN] = 1;
					if( NULL == this->setRequestedDomain())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RequestedDomain");
						throw lTssDiaMsgException;
					}
					mRequestedDomain->setAvpCode(706);
					mRequestedDomain->setAvpVendorId(lVenderId);
					mRequestedDomain->SetDataType((DiameterDataType)7);
					mRequestedDomain->mspByteArray = mspByteArray;
					mRequestedDomain->mAvpDecodedFlag = false;
					mRequestedDomain->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 707:
				{
						mMandatoryAvpSetVal [UserDataRequest_CURRENTLOCATION] = 1;
					if( NULL == this->setCurrentLocation())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CurrentLocation");
						throw lTssDiaMsgException;
					}
					mCurrentLocation->setAvpCode(707);
					mCurrentLocation->setAvpVendorId(lVenderId);
					mCurrentLocation->SetDataType((DiameterDataType)7);
					mCurrentLocation->mspByteArray = mspByteArray;
					mCurrentLocation->mAvpDecodedFlag = false;
					mCurrentLocation->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 711:
				{
						mMandatoryAvpSetVal [UserDataRequest_DSAITAG] = 1;
					mTagsPresent[UserDataRequest_DSAITAG] = 1;
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
			case 650:
				{
					if( NULL == this->setSessionPriority())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SessionPriority");
						throw lTssDiaMsgException;
					}
					mSessionPriority->setAvpCode(650);
					mSessionPriority->setAvpVendorId(lVenderId);
					mSessionPriority->SetDataType((DiameterDataType)7);
					mSessionPriority->mspByteArray = mspByteArray;
					mSessionPriority->mAvpDecodedFlag = false;
					mSessionPriority->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1:
				{
						mMandatoryAvpSetVal [UserDataRequest_USERNAME] = 1;
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
			case 713:
				{
					if( NULL == this->setRequestedNodes())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RequestedNodes");
						throw lTssDiaMsgException;
					}
					mRequestedNodes->setAvpCode(713);
					mRequestedNodes->setAvpVendorId(lVenderId);
					mRequestedNodes->SetDataType((DiameterDataType)3);
					mRequestedNodes->mspByteArray = mspByteArray;
					mRequestedNodes->mAvpDecodedFlag = false;
					mRequestedNodes->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 714:
				{
					if( NULL == this->setServingNodeIndication())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ServingNodeIndication");
						throw lTssDiaMsgException;
					}
					mServingNodeIndication->setAvpCode(714);
					mServingNodeIndication->setAvpVendorId(lVenderId);
					mServingNodeIndication->SetDataType((DiameterDataType)7);
					mServingNodeIndication->mspByteArray = mspByteArray;
					mServingNodeIndication->mAvpDecodedFlag = false;
					mServingNodeIndication->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 717:
				{
					if( NULL == this->setPrepagingSupported())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PrepagingSupported");
						throw lTssDiaMsgException;
					}
					mPrepagingSupported->setAvpCode(717);
					mPrepagingSupported->setAvpVendorId(lVenderId);
					mPrepagingSupported->SetDataType((DiameterDataType)7);
					mPrepagingSupported->mspByteArray = mspByteArray;
					mPrepagingSupported->mAvpDecodedFlag = false;
					mPrepagingSupported->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 718:
				{
					if( NULL == this->setLocalTimeZoneIndication())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding LocalTimeZoneIndication");
						throw lTssDiaMsgException;
					}
					mLocalTimeZoneIndication->setAvpCode(718);
					mLocalTimeZoneIndication->setAvpVendorId(lVenderId);
					mLocalTimeZoneIndication->SetDataType((DiameterDataType)7);
					mLocalTimeZoneIndication->mspByteArray = mspByteArray;
					mLocalTimeZoneIndication->mAvpDecodedFlag = false;
					mLocalTimeZoneIndication->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 719:
				{
					if( NULL == this->setUDRFlags())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UDRFlags");
						throw lTssDiaMsgException;
					}
					mUDRFlags->setAvpCode(719);
					mUDRFlags->setAvpVendorId(lVenderId);
					mUDRFlags->SetDataType((DiameterDataType)3);
					mUDRFlags->mspByteArray = mspByteArray;
					mUDRFlags->mAvpDecodedFlag = false;
					mUDRFlags->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 720:
				{
					mTagsPresent[UserDataRequest_CALLREFERENCEINFO] = 1;
						if( NULL == this->setCallReferenceInfo()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CallReferenceInfo");
						throw lTssDiaMsgException;
						}
					mCallReferenceInfoGrp->setAvpCode(720);
					mCallReferenceInfoGrp->SetDataType((DiameterDataType)6);
					mCallReferenceInfoGrp->mspByteArray = mspByteArray;
					mCallReferenceInfoGrp->mAvpDecodedFlag = false;
					mCallReferenceInfoGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mCallReferenceInfoGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			case 621:
				{
					mTagsPresent[UserDataRequest_OCSUPPORTEDFEATURES] = 1;
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
						mMandatoryAvpSetVal [UserDataRequest_PROXYINFO] = 1;
					mTagsPresent[UserDataRequest_PROXYINFO] = 1;
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
						mMandatoryAvpSetVal [UserDataRequest_ROUTERECORD] = 1;
					mTagsPresent[UserDataRequest_ROUTERECORD] = 1;
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


DiameterBaseInterface* UserDataRequest::Find(byteArray *array, UINT32 avpCode)
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
			case 602:
			{
				if(mServerName != NULL)
					return mServerName->Find(array, avpCode);
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
			case 706:
			{
				if(mRequestedDomain != NULL)
					return mRequestedDomain->Find(array, avpCode);
				else
					return NULL;
			}
			case 707:
			{
				if(mCurrentLocation != NULL)
					return mCurrentLocation->Find(array, avpCode);
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
			case 650:
			{
				if(mSessionPriority != NULL)
					return mSessionPriority->Find(array, avpCode);
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
			case 713:
			{
				if(mRequestedNodes != NULL)
					return mRequestedNodes->Find(array, avpCode);
				else
					return NULL;
			}
			case 714:
			{
				if(mServingNodeIndication != NULL)
					return mServingNodeIndication->Find(array, avpCode);
				else
					return NULL;
			}
			case 717:
			{
				if(mPrepagingSupported != NULL)
					return mPrepagingSupported->Find(array, avpCode);
				else
					return NULL;
			}
			case 718:
			{
				if(mLocalTimeZoneIndication != NULL)
					return mLocalTimeZoneIndication->Find(array, avpCode);
				else
					return NULL;
			}
			case 719:
			{
				if(mUDRFlags != NULL)
					return mUDRFlags->Find(array, avpCode);
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


BOOLEAN UserDataRequest::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
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
			case 706:
			{
				if(mRequestedDomain != NULL)
				{
					DiameterBaseInterface* inf =  mRequestedDomain->Find(this->mspByteArray.get(), avpCode);
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
			case 707:
			{
				if(mCurrentLocation != NULL)
				{
					DiameterBaseInterface* inf =  mCurrentLocation->Find(this->mspByteArray.get(), avpCode);
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
			case 650:
			{
				if(mSessionPriority != NULL)
				{
					DiameterBaseInterface* inf =  mSessionPriority->Find(this->mspByteArray.get(), avpCode);
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
			case 713:
			{
				if(mRequestedNodes != NULL)
				{
					DiameterBaseInterface* inf =  mRequestedNodes->Find(this->mspByteArray.get(), avpCode);
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
			case 714:
			{
				if(mServingNodeIndication != NULL)
				{
					DiameterBaseInterface* inf =  mServingNodeIndication->Find(this->mspByteArray.get(), avpCode);
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
			case 717:
			{
				if(mPrepagingSupported != NULL)
				{
					DiameterBaseInterface* inf =  mPrepagingSupported->Find(this->mspByteArray.get(), avpCode);
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
			case 718:
			{
				if(mLocalTimeZoneIndication != NULL)
				{
					DiameterBaseInterface* inf =  mLocalTimeZoneIndication->Find(this->mspByteArray.get(), avpCode);
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
			case 719:
			{
				if(mUDRFlags != NULL)
				{
					DiameterBaseInterface* inf =  mUDRFlags->Find(this->mspByteArray.get(), avpCode);
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
			case 720:
			{
				if(mCallReferenceInfoGrp != NULL)
				{
						pBaseInterface.push_back(mCallReferenceInfoGrp);
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
std::shared_ptr<byteArray> UserDataRequest::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN UserDataRequest::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
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
			case 706:
			{
				if(mRequestedDomain != NULL)
				{
					DiameterBaseInterface* inf =  mRequestedDomain->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 707:
			{
				if(mCurrentLocation != NULL)
				{
					DiameterBaseInterface* inf =  mCurrentLocation->Find(this->mspByteArray.get(), avpCode);
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
			case 650:
			{
				if(mSessionPriority != NULL)
				{
					DiameterBaseInterface* inf =  mSessionPriority->Find(this->mspByteArray.get(), avpCode);
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
			case 713:
			{
				if(mRequestedNodes != NULL)
				{
					DiameterBaseInterface* inf =  mRequestedNodes->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 714:
			{
				if(mServingNodeIndication != NULL)
				{
					DiameterBaseInterface* inf =  mServingNodeIndication->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 717:
			{
				if(mPrepagingSupported != NULL)
				{
					DiameterBaseInterface* inf =  mPrepagingSupported->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 718:
			{
				if(mLocalTimeZoneIndication != NULL)
				{
					DiameterBaseInterface* inf =  mLocalTimeZoneIndication->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 719:
			{
				if(mUDRFlags != NULL)
				{
					DiameterBaseInterface* inf =  mUDRFlags->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 720:
			{
				if(mCallReferenceInfoGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mCallReferenceInfoGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mCallReferenceInfoGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
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




void UserDataRequest::Display(UINT32 tab)
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
			case UserDataRequest_SESSIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "263" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SessionId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getSessionId()->Display(tab+1);
			}
				break;
			case UserDataRequest_DRMP:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "301" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DRMP" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getDRMP()->Display(tab+1);
			}
				break;
			case UserDataRequest_VENDORSPECIFICAPPLICATIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "260" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "VendorSpecificApplicationId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getVendorSpecificApplicationId()->Display(tab+1);
			}
				break;
			case UserDataRequest_AUTHSESSIONSTATE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "277" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AuthSessionState" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getAuthSessionState()->Display(tab+1);
			}
				break;
			case UserDataRequest_ORIGINHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "264" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginHost()->Display(tab+1);
			}
				break;
			case UserDataRequest_ORIGINREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "296" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginRealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginRealm()->Display(tab+1);
			}
				break;
			case UserDataRequest_DESTINATIONHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "293" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DestinationHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getDestinationHost()->Display(tab+1);
			}
				break;
			case UserDataRequest_DESTINATIONREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "283" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DestinationRealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getDestinationRealm()->Display(tab+1);
			}
				break;
			case UserDataRequest_SUPPORTEDFEATURES:
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
			case UserDataRequest_USERIDENTITY:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "700" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserIdentity" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getUserIdentity()->Display(tab+1);
			}
				break;
			case UserDataRequest_WILDCARDEDPUBLICIDENTITY:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "634" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "WildcardedPublicIdentity" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getWildcardedPublicIdentity()->Display(tab+1);
			}
				break;
			case UserDataRequest_WILDCARDEDIMPU:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "636" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "WildcardedIMPU" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getWildcardedIMPU()->Display(tab+1);
			}
				break;
			case UserDataRequest_SERVERNAME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "602" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ServerName" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getServerName()->Display(tab+1);
			}
				break;
			case UserDataRequest_SERVICEINDICATION:
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
			case UserDataRequest_DATAREFERENCE:
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
			case UserDataRequest_IDENTITYSET:
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
			case UserDataRequest_REQUESTEDDOMAIN:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "706" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RequestedDomain" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getRequestedDomain()->Display(tab+1);
			}
				break;
			case UserDataRequest_CURRENTLOCATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "707" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CurrentLocation" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getCurrentLocation()->Display(tab+1);
			}
				break;
			case UserDataRequest_DSAITAG:
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
			case UserDataRequest_SESSIONPRIORITY:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "650" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SessionPriority" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getSessionPriority()->Display(tab+1);
			}
				break;
			case UserDataRequest_USERNAME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserName" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getUserName()->Display(tab+1);
			}
				break;
			case UserDataRequest_REQUESTEDNODES:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "713" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RequestedNodes" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getRequestedNodes()->Display(tab+1);
			}
				break;
			case UserDataRequest_SERVINGNODEINDICATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "714" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ServingNodeIndication" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getServingNodeIndication()->Display(tab+1);
			}
				break;
			case UserDataRequest_PREPAGINGSUPPORTED:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "717" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PrepagingSupported" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getPrepagingSupported()->Display(tab+1);
			}
				break;
			case UserDataRequest_LOCALTIMEZONEINDICATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "718" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "LocalTimeZoneIndication" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getLocalTimeZoneIndication()->Display(tab+1);
			}
				break;
			case UserDataRequest_UDRFLAGS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "719" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UDRFlags" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getUDRFlags()->Display(tab+1);
			}
				break;
			case UserDataRequest_CALLREFERENCEINFO:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "720" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CallReferenceInfo" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getCallReferenceInfo()->Display(tab+1);
			}
				break;
			case UserDataRequest_OCSUPPORTEDFEATURES:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "621" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OCSupportedFeatures" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getOCSupportedFeatures()->Display(tab+1);
			}
				break;
			case UserDataRequest_PROXYINFO:
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
			case UserDataRequest_ROUTERECORD:
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


BOOLEAN UserDataRequest::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<30> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case UserDataRequest_SESSIONID:
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
			case UserDataRequest_DRMP:
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
			case UserDataRequest_VENDORSPECIFICAPPLICATIONID:
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
			case UserDataRequest_AUTHSESSIONSTATE:
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
			case UserDataRequest_ORIGINHOST:
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
			case UserDataRequest_ORIGINREALM:
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
			case UserDataRequest_DESTINATIONHOST:
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
			case UserDataRequest_DESTINATIONREALM:
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
			case UserDataRequest_SUPPORTEDFEATURES:
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
			case UserDataRequest_USERIDENTITY:
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
			case UserDataRequest_WILDCARDEDPUBLICIDENTITY:
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
			case UserDataRequest_WILDCARDEDIMPU:
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
			case UserDataRequest_SERVERNAME:
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
			case UserDataRequest_SERVICEINDICATION:
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
			case UserDataRequest_DATAREFERENCE:
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
			case UserDataRequest_IDENTITYSET:
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
			case UserDataRequest_REQUESTEDDOMAIN:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 706");
				}
				else
					sprintf(lMissingAvpInfo, "%s,706", lMissingAvpInfo);
			}
				break;
			case UserDataRequest_CURRENTLOCATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 707");
				}
				else
					sprintf(lMissingAvpInfo, "%s,707", lMissingAvpInfo);
			}
				break;
			case UserDataRequest_DSAITAG:
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
			case UserDataRequest_SESSIONPRIORITY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 650");
				}
				else
					sprintf(lMissingAvpInfo, "%s,650", lMissingAvpInfo);
			}
				break;
			case UserDataRequest_USERNAME:
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
			case UserDataRequest_REQUESTEDNODES:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 713");
				}
				else
					sprintf(lMissingAvpInfo, "%s,713", lMissingAvpInfo);
			}
				break;
			case UserDataRequest_SERVINGNODEINDICATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 714");
				}
				else
					sprintf(lMissingAvpInfo, "%s,714", lMissingAvpInfo);
			}
				break;
			case UserDataRequest_PREPAGINGSUPPORTED:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 717");
				}
				else
					sprintf(lMissingAvpInfo, "%s,717", lMissingAvpInfo);
			}
				break;
			case UserDataRequest_LOCALTIMEZONEINDICATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 718");
				}
				else
					sprintf(lMissingAvpInfo, "%s,718", lMissingAvpInfo);
			}
				break;
			case UserDataRequest_UDRFLAGS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 719");
				}
				else
					sprintf(lMissingAvpInfo, "%s,719", lMissingAvpInfo);
			}
				break;
			case UserDataRequest_CALLREFERENCEINFO:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 720");
				}
				else
					sprintf(lMissingAvpInfo, "%s,720", lMissingAvpInfo);
			}
				break;
			case UserDataRequest_OCSUPPORTEDFEATURES:
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
			case UserDataRequest_PROXYINFO:
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
			case UserDataRequest_ROUTERECORD:
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
