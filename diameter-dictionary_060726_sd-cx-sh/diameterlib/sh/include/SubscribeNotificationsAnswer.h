#ifndef SH_SUBSCRIBENOTIFICATIONSANSWER_H
#define SH_SUBSCRIBENOTIFICATIONSANSWER_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sh/include/DRMP.h"
#include "sh/include/VendorSpecificApplicationId.h"
#include "sh/include/AuthSessionState.h"
#include "sh/include/ExperimentalResult.h"
#include "sh/include/SupportedFeatures.h"
#include "sh/include/OCSupportedFeatures.h"
#include "sh/include/OCOLR.h"
#include "sh/include/Load.h"
#include "sh/include/FailedAVP.h"
#include "sh/include/ProxyInfo.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace SH{
typedef enum _tags_SubscribeNotificationsAnswer
{
	SubscribeNotificationsAnswer_SESSIONID	= 0,
	SubscribeNotificationsAnswer_DRMP	= 1,
	SubscribeNotificationsAnswer_VENDORSPECIFICAPPLICATIONID	= 2,
	SubscribeNotificationsAnswer_AUTHSESSIONSTATE	= 3,
	SubscribeNotificationsAnswer_RESULTCODE	= 4,
	SubscribeNotificationsAnswer_EXPERIMENTALRESULT	= 5,
	SubscribeNotificationsAnswer_ORIGINHOST	= 6,
	SubscribeNotificationsAnswer_ORIGINREALM	= 7,
	SubscribeNotificationsAnswer_WILDCARDEDPUBLICIDENTITY	= 8,
	SubscribeNotificationsAnswer_WILDCARDEDIMPU	= 9,
	SubscribeNotificationsAnswer_SUPPORTEDFEATURES	= 10,
	SubscribeNotificationsAnswer_USERDATA	= 11,
	SubscribeNotificationsAnswer_EXPIRYTIME	= 12,
	SubscribeNotificationsAnswer_OCSUPPORTEDFEATURES	= 13,
	SubscribeNotificationsAnswer_OCOLR	= 14,
	SubscribeNotificationsAnswer_LOAD	= 15,
	SubscribeNotificationsAnswer_FAILEDAVP	= 16,
	SubscribeNotificationsAnswer_PROXYINFO	= 17,
	SubscribeNotificationsAnswer_ROUTERECORD	= 18,
}SubscribeNotificationsAnswer_tags;

		//! Class Definition
		/*!		ClassName is SubscribeNotificationsAnswer
		*/
class SubscribeNotificationsAnswer : public DiameterBase 
{
	private:

		bitset<19> mTagsPresent;

		bitset<19> mMandatoryAvpCheckVal;

		bitset<19> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		DRMP*		mDRMP;

		AuthSessionState*		mAuthSessionState;

		Unsigned32*		mResultCode;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		OctetString*		mWildcardedPublicIdentity;

		OctetString*		mWildcardedIMPU;

		OctetString*		mUserData;

		Time*		mExpiryTime;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;




		VendorSpecificApplicationId*	mVendorSpecificApplicationIdGrp;



		ExperimentalResult*	mExperimentalResultGrp;





		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;



		OCSupportedFeatures*	mOCSupportedFeaturesGrp;

		OCOLR*	mOCOLRGrp;

		list<Load*>*	mLoadGrpList;
		list<Load*>::iterator	mLoadGrpIterator;

		FailedAVP*	mFailedAVPGrp;

		list<SH::ProxyInfo*>*	mProxyInfoGrpList;
		list<SH::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		SubscribeNotificationsAnswer();

		SubscribeNotificationsAnswer(const SubscribeNotificationsAnswer &objSubscribeNotificationsAnswer) {

		mTagsPresent = objSubscribeNotificationsAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objSubscribeNotificationsAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSubscribeNotificationsAnswer.mMandatoryAvpSetVal;

		mTag = objSubscribeNotificationsAnswer.mTag;

		mDecodeFlag = objSubscribeNotificationsAnswer.mDecodeFlag;

		if(objSubscribeNotificationsAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objSubscribeNotificationsAnswer.mSessionId));

		if(objSubscribeNotificationsAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objSubscribeNotificationsAnswer.mDRMP));

		if(objSubscribeNotificationsAnswer.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objSubscribeNotificationsAnswer.mVendorSpecificApplicationIdGrp);
		 }
		if(objSubscribeNotificationsAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objSubscribeNotificationsAnswer.mAuthSessionState));

		if(objSubscribeNotificationsAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objSubscribeNotificationsAnswer.mResultCode));

		if(objSubscribeNotificationsAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objSubscribeNotificationsAnswer.mExperimentalResultGrp);
		 }
		if(objSubscribeNotificationsAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objSubscribeNotificationsAnswer.mOriginHost));

		if(objSubscribeNotificationsAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objSubscribeNotificationsAnswer.mOriginRealm));

		if(objSubscribeNotificationsAnswer.mWildcardedPublicIdentity != NULL)
		mWildcardedPublicIdentity = new OctetString(*(objSubscribeNotificationsAnswer.mWildcardedPublicIdentity));

		if(objSubscribeNotificationsAnswer.mWildcardedIMPU != NULL)
		mWildcardedIMPU = new OctetString(*(objSubscribeNotificationsAnswer.mWildcardedIMPU));

		if(objSubscribeNotificationsAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objSubscribeNotificationsAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objSubscribeNotificationsAnswer.mUserData != NULL)
		mUserData = new OctetString(*(objSubscribeNotificationsAnswer.mUserData));

		if(objSubscribeNotificationsAnswer.mExpiryTime != NULL)
		mExpiryTime = new Time(*(objSubscribeNotificationsAnswer.mExpiryTime));

		if(objSubscribeNotificationsAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objSubscribeNotificationsAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objSubscribeNotificationsAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objSubscribeNotificationsAnswer.mOCOLRGrp);
		 }
		if(objSubscribeNotificationsAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objSubscribeNotificationsAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		if(objSubscribeNotificationsAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objSubscribeNotificationsAnswer.mFailedAVPGrp);
		 }
		if(objSubscribeNotificationsAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SH::ProxyInfo*>;
		 for( auto element : *objSubscribeNotificationsAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const SubscribeNotificationsAnswer &objSubscribeNotificationsAnswer) {

		mTagsPresent = objSubscribeNotificationsAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objSubscribeNotificationsAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSubscribeNotificationsAnswer.mMandatoryAvpSetVal;

		mTag = objSubscribeNotificationsAnswer.mTag;

		mDecodeFlag = objSubscribeNotificationsAnswer.mDecodeFlag;

		if(objSubscribeNotificationsAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objSubscribeNotificationsAnswer.mSessionId));

		if(objSubscribeNotificationsAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objSubscribeNotificationsAnswer.mDRMP));

		if(objSubscribeNotificationsAnswer.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objSubscribeNotificationsAnswer.mVendorSpecificApplicationIdGrp);
		 }
		if(objSubscribeNotificationsAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objSubscribeNotificationsAnswer.mAuthSessionState));

		if(objSubscribeNotificationsAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objSubscribeNotificationsAnswer.mResultCode));

		if(objSubscribeNotificationsAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objSubscribeNotificationsAnswer.mExperimentalResultGrp);
		 }
		if(objSubscribeNotificationsAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objSubscribeNotificationsAnswer.mOriginHost));

		if(objSubscribeNotificationsAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objSubscribeNotificationsAnswer.mOriginRealm));

		if(objSubscribeNotificationsAnswer.mWildcardedPublicIdentity != NULL)
		mWildcardedPublicIdentity = new OctetString(*(objSubscribeNotificationsAnswer.mWildcardedPublicIdentity));

		if(objSubscribeNotificationsAnswer.mWildcardedIMPU != NULL)
		mWildcardedIMPU = new OctetString(*(objSubscribeNotificationsAnswer.mWildcardedIMPU));

		if(objSubscribeNotificationsAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objSubscribeNotificationsAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objSubscribeNotificationsAnswer.mUserData != NULL)
		mUserData = new OctetString(*(objSubscribeNotificationsAnswer.mUserData));

		if(objSubscribeNotificationsAnswer.mExpiryTime != NULL)
		mExpiryTime = new Time(*(objSubscribeNotificationsAnswer.mExpiryTime));

		if(objSubscribeNotificationsAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objSubscribeNotificationsAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objSubscribeNotificationsAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objSubscribeNotificationsAnswer.mOCOLRGrp);
		 }
		if(objSubscribeNotificationsAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objSubscribeNotificationsAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		if(objSubscribeNotificationsAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objSubscribeNotificationsAnswer.mFailedAVPGrp);
		 }
		if(objSubscribeNotificationsAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SH::ProxyInfo*>;
		 for( auto element : *objSubscribeNotificationsAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~SubscribeNotificationsAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype SubscribeNotificationsAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype SubscribeNotificationsAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype SubscribeNotificationsAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype SubscribeNotificationsAnswer
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype SubscribeNotificationsAnswer
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype SubscribeNotificationsAnswer
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		VendorSpecificApplicationId* getVendorSpecificApplicationId();

		VendorSpecificApplicationId* setVendorSpecificApplicationId();

		void resetVendorSpecificApplicationId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype SubscribeNotificationsAnswer
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype SubscribeNotificationsAnswer
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype SubscribeNotificationsAnswer
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype SubscribeNotificationsAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype SubscribeNotificationsAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype SubscribeNotificationsAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		ExperimentalResult* getExperimentalResult();

		ExperimentalResult* setExperimentalResult();

		void resetExperimentalResult();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype SubscribeNotificationsAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype SubscribeNotificationsAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype SubscribeNotificationsAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype SubscribeNotificationsAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype SubscribeNotificationsAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype SubscribeNotificationsAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument WildcardedPublicIdentity for datatype SubscribeNotificationsAnswer
		*/
		OctetString* setWildcardedPublicIdentity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument WildcardedPublicIdentity for datatype SubscribeNotificationsAnswer
		*/
		void resetWildcardedPublicIdentity();

		//!Function to get values
		/*!		Function to get OctetString type of argument WildcardedPublicIdentity for datatype SubscribeNotificationsAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getWildcardedPublicIdentity();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument WildcardedIMPU for datatype SubscribeNotificationsAnswer
		*/
		OctetString* setWildcardedIMPU();

		//! Function to reset 
		/*!		Function to reset NULL type of argument WildcardedIMPU for datatype SubscribeNotificationsAnswer
		*/
		void resetWildcardedIMPU();

		//!Function to get values
		/*!		Function to get OctetString type of argument WildcardedIMPU for datatype SubscribeNotificationsAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getWildcardedIMPU();

		list<SupportedFeatures*>* getSupportedFeaturesGrpList();

		list<SupportedFeatures*>* setSupportedFeaturesGrpList();

		void resetSupportedFeaturesGrpList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserData for datatype SubscribeNotificationsAnswer
		*/
		OctetString* setUserData();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserData for datatype SubscribeNotificationsAnswer
		*/
		void resetUserData();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserData for datatype SubscribeNotificationsAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserData();

		//!Function to set values
		/*!		Function to set the recent Time type of argument ExpiryTime for datatype SubscribeNotificationsAnswer
		*/
		Time* setExpiryTime();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ExpiryTime for datatype SubscribeNotificationsAnswer
		*/
		void resetExpiryTime();

		//!Function to get values
		/*!		Function to get Time type of argument ExpiryTime for datatype SubscribeNotificationsAnswer
		Throws exception of which type and Summary of Exception
		*/
		Time* getExpiryTime();

		OCSupportedFeatures* getOCSupportedFeatures();

		OCSupportedFeatures* setOCSupportedFeatures();

		void resetOCSupportedFeatures();

		OCOLR* getOCOLR();

		OCOLR* setOCOLR();

		void resetOCOLR();

		list<Load*>* getLoadGrpList();

		list<Load*>* setLoadGrpList();

		void resetLoadGrpList();

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
		/*!		Function to Decode datatype SubscribeNotificationsAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype SubscribeNotificationsAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype SubscribeNotificationsAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype SubscribeNotificationsAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype SubscribeNotificationsAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
