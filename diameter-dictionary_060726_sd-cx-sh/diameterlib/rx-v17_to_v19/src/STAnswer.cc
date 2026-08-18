#include "rx/include/STAnswer.h"

using namespace RX;
BOOLEAN STAnswer::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

STAnswer::STAnswer()
{
	mSessionId = NULL;
	mDRMP = NULL;
	mOriginHost = NULL;
	mOriginRealm = NULL;
	mResultCode = NULL;
	mErrorMessage = NULL;
	mErrorReportingHost = NULL;
	mOCSupportedFeaturesGrp = NULL;
	mOCOLRGrp = NULL;
	mFailedAVPGrpList = NULL;
	mSponsoredConnectivityDataGrpList = NULL;
	mOriginStateId = NULL;
	m3GPPUserLocationInfo = NULL;
	mUserLocationInfoTime = NULL;
	m3GPPMSTimeZone = NULL;
	mRANNASReleaseCause = NULL;
	mFiveGSRANNASReleaseCauseGrpList = NULL;
	m3GPPSGSNMCCMNC = NULL;
	mNID = NULL;
	mTWANIdentifier = NULL;
	mTCPSourcePort = NULL;
	mUDPSourcePort = NULL;
	mUELocalIPAddress = NULL;
	mNetLocAccessSupport = NULL;
	mWirelineUserLocationInfoGrpList = NULL;
	mClass = NULL;
	mRedirectHostList = NULL;
	mRedirectHostUsage = NULL;
	mRedirectMaxCacheTime = NULL;
	mProxyInfoGrpList = NULL;
	mLoadGrpList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<31>(string("1111110000000000000101001011101"));
	mMandatoryAvpSetVal.reset();
}

STAnswer::~STAnswer()
{
	if(mSessionId != NULL)
		delete mSessionId;
	if(mDRMP != NULL)
		delete mDRMP;
	if(mOriginHost != NULL)
		delete mOriginHost;
	if(mOriginRealm != NULL)
		delete mOriginRealm;
	if(mResultCode != NULL)
		delete mResultCode;
	if(mErrorMessage != NULL)
		delete mErrorMessage;
	if(mErrorReportingHost != NULL)
		delete mErrorReportingHost;
	if(mOCSupportedFeaturesGrp != NULL)
		delete mOCSupportedFeaturesGrp;
	if(mOCOLRGrp != NULL)
		delete mOCOLRGrp;
	if(mFailedAVPGrpList != NULL){
		mFailedAVPGrpIterator = mFailedAVPGrpList->begin();
		while(mFailedAVPGrpIterator != mFailedAVPGrpList->end()){
	if(*mFailedAVPGrpIterator != NULL)
			delete (*mFailedAVPGrpIterator);
			mFailedAVPGrpIterator++;
		}
		delete mFailedAVPGrpList;
	}
	if(mSponsoredConnectivityDataGrpList != NULL){
		mSponsoredConnectivityDataGrpIterator = mSponsoredConnectivityDataGrpList->begin();
		while(mSponsoredConnectivityDataGrpIterator != mSponsoredConnectivityDataGrpList->end()){
	if(*mSponsoredConnectivityDataGrpIterator != NULL)
			delete (*mSponsoredConnectivityDataGrpIterator);
			mSponsoredConnectivityDataGrpIterator++;
		}
		delete mSponsoredConnectivityDataGrpList;
	}
	if(mOriginStateId != NULL)
		delete mOriginStateId;
	if(m3GPPUserLocationInfo != NULL)
		delete m3GPPUserLocationInfo;
	if(mUserLocationInfoTime != NULL)
		delete mUserLocationInfoTime;
	if(m3GPPMSTimeZone != NULL)
		delete m3GPPMSTimeZone;
	if(mRANNASReleaseCause != NULL)
		delete mRANNASReleaseCause;
	if(mFiveGSRANNASReleaseCauseGrpList != NULL){
		mFiveGSRANNASReleaseCauseGrpIterator = mFiveGSRANNASReleaseCauseGrpList->begin();
		while(mFiveGSRANNASReleaseCauseGrpIterator != mFiveGSRANNASReleaseCauseGrpList->end()){
	if(*mFiveGSRANNASReleaseCauseGrpIterator != NULL)
			delete (*mFiveGSRANNASReleaseCauseGrpIterator);
			mFiveGSRANNASReleaseCauseGrpIterator++;
		}
		delete mFiveGSRANNASReleaseCauseGrpList;
	}
	if(m3GPPSGSNMCCMNC != NULL)
		delete m3GPPSGSNMCCMNC;
	if(mNID != NULL)
		delete mNID;
	if(mTWANIdentifier != NULL)
		delete mTWANIdentifier;
	if(mTCPSourcePort != NULL)
		delete mTCPSourcePort;
	if(mUDPSourcePort != NULL)
		delete mUDPSourcePort;
	if(mUELocalIPAddress != NULL)
		delete mUELocalIPAddress;
	if(mNetLocAccessSupport != NULL)
		delete mNetLocAccessSupport;
	if(mWirelineUserLocationInfoGrpList != NULL){
		mWirelineUserLocationInfoGrpIterator = mWirelineUserLocationInfoGrpList->begin();
		while(mWirelineUserLocationInfoGrpIterator != mWirelineUserLocationInfoGrpList->end()){
	if(*mWirelineUserLocationInfoGrpIterator != NULL)
			delete (*mWirelineUserLocationInfoGrpIterator);
			mWirelineUserLocationInfoGrpIterator++;
		}
		delete mWirelineUserLocationInfoGrpList;
	}
	if(mClass != NULL)
		delete mClass;
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

OctetString* STAnswer::setSessionId(){
	mMandatoryAvpSetVal [STAnswer_SESSIONID] = 1;
	if(mSessionId == NULL)
	{
		mSessionId = new OctetString();
		mTagsPresent[STAnswer_SESSIONID] = 1;
		return mSessionId;
	}
	return mSessionId;
}

void STAnswer::resetSessionId(){
	mTagsPresent[STAnswer_SESSIONID] = 0;
	if(mSessionId != NULL)
	{
		delete mSessionId; 
		mSessionId = NULL;
	}
}

DRMP* STAnswer::setDRMP(){
	if(mDRMP == NULL)
	{
		mDRMP = new DRMP();
		mTagsPresent[STAnswer_DRMP] = 1;
		return mDRMP;
	}
	return mDRMP;
}

void STAnswer::resetDRMP(){
	mTagsPresent[STAnswer_DRMP] = 0;
	if(mDRMP != NULL)
	{
		delete mDRMP; 
		mDRMP = NULL;
	}
}

OctetString* STAnswer::setOriginHost(){
	mMandatoryAvpSetVal [STAnswer_ORIGINHOST] = 1;
	if(mOriginHost == NULL)
	{
		mOriginHost = new OctetString();
		mTagsPresent[STAnswer_ORIGINHOST] = 1;
		return mOriginHost;
	}
	return mOriginHost;
}

void STAnswer::resetOriginHost(){
	mTagsPresent[STAnswer_ORIGINHOST] = 0;
	if(mOriginHost != NULL)
	{
		delete mOriginHost; 
		mOriginHost = NULL;
	}
}

OctetString* STAnswer::setOriginRealm(){
	mMandatoryAvpSetVal [STAnswer_ORIGINREALM] = 1;
	if(mOriginRealm == NULL)
	{
		mOriginRealm = new OctetString();
		mTagsPresent[STAnswer_ORIGINREALM] = 1;
		return mOriginRealm;
	}
	return mOriginRealm;
}

void STAnswer::resetOriginRealm(){
	mTagsPresent[STAnswer_ORIGINREALM] = 0;
	if(mOriginRealm != NULL)
	{
		delete mOriginRealm; 
		mOriginRealm = NULL;
	}
}

Unsigned32* STAnswer::setResultCode(){
	mMandatoryAvpSetVal [STAnswer_RESULTCODE] = 1;
	if(mResultCode == NULL)
	{
		mResultCode = new Unsigned32();
		mTagsPresent[STAnswer_RESULTCODE] = 1;
		return mResultCode;
	}
	return mResultCode;
}

void STAnswer::resetResultCode(){
	mTagsPresent[STAnswer_RESULTCODE] = 0;
	if(mResultCode != NULL)
	{
		delete mResultCode; 
		mResultCode = NULL;
	}
}

OctetString* STAnswer::setErrorMessage(){
	if(mErrorMessage == NULL)
	{
		mErrorMessage = new OctetString();
		mTagsPresent[STAnswer_ERRORMESSAGE] = 1;
		return mErrorMessage;
	}
	return mErrorMessage;
}

void STAnswer::resetErrorMessage(){
	mTagsPresent[STAnswer_ERRORMESSAGE] = 0;
	if(mErrorMessage != NULL)
	{
		delete mErrorMessage; 
		mErrorMessage = NULL;
	}
}

OctetString* STAnswer::setErrorReportingHost(){
	mMandatoryAvpSetVal [STAnswer_ERRORREPORTINGHOST] = 1;
	if(mErrorReportingHost == NULL)
	{
		mErrorReportingHost = new OctetString();
		mTagsPresent[STAnswer_ERRORREPORTINGHOST] = 1;
		return mErrorReportingHost;
	}
	return mErrorReportingHost;
}

void STAnswer::resetErrorReportingHost(){
	mTagsPresent[STAnswer_ERRORREPORTINGHOST] = 0;
	if(mErrorReportingHost != NULL)
	{
		delete mErrorReportingHost; 
		mErrorReportingHost = NULL;
	}
}

Unsigned32* STAnswer::setOriginStateId(){
	mMandatoryAvpSetVal [STAnswer_ORIGINSTATEID] = 1;
	if(mOriginStateId == NULL)
	{
		mOriginStateId = new Unsigned32();
		mTagsPresent[STAnswer_ORIGINSTATEID] = 1;
		return mOriginStateId;
	}
	return mOriginStateId;
}

void STAnswer::resetOriginStateId(){
	mTagsPresent[STAnswer_ORIGINSTATEID] = 0;
	if(mOriginStateId != NULL)
	{
		delete mOriginStateId; 
		mOriginStateId = NULL;
	}
}

OctetString* STAnswer::set3GPPUserLocationInfo(){
	if(m3GPPUserLocationInfo == NULL)
	{
		m3GPPUserLocationInfo = new OctetString();
		mTagsPresent[STAnswer_3GPPUSERLOCATIONINFO] = 1;
		return m3GPPUserLocationInfo;
	}
	return m3GPPUserLocationInfo;
}

void STAnswer::reset3GPPUserLocationInfo(){
	mTagsPresent[STAnswer_3GPPUSERLOCATIONINFO] = 0;
	if(m3GPPUserLocationInfo != NULL)
	{
		delete m3GPPUserLocationInfo; 
		m3GPPUserLocationInfo = NULL;
	}
}

Time* STAnswer::setUserLocationInfoTime(){
	if(mUserLocationInfoTime == NULL)
	{
		mUserLocationInfoTime = new Time();
		mTagsPresent[STAnswer_USERLOCATIONINFOTIME] = 1;
		return mUserLocationInfoTime;
	}
	return mUserLocationInfoTime;
}

void STAnswer::resetUserLocationInfoTime(){
	mTagsPresent[STAnswer_USERLOCATIONINFOTIME] = 0;
	if(mUserLocationInfoTime != NULL)
	{
		delete mUserLocationInfoTime; 
		mUserLocationInfoTime = NULL;
	}
}

OctetString* STAnswer::set3GPPMSTimeZone(){
	if(m3GPPMSTimeZone == NULL)
	{
		m3GPPMSTimeZone = new OctetString();
		mTagsPresent[STAnswer_3GPPMSTIMEZONE] = 1;
		return m3GPPMSTimeZone;
	}
	return m3GPPMSTimeZone;
}

void STAnswer::reset3GPPMSTimeZone(){
	mTagsPresent[STAnswer_3GPPMSTIMEZONE] = 0;
	if(m3GPPMSTimeZone != NULL)
	{
		delete m3GPPMSTimeZone; 
		m3GPPMSTimeZone = NULL;
	}
}

OctetString* STAnswer::setRANNASReleaseCause(){
	if(mRANNASReleaseCause == NULL)
	{
		mRANNASReleaseCause = new OctetString();
		mTagsPresent[STAnswer_RANNASRELEASECAUSE] = 1;
		return mRANNASReleaseCause;
	}
	return mRANNASReleaseCause;
}

void STAnswer::resetRANNASReleaseCause(){
	mTagsPresent[STAnswer_RANNASRELEASECAUSE] = 0;
	if(mRANNASReleaseCause != NULL)
	{
		delete mRANNASReleaseCause; 
		mRANNASReleaseCause = NULL;
	}
}

OctetString* STAnswer::set3GPPSGSNMCCMNC(){
	if(m3GPPSGSNMCCMNC == NULL)
	{
		m3GPPSGSNMCCMNC = new OctetString();
		mTagsPresent[STAnswer_3GPPSGSNMCCMNC] = 1;
		return m3GPPSGSNMCCMNC;
	}
	return m3GPPSGSNMCCMNC;
}

void STAnswer::reset3GPPSGSNMCCMNC(){
	mTagsPresent[STAnswer_3GPPSGSNMCCMNC] = 0;
	if(m3GPPSGSNMCCMNC != NULL)
	{
		delete m3GPPSGSNMCCMNC; 
		m3GPPSGSNMCCMNC = NULL;
	}
}

OctetString* STAnswer::setNID(){
	if(mNID == NULL)
	{
		mNID = new OctetString();
		mTagsPresent[STAnswer_NID] = 1;
		return mNID;
	}
	return mNID;
}

void STAnswer::resetNID(){
	mTagsPresent[STAnswer_NID] = 0;
	if(mNID != NULL)
	{
		delete mNID; 
		mNID = NULL;
	}
}

OctetString* STAnswer::setTWANIdentifier(){
	if(mTWANIdentifier == NULL)
	{
		mTWANIdentifier = new OctetString();
		mTagsPresent[STAnswer_TWANIDENTIFIER] = 1;
		return mTWANIdentifier;
	}
	return mTWANIdentifier;
}

void STAnswer::resetTWANIdentifier(){
	mTagsPresent[STAnswer_TWANIDENTIFIER] = 0;
	if(mTWANIdentifier != NULL)
	{
		delete mTWANIdentifier; 
		mTWANIdentifier = NULL;
	}
}

Unsigned32* STAnswer::setTCPSourcePort(){
	if(mTCPSourcePort == NULL)
	{
		mTCPSourcePort = new Unsigned32();
		mTagsPresent[STAnswer_TCPSOURCEPORT] = 1;
		return mTCPSourcePort;
	}
	return mTCPSourcePort;
}

void STAnswer::resetTCPSourcePort(){
	mTagsPresent[STAnswer_TCPSOURCEPORT] = 0;
	if(mTCPSourcePort != NULL)
	{
		delete mTCPSourcePort; 
		mTCPSourcePort = NULL;
	}
}

Unsigned32* STAnswer::setUDPSourcePort(){
	if(mUDPSourcePort == NULL)
	{
		mUDPSourcePort = new Unsigned32();
		mTagsPresent[STAnswer_UDPSOURCEPORT] = 1;
		return mUDPSourcePort;
	}
	return mUDPSourcePort;
}

void STAnswer::resetUDPSourcePort(){
	mTagsPresent[STAnswer_UDPSOURCEPORT] = 0;
	if(mUDPSourcePort != NULL)
	{
		delete mUDPSourcePort; 
		mUDPSourcePort = NULL;
	}
}

Address* STAnswer::setUELocalIPAddress(){
	if(mUELocalIPAddress == NULL)
	{
		mUELocalIPAddress = new Address();
		mTagsPresent[STAnswer_UELOCALIPADDRESS] = 1;
		return mUELocalIPAddress;
	}
	return mUELocalIPAddress;
}

void STAnswer::resetUELocalIPAddress(){
	mTagsPresent[STAnswer_UELOCALIPADDRESS] = 0;
	if(mUELocalIPAddress != NULL)
	{
		delete mUELocalIPAddress; 
		mUELocalIPAddress = NULL;
	}
}

Unsigned32* STAnswer::setNetLocAccessSupport(){
	if(mNetLocAccessSupport == NULL)
	{
		mNetLocAccessSupport = new Unsigned32();
		mTagsPresent[STAnswer_NETLOCACCESSSUPPORT] = 1;
		return mNetLocAccessSupport;
	}
	return mNetLocAccessSupport;
}

void STAnswer::resetNetLocAccessSupport(){
	mTagsPresent[STAnswer_NETLOCACCESSSUPPORT] = 0;
	if(mNetLocAccessSupport != NULL)
	{
		delete mNetLocAccessSupport; 
		mNetLocAccessSupport = NULL;
	}
}

OctetString* STAnswer::setClass(){
	mMandatoryAvpSetVal [STAnswer_CLASS] = 1;
	if(mClass == NULL)
	{
		mClass = new OctetString();
		mTagsPresent[STAnswer_CLASS] = 1;
		return mClass;
	}
	return mClass;
}

void STAnswer::resetClass(){
	mTagsPresent[STAnswer_CLASS] = 0;
	if(mClass != NULL)
	{
		delete mClass; 
		mClass = NULL;
	}
}

RedirectHostUsage* STAnswer::setRedirectHostUsage(){
	mMandatoryAvpSetVal [STAnswer_REDIRECTHOSTUSAGE] = 1;
	if(mRedirectHostUsage == NULL)
	{
		mRedirectHostUsage = new RedirectHostUsage();
		mTagsPresent[STAnswer_REDIRECTHOSTUSAGE] = 1;
		return mRedirectHostUsage;
	}
	return mRedirectHostUsage;
}

void STAnswer::resetRedirectHostUsage(){
	mTagsPresent[STAnswer_REDIRECTHOSTUSAGE] = 0;
	if(mRedirectHostUsage != NULL)
	{
		delete mRedirectHostUsage; 
		mRedirectHostUsage = NULL;
	}
}

Unsigned32* STAnswer::setRedirectMaxCacheTime(){
	mMandatoryAvpSetVal [STAnswer_REDIRECTMAXCACHETIME] = 1;
	if(mRedirectMaxCacheTime == NULL)
	{
		mRedirectMaxCacheTime = new Unsigned32();
		mTagsPresent[STAnswer_REDIRECTMAXCACHETIME] = 1;
		return mRedirectMaxCacheTime;
	}
	return mRedirectMaxCacheTime;
}

void STAnswer::resetRedirectMaxCacheTime(){
	mTagsPresent[STAnswer_REDIRECTMAXCACHETIME] = 0;
	if(mRedirectMaxCacheTime != NULL)
	{
		delete mRedirectMaxCacheTime; 
		mRedirectMaxCacheTime = NULL;
	}
}

OctetString* STAnswer::getSessionId(){
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

DRMP* STAnswer::getDRMP(){
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

OctetString* STAnswer::getOriginHost(){
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

OctetString* STAnswer::getOriginRealm(){
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

Unsigned32* STAnswer::getResultCode(){
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

OctetString* STAnswer::getErrorMessage(){
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

OctetString* STAnswer::getErrorReportingHost(){
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

OCSupportedFeatures* STAnswer::getOCSupportedFeatures()
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

OCSupportedFeatures* STAnswer::setOCSupportedFeatures(){
	if(mOCSupportedFeaturesGrp == NULL)
		mOCSupportedFeaturesGrp = new OCSupportedFeatures();
	mTagsPresent[STAnswer_OCSUPPORTEDFEATURES] = 1;
	return mOCSupportedFeaturesGrp;
}

void STAnswer::resetOCSupportedFeatures(){
	mTagsPresent[STAnswer_OCSUPPORTEDFEATURES] = 0;
	if(mOCSupportedFeaturesGrp != NULL)
		delete mOCSupportedFeaturesGrp;
}

OCOLR* STAnswer::getOCOLR()
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

OCOLR* STAnswer::setOCOLR(){
	if(mOCOLRGrp == NULL)
		mOCOLRGrp = new OCOLR();
	mTagsPresent[STAnswer_OCOLR] = 1;
	return mOCOLRGrp;
}

void STAnswer::resetOCOLR(){
	mTagsPresent[STAnswer_OCOLR] = 0;
	if(mOCOLRGrp != NULL)
		delete mOCOLRGrp;
}

list<FailedAVP*>* STAnswer::getFailedAVPGrpList()
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
			mTagsPresent[STAnswer_FAILEDAVP] = 0;
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

list<FailedAVP*>* STAnswer::setFailedAVPGrpList(){
	mTagsPresent[STAnswer_FAILEDAVP] = 1;
	if(mFailedAVPGrpList == NULL)
		mFailedAVPGrpList = new list<FailedAVP*>;
	mMandatoryAvpSetVal[STAnswer_FAILEDAVP] = 1;
	mFailedAVPGrpList->clear();
	return mFailedAVPGrpList;
}

void STAnswer::resetFailedAVPGrpList(){
	mTagsPresent[STAnswer_FAILEDAVP] = 0;
	if(mFailedAVPGrpList != NULL)
		delete mFailedAVPGrpList;
}

list<SponsoredConnectivityData*>* STAnswer::getSponsoredConnectivityDataGrpList()
{
	if(mSponsoredConnectivityDataGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SponsoredConnectivityData is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mSponsoredConnectivityDataGrpList)
	{
		if(mSponsoredConnectivityDataGrpList != NULL)
		{
		if(mSponsoredConnectivityDataGrpList->size() == 0)
		{
			mTagsPresent[STAnswer_SPONSOREDCONNECTIVITYDATA] = 0;
			mSponsoredConnectivityDataGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SponsoredConnectivityData is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SponsoredConnectivityData is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SponsoredConnectivityData")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mSponsoredConnectivityDataGrpList;
}

list<SponsoredConnectivityData*>* STAnswer::setSponsoredConnectivityDataGrpList(){
	mTagsPresent[STAnswer_SPONSOREDCONNECTIVITYDATA] = 1;
	if(mSponsoredConnectivityDataGrpList == NULL)
		mSponsoredConnectivityDataGrpList = new list<SponsoredConnectivityData*>;
	mSponsoredConnectivityDataGrpList->clear();
	return mSponsoredConnectivityDataGrpList;
}

void STAnswer::resetSponsoredConnectivityDataGrpList(){
	mTagsPresent[STAnswer_SPONSOREDCONNECTIVITYDATA] = 0;
	if(mSponsoredConnectivityDataGrpList != NULL)
		delete mSponsoredConnectivityDataGrpList;
}

Unsigned32* STAnswer::getOriginStateId(){
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

OctetString* STAnswer::get3GPPUserLocationInfo(){
	if(NULL == m3GPPUserLocationInfo) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPUserLocationInfo is Null");
		throw lTssDiaMsgException;
	}
	if(!m3GPPUserLocationInfo->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			m3GPPUserLocationInfo->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPUserLocationInfo is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = m3GPPUserLocationInfo->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(m3GPPUserLocationInfo->Decode(mspByteArray.get(), m3GPPUserLocationInfo->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPUserLocationInfo")     ;
			throw lTssDiaMsgException;
		}
		m3GPPUserLocationInfo->mAvpDecodedFlag = true;
	}
	return m3GPPUserLocationInfo;
}

Time* STAnswer::getUserLocationInfoTime(){
	if(NULL == mUserLocationInfoTime) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserLocationInfoTime is Null");
		throw lTssDiaMsgException;
	}
	if(!mUserLocationInfoTime->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUserLocationInfoTime->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserLocationInfoTime is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUserLocationInfoTime->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUserLocationInfoTime->Decode(mspByteArray.get(), mUserLocationInfoTime->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserLocationInfoTime")     ;
			throw lTssDiaMsgException;
		}
		mUserLocationInfoTime->mAvpDecodedFlag = true;
	}
	return mUserLocationInfoTime;
}

OctetString* STAnswer::get3GPPMSTimeZone(){
	if(NULL == m3GPPMSTimeZone) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPMSTimeZone is Null");
		throw lTssDiaMsgException;
	}
	if(!m3GPPMSTimeZone->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			m3GPPMSTimeZone->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPMSTimeZone is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = m3GPPMSTimeZone->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(m3GPPMSTimeZone->Decode(mspByteArray.get(), m3GPPMSTimeZone->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPMSTimeZone")     ;
			throw lTssDiaMsgException;
		}
		m3GPPMSTimeZone->mAvpDecodedFlag = true;
	}
	return m3GPPMSTimeZone;
}

OctetString* STAnswer::getRANNASReleaseCause(){
	if(NULL == mRANNASReleaseCause) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RANNASReleaseCause is Null");
		throw lTssDiaMsgException;
	}
	if(!mRANNASReleaseCause->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRANNASReleaseCause->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RANNASReleaseCause is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRANNASReleaseCause->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRANNASReleaseCause->Decode(mspByteArray.get(), mRANNASReleaseCause->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RANNASReleaseCause")     ;
			throw lTssDiaMsgException;
		}
		mRANNASReleaseCause->mAvpDecodedFlag = true;
	}
	return mRANNASReleaseCause;
}

list<FiveGSRANNASReleaseCause*>* STAnswer::getFiveGSRANNASReleaseCauseGrpList()
{
	if(mFiveGSRANNASReleaseCauseGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FiveGSRANNASReleaseCause is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mFiveGSRANNASReleaseCauseGrpList)
	{
		if(mFiveGSRANNASReleaseCauseGrpList != NULL)
		{
		if(mFiveGSRANNASReleaseCauseGrpList->size() == 0)
		{
			mTagsPresent[STAnswer_FIVEGSRANNASRELEASECAUSE] = 0;
			mFiveGSRANNASReleaseCauseGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FiveGSRANNASReleaseCause is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FiveGSRANNASReleaseCause is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FiveGSRANNASReleaseCause")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mFiveGSRANNASReleaseCauseGrpList;
}

list<FiveGSRANNASReleaseCause*>* STAnswer::setFiveGSRANNASReleaseCauseGrpList(){
	mTagsPresent[STAnswer_FIVEGSRANNASRELEASECAUSE] = 1;
	if(mFiveGSRANNASReleaseCauseGrpList == NULL)
		mFiveGSRANNASReleaseCauseGrpList = new list<FiveGSRANNASReleaseCause*>;
	mFiveGSRANNASReleaseCauseGrpList->clear();
	return mFiveGSRANNASReleaseCauseGrpList;
}

void STAnswer::resetFiveGSRANNASReleaseCauseGrpList(){
	mTagsPresent[STAnswer_FIVEGSRANNASRELEASECAUSE] = 0;
	if(mFiveGSRANNASReleaseCauseGrpList != NULL)
		delete mFiveGSRANNASReleaseCauseGrpList;
}

OctetString* STAnswer::get3GPPSGSNMCCMNC(){
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

OctetString* STAnswer::getNID(){
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

OctetString* STAnswer::getTWANIdentifier(){
	if(NULL == mTWANIdentifier) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TWANIdentifier is Null");
		throw lTssDiaMsgException;
	}
	if(!mTWANIdentifier->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mTWANIdentifier->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TWANIdentifier is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mTWANIdentifier->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mTWANIdentifier->Decode(mspByteArray.get(), mTWANIdentifier->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TWANIdentifier")     ;
			throw lTssDiaMsgException;
		}
		mTWANIdentifier->mAvpDecodedFlag = true;
	}
	return mTWANIdentifier;
}

Unsigned32* STAnswer::getTCPSourcePort(){
	if(NULL == mTCPSourcePort) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TCPSourcePort is Null");
		throw lTssDiaMsgException;
	}
	if(!mTCPSourcePort->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mTCPSourcePort->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TCPSourcePort is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mTCPSourcePort->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mTCPSourcePort->Decode(mspByteArray.get(), mTCPSourcePort->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TCPSourcePort")     ;
			throw lTssDiaMsgException;
		}
		mTCPSourcePort->mAvpDecodedFlag = true;
	}
	return mTCPSourcePort;
}

Unsigned32* STAnswer::getUDPSourcePort(){
	if(NULL == mUDPSourcePort) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UDPSourcePort is Null");
		throw lTssDiaMsgException;
	}
	if(!mUDPSourcePort->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUDPSourcePort->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UDPSourcePort is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUDPSourcePort->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUDPSourcePort->Decode(mspByteArray.get(), mUDPSourcePort->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UDPSourcePort")     ;
			throw lTssDiaMsgException;
		}
		mUDPSourcePort->mAvpDecodedFlag = true;
	}
	return mUDPSourcePort;
}

Address* STAnswer::getUELocalIPAddress(){
	if(NULL == mUELocalIPAddress) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UELocalIPAddress is Null");
		throw lTssDiaMsgException;
	}
	if(!mUELocalIPAddress->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUELocalIPAddress->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UELocalIPAddress is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUELocalIPAddress->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUELocalIPAddress->Decode(mspByteArray.get(), mUELocalIPAddress->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UELocalIPAddress")     ;
			throw lTssDiaMsgException;
		}
		mUELocalIPAddress->mAvpDecodedFlag = true;
	}
	return mUELocalIPAddress;
}

Unsigned32* STAnswer::getNetLocAccessSupport(){
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

list<WirelineUserLocationInfo*>* STAnswer::getWirelineUserLocationInfoGrpList()
{
	if(mWirelineUserLocationInfoGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "WirelineUserLocationInfo is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mWirelineUserLocationInfoGrpList)
	{
		if(mWirelineUserLocationInfoGrpList != NULL)
		{
		if(mWirelineUserLocationInfoGrpList->size() == 0)
		{
			mTagsPresent[STAnswer_WIRELINEUSERLOCATIONINFO] = 0;
			mWirelineUserLocationInfoGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "WirelineUserLocationInfo is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "WirelineUserLocationInfo is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding WirelineUserLocationInfo")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mWirelineUserLocationInfoGrpList;
}

list<WirelineUserLocationInfo*>* STAnswer::setWirelineUserLocationInfoGrpList(){
	mTagsPresent[STAnswer_WIRELINEUSERLOCATIONINFO] = 1;
	if(mWirelineUserLocationInfoGrpList == NULL)
		mWirelineUserLocationInfoGrpList = new list<WirelineUserLocationInfo*>;
	mWirelineUserLocationInfoGrpList->clear();
	return mWirelineUserLocationInfoGrpList;
}

void STAnswer::resetWirelineUserLocationInfoGrpList(){
	mTagsPresent[STAnswer_WIRELINEUSERLOCATIONINFO] = 0;
	if(mWirelineUserLocationInfoGrpList != NULL)
		delete mWirelineUserLocationInfoGrpList;
}

OctetString* STAnswer::getClass(){
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

list<OctetString*>* STAnswer::getRedirectHostList()
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

list<OctetString*>* STAnswer::setRedirectHostList() {
	mTagsPresent[STAnswer_REDIRECTHOST] = 1;
	if(mRedirectHostList == NULL)
		mRedirectHostList = new list<OctetString*>;
	mMandatoryAvpSetVal [STAnswer_REDIRECTHOST] = 1;
	mRedirectHostList->clear();
	return mRedirectHostList;
}

void STAnswer::resetRedirectHostList(){
	mTagsPresent[STAnswer_REDIRECTHOST] = 0;
	if(mRedirectHostList != NULL)
		delete mRedirectHostList;
}

RedirectHostUsage* STAnswer::getRedirectHostUsage(){
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

Unsigned32* STAnswer::getRedirectMaxCacheTime(){
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

list<RX::ProxyInfo*>* STAnswer::getProxyInfoGrpList()
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
			mTagsPresent[STAnswer_PROXYINFO] = 0;
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

list<RX::ProxyInfo*>* STAnswer::setProxyInfoGrpList(){
	mTagsPresent[STAnswer_PROXYINFO] = 1;
	if(mProxyInfoGrpList == NULL)
		mProxyInfoGrpList = new list<RX::ProxyInfo*>;
	mMandatoryAvpSetVal[STAnswer_PROXYINFO] = 1;
	mProxyInfoGrpList->clear();
	return mProxyInfoGrpList;
}

void STAnswer::resetProxyInfoGrpList(){
	mTagsPresent[STAnswer_PROXYINFO] = 0;
	if(mProxyInfoGrpList != NULL)
		delete mProxyInfoGrpList;
}

list<Load*>* STAnswer::getLoadGrpList()
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
			mTagsPresent[STAnswer_LOAD] = 0;
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

list<Load*>* STAnswer::setLoadGrpList(){
	mTagsPresent[STAnswer_LOAD] = 1;
	if(mLoadGrpList == NULL)
		mLoadGrpList = new list<Load*>;
	mMandatoryAvpSetVal[STAnswer_LOAD] = 1;
	mLoadGrpList->clear();
	return mLoadGrpList;
}

void STAnswer::resetLoadGrpList(){
	mTagsPresent[STAnswer_LOAD] = 0;
	if(mLoadGrpList != NULL)
		delete mLoadGrpList;
}



int STAnswer::Encode(byteArray *array)
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
	array->byte[array->offset++] = (275>>16) & 0xFF;
	array->byte[array->offset++] = (275>>8) & 0xFF;
	array->byte[array->offset++] = (275) & 0xFF;
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
			case STAnswer_SESSIONID:
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
			case STAnswer_DRMP:
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
			case STAnswer_ORIGINHOST:
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
			case STAnswer_ORIGINREALM:
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
			case STAnswer_RESULTCODE:
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
			case STAnswer_ERRORMESSAGE:
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
			case STAnswer_ERRORREPORTINGHOST:
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
			case STAnswer_OCSUPPORTEDFEATURES:
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
			case STAnswer_OCOLR:
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
			case STAnswer_FAILEDAVP:
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
			case STAnswer_SPONSOREDCONNECTIVITYDATA:
			{
				if( mSponsoredConnectivityDataGrpList->size() <= 0) {
					break;
				}

				mSponsoredConnectivityDataGrpIterator = this->getSponsoredConnectivityDataGrpList()->begin();
				while(mSponsoredConnectivityDataGrpIterator != mSponsoredConnectivityDataGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(530);
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
					if(((*mSponsoredConnectivityDataGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SponsoredConnectivityData");
						throw lTssDiaMsgException;
					}
					
					mSponsoredConnectivityDataGrpIterator++;
				}
				}
				break;
			case STAnswer_ORIGINSTATEID:
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
			case STAnswer_3GPPUSERLOCATIONINFO:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(22);
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
					if(!m3GPPUserLocationInfo->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[m3GPPUserLocationInfo->getAvpOffsetLen().first], m3GPPUserLocationInfo->getAvpOffsetLen().second);
						array->offset += m3GPPUserLocationInfo->getAvpOffsetLen().second;
						array->size += m3GPPUserLocationInfo->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( m3GPPUserLocationInfo->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(m3GPPUserLocationInfo->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPUserLocationInfo");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((m3GPPUserLocationInfo->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, m3GPPUserLocationInfo->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPUserLocationInfo");
						throw lTssDiaMsgException;
					}
				}
				break;
			case STAnswer_USERLOCATIONINFOTIME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2812);
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
					if(!mUserLocationInfoTime->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mUserLocationInfoTime->getAvpOffsetLen().first], mUserLocationInfoTime->getAvpOffsetLen().second);
						array->offset += mUserLocationInfoTime->getAvpOffsetLen().second;
						array->size += mUserLocationInfoTime->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mUserLocationInfoTime->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mUserLocationInfoTime->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserLocationInfoTime");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mUserLocationInfoTime->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mUserLocationInfoTime->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserLocationInfoTime");
						throw lTssDiaMsgException;
					}
				}
				break;
			case STAnswer_3GPPMSTIMEZONE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(23);
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
					if(!m3GPPMSTimeZone->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[m3GPPMSTimeZone->getAvpOffsetLen().first], m3GPPMSTimeZone->getAvpOffsetLen().second);
						array->offset += m3GPPMSTimeZone->getAvpOffsetLen().second;
						array->size += m3GPPMSTimeZone->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( m3GPPMSTimeZone->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(m3GPPMSTimeZone->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPMSTimeZone");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((m3GPPMSTimeZone->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, m3GPPMSTimeZone->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPMSTimeZone");
						throw lTssDiaMsgException;
					}
				}
				break;
			case STAnswer_RANNASRELEASECAUSE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2819);
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
					if(!mRANNASReleaseCause->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRANNASReleaseCause->getAvpOffsetLen().first], mRANNASReleaseCause->getAvpOffsetLen().second);
						array->offset += mRANNASReleaseCause->getAvpOffsetLen().second;
						array->size += mRANNASReleaseCause->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mRANNASReleaseCause->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mRANNASReleaseCause->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RANNASReleaseCause");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mRANNASReleaseCause->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mRANNASReleaseCause->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RANNASReleaseCause");
						throw lTssDiaMsgException;
					}
				}
				break;
			case STAnswer_FIVEGSRANNASRELEASECAUSE:
			{
				if( mFiveGSRANNASReleaseCauseGrpList->size() <= 0) {
					break;
				}

				mFiveGSRANNASReleaseCauseGrpIterator = this->getFiveGSRANNASReleaseCauseGrpList()->begin();
				while(mFiveGSRANNASReleaseCauseGrpIterator != mFiveGSRANNASReleaseCauseGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(572);
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
					if(((*mFiveGSRANNASReleaseCauseGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FiveGSRANNASReleaseCause");
						throw lTssDiaMsgException;
					}
					
					mFiveGSRANNASReleaseCauseGrpIterator++;
				}
				}
				break;
			case STAnswer_3GPPSGSNMCCMNC:
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
			case STAnswer_NID:
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
			case STAnswer_TWANIDENTIFIER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(29);
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
					if(!mTWANIdentifier->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mTWANIdentifier->getAvpOffsetLen().first], mTWANIdentifier->getAvpOffsetLen().second);
						array->offset += mTWANIdentifier->getAvpOffsetLen().second;
						array->size += mTWANIdentifier->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mTWANIdentifier->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mTWANIdentifier->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TWANIdentifier");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mTWANIdentifier->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mTWANIdentifier->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TWANIdentifier");
						throw lTssDiaMsgException;
					}
				}
				break;
			case STAnswer_TCPSOURCEPORT:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2843);
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
					if(!mTCPSourcePort->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mTCPSourcePort->getAvpOffsetLen().first], mTCPSourcePort->getAvpOffsetLen().second);
						array->offset += mTCPSourcePort->getAvpOffsetLen().second;
						array->size += mTCPSourcePort->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TCPSourcePort");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mTCPSourcePort->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TCPSourcePort");
						throw lTssDiaMsgException;
					}
				}
				break;
			case STAnswer_UDPSOURCEPORT:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2806);
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
					if(!mUDPSourcePort->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mUDPSourcePort->getAvpOffsetLen().first], mUDPSourcePort->getAvpOffsetLen().second);
						array->offset += mUDPSourcePort->getAvpOffsetLen().second;
						array->size += mUDPSourcePort->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UDPSourcePort");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mUDPSourcePort->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UDPSourcePort");
						throw lTssDiaMsgException;
					}
				}
				break;
			case STAnswer_UELOCALIPADDRESS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2805);
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
					if(!mUELocalIPAddress->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mUELocalIPAddress->getAvpOffsetLen().first], mUELocalIPAddress->getAvpOffsetLen().second);
						array->offset += mUELocalIPAddress->getAvpOffsetLen().second;
						array->size += mUELocalIPAddress->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mUELocalIPAddress->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mUELocalIPAddress->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array,TSS_MAX_DIAMETER_TIME_LEN)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UELocalIPAddress");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mUELocalIPAddress->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mUELocalIPAddress->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UELocalIPAddress");
						throw lTssDiaMsgException;
					}
				}
				break;
			case STAnswer_NETLOCACCESSSUPPORT:
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
			case STAnswer_WIRELINEUSERLOCATIONINFO:
			{
				if( mWirelineUserLocationInfoGrpList->size() <= 0) {
					break;
				}

				mWirelineUserLocationInfoGrpIterator = this->getWirelineUserLocationInfoGrpList()->begin();
				while(mWirelineUserLocationInfoGrpIterator != mWirelineUserLocationInfoGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(578);
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
					if(((*mWirelineUserLocationInfoGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding WirelineUserLocationInfo");
						throw lTssDiaMsgException;
					}
					
					mWirelineUserLocationInfoGrpIterator++;
				}
				}
				break;
			case STAnswer_CLASS:
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
			case STAnswer_REDIRECTHOST:
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
			case STAnswer_REDIRECTHOSTUSAGE:
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
			case STAnswer_REDIRECTMAXCACHETIME:
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
			case STAnswer_PROXYINFO:
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
			case STAnswer_LOAD:
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


int STAnswer::Decode(byteArray *array, INT16 lMLen, UINT16 *parsedBytes)
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
						mMandatoryAvpSetVal [STAnswer_SESSIONID] = 1;
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
			case 264:
				{
						mMandatoryAvpSetVal [STAnswer_ORIGINHOST] = 1;
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
						mMandatoryAvpSetVal [STAnswer_ORIGINREALM] = 1;
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
						mMandatoryAvpSetVal [STAnswer_RESULTCODE] = 1;
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
						mMandatoryAvpSetVal [STAnswer_ERRORREPORTINGHOST] = 1;
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
			case 621:
				{
					mTagsPresent[STAnswer_OCSUPPORTEDFEATURES] = 1;
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
					mTagsPresent[STAnswer_OCOLR] = 1;
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
			case 279:
				{
						mMandatoryAvpSetVal [STAnswer_FAILEDAVP] = 1;
					mTagsPresent[STAnswer_FAILEDAVP] = 1;
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
			case 530:
				{
					mTagsPresent[STAnswer_SPONSOREDCONNECTIVITYDATA] = 1;
					SponsoredConnectivityData *lSponsoredConnectivityData = new SponsoredConnectivityData();
					if( lSponsoredConnectivityData == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SponsoredConnectivityData");
						throw lTssDiaMsgException;
					}
					lSponsoredConnectivityData->setAvpCode(530);
					lSponsoredConnectivityData->SetDataType((DiameterDataType)6);
					lSponsoredConnectivityData->mspByteArray = mspByteArray;
					lSponsoredConnectivityData->mAvpDecodedFlag = false;
					lSponsoredConnectivityData->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mSponsoredConnectivityDataGrpList == NULL)
						this->setSponsoredConnectivityDataGrpList();
					mSponsoredConnectivityDataGrpList->push_back(lSponsoredConnectivityData);
					mBaseInterfaceList.push_back(lSponsoredConnectivityData);
					
				}
				break;
			case 278:
				{
						mMandatoryAvpSetVal [STAnswer_ORIGINSTATEID] = 1;
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
			case 22:
				{
					if( NULL == this->set3GPPUserLocationInfo())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPUserLocationInfo");
						throw lTssDiaMsgException;
					}
					m3GPPUserLocationInfo->setAvpCode(22);
					m3GPPUserLocationInfo->setAvpVendorId(lVenderId);
					m3GPPUserLocationInfo->SetDataType((DiameterDataType)5);
					m3GPPUserLocationInfo->mspByteArray = mspByteArray;
					m3GPPUserLocationInfo->mAvpDecodedFlag = false;
					m3GPPUserLocationInfo->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2812:
				{
					if( NULL == this->setUserLocationInfoTime())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserLocationInfoTime");
						throw lTssDiaMsgException;
					}
					mUserLocationInfoTime->setAvpCode(2812);
					mUserLocationInfoTime->setAvpVendorId(lVenderId);
					mUserLocationInfoTime->SetDataType((DiameterDataType)9);
					mUserLocationInfoTime->mspByteArray = mspByteArray;
					mUserLocationInfoTime->mAvpDecodedFlag = false;
					mUserLocationInfoTime->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 23:
				{
					if( NULL == this->set3GPPMSTimeZone())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPMSTimeZone");
						throw lTssDiaMsgException;
					}
					m3GPPMSTimeZone->setAvpCode(23);
					m3GPPMSTimeZone->setAvpVendorId(lVenderId);
					m3GPPMSTimeZone->SetDataType((DiameterDataType)5);
					m3GPPMSTimeZone->mspByteArray = mspByteArray;
					m3GPPMSTimeZone->mAvpDecodedFlag = false;
					m3GPPMSTimeZone->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2819:
				{
					if( NULL == this->setRANNASReleaseCause())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RANNASReleaseCause");
						throw lTssDiaMsgException;
					}
					mRANNASReleaseCause->setAvpCode(2819);
					mRANNASReleaseCause->setAvpVendorId(lVenderId);
					mRANNASReleaseCause->SetDataType((DiameterDataType)5);
					mRANNASReleaseCause->mspByteArray = mspByteArray;
					mRANNASReleaseCause->mAvpDecodedFlag = false;
					mRANNASReleaseCause->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 572:
				{
					mTagsPresent[STAnswer_FIVEGSRANNASRELEASECAUSE] = 1;
					FiveGSRANNASReleaseCause *lFiveGSRANNASReleaseCause = new FiveGSRANNASReleaseCause();
					if( lFiveGSRANNASReleaseCause == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FiveGSRANNASReleaseCause");
						throw lTssDiaMsgException;
					}
					lFiveGSRANNASReleaseCause->setAvpCode(572);
					lFiveGSRANNASReleaseCause->SetDataType((DiameterDataType)6);
					lFiveGSRANNASReleaseCause->mspByteArray = mspByteArray;
					lFiveGSRANNASReleaseCause->mAvpDecodedFlag = false;
					lFiveGSRANNASReleaseCause->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mFiveGSRANNASReleaseCauseGrpList == NULL)
						this->setFiveGSRANNASReleaseCauseGrpList();
					mFiveGSRANNASReleaseCauseGrpList->push_back(lFiveGSRANNASReleaseCause);
					mBaseInterfaceList.push_back(lFiveGSRANNASReleaseCause);
					
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
			case 29:
				{
					if( NULL == this->setTWANIdentifier())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TWANIdentifier");
						throw lTssDiaMsgException;
					}
					mTWANIdentifier->setAvpCode(29);
					mTWANIdentifier->setAvpVendorId(lVenderId);
					mTWANIdentifier->SetDataType((DiameterDataType)5);
					mTWANIdentifier->mspByteArray = mspByteArray;
					mTWANIdentifier->mAvpDecodedFlag = false;
					mTWANIdentifier->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2843:
				{
					if( NULL == this->setTCPSourcePort())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TCPSourcePort");
						throw lTssDiaMsgException;
					}
					mTCPSourcePort->setAvpCode(2843);
					mTCPSourcePort->setAvpVendorId(lVenderId);
					mTCPSourcePort->SetDataType((DiameterDataType)3);
					mTCPSourcePort->mspByteArray = mspByteArray;
					mTCPSourcePort->mAvpDecodedFlag = false;
					mTCPSourcePort->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2806:
				{
					if( NULL == this->setUDPSourcePort())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UDPSourcePort");
						throw lTssDiaMsgException;
					}
					mUDPSourcePort->setAvpCode(2806);
					mUDPSourcePort->setAvpVendorId(lVenderId);
					mUDPSourcePort->SetDataType((DiameterDataType)3);
					mUDPSourcePort->mspByteArray = mspByteArray;
					mUDPSourcePort->mAvpDecodedFlag = false;
					mUDPSourcePort->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2805:
				{
					if( NULL == this->setUELocalIPAddress())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UELocalIPAddress");
						throw lTssDiaMsgException;
					}
					mUELocalIPAddress->setAvpCode(2805);
					mUELocalIPAddress->setAvpVendorId(lVenderId);
					mUELocalIPAddress->SetDataType((DiameterDataType)8);
					mUELocalIPAddress->mspByteArray = mspByteArray;
					mUELocalIPAddress->mAvpDecodedFlag = false;
					mUELocalIPAddress->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

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
			case 578:
				{
					mTagsPresent[STAnswer_WIRELINEUSERLOCATIONINFO] = 1;
					WirelineUserLocationInfo *lWirelineUserLocationInfo = new WirelineUserLocationInfo();
					if( lWirelineUserLocationInfo == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding WirelineUserLocationInfo");
						throw lTssDiaMsgException;
					}
					lWirelineUserLocationInfo->setAvpCode(578);
					lWirelineUserLocationInfo->SetDataType((DiameterDataType)6);
					lWirelineUserLocationInfo->mspByteArray = mspByteArray;
					lWirelineUserLocationInfo->mAvpDecodedFlag = false;
					lWirelineUserLocationInfo->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mWirelineUserLocationInfoGrpList == NULL)
						this->setWirelineUserLocationInfoGrpList();
					mWirelineUserLocationInfoGrpList->push_back(lWirelineUserLocationInfo);
					mBaseInterfaceList.push_back(lWirelineUserLocationInfo);
					
				}
				break;
			case 25:
				{
						mMandatoryAvpSetVal [STAnswer_CLASS] = 1;
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
			case 292:
				{
						mMandatoryAvpSetVal [STAnswer_REDIRECTHOST] = 1;
					mTagsPresent[STAnswer_REDIRECTHOST] = 1;
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
						mMandatoryAvpSetVal [STAnswer_REDIRECTHOSTUSAGE] = 1;
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
						mMandatoryAvpSetVal [STAnswer_REDIRECTMAXCACHETIME] = 1;
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
						mMandatoryAvpSetVal [STAnswer_PROXYINFO] = 1;
					mTagsPresent[STAnswer_PROXYINFO] = 1;
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
						mMandatoryAvpSetVal [STAnswer_LOAD] = 1;
					mTagsPresent[STAnswer_LOAD] = 1;
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


DiameterBaseInterface* STAnswer::Find(byteArray *array, UINT32 avpCode)
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
			case 278:
			{
				if(mOriginStateId != NULL)
					return mOriginStateId->Find(array, avpCode);
				else
					return NULL;
			}
			case 22:
			{
				if(m3GPPUserLocationInfo != NULL)
					return m3GPPUserLocationInfo->Find(array, avpCode);
				else
					return NULL;
			}
			case 2812:
			{
				if(mUserLocationInfoTime != NULL)
					return mUserLocationInfoTime->Find(array, avpCode);
				else
					return NULL;
			}
			case 23:
			{
				if(m3GPPMSTimeZone != NULL)
					return m3GPPMSTimeZone->Find(array, avpCode);
				else
					return NULL;
			}
			case 2819:
			{
				if(mRANNASReleaseCause != NULL)
					return mRANNASReleaseCause->Find(array, avpCode);
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
			case 29:
			{
				if(mTWANIdentifier != NULL)
					return mTWANIdentifier->Find(array, avpCode);
				else
					return NULL;
			}
			case 2843:
			{
				if(mTCPSourcePort != NULL)
					return mTCPSourcePort->Find(array, avpCode);
				else
					return NULL;
			}
			case 2806:
			{
				if(mUDPSourcePort != NULL)
					return mUDPSourcePort->Find(array, avpCode);
				else
					return NULL;
			}
			case 2805:
			{
				if(mUELocalIPAddress != NULL)
					return mUELocalIPAddress->Find(array, avpCode);
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
			case 25:
			{
				if(mClass != NULL)
					return mClass->Find(array, avpCode);
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


BOOLEAN STAnswer::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
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
			case 530:
			{
				if(mSponsoredConnectivityDataGrpList != NULL)
				{
					for(auto itr = mSponsoredConnectivityDataGrpList->begin(); itr != mSponsoredConnectivityDataGrpList->end(); ++itr)
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
			case 22:
			{
				if(m3GPPUserLocationInfo != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPUserLocationInfo->Find(this->mspByteArray.get(), avpCode);
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
			case 2812:
			{
				if(mUserLocationInfoTime != NULL)
				{
					DiameterBaseInterface* inf =  mUserLocationInfoTime->Find(this->mspByteArray.get(), avpCode);
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
			case 23:
			{
				if(m3GPPMSTimeZone != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPMSTimeZone->Find(this->mspByteArray.get(), avpCode);
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
			case 2819:
			{
				if(mRANNASReleaseCause != NULL)
				{
					DiameterBaseInterface* inf =  mRANNASReleaseCause->Find(this->mspByteArray.get(), avpCode);
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
			case 572:
			{
				if(mFiveGSRANNASReleaseCauseGrpList != NULL)
				{
					for(auto itr = mFiveGSRANNASReleaseCauseGrpList->begin(); itr != mFiveGSRANNASReleaseCauseGrpList->end(); ++itr)
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
			case 29:
			{
				if(mTWANIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mTWANIdentifier->Find(this->mspByteArray.get(), avpCode);
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
			case 2843:
			{
				if(mTCPSourcePort != NULL)
				{
					DiameterBaseInterface* inf =  mTCPSourcePort->Find(this->mspByteArray.get(), avpCode);
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
			case 2806:
			{
				if(mUDPSourcePort != NULL)
				{
					DiameterBaseInterface* inf =  mUDPSourcePort->Find(this->mspByteArray.get(), avpCode);
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
			case 2805:
			{
				if(mUELocalIPAddress != NULL)
				{
					DiameterBaseInterface* inf =  mUELocalIPAddress->Find(this->mspByteArray.get(), avpCode);
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
			case 578:
			{
				if(mWirelineUserLocationInfoGrpList != NULL)
				{
					for(auto itr = mWirelineUserLocationInfoGrpList->begin(); itr != mWirelineUserLocationInfoGrpList->end(); ++itr)
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
std::shared_ptr<byteArray> STAnswer::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN STAnswer::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
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
			case 530:
			{
				if(mSponsoredConnectivityDataGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mSponsoredConnectivityDataGrpList->begin(); itr != mSponsoredConnectivityDataGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mSponsoredConnectivityDataGrpList->begin(); itr != mSponsoredConnectivityDataGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
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
			case 22:
			{
				if(m3GPPUserLocationInfo != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPUserLocationInfo->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2812:
			{
				if(mUserLocationInfoTime != NULL)
				{
					DiameterBaseInterface* inf =  mUserLocationInfoTime->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 23:
			{
				if(m3GPPMSTimeZone != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPMSTimeZone->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2819:
			{
				if(mRANNASReleaseCause != NULL)
				{
					DiameterBaseInterface* inf =  mRANNASReleaseCause->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 572:
			{
				if(mFiveGSRANNASReleaseCauseGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mFiveGSRANNASReleaseCauseGrpList->begin(); itr != mFiveGSRANNASReleaseCauseGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mFiveGSRANNASReleaseCauseGrpList->begin(); itr != mFiveGSRANNASReleaseCauseGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
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
			case 29:
			{
				if(mTWANIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mTWANIdentifier->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2843:
			{
				if(mTCPSourcePort != NULL)
				{
					DiameterBaseInterface* inf =  mTCPSourcePort->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2806:
			{
				if(mUDPSourcePort != NULL)
				{
					DiameterBaseInterface* inf =  mUDPSourcePort->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2805:
			{
				if(mUELocalIPAddress != NULL)
				{
					DiameterBaseInterface* inf =  mUELocalIPAddress->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
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
			case 578:
			{
				if(mWirelineUserLocationInfoGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mWirelineUserLocationInfoGrpList->begin(); itr != mWirelineUserLocationInfoGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mWirelineUserLocationInfoGrpList->begin(); itr != mWirelineUserLocationInfoGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
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




void STAnswer::Display(UINT32 tab)
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
			case STAnswer_SESSIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "263" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SessionId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getSessionId()->Display(tab+1);
			}
				break;
			case STAnswer_DRMP:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "301" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DRMP" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getDRMP()->Display(tab+1);
			}
				break;
			case STAnswer_ORIGINHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "264" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginHost()->Display(tab+1);
			}
				break;
			case STAnswer_ORIGINREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "296" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginRealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginRealm()->Display(tab+1);
			}
				break;
			case STAnswer_RESULTCODE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "268" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ResultCode" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getResultCode()->Display(tab+1);
			}
				break;
			case STAnswer_ERRORMESSAGE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "281" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ErrorMessage" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(32)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(32)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(32)==true)?"Protected":""));
				this->getErrorMessage()->Display(tab+1);
			}
				break;
			case STAnswer_ERRORREPORTINGHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "294" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ErrorReportingHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getErrorReportingHost()->Display(tab+1);
			}
				break;
			case STAnswer_OCSUPPORTEDFEATURES:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "621" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OCSupportedFeatures" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getOCSupportedFeatures()->Display(tab+1);
			}
				break;
			case STAnswer_OCOLR:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "623" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OCOLR" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getOCOLR()->Display(tab+1);
			}
				break;
			case STAnswer_FAILEDAVP:
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
			case STAnswer_SPONSOREDCONNECTIVITYDATA:
			{
				if( mSponsoredConnectivityDataGrpList->size() <= 0) {
					break;
				}

				mSponsoredConnectivityDataGrpIterator = this->getSponsoredConnectivityDataGrpList()->begin();
				while(mSponsoredConnectivityDataGrpIterator != this->getSponsoredConnectivityDataGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "530" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SponsoredConnectivityData" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
					(*mSponsoredConnectivityDataGrpIterator)->Display(tab+1);
					mSponsoredConnectivityDataGrpIterator++;

				};

			}
				break;
			case STAnswer_ORIGINSTATEID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "278" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginStateId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginStateId()->Display(tab+1);
			}
				break;
			case STAnswer_3GPPUSERLOCATIONINFO:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "22" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPPUserLocationInfo" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->get3GPPUserLocationInfo()->Display(tab+1);
			}
				break;
			case STAnswer_USERLOCATIONINFOTIME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2812" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserLocationInfoTime" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getUserLocationInfoTime()->Display(tab+1);
			}
				break;
			case STAnswer_3GPPMSTIMEZONE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "23" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPPMSTimeZone" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->get3GPPMSTimeZone()->Display(tab+1);
			}
				break;
			case STAnswer_RANNASRELEASECAUSE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2819" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RANNASReleaseCause" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getRANNASReleaseCause()->Display(tab+1);
			}
				break;
			case STAnswer_FIVEGSRANNASRELEASECAUSE:
			{
				if( mFiveGSRANNASReleaseCauseGrpList->size() <= 0) {
					break;
				}

				mFiveGSRANNASReleaseCauseGrpIterator = this->getFiveGSRANNASReleaseCauseGrpList()->begin();
				while(mFiveGSRANNASReleaseCauseGrpIterator != this->getFiveGSRANNASReleaseCauseGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "572" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FiveGSRANNASReleaseCause" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
					(*mFiveGSRANNASReleaseCauseGrpIterator)->Display(tab+1);
					mFiveGSRANNASReleaseCauseGrpIterator++;

				};

			}
				break;
			case STAnswer_3GPPSGSNMCCMNC:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "18" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPPSGSNMCCMNC" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->get3GPPSGSNMCCMNC()->Display(tab+1);
			}
				break;
			case STAnswer_NID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "569" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "NID" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getNID()->Display(tab+1);
			}
				break;
			case STAnswer_TWANIDENTIFIER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "29" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "TWANIdentifier" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getTWANIdentifier()->Display(tab+1);
			}
				break;
			case STAnswer_TCPSOURCEPORT:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2843" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "TCPSourcePort" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getTCPSourcePort()->Display(tab+1);
			}
				break;
			case STAnswer_UDPSOURCEPORT:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2806" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UDPSourcePort" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getUDPSourcePort()->Display(tab+1);
			}
				break;
			case STAnswer_UELOCALIPADDRESS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2805" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UELocalIPAddress" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getUELocalIPAddress()->Display(tab+1);
			}
				break;
			case STAnswer_NETLOCACCESSSUPPORT:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2824" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "NetLocAccessSupport" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getNetLocAccessSupport()->Display(tab+1);
			}
				break;
			case STAnswer_WIRELINEUSERLOCATIONINFO:
			{
				if( mWirelineUserLocationInfoGrpList->size() <= 0) {
					break;
				}

				mWirelineUserLocationInfoGrpIterator = this->getWirelineUserLocationInfoGrpList()->begin();
				while(mWirelineUserLocationInfoGrpIterator != this->getWirelineUserLocationInfoGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "578" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "WirelineUserLocationInfo" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
					(*mWirelineUserLocationInfoGrpIterator)->Display(tab+1);
					mWirelineUserLocationInfoGrpIterator++;

				};

			}
				break;
			case STAnswer_CLASS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "25" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "Class" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getClass()->Display(tab+1);
			}
				break;
			case STAnswer_REDIRECTHOST:
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
			case STAnswer_REDIRECTHOSTUSAGE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "261" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RedirectHostUsage" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getRedirectHostUsage()->Display(tab+1);
			}
				break;
			case STAnswer_REDIRECTMAXCACHETIME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "262" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RedirectMaxCacheTime" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getRedirectMaxCacheTime()->Display(tab+1);
			}
				break;
			case STAnswer_PROXYINFO:
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
			case STAnswer_LOAD:
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


BOOLEAN STAnswer::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<31> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case STAnswer_SESSIONID:
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
			case STAnswer_DRMP:
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
			case STAnswer_ORIGINHOST:
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
			case STAnswer_ORIGINREALM:
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
			case STAnswer_RESULTCODE:
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
			case STAnswer_ERRORMESSAGE:
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
			case STAnswer_ERRORREPORTINGHOST:
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
			case STAnswer_OCSUPPORTEDFEATURES:
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
			case STAnswer_OCOLR:
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
			case STAnswer_FAILEDAVP:
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
			case STAnswer_SPONSOREDCONNECTIVITYDATA:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 530");
				}
				else
					sprintf(lMissingAvpInfo, "%s,530", lMissingAvpInfo);
			}
				break;
			case STAnswer_ORIGINSTATEID:
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
			case STAnswer_3GPPUSERLOCATIONINFO:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 22");
				}
				else
					sprintf(lMissingAvpInfo, "%s,22", lMissingAvpInfo);
			}
				break;
			case STAnswer_USERLOCATIONINFOTIME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2812");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2812", lMissingAvpInfo);
			}
				break;
			case STAnswer_3GPPMSTIMEZONE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 23");
				}
				else
					sprintf(lMissingAvpInfo, "%s,23", lMissingAvpInfo);
			}
				break;
			case STAnswer_RANNASRELEASECAUSE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2819");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2819", lMissingAvpInfo);
			}
				break;
			case STAnswer_FIVEGSRANNASRELEASECAUSE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 572");
				}
				else
					sprintf(lMissingAvpInfo, "%s,572", lMissingAvpInfo);
			}
				break;
			case STAnswer_3GPPSGSNMCCMNC:
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
			case STAnswer_NID:
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
			case STAnswer_TWANIDENTIFIER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 29");
				}
				else
					sprintf(lMissingAvpInfo, "%s,29", lMissingAvpInfo);
			}
				break;
			case STAnswer_TCPSOURCEPORT:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2843");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2843", lMissingAvpInfo);
			}
				break;
			case STAnswer_UDPSOURCEPORT:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2806");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2806", lMissingAvpInfo);
			}
				break;
			case STAnswer_UELOCALIPADDRESS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2805");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2805", lMissingAvpInfo);
			}
				break;
			case STAnswer_NETLOCACCESSSUPPORT:
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
			case STAnswer_WIRELINEUSERLOCATIONINFO:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 578");
				}
				else
					sprintf(lMissingAvpInfo, "%s,578", lMissingAvpInfo);
			}
				break;
			case STAnswer_CLASS:
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
			case STAnswer_REDIRECTHOST:
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
			case STAnswer_REDIRECTHOSTUSAGE:
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
			case STAnswer_REDIRECTMAXCACHETIME:
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
			case STAnswer_PROXYINFO:
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
			case STAnswer_LOAD:
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
