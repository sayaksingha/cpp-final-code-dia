#ifndef SD_CREDITCONTROLANSWER_H
#define SD_CREDITCONTROLANSWER_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/DRMP.h"
#include "sd/include/ExperimentalResult.h"
#include "sd/include/OCSupportedFeatures.h"
#include "sd/include/OCOLR.h"
#include "sd/include/QoSInformation.h"
#include "sd/include/EventTrigger.h"
#include "sd/include/CSGInformationReporting.h"
#include "sd/include/EventReportIndication.h"
#include "sd/include/RedirectHostUsage.h"
#include "sd/include/ADCRuleRemove.h"
#include "sd/include/ADCRuleInstall.h"
#include "sd/include/UsageMonitoringInformation.h"
#include "sd/include/FailedAVP.h"
#include "sd/include/ProxyInfo.h"
#include "sd/include/SupportedFeatures.h"
#include "sd/include/Load.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace SD{
typedef enum _tags_CreditControlAnswer
{
	CreditControlAnswer_SESSIONID	= 0,
	CreditControlAnswer_DRMP	= 1,
	CreditControlAnswer_AUTHAPPLICATIONID	= 2,
	CreditControlAnswer_ORIGINHOST	= 3,
	CreditControlAnswer_ORIGINREALM	= 4,
	CreditControlAnswer_RESULTCODE	= 5,
	CreditControlAnswer_EXPERIMENTALRESULT	= 6,
	CreditControlAnswer_CCREQUESTTYPE	= 7,
	CreditControlAnswer_CCREQUESTNUMBER	= 8,
	CreditControlAnswer_OCSUPPORTEDFEATURES	= 9,
	CreditControlAnswer_OCOLR	= 10,
	CreditControlAnswer_FRAMEDIPV6PREFIX	= 11,
	CreditControlAnswer_QOSINFORMATION	= 12,
	CreditControlAnswer_EVENTTRIGGER	= 13,
	CreditControlAnswer_CSGINFORMATIONREPORTING	= 14,
	CreditControlAnswer_EVENTREPORTINDICATION	= 15,
	CreditControlAnswer_ORIGINSTATEID	= 16,
	CreditControlAnswer_REDIRECTHOST	= 17,
	CreditControlAnswer_REDIRECTHOSTUSAGE	= 18,
	CreditControlAnswer_REDIRECTMAXCACHETIME	= 19,
	CreditControlAnswer_ADCRULEREMOVE	= 20,
	CreditControlAnswer_ADCRULEINSTALL	= 21,
	CreditControlAnswer_REVALIDATIONTIME	= 22,
	CreditControlAnswer_USAGEMONITORINGINFORMATION	= 23,
	CreditControlAnswer_ERRORMESSAGE	= 24,
	CreditControlAnswer_ERRORREPORTINGHOST	= 25,
	CreditControlAnswer_FAILEDAVP	= 26,
	CreditControlAnswer_PROXYINFO	= 27,
	CreditControlAnswer_ROUTERECORD	= 28,
	CreditControlAnswer_SUPPORTEDFEATURES	= 29,
	CreditControlAnswer_LOAD	= 30,
}CreditControlAnswer_tags;

		//! Class Definition
		/*!		ClassName is CreditControlAnswer
		*/
class CreditControlAnswer : public DiameterBase 
{
	private:

		bitset<31> mTagsPresent;

		bitset<31> mMandatoryAvpCheckVal;

		bitset<31> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		DRMP*		mDRMP;

		Integer32*		mAuthApplicationId;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		Unsigned32*		mResultCode;

		CCRequestType*		mCCRequestType;

		Unsigned32*		mCCRequestNumber;

		OctetString*		mFramedIPv6Prefix;

		list<EventTrigger*>* 		mEventTriggerList;

		list<EventTrigger*>::iterator 		mEventTriggerIterator;

		list<CSGInformationReporting*>* 		mCSGInformationReportingList;

		list<CSGInformationReporting*>::iterator 		mCSGInformationReportingIterator;

		Unsigned32*		mOriginStateId;

		list<OctetString*>* 		mRedirectHostList;

		list<OctetString*>::iterator 		mRedirectHostIterator;

		RedirectHostUsage*		mRedirectHostUsage;

		Unsigned32*		mRedirectMaxCacheTime;

		Time*		mRevalidationTime;

		OctetString*		mErrorMessage;

		OctetString*		mErrorReportingHost;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;








		ExperimentalResult*	mExperimentalResultGrp;



		OCSupportedFeatures*	mOCSupportedFeaturesGrp;

		OCOLR*	mOCOLRGrp;


		QoSInformation*	mQoSInformationGrp;



		EventReportIndication*	mEventReportIndicationGrp;





		list<ADCRuleRemove*>*	mADCRuleRemoveGrpList;
		list<ADCRuleRemove*>::iterator	mADCRuleRemoveGrpIterator;

		list<ADCRuleInstall*>*	mADCRuleInstallGrpList;
		list<ADCRuleInstall*>::iterator	mADCRuleInstallGrpIterator;


		list<UsageMonitoringInformation*>*	mUsageMonitoringInformationGrpList;
		list<UsageMonitoringInformation*>::iterator	mUsageMonitoringInformationGrpIterator;



		FailedAVP*	mFailedAVPGrp;

		list<SD::ProxyInfo*>*	mProxyInfoGrpList;
		list<SD::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;

		list<Load*>*	mLoadGrpList;
		list<Load*>::iterator	mLoadGrpIterator;

	public:
		CreditControlAnswer();

		CreditControlAnswer(const CreditControlAnswer &objCreditControlAnswer) {

		mTagsPresent = objCreditControlAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objCreditControlAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objCreditControlAnswer.mMandatoryAvpSetVal;

		mTag = objCreditControlAnswer.mTag;

		mDecodeFlag = objCreditControlAnswer.mDecodeFlag;

		if(objCreditControlAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objCreditControlAnswer.mSessionId));

		if(objCreditControlAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objCreditControlAnswer.mDRMP));

		if(objCreditControlAnswer.mAuthApplicationId != NULL)
		mAuthApplicationId = new Integer32(*(objCreditControlAnswer.mAuthApplicationId));

		if(objCreditControlAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objCreditControlAnswer.mOriginHost));

		if(objCreditControlAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objCreditControlAnswer.mOriginRealm));

		if(objCreditControlAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objCreditControlAnswer.mResultCode));

		if(objCreditControlAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objCreditControlAnswer.mExperimentalResultGrp);
		 }
		if(objCreditControlAnswer.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objCreditControlAnswer.mCCRequestType));

		if(objCreditControlAnswer.mCCRequestNumber != NULL)
		mCCRequestNumber = new Unsigned32(*(objCreditControlAnswer.mCCRequestNumber));

		if(objCreditControlAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objCreditControlAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objCreditControlAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objCreditControlAnswer.mOCOLRGrp);
		 }
		if(objCreditControlAnswer.mFramedIPv6Prefix != NULL)
		mFramedIPv6Prefix = new OctetString(*(objCreditControlAnswer.mFramedIPv6Prefix));

		if(objCreditControlAnswer.mQoSInformationGrp != NULL)
		 {
				 mQoSInformationGrp =  new QoSInformation(*objCreditControlAnswer.mQoSInformationGrp);
		 }
		if(objCreditControlAnswer.mEventReportIndicationGrp != NULL)
		 {
				 mEventReportIndicationGrp =  new EventReportIndication(*objCreditControlAnswer.mEventReportIndicationGrp);
		 }
		if(objCreditControlAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objCreditControlAnswer.mOriginStateId));

		if(objCreditControlAnswer.mRedirectHostUsage != NULL)
		mRedirectHostUsage = new RedirectHostUsage(*(objCreditControlAnswer.mRedirectHostUsage));

		if(objCreditControlAnswer.mRedirectMaxCacheTime != NULL)
		mRedirectMaxCacheTime = new Unsigned32(*(objCreditControlAnswer.mRedirectMaxCacheTime));

		if(objCreditControlAnswer.mADCRuleRemoveGrpList != NULL)
		 {
		 mADCRuleRemoveGrpList = new list<ADCRuleRemove*>;
		 for( auto element : *objCreditControlAnswer.mADCRuleRemoveGrpList)
		 {
				 ADCRuleRemove *lADCRuleRemove =  new ADCRuleRemove(*element);
				 mADCRuleRemoveGrpList->push_back(lADCRuleRemove);
		 }
		 }
		if(objCreditControlAnswer.mADCRuleInstallGrpList != NULL)
		 {
		 mADCRuleInstallGrpList = new list<ADCRuleInstall*>;
		 for( auto element : *objCreditControlAnswer.mADCRuleInstallGrpList)
		 {
				 ADCRuleInstall *lADCRuleInstall =  new ADCRuleInstall(*element);
				 mADCRuleInstallGrpList->push_back(lADCRuleInstall);
		 }
		 }
		if(objCreditControlAnswer.mRevalidationTime != NULL)
		mRevalidationTime = new Time(*(objCreditControlAnswer.mRevalidationTime));

		if(objCreditControlAnswer.mUsageMonitoringInformationGrpList != NULL)
		 {
		 mUsageMonitoringInformationGrpList = new list<UsageMonitoringInformation*>;
		 for( auto element : *objCreditControlAnswer.mUsageMonitoringInformationGrpList)
		 {
				 UsageMonitoringInformation *lUsageMonitoringInformation =  new UsageMonitoringInformation(*element);
				 mUsageMonitoringInformationGrpList->push_back(lUsageMonitoringInformation);
		 }
		 }
		if(objCreditControlAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objCreditControlAnswer.mErrorMessage));

		if(objCreditControlAnswer.mErrorReportingHost != NULL)
		mErrorReportingHost = new OctetString(*(objCreditControlAnswer.mErrorReportingHost));

		if(objCreditControlAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objCreditControlAnswer.mFailedAVPGrp);
		 }
		if(objCreditControlAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SD::ProxyInfo*>;
		 for( auto element : *objCreditControlAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objCreditControlAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objCreditControlAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objCreditControlAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objCreditControlAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		}

		void operator = (const CreditControlAnswer &objCreditControlAnswer) {

		mTagsPresent = objCreditControlAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objCreditControlAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objCreditControlAnswer.mMandatoryAvpSetVal;

		mTag = objCreditControlAnswer.mTag;

		mDecodeFlag = objCreditControlAnswer.mDecodeFlag;

		if(objCreditControlAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objCreditControlAnswer.mSessionId));

		if(objCreditControlAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objCreditControlAnswer.mDRMP));

		if(objCreditControlAnswer.mAuthApplicationId != NULL)
		mAuthApplicationId = new Integer32(*(objCreditControlAnswer.mAuthApplicationId));

		if(objCreditControlAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objCreditControlAnswer.mOriginHost));

		if(objCreditControlAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objCreditControlAnswer.mOriginRealm));

		if(objCreditControlAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objCreditControlAnswer.mResultCode));

		if(objCreditControlAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objCreditControlAnswer.mExperimentalResultGrp);
		 }
		if(objCreditControlAnswer.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objCreditControlAnswer.mCCRequestType));

		if(objCreditControlAnswer.mCCRequestNumber != NULL)
		mCCRequestNumber = new Unsigned32(*(objCreditControlAnswer.mCCRequestNumber));

		if(objCreditControlAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objCreditControlAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objCreditControlAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objCreditControlAnswer.mOCOLRGrp);
		 }
		if(objCreditControlAnswer.mFramedIPv6Prefix != NULL)
		mFramedIPv6Prefix = new OctetString(*(objCreditControlAnswer.mFramedIPv6Prefix));

		if(objCreditControlAnswer.mQoSInformationGrp != NULL)
		 {
				 mQoSInformationGrp =  new QoSInformation(*objCreditControlAnswer.mQoSInformationGrp);
		 }
		if(objCreditControlAnswer.mEventReportIndicationGrp != NULL)
		 {
				 mEventReportIndicationGrp =  new EventReportIndication(*objCreditControlAnswer.mEventReportIndicationGrp);
		 }
		if(objCreditControlAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objCreditControlAnswer.mOriginStateId));

		if(objCreditControlAnswer.mRedirectHostUsage != NULL)
		mRedirectHostUsage = new RedirectHostUsage(*(objCreditControlAnswer.mRedirectHostUsage));

		if(objCreditControlAnswer.mRedirectMaxCacheTime != NULL)
		mRedirectMaxCacheTime = new Unsigned32(*(objCreditControlAnswer.mRedirectMaxCacheTime));

		if(objCreditControlAnswer.mADCRuleRemoveGrpList != NULL)
		 {
		 mADCRuleRemoveGrpList = new list<ADCRuleRemove*>;
		 for( auto element : *objCreditControlAnswer.mADCRuleRemoveGrpList)
		 {
				 ADCRuleRemove *lADCRuleRemove =  new ADCRuleRemove(*element);
				 mADCRuleRemoveGrpList->push_back(lADCRuleRemove);
		 }
		 }
		if(objCreditControlAnswer.mADCRuleInstallGrpList != NULL)
		 {
		 mADCRuleInstallGrpList = new list<ADCRuleInstall*>;
		 for( auto element : *objCreditControlAnswer.mADCRuleInstallGrpList)
		 {
				 ADCRuleInstall *lADCRuleInstall =  new ADCRuleInstall(*element);
				 mADCRuleInstallGrpList->push_back(lADCRuleInstall);
		 }
		 }
		if(objCreditControlAnswer.mRevalidationTime != NULL)
		mRevalidationTime = new Time(*(objCreditControlAnswer.mRevalidationTime));

		if(objCreditControlAnswer.mUsageMonitoringInformationGrpList != NULL)
		 {
		 mUsageMonitoringInformationGrpList = new list<UsageMonitoringInformation*>;
		 for( auto element : *objCreditControlAnswer.mUsageMonitoringInformationGrpList)
		 {
				 UsageMonitoringInformation *lUsageMonitoringInformation =  new UsageMonitoringInformation(*element);
				 mUsageMonitoringInformationGrpList->push_back(lUsageMonitoringInformation);
		 }
		 }
		if(objCreditControlAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objCreditControlAnswer.mErrorMessage));

		if(objCreditControlAnswer.mErrorReportingHost != NULL)
		mErrorReportingHost = new OctetString(*(objCreditControlAnswer.mErrorReportingHost));

		if(objCreditControlAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objCreditControlAnswer.mFailedAVPGrp);
		 }
		if(objCreditControlAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SD::ProxyInfo*>;
		 for( auto element : *objCreditControlAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objCreditControlAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objCreditControlAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objCreditControlAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objCreditControlAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		}

		virtual ~CreditControlAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype CreditControlAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype CreditControlAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype CreditControlAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype CreditControlAnswer
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype CreditControlAnswer
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype CreditControlAnswer
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		//!Function to set values
		/*!		Function to set the recent Integer32 type of argument AuthApplicationId for datatype CreditControlAnswer
		*/
		Integer32* setAuthApplicationId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthApplicationId for datatype CreditControlAnswer
		*/
		void resetAuthApplicationId();

		//!Function to get values
		/*!		Function to get Integer32 type of argument AuthApplicationId for datatype CreditControlAnswer
		Throws exception of which type and Summary of Exception
		*/
		Integer32* getAuthApplicationId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype CreditControlAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype CreditControlAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype CreditControlAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype CreditControlAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype CreditControlAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype CreditControlAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype CreditControlAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype CreditControlAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype CreditControlAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		ExperimentalResult* getExperimentalResult();

		ExperimentalResult* setExperimentalResult();

		void resetExperimentalResult();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument CCRequestType for datatype CreditControlAnswer
		*/
		CCRequestType* setCCRequestType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCRequestType for datatype CreditControlAnswer
		*/
		void resetCCRequestType();

		//!Function to get values
		/*!		Function to get CCRequestType type of argument CCRequestType for datatype CreditControlAnswer
		Throws exception of which type and Summary of Exception
		*/
		CCRequestType* getCCRequestType();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument CCRequestNumber for datatype CreditControlAnswer
		*/
		Unsigned32* setCCRequestNumber();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCRequestNumber for datatype CreditControlAnswer
		*/
		void resetCCRequestNumber();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument CCRequestNumber for datatype CreditControlAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getCCRequestNumber();

		OCSupportedFeatures* getOCSupportedFeatures();

		OCSupportedFeatures* setOCSupportedFeatures();

		void resetOCSupportedFeatures();

		OCOLR* getOCOLR();

		OCOLR* setOCOLR();

		void resetOCOLR();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument FramedIPv6Prefix for datatype CreditControlAnswer
		*/
		OctetString* setFramedIPv6Prefix();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FramedIPv6Prefix for datatype CreditControlAnswer
		*/
		void resetFramedIPv6Prefix();

		//!Function to get values
		/*!		Function to get OctetString type of argument FramedIPv6Prefix for datatype CreditControlAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getFramedIPv6Prefix();

		QoSInformation* getQoSInformation();

		QoSInformation* setQoSInformation();

		void resetQoSInformation();

		list<EventTrigger*>* getEventTriggerList();

		list<EventTrigger*>* setEventTriggerList();

		void resetEventTriggerList();

		list<CSGInformationReporting*>* getCSGInformationReportingList();

		list<CSGInformationReporting*>* setCSGInformationReportingList();

		void resetCSGInformationReportingList();

		EventReportIndication* getEventReportIndication();

		EventReportIndication* setEventReportIndication();

		void resetEventReportIndication();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype CreditControlAnswer
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype CreditControlAnswer
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype CreditControlAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		list<OctetString*>* getRedirectHostList();

		list<OctetString*>* setRedirectHostList();

		void resetRedirectHostList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument RedirectHostUsage for datatype CreditControlAnswer
		*/
		RedirectHostUsage* setRedirectHostUsage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RedirectHostUsage for datatype CreditControlAnswer
		*/
		void resetRedirectHostUsage();

		//!Function to get values
		/*!		Function to get RedirectHostUsage type of argument RedirectHostUsage for datatype CreditControlAnswer
		Throws exception of which type and Summary of Exception
		*/
		RedirectHostUsage* getRedirectHostUsage();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument RedirectMaxCacheTime for datatype CreditControlAnswer
		*/
		Unsigned32* setRedirectMaxCacheTime();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RedirectMaxCacheTime for datatype CreditControlAnswer
		*/
		void resetRedirectMaxCacheTime();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument RedirectMaxCacheTime for datatype CreditControlAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getRedirectMaxCacheTime();

		list<ADCRuleRemove*>* getADCRuleRemoveGrpList();

		list<ADCRuleRemove*>* setADCRuleRemoveGrpList();

		void resetADCRuleRemoveGrpList();

		list<ADCRuleInstall*>* getADCRuleInstallGrpList();

		list<ADCRuleInstall*>* setADCRuleInstallGrpList();

		void resetADCRuleInstallGrpList();

		//!Function to set values
		/*!		Function to set the recent Time type of argument RevalidationTime for datatype CreditControlAnswer
		*/
		Time* setRevalidationTime();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RevalidationTime for datatype CreditControlAnswer
		*/
		void resetRevalidationTime();

		//!Function to get values
		/*!		Function to get Time type of argument RevalidationTime for datatype CreditControlAnswer
		Throws exception of which type and Summary of Exception
		*/
		Time* getRevalidationTime();

		list<UsageMonitoringInformation*>* getUsageMonitoringInformationGrpList();

		list<UsageMonitoringInformation*>* setUsageMonitoringInformationGrpList();

		void resetUsageMonitoringInformationGrpList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorMessage for datatype CreditControlAnswer
		*/
		OctetString* setErrorMessage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorMessage for datatype CreditControlAnswer
		*/
		void resetErrorMessage();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorMessage for datatype CreditControlAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorMessage();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorReportingHost for datatype CreditControlAnswer
		*/
		OctetString* setErrorReportingHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorReportingHost for datatype CreditControlAnswer
		*/
		void resetErrorReportingHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorReportingHost for datatype CreditControlAnswer
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

		list<SupportedFeatures*>* getSupportedFeaturesGrpList();

		list<SupportedFeatures*>* setSupportedFeaturesGrpList();

		void resetSupportedFeaturesGrpList();

		list<Load*>* getLoadGrpList();

		list<Load*>* setLoadGrpList();

		void resetLoadGrpList();

		//! Function to Decode
		/*!		Function to Decode datatype CreditControlAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype CreditControlAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype CreditControlAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype CreditControlAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CreditControlAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
