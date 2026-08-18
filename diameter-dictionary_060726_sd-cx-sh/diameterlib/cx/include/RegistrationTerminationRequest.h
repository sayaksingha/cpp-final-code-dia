#ifndef CX_REGISTRATIONTERMINATIONREQUEST_H
#define CX_REGISTRATIONTERMINATIONREQUEST_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "cx/include/DRMP.h"
#include "cx/include/VendorSpecificApplicationId.h"
#include "cx/include/AuthSessionState.h"
#include "cx/include/AssociatedIdentities.h"
#include "cx/include/SupportedFeatures.h"
#include "cx/include/DeregistrationReason.h"
#include "cx/include/ProxyInfo.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace CX{
typedef enum _tags_RegistrationTerminationRequest
{
	RegistrationTerminationRequest_SESSIONID	= 0,
	RegistrationTerminationRequest_DRMP	= 1,
	RegistrationTerminationRequest_VENDORSPECIFICAPPLICATIONID	= 2,
	RegistrationTerminationRequest_AUTHSESSIONSTATE	= 3,
	RegistrationTerminationRequest_ORIGINHOST	= 4,
	RegistrationTerminationRequest_ORIGINREALM	= 5,
	RegistrationTerminationRequest_DESTINATIONREALM	= 6,
	RegistrationTerminationRequest_USERNAME	= 7,
	RegistrationTerminationRequest_ASSOCIATEDIDENTITIES	= 8,
	RegistrationTerminationRequest_SUPPORTEDFEATURES	= 9,
	RegistrationTerminationRequest_PUBLICIDENTITY	= 10,
	RegistrationTerminationRequest_DEREGISTRATIONREASON	= 11,
	RegistrationTerminationRequest_RTRFLAGS	= 12,
	RegistrationTerminationRequest_PROXYINFO	= 13,
	RegistrationTerminationRequest_ROUTERECORD	= 14,
}RegistrationTerminationRequest_tags;

		//! Class Definition
		/*!		ClassName is RegistrationTerminationRequest
		*/
class RegistrationTerminationRequest : public DiameterBase 
{
	private:

		bitset<15> mTagsPresent;

		bitset<15> mMandatoryAvpCheckVal;

		bitset<15> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		DRMP*		mDRMP;

		AuthSessionState*		mAuthSessionState;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		OctetString*		mDestinationRealm;

		OctetString*		mUserName;

		list<OctetString*>* 		mPublicIdentityList;

		list<OctetString*>::iterator 		mPublicIdentityIterator;

		Unsigned32*		mRTRFlags;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;




		VendorSpecificApplicationId*	mVendorSpecificApplicationIdGrp;






		AssociatedIdentities*	mAssociatedIdentitiesGrp;

		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;


		DeregistrationReason*	mDeregistrationReasonGrp;


		list<CX::ProxyInfo*>*	mProxyInfoGrpList;
		list<CX::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		RegistrationTerminationRequest();

		RegistrationTerminationRequest(const RegistrationTerminationRequest &objRegistrationTerminationRequest) {

		mTagsPresent = objRegistrationTerminationRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objRegistrationTerminationRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objRegistrationTerminationRequest.mMandatoryAvpSetVal;

		mTag = objRegistrationTerminationRequest.mTag;

		mDecodeFlag = objRegistrationTerminationRequest.mDecodeFlag;

		if(objRegistrationTerminationRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objRegistrationTerminationRequest.mSessionId));

		if(objRegistrationTerminationRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objRegistrationTerminationRequest.mDRMP));

		if(objRegistrationTerminationRequest.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objRegistrationTerminationRequest.mVendorSpecificApplicationIdGrp);
		 }
		if(objRegistrationTerminationRequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objRegistrationTerminationRequest.mAuthSessionState));

		if(objRegistrationTerminationRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objRegistrationTerminationRequest.mOriginHost));

		if(objRegistrationTerminationRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objRegistrationTerminationRequest.mOriginRealm));

		if(objRegistrationTerminationRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objRegistrationTerminationRequest.mDestinationRealm));

		if(objRegistrationTerminationRequest.mUserName != NULL)
		mUserName = new OctetString(*(objRegistrationTerminationRequest.mUserName));

		if(objRegistrationTerminationRequest.mAssociatedIdentitiesGrp != NULL)
		 {
				 mAssociatedIdentitiesGrp =  new AssociatedIdentities(*objRegistrationTerminationRequest.mAssociatedIdentitiesGrp);
		 }
		if(objRegistrationTerminationRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objRegistrationTerminationRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objRegistrationTerminationRequest.mDeregistrationReasonGrp != NULL)
		 {
				 mDeregistrationReasonGrp =  new DeregistrationReason(*objRegistrationTerminationRequest.mDeregistrationReasonGrp);
		 }
		if(objRegistrationTerminationRequest.mRTRFlags != NULL)
		mRTRFlags = new Unsigned32(*(objRegistrationTerminationRequest.mRTRFlags));

		if(objRegistrationTerminationRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objRegistrationTerminationRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const RegistrationTerminationRequest &objRegistrationTerminationRequest) {

		mTagsPresent = objRegistrationTerminationRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objRegistrationTerminationRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objRegistrationTerminationRequest.mMandatoryAvpSetVal;

		mTag = objRegistrationTerminationRequest.mTag;

		mDecodeFlag = objRegistrationTerminationRequest.mDecodeFlag;

		if(objRegistrationTerminationRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objRegistrationTerminationRequest.mSessionId));

		if(objRegistrationTerminationRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objRegistrationTerminationRequest.mDRMP));

		if(objRegistrationTerminationRequest.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objRegistrationTerminationRequest.mVendorSpecificApplicationIdGrp);
		 }
		if(objRegistrationTerminationRequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objRegistrationTerminationRequest.mAuthSessionState));

		if(objRegistrationTerminationRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objRegistrationTerminationRequest.mOriginHost));

		if(objRegistrationTerminationRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objRegistrationTerminationRequest.mOriginRealm));

		if(objRegistrationTerminationRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objRegistrationTerminationRequest.mDestinationRealm));

		if(objRegistrationTerminationRequest.mUserName != NULL)
		mUserName = new OctetString(*(objRegistrationTerminationRequest.mUserName));

		if(objRegistrationTerminationRequest.mAssociatedIdentitiesGrp != NULL)
		 {
				 mAssociatedIdentitiesGrp =  new AssociatedIdentities(*objRegistrationTerminationRequest.mAssociatedIdentitiesGrp);
		 }
		if(objRegistrationTerminationRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objRegistrationTerminationRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objRegistrationTerminationRequest.mDeregistrationReasonGrp != NULL)
		 {
				 mDeregistrationReasonGrp =  new DeregistrationReason(*objRegistrationTerminationRequest.mDeregistrationReasonGrp);
		 }
		if(objRegistrationTerminationRequest.mRTRFlags != NULL)
		mRTRFlags = new Unsigned32(*(objRegistrationTerminationRequest.mRTRFlags));

		if(objRegistrationTerminationRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objRegistrationTerminationRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~RegistrationTerminationRequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype RegistrationTerminationRequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype RegistrationTerminationRequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype RegistrationTerminationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype RegistrationTerminationRequest
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype RegistrationTerminationRequest
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype RegistrationTerminationRequest
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		VendorSpecificApplicationId* getVendorSpecificApplicationId();

		VendorSpecificApplicationId* setVendorSpecificApplicationId();

		void resetVendorSpecificApplicationId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype RegistrationTerminationRequest
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype RegistrationTerminationRequest
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype RegistrationTerminationRequest
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype RegistrationTerminationRequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype RegistrationTerminationRequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype RegistrationTerminationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype RegistrationTerminationRequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype RegistrationTerminationRequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype RegistrationTerminationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationRealm for datatype RegistrationTerminationRequest
		*/
		OctetString* setDestinationRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationRealm for datatype RegistrationTerminationRequest
		*/
		void resetDestinationRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationRealm for datatype RegistrationTerminationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserName for datatype RegistrationTerminationRequest
		*/
		OctetString* setUserName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserName for datatype RegistrationTerminationRequest
		*/
		void resetUserName();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserName for datatype RegistrationTerminationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserName();

		AssociatedIdentities* getAssociatedIdentities();

		AssociatedIdentities* setAssociatedIdentities();

		void resetAssociatedIdentities();

		list<SupportedFeatures*>* getSupportedFeaturesGrpList();

		list<SupportedFeatures*>* setSupportedFeaturesGrpList();

		void resetSupportedFeaturesGrpList();

		list<OctetString*>* getPublicIdentityList();

		list<OctetString*>* setPublicIdentityList();

		void resetPublicIdentityList();

		DeregistrationReason* getDeregistrationReason();

		DeregistrationReason* setDeregistrationReason();

		void resetDeregistrationReason();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument RTRFlags for datatype RegistrationTerminationRequest
		*/
		Unsigned32* setRTRFlags();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RTRFlags for datatype RegistrationTerminationRequest
		*/
		void resetRTRFlags();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument RTRFlags for datatype RegistrationTerminationRequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getRTRFlags();

		list<CX::ProxyInfo*>* getProxyInfoGrpList();

		list<CX::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		//! Function to Decode
		/*!		Function to Decode datatype RegistrationTerminationRequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype RegistrationTerminationRequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype RegistrationTerminationRequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype RegistrationTerminationRequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype RegistrationTerminationRequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
