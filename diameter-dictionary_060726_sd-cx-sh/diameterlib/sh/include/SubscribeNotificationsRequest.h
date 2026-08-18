#ifndef SH_SUBSCRIBENOTIFICATIONSREQUEST_H
#define SH_SUBSCRIBENOTIFICATIONSREQUEST_H
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
#include "sh/include/SendDataIndication.h"
#include "sh/include/SubsReqType.h"
#include "sh/include/DataReference.h"
#include "sh/include/IdentitySet.h"
#include "sh/include/OneTimeNotification.h"
#include "sh/include/OCSupportedFeatures.h"
#include "sh/include/ProxyInfo.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace SH{
typedef enum _tags_SubscribeNotificationsRequest
{
	SubscribeNotificationsRequest_SESSIONID	= 0,
	SubscribeNotificationsRequest_DRMP	= 1,
	SubscribeNotificationsRequest_VENDORSPECIFICAPPLICATIONID	= 2,
	SubscribeNotificationsRequest_AUTHSESSIONSTATE	= 3,
	SubscribeNotificationsRequest_ORIGINHOST	= 4,
	SubscribeNotificationsRequest_ORIGINREALM	= 5,
	SubscribeNotificationsRequest_DESTINATIONHOST	= 6,
	SubscribeNotificationsRequest_DESTINATIONREALM	= 7,
	SubscribeNotificationsRequest_SUPPORTEDFEATURES	= 8,
	SubscribeNotificationsRequest_USERIDENTITY	= 9,
	SubscribeNotificationsRequest_WILDCARDEDPUBLICIDENTITY	= 10,
	SubscribeNotificationsRequest_WILDCARDEDIMPU	= 11,
	SubscribeNotificationsRequest_SERVICEINDICATION	= 12,
	SubscribeNotificationsRequest_SENDDATAINDICATION	= 13,
	SubscribeNotificationsRequest_SERVERNAME	= 14,
	SubscribeNotificationsRequest_SUBSREQTYPE	= 15,
	SubscribeNotificationsRequest_DATAREFERENCE	= 16,
	SubscribeNotificationsRequest_IDENTITYSET	= 17,
	SubscribeNotificationsRequest_EXPIRYTIME	= 18,
	SubscribeNotificationsRequest_DSAITAG	= 19,
	SubscribeNotificationsRequest_ONETIMENOTIFICATION	= 20,
	SubscribeNotificationsRequest_USERNAME	= 21,
	SubscribeNotificationsRequest_OCSUPPORTEDFEATURES	= 22,
	SubscribeNotificationsRequest_PROXYINFO	= 23,
	SubscribeNotificationsRequest_ROUTERECORD	= 24,
}SubscribeNotificationsRequest_tags;

		//! Class Definition
		/*!		ClassName is SubscribeNotificationsRequest
		*/
class SubscribeNotificationsRequest : public DiameterBase 
{
	private:

		bitset<25> mTagsPresent;

		bitset<25> mMandatoryAvpCheckVal;

		bitset<25> mMandatoryAvpSetVal;

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

		list<OctetString*>* 		mServiceIndicationList;

		list<OctetString*>::iterator 		mServiceIndicationIterator;

		SendDataIndication*		mSendDataIndication;

		OctetString*		mServerName;

		SubsReqType*		mSubsReqType;

		list<DataReference*>* 		mDataReferenceList;

		list<DataReference*>::iterator 		mDataReferenceIterator;

		list<IdentitySet*>* 		mIdentitySetList;

		list<IdentitySet*>::iterator 		mIdentitySetIterator;

		Time*		mExpiryTime;

		list<OctetString*>* 		mDSAITagList;

		list<OctetString*>::iterator 		mDSAITagIterator;

		OneTimeNotification*		mOneTimeNotification;

		OctetString*		mUserName;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;




		VendorSpecificApplicationId*	mVendorSpecificApplicationIdGrp;






		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;

		UserIdentity*	mUserIdentityGrp;













		OCSupportedFeatures*	mOCSupportedFeaturesGrp;

		list<SH::ProxyInfo*>*	mProxyInfoGrpList;
		list<SH::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		SubscribeNotificationsRequest();

		SubscribeNotificationsRequest(const SubscribeNotificationsRequest &objSubscribeNotificationsRequest) {

		mTagsPresent = objSubscribeNotificationsRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objSubscribeNotificationsRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSubscribeNotificationsRequest.mMandatoryAvpSetVal;

		mTag = objSubscribeNotificationsRequest.mTag;

		mDecodeFlag = objSubscribeNotificationsRequest.mDecodeFlag;

		if(objSubscribeNotificationsRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objSubscribeNotificationsRequest.mSessionId));

		if(objSubscribeNotificationsRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objSubscribeNotificationsRequest.mDRMP));

		if(objSubscribeNotificationsRequest.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objSubscribeNotificationsRequest.mVendorSpecificApplicationIdGrp);
		 }
		if(objSubscribeNotificationsRequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objSubscribeNotificationsRequest.mAuthSessionState));

		if(objSubscribeNotificationsRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objSubscribeNotificationsRequest.mOriginHost));

		if(objSubscribeNotificationsRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objSubscribeNotificationsRequest.mOriginRealm));

		if(objSubscribeNotificationsRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objSubscribeNotificationsRequest.mDestinationHost));

		if(objSubscribeNotificationsRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objSubscribeNotificationsRequest.mDestinationRealm));

		if(objSubscribeNotificationsRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objSubscribeNotificationsRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objSubscribeNotificationsRequest.mUserIdentityGrp != NULL)
		 {
				 mUserIdentityGrp =  new UserIdentity(*objSubscribeNotificationsRequest.mUserIdentityGrp);
		 }
		if(objSubscribeNotificationsRequest.mWildcardedPublicIdentity != NULL)
		mWildcardedPublicIdentity = new OctetString(*(objSubscribeNotificationsRequest.mWildcardedPublicIdentity));

		if(objSubscribeNotificationsRequest.mWildcardedIMPU != NULL)
		mWildcardedIMPU = new OctetString(*(objSubscribeNotificationsRequest.mWildcardedIMPU));

		if(objSubscribeNotificationsRequest.mSendDataIndication != NULL)
		mSendDataIndication = new SendDataIndication(*(objSubscribeNotificationsRequest.mSendDataIndication));

		if(objSubscribeNotificationsRequest.mServerName != NULL)
		mServerName = new OctetString(*(objSubscribeNotificationsRequest.mServerName));

		if(objSubscribeNotificationsRequest.mSubsReqType != NULL)
		mSubsReqType = new SubsReqType(*(objSubscribeNotificationsRequest.mSubsReqType));

		if(objSubscribeNotificationsRequest.mExpiryTime != NULL)
		mExpiryTime = new Time(*(objSubscribeNotificationsRequest.mExpiryTime));

		if(objSubscribeNotificationsRequest.mOneTimeNotification != NULL)
		mOneTimeNotification = new OneTimeNotification(*(objSubscribeNotificationsRequest.mOneTimeNotification));

		if(objSubscribeNotificationsRequest.mUserName != NULL)
		mUserName = new OctetString(*(objSubscribeNotificationsRequest.mUserName));

		if(objSubscribeNotificationsRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objSubscribeNotificationsRequest.mOCSupportedFeaturesGrp);
		 }
		if(objSubscribeNotificationsRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SH::ProxyInfo*>;
		 for( auto element : *objSubscribeNotificationsRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const SubscribeNotificationsRequest &objSubscribeNotificationsRequest) {

		mTagsPresent = objSubscribeNotificationsRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objSubscribeNotificationsRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSubscribeNotificationsRequest.mMandatoryAvpSetVal;

		mTag = objSubscribeNotificationsRequest.mTag;

		mDecodeFlag = objSubscribeNotificationsRequest.mDecodeFlag;

		if(objSubscribeNotificationsRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objSubscribeNotificationsRequest.mSessionId));

		if(objSubscribeNotificationsRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objSubscribeNotificationsRequest.mDRMP));

		if(objSubscribeNotificationsRequest.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objSubscribeNotificationsRequest.mVendorSpecificApplicationIdGrp);
		 }
		if(objSubscribeNotificationsRequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objSubscribeNotificationsRequest.mAuthSessionState));

		if(objSubscribeNotificationsRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objSubscribeNotificationsRequest.mOriginHost));

		if(objSubscribeNotificationsRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objSubscribeNotificationsRequest.mOriginRealm));

		if(objSubscribeNotificationsRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objSubscribeNotificationsRequest.mDestinationHost));

		if(objSubscribeNotificationsRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objSubscribeNotificationsRequest.mDestinationRealm));

		if(objSubscribeNotificationsRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objSubscribeNotificationsRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objSubscribeNotificationsRequest.mUserIdentityGrp != NULL)
		 {
				 mUserIdentityGrp =  new UserIdentity(*objSubscribeNotificationsRequest.mUserIdentityGrp);
		 }
		if(objSubscribeNotificationsRequest.mWildcardedPublicIdentity != NULL)
		mWildcardedPublicIdentity = new OctetString(*(objSubscribeNotificationsRequest.mWildcardedPublicIdentity));

		if(objSubscribeNotificationsRequest.mWildcardedIMPU != NULL)
		mWildcardedIMPU = new OctetString(*(objSubscribeNotificationsRequest.mWildcardedIMPU));

		if(objSubscribeNotificationsRequest.mSendDataIndication != NULL)
		mSendDataIndication = new SendDataIndication(*(objSubscribeNotificationsRequest.mSendDataIndication));

		if(objSubscribeNotificationsRequest.mServerName != NULL)
		mServerName = new OctetString(*(objSubscribeNotificationsRequest.mServerName));

		if(objSubscribeNotificationsRequest.mSubsReqType != NULL)
		mSubsReqType = new SubsReqType(*(objSubscribeNotificationsRequest.mSubsReqType));

		if(objSubscribeNotificationsRequest.mExpiryTime != NULL)
		mExpiryTime = new Time(*(objSubscribeNotificationsRequest.mExpiryTime));

		if(objSubscribeNotificationsRequest.mOneTimeNotification != NULL)
		mOneTimeNotification = new OneTimeNotification(*(objSubscribeNotificationsRequest.mOneTimeNotification));

		if(objSubscribeNotificationsRequest.mUserName != NULL)
		mUserName = new OctetString(*(objSubscribeNotificationsRequest.mUserName));

		if(objSubscribeNotificationsRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objSubscribeNotificationsRequest.mOCSupportedFeaturesGrp);
		 }
		if(objSubscribeNotificationsRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SH::ProxyInfo*>;
		 for( auto element : *objSubscribeNotificationsRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~SubscribeNotificationsRequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype SubscribeNotificationsRequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype SubscribeNotificationsRequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype SubscribeNotificationsRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype SubscribeNotificationsRequest
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype SubscribeNotificationsRequest
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype SubscribeNotificationsRequest
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		VendorSpecificApplicationId* getVendorSpecificApplicationId();

		VendorSpecificApplicationId* setVendorSpecificApplicationId();

		void resetVendorSpecificApplicationId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype SubscribeNotificationsRequest
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype SubscribeNotificationsRequest
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype SubscribeNotificationsRequest
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype SubscribeNotificationsRequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype SubscribeNotificationsRequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype SubscribeNotificationsRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype SubscribeNotificationsRequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype SubscribeNotificationsRequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype SubscribeNotificationsRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationHost for datatype SubscribeNotificationsRequest
		*/
		OctetString* setDestinationHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationHost for datatype SubscribeNotificationsRequest
		*/
		void resetDestinationHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationHost for datatype SubscribeNotificationsRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationRealm for datatype SubscribeNotificationsRequest
		*/
		OctetString* setDestinationRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationRealm for datatype SubscribeNotificationsRequest
		*/
		void resetDestinationRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationRealm for datatype SubscribeNotificationsRequest
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
		/*!		Function to set the recent OctetString type of argument WildcardedPublicIdentity for datatype SubscribeNotificationsRequest
		*/
		OctetString* setWildcardedPublicIdentity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument WildcardedPublicIdentity for datatype SubscribeNotificationsRequest
		*/
		void resetWildcardedPublicIdentity();

		//!Function to get values
		/*!		Function to get OctetString type of argument WildcardedPublicIdentity for datatype SubscribeNotificationsRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getWildcardedPublicIdentity();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument WildcardedIMPU for datatype SubscribeNotificationsRequest
		*/
		OctetString* setWildcardedIMPU();

		//! Function to reset 
		/*!		Function to reset NULL type of argument WildcardedIMPU for datatype SubscribeNotificationsRequest
		*/
		void resetWildcardedIMPU();

		//!Function to get values
		/*!		Function to get OctetString type of argument WildcardedIMPU for datatype SubscribeNotificationsRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getWildcardedIMPU();

		list<OctetString*>* getServiceIndicationList();

		list<OctetString*>* setServiceIndicationList();

		void resetServiceIndicationList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument SendDataIndication for datatype SubscribeNotificationsRequest
		*/
		SendDataIndication* setSendDataIndication();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SendDataIndication for datatype SubscribeNotificationsRequest
		*/
		void resetSendDataIndication();

		//!Function to get values
		/*!		Function to get SendDataIndication type of argument SendDataIndication for datatype SubscribeNotificationsRequest
		Throws exception of which type and Summary of Exception
		*/
		SendDataIndication* getSendDataIndication();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ServerName for datatype SubscribeNotificationsRequest
		*/
		OctetString* setServerName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ServerName for datatype SubscribeNotificationsRequest
		*/
		void resetServerName();

		//!Function to get values
		/*!		Function to get OctetString type of argument ServerName for datatype SubscribeNotificationsRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getServerName();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument SubsReqType for datatype SubscribeNotificationsRequest
		*/
		SubsReqType* setSubsReqType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SubsReqType for datatype SubscribeNotificationsRequest
		*/
		void resetSubsReqType();

		//!Function to get values
		/*!		Function to get SubsReqType type of argument SubsReqType for datatype SubscribeNotificationsRequest
		Throws exception of which type and Summary of Exception
		*/
		SubsReqType* getSubsReqType();

		list<DataReference*>* getDataReferenceList();

		list<DataReference*>* setDataReferenceList();

		void resetDataReferenceList();

		list<IdentitySet*>* getIdentitySetList();

		list<IdentitySet*>* setIdentitySetList();

		void resetIdentitySetList();

		//!Function to set values
		/*!		Function to set the recent Time type of argument ExpiryTime for datatype SubscribeNotificationsRequest
		*/
		Time* setExpiryTime();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ExpiryTime for datatype SubscribeNotificationsRequest
		*/
		void resetExpiryTime();

		//!Function to get values
		/*!		Function to get Time type of argument ExpiryTime for datatype SubscribeNotificationsRequest
		Throws exception of which type and Summary of Exception
		*/
		Time* getExpiryTime();

		list<OctetString*>* getDSAITagList();

		list<OctetString*>* setDSAITagList();

		void resetDSAITagList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument OneTimeNotification for datatype SubscribeNotificationsRequest
		*/
		OneTimeNotification* setOneTimeNotification();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OneTimeNotification for datatype SubscribeNotificationsRequest
		*/
		void resetOneTimeNotification();

		//!Function to get values
		/*!		Function to get OneTimeNotification type of argument OneTimeNotification for datatype SubscribeNotificationsRequest
		Throws exception of which type and Summary of Exception
		*/
		OneTimeNotification* getOneTimeNotification();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserName for datatype SubscribeNotificationsRequest
		*/
		OctetString* setUserName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserName for datatype SubscribeNotificationsRequest
		*/
		void resetUserName();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserName for datatype SubscribeNotificationsRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserName();

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
		/*!		Function to Decode datatype SubscribeNotificationsRequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype SubscribeNotificationsRequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype SubscribeNotificationsRequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype SubscribeNotificationsRequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype SubscribeNotificationsRequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
