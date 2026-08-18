#include "slh/include/LCSRoutingInfoRequest.h"

using namespace SLH;
BOOLEAN LCSRoutingInfoRequest::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

LCSRoutingInfoRequest::LCSRoutingInfoRequest()
{
	mSessionId = NULL;
	mVendorSpecificApplicationIdGrpList = NULL;
	mAuthSessionState = NULL;
	mOriginHost = NULL;
	mOriginRealm = NULL;
	mDestinationHost = NULL;
	mDestinationRealm = NULL;
	mUserName = NULL;
	mMSISDN = NULL;
	mGMLCNumber = NULL;
	mSupportedFeaturesGrpList = NULL;
	mProxyInfoGrpList = NULL;
	mRouteRecordList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<13>(string("1101111111011"));
	mMandatoryAvpSetVal.reset();
}

LCSRoutingInfoRequest::~LCSRoutingInfoRequest()
{
	if(mSessionId != NULL)
		delete mSessionId;
	if(mVendorSpecificApplicationIdGrpList != NULL){
		mVendorSpecificApplicationIdGrpIterator = mVendorSpecificApplicationIdGrpList->begin();
		while(mVendorSpecificApplicationIdGrpIterator != mVendorSpecificApplicationIdGrpList->end()){
	if(*mVendorSpecificApplicationIdGrpIterator != NULL)
			delete (*mVendorSpecificApplicationIdGrpIterator);
			mVendorSpecificApplicationIdGrpIterator++;
		}
		delete mVendorSpecificApplicationIdGrpList;
	}
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
	if(mUserName != NULL)
		delete mUserName;
	if(mMSISDN != NULL)
		delete mMSISDN;
	if(mGMLCNumber != NULL)
		delete mGMLCNumber;
	if(mSupportedFeaturesGrpList != NULL){
		mSupportedFeaturesGrpIterator = mSupportedFeaturesGrpList->begin();
		while(mSupportedFeaturesGrpIterator != mSupportedFeaturesGrpList->end()){
	if(*mSupportedFeaturesGrpIterator != NULL)
			delete (*mSupportedFeaturesGrpIterator);
			mSupportedFeaturesGrpIterator++;
		}
		delete mSupportedFeaturesGrpList;
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

OctetString* LCSRoutingInfoRequest::setSessionId(){
	mMandatoryAvpSetVal [LCSRoutingInfoRequest_SESSIONID] = 1;
	if(mSessionId == NULL)
	{
		mSessionId = new OctetString();
		mTagsPresent[LCSRoutingInfoRequest_SESSIONID] = 1;
		return mSessionId;
	}
	return mSessionId;
}

void LCSRoutingInfoRequest::resetSessionId(){
	mTagsPresent[LCSRoutingInfoRequest_SESSIONID] = 0;
	if(mSessionId != NULL)
	{
		delete mSessionId; 
		mSessionId = NULL;
	}
}

AuthSessionState* LCSRoutingInfoRequest::setAuthSessionState(){
	if(mAuthSessionState == NULL)
	{
		mAuthSessionState = new AuthSessionState();
		mTagsPresent[LCSRoutingInfoRequest_AUTHSESSIONSTATE] = 1;
		return mAuthSessionState;
	}
	return mAuthSessionState;
}

void LCSRoutingInfoRequest::resetAuthSessionState(){
	mTagsPresent[LCSRoutingInfoRequest_AUTHSESSIONSTATE] = 0;
	if(mAuthSessionState != NULL)
	{
		delete mAuthSessionState; 
		mAuthSessionState = NULL;
	}
}

OctetString* LCSRoutingInfoRequest::setOriginHost(){
	mMandatoryAvpSetVal [LCSRoutingInfoRequest_ORIGINHOST] = 1;
	if(mOriginHost == NULL)
	{
		mOriginHost = new OctetString();
		mTagsPresent[LCSRoutingInfoRequest_ORIGINHOST] = 1;
		return mOriginHost;
	}
	return mOriginHost;
}

void LCSRoutingInfoRequest::resetOriginHost(){
	mTagsPresent[LCSRoutingInfoRequest_ORIGINHOST] = 0;
	if(mOriginHost != NULL)
	{
		delete mOriginHost; 
		mOriginHost = NULL;
	}
}

OctetString* LCSRoutingInfoRequest::setOriginRealm(){
	mMandatoryAvpSetVal [LCSRoutingInfoRequest_ORIGINREALM] = 1;
	if(mOriginRealm == NULL)
	{
		mOriginRealm = new OctetString();
		mTagsPresent[LCSRoutingInfoRequest_ORIGINREALM] = 1;
		return mOriginRealm;
	}
	return mOriginRealm;
}

void LCSRoutingInfoRequest::resetOriginRealm(){
	mTagsPresent[LCSRoutingInfoRequest_ORIGINREALM] = 0;
	if(mOriginRealm != NULL)
	{
		delete mOriginRealm; 
		mOriginRealm = NULL;
	}
}

OctetString* LCSRoutingInfoRequest::setDestinationHost(){
	mMandatoryAvpSetVal [LCSRoutingInfoRequest_DESTINATIONHOST] = 1;
	if(mDestinationHost == NULL)
	{
		mDestinationHost = new OctetString();
		mTagsPresent[LCSRoutingInfoRequest_DESTINATIONHOST] = 1;
		return mDestinationHost;
	}
	return mDestinationHost;
}

void LCSRoutingInfoRequest::resetDestinationHost(){
	mTagsPresent[LCSRoutingInfoRequest_DESTINATIONHOST] = 0;
	if(mDestinationHost != NULL)
	{
		delete mDestinationHost; 
		mDestinationHost = NULL;
	}
}

OctetString* LCSRoutingInfoRequest::setDestinationRealm(){
	mMandatoryAvpSetVal [LCSRoutingInfoRequest_DESTINATIONREALM] = 1;
	if(mDestinationRealm == NULL)
	{
		mDestinationRealm = new OctetString();
		mTagsPresent[LCSRoutingInfoRequest_DESTINATIONREALM] = 1;
		return mDestinationRealm;
	}
	return mDestinationRealm;
}

void LCSRoutingInfoRequest::resetDestinationRealm(){
	mTagsPresent[LCSRoutingInfoRequest_DESTINATIONREALM] = 0;
	if(mDestinationRealm != NULL)
	{
		delete mDestinationRealm; 
		mDestinationRealm = NULL;
	}
}

OctetString* LCSRoutingInfoRequest::setUserName(){
	mMandatoryAvpSetVal [LCSRoutingInfoRequest_USERNAME] = 1;
	if(mUserName == NULL)
	{
		mUserName = new OctetString();
		mTagsPresent[LCSRoutingInfoRequest_USERNAME] = 1;
		return mUserName;
	}
	return mUserName;
}

void LCSRoutingInfoRequest::resetUserName(){
	mTagsPresent[LCSRoutingInfoRequest_USERNAME] = 0;
	if(mUserName != NULL)
	{
		delete mUserName; 
		mUserName = NULL;
	}
}

OctetString* LCSRoutingInfoRequest::setMSISDN(){
	mMandatoryAvpSetVal [LCSRoutingInfoRequest_MSISDN] = 1;
	if(mMSISDN == NULL)
	{
		mMSISDN = new OctetString();
		mTagsPresent[LCSRoutingInfoRequest_MSISDN] = 1;
		return mMSISDN;
	}
	return mMSISDN;
}

void LCSRoutingInfoRequest::resetMSISDN(){
	mTagsPresent[LCSRoutingInfoRequest_MSISDN] = 0;
	if(mMSISDN != NULL)
	{
		delete mMSISDN; 
		mMSISDN = NULL;
	}
}

OctetString* LCSRoutingInfoRequest::setGMLCNumber(){
	mMandatoryAvpSetVal [LCSRoutingInfoRequest_GMLCNUMBER] = 1;
	if(mGMLCNumber == NULL)
	{
		mGMLCNumber = new OctetString();
		mTagsPresent[LCSRoutingInfoRequest_GMLCNUMBER] = 1;
		return mGMLCNumber;
	}
	return mGMLCNumber;
}

void LCSRoutingInfoRequest::resetGMLCNumber(){
	mTagsPresent[LCSRoutingInfoRequest_GMLCNUMBER] = 0;
	if(mGMLCNumber != NULL)
	{
		delete mGMLCNumber; 
		mGMLCNumber = NULL;
	}
}

OctetString* LCSRoutingInfoRequest::getSessionId(){
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

list<SLH::VendorSpecificApplicationId*>* SLH::LCSRoutingInfoRequest::getVendorSpecificApplicationIdGrpList()
{
	if(mVendorSpecificApplicationIdGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "VendorSpecificApplicationId is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mVendorSpecificApplicationIdGrpList)
	{
		if(mVendorSpecificApplicationIdGrpList != NULL)
		{
		if(mVendorSpecificApplicationIdGrpList->size() == 0)
		{
			mTagsPresent[LCSRoutingInfoRequest_VENDORSPECIFICAPPLICATIONID] = 0;
			mVendorSpecificApplicationIdGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "VendorSpecificApplicationId is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "VendorSpecificApplicationId is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding VendorSpecificApplicationId")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mVendorSpecificApplicationIdGrpList;
}

list<SLH::VendorSpecificApplicationId*>* SLH::LCSRoutingInfoRequest::setVendorSpecificApplicationIdGrpList(){
	mTagsPresent[LCSRoutingInfoRequest_VENDORSPECIFICAPPLICATIONID] = 1;
	if(mVendorSpecificApplicationIdGrpList == NULL)
		mVendorSpecificApplicationIdGrpList = new list<VendorSpecificApplicationId*>;
	mMandatoryAvpSetVal[LCSRoutingInfoRequest_VENDORSPECIFICAPPLICATIONID] = 1;
	mVendorSpecificApplicationIdGrpList->clear();
	return mVendorSpecificApplicationIdGrpList;
}

void LCSRoutingInfoRequest::resetVendorSpecificApplicationIdGrpList(){
	mTagsPresent[LCSRoutingInfoRequest_VENDORSPECIFICAPPLICATIONID] = 0;
	if(mVendorSpecificApplicationIdGrpList != NULL)
		delete mVendorSpecificApplicationIdGrpList;
}

AuthSessionState* LCSRoutingInfoRequest::getAuthSessionState(){
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

OctetString* LCSRoutingInfoRequest::getOriginHost(){
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

OctetString* LCSRoutingInfoRequest::getOriginRealm(){
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

OctetString* LCSRoutingInfoRequest::getDestinationHost(){
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

OctetString* LCSRoutingInfoRequest::getDestinationRealm(){
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

OctetString* LCSRoutingInfoRequest::getUserName(){
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

OctetString* LCSRoutingInfoRequest::getMSISDN(){
	if(NULL == mMSISDN) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MSISDN is Null");
		throw lTssDiaMsgException;
	}
	if(!mMSISDN->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMSISDN->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MSISDN is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMSISDN->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMSISDN->Decode(mspByteArray.get(), mMSISDN->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MSISDN")     ;
			throw lTssDiaMsgException;
		}
		mMSISDN->mAvpDecodedFlag = true;
	}
	return mMSISDN;
}

OctetString* LCSRoutingInfoRequest::getGMLCNumber(){
	if(NULL == mGMLCNumber) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "GMLCNumber is Null");
		throw lTssDiaMsgException;
	}
	if(!mGMLCNumber->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mGMLCNumber->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "GMLCNumber is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mGMLCNumber->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mGMLCNumber->Decode(mspByteArray.get(), mGMLCNumber->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding GMLCNumber")     ;
			throw lTssDiaMsgException;
		}
		mGMLCNumber->mAvpDecodedFlag = true;
	}
	return mGMLCNumber;
}

list<SupportedFeatures*>* LCSRoutingInfoRequest::getSupportedFeaturesGrpList()
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
			mTagsPresent[LCSRoutingInfoRequest_SUPPORTEDFEATURES] = 0;
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

list<SupportedFeatures*>* LCSRoutingInfoRequest::setSupportedFeaturesGrpList(){
	mTagsPresent[LCSRoutingInfoRequest_SUPPORTEDFEATURES] = 1;
	if(mSupportedFeaturesGrpList == NULL)
		mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
	mSupportedFeaturesGrpList->clear();
	return mSupportedFeaturesGrpList;
}

void LCSRoutingInfoRequest::resetSupportedFeaturesGrpList(){
	mTagsPresent[LCSRoutingInfoRequest_SUPPORTEDFEATURES] = 0;
	if(mSupportedFeaturesGrpList != NULL)
		delete mSupportedFeaturesGrpList;
}

list<SLH::ProxyInfo*>* LCSRoutingInfoRequest::getProxyInfoGrpList()
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
			mTagsPresent[LCSRoutingInfoRequest_PROXYINFO] = 0;
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

list<SLH::ProxyInfo*>* LCSRoutingInfoRequest::setProxyInfoGrpList(){
	mTagsPresent[LCSRoutingInfoRequest_PROXYINFO] = 1;
	if(mProxyInfoGrpList == NULL)
		mProxyInfoGrpList = new list<SLH::ProxyInfo*>;
	mMandatoryAvpSetVal[LCSRoutingInfoRequest_PROXYINFO] = 1;
	mProxyInfoGrpList->clear();
	return mProxyInfoGrpList;
}

void LCSRoutingInfoRequest::resetProxyInfoGrpList(){
	mTagsPresent[LCSRoutingInfoRequest_PROXYINFO] = 0;
	if(mProxyInfoGrpList != NULL)
		delete mProxyInfoGrpList;
}

list<OctetString*>* LCSRoutingInfoRequest::getRouteRecordList()
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

list<OctetString*>* LCSRoutingInfoRequest::setRouteRecordList() {
	mTagsPresent[LCSRoutingInfoRequest_ROUTERECORD] = 1;
	if(mRouteRecordList == NULL)
		mRouteRecordList = new list<OctetString*>;
	mMandatoryAvpSetVal [LCSRoutingInfoRequest_ROUTERECORD] = 1;
	mRouteRecordList->clear();
	return mRouteRecordList;
}

void LCSRoutingInfoRequest::resetRouteRecordList(){
	mTagsPresent[LCSRoutingInfoRequest_ROUTERECORD] = 0;
	if(mRouteRecordList != NULL)
		delete mRouteRecordList;
}



int LCSRoutingInfoRequest::Encode(byteArray *array)
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
	array->byte[array->offset++] = (8388622>>16) & 0xFF;
	array->byte[array->offset++] = (8388622>>8) & 0xFF;
	array->byte[array->offset++] = (8388622) & 0xFF;
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
			case LCSRoutingInfoRequest_SESSIONID:
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
			case LCSRoutingInfoRequest_VENDORSPECIFICAPPLICATIONID:
			{
				if( mVendorSpecificApplicationIdGrpList->size() <= 0) {
					break;
				}

				mVendorSpecificApplicationIdGrpIterator = this->getVendorSpecificApplicationIdGrpList()->begin();
				while(mVendorSpecificApplicationIdGrpIterator != mVendorSpecificApplicationIdGrpList->end())
				{
					lengthOffset = 0;
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
					if(((*mVendorSpecificApplicationIdGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding VendorSpecificApplicationId");
						throw lTssDiaMsgException;
					}
					
					mVendorSpecificApplicationIdGrpIterator++;
				}
				}
				break;
			case LCSRoutingInfoRequest_AUTHSESSIONSTATE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(277);
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
			case LCSRoutingInfoRequest_ORIGINHOST:
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
			case LCSRoutingInfoRequest_ORIGINREALM:
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
			case LCSRoutingInfoRequest_DESTINATIONHOST:
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
			case LCSRoutingInfoRequest_DESTINATIONREALM:
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
			case LCSRoutingInfoRequest_USERNAME:
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
			case LCSRoutingInfoRequest_MSISDN:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(701);
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
					if(!mMSISDN->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMSISDN->getAvpOffsetLen().first], mMSISDN->getAvpOffsetLen().second);
						array->offset += mMSISDN->getAvpOffsetLen().second;
						array->size += mMSISDN->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mMSISDN->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mMSISDN->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MSISDN");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mMSISDN->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mMSISDN->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MSISDN");
						throw lTssDiaMsgException;
					}
				}
				break;
			case LCSRoutingInfoRequest_GMLCNUMBER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1474);
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
					if(!mGMLCNumber->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mGMLCNumber->getAvpOffsetLen().first], mGMLCNumber->getAvpOffsetLen().second);
						array->offset += mGMLCNumber->getAvpOffsetLen().second;
						array->size += mGMLCNumber->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mGMLCNumber->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mGMLCNumber->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding GMLCNumber");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mGMLCNumber->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mGMLCNumber->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding GMLCNumber");
						throw lTssDiaMsgException;
					}
				}
				break;
			case LCSRoutingInfoRequest_SUPPORTEDFEATURES:
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
			case LCSRoutingInfoRequest_PROXYINFO:
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
			case LCSRoutingInfoRequest_ROUTERECORD:
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


int LCSRoutingInfoRequest::Decode(byteArray *array, INT16 lMLen, UINT16 *parsedBytes)
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
						mMandatoryAvpSetVal [LCSRoutingInfoRequest_SESSIONID] = 1;
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
			case 260:
				{
						mMandatoryAvpSetVal [LCSRoutingInfoRequest_VENDORSPECIFICAPPLICATIONID] = 1;
					mTagsPresent[LCSRoutingInfoRequest_VENDORSPECIFICAPPLICATIONID] = 1;
					VendorSpecificApplicationId *lVendorSpecificApplicationId = new VendorSpecificApplicationId();
					if( lVendorSpecificApplicationId == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding VendorSpecificApplicationId");
						throw lTssDiaMsgException;
					}
					lVendorSpecificApplicationId->setAvpCode(260);
					lVendorSpecificApplicationId->SetDataType((DiameterDataType)6);
					lVendorSpecificApplicationId->mspByteArray = mspByteArray;
					lVendorSpecificApplicationId->mAvpDecodedFlag = false;
					lVendorSpecificApplicationId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mVendorSpecificApplicationIdGrpList == NULL)
						this->setVendorSpecificApplicationIdGrpList();
					mVendorSpecificApplicationIdGrpList->push_back(lVendorSpecificApplicationId);
					mBaseInterfaceList.push_back(lVendorSpecificApplicationId);
					
				}
				break;
			case 277:
				{
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
						mMandatoryAvpSetVal [LCSRoutingInfoRequest_ORIGINHOST] = 1;
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
						mMandatoryAvpSetVal [LCSRoutingInfoRequest_ORIGINREALM] = 1;
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
						mMandatoryAvpSetVal [LCSRoutingInfoRequest_DESTINATIONHOST] = 1;
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
						mMandatoryAvpSetVal [LCSRoutingInfoRequest_DESTINATIONREALM] = 1;
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
			case 1:
				{
						mMandatoryAvpSetVal [LCSRoutingInfoRequest_USERNAME] = 1;
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
			case 701:
				{
						mMandatoryAvpSetVal [LCSRoutingInfoRequest_MSISDN] = 1;
					if( NULL == this->setMSISDN())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MSISDN");
						throw lTssDiaMsgException;
					}
					mMSISDN->setAvpCode(701);
					mMSISDN->setAvpVendorId(lVenderId);
					mMSISDN->SetDataType((DiameterDataType)5);
					mMSISDN->mspByteArray = mspByteArray;
					mMSISDN->mAvpDecodedFlag = false;
					mMSISDN->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1474:
				{
						mMandatoryAvpSetVal [LCSRoutingInfoRequest_GMLCNUMBER] = 1;
					if( NULL == this->setGMLCNumber())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding GMLCNumber");
						throw lTssDiaMsgException;
					}
					mGMLCNumber->setAvpCode(1474);
					mGMLCNumber->setAvpVendorId(lVenderId);
					mGMLCNumber->SetDataType((DiameterDataType)5);
					mGMLCNumber->mspByteArray = mspByteArray;
					mGMLCNumber->mAvpDecodedFlag = false;
					mGMLCNumber->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 628:
				{
					mTagsPresent[LCSRoutingInfoRequest_SUPPORTEDFEATURES] = 1;
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
			case 284:
				{
						mMandatoryAvpSetVal [LCSRoutingInfoRequest_PROXYINFO] = 1;
					mTagsPresent[LCSRoutingInfoRequest_PROXYINFO] = 1;
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
						mMandatoryAvpSetVal [LCSRoutingInfoRequest_ROUTERECORD] = 1;
					mTagsPresent[LCSRoutingInfoRequest_ROUTERECORD] = 1;
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


DiameterBaseInterface* LCSRoutingInfoRequest::Find(byteArray *array, UINT32 avpCode)
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
			case 1:
			{
				if(mUserName != NULL)
					return mUserName->Find(array, avpCode);
				else
					return NULL;
			}
			case 701:
			{
				if(mMSISDN != NULL)
					return mMSISDN->Find(array, avpCode);
				else
					return NULL;
			}
			case 1474:
			{
				if(mGMLCNumber != NULL)
					return mGMLCNumber->Find(array, avpCode);
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


BOOLEAN LCSRoutingInfoRequest::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
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
			case 260:
			{
				if(mVendorSpecificApplicationIdGrpList != NULL)
				{
					for(auto itr = mVendorSpecificApplicationIdGrpList->begin(); itr != mVendorSpecificApplicationIdGrpList->end(); ++itr)
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
			case 701:
			{
				if(mMSISDN != NULL)
				{
					DiameterBaseInterface* inf =  mMSISDN->Find(this->mspByteArray.get(), avpCode);
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
			case 1474:
			{
				if(mGMLCNumber != NULL)
				{
					DiameterBaseInterface* inf =  mGMLCNumber->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> LCSRoutingInfoRequest::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN LCSRoutingInfoRequest::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
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
			case 260:
			{
				if(mVendorSpecificApplicationIdGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mVendorSpecificApplicationIdGrpList->begin(); itr != mVendorSpecificApplicationIdGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mVendorSpecificApplicationIdGrpList->begin(); itr != mVendorSpecificApplicationIdGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
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
			case 701:
			{
				if(mMSISDN != NULL)
				{
					DiameterBaseInterface* inf =  mMSISDN->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1474:
			{
				if(mGMLCNumber != NULL)
				{
					DiameterBaseInterface* inf =  mGMLCNumber->Find(this->mspByteArray.get(), avpCode);
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




void LCSRoutingInfoRequest::Display(UINT32 tab)
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
			case LCSRoutingInfoRequest_SESSIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "263" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SessionId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getSessionId()->Display(tab+1);
			}
				break;
			case LCSRoutingInfoRequest_VENDORSPECIFICAPPLICATIONID:
			{
				if( mVendorSpecificApplicationIdGrpList->size() <= 0) {
					break;
				}

				mVendorSpecificApplicationIdGrpIterator = this->getVendorSpecificApplicationIdGrpList()->begin();
				while(mVendorSpecificApplicationIdGrpIterator != this->getVendorSpecificApplicationIdGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "260" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "VendorSpecificApplicationId" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
					(*mVendorSpecificApplicationIdGrpIterator)->Display(tab+1);
					mVendorSpecificApplicationIdGrpIterator++;

				};

			}
				break;
			case LCSRoutingInfoRequest_AUTHSESSIONSTATE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "277" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AuthSessionState" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getAuthSessionState()->Display(tab+1);
			}
				break;
			case LCSRoutingInfoRequest_ORIGINHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "264" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginHost()->Display(tab+1);
			}
				break;
			case LCSRoutingInfoRequest_ORIGINREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "296" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginRealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginRealm()->Display(tab+1);
			}
				break;
			case LCSRoutingInfoRequest_DESTINATIONHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "293" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DestinationHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getDestinationHost()->Display(tab+1);
			}
				break;
			case LCSRoutingInfoRequest_DESTINATIONREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "283" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DestinationRealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getDestinationRealm()->Display(tab+1);
			}
				break;
			case LCSRoutingInfoRequest_USERNAME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserName" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getUserName()->Display(tab+1);
			}
				break;
			case LCSRoutingInfoRequest_MSISDN:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "701" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MSISDN" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getMSISDN()->Display(tab+1);
			}
				break;
			case LCSRoutingInfoRequest_GMLCNUMBER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1474" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "GMLCNumber" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getGMLCNumber()->Display(tab+1);
			}
				break;
			case LCSRoutingInfoRequest_SUPPORTEDFEATURES:
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
			case LCSRoutingInfoRequest_PROXYINFO:
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
			case LCSRoutingInfoRequest_ROUTERECORD:
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


BOOLEAN LCSRoutingInfoRequest::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<13> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case LCSRoutingInfoRequest_SESSIONID:
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
			case LCSRoutingInfoRequest_VENDORSPECIFICAPPLICATIONID:
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
			case LCSRoutingInfoRequest_AUTHSESSIONSTATE:
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
			case LCSRoutingInfoRequest_ORIGINHOST:
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
			case LCSRoutingInfoRequest_ORIGINREALM:
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
			case LCSRoutingInfoRequest_DESTINATIONHOST:
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
			case LCSRoutingInfoRequest_DESTINATIONREALM:
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
			case LCSRoutingInfoRequest_USERNAME:
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
			case LCSRoutingInfoRequest_MSISDN:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 701");
				}
				else
					sprintf(lMissingAvpInfo, "%s,701", lMissingAvpInfo);
			}
				break;
			case LCSRoutingInfoRequest_GMLCNUMBER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1474");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1474", lMissingAvpInfo);
			}
				break;
			case LCSRoutingInfoRequest_SUPPORTEDFEATURES:
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
			case LCSRoutingInfoRequest_PROXYINFO:
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
			case LCSRoutingInfoRequest_ROUTERECORD:
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
