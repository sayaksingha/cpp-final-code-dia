#ifndef SD_TDFSESSIONREQUEST_H
#define SD_TDFSESSIONREQUEST_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/DRMP.h"
#include "sd/include/VendorSpecificApplicationId.h"
#include "sd/include/OCSupportedFeatures.h"
#include "sd/include/SubscriptionId.h"
#include "sd/include/SupportedFeatures.h"
#include "sd/include/IPCANType.h"
#include "sd/include/RATType.h"
#include "sd/include/ANTrusted.h"
#include "sd/include/UserEquipmentInfo.h"
#include "sd/include/UserEquipmentInfoExtension.h"
#include "sd/include/QoSInformation.h"
#include "sd/include/DynamicAddressFlag.h"
#include "sd/include/DynamicAddressFlagExtension.h"
#include "sd/include/FixedUserLocationInfo.h"
#include "sd/include/UserCSGInformation.h"
#include "sd/include/ChargingInformation.h"
#include "sd/include/Online.h"
#include "sd/include/Offline.h"
#include "sd/include/ADCRuleInstall.h"
#include "sd/include/UsageMonitoringInformation.h"
#include "sd/include/CSGInformationReporting.h"
#include "sd/include/EventTrigger.h"
#include "sd/include/PresenceReportingAreaInformation.h"
#include "sd/include/ProxyInfo.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace SD{
typedef enum _tags_TDFSessionRequest
{
	TDFSessionRequest_SESSIONID	= 0,
	TDFSessionRequest_DRMP	= 1,
	TDFSessionRequest_VENDORSPECIFICAPPLICATIONID	= 2,
	TDFSessionRequest_ORIGINHOST	= 3,
	TDFSessionRequest_ORIGINREALM	= 4,
	TDFSessionRequest_DESTINATIONREALM	= 5,
	TDFSessionRequest_DESTINATIONHOST	= 6,
	TDFSessionRequest_ORIGINSTATEID	= 7,
	TDFSessionRequest_OCSUPPORTEDFEATURES	= 8,
	TDFSessionRequest_SUBSCRIPTIONID	= 9,
	TDFSessionRequest_SUPPORTEDFEATURES	= 10,
	TDFSessionRequest_FRAMEDIPADDRESS	= 11,
	TDFSessionRequest_FRAMEDIPV6PREFIX	= 12,
	TDFSessionRequest_IPCANTYPE	= 13,
	TDFSessionRequest_RATTYPE	= 14,
	TDFSessionRequest_ANTRUSTED	= 15,
	TDFSessionRequest_USEREQUIPMENTINFO	= 16,
	TDFSessionRequest_USEREQUIPMENTINFOEXTENSION	= 17,
	TDFSessionRequest_QOSINFORMATION	= 18,
	TDFSessionRequest_ANGWADDRESS	= 19,
	TDFSessionRequest_3GPPSGSNADDRESS	= 20,
	TDFSessionRequest_3GPPSGSNIPV6ADDRESS	= 21,
	TDFSessionRequest_3GPPGGSNADDRESS	= 22,
	TDFSessionRequest_3GPPGGSNIPV6ADDRESS	= 23,
	TDFSessionRequest_3GPPSELECTIONMODE	= 24,
	TDFSessionRequest_DYNAMICADDRESSFLAG	= 25,
	TDFSessionRequest_DYNAMICADDRESSFLAGEXTENSION	= 26,
	TDFSessionRequest_PDNCONNECTIONCHARGINGID	= 27,
	TDFSessionRequest_3GPPSGSNMCCMNC	= 28,
	TDFSessionRequest_RAI	= 29,
	TDFSessionRequest_3GPPUSERLOCATIONINFO	= 30,
	TDFSessionRequest_FIXEDUSERLOCATIONINFO	= 31,
	TDFSessionRequest_USERCSGINFORMATION	= 32,
	TDFSessionRequest_TWANIDENTIFIER	= 33,
	TDFSessionRequest_3GPPMSTIMEZONE	= 34,
	TDFSessionRequest_3GPPCHARGINGCHARACTERISTICS	= 35,
	TDFSessionRequest_CALLEDSTATIONID	= 36,
	TDFSessionRequest_CHARGINGINFORMATION	= 37,
	TDFSessionRequest_ONLINE	= 38,
	TDFSessionRequest_OFFLINE	= 39,
	TDFSessionRequest_ADCRULEINSTALL	= 40,
	TDFSessionRequest_REVALIDATIONTIME	= 41,
	TDFSessionRequest_USAGEMONITORINGINFORMATION	= 42,
	TDFSessionRequest_CSGINFORMATIONREPORTING	= 43,
	TDFSessionRequest_EVENTTRIGGER	= 44,
	TDFSessionRequest_PRESENCEREPORTINGAREAINFORMATION	= 45,
	TDFSessionRequest_LOGICALACCESSID	= 46,
	TDFSessionRequest_PHYSICALACCESSID	= 47,
	TDFSessionRequest_3GPP2BSID	= 48,
	TDFSessionRequest_PROXYINFO	= 49,
	TDFSessionRequest_ROUTERECORD	= 50,
}TDFSessionRequest_tags;

		//! Class Definition
		/*!		ClassName is TDFSessionRequest
		*/
class TDFSessionRequest : public DiameterBase 
{
	private:

		bitset<51> mTagsPresent;

		bitset<51> mMandatoryAvpCheckVal;

		bitset<51> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		DRMP*		mDRMP;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		OctetString*		mDestinationRealm;

		OctetString*		mDestinationHost;

		Unsigned32*		mOriginStateId;

		OctetString*		mFramedIPAddress;

		OctetString*		mFramedIPv6Prefix;

		IPCANType*		mIPCANType;

		RATType*		mRATType;

		ANTrusted*		mANTrusted;

		list<Address*>* 		mANGWAddressList;

		list<Address*>::iterator 		mANGWAddressIterator;

		OctetString*		m3GPPSGSNAddress;

		OctetString*		m3GPPSGSNIPv6Address;

		OctetString*		m3GPPGGSNAddress;

		OctetString*		m3GPPGGSNIPv6Address;

		OctetString*		m3GPPSelectionMode;

		DynamicAddressFlag*		mDynamicAddressFlag;

		DynamicAddressFlagExtension*		mDynamicAddressFlagExtension;

		Unsigned32*		mPDNConnectionChargingID;

		OctetString*		m3GPPSGSNMCCMNC;

		OctetString*		mRAI;

		OctetString*		m3GPPUserLocationInfo;

		OctetString*		mTWANIdentifier;

		OctetString*		m3GPPMSTimeZone;

		OctetString*		m3GPPChargingCharacteristics;

		OctetString*		mCalledStationId;

		Online*		mOnline;

		Offline*		mOffline;

		Time*		mRevalidationTime;

		list<CSGInformationReporting*>* 		mCSGInformationReportingList;

		list<CSGInformationReporting*>::iterator 		mCSGInformationReportingIterator;

		list<EventTrigger*>* 		mEventTriggerList;

		list<EventTrigger*>::iterator 		mEventTriggerIterator;

		OctetString*		mLogicalAccessID;

		OctetString*		mPhysicalAccessID;

		OctetString*		m3GPP2BSID;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;




		VendorSpecificApplicationId*	mVendorSpecificApplicationIdGrp;






		OCSupportedFeatures*	mOCSupportedFeaturesGrp;

		list<SubscriptionId*>*	mSubscriptionIdGrpList;
		list<SubscriptionId*>::iterator	mSubscriptionIdGrpIterator;

		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;






		UserEquipmentInfo*	mUserEquipmentInfoGrp;

		UserEquipmentInfoExtension*	mUserEquipmentInfoExtensionGrp;

		QoSInformation*	mQoSInformationGrp;













		FixedUserLocationInfo*	mFixedUserLocationInfoGrp;

		UserCSGInformation*	mUserCSGInformationGrp;





		ChargingInformation*	mChargingInformationGrp;



		list<ADCRuleInstall*>*	mADCRuleInstallGrpList;
		list<ADCRuleInstall*>::iterator	mADCRuleInstallGrpIterator;


		list<UsageMonitoringInformation*>*	mUsageMonitoringInformationGrpList;
		list<UsageMonitoringInformation*>::iterator	mUsageMonitoringInformationGrpIterator;



		PresenceReportingAreaInformation*	mPresenceReportingAreaInformationGrp;




		list<SD::ProxyInfo*>*	mProxyInfoGrpList;
		list<SD::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		TDFSessionRequest();

		TDFSessionRequest(const TDFSessionRequest &objTDFSessionRequest) {

		mTagsPresent = objTDFSessionRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objTDFSessionRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objTDFSessionRequest.mMandatoryAvpSetVal;

		mTag = objTDFSessionRequest.mTag;

		mDecodeFlag = objTDFSessionRequest.mDecodeFlag;

		if(objTDFSessionRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objTDFSessionRequest.mSessionId));

		if(objTDFSessionRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objTDFSessionRequest.mDRMP));

		if(objTDFSessionRequest.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objTDFSessionRequest.mVendorSpecificApplicationIdGrp);
		 }
		if(objTDFSessionRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objTDFSessionRequest.mOriginHost));

		if(objTDFSessionRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objTDFSessionRequest.mOriginRealm));

		if(objTDFSessionRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objTDFSessionRequest.mDestinationRealm));

		if(objTDFSessionRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objTDFSessionRequest.mDestinationHost));

		if(objTDFSessionRequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objTDFSessionRequest.mOriginStateId));

		if(objTDFSessionRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objTDFSessionRequest.mOCSupportedFeaturesGrp);
		 }
		if(objTDFSessionRequest.mSubscriptionIdGrpList != NULL)
		 {
		 mSubscriptionIdGrpList = new list<SubscriptionId*>;
		 for( auto element : *objTDFSessionRequest.mSubscriptionIdGrpList)
		 {
				 SubscriptionId *lSubscriptionId =  new SubscriptionId(*element);
				 mSubscriptionIdGrpList->push_back(lSubscriptionId);
		 }
		 }
		if(objTDFSessionRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objTDFSessionRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objTDFSessionRequest.mFramedIPAddress != NULL)
		mFramedIPAddress = new OctetString(*(objTDFSessionRequest.mFramedIPAddress));

		if(objTDFSessionRequest.mFramedIPv6Prefix != NULL)
		mFramedIPv6Prefix = new OctetString(*(objTDFSessionRequest.mFramedIPv6Prefix));

		if(objTDFSessionRequest.mIPCANType != NULL)
		mIPCANType = new IPCANType(*(objTDFSessionRequest.mIPCANType));

		if(objTDFSessionRequest.mRATType != NULL)
		mRATType = new RATType(*(objTDFSessionRequest.mRATType));

		if(objTDFSessionRequest.mANTrusted != NULL)
		mANTrusted = new ANTrusted(*(objTDFSessionRequest.mANTrusted));

		if(objTDFSessionRequest.mUserEquipmentInfoGrp != NULL)
		 {
				 mUserEquipmentInfoGrp =  new UserEquipmentInfo(*objTDFSessionRequest.mUserEquipmentInfoGrp);
		 }
		if(objTDFSessionRequest.mUserEquipmentInfoExtensionGrp != NULL)
		 {
				 mUserEquipmentInfoExtensionGrp =  new UserEquipmentInfoExtension(*objTDFSessionRequest.mUserEquipmentInfoExtensionGrp);
		 }
		if(objTDFSessionRequest.mQoSInformationGrp != NULL)
		 {
				 mQoSInformationGrp =  new QoSInformation(*objTDFSessionRequest.mQoSInformationGrp);
		 }
		if(objTDFSessionRequest.m3GPPSGSNAddress != NULL)
		m3GPPSGSNAddress = new OctetString(*(objTDFSessionRequest.m3GPPSGSNAddress));

		if(objTDFSessionRequest.m3GPPSGSNIPv6Address != NULL)
		m3GPPSGSNIPv6Address = new OctetString(*(objTDFSessionRequest.m3GPPSGSNIPv6Address));

		if(objTDFSessionRequest.m3GPPGGSNAddress != NULL)
		m3GPPGGSNAddress = new OctetString(*(objTDFSessionRequest.m3GPPGGSNAddress));

		if(objTDFSessionRequest.m3GPPGGSNIPv6Address != NULL)
		m3GPPGGSNIPv6Address = new OctetString(*(objTDFSessionRequest.m3GPPGGSNIPv6Address));

		if(objTDFSessionRequest.m3GPPSelectionMode != NULL)
		m3GPPSelectionMode = new OctetString(*(objTDFSessionRequest.m3GPPSelectionMode));

		if(objTDFSessionRequest.mDynamicAddressFlag != NULL)
		mDynamicAddressFlag = new DynamicAddressFlag(*(objTDFSessionRequest.mDynamicAddressFlag));

		if(objTDFSessionRequest.mDynamicAddressFlagExtension != NULL)
		mDynamicAddressFlagExtension = new DynamicAddressFlagExtension(*(objTDFSessionRequest.mDynamicAddressFlagExtension));

		if(objTDFSessionRequest.mPDNConnectionChargingID != NULL)
		mPDNConnectionChargingID = new Unsigned32(*(objTDFSessionRequest.mPDNConnectionChargingID));

		if(objTDFSessionRequest.m3GPPSGSNMCCMNC != NULL)
		m3GPPSGSNMCCMNC = new OctetString(*(objTDFSessionRequest.m3GPPSGSNMCCMNC));

		if(objTDFSessionRequest.mRAI != NULL)
		mRAI = new OctetString(*(objTDFSessionRequest.mRAI));

		if(objTDFSessionRequest.m3GPPUserLocationInfo != NULL)
		m3GPPUserLocationInfo = new OctetString(*(objTDFSessionRequest.m3GPPUserLocationInfo));

		if(objTDFSessionRequest.mFixedUserLocationInfoGrp != NULL)
		 {
				 mFixedUserLocationInfoGrp =  new FixedUserLocationInfo(*objTDFSessionRequest.mFixedUserLocationInfoGrp);
		 }
		if(objTDFSessionRequest.mUserCSGInformationGrp != NULL)
		 {
				 mUserCSGInformationGrp =  new UserCSGInformation(*objTDFSessionRequest.mUserCSGInformationGrp);
		 }
		if(objTDFSessionRequest.mTWANIdentifier != NULL)
		mTWANIdentifier = new OctetString(*(objTDFSessionRequest.mTWANIdentifier));

		if(objTDFSessionRequest.m3GPPMSTimeZone != NULL)
		m3GPPMSTimeZone = new OctetString(*(objTDFSessionRequest.m3GPPMSTimeZone));

		if(objTDFSessionRequest.m3GPPChargingCharacteristics != NULL)
		m3GPPChargingCharacteristics = new OctetString(*(objTDFSessionRequest.m3GPPChargingCharacteristics));

		if(objTDFSessionRequest.mCalledStationId != NULL)
		mCalledStationId = new OctetString(*(objTDFSessionRequest.mCalledStationId));

		if(objTDFSessionRequest.mChargingInformationGrp != NULL)
		 {
				 mChargingInformationGrp =  new ChargingInformation(*objTDFSessionRequest.mChargingInformationGrp);
		 }
		if(objTDFSessionRequest.mOnline != NULL)
		mOnline = new Online(*(objTDFSessionRequest.mOnline));

		if(objTDFSessionRequest.mOffline != NULL)
		mOffline = new Offline(*(objTDFSessionRequest.mOffline));

		if(objTDFSessionRequest.mADCRuleInstallGrpList != NULL)
		 {
		 mADCRuleInstallGrpList = new list<ADCRuleInstall*>;
		 for( auto element : *objTDFSessionRequest.mADCRuleInstallGrpList)
		 {
				 ADCRuleInstall *lADCRuleInstall =  new ADCRuleInstall(*element);
				 mADCRuleInstallGrpList->push_back(lADCRuleInstall);
		 }
		 }
		if(objTDFSessionRequest.mRevalidationTime != NULL)
		mRevalidationTime = new Time(*(objTDFSessionRequest.mRevalidationTime));

		if(objTDFSessionRequest.mUsageMonitoringInformationGrpList != NULL)
		 {
		 mUsageMonitoringInformationGrpList = new list<UsageMonitoringInformation*>;
		 for( auto element : *objTDFSessionRequest.mUsageMonitoringInformationGrpList)
		 {
				 UsageMonitoringInformation *lUsageMonitoringInformation =  new UsageMonitoringInformation(*element);
				 mUsageMonitoringInformationGrpList->push_back(lUsageMonitoringInformation);
		 }
		 }
		if(objTDFSessionRequest.mPresenceReportingAreaInformationGrp != NULL)
		 {
				 mPresenceReportingAreaInformationGrp =  new PresenceReportingAreaInformation(*objTDFSessionRequest.mPresenceReportingAreaInformationGrp);
		 }
		if(objTDFSessionRequest.mLogicalAccessID != NULL)
		mLogicalAccessID = new OctetString(*(objTDFSessionRequest.mLogicalAccessID));

		if(objTDFSessionRequest.mPhysicalAccessID != NULL)
		mPhysicalAccessID = new OctetString(*(objTDFSessionRequest.mPhysicalAccessID));

		if(objTDFSessionRequest.m3GPP2BSID != NULL)
		m3GPP2BSID = new OctetString(*(objTDFSessionRequest.m3GPP2BSID));

		if(objTDFSessionRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SD::ProxyInfo*>;
		 for( auto element : *objTDFSessionRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const TDFSessionRequest &objTDFSessionRequest) {

		mTagsPresent = objTDFSessionRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objTDFSessionRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objTDFSessionRequest.mMandatoryAvpSetVal;

		mTag = objTDFSessionRequest.mTag;

		mDecodeFlag = objTDFSessionRequest.mDecodeFlag;

		if(objTDFSessionRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objTDFSessionRequest.mSessionId));

		if(objTDFSessionRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objTDFSessionRequest.mDRMP));

		if(objTDFSessionRequest.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objTDFSessionRequest.mVendorSpecificApplicationIdGrp);
		 }
		if(objTDFSessionRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objTDFSessionRequest.mOriginHost));

		if(objTDFSessionRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objTDFSessionRequest.mOriginRealm));

		if(objTDFSessionRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objTDFSessionRequest.mDestinationRealm));

		if(objTDFSessionRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objTDFSessionRequest.mDestinationHost));

		if(objTDFSessionRequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objTDFSessionRequest.mOriginStateId));

		if(objTDFSessionRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objTDFSessionRequest.mOCSupportedFeaturesGrp);
		 }
		if(objTDFSessionRequest.mSubscriptionIdGrpList != NULL)
		 {
		 mSubscriptionIdGrpList = new list<SubscriptionId*>;
		 for( auto element : *objTDFSessionRequest.mSubscriptionIdGrpList)
		 {
				 SubscriptionId *lSubscriptionId =  new SubscriptionId(*element);
				 mSubscriptionIdGrpList->push_back(lSubscriptionId);
		 }
		 }
		if(objTDFSessionRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objTDFSessionRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objTDFSessionRequest.mFramedIPAddress != NULL)
		mFramedIPAddress = new OctetString(*(objTDFSessionRequest.mFramedIPAddress));

		if(objTDFSessionRequest.mFramedIPv6Prefix != NULL)
		mFramedIPv6Prefix = new OctetString(*(objTDFSessionRequest.mFramedIPv6Prefix));

		if(objTDFSessionRequest.mIPCANType != NULL)
		mIPCANType = new IPCANType(*(objTDFSessionRequest.mIPCANType));

		if(objTDFSessionRequest.mRATType != NULL)
		mRATType = new RATType(*(objTDFSessionRequest.mRATType));

		if(objTDFSessionRequest.mANTrusted != NULL)
		mANTrusted = new ANTrusted(*(objTDFSessionRequest.mANTrusted));

		if(objTDFSessionRequest.mUserEquipmentInfoGrp != NULL)
		 {
				 mUserEquipmentInfoGrp =  new UserEquipmentInfo(*objTDFSessionRequest.mUserEquipmentInfoGrp);
		 }
		if(objTDFSessionRequest.mUserEquipmentInfoExtensionGrp != NULL)
		 {
				 mUserEquipmentInfoExtensionGrp =  new UserEquipmentInfoExtension(*objTDFSessionRequest.mUserEquipmentInfoExtensionGrp);
		 }
		if(objTDFSessionRequest.mQoSInformationGrp != NULL)
		 {
				 mQoSInformationGrp =  new QoSInformation(*objTDFSessionRequest.mQoSInformationGrp);
		 }
		if(objTDFSessionRequest.m3GPPSGSNAddress != NULL)
		m3GPPSGSNAddress = new OctetString(*(objTDFSessionRequest.m3GPPSGSNAddress));

		if(objTDFSessionRequest.m3GPPSGSNIPv6Address != NULL)
		m3GPPSGSNIPv6Address = new OctetString(*(objTDFSessionRequest.m3GPPSGSNIPv6Address));

		if(objTDFSessionRequest.m3GPPGGSNAddress != NULL)
		m3GPPGGSNAddress = new OctetString(*(objTDFSessionRequest.m3GPPGGSNAddress));

		if(objTDFSessionRequest.m3GPPGGSNIPv6Address != NULL)
		m3GPPGGSNIPv6Address = new OctetString(*(objTDFSessionRequest.m3GPPGGSNIPv6Address));

		if(objTDFSessionRequest.m3GPPSelectionMode != NULL)
		m3GPPSelectionMode = new OctetString(*(objTDFSessionRequest.m3GPPSelectionMode));

		if(objTDFSessionRequest.mDynamicAddressFlag != NULL)
		mDynamicAddressFlag = new DynamicAddressFlag(*(objTDFSessionRequest.mDynamicAddressFlag));

		if(objTDFSessionRequest.mDynamicAddressFlagExtension != NULL)
		mDynamicAddressFlagExtension = new DynamicAddressFlagExtension(*(objTDFSessionRequest.mDynamicAddressFlagExtension));

		if(objTDFSessionRequest.mPDNConnectionChargingID != NULL)
		mPDNConnectionChargingID = new Unsigned32(*(objTDFSessionRequest.mPDNConnectionChargingID));

		if(objTDFSessionRequest.m3GPPSGSNMCCMNC != NULL)
		m3GPPSGSNMCCMNC = new OctetString(*(objTDFSessionRequest.m3GPPSGSNMCCMNC));

		if(objTDFSessionRequest.mRAI != NULL)
		mRAI = new OctetString(*(objTDFSessionRequest.mRAI));

		if(objTDFSessionRequest.m3GPPUserLocationInfo != NULL)
		m3GPPUserLocationInfo = new OctetString(*(objTDFSessionRequest.m3GPPUserLocationInfo));

		if(objTDFSessionRequest.mFixedUserLocationInfoGrp != NULL)
		 {
				 mFixedUserLocationInfoGrp =  new FixedUserLocationInfo(*objTDFSessionRequest.mFixedUserLocationInfoGrp);
		 }
		if(objTDFSessionRequest.mUserCSGInformationGrp != NULL)
		 {
				 mUserCSGInformationGrp =  new UserCSGInformation(*objTDFSessionRequest.mUserCSGInformationGrp);
		 }
		if(objTDFSessionRequest.mTWANIdentifier != NULL)
		mTWANIdentifier = new OctetString(*(objTDFSessionRequest.mTWANIdentifier));

		if(objTDFSessionRequest.m3GPPMSTimeZone != NULL)
		m3GPPMSTimeZone = new OctetString(*(objTDFSessionRequest.m3GPPMSTimeZone));

		if(objTDFSessionRequest.m3GPPChargingCharacteristics != NULL)
		m3GPPChargingCharacteristics = new OctetString(*(objTDFSessionRequest.m3GPPChargingCharacteristics));

		if(objTDFSessionRequest.mCalledStationId != NULL)
		mCalledStationId = new OctetString(*(objTDFSessionRequest.mCalledStationId));

		if(objTDFSessionRequest.mChargingInformationGrp != NULL)
		 {
				 mChargingInformationGrp =  new ChargingInformation(*objTDFSessionRequest.mChargingInformationGrp);
		 }
		if(objTDFSessionRequest.mOnline != NULL)
		mOnline = new Online(*(objTDFSessionRequest.mOnline));

		if(objTDFSessionRequest.mOffline != NULL)
		mOffline = new Offline(*(objTDFSessionRequest.mOffline));

		if(objTDFSessionRequest.mADCRuleInstallGrpList != NULL)
		 {
		 mADCRuleInstallGrpList = new list<ADCRuleInstall*>;
		 for( auto element : *objTDFSessionRequest.mADCRuleInstallGrpList)
		 {
				 ADCRuleInstall *lADCRuleInstall =  new ADCRuleInstall(*element);
				 mADCRuleInstallGrpList->push_back(lADCRuleInstall);
		 }
		 }
		if(objTDFSessionRequest.mRevalidationTime != NULL)
		mRevalidationTime = new Time(*(objTDFSessionRequest.mRevalidationTime));

		if(objTDFSessionRequest.mUsageMonitoringInformationGrpList != NULL)
		 {
		 mUsageMonitoringInformationGrpList = new list<UsageMonitoringInformation*>;
		 for( auto element : *objTDFSessionRequest.mUsageMonitoringInformationGrpList)
		 {
				 UsageMonitoringInformation *lUsageMonitoringInformation =  new UsageMonitoringInformation(*element);
				 mUsageMonitoringInformationGrpList->push_back(lUsageMonitoringInformation);
		 }
		 }
		if(objTDFSessionRequest.mPresenceReportingAreaInformationGrp != NULL)
		 {
				 mPresenceReportingAreaInformationGrp =  new PresenceReportingAreaInformation(*objTDFSessionRequest.mPresenceReportingAreaInformationGrp);
		 }
		if(objTDFSessionRequest.mLogicalAccessID != NULL)
		mLogicalAccessID = new OctetString(*(objTDFSessionRequest.mLogicalAccessID));

		if(objTDFSessionRequest.mPhysicalAccessID != NULL)
		mPhysicalAccessID = new OctetString(*(objTDFSessionRequest.mPhysicalAccessID));

		if(objTDFSessionRequest.m3GPP2BSID != NULL)
		m3GPP2BSID = new OctetString(*(objTDFSessionRequest.m3GPP2BSID));

		if(objTDFSessionRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SD::ProxyInfo*>;
		 for( auto element : *objTDFSessionRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~TDFSessionRequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype TDFSessionRequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype TDFSessionRequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype TDFSessionRequest
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype TDFSessionRequest
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		VendorSpecificApplicationId* getVendorSpecificApplicationId();

		VendorSpecificApplicationId* setVendorSpecificApplicationId();

		void resetVendorSpecificApplicationId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype TDFSessionRequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype TDFSessionRequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype TDFSessionRequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype TDFSessionRequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationRealm for datatype TDFSessionRequest
		*/
		OctetString* setDestinationRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationRealm for datatype TDFSessionRequest
		*/
		void resetDestinationRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationRealm for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationHost for datatype TDFSessionRequest
		*/
		OctetString* setDestinationHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationHost for datatype TDFSessionRequest
		*/
		void resetDestinationHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationHost for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationHost();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype TDFSessionRequest
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype TDFSessionRequest
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		OCSupportedFeatures* getOCSupportedFeatures();

		OCSupportedFeatures* setOCSupportedFeatures();

		void resetOCSupportedFeatures();

		list<SubscriptionId*>* getSubscriptionIdGrpList();

		list<SubscriptionId*>* setSubscriptionIdGrpList();

		void resetSubscriptionIdGrpList();

		list<SupportedFeatures*>* getSupportedFeaturesGrpList();

		list<SupportedFeatures*>* setSupportedFeaturesGrpList();

		void resetSupportedFeaturesGrpList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument FramedIPAddress for datatype TDFSessionRequest
		*/
		OctetString* setFramedIPAddress();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FramedIPAddress for datatype TDFSessionRequest
		*/
		void resetFramedIPAddress();

		//!Function to get values
		/*!		Function to get OctetString type of argument FramedIPAddress for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getFramedIPAddress();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument FramedIPv6Prefix for datatype TDFSessionRequest
		*/
		OctetString* setFramedIPv6Prefix();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FramedIPv6Prefix for datatype TDFSessionRequest
		*/
		void resetFramedIPv6Prefix();

		//!Function to get values
		/*!		Function to get OctetString type of argument FramedIPv6Prefix for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getFramedIPv6Prefix();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument IPCANType for datatype TDFSessionRequest
		*/
		IPCANType* setIPCANType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument IPCANType for datatype TDFSessionRequest
		*/
		void resetIPCANType();

		//!Function to get values
		/*!		Function to get IPCANType type of argument IPCANType for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		IPCANType* getIPCANType();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument RATType for datatype TDFSessionRequest
		*/
		RATType* setRATType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RATType for datatype TDFSessionRequest
		*/
		void resetRATType();

		//!Function to get values
		/*!		Function to get RATType type of argument RATType for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		RATType* getRATType();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument ANTrusted for datatype TDFSessionRequest
		*/
		ANTrusted* setANTrusted();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ANTrusted for datatype TDFSessionRequest
		*/
		void resetANTrusted();

		//!Function to get values
		/*!		Function to get ANTrusted type of argument ANTrusted for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		ANTrusted* getANTrusted();

		UserEquipmentInfo* getUserEquipmentInfo();

		UserEquipmentInfo* setUserEquipmentInfo();

		void resetUserEquipmentInfo();

		UserEquipmentInfoExtension* getUserEquipmentInfoExtension();

		UserEquipmentInfoExtension* setUserEquipmentInfoExtension();

		void resetUserEquipmentInfoExtension();

		QoSInformation* getQoSInformation();

		QoSInformation* setQoSInformation();

		void resetQoSInformation();

		list<Address*>* getANGWAddressList();

		list<Address*>* setANGWAddressList();

		void resetANGWAddressList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPSGSNAddress for datatype TDFSessionRequest
		*/
		OctetString* set3GPPSGSNAddress();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPSGSNAddress for datatype TDFSessionRequest
		*/
		void reset3GPPSGSNAddress();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPSGSNAddress for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPSGSNAddress();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPSGSNIPv6Address for datatype TDFSessionRequest
		*/
		OctetString* set3GPPSGSNIPv6Address();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPSGSNIPv6Address for datatype TDFSessionRequest
		*/
		void reset3GPPSGSNIPv6Address();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPSGSNIPv6Address for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPSGSNIPv6Address();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPGGSNAddress for datatype TDFSessionRequest
		*/
		OctetString* set3GPPGGSNAddress();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPGGSNAddress for datatype TDFSessionRequest
		*/
		void reset3GPPGGSNAddress();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPGGSNAddress for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPGGSNAddress();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPGGSNIPv6Address for datatype TDFSessionRequest
		*/
		OctetString* set3GPPGGSNIPv6Address();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPGGSNIPv6Address for datatype TDFSessionRequest
		*/
		void reset3GPPGGSNIPv6Address();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPGGSNIPv6Address for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPGGSNIPv6Address();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPSelectionMode for datatype TDFSessionRequest
		*/
		OctetString* set3GPPSelectionMode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPSelectionMode for datatype TDFSessionRequest
		*/
		void reset3GPPSelectionMode();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPSelectionMode for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPSelectionMode();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DynamicAddressFlag for datatype TDFSessionRequest
		*/
		DynamicAddressFlag* setDynamicAddressFlag();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DynamicAddressFlag for datatype TDFSessionRequest
		*/
		void resetDynamicAddressFlag();

		//!Function to get values
		/*!		Function to get DynamicAddressFlag type of argument DynamicAddressFlag for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		DynamicAddressFlag* getDynamicAddressFlag();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DynamicAddressFlagExtension for datatype TDFSessionRequest
		*/
		DynamicAddressFlagExtension* setDynamicAddressFlagExtension();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DynamicAddressFlagExtension for datatype TDFSessionRequest
		*/
		void resetDynamicAddressFlagExtension();

		//!Function to get values
		/*!		Function to get DynamicAddressFlagExtension type of argument DynamicAddressFlagExtension for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		DynamicAddressFlagExtension* getDynamicAddressFlagExtension();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument PDNConnectionChargingID for datatype TDFSessionRequest
		*/
		Unsigned32* setPDNConnectionChargingID();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PDNConnectionChargingID for datatype TDFSessionRequest
		*/
		void resetPDNConnectionChargingID();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument PDNConnectionChargingID for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getPDNConnectionChargingID();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPSGSNMCCMNC for datatype TDFSessionRequest
		*/
		OctetString* set3GPPSGSNMCCMNC();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPSGSNMCCMNC for datatype TDFSessionRequest
		*/
		void reset3GPPSGSNMCCMNC();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPSGSNMCCMNC for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPSGSNMCCMNC();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument RAI for datatype TDFSessionRequest
		*/
		OctetString* setRAI();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RAI for datatype TDFSessionRequest
		*/
		void resetRAI();

		//!Function to get values
		/*!		Function to get OctetString type of argument RAI for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getRAI();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPUserLocationInfo for datatype TDFSessionRequest
		*/
		OctetString* set3GPPUserLocationInfo();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPUserLocationInfo for datatype TDFSessionRequest
		*/
		void reset3GPPUserLocationInfo();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPUserLocationInfo for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPUserLocationInfo();

		FixedUserLocationInfo* getFixedUserLocationInfo();

		FixedUserLocationInfo* setFixedUserLocationInfo();

		void resetFixedUserLocationInfo();

		UserCSGInformation* getUserCSGInformation();

		UserCSGInformation* setUserCSGInformation();

		void resetUserCSGInformation();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument TWANIdentifier for datatype TDFSessionRequest
		*/
		OctetString* setTWANIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument TWANIdentifier for datatype TDFSessionRequest
		*/
		void resetTWANIdentifier();

		//!Function to get values
		/*!		Function to get OctetString type of argument TWANIdentifier for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getTWANIdentifier();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPMSTimeZone for datatype TDFSessionRequest
		*/
		OctetString* set3GPPMSTimeZone();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPMSTimeZone for datatype TDFSessionRequest
		*/
		void reset3GPPMSTimeZone();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPMSTimeZone for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPMSTimeZone();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPChargingCharacteristics for datatype TDFSessionRequest
		*/
		OctetString* set3GPPChargingCharacteristics();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPChargingCharacteristics for datatype TDFSessionRequest
		*/
		void reset3GPPChargingCharacteristics();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPChargingCharacteristics for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPChargingCharacteristics();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument CalledStationId for datatype TDFSessionRequest
		*/
		OctetString* setCalledStationId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CalledStationId for datatype TDFSessionRequest
		*/
		void resetCalledStationId();

		//!Function to get values
		/*!		Function to get OctetString type of argument CalledStationId for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getCalledStationId();

		ChargingInformation* getChargingInformation();

		ChargingInformation* setChargingInformation();

		void resetChargingInformation();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument Online for datatype TDFSessionRequest
		*/
		Online* setOnline();

		//! Function to reset 
		/*!		Function to reset NULL type of argument Online for datatype TDFSessionRequest
		*/
		void resetOnline();

		//!Function to get values
		/*!		Function to get Online type of argument Online for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		Online* getOnline();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument Offline for datatype TDFSessionRequest
		*/
		Offline* setOffline();

		//! Function to reset 
		/*!		Function to reset NULL type of argument Offline for datatype TDFSessionRequest
		*/
		void resetOffline();

		//!Function to get values
		/*!		Function to get Offline type of argument Offline for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		Offline* getOffline();

		list<ADCRuleInstall*>* getADCRuleInstallGrpList();

		list<ADCRuleInstall*>* setADCRuleInstallGrpList();

		void resetADCRuleInstallGrpList();

		//!Function to set values
		/*!		Function to set the recent Time type of argument RevalidationTime for datatype TDFSessionRequest
		*/
		Time* setRevalidationTime();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RevalidationTime for datatype TDFSessionRequest
		*/
		void resetRevalidationTime();

		//!Function to get values
		/*!		Function to get Time type of argument RevalidationTime for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		Time* getRevalidationTime();

		list<UsageMonitoringInformation*>* getUsageMonitoringInformationGrpList();

		list<UsageMonitoringInformation*>* setUsageMonitoringInformationGrpList();

		void resetUsageMonitoringInformationGrpList();

		list<CSGInformationReporting*>* getCSGInformationReportingList();

		list<CSGInformationReporting*>* setCSGInformationReportingList();

		void resetCSGInformationReportingList();

		list<EventTrigger*>* getEventTriggerList();

		list<EventTrigger*>* setEventTriggerList();

		void resetEventTriggerList();

		PresenceReportingAreaInformation* getPresenceReportingAreaInformation();

		PresenceReportingAreaInformation* setPresenceReportingAreaInformation();

		void resetPresenceReportingAreaInformation();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument LogicalAccessID for datatype TDFSessionRequest
		*/
		OctetString* setLogicalAccessID();

		//! Function to reset 
		/*!		Function to reset NULL type of argument LogicalAccessID for datatype TDFSessionRequest
		*/
		void resetLogicalAccessID();

		//!Function to get values
		/*!		Function to get OctetString type of argument LogicalAccessID for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getLogicalAccessID();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument PhysicalAccessID for datatype TDFSessionRequest
		*/
		OctetString* setPhysicalAccessID();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PhysicalAccessID for datatype TDFSessionRequest
		*/
		void resetPhysicalAccessID();

		//!Function to get values
		/*!		Function to get OctetString type of argument PhysicalAccessID for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getPhysicalAccessID();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPP2BSID for datatype TDFSessionRequest
		*/
		OctetString* set3GPP2BSID();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPP2BSID for datatype TDFSessionRequest
		*/
		void reset3GPP2BSID();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPP2BSID for datatype TDFSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPP2BSID();

		list<SD::ProxyInfo*>* getProxyInfoGrpList();

		list<SD::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		//! Function to Decode
		/*!		Function to Decode datatype TDFSessionRequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype TDFSessionRequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype TDFSessionRequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype TDFSessionRequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype TDFSessionRequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
