#ifndef SH_PUSHNOTIFICATIONREQUEST_H
#define SH_PUSHNOTIFICATIONREQUEST_H
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
#include "sh/include/ProxyInfo.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace SH{
typedef enum _tags_PushNotificationRequest
{
	PushNotificationRequest_SESSIONID	= 0,
	PushNotificationRequest_DRMP	= 1,
	PushNotificationRequest_VENDORSPECIFICAPPLICATIONID	= 2,
	PushNotificationRequest_AUTHSESSIONSTATE	= 3,
	PushNotificationRequest_ORIGINHOST	= 4,
	PushNotificationRequest_ORIGINREALM	= 5,
	PushNotificationRequest_DESTINATIONHOST	= 6,
	PushNotificationRequest_DESTINATIONREALM	= 7,
	PushNotificationRequest_SUPPORTEDFEATURES	= 8,
	PushNotificationRequest_USERIDENTITY	= 9,
	PushNotificationRequest_WILDCARDEDPUBLICIDENTITY	= 10,
	PushNotificationRequest_WILDCARDEDIMPU	= 11,
	PushNotificationRequest_USERNAME	= 12,
	PushNotificationRequest_USERDATA	= 13,
	PushNotificationRequest_PROXYINFO	= 14,
	PushNotificationRequest_ROUTERECORD	= 15,
}PushNotificationRequest_tags;

		//! Class Definition
		/*!		ClassName is PushNotificationRequest
		*/
class PushNotificationRequest : public DiameterBase 
{
	private:

		bitset<16> mTagsPresent;

		bitset<16> mMandatoryAvpCheckVal;

		bitset<16> mMandatoryAvpSetVal;

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

		OctetString*		mUserName;

		OctetString*		mUserData;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;




		VendorSpecificApplicationId*	mVendorSpecificApplicationIdGrp;






		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;

		UserIdentity*	mUserIdentityGrp;





		list<SH::ProxyInfo*>*	mProxyInfoGrpList;
		list<SH::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		PushNotificationRequest();

		PushNotificationRequest(const PushNotificationRequest &objPushNotificationRequest) {

		mTagsPresent = objPushNotificationRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objPushNotificationRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objPushNotificationRequest.mMandatoryAvpSetVal;

		mTag = objPushNotificationRequest.mTag;

		mDecodeFlag = objPushNotificationRequest.mDecodeFlag;

		if(objPushNotificationRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objPushNotificationRequest.mSessionId));

		if(objPushNotificationRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objPushNotificationRequest.mDRMP));

		if(objPushNotificationRequest.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objPushNotificationRequest.mVendorSpecificApplicationIdGrp);
		 }
		if(objPushNotificationRequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objPushNotificationRequest.mAuthSessionState));

		if(objPushNotificationRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objPushNotificationRequest.mOriginHost));

		if(objPushNotificationRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objPushNotificationRequest.mOriginRealm));

		if(objPushNotificationRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objPushNotificationRequest.mDestinationHost));

		if(objPushNotificationRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objPushNotificationRequest.mDestinationRealm));

		if(objPushNotificationRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objPushNotificationRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objPushNotificationRequest.mUserIdentityGrp != NULL)
		 {
				 mUserIdentityGrp =  new UserIdentity(*objPushNotificationRequest.mUserIdentityGrp);
		 }
		if(objPushNotificationRequest.mWildcardedPublicIdentity != NULL)
		mWildcardedPublicIdentity = new OctetString(*(objPushNotificationRequest.mWildcardedPublicIdentity));

		if(objPushNotificationRequest.mWildcardedIMPU != NULL)
		mWildcardedIMPU = new OctetString(*(objPushNotificationRequest.mWildcardedIMPU));

		if(objPushNotificationRequest.mUserName != NULL)
		mUserName = new OctetString(*(objPushNotificationRequest.mUserName));

		if(objPushNotificationRequest.mUserData != NULL)
		mUserData = new OctetString(*(objPushNotificationRequest.mUserData));

		if(objPushNotificationRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SH::ProxyInfo*>;
		 for( auto element : *objPushNotificationRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const PushNotificationRequest &objPushNotificationRequest) {

		mTagsPresent = objPushNotificationRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objPushNotificationRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objPushNotificationRequest.mMandatoryAvpSetVal;

		mTag = objPushNotificationRequest.mTag;

		mDecodeFlag = objPushNotificationRequest.mDecodeFlag;

		if(objPushNotificationRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objPushNotificationRequest.mSessionId));

		if(objPushNotificationRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objPushNotificationRequest.mDRMP));

		if(objPushNotificationRequest.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objPushNotificationRequest.mVendorSpecificApplicationIdGrp);
		 }
		if(objPushNotificationRequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objPushNotificationRequest.mAuthSessionState));

		if(objPushNotificationRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objPushNotificationRequest.mOriginHost));

		if(objPushNotificationRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objPushNotificationRequest.mOriginRealm));

		if(objPushNotificationRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objPushNotificationRequest.mDestinationHost));

		if(objPushNotificationRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objPushNotificationRequest.mDestinationRealm));

		if(objPushNotificationRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objPushNotificationRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objPushNotificationRequest.mUserIdentityGrp != NULL)
		 {
				 mUserIdentityGrp =  new UserIdentity(*objPushNotificationRequest.mUserIdentityGrp);
		 }
		if(objPushNotificationRequest.mWildcardedPublicIdentity != NULL)
		mWildcardedPublicIdentity = new OctetString(*(objPushNotificationRequest.mWildcardedPublicIdentity));

		if(objPushNotificationRequest.mWildcardedIMPU != NULL)
		mWildcardedIMPU = new OctetString(*(objPushNotificationRequest.mWildcardedIMPU));

		if(objPushNotificationRequest.mUserName != NULL)
		mUserName = new OctetString(*(objPushNotificationRequest.mUserName));

		if(objPushNotificationRequest.mUserData != NULL)
		mUserData = new OctetString(*(objPushNotificationRequest.mUserData));

		if(objPushNotificationRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SH::ProxyInfo*>;
		 for( auto element : *objPushNotificationRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~PushNotificationRequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype PushNotificationRequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype PushNotificationRequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype PushNotificationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype PushNotificationRequest
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype PushNotificationRequest
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype PushNotificationRequest
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		VendorSpecificApplicationId* getVendorSpecificApplicationId();

		VendorSpecificApplicationId* setVendorSpecificApplicationId();

		void resetVendorSpecificApplicationId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype PushNotificationRequest
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype PushNotificationRequest
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype PushNotificationRequest
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype PushNotificationRequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype PushNotificationRequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype PushNotificationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype PushNotificationRequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype PushNotificationRequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype PushNotificationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationHost for datatype PushNotificationRequest
		*/
		OctetString* setDestinationHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationHost for datatype PushNotificationRequest
		*/
		void resetDestinationHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationHost for datatype PushNotificationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationRealm for datatype PushNotificationRequest
		*/
		OctetString* setDestinationRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationRealm for datatype PushNotificationRequest
		*/
		void resetDestinationRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationRealm for datatype PushNotificationRequest
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
		/*!		Function to set the recent OctetString type of argument WildcardedPublicIdentity for datatype PushNotificationRequest
		*/
		OctetString* setWildcardedPublicIdentity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument WildcardedPublicIdentity for datatype PushNotificationRequest
		*/
		void resetWildcardedPublicIdentity();

		//!Function to get values
		/*!		Function to get OctetString type of argument WildcardedPublicIdentity for datatype PushNotificationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getWildcardedPublicIdentity();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument WildcardedIMPU for datatype PushNotificationRequest
		*/
		OctetString* setWildcardedIMPU();

		//! Function to reset 
		/*!		Function to reset NULL type of argument WildcardedIMPU for datatype PushNotificationRequest
		*/
		void resetWildcardedIMPU();

		//!Function to get values
		/*!		Function to get OctetString type of argument WildcardedIMPU for datatype PushNotificationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getWildcardedIMPU();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserName for datatype PushNotificationRequest
		*/
		OctetString* setUserName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserName for datatype PushNotificationRequest
		*/
		void resetUserName();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserName for datatype PushNotificationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserName();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserData for datatype PushNotificationRequest
		*/
		OctetString* setUserData();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserData for datatype PushNotificationRequest
		*/
		void resetUserData();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserData for datatype PushNotificationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserData();

		list<SH::ProxyInfo*>* getProxyInfoGrpList();

		list<SH::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		//! Function to Decode
		/*!		Function to Decode datatype PushNotificationRequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype PushNotificationRequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype PushNotificationRequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype PushNotificationRequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype PushNotificationRequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
