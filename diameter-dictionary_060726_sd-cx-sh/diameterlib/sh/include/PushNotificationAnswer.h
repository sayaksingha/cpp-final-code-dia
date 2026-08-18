#ifndef SH_PUSHNOTIFICATIONANSWER_H
#define SH_PUSHNOTIFICATIONANSWER_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sh/include/DRMP.h"
#include "sh/include/VendorSpecificApplicationId.h"
#include "sh/include/ExperimentalResult.h"
#include "sh/include/AuthSessionState.h"
#include "sh/include/SupportedFeatures.h"
#include "sh/include/FailedAVP.h"
#include "sh/include/ProxyInfo.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace SH{
typedef enum _tags_PushNotificationAnswer
{
	PushNotificationAnswer_SESSIONID	= 0,
	PushNotificationAnswer_DRMP	= 1,
	PushNotificationAnswer_VENDORSPECIFICAPPLICATIONID	= 2,
	PushNotificationAnswer_RESULTCODE	= 3,
	PushNotificationAnswer_EXPERIMENTALRESULT	= 4,
	PushNotificationAnswer_AUTHSESSIONSTATE	= 5,
	PushNotificationAnswer_ORIGINHOST	= 6,
	PushNotificationAnswer_ORIGINREALM	= 7,
	PushNotificationAnswer_SUPPORTEDFEATURES	= 8,
	PushNotificationAnswer_FAILEDAVP	= 9,
	PushNotificationAnswer_PROXYINFO	= 10,
	PushNotificationAnswer_ROUTERECORD	= 11,
}PushNotificationAnswer_tags;

		//! Class Definition
		/*!		ClassName is PushNotificationAnswer
		*/
class PushNotificationAnswer : public DiameterBase 
{
	private:

		bitset<12> mTagsPresent;

		bitset<12> mMandatoryAvpCheckVal;

		bitset<12> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		DRMP*		mDRMP;

		Unsigned32*		mResultCode;

		AuthSessionState*		mAuthSessionState;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;




		VendorSpecificApplicationId*	mVendorSpecificApplicationIdGrp;


		ExperimentalResult*	mExperimentalResultGrp;




		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;

		FailedAVP*	mFailedAVPGrp;

		list<SH::ProxyInfo*>*	mProxyInfoGrpList;
		list<SH::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		PushNotificationAnswer();

		PushNotificationAnswer(const PushNotificationAnswer &objPushNotificationAnswer) {

		mTagsPresent = objPushNotificationAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objPushNotificationAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objPushNotificationAnswer.mMandatoryAvpSetVal;

		mTag = objPushNotificationAnswer.mTag;

		mDecodeFlag = objPushNotificationAnswer.mDecodeFlag;

		if(objPushNotificationAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objPushNotificationAnswer.mSessionId));

		if(objPushNotificationAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objPushNotificationAnswer.mDRMP));

		if(objPushNotificationAnswer.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objPushNotificationAnswer.mVendorSpecificApplicationIdGrp);
		 }
		if(objPushNotificationAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objPushNotificationAnswer.mResultCode));

		if(objPushNotificationAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objPushNotificationAnswer.mExperimentalResultGrp);
		 }
		if(objPushNotificationAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objPushNotificationAnswer.mAuthSessionState));

		if(objPushNotificationAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objPushNotificationAnswer.mOriginHost));

		if(objPushNotificationAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objPushNotificationAnswer.mOriginRealm));

		if(objPushNotificationAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objPushNotificationAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objPushNotificationAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objPushNotificationAnswer.mFailedAVPGrp);
		 }
		if(objPushNotificationAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SH::ProxyInfo*>;
		 for( auto element : *objPushNotificationAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const PushNotificationAnswer &objPushNotificationAnswer) {

		mTagsPresent = objPushNotificationAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objPushNotificationAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objPushNotificationAnswer.mMandatoryAvpSetVal;

		mTag = objPushNotificationAnswer.mTag;

		mDecodeFlag = objPushNotificationAnswer.mDecodeFlag;

		if(objPushNotificationAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objPushNotificationAnswer.mSessionId));

		if(objPushNotificationAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objPushNotificationAnswer.mDRMP));

		if(objPushNotificationAnswer.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objPushNotificationAnswer.mVendorSpecificApplicationIdGrp);
		 }
		if(objPushNotificationAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objPushNotificationAnswer.mResultCode));

		if(objPushNotificationAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objPushNotificationAnswer.mExperimentalResultGrp);
		 }
		if(objPushNotificationAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objPushNotificationAnswer.mAuthSessionState));

		if(objPushNotificationAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objPushNotificationAnswer.mOriginHost));

		if(objPushNotificationAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objPushNotificationAnswer.mOriginRealm));

		if(objPushNotificationAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objPushNotificationAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objPushNotificationAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objPushNotificationAnswer.mFailedAVPGrp);
		 }
		if(objPushNotificationAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SH::ProxyInfo*>;
		 for( auto element : *objPushNotificationAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~PushNotificationAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype PushNotificationAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype PushNotificationAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype PushNotificationAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype PushNotificationAnswer
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype PushNotificationAnswer
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype PushNotificationAnswer
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		VendorSpecificApplicationId* getVendorSpecificApplicationId();

		VendorSpecificApplicationId* setVendorSpecificApplicationId();

		void resetVendorSpecificApplicationId();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype PushNotificationAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype PushNotificationAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype PushNotificationAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		ExperimentalResult* getExperimentalResult();

		ExperimentalResult* setExperimentalResult();

		void resetExperimentalResult();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype PushNotificationAnswer
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype PushNotificationAnswer
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype PushNotificationAnswer
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype PushNotificationAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype PushNotificationAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype PushNotificationAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype PushNotificationAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype PushNotificationAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype PushNotificationAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		list<SupportedFeatures*>* getSupportedFeaturesGrpList();

		list<SupportedFeatures*>* setSupportedFeaturesGrpList();

		void resetSupportedFeaturesGrpList();

		FailedAVP* getFailedAVP();

		FailedAVP* setFailedAVP();

		void resetFailedAVP();

		list<SH::ProxyInfo*>* getProxyInfoGrpList();

		list<SH::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		//! Function to Decode
		/*!		Function to Decode datatype PushNotificationAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype PushNotificationAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype PushNotificationAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype PushNotificationAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype PushNotificationAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
