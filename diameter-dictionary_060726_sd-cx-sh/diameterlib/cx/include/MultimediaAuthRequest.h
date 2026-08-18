#ifndef CX_MULTIMEDIAAUTHREQUEST_H
#define CX_MULTIMEDIAAUTHREQUEST_H
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
#include "cx/include/SIPAuthDataItem.h"
#include "cx/include/ProxyInfo.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace CX{
typedef enum _tags_MultimediaAuthRequest
{
	MultimediaAuthRequest_SESSIONID	= 0,
	MultimediaAuthRequest_DRMP	= 1,
	MultimediaAuthRequest_VENDORSPECIFICAPPLICATIONID	= 2,
	MultimediaAuthRequest_AUTHSESSIONSTATE	= 3,
	MultimediaAuthRequest_ORIGINHOST	= 4,
	MultimediaAuthRequest_ORIGINREALM	= 5,
	MultimediaAuthRequest_DESTINATIONREALM	= 6,
	MultimediaAuthRequest_DESTINATIONHOST	= 7,
	MultimediaAuthRequest_USERNAME	= 8,
	MultimediaAuthRequest_OCSUPPORTEDFEATURES	= 9,
	MultimediaAuthRequest_SUPPORTEDFEATURES	= 10,
	MultimediaAuthRequest_PUBLICIDENTITY	= 11,
	MultimediaAuthRequest_SIPAUTHDATAITEM	= 12,
	MultimediaAuthRequest_SIPNUMBERAUTHITEMS	= 13,
	MultimediaAuthRequest_SERVERNAME	= 14,
	MultimediaAuthRequest_PROXYINFO	= 15,
	MultimediaAuthRequest_ROUTERECORD	= 16,
}MultimediaAuthRequest_tags;

		//! Class Definition
		/*!		ClassName is MultimediaAuthRequest
		*/
class MultimediaAuthRequest : public DiameterBase 
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

		OctetString*		mDestinationRealm;

		OctetString*		mDestinationHost;

		OctetString*		mUserName;

		OctetString*		mPublicIdentity;

		Unsigned32*		mSIPNumberAuthItems;

		OctetString*		mServerName;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;




		VendorSpecificApplicationId*	mVendorSpecificApplicationIdGrp;







		OCSupportedFeatures*	mOCSupportedFeaturesGrp;

		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;


		SIPAuthDataItem*	mSIPAuthDataItemGrp;



		list<CX::ProxyInfo*>*	mProxyInfoGrpList;
		list<CX::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		MultimediaAuthRequest();

		MultimediaAuthRequest(const MultimediaAuthRequest &objMultimediaAuthRequest) {

		mTagsPresent = objMultimediaAuthRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objMultimediaAuthRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objMultimediaAuthRequest.mMandatoryAvpSetVal;

		mTag = objMultimediaAuthRequest.mTag;

		mDecodeFlag = objMultimediaAuthRequest.mDecodeFlag;

		if(objMultimediaAuthRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objMultimediaAuthRequest.mSessionId));

		if(objMultimediaAuthRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objMultimediaAuthRequest.mDRMP));

		if(objMultimediaAuthRequest.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objMultimediaAuthRequest.mVendorSpecificApplicationIdGrp);
		 }
		if(objMultimediaAuthRequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objMultimediaAuthRequest.mAuthSessionState));

		if(objMultimediaAuthRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objMultimediaAuthRequest.mOriginHost));

		if(objMultimediaAuthRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objMultimediaAuthRequest.mOriginRealm));

		if(objMultimediaAuthRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objMultimediaAuthRequest.mDestinationRealm));

		if(objMultimediaAuthRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objMultimediaAuthRequest.mDestinationHost));

		if(objMultimediaAuthRequest.mUserName != NULL)
		mUserName = new OctetString(*(objMultimediaAuthRequest.mUserName));

		if(objMultimediaAuthRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objMultimediaAuthRequest.mOCSupportedFeaturesGrp);
		 }
		if(objMultimediaAuthRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objMultimediaAuthRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objMultimediaAuthRequest.mPublicIdentity != NULL)
		mPublicIdentity = new OctetString(*(objMultimediaAuthRequest.mPublicIdentity));

		if(objMultimediaAuthRequest.mSIPAuthDataItemGrp != NULL)
		 {
				 mSIPAuthDataItemGrp =  new SIPAuthDataItem(*objMultimediaAuthRequest.mSIPAuthDataItemGrp);
		 }
		if(objMultimediaAuthRequest.mSIPNumberAuthItems != NULL)
		mSIPNumberAuthItems = new Unsigned32(*(objMultimediaAuthRequest.mSIPNumberAuthItems));

		if(objMultimediaAuthRequest.mServerName != NULL)
		mServerName = new OctetString(*(objMultimediaAuthRequest.mServerName));

		if(objMultimediaAuthRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objMultimediaAuthRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const MultimediaAuthRequest &objMultimediaAuthRequest) {

		mTagsPresent = objMultimediaAuthRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objMultimediaAuthRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objMultimediaAuthRequest.mMandatoryAvpSetVal;

		mTag = objMultimediaAuthRequest.mTag;

		mDecodeFlag = objMultimediaAuthRequest.mDecodeFlag;

		if(objMultimediaAuthRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objMultimediaAuthRequest.mSessionId));

		if(objMultimediaAuthRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objMultimediaAuthRequest.mDRMP));

		if(objMultimediaAuthRequest.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objMultimediaAuthRequest.mVendorSpecificApplicationIdGrp);
		 }
		if(objMultimediaAuthRequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objMultimediaAuthRequest.mAuthSessionState));

		if(objMultimediaAuthRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objMultimediaAuthRequest.mOriginHost));

		if(objMultimediaAuthRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objMultimediaAuthRequest.mOriginRealm));

		if(objMultimediaAuthRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objMultimediaAuthRequest.mDestinationRealm));

		if(objMultimediaAuthRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objMultimediaAuthRequest.mDestinationHost));

		if(objMultimediaAuthRequest.mUserName != NULL)
		mUserName = new OctetString(*(objMultimediaAuthRequest.mUserName));

		if(objMultimediaAuthRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objMultimediaAuthRequest.mOCSupportedFeaturesGrp);
		 }
		if(objMultimediaAuthRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objMultimediaAuthRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objMultimediaAuthRequest.mPublicIdentity != NULL)
		mPublicIdentity = new OctetString(*(objMultimediaAuthRequest.mPublicIdentity));

		if(objMultimediaAuthRequest.mSIPAuthDataItemGrp != NULL)
		 {
				 mSIPAuthDataItemGrp =  new SIPAuthDataItem(*objMultimediaAuthRequest.mSIPAuthDataItemGrp);
		 }
		if(objMultimediaAuthRequest.mSIPNumberAuthItems != NULL)
		mSIPNumberAuthItems = new Unsigned32(*(objMultimediaAuthRequest.mSIPNumberAuthItems));

		if(objMultimediaAuthRequest.mServerName != NULL)
		mServerName = new OctetString(*(objMultimediaAuthRequest.mServerName));

		if(objMultimediaAuthRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objMultimediaAuthRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~MultimediaAuthRequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype MultimediaAuthRequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype MultimediaAuthRequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype MultimediaAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype MultimediaAuthRequest
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype MultimediaAuthRequest
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype MultimediaAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		VendorSpecificApplicationId* getVendorSpecificApplicationId();

		VendorSpecificApplicationId* setVendorSpecificApplicationId();

		void resetVendorSpecificApplicationId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype MultimediaAuthRequest
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype MultimediaAuthRequest
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype MultimediaAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype MultimediaAuthRequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype MultimediaAuthRequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype MultimediaAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype MultimediaAuthRequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype MultimediaAuthRequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype MultimediaAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationRealm for datatype MultimediaAuthRequest
		*/
		OctetString* setDestinationRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationRealm for datatype MultimediaAuthRequest
		*/
		void resetDestinationRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationRealm for datatype MultimediaAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationHost for datatype MultimediaAuthRequest
		*/
		OctetString* setDestinationHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationHost for datatype MultimediaAuthRequest
		*/
		void resetDestinationHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationHost for datatype MultimediaAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserName for datatype MultimediaAuthRequest
		*/
		OctetString* setUserName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserName for datatype MultimediaAuthRequest
		*/
		void resetUserName();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserName for datatype MultimediaAuthRequest
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
		/*!		Function to set the recent OctetString type of argument PublicIdentity for datatype MultimediaAuthRequest
		*/
		OctetString* setPublicIdentity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PublicIdentity for datatype MultimediaAuthRequest
		*/
		void resetPublicIdentity();

		//!Function to get values
		/*!		Function to get OctetString type of argument PublicIdentity for datatype MultimediaAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getPublicIdentity();

		SIPAuthDataItem* getSIPAuthDataItem();

		SIPAuthDataItem* setSIPAuthDataItem();

		void resetSIPAuthDataItem();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument SIPNumberAuthItems for datatype MultimediaAuthRequest
		*/
		Unsigned32* setSIPNumberAuthItems();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SIPNumberAuthItems for datatype MultimediaAuthRequest
		*/
		void resetSIPNumberAuthItems();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument SIPNumberAuthItems for datatype MultimediaAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getSIPNumberAuthItems();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ServerName for datatype MultimediaAuthRequest
		*/
		OctetString* setServerName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ServerName for datatype MultimediaAuthRequest
		*/
		void resetServerName();

		//!Function to get values
		/*!		Function to get OctetString type of argument ServerName for datatype MultimediaAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getServerName();

		list<CX::ProxyInfo*>* getProxyInfoGrpList();

		list<CX::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		//! Function to Decode
		/*!		Function to Decode datatype MultimediaAuthRequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype MultimediaAuthRequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype MultimediaAuthRequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype MultimediaAuthRequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype MultimediaAuthRequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
