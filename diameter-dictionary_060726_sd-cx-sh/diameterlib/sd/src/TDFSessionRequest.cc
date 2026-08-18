#include "sd/include/TDFSessionRequest.h"

using namespace SD;
BOOLEAN TDFSessionRequest::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

TDFSessionRequest::TDFSessionRequest()
{
	mSessionId = NULL;
	mDRMP = NULL;
	mVendorSpecificApplicationIdGrp = NULL;
	mOriginHost = NULL;
	mOriginRealm = NULL;
	mDestinationRealm = NULL;
	mDestinationHost = NULL;
	mOriginStateId = NULL;
	mOCSupportedFeaturesGrp = NULL;
	mSubscriptionIdGrpList = NULL;
	mSupportedFeaturesGrpList = NULL;
	mFramedIPAddress = NULL;
	mFramedIPv6Prefix = NULL;
	mIPCANType = NULL;
	mRATType = NULL;
	mANTrusted = NULL;
	mUserEquipmentInfoGrp = NULL;
	mUserEquipmentInfoExtensionGrp = NULL;
	mQoSInformationGrp = NULL;
	mANGWAddressList = NULL;
	m3GPPSGSNAddress = NULL;
	m3GPPSGSNIPv6Address = NULL;
	m3GPPGGSNAddress = NULL;
	m3GPPGGSNIPv6Address = NULL;
	m3GPPSelectionMode = NULL;
	mDynamicAddressFlag = NULL;
	mDynamicAddressFlagExtension = NULL;
	mPDNConnectionChargingID = NULL;
	m3GPPSGSNMCCMNC = NULL;
	mRAI = NULL;
	m3GPPUserLocationInfo = NULL;
	mFixedUserLocationInfoGrp = NULL;
	mUserCSGInformationGrp = NULL;
	mTWANIdentifier = NULL;
	m3GPPMSTimeZone = NULL;
	m3GPPChargingCharacteristics = NULL;
	mCalledStationId = NULL;
	mChargingInformationGrp = NULL;
	mOnline = NULL;
	mOffline = NULL;
	mADCRuleInstallGrpList = NULL;
	mRevalidationTime = NULL;
	mUsageMonitoringInformationGrpList = NULL;
	mCSGInformationReportingList = NULL;
	mEventTriggerList = NULL;
	mPresenceReportingAreaInformationGrp = NULL;
	mLogicalAccessID = NULL;
	mPhysicalAccessID = NULL;
	m3GPP2BSID = NULL;
	mProxyInfoGrpList = NULL;
	mRouteRecordList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<51>(string("111000100111111000100000000000001001011101011111101"));
	mMandatoryAvpSetVal.reset();
}

TDFSessionRequest::~TDFSessionRequest()
{
	if(mSessionId != NULL)
		delete mSessionId;
	if(mDRMP != NULL)
		delete mDRMP;
	if(mVendorSpecificApplicationIdGrp != NULL)
		delete mVendorSpecificApplicationIdGrp;
	if(mOriginHost != NULL)
		delete mOriginHost;
	if(mOriginRealm != NULL)
		delete mOriginRealm;
	if(mDestinationRealm != NULL)
		delete mDestinationRealm;
	if(mDestinationHost != NULL)
		delete mDestinationHost;
	if(mOriginStateId != NULL)
		delete mOriginStateId;
	if(mOCSupportedFeaturesGrp != NULL)
		delete mOCSupportedFeaturesGrp;
	if(mSubscriptionIdGrpList != NULL){
		mSubscriptionIdGrpIterator = mSubscriptionIdGrpList->begin();
		while(mSubscriptionIdGrpIterator != mSubscriptionIdGrpList->end()){
	if(*mSubscriptionIdGrpIterator != NULL)
			delete (*mSubscriptionIdGrpIterator);
			mSubscriptionIdGrpIterator++;
		}
		delete mSubscriptionIdGrpList;
	}
	if(mSupportedFeaturesGrpList != NULL){
		mSupportedFeaturesGrpIterator = mSupportedFeaturesGrpList->begin();
		while(mSupportedFeaturesGrpIterator != mSupportedFeaturesGrpList->end()){
	if(*mSupportedFeaturesGrpIterator != NULL)
			delete (*mSupportedFeaturesGrpIterator);
			mSupportedFeaturesGrpIterator++;
		}
		delete mSupportedFeaturesGrpList;
	}
	if(mFramedIPAddress != NULL)
		delete mFramedIPAddress;
	if(mFramedIPv6Prefix != NULL)
		delete mFramedIPv6Prefix;
	if(mIPCANType != NULL)
		delete mIPCANType;
	if(mRATType != NULL)
		delete mRATType;
	if(mANTrusted != NULL)
		delete mANTrusted;
	if(mUserEquipmentInfoGrp != NULL)
		delete mUserEquipmentInfoGrp;
	if(mUserEquipmentInfoExtensionGrp != NULL)
		delete mUserEquipmentInfoExtensionGrp;
	if(mQoSInformationGrp != NULL)
		delete mQoSInformationGrp;
	if(mANGWAddressList != NULL){
		mANGWAddressIterator = mANGWAddressList->begin();
		while(mANGWAddressIterator != mANGWAddressList->end()){
			delete (*mANGWAddressIterator);
			mANGWAddressIterator++;
		}
		delete mANGWAddressList;
	}
	if(m3GPPSGSNAddress != NULL)
		delete m3GPPSGSNAddress;
	if(m3GPPSGSNIPv6Address != NULL)
		delete m3GPPSGSNIPv6Address;
	if(m3GPPGGSNAddress != NULL)
		delete m3GPPGGSNAddress;
	if(m3GPPGGSNIPv6Address != NULL)
		delete m3GPPGGSNIPv6Address;
	if(m3GPPSelectionMode != NULL)
		delete m3GPPSelectionMode;
	if(mDynamicAddressFlag != NULL)
		delete mDynamicAddressFlag;
	if(mDynamicAddressFlagExtension != NULL)
		delete mDynamicAddressFlagExtension;
	if(mPDNConnectionChargingID != NULL)
		delete mPDNConnectionChargingID;
	if(m3GPPSGSNMCCMNC != NULL)
		delete m3GPPSGSNMCCMNC;
	if(mRAI != NULL)
		delete mRAI;
	if(m3GPPUserLocationInfo != NULL)
		delete m3GPPUserLocationInfo;
	if(mFixedUserLocationInfoGrp != NULL)
		delete mFixedUserLocationInfoGrp;
	if(mUserCSGInformationGrp != NULL)
		delete mUserCSGInformationGrp;
	if(mTWANIdentifier != NULL)
		delete mTWANIdentifier;
	if(m3GPPMSTimeZone != NULL)
		delete m3GPPMSTimeZone;
	if(m3GPPChargingCharacteristics != NULL)
		delete m3GPPChargingCharacteristics;
	if(mCalledStationId != NULL)
		delete mCalledStationId;
	if(mChargingInformationGrp != NULL)
		delete mChargingInformationGrp;
	if(mOnline != NULL)
		delete mOnline;
	if(mOffline != NULL)
		delete mOffline;
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
	if(mCSGInformationReportingList != NULL){
		mCSGInformationReportingIterator = mCSGInformationReportingList->begin();
		while(mCSGInformationReportingIterator != mCSGInformationReportingList->end()){
			delete (*mCSGInformationReportingIterator);
			mCSGInformationReportingIterator++;
		}
		delete mCSGInformationReportingList;
	}
	if(mEventTriggerList != NULL){
		mEventTriggerIterator = mEventTriggerList->begin();
		while(mEventTriggerIterator != mEventTriggerList->end()){
			delete (*mEventTriggerIterator);
			mEventTriggerIterator++;
		}
		delete mEventTriggerList;
	}
	if(mPresenceReportingAreaInformationGrp != NULL)
		delete mPresenceReportingAreaInformationGrp;
	if(mLogicalAccessID != NULL)
		delete mLogicalAccessID;
	if(mPhysicalAccessID != NULL)
		delete mPhysicalAccessID;
	if(m3GPP2BSID != NULL)
		delete m3GPP2BSID;
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

OctetString* TDFSessionRequest::setSessionId(){
	mMandatoryAvpSetVal [TDFSessionRequest_SESSIONID] = 1;
	if(mSessionId == NULL)
	{
		mSessionId = new OctetString();
		mTagsPresent[TDFSessionRequest_SESSIONID] = 1;
		return mSessionId;
	}
	return mSessionId;
}

void TDFSessionRequest::resetSessionId(){
	mTagsPresent[TDFSessionRequest_SESSIONID] = 0;
	if(mSessionId != NULL)
	{
		delete mSessionId; 
		mSessionId = NULL;
	}
}

DRMP* TDFSessionRequest::setDRMP(){
	if(mDRMP == NULL)
	{
		mDRMP = new DRMP();
		mTagsPresent[TDFSessionRequest_DRMP] = 1;
		return mDRMP;
	}
	return mDRMP;
}

void TDFSessionRequest::resetDRMP(){
	mTagsPresent[TDFSessionRequest_DRMP] = 0;
	if(mDRMP != NULL)
	{
		delete mDRMP; 
		mDRMP = NULL;
	}
}

OctetString* TDFSessionRequest::setOriginHost(){
	mMandatoryAvpSetVal [TDFSessionRequest_ORIGINHOST] = 1;
	if(mOriginHost == NULL)
	{
		mOriginHost = new OctetString();
		mTagsPresent[TDFSessionRequest_ORIGINHOST] = 1;
		return mOriginHost;
	}
	return mOriginHost;
}

void TDFSessionRequest::resetOriginHost(){
	mTagsPresent[TDFSessionRequest_ORIGINHOST] = 0;
	if(mOriginHost != NULL)
	{
		delete mOriginHost; 
		mOriginHost = NULL;
	}
}

OctetString* TDFSessionRequest::setOriginRealm(){
	mMandatoryAvpSetVal [TDFSessionRequest_ORIGINREALM] = 1;
	if(mOriginRealm == NULL)
	{
		mOriginRealm = new OctetString();
		mTagsPresent[TDFSessionRequest_ORIGINREALM] = 1;
		return mOriginRealm;
	}
	return mOriginRealm;
}

void TDFSessionRequest::resetOriginRealm(){
	mTagsPresent[TDFSessionRequest_ORIGINREALM] = 0;
	if(mOriginRealm != NULL)
	{
		delete mOriginRealm; 
		mOriginRealm = NULL;
	}
}

OctetString* TDFSessionRequest::setDestinationRealm(){
	mMandatoryAvpSetVal [TDFSessionRequest_DESTINATIONREALM] = 1;
	if(mDestinationRealm == NULL)
	{
		mDestinationRealm = new OctetString();
		mTagsPresent[TDFSessionRequest_DESTINATIONREALM] = 1;
		return mDestinationRealm;
	}
	return mDestinationRealm;
}

void TDFSessionRequest::resetDestinationRealm(){
	mTagsPresent[TDFSessionRequest_DESTINATIONREALM] = 0;
	if(mDestinationRealm != NULL)
	{
		delete mDestinationRealm; 
		mDestinationRealm = NULL;
	}
}

OctetString* TDFSessionRequest::setDestinationHost(){
	mMandatoryAvpSetVal [TDFSessionRequest_DESTINATIONHOST] = 1;
	if(mDestinationHost == NULL)
	{
		mDestinationHost = new OctetString();
		mTagsPresent[TDFSessionRequest_DESTINATIONHOST] = 1;
		return mDestinationHost;
	}
	return mDestinationHost;
}

void TDFSessionRequest::resetDestinationHost(){
	mTagsPresent[TDFSessionRequest_DESTINATIONHOST] = 0;
	if(mDestinationHost != NULL)
	{
		delete mDestinationHost; 
		mDestinationHost = NULL;
	}
}

Unsigned32* TDFSessionRequest::setOriginStateId(){
	mMandatoryAvpSetVal [TDFSessionRequest_ORIGINSTATEID] = 1;
	if(mOriginStateId == NULL)
	{
		mOriginStateId = new Unsigned32();
		mTagsPresent[TDFSessionRequest_ORIGINSTATEID] = 1;
		return mOriginStateId;
	}
	return mOriginStateId;
}

void TDFSessionRequest::resetOriginStateId(){
	mTagsPresent[TDFSessionRequest_ORIGINSTATEID] = 0;
	if(mOriginStateId != NULL)
	{
		delete mOriginStateId; 
		mOriginStateId = NULL;
	}
}

OctetString* TDFSessionRequest::setFramedIPAddress(){
	mMandatoryAvpSetVal [TDFSessionRequest_FRAMEDIPADDRESS] = 1;
	if(mFramedIPAddress == NULL)
	{
		mFramedIPAddress = new OctetString();
		mTagsPresent[TDFSessionRequest_FRAMEDIPADDRESS] = 1;
		return mFramedIPAddress;
	}
	return mFramedIPAddress;
}

void TDFSessionRequest::resetFramedIPAddress(){
	mTagsPresent[TDFSessionRequest_FRAMEDIPADDRESS] = 0;
	if(mFramedIPAddress != NULL)
	{
		delete mFramedIPAddress; 
		mFramedIPAddress = NULL;
	}
}

OctetString* TDFSessionRequest::setFramedIPv6Prefix(){
	mMandatoryAvpSetVal [TDFSessionRequest_FRAMEDIPV6PREFIX] = 1;
	if(mFramedIPv6Prefix == NULL)
	{
		mFramedIPv6Prefix = new OctetString();
		mTagsPresent[TDFSessionRequest_FRAMEDIPV6PREFIX] = 1;
		return mFramedIPv6Prefix;
	}
	return mFramedIPv6Prefix;
}

void TDFSessionRequest::resetFramedIPv6Prefix(){
	mTagsPresent[TDFSessionRequest_FRAMEDIPV6PREFIX] = 0;
	if(mFramedIPv6Prefix != NULL)
	{
		delete mFramedIPv6Prefix; 
		mFramedIPv6Prefix = NULL;
	}
}

IPCANType* TDFSessionRequest::setIPCANType(){
	mMandatoryAvpSetVal [TDFSessionRequest_IPCANTYPE] = 1;
	if(mIPCANType == NULL)
	{
		mIPCANType = new IPCANType();
		mTagsPresent[TDFSessionRequest_IPCANTYPE] = 1;
		return mIPCANType;
	}
	return mIPCANType;
}

void TDFSessionRequest::resetIPCANType(){
	mTagsPresent[TDFSessionRequest_IPCANTYPE] = 0;
	if(mIPCANType != NULL)
	{
		delete mIPCANType; 
		mIPCANType = NULL;
	}
}

RATType* TDFSessionRequest::setRATType(){
	if(mRATType == NULL)
	{
		mRATType = new RATType();
		mTagsPresent[TDFSessionRequest_RATTYPE] = 1;
		return mRATType;
	}
	return mRATType;
}

void TDFSessionRequest::resetRATType(){
	mTagsPresent[TDFSessionRequest_RATTYPE] = 0;
	if(mRATType != NULL)
	{
		delete mRATType; 
		mRATType = NULL;
	}
}

ANTrusted* TDFSessionRequest::setANTrusted(){
	mMandatoryAvpSetVal [TDFSessionRequest_ANTRUSTED] = 1;
	if(mANTrusted == NULL)
	{
		mANTrusted = new ANTrusted();
		mTagsPresent[TDFSessionRequest_ANTRUSTED] = 1;
		return mANTrusted;
	}
	return mANTrusted;
}

void TDFSessionRequest::resetANTrusted(){
	mTagsPresent[TDFSessionRequest_ANTRUSTED] = 0;
	if(mANTrusted != NULL)
	{
		delete mANTrusted; 
		mANTrusted = NULL;
	}
}

OctetString* TDFSessionRequest::set3GPPSGSNAddress(){
	if(m3GPPSGSNAddress == NULL)
	{
		m3GPPSGSNAddress = new OctetString();
		mTagsPresent[TDFSessionRequest_3GPPSGSNADDRESS] = 1;
		return m3GPPSGSNAddress;
	}
	return m3GPPSGSNAddress;
}

void TDFSessionRequest::reset3GPPSGSNAddress(){
	mTagsPresent[TDFSessionRequest_3GPPSGSNADDRESS] = 0;
	if(m3GPPSGSNAddress != NULL)
	{
		delete m3GPPSGSNAddress; 
		m3GPPSGSNAddress = NULL;
	}
}

OctetString* TDFSessionRequest::set3GPPSGSNIPv6Address(){
	if(m3GPPSGSNIPv6Address == NULL)
	{
		m3GPPSGSNIPv6Address = new OctetString();
		mTagsPresent[TDFSessionRequest_3GPPSGSNIPV6ADDRESS] = 1;
		return m3GPPSGSNIPv6Address;
	}
	return m3GPPSGSNIPv6Address;
}

void TDFSessionRequest::reset3GPPSGSNIPv6Address(){
	mTagsPresent[TDFSessionRequest_3GPPSGSNIPV6ADDRESS] = 0;
	if(m3GPPSGSNIPv6Address != NULL)
	{
		delete m3GPPSGSNIPv6Address; 
		m3GPPSGSNIPv6Address = NULL;
	}
}

OctetString* TDFSessionRequest::set3GPPGGSNAddress(){
	if(m3GPPGGSNAddress == NULL)
	{
		m3GPPGGSNAddress = new OctetString();
		mTagsPresent[TDFSessionRequest_3GPPGGSNADDRESS] = 1;
		return m3GPPGGSNAddress;
	}
	return m3GPPGGSNAddress;
}

void TDFSessionRequest::reset3GPPGGSNAddress(){
	mTagsPresent[TDFSessionRequest_3GPPGGSNADDRESS] = 0;
	if(m3GPPGGSNAddress != NULL)
	{
		delete m3GPPGGSNAddress; 
		m3GPPGGSNAddress = NULL;
	}
}

OctetString* TDFSessionRequest::set3GPPGGSNIPv6Address(){
	if(m3GPPGGSNIPv6Address == NULL)
	{
		m3GPPGGSNIPv6Address = new OctetString();
		mTagsPresent[TDFSessionRequest_3GPPGGSNIPV6ADDRESS] = 1;
		return m3GPPGGSNIPv6Address;
	}
	return m3GPPGGSNIPv6Address;
}

void TDFSessionRequest::reset3GPPGGSNIPv6Address(){
	mTagsPresent[TDFSessionRequest_3GPPGGSNIPV6ADDRESS] = 0;
	if(m3GPPGGSNIPv6Address != NULL)
	{
		delete m3GPPGGSNIPv6Address; 
		m3GPPGGSNIPv6Address = NULL;
	}
}

OctetString* TDFSessionRequest::set3GPPSelectionMode(){
	if(m3GPPSelectionMode == NULL)
	{
		m3GPPSelectionMode = new OctetString();
		mTagsPresent[TDFSessionRequest_3GPPSELECTIONMODE] = 1;
		return m3GPPSelectionMode;
	}
	return m3GPPSelectionMode;
}

void TDFSessionRequest::reset3GPPSelectionMode(){
	mTagsPresent[TDFSessionRequest_3GPPSELECTIONMODE] = 0;
	if(m3GPPSelectionMode != NULL)
	{
		delete m3GPPSelectionMode; 
		m3GPPSelectionMode = NULL;
	}
}

DynamicAddressFlag* TDFSessionRequest::setDynamicAddressFlag(){
	if(mDynamicAddressFlag == NULL)
	{
		mDynamicAddressFlag = new DynamicAddressFlag();
		mTagsPresent[TDFSessionRequest_DYNAMICADDRESSFLAG] = 1;
		return mDynamicAddressFlag;
	}
	return mDynamicAddressFlag;
}

void TDFSessionRequest::resetDynamicAddressFlag(){
	mTagsPresent[TDFSessionRequest_DYNAMICADDRESSFLAG] = 0;
	if(mDynamicAddressFlag != NULL)
	{
		delete mDynamicAddressFlag; 
		mDynamicAddressFlag = NULL;
	}
}

DynamicAddressFlagExtension* TDFSessionRequest::setDynamicAddressFlagExtension(){
	if(mDynamicAddressFlagExtension == NULL)
	{
		mDynamicAddressFlagExtension = new DynamicAddressFlagExtension();
		mTagsPresent[TDFSessionRequest_DYNAMICADDRESSFLAGEXTENSION] = 1;
		return mDynamicAddressFlagExtension;
	}
	return mDynamicAddressFlagExtension;
}

void TDFSessionRequest::resetDynamicAddressFlagExtension(){
	mTagsPresent[TDFSessionRequest_DYNAMICADDRESSFLAGEXTENSION] = 0;
	if(mDynamicAddressFlagExtension != NULL)
	{
		delete mDynamicAddressFlagExtension; 
		mDynamicAddressFlagExtension = NULL;
	}
}

Unsigned32* TDFSessionRequest::setPDNConnectionChargingID(){
	if(mPDNConnectionChargingID == NULL)
	{
		mPDNConnectionChargingID = new Unsigned32();
		mTagsPresent[TDFSessionRequest_PDNCONNECTIONCHARGINGID] = 1;
		return mPDNConnectionChargingID;
	}
	return mPDNConnectionChargingID;
}

void TDFSessionRequest::resetPDNConnectionChargingID(){
	mTagsPresent[TDFSessionRequest_PDNCONNECTIONCHARGINGID] = 0;
	if(mPDNConnectionChargingID != NULL)
	{
		delete mPDNConnectionChargingID; 
		mPDNConnectionChargingID = NULL;
	}
}

OctetString* TDFSessionRequest::set3GPPSGSNMCCMNC(){
	if(m3GPPSGSNMCCMNC == NULL)
	{
		m3GPPSGSNMCCMNC = new OctetString();
		mTagsPresent[TDFSessionRequest_3GPPSGSNMCCMNC] = 1;
		return m3GPPSGSNMCCMNC;
	}
	return m3GPPSGSNMCCMNC;
}

void TDFSessionRequest::reset3GPPSGSNMCCMNC(){
	mTagsPresent[TDFSessionRequest_3GPPSGSNMCCMNC] = 0;
	if(m3GPPSGSNMCCMNC != NULL)
	{
		delete m3GPPSGSNMCCMNC; 
		m3GPPSGSNMCCMNC = NULL;
	}
}

OctetString* TDFSessionRequest::setRAI(){
	if(mRAI == NULL)
	{
		mRAI = new OctetString();
		mTagsPresent[TDFSessionRequest_RAI] = 1;
		return mRAI;
	}
	return mRAI;
}

void TDFSessionRequest::resetRAI(){
	mTagsPresent[TDFSessionRequest_RAI] = 0;
	if(mRAI != NULL)
	{
		delete mRAI; 
		mRAI = NULL;
	}
}

OctetString* TDFSessionRequest::set3GPPUserLocationInfo(){
	if(m3GPPUserLocationInfo == NULL)
	{
		m3GPPUserLocationInfo = new OctetString();
		mTagsPresent[TDFSessionRequest_3GPPUSERLOCATIONINFO] = 1;
		return m3GPPUserLocationInfo;
	}
	return m3GPPUserLocationInfo;
}

void TDFSessionRequest::reset3GPPUserLocationInfo(){
	mTagsPresent[TDFSessionRequest_3GPPUSERLOCATIONINFO] = 0;
	if(m3GPPUserLocationInfo != NULL)
	{
		delete m3GPPUserLocationInfo; 
		m3GPPUserLocationInfo = NULL;
	}
}

OctetString* TDFSessionRequest::setTWANIdentifier(){
	if(mTWANIdentifier == NULL)
	{
		mTWANIdentifier = new OctetString();
		mTagsPresent[TDFSessionRequest_TWANIDENTIFIER] = 1;
		return mTWANIdentifier;
	}
	return mTWANIdentifier;
}

void TDFSessionRequest::resetTWANIdentifier(){
	mTagsPresent[TDFSessionRequest_TWANIDENTIFIER] = 0;
	if(mTWANIdentifier != NULL)
	{
		delete mTWANIdentifier; 
		mTWANIdentifier = NULL;
	}
}

OctetString* TDFSessionRequest::set3GPPMSTimeZone(){
	if(m3GPPMSTimeZone == NULL)
	{
		m3GPPMSTimeZone = new OctetString();
		mTagsPresent[TDFSessionRequest_3GPPMSTIMEZONE] = 1;
		return m3GPPMSTimeZone;
	}
	return m3GPPMSTimeZone;
}

void TDFSessionRequest::reset3GPPMSTimeZone(){
	mTagsPresent[TDFSessionRequest_3GPPMSTIMEZONE] = 0;
	if(m3GPPMSTimeZone != NULL)
	{
		delete m3GPPMSTimeZone; 
		m3GPPMSTimeZone = NULL;
	}
}

OctetString* TDFSessionRequest::set3GPPChargingCharacteristics(){
	if(m3GPPChargingCharacteristics == NULL)
	{
		m3GPPChargingCharacteristics = new OctetString();
		mTagsPresent[TDFSessionRequest_3GPPCHARGINGCHARACTERISTICS] = 1;
		return m3GPPChargingCharacteristics;
	}
	return m3GPPChargingCharacteristics;
}

void TDFSessionRequest::reset3GPPChargingCharacteristics(){
	mTagsPresent[TDFSessionRequest_3GPPCHARGINGCHARACTERISTICS] = 0;
	if(m3GPPChargingCharacteristics != NULL)
	{
		delete m3GPPChargingCharacteristics; 
		m3GPPChargingCharacteristics = NULL;
	}
}

OctetString* TDFSessionRequest::setCalledStationId(){
	mMandatoryAvpSetVal [TDFSessionRequest_CALLEDSTATIONID] = 1;
	if(mCalledStationId == NULL)
	{
		mCalledStationId = new OctetString();
		mTagsPresent[TDFSessionRequest_CALLEDSTATIONID] = 1;
		return mCalledStationId;
	}
	return mCalledStationId;
}

void TDFSessionRequest::resetCalledStationId(){
	mTagsPresent[TDFSessionRequest_CALLEDSTATIONID] = 0;
	if(mCalledStationId != NULL)
	{
		delete mCalledStationId; 
		mCalledStationId = NULL;
	}
}

Online* TDFSessionRequest::setOnline(){
	mMandatoryAvpSetVal [TDFSessionRequest_ONLINE] = 1;
	if(mOnline == NULL)
	{
		mOnline = new Online();
		mTagsPresent[TDFSessionRequest_ONLINE] = 1;
		return mOnline;
	}
	return mOnline;
}

void TDFSessionRequest::resetOnline(){
	mTagsPresent[TDFSessionRequest_ONLINE] = 0;
	if(mOnline != NULL)
	{
		delete mOnline; 
		mOnline = NULL;
	}
}

Offline* TDFSessionRequest::setOffline(){
	mMandatoryAvpSetVal [TDFSessionRequest_OFFLINE] = 1;
	if(mOffline == NULL)
	{
		mOffline = new Offline();
		mTagsPresent[TDFSessionRequest_OFFLINE] = 1;
		return mOffline;
	}
	return mOffline;
}

void TDFSessionRequest::resetOffline(){
	mTagsPresent[TDFSessionRequest_OFFLINE] = 0;
	if(mOffline != NULL)
	{
		delete mOffline; 
		mOffline = NULL;
	}
}

Time* TDFSessionRequest::setRevalidationTime(){
	mMandatoryAvpSetVal [TDFSessionRequest_REVALIDATIONTIME] = 1;
	if(mRevalidationTime == NULL)
	{
		mRevalidationTime = new Time();
		mTagsPresent[TDFSessionRequest_REVALIDATIONTIME] = 1;
		return mRevalidationTime;
	}
	return mRevalidationTime;
}

void TDFSessionRequest::resetRevalidationTime(){
	mTagsPresent[TDFSessionRequest_REVALIDATIONTIME] = 0;
	if(mRevalidationTime != NULL)
	{
		delete mRevalidationTime; 
		mRevalidationTime = NULL;
	}
}

OctetString* TDFSessionRequest::setLogicalAccessID(){
	if(mLogicalAccessID == NULL)
	{
		mLogicalAccessID = new OctetString();
		mTagsPresent[TDFSessionRequest_LOGICALACCESSID] = 1;
		return mLogicalAccessID;
	}
	return mLogicalAccessID;
}

void TDFSessionRequest::resetLogicalAccessID(){
	mTagsPresent[TDFSessionRequest_LOGICALACCESSID] = 0;
	if(mLogicalAccessID != NULL)
	{
		delete mLogicalAccessID; 
		mLogicalAccessID = NULL;
	}
}

OctetString* TDFSessionRequest::setPhysicalAccessID(){
	if(mPhysicalAccessID == NULL)
	{
		mPhysicalAccessID = new OctetString();
		mTagsPresent[TDFSessionRequest_PHYSICALACCESSID] = 1;
		return mPhysicalAccessID;
	}
	return mPhysicalAccessID;
}

void TDFSessionRequest::resetPhysicalAccessID(){
	mTagsPresent[TDFSessionRequest_PHYSICALACCESSID] = 0;
	if(mPhysicalAccessID != NULL)
	{
		delete mPhysicalAccessID; 
		mPhysicalAccessID = NULL;
	}
}

OctetString* TDFSessionRequest::set3GPP2BSID(){
	mMandatoryAvpSetVal [TDFSessionRequest_3GPP2BSID] = 1;
	if(m3GPP2BSID == NULL)
	{
		m3GPP2BSID = new OctetString();
		mTagsPresent[TDFSessionRequest_3GPP2BSID] = 1;
		return m3GPP2BSID;
	}
	return m3GPP2BSID;
}

void TDFSessionRequest::reset3GPP2BSID(){
	mTagsPresent[TDFSessionRequest_3GPP2BSID] = 0;
	if(m3GPP2BSID != NULL)
	{
		delete m3GPP2BSID; 
		m3GPP2BSID = NULL;
	}
}

OctetString* TDFSessionRequest::getSessionId(){
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

DRMP* TDFSessionRequest::getDRMP(){
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

SD::VendorSpecificApplicationId* TDFSessionRequest::getVendorSpecificApplicationId()
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

SD::VendorSpecificApplicationId* TDFSessionRequest::setVendorSpecificApplicationId(){
	if(mVendorSpecificApplicationIdGrp == NULL)
		mVendorSpecificApplicationIdGrp = new VendorSpecificApplicationId();
	mTagsPresent[TDFSessionRequest_VENDORSPECIFICAPPLICATIONID] = 1;
	mMandatoryAvpSetVal[TDFSessionRequest_VENDORSPECIFICAPPLICATIONID] = 1;
	return mVendorSpecificApplicationIdGrp;
}

void TDFSessionRequest::resetVendorSpecificApplicationId(){
	mTagsPresent[TDFSessionRequest_VENDORSPECIFICAPPLICATIONID] = 0;
	if(mVendorSpecificApplicationIdGrp != NULL)
		delete mVendorSpecificApplicationIdGrp;
}

OctetString* TDFSessionRequest::getOriginHost(){
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

OctetString* TDFSessionRequest::getOriginRealm(){
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

OctetString* TDFSessionRequest::getDestinationRealm(){
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

OctetString* TDFSessionRequest::getDestinationHost(){
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

Unsigned32* TDFSessionRequest::getOriginStateId(){
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

OCSupportedFeatures* TDFSessionRequest::getOCSupportedFeatures()
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

OCSupportedFeatures* TDFSessionRequest::setOCSupportedFeatures(){
	if(mOCSupportedFeaturesGrp == NULL)
		mOCSupportedFeaturesGrp = new OCSupportedFeatures();
	mTagsPresent[TDFSessionRequest_OCSUPPORTEDFEATURES] = 1;
	return mOCSupportedFeaturesGrp;
}

void TDFSessionRequest::resetOCSupportedFeatures(){
	mTagsPresent[TDFSessionRequest_OCSUPPORTEDFEATURES] = 0;
	if(mOCSupportedFeaturesGrp != NULL)
		delete mOCSupportedFeaturesGrp;
}

list<SubscriptionId*>* TDFSessionRequest::getSubscriptionIdGrpList()
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
			mTagsPresent[TDFSessionRequest_SUBSCRIPTIONID] = 0;
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

list<SubscriptionId*>* TDFSessionRequest::setSubscriptionIdGrpList(){
	mTagsPresent[TDFSessionRequest_SUBSCRIPTIONID] = 1;
	if(mSubscriptionIdGrpList == NULL)
		mSubscriptionIdGrpList = new list<SubscriptionId*>;
	mMandatoryAvpSetVal[TDFSessionRequest_SUBSCRIPTIONID] = 1;
	mSubscriptionIdGrpList->clear();
	return mSubscriptionIdGrpList;
}

void TDFSessionRequest::resetSubscriptionIdGrpList(){
	mTagsPresent[TDFSessionRequest_SUBSCRIPTIONID] = 0;
	if(mSubscriptionIdGrpList != NULL)
		delete mSubscriptionIdGrpList;
}

list<SupportedFeatures*>* TDFSessionRequest::getSupportedFeaturesGrpList()
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
			mTagsPresent[TDFSessionRequest_SUPPORTEDFEATURES] = 0;
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

list<SupportedFeatures*>* TDFSessionRequest::setSupportedFeaturesGrpList(){
	mTagsPresent[TDFSessionRequest_SUPPORTEDFEATURES] = 1;
	if(mSupportedFeaturesGrpList == NULL)
		mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
	mSupportedFeaturesGrpList->clear();
	return mSupportedFeaturesGrpList;
}

void TDFSessionRequest::resetSupportedFeaturesGrpList(){
	mTagsPresent[TDFSessionRequest_SUPPORTEDFEATURES] = 0;
	if(mSupportedFeaturesGrpList != NULL)
		delete mSupportedFeaturesGrpList;
}

OctetString* TDFSessionRequest::getFramedIPAddress(){
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

OctetString* TDFSessionRequest::getFramedIPv6Prefix(){
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

IPCANType* TDFSessionRequest::getIPCANType(){
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

RATType* TDFSessionRequest::getRATType(){
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

ANTrusted* TDFSessionRequest::getANTrusted(){
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

UserEquipmentInfo* TDFSessionRequest::getUserEquipmentInfo()
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

UserEquipmentInfo* TDFSessionRequest::setUserEquipmentInfo(){
	if(mUserEquipmentInfoGrp == NULL)
		mUserEquipmentInfoGrp = new UserEquipmentInfo();
	mTagsPresent[TDFSessionRequest_USEREQUIPMENTINFO] = 1;
	return mUserEquipmentInfoGrp;
}

void TDFSessionRequest::resetUserEquipmentInfo(){
	mTagsPresent[TDFSessionRequest_USEREQUIPMENTINFO] = 0;
	if(mUserEquipmentInfoGrp != NULL)
		delete mUserEquipmentInfoGrp;
}

UserEquipmentInfoExtension* TDFSessionRequest::getUserEquipmentInfoExtension()
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

UserEquipmentInfoExtension* TDFSessionRequest::setUserEquipmentInfoExtension(){
	if(mUserEquipmentInfoExtensionGrp == NULL)
		mUserEquipmentInfoExtensionGrp = new UserEquipmentInfoExtension();
	mTagsPresent[TDFSessionRequest_USEREQUIPMENTINFOEXTENSION] = 1;
	return mUserEquipmentInfoExtensionGrp;
}

void TDFSessionRequest::resetUserEquipmentInfoExtension(){
	mTagsPresent[TDFSessionRequest_USEREQUIPMENTINFOEXTENSION] = 0;
	if(mUserEquipmentInfoExtensionGrp != NULL)
		delete mUserEquipmentInfoExtensionGrp;
}

QoSInformation* TDFSessionRequest::getQoSInformation()
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

QoSInformation* TDFSessionRequest::setQoSInformation(){
	if(mQoSInformationGrp == NULL)
		mQoSInformationGrp = new QoSInformation();
	mTagsPresent[TDFSessionRequest_QOSINFORMATION] = 1;
	mMandatoryAvpSetVal[TDFSessionRequest_QOSINFORMATION] = 1;
	return mQoSInformationGrp;
}

void TDFSessionRequest::resetQoSInformation(){
	mTagsPresent[TDFSessionRequest_QOSINFORMATION] = 0;
	if(mQoSInformationGrp != NULL)
		delete mQoSInformationGrp;
}

list<Address*>* TDFSessionRequest::getANGWAddressList()
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

list<Address*>* TDFSessionRequest::setANGWAddressList() {
	mTagsPresent[TDFSessionRequest_ANGWADDRESS] = 1;
	if(mANGWAddressList == NULL)
		mANGWAddressList = new list<Address*>;
	mANGWAddressList->clear();
	return mANGWAddressList;
}

void TDFSessionRequest::resetANGWAddressList(){
	mTagsPresent[TDFSessionRequest_ANGWADDRESS] = 0;
	if(mANGWAddressList != NULL)
		delete mANGWAddressList;
}

OctetString* TDFSessionRequest::get3GPPSGSNAddress(){
	if(NULL == m3GPPSGSNAddress) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPSGSNAddress is Null");
		throw lTssDiaMsgException;
	}
	if(!m3GPPSGSNAddress->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			m3GPPSGSNAddress->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPSGSNAddress is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = m3GPPSGSNAddress->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(m3GPPSGSNAddress->Decode(mspByteArray.get(), m3GPPSGSNAddress->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPSGSNAddress")     ;
			throw lTssDiaMsgException;
		}
		m3GPPSGSNAddress->mAvpDecodedFlag = true;
	}
	return m3GPPSGSNAddress;
}

OctetString* TDFSessionRequest::get3GPPSGSNIPv6Address(){
	if(NULL == m3GPPSGSNIPv6Address) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPSGSNIPv6Address is Null");
		throw lTssDiaMsgException;
	}
	if(!m3GPPSGSNIPv6Address->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			m3GPPSGSNIPv6Address->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPSGSNIPv6Address is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = m3GPPSGSNIPv6Address->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(m3GPPSGSNIPv6Address->Decode(mspByteArray.get(), m3GPPSGSNIPv6Address->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPSGSNIPv6Address")     ;
			throw lTssDiaMsgException;
		}
		m3GPPSGSNIPv6Address->mAvpDecodedFlag = true;
	}
	return m3GPPSGSNIPv6Address;
}

OctetString* TDFSessionRequest::get3GPPGGSNAddress(){
	if(NULL == m3GPPGGSNAddress) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPGGSNAddress is Null");
		throw lTssDiaMsgException;
	}
	if(!m3GPPGGSNAddress->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			m3GPPGGSNAddress->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPGGSNAddress is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = m3GPPGGSNAddress->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(m3GPPGGSNAddress->Decode(mspByteArray.get(), m3GPPGGSNAddress->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPGGSNAddress")     ;
			throw lTssDiaMsgException;
		}
		m3GPPGGSNAddress->mAvpDecodedFlag = true;
	}
	return m3GPPGGSNAddress;
}

OctetString* TDFSessionRequest::get3GPPGGSNIPv6Address(){
	if(NULL == m3GPPGGSNIPv6Address) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPGGSNIPv6Address is Null");
		throw lTssDiaMsgException;
	}
	if(!m3GPPGGSNIPv6Address->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			m3GPPGGSNIPv6Address->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPGGSNIPv6Address is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = m3GPPGGSNIPv6Address->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(m3GPPGGSNIPv6Address->Decode(mspByteArray.get(), m3GPPGGSNIPv6Address->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPGGSNIPv6Address")     ;
			throw lTssDiaMsgException;
		}
		m3GPPGGSNIPv6Address->mAvpDecodedFlag = true;
	}
	return m3GPPGGSNIPv6Address;
}

OctetString* TDFSessionRequest::get3GPPSelectionMode(){
	if(NULL == m3GPPSelectionMode) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPSelectionMode is Null");
		throw lTssDiaMsgException;
	}
	if(!m3GPPSelectionMode->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			m3GPPSelectionMode->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPSelectionMode is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = m3GPPSelectionMode->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(m3GPPSelectionMode->Decode(mspByteArray.get(), m3GPPSelectionMode->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPSelectionMode")     ;
			throw lTssDiaMsgException;
		}
		m3GPPSelectionMode->mAvpDecodedFlag = true;
	}
	return m3GPPSelectionMode;
}

DynamicAddressFlag* TDFSessionRequest::getDynamicAddressFlag(){
	if(NULL == mDynamicAddressFlag) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DynamicAddressFlag is Null");
		throw lTssDiaMsgException;
	}
	if(!mDynamicAddressFlag->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mDynamicAddressFlag->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DynamicAddressFlag is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mDynamicAddressFlag->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mDynamicAddressFlag->Decode(mspByteArray.get(), mDynamicAddressFlag->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DynamicAddressFlag")     ;
			throw lTssDiaMsgException;
		}
		mDynamicAddressFlag->mAvpDecodedFlag = true;
	}
	return mDynamicAddressFlag;
}

DynamicAddressFlagExtension* TDFSessionRequest::getDynamicAddressFlagExtension(){
	if(NULL == mDynamicAddressFlagExtension) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DynamicAddressFlagExtension is Null");
		throw lTssDiaMsgException;
	}
	if(!mDynamicAddressFlagExtension->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mDynamicAddressFlagExtension->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DynamicAddressFlagExtension is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mDynamicAddressFlagExtension->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mDynamicAddressFlagExtension->Decode(mspByteArray.get(), mDynamicAddressFlagExtension->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DynamicAddressFlagExtension")     ;
			throw lTssDiaMsgException;
		}
		mDynamicAddressFlagExtension->mAvpDecodedFlag = true;
	}
	return mDynamicAddressFlagExtension;
}

Unsigned32* TDFSessionRequest::getPDNConnectionChargingID(){
	if(NULL == mPDNConnectionChargingID) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PDNConnectionChargingID is Null");
		throw lTssDiaMsgException;
	}
	if(!mPDNConnectionChargingID->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPDNConnectionChargingID->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PDNConnectionChargingID is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPDNConnectionChargingID->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPDNConnectionChargingID->Decode(mspByteArray.get(), mPDNConnectionChargingID->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PDNConnectionChargingID")     ;
			throw lTssDiaMsgException;
		}
		mPDNConnectionChargingID->mAvpDecodedFlag = true;
	}
	return mPDNConnectionChargingID;
}

OctetString* TDFSessionRequest::get3GPPSGSNMCCMNC(){
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

OctetString* TDFSessionRequest::getRAI(){
	if(NULL == mRAI) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RAI is Null");
		throw lTssDiaMsgException;
	}
	if(!mRAI->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRAI->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RAI is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRAI->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRAI->Decode(mspByteArray.get(), mRAI->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RAI")     ;
			throw lTssDiaMsgException;
		}
		mRAI->mAvpDecodedFlag = true;
	}
	return mRAI;
}

OctetString* TDFSessionRequest::get3GPPUserLocationInfo(){
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

FixedUserLocationInfo* TDFSessionRequest::getFixedUserLocationInfo()
{
	if(mFixedUserLocationInfoGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FixedUserLocationInfo is Null");
		throw lTssDiaMsgException;
	}
	if(!mFixedUserLocationInfoGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mFixedUserLocationInfoGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FixedUserLocationInfo is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mFixedUserLocationInfoGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mFixedUserLocationInfoGrp->Decode(mspByteArray.get(), mFixedUserLocationInfoGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FixedUserLocationInfo")     ;
			throw lTssDiaMsgException;
		}
		mFixedUserLocationInfoGrp->mAvpDecodedFlag = true;
	}
	return mFixedUserLocationInfoGrp;
}

FixedUserLocationInfo* TDFSessionRequest::setFixedUserLocationInfo(){
	if(mFixedUserLocationInfoGrp == NULL)
		mFixedUserLocationInfoGrp = new FixedUserLocationInfo();
	mTagsPresent[TDFSessionRequest_FIXEDUSERLOCATIONINFO] = 1;
	return mFixedUserLocationInfoGrp;
}

void TDFSessionRequest::resetFixedUserLocationInfo(){
	mTagsPresent[TDFSessionRequest_FIXEDUSERLOCATIONINFO] = 0;
	if(mFixedUserLocationInfoGrp != NULL)
		delete mFixedUserLocationInfoGrp;
}

UserCSGInformation* TDFSessionRequest::getUserCSGInformation()
{
	if(mUserCSGInformationGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserCSGInformation is Null");
		throw lTssDiaMsgException;
	}
	if(!mUserCSGInformationGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUserCSGInformationGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserCSGInformation is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUserCSGInformationGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUserCSGInformationGrp->Decode(mspByteArray.get(), mUserCSGInformationGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserCSGInformation")     ;
			throw lTssDiaMsgException;
		}
		mUserCSGInformationGrp->mAvpDecodedFlag = true;
	}
	return mUserCSGInformationGrp;
}

UserCSGInformation* TDFSessionRequest::setUserCSGInformation(){
	if(mUserCSGInformationGrp == NULL)
		mUserCSGInformationGrp = new UserCSGInformation();
	mTagsPresent[TDFSessionRequest_USERCSGINFORMATION] = 1;
	mMandatoryAvpSetVal[TDFSessionRequest_USERCSGINFORMATION] = 1;
	return mUserCSGInformationGrp;
}

void TDFSessionRequest::resetUserCSGInformation(){
	mTagsPresent[TDFSessionRequest_USERCSGINFORMATION] = 0;
	if(mUserCSGInformationGrp != NULL)
		delete mUserCSGInformationGrp;
}

OctetString* TDFSessionRequest::getTWANIdentifier(){
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

OctetString* TDFSessionRequest::get3GPPMSTimeZone(){
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

OctetString* TDFSessionRequest::get3GPPChargingCharacteristics(){
	if(NULL == m3GPPChargingCharacteristics) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPChargingCharacteristics is Null");
		throw lTssDiaMsgException;
	}
	if(!m3GPPChargingCharacteristics->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			m3GPPChargingCharacteristics->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPChargingCharacteristics is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = m3GPPChargingCharacteristics->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(m3GPPChargingCharacteristics->Decode(mspByteArray.get(), m3GPPChargingCharacteristics->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPChargingCharacteristics")     ;
			throw lTssDiaMsgException;
		}
		m3GPPChargingCharacteristics->mAvpDecodedFlag = true;
	}
	return m3GPPChargingCharacteristics;
}

OctetString* TDFSessionRequest::getCalledStationId(){
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

ChargingInformation* TDFSessionRequest::getChargingInformation()
{
	if(mChargingInformationGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ChargingInformation is Null");
		throw lTssDiaMsgException;
	}
	if(!mChargingInformationGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mChargingInformationGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ChargingInformation is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mChargingInformationGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mChargingInformationGrp->Decode(mspByteArray.get(), mChargingInformationGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ChargingInformation")     ;
			throw lTssDiaMsgException;
		}
		mChargingInformationGrp->mAvpDecodedFlag = true;
	}
	return mChargingInformationGrp;
}

ChargingInformation* TDFSessionRequest::setChargingInformation(){
	if(mChargingInformationGrp == NULL)
		mChargingInformationGrp = new ChargingInformation();
	mTagsPresent[TDFSessionRequest_CHARGINGINFORMATION] = 1;
	mMandatoryAvpSetVal[TDFSessionRequest_CHARGINGINFORMATION] = 1;
	return mChargingInformationGrp;
}

void TDFSessionRequest::resetChargingInformation(){
	mTagsPresent[TDFSessionRequest_CHARGINGINFORMATION] = 0;
	if(mChargingInformationGrp != NULL)
		delete mChargingInformationGrp;
}

Online* TDFSessionRequest::getOnline(){
	if(NULL == mOnline) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Online is Null");
		throw lTssDiaMsgException;
	}
	if(!mOnline->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mOnline->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Online is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mOnline->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mOnline->Decode(mspByteArray.get(), mOnline->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Online")     ;
			throw lTssDiaMsgException;
		}
		mOnline->mAvpDecodedFlag = true;
	}
	return mOnline;
}

Offline* TDFSessionRequest::getOffline(){
	if(NULL == mOffline) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Offline is Null");
		throw lTssDiaMsgException;
	}
	if(!mOffline->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mOffline->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Offline is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mOffline->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mOffline->Decode(mspByteArray.get(), mOffline->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Offline")     ;
			throw lTssDiaMsgException;
		}
		mOffline->mAvpDecodedFlag = true;
	}
	return mOffline;
}

list<ADCRuleInstall*>* TDFSessionRequest::getADCRuleInstallGrpList()
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
			mTagsPresent[TDFSessionRequest_ADCRULEINSTALL] = 0;
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

list<ADCRuleInstall*>* TDFSessionRequest::setADCRuleInstallGrpList(){
	mTagsPresent[TDFSessionRequest_ADCRULEINSTALL] = 1;
	if(mADCRuleInstallGrpList == NULL)
		mADCRuleInstallGrpList = new list<ADCRuleInstall*>;
	mMandatoryAvpSetVal[TDFSessionRequest_ADCRULEINSTALL] = 1;
	mADCRuleInstallGrpList->clear();
	return mADCRuleInstallGrpList;
}

void TDFSessionRequest::resetADCRuleInstallGrpList(){
	mTagsPresent[TDFSessionRequest_ADCRULEINSTALL] = 0;
	if(mADCRuleInstallGrpList != NULL)
		delete mADCRuleInstallGrpList;
}

Time* TDFSessionRequest::getRevalidationTime(){
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

list<UsageMonitoringInformation*>* TDFSessionRequest::getUsageMonitoringInformationGrpList()
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
			mTagsPresent[TDFSessionRequest_USAGEMONITORINGINFORMATION] = 0;
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

list<UsageMonitoringInformation*>* TDFSessionRequest::setUsageMonitoringInformationGrpList(){
	mTagsPresent[TDFSessionRequest_USAGEMONITORINGINFORMATION] = 1;
	if(mUsageMonitoringInformationGrpList == NULL)
		mUsageMonitoringInformationGrpList = new list<UsageMonitoringInformation*>;
	mUsageMonitoringInformationGrpList->clear();
	return mUsageMonitoringInformationGrpList;
}

void TDFSessionRequest::resetUsageMonitoringInformationGrpList(){
	mTagsPresent[TDFSessionRequest_USAGEMONITORINGINFORMATION] = 0;
	if(mUsageMonitoringInformationGrpList != NULL)
		delete mUsageMonitoringInformationGrpList;
}

list<CSGInformationReporting*>* TDFSessionRequest::getCSGInformationReportingList()
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

list<CSGInformationReporting*>* TDFSessionRequest::setCSGInformationReportingList() {
	mTagsPresent[TDFSessionRequest_CSGINFORMATIONREPORTING] = 1;
	if(mCSGInformationReportingList == NULL)
		mCSGInformationReportingList = new list<CSGInformationReporting*>;
	mCSGInformationReportingList->clear();
	return mCSGInformationReportingList;
}

void TDFSessionRequest::resetCSGInformationReportingList(){
	mTagsPresent[TDFSessionRequest_CSGINFORMATIONREPORTING] = 0;
	if(mCSGInformationReportingList != NULL)
		delete mCSGInformationReportingList;
}

list<EventTrigger*>* TDFSessionRequest::getEventTriggerList()
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

list<EventTrigger*>* TDFSessionRequest::setEventTriggerList() {
	mTagsPresent[TDFSessionRequest_EVENTTRIGGER] = 1;
	if(mEventTriggerList == NULL)
		mEventTriggerList = new list<EventTrigger*>;
	mMandatoryAvpSetVal [TDFSessionRequest_EVENTTRIGGER] = 1;
	mEventTriggerList->clear();
	return mEventTriggerList;
}

void TDFSessionRequest::resetEventTriggerList(){
	mTagsPresent[TDFSessionRequest_EVENTTRIGGER] = 0;
	if(mEventTriggerList != NULL)
		delete mEventTriggerList;
}

PresenceReportingAreaInformation* TDFSessionRequest::getPresenceReportingAreaInformation()
{
	if(mPresenceReportingAreaInformationGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PresenceReportingAreaInformation is Null");
		throw lTssDiaMsgException;
	}
	if(!mPresenceReportingAreaInformationGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPresenceReportingAreaInformationGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PresenceReportingAreaInformation is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPresenceReportingAreaInformationGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPresenceReportingAreaInformationGrp->Decode(mspByteArray.get(), mPresenceReportingAreaInformationGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PresenceReportingAreaInformation")     ;
			throw lTssDiaMsgException;
		}
		mPresenceReportingAreaInformationGrp->mAvpDecodedFlag = true;
	}
	return mPresenceReportingAreaInformationGrp;
}

PresenceReportingAreaInformation* TDFSessionRequest::setPresenceReportingAreaInformation(){
	if(mPresenceReportingAreaInformationGrp == NULL)
		mPresenceReportingAreaInformationGrp = new PresenceReportingAreaInformation();
	mTagsPresent[TDFSessionRequest_PRESENCEREPORTINGAREAINFORMATION] = 1;
	return mPresenceReportingAreaInformationGrp;
}

void TDFSessionRequest::resetPresenceReportingAreaInformation(){
	mTagsPresent[TDFSessionRequest_PRESENCEREPORTINGAREAINFORMATION] = 0;
	if(mPresenceReportingAreaInformationGrp != NULL)
		delete mPresenceReportingAreaInformationGrp;
}

OctetString* TDFSessionRequest::getLogicalAccessID(){
	if(NULL == mLogicalAccessID) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "LogicalAccessID is Null");
		throw lTssDiaMsgException;
	}
	if(!mLogicalAccessID->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mLogicalAccessID->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "LogicalAccessID is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mLogicalAccessID->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mLogicalAccessID->Decode(mspByteArray.get(), mLogicalAccessID->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding LogicalAccessID")     ;
			throw lTssDiaMsgException;
		}
		mLogicalAccessID->mAvpDecodedFlag = true;
	}
	return mLogicalAccessID;
}

OctetString* TDFSessionRequest::getPhysicalAccessID(){
	if(NULL == mPhysicalAccessID) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PhysicalAccessID is Null");
		throw lTssDiaMsgException;
	}
	if(!mPhysicalAccessID->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPhysicalAccessID->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PhysicalAccessID is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPhysicalAccessID->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPhysicalAccessID->Decode(mspByteArray.get(), mPhysicalAccessID->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PhysicalAccessID")     ;
			throw lTssDiaMsgException;
		}
		mPhysicalAccessID->mAvpDecodedFlag = true;
	}
	return mPhysicalAccessID;
}

OctetString* TDFSessionRequest::get3GPP2BSID(){
	if(NULL == m3GPP2BSID) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPP2BSID is Null");
		throw lTssDiaMsgException;
	}
	if(!m3GPP2BSID->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			m3GPP2BSID->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPP2BSID is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = m3GPP2BSID->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(m3GPP2BSID->Decode(mspByteArray.get(), m3GPP2BSID->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPP2BSID")     ;
			throw lTssDiaMsgException;
		}
		m3GPP2BSID->mAvpDecodedFlag = true;
	}
	return m3GPP2BSID;
}

list<SD::ProxyInfo*>* TDFSessionRequest::getProxyInfoGrpList()
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
			mTagsPresent[TDFSessionRequest_PROXYINFO] = 0;
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

list<SD::ProxyInfo*>* TDFSessionRequest::setProxyInfoGrpList(){
	mTagsPresent[TDFSessionRequest_PROXYINFO] = 1;
	if(mProxyInfoGrpList == NULL)
		mProxyInfoGrpList = new list<SD::ProxyInfo*>;
	mMandatoryAvpSetVal[TDFSessionRequest_PROXYINFO] = 1;
	mProxyInfoGrpList->clear();
	return mProxyInfoGrpList;
}

void TDFSessionRequest::resetProxyInfoGrpList(){
	mTagsPresent[TDFSessionRequest_PROXYINFO] = 0;
	if(mProxyInfoGrpList != NULL)
		delete mProxyInfoGrpList;
}

list<OctetString*>* TDFSessionRequest::getRouteRecordList()
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

list<OctetString*>* TDFSessionRequest::setRouteRecordList() {
	mTagsPresent[TDFSessionRequest_ROUTERECORD] = 1;
	if(mRouteRecordList == NULL)
		mRouteRecordList = new list<OctetString*>;
	mMandatoryAvpSetVal [TDFSessionRequest_ROUTERECORD] = 1;
	mRouteRecordList->clear();
	return mRouteRecordList;
}

void TDFSessionRequest::resetRouteRecordList(){
	mTagsPresent[TDFSessionRequest_ROUTERECORD] = 0;
	if(mRouteRecordList != NULL)
		delete mRouteRecordList;
}



int TDFSessionRequest::Encode(byteArray *array)
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
	array->byte[array->offset++] = (29>>16) & 0xFF;
	array->byte[array->offset++] = (29>>8) & 0xFF;
	array->byte[array->offset++] = (29) & 0xFF;
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
			case TDFSessionRequest_SESSIONID:
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
			case TDFSessionRequest_DRMP:
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
			case TDFSessionRequest_VENDORSPECIFICAPPLICATIONID:
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
			case TDFSessionRequest_ORIGINHOST:
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
			case TDFSessionRequest_ORIGINREALM:
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
			case TDFSessionRequest_DESTINATIONREALM:
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
			case TDFSessionRequest_DESTINATIONHOST:
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
			case TDFSessionRequest_ORIGINSTATEID:
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
						INT32 venderId=0;
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
			case TDFSessionRequest_OCSUPPORTEDFEATURES:
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
						INT32 venderId=0;
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
			case TDFSessionRequest_SUBSCRIPTIONID:
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
						INT32 venderId=0;
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
			case TDFSessionRequest_SUPPORTEDFEATURES:
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
			case TDFSessionRequest_FRAMEDIPADDRESS:
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
			case TDFSessionRequest_FRAMEDIPV6PREFIX:
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
			case TDFSessionRequest_IPCANTYPE:
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
			case TDFSessionRequest_RATTYPE:
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
			case TDFSessionRequest_ANTRUSTED:
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
			case TDFSessionRequest_USEREQUIPMENTINFO:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(458);
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
				if((this->getUserEquipmentInfo()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserEquipmentInfo");
					throw lTssDiaMsgException;
					}
				}
				break;
			case TDFSessionRequest_USEREQUIPMENTINFOEXTENSION:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(653);
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
				if((this->getUserEquipmentInfoExtension()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserEquipmentInfoExtension");
					throw lTssDiaMsgException;
					}
				}
				break;
			case TDFSessionRequest_QOSINFORMATION:
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
			case TDFSessionRequest_ANGWADDRESS:
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
			case TDFSessionRequest_3GPPSGSNADDRESS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(6);
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
					if(!m3GPPSGSNAddress->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[m3GPPSGSNAddress->getAvpOffsetLen().first], m3GPPSGSNAddress->getAvpOffsetLen().second);
						array->offset += m3GPPSGSNAddress->getAvpOffsetLen().second;
						array->size += m3GPPSGSNAddress->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( m3GPPSGSNAddress->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(m3GPPSGSNAddress->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPSGSNAddress");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((m3GPPSGSNAddress->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, m3GPPSGSNAddress->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPSGSNAddress");
						throw lTssDiaMsgException;
					}
				}
				break;
			case TDFSessionRequest_3GPPSGSNIPV6ADDRESS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(15);
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
					if(!m3GPPSGSNIPv6Address->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[m3GPPSGSNIPv6Address->getAvpOffsetLen().first], m3GPPSGSNIPv6Address->getAvpOffsetLen().second);
						array->offset += m3GPPSGSNIPv6Address->getAvpOffsetLen().second;
						array->size += m3GPPSGSNIPv6Address->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( m3GPPSGSNIPv6Address->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(m3GPPSGSNIPv6Address->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPSGSNIPv6Address");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((m3GPPSGSNIPv6Address->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, m3GPPSGSNIPv6Address->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPSGSNIPv6Address");
						throw lTssDiaMsgException;
					}
				}
				break;
			case TDFSessionRequest_3GPPGGSNADDRESS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(7);
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
					if(!m3GPPGGSNAddress->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[m3GPPGGSNAddress->getAvpOffsetLen().first], m3GPPGGSNAddress->getAvpOffsetLen().second);
						array->offset += m3GPPGGSNAddress->getAvpOffsetLen().second;
						array->size += m3GPPGGSNAddress->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( m3GPPGGSNAddress->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(m3GPPGGSNAddress->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPGGSNAddress");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((m3GPPGGSNAddress->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, m3GPPGGSNAddress->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPGGSNAddress");
						throw lTssDiaMsgException;
					}
				}
				break;
			case TDFSessionRequest_3GPPGGSNIPV6ADDRESS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(16);
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
					if(!m3GPPGGSNIPv6Address->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[m3GPPGGSNIPv6Address->getAvpOffsetLen().first], m3GPPGGSNIPv6Address->getAvpOffsetLen().second);
						array->offset += m3GPPGGSNIPv6Address->getAvpOffsetLen().second;
						array->size += m3GPPGGSNIPv6Address->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( m3GPPGGSNIPv6Address->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(m3GPPGGSNIPv6Address->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPGGSNIPv6Address");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((m3GPPGGSNIPv6Address->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, m3GPPGGSNIPv6Address->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPGGSNIPv6Address");
						throw lTssDiaMsgException;
					}
				}
				break;
			case TDFSessionRequest_3GPPSELECTIONMODE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(12);
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
					if(!m3GPPSelectionMode->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[m3GPPSelectionMode->getAvpOffsetLen().first], m3GPPSelectionMode->getAvpOffsetLen().second);
						array->offset += m3GPPSelectionMode->getAvpOffsetLen().second;
						array->size += m3GPPSelectionMode->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( m3GPPSelectionMode->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(m3GPPSelectionMode->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPSelectionMode");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((m3GPPSelectionMode->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, m3GPPSelectionMode->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPSelectionMode");
						throw lTssDiaMsgException;
					}
				}
				break;
			case TDFSessionRequest_DYNAMICADDRESSFLAG:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2051);
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
					if(!mDynamicAddressFlag->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mDynamicAddressFlag->getAvpOffsetLen().first], mDynamicAddressFlag->getAvpOffsetLen().second);
						array->offset += mDynamicAddressFlag->getAvpOffsetLen().second;
						array->size += mDynamicAddressFlag->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DynamicAddressFlag");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mDynamicAddressFlag->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DynamicAddressFlag");
						throw lTssDiaMsgException;
					}
				}
				break;
			case TDFSessionRequest_DYNAMICADDRESSFLAGEXTENSION:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2068);
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
					if(!mDynamicAddressFlagExtension->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mDynamicAddressFlagExtension->getAvpOffsetLen().first], mDynamicAddressFlagExtension->getAvpOffsetLen().second);
						array->offset += mDynamicAddressFlagExtension->getAvpOffsetLen().second;
						array->size += mDynamicAddressFlagExtension->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DynamicAddressFlagExtension");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mDynamicAddressFlagExtension->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DynamicAddressFlagExtension");
						throw lTssDiaMsgException;
					}
				}
				break;
			case TDFSessionRequest_PDNCONNECTIONCHARGINGID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2050);
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
					if(!mPDNConnectionChargingID->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mPDNConnectionChargingID->getAvpOffsetLen().first], mPDNConnectionChargingID->getAvpOffsetLen().second);
						array->offset += mPDNConnectionChargingID->getAvpOffsetLen().second;
						array->size += mPDNConnectionChargingID->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PDNConnectionChargingID");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mPDNConnectionChargingID->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PDNConnectionChargingID");
						throw lTssDiaMsgException;
					}
				}
				break;
			case TDFSessionRequest_3GPPSGSNMCCMNC:
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
			case TDFSessionRequest_RAI:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(909);
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
					if(!mRAI->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRAI->getAvpOffsetLen().first], mRAI->getAvpOffsetLen().second);
						array->offset += mRAI->getAvpOffsetLen().second;
						array->size += mRAI->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mRAI->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mRAI->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RAI");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mRAI->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mRAI->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RAI");
						throw lTssDiaMsgException;
					}
				}
				break;
			case TDFSessionRequest_3GPPUSERLOCATIONINFO:
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
			case TDFSessionRequest_FIXEDUSERLOCATIONINFO:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(2825);
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
				if((this->getFixedUserLocationInfo()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FixedUserLocationInfo");
					throw lTssDiaMsgException;
					}
				}
				break;
			case TDFSessionRequest_USERCSGINFORMATION:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(2319);
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
				if((this->getUserCSGInformation()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserCSGInformation");
					throw lTssDiaMsgException;
					}
				}
				break;
			case TDFSessionRequest_TWANIDENTIFIER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(29);
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
			case TDFSessionRequest_3GPPMSTIMEZONE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(23);
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
			case TDFSessionRequest_3GPPCHARGINGCHARACTERISTICS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(13);
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
					if(!m3GPPChargingCharacteristics->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[m3GPPChargingCharacteristics->getAvpOffsetLen().first], m3GPPChargingCharacteristics->getAvpOffsetLen().second);
						array->offset += m3GPPChargingCharacteristics->getAvpOffsetLen().second;
						array->size += m3GPPChargingCharacteristics->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( m3GPPChargingCharacteristics->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(m3GPPChargingCharacteristics->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPChargingCharacteristics");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((m3GPPChargingCharacteristics->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, m3GPPChargingCharacteristics->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPChargingCharacteristics");
						throw lTssDiaMsgException;
					}
				}
				break;
			case TDFSessionRequest_CALLEDSTATIONID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(30);
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
			case TDFSessionRequest_CHARGINGINFORMATION:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(618);
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
				if((this->getChargingInformation()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ChargingInformation");
					throw lTssDiaMsgException;
					}
				}
				break;
			case TDFSessionRequest_ONLINE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1009);
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
					if(!mOnline->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mOnline->getAvpOffsetLen().first], mOnline->getAvpOffsetLen().second);
						array->offset += mOnline->getAvpOffsetLen().second;
						array->size += mOnline->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Online");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mOnline->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Online");
						throw lTssDiaMsgException;
					}
				}
				break;
			case TDFSessionRequest_OFFLINE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1008);
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
					if(!mOffline->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mOffline->getAvpOffsetLen().first], mOffline->getAvpOffsetLen().second);
						array->offset += mOffline->getAvpOffsetLen().second;
						array->size += mOffline->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Offline");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mOffline->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Offline");
						throw lTssDiaMsgException;
					}
				}
				break;
			case TDFSessionRequest_ADCRULEINSTALL:
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
			case TDFSessionRequest_REVALIDATIONTIME:
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
			case TDFSessionRequest_USAGEMONITORINGINFORMATION:
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
			case TDFSessionRequest_CSGINFORMATIONREPORTING:
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
			case TDFSessionRequest_EVENTTRIGGER:
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
			case TDFSessionRequest_PRESENCEREPORTINGAREAINFORMATION:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(2822);
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
				if((this->getPresenceReportingAreaInformation()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PresenceReportingAreaInformation");
					throw lTssDiaMsgException;
					}
				}
				break;
			case TDFSessionRequest_LOGICALACCESSID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(302);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=13019;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mLogicalAccessID->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mLogicalAccessID->getAvpOffsetLen().first], mLogicalAccessID->getAvpOffsetLen().second);
						array->offset += mLogicalAccessID->getAvpOffsetLen().second;
						array->size += mLogicalAccessID->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mLogicalAccessID->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mLogicalAccessID->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding LogicalAccessID");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mLogicalAccessID->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mLogicalAccessID->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding LogicalAccessID");
						throw lTssDiaMsgException;
					}
				}
				break;
			case TDFSessionRequest_PHYSICALACCESSID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(313);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=13019;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mPhysicalAccessID->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mPhysicalAccessID->getAvpOffsetLen().first], mPhysicalAccessID->getAvpOffsetLen().second);
						array->offset += mPhysicalAccessID->getAvpOffsetLen().second;
						array->size += mPhysicalAccessID->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mPhysicalAccessID->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mPhysicalAccessID->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PhysicalAccessID");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mPhysicalAccessID->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mPhysicalAccessID->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PhysicalAccessID");
						throw lTssDiaMsgException;
					}
				}
				break;
			case TDFSessionRequest_3GPP2BSID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(9010);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 192;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(192))
					{ 
						INT32 venderId=5535;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!m3GPP2BSID->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[m3GPP2BSID->getAvpOffsetLen().first], m3GPP2BSID->getAvpOffsetLen().second);
						array->offset += m3GPP2BSID->getAvpOffsetLen().second;
						array->size += m3GPP2BSID->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( m3GPP2BSID->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(m3GPP2BSID->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPP2BSID");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((m3GPP2BSID->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, m3GPP2BSID->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPP2BSID");
						throw lTssDiaMsgException;
					}
				}
				break;
			case TDFSessionRequest_PROXYINFO:
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
						INT32 venderId=5535;
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
			case TDFSessionRequest_ROUTERECORD:
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
						INT32 venderId=5535;
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


int TDFSessionRequest::Decode(byteArray *array, INT16 lMLen, UINT16 *parsedBytes)
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
						mMandatoryAvpSetVal [TDFSessionRequest_SESSIONID] = 1;
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
						mMandatoryAvpSetVal [TDFSessionRequest_VENDORSPECIFICAPPLICATIONID] = 1;
					mTagsPresent[TDFSessionRequest_VENDORSPECIFICAPPLICATIONID] = 1;
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
			case 264:
				{
						mMandatoryAvpSetVal [TDFSessionRequest_ORIGINHOST] = 1;
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
						mMandatoryAvpSetVal [TDFSessionRequest_ORIGINREALM] = 1;
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
						mMandatoryAvpSetVal [TDFSessionRequest_DESTINATIONREALM] = 1;
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
						mMandatoryAvpSetVal [TDFSessionRequest_DESTINATIONHOST] = 1;
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
			case 278:
				{
						mMandatoryAvpSetVal [TDFSessionRequest_ORIGINSTATEID] = 1;
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
					mTagsPresent[TDFSessionRequest_OCSUPPORTEDFEATURES] = 1;
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
			case 443:
				{
						mMandatoryAvpSetVal [TDFSessionRequest_SUBSCRIPTIONID] = 1;
					mTagsPresent[TDFSessionRequest_SUBSCRIPTIONID] = 1;
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
			case 628:
				{
					mTagsPresent[TDFSessionRequest_SUPPORTEDFEATURES] = 1;
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
			case 8:
				{
						mMandatoryAvpSetVal [TDFSessionRequest_FRAMEDIPADDRESS] = 1;
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
						mMandatoryAvpSetVal [TDFSessionRequest_FRAMEDIPV6PREFIX] = 1;
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
			case 1027:
				{
						mMandatoryAvpSetVal [TDFSessionRequest_IPCANTYPE] = 1;
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
			case 1503:
				{
						mMandatoryAvpSetVal [TDFSessionRequest_ANTRUSTED] = 1;
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
			case 458:
				{
					mTagsPresent[TDFSessionRequest_USEREQUIPMENTINFO] = 1;
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
					mTagsPresent[TDFSessionRequest_USEREQUIPMENTINFOEXTENSION] = 1;
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
			case 1016:
				{
						mMandatoryAvpSetVal [TDFSessionRequest_QOSINFORMATION] = 1;
					mTagsPresent[TDFSessionRequest_QOSINFORMATION] = 1;
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
			case 1050:
				{
					mTagsPresent[TDFSessionRequest_ANGWADDRESS] = 1;
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
			case 6:
				{
					if( NULL == this->set3GPPSGSNAddress())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPSGSNAddress");
						throw lTssDiaMsgException;
					}
					m3GPPSGSNAddress->setAvpCode(6);
					m3GPPSGSNAddress->setAvpVendorId(lVenderId);
					m3GPPSGSNAddress->SetDataType((DiameterDataType)5);
					m3GPPSGSNAddress->mspByteArray = mspByteArray;
					m3GPPSGSNAddress->mAvpDecodedFlag = false;
					m3GPPSGSNAddress->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 15:
				{
					if( NULL == this->set3GPPSGSNIPv6Address())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPSGSNIPv6Address");
						throw lTssDiaMsgException;
					}
					m3GPPSGSNIPv6Address->setAvpCode(15);
					m3GPPSGSNIPv6Address->setAvpVendorId(lVenderId);
					m3GPPSGSNIPv6Address->SetDataType((DiameterDataType)5);
					m3GPPSGSNIPv6Address->mspByteArray = mspByteArray;
					m3GPPSGSNIPv6Address->mAvpDecodedFlag = false;
					m3GPPSGSNIPv6Address->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 7:
				{
					if( NULL == this->set3GPPGGSNAddress())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPGGSNAddress");
						throw lTssDiaMsgException;
					}
					m3GPPGGSNAddress->setAvpCode(7);
					m3GPPGGSNAddress->setAvpVendorId(lVenderId);
					m3GPPGGSNAddress->SetDataType((DiameterDataType)5);
					m3GPPGGSNAddress->mspByteArray = mspByteArray;
					m3GPPGGSNAddress->mAvpDecodedFlag = false;
					m3GPPGGSNAddress->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 16:
				{
					if( NULL == this->set3GPPGGSNIPv6Address())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPGGSNIPv6Address");
						throw lTssDiaMsgException;
					}
					m3GPPGGSNIPv6Address->setAvpCode(16);
					m3GPPGGSNIPv6Address->setAvpVendorId(lVenderId);
					m3GPPGGSNIPv6Address->SetDataType((DiameterDataType)5);
					m3GPPGGSNIPv6Address->mspByteArray = mspByteArray;
					m3GPPGGSNIPv6Address->mAvpDecodedFlag = false;
					m3GPPGGSNIPv6Address->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 12:
				{
					if( NULL == this->set3GPPSelectionMode())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPSelectionMode");
						throw lTssDiaMsgException;
					}
					m3GPPSelectionMode->setAvpCode(12);
					m3GPPSelectionMode->setAvpVendorId(lVenderId);
					m3GPPSelectionMode->SetDataType((DiameterDataType)5);
					m3GPPSelectionMode->mspByteArray = mspByteArray;
					m3GPPSelectionMode->mAvpDecodedFlag = false;
					m3GPPSelectionMode->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2051:
				{
					if( NULL == this->setDynamicAddressFlag())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DynamicAddressFlag");
						throw lTssDiaMsgException;
					}
					mDynamicAddressFlag->setAvpCode(2051);
					mDynamicAddressFlag->setAvpVendorId(lVenderId);
					mDynamicAddressFlag->SetDataType((DiameterDataType)7);
					mDynamicAddressFlag->mspByteArray = mspByteArray;
					mDynamicAddressFlag->mAvpDecodedFlag = false;
					mDynamicAddressFlag->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2068:
				{
					if( NULL == this->setDynamicAddressFlagExtension())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DynamicAddressFlagExtension");
						throw lTssDiaMsgException;
					}
					mDynamicAddressFlagExtension->setAvpCode(2068);
					mDynamicAddressFlagExtension->setAvpVendorId(lVenderId);
					mDynamicAddressFlagExtension->SetDataType((DiameterDataType)7);
					mDynamicAddressFlagExtension->mspByteArray = mspByteArray;
					mDynamicAddressFlagExtension->mAvpDecodedFlag = false;
					mDynamicAddressFlagExtension->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2050:
				{
					if( NULL == this->setPDNConnectionChargingID())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PDNConnectionChargingID");
						throw lTssDiaMsgException;
					}
					mPDNConnectionChargingID->setAvpCode(2050);
					mPDNConnectionChargingID->setAvpVendorId(lVenderId);
					mPDNConnectionChargingID->SetDataType((DiameterDataType)3);
					mPDNConnectionChargingID->mspByteArray = mspByteArray;
					mPDNConnectionChargingID->mAvpDecodedFlag = false;
					mPDNConnectionChargingID->setAvpOffsetLen(array->offset,lAvpDataLen);
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
			case 909:
				{
					if( NULL == this->setRAI())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RAI");
						throw lTssDiaMsgException;
					}
					mRAI->setAvpCode(909);
					mRAI->setAvpVendorId(lVenderId);
					mRAI->SetDataType((DiameterDataType)5);
					mRAI->mspByteArray = mspByteArray;
					mRAI->mAvpDecodedFlag = false;
					mRAI->setAvpOffsetLen(array->offset,lAvpDataLen);
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
			case 2825:
				{
					mTagsPresent[TDFSessionRequest_FIXEDUSERLOCATIONINFO] = 1;
						if( NULL == this->setFixedUserLocationInfo()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FixedUserLocationInfo");
						throw lTssDiaMsgException;
						}
					mFixedUserLocationInfoGrp->setAvpCode(2825);
					mFixedUserLocationInfoGrp->SetDataType((DiameterDataType)6);
					mFixedUserLocationInfoGrp->mspByteArray = mspByteArray;
					mFixedUserLocationInfoGrp->mAvpDecodedFlag = false;
					mFixedUserLocationInfoGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mFixedUserLocationInfoGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2319:
				{
						mMandatoryAvpSetVal [TDFSessionRequest_USERCSGINFORMATION] = 1;
					mTagsPresent[TDFSessionRequest_USERCSGINFORMATION] = 1;
						if( NULL == this->setUserCSGInformation()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserCSGInformation");
						throw lTssDiaMsgException;
						}
					mUserCSGInformationGrp->setAvpCode(2319);
					mUserCSGInformationGrp->SetDataType((DiameterDataType)6);
					mUserCSGInformationGrp->mspByteArray = mspByteArray;
					mUserCSGInformationGrp->mAvpDecodedFlag = false;
					mUserCSGInformationGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mUserCSGInformationGrp);
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
			case 13:
				{
					if( NULL == this->set3GPPChargingCharacteristics())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPChargingCharacteristics");
						throw lTssDiaMsgException;
					}
					m3GPPChargingCharacteristics->setAvpCode(13);
					m3GPPChargingCharacteristics->setAvpVendorId(lVenderId);
					m3GPPChargingCharacteristics->SetDataType((DiameterDataType)5);
					m3GPPChargingCharacteristics->mspByteArray = mspByteArray;
					m3GPPChargingCharacteristics->mAvpDecodedFlag = false;
					m3GPPChargingCharacteristics->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 30:
				{
						mMandatoryAvpSetVal [TDFSessionRequest_CALLEDSTATIONID] = 1;
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
			case 618:
				{
						mMandatoryAvpSetVal [TDFSessionRequest_CHARGINGINFORMATION] = 1;
					mTagsPresent[TDFSessionRequest_CHARGINGINFORMATION] = 1;
						if( NULL == this->setChargingInformation()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ChargingInformation");
						throw lTssDiaMsgException;
						}
					mChargingInformationGrp->setAvpCode(618);
					mChargingInformationGrp->SetDataType((DiameterDataType)6);
					mChargingInformationGrp->mspByteArray = mspByteArray;
					mChargingInformationGrp->mAvpDecodedFlag = false;
					mChargingInformationGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mChargingInformationGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1009:
				{
						mMandatoryAvpSetVal [TDFSessionRequest_ONLINE] = 1;
					if( NULL == this->setOnline())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Online");
						throw lTssDiaMsgException;
					}
					mOnline->setAvpCode(1009);
					mOnline->setAvpVendorId(lVenderId);
					mOnline->SetDataType((DiameterDataType)7);
					mOnline->mspByteArray = mspByteArray;
					mOnline->mAvpDecodedFlag = false;
					mOnline->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1008:
				{
						mMandatoryAvpSetVal [TDFSessionRequest_OFFLINE] = 1;
					if( NULL == this->setOffline())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Offline");
						throw lTssDiaMsgException;
					}
					mOffline->setAvpCode(1008);
					mOffline->setAvpVendorId(lVenderId);
					mOffline->SetDataType((DiameterDataType)7);
					mOffline->mspByteArray = mspByteArray;
					mOffline->mAvpDecodedFlag = false;
					mOffline->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1092:
				{
						mMandatoryAvpSetVal [TDFSessionRequest_ADCRULEINSTALL] = 1;
					mTagsPresent[TDFSessionRequest_ADCRULEINSTALL] = 1;
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
						mMandatoryAvpSetVal [TDFSessionRequest_REVALIDATIONTIME] = 1;
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
					mTagsPresent[TDFSessionRequest_USAGEMONITORINGINFORMATION] = 1;
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
			case 1071:
				{
					mTagsPresent[TDFSessionRequest_CSGINFORMATIONREPORTING] = 1;
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
			case 1006:
				{
						mMandatoryAvpSetVal [TDFSessionRequest_EVENTTRIGGER] = 1;
					mTagsPresent[TDFSessionRequest_EVENTTRIGGER] = 1;
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
			case 2822:
				{
					mTagsPresent[TDFSessionRequest_PRESENCEREPORTINGAREAINFORMATION] = 1;
						if( NULL == this->setPresenceReportingAreaInformation()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PresenceReportingAreaInformation");
						throw lTssDiaMsgException;
						}
					mPresenceReportingAreaInformationGrp->setAvpCode(2822);
					mPresenceReportingAreaInformationGrp->SetDataType((DiameterDataType)6);
					mPresenceReportingAreaInformationGrp->mspByteArray = mspByteArray;
					mPresenceReportingAreaInformationGrp->mAvpDecodedFlag = false;
					mPresenceReportingAreaInformationGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mPresenceReportingAreaInformationGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			case 302:
				{
					if( NULL == this->setLogicalAccessID())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding LogicalAccessID");
						throw lTssDiaMsgException;
					}
					mLogicalAccessID->setAvpCode(302);
					mLogicalAccessID->setAvpVendorId(lVenderId);
					mLogicalAccessID->SetDataType((DiameterDataType)5);
					mLogicalAccessID->mspByteArray = mspByteArray;
					mLogicalAccessID->mAvpDecodedFlag = false;
					mLogicalAccessID->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 313:
				{
					if( NULL == this->setPhysicalAccessID())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PhysicalAccessID");
						throw lTssDiaMsgException;
					}
					mPhysicalAccessID->setAvpCode(313);
					mPhysicalAccessID->setAvpVendorId(lVenderId);
					mPhysicalAccessID->SetDataType((DiameterDataType)5);
					mPhysicalAccessID->mspByteArray = mspByteArray;
					mPhysicalAccessID->mAvpDecodedFlag = false;
					mPhysicalAccessID->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 9010:
				{
						mMandatoryAvpSetVal [TDFSessionRequest_3GPP2BSID] = 1;
					if( NULL == this->set3GPP2BSID())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPP2BSID");
						throw lTssDiaMsgException;
					}
					m3GPP2BSID->setAvpCode(9010);
					m3GPP2BSID->setAvpVendorId(lVenderId);
					m3GPP2BSID->SetDataType((DiameterDataType)5);
					m3GPP2BSID->mspByteArray = mspByteArray;
					m3GPP2BSID->mAvpDecodedFlag = false;
					m3GPP2BSID->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 284:
				{
						mMandatoryAvpSetVal [TDFSessionRequest_PROXYINFO] = 1;
					mTagsPresent[TDFSessionRequest_PROXYINFO] = 1;
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
						mMandatoryAvpSetVal [TDFSessionRequest_ROUTERECORD] = 1;
					mTagsPresent[TDFSessionRequest_ROUTERECORD] = 1;
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


DiameterBaseInterface* TDFSessionRequest::Find(byteArray *array, UINT32 avpCode)
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
			case 278:
			{
				if(mOriginStateId != NULL)
					return mOriginStateId->Find(array, avpCode);
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
			case 1027:
			{
				if(mIPCANType != NULL)
					return mIPCANType->Find(array, avpCode);
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
			case 1503:
			{
				if(mANTrusted != NULL)
					return mANTrusted->Find(array, avpCode);
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
			case 6:
			{
				if(m3GPPSGSNAddress != NULL)
					return m3GPPSGSNAddress->Find(array, avpCode);
				else
					return NULL;
			}
			case 15:
			{
				if(m3GPPSGSNIPv6Address != NULL)
					return m3GPPSGSNIPv6Address->Find(array, avpCode);
				else
					return NULL;
			}
			case 7:
			{
				if(m3GPPGGSNAddress != NULL)
					return m3GPPGGSNAddress->Find(array, avpCode);
				else
					return NULL;
			}
			case 16:
			{
				if(m3GPPGGSNIPv6Address != NULL)
					return m3GPPGGSNIPv6Address->Find(array, avpCode);
				else
					return NULL;
			}
			case 12:
			{
				if(m3GPPSelectionMode != NULL)
					return m3GPPSelectionMode->Find(array, avpCode);
				else
					return NULL;
			}
			case 2051:
			{
				if(mDynamicAddressFlag != NULL)
					return mDynamicAddressFlag->Find(array, avpCode);
				else
					return NULL;
			}
			case 2068:
			{
				if(mDynamicAddressFlagExtension != NULL)
					return mDynamicAddressFlagExtension->Find(array, avpCode);
				else
					return NULL;
			}
			case 2050:
			{
				if(mPDNConnectionChargingID != NULL)
					return mPDNConnectionChargingID->Find(array, avpCode);
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
			case 909:
			{
				if(mRAI != NULL)
					return mRAI->Find(array, avpCode);
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
			case 29:
			{
				if(mTWANIdentifier != NULL)
					return mTWANIdentifier->Find(array, avpCode);
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
			case 13:
			{
				if(m3GPPChargingCharacteristics != NULL)
					return m3GPPChargingCharacteristics->Find(array, avpCode);
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
			case 1009:
			{
				if(mOnline != NULL)
					return mOnline->Find(array, avpCode);
				else
					return NULL;
			}
			case 1008:
			{
				if(mOffline != NULL)
					return mOffline->Find(array, avpCode);
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
			case 1071:
			{
				if(mCSGInformationReportingList != NULL && mCSGInformationReportingList->size() > 0)
					return (mCSGInformationReportingList->back())->Find(array, avpCode);
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
			case 302:
			{
				if(mLogicalAccessID != NULL)
					return mLogicalAccessID->Find(array, avpCode);
				else
					return NULL;
			}
			case 313:
			{
				if(mPhysicalAccessID != NULL)
					return mPhysicalAccessID->Find(array, avpCode);
				else
					return NULL;
			}
			case 9010:
			{
				if(m3GPP2BSID != NULL)
					return m3GPP2BSID->Find(array, avpCode);
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


BOOLEAN TDFSessionRequest::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
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
			case 6:
			{
				if(m3GPPSGSNAddress != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPSGSNAddress->Find(this->mspByteArray.get(), avpCode);
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
			case 15:
			{
				if(m3GPPSGSNIPv6Address != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPSGSNIPv6Address->Find(this->mspByteArray.get(), avpCode);
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
			case 7:
			{
				if(m3GPPGGSNAddress != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPGGSNAddress->Find(this->mspByteArray.get(), avpCode);
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
			case 16:
			{
				if(m3GPPGGSNIPv6Address != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPGGSNIPv6Address->Find(this->mspByteArray.get(), avpCode);
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
			case 12:
			{
				if(m3GPPSelectionMode != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPSelectionMode->Find(this->mspByteArray.get(), avpCode);
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
			case 2051:
			{
				if(mDynamicAddressFlag != NULL)
				{
					DiameterBaseInterface* inf =  mDynamicAddressFlag->Find(this->mspByteArray.get(), avpCode);
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
			case 2068:
			{
				if(mDynamicAddressFlagExtension != NULL)
				{
					DiameterBaseInterface* inf =  mDynamicAddressFlagExtension->Find(this->mspByteArray.get(), avpCode);
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
			case 2050:
			{
				if(mPDNConnectionChargingID != NULL)
				{
					DiameterBaseInterface* inf =  mPDNConnectionChargingID->Find(this->mspByteArray.get(), avpCode);
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
			case 909:
			{
				if(mRAI != NULL)
				{
					DiameterBaseInterface* inf =  mRAI->Find(this->mspByteArray.get(), avpCode);
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
			case 2825:
			{
				if(mFixedUserLocationInfoGrp != NULL)
				{
						pBaseInterface.push_back(mFixedUserLocationInfoGrp);
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
			case 2319:
			{
				if(mUserCSGInformationGrp != NULL)
				{
						pBaseInterface.push_back(mUserCSGInformationGrp);
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
			case 13:
			{
				if(m3GPPChargingCharacteristics != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPChargingCharacteristics->Find(this->mspByteArray.get(), avpCode);
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
			case 618:
			{
				if(mChargingInformationGrp != NULL)
				{
						pBaseInterface.push_back(mChargingInformationGrp);
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
			case 1009:
			{
				if(mOnline != NULL)
				{
					DiameterBaseInterface* inf =  mOnline->Find(this->mspByteArray.get(), avpCode);
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
			case 1008:
			{
				if(mOffline != NULL)
				{
					DiameterBaseInterface* inf =  mOffline->Find(this->mspByteArray.get(), avpCode);
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
			case 2822:
			{
				if(mPresenceReportingAreaInformationGrp != NULL)
				{
						pBaseInterface.push_back(mPresenceReportingAreaInformationGrp);
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
			case 302:
			{
				if(mLogicalAccessID != NULL)
				{
					DiameterBaseInterface* inf =  mLogicalAccessID->Find(this->mspByteArray.get(), avpCode);
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
			case 313:
			{
				if(mPhysicalAccessID != NULL)
				{
					DiameterBaseInterface* inf =  mPhysicalAccessID->Find(this->mspByteArray.get(), avpCode);
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
			case 9010:
			{
				if(m3GPP2BSID != NULL)
				{
					DiameterBaseInterface* inf =  m3GPP2BSID->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> TDFSessionRequest::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN TDFSessionRequest::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
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
			case 6:
			{
				if(m3GPPSGSNAddress != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPSGSNAddress->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 15:
			{
				if(m3GPPSGSNIPv6Address != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPSGSNIPv6Address->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 7:
			{
				if(m3GPPGGSNAddress != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPGGSNAddress->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 16:
			{
				if(m3GPPGGSNIPv6Address != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPGGSNIPv6Address->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 12:
			{
				if(m3GPPSelectionMode != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPSelectionMode->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2051:
			{
				if(mDynamicAddressFlag != NULL)
				{
					DiameterBaseInterface* inf =  mDynamicAddressFlag->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2068:
			{
				if(mDynamicAddressFlagExtension != NULL)
				{
					DiameterBaseInterface* inf =  mDynamicAddressFlagExtension->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2050:
			{
				if(mPDNConnectionChargingID != NULL)
				{
					DiameterBaseInterface* inf =  mPDNConnectionChargingID->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
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
			case 909:
			{
				if(mRAI != NULL)
				{
					DiameterBaseInterface* inf =  mRAI->Find(this->mspByteArray.get(), avpCode);
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
			case 2825:
			{
				if(mFixedUserLocationInfoGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mFixedUserLocationInfoGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mFixedUserLocationInfoGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
				}
				}
				break;
			}
			case 2319:
			{
				if(mUserCSGInformationGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mUserCSGInformationGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mUserCSGInformationGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
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
			case 13:
			{
				if(m3GPPChargingCharacteristics != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPChargingCharacteristics->Find(this->mspByteArray.get(), avpCode);
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
			case 618:
			{
				if(mChargingInformationGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mChargingInformationGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mChargingInformationGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
				}
				}
				break;
			}
			case 1009:
			{
				if(mOnline != NULL)
				{
					DiameterBaseInterface* inf =  mOnline->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1008:
			{
				if(mOffline != NULL)
				{
					DiameterBaseInterface* inf =  mOffline->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
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
			case 2822:
			{
				if(mPresenceReportingAreaInformationGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mPresenceReportingAreaInformationGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mPresenceReportingAreaInformationGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
				}
				}
				break;
			}
			case 302:
			{
				if(mLogicalAccessID != NULL)
				{
					DiameterBaseInterface* inf =  mLogicalAccessID->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 313:
			{
				if(mPhysicalAccessID != NULL)
				{
					DiameterBaseInterface* inf =  mPhysicalAccessID->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 9010:
			{
				if(m3GPP2BSID != NULL)
				{
					DiameterBaseInterface* inf =  m3GPP2BSID->Find(this->mspByteArray.get(), avpCode);
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




void TDFSessionRequest::Display(UINT32 tab)
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
			case TDFSessionRequest_SESSIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "263" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SessionId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getSessionId()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_DRMP:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "301" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DRMP" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getDRMP()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_VENDORSPECIFICAPPLICATIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "260" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "VendorSpecificApplicationId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getVendorSpecificApplicationId()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_ORIGINHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "264" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginHost()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_ORIGINREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "296" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginRealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginRealm()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_DESTINATIONREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "283" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DestinationRealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getDestinationRealm()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_DESTINATIONHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "293" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DestinationHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getDestinationHost()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_ORIGINSTATEID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "278" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginStateId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginStateId()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_OCSUPPORTEDFEATURES:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "621" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OCSupportedFeatures" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getOCSupportedFeatures()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_SUBSCRIPTIONID:
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
			case TDFSessionRequest_SUPPORTEDFEATURES:
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
			case TDFSessionRequest_FRAMEDIPADDRESS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "8" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FramedIPAddress" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getFramedIPAddress()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_FRAMEDIPV6PREFIX:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "97" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FramedIPv6Prefix" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getFramedIPv6Prefix()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_IPCANTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1027" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "IPCANType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getIPCANType()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_RATTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1032" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RATType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getRATType()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_ANTRUSTED:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1503" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ANTrusted" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getANTrusted()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_USEREQUIPMENTINFO:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "458" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserEquipmentInfo" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getUserEquipmentInfo()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_USEREQUIPMENTINFOEXTENSION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "653" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserEquipmentInfoExtension" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getUserEquipmentInfoExtension()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_QOSINFORMATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1016" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "QoSInformation" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getQoSInformation()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_ANGWADDRESS:
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
			case TDFSessionRequest_3GPPSGSNADDRESS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "6" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPPSGSNAddress" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->get3GPPSGSNAddress()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_3GPPSGSNIPV6ADDRESS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "15" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPPSGSNIPv6Address" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->get3GPPSGSNIPv6Address()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_3GPPGGSNADDRESS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "7" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPPGGSNAddress" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->get3GPPGGSNAddress()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_3GPPGGSNIPV6ADDRESS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "16" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPPGGSNIPv6Address" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->get3GPPGGSNIPv6Address()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_3GPPSELECTIONMODE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "12" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPPSelectionMode" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->get3GPPSelectionMode()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_DYNAMICADDRESSFLAG:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2051" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DynamicAddressFlag" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getDynamicAddressFlag()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_DYNAMICADDRESSFLAGEXTENSION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2068" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DynamicAddressFlagExtension" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getDynamicAddressFlagExtension()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_PDNCONNECTIONCHARGINGID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2050" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PDNConnectionChargingID" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getPDNConnectionChargingID()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_3GPPSGSNMCCMNC:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "18" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPPSGSNMCCMNC" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->get3GPPSGSNMCCMNC()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_RAI:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "909" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RAI" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getRAI()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_3GPPUSERLOCATIONINFO:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "22" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPPUserLocationInfo" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->get3GPPUserLocationInfo()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_FIXEDUSERLOCATIONINFO:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2825" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FixedUserLocationInfo" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getFixedUserLocationInfo()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_USERCSGINFORMATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2319" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserCSGInformation" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getUserCSGInformation()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_TWANIDENTIFIER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "29" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "TWANIdentifier" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getTWANIdentifier()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_3GPPMSTIMEZONE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "23" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPPMSTimeZone" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->get3GPPMSTimeZone()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_3GPPCHARGINGCHARACTERISTICS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "13" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPPChargingCharacteristics" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->get3GPPChargingCharacteristics()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_CALLEDSTATIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "30" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CalledStationId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getCalledStationId()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_CHARGINGINFORMATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "618" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ChargingInformation" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getChargingInformation()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_ONLINE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1009" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "Online" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getOnline()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_OFFLINE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1008" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "Offline" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getOffline()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_ADCRULEINSTALL:
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
			case TDFSessionRequest_REVALIDATIONTIME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1042" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RevalidationTime" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getRevalidationTime()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_USAGEMONITORINGINFORMATION:
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
			case TDFSessionRequest_CSGINFORMATIONREPORTING:
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
			case TDFSessionRequest_EVENTTRIGGER:
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
			case TDFSessionRequest_PRESENCEREPORTINGAREAINFORMATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2822" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PresenceReportingAreaInformation" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getPresenceReportingAreaInformation()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_LOGICALACCESSID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "302" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "LogicalAccessID" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getLogicalAccessID()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_PHYSICALACCESSID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "313" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PhysicalAccessID" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getPhysicalAccessID()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_3GPP2BSID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "9010" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPP2BSID" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->get3GPP2BSID()->Display(tab+1);
			}
				break;
			case TDFSessionRequest_PROXYINFO:
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
			case TDFSessionRequest_ROUTERECORD:
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


BOOLEAN TDFSessionRequest::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<51> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case TDFSessionRequest_SESSIONID:
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
			case TDFSessionRequest_DRMP:
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
			case TDFSessionRequest_VENDORSPECIFICAPPLICATIONID:
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
			case TDFSessionRequest_ORIGINHOST:
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
			case TDFSessionRequest_ORIGINREALM:
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
			case TDFSessionRequest_DESTINATIONREALM:
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
			case TDFSessionRequest_DESTINATIONHOST:
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
			case TDFSessionRequest_ORIGINSTATEID:
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
			case TDFSessionRequest_OCSUPPORTEDFEATURES:
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
			case TDFSessionRequest_SUBSCRIPTIONID:
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
			case TDFSessionRequest_SUPPORTEDFEATURES:
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
			case TDFSessionRequest_FRAMEDIPADDRESS:
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
			case TDFSessionRequest_FRAMEDIPV6PREFIX:
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
			case TDFSessionRequest_IPCANTYPE:
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
			case TDFSessionRequest_RATTYPE:
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
			case TDFSessionRequest_ANTRUSTED:
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
			case TDFSessionRequest_USEREQUIPMENTINFO:
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
			case TDFSessionRequest_USEREQUIPMENTINFOEXTENSION:
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
			case TDFSessionRequest_QOSINFORMATION:
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
			case TDFSessionRequest_ANGWADDRESS:
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
			case TDFSessionRequest_3GPPSGSNADDRESS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 6");
				}
				else
					sprintf(lMissingAvpInfo, "%s,6", lMissingAvpInfo);
			}
				break;
			case TDFSessionRequest_3GPPSGSNIPV6ADDRESS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 15");
				}
				else
					sprintf(lMissingAvpInfo, "%s,15", lMissingAvpInfo);
			}
				break;
			case TDFSessionRequest_3GPPGGSNADDRESS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 7");
				}
				else
					sprintf(lMissingAvpInfo, "%s,7", lMissingAvpInfo);
			}
				break;
			case TDFSessionRequest_3GPPGGSNIPV6ADDRESS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 16");
				}
				else
					sprintf(lMissingAvpInfo, "%s,16", lMissingAvpInfo);
			}
				break;
			case TDFSessionRequest_3GPPSELECTIONMODE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 12");
				}
				else
					sprintf(lMissingAvpInfo, "%s,12", lMissingAvpInfo);
			}
				break;
			case TDFSessionRequest_DYNAMICADDRESSFLAG:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2051");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2051", lMissingAvpInfo);
			}
				break;
			case TDFSessionRequest_DYNAMICADDRESSFLAGEXTENSION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2068");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2068", lMissingAvpInfo);
			}
				break;
			case TDFSessionRequest_PDNCONNECTIONCHARGINGID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2050");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2050", lMissingAvpInfo);
			}
				break;
			case TDFSessionRequest_3GPPSGSNMCCMNC:
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
			case TDFSessionRequest_RAI:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 909");
				}
				else
					sprintf(lMissingAvpInfo, "%s,909", lMissingAvpInfo);
			}
				break;
			case TDFSessionRequest_3GPPUSERLOCATIONINFO:
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
			case TDFSessionRequest_FIXEDUSERLOCATIONINFO:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2825");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2825", lMissingAvpInfo);
			}
				break;
			case TDFSessionRequest_USERCSGINFORMATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2319");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2319", lMissingAvpInfo);
			}
				break;
			case TDFSessionRequest_TWANIDENTIFIER:
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
			case TDFSessionRequest_3GPPMSTIMEZONE:
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
			case TDFSessionRequest_3GPPCHARGINGCHARACTERISTICS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 13");
				}
				else
					sprintf(lMissingAvpInfo, "%s,13", lMissingAvpInfo);
			}
				break;
			case TDFSessionRequest_CALLEDSTATIONID:
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
			case TDFSessionRequest_CHARGINGINFORMATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 618");
				}
				else
					sprintf(lMissingAvpInfo, "%s,618", lMissingAvpInfo);
			}
				break;
			case TDFSessionRequest_ONLINE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1009");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1009", lMissingAvpInfo);
			}
				break;
			case TDFSessionRequest_OFFLINE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1008");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1008", lMissingAvpInfo);
			}
				break;
			case TDFSessionRequest_ADCRULEINSTALL:
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
			case TDFSessionRequest_REVALIDATIONTIME:
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
			case TDFSessionRequest_USAGEMONITORINGINFORMATION:
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
			case TDFSessionRequest_CSGINFORMATIONREPORTING:
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
			case TDFSessionRequest_EVENTTRIGGER:
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
			case TDFSessionRequest_PRESENCEREPORTINGAREAINFORMATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2822");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2822", lMissingAvpInfo);
			}
				break;
			case TDFSessionRequest_LOGICALACCESSID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 302");
				}
				else
					sprintf(lMissingAvpInfo, "%s,302", lMissingAvpInfo);
			}
				break;
			case TDFSessionRequest_PHYSICALACCESSID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 313");
				}
				else
					sprintf(lMissingAvpInfo, "%s,313", lMissingAvpInfo);
			}
				break;
			case TDFSessionRequest_3GPP2BSID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 9010");
				}
				else
					sprintf(lMissingAvpInfo, "%s,9010", lMissingAvpInfo);
			}
				break;
			case TDFSessionRequest_PROXYINFO:
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
			case TDFSessionRequest_ROUTERECORD:
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
