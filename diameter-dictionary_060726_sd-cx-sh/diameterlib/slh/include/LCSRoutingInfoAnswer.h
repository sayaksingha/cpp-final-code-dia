#ifndef SLH_LCSROUTINGINFOANSWER_H
#define SLH_LCSROUTINGINFOANSWER_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"
#include "slh/include/ProxyInfo.h"
#include "slh/include/VendorSpecificApplicationId.h"
#include "slh/include/ExperimentalResult.h"
#include "slh/include/AuthSessionState.h"
#include "slh/include/SupportedFeatures.h"
#include "slh/include/ServingNode.h"
#include "slh/include/AdditionalServingNode.h"
#include "slh/include/FailedAVP.h"
#include "slh/include/ProxyInfo.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace SLH{
typedef enum _tags_LCSRoutingInfoAnswer
{
	LCSRoutingInfoAnswer_SESSIONID	= 0,
	LCSRoutingInfoAnswer_VENDORSPECIFICAPPLICATIONID	= 1,
	LCSRoutingInfoAnswer_RESULTCODE	= 2,
	LCSRoutingInfoAnswer_EXPERIMENTALRESULT	= 3,
	LCSRoutingInfoAnswer_AUTHSESSIONSTATE	= 4,
	LCSRoutingInfoAnswer_ORIGINHOST	= 5,
	LCSRoutingInfoAnswer_ORIGINREALM	= 6,
	LCSRoutingInfoAnswer_SUPPORTEDFEATURES	= 7,
	LCSRoutingInfoAnswer_USERNAME	= 8,
	LCSRoutingInfoAnswer_MSISDN	= 9,
	LCSRoutingInfoAnswer_LMSI	= 10,
	LCSRoutingInfoAnswer_SERVINGNODE	= 11,
	LCSRoutingInfoAnswer_ADDITIONALSERVINGNODE	= 12,
	LCSRoutingInfoAnswer_GMLCADDRESS	= 13,
	LCSRoutingInfoAnswer_PPRADDRESS	= 14,
	LCSRoutingInfoAnswer_RIAFLAGS	= 15,
	LCSRoutingInfoAnswer_FAILEDAVP	= 16,
	LCSRoutingInfoAnswer_PROXYINFO	= 17,
	LCSRoutingInfoAnswer_ROUTERECORD	= 18,
}LCSRoutingInfoAnswer_tags;

		//! Class Definition
		/*!		ClassName is LCSRoutingInfoAnswer
		*/
class LCSRoutingInfoAnswer : public DiameterBase 
{
	private:

		bitset<19> mTagsPresent;

		bitset<19> mMandatoryAvpCheckVal;

		bitset<19> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		Unsigned32*		mResultCode;

		AuthSessionState*		mAuthSessionState;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		OctetString*		mUserName;

		OctetString*		mMSISDN;

		OctetString*		mLMSI;

		list<OctetString*>* 		mGMLCAddressList;

		list<OctetString*>::iterator 		mGMLCAddressIterator;

		list<OctetString*>* 		mPPRAddressList;

		list<OctetString*>::iterator 		mPPRAddressIterator;

		Unsigned32*		mRIAFlags;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;



		list<VendorSpecificApplicationId*>*	mVendorSpecificApplicationIdGrpList;
		list<VendorSpecificApplicationId*>::iterator	mVendorSpecificApplicationIdGrpIterator;


		ExperimentalResult*	mExperimentalResultGrp;




		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;




		ServingNode*	mServingNodeGrp;

		list<AdditionalServingNode*>*	mAdditionalServingNodeGrpList;
		list<AdditionalServingNode*>::iterator	mAdditionalServingNodeGrpIterator;




		FailedAVP*	mFailedAVPGrp;

		list<SLH::ProxyInfo*>*	mProxyInfoGrpList;
		list<SLH::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		LCSRoutingInfoAnswer();

		LCSRoutingInfoAnswer(const LCSRoutingInfoAnswer &objLCSRoutingInfoAnswer) {

		mTagsPresent = objLCSRoutingInfoAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objLCSRoutingInfoAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objLCSRoutingInfoAnswer.mMandatoryAvpSetVal;

		mTag = objLCSRoutingInfoAnswer.mTag;

		mDecodeFlag = objLCSRoutingInfoAnswer.mDecodeFlag;

		if(objLCSRoutingInfoAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objLCSRoutingInfoAnswer.mSessionId));

		if(objLCSRoutingInfoAnswer.mVendorSpecificApplicationIdGrpList != NULL)
		 {
		 mVendorSpecificApplicationIdGrpList = new list<VendorSpecificApplicationId*>;
		 for( auto element : *objLCSRoutingInfoAnswer.mVendorSpecificApplicationIdGrpList)
		 {
				 VendorSpecificApplicationId *lVendorSpecificApplicationId =  new VendorSpecificApplicationId(*element);
				 mVendorSpecificApplicationIdGrpList->push_back(lVendorSpecificApplicationId);
		 }
		 }
		if(objLCSRoutingInfoAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objLCSRoutingInfoAnswer.mResultCode));

		if(objLCSRoutingInfoAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objLCSRoutingInfoAnswer.mExperimentalResultGrp);
		 }
		if(objLCSRoutingInfoAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objLCSRoutingInfoAnswer.mAuthSessionState));

		if(objLCSRoutingInfoAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objLCSRoutingInfoAnswer.mOriginHost));

		if(objLCSRoutingInfoAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objLCSRoutingInfoAnswer.mOriginRealm));

		if(objLCSRoutingInfoAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objLCSRoutingInfoAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objLCSRoutingInfoAnswer.mUserName != NULL)
		mUserName = new OctetString(*(objLCSRoutingInfoAnswer.mUserName));

		if(objLCSRoutingInfoAnswer.mMSISDN != NULL)
		mMSISDN = new OctetString(*(objLCSRoutingInfoAnswer.mMSISDN));

		if(objLCSRoutingInfoAnswer.mLMSI != NULL)
		mLMSI = new OctetString(*(objLCSRoutingInfoAnswer.mLMSI));

		if(objLCSRoutingInfoAnswer.mServingNodeGrp != NULL)
		 {
				 mServingNodeGrp =  new ServingNode(*objLCSRoutingInfoAnswer.mServingNodeGrp);
		 }
		if(objLCSRoutingInfoAnswer.mAdditionalServingNodeGrpList != NULL)
		 {
		 mAdditionalServingNodeGrpList = new list<AdditionalServingNode*>;
		 for( auto element : *objLCSRoutingInfoAnswer.mAdditionalServingNodeGrpList)
		 {
				 AdditionalServingNode *lAdditionalServingNode =  new AdditionalServingNode(*element);
				 mAdditionalServingNodeGrpList->push_back(lAdditionalServingNode);
		 }
		 }
		if(objLCSRoutingInfoAnswer.mRIAFlags != NULL)
		mRIAFlags = new Unsigned32(*(objLCSRoutingInfoAnswer.mRIAFlags));

		if(objLCSRoutingInfoAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objLCSRoutingInfoAnswer.mFailedAVPGrp);
		 }
		if(objLCSRoutingInfoAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SLH::ProxyInfo*>;
		 for( auto element : *objLCSRoutingInfoAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const LCSRoutingInfoAnswer &objLCSRoutingInfoAnswer) {

		mTagsPresent = objLCSRoutingInfoAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objLCSRoutingInfoAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objLCSRoutingInfoAnswer.mMandatoryAvpSetVal;

		mTag = objLCSRoutingInfoAnswer.mTag;

		mDecodeFlag = objLCSRoutingInfoAnswer.mDecodeFlag;

		if(objLCSRoutingInfoAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objLCSRoutingInfoAnswer.mSessionId));

		if(objLCSRoutingInfoAnswer.mVendorSpecificApplicationIdGrpList != NULL)
		 {
		 mVendorSpecificApplicationIdGrpList = new list<VendorSpecificApplicationId*>;
		 for( auto element : *objLCSRoutingInfoAnswer.mVendorSpecificApplicationIdGrpList)
		 {
				 VendorSpecificApplicationId *lVendorSpecificApplicationId =  new VendorSpecificApplicationId(*element);
				 mVendorSpecificApplicationIdGrpList->push_back(lVendorSpecificApplicationId);
		 }
		 }
		if(objLCSRoutingInfoAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objLCSRoutingInfoAnswer.mResultCode));

		if(objLCSRoutingInfoAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objLCSRoutingInfoAnswer.mExperimentalResultGrp);
		 }
		if(objLCSRoutingInfoAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objLCSRoutingInfoAnswer.mAuthSessionState));

		if(objLCSRoutingInfoAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objLCSRoutingInfoAnswer.mOriginHost));

		if(objLCSRoutingInfoAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objLCSRoutingInfoAnswer.mOriginRealm));

		if(objLCSRoutingInfoAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objLCSRoutingInfoAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objLCSRoutingInfoAnswer.mUserName != NULL)
		mUserName = new OctetString(*(objLCSRoutingInfoAnswer.mUserName));

		if(objLCSRoutingInfoAnswer.mMSISDN != NULL)
		mMSISDN = new OctetString(*(objLCSRoutingInfoAnswer.mMSISDN));

		if(objLCSRoutingInfoAnswer.mLMSI != NULL)
		mLMSI = new OctetString(*(objLCSRoutingInfoAnswer.mLMSI));

		if(objLCSRoutingInfoAnswer.mServingNodeGrp != NULL)
		 {
				 mServingNodeGrp =  new ServingNode(*objLCSRoutingInfoAnswer.mServingNodeGrp);
		 }
		if(objLCSRoutingInfoAnswer.mAdditionalServingNodeGrpList != NULL)
		 {
		 mAdditionalServingNodeGrpList = new list<AdditionalServingNode*>;
		 for( auto element : *objLCSRoutingInfoAnswer.mAdditionalServingNodeGrpList)
		 {
				 AdditionalServingNode *lAdditionalServingNode =  new AdditionalServingNode(*element);
				 mAdditionalServingNodeGrpList->push_back(lAdditionalServingNode);
		 }
		 }
		if(objLCSRoutingInfoAnswer.mRIAFlags != NULL)
		mRIAFlags = new Unsigned32(*(objLCSRoutingInfoAnswer.mRIAFlags));

		if(objLCSRoutingInfoAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objLCSRoutingInfoAnswer.mFailedAVPGrp);
		 }
		if(objLCSRoutingInfoAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SLH::ProxyInfo*>;
		 for( auto element : *objLCSRoutingInfoAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~LCSRoutingInfoAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype LCSRoutingInfoAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype LCSRoutingInfoAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype LCSRoutingInfoAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		list<VendorSpecificApplicationId*>* getVendorSpecificApplicationIdGrpList();

		list<VendorSpecificApplicationId*>* setVendorSpecificApplicationIdGrpList();

		void resetVendorSpecificApplicationIdGrpList();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype LCSRoutingInfoAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype LCSRoutingInfoAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype LCSRoutingInfoAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		ExperimentalResult* getExperimentalResult();

		ExperimentalResult* setExperimentalResult();

		void resetExperimentalResult();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype LCSRoutingInfoAnswer
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype LCSRoutingInfoAnswer
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype LCSRoutingInfoAnswer
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype LCSRoutingInfoAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype LCSRoutingInfoAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype LCSRoutingInfoAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype LCSRoutingInfoAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype LCSRoutingInfoAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype LCSRoutingInfoAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		list<SupportedFeatures*>* getSupportedFeaturesGrpList();

		list<SupportedFeatures*>* setSupportedFeaturesGrpList();

		void resetSupportedFeaturesGrpList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserName for datatype LCSRoutingInfoAnswer
		*/
		OctetString* setUserName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserName for datatype LCSRoutingInfoAnswer
		*/
		void resetUserName();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserName for datatype LCSRoutingInfoAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserName();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument MSISDN for datatype LCSRoutingInfoAnswer
		*/
		OctetString* setMSISDN();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MSISDN for datatype LCSRoutingInfoAnswer
		*/
		void resetMSISDN();

		//!Function to get values
		/*!		Function to get OctetString type of argument MSISDN for datatype LCSRoutingInfoAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getMSISDN();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument LMSI for datatype LCSRoutingInfoAnswer
		*/
		OctetString* setLMSI();

		//! Function to reset 
		/*!		Function to reset NULL type of argument LMSI for datatype LCSRoutingInfoAnswer
		*/
		void resetLMSI();

		//!Function to get values
		/*!		Function to get OctetString type of argument LMSI for datatype LCSRoutingInfoAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getLMSI();

		ServingNode* getServingNode();

		ServingNode* setServingNode();

		void resetServingNode();

		list<AdditionalServingNode*>* getAdditionalServingNodeGrpList();

		list<AdditionalServingNode*>* setAdditionalServingNodeGrpList();

		void resetAdditionalServingNodeGrpList();

		list<OctetString*>* getGMLCAddressList();

		list<OctetString*>* setGMLCAddressList();

		void resetGMLCAddressList();

		list<OctetString*>* getPPRAddressList();

		list<OctetString*>* setPPRAddressList();

		void resetPPRAddressList();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument RIAFlags for datatype LCSRoutingInfoAnswer
		*/
		Unsigned32* setRIAFlags();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RIAFlags for datatype LCSRoutingInfoAnswer
		*/
		void resetRIAFlags();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument RIAFlags for datatype LCSRoutingInfoAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getRIAFlags();

		FailedAVP* getFailedAVP();

		FailedAVP* setFailedAVP();

		void resetFailedAVP();

		list<SLH::ProxyInfo*>* getProxyInfoGrpList();

		list<SLH::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		//! Function to Decode
		/*!		Function to Decode datatype LCSRoutingInfoAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype LCSRoutingInfoAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype LCSRoutingInfoAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype LCSRoutingInfoAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype LCSRoutingInfoAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
