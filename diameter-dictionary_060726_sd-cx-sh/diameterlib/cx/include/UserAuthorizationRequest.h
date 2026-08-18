#ifndef CX_USERAUTHORIZATIONREQUEST_H
#define CX_USERAUTHORIZATIONREQUEST_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "cx/include/DRMP.h"
#include "cx/include/VendorSpecificApplicationId.h"
#include "cx/include/AuthSessionState.h"
#include "cx/include/OCSupportedFeatures.h"
#include "cx/include/SupportedFeatures.h"
#include "cx/include/UserAuthorizationType.h"
#include "cx/include/ProxyInfo.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace CX{
typedef enum _tags_UserAuthorizationRequest
{
	UserAuthorizationRequest_SESSIONID	= 0,
	UserAuthorizationRequest_DRMP	= 1,
	UserAuthorizationRequest_VENDORSPECIFICAPPLICATIONID	= 2,
	UserAuthorizationRequest_AUTHSESSIONSTATE	= 3,
	UserAuthorizationRequest_ORIGINHOST	= 4,
	UserAuthorizationRequest_ORIGINREALM	= 5,
	UserAuthorizationRequest_DESTINATIONHOST	= 6,
	UserAuthorizationRequest_DESTINATIONREALM	= 7,
	UserAuthorizationRequest_USERNAME	= 8,
	UserAuthorizationRequest_OCSUPPORTEDFEATURES	= 9,
	UserAuthorizationRequest_SUPPORTEDFEATURES	= 10,
	UserAuthorizationRequest_PUBLICIDENTITY	= 11,
	UserAuthorizationRequest_VISITEDNETWORKIDENTIFIER	= 12,
	UserAuthorizationRequest_USERAUTHORIZATIONTYPE	= 13,
	UserAuthorizationRequest_UARFLAGS	= 14,
	UserAuthorizationRequest_PROXYINFO	= 15,
	UserAuthorizationRequest_ROUTERECORD	= 16,
}UserAuthorizationRequest_tags;

		//! Class Definition
		/*!		ClassName is UserAuthorizationRequest
		*/
class UserAuthorizationRequest : public DiameterBase 
{
	private:

		bitset<17> mTagsPresent;

		bitset<17> mMandatoryAvpCheckVal;

		bitset<17> mMandatoryAvpSetVal;

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

		OctetString*		mUserName;

		OctetString*		mPublicIdentity;

		OctetString*		mVisitedNetworkIdentifier;

		UserAuthorizationType*		mUserAuthorizationType;

		Unsigned32*		mUARFlags;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;




		VendorSpecificApplicationId*	mVendorSpecificApplicationIdGrp;







		OCSupportedFeatures*	mOCSupportedFeaturesGrp;

		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;





		list<CX::ProxyInfo*>*	mProxyInfoGrpList;
		list<CX::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		UserAuthorizationRequest();

		UserAuthorizationRequest(const UserAuthorizationRequest &objUserAuthorizationRequest) {

		mTagsPresent = objUserAuthorizationRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objUserAuthorizationRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUserAuthorizationRequest.mMandatoryAvpSetVal;

		mTag = objUserAuthorizationRequest.mTag;

		mDecodeFlag = objUserAuthorizationRequest.mDecodeFlag;

		if(objUserAuthorizationRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objUserAuthorizationRequest.mSessionId));

		if(objUserAuthorizationRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objUserAuthorizationRequest.mDRMP));

		if(objUserAuthorizationRequest.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objUserAuthorizationRequest.mVendorSpecificApplicationIdGrp);
		 }
		if(objUserAuthorizationRequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objUserAuthorizationRequest.mAuthSessionState));

		if(objUserAuthorizationRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objUserAuthorizationRequest.mOriginHost));

		if(objUserAuthorizationRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objUserAuthorizationRequest.mOriginRealm));

		if(objUserAuthorizationRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objUserAuthorizationRequest.mDestinationHost));

		if(objUserAuthorizationRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objUserAuthorizationRequest.mDestinationRealm));

		if(objUserAuthorizationRequest.mUserName != NULL)
		mUserName = new OctetString(*(objUserAuthorizationRequest.mUserName));

		if(objUserAuthorizationRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objUserAuthorizationRequest.mOCSupportedFeaturesGrp);
		 }
		if(objUserAuthorizationRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objUserAuthorizationRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objUserAuthorizationRequest.mPublicIdentity != NULL)
		mPublicIdentity = new OctetString(*(objUserAuthorizationRequest.mPublicIdentity));

		if(objUserAuthorizationRequest.mVisitedNetworkIdentifier != NULL)
		mVisitedNetworkIdentifier = new OctetString(*(objUserAuthorizationRequest.mVisitedNetworkIdentifier));

		if(objUserAuthorizationRequest.mUserAuthorizationType != NULL)
		mUserAuthorizationType = new UserAuthorizationType(*(objUserAuthorizationRequest.mUserAuthorizationType));

		if(objUserAuthorizationRequest.mUARFlags != NULL)
		mUARFlags = new Unsigned32(*(objUserAuthorizationRequest.mUARFlags));

		if(objUserAuthorizationRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objUserAuthorizationRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const UserAuthorizationRequest &objUserAuthorizationRequest) {

		mTagsPresent = objUserAuthorizationRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objUserAuthorizationRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUserAuthorizationRequest.mMandatoryAvpSetVal;

		mTag = objUserAuthorizationRequest.mTag;

		mDecodeFlag = objUserAuthorizationRequest.mDecodeFlag;

		if(objUserAuthorizationRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objUserAuthorizationRequest.mSessionId));

		if(objUserAuthorizationRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objUserAuthorizationRequest.mDRMP));

		if(objUserAuthorizationRequest.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objUserAuthorizationRequest.mVendorSpecificApplicationIdGrp);
		 }
		if(objUserAuthorizationRequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objUserAuthorizationRequest.mAuthSessionState));

		if(objUserAuthorizationRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objUserAuthorizationRequest.mOriginHost));

		if(objUserAuthorizationRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objUserAuthorizationRequest.mOriginRealm));

		if(objUserAuthorizationRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objUserAuthorizationRequest.mDestinationHost));

		if(objUserAuthorizationRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objUserAuthorizationRequest.mDestinationRealm));

		if(objUserAuthorizationRequest.mUserName != NULL)
		mUserName = new OctetString(*(objUserAuthorizationRequest.mUserName));

		if(objUserAuthorizationRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objUserAuthorizationRequest.mOCSupportedFeaturesGrp);
		 }
		if(objUserAuthorizationRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objUserAuthorizationRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objUserAuthorizationRequest.mPublicIdentity != NULL)
		mPublicIdentity = new OctetString(*(objUserAuthorizationRequest.mPublicIdentity));

		if(objUserAuthorizationRequest.mVisitedNetworkIdentifier != NULL)
		mVisitedNetworkIdentifier = new OctetString(*(objUserAuthorizationRequest.mVisitedNetworkIdentifier));

		if(objUserAuthorizationRequest.mUserAuthorizationType != NULL)
		mUserAuthorizationType = new UserAuthorizationType(*(objUserAuthorizationRequest.mUserAuthorizationType));

		if(objUserAuthorizationRequest.mUARFlags != NULL)
		mUARFlags = new Unsigned32(*(objUserAuthorizationRequest.mUARFlags));

		if(objUserAuthorizationRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objUserAuthorizationRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~UserAuthorizationRequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype UserAuthorizationRequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype UserAuthorizationRequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype UserAuthorizationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype UserAuthorizationRequest
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype UserAuthorizationRequest
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype UserAuthorizationRequest
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		VendorSpecificApplicationId* getVendorSpecificApplicationId();

		VendorSpecificApplicationId* setVendorSpecificApplicationId();

		void resetVendorSpecificApplicationId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype UserAuthorizationRequest
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype UserAuthorizationRequest
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype UserAuthorizationRequest
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype UserAuthorizationRequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype UserAuthorizationRequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype UserAuthorizationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype UserAuthorizationRequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype UserAuthorizationRequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype UserAuthorizationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationHost for datatype UserAuthorizationRequest
		*/
		OctetString* setDestinationHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationHost for datatype UserAuthorizationRequest
		*/
		void resetDestinationHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationHost for datatype UserAuthorizationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationRealm for datatype UserAuthorizationRequest
		*/
		OctetString* setDestinationRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationRealm for datatype UserAuthorizationRequest
		*/
		void resetDestinationRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationRealm for datatype UserAuthorizationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserName for datatype UserAuthorizationRequest
		*/
		OctetString* setUserName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserName for datatype UserAuthorizationRequest
		*/
		void resetUserName();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserName for datatype UserAuthorizationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserName();

		OCSupportedFeatures* getOCSupportedFeatures();

		OCSupportedFeatures* setOCSupportedFeatures();

		void resetOCSupportedFeatures();

		list<SupportedFeatures*>* getSupportedFeaturesGrpList();

		list<SupportedFeatures*>* setSupportedFeaturesGrpList();

		void resetSupportedFeaturesGrpList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument PublicIdentity for datatype UserAuthorizationRequest
		*/
		OctetString* setPublicIdentity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PublicIdentity for datatype UserAuthorizationRequest
		*/
		void resetPublicIdentity();

		//!Function to get values
		/*!		Function to get OctetString type of argument PublicIdentity for datatype UserAuthorizationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getPublicIdentity();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument VisitedNetworkIdentifier for datatype UserAuthorizationRequest
		*/
		OctetString* setVisitedNetworkIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument VisitedNetworkIdentifier for datatype UserAuthorizationRequest
		*/
		void resetVisitedNetworkIdentifier();

		//!Function to get values
		/*!		Function to get OctetString type of argument VisitedNetworkIdentifier for datatype UserAuthorizationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getVisitedNetworkIdentifier();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument UserAuthorizationType for datatype UserAuthorizationRequest
		*/
		UserAuthorizationType* setUserAuthorizationType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserAuthorizationType for datatype UserAuthorizationRequest
		*/
		void resetUserAuthorizationType();

		//!Function to get values
		/*!		Function to get UserAuthorizationType type of argument UserAuthorizationType for datatype UserAuthorizationRequest
		Throws exception of which type and Summary of Exception
		*/
		UserAuthorizationType* getUserAuthorizationType();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument UARFlags for datatype UserAuthorizationRequest
		*/
		Unsigned32* setUARFlags();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UARFlags for datatype UserAuthorizationRequest
		*/
		void resetUARFlags();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument UARFlags for datatype UserAuthorizationRequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getUARFlags();

		list<CX::ProxyInfo*>* getProxyInfoGrpList();

		list<CX::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		//! Function to Decode
		/*!		Function to Decode datatype UserAuthorizationRequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype UserAuthorizationRequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype UserAuthorizationRequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype UserAuthorizationRequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype UserAuthorizationRequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
