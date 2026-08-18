#ifndef SH_USERDATAANSWER_H
#define SH_USERDATAANSWER_H
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
typedef enum _tags_UserDataAnswer
{
	UserDataAnswer_SESSIONID	= 0,
	UserDataAnswer_DRMP	= 1,
	UserDataAnswer_VENDORSPECIFICAPPLICATIONID	= 2,
	UserDataAnswer_RESULTCODE	= 3,
	UserDataAnswer_EXPERIMENTALRESULT	= 4,
	UserDataAnswer_AUTHSESSIONSTATE	= 5,
	UserDataAnswer_ORIGINHOST	= 6,
	UserDataAnswer_ORIGINREALM	= 7,
	UserDataAnswer_SUPPORTEDFEATURES	= 8,
	UserDataAnswer_WILDCARDEDPUBLICIDENTITY	= 9,
	UserDataAnswer_WILDCARDEDIMPU	= 10,
	UserDataAnswer_USERDATA	= 11,
	UserDataAnswer_OCSUPPORTEDFEATURES	= 12,
	UserDataAnswer_OCOLR	= 13,
	UserDataAnswer_LOAD	= 14,
	UserDataAnswer_FAILEDAVP	= 15,
	UserDataAnswer_PROXYINFO	= 16,
	UserDataAnswer_ROUTERECORD	= 17,
}UserDataAnswer_tags;

		//! Class Definition
		/*!		ClassName is UserDataAnswer
		*/
class UserDataAnswer : public DiameterBase 
{
	private:

		bitset<18> mTagsPresent;

		bitset<18> mMandatoryAvpCheckVal;

		bitset<18> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		DRMP*		mDRMP;

		Unsigned32*		mResultCode;

		AuthSessionState*		mAuthSessionState;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		OctetString*		mWildcardedPublicIdentity;

		OctetString*		mWildcardedIMPU;

		OctetString*		mUserData;

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
		UserDataAnswer();

		UserDataAnswer(const UserDataAnswer &objUserDataAnswer) {

		mTagsPresent = objUserDataAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objUserDataAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUserDataAnswer.mMandatoryAvpSetVal;

		mTag = objUserDataAnswer.mTag;

		mDecodeFlag = objUserDataAnswer.mDecodeFlag;

		if(objUserDataAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objUserDataAnswer.mSessionId));

		if(objUserDataAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objUserDataAnswer.mDRMP));

		if(objUserDataAnswer.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objUserDataAnswer.mVendorSpecificApplicationIdGrp);
		 }
		if(objUserDataAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objUserDataAnswer.mResultCode));

		if(objUserDataAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objUserDataAnswer.mExperimentalResultGrp);
		 }
		if(objUserDataAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objUserDataAnswer.mAuthSessionState));

		if(objUserDataAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objUserDataAnswer.mOriginHost));

		if(objUserDataAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objUserDataAnswer.mOriginRealm));

		if(objUserDataAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objUserDataAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objUserDataAnswer.mWildcardedPublicIdentity != NULL)
		mWildcardedPublicIdentity = new OctetString(*(objUserDataAnswer.mWildcardedPublicIdentity));

		if(objUserDataAnswer.mWildcardedIMPU != NULL)
		mWildcardedIMPU = new OctetString(*(objUserDataAnswer.mWildcardedIMPU));

		if(objUserDataAnswer.mUserData != NULL)
		mUserData = new OctetString(*(objUserDataAnswer.mUserData));

		if(objUserDataAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objUserDataAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objUserDataAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objUserDataAnswer.mOCOLRGrp);
		 }
		if(objUserDataAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objUserDataAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		if(objUserDataAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objUserDataAnswer.mFailedAVPGrp);
		 }
		if(objUserDataAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SH::ProxyInfo*>;
		 for( auto element : *objUserDataAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const UserDataAnswer &objUserDataAnswer) {

		mTagsPresent = objUserDataAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objUserDataAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUserDataAnswer.mMandatoryAvpSetVal;

		mTag = objUserDataAnswer.mTag;

		mDecodeFlag = objUserDataAnswer.mDecodeFlag;

		if(objUserDataAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objUserDataAnswer.mSessionId));

		if(objUserDataAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objUserDataAnswer.mDRMP));

		if(objUserDataAnswer.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objUserDataAnswer.mVendorSpecificApplicationIdGrp);
		 }
		if(objUserDataAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objUserDataAnswer.mResultCode));

		if(objUserDataAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objUserDataAnswer.mExperimentalResultGrp);
		 }
		if(objUserDataAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objUserDataAnswer.mAuthSessionState));

		if(objUserDataAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objUserDataAnswer.mOriginHost));

		if(objUserDataAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objUserDataAnswer.mOriginRealm));

		if(objUserDataAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objUserDataAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objUserDataAnswer.mWildcardedPublicIdentity != NULL)
		mWildcardedPublicIdentity = new OctetString(*(objUserDataAnswer.mWildcardedPublicIdentity));

		if(objUserDataAnswer.mWildcardedIMPU != NULL)
		mWildcardedIMPU = new OctetString(*(objUserDataAnswer.mWildcardedIMPU));

		if(objUserDataAnswer.mUserData != NULL)
		mUserData = new OctetString(*(objUserDataAnswer.mUserData));

		if(objUserDataAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objUserDataAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objUserDataAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objUserDataAnswer.mOCOLRGrp);
		 }
		if(objUserDataAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objUserDataAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		if(objUserDataAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objUserDataAnswer.mFailedAVPGrp);
		 }
		if(objUserDataAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SH::ProxyInfo*>;
		 for( auto element : *objUserDataAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~UserDataAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype UserDataAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype UserDataAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype UserDataAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype UserDataAnswer
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype UserDataAnswer
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype UserDataAnswer
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		VendorSpecificApplicationId* getVendorSpecificApplicationId();

		VendorSpecificApplicationId* setVendorSpecificApplicationId();

		void resetVendorSpecificApplicationId();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype UserDataAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype UserDataAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype UserDataAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		ExperimentalResult* getExperimentalResult();

		ExperimentalResult* setExperimentalResult();

		void resetExperimentalResult();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype UserDataAnswer
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype UserDataAnswer
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype UserDataAnswer
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype UserDataAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype UserDataAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype UserDataAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype UserDataAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype UserDataAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype UserDataAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		list<SupportedFeatures*>* getSupportedFeaturesGrpList();

		list<SupportedFeatures*>* setSupportedFeaturesGrpList();

		void resetSupportedFeaturesGrpList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument WildcardedPublicIdentity for datatype UserDataAnswer
		*/
		OctetString* setWildcardedPublicIdentity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument WildcardedPublicIdentity for datatype UserDataAnswer
		*/
		void resetWildcardedPublicIdentity();

		//!Function to get values
		/*!		Function to get OctetString type of argument WildcardedPublicIdentity for datatype UserDataAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getWildcardedPublicIdentity();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument WildcardedIMPU for datatype UserDataAnswer
		*/
		OctetString* setWildcardedIMPU();

		//! Function to reset 
		/*!		Function to reset NULL type of argument WildcardedIMPU for datatype UserDataAnswer
		*/
		void resetWildcardedIMPU();

		//!Function to get values
		/*!		Function to get OctetString type of argument WildcardedIMPU for datatype UserDataAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getWildcardedIMPU();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserData for datatype UserDataAnswer
		*/
		OctetString* setUserData();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserData for datatype UserDataAnswer
		*/
		void resetUserData();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserData for datatype UserDataAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserData();

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
		/*!		Function to Decode datatype UserDataAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype UserDataAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype UserDataAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype UserDataAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype UserDataAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
