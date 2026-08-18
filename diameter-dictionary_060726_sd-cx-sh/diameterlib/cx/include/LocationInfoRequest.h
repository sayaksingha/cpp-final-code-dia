#ifndef CX_LOCATIONINFOREQUEST_H
#define CX_LOCATIONINFOREQUEST_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "cx/include/DRMP.h"
#include "cx/include/VendorSpecificApplicationId.h"
#include "cx/include/AuthSessionState.h"
#include "cx/include/OriginatingRequest.h"
#include "cx/include/OCSupportedFeatures.h"
#include "cx/include/SupportedFeatures.h"
#include "cx/include/UserAuthorizationType.h"
#include "cx/include/SessionPriority.h"
#include "cx/include/ProxyInfo.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace CX{
typedef enum _tags_LocationInfoRequest
{
	LocationInfoRequest_SESSIONID	= 0,
	LocationInfoRequest_DRMP	= 1,
	LocationInfoRequest_VENDORSPECIFICAPPLICATIONID	= 2,
	LocationInfoRequest_AUTHSESSIONSTATE	= 3,
	LocationInfoRequest_ORIGINHOST	= 4,
	LocationInfoRequest_ORIGINREALM	= 5,
	LocationInfoRequest_DESTINATIONHOST	= 6,
	LocationInfoRequest_DESTINATIONREALM	= 7,
	LocationInfoRequest_ORIGINATINGREQUEST	= 8,
	LocationInfoRequest_OCSUPPORTEDFEATURES	= 9,
	LocationInfoRequest_SUPPORTEDFEATURES	= 10,
	LocationInfoRequest_PUBLICIDENTITY	= 11,
	LocationInfoRequest_USERAUTHORIZATIONTYPE	= 12,
	LocationInfoRequest_SESSIONPRIORITY	= 13,
	LocationInfoRequest_PROXYINFO	= 14,
	LocationInfoRequest_ROUTERECORD	= 15,
}LocationInfoRequest_tags;

		//! Class Definition
		/*!		ClassName is LocationInfoRequest
		*/
class LocationInfoRequest : public DiameterBase 
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

		OriginatingRequest*		mOriginatingRequest;

		OctetString*		mPublicIdentity;

		UserAuthorizationType*		mUserAuthorizationType;

		SessionPriority*		mSessionPriority;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;




		VendorSpecificApplicationId*	mVendorSpecificApplicationIdGrp;







		OCSupportedFeatures*	mOCSupportedFeaturesGrp;

		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;




		list<CX::ProxyInfo*>*	mProxyInfoGrpList;
		list<CX::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		LocationInfoRequest();

		LocationInfoRequest(const LocationInfoRequest &objLocationInfoRequest) {

		mTagsPresent = objLocationInfoRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objLocationInfoRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objLocationInfoRequest.mMandatoryAvpSetVal;

		mTag = objLocationInfoRequest.mTag;

		mDecodeFlag = objLocationInfoRequest.mDecodeFlag;

		if(objLocationInfoRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objLocationInfoRequest.mSessionId));

		if(objLocationInfoRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objLocationInfoRequest.mDRMP));

		if(objLocationInfoRequest.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objLocationInfoRequest.mVendorSpecificApplicationIdGrp);
		 }
		if(objLocationInfoRequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objLocationInfoRequest.mAuthSessionState));

		if(objLocationInfoRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objLocationInfoRequest.mOriginHost));

		if(objLocationInfoRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objLocationInfoRequest.mOriginRealm));

		if(objLocationInfoRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objLocationInfoRequest.mDestinationHost));

		if(objLocationInfoRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objLocationInfoRequest.mDestinationRealm));

		if(objLocationInfoRequest.mOriginatingRequest != NULL)
		mOriginatingRequest = new OriginatingRequest(*(objLocationInfoRequest.mOriginatingRequest));

		if(objLocationInfoRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objLocationInfoRequest.mOCSupportedFeaturesGrp);
		 }
		if(objLocationInfoRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objLocationInfoRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objLocationInfoRequest.mPublicIdentity != NULL)
		mPublicIdentity = new OctetString(*(objLocationInfoRequest.mPublicIdentity));

		if(objLocationInfoRequest.mUserAuthorizationType != NULL)
		mUserAuthorizationType = new UserAuthorizationType(*(objLocationInfoRequest.mUserAuthorizationType));

		if(objLocationInfoRequest.mSessionPriority != NULL)
		mSessionPriority = new SessionPriority(*(objLocationInfoRequest.mSessionPriority));

		if(objLocationInfoRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objLocationInfoRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const LocationInfoRequest &objLocationInfoRequest) {

		mTagsPresent = objLocationInfoRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objLocationInfoRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objLocationInfoRequest.mMandatoryAvpSetVal;

		mTag = objLocationInfoRequest.mTag;

		mDecodeFlag = objLocationInfoRequest.mDecodeFlag;

		if(objLocationInfoRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objLocationInfoRequest.mSessionId));

		if(objLocationInfoRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objLocationInfoRequest.mDRMP));

		if(objLocationInfoRequest.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objLocationInfoRequest.mVendorSpecificApplicationIdGrp);
		 }
		if(objLocationInfoRequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objLocationInfoRequest.mAuthSessionState));

		if(objLocationInfoRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objLocationInfoRequest.mOriginHost));

		if(objLocationInfoRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objLocationInfoRequest.mOriginRealm));

		if(objLocationInfoRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objLocationInfoRequest.mDestinationHost));

		if(objLocationInfoRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objLocationInfoRequest.mDestinationRealm));

		if(objLocationInfoRequest.mOriginatingRequest != NULL)
		mOriginatingRequest = new OriginatingRequest(*(objLocationInfoRequest.mOriginatingRequest));

		if(objLocationInfoRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objLocationInfoRequest.mOCSupportedFeaturesGrp);
		 }
		if(objLocationInfoRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objLocationInfoRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objLocationInfoRequest.mPublicIdentity != NULL)
		mPublicIdentity = new OctetString(*(objLocationInfoRequest.mPublicIdentity));

		if(objLocationInfoRequest.mUserAuthorizationType != NULL)
		mUserAuthorizationType = new UserAuthorizationType(*(objLocationInfoRequest.mUserAuthorizationType));

		if(objLocationInfoRequest.mSessionPriority != NULL)
		mSessionPriority = new SessionPriority(*(objLocationInfoRequest.mSessionPriority));

		if(objLocationInfoRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objLocationInfoRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~LocationInfoRequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype LocationInfoRequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype LocationInfoRequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype LocationInfoRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype LocationInfoRequest
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype LocationInfoRequest
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype LocationInfoRequest
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		VendorSpecificApplicationId* getVendorSpecificApplicationId();

		VendorSpecificApplicationId* setVendorSpecificApplicationId();

		void resetVendorSpecificApplicationId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype LocationInfoRequest
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype LocationInfoRequest
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype LocationInfoRequest
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype LocationInfoRequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype LocationInfoRequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype LocationInfoRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype LocationInfoRequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype LocationInfoRequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype LocationInfoRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationHost for datatype LocationInfoRequest
		*/
		OctetString* setDestinationHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationHost for datatype LocationInfoRequest
		*/
		void resetDestinationHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationHost for datatype LocationInfoRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationRealm for datatype LocationInfoRequest
		*/
		OctetString* setDestinationRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationRealm for datatype LocationInfoRequest
		*/
		void resetDestinationRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationRealm for datatype LocationInfoRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationRealm();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument OriginatingRequest for datatype LocationInfoRequest
		*/
		OriginatingRequest* setOriginatingRequest();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginatingRequest for datatype LocationInfoRequest
		*/
		void resetOriginatingRequest();

		//!Function to get values
		/*!		Function to get OriginatingRequest type of argument OriginatingRequest for datatype LocationInfoRequest
		Throws exception of which type and Summary of Exception
		*/
		OriginatingRequest* getOriginatingRequest();

		OCSupportedFeatures* getOCSupportedFeatures();

		OCSupportedFeatures* setOCSupportedFeatures();

		void resetOCSupportedFeatures();

		list<SupportedFeatures*>* getSupportedFeaturesGrpList();

		list<SupportedFeatures*>* setSupportedFeaturesGrpList();

		void resetSupportedFeaturesGrpList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument PublicIdentity for datatype LocationInfoRequest
		*/
		OctetString* setPublicIdentity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PublicIdentity for datatype LocationInfoRequest
		*/
		void resetPublicIdentity();

		//!Function to get values
		/*!		Function to get OctetString type of argument PublicIdentity for datatype LocationInfoRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getPublicIdentity();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument UserAuthorizationType for datatype LocationInfoRequest
		*/
		UserAuthorizationType* setUserAuthorizationType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserAuthorizationType for datatype LocationInfoRequest
		*/
		void resetUserAuthorizationType();

		//!Function to get values
		/*!		Function to get UserAuthorizationType type of argument UserAuthorizationType for datatype LocationInfoRequest
		Throws exception of which type and Summary of Exception
		*/
		UserAuthorizationType* getUserAuthorizationType();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument SessionPriority for datatype LocationInfoRequest
		*/
		SessionPriority* setSessionPriority();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionPriority for datatype LocationInfoRequest
		*/
		void resetSessionPriority();

		//!Function to get values
		/*!		Function to get SessionPriority type of argument SessionPriority for datatype LocationInfoRequest
		Throws exception of which type and Summary of Exception
		*/
		SessionPriority* getSessionPriority();

		list<CX::ProxyInfo*>* getProxyInfoGrpList();

		list<CX::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		//! Function to Decode
		/*!		Function to Decode datatype LocationInfoRequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype LocationInfoRequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype LocationInfoRequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype LocationInfoRequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype LocationInfoRequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
