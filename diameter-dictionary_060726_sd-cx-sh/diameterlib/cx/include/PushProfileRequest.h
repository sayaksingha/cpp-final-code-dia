#ifndef CX_PUSHPROFILEREQUEST_H
#define CX_PUSHPROFILEREQUEST_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "cx/include/DRMP.h"
#include "cx/include/VendorSpecificApplicationId.h"
#include "cx/include/AuthSessionState.h"
#include "cx/include/SupportedFeatures.h"
#include "cx/include/ChargingInformation.h"
#include "cx/include/SIPAuthDataItem.h"
#include "cx/include/AllowedWAFWWSFIdentities.h"
#include "cx/include/ProxyInfo.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace CX{
typedef enum _tags_PushProfileRequest
{
	PushProfileRequest_SESSIONID	= 0,
	PushProfileRequest_DRMP	= 1,
	PushProfileRequest_VENDORSPECIFICAPPLICATIONID	= 2,
	PushProfileRequest_AUTHSESSIONSTATE	= 3,
	PushProfileRequest_ORIGINHOST	= 4,
	PushProfileRequest_ORIGINREALM	= 5,
	PushProfileRequest_DESTINATIONHOST	= 6,
	PushProfileRequest_DESTINATIONREALM	= 7,
	PushProfileRequest_USERNAME	= 8,
	PushProfileRequest_SUPPORTEDFEATURES	= 9,
	PushProfileRequest_USERDATA	= 10,
	PushProfileRequest_CHARGINGINFORMATION	= 11,
	PushProfileRequest_SIPAUTHDATAITEM	= 12,
	PushProfileRequest_ALLOWEDWAFWWSFIDENTITIES	= 13,
	PushProfileRequest_PROXYINFO	= 14,
	PushProfileRequest_ROUTERECORD	= 15,
}PushProfileRequest_tags;

		//! Class Definition
		/*!		ClassName is PushProfileRequest
		*/
class PushProfileRequest : public DiameterBase 
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

		OctetString*		mUserName;

		OctetString*		mUserData;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;




		VendorSpecificApplicationId*	mVendorSpecificApplicationIdGrp;







		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;


		ChargingInformation*	mChargingInformationGrp;

		SIPAuthDataItem*	mSIPAuthDataItemGrp;

		AllowedWAFWWSFIdentities*	mAllowedWAFWWSFIdentitiesGrp;

		list<CX::ProxyInfo*>*	mProxyInfoGrpList;
		list<CX::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		PushProfileRequest();

		PushProfileRequest(const PushProfileRequest &objPushProfileRequest) {

		mTagsPresent = objPushProfileRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objPushProfileRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objPushProfileRequest.mMandatoryAvpSetVal;

		mTag = objPushProfileRequest.mTag;

		mDecodeFlag = objPushProfileRequest.mDecodeFlag;

		if(objPushProfileRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objPushProfileRequest.mSessionId));

		if(objPushProfileRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objPushProfileRequest.mDRMP));

		if(objPushProfileRequest.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objPushProfileRequest.mVendorSpecificApplicationIdGrp);
		 }
		if(objPushProfileRequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objPushProfileRequest.mAuthSessionState));

		if(objPushProfileRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objPushProfileRequest.mOriginHost));

		if(objPushProfileRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objPushProfileRequest.mOriginRealm));

		if(objPushProfileRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objPushProfileRequest.mDestinationHost));

		if(objPushProfileRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objPushProfileRequest.mDestinationRealm));

		if(objPushProfileRequest.mUserName != NULL)
		mUserName = new OctetString(*(objPushProfileRequest.mUserName));

		if(objPushProfileRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objPushProfileRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objPushProfileRequest.mUserData != NULL)
		mUserData = new OctetString(*(objPushProfileRequest.mUserData));

		if(objPushProfileRequest.mChargingInformationGrp != NULL)
		 {
				 mChargingInformationGrp =  new ChargingInformation(*objPushProfileRequest.mChargingInformationGrp);
		 }
		if(objPushProfileRequest.mSIPAuthDataItemGrp != NULL)
		 {
				 mSIPAuthDataItemGrp =  new SIPAuthDataItem(*objPushProfileRequest.mSIPAuthDataItemGrp);
		 }
		if(objPushProfileRequest.mAllowedWAFWWSFIdentitiesGrp != NULL)
		 {
				 mAllowedWAFWWSFIdentitiesGrp =  new AllowedWAFWWSFIdentities(*objPushProfileRequest.mAllowedWAFWWSFIdentitiesGrp);
		 }
		if(objPushProfileRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objPushProfileRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const PushProfileRequest &objPushProfileRequest) {

		mTagsPresent = objPushProfileRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objPushProfileRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objPushProfileRequest.mMandatoryAvpSetVal;

		mTag = objPushProfileRequest.mTag;

		mDecodeFlag = objPushProfileRequest.mDecodeFlag;

		if(objPushProfileRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objPushProfileRequest.mSessionId));

		if(objPushProfileRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objPushProfileRequest.mDRMP));

		if(objPushProfileRequest.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objPushProfileRequest.mVendorSpecificApplicationIdGrp);
		 }
		if(objPushProfileRequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objPushProfileRequest.mAuthSessionState));

		if(objPushProfileRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objPushProfileRequest.mOriginHost));

		if(objPushProfileRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objPushProfileRequest.mOriginRealm));

		if(objPushProfileRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objPushProfileRequest.mDestinationHost));

		if(objPushProfileRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objPushProfileRequest.mDestinationRealm));

		if(objPushProfileRequest.mUserName != NULL)
		mUserName = new OctetString(*(objPushProfileRequest.mUserName));

		if(objPushProfileRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objPushProfileRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objPushProfileRequest.mUserData != NULL)
		mUserData = new OctetString(*(objPushProfileRequest.mUserData));

		if(objPushProfileRequest.mChargingInformationGrp != NULL)
		 {
				 mChargingInformationGrp =  new ChargingInformation(*objPushProfileRequest.mChargingInformationGrp);
		 }
		if(objPushProfileRequest.mSIPAuthDataItemGrp != NULL)
		 {
				 mSIPAuthDataItemGrp =  new SIPAuthDataItem(*objPushProfileRequest.mSIPAuthDataItemGrp);
		 }
		if(objPushProfileRequest.mAllowedWAFWWSFIdentitiesGrp != NULL)
		 {
				 mAllowedWAFWWSFIdentitiesGrp =  new AllowedWAFWWSFIdentities(*objPushProfileRequest.mAllowedWAFWWSFIdentitiesGrp);
		 }
		if(objPushProfileRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objPushProfileRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~PushProfileRequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype PushProfileRequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype PushProfileRequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype PushProfileRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype PushProfileRequest
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype PushProfileRequest
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype PushProfileRequest
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		VendorSpecificApplicationId* getVendorSpecificApplicationId();

		VendorSpecificApplicationId* setVendorSpecificApplicationId();

		void resetVendorSpecificApplicationId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype PushProfileRequest
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype PushProfileRequest
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype PushProfileRequest
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype PushProfileRequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype PushProfileRequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype PushProfileRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype PushProfileRequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype PushProfileRequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype PushProfileRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationHost for datatype PushProfileRequest
		*/
		OctetString* setDestinationHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationHost for datatype PushProfileRequest
		*/
		void resetDestinationHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationHost for datatype PushProfileRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationRealm for datatype PushProfileRequest
		*/
		OctetString* setDestinationRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationRealm for datatype PushProfileRequest
		*/
		void resetDestinationRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationRealm for datatype PushProfileRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserName for datatype PushProfileRequest
		*/
		OctetString* setUserName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserName for datatype PushProfileRequest
		*/
		void resetUserName();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserName for datatype PushProfileRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserName();

		list<SupportedFeatures*>* getSupportedFeaturesGrpList();

		list<SupportedFeatures*>* setSupportedFeaturesGrpList();

		void resetSupportedFeaturesGrpList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserData for datatype PushProfileRequest
		*/
		OctetString* setUserData();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserData for datatype PushProfileRequest
		*/
		void resetUserData();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserData for datatype PushProfileRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserData();

		ChargingInformation* getChargingInformation();

		ChargingInformation* setChargingInformation();

		void resetChargingInformation();

		SIPAuthDataItem* getSIPAuthDataItem();

		SIPAuthDataItem* setSIPAuthDataItem();

		void resetSIPAuthDataItem();

		AllowedWAFWWSFIdentities* getAllowedWAFWWSFIdentities();

		AllowedWAFWWSFIdentities* setAllowedWAFWWSFIdentities();

		void resetAllowedWAFWWSFIdentities();

		list<CX::ProxyInfo*>* getProxyInfoGrpList();

		list<CX::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		//! Function to Decode
		/*!		Function to Decode datatype PushProfileRequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype PushProfileRequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype PushProfileRequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype PushProfileRequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype PushProfileRequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
