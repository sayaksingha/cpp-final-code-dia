#ifndef RX_RAREQUEST_H
#define RX_RAREQUEST_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"
#include "rx/include/ProxyInfo.h"
#include "rx/include/DRMP.h"
#include "rx/include/SpecificAction.h"
#include "rx/include/OCSupportedFeatures.h"
#include "rx/include/AccessNetworkChargingIdentifier.h"
#include "rx/include/ANTrusted.h"
#include "rx/include/Flows.h"
#include "rx/include/SubscriptionId.h"
#include "rx/include/AbortCause.h"
#include "rx/include/IPCANType.h"
#include "rx/include/MAInformation.h"
#include "rx/include/RATType.h"
#include "rx/include/SponsoredConnectivityData.h"
#include "rx/include/FiveGSRANNASReleaseCause.h"
#include "rx/include/WirelineUserLocationInfo.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace RX{
typedef enum _tags_RARequest
{
	RARequest_SESSIONID	= 0,
	RARequest_DRMP	= 1,
	RARequest_ORIGINHOST	= 2,
	RARequest_ORIGINREALM	= 3,
	RARequest_DESTINATIONREALM	= 4,
	RARequest_DESTINATIONHOST	= 5,
	RARequest_AUTHAPPLICATIONID	= 6,
	RARequest_SPECIFICACTION	= 7,
	RARequest_OCSUPPORTEDFEATURES	= 8,
	RARequest_ACCESSNETWORKCHARGINGIDENTIFIER	= 9,
	RARequest_ACCESSNETWORKCHARGINGADDRESS	= 10,
	RARequest_ANGWADDRESS	= 11,
	RARequest_ANTRUSTED	= 12,
	RARequest_FLOWS	= 13,
	RARequest_SUBSCRIPTIONID	= 14,
	RARequest_ABORTCAUSE	= 15,
	RARequest_IPCANTYPE	= 16,
	RARequest_MAINFORMATION	= 17,
	RARequest_NETLOCACCESSSUPPORT	= 18,
	RARequest_RATTYPE	= 19,
	RARequest_SPONSOREDCONNECTIVITYDATA	= 20,
	RARequest_3GPPUSERLOCATIONINFO	= 21,
	RARequest_USERLOCATIONINFOTIME	= 22,
	RARequest_3GPPMSTIMEZONE	= 23,
	RARequest_RANNASRELEASECAUSE	= 24,
	RARequest_FIVEGSRANNASRELEASECAUSE	= 25,
	RARequest_3GPPSGSNMCCMNC	= 26,
	RARequest_NID	= 27,
	RARequest_TWANIDENTIFIER	= 28,
	RARequest_TCPSOURCEPORT	= 29,
	RARequest_UDPSOURCEPORT	= 30,
	RARequest_UELOCALIPADDRESS	= 31,
	RARequest_WIRELINEUSERLOCATIONINFO	= 32,
	RARequest_ORIGINSTATEID	= 33,
	RARequest_CLASS	= 34,
	RARequest_PROXYINFO	= 35,
	RARequest_ROUTERECORD	= 36,
}RARequest_tags;

		//! Class Definition
		/*!		ClassName is RARequest
		*/
class RARequest : public DiameterBase 
{
	private:

		bitset<37> mTagsPresent;

		bitset<37> mMandatoryAvpCheckVal;

		bitset<37> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		DRMP*		mDRMP;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		OctetString*		mDestinationRealm;

		OctetString*		mDestinationHost;

		Integer32*		mAuthApplicationId;

		list<SpecificAction*>* 		mSpecificActionList;

		list<SpecificAction*>::iterator 		mSpecificActionIterator;

		Address*		mAccessNetworkChargingAddress;

		list<Address*>* 		mANGWAddressList;

		list<Address*>::iterator 		mANGWAddressIterator;

		ANTrusted*		mANTrusted;

		AbortCause*		mAbortCause;

		IPCANType*		mIPCANType;

		Unsigned32*		mNetLocAccessSupport;

		RATType*		mRATType;

		OctetString*		m3GPPUserLocationInfo;

		Time*		mUserLocationInfoTime;

		OctetString*		m3GPPMSTimeZone;

		OctetString*		mRANNASReleaseCause;

		OctetString*		m3GPPSGSNMCCMNC;

		OctetString*		mNID;

		OctetString*		mTWANIdentifier;

		Unsigned32*		mTCPSourcePort;

		Unsigned32*		mUDPSourcePort;

		Address*		mUELocalIPAddress;

		Unsigned32*		mOriginStateId;

		OctetString*		mClass;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;










		OCSupportedFeatures*	mOCSupportedFeaturesGrp;

		list<AccessNetworkChargingIdentifier*>*	mAccessNetworkChargingIdentifierGrpList;
		list<AccessNetworkChargingIdentifier*>::iterator	mAccessNetworkChargingIdentifierGrpIterator;




		list<Flows*>*	mFlowsGrpList;
		list<Flows*>::iterator	mFlowsGrpIterator;

		list<SubscriptionId*>*	mSubscriptionIdGrpList;
		list<SubscriptionId*>::iterator	mSubscriptionIdGrpIterator;



		list<MAInformation*>*	mMAInformationGrpList;
		list<MAInformation*>::iterator	mMAInformationGrpIterator;



		list<SponsoredConnectivityData*>*	mSponsoredConnectivityDataGrpList;
		list<SponsoredConnectivityData*>::iterator	mSponsoredConnectivityDataGrpIterator;





		list<FiveGSRANNASReleaseCause*>*	mFiveGSRANNASReleaseCauseGrpList;
		list<FiveGSRANNASReleaseCause*>::iterator	mFiveGSRANNASReleaseCauseGrpIterator;







		list<WirelineUserLocationInfo*>*	mWirelineUserLocationInfoGrpList;
		list<WirelineUserLocationInfo*>::iterator	mWirelineUserLocationInfoGrpIterator;



		list<RX::ProxyInfo*>*	mProxyInfoGrpList;
		list<RX::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		RARequest();

		RARequest(const RARequest &objRARequest) {

		mTagsPresent = objRARequest.mTagsPresent;

		mMandatoryAvpCheckVal = objRARequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objRARequest.mMandatoryAvpSetVal;

		mTag = objRARequest.mTag;

		mDecodeFlag = objRARequest.mDecodeFlag;

		if(objRARequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objRARequest.mSessionId));

		if(objRARequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objRARequest.mDRMP));

		if(objRARequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objRARequest.mOriginHost));

		if(objRARequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objRARequest.mOriginRealm));

		if(objRARequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objRARequest.mDestinationRealm));

		if(objRARequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objRARequest.mDestinationHost));

		if(objRARequest.mAuthApplicationId != NULL)
		mAuthApplicationId = new Integer32(*(objRARequest.mAuthApplicationId));

		if(objRARequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objRARequest.mOCSupportedFeaturesGrp);
		 }
		if(objRARequest.mAccessNetworkChargingIdentifierGrpList != NULL)
		 {
		 mAccessNetworkChargingIdentifierGrpList = new list<AccessNetworkChargingIdentifier*>;
		 for( auto element : *objRARequest.mAccessNetworkChargingIdentifierGrpList)
		 {
				 AccessNetworkChargingIdentifier *lAccessNetworkChargingIdentifier =  new AccessNetworkChargingIdentifier(*element);
				 mAccessNetworkChargingIdentifierGrpList->push_back(lAccessNetworkChargingIdentifier);
		 }
		 }
		if(objRARequest.mAccessNetworkChargingAddress != NULL)
		mAccessNetworkChargingAddress = new Address(*(objRARequest.mAccessNetworkChargingAddress));

		if(objRARequest.mANTrusted != NULL)
		mANTrusted = new ANTrusted(*(objRARequest.mANTrusted));

		if(objRARequest.mFlowsGrpList != NULL)
		 {
		 mFlowsGrpList = new list<Flows*>;
		 for( auto element : *objRARequest.mFlowsGrpList)
		 {
				 Flows *lFlows =  new Flows(*element);
				 mFlowsGrpList->push_back(lFlows);
		 }
		 }
		if(objRARequest.mSubscriptionIdGrpList != NULL)
		 {
		 mSubscriptionIdGrpList = new list<SubscriptionId*>;
		 for( auto element : *objRARequest.mSubscriptionIdGrpList)
		 {
				 SubscriptionId *lSubscriptionId =  new SubscriptionId(*element);
				 mSubscriptionIdGrpList->push_back(lSubscriptionId);
		 }
		 }
		if(objRARequest.mAbortCause != NULL)
		mAbortCause = new AbortCause(*(objRARequest.mAbortCause));

		if(objRARequest.mIPCANType != NULL)
		mIPCANType = new IPCANType(*(objRARequest.mIPCANType));

		if(objRARequest.mMAInformationGrpList != NULL)
		 {
		 mMAInformationGrpList = new list<MAInformation*>;
		 for( auto element : *objRARequest.mMAInformationGrpList)
		 {
				 MAInformation *lMAInformation =  new MAInformation(*element);
				 mMAInformationGrpList->push_back(lMAInformation);
		 }
		 }
		if(objRARequest.mNetLocAccessSupport != NULL)
		mNetLocAccessSupport = new Unsigned32(*(objRARequest.mNetLocAccessSupport));

		if(objRARequest.mRATType != NULL)
		mRATType = new RATType(*(objRARequest.mRATType));

		if(objRARequest.mSponsoredConnectivityDataGrpList != NULL)
		 {
		 mSponsoredConnectivityDataGrpList = new list<SponsoredConnectivityData*>;
		 for( auto element : *objRARequest.mSponsoredConnectivityDataGrpList)
		 {
				 SponsoredConnectivityData *lSponsoredConnectivityData =  new SponsoredConnectivityData(*element);
				 mSponsoredConnectivityDataGrpList->push_back(lSponsoredConnectivityData);
		 }
		 }
		if(objRARequest.m3GPPUserLocationInfo != NULL)
		m3GPPUserLocationInfo = new OctetString(*(objRARequest.m3GPPUserLocationInfo));

		if(objRARequest.mUserLocationInfoTime != NULL)
		mUserLocationInfoTime = new Time(*(objRARequest.mUserLocationInfoTime));

		if(objRARequest.m3GPPMSTimeZone != NULL)
		m3GPPMSTimeZone = new OctetString(*(objRARequest.m3GPPMSTimeZone));

		if(objRARequest.mRANNASReleaseCause != NULL)
		mRANNASReleaseCause = new OctetString(*(objRARequest.mRANNASReleaseCause));

		if(objRARequest.mFiveGSRANNASReleaseCauseGrpList != NULL)
		 {
		 mFiveGSRANNASReleaseCauseGrpList = new list<FiveGSRANNASReleaseCause*>;
		 for( auto element : *objRARequest.mFiveGSRANNASReleaseCauseGrpList)
		 {
				 FiveGSRANNASReleaseCause *lFiveGSRANNASReleaseCause =  new FiveGSRANNASReleaseCause(*element);
				 mFiveGSRANNASReleaseCauseGrpList->push_back(lFiveGSRANNASReleaseCause);
		 }
		 }
		if(objRARequest.m3GPPSGSNMCCMNC != NULL)
		m3GPPSGSNMCCMNC = new OctetString(*(objRARequest.m3GPPSGSNMCCMNC));

		if(objRARequest.mNID != NULL)
		mNID = new OctetString(*(objRARequest.mNID));

		if(objRARequest.mTWANIdentifier != NULL)
		mTWANIdentifier = new OctetString(*(objRARequest.mTWANIdentifier));

		if(objRARequest.mTCPSourcePort != NULL)
		mTCPSourcePort = new Unsigned32(*(objRARequest.mTCPSourcePort));

		if(objRARequest.mUDPSourcePort != NULL)
		mUDPSourcePort = new Unsigned32(*(objRARequest.mUDPSourcePort));

		if(objRARequest.mUELocalIPAddress != NULL)
		mUELocalIPAddress = new Address(*(objRARequest.mUELocalIPAddress));

		if(objRARequest.mWirelineUserLocationInfoGrpList != NULL)
		 {
		 mWirelineUserLocationInfoGrpList = new list<WirelineUserLocationInfo*>;
		 for( auto element : *objRARequest.mWirelineUserLocationInfoGrpList)
		 {
				 WirelineUserLocationInfo *lWirelineUserLocationInfo =  new WirelineUserLocationInfo(*element);
				 mWirelineUserLocationInfoGrpList->push_back(lWirelineUserLocationInfo);
		 }
		 }
		if(objRARequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objRARequest.mOriginStateId));

		if(objRARequest.mClass != NULL)
		mClass = new OctetString(*(objRARequest.mClass));

		if(objRARequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<RX::ProxyInfo*>;
		 for( auto element : *objRARequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const RARequest &objRARequest) {

		mTagsPresent = objRARequest.mTagsPresent;

		mMandatoryAvpCheckVal = objRARequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objRARequest.mMandatoryAvpSetVal;

		mTag = objRARequest.mTag;

		mDecodeFlag = objRARequest.mDecodeFlag;

		if(objRARequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objRARequest.mSessionId));

		if(objRARequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objRARequest.mDRMP));

		if(objRARequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objRARequest.mOriginHost));

		if(objRARequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objRARequest.mOriginRealm));

		if(objRARequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objRARequest.mDestinationRealm));

		if(objRARequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objRARequest.mDestinationHost));

		if(objRARequest.mAuthApplicationId != NULL)
		mAuthApplicationId = new Integer32(*(objRARequest.mAuthApplicationId));

		if(objRARequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objRARequest.mOCSupportedFeaturesGrp);
		 }
		if(objRARequest.mAccessNetworkChargingIdentifierGrpList != NULL)
		 {
		 mAccessNetworkChargingIdentifierGrpList = new list<AccessNetworkChargingIdentifier*>;
		 for( auto element : *objRARequest.mAccessNetworkChargingIdentifierGrpList)
		 {
				 AccessNetworkChargingIdentifier *lAccessNetworkChargingIdentifier =  new AccessNetworkChargingIdentifier(*element);
				 mAccessNetworkChargingIdentifierGrpList->push_back(lAccessNetworkChargingIdentifier);
		 }
		 }
		if(objRARequest.mAccessNetworkChargingAddress != NULL)
		mAccessNetworkChargingAddress = new Address(*(objRARequest.mAccessNetworkChargingAddress));

		if(objRARequest.mANTrusted != NULL)
		mANTrusted = new ANTrusted(*(objRARequest.mANTrusted));

		if(objRARequest.mFlowsGrpList != NULL)
		 {
		 mFlowsGrpList = new list<Flows*>;
		 for( auto element : *objRARequest.mFlowsGrpList)
		 {
				 Flows *lFlows =  new Flows(*element);
				 mFlowsGrpList->push_back(lFlows);
		 }
		 }
		if(objRARequest.mSubscriptionIdGrpList != NULL)
		 {
		 mSubscriptionIdGrpList = new list<SubscriptionId*>;
		 for( auto element : *objRARequest.mSubscriptionIdGrpList)
		 {
				 SubscriptionId *lSubscriptionId =  new SubscriptionId(*element);
				 mSubscriptionIdGrpList->push_back(lSubscriptionId);
		 }
		 }
		if(objRARequest.mAbortCause != NULL)
		mAbortCause = new AbortCause(*(objRARequest.mAbortCause));

		if(objRARequest.mIPCANType != NULL)
		mIPCANType = new IPCANType(*(objRARequest.mIPCANType));

		if(objRARequest.mMAInformationGrpList != NULL)
		 {
		 mMAInformationGrpList = new list<MAInformation*>;
		 for( auto element : *objRARequest.mMAInformationGrpList)
		 {
				 MAInformation *lMAInformation =  new MAInformation(*element);
				 mMAInformationGrpList->push_back(lMAInformation);
		 }
		 }
		if(objRARequest.mNetLocAccessSupport != NULL)
		mNetLocAccessSupport = new Unsigned32(*(objRARequest.mNetLocAccessSupport));

		if(objRARequest.mRATType != NULL)
		mRATType = new RATType(*(objRARequest.mRATType));

		if(objRARequest.mSponsoredConnectivityDataGrpList != NULL)
		 {
		 mSponsoredConnectivityDataGrpList = new list<SponsoredConnectivityData*>;
		 for( auto element : *objRARequest.mSponsoredConnectivityDataGrpList)
		 {
				 SponsoredConnectivityData *lSponsoredConnectivityData =  new SponsoredConnectivityData(*element);
				 mSponsoredConnectivityDataGrpList->push_back(lSponsoredConnectivityData);
		 }
		 }
		if(objRARequest.m3GPPUserLocationInfo != NULL)
		m3GPPUserLocationInfo = new OctetString(*(objRARequest.m3GPPUserLocationInfo));

		if(objRARequest.mUserLocationInfoTime != NULL)
		mUserLocationInfoTime = new Time(*(objRARequest.mUserLocationInfoTime));

		if(objRARequest.m3GPPMSTimeZone != NULL)
		m3GPPMSTimeZone = new OctetString(*(objRARequest.m3GPPMSTimeZone));

		if(objRARequest.mRANNASReleaseCause != NULL)
		mRANNASReleaseCause = new OctetString(*(objRARequest.mRANNASReleaseCause));

		if(objRARequest.mFiveGSRANNASReleaseCauseGrpList != NULL)
		 {
		 mFiveGSRANNASReleaseCauseGrpList = new list<FiveGSRANNASReleaseCause*>;
		 for( auto element : *objRARequest.mFiveGSRANNASReleaseCauseGrpList)
		 {
				 FiveGSRANNASReleaseCause *lFiveGSRANNASReleaseCause =  new FiveGSRANNASReleaseCause(*element);
				 mFiveGSRANNASReleaseCauseGrpList->push_back(lFiveGSRANNASReleaseCause);
		 }
		 }
		if(objRARequest.m3GPPSGSNMCCMNC != NULL)
		m3GPPSGSNMCCMNC = new OctetString(*(objRARequest.m3GPPSGSNMCCMNC));

		if(objRARequest.mNID != NULL)
		mNID = new OctetString(*(objRARequest.mNID));

		if(objRARequest.mTWANIdentifier != NULL)
		mTWANIdentifier = new OctetString(*(objRARequest.mTWANIdentifier));

		if(objRARequest.mTCPSourcePort != NULL)
		mTCPSourcePort = new Unsigned32(*(objRARequest.mTCPSourcePort));

		if(objRARequest.mUDPSourcePort != NULL)
		mUDPSourcePort = new Unsigned32(*(objRARequest.mUDPSourcePort));

		if(objRARequest.mUELocalIPAddress != NULL)
		mUELocalIPAddress = new Address(*(objRARequest.mUELocalIPAddress));

		if(objRARequest.mWirelineUserLocationInfoGrpList != NULL)
		 {
		 mWirelineUserLocationInfoGrpList = new list<WirelineUserLocationInfo*>;
		 for( auto element : *objRARequest.mWirelineUserLocationInfoGrpList)
		 {
				 WirelineUserLocationInfo *lWirelineUserLocationInfo =  new WirelineUserLocationInfo(*element);
				 mWirelineUserLocationInfoGrpList->push_back(lWirelineUserLocationInfo);
		 }
		 }
		if(objRARequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objRARequest.mOriginStateId));

		if(objRARequest.mClass != NULL)
		mClass = new OctetString(*(objRARequest.mClass));

		if(objRARequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<RX::ProxyInfo*>;
		 for( auto element : *objRARequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~RARequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype RARequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype RARequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype RARequest
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype RARequest
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype RARequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype RARequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype RARequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype RARequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationRealm for datatype RARequest
		*/
		OctetString* setDestinationRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationRealm for datatype RARequest
		*/
		void resetDestinationRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationRealm for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationHost for datatype RARequest
		*/
		OctetString* setDestinationHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationHost for datatype RARequest
		*/
		void resetDestinationHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationHost for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationHost();

		//!Function to set values
		/*!		Function to set the recent Integer32 type of argument AuthApplicationId for datatype RARequest
		*/
		Integer32* setAuthApplicationId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthApplicationId for datatype RARequest
		*/
		void resetAuthApplicationId();

		//!Function to get values
		/*!		Function to get Integer32 type of argument AuthApplicationId for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		Integer32* getAuthApplicationId();

		list<SpecificAction*>* getSpecificActionList();

		list<SpecificAction*>* setSpecificActionList();

		void resetSpecificActionList();

		OCSupportedFeatures* getOCSupportedFeatures();

		OCSupportedFeatures* setOCSupportedFeatures();

		void resetOCSupportedFeatures();

		list<AccessNetworkChargingIdentifier*>* getAccessNetworkChargingIdentifierGrpList();

		list<AccessNetworkChargingIdentifier*>* setAccessNetworkChargingIdentifierGrpList();

		void resetAccessNetworkChargingIdentifierGrpList();

		//!Function to set values
		/*!		Function to set the recent Address type of argument AccessNetworkChargingAddress for datatype RARequest
		*/
		Address* setAccessNetworkChargingAddress();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AccessNetworkChargingAddress for datatype RARequest
		*/
		void resetAccessNetworkChargingAddress();

		//!Function to get values
		/*!		Function to get Address type of argument AccessNetworkChargingAddress for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		Address* getAccessNetworkChargingAddress();

		list<Address*>* getANGWAddressList();

		list<Address*>* setANGWAddressList();

		void resetANGWAddressList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument ANTrusted for datatype RARequest
		*/
		ANTrusted* setANTrusted();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ANTrusted for datatype RARequest
		*/
		void resetANTrusted();

		//!Function to get values
		/*!		Function to get ANTrusted type of argument ANTrusted for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		ANTrusted* getANTrusted();

		list<Flows*>* getFlowsGrpList();

		list<Flows*>* setFlowsGrpList();

		void resetFlowsGrpList();

		list<SubscriptionId*>* getSubscriptionIdGrpList();

		list<SubscriptionId*>* setSubscriptionIdGrpList();

		void resetSubscriptionIdGrpList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AbortCause for datatype RARequest
		*/
		AbortCause* setAbortCause();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AbortCause for datatype RARequest
		*/
		void resetAbortCause();

		//!Function to get values
		/*!		Function to get AbortCause type of argument AbortCause for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		AbortCause* getAbortCause();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument IPCANType for datatype RARequest
		*/
		IPCANType* setIPCANType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument IPCANType for datatype RARequest
		*/
		void resetIPCANType();

		//!Function to get values
		/*!		Function to get IPCANType type of argument IPCANType for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		IPCANType* getIPCANType();

		list<MAInformation*>* getMAInformationGrpList();

		list<MAInformation*>* setMAInformationGrpList();

		void resetMAInformationGrpList();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument NetLocAccessSupport for datatype RARequest
		*/
		Unsigned32* setNetLocAccessSupport();

		//! Function to reset 
		/*!		Function to reset NULL type of argument NetLocAccessSupport for datatype RARequest
		*/
		void resetNetLocAccessSupport();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument NetLocAccessSupport for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getNetLocAccessSupport();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument RATType for datatype RARequest
		*/
		RATType* setRATType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RATType for datatype RARequest
		*/
		void resetRATType();

		//!Function to get values
		/*!		Function to get RATType type of argument RATType for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		RATType* getRATType();

		list<SponsoredConnectivityData*>* getSponsoredConnectivityDataGrpList();

		list<SponsoredConnectivityData*>* setSponsoredConnectivityDataGrpList();

		void resetSponsoredConnectivityDataGrpList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPUserLocationInfo for datatype RARequest
		*/
		OctetString* set3GPPUserLocationInfo();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPUserLocationInfo for datatype RARequest
		*/
		void reset3GPPUserLocationInfo();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPUserLocationInfo for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPUserLocationInfo();

		//!Function to set values
		/*!		Function to set the recent Time type of argument UserLocationInfoTime for datatype RARequest
		*/
		Time* setUserLocationInfoTime();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserLocationInfoTime for datatype RARequest
		*/
		void resetUserLocationInfoTime();

		//!Function to get values
		/*!		Function to get Time type of argument UserLocationInfoTime for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		Time* getUserLocationInfoTime();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPMSTimeZone for datatype RARequest
		*/
		OctetString* set3GPPMSTimeZone();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPMSTimeZone for datatype RARequest
		*/
		void reset3GPPMSTimeZone();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPMSTimeZone for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPMSTimeZone();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument RANNASReleaseCause for datatype RARequest
		*/
		OctetString* setRANNASReleaseCause();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RANNASReleaseCause for datatype RARequest
		*/
		void resetRANNASReleaseCause();

		//!Function to get values
		/*!		Function to get OctetString type of argument RANNASReleaseCause for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getRANNASReleaseCause();

		list<FiveGSRANNASReleaseCause*>* getFiveGSRANNASReleaseCauseGrpList();

		list<FiveGSRANNASReleaseCause*>* setFiveGSRANNASReleaseCauseGrpList();

		void resetFiveGSRANNASReleaseCauseGrpList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPSGSNMCCMNC for datatype RARequest
		*/
		OctetString* set3GPPSGSNMCCMNC();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPSGSNMCCMNC for datatype RARequest
		*/
		void reset3GPPSGSNMCCMNC();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPSGSNMCCMNC for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPSGSNMCCMNC();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument NID for datatype RARequest
		*/
		OctetString* setNID();

		//! Function to reset 
		/*!		Function to reset NULL type of argument NID for datatype RARequest
		*/
		void resetNID();

		//!Function to get values
		/*!		Function to get OctetString type of argument NID for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getNID();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument TWANIdentifier for datatype RARequest
		*/
		OctetString* setTWANIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument TWANIdentifier for datatype RARequest
		*/
		void resetTWANIdentifier();

		//!Function to get values
		/*!		Function to get OctetString type of argument TWANIdentifier for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getTWANIdentifier();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument TCPSourcePort for datatype RARequest
		*/
		Unsigned32* setTCPSourcePort();

		//! Function to reset 
		/*!		Function to reset NULL type of argument TCPSourcePort for datatype RARequest
		*/
		void resetTCPSourcePort();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument TCPSourcePort for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getTCPSourcePort();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument UDPSourcePort for datatype RARequest
		*/
		Unsigned32* setUDPSourcePort();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UDPSourcePort for datatype RARequest
		*/
		void resetUDPSourcePort();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument UDPSourcePort for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getUDPSourcePort();

		//!Function to set values
		/*!		Function to set the recent Address type of argument UELocalIPAddress for datatype RARequest
		*/
		Address* setUELocalIPAddress();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UELocalIPAddress for datatype RARequest
		*/
		void resetUELocalIPAddress();

		//!Function to get values
		/*!		Function to get Address type of argument UELocalIPAddress for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		Address* getUELocalIPAddress();

		list<WirelineUserLocationInfo*>* getWirelineUserLocationInfoGrpList();

		list<WirelineUserLocationInfo*>* setWirelineUserLocationInfoGrpList();

		void resetWirelineUserLocationInfoGrpList();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype RARequest
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype RARequest
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument Class for datatype RARequest
		*/
		OctetString* setClass();

		//! Function to reset 
		/*!		Function to reset NULL type of argument Class for datatype RARequest
		*/
		void resetClass();

		//!Function to get values
		/*!		Function to get OctetString type of argument Class for datatype RARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getClass();

		list<RX::ProxyInfo*>* getProxyInfoGrpList();

		list<RX::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		//! Function to Decode
		/*!		Function to Decode datatype RARequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype RARequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype RARequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype RARequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype RARequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
