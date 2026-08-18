#ifndef SH_PROFILEUPDATEREQUEST_H
#define SH_PROFILEUPDATEREQUEST_H
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
#include "sh/include/OCSupportedFeatures.h"
#include "sh/include/ProxyInfo.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace SH{
typedef enum _tags_ProfileUpdateRequest
{
	ProfileUpdateRequest_SESSIONID	= 0,
	ProfileUpdateRequest_DRMP	= 1,
	ProfileUpdateRequest_VENDORSPECIFICAPPLICATIONID	= 2,
	ProfileUpdateRequest_AUTHSESSIONSTATE	= 3,
	ProfileUpdateRequest_ORIGINHOST	= 4,
	ProfileUpdateRequest_ORIGINREALM	= 5,
	ProfileUpdateRequest_DESTINATIONHOST	= 6,
	ProfileUpdateRequest_DESTINATIONREALM	= 7,
	ProfileUpdateRequest_SUPPORTEDFEATURES	= 8,
	ProfileUpdateRequest_USERIDENTITY	= 9,
	ProfileUpdateRequest_WILDCARDEDPUBLICIDENTITY	= 10,
	ProfileUpdateRequest_WILDCARDEDIMPU	= 11,
	ProfileUpdateRequest_USERNAME	= 12,
	ProfileUpdateRequest_DATAREFERENCE	= 13,
	ProfileUpdateRequest_USERDATA	= 14,
	ProfileUpdateRequest_OCSUPPORTEDFEATURES	= 15,
	ProfileUpdateRequest_PROXYINFO	= 16,
	ProfileUpdateRequest_ROUTERECORD	= 17,
}ProfileUpdateRequest_tags;

		//! Class Definition
		/*!		ClassName is ProfileUpdateRequest
		*/
class ProfileUpdateRequest : public DiameterBase 
{
	private:

		bitset<18> mTagsPresent;

		bitset<18> mMandatoryAvpCheckVal;

		bitset<18> mMandatoryAvpSetVal;

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

		list<DataReference*>* 		mDataReferenceList;

		list<DataReference*>::iterator 		mDataReferenceIterator;

		OctetString*		mUserData;

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
		ProfileUpdateRequest();

		ProfileUpdateRequest(const ProfileUpdateRequest &objProfileUpdateRequest) {

		mTagsPresent = objProfileUpdateRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objProfileUpdateRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objProfileUpdateRequest.mMandatoryAvpSetVal;

		mTag = objProfileUpdateRequest.mTag;

		mDecodeFlag = objProfileUpdateRequest.mDecodeFlag;

		if(objProfileUpdateRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objProfileUpdateRequest.mSessionId));

		if(objProfileUpdateRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objProfileUpdateRequest.mDRMP));

		if(objProfileUpdateRequest.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objProfileUpdateRequest.mVendorSpecificApplicationIdGrp);
		 }
		if(objProfileUpdateRequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objProfileUpdateRequest.mAuthSessionState));

		if(objProfileUpdateRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objProfileUpdateRequest.mOriginHost));

		if(objProfileUpdateRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objProfileUpdateRequest.mOriginRealm));

		if(objProfileUpdateRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objProfileUpdateRequest.mDestinationHost));

		if(objProfileUpdateRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objProfileUpdateRequest.mDestinationRealm));

		if(objProfileUpdateRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objProfileUpdateRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objProfileUpdateRequest.mUserIdentityGrp != NULL)
		 {
				 mUserIdentityGrp =  new UserIdentity(*objProfileUpdateRequest.mUserIdentityGrp);
		 }
		if(objProfileUpdateRequest.mWildcardedPublicIdentity != NULL)
		mWildcardedPublicIdentity = new OctetString(*(objProfileUpdateRequest.mWildcardedPublicIdentity));

		if(objProfileUpdateRequest.mWildcardedIMPU != NULL)
		mWildcardedIMPU = new OctetString(*(objProfileUpdateRequest.mWildcardedIMPU));

		if(objProfileUpdateRequest.mUserName != NULL)
		mUserName = new OctetString(*(objProfileUpdateRequest.mUserName));

		if(objProfileUpdateRequest.mUserData != NULL)
		mUserData = new OctetString(*(objProfileUpdateRequest.mUserData));

		if(objProfileUpdateRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objProfileUpdateRequest.mOCSupportedFeaturesGrp);
		 }
		if(objProfileUpdateRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SH::ProxyInfo*>;
		 for( auto element : *objProfileUpdateRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const ProfileUpdateRequest &objProfileUpdateRequest) {

		mTagsPresent = objProfileUpdateRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objProfileUpdateRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objProfileUpdateRequest.mMandatoryAvpSetVal;

		mTag = objProfileUpdateRequest.mTag;

		mDecodeFlag = objProfileUpdateRequest.mDecodeFlag;

		if(objProfileUpdateRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objProfileUpdateRequest.mSessionId));

		if(objProfileUpdateRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objProfileUpdateRequest.mDRMP));

		if(objProfileUpdateRequest.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objProfileUpdateRequest.mVendorSpecificApplicationIdGrp);
		 }
		if(objProfileUpdateRequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objProfileUpdateRequest.mAuthSessionState));

		if(objProfileUpdateRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objProfileUpdateRequest.mOriginHost));

		if(objProfileUpdateRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objProfileUpdateRequest.mOriginRealm));

		if(objProfileUpdateRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objProfileUpdateRequest.mDestinationHost));

		if(objProfileUpdateRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objProfileUpdateRequest.mDestinationRealm));

		if(objProfileUpdateRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objProfileUpdateRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objProfileUpdateRequest.mUserIdentityGrp != NULL)
		 {
				 mUserIdentityGrp =  new UserIdentity(*objProfileUpdateRequest.mUserIdentityGrp);
		 }
		if(objProfileUpdateRequest.mWildcardedPublicIdentity != NULL)
		mWildcardedPublicIdentity = new OctetString(*(objProfileUpdateRequest.mWildcardedPublicIdentity));

		if(objProfileUpdateRequest.mWildcardedIMPU != NULL)
		mWildcardedIMPU = new OctetString(*(objProfileUpdateRequest.mWildcardedIMPU));

		if(objProfileUpdateRequest.mUserName != NULL)
		mUserName = new OctetString(*(objProfileUpdateRequest.mUserName));

		if(objProfileUpdateRequest.mUserData != NULL)
		mUserData = new OctetString(*(objProfileUpdateRequest.mUserData));

		if(objProfileUpdateRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objProfileUpdateRequest.mOCSupportedFeaturesGrp);
		 }
		if(objProfileUpdateRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SH::ProxyInfo*>;
		 for( auto element : *objProfileUpdateRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~ProfileUpdateRequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype ProfileUpdateRequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype ProfileUpdateRequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype ProfileUpdateRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype ProfileUpdateRequest
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype ProfileUpdateRequest
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype ProfileUpdateRequest
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		VendorSpecificApplicationId* getVendorSpecificApplicationId();

		VendorSpecificApplicationId* setVendorSpecificApplicationId();

		void resetVendorSpecificApplicationId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype ProfileUpdateRequest
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype ProfileUpdateRequest
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype ProfileUpdateRequest
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype ProfileUpdateRequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype ProfileUpdateRequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype ProfileUpdateRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype ProfileUpdateRequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype ProfileUpdateRequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype ProfileUpdateRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationHost for datatype ProfileUpdateRequest
		*/
		OctetString* setDestinationHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationHost for datatype ProfileUpdateRequest
		*/
		void resetDestinationHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationHost for datatype ProfileUpdateRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationRealm for datatype ProfileUpdateRequest
		*/
		OctetString* setDestinationRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationRealm for datatype ProfileUpdateRequest
		*/
		void resetDestinationRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationRealm for datatype ProfileUpdateRequest
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
		/*!		Function to set the recent OctetString type of argument WildcardedPublicIdentity for datatype ProfileUpdateRequest
		*/
		OctetString* setWildcardedPublicIdentity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument WildcardedPublicIdentity for datatype ProfileUpdateRequest
		*/
		void resetWildcardedPublicIdentity();

		//!Function to get values
		/*!		Function to get OctetString type of argument WildcardedPublicIdentity for datatype ProfileUpdateRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getWildcardedPublicIdentity();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument WildcardedIMPU for datatype ProfileUpdateRequest
		*/
		OctetString* setWildcardedIMPU();

		//! Function to reset 
		/*!		Function to reset NULL type of argument WildcardedIMPU for datatype ProfileUpdateRequest
		*/
		void resetWildcardedIMPU();

		//!Function to get values
		/*!		Function to get OctetString type of argument WildcardedIMPU for datatype ProfileUpdateRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getWildcardedIMPU();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserName for datatype ProfileUpdateRequest
		*/
		OctetString* setUserName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserName for datatype ProfileUpdateRequest
		*/
		void resetUserName();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserName for datatype ProfileUpdateRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserName();

		list<DataReference*>* getDataReferenceList();

		list<DataReference*>* setDataReferenceList();

		void resetDataReferenceList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserData for datatype ProfileUpdateRequest
		*/
		OctetString* setUserData();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserData for datatype ProfileUpdateRequest
		*/
		void resetUserData();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserData for datatype ProfileUpdateRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserData();

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
		/*!		Function to Decode datatype ProfileUpdateRequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype ProfileUpdateRequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype ProfileUpdateRequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype ProfileUpdateRequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ProfileUpdateRequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
