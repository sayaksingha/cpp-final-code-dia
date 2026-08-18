#ifndef CX_MULTIMEDIAAUTHANSWER_H
#define CX_MULTIMEDIAAUTHANSWER_H
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
#include "cx/include/SIPAuthDataItem.h"
#include "cx/include/FailedAVP.h"
#include "cx/include/ProxyInfo.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace CX{
typedef enum _tags_MultimediaAuthAnswer
{
	MultimediaAuthAnswer_SESSIONID	= 0,
	MultimediaAuthAnswer_DRMP	= 1,
	MultimediaAuthAnswer_VENDORSPECIFICAPPLICATIONID	= 2,
	MultimediaAuthAnswer_RESULTCODE	= 3,
	MultimediaAuthAnswer_EXPERIMENTALRESULT	= 4,
	MultimediaAuthAnswer_AUTHSESSIONSTATE	= 5,
	MultimediaAuthAnswer_ORIGINHOST	= 6,
	MultimediaAuthAnswer_ORIGINREALM	= 7,
	MultimediaAuthAnswer_USERNAME	= 8,
	MultimediaAuthAnswer_OCSUPPORTEDFEATURES	= 9,
	MultimediaAuthAnswer_OCOLR	= 10,
	MultimediaAuthAnswer_LOAD	= 11,
	MultimediaAuthAnswer_SUPPORTEDFEATURES	= 12,
	MultimediaAuthAnswer_PUBLICIDENTITY	= 13,
	MultimediaAuthAnswer_SIPNUMBERAUTHITEMS	= 14,
	MultimediaAuthAnswer_SIPAUTHDATAITEM	= 15,
	MultimediaAuthAnswer_ERRORMESSAGE	= 16,
	MultimediaAuthAnswer_FAILEDAVP	= 17,
	MultimediaAuthAnswer_PROXYINFO	= 18,
	MultimediaAuthAnswer_ROUTERECORD	= 19,
}MultimediaAuthAnswer_tags;

		//! Class Definition
		/*!		ClassName is MultimediaAuthAnswer
		*/
class MultimediaAuthAnswer : public DiameterBase 
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

		OctetString*		mUserName;

		OctetString*		mPublicIdentity;

		Unsigned32*		mSIPNumberAuthItems;

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



		list<SIPAuthDataItem*>*	mSIPAuthDataItemGrpList;
		list<SIPAuthDataItem*>::iterator	mSIPAuthDataItemGrpIterator;


		FailedAVP*	mFailedAVPGrp;

		list<CX::ProxyInfo*>*	mProxyInfoGrpList;
		list<CX::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		MultimediaAuthAnswer();

		MultimediaAuthAnswer(const MultimediaAuthAnswer &objMultimediaAuthAnswer) {

		mTagsPresent = objMultimediaAuthAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objMultimediaAuthAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objMultimediaAuthAnswer.mMandatoryAvpSetVal;

		mTag = objMultimediaAuthAnswer.mTag;

		mDecodeFlag = objMultimediaAuthAnswer.mDecodeFlag;

		if(objMultimediaAuthAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objMultimediaAuthAnswer.mSessionId));

		if(objMultimediaAuthAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objMultimediaAuthAnswer.mDRMP));

		if(objMultimediaAuthAnswer.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objMultimediaAuthAnswer.mVendorSpecificApplicationIdGrp);
		 }
		if(objMultimediaAuthAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objMultimediaAuthAnswer.mResultCode));

		if(objMultimediaAuthAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objMultimediaAuthAnswer.mExperimentalResultGrp);
		 }
		if(objMultimediaAuthAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objMultimediaAuthAnswer.mAuthSessionState));

		if(objMultimediaAuthAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objMultimediaAuthAnswer.mOriginHost));

		if(objMultimediaAuthAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objMultimediaAuthAnswer.mOriginRealm));

		if(objMultimediaAuthAnswer.mUserName != NULL)
		mUserName = new OctetString(*(objMultimediaAuthAnswer.mUserName));

		if(objMultimediaAuthAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objMultimediaAuthAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objMultimediaAuthAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objMultimediaAuthAnswer.mOCOLRGrp);
		 }
		if(objMultimediaAuthAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objMultimediaAuthAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		if(objMultimediaAuthAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objMultimediaAuthAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objMultimediaAuthAnswer.mPublicIdentity != NULL)
		mPublicIdentity = new OctetString(*(objMultimediaAuthAnswer.mPublicIdentity));

		if(objMultimediaAuthAnswer.mSIPNumberAuthItems != NULL)
		mSIPNumberAuthItems = new Unsigned32(*(objMultimediaAuthAnswer.mSIPNumberAuthItems));

		if(objMultimediaAuthAnswer.mSIPAuthDataItemGrpList != NULL)
		 {
		 mSIPAuthDataItemGrpList = new list<SIPAuthDataItem*>;
		 for( auto element : *objMultimediaAuthAnswer.mSIPAuthDataItemGrpList)
		 {
				 SIPAuthDataItem *lSIPAuthDataItem =  new SIPAuthDataItem(*element);
				 mSIPAuthDataItemGrpList->push_back(lSIPAuthDataItem);
		 }
		 }
		if(objMultimediaAuthAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objMultimediaAuthAnswer.mErrorMessage));

		if(objMultimediaAuthAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objMultimediaAuthAnswer.mFailedAVPGrp);
		 }
		if(objMultimediaAuthAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objMultimediaAuthAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const MultimediaAuthAnswer &objMultimediaAuthAnswer) {

		mTagsPresent = objMultimediaAuthAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objMultimediaAuthAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objMultimediaAuthAnswer.mMandatoryAvpSetVal;

		mTag = objMultimediaAuthAnswer.mTag;

		mDecodeFlag = objMultimediaAuthAnswer.mDecodeFlag;

		if(objMultimediaAuthAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objMultimediaAuthAnswer.mSessionId));

		if(objMultimediaAuthAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objMultimediaAuthAnswer.mDRMP));

		if(objMultimediaAuthAnswer.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objMultimediaAuthAnswer.mVendorSpecificApplicationIdGrp);
		 }
		if(objMultimediaAuthAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objMultimediaAuthAnswer.mResultCode));

		if(objMultimediaAuthAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objMultimediaAuthAnswer.mExperimentalResultGrp);
		 }
		if(objMultimediaAuthAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objMultimediaAuthAnswer.mAuthSessionState));

		if(objMultimediaAuthAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objMultimediaAuthAnswer.mOriginHost));

		if(objMultimediaAuthAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objMultimediaAuthAnswer.mOriginRealm));

		if(objMultimediaAuthAnswer.mUserName != NULL)
		mUserName = new OctetString(*(objMultimediaAuthAnswer.mUserName));

		if(objMultimediaAuthAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objMultimediaAuthAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objMultimediaAuthAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objMultimediaAuthAnswer.mOCOLRGrp);
		 }
		if(objMultimediaAuthAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objMultimediaAuthAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		if(objMultimediaAuthAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objMultimediaAuthAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objMultimediaAuthAnswer.mPublicIdentity != NULL)
		mPublicIdentity = new OctetString(*(objMultimediaAuthAnswer.mPublicIdentity));

		if(objMultimediaAuthAnswer.mSIPNumberAuthItems != NULL)
		mSIPNumberAuthItems = new Unsigned32(*(objMultimediaAuthAnswer.mSIPNumberAuthItems));

		if(objMultimediaAuthAnswer.mSIPAuthDataItemGrpList != NULL)
		 {
		 mSIPAuthDataItemGrpList = new list<SIPAuthDataItem*>;
		 for( auto element : *objMultimediaAuthAnswer.mSIPAuthDataItemGrpList)
		 {
				 SIPAuthDataItem *lSIPAuthDataItem =  new SIPAuthDataItem(*element);
				 mSIPAuthDataItemGrpList->push_back(lSIPAuthDataItem);
		 }
		 }
		if(objMultimediaAuthAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objMultimediaAuthAnswer.mErrorMessage));

		if(objMultimediaAuthAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objMultimediaAuthAnswer.mFailedAVPGrp);
		 }
		if(objMultimediaAuthAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objMultimediaAuthAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~MultimediaAuthAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype MultimediaAuthAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype MultimediaAuthAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype MultimediaAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype MultimediaAuthAnswer
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype MultimediaAuthAnswer
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype MultimediaAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		VendorSpecificApplicationId* getVendorSpecificApplicationId();

		VendorSpecificApplicationId* setVendorSpecificApplicationId();

		void resetVendorSpecificApplicationId();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype MultimediaAuthAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype MultimediaAuthAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype MultimediaAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		ExperimentalResult* getExperimentalResult();

		ExperimentalResult* setExperimentalResult();

		void resetExperimentalResult();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype MultimediaAuthAnswer
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype MultimediaAuthAnswer
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype MultimediaAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype MultimediaAuthAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype MultimediaAuthAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype MultimediaAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype MultimediaAuthAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype MultimediaAuthAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype MultimediaAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserName for datatype MultimediaAuthAnswer
		*/
		OctetString* setUserName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserName for datatype MultimediaAuthAnswer
		*/
		void resetUserName();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserName for datatype MultimediaAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserName();

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
		/*!		Function to set the recent OctetString type of argument PublicIdentity for datatype MultimediaAuthAnswer
		*/
		OctetString* setPublicIdentity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PublicIdentity for datatype MultimediaAuthAnswer
		*/
		void resetPublicIdentity();

		//!Function to get values
		/*!		Function to get OctetString type of argument PublicIdentity for datatype MultimediaAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getPublicIdentity();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument SIPNumberAuthItems for datatype MultimediaAuthAnswer
		*/
		Unsigned32* setSIPNumberAuthItems();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SIPNumberAuthItems for datatype MultimediaAuthAnswer
		*/
		void resetSIPNumberAuthItems();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument SIPNumberAuthItems for datatype MultimediaAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getSIPNumberAuthItems();

		list<SIPAuthDataItem*>* getSIPAuthDataItemGrpList();

		list<SIPAuthDataItem*>* setSIPAuthDataItemGrpList();

		void resetSIPAuthDataItemGrpList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorMessage for datatype MultimediaAuthAnswer
		*/
		OctetString* setErrorMessage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorMessage for datatype MultimediaAuthAnswer
		*/
		void resetErrorMessage();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorMessage for datatype MultimediaAuthAnswer
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
		/*!		Function to Decode datatype MultimediaAuthAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype MultimediaAuthAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype MultimediaAuthAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype MultimediaAuthAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype MultimediaAuthAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
