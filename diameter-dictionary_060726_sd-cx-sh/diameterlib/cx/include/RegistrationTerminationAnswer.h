#ifndef CX_REGISTRATIONTERMINATIONANSWER_H
#define CX_REGISTRATIONTERMINATIONANSWER_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "cx/include/DRMP.h"
#include "cx/include/VendorSpecificApplicationId.h"
#include "cx/include/ExperimentalResult.h"
#include "cx/include/AuthSessionState.h"
#include "cx/include/AssociatedIdentities.h"
#include "cx/include/SupportedFeatures.h"
#include "cx/include/IdentitywithEmergencyRegistration.h"
#include "cx/include/FailedAVP.h"
#include "cx/include/ProxyInfo.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace CX{
typedef enum _tags_RegistrationTerminationAnswer
{
	RegistrationTerminationAnswer_SESSIONID	= 0,
	RegistrationTerminationAnswer_DRMP	= 1,
	RegistrationTerminationAnswer_VENDORSPECIFICAPPLICATIONID	= 2,
	RegistrationTerminationAnswer_RESULTCODE	= 3,
	RegistrationTerminationAnswer_EXPERIMENTALRESULT	= 4,
	RegistrationTerminationAnswer_AUTHSESSIONSTATE	= 5,
	RegistrationTerminationAnswer_ORIGINHOST	= 6,
	RegistrationTerminationAnswer_ORIGINREALM	= 7,
	RegistrationTerminationAnswer_ASSOCIATEDIDENTITIES	= 8,
	RegistrationTerminationAnswer_SUPPORTEDFEATURES	= 9,
	RegistrationTerminationAnswer_IDENTITYWITHEMERGENCYREGISTRATION	= 10,
	RegistrationTerminationAnswer_ERRORMESSAGE	= 11,
	RegistrationTerminationAnswer_FAILEDAVP	= 12,
	RegistrationTerminationAnswer_PROXYINFO	= 13,
	RegistrationTerminationAnswer_ROUTERECORD	= 14,
}RegistrationTerminationAnswer_tags;

		//! Class Definition
		/*!		ClassName is RegistrationTerminationAnswer
		*/
class RegistrationTerminationAnswer : public DiameterBase 
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

		Unsigned32*		mResultCode;

		AuthSessionState*		mAuthSessionState;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		OctetString*		mErrorMessage;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;




		VendorSpecificApplicationId*	mVendorSpecificApplicationIdGrp;


		ExperimentalResult*	mExperimentalResultGrp;




		AssociatedIdentities*	mAssociatedIdentitiesGrp;

		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;

		list<IdentitywithEmergencyRegistration*>*	mIdentitywithEmergencyRegistrationGrpList;
		list<IdentitywithEmergencyRegistration*>::iterator	mIdentitywithEmergencyRegistrationGrpIterator;


		FailedAVP*	mFailedAVPGrp;

		list<CX::ProxyInfo*>*	mProxyInfoGrpList;
		list<CX::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		RegistrationTerminationAnswer();

		RegistrationTerminationAnswer(const RegistrationTerminationAnswer &objRegistrationTerminationAnswer) {

		mTagsPresent = objRegistrationTerminationAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objRegistrationTerminationAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objRegistrationTerminationAnswer.mMandatoryAvpSetVal;

		mTag = objRegistrationTerminationAnswer.mTag;

		mDecodeFlag = objRegistrationTerminationAnswer.mDecodeFlag;

		if(objRegistrationTerminationAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objRegistrationTerminationAnswer.mSessionId));

		if(objRegistrationTerminationAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objRegistrationTerminationAnswer.mDRMP));

		if(objRegistrationTerminationAnswer.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objRegistrationTerminationAnswer.mVendorSpecificApplicationIdGrp);
		 }
		if(objRegistrationTerminationAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objRegistrationTerminationAnswer.mResultCode));

		if(objRegistrationTerminationAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objRegistrationTerminationAnswer.mExperimentalResultGrp);
		 }
		if(objRegistrationTerminationAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objRegistrationTerminationAnswer.mAuthSessionState));

		if(objRegistrationTerminationAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objRegistrationTerminationAnswer.mOriginHost));

		if(objRegistrationTerminationAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objRegistrationTerminationAnswer.mOriginRealm));

		if(objRegistrationTerminationAnswer.mAssociatedIdentitiesGrp != NULL)
		 {
				 mAssociatedIdentitiesGrp =  new AssociatedIdentities(*objRegistrationTerminationAnswer.mAssociatedIdentitiesGrp);
		 }
		if(objRegistrationTerminationAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objRegistrationTerminationAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objRegistrationTerminationAnswer.mIdentitywithEmergencyRegistrationGrpList != NULL)
		 {
		 mIdentitywithEmergencyRegistrationGrpList = new list<IdentitywithEmergencyRegistration*>;
		 for( auto element : *objRegistrationTerminationAnswer.mIdentitywithEmergencyRegistrationGrpList)
		 {
				 IdentitywithEmergencyRegistration *lIdentitywithEmergencyRegistration =  new IdentitywithEmergencyRegistration(*element);
				 mIdentitywithEmergencyRegistrationGrpList->push_back(lIdentitywithEmergencyRegistration);
		 }
		 }
		if(objRegistrationTerminationAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objRegistrationTerminationAnswer.mErrorMessage));

		if(objRegistrationTerminationAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objRegistrationTerminationAnswer.mFailedAVPGrp);
		 }
		if(objRegistrationTerminationAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objRegistrationTerminationAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const RegistrationTerminationAnswer &objRegistrationTerminationAnswer) {

		mTagsPresent = objRegistrationTerminationAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objRegistrationTerminationAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objRegistrationTerminationAnswer.mMandatoryAvpSetVal;

		mTag = objRegistrationTerminationAnswer.mTag;

		mDecodeFlag = objRegistrationTerminationAnswer.mDecodeFlag;

		if(objRegistrationTerminationAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objRegistrationTerminationAnswer.mSessionId));

		if(objRegistrationTerminationAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objRegistrationTerminationAnswer.mDRMP));

		if(objRegistrationTerminationAnswer.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objRegistrationTerminationAnswer.mVendorSpecificApplicationIdGrp);
		 }
		if(objRegistrationTerminationAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objRegistrationTerminationAnswer.mResultCode));

		if(objRegistrationTerminationAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objRegistrationTerminationAnswer.mExperimentalResultGrp);
		 }
		if(objRegistrationTerminationAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objRegistrationTerminationAnswer.mAuthSessionState));

		if(objRegistrationTerminationAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objRegistrationTerminationAnswer.mOriginHost));

		if(objRegistrationTerminationAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objRegistrationTerminationAnswer.mOriginRealm));

		if(objRegistrationTerminationAnswer.mAssociatedIdentitiesGrp != NULL)
		 {
				 mAssociatedIdentitiesGrp =  new AssociatedIdentities(*objRegistrationTerminationAnswer.mAssociatedIdentitiesGrp);
		 }
		if(objRegistrationTerminationAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objRegistrationTerminationAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objRegistrationTerminationAnswer.mIdentitywithEmergencyRegistrationGrpList != NULL)
		 {
		 mIdentitywithEmergencyRegistrationGrpList = new list<IdentitywithEmergencyRegistration*>;
		 for( auto element : *objRegistrationTerminationAnswer.mIdentitywithEmergencyRegistrationGrpList)
		 {
				 IdentitywithEmergencyRegistration *lIdentitywithEmergencyRegistration =  new IdentitywithEmergencyRegistration(*element);
				 mIdentitywithEmergencyRegistrationGrpList->push_back(lIdentitywithEmergencyRegistration);
		 }
		 }
		if(objRegistrationTerminationAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objRegistrationTerminationAnswer.mErrorMessage));

		if(objRegistrationTerminationAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objRegistrationTerminationAnswer.mFailedAVPGrp);
		 }
		if(objRegistrationTerminationAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objRegistrationTerminationAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~RegistrationTerminationAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype RegistrationTerminationAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype RegistrationTerminationAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype RegistrationTerminationAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype RegistrationTerminationAnswer
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype RegistrationTerminationAnswer
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype RegistrationTerminationAnswer
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		VendorSpecificApplicationId* getVendorSpecificApplicationId();

		VendorSpecificApplicationId* setVendorSpecificApplicationId();

		void resetVendorSpecificApplicationId();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype RegistrationTerminationAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype RegistrationTerminationAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype RegistrationTerminationAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		ExperimentalResult* getExperimentalResult();

		ExperimentalResult* setExperimentalResult();

		void resetExperimentalResult();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype RegistrationTerminationAnswer
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype RegistrationTerminationAnswer
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype RegistrationTerminationAnswer
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype RegistrationTerminationAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype RegistrationTerminationAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype RegistrationTerminationAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype RegistrationTerminationAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype RegistrationTerminationAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype RegistrationTerminationAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		AssociatedIdentities* getAssociatedIdentities();

		AssociatedIdentities* setAssociatedIdentities();

		void resetAssociatedIdentities();

		list<SupportedFeatures*>* getSupportedFeaturesGrpList();

		list<SupportedFeatures*>* setSupportedFeaturesGrpList();

		void resetSupportedFeaturesGrpList();

		list<IdentitywithEmergencyRegistration*>* getIdentitywithEmergencyRegistrationGrpList();

		list<IdentitywithEmergencyRegistration*>* setIdentitywithEmergencyRegistrationGrpList();

		void resetIdentitywithEmergencyRegistrationGrpList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorMessage for datatype RegistrationTerminationAnswer
		*/
		OctetString* setErrorMessage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorMessage for datatype RegistrationTerminationAnswer
		*/
		void resetErrorMessage();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorMessage for datatype RegistrationTerminationAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorMessage();

		FailedAVP* getFailedAVP();

		FailedAVP* setFailedAVP();

		void resetFailedAVP();

		list<CX::ProxyInfo*>* getProxyInfoGrpList();

		list<CX::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		//! Function to Decode
		/*!		Function to Decode datatype RegistrationTerminationAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype RegistrationTerminationAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype RegistrationTerminationAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype RegistrationTerminationAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype RegistrationTerminationAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
