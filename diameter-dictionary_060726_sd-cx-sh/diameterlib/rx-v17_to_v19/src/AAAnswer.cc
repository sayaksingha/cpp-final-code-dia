#include "rx/include/AAAnswer.h"

using namespace RX;
BOOLEAN AAAnswer::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

AAAnswer::AAAnswer()
{
	mSessionId = NULL;
	mDRMP = NULL;
	mAuthApplicationId = NULL;
	mOriginHost = NULL;
	mOriginRealm = NULL;
	mResultCode = NULL;
	mExperimentalResultGrp = NULL;
	mAuthSessionState = NULL;
	mAccessNetworkChargingIdentifierGrpList = NULL;
	mAccessNetworkChargingAddress = NULL;
	mAcceptableServiceInfoGrp = NULL;
	mANGWAddressList = NULL;
	mANTrusted = NULL;
	mServiceAuthorizationInfo = NULL;
	mIPCANType = NULL;
	mMAInformationGrpList = NULL;
	mNetLocAccessSupport = NULL;
	mRATType = NULL;
	mFlowsGrpList = NULL;
	mOCSupportedFeaturesGrp = NULL;
	mOCOLRGrp = NULL;
	mSupportedFeaturesGrpList = NULL;
	mSubscriptionIdGrpList = NULL;
	mUserEquipmentInfoGrp = NULL;
	mUserEquipmentInfoExtensionGrp = NULL;
	m3GPPSGSNMCCMNC = NULL;
	mNID = NULL;
	mClass = NULL;
	mErrorMessage = NULL;
	mErrorReportingHost = NULL;
	mFailedAVPGrpList = NULL;
	mRetryInterval = NULL;
	mOriginStateId = NULL;
	mRedirectHostList = NULL;
	mRedirectHostUsage = NULL;
	mRedirectMaxCacheTime = NULL;
	mProxyInfoGrpList = NULL;
	mLoadGrpList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<38>(string("11111101101000011001000101011101111101"));
	mMandatoryAvpSetVal.reset();
}

AAAnswer::~AAAnswer()
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
	if(mResultCode != NULL)
		delete mResultCode;
	if(mExperimentalResultGrp != NULL)
		delete mExperimentalResultGrp;
	if(mAuthSessionState != NULL)
		delete mAuthSessionState;
	if(mAccessNetworkChargingIdentifierGrpList != NULL){
		mAccessNetworkChargingIdentifierGrpIterator = mAccessNetworkChargingIdentifierGrpList->begin();
		while(mAccessNetworkChargingIdentifierGrpIterator != mAccessNetworkChargingIdentifierGrpList->end()){
	if(*mAccessNetworkChargingIdentifierGrpIterator != NULL)
			delete (*mAccessNetworkChargingIdentifierGrpIterator);
			mAccessNetworkChargingIdentifierGrpIterator++;
		}
		delete mAccessNetworkChargingIdentifierGrpList;
	}
	if(mAccessNetworkChargingAddress != NULL)
		delete mAccessNetworkChargingAddress;
	if(mAcceptableServiceInfoGrp != NULL)
		delete mAcceptableServiceInfoGrp;
	if(mANGWAddressList != NULL){
		mANGWAddressIterator = mANGWAddressList->begin();
		while(mANGWAddressIterator != mANGWAddressList->end()){
			delete (*mANGWAddressIterator);
			mANGWAddressIterator++;
		}
		delete mANGWAddressList;
	}
	if(mANTrusted != NULL)
		delete mANTrusted;
	if(mServiceAuthorizationInfo != NULL)
		delete mServiceAuthorizationInfo;
	if(mIPCANType != NULL)
		delete mIPCANType;
	if(mMAInformationGrpList != NULL){
		mMAInformationGrpIterator = mMAInformationGrpList->begin();
		while(mMAInformationGrpIterator != mMAInformationGrpList->end()){
	if(*mMAInformationGrpIterator != NULL)
			delete (*mMAInformationGrpIterator);
			mMAInformationGrpIterator++;
		}
		delete mMAInformationGrpList;
	}
	if(mNetLocAccessSupport != NULL)
		delete mNetLocAccessSupport;
	if(mRATType != NULL)
		delete mRATType;
	if(mFlowsGrpList != NULL){
		mFlowsGrpIterator = mFlowsGrpList->begin();
		while(mFlowsGrpIterator != mFlowsGrpList->end()){
	if(*mFlowsGrpIterator != NULL)
			delete (*mFlowsGrpIterator);
			mFlowsGrpIterator++;
		}
		delete mFlowsGrpList;
	}
	if(mOCSupportedFeaturesGrp != NULL)
		delete mOCSupportedFeaturesGrp;
	if(mOCOLRGrp != NULL)
		delete mOCOLRGrp;
	if(mSupportedFeaturesGrpList != NULL){
		mSupportedFeaturesGrpIterator = mSupportedFeaturesGrpList->begin();
		while(mSupportedFeaturesGrpIterator != mSupportedFeaturesGrpList->end()){
	if(*mSupportedFeaturesGrpIterator != NULL)
			delete (*mSupportedFeaturesGrpIterator);
			mSupportedFeaturesGrpIterator++;
		}
		delete mSupportedFeaturesGrpList;
	}
	if(mSubscriptionIdGrpList != NULL){
		mSubscriptionIdGrpIterator = mSubscriptionIdGrpList->begin();
		while(mSubscriptionIdGrpIterator != mSubscriptionIdGrpList->end()){
	if(*mSubscriptionIdGrpIterator != NULL)
			delete (*mSubscriptionIdGrpIterator);
			mSubscriptionIdGrpIterator++;
		}
		delete mSubscriptionIdGrpList;
	}
	if(mUserEquipmentInfoGrp != NULL)
		delete mUserEquipmentInfoGrp;
	if(mUserEquipmentInfoExtensionGrp != NULL)
		delete mUserEquipmentInfoExtensionGrp;
	if(m3GPPSGSNMCCMNC != NULL)
		delete m3GPPSGSNMCCMNC;
	if(mNID != NULL)
		delete mNID;
	if(mClass != NULL)
		delete mClass;
	if(mErrorMessage != NULL)
		delete mErrorMessage;
	if(mErrorReportingHost != NULL)
		delete mErrorReportingHost;
	if(mFailedAVPGrpList != NULL){
		mFailedAVPGrpIterator = mFailedAVPGrpList->begin();
		while(mFailedAVPGrpIterator != mFailedAVPGrpList->end()){
	if(*mFailedAVPGrpIterator != NULL)
			delete (*mFailedAVPGrpIterator);
			mFailedAVPGrpIterator++;
		}
		delete mFailedAVPGrpList;
	}
	if(mRetryInterval != NULL)
		delete mRetryInterval;
	if(mOriginStateId != NULL)
		delete mOriginStateId;
	if(mRedirectHostList != NULL){
		mRedirectHostIterator = mRedirectHostList->begin();
		while(mRedirectHostIterator != mRedirectHostList->end()){
			delete (*mRedirectHostIterator);
			mRedirectHostIterator++;
		}
		delete mRedirectHostList;
	}
	if(mRedirectHostUsage != NULL)
		delete mRedirectHostUsage;
	if(mRedirectMaxCacheTime != NULL)
		delete mRedirectMaxCacheTime;
	if(mProxyInfoGrpList != NULL){
		mProxyInfoGrpIterator = mProxyInfoGrpList->begin();
		while(mProxyInfoGrpIterator != mProxyInfoGrpList->end()){
	if(*mProxyInfoGrpIterator != NULL)
			delete (*mProxyInfoGrpIterator);
			mProxyInfoGrpIterator++;
		}
		delete mProxyInfoGrpList;
	}
	if(mLoadGrpList != NULL){
		mLoadGrpIterator = mLoadGrpList->begin();
		while(mLoadGrpIterator != mLoadGrpList->end()){
	if(*mLoadGrpIterator != NULL)
			delete (*mLoadGrpIterator);
			mLoadGrpIterator++;
		}
		delete mLoadGrpList;
	}
}

OctetString* AAAnswer::setSessionId(){
	mMandatoryAvpSetVal [AAAnswer_SESSIONID] = 1;
	if(mSessionId == NULL)
	{
		mSessionId = new OctetString();
		mTagsPresent[AAAnswer_SESSIONID] = 1;
		return mSessionId;
	}
	return mSessionId;
}

void AAAnswer::resetSessionId(){
	mTagsPresent[AAAnswer_SESSIONID] = 0;
	if(mSessionId != NULL)
	{
		delete mSessionId; 
		mSessionId = NULL;
	}
}

DRMP* AAAnswer::setDRMP(){
	if(mDRMP == NULL)
	{
		mDRMP = new DRMP();
		mTagsPresent[AAAnswer_DRMP] = 1;
		return mDRMP;
	}
	return mDRMP;
}

void AAAnswer::resetDRMP(){
	mTagsPresent[AAAnswer_DRMP] = 0;
	if(mDRMP != NULL)
	{
		delete mDRMP; 
		mDRMP = NULL;
	}
}

Integer32* AAAnswer::setAuthApplicationId(){
	mMandatoryAvpSetVal [AAAnswer_AUTHAPPLICATIONID] = 1;
	if(mAuthApplicationId == NULL)
	{
		mAuthApplicationId = new Integer32();
		mTagsPresent[AAAnswer_AUTHAPPLICATIONID] = 1;
		return mAuthApplicationId;
	}
	return mAuthApplicationId;
}

void AAAnswer::resetAuthApplicationId(){
	mTagsPresent[AAAnswer_AUTHAPPLICATIONID] = 0;
	if(mAuthApplicationId != NULL)
	{
		delete mAuthApplicationId; 
		mAuthApplicationId = NULL;
	}
}

OctetString* AAAnswer::setOriginHost(){
	mMandatoryAvpSetVal [AAAnswer_ORIGINHOST] = 1;
	if(mOriginHost == NULL)
	{
		mOriginHost = new OctetString();
		mTagsPresent[AAAnswer_ORIGINHOST] = 1;
		return mOriginHost;
	}
	return mOriginHost;
}

void AAAnswer::resetOriginHost(){
	mTagsPresent[AAAnswer_ORIGINHOST] = 0;
	if(mOriginHost != NULL)
	{
		delete mOriginHost; 
		mOriginHost = NULL;
	}
}

OctetString* AAAnswer::setOriginRealm(){
	mMandatoryAvpSetVal [AAAnswer_ORIGINREALM] = 1;
	if(mOriginRealm == NULL)
	{
		mOriginRealm = new OctetString();
		mTagsPresent[AAAnswer_ORIGINREALM] = 1;
		return mOriginRealm;
	}
	return mOriginRealm;
}

void AAAnswer::resetOriginRealm(){
	mTagsPresent[AAAnswer_ORIGINREALM] = 0;
	if(mOriginRealm != NULL)
	{
		delete mOriginRealm; 
		mOriginRealm = NULL;
	}
}

Unsigned32* AAAnswer::setResultCode(){
	mMandatoryAvpSetVal [AAAnswer_RESULTCODE] = 1;
	if(mResultCode == NULL)
	{
		mResultCode = new Unsigned32();
		mTagsPresent[AAAnswer_RESULTCODE] = 1;
		return mResultCode;
	}
	return mResultCode;
}

void AAAnswer::resetResultCode(){
	mTagsPresent[AAAnswer_RESULTCODE] = 0;
	if(mResultCode != NULL)
	{
		delete mResultCode; 
		mResultCode = NULL;
	}
}

AuthSessionState* AAAnswer::setAuthSessionState(){
	if(mAuthSessionState == NULL)
	{
		mAuthSessionState = new AuthSessionState();
		mTagsPresent[AAAnswer_AUTHSESSIONSTATE] = 1;
		return mAuthSessionState;
	}
	return mAuthSessionState;
}

void AAAnswer::resetAuthSessionState(){
	mTagsPresent[AAAnswer_AUTHSESSIONSTATE] = 0;
	if(mAuthSessionState != NULL)
	{
		delete mAuthSessionState; 
		mAuthSessionState = NULL;
	}
}

Address* AAAnswer::setAccessNetworkChargingAddress(){
	mMandatoryAvpSetVal [AAAnswer_ACCESSNETWORKCHARGINGADDRESS] = 1;
	if(mAccessNetworkChargingAddress == NULL)
	{
		mAccessNetworkChargingAddress = new Address();
		mTagsPresent[AAAnswer_ACCESSNETWORKCHARGINGADDRESS] = 1;
		return mAccessNetworkChargingAddress;
	}
	return mAccessNetworkChargingAddress;
}

void AAAnswer::resetAccessNetworkChargingAddress(){
	mTagsPresent[AAAnswer_ACCESSNETWORKCHARGINGADDRESS] = 0;
	if(mAccessNetworkChargingAddress != NULL)
	{
		delete mAccessNetworkChargingAddress; 
		mAccessNetworkChargingAddress = NULL;
	}
}

ANTrusted* AAAnswer::setANTrusted(){
	mMandatoryAvpSetVal [AAAnswer_ANTRUSTED] = 1;
	if(mANTrusted == NULL)
	{
		mANTrusted = new ANTrusted();
		mTagsPresent[AAAnswer_ANTRUSTED] = 1;
		return mANTrusted;
	}
	return mANTrusted;
}

void AAAnswer::resetANTrusted(){
	mTagsPresent[AAAnswer_ANTRUSTED] = 0;
	if(mANTrusted != NULL)
	{
		delete mANTrusted; 
		mANTrusted = NULL;
	}
}

Unsigned32* AAAnswer::setServiceAuthorizationInfo(){
	if(mServiceAuthorizationInfo == NULL)
	{
		mServiceAuthorizationInfo = new Unsigned32();
		mTagsPresent[AAAnswer_SERVICEAUTHORIZATIONINFO] = 1;
		return mServiceAuthorizationInfo;
	}
	return mServiceAuthorizationInfo;
}

void AAAnswer::resetServiceAuthorizationInfo(){
	mTagsPresent[AAAnswer_SERVICEAUTHORIZATIONINFO] = 0;
	if(mServiceAuthorizationInfo != NULL)
	{
		delete mServiceAuthorizationInfo; 
		mServiceAuthorizationInfo = NULL;
	}
}

IPCANType* AAAnswer::setIPCANType(){
	mMandatoryAvpSetVal [AAAnswer_IPCANTYPE] = 1;
	if(mIPCANType == NULL)
	{
		mIPCANType = new IPCANType();
		mTagsPresent[AAAnswer_IPCANTYPE] = 1;
		return mIPCANType;
	}
	return mIPCANType;
}

void AAAnswer::resetIPCANType(){
	mTagsPresent[AAAnswer_IPCANTYPE] = 0;
	if(mIPCANType != NULL)
	{
		delete mIPCANType; 
		mIPCANType = NULL;
	}
}

Unsigned32* AAAnswer::setNetLocAccessSupport(){
	if(mNetLocAccessSupport == NULL)
	{
		mNetLocAccessSupport = new Unsigned32();
		mTagsPresent[AAAnswer_NETLOCACCESSSUPPORT] = 1;
		return mNetLocAccessSupport;
	}
	return mNetLocAccessSupport;
}

void AAAnswer::resetNetLocAccessSupport(){
	mTagsPresent[AAAnswer_NETLOCACCESSSUPPORT] = 0;
	if(mNetLocAccessSupport != NULL)
	{
		delete mNetLocAccessSupport; 
		mNetLocAccessSupport = NULL;
	}
}

Unsigned32* AAAnswer::setRATType(){
	if(mRATType == NULL)
	{
		mRATType = new Unsigned32();
		mTagsPresent[AAAnswer_RATTYPE] = 1;
		return mRATType;
	}
	return mRATType;
}

void AAAnswer::resetRATType(){
	mTagsPresent[AAAnswer_RATTYPE] = 0;
	if(mRATType != NULL)
	{
		delete mRATType; 
		mRATType = NULL;
	}
}

OctetString* AAAnswer::set3GPPSGSNMCCMNC(){
	if(m3GPPSGSNMCCMNC == NULL)
	{
		m3GPPSGSNMCCMNC = new OctetString();
		mTagsPresent[AAAnswer_3GPPSGSNMCCMNC] = 1;
		return m3GPPSGSNMCCMNC;
	}
	return m3GPPSGSNMCCMNC;
}

void AAAnswer::reset3GPPSGSNMCCMNC(){
	mTagsPresent[AAAnswer_3GPPSGSNMCCMNC] = 0;
	if(m3GPPSGSNMCCMNC != NULL)
	{
		delete m3GPPSGSNMCCMNC; 
		m3GPPSGSNMCCMNC = NULL;
	}
}

OctetString* AAAnswer::setNID(){
	if(mNID == NULL)
	{
		mNID = new OctetString();
		mTagsPresent[AAAnswer_NID] = 1;
		return mNID;
	}
	return mNID;
}

void AAAnswer::resetNID(){
	mTagsPresent[AAAnswer_NID] = 0;
	if(mNID != NULL)
	{
		delete mNID; 
		mNID = NULL;
	}
}

OctetString* AAAnswer::setClass(){
	mMandatoryAvpSetVal [AAAnswer_CLASS] = 1;
	if(mClass == NULL)
	{
		mClass = new OctetString();
		mTagsPresent[AAAnswer_CLASS] = 1;
		return mClass;
	}
	return mClass;
}

void AAAnswer::resetClass(){
	mTagsPresent[AAAnswer_CLASS] = 0;
	if(mClass != NULL)
	{
		delete mClass; 
		mClass = NULL;
	}
}

OctetString* AAAnswer::setErrorMessage(){
	if(mErrorMessage == NULL)
	{
		mErrorMessage = new OctetString();
		mTagsPresent[AAAnswer_ERRORMESSAGE] = 1;
		return mErrorMessage;
	}
	return mErrorMessage;
}

void AAAnswer::resetErrorMessage(){
	mTagsPresent[AAAnswer_ERRORMESSAGE] = 0;
	if(mErrorMessage != NULL)
	{
		delete mErrorMessage; 
		mErrorMessage = NULL;
	}
}

OctetString* AAAnswer::setErrorReportingHost(){
	mMandatoryAvpSetVal [AAAnswer_ERRORREPORTINGHOST] = 1;
	if(mErrorReportingHost == NULL)
	{
		mErrorReportingHost = new OctetString();
		mTagsPresent[AAAnswer_ERRORREPORTINGHOST] = 1;
		return mErrorReportingHost;
	}
	return mErrorReportingHost;
}

void AAAnswer::resetErrorReportingHost(){
	mTagsPresent[AAAnswer_ERRORREPORTINGHOST] = 0;
	if(mErrorReportingHost != NULL)
	{
		delete mErrorReportingHost; 
		mErrorReportingHost = NULL;
	}
}

Unsigned32* AAAnswer::setRetryInterval(){
	if(mRetryInterval == NULL)
	{
		mRetryInterval = new Unsigned32();
		mTagsPresent[AAAnswer_RETRYINTERVAL] = 1;
		return mRetryInterval;
	}
	return mRetryInterval;
}

void AAAnswer::resetRetryInterval(){
	mTagsPresent[AAAnswer_RETRYINTERVAL] = 0;
	if(mRetryInterval != NULL)
	{
		delete mRetryInterval; 
		mRetryInterval = NULL;
	}
}

Unsigned32* AAAnswer::setOriginStateId(){
	mMandatoryAvpSetVal [AAAnswer_ORIGINSTATEID] = 1;
	if(mOriginStateId == NULL)
	{
		mOriginStateId = new Unsigned32();
		mTagsPresent[AAAnswer_ORIGINSTATEID] = 1;
		return mOriginStateId;
	}
	return mOriginStateId;
}

void AAAnswer::resetOriginStateId(){
	mTagsPresent[AAAnswer_ORIGINSTATEID] = 0;
	if(mOriginStateId != NULL)
	{
		delete mOriginStateId; 
		mOriginStateId = NULL;
	}
}

RedirectHostUsage* AAAnswer::setRedirectHostUsage(){
	mMandatoryAvpSetVal [AAAnswer_REDIRECTHOSTUSAGE] = 1;
	if(mRedirectHostUsage == NULL)
	{
		mRedirectHostUsage = new RedirectHostUsage();
		mTagsPresent[AAAnswer_REDIRECTHOSTUSAGE] = 1;
		return mRedirectHostUsage;
	}
	return mRedirectHostUsage;
}

void AAAnswer::resetRedirectHostUsage(){
	mTagsPresent[AAAnswer_REDIRECTHOSTUSAGE] = 0;
	if(mRedirectHostUsage != NULL)
	{
		delete mRedirectHostUsage; 
		mRedirectHostUsage = NULL;
	}
}

Unsigned32* AAAnswer::setRedirectMaxCacheTime(){
	mMandatoryAvpSetVal [AAAnswer_REDIRECTMAXCACHETIME] = 1;
	if(mRedirectMaxCacheTime == NULL)
	{
		mRedirectMaxCacheTime = new Unsigned32();
		mTagsPresent[AAAnswer_REDIRECTMAXCACHETIME] = 1;
		return mRedirectMaxCacheTime;
	}
	return mRedirectMaxCacheTime;
}

void AAAnswer::resetRedirectMaxCacheTime(){
	mTagsPresent[AAAnswer_REDIRECTMAXCACHETIME] = 0;
	if(mRedirectMaxCacheTime != NULL)
	{
		delete mRedirectMaxCacheTime; 
		mRedirectMaxCacheTime = NULL;
	}
}

OctetString* AAAnswer::getSessionId(){
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

DRMP* AAAnswer::getDRMP(){
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

Integer32* AAAnswer::getAuthApplicationId(){
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

OctetString* AAAnswer::getOriginHost(){
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

OctetString* AAAnswer::getOriginRealm(){
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

Unsigned32* AAAnswer::getResultCode(){
	if(NULL == mResultCode) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ResultCode is Null");
		throw lTssDiaMsgException;
	}
	if(!mResultCode->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mResultCode->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ResultCode is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mResultCode->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mResultCode->Decode(mspByteArray.get(), mResultCode->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ResultCode")     ;
			throw lTssDiaMsgException;
		}
		mResultCode->mAvpDecodedFlag = true;
	}
	return mResultCode;
}

ExperimentalResult* AAAnswer::getExperimentalResult()
{
	if(mExperimentalResultGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExperimentalResult is Null");
		throw lTssDiaMsgException;
	}
	if(!mExperimentalResultGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mExperimentalResultGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExperimentalResult is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mExperimentalResultGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mExperimentalResultGrp->Decode(mspByteArray.get(), mExperimentalResultGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExperimentalResult")     ;
			throw lTssDiaMsgException;
		}
		mExperimentalResultGrp->mAvpDecodedFlag = true;
	}
	return mExperimentalResultGrp;
}

ExperimentalResult* AAAnswer::setExperimentalResult(){
	if(mExperimentalResultGrp == NULL)
		mExperimentalResultGrp = new ExperimentalResult();
	mTagsPresent[AAAnswer_EXPERIMENTALRESULT] = 1;
	mMandatoryAvpSetVal[AAAnswer_EXPERIMENTALRESULT] = 1;
	return mExperimentalResultGrp;
}

void AAAnswer::resetExperimentalResult(){
	mTagsPresent[AAAnswer_EXPERIMENTALRESULT] = 0;
	if(mExperimentalResultGrp != NULL)
		delete mExperimentalResultGrp;
}

AuthSessionState* AAAnswer::getAuthSessionState(){
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

list<AccessNetworkChargingIdentifier*>* AAAnswer::getAccessNetworkChargingIdentifierGrpList()
{
	if(mAccessNetworkChargingIdentifierGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AccessNetworkChargingIdentifier is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mAccessNetworkChargingIdentifierGrpList)
	{
		if(mAccessNetworkChargingIdentifierGrpList != NULL)
		{
		if(mAccessNetworkChargingIdentifierGrpList->size() == 0)
		{
			mTagsPresent[AAAnswer_ACCESSNETWORKCHARGINGIDENTIFIER] = 0;
			mAccessNetworkChargingIdentifierGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AccessNetworkChargingIdentifier is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AccessNetworkChargingIdentifier is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AccessNetworkChargingIdentifier")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mAccessNetworkChargingIdentifierGrpList;
}

list<AccessNetworkChargingIdentifier*>* AAAnswer::setAccessNetworkChargingIdentifierGrpList(){
	mTagsPresent[AAAnswer_ACCESSNETWORKCHARGINGIDENTIFIER] = 1;
	if(mAccessNetworkChargingIdentifierGrpList == NULL)
		mAccessNetworkChargingIdentifierGrpList = new list<AccessNetworkChargingIdentifier*>;
	mMandatoryAvpSetVal[AAAnswer_ACCESSNETWORKCHARGINGIDENTIFIER] = 1;
	mAccessNetworkChargingIdentifierGrpList->clear();
	return mAccessNetworkChargingIdentifierGrpList;
}

void AAAnswer::resetAccessNetworkChargingIdentifierGrpList(){
	mTagsPresent[AAAnswer_ACCESSNETWORKCHARGINGIDENTIFIER] = 0;
	if(mAccessNetworkChargingIdentifierGrpList != NULL)
		delete mAccessNetworkChargingIdentifierGrpList;
}

Address* AAAnswer::getAccessNetworkChargingAddress(){
	if(NULL == mAccessNetworkChargingAddress) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AccessNetworkChargingAddress is Null");
		throw lTssDiaMsgException;
	}
	if(!mAccessNetworkChargingAddress->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAccessNetworkChargingAddress->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AccessNetworkChargingAddress is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAccessNetworkChargingAddress->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAccessNetworkChargingAddress->Decode(mspByteArray.get(), mAccessNetworkChargingAddress->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AccessNetworkChargingAddress")     ;
			throw lTssDiaMsgException;
		}
		mAccessNetworkChargingAddress->mAvpDecodedFlag = true;
	}
	return mAccessNetworkChargingAddress;
}

AcceptableServiceInfo* AAAnswer::getAcceptableServiceInfo()
{
	if(mAcceptableServiceInfoGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AcceptableServiceInfo is Null");
		throw lTssDiaMsgException;
	}
	if(!mAcceptableServiceInfoGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAcceptableServiceInfoGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AcceptableServiceInfo is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAcceptableServiceInfoGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAcceptableServiceInfoGrp->Decode(mspByteArray.get(), mAcceptableServiceInfoGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AcceptableServiceInfo")     ;
			throw lTssDiaMsgException;
		}
		mAcceptableServiceInfoGrp->mAvpDecodedFlag = true;
	}
	return mAcceptableServiceInfoGrp;
}

AcceptableServiceInfo* AAAnswer::setAcceptableServiceInfo(){
	if(mAcceptableServiceInfoGrp == NULL)
		mAcceptableServiceInfoGrp = new AcceptableServiceInfo();
	mTagsPresent[AAAnswer_ACCEPTABLESERVICEINFO] = 1;
	mMandatoryAvpSetVal[AAAnswer_ACCEPTABLESERVICEINFO] = 1;
	return mAcceptableServiceInfoGrp;
}

void AAAnswer::resetAcceptableServiceInfo(){
	mTagsPresent[AAAnswer_ACCEPTABLESERVICEINFO] = 0;
	if(mAcceptableServiceInfoGrp != NULL)
		delete mAcceptableServiceInfoGrp;
}

list<Address*>* AAAnswer::getANGWAddressList()
{
	if(mANGWAddressList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ANGWAddress is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mANGWAddressList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ANGWAddress is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ANGWAddress")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mANGWAddressList;
}

list<Address*>* AAAnswer::setANGWAddressList() {
	mTagsPresent[AAAnswer_ANGWADDRESS] = 1;
	if(mANGWAddressList == NULL)
		mANGWAddressList = new list<Address*>;
	mANGWAddressList->clear();
	return mANGWAddressList;
}

void AAAnswer::resetANGWAddressList(){
	mTagsPresent[AAAnswer_ANGWADDRESS] = 0;
	if(mANGWAddressList != NULL)
		delete mANGWAddressList;
}

ANTrusted* AAAnswer::getANTrusted(){
	if(NULL == mANTrusted) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ANTrusted is Null");
		throw lTssDiaMsgException;
	}
	if(!mANTrusted->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mANTrusted->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ANTrusted is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mANTrusted->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mANTrusted->Decode(mspByteArray.get(), mANTrusted->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ANTrusted")     ;
			throw lTssDiaMsgException;
		}
		mANTrusted->mAvpDecodedFlag = true;
	}
	return mANTrusted;
}

Unsigned32* AAAnswer::getServiceAuthorizationInfo(){
	if(NULL == mServiceAuthorizationInfo) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ServiceAuthorizationInfo is Null");
		throw lTssDiaMsgException;
	}
	if(!mServiceAuthorizationInfo->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mServiceAuthorizationInfo->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ServiceAuthorizationInfo is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mServiceAuthorizationInfo->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mServiceAuthorizationInfo->Decode(mspByteArray.get(), mServiceAuthorizationInfo->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ServiceAuthorizationInfo")     ;
			throw lTssDiaMsgException;
		}
		mServiceAuthorizationInfo->mAvpDecodedFlag = true;
	}
	return mServiceAuthorizationInfo;
}

IPCANType* AAAnswer::getIPCANType(){
	if(NULL == mIPCANType) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "IPCANType is Null");
		throw lTssDiaMsgException;
	}
	if(!mIPCANType->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mIPCANType->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "IPCANType is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mIPCANType->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mIPCANType->Decode(mspByteArray.get(), mIPCANType->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding IPCANType")     ;
			throw lTssDiaMsgException;
		}
		mIPCANType->mAvpDecodedFlag = true;
	}
	return mIPCANType;
}

list<MAInformation*>* AAAnswer::getMAInformationGrpList()
{
	if(mMAInformationGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MAInformation is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mMAInformationGrpList)
	{
		if(mMAInformationGrpList != NULL)
		{
		if(mMAInformationGrpList->size() == 0)
		{
			mTagsPresent[AAAnswer_MAINFORMATION] = 0;
			mMAInformationGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MAInformation is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MAInformation is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MAInformation")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mMAInformationGrpList;
}

list<MAInformation*>* AAAnswer::setMAInformationGrpList(){
	mTagsPresent[AAAnswer_MAINFORMATION] = 1;
	if(mMAInformationGrpList == NULL)
		mMAInformationGrpList = new list<MAInformation*>;
	mMAInformationGrpList->clear();
	return mMAInformationGrpList;
}

void AAAnswer::resetMAInformationGrpList(){
	mTagsPresent[AAAnswer_MAINFORMATION] = 0;
	if(mMAInformationGrpList != NULL)
		delete mMAInformationGrpList;
}

Unsigned32* AAAnswer::getNetLocAccessSupport(){
	if(NULL == mNetLocAccessSupport) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "NetLocAccessSupport is Null");
		throw lTssDiaMsgException;
	}
	if(!mNetLocAccessSupport->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mNetLocAccessSupport->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "NetLocAccessSupport is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mNetLocAccessSupport->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mNetLocAccessSupport->Decode(mspByteArray.get(), mNetLocAccessSupport->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding NetLocAccessSupport")     ;
			throw lTssDiaMsgException;
		}
		mNetLocAccessSupport->mAvpDecodedFlag = true;
	}
	return mNetLocAccessSupport;
}

Unsigned32* AAAnswer::getRATType(){
	if(NULL == mRATType) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RATType is Null");
		throw lTssDiaMsgException;
	}
	if(!mRATType->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRATType->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RATType is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRATType->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRATType->Decode(mspByteArray.get(), mRATType->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RATType")     ;
			throw lTssDiaMsgException;
		}
		mRATType->mAvpDecodedFlag = true;
	}
	return mRATType;
}

list<Flows*>* AAAnswer::getFlowsGrpList()
{
	if(mFlowsGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Flows is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mFlowsGrpList)
	{
		if(mFlowsGrpList != NULL)
		{
		if(mFlowsGrpList->size() == 0)
		{
			mTagsPresent[AAAnswer_FLOWS] = 0;
			mFlowsGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Flows is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Flows is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Flows")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mFlowsGrpList;
}

list<Flows*>* AAAnswer::setFlowsGrpList(){
	mTagsPresent[AAAnswer_FLOWS] = 1;
	if(mFlowsGrpList == NULL)
		mFlowsGrpList = new list<Flows*>;
	mMandatoryAvpSetVal[AAAnswer_FLOWS] = 1;
	mFlowsGrpList->clear();
	return mFlowsGrpList;
}

void AAAnswer::resetFlowsGrpList(){
	mTagsPresent[AAAnswer_FLOWS] = 0;
	if(mFlowsGrpList != NULL)
		delete mFlowsGrpList;
}

OCSupportedFeatures* AAAnswer::getOCSupportedFeatures()
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

OCSupportedFeatures* AAAnswer::setOCSupportedFeatures(){
	if(mOCSupportedFeaturesGrp == NULL)
		mOCSupportedFeaturesGrp = new OCSupportedFeatures();
	mTagsPresent[AAAnswer_OCSUPPORTEDFEATURES] = 1;
	return mOCSupportedFeaturesGrp;
}

void AAAnswer::resetOCSupportedFeatures(){
	mTagsPresent[AAAnswer_OCSUPPORTEDFEATURES] = 0;
	if(mOCSupportedFeaturesGrp != NULL)
		delete mOCSupportedFeaturesGrp;
}

OCOLR* AAAnswer::getOCOLR()
{
	if(mOCOLRGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OCOLR is Null");
		throw lTssDiaMsgException;
	}
	if(!mOCOLRGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mOCOLRGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OCOLR is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mOCOLRGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mOCOLRGrp->Decode(mspByteArray.get(), mOCOLRGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OCOLR")     ;
			throw lTssDiaMsgException;
		}
		mOCOLRGrp->mAvpDecodedFlag = true;
	}
	return mOCOLRGrp;
}

OCOLR* AAAnswer::setOCOLR(){
	if(mOCOLRGrp == NULL)
		mOCOLRGrp = new OCOLR();
	mTagsPresent[AAAnswer_OCOLR] = 1;
	return mOCOLRGrp;
}

void AAAnswer::resetOCOLR(){
	mTagsPresent[AAAnswer_OCOLR] = 0;
	if(mOCOLRGrp != NULL)
		delete mOCOLRGrp;
}

list<SupportedFeatures*>* AAAnswer::getSupportedFeaturesGrpList()
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
			mTagsPresent[AAAnswer_SUPPORTEDFEATURES] = 0;
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

list<SupportedFeatures*>* AAAnswer::setSupportedFeaturesGrpList(){
	mTagsPresent[AAAnswer_SUPPORTEDFEATURES] = 1;
	if(mSupportedFeaturesGrpList == NULL)
		mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
	mMandatoryAvpSetVal[AAAnswer_SUPPORTEDFEATURES] = 1;
	mSupportedFeaturesGrpList->clear();
	return mSupportedFeaturesGrpList;
}

void AAAnswer::resetSupportedFeaturesGrpList(){
	mTagsPresent[AAAnswer_SUPPORTEDFEATURES] = 0;
	if(mSupportedFeaturesGrpList != NULL)
		delete mSupportedFeaturesGrpList;
}

list<SubscriptionId*>* AAAnswer::getSubscriptionIdGrpList()
{
	if(mSubscriptionIdGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SubscriptionId is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mSubscriptionIdGrpList)
	{
		if(mSubscriptionIdGrpList != NULL)
		{
		if(mSubscriptionIdGrpList->size() == 0)
		{
			mTagsPresent[AAAnswer_SUBSCRIPTIONID] = 0;
			mSubscriptionIdGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SubscriptionId is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SubscriptionId is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SubscriptionId")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mSubscriptionIdGrpList;
}

list<SubscriptionId*>* AAAnswer::setSubscriptionIdGrpList(){
	mTagsPresent[AAAnswer_SUBSCRIPTIONID] = 1;
	if(mSubscriptionIdGrpList == NULL)
		mSubscriptionIdGrpList = new list<SubscriptionId*>;
	mMandatoryAvpSetVal[AAAnswer_SUBSCRIPTIONID] = 1;
	mSubscriptionIdGrpList->clear();
	return mSubscriptionIdGrpList;
}

void AAAnswer::resetSubscriptionIdGrpList(){
	mTagsPresent[AAAnswer_SUBSCRIPTIONID] = 0;
	if(mSubscriptionIdGrpList != NULL)
		delete mSubscriptionIdGrpList;
}

UserEquipmentInfo* AAAnswer::getUserEquipmentInfo()
{
	if(mUserEquipmentInfoGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserEquipmentInfo is Null");
		throw lTssDiaMsgException;
	}
	if(!mUserEquipmentInfoGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUserEquipmentInfoGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserEquipmentInfo is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUserEquipmentInfoGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUserEquipmentInfoGrp->Decode(mspByteArray.get(), mUserEquipmentInfoGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfo")     ;
			throw lTssDiaMsgException;
		}
		mUserEquipmentInfoGrp->mAvpDecodedFlag = true;
	}
	return mUserEquipmentInfoGrp;
}

UserEquipmentInfo* AAAnswer::setUserEquipmentInfo(){
	if(mUserEquipmentInfoGrp == NULL)
		mUserEquipmentInfoGrp = new UserEquipmentInfo();
	mTagsPresent[AAAnswer_USEREQUIPMENTINFO] = 1;
	return mUserEquipmentInfoGrp;
}

void AAAnswer::resetUserEquipmentInfo(){
	mTagsPresent[AAAnswer_USEREQUIPMENTINFO] = 0;
	if(mUserEquipmentInfoGrp != NULL)
		delete mUserEquipmentInfoGrp;
}

UserEquipmentInfoExtension* AAAnswer::getUserEquipmentInfoExtension()
{
	if(mUserEquipmentInfoExtensionGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserEquipmentInfoExtension is Null");
		throw lTssDiaMsgException;
	}
	if(!mUserEquipmentInfoExtensionGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUserEquipmentInfoExtensionGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserEquipmentInfoExtension is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUserEquipmentInfoExtensionGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUserEquipmentInfoExtensionGrp->Decode(mspByteArray.get(), mUserEquipmentInfoExtensionGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfoExtension")     ;
			throw lTssDiaMsgException;
		}
		mUserEquipmentInfoExtensionGrp->mAvpDecodedFlag = true;
	}
	return mUserEquipmentInfoExtensionGrp;
}

UserEquipmentInfoExtension* AAAnswer::setUserEquipmentInfoExtension(){
	if(mUserEquipmentInfoExtensionGrp == NULL)
		mUserEquipmentInfoExtensionGrp = new UserEquipmentInfoExtension();
	mTagsPresent[AAAnswer_USEREQUIPMENTINFOEXTENSION] = 1;
	return mUserEquipmentInfoExtensionGrp;
}

void AAAnswer::resetUserEquipmentInfoExtension(){
	mTagsPresent[AAAnswer_USEREQUIPMENTINFOEXTENSION] = 0;
	if(mUserEquipmentInfoExtensionGrp != NULL)
		delete mUserEquipmentInfoExtensionGrp;
}

OctetString* AAAnswer::get3GPPSGSNMCCMNC(){
	if(NULL == m3GPPSGSNMCCMNC) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPSGSNMCCMNC is Null");
		throw lTssDiaMsgException;
	}
	if(!m3GPPSGSNMCCMNC->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			m3GPPSGSNMCCMNC->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPSGSNMCCMNC is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = m3GPPSGSNMCCMNC->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(m3GPPSGSNMCCMNC->Decode(mspByteArray.get(), m3GPPSGSNMCCMNC->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPSGSNMCCMNC")     ;
			throw lTssDiaMsgException;
		}
		m3GPPSGSNMCCMNC->mAvpDecodedFlag = true;
	}
	return m3GPPSGSNMCCMNC;
}

OctetString* AAAnswer::getNID(){
	if(NULL == mNID) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "NID is Null");
		throw lTssDiaMsgException;
	}
	if(!mNID->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mNID->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "NID is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mNID->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mNID->Decode(mspByteArray.get(), mNID->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding NID")     ;
			throw lTssDiaMsgException;
		}
		mNID->mAvpDecodedFlag = true;
	}
	return mNID;
}

OctetString* AAAnswer::getClass(){
	if(NULL == mClass) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Class is Null");
		throw lTssDiaMsgException;
	}
	if(!mClass->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mClass->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Class is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mClass->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mClass->Decode(mspByteArray.get(), mClass->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Class")     ;
			throw lTssDiaMsgException;
		}
		mClass->mAvpDecodedFlag = true;
	}
	return mClass;
}

OctetString* AAAnswer::getErrorMessage(){
	if(NULL == mErrorMessage) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ErrorMessage is Null");
		throw lTssDiaMsgException;
	}
	if(!mErrorMessage->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mErrorMessage->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ErrorMessage is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mErrorMessage->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mErrorMessage->Decode(mspByteArray.get(), mErrorMessage->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ErrorMessage")     ;
			throw lTssDiaMsgException;
		}
		mErrorMessage->mAvpDecodedFlag = true;
	}
	return mErrorMessage;
}

OctetString* AAAnswer::getErrorReportingHost(){
	if(NULL == mErrorReportingHost) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ErrorReportingHost is Null");
		throw lTssDiaMsgException;
	}
	if(!mErrorReportingHost->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mErrorReportingHost->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ErrorReportingHost is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mErrorReportingHost->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mErrorReportingHost->Decode(mspByteArray.get(), mErrorReportingHost->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ErrorReportingHost")     ;
			throw lTssDiaMsgException;
		}
		mErrorReportingHost->mAvpDecodedFlag = true;
	}
	return mErrorReportingHost;
}

list<FailedAVP*>* AAAnswer::getFailedAVPGrpList()
{
	if(mFailedAVPGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FailedAVP is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mFailedAVPGrpList)
	{
		if(mFailedAVPGrpList != NULL)
		{
		if(mFailedAVPGrpList->size() == 0)
		{
			mTagsPresent[AAAnswer_FAILEDAVP] = 0;
			mFailedAVPGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FailedAVP is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FailedAVP is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FailedAVP")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mFailedAVPGrpList;
}

list<FailedAVP*>* AAAnswer::setFailedAVPGrpList(){
	mTagsPresent[AAAnswer_FAILEDAVP] = 1;
	if(mFailedAVPGrpList == NULL)
		mFailedAVPGrpList = new list<FailedAVP*>;
	mMandatoryAvpSetVal[AAAnswer_FAILEDAVP] = 1;
	mFailedAVPGrpList->clear();
	return mFailedAVPGrpList;
}

void AAAnswer::resetFailedAVPGrpList(){
	mTagsPresent[AAAnswer_FAILEDAVP] = 0;
	if(mFailedAVPGrpList != NULL)
		delete mFailedAVPGrpList;
}

Unsigned32* AAAnswer::getRetryInterval(){
	if(NULL == mRetryInterval) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RetryInterval is Null");
		throw lTssDiaMsgException;
	}
	if(!mRetryInterval->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRetryInterval->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RetryInterval is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRetryInterval->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRetryInterval->Decode(mspByteArray.get(), mRetryInterval->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RetryInterval")     ;
			throw lTssDiaMsgException;
		}
		mRetryInterval->mAvpDecodedFlag = true;
	}
	return mRetryInterval;
}

Unsigned32* AAAnswer::getOriginStateId(){
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

list<OctetString*>* AAAnswer::getRedirectHostList()
{
	if(mRedirectHostList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectHost is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mRedirectHostList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectHost is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectHost")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mRedirectHostList;
}

list<OctetString*>* AAAnswer::setRedirectHostList() {
	mTagsPresent[AAAnswer_REDIRECTHOST] = 1;
	if(mRedirectHostList == NULL)
		mRedirectHostList = new list<OctetString*>;
	mMandatoryAvpSetVal [AAAnswer_REDIRECTHOST] = 1;
	mRedirectHostList->clear();
	return mRedirectHostList;
}

void AAAnswer::resetRedirectHostList(){
	mTagsPresent[AAAnswer_REDIRECTHOST] = 0;
	if(mRedirectHostList != NULL)
		delete mRedirectHostList;
}

RedirectHostUsage* AAAnswer::getRedirectHostUsage(){
	if(NULL == mRedirectHostUsage) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectHostUsage is Null");
		throw lTssDiaMsgException;
	}
	if(!mRedirectHostUsage->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRedirectHostUsage->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectHostUsage is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRedirectHostUsage->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRedirectHostUsage->Decode(mspByteArray.get(), mRedirectHostUsage->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectHostUsage")     ;
			throw lTssDiaMsgException;
		}
		mRedirectHostUsage->mAvpDecodedFlag = true;
	}
	return mRedirectHostUsage;
}

Unsigned32* AAAnswer::getRedirectMaxCacheTime(){
	if(NULL == mRedirectMaxCacheTime) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectMaxCacheTime is Null");
		throw lTssDiaMsgException;
	}
	if(!mRedirectMaxCacheTime->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRedirectMaxCacheTime->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectMaxCacheTime is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRedirectMaxCacheTime->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRedirectMaxCacheTime->Decode(mspByteArray.get(), mRedirectMaxCacheTime->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectMaxCacheTime")     ;
			throw lTssDiaMsgException;
		}
		mRedirectMaxCacheTime->mAvpDecodedFlag = true;
	}
	return mRedirectMaxCacheTime;
}

list<RX::ProxyInfo*>* AAAnswer::getProxyInfoGrpList()
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
			mTagsPresent[AAAnswer_PROXYINFO] = 0;
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

list<RX::ProxyInfo*>* AAAnswer::setProxyInfoGrpList(){
	mTagsPresent[AAAnswer_PROXYINFO] = 1;
	if(mProxyInfoGrpList == NULL)
		mProxyInfoGrpList = new list<RX::ProxyInfo*>;
	mMandatoryAvpSetVal[AAAnswer_PROXYINFO] = 1;
	mProxyInfoGrpList->clear();
	return mProxyInfoGrpList;
}

void AAAnswer::resetProxyInfoGrpList(){
	mTagsPresent[AAAnswer_PROXYINFO] = 0;
	if(mProxyInfoGrpList != NULL)
		delete mProxyInfoGrpList;
}

list<Load*>* AAAnswer::getLoadGrpList()
{
	if(mLoadGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Load is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mLoadGrpList)
	{
		if(mLoadGrpList != NULL)
		{
		if(mLoadGrpList->size() == 0)
		{
			mTagsPresent[AAAnswer_LOAD] = 0;
			mLoadGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Load is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Load is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Load")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mLoadGrpList;
}

list<Load*>* AAAnswer::setLoadGrpList(){
	mTagsPresent[AAAnswer_LOAD] = 1;
	if(mLoadGrpList == NULL)
		mLoadGrpList = new list<Load*>;
	mMandatoryAvpSetVal[AAAnswer_LOAD] = 1;
	mLoadGrpList->clear();
	return mLoadGrpList;
}

void AAAnswer::resetLoadGrpList(){
	mTagsPresent[AAAnswer_LOAD] = 0;
	if(mLoadGrpList != NULL)
		delete mLoadGrpList;
}



int AAAnswer::Encode(byteArray *array)
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
	array->byte[array->offset++] = (265>>16) & 0xFF;
	array->byte[array->offset++] = (265>>8) & 0xFF;
	array->byte[array->offset++] = (265) & 0xFF;
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
			case AAAnswer_SESSIONID:
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
			case AAAnswer_DRMP:
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
			case AAAnswer_AUTHAPPLICATIONID:
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
			case AAAnswer_ORIGINHOST:
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
			case AAAnswer_ORIGINREALM:
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
			case AAAnswer_RESULTCODE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(268);
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
					if(!mResultCode->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mResultCode->getAvpOffsetLen().first], mResultCode->getAvpOffsetLen().second);
						array->offset += mResultCode->getAvpOffsetLen().second;
						array->size += mResultCode->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ResultCode");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mResultCode->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ResultCode");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AAAnswer_EXPERIMENTALRESULT:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(297);
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
				if((this->getExperimentalResult()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExperimentalResult");
					throw lTssDiaMsgException;
					}
				}
				break;
			case AAAnswer_AUTHSESSIONSTATE:
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
			case AAAnswer_ACCESSNETWORKCHARGINGIDENTIFIER:
			{
				if( mAccessNetworkChargingIdentifierGrpList->size() <= 0) {
					break;
				}

				mAccessNetworkChargingIdentifierGrpIterator = this->getAccessNetworkChargingIdentifierGrpList()->begin();
				while(mAccessNetworkChargingIdentifierGrpIterator != mAccessNetworkChargingIdentifierGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(502);
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
					if(((*mAccessNetworkChargingIdentifierGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AccessNetworkChargingIdentifier");
						throw lTssDiaMsgException;
					}
					
					mAccessNetworkChargingIdentifierGrpIterator++;
				}
				}
				break;
			case AAAnswer_ACCESSNETWORKCHARGINGADDRESS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(501);
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
					if(!mAccessNetworkChargingAddress->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAccessNetworkChargingAddress->getAvpOffsetLen().first], mAccessNetworkChargingAddress->getAvpOffsetLen().second);
						array->offset += mAccessNetworkChargingAddress->getAvpOffsetLen().second;
						array->size += mAccessNetworkChargingAddress->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mAccessNetworkChargingAddress->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mAccessNetworkChargingAddress->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array,TSS_MAX_DIAMETER_TIME_LEN)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AccessNetworkChargingAddress");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mAccessNetworkChargingAddress->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mAccessNetworkChargingAddress->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AccessNetworkChargingAddress");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AAAnswer_ACCEPTABLESERVICEINFO:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(526);
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
				if((this->getAcceptableServiceInfo()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AcceptableServiceInfo");
					throw lTssDiaMsgException;
					}
				}
				break;
			case AAAnswer_ANGWADDRESS:
			{
					if( mANGWAddressList->size() <= 0) {
						break;
					}

					mANGWAddressIterator = this->getANGWAddressList()->begin();
					while(mANGWAddressIterator != mANGWAddressList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(1050);
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
					if(!(*mANGWAddressIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mANGWAddressIterator)->getAvpOffsetLen().first], (*mANGWAddressIterator)->getAvpOffsetLen().second);
						array->offset += (*mANGWAddressIterator)->getAvpOffsetLen().second;
						array->size += (*mANGWAddressIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mANGWAddressIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mANGWAddressIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array,TSS_MAX_DIAMETER_TIME_LEN)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ANGWAddress");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mANGWAddressIterator++;
						continue;
					}
						if(((*mANGWAddressIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mANGWAddressIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ANGWAddress");
							throw lTssDiaMsgException;
						}
						mANGWAddressIterator++;
				}
				}
				break;
			case AAAnswer_ANTRUSTED:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1503);
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
					if(!mANTrusted->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mANTrusted->getAvpOffsetLen().first], mANTrusted->getAvpOffsetLen().second);
						array->offset += mANTrusted->getAvpOffsetLen().second;
						array->size += mANTrusted->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ANTrusted");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mANTrusted->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ANTrusted");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AAAnswer_SERVICEAUTHORIZATIONINFO:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(548);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 160;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(160))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mServiceAuthorizationInfo->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mServiceAuthorizationInfo->getAvpOffsetLen().first], mServiceAuthorizationInfo->getAvpOffsetLen().second);
						array->offset += mServiceAuthorizationInfo->getAvpOffsetLen().second;
						array->size += mServiceAuthorizationInfo->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ServiceAuthorizationInfo");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mServiceAuthorizationInfo->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ServiceAuthorizationInfo");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AAAnswer_IPCANTYPE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1027);
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
					if(!mIPCANType->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mIPCANType->getAvpOffsetLen().first], mIPCANType->getAvpOffsetLen().second);
						array->offset += mIPCANType->getAvpOffsetLen().second;
						array->size += mIPCANType->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding IPCANType");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mIPCANType->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding IPCANType");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AAAnswer_MAINFORMATION:
			{
				if( mMAInformationGrpList->size() <= 0) {
					break;
				}

				mMAInformationGrpIterator = this->getMAInformationGrpList()->begin();
				while(mMAInformationGrpIterator != mMAInformationGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(570);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 160;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(160))
						{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(((*mMAInformationGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MAInformation");
						throw lTssDiaMsgException;
					}
					
					mMAInformationGrpIterator++;
				}
				}
				break;
			case AAAnswer_NETLOCACCESSSUPPORT:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2824);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 160;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(160))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mNetLocAccessSupport->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mNetLocAccessSupport->getAvpOffsetLen().first], mNetLocAccessSupport->getAvpOffsetLen().second);
						array->offset += mNetLocAccessSupport->getAvpOffsetLen().second;
						array->size += mNetLocAccessSupport->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding NetLocAccessSupport");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mNetLocAccessSupport->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding NetLocAccessSupport");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AAAnswer_RATTYPE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1032);
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
					if(!mRATType->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRATType->getAvpOffsetLen().first], mRATType->getAvpOffsetLen().second);
						array->offset += mRATType->getAvpOffsetLen().second;
						array->size += mRATType->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RATType");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mRATType->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RATType");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AAAnswer_FLOWS:
			{
				if( mFlowsGrpList->size() <= 0) {
					break;
				}

				mFlowsGrpIterator = this->getFlowsGrpList()->begin();
				while(mFlowsGrpIterator != mFlowsGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(510);
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
					if(((*mFlowsGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Flows");
						throw lTssDiaMsgException;
					}
					
					mFlowsGrpIterator++;
				}
				}
				break;
			case AAAnswer_OCSUPPORTEDFEATURES:
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
			case AAAnswer_OCOLR:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(623);
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
				if((this->getOCOLR()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OCOLR");
					throw lTssDiaMsgException;
					}
				}
				break;
			case AAAnswer_SUPPORTEDFEATURES:
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
					if(((*mSupportedFeaturesGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SupportedFeatures");
						throw lTssDiaMsgException;
					}
					
					mSupportedFeaturesGrpIterator++;
				}
				}
				break;
			case AAAnswer_SUBSCRIPTIONID:
			{
				if( mSubscriptionIdGrpList->size() <= 0) {
					break;
				}

				mSubscriptionIdGrpIterator = this->getSubscriptionIdGrpList()->begin();
				while(mSubscriptionIdGrpIterator != mSubscriptionIdGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(443);
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
					if(((*mSubscriptionIdGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SubscriptionId");
						throw lTssDiaMsgException;
					}
					
					mSubscriptionIdGrpIterator++;
				}
				}
				break;
			case AAAnswer_USEREQUIPMENTINFO:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(458);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
				array->size++;
				array->byte[array->offset++] = 32;
				lengthOffset = array->offset; 
				array->offset += 3; 
				array->size += 3; 
				if( true == DiameterTLVUtil::isVenderSpecific(32))
 						{ 
						INT32 venderId=10415;
					array->size+=4;
					lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
						array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
				} 
				if((this->getUserEquipmentInfo()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserEquipmentInfo");
					throw lTssDiaMsgException;
					}
				}
				break;
			case AAAnswer_USEREQUIPMENTINFOEXTENSION:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(653);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
				array->size++;
				array->byte[array->offset++] = 32;
				lengthOffset = array->offset; 
				array->offset += 3; 
				array->size += 3; 
				if( true == DiameterTLVUtil::isVenderSpecific(32))
 						{ 
						INT32 venderId=10415;
					array->size+=4;
					lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
						array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
				} 
				if((this->getUserEquipmentInfoExtension()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserEquipmentInfoExtension");
					throw lTssDiaMsgException;
					}
				}
				break;
			case AAAnswer_3GPPSGSNMCCMNC:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(18);
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
					if(!m3GPPSGSNMCCMNC->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[m3GPPSGSNMCCMNC->getAvpOffsetLen().first], m3GPPSGSNMCCMNC->getAvpOffsetLen().second);
						array->offset += m3GPPSGSNMCCMNC->getAvpOffsetLen().second;
						array->size += m3GPPSGSNMCCMNC->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( m3GPPSGSNMCCMNC->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(m3GPPSGSNMCCMNC->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPSGSNMCCMNC");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((m3GPPSGSNMCCMNC->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, m3GPPSGSNMCCMNC->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPSGSNMCCMNC");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AAAnswer_NID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(569);
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
					if(!mNID->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mNID->getAvpOffsetLen().first], mNID->getAvpOffsetLen().second);
						array->offset += mNID->getAvpOffsetLen().second;
						array->size += mNID->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mNID->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mNID->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding NID");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mNID->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mNID->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding NID");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AAAnswer_CLASS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(25);
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
					if(!mClass->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mClass->getAvpOffsetLen().first], mClass->getAvpOffsetLen().second);
						array->offset += mClass->getAvpOffsetLen().second;
						array->size += mClass->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mClass->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mClass->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Class");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mClass->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mClass->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Class");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AAAnswer_ERRORMESSAGE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(281);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 32;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(32))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mErrorMessage->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mErrorMessage->getAvpOffsetLen().first], mErrorMessage->getAvpOffsetLen().second);
						array->offset += mErrorMessage->getAvpOffsetLen().second;
						array->size += mErrorMessage->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mErrorMessage->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mErrorMessage->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ErrorMessage");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mErrorMessage->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mErrorMessage->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ErrorMessage");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AAAnswer_ERRORREPORTINGHOST:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(294);
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
					if(!mErrorReportingHost->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mErrorReportingHost->getAvpOffsetLen().first], mErrorReportingHost->getAvpOffsetLen().second);
						array->offset += mErrorReportingHost->getAvpOffsetLen().second;
						array->size += mErrorReportingHost->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mErrorReportingHost->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mErrorReportingHost->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ErrorReportingHost");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mErrorReportingHost->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mErrorReportingHost->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ErrorReportingHost");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AAAnswer_FAILEDAVP:
			{
				if( mFailedAVPGrpList->size() <= 0) {
					break;
				}

				mFailedAVPGrpIterator = this->getFailedAVPGrpList()->begin();
				while(mFailedAVPGrpIterator != mFailedAVPGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(279);
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
					if(((*mFailedAVPGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FailedAVP");
						throw lTssDiaMsgException;
					}
					
					mFailedAVPGrpIterator++;
				}
				}
				break;
			case AAAnswer_RETRYINTERVAL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(541);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 160;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(160))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mRetryInterval->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRetryInterval->getAvpOffsetLen().first], mRetryInterval->getAvpOffsetLen().second);
						array->offset += mRetryInterval->getAvpOffsetLen().second;
						array->size += mRetryInterval->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RetryInterval");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mRetryInterval->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RetryInterval");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AAAnswer_ORIGINSTATEID:
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
			case AAAnswer_REDIRECTHOST:
			{
					if( mRedirectHostList->size() <= 0) {
						break;
					}

					mRedirectHostIterator = this->getRedirectHostList()->begin();
					while(mRedirectHostIterator != mRedirectHostList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(292);
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
					if(!(*mRedirectHostIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mRedirectHostIterator)->getAvpOffsetLen().first], (*mRedirectHostIterator)->getAvpOffsetLen().second);
						array->offset += (*mRedirectHostIterator)->getAvpOffsetLen().second;
						array->size += (*mRedirectHostIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mRedirectHostIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mRedirectHostIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RedirectHost");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mRedirectHostIterator++;
						continue;
					}
						if(((*mRedirectHostIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mRedirectHostIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RedirectHost");
							throw lTssDiaMsgException;
						}
						mRedirectHostIterator++;
				}
				}
				break;
			case AAAnswer_REDIRECTHOSTUSAGE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(261);
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
					if(!mRedirectHostUsage->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRedirectHostUsage->getAvpOffsetLen().first], mRedirectHostUsage->getAvpOffsetLen().second);
						array->offset += mRedirectHostUsage->getAvpOffsetLen().second;
						array->size += mRedirectHostUsage->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RedirectHostUsage");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mRedirectHostUsage->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RedirectHostUsage");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AAAnswer_REDIRECTMAXCACHETIME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(262);
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
					if(!mRedirectMaxCacheTime->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRedirectMaxCacheTime->getAvpOffsetLen().first], mRedirectMaxCacheTime->getAvpOffsetLen().second);
						array->offset += mRedirectMaxCacheTime->getAvpOffsetLen().second;
						array->size += mRedirectMaxCacheTime->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RedirectMaxCacheTime");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mRedirectMaxCacheTime->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RedirectMaxCacheTime");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AAAnswer_PROXYINFO:
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
			case AAAnswer_LOAD:
			{
				if( mLoadGrpList->size() <= 0) {
					break;
				}

				mLoadGrpIterator = this->getLoadGrpList()->begin();
				while(mLoadGrpIterator != mLoadGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(650);
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
					if(((*mLoadGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Load");
						throw lTssDiaMsgException;
					}
					
					mLoadGrpIterator++;
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


int AAAnswer::Decode(byteArray *array, INT16 lMLen, UINT16 *parsedBytes)
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
						mMandatoryAvpSetVal [AAAnswer_SESSIONID] = 1;
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
						mMandatoryAvpSetVal [AAAnswer_AUTHAPPLICATIONID] = 1;
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
						mMandatoryAvpSetVal [AAAnswer_ORIGINHOST] = 1;
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
						mMandatoryAvpSetVal [AAAnswer_ORIGINREALM] = 1;
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
			case 268:
				{
						mMandatoryAvpSetVal [AAAnswer_RESULTCODE] = 1;
					if( NULL == this->setResultCode())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ResultCode");
						throw lTssDiaMsgException;
					}
					mResultCode->setAvpCode(268);
					mResultCode->setAvpVendorId(lVenderId);
					mResultCode->SetDataType((DiameterDataType)3);
					mResultCode->mspByteArray = mspByteArray;
					mResultCode->mAvpDecodedFlag = false;
					mResultCode->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 297:
				{
						mMandatoryAvpSetVal [AAAnswer_EXPERIMENTALRESULT] = 1;
					mTagsPresent[AAAnswer_EXPERIMENTALRESULT] = 1;
						if( NULL == this->setExperimentalResult()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExperimentalResult");
						throw lTssDiaMsgException;
						}
					mExperimentalResultGrp->setAvpCode(297);
					mExperimentalResultGrp->SetDataType((DiameterDataType)6);
					mExperimentalResultGrp->mspByteArray = mspByteArray;
					mExperimentalResultGrp->mAvpDecodedFlag = false;
					mExperimentalResultGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mExperimentalResultGrp);
					array->offset+=lAvpDataLen;

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
			case 502:
				{
						mMandatoryAvpSetVal [AAAnswer_ACCESSNETWORKCHARGINGIDENTIFIER] = 1;
					mTagsPresent[AAAnswer_ACCESSNETWORKCHARGINGIDENTIFIER] = 1;
					AccessNetworkChargingIdentifier *lAccessNetworkChargingIdentifier = new AccessNetworkChargingIdentifier();
					if( lAccessNetworkChargingIdentifier == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AccessNetworkChargingIdentifier");
						throw lTssDiaMsgException;
					}
					lAccessNetworkChargingIdentifier->setAvpCode(502);
					lAccessNetworkChargingIdentifier->SetDataType((DiameterDataType)6);
					lAccessNetworkChargingIdentifier->mspByteArray = mspByteArray;
					lAccessNetworkChargingIdentifier->mAvpDecodedFlag = false;
					lAccessNetworkChargingIdentifier->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mAccessNetworkChargingIdentifierGrpList == NULL)
						this->setAccessNetworkChargingIdentifierGrpList();
					mAccessNetworkChargingIdentifierGrpList->push_back(lAccessNetworkChargingIdentifier);
					mBaseInterfaceList.push_back(lAccessNetworkChargingIdentifier);
					
				}
				break;
			case 501:
				{
						mMandatoryAvpSetVal [AAAnswer_ACCESSNETWORKCHARGINGADDRESS] = 1;
					if( NULL == this->setAccessNetworkChargingAddress())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AccessNetworkChargingAddress");
						throw lTssDiaMsgException;
					}
					mAccessNetworkChargingAddress->setAvpCode(501);
					mAccessNetworkChargingAddress->setAvpVendorId(lVenderId);
					mAccessNetworkChargingAddress->SetDataType((DiameterDataType)8);
					mAccessNetworkChargingAddress->mspByteArray = mspByteArray;
					mAccessNetworkChargingAddress->mAvpDecodedFlag = false;
					mAccessNetworkChargingAddress->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 526:
				{
						mMandatoryAvpSetVal [AAAnswer_ACCEPTABLESERVICEINFO] = 1;
					mTagsPresent[AAAnswer_ACCEPTABLESERVICEINFO] = 1;
						if( NULL == this->setAcceptableServiceInfo()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AcceptableServiceInfo");
						throw lTssDiaMsgException;
						}
					mAcceptableServiceInfoGrp->setAvpCode(526);
					mAcceptableServiceInfoGrp->SetDataType((DiameterDataType)6);
					mAcceptableServiceInfoGrp->mspByteArray = mspByteArray;
					mAcceptableServiceInfoGrp->mAvpDecodedFlag = false;
					mAcceptableServiceInfoGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mAcceptableServiceInfoGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1050:
				{
					mTagsPresent[AAAnswer_ANGWADDRESS] = 1;
					Address *lANGWAddress = new Address();
					if( lANGWAddress == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ANGWAddress");
						throw lTssDiaMsgException;
					}
					lANGWAddress->setAvpCode(1050);
					lANGWAddress->setAvpVendorId(lVenderId);
					lANGWAddress->SetDataType((DiameterDataType)8);
					lANGWAddress->mspByteArray = mspByteArray;
					lANGWAddress->mAvpDecodedFlag = false;
					lANGWAddress->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mANGWAddressList == NULL)
						this->setANGWAddressList();
					mANGWAddressList->push_back(lANGWAddress);
					
				}
				break;
			case 1503:
				{
						mMandatoryAvpSetVal [AAAnswer_ANTRUSTED] = 1;
					if( NULL == this->setANTrusted())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ANTrusted");
						throw lTssDiaMsgException;
					}
					mANTrusted->setAvpCode(1503);
					mANTrusted->setAvpVendorId(lVenderId);
					mANTrusted->SetDataType((DiameterDataType)7);
					mANTrusted->mspByteArray = mspByteArray;
					mANTrusted->mAvpDecodedFlag = false;
					mANTrusted->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 548:
				{
					if( NULL == this->setServiceAuthorizationInfo())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ServiceAuthorizationInfo");
						throw lTssDiaMsgException;
					}
					mServiceAuthorizationInfo->setAvpCode(548);
					mServiceAuthorizationInfo->setAvpVendorId(lVenderId);
					mServiceAuthorizationInfo->SetDataType((DiameterDataType)3);
					mServiceAuthorizationInfo->mspByteArray = mspByteArray;
					mServiceAuthorizationInfo->mAvpDecodedFlag = false;
					mServiceAuthorizationInfo->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1027:
				{
						mMandatoryAvpSetVal [AAAnswer_IPCANTYPE] = 1;
					if( NULL == this->setIPCANType())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding IPCANType");
						throw lTssDiaMsgException;
					}
					mIPCANType->setAvpCode(1027);
					mIPCANType->setAvpVendorId(lVenderId);
					mIPCANType->SetDataType((DiameterDataType)7);
					mIPCANType->mspByteArray = mspByteArray;
					mIPCANType->mAvpDecodedFlag = false;
					mIPCANType->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 570:
				{
					mTagsPresent[AAAnswer_MAINFORMATION] = 1;
					MAInformation *lMAInformation = new MAInformation();
					if( lMAInformation == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MAInformation");
						throw lTssDiaMsgException;
					}
					lMAInformation->setAvpCode(570);
					lMAInformation->SetDataType((DiameterDataType)6);
					lMAInformation->mspByteArray = mspByteArray;
					lMAInformation->mAvpDecodedFlag = false;
					lMAInformation->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mMAInformationGrpList == NULL)
						this->setMAInformationGrpList();
					mMAInformationGrpList->push_back(lMAInformation);
					mBaseInterfaceList.push_back(lMAInformation);
					
				}
				break;
			case 2824:
				{
					if( NULL == this->setNetLocAccessSupport())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding NetLocAccessSupport");
						throw lTssDiaMsgException;
					}
					mNetLocAccessSupport->setAvpCode(2824);
					mNetLocAccessSupport->setAvpVendorId(lVenderId);
					mNetLocAccessSupport->SetDataType((DiameterDataType)3);
					mNetLocAccessSupport->mspByteArray = mspByteArray;
					mNetLocAccessSupport->mAvpDecodedFlag = false;
					mNetLocAccessSupport->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1032:
				{
					if( NULL == this->setRATType())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RATType");
						throw lTssDiaMsgException;
					}
					mRATType->setAvpCode(1032);
					mRATType->setAvpVendorId(lVenderId);
					mRATType->SetDataType((DiameterDataType)3);
					mRATType->mspByteArray = mspByteArray;
					mRATType->mAvpDecodedFlag = false;
					mRATType->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 510:
				{
						mMandatoryAvpSetVal [AAAnswer_FLOWS] = 1;
					mTagsPresent[AAAnswer_FLOWS] = 1;
					Flows *lFlows = new Flows();
					if( lFlows == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Flows");
						throw lTssDiaMsgException;
					}
					lFlows->setAvpCode(510);
					lFlows->SetDataType((DiameterDataType)6);
					lFlows->mspByteArray = mspByteArray;
					lFlows->mAvpDecodedFlag = false;
					lFlows->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mFlowsGrpList == NULL)
						this->setFlowsGrpList();
					mFlowsGrpList->push_back(lFlows);
					mBaseInterfaceList.push_back(lFlows);
					
				}
				break;
			case 621:
				{
					mTagsPresent[AAAnswer_OCSUPPORTEDFEATURES] = 1;
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
			case 623:
				{
					mTagsPresent[AAAnswer_OCOLR] = 1;
						if( NULL == this->setOCOLR()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OCOLR");
						throw lTssDiaMsgException;
						}
					mOCOLRGrp->setAvpCode(623);
					mOCOLRGrp->SetDataType((DiameterDataType)6);
					mOCOLRGrp->mspByteArray = mspByteArray;
					mOCOLRGrp->mAvpDecodedFlag = false;
					mOCOLRGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mOCOLRGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			case 628:
				{
						mMandatoryAvpSetVal [AAAnswer_SUPPORTEDFEATURES] = 1;
					mTagsPresent[AAAnswer_SUPPORTEDFEATURES] = 1;
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
			case 443:
				{
						mMandatoryAvpSetVal [AAAnswer_SUBSCRIPTIONID] = 1;
					mTagsPresent[AAAnswer_SUBSCRIPTIONID] = 1;
					SubscriptionId *lSubscriptionId = new SubscriptionId();
					if( lSubscriptionId == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SubscriptionId");
						throw lTssDiaMsgException;
					}
					lSubscriptionId->setAvpCode(443);
					lSubscriptionId->SetDataType((DiameterDataType)6);
					lSubscriptionId->mspByteArray = mspByteArray;
					lSubscriptionId->mAvpDecodedFlag = false;
					lSubscriptionId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mSubscriptionIdGrpList == NULL)
						this->setSubscriptionIdGrpList();
					mSubscriptionIdGrpList->push_back(lSubscriptionId);
					mBaseInterfaceList.push_back(lSubscriptionId);
					
				}
				break;
			case 458:
				{
					mTagsPresent[AAAnswer_USEREQUIPMENTINFO] = 1;
						if( NULL == this->setUserEquipmentInfo()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfo");
						throw lTssDiaMsgException;
						}
					mUserEquipmentInfoGrp->setAvpCode(458);
					mUserEquipmentInfoGrp->SetDataType((DiameterDataType)6);
					mUserEquipmentInfoGrp->mspByteArray = mspByteArray;
					mUserEquipmentInfoGrp->mAvpDecodedFlag = false;
					mUserEquipmentInfoGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mUserEquipmentInfoGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			case 653:
				{
					mTagsPresent[AAAnswer_USEREQUIPMENTINFOEXTENSION] = 1;
						if( NULL == this->setUserEquipmentInfoExtension()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfoExtension");
						throw lTssDiaMsgException;
						}
					mUserEquipmentInfoExtensionGrp->setAvpCode(653);
					mUserEquipmentInfoExtensionGrp->SetDataType((DiameterDataType)6);
					mUserEquipmentInfoExtensionGrp->mspByteArray = mspByteArray;
					mUserEquipmentInfoExtensionGrp->mAvpDecodedFlag = false;
					mUserEquipmentInfoExtensionGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mUserEquipmentInfoExtensionGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			case 18:
				{
					if( NULL == this->set3GPPSGSNMCCMNC())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPSGSNMCCMNC");
						throw lTssDiaMsgException;
					}
					m3GPPSGSNMCCMNC->setAvpCode(18);
					m3GPPSGSNMCCMNC->setAvpVendorId(lVenderId);
					m3GPPSGSNMCCMNC->SetDataType((DiameterDataType)5);
					m3GPPSGSNMCCMNC->mspByteArray = mspByteArray;
					m3GPPSGSNMCCMNC->mAvpDecodedFlag = false;
					m3GPPSGSNMCCMNC->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 569:
				{
					if( NULL == this->setNID())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding NID");
						throw lTssDiaMsgException;
					}
					mNID->setAvpCode(569);
					mNID->setAvpVendorId(lVenderId);
					mNID->SetDataType((DiameterDataType)5);
					mNID->mspByteArray = mspByteArray;
					mNID->mAvpDecodedFlag = false;
					mNID->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 25:
				{
						mMandatoryAvpSetVal [AAAnswer_CLASS] = 1;
					if( NULL == this->setClass())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Class");
						throw lTssDiaMsgException;
					}
					mClass->setAvpCode(25);
					mClass->setAvpVendorId(lVenderId);
					mClass->SetDataType((DiameterDataType)5);
					mClass->mspByteArray = mspByteArray;
					mClass->mAvpDecodedFlag = false;
					mClass->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 281:
				{
					if( NULL == this->setErrorMessage())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ErrorMessage");
						throw lTssDiaMsgException;
					}
					mErrorMessage->setAvpCode(281);
					mErrorMessage->setAvpVendorId(lVenderId);
					mErrorMessage->SetDataType((DiameterDataType)5);
					mErrorMessage->mspByteArray = mspByteArray;
					mErrorMessage->mAvpDecodedFlag = false;
					mErrorMessage->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 294:
				{
						mMandatoryAvpSetVal [AAAnswer_ERRORREPORTINGHOST] = 1;
					if( NULL == this->setErrorReportingHost())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ErrorReportingHost");
						throw lTssDiaMsgException;
					}
					mErrorReportingHost->setAvpCode(294);
					mErrorReportingHost->setAvpVendorId(lVenderId);
					mErrorReportingHost->SetDataType((DiameterDataType)5);
					mErrorReportingHost->mspByteArray = mspByteArray;
					mErrorReportingHost->mAvpDecodedFlag = false;
					mErrorReportingHost->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 279:
				{
						mMandatoryAvpSetVal [AAAnswer_FAILEDAVP] = 1;
					mTagsPresent[AAAnswer_FAILEDAVP] = 1;
					FailedAVP *lFailedAVP = new FailedAVP();
					if( lFailedAVP == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FailedAVP");
						throw lTssDiaMsgException;
					}
					lFailedAVP->setAvpCode(279);
					lFailedAVP->SetDataType((DiameterDataType)6);
					lFailedAVP->mspByteArray = mspByteArray;
					lFailedAVP->mAvpDecodedFlag = false;
					lFailedAVP->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mFailedAVPGrpList == NULL)
						this->setFailedAVPGrpList();
					mFailedAVPGrpList->push_back(lFailedAVP);
					mBaseInterfaceList.push_back(lFailedAVP);
					
				}
				break;
			case 541:
				{
					if( NULL == this->setRetryInterval())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RetryInterval");
						throw lTssDiaMsgException;
					}
					mRetryInterval->setAvpCode(541);
					mRetryInterval->setAvpVendorId(lVenderId);
					mRetryInterval->SetDataType((DiameterDataType)3);
					mRetryInterval->mspByteArray = mspByteArray;
					mRetryInterval->mAvpDecodedFlag = false;
					mRetryInterval->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 278:
				{
						mMandatoryAvpSetVal [AAAnswer_ORIGINSTATEID] = 1;
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
			case 292:
				{
						mMandatoryAvpSetVal [AAAnswer_REDIRECTHOST] = 1;
					mTagsPresent[AAAnswer_REDIRECTHOST] = 1;
					OctetString *lRedirectHost = new OctetString();
					if( lRedirectHost == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectHost");
						throw lTssDiaMsgException;
					}
					lRedirectHost->setAvpCode(292);
					lRedirectHost->setAvpVendorId(lVenderId);
					lRedirectHost->SetDataType((DiameterDataType)5);
					lRedirectHost->mspByteArray = mspByteArray;
					lRedirectHost->mAvpDecodedFlag = false;
					lRedirectHost->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mRedirectHostList == NULL)
						this->setRedirectHostList();
					mRedirectHostList->push_back(lRedirectHost);
					
				}
				break;
			case 261:
				{
						mMandatoryAvpSetVal [AAAnswer_REDIRECTHOSTUSAGE] = 1;
					if( NULL == this->setRedirectHostUsage())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectHostUsage");
						throw lTssDiaMsgException;
					}
					mRedirectHostUsage->setAvpCode(261);
					mRedirectHostUsage->setAvpVendorId(lVenderId);
					mRedirectHostUsage->SetDataType((DiameterDataType)7);
					mRedirectHostUsage->mspByteArray = mspByteArray;
					mRedirectHostUsage->mAvpDecodedFlag = false;
					mRedirectHostUsage->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 262:
				{
						mMandatoryAvpSetVal [AAAnswer_REDIRECTMAXCACHETIME] = 1;
					if( NULL == this->setRedirectMaxCacheTime())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectMaxCacheTime");
						throw lTssDiaMsgException;
					}
					mRedirectMaxCacheTime->setAvpCode(262);
					mRedirectMaxCacheTime->setAvpVendorId(lVenderId);
					mRedirectMaxCacheTime->SetDataType((DiameterDataType)3);
					mRedirectMaxCacheTime->mspByteArray = mspByteArray;
					mRedirectMaxCacheTime->mAvpDecodedFlag = false;
					mRedirectMaxCacheTime->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 284:
				{
						mMandatoryAvpSetVal [AAAnswer_PROXYINFO] = 1;
					mTagsPresent[AAAnswer_PROXYINFO] = 1;
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
			case 650:
				{
						mMandatoryAvpSetVal [AAAnswer_LOAD] = 1;
					mTagsPresent[AAAnswer_LOAD] = 1;
					Load *lLoad = new Load();
					if( lLoad == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Load");
						throw lTssDiaMsgException;
					}
					lLoad->setAvpCode(650);
					lLoad->SetDataType((DiameterDataType)6);
					lLoad->mspByteArray = mspByteArray;
					lLoad->mAvpDecodedFlag = false;
					lLoad->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mLoadGrpList == NULL)
						this->setLoadGrpList();
					mLoadGrpList->push_back(lLoad);
					mBaseInterfaceList.push_back(lLoad);
					
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


DiameterBaseInterface* AAAnswer::Find(byteArray *array, UINT32 avpCode)
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
			case 268:
			{
				if(mResultCode != NULL)
					return mResultCode->Find(array, avpCode);
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
			case 501:
			{
				if(mAccessNetworkChargingAddress != NULL)
					return mAccessNetworkChargingAddress->Find(array, avpCode);
				else
					return NULL;
			}
			case 1050:
			{
				if(mANGWAddressList != NULL && mANGWAddressList->size() > 0)
					return (mANGWAddressList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 1503:
			{
				if(mANTrusted != NULL)
					return mANTrusted->Find(array, avpCode);
				else
					return NULL;
			}
			case 548:
			{
				if(mServiceAuthorizationInfo != NULL)
					return mServiceAuthorizationInfo->Find(array, avpCode);
				else
					return NULL;
			}
			case 1027:
			{
				if(mIPCANType != NULL)
					return mIPCANType->Find(array, avpCode);
				else
					return NULL;
			}
			case 2824:
			{
				if(mNetLocAccessSupport != NULL)
					return mNetLocAccessSupport->Find(array, avpCode);
				else
					return NULL;
			}
			case 1032:
			{
				if(mRATType != NULL)
					return mRATType->Find(array, avpCode);
				else
					return NULL;
			}
			case 18:
			{
				if(m3GPPSGSNMCCMNC != NULL)
					return m3GPPSGSNMCCMNC->Find(array, avpCode);
				else
					return NULL;
			}
			case 569:
			{
				if(mNID != NULL)
					return mNID->Find(array, avpCode);
				else
					return NULL;
			}
			case 25:
			{
				if(mClass != NULL)
					return mClass->Find(array, avpCode);
				else
					return NULL;
			}
			case 281:
			{
				if(mErrorMessage != NULL)
					return mErrorMessage->Find(array, avpCode);
				else
					return NULL;
			}
			case 294:
			{
				if(mErrorReportingHost != NULL)
					return mErrorReportingHost->Find(array, avpCode);
				else
					return NULL;
			}
			case 541:
			{
				if(mRetryInterval != NULL)
					return mRetryInterval->Find(array, avpCode);
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
			case 292:
			{
				if(mRedirectHostList != NULL && mRedirectHostList->size() > 0)
					return (mRedirectHostList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 261:
			{
				if(mRedirectHostUsage != NULL)
					return mRedirectHostUsage->Find(array, avpCode);
				else
					return NULL;
			}
			case 262:
			{
				if(mRedirectMaxCacheTime != NULL)
					return mRedirectMaxCacheTime->Find(array, avpCode);
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


BOOLEAN AAAnswer::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
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
			case 268:
			{
				if(mResultCode != NULL)
				{
					DiameterBaseInterface* inf =  mResultCode->Find(this->mspByteArray.get(), avpCode);
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
			case 297:
			{
				if(mExperimentalResultGrp != NULL)
				{
						pBaseInterface.push_back(mExperimentalResultGrp);
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
			case 502:
			{
				if(mAccessNetworkChargingIdentifierGrpList != NULL)
				{
					for(auto itr = mAccessNetworkChargingIdentifierGrpList->begin(); itr != mAccessNetworkChargingIdentifierGrpList->end(); ++itr)
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
			case 501:
			{
				if(mAccessNetworkChargingAddress != NULL)
				{
					DiameterBaseInterface* inf =  mAccessNetworkChargingAddress->Find(this->mspByteArray.get(), avpCode);
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
			case 526:
			{
				if(mAcceptableServiceInfoGrp != NULL)
				{
						pBaseInterface.push_back(mAcceptableServiceInfoGrp);
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
			case 1050:
			{
				if(mANGWAddressList != NULL)
				{
					for(auto itr = mANGWAddressList->begin(); itr != mANGWAddressList->end(); ++itr)
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
			case 1503:
			{
				if(mANTrusted != NULL)
				{
					DiameterBaseInterface* inf =  mANTrusted->Find(this->mspByteArray.get(), avpCode);
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
			case 548:
			{
				if(mServiceAuthorizationInfo != NULL)
				{
					DiameterBaseInterface* inf =  mServiceAuthorizationInfo->Find(this->mspByteArray.get(), avpCode);
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
			case 1027:
			{
				if(mIPCANType != NULL)
				{
					DiameterBaseInterface* inf =  mIPCANType->Find(this->mspByteArray.get(), avpCode);
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
			case 570:
			{
				if(mMAInformationGrpList != NULL)
				{
					for(auto itr = mMAInformationGrpList->begin(); itr != mMAInformationGrpList->end(); ++itr)
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
			case 2824:
			{
				if(mNetLocAccessSupport != NULL)
				{
					DiameterBaseInterface* inf =  mNetLocAccessSupport->Find(this->mspByteArray.get(), avpCode);
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
			case 1032:
			{
				if(mRATType != NULL)
				{
					DiameterBaseInterface* inf =  mRATType->Find(this->mspByteArray.get(), avpCode);
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
			case 510:
			{
				if(mFlowsGrpList != NULL)
				{
					for(auto itr = mFlowsGrpList->begin(); itr != mFlowsGrpList->end(); ++itr)
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
			case 623:
			{
				if(mOCOLRGrp != NULL)
				{
						pBaseInterface.push_back(mOCOLRGrp);
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
			case 443:
			{
				if(mSubscriptionIdGrpList != NULL)
				{
					for(auto itr = mSubscriptionIdGrpList->begin(); itr != mSubscriptionIdGrpList->end(); ++itr)
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
			case 458:
			{
				if(mUserEquipmentInfoGrp != NULL)
				{
						pBaseInterface.push_back(mUserEquipmentInfoGrp);
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
			case 653:
			{
				if(mUserEquipmentInfoExtensionGrp != NULL)
				{
						pBaseInterface.push_back(mUserEquipmentInfoExtensionGrp);
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
			case 18:
			{
				if(m3GPPSGSNMCCMNC != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPSGSNMCCMNC->Find(this->mspByteArray.get(), avpCode);
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
			case 569:
			{
				if(mNID != NULL)
				{
					DiameterBaseInterface* inf =  mNID->Find(this->mspByteArray.get(), avpCode);
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
			case 25:
			{
				if(mClass != NULL)
				{
					DiameterBaseInterface* inf =  mClass->Find(this->mspByteArray.get(), avpCode);
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
			case 281:
			{
				if(mErrorMessage != NULL)
				{
					DiameterBaseInterface* inf =  mErrorMessage->Find(this->mspByteArray.get(), avpCode);
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
			case 294:
			{
				if(mErrorReportingHost != NULL)
				{
					DiameterBaseInterface* inf =  mErrorReportingHost->Find(this->mspByteArray.get(), avpCode);
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
			case 279:
			{
				if(mFailedAVPGrpList != NULL)
				{
					for(auto itr = mFailedAVPGrpList->begin(); itr != mFailedAVPGrpList->end(); ++itr)
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
			case 541:
			{
				if(mRetryInterval != NULL)
				{
					DiameterBaseInterface* inf =  mRetryInterval->Find(this->mspByteArray.get(), avpCode);
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
			case 292:
			{
				if(mRedirectHostList != NULL)
				{
					for(auto itr = mRedirectHostList->begin(); itr != mRedirectHostList->end(); ++itr)
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
			case 261:
			{
				if(mRedirectHostUsage != NULL)
				{
					DiameterBaseInterface* inf =  mRedirectHostUsage->Find(this->mspByteArray.get(), avpCode);
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
			case 262:
			{
				if(mRedirectMaxCacheTime != NULL)
				{
					DiameterBaseInterface* inf =  mRedirectMaxCacheTime->Find(this->mspByteArray.get(), avpCode);
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
			case 650:
			{
				if(mLoadGrpList != NULL)
				{
					for(auto itr = mLoadGrpList->begin(); itr != mLoadGrpList->end(); ++itr)
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
std::shared_ptr<byteArray> AAAnswer::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN AAAnswer::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
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
			case 268:
			{
				if(mResultCode != NULL)
				{
					DiameterBaseInterface* inf =  mResultCode->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 297:
			{
				if(mExperimentalResultGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mExperimentalResultGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mExperimentalResultGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
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
			case 502:
			{
				if(mAccessNetworkChargingIdentifierGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mAccessNetworkChargingIdentifierGrpList->begin(); itr != mAccessNetworkChargingIdentifierGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mAccessNetworkChargingIdentifierGrpList->begin(); itr != mAccessNetworkChargingIdentifierGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 501:
			{
				if(mAccessNetworkChargingAddress != NULL)
				{
					DiameterBaseInterface* inf =  mAccessNetworkChargingAddress->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 526:
			{
				if(mAcceptableServiceInfoGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mAcceptableServiceInfoGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mAcceptableServiceInfoGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
				}
				}
				break;
			}
			case 1050:
			{
				if(mANGWAddressList != NULL)
				{
					for(auto itr = mANGWAddressList->begin(); itr != mANGWAddressList->end(); ++itr)
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
			case 1503:
			{
				if(mANTrusted != NULL)
				{
					DiameterBaseInterface* inf =  mANTrusted->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 548:
			{
				if(mServiceAuthorizationInfo != NULL)
				{
					DiameterBaseInterface* inf =  mServiceAuthorizationInfo->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1027:
			{
				if(mIPCANType != NULL)
				{
					DiameterBaseInterface* inf =  mIPCANType->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 570:
			{
				if(mMAInformationGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mMAInformationGrpList->begin(); itr != mMAInformationGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mMAInformationGrpList->begin(); itr != mMAInformationGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 2824:
			{
				if(mNetLocAccessSupport != NULL)
				{
					DiameterBaseInterface* inf =  mNetLocAccessSupport->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1032:
			{
				if(mRATType != NULL)
				{
					DiameterBaseInterface* inf =  mRATType->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 510:
			{
				if(mFlowsGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mFlowsGrpList->begin(); itr != mFlowsGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mFlowsGrpList->begin(); itr != mFlowsGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
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
			case 623:
			{
				if(mOCOLRGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mOCOLRGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mOCOLRGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
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
			case 443:
			{
				if(mSubscriptionIdGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mSubscriptionIdGrpList->begin(); itr != mSubscriptionIdGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mSubscriptionIdGrpList->begin(); itr != mSubscriptionIdGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 458:
			{
				if(mUserEquipmentInfoGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mUserEquipmentInfoGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mUserEquipmentInfoGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
				}
				}
				break;
			}
			case 653:
			{
				if(mUserEquipmentInfoExtensionGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mUserEquipmentInfoExtensionGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mUserEquipmentInfoExtensionGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
				}
				}
				break;
			}
			case 18:
			{
				if(m3GPPSGSNMCCMNC != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPSGSNMCCMNC->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 569:
			{
				if(mNID != NULL)
				{
					DiameterBaseInterface* inf =  mNID->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 25:
			{
				if(mClass != NULL)
				{
					DiameterBaseInterface* inf =  mClass->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 281:
			{
				if(mErrorMessage != NULL)
				{
					DiameterBaseInterface* inf =  mErrorMessage->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 294:
			{
				if(mErrorReportingHost != NULL)
				{
					DiameterBaseInterface* inf =  mErrorReportingHost->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 279:
			{
				if(mFailedAVPGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mFailedAVPGrpList->begin(); itr != mFailedAVPGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mFailedAVPGrpList->begin(); itr != mFailedAVPGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 541:
			{
				if(mRetryInterval != NULL)
				{
					DiameterBaseInterface* inf =  mRetryInterval->Find(this->mspByteArray.get(), avpCode);
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
			case 292:
			{
				if(mRedirectHostList != NULL)
				{
					for(auto itr = mRedirectHostList->begin(); itr != mRedirectHostList->end(); ++itr)
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
			case 261:
			{
				if(mRedirectHostUsage != NULL)
				{
					DiameterBaseInterface* inf =  mRedirectHostUsage->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 262:
			{
				if(mRedirectMaxCacheTime != NULL)
				{
					DiameterBaseInterface* inf =  mRedirectMaxCacheTime->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
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
			case 650:
			{
				if(mLoadGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mLoadGrpList->begin(); itr != mLoadGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mLoadGrpList->begin(); itr != mLoadGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
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




void AAAnswer::Display(UINT32 tab)
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
			case AAAnswer_SESSIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "263" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SessionId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getSessionId()->Display(tab+1);
			}
				break;
			case AAAnswer_DRMP:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "301" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DRMP" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getDRMP()->Display(tab+1);
			}
				break;
			case AAAnswer_AUTHAPPLICATIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "258" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AuthApplicationId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getAuthApplicationId()->Display(tab+1);
			}
				break;
			case AAAnswer_ORIGINHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "264" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginHost()->Display(tab+1);
			}
				break;
			case AAAnswer_ORIGINREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "296" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginRealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginRealm()->Display(tab+1);
			}
				break;
			case AAAnswer_RESULTCODE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "268" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ResultCode" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getResultCode()->Display(tab+1);
			}
				break;
			case AAAnswer_EXPERIMENTALRESULT:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "297" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ExperimentalResult" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getExperimentalResult()->Display(tab+1);
			}
				break;
			case AAAnswer_AUTHSESSIONSTATE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "277" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AuthSessionState" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getAuthSessionState()->Display(tab+1);
			}
				break;
			case AAAnswer_ACCESSNETWORKCHARGINGIDENTIFIER:
			{
				if( mAccessNetworkChargingIdentifierGrpList->size() <= 0) {
					break;
				}

				mAccessNetworkChargingIdentifierGrpIterator = this->getAccessNetworkChargingIdentifierGrpList()->begin();
				while(mAccessNetworkChargingIdentifierGrpIterator != this->getAccessNetworkChargingIdentifierGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "502" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AccessNetworkChargingIdentifier" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mAccessNetworkChargingIdentifierGrpIterator)->Display(tab+1);
					mAccessNetworkChargingIdentifierGrpIterator++;

				};

			}
				break;
			case AAAnswer_ACCESSNETWORKCHARGINGADDRESS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "501" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AccessNetworkChargingAddress" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getAccessNetworkChargingAddress()->Display(tab+1);
			}
				break;
			case AAAnswer_ACCEPTABLESERVICEINFO:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "526" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AcceptableServiceInfo" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getAcceptableServiceInfo()->Display(tab+1);
			}
				break;
			case AAAnswer_ANGWADDRESS:
			{
				if( mANGWAddressList->size() <= 0) {
					break;
				}

				mANGWAddressIterator = this->getANGWAddressList()->begin();
				while(mANGWAddressIterator != this->getANGWAddressList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1050" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ANGWAddress" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mANGWAddressIterator)->Display(tab+1);
					mANGWAddressIterator++;

				};

			}
				break;
			case AAAnswer_ANTRUSTED:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1503" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ANTrusted" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getANTrusted()->Display(tab+1);
			}
				break;
			case AAAnswer_SERVICEAUTHORIZATIONINFO:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "548" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ServiceAuthorizationInfo" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getServiceAuthorizationInfo()->Display(tab+1);
			}
				break;
			case AAAnswer_IPCANTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1027" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "IPCANType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getIPCANType()->Display(tab+1);
			}
				break;
			case AAAnswer_MAINFORMATION:
			{
				if( mMAInformationGrpList->size() <= 0) {
					break;
				}

				mMAInformationGrpIterator = this->getMAInformationGrpList()->begin();
				while(mMAInformationGrpIterator != this->getMAInformationGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "570" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MAInformation" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
					(*mMAInformationGrpIterator)->Display(tab+1);
					mMAInformationGrpIterator++;

				};

			}
				break;
			case AAAnswer_NETLOCACCESSSUPPORT:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2824" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "NetLocAccessSupport" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getNetLocAccessSupport()->Display(tab+1);
			}
				break;
			case AAAnswer_RATTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1032" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RATType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getRATType()->Display(tab+1);
			}
				break;
			case AAAnswer_FLOWS:
			{
				if( mFlowsGrpList->size() <= 0) {
					break;
				}

				mFlowsGrpIterator = this->getFlowsGrpList()->begin();
				while(mFlowsGrpIterator != this->getFlowsGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "510" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "Flows" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mFlowsGrpIterator)->Display(tab+1);
					mFlowsGrpIterator++;

				};

			}
				break;
			case AAAnswer_OCSUPPORTEDFEATURES:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "621" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OCSupportedFeatures" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getOCSupportedFeatures()->Display(tab+1);
			}
				break;
			case AAAnswer_OCOLR:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "623" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OCOLR" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getOCOLR()->Display(tab+1);
			}
				break;
			case AAAnswer_SUPPORTEDFEATURES:
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
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mSupportedFeaturesGrpIterator)->Display(tab+1);
					mSupportedFeaturesGrpIterator++;

				};

			}
				break;
			case AAAnswer_SUBSCRIPTIONID:
			{
				if( mSubscriptionIdGrpList->size() <= 0) {
					break;
				}

				mSubscriptionIdGrpIterator = this->getSubscriptionIdGrpList()->begin();
				while(mSubscriptionIdGrpIterator != this->getSubscriptionIdGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "443" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SubscriptionId" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
					(*mSubscriptionIdGrpIterator)->Display(tab+1);
					mSubscriptionIdGrpIterator++;

				};

			}
				break;
			case AAAnswer_USEREQUIPMENTINFO:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "458" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserEquipmentInfo" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(32)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(32)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(32)==true)?"Protected":""));
				this->getUserEquipmentInfo()->Display(tab+1);
			}
				break;
			case AAAnswer_USEREQUIPMENTINFOEXTENSION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "653" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserEquipmentInfoExtension" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(32)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(32)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(32)==true)?"Protected":""));
				this->getUserEquipmentInfoExtension()->Display(tab+1);
			}
				break;
			case AAAnswer_3GPPSGSNMCCMNC:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "18" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPPSGSNMCCMNC" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->get3GPPSGSNMCCMNC()->Display(tab+1);
			}
				break;
			case AAAnswer_NID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "569" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "NID" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getNID()->Display(tab+1);
			}
				break;
			case AAAnswer_CLASS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "25" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "Class" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getClass()->Display(tab+1);
			}
				break;
			case AAAnswer_ERRORMESSAGE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "281" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ErrorMessage" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(32)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(32)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(32)==true)?"Protected":""));
				this->getErrorMessage()->Display(tab+1);
			}
				break;
			case AAAnswer_ERRORREPORTINGHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "294" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ErrorReportingHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getErrorReportingHost()->Display(tab+1);
			}
				break;
			case AAAnswer_FAILEDAVP:
			{
				if( mFailedAVPGrpList->size() <= 0) {
					break;
				}

				mFailedAVPGrpIterator = this->getFailedAVPGrpList()->begin();
				while(mFailedAVPGrpIterator != this->getFailedAVPGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "279" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FailedAVP" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
					(*mFailedAVPGrpIterator)->Display(tab+1);
					mFailedAVPGrpIterator++;

				};

			}
				break;
			case AAAnswer_RETRYINTERVAL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "541" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RetryInterval" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getRetryInterval()->Display(tab+1);
			}
				break;
			case AAAnswer_ORIGINSTATEID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "278" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginStateId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginStateId()->Display(tab+1);
			}
				break;
			case AAAnswer_REDIRECTHOST:
			{
				if( mRedirectHostList->size() <= 0) {
					break;
				}

				mRedirectHostIterator = this->getRedirectHostList()->begin();
				while(mRedirectHostIterator != this->getRedirectHostList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "292" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RedirectHost" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
					(*mRedirectHostIterator)->Display(tab+1);
					mRedirectHostIterator++;

				};

			}
				break;
			case AAAnswer_REDIRECTHOSTUSAGE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "261" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RedirectHostUsage" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getRedirectHostUsage()->Display(tab+1);
			}
				break;
			case AAAnswer_REDIRECTMAXCACHETIME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "262" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RedirectMaxCacheTime" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getRedirectMaxCacheTime()->Display(tab+1);
			}
				break;
			case AAAnswer_PROXYINFO:
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
			case AAAnswer_LOAD:
			{
				if( mLoadGrpList->size() <= 0) {
					break;
				}

				mLoadGrpIterator = this->getLoadGrpList()->begin();
				while(mLoadGrpIterator != this->getLoadGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "650" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "Load" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
					(*mLoadGrpIterator)->Display(tab+1);
					mLoadGrpIterator++;

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


BOOLEAN AAAnswer::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<38> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case AAAnswer_SESSIONID:
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
			case AAAnswer_DRMP:
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
			case AAAnswer_AUTHAPPLICATIONID:
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
			case AAAnswer_ORIGINHOST:
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
			case AAAnswer_ORIGINREALM:
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
			case AAAnswer_RESULTCODE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 268");
				}
				else
					sprintf(lMissingAvpInfo, "%s,268", lMissingAvpInfo);
			}
				break;
			case AAAnswer_EXPERIMENTALRESULT:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 297");
				}
				else
					sprintf(lMissingAvpInfo, "%s,297", lMissingAvpInfo);
			}
				break;
			case AAAnswer_AUTHSESSIONSTATE:
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
			case AAAnswer_ACCESSNETWORKCHARGINGIDENTIFIER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 502");
				}
				else
					sprintf(lMissingAvpInfo, "%s,502", lMissingAvpInfo);
			}
				break;
			case AAAnswer_ACCESSNETWORKCHARGINGADDRESS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 501");
				}
				else
					sprintf(lMissingAvpInfo, "%s,501", lMissingAvpInfo);
			}
				break;
			case AAAnswer_ACCEPTABLESERVICEINFO:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 526");
				}
				else
					sprintf(lMissingAvpInfo, "%s,526", lMissingAvpInfo);
			}
				break;
			case AAAnswer_ANGWADDRESS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1050");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1050", lMissingAvpInfo);
			}
				break;
			case AAAnswer_ANTRUSTED:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1503");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1503", lMissingAvpInfo);
			}
				break;
			case AAAnswer_SERVICEAUTHORIZATIONINFO:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 548");
				}
				else
					sprintf(lMissingAvpInfo, "%s,548", lMissingAvpInfo);
			}
				break;
			case AAAnswer_IPCANTYPE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1027");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1027", lMissingAvpInfo);
			}
				break;
			case AAAnswer_MAINFORMATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 570");
				}
				else
					sprintf(lMissingAvpInfo, "%s,570", lMissingAvpInfo);
			}
				break;
			case AAAnswer_NETLOCACCESSSUPPORT:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2824");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2824", lMissingAvpInfo);
			}
				break;
			case AAAnswer_RATTYPE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1032");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1032", lMissingAvpInfo);
			}
				break;
			case AAAnswer_FLOWS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 510");
				}
				else
					sprintf(lMissingAvpInfo, "%s,510", lMissingAvpInfo);
			}
				break;
			case AAAnswer_OCSUPPORTEDFEATURES:
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
			case AAAnswer_OCOLR:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 623");
				}
				else
					sprintf(lMissingAvpInfo, "%s,623", lMissingAvpInfo);
			}
				break;
			case AAAnswer_SUPPORTEDFEATURES:
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
			case AAAnswer_SUBSCRIPTIONID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 443");
				}
				else
					sprintf(lMissingAvpInfo, "%s,443", lMissingAvpInfo);
			}
				break;
			case AAAnswer_USEREQUIPMENTINFO:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 458");
				}
				else
					sprintf(lMissingAvpInfo, "%s,458", lMissingAvpInfo);
			}
				break;
			case AAAnswer_USEREQUIPMENTINFOEXTENSION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 653");
				}
				else
					sprintf(lMissingAvpInfo, "%s,653", lMissingAvpInfo);
			}
				break;
			case AAAnswer_3GPPSGSNMCCMNC:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 18");
				}
				else
					sprintf(lMissingAvpInfo, "%s,18", lMissingAvpInfo);
			}
				break;
			case AAAnswer_NID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 569");
				}
				else
					sprintf(lMissingAvpInfo, "%s,569", lMissingAvpInfo);
			}
				break;
			case AAAnswer_CLASS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 25");
				}
				else
					sprintf(lMissingAvpInfo, "%s,25", lMissingAvpInfo);
			}
				break;
			case AAAnswer_ERRORMESSAGE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 281");
				}
				else
					sprintf(lMissingAvpInfo, "%s,281", lMissingAvpInfo);
			}
				break;
			case AAAnswer_ERRORREPORTINGHOST:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 294");
				}
				else
					sprintf(lMissingAvpInfo, "%s,294", lMissingAvpInfo);
			}
				break;
			case AAAnswer_FAILEDAVP:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 279");
				}
				else
					sprintf(lMissingAvpInfo, "%s,279", lMissingAvpInfo);
			}
				break;
			case AAAnswer_RETRYINTERVAL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 541");
				}
				else
					sprintf(lMissingAvpInfo, "%s,541", lMissingAvpInfo);
			}
				break;
			case AAAnswer_ORIGINSTATEID:
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
			case AAAnswer_REDIRECTHOST:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 292");
				}
				else
					sprintf(lMissingAvpInfo, "%s,292", lMissingAvpInfo);
			}
				break;
			case AAAnswer_REDIRECTHOSTUSAGE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 261");
				}
				else
					sprintf(lMissingAvpInfo, "%s,261", lMissingAvpInfo);
			}
				break;
			case AAAnswer_REDIRECTMAXCACHETIME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 262");
				}
				else
					sprintf(lMissingAvpInfo, "%s,262", lMissingAvpInfo);
			}
				break;
			case AAAnswer_PROXYINFO:
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
			case AAAnswer_LOAD:
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
			default:
				break;
		}
	}


	return true;
}
