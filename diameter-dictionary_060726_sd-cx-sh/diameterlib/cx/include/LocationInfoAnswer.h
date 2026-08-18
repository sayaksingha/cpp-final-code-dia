#ifndef CX_LOCATIONINFOANSWER_H
#define CX_LOCATIONINFOANSWER_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "cx/include/DRMP.h"
#include "cx/include/VendorSpecificApplicationId.h"
#include "cx/include/ExperimentalResult.h"
#include "cx/include/AuthSessionState.h"
#include "cx/include/OCSupportedFeatures.h"
#include "cx/include/OCOLR.h"
#include "cx/include/Load.h"
#include "cx/include/SupportedFeatures.h"
#include "cx/include/ServerCapabilities.h"
#include "cx/include/FailedAVP.h"
#include "cx/include/ProxyInfo.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace CX{
typedef enum _tags_LocationInfoAnswer
{
	LocationInfoAnswer_SESSIONID	= 0,
	LocationInfoAnswer_DRMP	= 1,
	LocationInfoAnswer_VENDORSPECIFICAPPLICATIONID	= 2,
	LocationInfoAnswer_RESULTCODE	= 3,
	LocationInfoAnswer_EXPERIMENTALRESULT	= 4,
	LocationInfoAnswer_AUTHSESSIONSTATE	= 5,
	LocationInfoAnswer_ORIGINHOST	= 6,
	LocationInfoAnswer_ORIGINREALM	= 7,
	LocationInfoAnswer_OCSUPPORTEDFEATURES	= 8,
	LocationInfoAnswer_OCOLR	= 9,
	LocationInfoAnswer_LOAD	= 10,
	LocationInfoAnswer_SUPPORTEDFEATURES	= 11,
	LocationInfoAnswer_SERVERNAME	= 12,
	LocationInfoAnswer_SERVERCAPABILITIES	= 13,
	LocationInfoAnswer_WILDCARDEDPUBLICIDENTITY	= 14,
	LocationInfoAnswer_LIAFLAGS	= 15,
	LocationInfoAnswer_ERRORMESSAGE	= 16,
	LocationInfoAnswer_FAILEDAVP	= 17,
	LocationInfoAnswer_PROXYINFO	= 18,
	LocationInfoAnswer_ROUTERECORD	= 19,
}LocationInfoAnswer_tags;

		//! Class Definition
		/*!		ClassName is LocationInfoAnswer
		*/
class LocationInfoAnswer : public DiameterBase 
{
	private:

		bitset<20> mTagsPresent;

		bitset<20> mMandatoryAvpCheckVal;

		bitset<20> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		DRMP*		mDRMP;

		Unsigned32*		mResultCode;

		AuthSessionState*		mAuthSessionState;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		OctetString*		mServerName;

		OctetString*		mWildcardedPublicIdentity;

		Unsigned32*		mLIAFlags;

		OctetString*		mErrorMessage;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;




		VendorSpecificApplicationId*	mVendorSpecificApplicationIdGrp;


		ExperimentalResult*	mExperimentalResultGrp;




		OCSupportedFeatures*	mOCSupportedFeaturesGrp;

		OCOLR*	mOCOLRGrp;

		list<Load*>*	mLoadGrpList;
		list<Load*>::iterator	mLoadGrpIterator;

		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;


		ServerCapabilities*	mServerCapabilitiesGrp;




		FailedAVP*	mFailedAVPGrp;

		list<CX::ProxyInfo*>*	mProxyInfoGrpList;
		list<CX::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		LocationInfoAnswer();

		LocationInfoAnswer(const LocationInfoAnswer &objLocationInfoAnswer) {

		mTagsPresent = objLocationInfoAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objLocationInfoAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objLocationInfoAnswer.mMandatoryAvpSetVal;

		mTag = objLocationInfoAnswer.mTag;

		mDecodeFlag = objLocationInfoAnswer.mDecodeFlag;

		if(objLocationInfoAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objLocationInfoAnswer.mSessionId));

		if(objLocationInfoAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objLocationInfoAnswer.mDRMP));

		if(objLocationInfoAnswer.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objLocationInfoAnswer.mVendorSpecificApplicationIdGrp);
		 }
		if(objLocationInfoAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objLocationInfoAnswer.mResultCode));

		if(objLocationInfoAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objLocationInfoAnswer.mExperimentalResultGrp);
		 }
		if(objLocationInfoAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objLocationInfoAnswer.mAuthSessionState));

		if(objLocationInfoAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objLocationInfoAnswer.mOriginHost));

		if(objLocationInfoAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objLocationInfoAnswer.mOriginRealm));

		if(objLocationInfoAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objLocationInfoAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objLocationInfoAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objLocationInfoAnswer.mOCOLRGrp);
		 }
		if(objLocationInfoAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objLocationInfoAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		if(objLocationInfoAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objLocationInfoAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objLocationInfoAnswer.mServerName != NULL)
		mServerName = new OctetString(*(objLocationInfoAnswer.mServerName));

		if(objLocationInfoAnswer.mServerCapabilitiesGrp != NULL)
		 {
				 mServerCapabilitiesGrp =  new ServerCapabilities(*objLocationInfoAnswer.mServerCapabilitiesGrp);
		 }
		if(objLocationInfoAnswer.mWildcardedPublicIdentity != NULL)
		mWildcardedPublicIdentity = new OctetString(*(objLocationInfoAnswer.mWildcardedPublicIdentity));

		if(objLocationInfoAnswer.mLIAFlags != NULL)
		mLIAFlags = new Unsigned32(*(objLocationInfoAnswer.mLIAFlags));

		if(objLocationInfoAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objLocationInfoAnswer.mErrorMessage));

		if(objLocationInfoAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objLocationInfoAnswer.mFailedAVPGrp);
		 }
		if(objLocationInfoAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objLocationInfoAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const LocationInfoAnswer &objLocationInfoAnswer) {

		mTagsPresent = objLocationInfoAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objLocationInfoAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objLocationInfoAnswer.mMandatoryAvpSetVal;

		mTag = objLocationInfoAnswer.mTag;

		mDecodeFlag = objLocationInfoAnswer.mDecodeFlag;

		if(objLocationInfoAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objLocationInfoAnswer.mSessionId));

		if(objLocationInfoAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objLocationInfoAnswer.mDRMP));

		if(objLocationInfoAnswer.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objLocationInfoAnswer.mVendorSpecificApplicationIdGrp);
		 }
		if(objLocationInfoAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objLocationInfoAnswer.mResultCode));

		if(objLocationInfoAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objLocationInfoAnswer.mExperimentalResultGrp);
		 }
		if(objLocationInfoAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objLocationInfoAnswer.mAuthSessionState));

		if(objLocationInfoAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objLocationInfoAnswer.mOriginHost));

		if(objLocationInfoAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objLocationInfoAnswer.mOriginRealm));

		if(objLocationInfoAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objLocationInfoAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objLocationInfoAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objLocationInfoAnswer.mOCOLRGrp);
		 }
		if(objLocationInfoAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objLocationInfoAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		if(objLocationInfoAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objLocationInfoAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objLocationInfoAnswer.mServerName != NULL)
		mServerName = new OctetString(*(objLocationInfoAnswer.mServerName));

		if(objLocationInfoAnswer.mServerCapabilitiesGrp != NULL)
		 {
				 mServerCapabilitiesGrp =  new ServerCapabilities(*objLocationInfoAnswer.mServerCapabilitiesGrp);
		 }
		if(objLocationInfoAnswer.mWildcardedPublicIdentity != NULL)
		mWildcardedPublicIdentity = new OctetString(*(objLocationInfoAnswer.mWildcardedPublicIdentity));

		if(objLocationInfoAnswer.mLIAFlags != NULL)
		mLIAFlags = new Unsigned32(*(objLocationInfoAnswer.mLIAFlags));

		if(objLocationInfoAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objLocationInfoAnswer.mErrorMessage));

		if(objLocationInfoAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objLocationInfoAnswer.mFailedAVPGrp);
		 }
		if(objLocationInfoAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objLocationInfoAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~LocationInfoAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype LocationInfoAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype LocationInfoAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype LocationInfoAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype LocationInfoAnswer
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype LocationInfoAnswer
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype LocationInfoAnswer
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		VendorSpecificApplicationId* getVendorSpecificApplicationId();

		VendorSpecificApplicationId* setVendorSpecificApplicationId();

		void resetVendorSpecificApplicationId();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype LocationInfoAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype LocationInfoAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype LocationInfoAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		ExperimentalResult* getExperimentalResult();

		ExperimentalResult* setExperimentalResult();

		void resetExperimentalResult();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype LocationInfoAnswer
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype LocationInfoAnswer
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype LocationInfoAnswer
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype LocationInfoAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype LocationInfoAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype LocationInfoAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype LocationInfoAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype LocationInfoAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype LocationInfoAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		OCSupportedFeatures* getOCSupportedFeatures();

		OCSupportedFeatures* setOCSupportedFeatures();

		void resetOCSupportedFeatures();

		OCOLR* getOCOLR();

		OCOLR* setOCOLR();

		void resetOCOLR();

		list<Load*>* getLoadGrpList();

		list<Load*>* setLoadGrpList();

		void resetLoadGrpList();

		list<SupportedFeatures*>* getSupportedFeaturesGrpList();

		list<SupportedFeatures*>* setSupportedFeaturesGrpList();

		void resetSupportedFeaturesGrpList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ServerName for datatype LocationInfoAnswer
		*/
		OctetString* setServerName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ServerName for datatype LocationInfoAnswer
		*/
		void resetServerName();

		//!Function to get values
		/*!		Function to get OctetString type of argument ServerName for datatype LocationInfoAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getServerName();

		ServerCapabilities* getServerCapabilities();

		ServerCapabilities* setServerCapabilities();

		void resetServerCapabilities();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument WildcardedPublicIdentity for datatype LocationInfoAnswer
		*/
		OctetString* setWildcardedPublicIdentity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument WildcardedPublicIdentity for datatype LocationInfoAnswer
		*/
		void resetWildcardedPublicIdentity();

		//!Function to get values
		/*!		Function to get OctetString type of argument WildcardedPublicIdentity for datatype LocationInfoAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getWildcardedPublicIdentity();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument LIAFlags for datatype LocationInfoAnswer
		*/
		Unsigned32* setLIAFlags();

		//! Function to reset 
		/*!		Function to reset NULL type of argument LIAFlags for datatype LocationInfoAnswer
		*/
		void resetLIAFlags();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument LIAFlags for datatype LocationInfoAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getLIAFlags();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorMessage for datatype LocationInfoAnswer
		*/
		OctetString* setErrorMessage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorMessage for datatype LocationInfoAnswer
		*/
		void resetErrorMessage();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorMessage for datatype LocationInfoAnswer
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
		/*!		Function to Decode datatype LocationInfoAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype LocationInfoAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype LocationInfoAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype LocationInfoAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype LocationInfoAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
