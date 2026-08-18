#ifndef CX_USERAUTHORIZATIONANSWER_H
#define CX_USERAUTHORIZATIONANSWER_H
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
typedef enum _tags_UserAuthorizationAnswer
{
	UserAuthorizationAnswer_SESSIONID	= 0,
	UserAuthorizationAnswer_DRMP	= 1,
	UserAuthorizationAnswer_VENDORSPECIFICAPPLICATIONID	= 2,
	UserAuthorizationAnswer_RESULTCODE	= 3,
	UserAuthorizationAnswer_EXPERIMENTALRESULT	= 4,
	UserAuthorizationAnswer_AUTHSESSIONSTATE	= 5,
	UserAuthorizationAnswer_ORIGINHOST	= 6,
	UserAuthorizationAnswer_ORIGINREALM	= 7,
	UserAuthorizationAnswer_OCSUPPORTEDFEATURES	= 8,
	UserAuthorizationAnswer_OCOLR	= 9,
	UserAuthorizationAnswer_LOAD	= 10,
	UserAuthorizationAnswer_SUPPORTEDFEATURES	= 11,
	UserAuthorizationAnswer_SERVERNAME	= 12,
	UserAuthorizationAnswer_SERVERCAPABILITIES	= 13,
	UserAuthorizationAnswer_ERRORMESSAGE	= 14,
	UserAuthorizationAnswer_FAILEDAVP	= 15,
	UserAuthorizationAnswer_PROXYINFO	= 16,
	UserAuthorizationAnswer_ROUTERECORD	= 17,
}UserAuthorizationAnswer_tags;

		//! Class Definition
		/*!		ClassName is UserAuthorizationAnswer
		*/
class UserAuthorizationAnswer : public DiameterBase 
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

		OctetString*		mServerName;

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
		UserAuthorizationAnswer();

		UserAuthorizationAnswer(const UserAuthorizationAnswer &objUserAuthorizationAnswer) {

		mTagsPresent = objUserAuthorizationAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objUserAuthorizationAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUserAuthorizationAnswer.mMandatoryAvpSetVal;

		mTag = objUserAuthorizationAnswer.mTag;

		mDecodeFlag = objUserAuthorizationAnswer.mDecodeFlag;

		if(objUserAuthorizationAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objUserAuthorizationAnswer.mSessionId));

		if(objUserAuthorizationAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objUserAuthorizationAnswer.mDRMP));

		if(objUserAuthorizationAnswer.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objUserAuthorizationAnswer.mVendorSpecificApplicationIdGrp);
		 }
		if(objUserAuthorizationAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objUserAuthorizationAnswer.mResultCode));

		if(objUserAuthorizationAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objUserAuthorizationAnswer.mExperimentalResultGrp);
		 }
		if(objUserAuthorizationAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objUserAuthorizationAnswer.mAuthSessionState));

		if(objUserAuthorizationAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objUserAuthorizationAnswer.mOriginHost));

		if(objUserAuthorizationAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objUserAuthorizationAnswer.mOriginRealm));

		if(objUserAuthorizationAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objUserAuthorizationAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objUserAuthorizationAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objUserAuthorizationAnswer.mOCOLRGrp);
		 }
		if(objUserAuthorizationAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objUserAuthorizationAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		if(objUserAuthorizationAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objUserAuthorizationAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objUserAuthorizationAnswer.mServerName != NULL)
		mServerName = new OctetString(*(objUserAuthorizationAnswer.mServerName));

		if(objUserAuthorizationAnswer.mServerCapabilitiesGrp != NULL)
		 {
				 mServerCapabilitiesGrp =  new ServerCapabilities(*objUserAuthorizationAnswer.mServerCapabilitiesGrp);
		 }
		if(objUserAuthorizationAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objUserAuthorizationAnswer.mErrorMessage));

		if(objUserAuthorizationAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objUserAuthorizationAnswer.mFailedAVPGrp);
		 }
		if(objUserAuthorizationAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objUserAuthorizationAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const UserAuthorizationAnswer &objUserAuthorizationAnswer) {

		mTagsPresent = objUserAuthorizationAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objUserAuthorizationAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUserAuthorizationAnswer.mMandatoryAvpSetVal;

		mTag = objUserAuthorizationAnswer.mTag;

		mDecodeFlag = objUserAuthorizationAnswer.mDecodeFlag;

		if(objUserAuthorizationAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objUserAuthorizationAnswer.mSessionId));

		if(objUserAuthorizationAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objUserAuthorizationAnswer.mDRMP));

		if(objUserAuthorizationAnswer.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objUserAuthorizationAnswer.mVendorSpecificApplicationIdGrp);
		 }
		if(objUserAuthorizationAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objUserAuthorizationAnswer.mResultCode));

		if(objUserAuthorizationAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objUserAuthorizationAnswer.mExperimentalResultGrp);
		 }
		if(objUserAuthorizationAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objUserAuthorizationAnswer.mAuthSessionState));

		if(objUserAuthorizationAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objUserAuthorizationAnswer.mOriginHost));

		if(objUserAuthorizationAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objUserAuthorizationAnswer.mOriginRealm));

		if(objUserAuthorizationAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objUserAuthorizationAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objUserAuthorizationAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objUserAuthorizationAnswer.mOCOLRGrp);
		 }
		if(objUserAuthorizationAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objUserAuthorizationAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		if(objUserAuthorizationAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objUserAuthorizationAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objUserAuthorizationAnswer.mServerName != NULL)
		mServerName = new OctetString(*(objUserAuthorizationAnswer.mServerName));

		if(objUserAuthorizationAnswer.mServerCapabilitiesGrp != NULL)
		 {
				 mServerCapabilitiesGrp =  new ServerCapabilities(*objUserAuthorizationAnswer.mServerCapabilitiesGrp);
		 }
		if(objUserAuthorizationAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objUserAuthorizationAnswer.mErrorMessage));

		if(objUserAuthorizationAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objUserAuthorizationAnswer.mFailedAVPGrp);
		 }
		if(objUserAuthorizationAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objUserAuthorizationAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~UserAuthorizationAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype UserAuthorizationAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype UserAuthorizationAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype UserAuthorizationAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype UserAuthorizationAnswer
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype UserAuthorizationAnswer
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype UserAuthorizationAnswer
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		VendorSpecificApplicationId* getVendorSpecificApplicationId();

		VendorSpecificApplicationId* setVendorSpecificApplicationId();

		void resetVendorSpecificApplicationId();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype UserAuthorizationAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype UserAuthorizationAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype UserAuthorizationAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		ExperimentalResult* getExperimentalResult();

		ExperimentalResult* setExperimentalResult();

		void resetExperimentalResult();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype UserAuthorizationAnswer
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype UserAuthorizationAnswer
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype UserAuthorizationAnswer
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype UserAuthorizationAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype UserAuthorizationAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype UserAuthorizationAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype UserAuthorizationAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype UserAuthorizationAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype UserAuthorizationAnswer
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
		/*!		Function to set the recent OctetString type of argument ServerName for datatype UserAuthorizationAnswer
		*/
		OctetString* setServerName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ServerName for datatype UserAuthorizationAnswer
		*/
		void resetServerName();

		//!Function to get values
		/*!		Function to get OctetString type of argument ServerName for datatype UserAuthorizationAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getServerName();

		ServerCapabilities* getServerCapabilities();

		ServerCapabilities* setServerCapabilities();

		void resetServerCapabilities();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorMessage for datatype UserAuthorizationAnswer
		*/
		OctetString* setErrorMessage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorMessage for datatype UserAuthorizationAnswer
		*/
		void resetErrorMessage();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorMessage for datatype UserAuthorizationAnswer
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
		/*!		Function to Decode datatype UserAuthorizationAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype UserAuthorizationAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype UserAuthorizationAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype UserAuthorizationAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype UserAuthorizationAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
