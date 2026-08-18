#ifndef SH_PROFILEUPDATEANSWER_H
#define SH_PROFILEUPDATEANSWER_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sh/include/DRMP.h"
#include "sh/include/VendorSpecificApplicationId.h"
#include "sh/include/ExperimentalResult.h"
#include "sh/include/AuthSessionState.h"
#include "sh/include/RepositoryDataID.h"
#include "sh/include/DataReference.h"
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
typedef enum _tags_ProfileUpdateAnswer
{
	ProfileUpdateAnswer_SESSIONID	= 0,
	ProfileUpdateAnswer_DRMP	= 1,
	ProfileUpdateAnswer_VENDORSPECIFICAPPLICATIONID	= 2,
	ProfileUpdateAnswer_RESULTCODE	= 3,
	ProfileUpdateAnswer_EXPERIMENTALRESULT	= 4,
	ProfileUpdateAnswer_AUTHSESSIONSTATE	= 5,
	ProfileUpdateAnswer_ORIGINHOST	= 6,
	ProfileUpdateAnswer_ORIGINREALM	= 7,
	ProfileUpdateAnswer_WILDCARDEDPUBLICIDENTITY	= 8,
	ProfileUpdateAnswer_WILDCARDEDIMPU	= 9,
	ProfileUpdateAnswer_REPOSITORYDATAID	= 10,
	ProfileUpdateAnswer_DATAREFERENCE	= 11,
	ProfileUpdateAnswer_SUPPORTEDFEATURES	= 12,
	ProfileUpdateAnswer_OCSUPPORTEDFEATURES	= 13,
	ProfileUpdateAnswer_OCOLR	= 14,
	ProfileUpdateAnswer_LOAD	= 15,
	ProfileUpdateAnswer_FAILEDAVP	= 16,
	ProfileUpdateAnswer_PROXYINFO	= 17,
	ProfileUpdateAnswer_ROUTERECORD	= 18,
}ProfileUpdateAnswer_tags;

		//! Class Definition
		/*!		ClassName is ProfileUpdateAnswer
		*/
class ProfileUpdateAnswer : public DiameterBase 
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

		Unsigned32*		mResultCode;

		AuthSessionState*		mAuthSessionState;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		OctetString*		mWildcardedPublicIdentity;

		OctetString*		mWildcardedIMPU;

		DataReference*		mDataReference;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;




		VendorSpecificApplicationId*	mVendorSpecificApplicationIdGrp;


		ExperimentalResult*	mExperimentalResultGrp;






		RepositoryDataID*	mRepositoryDataIDGrp;


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
		ProfileUpdateAnswer();

		ProfileUpdateAnswer(const ProfileUpdateAnswer &objProfileUpdateAnswer) {

		mTagsPresent = objProfileUpdateAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objProfileUpdateAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objProfileUpdateAnswer.mMandatoryAvpSetVal;

		mTag = objProfileUpdateAnswer.mTag;

		mDecodeFlag = objProfileUpdateAnswer.mDecodeFlag;

		if(objProfileUpdateAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objProfileUpdateAnswer.mSessionId));

		if(objProfileUpdateAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objProfileUpdateAnswer.mDRMP));

		if(objProfileUpdateAnswer.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objProfileUpdateAnswer.mVendorSpecificApplicationIdGrp);
		 }
		if(objProfileUpdateAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objProfileUpdateAnswer.mResultCode));

		if(objProfileUpdateAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objProfileUpdateAnswer.mExperimentalResultGrp);
		 }
		if(objProfileUpdateAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objProfileUpdateAnswer.mAuthSessionState));

		if(objProfileUpdateAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objProfileUpdateAnswer.mOriginHost));

		if(objProfileUpdateAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objProfileUpdateAnswer.mOriginRealm));

		if(objProfileUpdateAnswer.mWildcardedPublicIdentity != NULL)
		mWildcardedPublicIdentity = new OctetString(*(objProfileUpdateAnswer.mWildcardedPublicIdentity));

		if(objProfileUpdateAnswer.mWildcardedIMPU != NULL)
		mWildcardedIMPU = new OctetString(*(objProfileUpdateAnswer.mWildcardedIMPU));

		if(objProfileUpdateAnswer.mRepositoryDataIDGrp != NULL)
		 {
				 mRepositoryDataIDGrp =  new RepositoryDataID(*objProfileUpdateAnswer.mRepositoryDataIDGrp);
		 }
		if(objProfileUpdateAnswer.mDataReference != NULL)
		mDataReference = new DataReference(*(objProfileUpdateAnswer.mDataReference));

		if(objProfileUpdateAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objProfileUpdateAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objProfileUpdateAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objProfileUpdateAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objProfileUpdateAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objProfileUpdateAnswer.mOCOLRGrp);
		 }
		if(objProfileUpdateAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objProfileUpdateAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		if(objProfileUpdateAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objProfileUpdateAnswer.mFailedAVPGrp);
		 }
		if(objProfileUpdateAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SH::ProxyInfo*>;
		 for( auto element : *objProfileUpdateAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const ProfileUpdateAnswer &objProfileUpdateAnswer) {

		mTagsPresent = objProfileUpdateAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objProfileUpdateAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objProfileUpdateAnswer.mMandatoryAvpSetVal;

		mTag = objProfileUpdateAnswer.mTag;

		mDecodeFlag = objProfileUpdateAnswer.mDecodeFlag;

		if(objProfileUpdateAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objProfileUpdateAnswer.mSessionId));

		if(objProfileUpdateAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objProfileUpdateAnswer.mDRMP));

		if(objProfileUpdateAnswer.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objProfileUpdateAnswer.mVendorSpecificApplicationIdGrp);
		 }
		if(objProfileUpdateAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objProfileUpdateAnswer.mResultCode));

		if(objProfileUpdateAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objProfileUpdateAnswer.mExperimentalResultGrp);
		 }
		if(objProfileUpdateAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objProfileUpdateAnswer.mAuthSessionState));

		if(objProfileUpdateAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objProfileUpdateAnswer.mOriginHost));

		if(objProfileUpdateAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objProfileUpdateAnswer.mOriginRealm));

		if(objProfileUpdateAnswer.mWildcardedPublicIdentity != NULL)
		mWildcardedPublicIdentity = new OctetString(*(objProfileUpdateAnswer.mWildcardedPublicIdentity));

		if(objProfileUpdateAnswer.mWildcardedIMPU != NULL)
		mWildcardedIMPU = new OctetString(*(objProfileUpdateAnswer.mWildcardedIMPU));

		if(objProfileUpdateAnswer.mRepositoryDataIDGrp != NULL)
		 {
				 mRepositoryDataIDGrp =  new RepositoryDataID(*objProfileUpdateAnswer.mRepositoryDataIDGrp);
		 }
		if(objProfileUpdateAnswer.mDataReference != NULL)
		mDataReference = new DataReference(*(objProfileUpdateAnswer.mDataReference));

		if(objProfileUpdateAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objProfileUpdateAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objProfileUpdateAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objProfileUpdateAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objProfileUpdateAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objProfileUpdateAnswer.mOCOLRGrp);
		 }
		if(objProfileUpdateAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objProfileUpdateAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		if(objProfileUpdateAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objProfileUpdateAnswer.mFailedAVPGrp);
		 }
		if(objProfileUpdateAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SH::ProxyInfo*>;
		 for( auto element : *objProfileUpdateAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~ProfileUpdateAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype ProfileUpdateAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype ProfileUpdateAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype ProfileUpdateAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype ProfileUpdateAnswer
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype ProfileUpdateAnswer
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype ProfileUpdateAnswer
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		VendorSpecificApplicationId* getVendorSpecificApplicationId();

		VendorSpecificApplicationId* setVendorSpecificApplicationId();

		void resetVendorSpecificApplicationId();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype ProfileUpdateAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype ProfileUpdateAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype ProfileUpdateAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		ExperimentalResult* getExperimentalResult();

		ExperimentalResult* setExperimentalResult();

		void resetExperimentalResult();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype ProfileUpdateAnswer
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype ProfileUpdateAnswer
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype ProfileUpdateAnswer
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype ProfileUpdateAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype ProfileUpdateAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype ProfileUpdateAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype ProfileUpdateAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype ProfileUpdateAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype ProfileUpdateAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument WildcardedPublicIdentity for datatype ProfileUpdateAnswer
		*/
		OctetString* setWildcardedPublicIdentity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument WildcardedPublicIdentity for datatype ProfileUpdateAnswer
		*/
		void resetWildcardedPublicIdentity();

		//!Function to get values
		/*!		Function to get OctetString type of argument WildcardedPublicIdentity for datatype ProfileUpdateAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getWildcardedPublicIdentity();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument WildcardedIMPU for datatype ProfileUpdateAnswer
		*/
		OctetString* setWildcardedIMPU();

		//! Function to reset 
		/*!		Function to reset NULL type of argument WildcardedIMPU for datatype ProfileUpdateAnswer
		*/
		void resetWildcardedIMPU();

		//!Function to get values
		/*!		Function to get OctetString type of argument WildcardedIMPU for datatype ProfileUpdateAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getWildcardedIMPU();

		RepositoryDataID* getRepositoryDataID();

		RepositoryDataID* setRepositoryDataID();

		void resetRepositoryDataID();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DataReference for datatype ProfileUpdateAnswer
		*/
		DataReference* setDataReference();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DataReference for datatype ProfileUpdateAnswer
		*/
		void resetDataReference();

		//!Function to get values
		/*!		Function to get DataReference type of argument DataReference for datatype ProfileUpdateAnswer
		Throws exception of which type and Summary of Exception
		*/
		DataReference* getDataReference();

		list<SupportedFeatures*>* getSupportedFeaturesGrpList();

		list<SupportedFeatures*>* setSupportedFeaturesGrpList();

		void resetSupportedFeaturesGrpList();

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
		/*!		Function to Decode datatype ProfileUpdateAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype ProfileUpdateAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype ProfileUpdateAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype ProfileUpdateAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ProfileUpdateAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
