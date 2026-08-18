#ifndef SH_USERDATAREQUEST_H
#define SH_USERDATAREQUEST_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sh/include/DRMP.h"
#include "sh/include/VendorSpecificApplicationId.h"
#include "sh/include/AuthSessionState.h"
#include "sh/include/SupportedFeatures.h"
#include "sh/include/UserIdentity.h"
#include "sh/include/DataReference.h"
#include "sh/include/IdentitySet.h"
#include "sh/include/RequestedDomain.h"
#include "sh/include/CurrentLocation.h"
#include "sh/include/SessionPriority.h"
#include "sh/include/ServingNodeIndication.h"
#include "sh/include/PrepagingSupported.h"
#include "sh/include/LocalTimeZoneIndication.h"
#include "sh/include/CallReferenceInfo.h"
#include "sh/include/OCSupportedFeatures.h"
#include "sh/include/ProxyInfo.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace SH{
typedef enum _tags_UserDataRequest
{
	UserDataRequest_SESSIONID	= 0,
	UserDataRequest_DRMP	= 1,
	UserDataRequest_VENDORSPECIFICAPPLICATIONID	= 2,
	UserDataRequest_AUTHSESSIONSTATE	= 3,
	UserDataRequest_ORIGINHOST	= 4,
	UserDataRequest_ORIGINREALM	= 5,
	UserDataRequest_DESTINATIONHOST	= 6,
	UserDataRequest_DESTINATIONREALM	= 7,
	UserDataRequest_SUPPORTEDFEATURES	= 8,
	UserDataRequest_USERIDENTITY	= 9,
	UserDataRequest_WILDCARDEDPUBLICIDENTITY	= 10,
	UserDataRequest_WILDCARDEDIMPU	= 11,
	UserDataRequest_SERVERNAME	= 12,
	UserDataRequest_SERVICEINDICATION	= 13,
	UserDataRequest_DATAREFERENCE	= 14,
	UserDataRequest_IDENTITYSET	= 15,
	UserDataRequest_REQUESTEDDOMAIN	= 16,
	UserDataRequest_CURRENTLOCATION	= 17,
	UserDataRequest_DSAITAG	= 18,
	UserDataRequest_SESSIONPRIORITY	= 19,
	UserDataRequest_USERNAME	= 20,
	UserDataRequest_REQUESTEDNODES	= 21,
	UserDataRequest_SERVINGNODEINDICATION	= 22,
	UserDataRequest_PREPAGINGSUPPORTED	= 23,
	UserDataRequest_LOCALTIMEZONEINDICATION	= 24,
	UserDataRequest_UDRFLAGS	= 25,
	UserDataRequest_CALLREFERENCEINFO	= 26,
	UserDataRequest_OCSUPPORTEDFEATURES	= 27,
	UserDataRequest_PROXYINFO	= 28,
	UserDataRequest_ROUTERECORD	= 29,
}UserDataRequest_tags;

		//! Class Definition
		/*!		ClassName is UserDataRequest
		*/
class UserDataRequest : public DiameterBase 
{
	private:

		bitset<30> mTagsPresent;

		bitset<30> mMandatoryAvpCheckVal;

		bitset<30> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		DRMP*		mDRMP;

		AuthSessionState*		mAuthSessionState;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		OctetString*		mDestinationHost;

		OctetString*		mDestinationRealm;

		OctetString*		mWildcardedPublicIdentity;

		OctetString*		mWildcardedIMPU;

		OctetString*		mServerName;

		list<OctetString*>* 		mServiceIndicationList;

		list<OctetString*>::iterator 		mServiceIndicationIterator;

		list<DataReference*>* 		mDataReferenceList;

		list<DataReference*>::iterator 		mDataReferenceIterator;

		list<IdentitySet*>* 		mIdentitySetList;

		list<IdentitySet*>::iterator 		mIdentitySetIterator;

		RequestedDomain*		mRequestedDomain;

		CurrentLocation*		mCurrentLocation;

		list<OctetString*>* 		mDSAITagList;

		list<OctetString*>::iterator 		mDSAITagIterator;

		SessionPriority*		mSessionPriority;

		OctetString*		mUserName;

		Unsigned32*		mRequestedNodes;

		ServingNodeIndication*		mServingNodeIndication;

		PrepagingSupported*		mPrepagingSupported;

		LocalTimeZoneIndication*		mLocalTimeZoneIndication;

		Unsigned32*		mUDRFlags;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;




		VendorSpecificApplicationId*	mVendorSpecificApplicationIdGrp;






		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;

		UserIdentity*	mUserIdentityGrp;

















		CallReferenceInfo*	mCallReferenceInfoGrp;

		OCSupportedFeatures*	mOCSupportedFeaturesGrp;

		list<SH::ProxyInfo*>*	mProxyInfoGrpList;
		list<SH::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		UserDataRequest();

		UserDataRequest(const UserDataRequest &objUserDataRequest) {

		mTagsPresent = objUserDataRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objUserDataRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUserDataRequest.mMandatoryAvpSetVal;

		mTag = objUserDataRequest.mTag;

		mDecodeFlag = objUserDataRequest.mDecodeFlag;

		if(objUserDataRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objUserDataRequest.mSessionId));

		if(objUserDataRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objUserDataRequest.mDRMP));

		if(objUserDataRequest.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objUserDataRequest.mVendorSpecificApplicationIdGrp);
		 }
		if(objUserDataRequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objUserDataRequest.mAuthSessionState));

		if(objUserDataRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objUserDataRequest.mOriginHost));

		if(objUserDataRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objUserDataRequest.mOriginRealm));

		if(objUserDataRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objUserDataRequest.mDestinationHost));

		if(objUserDataRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objUserDataRequest.mDestinationRealm));

		if(objUserDataRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objUserDataRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objUserDataRequest.mUserIdentityGrp != NULL)
		 {
				 mUserIdentityGrp =  new UserIdentity(*objUserDataRequest.mUserIdentityGrp);
		 }
		if(objUserDataRequest.mWildcardedPublicIdentity != NULL)
		mWildcardedPublicIdentity = new OctetString(*(objUserDataRequest.mWildcardedPublicIdentity));

		if(objUserDataRequest.mWildcardedIMPU != NULL)
		mWildcardedIMPU = new OctetString(*(objUserDataRequest.mWildcardedIMPU));

		if(objUserDataRequest.mServerName != NULL)
		mServerName = new OctetString(*(objUserDataRequest.mServerName));

		if(objUserDataRequest.mRequestedDomain != NULL)
		mRequestedDomain = new RequestedDomain(*(objUserDataRequest.mRequestedDomain));

		if(objUserDataRequest.mCurrentLocation != NULL)
		mCurrentLocation = new CurrentLocation(*(objUserDataRequest.mCurrentLocation));

		if(objUserDataRequest.mSessionPriority != NULL)
		mSessionPriority = new SessionPriority(*(objUserDataRequest.mSessionPriority));

		if(objUserDataRequest.mUserName != NULL)
		mUserName = new OctetString(*(objUserDataRequest.mUserName));

		if(objUserDataRequest.mRequestedNodes != NULL)
		mRequestedNodes = new Unsigned32(*(objUserDataRequest.mRequestedNodes));

		if(objUserDataRequest.mServingNodeIndication != NULL)
		mServingNodeIndication = new ServingNodeIndication(*(objUserDataRequest.mServingNodeIndication));

		if(objUserDataRequest.mPrepagingSupported != NULL)
		mPrepagingSupported = new PrepagingSupported(*(objUserDataRequest.mPrepagingSupported));

		if(objUserDataRequest.mLocalTimeZoneIndication != NULL)
		mLocalTimeZoneIndication = new LocalTimeZoneIndication(*(objUserDataRequest.mLocalTimeZoneIndication));

		if(objUserDataRequest.mUDRFlags != NULL)
		mUDRFlags = new Unsigned32(*(objUserDataRequest.mUDRFlags));

		if(objUserDataRequest.mCallReferenceInfoGrp != NULL)
		 {
				 mCallReferenceInfoGrp =  new CallReferenceInfo(*objUserDataRequest.mCallReferenceInfoGrp);
		 }
		if(objUserDataRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objUserDataRequest.mOCSupportedFeaturesGrp);
		 }
		if(objUserDataRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SH::ProxyInfo*>;
		 for( auto element : *objUserDataRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const UserDataRequest &objUserDataRequest) {

		mTagsPresent = objUserDataRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objUserDataRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUserDataRequest.mMandatoryAvpSetVal;

		mTag = objUserDataRequest.mTag;

		mDecodeFlag = objUserDataRequest.mDecodeFlag;

		if(objUserDataRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objUserDataRequest.mSessionId));

		if(objUserDataRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objUserDataRequest.mDRMP));

		if(objUserDataRequest.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objUserDataRequest.mVendorSpecificApplicationIdGrp);
		 }
		if(objUserDataRequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objUserDataRequest.mAuthSessionState));

		if(objUserDataRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objUserDataRequest.mOriginHost));

		if(objUserDataRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objUserDataRequest.mOriginRealm));

		if(objUserDataRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objUserDataRequest.mDestinationHost));

		if(objUserDataRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objUserDataRequest.mDestinationRealm));

		if(objUserDataRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objUserDataRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objUserDataRequest.mUserIdentityGrp != NULL)
		 {
				 mUserIdentityGrp =  new UserIdentity(*objUserDataRequest.mUserIdentityGrp);
		 }
		if(objUserDataRequest.mWildcardedPublicIdentity != NULL)
		mWildcardedPublicIdentity = new OctetString(*(objUserDataRequest.mWildcardedPublicIdentity));

		if(objUserDataRequest.mWildcardedIMPU != NULL)
		mWildcardedIMPU = new OctetString(*(objUserDataRequest.mWildcardedIMPU));

		if(objUserDataRequest.mServerName != NULL)
		mServerName = new OctetString(*(objUserDataRequest.mServerName));

		if(objUserDataRequest.mRequestedDomain != NULL)
		mRequestedDomain = new RequestedDomain(*(objUserDataRequest.mRequestedDomain));

		if(objUserDataRequest.mCurrentLocation != NULL)
		mCurrentLocation = new CurrentLocation(*(objUserDataRequest.mCurrentLocation));

		if(objUserDataRequest.mSessionPriority != NULL)
		mSessionPriority = new SessionPriority(*(objUserDataRequest.mSessionPriority));

		if(objUserDataRequest.mUserName != NULL)
		mUserName = new OctetString(*(objUserDataRequest.mUserName));

		if(objUserDataRequest.mRequestedNodes != NULL)
		mRequestedNodes = new Unsigned32(*(objUserDataRequest.mRequestedNodes));

		if(objUserDataRequest.mServingNodeIndication != NULL)
		mServingNodeIndication = new ServingNodeIndication(*(objUserDataRequest.mServingNodeIndication));

		if(objUserDataRequest.mPrepagingSupported != NULL)
		mPrepagingSupported = new PrepagingSupported(*(objUserDataRequest.mPrepagingSupported));

		if(objUserDataRequest.mLocalTimeZoneIndication != NULL)
		mLocalTimeZoneIndication = new LocalTimeZoneIndication(*(objUserDataRequest.mLocalTimeZoneIndication));

		if(objUserDataRequest.mUDRFlags != NULL)
		mUDRFlags = new Unsigned32(*(objUserDataRequest.mUDRFlags));

		if(objUserDataRequest.mCallReferenceInfoGrp != NULL)
		 {
				 mCallReferenceInfoGrp =  new CallReferenceInfo(*objUserDataRequest.mCallReferenceInfoGrp);
		 }
		if(objUserDataRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objUserDataRequest.mOCSupportedFeaturesGrp);
		 }
		if(objUserDataRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SH::ProxyInfo*>;
		 for( auto element : *objUserDataRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~UserDataRequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype UserDataRequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype UserDataRequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype UserDataRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype UserDataRequest
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype UserDataRequest
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype UserDataRequest
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		VendorSpecificApplicationId* getVendorSpecificApplicationId();

		VendorSpecificApplicationId* setVendorSpecificApplicationId();

		void resetVendorSpecificApplicationId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype UserDataRequest
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype UserDataRequest
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype UserDataRequest
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype UserDataRequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype UserDataRequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype UserDataRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype UserDataRequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype UserDataRequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype UserDataRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationHost for datatype UserDataRequest
		*/
		OctetString* setDestinationHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationHost for datatype UserDataRequest
		*/
		void resetDestinationHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationHost for datatype UserDataRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationRealm for datatype UserDataRequest
		*/
		OctetString* setDestinationRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationRealm for datatype UserDataRequest
		*/
		void resetDestinationRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationRealm for datatype UserDataRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationRealm();

		list<SupportedFeatures*>* getSupportedFeaturesGrpList();

		list<SupportedFeatures*>* setSupportedFeaturesGrpList();

		void resetSupportedFeaturesGrpList();

		UserIdentity* getUserIdentity();

		UserIdentity* setUserIdentity();

		void resetUserIdentity();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument WildcardedPublicIdentity for datatype UserDataRequest
		*/
		OctetString* setWildcardedPublicIdentity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument WildcardedPublicIdentity for datatype UserDataRequest
		*/
		void resetWildcardedPublicIdentity();

		//!Function to get values
		/*!		Function to get OctetString type of argument WildcardedPublicIdentity for datatype UserDataRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getWildcardedPublicIdentity();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument WildcardedIMPU for datatype UserDataRequest
		*/
		OctetString* setWildcardedIMPU();

		//! Function to reset 
		/*!		Function to reset NULL type of argument WildcardedIMPU for datatype UserDataRequest
		*/
		void resetWildcardedIMPU();

		//!Function to get values
		/*!		Function to get OctetString type of argument WildcardedIMPU for datatype UserDataRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getWildcardedIMPU();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ServerName for datatype UserDataRequest
		*/
		OctetString* setServerName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ServerName for datatype UserDataRequest
		*/
		void resetServerName();

		//!Function to get values
		/*!		Function to get OctetString type of argument ServerName for datatype UserDataRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getServerName();

		list<OctetString*>* getServiceIndicationList();

		list<OctetString*>* setServiceIndicationList();

		void resetServiceIndicationList();

		list<DataReference*>* getDataReferenceList();

		list<DataReference*>* setDataReferenceList();

		void resetDataReferenceList();

		list<IdentitySet*>* getIdentitySetList();

		list<IdentitySet*>* setIdentitySetList();

		void resetIdentitySetList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument RequestedDomain for datatype UserDataRequest
		*/
		RequestedDomain* setRequestedDomain();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RequestedDomain for datatype UserDataRequest
		*/
		void resetRequestedDomain();

		//!Function to get values
		/*!		Function to get RequestedDomain type of argument RequestedDomain for datatype UserDataRequest
		Throws exception of which type and Summary of Exception
		*/
		RequestedDomain* getRequestedDomain();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument CurrentLocation for datatype UserDataRequest
		*/
		CurrentLocation* setCurrentLocation();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CurrentLocation for datatype UserDataRequest
		*/
		void resetCurrentLocation();

		//!Function to get values
		/*!		Function to get CurrentLocation type of argument CurrentLocation for datatype UserDataRequest
		Throws exception of which type and Summary of Exception
		*/
		CurrentLocation* getCurrentLocation();

		list<OctetString*>* getDSAITagList();

		list<OctetString*>* setDSAITagList();

		void resetDSAITagList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument SessionPriority for datatype UserDataRequest
		*/
		SessionPriority* setSessionPriority();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionPriority for datatype UserDataRequest
		*/
		void resetSessionPriority();

		//!Function to get values
		/*!		Function to get SessionPriority type of argument SessionPriority for datatype UserDataRequest
		Throws exception of which type and Summary of Exception
		*/
		SessionPriority* getSessionPriority();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserName for datatype UserDataRequest
		*/
		OctetString* setUserName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserName for datatype UserDataRequest
		*/
		void resetUserName();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserName for datatype UserDataRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserName();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument RequestedNodes for datatype UserDataRequest
		*/
		Unsigned32* setRequestedNodes();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RequestedNodes for datatype UserDataRequest
		*/
		void resetRequestedNodes();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument RequestedNodes for datatype UserDataRequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getRequestedNodes();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument ServingNodeIndication for datatype UserDataRequest
		*/
		ServingNodeIndication* setServingNodeIndication();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ServingNodeIndication for datatype UserDataRequest
		*/
		void resetServingNodeIndication();

		//!Function to get values
		/*!		Function to get ServingNodeIndication type of argument ServingNodeIndication for datatype UserDataRequest
		Throws exception of which type and Summary of Exception
		*/
		ServingNodeIndication* getServingNodeIndication();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument PrepagingSupported for datatype UserDataRequest
		*/
		PrepagingSupported* setPrepagingSupported();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PrepagingSupported for datatype UserDataRequest
		*/
		void resetPrepagingSupported();

		//!Function to get values
		/*!		Function to get PrepagingSupported type of argument PrepagingSupported for datatype UserDataRequest
		Throws exception of which type and Summary of Exception
		*/
		PrepagingSupported* getPrepagingSupported();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument LocalTimeZoneIndication for datatype UserDataRequest
		*/
		LocalTimeZoneIndication* setLocalTimeZoneIndication();

		//! Function to reset 
		/*!		Function to reset NULL type of argument LocalTimeZoneIndication for datatype UserDataRequest
		*/
		void resetLocalTimeZoneIndication();

		//!Function to get values
		/*!		Function to get LocalTimeZoneIndication type of argument LocalTimeZoneIndication for datatype UserDataRequest
		Throws exception of which type and Summary of Exception
		*/
		LocalTimeZoneIndication* getLocalTimeZoneIndication();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument UDRFlags for datatype UserDataRequest
		*/
		Unsigned32* setUDRFlags();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UDRFlags for datatype UserDataRequest
		*/
		void resetUDRFlags();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument UDRFlags for datatype UserDataRequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getUDRFlags();

		CallReferenceInfo* getCallReferenceInfo();

		CallReferenceInfo* setCallReferenceInfo();

		void resetCallReferenceInfo();

		OCSupportedFeatures* getOCSupportedFeatures();

		OCSupportedFeatures* setOCSupportedFeatures();

		void resetOCSupportedFeatures();

		list<SH::ProxyInfo*>* getProxyInfoGrpList();

		list<SH::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		//! Function to Decode
		/*!		Function to Decode datatype UserDataRequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype UserDataRequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype UserDataRequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype UserDataRequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype UserDataRequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
