#ifndef SD_TDFSESSIONANSWER_H
#define SD_TDFSESSIONANSWER_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/DRMP.h"
#include "sd/include/VendorSpecificApplicationId.h"
#include "sd/include/ExperimentalResult.h"
#include "sd/include/OCSupportedFeatures.h"
#include "sd/include/OCOLR.h"
#include "sd/include/SupportedFeatures.h"
#include "sd/include/ADCRuleReport.h"
#include "sd/include/EventReportIndication.h"
#include "sd/include/FailedAVP.h"
#include "sd/include/ProxyInfo.h"
#include "sd/include/Load.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace SD{
typedef enum _tags_TDFSessionAnswer
{
	TDFSessionAnswer_SESSIONID	= 0,
	TDFSessionAnswer_DRMP	= 1,
	TDFSessionAnswer_VENDORSPECIFICAPPLICATIONID	= 2,
	TDFSessionAnswer_ORIGINHOST	= 3,
	TDFSessionAnswer_ORIGINREALM	= 4,
	TDFSessionAnswer_RESULTCODE	= 5,
	TDFSessionAnswer_EXPERIMENTALRESULT	= 6,
	TDFSessionAnswer_ORIGINSTATEID	= 7,
	TDFSessionAnswer_OCSUPPORTEDFEATURES	= 8,
	TDFSessionAnswer_OCOLR	= 9,
	TDFSessionAnswer_SUPPORTEDFEATURES	= 10,
	TDFSessionAnswer_ADCRULEREPORT	= 11,
	TDFSessionAnswer_EVENTREPORTINDICATION	= 12,
	TDFSessionAnswer_ERRORMESSAGE	= 13,
	TDFSessionAnswer_ERRORREPORTINGHOST	= 14,
	TDFSessionAnswer_FAILEDAVP	= 15,
	TDFSessionAnswer_PROXYINFO	= 16,
	TDFSessionAnswer_ROUTERECORD	= 17,
	TDFSessionAnswer_LOAD	= 18,
}TDFSessionAnswer_tags;

		//! Class Definition
		/*!		ClassName is TDFSessionAnswer
		*/
class TDFSessionAnswer : public DiameterBase 
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

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		Unsigned32*		mResultCode;

		Unsigned32*		mOriginStateId;

		OctetString*		mErrorMessage;

		OctetString*		mErrorReportingHost;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;




		VendorSpecificApplicationId*	mVendorSpecificApplicationIdGrp;




		ExperimentalResult*	mExperimentalResultGrp;


		OCSupportedFeatures*	mOCSupportedFeaturesGrp;

		OCOLR*	mOCOLRGrp;

		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;

		list<ADCRuleReport*>*	mADCRuleReportGrpList;
		list<ADCRuleReport*>::iterator	mADCRuleReportGrpIterator;

		EventReportIndication*	mEventReportIndicationGrp;



		FailedAVP*	mFailedAVPGrp;

		list<SD::ProxyInfo*>*	mProxyInfoGrpList;
		list<SD::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


		list<Load*>*	mLoadGrpList;
		list<Load*>::iterator	mLoadGrpIterator;

	public:
		TDFSessionAnswer();

		TDFSessionAnswer(const TDFSessionAnswer &objTDFSessionAnswer) {

		mTagsPresent = objTDFSessionAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objTDFSessionAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objTDFSessionAnswer.mMandatoryAvpSetVal;

		mTag = objTDFSessionAnswer.mTag;

		mDecodeFlag = objTDFSessionAnswer.mDecodeFlag;

		if(objTDFSessionAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objTDFSessionAnswer.mSessionId));

		if(objTDFSessionAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objTDFSessionAnswer.mDRMP));

		if(objTDFSessionAnswer.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objTDFSessionAnswer.mVendorSpecificApplicationIdGrp);
		 }
		if(objTDFSessionAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objTDFSessionAnswer.mOriginHost));

		if(objTDFSessionAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objTDFSessionAnswer.mOriginRealm));

		if(objTDFSessionAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objTDFSessionAnswer.mResultCode));

		if(objTDFSessionAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objTDFSessionAnswer.mExperimentalResultGrp);
		 }
		if(objTDFSessionAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objTDFSessionAnswer.mOriginStateId));

		if(objTDFSessionAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objTDFSessionAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objTDFSessionAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objTDFSessionAnswer.mOCOLRGrp);
		 }
		if(objTDFSessionAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objTDFSessionAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objTDFSessionAnswer.mADCRuleReportGrpList != NULL)
		 {
		 mADCRuleReportGrpList = new list<ADCRuleReport*>;
		 for( auto element : *objTDFSessionAnswer.mADCRuleReportGrpList)
		 {
				 ADCRuleReport *lADCRuleReport =  new ADCRuleReport(*element);
				 mADCRuleReportGrpList->push_back(lADCRuleReport);
		 }
		 }
		if(objTDFSessionAnswer.mEventReportIndicationGrp != NULL)
		 {
				 mEventReportIndicationGrp =  new EventReportIndication(*objTDFSessionAnswer.mEventReportIndicationGrp);
		 }
		if(objTDFSessionAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objTDFSessionAnswer.mErrorMessage));

		if(objTDFSessionAnswer.mErrorReportingHost != NULL)
		mErrorReportingHost = new OctetString(*(objTDFSessionAnswer.mErrorReportingHost));

		if(objTDFSessionAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objTDFSessionAnswer.mFailedAVPGrp);
		 }
		if(objTDFSessionAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SD::ProxyInfo*>;
		 for( auto element : *objTDFSessionAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objTDFSessionAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objTDFSessionAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		}

		void operator = (const TDFSessionAnswer &objTDFSessionAnswer) {

		mTagsPresent = objTDFSessionAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objTDFSessionAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objTDFSessionAnswer.mMandatoryAvpSetVal;

		mTag = objTDFSessionAnswer.mTag;

		mDecodeFlag = objTDFSessionAnswer.mDecodeFlag;

		if(objTDFSessionAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objTDFSessionAnswer.mSessionId));

		if(objTDFSessionAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objTDFSessionAnswer.mDRMP));

		if(objTDFSessionAnswer.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objTDFSessionAnswer.mVendorSpecificApplicationIdGrp);
		 }
		if(objTDFSessionAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objTDFSessionAnswer.mOriginHost));

		if(objTDFSessionAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objTDFSessionAnswer.mOriginRealm));

		if(objTDFSessionAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objTDFSessionAnswer.mResultCode));

		if(objTDFSessionAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objTDFSessionAnswer.mExperimentalResultGrp);
		 }
		if(objTDFSessionAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objTDFSessionAnswer.mOriginStateId));

		if(objTDFSessionAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objTDFSessionAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objTDFSessionAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objTDFSessionAnswer.mOCOLRGrp);
		 }
		if(objTDFSessionAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objTDFSessionAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objTDFSessionAnswer.mADCRuleReportGrpList != NULL)
		 {
		 mADCRuleReportGrpList = new list<ADCRuleReport*>;
		 for( auto element : *objTDFSessionAnswer.mADCRuleReportGrpList)
		 {
				 ADCRuleReport *lADCRuleReport =  new ADCRuleReport(*element);
				 mADCRuleReportGrpList->push_back(lADCRuleReport);
		 }
		 }
		if(objTDFSessionAnswer.mEventReportIndicationGrp != NULL)
		 {
				 mEventReportIndicationGrp =  new EventReportIndication(*objTDFSessionAnswer.mEventReportIndicationGrp);
		 }
		if(objTDFSessionAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objTDFSessionAnswer.mErrorMessage));

		if(objTDFSessionAnswer.mErrorReportingHost != NULL)
		mErrorReportingHost = new OctetString(*(objTDFSessionAnswer.mErrorReportingHost));

		if(objTDFSessionAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objTDFSessionAnswer.mFailedAVPGrp);
		 }
		if(objTDFSessionAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SD::ProxyInfo*>;
		 for( auto element : *objTDFSessionAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objTDFSessionAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objTDFSessionAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		}

		virtual ~TDFSessionAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype TDFSessionAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype TDFSessionAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype TDFSessionAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype TDFSessionAnswer
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype TDFSessionAnswer
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype TDFSessionAnswer
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		VendorSpecificApplicationId* getVendorSpecificApplicationId();

		VendorSpecificApplicationId* setVendorSpecificApplicationId();

		void resetVendorSpecificApplicationId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype TDFSessionAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype TDFSessionAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype TDFSessionAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype TDFSessionAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype TDFSessionAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype TDFSessionAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype TDFSessionAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype TDFSessionAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype TDFSessionAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		ExperimentalResult* getExperimentalResult();

		ExperimentalResult* setExperimentalResult();

		void resetExperimentalResult();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype TDFSessionAnswer
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype TDFSessionAnswer
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype TDFSessionAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		OCSupportedFeatures* getOCSupportedFeatures();

		OCSupportedFeatures* setOCSupportedFeatures();

		void resetOCSupportedFeatures();

		OCOLR* getOCOLR();

		OCOLR* setOCOLR();

		void resetOCOLR();

		list<SupportedFeatures*>* getSupportedFeaturesGrpList();

		list<SupportedFeatures*>* setSupportedFeaturesGrpList();

		void resetSupportedFeaturesGrpList();

		list<ADCRuleReport*>* getADCRuleReportGrpList();

		list<ADCRuleReport*>* setADCRuleReportGrpList();

		void resetADCRuleReportGrpList();

		EventReportIndication* getEventReportIndication();

		EventReportIndication* setEventReportIndication();

		void resetEventReportIndication();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorMessage for datatype TDFSessionAnswer
		*/
		OctetString* setErrorMessage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorMessage for datatype TDFSessionAnswer
		*/
		void resetErrorMessage();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorMessage for datatype TDFSessionAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorMessage();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorReportingHost for datatype TDFSessionAnswer
		*/
		OctetString* setErrorReportingHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorReportingHost for datatype TDFSessionAnswer
		*/
		void resetErrorReportingHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorReportingHost for datatype TDFSessionAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorReportingHost();

		FailedAVP* getFailedAVP();

		FailedAVP* setFailedAVP();

		void resetFailedAVP();

		list<SD::ProxyInfo*>* getProxyInfoGrpList();

		list<SD::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		list<Load*>* getLoadGrpList();

		list<Load*>* setLoadGrpList();

		void resetLoadGrpList();

		//! Function to Decode
		/*!		Function to Decode datatype TDFSessionAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype TDFSessionAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype TDFSessionAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype TDFSessionAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype TDFSessionAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
