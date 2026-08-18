#ifndef SLH_LCSROUTINGINFOREQUEST_H
#define SLH_LCSROUTINGINFOREQUEST_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"
#include "slh/include/ProxyInfo.h"
#include "slh/include/VendorSpecificApplicationId.h"
#include "slh/include/AuthSessionState.h"
#include "slh/include/SupportedFeatures.h"
#include "slh/include/ProxyInfo.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace SLH{
typedef enum _tags_LCSRoutingInfoRequest
{
	LCSRoutingInfoRequest_SESSIONID	= 0,
	LCSRoutingInfoRequest_VENDORSPECIFICAPPLICATIONID	= 1,
	LCSRoutingInfoRequest_AUTHSESSIONSTATE	= 2,
	LCSRoutingInfoRequest_ORIGINHOST	= 3,
	LCSRoutingInfoRequest_ORIGINREALM	= 4,
	LCSRoutingInfoRequest_DESTINATIONHOST	= 5,
	LCSRoutingInfoRequest_DESTINATIONREALM	= 6,
	LCSRoutingInfoRequest_USERNAME	= 7,
	LCSRoutingInfoRequest_MSISDN	= 8,
	LCSRoutingInfoRequest_GMLCNUMBER	= 9,
	LCSRoutingInfoRequest_SUPPORTEDFEATURES	= 10,
	LCSRoutingInfoRequest_PROXYINFO	= 11,
	LCSRoutingInfoRequest_ROUTERECORD	= 12,
}LCSRoutingInfoRequest_tags;

		//! Class Definition
		/*!		ClassName is LCSRoutingInfoRequest
		*/
class LCSRoutingInfoRequest : public DiameterBase 
{
	private:

		bitset<13> mTagsPresent;

		bitset<13> mMandatoryAvpCheckVal;

		bitset<13> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		AuthSessionState*		mAuthSessionState;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		OctetString*		mDestinationHost;

		OctetString*		mDestinationRealm;

		OctetString*		mUserName;

		OctetString*		mMSISDN;

		OctetString*		mGMLCNumber;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;



		list<VendorSpecificApplicationId*>*	mVendorSpecificApplicationIdGrpList;
		list<VendorSpecificApplicationId*>::iterator	mVendorSpecificApplicationIdGrpIterator;









		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;

		list<SLH::ProxyInfo*>*	mProxyInfoGrpList;
		list<SLH::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		LCSRoutingInfoRequest();

		LCSRoutingInfoRequest(const LCSRoutingInfoRequest &objLCSRoutingInfoRequest) {

		mTagsPresent = objLCSRoutingInfoRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objLCSRoutingInfoRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objLCSRoutingInfoRequest.mMandatoryAvpSetVal;

		mTag = objLCSRoutingInfoRequest.mTag;

		mDecodeFlag = objLCSRoutingInfoRequest.mDecodeFlag;

		if(objLCSRoutingInfoRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objLCSRoutingInfoRequest.mSessionId));

		if(objLCSRoutingInfoRequest.mVendorSpecificApplicationIdGrpList != NULL)
		 {
		 mVendorSpecificApplicationIdGrpList = new list<VendorSpecificApplicationId*>;
		 for( auto element : *objLCSRoutingInfoRequest.mVendorSpecificApplicationIdGrpList)
		 {
				 VendorSpecificApplicationId *lVendorSpecificApplicationId =  new VendorSpecificApplicationId(*element);
				 mVendorSpecificApplicationIdGrpList->push_back(lVendorSpecificApplicationId);
		 }
		 }
		if(objLCSRoutingInfoRequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objLCSRoutingInfoRequest.mAuthSessionState));

		if(objLCSRoutingInfoRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objLCSRoutingInfoRequest.mOriginHost));

		if(objLCSRoutingInfoRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objLCSRoutingInfoRequest.mOriginRealm));

		if(objLCSRoutingInfoRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objLCSRoutingInfoRequest.mDestinationHost));

		if(objLCSRoutingInfoRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objLCSRoutingInfoRequest.mDestinationRealm));

		if(objLCSRoutingInfoRequest.mUserName != NULL)
		mUserName = new OctetString(*(objLCSRoutingInfoRequest.mUserName));

		if(objLCSRoutingInfoRequest.mMSISDN != NULL)
		mMSISDN = new OctetString(*(objLCSRoutingInfoRequest.mMSISDN));

		if(objLCSRoutingInfoRequest.mGMLCNumber != NULL)
		mGMLCNumber = new OctetString(*(objLCSRoutingInfoRequest.mGMLCNumber));

		if(objLCSRoutingInfoRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objLCSRoutingInfoRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objLCSRoutingInfoRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SLH::ProxyInfo*>;
		 for( auto element : *objLCSRoutingInfoRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const LCSRoutingInfoRequest &objLCSRoutingInfoRequest) {

		mTagsPresent = objLCSRoutingInfoRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objLCSRoutingInfoRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objLCSRoutingInfoRequest.mMandatoryAvpSetVal;

		mTag = objLCSRoutingInfoRequest.mTag;

		mDecodeFlag = objLCSRoutingInfoRequest.mDecodeFlag;

		if(objLCSRoutingInfoRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objLCSRoutingInfoRequest.mSessionId));

		if(objLCSRoutingInfoRequest.mVendorSpecificApplicationIdGrpList != NULL)
		 {
		 mVendorSpecificApplicationIdGrpList = new list<VendorSpecificApplicationId*>;
		 for( auto element : *objLCSRoutingInfoRequest.mVendorSpecificApplicationIdGrpList)
		 {
				 VendorSpecificApplicationId *lVendorSpecificApplicationId =  new VendorSpecificApplicationId(*element);
				 mVendorSpecificApplicationIdGrpList->push_back(lVendorSpecificApplicationId);
		 }
		 }
		if(objLCSRoutingInfoRequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objLCSRoutingInfoRequest.mAuthSessionState));

		if(objLCSRoutingInfoRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objLCSRoutingInfoRequest.mOriginHost));

		if(objLCSRoutingInfoRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objLCSRoutingInfoRequest.mOriginRealm));

		if(objLCSRoutingInfoRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objLCSRoutingInfoRequest.mDestinationHost));

		if(objLCSRoutingInfoRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objLCSRoutingInfoRequest.mDestinationRealm));

		if(objLCSRoutingInfoRequest.mUserName != NULL)
		mUserName = new OctetString(*(objLCSRoutingInfoRequest.mUserName));

		if(objLCSRoutingInfoRequest.mMSISDN != NULL)
		mMSISDN = new OctetString(*(objLCSRoutingInfoRequest.mMSISDN));

		if(objLCSRoutingInfoRequest.mGMLCNumber != NULL)
		mGMLCNumber = new OctetString(*(objLCSRoutingInfoRequest.mGMLCNumber));

		if(objLCSRoutingInfoRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objLCSRoutingInfoRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objLCSRoutingInfoRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SLH::ProxyInfo*>;
		 for( auto element : *objLCSRoutingInfoRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~LCSRoutingInfoRequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype LCSRoutingInfoRequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype LCSRoutingInfoRequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype LCSRoutingInfoRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		list<VendorSpecificApplicationId*>* getVendorSpecificApplicationIdGrpList();

		list<VendorSpecificApplicationId*>* setVendorSpecificApplicationIdGrpList();

		void resetVendorSpecificApplicationIdGrpList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype LCSRoutingInfoRequest
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype LCSRoutingInfoRequest
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype LCSRoutingInfoRequest
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype LCSRoutingInfoRequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype LCSRoutingInfoRequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype LCSRoutingInfoRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype LCSRoutingInfoRequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype LCSRoutingInfoRequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype LCSRoutingInfoRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationHost for datatype LCSRoutingInfoRequest
		*/
		OctetString* setDestinationHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationHost for datatype LCSRoutingInfoRequest
		*/
		void resetDestinationHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationHost for datatype LCSRoutingInfoRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationRealm for datatype LCSRoutingInfoRequest
		*/
		OctetString* setDestinationRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationRealm for datatype LCSRoutingInfoRequest
		*/
		void resetDestinationRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationRealm for datatype LCSRoutingInfoRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserName for datatype LCSRoutingInfoRequest
		*/
		OctetString* setUserName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserName for datatype LCSRoutingInfoRequest
		*/
		void resetUserName();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserName for datatype LCSRoutingInfoRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserName();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument MSISDN for datatype LCSRoutingInfoRequest
		*/
		OctetString* setMSISDN();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MSISDN for datatype LCSRoutingInfoRequest
		*/
		void resetMSISDN();

		//!Function to get values
		/*!		Function to get OctetString type of argument MSISDN for datatype LCSRoutingInfoRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getMSISDN();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument GMLCNumber for datatype LCSRoutingInfoRequest
		*/
		OctetString* setGMLCNumber();

		//! Function to reset 
		/*!		Function to reset NULL type of argument GMLCNumber for datatype LCSRoutingInfoRequest
		*/
		void resetGMLCNumber();

		//!Function to get values
		/*!		Function to get OctetString type of argument GMLCNumber for datatype LCSRoutingInfoRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getGMLCNumber();

		list<SupportedFeatures*>* getSupportedFeaturesGrpList();

		list<SupportedFeatures*>* setSupportedFeaturesGrpList();

		void resetSupportedFeaturesGrpList();

		list<SLH::ProxyInfo*>* getProxyInfoGrpList();

		list<SLH::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		//! Function to Decode
		/*!		Function to Decode datatype LCSRoutingInfoRequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype LCSRoutingInfoRequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype LCSRoutingInfoRequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype LCSRoutingInfoRequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype LCSRoutingInfoRequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
