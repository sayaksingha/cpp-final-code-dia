#ifndef CX_PUSHPROFILEANSWER_H
#define CX_PUSHPROFILEANSWER_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "cx/include/DRMP.h"
#include "cx/include/VendorSpecificApplicationId.h"
#include "cx/include/ExperimentalResult.h"
#include "cx/include/AuthSessionState.h"
#include "cx/include/SupportedFeatures.h"
#include "cx/include/FailedAVP.h"
#include "cx/include/ProxyInfo.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace CX{
typedef enum _tags_PushProfileAnswer
{
	PushProfileAnswer_SESSIONID	= 0,
	PushProfileAnswer_DRMP	= 1,
	PushProfileAnswer_VENDORSPECIFICAPPLICATIONID	= 2,
	PushProfileAnswer_RESULTCODE	= 3,
	PushProfileAnswer_EXPERIMENTALRESULT	= 4,
	PushProfileAnswer_AUTHSESSIONSTATE	= 5,
	PushProfileAnswer_ORIGINHOST	= 6,
	PushProfileAnswer_ORIGINREALM	= 7,
	PushProfileAnswer_SUPPORTEDFEATURES	= 8,
	PushProfileAnswer_ERRORMESSAGE	= 9,
	PushProfileAnswer_FAILEDAVP	= 10,
	PushProfileAnswer_PROXYINFO	= 11,
	PushProfileAnswer_ROUTERECORD	= 12,
}PushProfileAnswer_tags;

		//! Class Definition
		/*!		ClassName is PushProfileAnswer
		*/
class PushProfileAnswer : public DiameterBase 
{
	private:

		bitset<13> mTagsPresent;

		bitset<13> mMandatoryAvpCheckVal;

		bitset<13> mMandatoryAvpSetVal;

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




		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;


		FailedAVP*	mFailedAVPGrp;

		list<CX::ProxyInfo*>*	mProxyInfoGrpList;
		list<CX::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		PushProfileAnswer();

		PushProfileAnswer(const PushProfileAnswer &objPushProfileAnswer) {

		mTagsPresent = objPushProfileAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objPushProfileAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objPushProfileAnswer.mMandatoryAvpSetVal;

		mTag = objPushProfileAnswer.mTag;

		mDecodeFlag = objPushProfileAnswer.mDecodeFlag;

		if(objPushProfileAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objPushProfileAnswer.mSessionId));

		if(objPushProfileAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objPushProfileAnswer.mDRMP));

		if(objPushProfileAnswer.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objPushProfileAnswer.mVendorSpecificApplicationIdGrp);
		 }
		if(objPushProfileAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objPushProfileAnswer.mResultCode));

		if(objPushProfileAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objPushProfileAnswer.mExperimentalResultGrp);
		 }
		if(objPushProfileAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objPushProfileAnswer.mAuthSessionState));

		if(objPushProfileAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objPushProfileAnswer.mOriginHost));

		if(objPushProfileAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objPushProfileAnswer.mOriginRealm));

		if(objPushProfileAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objPushProfileAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objPushProfileAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objPushProfileAnswer.mErrorMessage));

		if(objPushProfileAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objPushProfileAnswer.mFailedAVPGrp);
		 }
		if(objPushProfileAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objPushProfileAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const PushProfileAnswer &objPushProfileAnswer) {

		mTagsPresent = objPushProfileAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objPushProfileAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objPushProfileAnswer.mMandatoryAvpSetVal;

		mTag = objPushProfileAnswer.mTag;

		mDecodeFlag = objPushProfileAnswer.mDecodeFlag;

		if(objPushProfileAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objPushProfileAnswer.mSessionId));

		if(objPushProfileAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objPushProfileAnswer.mDRMP));

		if(objPushProfileAnswer.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objPushProfileAnswer.mVendorSpecificApplicationIdGrp);
		 }
		if(objPushProfileAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objPushProfileAnswer.mResultCode));

		if(objPushProfileAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objPushProfileAnswer.mExperimentalResultGrp);
		 }
		if(objPushProfileAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objPushProfileAnswer.mAuthSessionState));

		if(objPushProfileAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objPushProfileAnswer.mOriginHost));

		if(objPushProfileAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objPushProfileAnswer.mOriginRealm));

		if(objPushProfileAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objPushProfileAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objPushProfileAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objPushProfileAnswer.mErrorMessage));

		if(objPushProfileAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objPushProfileAnswer.mFailedAVPGrp);
		 }
		if(objPushProfileAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objPushProfileAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~PushProfileAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype PushProfileAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype PushProfileAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype PushProfileAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype PushProfileAnswer
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype PushProfileAnswer
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype PushProfileAnswer
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		VendorSpecificApplicationId* getVendorSpecificApplicationId();

		VendorSpecificApplicationId* setVendorSpecificApplicationId();

		void resetVendorSpecificApplicationId();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype PushProfileAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype PushProfileAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype PushProfileAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		ExperimentalResult* getExperimentalResult();

		ExperimentalResult* setExperimentalResult();

		void resetExperimentalResult();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype PushProfileAnswer
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype PushProfileAnswer
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype PushProfileAnswer
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype PushProfileAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype PushProfileAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype PushProfileAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype PushProfileAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype PushProfileAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype PushProfileAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		list<SupportedFeatures*>* getSupportedFeaturesGrpList();

		list<SupportedFeatures*>* setSupportedFeaturesGrpList();

		void resetSupportedFeaturesGrpList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorMessage for datatype PushProfileAnswer
		*/
		OctetString* setErrorMessage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorMessage for datatype PushProfileAnswer
		*/
		void resetErrorMessage();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorMessage for datatype PushProfileAnswer
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
		/*!		Function to Decode datatype PushProfileAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype PushProfileAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype PushProfileAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype PushProfileAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype PushProfileAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
