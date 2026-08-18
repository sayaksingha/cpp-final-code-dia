#ifndef SD_CREDITCONTROLREQUEST_H
#define SD_CREDITCONTROLREQUEST_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/DRMP.h"
#include "sd/include/OCSupportedFeatures.h"
#include "sd/include/ADCRuleReport.h"
#include "sd/include/ApplicationDetectionInformation.h"
#include "sd/include/EventTrigger.h"
#include "sd/include/EventReportIndication.h"
#include "sd/include/UsageMonitoringInformation.h"
#include "sd/include/ProxyInfo.h"
#include "sd/include/SupportedFeatures.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace SD{
typedef enum _tags_CreditControlRequest
{
	CreditControlRequest_SESSIONID	= 0,
	CreditControlRequest_DRMP	= 1,
	CreditControlRequest_AUTHAPPLICATIONID	= 2,
	CreditControlRequest_ORIGINHOST	= 3,
	CreditControlRequest_ORIGINREALM	= 4,
	CreditControlRequest_DESTINATIONREALM	= 5,
	CreditControlRequest_OCSUPPORTEDFEATURES	= 6,
	CreditControlRequest_CCREQUESTTYPE	= 7,
	CreditControlRequest_CCREQUESTNUMBER	= 8,
	CreditControlRequest_CREDITMANAGEMENTSTATUS	= 9,
	CreditControlRequest_DESTINATIONHOST	= 10,
	CreditControlRequest_ORIGINSTATEID	= 11,
	CreditControlRequest_FRAMEDIPADDRESS	= 12,
	CreditControlRequest_FRAMEDIPV6PREFIX	= 13,
	CreditControlRequest_ADCRULEREPORT	= 14,
	CreditControlRequest_APPLICATIONDETECTIONINFORMATION	= 15,
	CreditControlRequest_EVENTTRIGGER	= 16,
	CreditControlRequest_EVENTREPORTINDICATION	= 17,
	CreditControlRequest_USAGEMONITORINGINFORMATION	= 18,
	CreditControlRequest_PROXYINFO	= 19,
	CreditControlRequest_ROUTERECORD	= 20,
	CreditControlRequest_SUPPORTEDFEATURES	= 21,
}CreditControlRequest_tags;

		//! Class Definition
		/*!		ClassName is CreditControlRequest
		*/
class CreditControlRequest : public DiameterBase 
{
	private:

		bitset<22> mTagsPresent;

		bitset<22> mMandatoryAvpCheckVal;

		bitset<22> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		DRMP*		mDRMP;

		Integer32*		mAuthApplicationId;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		OctetString*		mDestinationRealm;

		CCRequestType*		mCCRequestType;

		Unsigned32*		mCCRequestNumber;

		Unsigned32*		mCreditManagementStatus;

		OctetString*		mDestinationHost;

		Unsigned32*		mOriginStateId;

		OctetString*		mFramedIPAddress;

		OctetString*		mFramedIPv6Prefix;

		list<EventTrigger*>* 		mEventTriggerList;

		list<EventTrigger*>::iterator 		mEventTriggerIterator;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;








		OCSupportedFeatures*	mOCSupportedFeaturesGrp;








		list<ADCRuleReport*>*	mADCRuleReportGrpList;
		list<ADCRuleReport*>::iterator	mADCRuleReportGrpIterator;

		list<ApplicationDetectionInformation*>*	mApplicationDetectionInformationGrpList;
		list<ApplicationDetectionInformation*>::iterator	mApplicationDetectionInformationGrpIterator;


		EventReportIndication*	mEventReportIndicationGrp;

		list<UsageMonitoringInformation*>*	mUsageMonitoringInformationGrpList;
		list<UsageMonitoringInformation*>::iterator	mUsageMonitoringInformationGrpIterator;

		list<SD::ProxyInfo*>*	mProxyInfoGrpList;
		list<SD::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;

	public:
		CreditControlRequest();

		CreditControlRequest(const CreditControlRequest &objCreditControlRequest) {

		mTagsPresent = objCreditControlRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objCreditControlRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objCreditControlRequest.mMandatoryAvpSetVal;

		mTag = objCreditControlRequest.mTag;

		mDecodeFlag = objCreditControlRequest.mDecodeFlag;

		if(objCreditControlRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objCreditControlRequest.mSessionId));

		if(objCreditControlRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objCreditControlRequest.mDRMP));

		if(objCreditControlRequest.mAuthApplicationId != NULL)
		mAuthApplicationId = new Integer32(*(objCreditControlRequest.mAuthApplicationId));

		if(objCreditControlRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objCreditControlRequest.mOriginHost));

		if(objCreditControlRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objCreditControlRequest.mOriginRealm));

		if(objCreditControlRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objCreditControlRequest.mDestinationRealm));

		if(objCreditControlRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objCreditControlRequest.mOCSupportedFeaturesGrp);
		 }
		if(objCreditControlRequest.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objCreditControlRequest.mCCRequestType));

		if(objCreditControlRequest.mCCRequestNumber != NULL)
		mCCRequestNumber = new Unsigned32(*(objCreditControlRequest.mCCRequestNumber));

		if(objCreditControlRequest.mCreditManagementStatus != NULL)
		mCreditManagementStatus = new Unsigned32(*(objCreditControlRequest.mCreditManagementStatus));

		if(objCreditControlRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objCreditControlRequest.mDestinationHost));

		if(objCreditControlRequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objCreditControlRequest.mOriginStateId));

		if(objCreditControlRequest.mFramedIPAddress != NULL)
		mFramedIPAddress = new OctetString(*(objCreditControlRequest.mFramedIPAddress));

		if(objCreditControlRequest.mFramedIPv6Prefix != NULL)
		mFramedIPv6Prefix = new OctetString(*(objCreditControlRequest.mFramedIPv6Prefix));

		if(objCreditControlRequest.mADCRuleReportGrpList != NULL)
		 {
		 mADCRuleReportGrpList = new list<ADCRuleReport*>;
		 for( auto element : *objCreditControlRequest.mADCRuleReportGrpList)
		 {
				 ADCRuleReport *lADCRuleReport =  new ADCRuleReport(*element);
				 mADCRuleReportGrpList->push_back(lADCRuleReport);
		 }
		 }
		if(objCreditControlRequest.mApplicationDetectionInformationGrpList != NULL)
		 {
		 mApplicationDetectionInformationGrpList = new list<ApplicationDetectionInformation*>;
		 for( auto element : *objCreditControlRequest.mApplicationDetectionInformationGrpList)
		 {
				 ApplicationDetectionInformation *lApplicationDetectionInformation =  new ApplicationDetectionInformation(*element);
				 mApplicationDetectionInformationGrpList->push_back(lApplicationDetectionInformation);
		 }
		 }
		if(objCreditControlRequest.mEventReportIndicationGrp != NULL)
		 {
				 mEventReportIndicationGrp =  new EventReportIndication(*objCreditControlRequest.mEventReportIndicationGrp);
		 }
		if(objCreditControlRequest.mUsageMonitoringInformationGrpList != NULL)
		 {
		 mUsageMonitoringInformationGrpList = new list<UsageMonitoringInformation*>;
		 for( auto element : *objCreditControlRequest.mUsageMonitoringInformationGrpList)
		 {
				 UsageMonitoringInformation *lUsageMonitoringInformation =  new UsageMonitoringInformation(*element);
				 mUsageMonitoringInformationGrpList->push_back(lUsageMonitoringInformation);
		 }
		 }
		if(objCreditControlRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SD::ProxyInfo*>;
		 for( auto element : *objCreditControlRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objCreditControlRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objCreditControlRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		}

		void operator = (const CreditControlRequest &objCreditControlRequest) {

		mTagsPresent = objCreditControlRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objCreditControlRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objCreditControlRequest.mMandatoryAvpSetVal;

		mTag = objCreditControlRequest.mTag;

		mDecodeFlag = objCreditControlRequest.mDecodeFlag;

		if(objCreditControlRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objCreditControlRequest.mSessionId));

		if(objCreditControlRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objCreditControlRequest.mDRMP));

		if(objCreditControlRequest.mAuthApplicationId != NULL)
		mAuthApplicationId = new Integer32(*(objCreditControlRequest.mAuthApplicationId));

		if(objCreditControlRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objCreditControlRequest.mOriginHost));

		if(objCreditControlRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objCreditControlRequest.mOriginRealm));

		if(objCreditControlRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objCreditControlRequest.mDestinationRealm));

		if(objCreditControlRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objCreditControlRequest.mOCSupportedFeaturesGrp);
		 }
		if(objCreditControlRequest.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objCreditControlRequest.mCCRequestType));

		if(objCreditControlRequest.mCCRequestNumber != NULL)
		mCCRequestNumber = new Unsigned32(*(objCreditControlRequest.mCCRequestNumber));

		if(objCreditControlRequest.mCreditManagementStatus != NULL)
		mCreditManagementStatus = new Unsigned32(*(objCreditControlRequest.mCreditManagementStatus));

		if(objCreditControlRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objCreditControlRequest.mDestinationHost));

		if(objCreditControlRequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objCreditControlRequest.mOriginStateId));

		if(objCreditControlRequest.mFramedIPAddress != NULL)
		mFramedIPAddress = new OctetString(*(objCreditControlRequest.mFramedIPAddress));

		if(objCreditControlRequest.mFramedIPv6Prefix != NULL)
		mFramedIPv6Prefix = new OctetString(*(objCreditControlRequest.mFramedIPv6Prefix));

		if(objCreditControlRequest.mADCRuleReportGrpList != NULL)
		 {
		 mADCRuleReportGrpList = new list<ADCRuleReport*>;
		 for( auto element : *objCreditControlRequest.mADCRuleReportGrpList)
		 {
				 ADCRuleReport *lADCRuleReport =  new ADCRuleReport(*element);
				 mADCRuleReportGrpList->push_back(lADCRuleReport);
		 }
		 }
		if(objCreditControlRequest.mApplicationDetectionInformationGrpList != NULL)
		 {
		 mApplicationDetectionInformationGrpList = new list<ApplicationDetectionInformation*>;
		 for( auto element : *objCreditControlRequest.mApplicationDetectionInformationGrpList)
		 {
				 ApplicationDetectionInformation *lApplicationDetectionInformation =  new ApplicationDetectionInformation(*element);
				 mApplicationDetectionInformationGrpList->push_back(lApplicationDetectionInformation);
		 }
		 }
		if(objCreditControlRequest.mEventReportIndicationGrp != NULL)
		 {
				 mEventReportIndicationGrp =  new EventReportIndication(*objCreditControlRequest.mEventReportIndicationGrp);
		 }
		if(objCreditControlRequest.mUsageMonitoringInformationGrpList != NULL)
		 {
		 mUsageMonitoringInformationGrpList = new list<UsageMonitoringInformation*>;
		 for( auto element : *objCreditControlRequest.mUsageMonitoringInformationGrpList)
		 {
				 UsageMonitoringInformation *lUsageMonitoringInformation =  new UsageMonitoringInformation(*element);
				 mUsageMonitoringInformationGrpList->push_back(lUsageMonitoringInformation);
		 }
		 }
		if(objCreditControlRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<SD::ProxyInfo*>;
		 for( auto element : *objCreditControlRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objCreditControlRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objCreditControlRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		}

		virtual ~CreditControlRequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype CreditControlRequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype CreditControlRequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype CreditControlRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype CreditControlRequest
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype CreditControlRequest
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype CreditControlRequest
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		//!Function to set values
		/*!		Function to set the recent Integer32 type of argument AuthApplicationId for datatype CreditControlRequest
		*/
		Integer32* setAuthApplicationId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthApplicationId for datatype CreditControlRequest
		*/
		void resetAuthApplicationId();

		//!Function to get values
		/*!		Function to get Integer32 type of argument AuthApplicationId for datatype CreditControlRequest
		Throws exception of which type and Summary of Exception
		*/
		Integer32* getAuthApplicationId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype CreditControlRequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype CreditControlRequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype CreditControlRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype CreditControlRequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype CreditControlRequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype CreditControlRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationRealm for datatype CreditControlRequest
		*/
		OctetString* setDestinationRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationRealm for datatype CreditControlRequest
		*/
		void resetDestinationRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationRealm for datatype CreditControlRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationRealm();

		OCSupportedFeatures* getOCSupportedFeatures();

		OCSupportedFeatures* setOCSupportedFeatures();

		void resetOCSupportedFeatures();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument CCRequestType for datatype CreditControlRequest
		*/
		CCRequestType* setCCRequestType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCRequestType for datatype CreditControlRequest
		*/
		void resetCCRequestType();

		//!Function to get values
		/*!		Function to get CCRequestType type of argument CCRequestType for datatype CreditControlRequest
		Throws exception of which type and Summary of Exception
		*/
		CCRequestType* getCCRequestType();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument CCRequestNumber for datatype CreditControlRequest
		*/
		Unsigned32* setCCRequestNumber();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCRequestNumber for datatype CreditControlRequest
		*/
		void resetCCRequestNumber();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument CCRequestNumber for datatype CreditControlRequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getCCRequestNumber();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument CreditManagementStatus for datatype CreditControlRequest
		*/
		Unsigned32* setCreditManagementStatus();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CreditManagementStatus for datatype CreditControlRequest
		*/
		void resetCreditManagementStatus();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument CreditManagementStatus for datatype CreditControlRequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getCreditManagementStatus();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationHost for datatype CreditControlRequest
		*/
		OctetString* setDestinationHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationHost for datatype CreditControlRequest
		*/
		void resetDestinationHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationHost for datatype CreditControlRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationHost();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype CreditControlRequest
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype CreditControlRequest
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype CreditControlRequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument FramedIPAddress for datatype CreditControlRequest
		*/
		OctetString* setFramedIPAddress();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FramedIPAddress for datatype CreditControlRequest
		*/
		void resetFramedIPAddress();

		//!Function to get values
		/*!		Function to get OctetString type of argument FramedIPAddress for datatype CreditControlRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getFramedIPAddress();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument FramedIPv6Prefix for datatype CreditControlRequest
		*/
		OctetString* setFramedIPv6Prefix();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FramedIPv6Prefix for datatype CreditControlRequest
		*/
		void resetFramedIPv6Prefix();

		//!Function to get values
		/*!		Function to get OctetString type of argument FramedIPv6Prefix for datatype CreditControlRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getFramedIPv6Prefix();

		list<ADCRuleReport*>* getADCRuleReportGrpList();

		list<ADCRuleReport*>* setADCRuleReportGrpList();

		void resetADCRuleReportGrpList();

		list<ApplicationDetectionInformation*>* getApplicationDetectionInformationGrpList();

		list<ApplicationDetectionInformation*>* setApplicationDetectionInformationGrpList();

		void resetApplicationDetectionInformationGrpList();

		list<EventTrigger*>* getEventTriggerList();

		list<EventTrigger*>* setEventTriggerList();

		void resetEventTriggerList();

		EventReportIndication* getEventReportIndication();

		EventReportIndication* setEventReportIndication();

		void resetEventReportIndication();

		list<UsageMonitoringInformation*>* getUsageMonitoringInformationGrpList();

		list<UsageMonitoringInformation*>* setUsageMonitoringInformationGrpList();

		void resetUsageMonitoringInformationGrpList();

		list<SD::ProxyInfo*>* getProxyInfoGrpList();

		list<SD::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		list<SupportedFeatures*>* getSupportedFeaturesGrpList();

		list<SupportedFeatures*>* setSupportedFeaturesGrpList();

		void resetSupportedFeaturesGrpList();

		//! Function to Decode
		/*!		Function to Decode datatype CreditControlRequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype CreditControlRequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype CreditControlRequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype CreditControlRequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CreditControlRequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
