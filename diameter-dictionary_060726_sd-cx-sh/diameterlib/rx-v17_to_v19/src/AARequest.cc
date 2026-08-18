#include "rx/include/AARequest.h"

using namespace RX;
BOOLEAN AARequest::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

AARequest::AARequest()
{
	mSessionId = NULL;
	mDRMP = NULL;
	mAuthApplicationId = NULL;
	mOriginHost = NULL;
	mOriginRealm = NULL;
	mDestinationRealm = NULL;
	mDestinationHost = NULL;
	mIPDomainId = NULL;
	mAuthSessionState = NULL;
	mAFApplicationIdentifier = NULL;
	mMediaComponentDescriptionGrpList = NULL;
	mServiceInfoStatus = NULL;
	mAFChargingIdentifier = NULL;
	mSIPForkingIndication = NULL;
	mSpecificActionList = NULL;
	mSubscriptionIdGrpList = NULL;
	mOCSupportedFeaturesGrp = NULL;
	mSupportedFeaturesGrpList = NULL;
	mReservationPriority = NULL;
	mFramedIPAddress = NULL;
	mFramedIPv6Prefix = NULL;
	mCalledStationId = NULL;
	mServiceURN = NULL;
	mSponsoredConnectivityDataGrpList = NULL;
	mMPSIdentifier = NULL;
	mGCSIdentifier = NULL;
	mMCPTTIdentifier = NULL;
	mMCVideoIdentifier = NULL;
	mIMSContentIdentifier = NULL;
	mIMSContentType = NULL;
	mCallingPartyAddress = NULL;
	mCalleeInformationGrpList = NULL;
	mRxRequestType = NULL;
	mRequiredAccessInfoList = NULL;
	mAFRequestedData = NULL;
	mReferenceID = NULL;
	mPreEmptionControlInfo = NULL;
	mMPSAction = NULL;
	mOriginStateId = NULL;
	mProxyInfoGrpList = NULL;
	mRouteRecordList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<41>(string("01100100001000000010110101111111001111101"));
	mMandatoryAvpSetVal.reset();
}

AARequest::~AARequest()
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
	if(mIPDomainId != NULL)
		delete mIPDomainId;
	if(mAuthSessionState != NULL)
		delete mAuthSessionState;
	if(mAFApplicationIdentifier != NULL)
		delete mAFApplicationIdentifier;
	if(mMediaComponentDescriptionGrpList != NULL){
		mMediaComponentDescriptionGrpIterator = mMediaComponentDescriptionGrpList->begin();
		while(mMediaComponentDescriptionGrpIterator != mMediaComponentDescriptionGrpList->end()){
	if(*mMediaComponentDescriptionGrpIterator != NULL)
			delete (*mMediaComponentDescriptionGrpIterator);
			mMediaComponentDescriptionGrpIterator++;
		}
		delete mMediaComponentDescriptionGrpList;
	}
	if(mServiceInfoStatus != NULL)
		delete mServiceInfoStatus;
	if(mAFChargingIdentifier != NULL)
		delete mAFChargingIdentifier;
	if(mSIPForkingIndication != NULL)
		delete mSIPForkingIndication;
	if(mSpecificActionList != NULL){
		mSpecificActionIterator = mSpecificActionList->begin();
		while(mSpecificActionIterator != mSpecificActionList->end()){
			delete (*mSpecificActionIterator);
			mSpecificActionIterator++;
		}
		delete mSpecificActionList;
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
	if(mOCSupportedFeaturesGrp != NULL)
		delete mOCSupportedFeaturesGrp;
	if(mSupportedFeaturesGrpList != NULL){
		mSupportedFeaturesGrpIterator = mSupportedFeaturesGrpList->begin();
		while(mSupportedFeaturesGrpIterator != mSupportedFeaturesGrpList->end()){
	if(*mSupportedFeaturesGrpIterator != NULL)
			delete (*mSupportedFeaturesGrpIterator);
			mSupportedFeaturesGrpIterator++;
		}
		delete mSupportedFeaturesGrpList;
	}
	if(mReservationPriority != NULL)
		delete mReservationPriority;
	if(mFramedIPAddress != NULL)
		delete mFramedIPAddress;
	if(mFramedIPv6Prefix != NULL)
		delete mFramedIPv6Prefix;
	if(mCalledStationId != NULL)
		delete mCalledStationId;
	if(mServiceURN != NULL)
		delete mServiceURN;
	if(mSponsoredConnectivityDataGrpList != NULL){
		mSponsoredConnectivityDataGrpIterator = mSponsoredConnectivityDataGrpList->begin();
		while(mSponsoredConnectivityDataGrpIterator != mSponsoredConnectivityDataGrpList->end()){
	if(*mSponsoredConnectivityDataGrpIterator != NULL)
			delete (*mSponsoredConnectivityDataGrpIterator);
			mSponsoredConnectivityDataGrpIterator++;
		}
		delete mSponsoredConnectivityDataGrpList;
	}
	if(mMPSIdentifier != NULL)
		delete mMPSIdentifier;
	if(mGCSIdentifier != NULL)
		delete mGCSIdentifier;
	if(mMCPTTIdentifier != NULL)
		delete mMCPTTIdentifier;
	if(mMCVideoIdentifier != NULL)
		delete mMCVideoIdentifier;
	if(mIMSContentIdentifier != NULL)
		delete mIMSContentIdentifier;
	if(mIMSContentType != NULL)
		delete mIMSContentType;
	if(mCallingPartyAddress != NULL)
		delete mCallingPartyAddress;
	if(mCalleeInformationGrpList != NULL){
		mCalleeInformationGrpIterator = mCalleeInformationGrpList->begin();
		while(mCalleeInformationGrpIterator != mCalleeInformationGrpList->end()){
	if(*mCalleeInformationGrpIterator != NULL)
			delete (*mCalleeInformationGrpIterator);
			mCalleeInformationGrpIterator++;
		}
		delete mCalleeInformationGrpList;
	}
	if(mRxRequestType != NULL)
		delete mRxRequestType;
	if(mRequiredAccessInfoList != NULL){
		mRequiredAccessInfoIterator = mRequiredAccessInfoList->begin();
		while(mRequiredAccessInfoIterator != mRequiredAccessInfoList->end()){
			delete (*mRequiredAccessInfoIterator);
			mRequiredAccessInfoIterator++;
		}
		delete mRequiredAccessInfoList;
	}
	if(mAFRequestedData != NULL)
		delete mAFRequestedData;
	if(mReferenceID != NULL)
		delete mReferenceID;
	if(mPreEmptionControlInfo != NULL)
		delete mPreEmptionControlInfo;
	if(mMPSAction != NULL)
		delete mMPSAction;
	if(mOriginStateId != NULL)
		delete mOriginStateId;
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

OctetString* AARequest::setSessionId(){
	mMandatoryAvpSetVal [AARequest_SESSIONID] = 1;
	if(mSessionId == NULL)
	{
		mSessionId = new OctetString();
		mTagsPresent[AARequest_SESSIONID] = 1;
		return mSessionId;
	}
	return mSessionId;
}

void AARequest::resetSessionId(){
	mTagsPresent[AARequest_SESSIONID] = 0;
	if(mSessionId != NULL)
	{
		delete mSessionId; 
		mSessionId = NULL;
	}
}

DRMP* AARequest::setDRMP(){
	if(mDRMP == NULL)
	{
		mDRMP = new DRMP();
		mTagsPresent[AARequest_DRMP] = 1;
		return mDRMP;
	}
	return mDRMP;
}

void AARequest::resetDRMP(){
	mTagsPresent[AARequest_DRMP] = 0;
	if(mDRMP != NULL)
	{
		delete mDRMP; 
		mDRMP = NULL;
	}
}

Integer32* AARequest::setAuthApplicationId(){
	mMandatoryAvpSetVal [AARequest_AUTHAPPLICATIONID] = 1;
	if(mAuthApplicationId == NULL)
	{
		mAuthApplicationId = new Integer32();
		mTagsPresent[AARequest_AUTHAPPLICATIONID] = 1;
		return mAuthApplicationId;
	}
	return mAuthApplicationId;
}

void AARequest::resetAuthApplicationId(){
	mTagsPresent[AARequest_AUTHAPPLICATIONID] = 0;
	if(mAuthApplicationId != NULL)
	{
		delete mAuthApplicationId; 
		mAuthApplicationId = NULL;
	}
}

OctetString* AARequest::setOriginHost(){
	mMandatoryAvpSetVal [AARequest_ORIGINHOST] = 1;
	if(mOriginHost == NULL)
	{
		mOriginHost = new OctetString();
		mTagsPresent[AARequest_ORIGINHOST] = 1;
		return mOriginHost;
	}
	return mOriginHost;
}

void AARequest::resetOriginHost(){
	mTagsPresent[AARequest_ORIGINHOST] = 0;
	if(mOriginHost != NULL)
	{
		delete mOriginHost; 
		mOriginHost = NULL;
	}
}

OctetString* AARequest::setOriginRealm(){
	mMandatoryAvpSetVal [AARequest_ORIGINREALM] = 1;
	if(mOriginRealm == NULL)
	{
		mOriginRealm = new OctetString();
		mTagsPresent[AARequest_ORIGINREALM] = 1;
		return mOriginRealm;
	}
	return mOriginRealm;
}

void AARequest::resetOriginRealm(){
	mTagsPresent[AARequest_ORIGINREALM] = 0;
	if(mOriginRealm != NULL)
	{
		delete mOriginRealm; 
		mOriginRealm = NULL;
	}
}

OctetString* AARequest::setDestinationRealm(){
	mMandatoryAvpSetVal [AARequest_DESTINATIONREALM] = 1;
	if(mDestinationRealm == NULL)
	{
		mDestinationRealm = new OctetString();
		mTagsPresent[AARequest_DESTINATIONREALM] = 1;
		return mDestinationRealm;
	}
	return mDestinationRealm;
}

void AARequest::resetDestinationRealm(){
	mTagsPresent[AARequest_DESTINATIONREALM] = 0;
	if(mDestinationRealm != NULL)
	{
		delete mDestinationRealm; 
		mDestinationRealm = NULL;
	}
}

OctetString* AARequest::setDestinationHost(){
	mMandatoryAvpSetVal [AARequest_DESTINATIONHOST] = 1;
	if(mDestinationHost == NULL)
	{
		mDestinationHost = new OctetString();
		mTagsPresent[AARequest_DESTINATIONHOST] = 1;
		return mDestinationHost;
	}
	return mDestinationHost;
}

void AARequest::resetDestinationHost(){
	mTagsPresent[AARequest_DESTINATIONHOST] = 0;
	if(mDestinationHost != NULL)
	{
		delete mDestinationHost; 
		mDestinationHost = NULL;
	}
}

OctetString* AARequest::setIPDomainId(){
	if(mIPDomainId == NULL)
	{
		mIPDomainId = new OctetString();
		mTagsPresent[AARequest_IPDOMAINID] = 1;
		return mIPDomainId;
	}
	return mIPDomainId;
}

void AARequest::resetIPDomainId(){
	mTagsPresent[AARequest_IPDOMAINID] = 0;
	if(mIPDomainId != NULL)
	{
		delete mIPDomainId; 
		mIPDomainId = NULL;
	}
}

AuthSessionState* AARequest::setAuthSessionState(){
	if(mAuthSessionState == NULL)
	{
		mAuthSessionState = new AuthSessionState();
		mTagsPresent[AARequest_AUTHSESSIONSTATE] = 1;
		return mAuthSessionState;
	}
	return mAuthSessionState;
}

void AARequest::resetAuthSessionState(){
	mTagsPresent[AARequest_AUTHSESSIONSTATE] = 0;
	if(mAuthSessionState != NULL)
	{
		delete mAuthSessionState; 
		mAuthSessionState = NULL;
	}
}

OctetString* AARequest::setAFApplicationIdentifier(){
	mMandatoryAvpSetVal [AARequest_AFAPPLICATIONIDENTIFIER] = 1;
	if(mAFApplicationIdentifier == NULL)
	{
		mAFApplicationIdentifier = new OctetString();
		mTagsPresent[AARequest_AFAPPLICATIONIDENTIFIER] = 1;
		return mAFApplicationIdentifier;
	}
	return mAFApplicationIdentifier;
}

void AARequest::resetAFApplicationIdentifier(){
	mTagsPresent[AARequest_AFAPPLICATIONIDENTIFIER] = 0;
	if(mAFApplicationIdentifier != NULL)
	{
		delete mAFApplicationIdentifier; 
		mAFApplicationIdentifier = NULL;
	}
}

ServiceInfoStatus* AARequest::setServiceInfoStatus(){
	mMandatoryAvpSetVal [AARequest_SERVICEINFOSTATUS] = 1;
	if(mServiceInfoStatus == NULL)
	{
		mServiceInfoStatus = new ServiceInfoStatus();
		mTagsPresent[AARequest_SERVICEINFOSTATUS] = 1;
		return mServiceInfoStatus;
	}
	return mServiceInfoStatus;
}

void AARequest::resetServiceInfoStatus(){
	mTagsPresent[AARequest_SERVICEINFOSTATUS] = 0;
	if(mServiceInfoStatus != NULL)
	{
		delete mServiceInfoStatus; 
		mServiceInfoStatus = NULL;
	}
}

OctetString* AARequest::setAFChargingIdentifier(){
	mMandatoryAvpSetVal [AARequest_AFCHARGINGIDENTIFIER] = 1;
	if(mAFChargingIdentifier == NULL)
	{
		mAFChargingIdentifier = new OctetString();
		mTagsPresent[AARequest_AFCHARGINGIDENTIFIER] = 1;
		return mAFChargingIdentifier;
	}
	return mAFChargingIdentifier;
}

void AARequest::resetAFChargingIdentifier(){
	mTagsPresent[AARequest_AFCHARGINGIDENTIFIER] = 0;
	if(mAFChargingIdentifier != NULL)
	{
		delete mAFChargingIdentifier; 
		mAFChargingIdentifier = NULL;
	}
}

SIPForkingIndication* AARequest::setSIPForkingIndication(){
	mMandatoryAvpSetVal [AARequest_SIPFORKINGINDICATION] = 1;
	if(mSIPForkingIndication == NULL)
	{
		mSIPForkingIndication = new SIPForkingIndication();
		mTagsPresent[AARequest_SIPFORKINGINDICATION] = 1;
		return mSIPForkingIndication;
	}
	return mSIPForkingIndication;
}

void AARequest::resetSIPForkingIndication(){
	mTagsPresent[AARequest_SIPFORKINGINDICATION] = 0;
	if(mSIPForkingIndication != NULL)
	{
		delete mSIPForkingIndication; 
		mSIPForkingIndication = NULL;
	}
}

ReservationPriority* AARequest::setReservationPriority(){
	if(mReservationPriority == NULL)
	{
		mReservationPriority = new ReservationPriority();
		mTagsPresent[AARequest_RESERVATIONPRIORITY] = 1;
		return mReservationPriority;
	}
	return mReservationPriority;
}

void AARequest::resetReservationPriority(){
	mTagsPresent[AARequest_RESERVATIONPRIORITY] = 0;
	if(mReservationPriority != NULL)
	{
		delete mReservationPriority; 
		mReservationPriority = NULL;
	}
}

OctetString* AARequest::setFramedIPAddress(){
	mMandatoryAvpSetVal [AARequest_FRAMEDIPADDRESS] = 1;
	if(mFramedIPAddress == NULL)
	{
		mFramedIPAddress = new OctetString();
		mTagsPresent[AARequest_FRAMEDIPADDRESS] = 1;
		return mFramedIPAddress;
	}
	return mFramedIPAddress;
}

void AARequest::resetFramedIPAddress(){
	mTagsPresent[AARequest_FRAMEDIPADDRESS] = 0;
	if(mFramedIPAddress != NULL)
	{
		delete mFramedIPAddress; 
		mFramedIPAddress = NULL;
	}
}

OctetString* AARequest::setFramedIPv6Prefix(){
	mMandatoryAvpSetVal [AARequest_FRAMEDIPV6PREFIX] = 1;
	if(mFramedIPv6Prefix == NULL)
	{
		mFramedIPv6Prefix = new OctetString();
		mTagsPresent[AARequest_FRAMEDIPV6PREFIX] = 1;
		return mFramedIPv6Prefix;
	}
	return mFramedIPv6Prefix;
}

void AARequest::resetFramedIPv6Prefix(){
	mTagsPresent[AARequest_FRAMEDIPV6PREFIX] = 0;
	if(mFramedIPv6Prefix != NULL)
	{
		delete mFramedIPv6Prefix; 
		mFramedIPv6Prefix = NULL;
	}
}

OctetString* AARequest::setCalledStationId(){
	if(mCalledStationId == NULL)
	{
		mCalledStationId = new OctetString();
		mTagsPresent[AARequest_CALLEDSTATIONID] = 1;
		return mCalledStationId;
	}
	return mCalledStationId;
}

void AARequest::resetCalledStationId(){
	mTagsPresent[AARequest_CALLEDSTATIONID] = 0;
	if(mCalledStationId != NULL)
	{
		delete mCalledStationId; 
		mCalledStationId = NULL;
	}
}

OctetString* AARequest::setServiceURN(){
	mMandatoryAvpSetVal [AARequest_SERVICEURN] = 1;
	if(mServiceURN == NULL)
	{
		mServiceURN = new OctetString();
		mTagsPresent[AARequest_SERVICEURN] = 1;
		return mServiceURN;
	}
	return mServiceURN;
}

void AARequest::resetServiceURN(){
	mTagsPresent[AARequest_SERVICEURN] = 0;
	if(mServiceURN != NULL)
	{
		delete mServiceURN; 
		mServiceURN = NULL;
	}
}

OctetString* AARequest::setMPSIdentifier(){
	if(mMPSIdentifier == NULL)
	{
		mMPSIdentifier = new OctetString();
		mTagsPresent[AARequest_MPSIDENTIFIER] = 1;
		return mMPSIdentifier;
	}
	return mMPSIdentifier;
}

void AARequest::resetMPSIdentifier(){
	mTagsPresent[AARequest_MPSIDENTIFIER] = 0;
	if(mMPSIdentifier != NULL)
	{
		delete mMPSIdentifier; 
		mMPSIdentifier = NULL;
	}
}

OctetString* AARequest::setGCSIdentifier(){
	if(mGCSIdentifier == NULL)
	{
		mGCSIdentifier = new OctetString();
		mTagsPresent[AARequest_GCSIDENTIFIER] = 1;
		return mGCSIdentifier;
	}
	return mGCSIdentifier;
}

void AARequest::resetGCSIdentifier(){
	mTagsPresent[AARequest_GCSIDENTIFIER] = 0;
	if(mGCSIdentifier != NULL)
	{
		delete mGCSIdentifier; 
		mGCSIdentifier = NULL;
	}
}

OctetString* AARequest::setMCPTTIdentifier(){
	if(mMCPTTIdentifier == NULL)
	{
		mMCPTTIdentifier = new OctetString();
		mTagsPresent[AARequest_MCPTTIDENTIFIER] = 1;
		return mMCPTTIdentifier;
	}
	return mMCPTTIdentifier;
}

void AARequest::resetMCPTTIdentifier(){
	mTagsPresent[AARequest_MCPTTIDENTIFIER] = 0;
	if(mMCPTTIdentifier != NULL)
	{
		delete mMCPTTIdentifier; 
		mMCPTTIdentifier = NULL;
	}
}

OctetString* AARequest::setMCVideoIdentifier(){
	if(mMCVideoIdentifier == NULL)
	{
		mMCVideoIdentifier = new OctetString();
		mTagsPresent[AARequest_MCVIDEOIDENTIFIER] = 1;
		return mMCVideoIdentifier;
	}
	return mMCVideoIdentifier;
}

void AARequest::resetMCVideoIdentifier(){
	mTagsPresent[AARequest_MCVIDEOIDENTIFIER] = 0;
	if(mMCVideoIdentifier != NULL)
	{
		delete mMCVideoIdentifier; 
		mMCVideoIdentifier = NULL;
	}
}

OctetString* AARequest::setIMSContentIdentifier(){
	if(mIMSContentIdentifier == NULL)
	{
		mIMSContentIdentifier = new OctetString();
		mTagsPresent[AARequest_IMSCONTENTIDENTIFIER] = 1;
		return mIMSContentIdentifier;
	}
	return mIMSContentIdentifier;
}

void AARequest::resetIMSContentIdentifier(){
	mTagsPresent[AARequest_IMSCONTENTIDENTIFIER] = 0;
	if(mIMSContentIdentifier != NULL)
	{
		delete mIMSContentIdentifier; 
		mIMSContentIdentifier = NULL;
	}
}

IMSContentType* AARequest::setIMSContentType(){
	if(mIMSContentType == NULL)
	{
		mIMSContentType = new IMSContentType();
		mTagsPresent[AARequest_IMSCONTENTTYPE] = 1;
		return mIMSContentType;
	}
	return mIMSContentType;
}

void AARequest::resetIMSContentType(){
	mTagsPresent[AARequest_IMSCONTENTTYPE] = 0;
	if(mIMSContentType != NULL)
	{
		delete mIMSContentType; 
		mIMSContentType = NULL;
	}
}

OctetString* AARequest::setCallingPartyAddress(){
	mMandatoryAvpSetVal [AARequest_CALLINGPARTYADDRESS] = 1;
	if(mCallingPartyAddress == NULL)
	{
		mCallingPartyAddress = new OctetString();
		mTagsPresent[AARequest_CALLINGPARTYADDRESS] = 1;
		return mCallingPartyAddress;
	}
	return mCallingPartyAddress;
}

void AARequest::resetCallingPartyAddress(){
	mTagsPresent[AARequest_CALLINGPARTYADDRESS] = 0;
	if(mCallingPartyAddress != NULL)
	{
		delete mCallingPartyAddress; 
		mCallingPartyAddress = NULL;
	}
}

RxRequestType* AARequest::setRxRequestType(){
	if(mRxRequestType == NULL)
	{
		mRxRequestType = new RxRequestType();
		mTagsPresent[AARequest_RXREQUESTTYPE] = 1;
		return mRxRequestType;
	}
	return mRxRequestType;
}

void AARequest::resetRxRequestType(){
	mTagsPresent[AARequest_RXREQUESTTYPE] = 0;
	if(mRxRequestType != NULL)
	{
		delete mRxRequestType; 
		mRxRequestType = NULL;
	}
}

Unsigned32* AARequest::setAFRequestedData(){
	if(mAFRequestedData == NULL)
	{
		mAFRequestedData = new Unsigned32();
		mTagsPresent[AARequest_AFREQUESTEDDATA] = 1;
		return mAFRequestedData;
	}
	return mAFRequestedData;
}

void AARequest::resetAFRequestedData(){
	mTagsPresent[AARequest_AFREQUESTEDDATA] = 0;
	if(mAFRequestedData != NULL)
	{
		delete mAFRequestedData; 
		mAFRequestedData = NULL;
	}
}

OctetString* AARequest::setReferenceID(){
	mMandatoryAvpSetVal [AARequest_REFERENCEID] = 1;
	if(mReferenceID == NULL)
	{
		mReferenceID = new OctetString();
		mTagsPresent[AARequest_REFERENCEID] = 1;
		return mReferenceID;
	}
	return mReferenceID;
}

void AARequest::resetReferenceID(){
	mTagsPresent[AARequest_REFERENCEID] = 0;
	if(mReferenceID != NULL)
	{
		delete mReferenceID; 
		mReferenceID = NULL;
	}
}

Unsigned32* AARequest::setPreEmptionControlInfo(){
	if(mPreEmptionControlInfo == NULL)
	{
		mPreEmptionControlInfo = new Unsigned32();
		mTagsPresent[AARequest_PREEMPTIONCONTROLINFO] = 1;
		return mPreEmptionControlInfo;
	}
	return mPreEmptionControlInfo;
}

void AARequest::resetPreEmptionControlInfo(){
	mTagsPresent[AARequest_PREEMPTIONCONTROLINFO] = 0;
	if(mPreEmptionControlInfo != NULL)
	{
		delete mPreEmptionControlInfo; 
		mPreEmptionControlInfo = NULL;
	}
}

MPSAction* AARequest::setMPSAction(){
	if(mMPSAction == NULL)
	{
		mMPSAction = new MPSAction();
		mTagsPresent[AARequest_MPSACTION] = 1;
		return mMPSAction;
	}
	return mMPSAction;
}

void AARequest::resetMPSAction(){
	mTagsPresent[AARequest_MPSACTION] = 0;
	if(mMPSAction != NULL)
	{
		delete mMPSAction; 
		mMPSAction = NULL;
	}
}

Unsigned32* AARequest::setOriginStateId(){
	mMandatoryAvpSetVal [AARequest_ORIGINSTATEID] = 1;
	if(mOriginStateId == NULL)
	{
		mOriginStateId = new Unsigned32();
		mTagsPresent[AARequest_ORIGINSTATEID] = 1;
		return mOriginStateId;
	}
	return mOriginStateId;
}

void AARequest::resetOriginStateId(){
	mTagsPresent[AARequest_ORIGINSTATEID] = 0;
	if(mOriginStateId != NULL)
	{
		delete mOriginStateId; 
		mOriginStateId = NULL;
	}
}

OctetString* AARequest::getSessionId(){
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

DRMP* AARequest::getDRMP(){
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

Integer32* AARequest::getAuthApplicationId(){
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

OctetString* AARequest::getOriginHost(){
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

OctetString* AARequest::getOriginRealm(){
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

OctetString* AARequest::getDestinationRealm(){
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

OctetString* AARequest::getDestinationHost(){
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

OctetString* AARequest::getIPDomainId(){
	if(NULL == mIPDomainId) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "IPDomainId is Null");
		throw lTssDiaMsgException;
	}
	if(!mIPDomainId->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mIPDomainId->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "IPDomainId is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mIPDomainId->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mIPDomainId->Decode(mspByteArray.get(), mIPDomainId->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding IPDomainId")     ;
			throw lTssDiaMsgException;
		}
		mIPDomainId->mAvpDecodedFlag = true;
	}
	return mIPDomainId;
}

AuthSessionState* AARequest::getAuthSessionState(){
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

OctetString* AARequest::getAFApplicationIdentifier(){
	if(NULL == mAFApplicationIdentifier) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AFApplicationIdentifier is Null");
		throw lTssDiaMsgException;
	}
	if(!mAFApplicationIdentifier->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAFApplicationIdentifier->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AFApplicationIdentifier is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAFApplicationIdentifier->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAFApplicationIdentifier->Decode(mspByteArray.get(), mAFApplicationIdentifier->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AFApplicationIdentifier")     ;
			throw lTssDiaMsgException;
		}
		mAFApplicationIdentifier->mAvpDecodedFlag = true;
	}
	return mAFApplicationIdentifier;
}

list<MediaComponentDescription*>* AARequest::getMediaComponentDescriptionGrpList()
{
	if(mMediaComponentDescriptionGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MediaComponentDescription is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mMediaComponentDescriptionGrpList)
	{
		if(mMediaComponentDescriptionGrpList != NULL)
		{
		if(mMediaComponentDescriptionGrpList->size() == 0)
		{
			mTagsPresent[AARequest_MEDIACOMPONENTDESCRIPTION] = 0;
			mMediaComponentDescriptionGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MediaComponentDescription is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MediaComponentDescription is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MediaComponentDescription")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mMediaComponentDescriptionGrpList;
}

list<MediaComponentDescription*>* AARequest::setMediaComponentDescriptionGrpList(){
	mTagsPresent[AARequest_MEDIACOMPONENTDESCRIPTION] = 1;
	if(mMediaComponentDescriptionGrpList == NULL)
		mMediaComponentDescriptionGrpList = new list<MediaComponentDescription*>;
	mMandatoryAvpSetVal[AARequest_MEDIACOMPONENTDESCRIPTION] = 1;
	mMediaComponentDescriptionGrpList->clear();
	return mMediaComponentDescriptionGrpList;
}

void AARequest::resetMediaComponentDescriptionGrpList(){
	mTagsPresent[AARequest_MEDIACOMPONENTDESCRIPTION] = 0;
	if(mMediaComponentDescriptionGrpList != NULL)
		delete mMediaComponentDescriptionGrpList;
}

ServiceInfoStatus* AARequest::getServiceInfoStatus(){
	if(NULL == mServiceInfoStatus) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ServiceInfoStatus is Null");
		throw lTssDiaMsgException;
	}
	if(!mServiceInfoStatus->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mServiceInfoStatus->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ServiceInfoStatus is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mServiceInfoStatus->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mServiceInfoStatus->Decode(mspByteArray.get(), mServiceInfoStatus->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ServiceInfoStatus")     ;
			throw lTssDiaMsgException;
		}
		mServiceInfoStatus->mAvpDecodedFlag = true;
	}
	return mServiceInfoStatus;
}

OctetString* AARequest::getAFChargingIdentifier(){
	if(NULL == mAFChargingIdentifier) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AFChargingIdentifier is Null");
		throw lTssDiaMsgException;
	}
	if(!mAFChargingIdentifier->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAFChargingIdentifier->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AFChargingIdentifier is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAFChargingIdentifier->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAFChargingIdentifier->Decode(mspByteArray.get(), mAFChargingIdentifier->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AFChargingIdentifier")     ;
			throw lTssDiaMsgException;
		}
		mAFChargingIdentifier->mAvpDecodedFlag = true;
	}
	return mAFChargingIdentifier;
}

SIPForkingIndication* AARequest::getSIPForkingIndication(){
	if(NULL == mSIPForkingIndication) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SIPForkingIndication is Null");
		throw lTssDiaMsgException;
	}
	if(!mSIPForkingIndication->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSIPForkingIndication->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SIPForkingIndication is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSIPForkingIndication->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSIPForkingIndication->Decode(mspByteArray.get(), mSIPForkingIndication->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SIPForkingIndication")     ;
			throw lTssDiaMsgException;
		}
		mSIPForkingIndication->mAvpDecodedFlag = true;
	}
	return mSIPForkingIndication;
}

list<SpecificAction*>* AARequest::getSpecificActionList()
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

list<SpecificAction*>* AARequest::setSpecificActionList() {
	mTagsPresent[AARequest_SPECIFICACTION] = 1;
	if(mSpecificActionList == NULL)
		mSpecificActionList = new list<SpecificAction*>;
	mMandatoryAvpSetVal [AARequest_SPECIFICACTION] = 1;
	mSpecificActionList->clear();
	return mSpecificActionList;
}

void AARequest::resetSpecificActionList(){
	mTagsPresent[AARequest_SPECIFICACTION] = 0;
	if(mSpecificActionList != NULL)
		delete mSpecificActionList;
}

list<SubscriptionId*>* AARequest::getSubscriptionIdGrpList()
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
			mTagsPresent[AARequest_SUBSCRIPTIONID] = 0;
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

list<SubscriptionId*>* AARequest::setSubscriptionIdGrpList(){
	mTagsPresent[AARequest_SUBSCRIPTIONID] = 1;
	if(mSubscriptionIdGrpList == NULL)
		mSubscriptionIdGrpList = new list<SubscriptionId*>;
	mMandatoryAvpSetVal[AARequest_SUBSCRIPTIONID] = 1;
	mSubscriptionIdGrpList->clear();
	return mSubscriptionIdGrpList;
}

void AARequest::resetSubscriptionIdGrpList(){
	mTagsPresent[AARequest_SUBSCRIPTIONID] = 0;
	if(mSubscriptionIdGrpList != NULL)
		delete mSubscriptionIdGrpList;
}

OCSupportedFeatures* AARequest::getOCSupportedFeatures()
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

OCSupportedFeatures* AARequest::setOCSupportedFeatures(){
	if(mOCSupportedFeaturesGrp == NULL)
		mOCSupportedFeaturesGrp = new OCSupportedFeatures();
	mTagsPresent[AARequest_OCSUPPORTEDFEATURES] = 1;
	return mOCSupportedFeaturesGrp;
}

void AARequest::resetOCSupportedFeatures(){
	mTagsPresent[AARequest_OCSUPPORTEDFEATURES] = 0;
	if(mOCSupportedFeaturesGrp != NULL)
		delete mOCSupportedFeaturesGrp;
}

list<SupportedFeatures*>* AARequest::getSupportedFeaturesGrpList()
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
			mTagsPresent[AARequest_SUPPORTEDFEATURES] = 0;
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

list<SupportedFeatures*>* AARequest::setSupportedFeaturesGrpList(){
	mTagsPresent[AARequest_SUPPORTEDFEATURES] = 1;
	if(mSupportedFeaturesGrpList == NULL)
		mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
	mMandatoryAvpSetVal[AARequest_SUPPORTEDFEATURES] = 1;
	mSupportedFeaturesGrpList->clear();
	return mSupportedFeaturesGrpList;
}

void AARequest::resetSupportedFeaturesGrpList(){
	mTagsPresent[AARequest_SUPPORTEDFEATURES] = 0;
	if(mSupportedFeaturesGrpList != NULL)
		delete mSupportedFeaturesGrpList;
}

ReservationPriority* AARequest::getReservationPriority(){
	if(NULL == mReservationPriority) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ReservationPriority is Null");
		throw lTssDiaMsgException;
	}
	if(!mReservationPriority->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mReservationPriority->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ReservationPriority is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mReservationPriority->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mReservationPriority->Decode(mspByteArray.get(), mReservationPriority->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ReservationPriority")     ;
			throw lTssDiaMsgException;
		}
		mReservationPriority->mAvpDecodedFlag = true;
	}
	return mReservationPriority;
}

OctetString* AARequest::getFramedIPAddress(){
	if(NULL == mFramedIPAddress) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FramedIPAddress is Null");
		throw lTssDiaMsgException;
	}
	if(!mFramedIPAddress->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mFramedIPAddress->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FramedIPAddress is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mFramedIPAddress->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mFramedIPAddress->Decode(mspByteArray.get(), mFramedIPAddress->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FramedIPAddress")     ;
			throw lTssDiaMsgException;
		}
		mFramedIPAddress->mAvpDecodedFlag = true;
	}
	return mFramedIPAddress;
}

OctetString* AARequest::getFramedIPv6Prefix(){
	if(NULL == mFramedIPv6Prefix) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FramedIPv6Prefix is Null");
		throw lTssDiaMsgException;
	}
	if(!mFramedIPv6Prefix->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mFramedIPv6Prefix->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FramedIPv6Prefix is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mFramedIPv6Prefix->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mFramedIPv6Prefix->Decode(mspByteArray.get(), mFramedIPv6Prefix->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FramedIPv6Prefix")     ;
			throw lTssDiaMsgException;
		}
		mFramedIPv6Prefix->mAvpDecodedFlag = true;
	}
	return mFramedIPv6Prefix;
}

OctetString* AARequest::getCalledStationId(){
	if(NULL == mCalledStationId) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CalledStationId is Null");
		throw lTssDiaMsgException;
	}
	if(!mCalledStationId->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCalledStationId->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CalledStationId is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCalledStationId->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCalledStationId->Decode(mspByteArray.get(), mCalledStationId->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CalledStationId")     ;
			throw lTssDiaMsgException;
		}
		mCalledStationId->mAvpDecodedFlag = true;
	}
	return mCalledStationId;
}

OctetString* AARequest::getServiceURN(){
	if(NULL == mServiceURN) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ServiceURN is Null");
		throw lTssDiaMsgException;
	}
	if(!mServiceURN->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mServiceURN->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ServiceURN is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mServiceURN->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mServiceURN->Decode(mspByteArray.get(), mServiceURN->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ServiceURN")     ;
			throw lTssDiaMsgException;
		}
		mServiceURN->mAvpDecodedFlag = true;
	}
	return mServiceURN;
}

list<SponsoredConnectivityData*>* AARequest::getSponsoredConnectivityDataGrpList()
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
			mTagsPresent[AARequest_SPONSOREDCONNECTIVITYDATA] = 0;
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

list<SponsoredConnectivityData*>* AARequest::setSponsoredConnectivityDataGrpList(){
	mTagsPresent[AARequest_SPONSOREDCONNECTIVITYDATA] = 1;
	if(mSponsoredConnectivityDataGrpList == NULL)
		mSponsoredConnectivityDataGrpList = new list<SponsoredConnectivityData*>;
	mSponsoredConnectivityDataGrpList->clear();
	return mSponsoredConnectivityDataGrpList;
}

void AARequest::resetSponsoredConnectivityDataGrpList(){
	mTagsPresent[AARequest_SPONSOREDCONNECTIVITYDATA] = 0;
	if(mSponsoredConnectivityDataGrpList != NULL)
		delete mSponsoredConnectivityDataGrpList;
}

OctetString* AARequest::getMPSIdentifier(){
	if(NULL == mMPSIdentifier) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MPSIdentifier is Null");
		throw lTssDiaMsgException;
	}
	if(!mMPSIdentifier->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMPSIdentifier->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MPSIdentifier is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMPSIdentifier->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMPSIdentifier->Decode(mspByteArray.get(), mMPSIdentifier->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MPSIdentifier")     ;
			throw lTssDiaMsgException;
		}
		mMPSIdentifier->mAvpDecodedFlag = true;
	}
	return mMPSIdentifier;
}

OctetString* AARequest::getGCSIdentifier(){
	if(NULL == mGCSIdentifier) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "GCSIdentifier is Null");
		throw lTssDiaMsgException;
	}
	if(!mGCSIdentifier->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mGCSIdentifier->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "GCSIdentifier is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mGCSIdentifier->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mGCSIdentifier->Decode(mspByteArray.get(), mGCSIdentifier->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding GCSIdentifier")     ;
			throw lTssDiaMsgException;
		}
		mGCSIdentifier->mAvpDecodedFlag = true;
	}
	return mGCSIdentifier;
}

OctetString* AARequest::getMCPTTIdentifier(){
	if(NULL == mMCPTTIdentifier) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MCPTTIdentifier is Null");
		throw lTssDiaMsgException;
	}
	if(!mMCPTTIdentifier->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMCPTTIdentifier->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MCPTTIdentifier is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMCPTTIdentifier->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMCPTTIdentifier->Decode(mspByteArray.get(), mMCPTTIdentifier->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MCPTTIdentifier")     ;
			throw lTssDiaMsgException;
		}
		mMCPTTIdentifier->mAvpDecodedFlag = true;
	}
	return mMCPTTIdentifier;
}

OctetString* AARequest::getMCVideoIdentifier(){
	if(NULL == mMCVideoIdentifier) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MCVideoIdentifier is Null");
		throw lTssDiaMsgException;
	}
	if(!mMCVideoIdentifier->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMCVideoIdentifier->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MCVideoIdentifier is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMCVideoIdentifier->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMCVideoIdentifier->Decode(mspByteArray.get(), mMCVideoIdentifier->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MCVideoIdentifier")     ;
			throw lTssDiaMsgException;
		}
		mMCVideoIdentifier->mAvpDecodedFlag = true;
	}
	return mMCVideoIdentifier;
}

OctetString* AARequest::getIMSContentIdentifier(){
	if(NULL == mIMSContentIdentifier) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "IMSContentIdentifier is Null");
		throw lTssDiaMsgException;
	}
	if(!mIMSContentIdentifier->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mIMSContentIdentifier->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "IMSContentIdentifier is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mIMSContentIdentifier->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mIMSContentIdentifier->Decode(mspByteArray.get(), mIMSContentIdentifier->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding IMSContentIdentifier")     ;
			throw lTssDiaMsgException;
		}
		mIMSContentIdentifier->mAvpDecodedFlag = true;
	}
	return mIMSContentIdentifier;
}

IMSContentType* AARequest::getIMSContentType(){
	if(NULL == mIMSContentType) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "IMSContentType is Null");
		throw lTssDiaMsgException;
	}
	if(!mIMSContentType->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mIMSContentType->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "IMSContentType is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mIMSContentType->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mIMSContentType->Decode(mspByteArray.get(), mIMSContentType->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding IMSContentType")     ;
			throw lTssDiaMsgException;
		}
		mIMSContentType->mAvpDecodedFlag = true;
	}
	return mIMSContentType;
}

OctetString* AARequest::getCallingPartyAddress(){
	if(NULL == mCallingPartyAddress) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CallingPartyAddress is Null");
		throw lTssDiaMsgException;
	}
	if(!mCallingPartyAddress->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCallingPartyAddress->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CallingPartyAddress is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCallingPartyAddress->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCallingPartyAddress->Decode(mspByteArray.get(), mCallingPartyAddress->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CallingPartyAddress")     ;
			throw lTssDiaMsgException;
		}
		mCallingPartyAddress->mAvpDecodedFlag = true;
	}
	return mCallingPartyAddress;
}

list<CalleeInformation*>* AARequest::getCalleeInformationGrpList()
{
	if(mCalleeInformationGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CalleeInformation is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mCalleeInformationGrpList)
	{
		if(mCalleeInformationGrpList != NULL)
		{
		if(mCalleeInformationGrpList->size() == 0)
		{
			mTagsPresent[AARequest_CALLEEINFORMATION] = 0;
			mCalleeInformationGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CalleeInformation is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CalleeInformation is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CalleeInformation")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mCalleeInformationGrpList;
}

list<CalleeInformation*>* AARequest::setCalleeInformationGrpList(){
	mTagsPresent[AARequest_CALLEEINFORMATION] = 1;
	if(mCalleeInformationGrpList == NULL)
		mCalleeInformationGrpList = new list<CalleeInformation*>;
	mCalleeInformationGrpList->clear();
	return mCalleeInformationGrpList;
}

void AARequest::resetCalleeInformationGrpList(){
	mTagsPresent[AARequest_CALLEEINFORMATION] = 0;
	if(mCalleeInformationGrpList != NULL)
		delete mCalleeInformationGrpList;
}

RxRequestType* AARequest::getRxRequestType(){
	if(NULL == mRxRequestType) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RxRequestType is Null");
		throw lTssDiaMsgException;
	}
	if(!mRxRequestType->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRxRequestType->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RxRequestType is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRxRequestType->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRxRequestType->Decode(mspByteArray.get(), mRxRequestType->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RxRequestType")     ;
			throw lTssDiaMsgException;
		}
		mRxRequestType->mAvpDecodedFlag = true;
	}
	return mRxRequestType;
}

list<OctetString*>* AARequest::getRequiredAccessInfoList()
{
	if(mRequiredAccessInfoList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RequiredAccessInfo is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mRequiredAccessInfoList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RequiredAccessInfo is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RequiredAccessInfo")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mRequiredAccessInfoList;
}

list<OctetString*>* AARequest::setRequiredAccessInfoList() {
	mTagsPresent[AARequest_REQUIREDACCESSINFO] = 1;
	if(mRequiredAccessInfoList == NULL)
		mRequiredAccessInfoList = new list<OctetString*>;
	mRequiredAccessInfoList->clear();
	return mRequiredAccessInfoList;
}

void AARequest::resetRequiredAccessInfoList(){
	mTagsPresent[AARequest_REQUIREDACCESSINFO] = 0;
	if(mRequiredAccessInfoList != NULL)
		delete mRequiredAccessInfoList;
}

Unsigned32* AARequest::getAFRequestedData(){
	if(NULL == mAFRequestedData) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AFRequestedData is Null");
		throw lTssDiaMsgException;
	}
	if(!mAFRequestedData->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAFRequestedData->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AFRequestedData is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAFRequestedData->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAFRequestedData->Decode(mspByteArray.get(), mAFRequestedData->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AFRequestedData")     ;
			throw lTssDiaMsgException;
		}
		mAFRequestedData->mAvpDecodedFlag = true;
	}
	return mAFRequestedData;
}

OctetString* AARequest::getReferenceID(){
	if(NULL == mReferenceID) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ReferenceID is Null");
		throw lTssDiaMsgException;
	}
	if(!mReferenceID->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mReferenceID->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ReferenceID is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mReferenceID->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mReferenceID->Decode(mspByteArray.get(), mReferenceID->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ReferenceID")     ;
			throw lTssDiaMsgException;
		}
		mReferenceID->mAvpDecodedFlag = true;
	}
	return mReferenceID;
}

Unsigned32* AARequest::getPreEmptionControlInfo(){
	if(NULL == mPreEmptionControlInfo) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PreEmptionControlInfo is Null");
		throw lTssDiaMsgException;
	}
	if(!mPreEmptionControlInfo->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPreEmptionControlInfo->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PreEmptionControlInfo is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPreEmptionControlInfo->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPreEmptionControlInfo->Decode(mspByteArray.get(), mPreEmptionControlInfo->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PreEmptionControlInfo")     ;
			throw lTssDiaMsgException;
		}
		mPreEmptionControlInfo->mAvpDecodedFlag = true;
	}
	return mPreEmptionControlInfo;
}

MPSAction* AARequest::getMPSAction(){
	if(NULL == mMPSAction) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MPSAction is Null");
		throw lTssDiaMsgException;
	}
	if(!mMPSAction->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMPSAction->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MPSAction is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMPSAction->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMPSAction->Decode(mspByteArray.get(), mMPSAction->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MPSAction")     ;
			throw lTssDiaMsgException;
		}
		mMPSAction->mAvpDecodedFlag = true;
	}
	return mMPSAction;
}

Unsigned32* AARequest::getOriginStateId(){
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

list<RX::ProxyInfo*>* AARequest::getProxyInfoGrpList()
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
			mTagsPresent[AARequest_PROXYINFO] = 0;
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

list<RX::ProxyInfo*>* AARequest::setProxyInfoGrpList(){
	mTagsPresent[AARequest_PROXYINFO] = 1;
	if(mProxyInfoGrpList == NULL)
		mProxyInfoGrpList = new list<RX::ProxyInfo*>;
	mMandatoryAvpSetVal[AARequest_PROXYINFO] = 1;
	mProxyInfoGrpList->clear();
	return mProxyInfoGrpList;
}

void AARequest::resetProxyInfoGrpList(){
	mTagsPresent[AARequest_PROXYINFO] = 0;
	if(mProxyInfoGrpList != NULL)
		delete mProxyInfoGrpList;
}

list<OctetString*>* AARequest::getRouteRecordList()
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

list<OctetString*>* AARequest::setRouteRecordList() {
	mTagsPresent[AARequest_ROUTERECORD] = 1;
	if(mRouteRecordList == NULL)
		mRouteRecordList = new list<OctetString*>;
	mRouteRecordList->clear();
	return mRouteRecordList;
}

void AARequest::resetRouteRecordList(){
	mTagsPresent[AARequest_ROUTERECORD] = 0;
	if(mRouteRecordList != NULL)
		delete mRouteRecordList;
}



int AARequest::Encode(byteArray *array)
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
			case AARequest_SESSIONID:
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
			case AARequest_DRMP:
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
			case AARequest_AUTHAPPLICATIONID:
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
						INT32 venderId=0;
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
			case AARequest_ORIGINHOST:
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
			case AARequest_ORIGINREALM:
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
			case AARequest_DESTINATIONREALM:
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
			case AARequest_DESTINATIONHOST:
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
			case AARequest_IPDOMAINID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(537);
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
					if(!mIPDomainId->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mIPDomainId->getAvpOffsetLen().first], mIPDomainId->getAvpOffsetLen().second);
						array->offset += mIPDomainId->getAvpOffsetLen().second;
						array->size += mIPDomainId->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mIPDomainId->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mIPDomainId->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding IPDomainId");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mIPDomainId->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mIPDomainId->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding IPDomainId");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AARequest_AUTHSESSIONSTATE:
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
			case AARequest_AFAPPLICATIONIDENTIFIER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(504);
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
					if(!mAFApplicationIdentifier->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAFApplicationIdentifier->getAvpOffsetLen().first], mAFApplicationIdentifier->getAvpOffsetLen().second);
						array->offset += mAFApplicationIdentifier->getAvpOffsetLen().second;
						array->size += mAFApplicationIdentifier->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mAFApplicationIdentifier->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mAFApplicationIdentifier->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AFApplicationIdentifier");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mAFApplicationIdentifier->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mAFApplicationIdentifier->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AFApplicationIdentifier");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AARequest_MEDIACOMPONENTDESCRIPTION:
			{
				if( mMediaComponentDescriptionGrpList->size() <= 0) {
					break;
				}

				mMediaComponentDescriptionGrpIterator = this->getMediaComponentDescriptionGrpList()->begin();
				while(mMediaComponentDescriptionGrpIterator != mMediaComponentDescriptionGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(517);
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
					if(((*mMediaComponentDescriptionGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MediaComponentDescription");
						throw lTssDiaMsgException;
					}
					
					mMediaComponentDescriptionGrpIterator++;
				}
				}
				break;
			case AARequest_SERVICEINFOSTATUS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(527);
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
					if(!mServiceInfoStatus->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mServiceInfoStatus->getAvpOffsetLen().first], mServiceInfoStatus->getAvpOffsetLen().second);
						array->offset += mServiceInfoStatus->getAvpOffsetLen().second;
						array->size += mServiceInfoStatus->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ServiceInfoStatus");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mServiceInfoStatus->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ServiceInfoStatus");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AARequest_AFCHARGINGIDENTIFIER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(505);
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
					if(!mAFChargingIdentifier->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAFChargingIdentifier->getAvpOffsetLen().first], mAFChargingIdentifier->getAvpOffsetLen().second);
						array->offset += mAFChargingIdentifier->getAvpOffsetLen().second;
						array->size += mAFChargingIdentifier->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mAFChargingIdentifier->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mAFChargingIdentifier->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AFChargingIdentifier");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mAFChargingIdentifier->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mAFChargingIdentifier->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AFChargingIdentifier");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AARequest_SIPFORKINGINDICATION:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(523);
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
					if(!mSIPForkingIndication->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSIPForkingIndication->getAvpOffsetLen().first], mSIPForkingIndication->getAvpOffsetLen().second);
						array->offset += mSIPForkingIndication->getAvpOffsetLen().second;
						array->size += mSIPForkingIndication->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SIPForkingIndication");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mSIPForkingIndication->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SIPForkingIndication");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AARequest_SPECIFICACTION:
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
			case AARequest_SUBSCRIPTIONID:
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
			case AARequest_OCSUPPORTEDFEATURES:
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
			case AARequest_SUPPORTEDFEATURES:
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
			case AARequest_RESERVATIONPRIORITY:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(458);
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
					if(!mReservationPriority->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mReservationPriority->getAvpOffsetLen().first], mReservationPriority->getAvpOffsetLen().second);
						array->offset += mReservationPriority->getAvpOffsetLen().second;
						array->size += mReservationPriority->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ReservationPriority");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mReservationPriority->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ReservationPriority");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AARequest_FRAMEDIPADDRESS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(8);
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
					if(!mFramedIPAddress->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mFramedIPAddress->getAvpOffsetLen().first], mFramedIPAddress->getAvpOffsetLen().second);
						array->offset += mFramedIPAddress->getAvpOffsetLen().second;
						array->size += mFramedIPAddress->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mFramedIPAddress->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mFramedIPAddress->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FramedIPAddress");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mFramedIPAddress->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mFramedIPAddress->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FramedIPAddress");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AARequest_FRAMEDIPV6PREFIX:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(97);
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
					if(!mFramedIPv6Prefix->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mFramedIPv6Prefix->getAvpOffsetLen().first], mFramedIPv6Prefix->getAvpOffsetLen().second);
						array->offset += mFramedIPv6Prefix->getAvpOffsetLen().second;
						array->size += mFramedIPv6Prefix->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mFramedIPv6Prefix->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mFramedIPv6Prefix->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FramedIPv6Prefix");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mFramedIPv6Prefix->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mFramedIPv6Prefix->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FramedIPv6Prefix");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AARequest_CALLEDSTATIONID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(30);
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
					if(!mCalledStationId->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCalledStationId->getAvpOffsetLen().first], mCalledStationId->getAvpOffsetLen().second);
						array->offset += mCalledStationId->getAvpOffsetLen().second;
						array->size += mCalledStationId->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mCalledStationId->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mCalledStationId->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CalledStationId");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mCalledStationId->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mCalledStationId->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CalledStationId");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AARequest_SERVICEURN:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(525);
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
					if(!mServiceURN->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mServiceURN->getAvpOffsetLen().first], mServiceURN->getAvpOffsetLen().second);
						array->offset += mServiceURN->getAvpOffsetLen().second;
						array->size += mServiceURN->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mServiceURN->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mServiceURN->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ServiceURN");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mServiceURN->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mServiceURN->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ServiceURN");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AARequest_SPONSOREDCONNECTIVITYDATA:
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
			case AARequest_MPSIDENTIFIER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(528);
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
					if(!mMPSIdentifier->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMPSIdentifier->getAvpOffsetLen().first], mMPSIdentifier->getAvpOffsetLen().second);
						array->offset += mMPSIdentifier->getAvpOffsetLen().second;
						array->size += mMPSIdentifier->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mMPSIdentifier->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mMPSIdentifier->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MPSIdentifier");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mMPSIdentifier->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mMPSIdentifier->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MPSIdentifier");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AARequest_GCSIDENTIFIER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(538);
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
					if(!mGCSIdentifier->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mGCSIdentifier->getAvpOffsetLen().first], mGCSIdentifier->getAvpOffsetLen().second);
						array->offset += mGCSIdentifier->getAvpOffsetLen().second;
						array->size += mGCSIdentifier->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mGCSIdentifier->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mGCSIdentifier->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding GCSIdentifier");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mGCSIdentifier->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mGCSIdentifier->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding GCSIdentifier");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AARequest_MCPTTIDENTIFIER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(547);
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
					if(!mMCPTTIdentifier->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMCPTTIdentifier->getAvpOffsetLen().first], mMCPTTIdentifier->getAvpOffsetLen().second);
						array->offset += mMCPTTIdentifier->getAvpOffsetLen().second;
						array->size += mMCPTTIdentifier->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mMCPTTIdentifier->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mMCPTTIdentifier->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MCPTTIdentifier");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mMCPTTIdentifier->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mMCPTTIdentifier->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MCPTTIdentifier");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AARequest_MCVIDEOIDENTIFIER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(562);
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
					if(!mMCVideoIdentifier->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMCVideoIdentifier->getAvpOffsetLen().first], mMCVideoIdentifier->getAvpOffsetLen().second);
						array->offset += mMCVideoIdentifier->getAvpOffsetLen().second;
						array->size += mMCVideoIdentifier->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mMCVideoIdentifier->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mMCVideoIdentifier->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MCVideoIdentifier");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mMCVideoIdentifier->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mMCVideoIdentifier->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MCVideoIdentifier");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AARequest_IMSCONTENTIDENTIFIER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(563);
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
					if(!mIMSContentIdentifier->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mIMSContentIdentifier->getAvpOffsetLen().first], mIMSContentIdentifier->getAvpOffsetLen().second);
						array->offset += mIMSContentIdentifier->getAvpOffsetLen().second;
						array->size += mIMSContentIdentifier->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mIMSContentIdentifier->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mIMSContentIdentifier->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding IMSContentIdentifier");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mIMSContentIdentifier->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mIMSContentIdentifier->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding IMSContentIdentifier");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AARequest_IMSCONTENTTYPE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(564);
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
					if(!mIMSContentType->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mIMSContentType->getAvpOffsetLen().first], mIMSContentType->getAvpOffsetLen().second);
						array->offset += mIMSContentType->getAvpOffsetLen().second;
						array->size += mIMSContentType->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding IMSContentType");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mIMSContentType->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding IMSContentType");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AARequest_CALLINGPARTYADDRESS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(831);
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
					if(!mCallingPartyAddress->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCallingPartyAddress->getAvpOffsetLen().first], mCallingPartyAddress->getAvpOffsetLen().second);
						array->offset += mCallingPartyAddress->getAvpOffsetLen().second;
						array->size += mCallingPartyAddress->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mCallingPartyAddress->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mCallingPartyAddress->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CallingPartyAddress");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mCallingPartyAddress->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mCallingPartyAddress->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CallingPartyAddress");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AARequest_CALLEEINFORMATION:
			{
				if( mCalleeInformationGrpList->size() <= 0) {
					break;
				}

				mCalleeInformationGrpIterator = this->getCalleeInformationGrpList()->begin();
				while(mCalleeInformationGrpIterator != mCalleeInformationGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(565);
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
					if(((*mCalleeInformationGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CalleeInformation");
						throw lTssDiaMsgException;
					}
					
					mCalleeInformationGrpIterator++;
				}
				}
				break;
			case AARequest_RXREQUESTTYPE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(533);
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
					if(!mRxRequestType->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRxRequestType->getAvpOffsetLen().first], mRxRequestType->getAvpOffsetLen().second);
						array->offset += mRxRequestType->getAvpOffsetLen().second;
						array->size += mRxRequestType->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RxRequestType");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mRxRequestType->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RxRequestType");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AARequest_REQUIREDACCESSINFO:
			{
					if( mRequiredAccessInfoList->size() <= 0) {
						break;
					}

					mRequiredAccessInfoIterator = this->getRequiredAccessInfoList()->begin();
					while(mRequiredAccessInfoIterator != mRequiredAccessInfoList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(536);
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
					if(!(*mRequiredAccessInfoIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mRequiredAccessInfoIterator)->getAvpOffsetLen().first], (*mRequiredAccessInfoIterator)->getAvpOffsetLen().second);
						array->offset += (*mRequiredAccessInfoIterator)->getAvpOffsetLen().second;
						array->size += (*mRequiredAccessInfoIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mRequiredAccessInfoIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mRequiredAccessInfoIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RequiredAccessInfo");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mRequiredAccessInfoIterator++;
						continue;
					}
						if(((*mRequiredAccessInfoIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mRequiredAccessInfoIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RequiredAccessInfo");
							throw lTssDiaMsgException;
						}
						mRequiredAccessInfoIterator++;
				}
				}
				break;
			case AARequest_AFREQUESTEDDATA:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(551);
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
					if(!mAFRequestedData->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAFRequestedData->getAvpOffsetLen().first], mAFRequestedData->getAvpOffsetLen().second);
						array->offset += mAFRequestedData->getAvpOffsetLen().second;
						array->size += mAFRequestedData->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AFRequestedData");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mAFRequestedData->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AFRequestedData");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AARequest_REFERENCEID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(552);
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
					if(!mReferenceID->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mReferenceID->getAvpOffsetLen().first], mReferenceID->getAvpOffsetLen().second);
						array->offset += mReferenceID->getAvpOffsetLen().second;
						array->size += mReferenceID->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mReferenceID->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mReferenceID->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ReferenceID");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mReferenceID->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mReferenceID->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ReferenceID");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AARequest_PREEMPTIONCONTROLINFO:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(553);
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
					if(!mPreEmptionControlInfo->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mPreEmptionControlInfo->getAvpOffsetLen().first], mPreEmptionControlInfo->getAvpOffsetLen().second);
						array->offset += mPreEmptionControlInfo->getAvpOffsetLen().second;
						array->size += mPreEmptionControlInfo->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PreEmptionControlInfo");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mPreEmptionControlInfo->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PreEmptionControlInfo");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AARequest_MPSACTION:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(582);
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
					if(!mMPSAction->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMPSAction->getAvpOffsetLen().first], mMPSAction->getAvpOffsetLen().second);
						array->offset += mMPSAction->getAvpOffsetLen().second;
						array->size += mMPSAction->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MPSAction");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mMPSAction->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MPSAction");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AARequest_ORIGINSTATEID:
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
			case AARequest_PROXYINFO:
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
			case AARequest_ROUTERECORD:
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


int AARequest::Decode(byteArray *array, INT16 lMLen, UINT16 *parsedBytes)
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
						mMandatoryAvpSetVal [AARequest_SESSIONID] = 1;
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
						mMandatoryAvpSetVal [AARequest_AUTHAPPLICATIONID] = 1;
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
						mMandatoryAvpSetVal [AARequest_ORIGINHOST] = 1;
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
						mMandatoryAvpSetVal [AARequest_ORIGINREALM] = 1;
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
						mMandatoryAvpSetVal [AARequest_DESTINATIONREALM] = 1;
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
						mMandatoryAvpSetVal [AARequest_DESTINATIONHOST] = 1;
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
			case 537:
				{
					if( NULL == this->setIPDomainId())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding IPDomainId");
						throw lTssDiaMsgException;
					}
					mIPDomainId->setAvpCode(537);
					mIPDomainId->setAvpVendorId(lVenderId);
					mIPDomainId->SetDataType((DiameterDataType)5);
					mIPDomainId->mspByteArray = mspByteArray;
					mIPDomainId->mAvpDecodedFlag = false;
					mIPDomainId->setAvpOffsetLen(array->offset,lAvpDataLen);
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
			case 504:
				{
						mMandatoryAvpSetVal [AARequest_AFAPPLICATIONIDENTIFIER] = 1;
					if( NULL == this->setAFApplicationIdentifier())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AFApplicationIdentifier");
						throw lTssDiaMsgException;
					}
					mAFApplicationIdentifier->setAvpCode(504);
					mAFApplicationIdentifier->setAvpVendorId(lVenderId);
					mAFApplicationIdentifier->SetDataType((DiameterDataType)5);
					mAFApplicationIdentifier->mspByteArray = mspByteArray;
					mAFApplicationIdentifier->mAvpDecodedFlag = false;
					mAFApplicationIdentifier->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 517:
				{
						mMandatoryAvpSetVal [AARequest_MEDIACOMPONENTDESCRIPTION] = 1;
					mTagsPresent[AARequest_MEDIACOMPONENTDESCRIPTION] = 1;
					MediaComponentDescription *lMediaComponentDescription = new MediaComponentDescription();
					if( lMediaComponentDescription == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MediaComponentDescription");
						throw lTssDiaMsgException;
					}
					lMediaComponentDescription->setAvpCode(517);
					lMediaComponentDescription->SetDataType((DiameterDataType)6);
					lMediaComponentDescription->mspByteArray = mspByteArray;
					lMediaComponentDescription->mAvpDecodedFlag = false;
					lMediaComponentDescription->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mMediaComponentDescriptionGrpList == NULL)
						this->setMediaComponentDescriptionGrpList();
					mMediaComponentDescriptionGrpList->push_back(lMediaComponentDescription);
					mBaseInterfaceList.push_back(lMediaComponentDescription);
					
				}
				break;
			case 527:
				{
						mMandatoryAvpSetVal [AARequest_SERVICEINFOSTATUS] = 1;
					if( NULL == this->setServiceInfoStatus())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ServiceInfoStatus");
						throw lTssDiaMsgException;
					}
					mServiceInfoStatus->setAvpCode(527);
					mServiceInfoStatus->setAvpVendorId(lVenderId);
					mServiceInfoStatus->SetDataType((DiameterDataType)7);
					mServiceInfoStatus->mspByteArray = mspByteArray;
					mServiceInfoStatus->mAvpDecodedFlag = false;
					mServiceInfoStatus->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 505:
				{
						mMandatoryAvpSetVal [AARequest_AFCHARGINGIDENTIFIER] = 1;
					if( NULL == this->setAFChargingIdentifier())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AFChargingIdentifier");
						throw lTssDiaMsgException;
					}
					mAFChargingIdentifier->setAvpCode(505);
					mAFChargingIdentifier->setAvpVendorId(lVenderId);
					mAFChargingIdentifier->SetDataType((DiameterDataType)5);
					mAFChargingIdentifier->mspByteArray = mspByteArray;
					mAFChargingIdentifier->mAvpDecodedFlag = false;
					mAFChargingIdentifier->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 523:
				{
						mMandatoryAvpSetVal [AARequest_SIPFORKINGINDICATION] = 1;
					if( NULL == this->setSIPForkingIndication())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SIPForkingIndication");
						throw lTssDiaMsgException;
					}
					mSIPForkingIndication->setAvpCode(523);
					mSIPForkingIndication->setAvpVendorId(lVenderId);
					mSIPForkingIndication->SetDataType((DiameterDataType)7);
					mSIPForkingIndication->mspByteArray = mspByteArray;
					mSIPForkingIndication->mAvpDecodedFlag = false;
					mSIPForkingIndication->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 513:
				{
						mMandatoryAvpSetVal [AARequest_SPECIFICACTION] = 1;
					mTagsPresent[AARequest_SPECIFICACTION] = 1;
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
			case 443:
				{
						mMandatoryAvpSetVal [AARequest_SUBSCRIPTIONID] = 1;
					mTagsPresent[AARequest_SUBSCRIPTIONID] = 1;
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
			case 621:
				{
					mTagsPresent[AARequest_OCSUPPORTEDFEATURES] = 1;
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
			case 628:
				{
						mMandatoryAvpSetVal [AARequest_SUPPORTEDFEATURES] = 1;
					mTagsPresent[AARequest_SUPPORTEDFEATURES] = 1;
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
			case 458:
				{
					if( NULL == this->setReservationPriority())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ReservationPriority");
						throw lTssDiaMsgException;
					}
					mReservationPriority->setAvpCode(458);
					mReservationPriority->setAvpVendorId(lVenderId);
					mReservationPriority->SetDataType((DiameterDataType)7);
					mReservationPriority->mspByteArray = mspByteArray;
					mReservationPriority->mAvpDecodedFlag = false;
					mReservationPriority->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 8:
				{
						mMandatoryAvpSetVal [AARequest_FRAMEDIPADDRESS] = 1;
					if( NULL == this->setFramedIPAddress())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FramedIPAddress");
						throw lTssDiaMsgException;
					}
					mFramedIPAddress->setAvpCode(8);
					mFramedIPAddress->setAvpVendorId(lVenderId);
					mFramedIPAddress->SetDataType((DiameterDataType)5);
					mFramedIPAddress->mspByteArray = mspByteArray;
					mFramedIPAddress->mAvpDecodedFlag = false;
					mFramedIPAddress->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 97:
				{
						mMandatoryAvpSetVal [AARequest_FRAMEDIPV6PREFIX] = 1;
					if( NULL == this->setFramedIPv6Prefix())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FramedIPv6Prefix");
						throw lTssDiaMsgException;
					}
					mFramedIPv6Prefix->setAvpCode(97);
					mFramedIPv6Prefix->setAvpVendorId(lVenderId);
					mFramedIPv6Prefix->SetDataType((DiameterDataType)5);
					mFramedIPv6Prefix->mspByteArray = mspByteArray;
					mFramedIPv6Prefix->mAvpDecodedFlag = false;
					mFramedIPv6Prefix->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 30:
				{
					if( NULL == this->setCalledStationId())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CalledStationId");
						throw lTssDiaMsgException;
					}
					mCalledStationId->setAvpCode(30);
					mCalledStationId->setAvpVendorId(lVenderId);
					mCalledStationId->SetDataType((DiameterDataType)5);
					mCalledStationId->mspByteArray = mspByteArray;
					mCalledStationId->mAvpDecodedFlag = false;
					mCalledStationId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 525:
				{
						mMandatoryAvpSetVal [AARequest_SERVICEURN] = 1;
					if( NULL == this->setServiceURN())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ServiceURN");
						throw lTssDiaMsgException;
					}
					mServiceURN->setAvpCode(525);
					mServiceURN->setAvpVendorId(lVenderId);
					mServiceURN->SetDataType((DiameterDataType)5);
					mServiceURN->mspByteArray = mspByteArray;
					mServiceURN->mAvpDecodedFlag = false;
					mServiceURN->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 530:
				{
					mTagsPresent[AARequest_SPONSOREDCONNECTIVITYDATA] = 1;
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
			case 528:
				{
					if( NULL == this->setMPSIdentifier())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MPSIdentifier");
						throw lTssDiaMsgException;
					}
					mMPSIdentifier->setAvpCode(528);
					mMPSIdentifier->setAvpVendorId(lVenderId);
					mMPSIdentifier->SetDataType((DiameterDataType)5);
					mMPSIdentifier->mspByteArray = mspByteArray;
					mMPSIdentifier->mAvpDecodedFlag = false;
					mMPSIdentifier->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 538:
				{
					if( NULL == this->setGCSIdentifier())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding GCSIdentifier");
						throw lTssDiaMsgException;
					}
					mGCSIdentifier->setAvpCode(538);
					mGCSIdentifier->setAvpVendorId(lVenderId);
					mGCSIdentifier->SetDataType((DiameterDataType)5);
					mGCSIdentifier->mspByteArray = mspByteArray;
					mGCSIdentifier->mAvpDecodedFlag = false;
					mGCSIdentifier->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 547:
				{
					if( NULL == this->setMCPTTIdentifier())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MCPTTIdentifier");
						throw lTssDiaMsgException;
					}
					mMCPTTIdentifier->setAvpCode(547);
					mMCPTTIdentifier->setAvpVendorId(lVenderId);
					mMCPTTIdentifier->SetDataType((DiameterDataType)5);
					mMCPTTIdentifier->mspByteArray = mspByteArray;
					mMCPTTIdentifier->mAvpDecodedFlag = false;
					mMCPTTIdentifier->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 562:
				{
					if( NULL == this->setMCVideoIdentifier())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MCVideoIdentifier");
						throw lTssDiaMsgException;
					}
					mMCVideoIdentifier->setAvpCode(562);
					mMCVideoIdentifier->setAvpVendorId(lVenderId);
					mMCVideoIdentifier->SetDataType((DiameterDataType)5);
					mMCVideoIdentifier->mspByteArray = mspByteArray;
					mMCVideoIdentifier->mAvpDecodedFlag = false;
					mMCVideoIdentifier->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 563:
				{
					if( NULL == this->setIMSContentIdentifier())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding IMSContentIdentifier");
						throw lTssDiaMsgException;
					}
					mIMSContentIdentifier->setAvpCode(563);
					mIMSContentIdentifier->setAvpVendorId(lVenderId);
					mIMSContentIdentifier->SetDataType((DiameterDataType)5);
					mIMSContentIdentifier->mspByteArray = mspByteArray;
					mIMSContentIdentifier->mAvpDecodedFlag = false;
					mIMSContentIdentifier->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 564:
				{
					if( NULL == this->setIMSContentType())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding IMSContentType");
						throw lTssDiaMsgException;
					}
					mIMSContentType->setAvpCode(564);
					mIMSContentType->setAvpVendorId(lVenderId);
					mIMSContentType->SetDataType((DiameterDataType)7);
					mIMSContentType->mspByteArray = mspByteArray;
					mIMSContentType->mAvpDecodedFlag = false;
					mIMSContentType->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 831:
				{
						mMandatoryAvpSetVal [AARequest_CALLINGPARTYADDRESS] = 1;
					if( NULL == this->setCallingPartyAddress())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CallingPartyAddress");
						throw lTssDiaMsgException;
					}
					mCallingPartyAddress->setAvpCode(831);
					mCallingPartyAddress->setAvpVendorId(lVenderId);
					mCallingPartyAddress->SetDataType((DiameterDataType)5);
					mCallingPartyAddress->mspByteArray = mspByteArray;
					mCallingPartyAddress->mAvpDecodedFlag = false;
					mCallingPartyAddress->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 565:
				{
					mTagsPresent[AARequest_CALLEEINFORMATION] = 1;
					CalleeInformation *lCalleeInformation = new CalleeInformation();
					if( lCalleeInformation == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CalleeInformation");
						throw lTssDiaMsgException;
					}
					lCalleeInformation->setAvpCode(565);
					lCalleeInformation->SetDataType((DiameterDataType)6);
					lCalleeInformation->mspByteArray = mspByteArray;
					lCalleeInformation->mAvpDecodedFlag = false;
					lCalleeInformation->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mCalleeInformationGrpList == NULL)
						this->setCalleeInformationGrpList();
					mCalleeInformationGrpList->push_back(lCalleeInformation);
					mBaseInterfaceList.push_back(lCalleeInformation);
					
				}
				break;
			case 533:
				{
					if( NULL == this->setRxRequestType())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RxRequestType");
						throw lTssDiaMsgException;
					}
					mRxRequestType->setAvpCode(533);
					mRxRequestType->setAvpVendorId(lVenderId);
					mRxRequestType->SetDataType((DiameterDataType)7);
					mRxRequestType->mspByteArray = mspByteArray;
					mRxRequestType->mAvpDecodedFlag = false;
					mRxRequestType->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 536:
				{
					mTagsPresent[AARequest_REQUIREDACCESSINFO] = 1;
					OctetString *lRequiredAccessInfo = new OctetString();
					if( lRequiredAccessInfo == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RequiredAccessInfo");
						throw lTssDiaMsgException;
					}
					lRequiredAccessInfo->setAvpCode(536);
					lRequiredAccessInfo->setAvpVendorId(lVenderId);
					lRequiredAccessInfo->SetDataType((DiameterDataType)5);
					lRequiredAccessInfo->mspByteArray = mspByteArray;
					lRequiredAccessInfo->mAvpDecodedFlag = false;
					lRequiredAccessInfo->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mRequiredAccessInfoList == NULL)
						this->setRequiredAccessInfoList();
					mRequiredAccessInfoList->push_back(lRequiredAccessInfo);
					
				}
				break;
			case 551:
				{
					if( NULL == this->setAFRequestedData())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AFRequestedData");
						throw lTssDiaMsgException;
					}
					mAFRequestedData->setAvpCode(551);
					mAFRequestedData->setAvpVendorId(lVenderId);
					mAFRequestedData->SetDataType((DiameterDataType)3);
					mAFRequestedData->mspByteArray = mspByteArray;
					mAFRequestedData->mAvpDecodedFlag = false;
					mAFRequestedData->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 552:
				{
						mMandatoryAvpSetVal [AARequest_REFERENCEID] = 1;
					if( NULL == this->setReferenceID())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ReferenceID");
						throw lTssDiaMsgException;
					}
					mReferenceID->setAvpCode(552);
					mReferenceID->setAvpVendorId(lVenderId);
					mReferenceID->SetDataType((DiameterDataType)5);
					mReferenceID->mspByteArray = mspByteArray;
					mReferenceID->mAvpDecodedFlag = false;
					mReferenceID->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 553:
				{
					if( NULL == this->setPreEmptionControlInfo())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PreEmptionControlInfo");
						throw lTssDiaMsgException;
					}
					mPreEmptionControlInfo->setAvpCode(553);
					mPreEmptionControlInfo->setAvpVendorId(lVenderId);
					mPreEmptionControlInfo->SetDataType((DiameterDataType)3);
					mPreEmptionControlInfo->mspByteArray = mspByteArray;
					mPreEmptionControlInfo->mAvpDecodedFlag = false;
					mPreEmptionControlInfo->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 582:
				{
					if( NULL == this->setMPSAction())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MPSAction");
						throw lTssDiaMsgException;
					}
					mMPSAction->setAvpCode(582);
					mMPSAction->setAvpVendorId(lVenderId);
					mMPSAction->SetDataType((DiameterDataType)7);
					mMPSAction->mspByteArray = mspByteArray;
					mMPSAction->mAvpDecodedFlag = false;
					mMPSAction->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 278:
				{
						mMandatoryAvpSetVal [AARequest_ORIGINSTATEID] = 1;
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
			case 284:
				{
						mMandatoryAvpSetVal [AARequest_PROXYINFO] = 1;
					mTagsPresent[AARequest_PROXYINFO] = 1;
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
					mTagsPresent[AARequest_ROUTERECORD] = 1;
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


DiameterBaseInterface* AARequest::Find(byteArray *array, UINT32 avpCode)
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
			case 537:
			{
				if(mIPDomainId != NULL)
					return mIPDomainId->Find(array, avpCode);
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
			case 504:
			{
				if(mAFApplicationIdentifier != NULL)
					return mAFApplicationIdentifier->Find(array, avpCode);
				else
					return NULL;
			}
			case 527:
			{
				if(mServiceInfoStatus != NULL)
					return mServiceInfoStatus->Find(array, avpCode);
				else
					return NULL;
			}
			case 505:
			{
				if(mAFChargingIdentifier != NULL)
					return mAFChargingIdentifier->Find(array, avpCode);
				else
					return NULL;
			}
			case 523:
			{
				if(mSIPForkingIndication != NULL)
					return mSIPForkingIndication->Find(array, avpCode);
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
			case 458:
			{
				if(mReservationPriority != NULL)
					return mReservationPriority->Find(array, avpCode);
				else
					return NULL;
			}
			case 8:
			{
				if(mFramedIPAddress != NULL)
					return mFramedIPAddress->Find(array, avpCode);
				else
					return NULL;
			}
			case 97:
			{
				if(mFramedIPv6Prefix != NULL)
					return mFramedIPv6Prefix->Find(array, avpCode);
				else
					return NULL;
			}
			case 30:
			{
				if(mCalledStationId != NULL)
					return mCalledStationId->Find(array, avpCode);
				else
					return NULL;
			}
			case 525:
			{
				if(mServiceURN != NULL)
					return mServiceURN->Find(array, avpCode);
				else
					return NULL;
			}
			case 528:
			{
				if(mMPSIdentifier != NULL)
					return mMPSIdentifier->Find(array, avpCode);
				else
					return NULL;
			}
			case 538:
			{
				if(mGCSIdentifier != NULL)
					return mGCSIdentifier->Find(array, avpCode);
				else
					return NULL;
			}
			case 547:
			{
				if(mMCPTTIdentifier != NULL)
					return mMCPTTIdentifier->Find(array, avpCode);
				else
					return NULL;
			}
			case 562:
			{
				if(mMCVideoIdentifier != NULL)
					return mMCVideoIdentifier->Find(array, avpCode);
				else
					return NULL;
			}
			case 563:
			{
				if(mIMSContentIdentifier != NULL)
					return mIMSContentIdentifier->Find(array, avpCode);
				else
					return NULL;
			}
			case 564:
			{
				if(mIMSContentType != NULL)
					return mIMSContentType->Find(array, avpCode);
				else
					return NULL;
			}
			case 831:
			{
				if(mCallingPartyAddress != NULL)
					return mCallingPartyAddress->Find(array, avpCode);
				else
					return NULL;
			}
			case 533:
			{
				if(mRxRequestType != NULL)
					return mRxRequestType->Find(array, avpCode);
				else
					return NULL;
			}
			case 536:
			{
				if(mRequiredAccessInfoList != NULL && mRequiredAccessInfoList->size() > 0)
					return (mRequiredAccessInfoList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 551:
			{
				if(mAFRequestedData != NULL)
					return mAFRequestedData->Find(array, avpCode);
				else
					return NULL;
			}
			case 552:
			{
				if(mReferenceID != NULL)
					return mReferenceID->Find(array, avpCode);
				else
					return NULL;
			}
			case 553:
			{
				if(mPreEmptionControlInfo != NULL)
					return mPreEmptionControlInfo->Find(array, avpCode);
				else
					return NULL;
			}
			case 582:
			{
				if(mMPSAction != NULL)
					return mMPSAction->Find(array, avpCode);
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


BOOLEAN AARequest::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
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
			case 537:
			{
				if(mIPDomainId != NULL)
				{
					DiameterBaseInterface* inf =  mIPDomainId->Find(this->mspByteArray.get(), avpCode);
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
			case 504:
			{
				if(mAFApplicationIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mAFApplicationIdentifier->Find(this->mspByteArray.get(), avpCode);
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
			case 517:
			{
				if(mMediaComponentDescriptionGrpList != NULL)
				{
					for(auto itr = mMediaComponentDescriptionGrpList->begin(); itr != mMediaComponentDescriptionGrpList->end(); ++itr)
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
			case 527:
			{
				if(mServiceInfoStatus != NULL)
				{
					DiameterBaseInterface* inf =  mServiceInfoStatus->Find(this->mspByteArray.get(), avpCode);
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
			case 505:
			{
				if(mAFChargingIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mAFChargingIdentifier->Find(this->mspByteArray.get(), avpCode);
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
			case 523:
			{
				if(mSIPForkingIndication != NULL)
				{
					DiameterBaseInterface* inf =  mSIPForkingIndication->Find(this->mspByteArray.get(), avpCode);
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
			case 458:
			{
				if(mReservationPriority != NULL)
				{
					DiameterBaseInterface* inf =  mReservationPriority->Find(this->mspByteArray.get(), avpCode);
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
			case 8:
			{
				if(mFramedIPAddress != NULL)
				{
					DiameterBaseInterface* inf =  mFramedIPAddress->Find(this->mspByteArray.get(), avpCode);
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
			case 97:
			{
				if(mFramedIPv6Prefix != NULL)
				{
					DiameterBaseInterface* inf =  mFramedIPv6Prefix->Find(this->mspByteArray.get(), avpCode);
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
			case 30:
			{
				if(mCalledStationId != NULL)
				{
					DiameterBaseInterface* inf =  mCalledStationId->Find(this->mspByteArray.get(), avpCode);
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
			case 525:
			{
				if(mServiceURN != NULL)
				{
					DiameterBaseInterface* inf =  mServiceURN->Find(this->mspByteArray.get(), avpCode);
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
			case 528:
			{
				if(mMPSIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mMPSIdentifier->Find(this->mspByteArray.get(), avpCode);
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
			case 538:
			{
				if(mGCSIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mGCSIdentifier->Find(this->mspByteArray.get(), avpCode);
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
			case 547:
			{
				if(mMCPTTIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mMCPTTIdentifier->Find(this->mspByteArray.get(), avpCode);
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
			case 562:
			{
				if(mMCVideoIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mMCVideoIdentifier->Find(this->mspByteArray.get(), avpCode);
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
			case 563:
			{
				if(mIMSContentIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mIMSContentIdentifier->Find(this->mspByteArray.get(), avpCode);
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
			case 564:
			{
				if(mIMSContentType != NULL)
				{
					DiameterBaseInterface* inf =  mIMSContentType->Find(this->mspByteArray.get(), avpCode);
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
			case 831:
			{
				if(mCallingPartyAddress != NULL)
				{
					DiameterBaseInterface* inf =  mCallingPartyAddress->Find(this->mspByteArray.get(), avpCode);
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
			case 565:
			{
				if(mCalleeInformationGrpList != NULL)
				{
					for(auto itr = mCalleeInformationGrpList->begin(); itr != mCalleeInformationGrpList->end(); ++itr)
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
			case 533:
			{
				if(mRxRequestType != NULL)
				{
					DiameterBaseInterface* inf =  mRxRequestType->Find(this->mspByteArray.get(), avpCode);
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
			case 536:
			{
				if(mRequiredAccessInfoList != NULL)
				{
					for(auto itr = mRequiredAccessInfoList->begin(); itr != mRequiredAccessInfoList->end(); ++itr)
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
			case 551:
			{
				if(mAFRequestedData != NULL)
				{
					DiameterBaseInterface* inf =  mAFRequestedData->Find(this->mspByteArray.get(), avpCode);
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
			case 552:
			{
				if(mReferenceID != NULL)
				{
					DiameterBaseInterface* inf =  mReferenceID->Find(this->mspByteArray.get(), avpCode);
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
			case 553:
			{
				if(mPreEmptionControlInfo != NULL)
				{
					DiameterBaseInterface* inf =  mPreEmptionControlInfo->Find(this->mspByteArray.get(), avpCode);
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
			case 582:
			{
				if(mMPSAction != NULL)
				{
					DiameterBaseInterface* inf =  mMPSAction->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> AARequest::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN AARequest::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
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
			case 537:
			{
				if(mIPDomainId != NULL)
				{
					DiameterBaseInterface* inf =  mIPDomainId->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
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
			case 504:
			{
				if(mAFApplicationIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mAFApplicationIdentifier->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 517:
			{
				if(mMediaComponentDescriptionGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mMediaComponentDescriptionGrpList->begin(); itr != mMediaComponentDescriptionGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mMediaComponentDescriptionGrpList->begin(); itr != mMediaComponentDescriptionGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 527:
			{
				if(mServiceInfoStatus != NULL)
				{
					DiameterBaseInterface* inf =  mServiceInfoStatus->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 505:
			{
				if(mAFChargingIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mAFChargingIdentifier->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 523:
			{
				if(mSIPForkingIndication != NULL)
				{
					DiameterBaseInterface* inf =  mSIPForkingIndication->Find(this->mspByteArray.get(), avpCode);
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
			case 458:
			{
				if(mReservationPriority != NULL)
				{
					DiameterBaseInterface* inf =  mReservationPriority->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 8:
			{
				if(mFramedIPAddress != NULL)
				{
					DiameterBaseInterface* inf =  mFramedIPAddress->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 97:
			{
				if(mFramedIPv6Prefix != NULL)
				{
					DiameterBaseInterface* inf =  mFramedIPv6Prefix->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 30:
			{
				if(mCalledStationId != NULL)
				{
					DiameterBaseInterface* inf =  mCalledStationId->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 525:
			{
				if(mServiceURN != NULL)
				{
					DiameterBaseInterface* inf =  mServiceURN->Find(this->mspByteArray.get(), avpCode);
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
			case 528:
			{
				if(mMPSIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mMPSIdentifier->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 538:
			{
				if(mGCSIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mGCSIdentifier->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 547:
			{
				if(mMCPTTIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mMCPTTIdentifier->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 562:
			{
				if(mMCVideoIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mMCVideoIdentifier->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 563:
			{
				if(mIMSContentIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mIMSContentIdentifier->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 564:
			{
				if(mIMSContentType != NULL)
				{
					DiameterBaseInterface* inf =  mIMSContentType->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 831:
			{
				if(mCallingPartyAddress != NULL)
				{
					DiameterBaseInterface* inf =  mCallingPartyAddress->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 565:
			{
				if(mCalleeInformationGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mCalleeInformationGrpList->begin(); itr != mCalleeInformationGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mCalleeInformationGrpList->begin(); itr != mCalleeInformationGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 533:
			{
				if(mRxRequestType != NULL)
				{
					DiameterBaseInterface* inf =  mRxRequestType->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 536:
			{
				if(mRequiredAccessInfoList != NULL)
				{
					for(auto itr = mRequiredAccessInfoList->begin(); itr != mRequiredAccessInfoList->end(); ++itr)
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
			case 551:
			{
				if(mAFRequestedData != NULL)
				{
					DiameterBaseInterface* inf =  mAFRequestedData->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 552:
			{
				if(mReferenceID != NULL)
				{
					DiameterBaseInterface* inf =  mReferenceID->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 553:
			{
				if(mPreEmptionControlInfo != NULL)
				{
					DiameterBaseInterface* inf =  mPreEmptionControlInfo->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 582:
			{
				if(mMPSAction != NULL)
				{
					DiameterBaseInterface* inf =  mMPSAction->Find(this->mspByteArray.get(), avpCode);
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




void AARequest::Display(UINT32 tab)
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
			case AARequest_SESSIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "263" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SessionId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getSessionId()->Display(tab+1);
			}
				break;
			case AARequest_DRMP:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "301" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DRMP" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getDRMP()->Display(tab+1);
			}
				break;
			case AARequest_AUTHAPPLICATIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "258" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AuthApplicationId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getAuthApplicationId()->Display(tab+1);
			}
				break;
			case AARequest_ORIGINHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "264" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginHost()->Display(tab+1);
			}
				break;
			case AARequest_ORIGINREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "296" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginRealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginRealm()->Display(tab+1);
			}
				break;
			case AARequest_DESTINATIONREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "283" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DestinationRealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getDestinationRealm()->Display(tab+1);
			}
				break;
			case AARequest_DESTINATIONHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "293" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DestinationHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getDestinationHost()->Display(tab+1);
			}
				break;
			case AARequest_IPDOMAINID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "537" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "IPDomainId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getIPDomainId()->Display(tab+1);
			}
				break;
			case AARequest_AUTHSESSIONSTATE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "277" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AuthSessionState" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getAuthSessionState()->Display(tab+1);
			}
				break;
			case AARequest_AFAPPLICATIONIDENTIFIER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "504" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AFApplicationIdentifier" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getAFApplicationIdentifier()->Display(tab+1);
			}
				break;
			case AARequest_MEDIACOMPONENTDESCRIPTION:
			{
				if( mMediaComponentDescriptionGrpList->size() <= 0) {
					break;
				}

				mMediaComponentDescriptionGrpIterator = this->getMediaComponentDescriptionGrpList()->begin();
				while(mMediaComponentDescriptionGrpIterator != this->getMediaComponentDescriptionGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "517" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MediaComponentDescription" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mMediaComponentDescriptionGrpIterator)->Display(tab+1);
					mMediaComponentDescriptionGrpIterator++;

				};

			}
				break;
			case AARequest_SERVICEINFOSTATUS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "527" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ServiceInfoStatus" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getServiceInfoStatus()->Display(tab+1);
			}
				break;
			case AARequest_AFCHARGINGIDENTIFIER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "505" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AFChargingIdentifier" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getAFChargingIdentifier()->Display(tab+1);
			}
				break;
			case AARequest_SIPFORKINGINDICATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "523" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SIPForkingIndication" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getSIPForkingIndication()->Display(tab+1);
			}
				break;
			case AARequest_SPECIFICACTION:
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
			case AARequest_SUBSCRIPTIONID:
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
			case AARequest_OCSUPPORTEDFEATURES:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "621" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OCSupportedFeatures" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getOCSupportedFeatures()->Display(tab+1);
			}
				break;
			case AARequest_SUPPORTEDFEATURES:
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
			case AARequest_RESERVATIONPRIORITY:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "458" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ReservationPriority" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getReservationPriority()->Display(tab+1);
			}
				break;
			case AARequest_FRAMEDIPADDRESS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "8" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FramedIPAddress" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getFramedIPAddress()->Display(tab+1);
			}
				break;
			case AARequest_FRAMEDIPV6PREFIX:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "97" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FramedIPv6Prefix" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getFramedIPv6Prefix()->Display(tab+1);
			}
				break;
			case AARequest_CALLEDSTATIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "30" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CalledStationId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getCalledStationId()->Display(tab+1);
			}
				break;
			case AARequest_SERVICEURN:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "525" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ServiceURN" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getServiceURN()->Display(tab+1);
			}
				break;
			case AARequest_SPONSOREDCONNECTIVITYDATA:
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
			case AARequest_MPSIDENTIFIER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "528" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MPSIdentifier" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getMPSIdentifier()->Display(tab+1);
			}
				break;
			case AARequest_GCSIDENTIFIER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "538" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "GCSIdentifier" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getGCSIdentifier()->Display(tab+1);
			}
				break;
			case AARequest_MCPTTIDENTIFIER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "547" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MCPTTIdentifier" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getMCPTTIdentifier()->Display(tab+1);
			}
				break;
			case AARequest_MCVIDEOIDENTIFIER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "562" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MCVideoIdentifier" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getMCVideoIdentifier()->Display(tab+1);
			}
				break;
			case AARequest_IMSCONTENTIDENTIFIER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "563" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "IMSContentIdentifier" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getIMSContentIdentifier()->Display(tab+1);
			}
				break;
			case AARequest_IMSCONTENTTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "564" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "IMSContentType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getIMSContentType()->Display(tab+1);
			}
				break;
			case AARequest_CALLINGPARTYADDRESS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "831" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CallingPartyAddress" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getCallingPartyAddress()->Display(tab+1);
			}
				break;
			case AARequest_CALLEEINFORMATION:
			{
				if( mCalleeInformationGrpList->size() <= 0) {
					break;
				}

				mCalleeInformationGrpIterator = this->getCalleeInformationGrpList()->begin();
				while(mCalleeInformationGrpIterator != this->getCalleeInformationGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "565" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CalleeInformation" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
					(*mCalleeInformationGrpIterator)->Display(tab+1);
					mCalleeInformationGrpIterator++;

				};

			}
				break;
			case AARequest_RXREQUESTTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "533" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RxRequestType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getRxRequestType()->Display(tab+1);
			}
				break;
			case AARequest_REQUIREDACCESSINFO:
			{
				if( mRequiredAccessInfoList->size() <= 0) {
					break;
				}

				mRequiredAccessInfoIterator = this->getRequiredAccessInfoList()->begin();
				while(mRequiredAccessInfoIterator != this->getRequiredAccessInfoList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "536" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RequiredAccessInfo" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mRequiredAccessInfoIterator)->Display(tab+1);
					mRequiredAccessInfoIterator++;

				};

			}
				break;
			case AARequest_AFREQUESTEDDATA:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "551" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AFRequestedData" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getAFRequestedData()->Display(tab+1);
			}
				break;
			case AARequest_REFERENCEID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "552" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ReferenceID" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getReferenceID()->Display(tab+1);
			}
				break;
			case AARequest_PREEMPTIONCONTROLINFO:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "553" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PreEmptionControlInfo" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getPreEmptionControlInfo()->Display(tab+1);
			}
				break;
			case AARequest_MPSACTION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "582" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MPSAction" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getMPSAction()->Display(tab+1);
			}
				break;
			case AARequest_ORIGINSTATEID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "278" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginStateId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginStateId()->Display(tab+1);
			}
				break;
			case AARequest_PROXYINFO:
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
			case AARequest_ROUTERECORD:
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
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
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


BOOLEAN AARequest::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<41> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case AARequest_SESSIONID:
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
			case AARequest_DRMP:
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
			case AARequest_AUTHAPPLICATIONID:
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
			case AARequest_ORIGINHOST:
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
			case AARequest_ORIGINREALM:
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
			case AARequest_DESTINATIONREALM:
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
			case AARequest_DESTINATIONHOST:
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
			case AARequest_IPDOMAINID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 537");
				}
				else
					sprintf(lMissingAvpInfo, "%s,537", lMissingAvpInfo);
			}
				break;
			case AARequest_AUTHSESSIONSTATE:
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
			case AARequest_AFAPPLICATIONIDENTIFIER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 504");
				}
				else
					sprintf(lMissingAvpInfo, "%s,504", lMissingAvpInfo);
			}
				break;
			case AARequest_MEDIACOMPONENTDESCRIPTION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 517");
				}
				else
					sprintf(lMissingAvpInfo, "%s,517", lMissingAvpInfo);
			}
				break;
			case AARequest_SERVICEINFOSTATUS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 527");
				}
				else
					sprintf(lMissingAvpInfo, "%s,527", lMissingAvpInfo);
			}
				break;
			case AARequest_AFCHARGINGIDENTIFIER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 505");
				}
				else
					sprintf(lMissingAvpInfo, "%s,505", lMissingAvpInfo);
			}
				break;
			case AARequest_SIPFORKINGINDICATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 523");
				}
				else
					sprintf(lMissingAvpInfo, "%s,523", lMissingAvpInfo);
			}
				break;
			case AARequest_SPECIFICACTION:
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
			case AARequest_SUBSCRIPTIONID:
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
			case AARequest_OCSUPPORTEDFEATURES:
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
			case AARequest_SUPPORTEDFEATURES:
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
			case AARequest_RESERVATIONPRIORITY:
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
			case AARequest_FRAMEDIPADDRESS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 8");
				}
				else
					sprintf(lMissingAvpInfo, "%s,8", lMissingAvpInfo);
			}
				break;
			case AARequest_FRAMEDIPV6PREFIX:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 97");
				}
				else
					sprintf(lMissingAvpInfo, "%s,97", lMissingAvpInfo);
			}
				break;
			case AARequest_CALLEDSTATIONID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 30");
				}
				else
					sprintf(lMissingAvpInfo, "%s,30", lMissingAvpInfo);
			}
				break;
			case AARequest_SERVICEURN:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 525");
				}
				else
					sprintf(lMissingAvpInfo, "%s,525", lMissingAvpInfo);
			}
				break;
			case AARequest_SPONSOREDCONNECTIVITYDATA:
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
			case AARequest_MPSIDENTIFIER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 528");
				}
				else
					sprintf(lMissingAvpInfo, "%s,528", lMissingAvpInfo);
			}
				break;
			case AARequest_GCSIDENTIFIER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 538");
				}
				else
					sprintf(lMissingAvpInfo, "%s,538", lMissingAvpInfo);
			}
				break;
			case AARequest_MCPTTIDENTIFIER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 547");
				}
				else
					sprintf(lMissingAvpInfo, "%s,547", lMissingAvpInfo);
			}
				break;
			case AARequest_MCVIDEOIDENTIFIER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 562");
				}
				else
					sprintf(lMissingAvpInfo, "%s,562", lMissingAvpInfo);
			}
				break;
			case AARequest_IMSCONTENTIDENTIFIER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 563");
				}
				else
					sprintf(lMissingAvpInfo, "%s,563", lMissingAvpInfo);
			}
				break;
			case AARequest_IMSCONTENTTYPE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 564");
				}
				else
					sprintf(lMissingAvpInfo, "%s,564", lMissingAvpInfo);
			}
				break;
			case AARequest_CALLINGPARTYADDRESS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 831");
				}
				else
					sprintf(lMissingAvpInfo, "%s,831", lMissingAvpInfo);
			}
				break;
			case AARequest_CALLEEINFORMATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 565");
				}
				else
					sprintf(lMissingAvpInfo, "%s,565", lMissingAvpInfo);
			}
				break;
			case AARequest_RXREQUESTTYPE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 533");
				}
				else
					sprintf(lMissingAvpInfo, "%s,533", lMissingAvpInfo);
			}
				break;
			case AARequest_REQUIREDACCESSINFO:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 536");
				}
				else
					sprintf(lMissingAvpInfo, "%s,536", lMissingAvpInfo);
			}
				break;
			case AARequest_AFREQUESTEDDATA:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 551");
				}
				else
					sprintf(lMissingAvpInfo, "%s,551", lMissingAvpInfo);
			}
				break;
			case AARequest_REFERENCEID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 552");
				}
				else
					sprintf(lMissingAvpInfo, "%s,552", lMissingAvpInfo);
			}
				break;
			case AARequest_PREEMPTIONCONTROLINFO:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 553");
				}
				else
					sprintf(lMissingAvpInfo, "%s,553", lMissingAvpInfo);
			}
				break;
			case AARequest_MPSACTION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 582");
				}
				else
					sprintf(lMissingAvpInfo, "%s,582", lMissingAvpInfo);
			}
				break;
			case AARequest_ORIGINSTATEID:
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
			case AARequest_PROXYINFO:
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
			case AARequest_ROUTERECORD:
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
