#ifndef SD_REAUTHANSWER_H
#define SD_REAUTHANSWER_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/DRMP.h"
#include "sd/include/ExperimentalResult.h"
#include "sd/include/OCSupportedFeatures.h"
#include "sd/include/OCOLR.h"
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
typedef enum _tags_ReAuthAnswer
{
	ReAuthAnswer_SESSIONID	= 0,
	ReAuthAnswer_DRMP	= 1,
	ReAuthAnswer_ORIGINHOST	= 2,
	ReAuthAnswer_ORIGINREALM	= 3,
	ReAuthAnswer_RESULTCODE	= 4,
	ReAuthAnswer_EXPERIMENTALRESULT	= 5,
	ReAuthAnswer_ORIGINSTATEID	= 6,
	ReAuthAnswer_OCSUPPORTEDFEATURES	= 7,
	ReAuthAnswer_OCOLR	= 8,
	ReAuthAnswer_ADCRULEREPORT	= 9,
	ReAuthAnswer_EVENTREPORTINDICATION	= 10,
	ReAuthAnswer_ERRORMESSAGE	= 11,
	ReAuthAnswer_ERRORREPORTINGHOST	= 12,
	ReAuthAnswer_FAILEDAVP	= 13,
	ReAuthAnswer_PROXYINFO	= 14,
	ReAuthAnswer_LOAD	= 15,
}ReAuthAnswer_tags;

		//! Class Definition
		/*!		ClassName is ReAuthAnswer
		*/
class ReAuthAnswer : public DiameterBase 
{
	private:

		bitset<16> mTagsPresent;

		bitset<16> mMandatoryAvpCheckVal;

		bitset<16> mMandatoryAvpSetVal;

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







		ExperimentalResult*	mExperimentalResultGrp;


		OCSupportedFeatures*	mOCSupportedFeaturesGrp;

		OCOLR*	mOCOLRGrp;

		list<ADCRuleReport*>*	mADCRuleReportGrpList;
		list<ADCRuleReport*>::iterator	mADCRuleReportGrpIterator;

		EventReportIndication*	mEventReportIndicationGrp;



		FailedAVP*	mFailedAVPGrp;

		list<SD::ProxyInfo*>*	mProxyInfoGrpList;
		list<SD::ProxyInfo*>::iterator	mProxyInfoGrpIterator;

		list<Load*>*	mLoadGrpList;
		list<Load*>::iterator	mLoadGrpIterator;

	public:
		ReAuthAnswer();

		ReAuthAnswer(const ReAuthAnswer &objReAuthAnswer) {

		mTagsPresent = objReAuthAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objReAuthAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objReAuthAnswer.mMandatoryAvpSetVal;

		mTag = objReAuthAnswer.mTag;

		mDecodeFlag = objReAuthAnswer.mDecodeFlag;

		if(objReAuthAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objReAuthAnswer.mSessionId));

		if(objReAuthAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objReAuthAnswer.mDRMP));

		if(objReAuthAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objReAuthAnswer.mOriginHost));

		if(objReAuthAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objReAuthAnswer.mOriginRealm));

		if(objReAuthAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objReAuthAnswer.mResultCode));

		if(objReAuthAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objReAuthAnswer.mExperimentalResultGrp);
		 }
		if(objReAuthAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objReAuthAnswer.mOriginStateId));

		if(objReAuthAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objReAuthAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objReAuthAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objReAuthAnswer.mOCOLRGrp);
		 }
		if(objReAuthAnswer.mADCRuleReportGrpList != NULL)
		 {
		 mADCRuleReportGrpList = new list<ADCRuleReport*>;
		 for( auto element : *objReAuthAnswer.mADCRuleReportGrpList)
		 {
				 ADCRuleReport *lADCRuleReport =  new ADCRuleReport(*element);
				 mADCRuleReportGrpList->push_back(lADCRuleReport);
		 }
		 }
		if(objReAuthAnswer.mEventReportIndicationGrp != NULL)
		 {
				 mEventReportIndicationGrp =  new EventReportIndication(*objReAuthAnswer.mEventReportIndicationGrp);
		 }
		if(objReAuthAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objReAuthAnswer.mErrorMessage));

		if(objReAuthAnswer.mErrorReportingHost != NULL)
		mErrorReportingHost = new OctetString(*(objReAuthAnswer.mErrorReportingHost));

		if(objReAuthAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objReAuthAnswer.mFailedAVPGrp);
		 }
		if(objReAuthAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SD::ProxyInfo*>;
		 for( auto element : *objReAuthAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objReAuthAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objReAuthAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		}

		void operator = (const ReAuthAnswer &objReAuthAnswer) {

		mTagsPresent = objReAuthAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objReAuthAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objReAuthAnswer.mMandatoryAvpSetVal;

		mTag = objReAuthAnswer.mTag;

		mDecodeFlag = objReAuthAnswer.mDecodeFlag;

		if(objReAuthAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objReAuthAnswer.mSessionId));

		if(objReAuthAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objReAuthAnswer.mDRMP));

		if(objReAuthAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objReAuthAnswer.mOriginHost));

		if(objReAuthAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objReAuthAnswer.mOriginRealm));

		if(objReAuthAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objReAuthAnswer.mResultCode));

		if(objReAuthAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objReAuthAnswer.mExperimentalResultGrp);
		 }
		if(objReAuthAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objReAuthAnswer.mOriginStateId));

		if(objReAuthAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objReAuthAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objReAuthAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objReAuthAnswer.mOCOLRGrp);
		 }
		if(objReAuthAnswer.mADCRuleReportGrpList != NULL)
		 {
		 mADCRuleReportGrpList = new list<ADCRuleReport*>;
		 for( auto element : *objReAuthAnswer.mADCRuleReportGrpList)
		 {
				 ADCRuleReport *lADCRuleReport =  new ADCRuleReport(*element);
				 mADCRuleReportGrpList->push_back(lADCRuleReport);
		 }
		 }
		if(objReAuthAnswer.mEventReportIndicationGrp != NULL)
		 {
				 mEventReportIndicationGrp =  new EventReportIndication(*objReAuthAnswer.mEventReportIndicationGrp);
		 }
		if(objReAuthAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objReAuthAnswer.mErrorMessage));

		if(objReAuthAnswer.mErrorReportingHost != NULL)
		mErrorReportingHost = new OctetString(*(objReAuthAnswer.mErrorReportingHost));

		if(objReAuthAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objReAuthAnswer.mFailedAVPGrp);
		 }
		if(objReAuthAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SD::ProxyInfo*>;
		 for( auto element : *objReAuthAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objReAuthAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objReAuthAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		}

		virtual ~ReAuthAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype ReAuthAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype ReAuthAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype ReAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype ReAuthAnswer
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype ReAuthAnswer
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype ReAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype ReAuthAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype ReAuthAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype ReAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype ReAuthAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype ReAuthAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype ReAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype ReAuthAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype ReAuthAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype ReAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		ExperimentalResult* getExperimentalResult();

		ExperimentalResult* setExperimentalResult();

		void resetExperimentalResult();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype ReAuthAnswer
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype ReAuthAnswer
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype ReAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		OCSupportedFeatures* getOCSupportedFeatures();

		OCSupportedFeatures* setOCSupportedFeatures();

		void resetOCSupportedFeatures();

		OCOLR* getOCOLR();

		OCOLR* setOCOLR();

		void resetOCOLR();

		list<ADCRuleReport*>* getADCRuleReportGrpList();

		list<ADCRuleReport*>* setADCRuleReportGrpList();

		void resetADCRuleReportGrpList();

		EventReportIndication* getEventReportIndication();

		EventReportIndication* setEventReportIndication();

		void resetEventReportIndication();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorMessage for datatype ReAuthAnswer
		*/
		OctetString* setErrorMessage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorMessage for datatype ReAuthAnswer
		*/
		void resetErrorMessage();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorMessage for datatype ReAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorMessage();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorReportingHost for datatype ReAuthAnswer
		*/
		OctetString* setErrorReportingHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorReportingHost for datatype ReAuthAnswer
		*/
		void resetErrorReportingHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorReportingHost for datatype ReAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorReportingHost();

		FailedAVP* getFailedAVP();

		FailedAVP* setFailedAVP();

		void resetFailedAVP();

		list<SD::ProxyInfo*>* getProxyInfoGrpList();

		list<SD::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<Load*>* getLoadGrpList();

		list<Load*>* setLoadGrpList();

		void resetLoadGrpList();

		//! Function to Decode
		/*!		Function to Decode datatype ReAuthAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype ReAuthAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype ReAuthAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype ReAuthAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ReAuthAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
