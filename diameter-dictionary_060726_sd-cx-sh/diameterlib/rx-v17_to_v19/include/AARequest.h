#ifndef RX_AAREQUEST_H
#define RX_AAREQUEST_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"
#include "rx/include/ProxyInfo.h"
#include "rx/include/DRMP.h"
#include "rx/include/AuthSessionState.h"
#include "rx/include/MediaComponentDescription.h"
#include "rx/include/ServiceInfoStatus.h"
#include "rx/include/SIPForkingIndication.h"
#include "rx/include/SpecificAction.h"
#include "rx/include/SubscriptionId.h"
#include "rx/include/OCSupportedFeatures.h"
#include "rx/include/SupportedFeatures.h"
#include "rx/include/ReservationPriority.h"
#include "rx/include/SponsoredConnectivityData.h"
#include "rx/include/IMSContentType.h"
#include "rx/include/CalleeInformation.h"
#include "rx/include/RxRequestType.h"
#include "rx/include/MPSAction.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace RX{
typedef enum _tags_AARequest
{
	AARequest_SESSIONID	= 0,
	AARequest_DRMP	= 1,
	AARequest_AUTHAPPLICATIONID	= 2,
	AARequest_ORIGINHOST	= 3,
	AARequest_ORIGINREALM	= 4,
	AARequest_DESTINATIONREALM	= 5,
	AARequest_DESTINATIONHOST	= 6,
	AARequest_IPDOMAINID	= 7,
	AARequest_AUTHSESSIONSTATE	= 8,
	AARequest_AFAPPLICATIONIDENTIFIER	= 9,
	AARequest_MEDIACOMPONENTDESCRIPTION	= 10,
	AARequest_SERVICEINFOSTATUS	= 11,
	AARequest_AFCHARGINGIDENTIFIER	= 12,
	AARequest_SIPFORKINGINDICATION	= 13,
	AARequest_SPECIFICACTION	= 14,
	AARequest_SUBSCRIPTIONID	= 15,
	AARequest_OCSUPPORTEDFEATURES	= 16,
	AARequest_SUPPORTEDFEATURES	= 17,
	AARequest_RESERVATIONPRIORITY	= 18,
	AARequest_FRAMEDIPADDRESS	= 19,
	AARequest_FRAMEDIPV6PREFIX	= 20,
	AARequest_CALLEDSTATIONID	= 21,
	AARequest_SERVICEURN	= 22,
	AARequest_SPONSOREDCONNECTIVITYDATA	= 23,
	AARequest_MPSIDENTIFIER	= 24,
	AARequest_GCSIDENTIFIER	= 25,
	AARequest_MCPTTIDENTIFIER	= 26,
	AARequest_MCVIDEOIDENTIFIER	= 27,
	AARequest_IMSCONTENTIDENTIFIER	= 28,
	AARequest_IMSCONTENTTYPE	= 29,
	AARequest_CALLINGPARTYADDRESS	= 30,
	AARequest_CALLEEINFORMATION	= 31,
	AARequest_RXREQUESTTYPE	= 32,
	AARequest_REQUIREDACCESSINFO	= 33,
	AARequest_AFREQUESTEDDATA	= 34,
	AARequest_REFERENCEID	= 35,
	AARequest_PREEMPTIONCONTROLINFO	= 36,
	AARequest_MPSACTION	= 37,
	AARequest_ORIGINSTATEID	= 38,
	AARequest_PROXYINFO	= 39,
	AARequest_ROUTERECORD	= 40,
}AARequest_tags;

		//! Class Definition
		/*!		ClassName is AARequest
		*/
class AARequest : public DiameterBase 
{
	private:

		bitset<41> mTagsPresent;

		bitset<41> mMandatoryAvpCheckVal;

		bitset<41> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		DRMP*		mDRMP;

		Integer32*		mAuthApplicationId;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		OctetString*		mDestinationRealm;

		OctetString*		mDestinationHost;

		OctetString*		mIPDomainId;

		AuthSessionState*		mAuthSessionState;

		OctetString*		mAFApplicationIdentifier;

		ServiceInfoStatus*		mServiceInfoStatus;

		OctetString*		mAFChargingIdentifier;

		SIPForkingIndication*		mSIPForkingIndication;

		list<SpecificAction*>* 		mSpecificActionList;

		list<SpecificAction*>::iterator 		mSpecificActionIterator;

		ReservationPriority*		mReservationPriority;

		OctetString*		mFramedIPAddress;

		OctetString*		mFramedIPv6Prefix;

		OctetString*		mCalledStationId;

		OctetString*		mServiceURN;

		OctetString*		mMPSIdentifier;

		OctetString*		mGCSIdentifier;

		OctetString*		mMCPTTIdentifier;

		OctetString*		mMCVideoIdentifier;

		OctetString*		mIMSContentIdentifier;

		IMSContentType*		mIMSContentType;

		OctetString*		mCallingPartyAddress;

		RxRequestType*		mRxRequestType;

		list<OctetString*>* 		mRequiredAccessInfoList;

		list<OctetString*>::iterator 		mRequiredAccessInfoIterator;

		Unsigned32*		mAFRequestedData;

		OctetString*		mReferenceID;

		Unsigned32*		mPreEmptionControlInfo;

		MPSAction*		mMPSAction;

		Unsigned32*		mOriginStateId;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;












		list<MediaComponentDescription*>*	mMediaComponentDescriptionGrpList;
		list<MediaComponentDescription*>::iterator	mMediaComponentDescriptionGrpIterator;





		list<SubscriptionId*>*	mSubscriptionIdGrpList;
		list<SubscriptionId*>::iterator	mSubscriptionIdGrpIterator;

		OCSupportedFeatures*	mOCSupportedFeaturesGrp;

		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;






		list<SponsoredConnectivityData*>*	mSponsoredConnectivityDataGrpList;
		list<SponsoredConnectivityData*>::iterator	mSponsoredConnectivityDataGrpIterator;








		list<CalleeInformation*>*	mCalleeInformationGrpList;
		list<CalleeInformation*>::iterator	mCalleeInformationGrpIterator;








		list<RX::ProxyInfo*>*	mProxyInfoGrpList;
		list<RX::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		AARequest();

		AARequest(const AARequest &objAARequest) {

		mTagsPresent = objAARequest.mTagsPresent;

		mMandatoryAvpCheckVal = objAARequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objAARequest.mMandatoryAvpSetVal;

		mTag = objAARequest.mTag;

		mDecodeFlag = objAARequest.mDecodeFlag;

		if(objAARequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objAARequest.mSessionId));

		if(objAARequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objAARequest.mDRMP));

		if(objAARequest.mAuthApplicationId != NULL)
		mAuthApplicationId = new Integer32(*(objAARequest.mAuthApplicationId));

		if(objAARequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objAARequest.mOriginHost));

		if(objAARequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objAARequest.mOriginRealm));

		if(objAARequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objAARequest.mDestinationRealm));

		if(objAARequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objAARequest.mDestinationHost));

		if(objAARequest.mIPDomainId != NULL)
		mIPDomainId = new OctetString(*(objAARequest.mIPDomainId));

		if(objAARequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objAARequest.mAuthSessionState));

		if(objAARequest.mAFApplicationIdentifier != NULL)
		mAFApplicationIdentifier = new OctetString(*(objAARequest.mAFApplicationIdentifier));

		if(objAARequest.mMediaComponentDescriptionGrpList != NULL)
		 {
		 mMediaComponentDescriptionGrpList = new list<MediaComponentDescription*>;
		 for( auto element : *objAARequest.mMediaComponentDescriptionGrpList)
		 {
				 MediaComponentDescription *lMediaComponentDescription =  new MediaComponentDescription(*element);
				 mMediaComponentDescriptionGrpList->push_back(lMediaComponentDescription);
		 }
		 }
		if(objAARequest.mServiceInfoStatus != NULL)
		mServiceInfoStatus = new ServiceInfoStatus(*(objAARequest.mServiceInfoStatus));

		if(objAARequest.mAFChargingIdentifier != NULL)
		mAFChargingIdentifier = new OctetString(*(objAARequest.mAFChargingIdentifier));

		if(objAARequest.mSIPForkingIndication != NULL)
		mSIPForkingIndication = new SIPForkingIndication(*(objAARequest.mSIPForkingIndication));

		if(objAARequest.mSubscriptionIdGrpList != NULL)
		 {
		 mSubscriptionIdGrpList = new list<SubscriptionId*>;
		 for( auto element : *objAARequest.mSubscriptionIdGrpList)
		 {
				 SubscriptionId *lSubscriptionId =  new SubscriptionId(*element);
				 mSubscriptionIdGrpList->push_back(lSubscriptionId);
		 }
		 }
		if(objAARequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objAARequest.mOCSupportedFeaturesGrp);
		 }
		if(objAARequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objAARequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objAARequest.mReservationPriority != NULL)
		mReservationPriority = new ReservationPriority(*(objAARequest.mReservationPriority));

		if(objAARequest.mFramedIPAddress != NULL)
		mFramedIPAddress = new OctetString(*(objAARequest.mFramedIPAddress));

		if(objAARequest.mFramedIPv6Prefix != NULL)
		mFramedIPv6Prefix = new OctetString(*(objAARequest.mFramedIPv6Prefix));

		if(objAARequest.mCalledStationId != NULL)
		mCalledStationId = new OctetString(*(objAARequest.mCalledStationId));

		if(objAARequest.mServiceURN != NULL)
		mServiceURN = new OctetString(*(objAARequest.mServiceURN));

		if(objAARequest.mSponsoredConnectivityDataGrpList != NULL)
		 {
		 mSponsoredConnectivityDataGrpList = new list<SponsoredConnectivityData*>;
		 for( auto element : *objAARequest.mSponsoredConnectivityDataGrpList)
		 {
				 SponsoredConnectivityData *lSponsoredConnectivityData =  new SponsoredConnectivityData(*element);
				 mSponsoredConnectivityDataGrpList->push_back(lSponsoredConnectivityData);
		 }
		 }
		if(objAARequest.mMPSIdentifier != NULL)
		mMPSIdentifier = new OctetString(*(objAARequest.mMPSIdentifier));

		if(objAARequest.mGCSIdentifier != NULL)
		mGCSIdentifier = new OctetString(*(objAARequest.mGCSIdentifier));

		if(objAARequest.mMCPTTIdentifier != NULL)
		mMCPTTIdentifier = new OctetString(*(objAARequest.mMCPTTIdentifier));

		if(objAARequest.mMCVideoIdentifier != NULL)
		mMCVideoIdentifier = new OctetString(*(objAARequest.mMCVideoIdentifier));

		if(objAARequest.mIMSContentIdentifier != NULL)
		mIMSContentIdentifier = new OctetString(*(objAARequest.mIMSContentIdentifier));

		if(objAARequest.mIMSContentType != NULL)
		mIMSContentType = new IMSContentType(*(objAARequest.mIMSContentType));

		if(objAARequest.mCallingPartyAddress != NULL)
		mCallingPartyAddress = new OctetString(*(objAARequest.mCallingPartyAddress));

		if(objAARequest.mCalleeInformationGrpList != NULL)
		 {
		 mCalleeInformationGrpList = new list<CalleeInformation*>;
		 for( auto element : *objAARequest.mCalleeInformationGrpList)
		 {
				 CalleeInformation *lCalleeInformation =  new CalleeInformation(*element);
				 mCalleeInformationGrpList->push_back(lCalleeInformation);
		 }
		 }
		if(objAARequest.mRxRequestType != NULL)
		mRxRequestType = new RxRequestType(*(objAARequest.mRxRequestType));

		if(objAARequest.mAFRequestedData != NULL)
		mAFRequestedData = new Unsigned32(*(objAARequest.mAFRequestedData));

		if(objAARequest.mReferenceID != NULL)
		mReferenceID = new OctetString(*(objAARequest.mReferenceID));

		if(objAARequest.mPreEmptionControlInfo != NULL)
		mPreEmptionControlInfo = new Unsigned32(*(objAARequest.mPreEmptionControlInfo));

		if(objAARequest.mMPSAction != NULL)
		mMPSAction = new MPSAction(*(objAARequest.mMPSAction));

		if(objAARequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objAARequest.mOriginStateId));

		if(objAARequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<RX::ProxyInfo*>;
		 for( auto element : *objAARequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const AARequest &objAARequest) {

		mTagsPresent = objAARequest.mTagsPresent;

		mMandatoryAvpCheckVal = objAARequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objAARequest.mMandatoryAvpSetVal;

		mTag = objAARequest.mTag;

		mDecodeFlag = objAARequest.mDecodeFlag;

		if(objAARequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objAARequest.mSessionId));

		if(objAARequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objAARequest.mDRMP));

		if(objAARequest.mAuthApplicationId != NULL)
		mAuthApplicationId = new Integer32(*(objAARequest.mAuthApplicationId));

		if(objAARequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objAARequest.mOriginHost));

		if(objAARequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objAARequest.mOriginRealm));

		if(objAARequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objAARequest.mDestinationRealm));

		if(objAARequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objAARequest.mDestinationHost));

		if(objAARequest.mIPDomainId != NULL)
		mIPDomainId = new OctetString(*(objAARequest.mIPDomainId));

		if(objAARequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objAARequest.mAuthSessionState));

		if(objAARequest.mAFApplicationIdentifier != NULL)
		mAFApplicationIdentifier = new OctetString(*(objAARequest.mAFApplicationIdentifier));

		if(objAARequest.mMediaComponentDescriptionGrpList != NULL)
		 {
		 mMediaComponentDescriptionGrpList = new list<MediaComponentDescription*>;
		 for( auto element : *objAARequest.mMediaComponentDescriptionGrpList)
		 {
				 MediaComponentDescription *lMediaComponentDescription =  new MediaComponentDescription(*element);
				 mMediaComponentDescriptionGrpList->push_back(lMediaComponentDescription);
		 }
		 }
		if(objAARequest.mServiceInfoStatus != NULL)
		mServiceInfoStatus = new ServiceInfoStatus(*(objAARequest.mServiceInfoStatus));

		if(objAARequest.mAFChargingIdentifier != NULL)
		mAFChargingIdentifier = new OctetString(*(objAARequest.mAFChargingIdentifier));

		if(objAARequest.mSIPForkingIndication != NULL)
		mSIPForkingIndication = new SIPForkingIndication(*(objAARequest.mSIPForkingIndication));

		if(objAARequest.mSubscriptionIdGrpList != NULL)
		 {
		 mSubscriptionIdGrpList = new list<SubscriptionId*>;
		 for( auto element : *objAARequest.mSubscriptionIdGrpList)
		 {
				 SubscriptionId *lSubscriptionId =  new SubscriptionId(*element);
				 mSubscriptionIdGrpList->push_back(lSubscriptionId);
		 }
		 }
		if(objAARequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objAARequest.mOCSupportedFeaturesGrp);
		 }
		if(objAARequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objAARequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objAARequest.mReservationPriority != NULL)
		mReservationPriority = new ReservationPriority(*(objAARequest.mReservationPriority));

		if(objAARequest.mFramedIPAddress != NULL)
		mFramedIPAddress = new OctetString(*(objAARequest.mFramedIPAddress));

		if(objAARequest.mFramedIPv6Prefix != NULL)
		mFramedIPv6Prefix = new OctetString(*(objAARequest.mFramedIPv6Prefix));

		if(objAARequest.mCalledStationId != NULL)
		mCalledStationId = new OctetString(*(objAARequest.mCalledStationId));

		if(objAARequest.mServiceURN != NULL)
		mServiceURN = new OctetString(*(objAARequest.mServiceURN));

		if(objAARequest.mSponsoredConnectivityDataGrpList != NULL)
		 {
		 mSponsoredConnectivityDataGrpList = new list<SponsoredConnectivityData*>;
		 for( auto element : *objAARequest.mSponsoredConnectivityDataGrpList)
		 {
				 SponsoredConnectivityData *lSponsoredConnectivityData =  new SponsoredConnectivityData(*element);
				 mSponsoredConnectivityDataGrpList->push_back(lSponsoredConnectivityData);
		 }
		 }
		if(objAARequest.mMPSIdentifier != NULL)
		mMPSIdentifier = new OctetString(*(objAARequest.mMPSIdentifier));

		if(objAARequest.mGCSIdentifier != NULL)
		mGCSIdentifier = new OctetString(*(objAARequest.mGCSIdentifier));

		if(objAARequest.mMCPTTIdentifier != NULL)
		mMCPTTIdentifier = new OctetString(*(objAARequest.mMCPTTIdentifier));

		if(objAARequest.mMCVideoIdentifier != NULL)
		mMCVideoIdentifier = new OctetString(*(objAARequest.mMCVideoIdentifier));

		if(objAARequest.mIMSContentIdentifier != NULL)
		mIMSContentIdentifier = new OctetString(*(objAARequest.mIMSContentIdentifier));

		if(objAARequest.mIMSContentType != NULL)
		mIMSContentType = new IMSContentType(*(objAARequest.mIMSContentType));

		if(objAARequest.mCallingPartyAddress != NULL)
		mCallingPartyAddress = new OctetString(*(objAARequest.mCallingPartyAddress));

		if(objAARequest.mCalleeInformationGrpList != NULL)
		 {
		 mCalleeInformationGrpList = new list<CalleeInformation*>;
		 for( auto element : *objAARequest.mCalleeInformationGrpList)
		 {
				 CalleeInformation *lCalleeInformation =  new CalleeInformation(*element);
				 mCalleeInformationGrpList->push_back(lCalleeInformation);
		 }
		 }
		if(objAARequest.mRxRequestType != NULL)
		mRxRequestType = new RxRequestType(*(objAARequest.mRxRequestType));

		if(objAARequest.mAFRequestedData != NULL)
		mAFRequestedData = new Unsigned32(*(objAARequest.mAFRequestedData));

		if(objAARequest.mReferenceID != NULL)
		mReferenceID = new OctetString(*(objAARequest.mReferenceID));

		if(objAARequest.mPreEmptionControlInfo != NULL)
		mPreEmptionControlInfo = new Unsigned32(*(objAARequest.mPreEmptionControlInfo));

		if(objAARequest.mMPSAction != NULL)
		mMPSAction = new MPSAction(*(objAARequest.mMPSAction));

		if(objAARequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objAARequest.mOriginStateId));

		if(objAARequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<RX::ProxyInfo*>;
		 for( auto element : *objAARequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~AARequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype AARequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype AARequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype AARequest
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype AARequest
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		//!Function to set values
		/*!		Function to set the recent Integer32 type of argument AuthApplicationId for datatype AARequest
		*/
		Integer32* setAuthApplicationId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthApplicationId for datatype AARequest
		*/
		void resetAuthApplicationId();

		//!Function to get values
		/*!		Function to get Integer32 type of argument AuthApplicationId for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		Integer32* getAuthApplicationId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype AARequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype AARequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype AARequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype AARequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationRealm for datatype AARequest
		*/
		OctetString* setDestinationRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationRealm for datatype AARequest
		*/
		void resetDestinationRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationRealm for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationHost for datatype AARequest
		*/
		OctetString* setDestinationHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationHost for datatype AARequest
		*/
		void resetDestinationHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationHost for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument IPDomainId for datatype AARequest
		*/
		OctetString* setIPDomainId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument IPDomainId for datatype AARequest
		*/
		void resetIPDomainId();

		//!Function to get values
		/*!		Function to get OctetString type of argument IPDomainId for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getIPDomainId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype AARequest
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype AARequest
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument AFApplicationIdentifier for datatype AARequest
		*/
		OctetString* setAFApplicationIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AFApplicationIdentifier for datatype AARequest
		*/
		void resetAFApplicationIdentifier();

		//!Function to get values
		/*!		Function to get OctetString type of argument AFApplicationIdentifier for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getAFApplicationIdentifier();

		list<MediaComponentDescription*>* getMediaComponentDescriptionGrpList();

		list<MediaComponentDescription*>* setMediaComponentDescriptionGrpList();

		void resetMediaComponentDescriptionGrpList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument ServiceInfoStatus for datatype AARequest
		*/
		ServiceInfoStatus* setServiceInfoStatus();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ServiceInfoStatus for datatype AARequest
		*/
		void resetServiceInfoStatus();

		//!Function to get values
		/*!		Function to get ServiceInfoStatus type of argument ServiceInfoStatus for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		ServiceInfoStatus* getServiceInfoStatus();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument AFChargingIdentifier for datatype AARequest
		*/
		OctetString* setAFChargingIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AFChargingIdentifier for datatype AARequest
		*/
		void resetAFChargingIdentifier();

		//!Function to get values
		/*!		Function to get OctetString type of argument AFChargingIdentifier for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getAFChargingIdentifier();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument SIPForkingIndication for datatype AARequest
		*/
		SIPForkingIndication* setSIPForkingIndication();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SIPForkingIndication for datatype AARequest
		*/
		void resetSIPForkingIndication();

		//!Function to get values
		/*!		Function to get SIPForkingIndication type of argument SIPForkingIndication for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		SIPForkingIndication* getSIPForkingIndication();

		list<SpecificAction*>* getSpecificActionList();

		list<SpecificAction*>* setSpecificActionList();

		void resetSpecificActionList();

		list<SubscriptionId*>* getSubscriptionIdGrpList();

		list<SubscriptionId*>* setSubscriptionIdGrpList();

		void resetSubscriptionIdGrpList();

		OCSupportedFeatures* getOCSupportedFeatures();

		OCSupportedFeatures* setOCSupportedFeatures();

		void resetOCSupportedFeatures();

		list<SupportedFeatures*>* getSupportedFeaturesGrpList();

		list<SupportedFeatures*>* setSupportedFeaturesGrpList();

		void resetSupportedFeaturesGrpList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument ReservationPriority for datatype AARequest
		*/
		ReservationPriority* setReservationPriority();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ReservationPriority for datatype AARequest
		*/
		void resetReservationPriority();

		//!Function to get values
		/*!		Function to get ReservationPriority type of argument ReservationPriority for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		ReservationPriority* getReservationPriority();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument FramedIPAddress for datatype AARequest
		*/
		OctetString* setFramedIPAddress();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FramedIPAddress for datatype AARequest
		*/
		void resetFramedIPAddress();

		//!Function to get values
		/*!		Function to get OctetString type of argument FramedIPAddress for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getFramedIPAddress();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument FramedIPv6Prefix for datatype AARequest
		*/
		OctetString* setFramedIPv6Prefix();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FramedIPv6Prefix for datatype AARequest
		*/
		void resetFramedIPv6Prefix();

		//!Function to get values
		/*!		Function to get OctetString type of argument FramedIPv6Prefix for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getFramedIPv6Prefix();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument CalledStationId for datatype AARequest
		*/
		OctetString* setCalledStationId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CalledStationId for datatype AARequest
		*/
		void resetCalledStationId();

		//!Function to get values
		/*!		Function to get OctetString type of argument CalledStationId for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getCalledStationId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ServiceURN for datatype AARequest
		*/
		OctetString* setServiceURN();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ServiceURN for datatype AARequest
		*/
		void resetServiceURN();

		//!Function to get values
		/*!		Function to get OctetString type of argument ServiceURN for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getServiceURN();

		list<SponsoredConnectivityData*>* getSponsoredConnectivityDataGrpList();

		list<SponsoredConnectivityData*>* setSponsoredConnectivityDataGrpList();

		void resetSponsoredConnectivityDataGrpList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument MPSIdentifier for datatype AARequest
		*/
		OctetString* setMPSIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MPSIdentifier for datatype AARequest
		*/
		void resetMPSIdentifier();

		//!Function to get values
		/*!		Function to get OctetString type of argument MPSIdentifier for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getMPSIdentifier();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument GCSIdentifier for datatype AARequest
		*/
		OctetString* setGCSIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument GCSIdentifier for datatype AARequest
		*/
		void resetGCSIdentifier();

		//!Function to get values
		/*!		Function to get OctetString type of argument GCSIdentifier for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getGCSIdentifier();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument MCPTTIdentifier for datatype AARequest
		*/
		OctetString* setMCPTTIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MCPTTIdentifier for datatype AARequest
		*/
		void resetMCPTTIdentifier();

		//!Function to get values
		/*!		Function to get OctetString type of argument MCPTTIdentifier for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getMCPTTIdentifier();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument MCVideoIdentifier for datatype AARequest
		*/
		OctetString* setMCVideoIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MCVideoIdentifier for datatype AARequest
		*/
		void resetMCVideoIdentifier();

		//!Function to get values
		/*!		Function to get OctetString type of argument MCVideoIdentifier for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getMCVideoIdentifier();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument IMSContentIdentifier for datatype AARequest
		*/
		OctetString* setIMSContentIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument IMSContentIdentifier for datatype AARequest
		*/
		void resetIMSContentIdentifier();

		//!Function to get values
		/*!		Function to get OctetString type of argument IMSContentIdentifier for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getIMSContentIdentifier();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument IMSContentType for datatype AARequest
		*/
		IMSContentType* setIMSContentType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument IMSContentType for datatype AARequest
		*/
		void resetIMSContentType();

		//!Function to get values
		/*!		Function to get IMSContentType type of argument IMSContentType for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		IMSContentType* getIMSContentType();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument CallingPartyAddress for datatype AARequest
		*/
		OctetString* setCallingPartyAddress();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CallingPartyAddress for datatype AARequest
		*/
		void resetCallingPartyAddress();

		//!Function to get values
		/*!		Function to get OctetString type of argument CallingPartyAddress for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getCallingPartyAddress();

		list<CalleeInformation*>* getCalleeInformationGrpList();

		list<CalleeInformation*>* setCalleeInformationGrpList();

		void resetCalleeInformationGrpList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument RxRequestType for datatype AARequest
		*/
		RxRequestType* setRxRequestType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RxRequestType for datatype AARequest
		*/
		void resetRxRequestType();

		//!Function to get values
		/*!		Function to get RxRequestType type of argument RxRequestType for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		RxRequestType* getRxRequestType();

		list<OctetString*>* getRequiredAccessInfoList();

		list<OctetString*>* setRequiredAccessInfoList();

		void resetRequiredAccessInfoList();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument AFRequestedData for datatype AARequest
		*/
		Unsigned32* setAFRequestedData();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AFRequestedData for datatype AARequest
		*/
		void resetAFRequestedData();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument AFRequestedData for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getAFRequestedData();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ReferenceID for datatype AARequest
		*/
		OctetString* setReferenceID();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ReferenceID for datatype AARequest
		*/
		void resetReferenceID();

		//!Function to get values
		/*!		Function to get OctetString type of argument ReferenceID for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getReferenceID();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument PreEmptionControlInfo for datatype AARequest
		*/
		Unsigned32* setPreEmptionControlInfo();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PreEmptionControlInfo for datatype AARequest
		*/
		void resetPreEmptionControlInfo();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument PreEmptionControlInfo for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getPreEmptionControlInfo();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument MPSAction for datatype AARequest
		*/
		MPSAction* setMPSAction();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MPSAction for datatype AARequest
		*/
		void resetMPSAction();

		//!Function to get values
		/*!		Function to get MPSAction type of argument MPSAction for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		MPSAction* getMPSAction();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype AARequest
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype AARequest
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype AARequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		list<RX::ProxyInfo*>* getProxyInfoGrpList();

		list<RX::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		//! Function to Decode
		/*!		Function to Decode datatype AARequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype AARequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype AARequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype AARequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype AARequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
