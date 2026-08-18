#ifndef SD_REAUTHREQUEST_H
#define SD_REAUTHREQUEST_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/DRMP.h"
#include "sd/include/ReAuthRequestType.h"
#include "sd/include/SessionReleaseCause.h"
#include "sd/include/OCSupportedFeatures.h"
#include "sd/include/QoSInformation.h"
#include "sd/include/EventTrigger.h"
#include "sd/include/CSGInformationReporting.h"
#include "sd/include/EventReportIndication.h"
#include "sd/include/ADCRuleRemove.h"
#include "sd/include/ADCRuleInstall.h"
#include "sd/include/UsageMonitoringInformation.h"
#include "sd/include/ProxyInfo.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace SD{
typedef enum _tags_ReAuthRequest
{
	ReAuthRequest_SESSIONID	= 0,
	ReAuthRequest_DRMP	= 1,
	ReAuthRequest_AUTHAPPLICATIONID	= 2,
	ReAuthRequest_ORIGINHOST	= 3,
	ReAuthRequest_ORIGINREALM	= 4,
	ReAuthRequest_DESTINATIONREALM	= 5,
	ReAuthRequest_DESTINATIONHOST	= 6,
	ReAuthRequest_REAUTHREQUESTTYPE	= 7,
	ReAuthRequest_SESSIONRELEASECAUSE	= 8,
	ReAuthRequest_ORIGINSTATEID	= 9,
	ReAuthRequest_OCSUPPORTEDFEATURES	= 10,
	ReAuthRequest_QOSINFORMATION	= 11,
	ReAuthRequest_EVENTTRIGGER	= 12,
	ReAuthRequest_CSGINFORMATIONREPORTING	= 13,
	ReAuthRequest_EVENTREPORTINDICATION	= 14,
	ReAuthRequest_ADCRULEREMOVE	= 15,
	ReAuthRequest_ADCRULEINSTALL	= 16,
	ReAuthRequest_REVALIDATIONTIME	= 17,
	ReAuthRequest_USAGEMONITORINGINFORMATION	= 18,
	ReAuthRequest_PROXYINFO	= 19,
	ReAuthRequest_ROUTERECORD	= 20,
}ReAuthRequest_tags;

		//! Class Definition
		/*!		ClassName is ReAuthRequest
		*/
class ReAuthRequest : public DiameterBase 
{
	private:

		bitset<21> mTagsPresent;

		bitset<21> mMandatoryAvpCheckVal;

		bitset<21> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		DRMP*		mDRMP;

		Integer32*		mAuthApplicationId;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		OctetString*		mDestinationRealm;

		OctetString*		mDestinationHost;

		ReAuthRequestType*		mReAuthRequestType;

		SessionReleaseCause*		mSessionReleaseCause;

		Unsigned32*		mOriginStateId;

		list<EventTrigger*>* 		mEventTriggerList;

		list<EventTrigger*>::iterator 		mEventTriggerIterator;

		list<CSGInformationReporting*>* 		mCSGInformationReportingList;

		list<CSGInformationReporting*>::iterator 		mCSGInformationReportingIterator;

		Time*		mRevalidationTime;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;












		OCSupportedFeatures*	mOCSupportedFeaturesGrp;

		QoSInformation*	mQoSInformationGrp;



		EventReportIndication*	mEventReportIndicationGrp;

		list<ADCRuleRemove*>*	mADCRuleRemoveGrpList;
		list<ADCRuleRemove*>::iterator	mADCRuleRemoveGrpIterator;

		list<ADCRuleInstall*>*	mADCRuleInstallGrpList;
		list<ADCRuleInstall*>::iterator	mADCRuleInstallGrpIterator;


		list<UsageMonitoringInformation*>*	mUsageMonitoringInformationGrpList;
		list<UsageMonitoringInformation*>::iterator	mUsageMonitoringInformationGrpIterator;

		list<SD::ProxyInfo*>*	mProxyInfoGrpList;
		list<SD::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		ReAuthRequest();

		ReAuthRequest(const ReAuthRequest &objReAuthRequest) {

		mTagsPresent = objReAuthRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objReAuthRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objReAuthRequest.mMandatoryAvpSetVal;

		mTag = objReAuthRequest.mTag;

		mDecodeFlag = objReAuthRequest.mDecodeFlag;

		if(objReAuthRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objReAuthRequest.mSessionId));

		if(objReAuthRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objReAuthRequest.mDRMP));

		if(objReAuthRequest.mAuthApplicationId != NULL)
		mAuthApplicationId = new Integer32(*(objReAuthRequest.mAuthApplicationId));

		if(objReAuthRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objReAuthRequest.mOriginHost));

		if(objReAuthRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objReAuthRequest.mOriginRealm));

		if(objReAuthRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objReAuthRequest.mDestinationRealm));

		if(objReAuthRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objReAuthRequest.mDestinationHost));

		if(objReAuthRequest.mReAuthRequestType != NULL)
		mReAuthRequestType = new ReAuthRequestType(*(objReAuthRequest.mReAuthRequestType));

		if(objReAuthRequest.mSessionReleaseCause != NULL)
		mSessionReleaseCause = new SessionReleaseCause(*(objReAuthRequest.mSessionReleaseCause));

		if(objReAuthRequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objReAuthRequest.mOriginStateId));

		if(objReAuthRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objReAuthRequest.mOCSupportedFeaturesGrp);
		 }
		if(objReAuthRequest.mQoSInformationGrp != NULL)
		 {
				 mQoSInformationGrp =  new QoSInformation(*objReAuthRequest.mQoSInformationGrp);
		 }
		if(objReAuthRequest.mEventReportIndicationGrp != NULL)
		 {
				 mEventReportIndicationGrp =  new EventReportIndication(*objReAuthRequest.mEventReportIndicationGrp);
		 }
		if(objReAuthRequest.mADCRuleRemoveGrpList != NULL)
		 {
		 mADCRuleRemoveGrpList = new list<ADCRuleRemove*>;
		 for( auto element : *objReAuthRequest.mADCRuleRemoveGrpList)
		 {
				 ADCRuleRemove *lADCRuleRemove =  new ADCRuleRemove(*element);
				 mADCRuleRemoveGrpList->push_back(lADCRuleRemove);
		 }
		 }
		if(objReAuthRequest.mADCRuleInstallGrpList != NULL)
		 {
		 mADCRuleInstallGrpList = new list<ADCRuleInstall*>;
		 for( auto element : *objReAuthRequest.mADCRuleInstallGrpList)
		 {
				 ADCRuleInstall *lADCRuleInstall =  new ADCRuleInstall(*element);
				 mADCRuleInstallGrpList->push_back(lADCRuleInstall);
		 }
		 }
		if(objReAuthRequest.mRevalidationTime != NULL)
		mRevalidationTime = new Time(*(objReAuthRequest.mRevalidationTime));

		if(objReAuthRequest.mUsageMonitoringInformationGrpList != NULL)
		 {
		 mUsageMonitoringInformationGrpList = new list<UsageMonitoringInformation*>;
		 for( auto element : *objReAuthRequest.mUsageMonitoringInformationGrpList)
		 {
				 UsageMonitoringInformation *lUsageMonitoringInformation =  new UsageMonitoringInformation(*element);
				 mUsageMonitoringInformationGrpList->push_back(lUsageMonitoringInformation);
		 }
		 }
		if(objReAuthRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SD::ProxyInfo*>;
		 for( auto element : *objReAuthRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const ReAuthRequest &objReAuthRequest) {

		mTagsPresent = objReAuthRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objReAuthRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objReAuthRequest.mMandatoryAvpSetVal;

		mTag = objReAuthRequest.mTag;

		mDecodeFlag = objReAuthRequest.mDecodeFlag;

		if(objReAuthRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objReAuthRequest.mSessionId));

		if(objReAuthRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objReAuthRequest.mDRMP));

		if(objReAuthRequest.mAuthApplicationId != NULL)
		mAuthApplicationId = new Integer32(*(objReAuthRequest.mAuthApplicationId));

		if(objReAuthRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objReAuthRequest.mOriginHost));

		if(objReAuthRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objReAuthRequest.mOriginRealm));

		if(objReAuthRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objReAuthRequest.mDestinationRealm));

		if(objReAuthRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objReAuthRequest.mDestinationHost));

		if(objReAuthRequest.mReAuthRequestType != NULL)
		mReAuthRequestType = new ReAuthRequestType(*(objReAuthRequest.mReAuthRequestType));

		if(objReAuthRequest.mSessionReleaseCause != NULL)
		mSessionReleaseCause = new SessionReleaseCause(*(objReAuthRequest.mSessionReleaseCause));

		if(objReAuthRequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objReAuthRequest.mOriginStateId));

		if(objReAuthRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objReAuthRequest.mOCSupportedFeaturesGrp);
		 }
		if(objReAuthRequest.mQoSInformationGrp != NULL)
		 {
				 mQoSInformationGrp =  new QoSInformation(*objReAuthRequest.mQoSInformationGrp);
		 }
		if(objReAuthRequest.mEventReportIndicationGrp != NULL)
		 {
				 mEventReportIndicationGrp =  new EventReportIndication(*objReAuthRequest.mEventReportIndicationGrp);
		 }
		if(objReAuthRequest.mADCRuleRemoveGrpList != NULL)
		 {
		 mADCRuleRemoveGrpList = new list<ADCRuleRemove*>;
		 for( auto element : *objReAuthRequest.mADCRuleRemoveGrpList)
		 {
				 ADCRuleRemove *lADCRuleRemove =  new ADCRuleRemove(*element);
				 mADCRuleRemoveGrpList->push_back(lADCRuleRemove);
		 }
		 }
		if(objReAuthRequest.mADCRuleInstallGrpList != NULL)
		 {
		 mADCRuleInstallGrpList = new list<ADCRuleInstall*>;
		 for( auto element : *objReAuthRequest.mADCRuleInstallGrpList)
		 {
				 ADCRuleInstall *lADCRuleInstall =  new ADCRuleInstall(*element);
				 mADCRuleInstallGrpList->push_back(lADCRuleInstall);
		 }
		 }
		if(objReAuthRequest.mRevalidationTime != NULL)
		mRevalidationTime = new Time(*(objReAuthRequest.mRevalidationTime));

		if(objReAuthRequest.mUsageMonitoringInformationGrpList != NULL)
		 {
		 mUsageMonitoringInformationGrpList = new list<UsageMonitoringInformation*>;
		 for( auto element : *objReAuthRequest.mUsageMonitoringInformationGrpList)
		 {
				 UsageMonitoringInformation *lUsageMonitoringInformation =  new UsageMonitoringInformation(*element);
				 mUsageMonitoringInformationGrpList->push_back(lUsageMonitoringInformation);
		 }
		 }
		if(objReAuthRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SD::ProxyInfo*>;
		 for( auto element : *objReAuthRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~ReAuthRequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype ReAuthRequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype ReAuthRequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype ReAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype ReAuthRequest
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype ReAuthRequest
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype ReAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		//!Function to set values
		/*!		Function to set the recent Integer32 type of argument AuthApplicationId for datatype ReAuthRequest
		*/
		Integer32* setAuthApplicationId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthApplicationId for datatype ReAuthRequest
		*/
		void resetAuthApplicationId();

		//!Function to get values
		/*!		Function to get Integer32 type of argument AuthApplicationId for datatype ReAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		Integer32* getAuthApplicationId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype ReAuthRequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype ReAuthRequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype ReAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype ReAuthRequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype ReAuthRequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype ReAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationRealm for datatype ReAuthRequest
		*/
		OctetString* setDestinationRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationRealm for datatype ReAuthRequest
		*/
		void resetDestinationRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationRealm for datatype ReAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationHost for datatype ReAuthRequest
		*/
		OctetString* setDestinationHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationHost for datatype ReAuthRequest
		*/
		void resetDestinationHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationHost for datatype ReAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationHost();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument ReAuthRequestType for datatype ReAuthRequest
		*/
		ReAuthRequestType* setReAuthRequestType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ReAuthRequestType for datatype ReAuthRequest
		*/
		void resetReAuthRequestType();

		//!Function to get values
		/*!		Function to get ReAuthRequestType type of argument ReAuthRequestType for datatype ReAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		ReAuthRequestType* getReAuthRequestType();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument SessionReleaseCause for datatype ReAuthRequest
		*/
		SessionReleaseCause* setSessionReleaseCause();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionReleaseCause for datatype ReAuthRequest
		*/
		void resetSessionReleaseCause();

		//!Function to get values
		/*!		Function to get SessionReleaseCause type of argument SessionReleaseCause for datatype ReAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		SessionReleaseCause* getSessionReleaseCause();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype ReAuthRequest
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype ReAuthRequest
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype ReAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		OCSupportedFeatures* getOCSupportedFeatures();

		OCSupportedFeatures* setOCSupportedFeatures();

		void resetOCSupportedFeatures();

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

		list<ADCRuleRemove*>* getADCRuleRemoveGrpList();

		list<ADCRuleRemove*>* setADCRuleRemoveGrpList();

		void resetADCRuleRemoveGrpList();

		list<ADCRuleInstall*>* getADCRuleInstallGrpList();

		list<ADCRuleInstall*>* setADCRuleInstallGrpList();

		void resetADCRuleInstallGrpList();

		//!Function to set values
		/*!		Function to set the recent Time type of argument RevalidationTime for datatype ReAuthRequest
		*/
		Time* setRevalidationTime();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RevalidationTime for datatype ReAuthRequest
		*/
		void resetRevalidationTime();

		//!Function to get values
		/*!		Function to get Time type of argument RevalidationTime for datatype ReAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		Time* getRevalidationTime();

		list<UsageMonitoringInformation*>* getUsageMonitoringInformationGrpList();

		list<UsageMonitoringInformation*>* setUsageMonitoringInformationGrpList();

		void resetUsageMonitoringInformationGrpList();

		list<SD::ProxyInfo*>* getProxyInfoGrpList();

		list<SD::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		//! Function to Decode
		/*!		Function to Decode datatype ReAuthRequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype ReAuthRequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype ReAuthRequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype ReAuthRequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ReAuthRequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
