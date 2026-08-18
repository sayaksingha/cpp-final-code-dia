#include "rx/include/RARequest.h"

using namespace RX;
BOOLEAN RARequest::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

RARequest::RARequest()
{
	mSessionId = NULL;
	mDRMP = NULL;
	mOriginHost = NULL;
	mOriginRealm = NULL;
	mDestinationRealm = NULL;
	mDestinationHost = NULL;
	mAuthApplicationId = NULL;
	mSpecificActionList = NULL;
	mOCSupportedFeaturesGrp = NULL;
	mAccessNetworkChargingIdentifierGrpList = NULL;
	mAccessNetworkChargingAddress = NULL;
	mANGWAddressList = NULL;
	mANTrusted = NULL;
	mFlowsGrpList = NULL;
	mSubscriptionIdGrpList = NULL;
	mAbortCause = NULL;
	mIPCANType = NULL;
	mMAInformationGrpList = NULL;
	mNetLocAccessSupport = NULL;
	mRATType = NULL;
	mSponsoredConnectivityDataGrpList = NULL;
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
	mWirelineUserLocationInfoGrpList = NULL;
	mOriginStateId = NULL;
	mClass = NULL;
	mProxyInfoGrpList = NULL;
	mRouteRecordList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<37>(string("1111000000000000000011111011011111101"));
	mMandatoryAvpSetVal.reset();
}

RARequest::~RARequest()
{
	if(mSessionId != NULL)
		delete mSessionId;
	if(mDRMP != NULL)
		delete mDRMP;
	if(mOriginHost != NULL)
		delete mOriginHost;
	if(mOriginRealm != NULL)
		delete mOriginRealm;
	if(mDestinationRealm != NULL)
		delete mDestinationRealm;
	if(mDestinationHost != NULL)
		delete mDestinationHost;
	if(mAuthApplicationId != NULL)
		delete mAuthApplicationId;
	if(mSpecificActionList != NULL){
		mSpecificActionIterator = mSpecificActionList->begin();
		while(mSpecificActionIterator != mSpecificActionList->end()){
			delete (*mSpecificActionIterator);
			mSpecificActionIterator++;
		}
		delete mSpecificActionList;
	}
	if(mOCSupportedFeaturesGrp != NULL)
		delete mOCSupportedFeaturesGrp;
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
	if(mFlowsGrpList != NULL){
		mFlowsGrpIterator = mFlowsGrpList->begin();
		while(mFlowsGrpIterator != mFlowsGrpList->end()){
	if(*mFlowsGrpIterator != NULL)
			delete (*mFlowsGrpIterator);
			mFlowsGrpIterator++;
		}
		delete mFlowsGrpList;
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
	if(mAbortCause != NULL)
		delete mAbortCause;
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
	if(mSponsoredConnectivityDataGrpList != NULL){
		mSponsoredConnectivityDataGrpIterator = mSponsoredConnectivityDataGrpList->begin();
		while(mSponsoredConnectivityDataGrpIterator != mSponsoredConnectivityDataGrpList->end()){
	if(*mSponsoredConnectivityDataGrpIterator != NULL)
			delete (*mSponsoredConnectivityDataGrpIterator);
			mSponsoredConnectivityDataGrpIterator++;
		}
		delete mSponsoredConnectivityDataGrpList;
	}
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
	if(mWirelineUserLocationInfoGrpList != NULL){
		mWirelineUserLocationInfoGrpIterator = mWirelineUserLocationInfoGrpList->begin();
		while(mWirelineUserLocationInfoGrpIterator != mWirelineUserLocationInfoGrpList->end()){
	if(*mWirelineUserLocationInfoGrpIterator != NULL)
			delete (*mWirelineUserLocationInfoGrpIterator);
			mWirelineUserLocationInfoGrpIterator++;
		}
		delete mWirelineUserLocationInfoGrpList;
	}
	if(mOriginStateId != NULL)
		delete mOriginStateId;
	if(mClass != NULL)
		delete mClass;
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

OctetString* RARequest::setSessionId(){
	mMandatoryAvpSetVal [RARequest_SESSIONID] = 1;
	if(mSessionId == NULL)
	{
		mSessionId = new OctetString();
		mTagsPresent[RARequest_SESSIONID] = 1;
		return mSessionId;
	}
	return mSessionId;
}

void RARequest::resetSessionId(){
	mTagsPresent[RARequest_SESSIONID] = 0;
	if(mSessionId != NULL)
	{
		delete mSessionId; 
		mSessionId = NULL;
	}
}

DRMP* RARequest::setDRMP(){
	if(mDRMP == NULL)
	{
		mDRMP = new DRMP();
		mTagsPresent[RARequest_DRMP] = 1;
		return mDRMP;
	}
	return mDRMP;
}

void RARequest::resetDRMP(){
	mTagsPresent[RARequest_DRMP] = 0;
	if(mDRMP != NULL)
	{
		delete mDRMP; 
		mDRMP = NULL;
	}
}

OctetString* RARequest::setOriginHost(){
	mMandatoryAvpSetVal [RARequest_ORIGINHOST] = 1;
	if(mOriginHost == NULL)
	{
		mOriginHost = new OctetString();
		mTagsPresent[RARequest_ORIGINHOST] = 1;
		return mOriginHost;
	}
	return mOriginHost;
}

void RARequest::resetOriginHost(){
	mTagsPresent[RARequest_ORIGINHOST] = 0;
	if(mOriginHost != NULL)
	{
		delete mOriginHost; 
		mOriginHost = NULL;
	}
}

OctetString* RARequest::setOriginRealm(){
	mMandatoryAvpSetVal [RARequest_ORIGINREALM] = 1;
	if(mOriginRealm == NULL)
	{
		mOriginRealm = new OctetString();
		mTagsPresent[RARequest_ORIGINREALM] = 1;
		return mOriginRealm;
	}
	return mOriginRealm;
}

void RARequest::resetOriginRealm(){
	mTagsPresent[RARequest_ORIGINREALM] = 0;
	if(mOriginRealm != NULL)
	{
		delete mOriginRealm; 
		mOriginRealm = NULL;
	}
}

OctetString* RARequest::setDestinationRealm(){
	mMandatoryAvpSetVal [RARequest_DESTINATIONREALM] = 1;
	if(mDestinationRealm == NULL)
	{
		mDestinationRealm = new OctetString();
		mTagsPresent[RARequest_DESTINATIONREALM] = 1;
		return mDestinationRealm;
	}
	return mDestinationRealm;
}

void RARequest::resetDestinationRealm(){
	mTagsPresent[RARequest_DESTINATIONREALM] = 0;
	if(mDestinationRealm != NULL)
	{
		delete mDestinationRealm; 
		mDestinationRealm = NULL;
	}
}

OctetString* RARequest::setDestinationHost(){
	mMandatoryAvpSetVal [RARequest_DESTINATIONHOST] = 1;
	if(mDestinationHost == NULL)
	{
		mDestinationHost = new OctetString();
		mTagsPresent[RARequest_DESTINATIONHOST] = 1;
		return mDestinationHost;
	}
	return mDestinationHost;
}

void RARequest::resetDestinationHost(){
	mTagsPresent[RARequest_DESTINATIONHOST] = 0;
	if(mDestinationHost != NULL)
	{
		delete mDestinationHost; 
		mDestinationHost = NULL;
	}
}

Integer32* RARequest::setAuthApplicationId(){
	mMandatoryAvpSetVal [RARequest_AUTHAPPLICATIONID] = 1;
	if(mAuthApplicationId == NULL)
	{
		mAuthApplicationId = new Integer32();
		mTagsPresent[RARequest_AUTHAPPLICATIONID] = 1;
		return mAuthApplicationId;
	}
	return mAuthApplicationId;
}

void RARequest::resetAuthApplicationId(){
	mTagsPresent[RARequest_AUTHAPPLICATIONID] = 0;
	if(mAuthApplicationId != NULL)
	{
		delete mAuthApplicationId; 
		mAuthApplicationId = NULL;
	}
}

Address* RARequest::setAccessNetworkChargingAddress(){
	mMandatoryAvpSetVal [RARequest_ACCESSNETWORKCHARGINGADDRESS] = 1;
	if(mAccessNetworkChargingAddress == NULL)
	{
		mAccessNetworkChargingAddress = new Address();
		mTagsPresent[RARequest_ACCESSNETWORKCHARGINGADDRESS] = 1;
		return mAccessNetworkChargingAddress;
	}
	return mAccessNetworkChargingAddress;
}

void RARequest::resetAccessNetworkChargingAddress(){
	mTagsPresent[RARequest_ACCESSNETWORKCHARGINGADDRESS] = 0;
	if(mAccessNetworkChargingAddress != NULL)
	{
		delete mAccessNetworkChargingAddress; 
		mAccessNetworkChargingAddress = NULL;
	}
}

ANTrusted* RARequest::setANTrusted(){
	mMandatoryAvpSetVal [RARequest_ANTRUSTED] = 1;
	if(mANTrusted == NULL)
	{
		mANTrusted = new ANTrusted();
		mTagsPresent[RARequest_ANTRUSTED] = 1;
		return mANTrusted;
	}
	return mANTrusted;
}

void RARequest::resetANTrusted(){
	mTagsPresent[RARequest_ANTRUSTED] = 0;
	if(mANTrusted != NULL)
	{
		delete mANTrusted; 
		mANTrusted = NULL;
	}
}

AbortCause* RARequest::setAbortCause(){
	mMandatoryAvpSetVal [RARequest_ABORTCAUSE] = 1;
	if(mAbortCause == NULL)
	{
		mAbortCause = new AbortCause();
		mTagsPresent[RARequest_ABORTCAUSE] = 1;
		return mAbortCause;
	}
	return mAbortCause;
}

void RARequest::resetAbortCause(){
	mTagsPresent[RARequest_ABORTCAUSE] = 0;
	if(mAbortCause != NULL)
	{
		delete mAbortCause; 
		mAbortCause = NULL;
	}
}

IPCANType* RARequest::setIPCANType(){
	mMandatoryAvpSetVal [RARequest_IPCANTYPE] = 1;
	if(mIPCANType == NULL)
	{
		mIPCANType = new IPCANType();
		mTagsPresent[RARequest_IPCANTYPE] = 1;
		return mIPCANType;
	}
	return mIPCANType;
}

void RARequest::resetIPCANType(){
	mTagsPresent[RARequest_IPCANTYPE] = 0;
	if(mIPCANType != NULL)
	{
		delete mIPCANType; 
		mIPCANType = NULL;
	}
}

Unsigned32* RARequest::setNetLocAccessSupport(){
	if(mNetLocAccessSupport == NULL)
	{
		mNetLocAccessSupport = new Unsigned32();
		mTagsPresent[RARequest_NETLOCACCESSSUPPORT] = 1;
		return mNetLocAccessSupport;
	}
	return mNetLocAccessSupport;
}

void RARequest::resetNetLocAccessSupport(){
	mTagsPresent[RARequest_NETLOCACCESSSUPPORT] = 0;
	if(mNetLocAccessSupport != NULL)
	{
		delete mNetLocAccessSupport; 
		mNetLocAccessSupport = NULL;
	}
}

RATType* RARequest::setRATType(){
	if(mRATType == NULL)
	{
		mRATType = new RATType();
		mTagsPresent[RARequest_RATTYPE] = 1;
		return mRATType;
	}
	return mRATType;
}

void RARequest::resetRATType(){
	mTagsPresent[RARequest_RATTYPE] = 0;
	if(mRATType != NULL)
	{
		delete mRATType; 
		mRATType = NULL;
	}
}

OctetString* RARequest::set3GPPUserLocationInfo(){
	if(m3GPPUserLocationInfo == NULL)
	{
		m3GPPUserLocationInfo = new OctetString();
		mTagsPresent[RARequest_3GPPUSERLOCATIONINFO] = 1;
		return m3GPPUserLocationInfo;
	}
	return m3GPPUserLocationInfo;
}

void RARequest::reset3GPPUserLocationInfo(){
	mTagsPresent[RARequest_3GPPUSERLOCATIONINFO] = 0;
	if(m3GPPUserLocationInfo != NULL)
	{
		delete m3GPPUserLocationInfo; 
		m3GPPUserLocationInfo = NULL;
	}
}

Time* RARequest::setUserLocationInfoTime(){
	if(mUserLocationInfoTime == NULL)
	{
		mUserLocationInfoTime = new Time();
		mTagsPresent[RARequest_USERLOCATIONINFOTIME] = 1;
		return mUserLocationInfoTime;
	}
	return mUserLocationInfoTime;
}

void RARequest::resetUserLocationInfoTime(){
	mTagsPresent[RARequest_USERLOCATIONINFOTIME] = 0;
	if(mUserLocationInfoTime != NULL)
	{
		delete mUserLocationInfoTime; 
		mUserLocationInfoTime = NULL;
	}
}

OctetString* RARequest::set3GPPMSTimeZone(){
	if(m3GPPMSTimeZone == NULL)
	{
		m3GPPMSTimeZone = new OctetString();
		mTagsPresent[RARequest_3GPPMSTIMEZONE] = 1;
		return m3GPPMSTimeZone;
	}
	return m3GPPMSTimeZone;
}

void RARequest::reset3GPPMSTimeZone(){
	mTagsPresent[RARequest_3GPPMSTIMEZONE] = 0;
	if(m3GPPMSTimeZone != NULL)
	{
		delete m3GPPMSTimeZone; 
		m3GPPMSTimeZone = NULL;
	}
}

OctetString* RARequest::setRANNASReleaseCause(){
	if(mRANNASReleaseCause == NULL)
	{
		mRANNASReleaseCause = new OctetString();
		mTagsPresent[RARequest_RANNASRELEASECAUSE] = 1;
		return mRANNASReleaseCause;
	}
	return mRANNASReleaseCause;
}

void RARequest::resetRANNASReleaseCause(){
	mTagsPresent[RARequest_RANNASRELEASECAUSE] = 0;
	if(mRANNASReleaseCause != NULL)
	{
		delete mRANNASReleaseCause; 
		mRANNASReleaseCause = NULL;
	}
}

OctetString* RARequest::set3GPPSGSNMCCMNC(){
	if(m3GPPSGSNMCCMNC == NULL)
	{
		m3GPPSGSNMCCMNC = new OctetString();
		mTagsPresent[RARequest_3GPPSGSNMCCMNC] = 1;
		return m3GPPSGSNMCCMNC;
	}
	return m3GPPSGSNMCCMNC;
}

void RARequest::reset3GPPSGSNMCCMNC(){
	mTagsPresent[RARequest_3GPPSGSNMCCMNC] = 0;
	if(m3GPPSGSNMCCMNC != NULL)
	{
		delete m3GPPSGSNMCCMNC; 
		m3GPPSGSNMCCMNC = NULL;
	}
}

OctetString* RARequest::setNID(){
	if(mNID == NULL)
	{
		mNID = new OctetString();
		mTagsPresent[RARequest_NID] = 1;
		return mNID;
	}
	return mNID;
}

void RARequest::resetNID(){
	mTagsPresent[RARequest_NID] = 0;
	if(mNID != NULL)
	{
		delete mNID; 
		mNID = NULL;
	}
}

OctetString* RARequest::setTWANIdentifier(){
	if(mTWANIdentifier == NULL)
	{
		mTWANIdentifier = new OctetString();
		mTagsPresent[RARequest_TWANIDENTIFIER] = 1;
		return mTWANIdentifier;
	}
	return mTWANIdentifier;
}

void RARequest::resetTWANIdentifier(){
	mTagsPresent[RARequest_TWANIDENTIFIER] = 0;
	if(mTWANIdentifier != NULL)
	{
		delete mTWANIdentifier; 
		mTWANIdentifier = NULL;
	}
}

Unsigned32* RARequest::setTCPSourcePort(){
	if(mTCPSourcePort == NULL)
	{
		mTCPSourcePort = new Unsigned32();
		mTagsPresent[RARequest_TCPSOURCEPORT] = 1;
		return mTCPSourcePort;
	}
	return mTCPSourcePort;
}

void RARequest::resetTCPSourcePort(){
	mTagsPresent[RARequest_TCPSOURCEPORT] = 0;
	if(mTCPSourcePort != NULL)
	{
		delete mTCPSourcePort; 
		mTCPSourcePort = NULL;
	}
}

Unsigned32* RARequest::setUDPSourcePort(){
	if(mUDPSourcePort == NULL)
	{
		mUDPSourcePort = new Unsigned32();
		mTagsPresent[RARequest_UDPSOURCEPORT] = 1;
		return mUDPSourcePort;
	}
	return mUDPSourcePort;
}

void RARequest::resetUDPSourcePort(){
	mTagsPresent[RARequest_UDPSOURCEPORT] = 0;
	if(mUDPSourcePort != NULL)
	{
		delete mUDPSourcePort; 
		mUDPSourcePort = NULL;
	}
}

Address* RARequest::setUELocalIPAddress(){
	if(mUELocalIPAddress == NULL)
	{
		mUELocalIPAddress = new Address();
		mTagsPresent[RARequest_UELOCALIPADDRESS] = 1;
		return mUELocalIPAddress;
	}
	return mUELocalIPAddress;
}

void RARequest::resetUELocalIPAddress(){
	mTagsPresent[RARequest_UELOCALIPADDRESS] = 0;
	if(mUELocalIPAddress != NULL)
	{
		delete mUELocalIPAddress; 
		mUELocalIPAddress = NULL;
	}
}

Unsigned32* RARequest::setOriginStateId(){
	mMandatoryAvpSetVal [RARequest_ORIGINSTATEID] = 1;
	if(mOriginStateId == NULL)
	{
		mOriginStateId = new Unsigned32();
		mTagsPresent[RARequest_ORIGINSTATEID] = 1;
		return mOriginStateId;
	}
	return mOriginStateId;
}

void RARequest::resetOriginStateId(){
	mTagsPresent[RARequest_ORIGINSTATEID] = 0;
	if(mOriginStateId != NULL)
	{
		delete mOriginStateId; 
		mOriginStateId = NULL;
	}
}

OctetString* RARequest::setClass(){
	mMandatoryAvpSetVal [RARequest_CLASS] = 1;
	if(mClass == NULL)
	{
		mClass = new OctetString();
		mTagsPresent[RARequest_CLASS] = 1;
		return mClass;
	}
	return mClass;
}

void RARequest::resetClass(){
	mTagsPresent[RARequest_CLASS] = 0;
	if(mClass != NULL)
	{
		delete mClass; 
		mClass = NULL;
	}
}

OctetString* RARequest::getSessionId(){
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

DRMP* RARequest::getDRMP(){
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

OctetString* RARequest::getOriginHost(){
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

OctetString* RARequest::getOriginRealm(){
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

OctetString* RARequest::getDestinationRealm(){
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

OctetString* RARequest::getDestinationHost(){
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

Integer32* RARequest::getAuthApplicationId(){
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

list<SpecificAction*>* RARequest::getSpecificActionList()
{
	if(mSpecificActionList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SpecificAction is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr :* mSpecificActionList)
	{
		if(!itr->mAvpDecodedFlag)
		{
	if(mspByteArray.get() == NULL)
		{
	itr->mAvpDecodedFlag = true;
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SpecificAction is Null");
		throw lTssDiaMsgException;
	}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SpecificAction")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mSpecificActionList;
}

list<SpecificAction*>* RARequest::setSpecificActionList() {
	mTagsPresent[RARequest_SPECIFICACTION] = 1;
	if(mSpecificActionList == NULL)
		mSpecificActionList = new list<SpecificAction*>;
	mMandatoryAvpSetVal [RARequest_SPECIFICACTION] = 1;
	mSpecificActionList->clear();
	return mSpecificActionList;
}

void RARequest::resetSpecificActionList(){
	mTagsPresent[RARequest_SPECIFICACTION] = 0;
	if(mSpecificActionList != NULL)
		delete mSpecificActionList;
}

OCSupportedFeatures* RARequest::getOCSupportedFeatures()
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

OCSupportedFeatures* RARequest::setOCSupportedFeatures(){
	if(mOCSupportedFeaturesGrp == NULL)
		mOCSupportedFeaturesGrp = new OCSupportedFeatures();
	mTagsPresent[RARequest_OCSUPPORTEDFEATURES] = 1;
	return mOCSupportedFeaturesGrp;
}

void RARequest::resetOCSupportedFeatures(){
	mTagsPresent[RARequest_OCSUPPORTEDFEATURES] = 0;
	if(mOCSupportedFeaturesGrp != NULL)
		delete mOCSupportedFeaturesGrp;
}

list<AccessNetworkChargingIdentifier*>* RARequest::getAccessNetworkChargingIdentifierGrpList()
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
			mTagsPresent[RARequest_ACCESSNETWORKCHARGINGIDENTIFIER] = 0;
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

list<AccessNetworkChargingIdentifier*>* RARequest::setAccessNetworkChargingIdentifierGrpList(){
	mTagsPresent[RARequest_ACCESSNETWORKCHARGINGIDENTIFIER] = 1;
	if(mAccessNetworkChargingIdentifierGrpList == NULL)
		mAccessNetworkChargingIdentifierGrpList = new list<AccessNetworkChargingIdentifier*>;
	mMandatoryAvpSetVal[RARequest_ACCESSNETWORKCHARGINGIDENTIFIER] = 1;
	mAccessNetworkChargingIdentifierGrpList->clear();
	return mAccessNetworkChargingIdentifierGrpList;
}

void RARequest::resetAccessNetworkChargingIdentifierGrpList(){
	mTagsPresent[RARequest_ACCESSNETWORKCHARGINGIDENTIFIER] = 0;
	if(mAccessNetworkChargingIdentifierGrpList != NULL)
		delete mAccessNetworkChargingIdentifierGrpList;
}

Address* RARequest::getAccessNetworkChargingAddress(){
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

list<Address*>* RARequest::getANGWAddressList()
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

list<Address*>* RARequest::setANGWAddressList() {
	mTagsPresent[RARequest_ANGWADDRESS] = 1;
	if(mANGWAddressList == NULL)
		mANGWAddressList = new list<Address*>;
	mANGWAddressList->clear();
	return mANGWAddressList;
}

void RARequest::resetANGWAddressList(){
	mTagsPresent[RARequest_ANGWADDRESS] = 0;
	if(mANGWAddressList != NULL)
		delete mANGWAddressList;
}

ANTrusted* RARequest::getANTrusted(){
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

list<Flows*>* RARequest::getFlowsGrpList()
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
			mTagsPresent[RARequest_FLOWS] = 0;
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

list<Flows*>* RARequest::setFlowsGrpList(){
	mTagsPresent[RARequest_FLOWS] = 1;
	if(mFlowsGrpList == NULL)
		mFlowsGrpList = new list<Flows*>;
	mMandatoryAvpSetVal[RARequest_FLOWS] = 1;
	mFlowsGrpList->clear();
	return mFlowsGrpList;
}

void RARequest::resetFlowsGrpList(){
	mTagsPresent[RARequest_FLOWS] = 0;
	if(mFlowsGrpList != NULL)
		delete mFlowsGrpList;
}

list<SubscriptionId*>* RARequest::getSubscriptionIdGrpList()
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
			mTagsPresent[RARequest_SUBSCRIPTIONID] = 0;
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

list<SubscriptionId*>* RARequest::setSubscriptionIdGrpList(){
	mTagsPresent[RARequest_SUBSCRIPTIONID] = 1;
	if(mSubscriptionIdGrpList == NULL)
		mSubscriptionIdGrpList = new list<SubscriptionId*>;
	mMandatoryAvpSetVal[RARequest_SUBSCRIPTIONID] = 1;
	mSubscriptionIdGrpList->clear();
	return mSubscriptionIdGrpList;
}

void RARequest::resetSubscriptionIdGrpList(){
	mTagsPresent[RARequest_SUBSCRIPTIONID] = 0;
	if(mSubscriptionIdGrpList != NULL)
		delete mSubscriptionIdGrpList;
}

AbortCause* RARequest::getAbortCause(){
	if(NULL == mAbortCause) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AbortCause is Null");
		throw lTssDiaMsgException;
	}
	if(!mAbortCause->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAbortCause->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AbortCause is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAbortCause->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAbortCause->Decode(mspByteArray.get(), mAbortCause->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AbortCause")     ;
			throw lTssDiaMsgException;
		}
		mAbortCause->mAvpDecodedFlag = true;
	}
	return mAbortCause;
}

IPCANType* RARequest::getIPCANType(){
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

list<MAInformation*>* RARequest::getMAInformationGrpList()
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
			mTagsPresent[RARequest_MAINFORMATION] = 0;
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

list<MAInformation*>* RARequest::setMAInformationGrpList(){
	mTagsPresent[RARequest_MAINFORMATION] = 1;
	if(mMAInformationGrpList == NULL)
		mMAInformationGrpList = new list<MAInformation*>;
	mMAInformationGrpList->clear();
	return mMAInformationGrpList;
}

void RARequest::resetMAInformationGrpList(){
	mTagsPresent[RARequest_MAINFORMATION] = 0;
	if(mMAInformationGrpList != NULL)
		delete mMAInformationGrpList;
}

Unsigned32* RARequest::getNetLocAccessSupport(){
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

RATType* RARequest::getRATType(){
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

list<SponsoredConnectivityData*>* RARequest::getSponsoredConnectivityDataGrpList()
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
			mTagsPresent[RARequest_SPONSOREDCONNECTIVITYDATA] = 0;
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

list<SponsoredConnectivityData*>* RARequest::setSponsoredConnectivityDataGrpList(){
	mTagsPresent[RARequest_SPONSOREDCONNECTIVITYDATA] = 1;
	if(mSponsoredConnectivityDataGrpList == NULL)
		mSponsoredConnectivityDataGrpList = new list<SponsoredConnectivityData*>;
	mSponsoredConnectivityDataGrpList->clear();
	return mSponsoredConnectivityDataGrpList;
}

void RARequest::resetSponsoredConnectivityDataGrpList(){
	mTagsPresent[RARequest_SPONSOREDCONNECTIVITYDATA] = 0;
	if(mSponsoredConnectivityDataGrpList != NULL)
		delete mSponsoredConnectivityDataGrpList;
}

OctetString* RARequest::get3GPPUserLocationInfo(){
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

Time* RARequest::getUserLocationInfoTime(){
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

OctetString* RARequest::get3GPPMSTimeZone(){
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

OctetString* RARequest::getRANNASReleaseCause(){
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

list<FiveGSRANNASReleaseCause*>* RARequest::getFiveGSRANNASReleaseCauseGrpList()
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
			mTagsPresent[RARequest_FIVEGSRANNASRELEASECAUSE] = 0;
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

list<FiveGSRANNASReleaseCause*>* RARequest::setFiveGSRANNASReleaseCauseGrpList(){
	mTagsPresent[RARequest_FIVEGSRANNASRELEASECAUSE] = 1;
	if(mFiveGSRANNASReleaseCauseGrpList == NULL)
		mFiveGSRANNASReleaseCauseGrpList = new list<FiveGSRANNASReleaseCause*>;
	mFiveGSRANNASReleaseCauseGrpList->clear();
	return mFiveGSRANNASReleaseCauseGrpList;
}

void RARequest::resetFiveGSRANNASReleaseCauseGrpList(){
	mTagsPresent[RARequest_FIVEGSRANNASRELEASECAUSE] = 0;
	if(mFiveGSRANNASReleaseCauseGrpList != NULL)
		delete mFiveGSRANNASReleaseCauseGrpList;
}

OctetString* RARequest::get3GPPSGSNMCCMNC(){
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

OctetString* RARequest::getNID(){
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

OctetString* RARequest::getTWANIdentifier(){
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

Unsigned32* RARequest::getTCPSourcePort(){
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

Unsigned32* RARequest::getUDPSourcePort(){
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

Address* RARequest::getUELocalIPAddress(){
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

list<WirelineUserLocationInfo*>* RARequest::getWirelineUserLocationInfoGrpList()
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
			mTagsPresent[RARequest_WIRELINEUSERLOCATIONINFO] = 0;
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

list<WirelineUserLocationInfo*>* RARequest::setWirelineUserLocationInfoGrpList(){
	mTagsPresent[RARequest_WIRELINEUSERLOCATIONINFO] = 1;
	if(mWirelineUserLocationInfoGrpList == NULL)
		mWirelineUserLocationInfoGrpList = new list<WirelineUserLocationInfo*>;
	mWirelineUserLocationInfoGrpList->clear();
	return mWirelineUserLocationInfoGrpList;
}

void RARequest::resetWirelineUserLocationInfoGrpList(){
	mTagsPresent[RARequest_WIRELINEUSERLOCATIONINFO] = 0;
	if(mWirelineUserLocationInfoGrpList != NULL)
		delete mWirelineUserLocationInfoGrpList;
}

Unsigned32* RARequest::getOriginStateId(){
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

OctetString* RARequest::getClass(){
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

list<RX::ProxyInfo*>* RARequest::getProxyInfoGrpList()
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
			mTagsPresent[RARequest_PROXYINFO] = 0;
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

list<RX::ProxyInfo*>* RARequest::setProxyInfoGrpList(){
	mTagsPresent[RARequest_PROXYINFO] = 1;
	if(mProxyInfoGrpList == NULL)
		mProxyInfoGrpList = new list<RX::ProxyInfo*>;
	mMandatoryAvpSetVal[RARequest_PROXYINFO] = 1;
	mProxyInfoGrpList->clear();
	return mProxyInfoGrpList;
}

void RARequest::resetProxyInfoGrpList(){
	mTagsPresent[RARequest_PROXYINFO] = 0;
	if(mProxyInfoGrpList != NULL)
		delete mProxyInfoGrpList;
}

list<OctetString*>* RARequest::getRouteRecordList()
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

list<OctetString*>* RARequest::setRouteRecordList() {
	mTagsPresent[RARequest_ROUTERECORD] = 1;
	if(mRouteRecordList == NULL)
		mRouteRecordList = new list<OctetString*>;
	mMandatoryAvpSetVal [RARequest_ROUTERECORD] = 1;
	mRouteRecordList->clear();
	return mRouteRecordList;
}

void RARequest::resetRouteRecordList(){
	mTagsPresent[RARequest_ROUTERECORD] = 0;
	if(mRouteRecordList != NULL)
		delete mRouteRecordList;
}



int RARequest::Encode(byteArray *array)
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
			case RARequest_SESSIONID:
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
			case RARequest_DRMP:
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
			case RARequest_ORIGINHOST:
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
			case RARequest_ORIGINREALM:
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
			case RARequest_DESTINATIONREALM:
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
			case RARequest_DESTINATIONHOST:
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
			case RARequest_AUTHAPPLICATIONID:
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
			case RARequest_SPECIFICACTION:
			{
					if( mSpecificActionList->size() <= 0) {
						break;
					}

					mSpecificActionIterator = this->getSpecificActionList()->begin();
					while(mSpecificActionIterator != mSpecificActionList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(513);
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
					if(!(*mSpecificActionIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mSpecificActionIterator)->getAvpOffsetLen().first], (*mSpecificActionIterator)->getAvpOffsetLen().second);
						array->offset += (*mSpecificActionIterator)->getAvpOffsetLen().second;
						array->size += (*mSpecificActionIterator)->getAvpOffsetLen().second;
						if(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)
						{
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SpecificAction");
							throw lTssDiaMsgException;
						}
						mSpecificActionIterator++;
						continue;
					}
					if(((*mSpecificActionIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SpecificAction");
						throw lTssDiaMsgException;
					}
					mSpecificActionIterator++;
				}
				}
				break;
			case RARequest_OCSUPPORTEDFEATURES:
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
			case RARequest_ACCESSNETWORKCHARGINGIDENTIFIER:
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
			case RARequest_ACCESSNETWORKCHARGINGADDRESS:
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
			case RARequest_ANGWADDRESS:
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
			case RARequest_ANTRUSTED:
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
			case RARequest_FLOWS:
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
			case RARequest_SUBSCRIPTIONID:
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
			case RARequest_ABORTCAUSE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(500);
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
					if(!mAbortCause->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAbortCause->getAvpOffsetLen().first], mAbortCause->getAvpOffsetLen().second);
						array->offset += mAbortCause->getAvpOffsetLen().second;
						array->size += mAbortCause->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AbortCause");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mAbortCause->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AbortCause");
						throw lTssDiaMsgException;
					}
				}
				break;
			case RARequest_IPCANTYPE:
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
			case RARequest_MAINFORMATION:
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
					if(((*mMAInformationGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MAInformation");
						throw lTssDiaMsgException;
					}
					
					mMAInformationGrpIterator++;
				}
				}
				break;
			case RARequest_NETLOCACCESSSUPPORT:
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
			case RARequest_RATTYPE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1032);
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
			case RARequest_SPONSOREDCONNECTIVITYDATA:
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
					if(((*mSponsoredConnectivityDataGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SponsoredConnectivityData");
						throw lTssDiaMsgException;
					}
					
					mSponsoredConnectivityDataGrpIterator++;
				}
				}
				break;
			case RARequest_3GPPUSERLOCATIONINFO:
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
			case RARequest_USERLOCATIONINFOTIME:
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
			case RARequest_3GPPMSTIMEZONE:
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
			case RARequest_RANNASRELEASECAUSE:
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
			case RARequest_FIVEGSRANNASRELEASECAUSE:
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
			case RARequest_3GPPSGSNMCCMNC:
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
			case RARequest_NID:
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
			case RARequest_TWANIDENTIFIER:
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
			case RARequest_TCPSOURCEPORT:
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
			case RARequest_UDPSOURCEPORT:
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
			case RARequest_UELOCALIPADDRESS:
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
			case RARequest_WIRELINEUSERLOCATIONINFO:
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
			case RARequest_ORIGINSTATEID:
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
			case RARequest_CLASS:
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
			case RARequest_PROXYINFO:
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
			case RARequest_ROUTERECORD:
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


int RARequest::Decode(byteArray *array, INT16 lMLen, UINT16 *parsedBytes)
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
						mMandatoryAvpSetVal [RARequest_SESSIONID] = 1;
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
						mMandatoryAvpSetVal [RARequest_ORIGINHOST] = 1;
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
						mMandatoryAvpSetVal [RARequest_ORIGINREALM] = 1;
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
						mMandatoryAvpSetVal [RARequest_DESTINATIONREALM] = 1;
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
						mMandatoryAvpSetVal [RARequest_DESTINATIONHOST] = 1;
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
			case 258:
				{
						mMandatoryAvpSetVal [RARequest_AUTHAPPLICATIONID] = 1;
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
			case 513:
				{
						mMandatoryAvpSetVal [RARequest_SPECIFICACTION] = 1;
					mTagsPresent[RARequest_SPECIFICACTION] = 1;
					SpecificAction *lSpecificAction = new SpecificAction();
					if( lSpecificAction == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SpecificAction");
						throw lTssDiaMsgException;
					}
					lSpecificAction->setAvpCode(513);
					lSpecificAction->setAvpVendorId(lVenderId);
					lSpecificAction->SetDataType((DiameterDataType)7);
					lSpecificAction->mspByteArray = mspByteArray;
					lSpecificAction->mAvpDecodedFlag = false;
					lSpecificAction->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mSpecificActionList == NULL)
						this->setSpecificActionList();
					mSpecificActionList->push_back(lSpecificAction);
					
				}
				break;
			case 621:
				{
					mTagsPresent[RARequest_OCSUPPORTEDFEATURES] = 1;
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
			case 502:
				{
						mMandatoryAvpSetVal [RARequest_ACCESSNETWORKCHARGINGIDENTIFIER] = 1;
					mTagsPresent[RARequest_ACCESSNETWORKCHARGINGIDENTIFIER] = 1;
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
						mMandatoryAvpSetVal [RARequest_ACCESSNETWORKCHARGINGADDRESS] = 1;
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
			case 1050:
				{
					mTagsPresent[RARequest_ANGWADDRESS] = 1;
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
						mMandatoryAvpSetVal [RARequest_ANTRUSTED] = 1;
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
			case 510:
				{
						mMandatoryAvpSetVal [RARequest_FLOWS] = 1;
					mTagsPresent[RARequest_FLOWS] = 1;
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
			case 443:
				{
						mMandatoryAvpSetVal [RARequest_SUBSCRIPTIONID] = 1;
					mTagsPresent[RARequest_SUBSCRIPTIONID] = 1;
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
			case 500:
				{
						mMandatoryAvpSetVal [RARequest_ABORTCAUSE] = 1;
					if( NULL == this->setAbortCause())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AbortCause");
						throw lTssDiaMsgException;
					}
					mAbortCause->setAvpCode(500);
					mAbortCause->setAvpVendorId(lVenderId);
					mAbortCause->SetDataType((DiameterDataType)7);
					mAbortCause->mspByteArray = mspByteArray;
					mAbortCause->mAvpDecodedFlag = false;
					mAbortCause->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1027:
				{
						mMandatoryAvpSetVal [RARequest_IPCANTYPE] = 1;
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
					mTagsPresent[RARequest_MAINFORMATION] = 1;
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
					mRATType->SetDataType((DiameterDataType)7);
					mRATType->mspByteArray = mspByteArray;
					mRATType->mAvpDecodedFlag = false;
					mRATType->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 530:
				{
					mTagsPresent[RARequest_SPONSOREDCONNECTIVITYDATA] = 1;
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
					mTagsPresent[RARequest_FIVEGSRANNASRELEASECAUSE] = 1;
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
			case 578:
				{
					mTagsPresent[RARequest_WIRELINEUSERLOCATIONINFO] = 1;
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
			case 278:
				{
						mMandatoryAvpSetVal [RARequest_ORIGINSTATEID] = 1;
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
			case 25:
				{
						mMandatoryAvpSetVal [RARequest_CLASS] = 1;
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
			case 284:
				{
						mMandatoryAvpSetVal [RARequest_PROXYINFO] = 1;
					mTagsPresent[RARequest_PROXYINFO] = 1;
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
						mMandatoryAvpSetVal [RARequest_ROUTERECORD] = 1;
					mTagsPresent[RARequest_ROUTERECORD] = 1;
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


DiameterBaseInterface* RARequest::Find(byteArray *array, UINT32 avpCode)
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
			case 258:
			{
				if(mAuthApplicationId != NULL)
					return mAuthApplicationId->Find(array, avpCode);
				else
					return NULL;
			}
			case 513:
			{
				if(mSpecificActionList != NULL && mSpecificActionList->size() > 0)
					return (mSpecificActionList->back())->Find(array, avpCode);
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
			case 500:
			{
				if(mAbortCause != NULL)
					return mAbortCause->Find(array, avpCode);
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
			case 278:
			{
				if(mOriginStateId != NULL)
					return mOriginStateId->Find(array, avpCode);
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


BOOLEAN RARequest::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
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
			case 513:
			{
				if(mSpecificActionList != NULL)
				{
					for(auto itr = mSpecificActionList->begin(); itr != mSpecificActionList->end(); ++itr)
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
			case 500:
			{
				if(mAbortCause != NULL)
				{
					DiameterBaseInterface* inf =  mAbortCause->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> RARequest::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN RARequest::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
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
			case 513:
			{
				if(mSpecificActionList != NULL)
				{
					for(auto itr = mSpecificActionList->begin(); itr != mSpecificActionList->end(); ++itr)
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
			case 500:
			{
				if(mAbortCause != NULL)
				{
					DiameterBaseInterface* inf =  mAbortCause->Find(this->mspByteArray.get(), avpCode);
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




void RARequest::Display(UINT32 tab)
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
			case RARequest_SESSIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "263" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SessionId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getSessionId()->Display(tab+1);
			}
				break;
			case RARequest_DRMP:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "301" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DRMP" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getDRMP()->Display(tab+1);
			}
				break;
			case RARequest_ORIGINHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "264" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginHost()->Display(tab+1);
			}
				break;
			case RARequest_ORIGINREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "296" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginRealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginRealm()->Display(tab+1);
			}
				break;
			case RARequest_DESTINATIONREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "283" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DestinationRealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getDestinationRealm()->Display(tab+1);
			}
				break;
			case RARequest_DESTINATIONHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "293" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DestinationHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getDestinationHost()->Display(tab+1);
			}
				break;
			case RARequest_AUTHAPPLICATIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "258" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AuthApplicationId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getAuthApplicationId()->Display(tab+1);
			}
				break;
			case RARequest_SPECIFICACTION:
			{
				if( mSpecificActionList->size() <= 0) {
					break;
				}

				mSpecificActionIterator = this->getSpecificActionList()->begin();
				while(mSpecificActionIterator != this->getSpecificActionList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "513" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SpecificAction" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mSpecificActionIterator)->Display(tab+1);
					mSpecificActionIterator++;

				};

			}
				break;
			case RARequest_OCSUPPORTEDFEATURES:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "621" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OCSupportedFeatures" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getOCSupportedFeatures()->Display(tab+1);
			}
				break;
			case RARequest_ACCESSNETWORKCHARGINGIDENTIFIER:
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
			case RARequest_ACCESSNETWORKCHARGINGADDRESS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "501" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AccessNetworkChargingAddress" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getAccessNetworkChargingAddress()->Display(tab+1);
			}
				break;
			case RARequest_ANGWADDRESS:
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
			case RARequest_ANTRUSTED:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1503" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ANTrusted" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getANTrusted()->Display(tab+1);
			}
				break;
			case RARequest_FLOWS:
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
			case RARequest_SUBSCRIPTIONID:
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
			case RARequest_ABORTCAUSE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "500" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AbortCause" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getAbortCause()->Display(tab+1);
			}
				break;
			case RARequest_IPCANTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1027" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "IPCANType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getIPCANType()->Display(tab+1);
			}
				break;
			case RARequest_MAINFORMATION:
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
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mMAInformationGrpIterator)->Display(tab+1);
					mMAInformationGrpIterator++;

				};

			}
				break;
			case RARequest_NETLOCACCESSSUPPORT:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2824" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "NetLocAccessSupport" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getNetLocAccessSupport()->Display(tab+1);
			}
				break;
			case RARequest_RATTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1032" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RATType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getRATType()->Display(tab+1);
			}
				break;
			case RARequest_SPONSOREDCONNECTIVITYDATA:
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
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mSponsoredConnectivityDataGrpIterator)->Display(tab+1);
					mSponsoredConnectivityDataGrpIterator++;

				};

			}
				break;
			case RARequest_3GPPUSERLOCATIONINFO:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "22" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPPUserLocationInfo" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->get3GPPUserLocationInfo()->Display(tab+1);
			}
				break;
			case RARequest_USERLOCATIONINFOTIME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2812" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserLocationInfoTime" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getUserLocationInfoTime()->Display(tab+1);
			}
				break;
			case RARequest_3GPPMSTIMEZONE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "23" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPPMSTimeZone" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->get3GPPMSTimeZone()->Display(tab+1);
			}
				break;
			case RARequest_RANNASRELEASECAUSE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2819" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RANNASReleaseCause" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getRANNASReleaseCause()->Display(tab+1);
			}
				break;
			case RARequest_FIVEGSRANNASRELEASECAUSE:
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
			case RARequest_3GPPSGSNMCCMNC:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "18" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPPSGSNMCCMNC" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->get3GPPSGSNMCCMNC()->Display(tab+1);
			}
				break;
			case RARequest_NID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "569" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "NID" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getNID()->Display(tab+1);
			}
				break;
			case RARequest_TWANIDENTIFIER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "29" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "TWANIdentifier" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getTWANIdentifier()->Display(tab+1);
			}
				break;
			case RARequest_TCPSOURCEPORT:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2843" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "TCPSourcePort" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getTCPSourcePort()->Display(tab+1);
			}
				break;
			case RARequest_UDPSOURCEPORT:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2806" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UDPSourcePort" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getUDPSourcePort()->Display(tab+1);
			}
				break;
			case RARequest_UELOCALIPADDRESS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2805" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UELocalIPAddress" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getUELocalIPAddress()->Display(tab+1);
			}
				break;
			case RARequest_WIRELINEUSERLOCATIONINFO:
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
			case RARequest_ORIGINSTATEID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "278" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginStateId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginStateId()->Display(tab+1);
			}
				break;
			case RARequest_CLASS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "25" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "Class" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getClass()->Display(tab+1);
			}
				break;
			case RARequest_PROXYINFO:
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
			case RARequest_ROUTERECORD:
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


BOOLEAN RARequest::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<37> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case RARequest_SESSIONID:
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
			case RARequest_DRMP:
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
			case RARequest_ORIGINHOST:
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
			case RARequest_ORIGINREALM:
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
			case RARequest_DESTINATIONREALM:
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
			case RARequest_DESTINATIONHOST:
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
			case RARequest_AUTHAPPLICATIONID:
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
			case RARequest_SPECIFICACTION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 513");
				}
				else
					sprintf(lMissingAvpInfo, "%s,513", lMissingAvpInfo);
			}
				break;
			case RARequest_OCSUPPORTEDFEATURES:
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
			case RARequest_ACCESSNETWORKCHARGINGIDENTIFIER:
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
			case RARequest_ACCESSNETWORKCHARGINGADDRESS:
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
			case RARequest_ANGWADDRESS:
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
			case RARequest_ANTRUSTED:
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
			case RARequest_FLOWS:
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
			case RARequest_SUBSCRIPTIONID:
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
			case RARequest_ABORTCAUSE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 500");
				}
				else
					sprintf(lMissingAvpInfo, "%s,500", lMissingAvpInfo);
			}
				break;
			case RARequest_IPCANTYPE:
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
			case RARequest_MAINFORMATION:
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
			case RARequest_NETLOCACCESSSUPPORT:
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
			case RARequest_RATTYPE:
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
			case RARequest_SPONSOREDCONNECTIVITYDATA:
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
			case RARequest_3GPPUSERLOCATIONINFO:
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
			case RARequest_USERLOCATIONINFOTIME:
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
			case RARequest_3GPPMSTIMEZONE:
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
			case RARequest_RANNASRELEASECAUSE:
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
			case RARequest_FIVEGSRANNASRELEASECAUSE:
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
			case RARequest_3GPPSGSNMCCMNC:
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
			case RARequest_NID:
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
			case RARequest_TWANIDENTIFIER:
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
			case RARequest_TCPSOURCEPORT:
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
			case RARequest_UDPSOURCEPORT:
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
			case RARequest_UELOCALIPADDRESS:
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
			case RARequest_WIRELINEUSERLOCATIONINFO:
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
			case RARequest_ORIGINSTATEID:
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
			case RARequest_CLASS:
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
			case RARequest_PROXYINFO:
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
			case RARequest_ROUTERECORD:
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
