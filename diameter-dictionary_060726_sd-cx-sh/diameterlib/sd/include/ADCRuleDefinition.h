#ifndef SD_ADCRULEDEFINITION_H
#define SD_ADCRULEDEFINITION_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/FlowInformation.h"
#include "sd/include/ReportingLevel.h"
#include "sd/include/Online.h"
#include "sd/include/Offline.h"
#include "sd/include/MeteringMethod.h"
#include "sd/include/FlowStatus.h"
#include "sd/include/QoSInformation.h"
#include "sd/include/RedirectInformation.h"
#include "sd/include/MuteNotification.h"
using namespace std;

namespace SD{
typedef enum _tags_ADCRuleDefinition
{
	ADCRuleDefinition_ADCRULENAME	= 0,
	ADCRuleDefinition_TDFAPPLICATIONIDENTIFIER	= 1,
	ADCRuleDefinition_FLOWINFORMATION	= 2,
	ADCRuleDefinition_SERVICEIDENTIFIER	= 3,
	ADCRuleDefinition_RATINGGROUP	= 4,
	ADCRuleDefinition_REPORTINGLEVEL	= 5,
	ADCRuleDefinition_ONLINE	= 6,
	ADCRuleDefinition_OFFLINE	= 7,
	ADCRuleDefinition_METERINGMETHOD	= 8,
	ADCRuleDefinition_PRECEDENCE	= 9,
	ADCRuleDefinition_FLOWSTATUS	= 10,
	ADCRuleDefinition_QOSINFORMATION	= 11,
	ADCRuleDefinition_MONITORINGKEY	= 12,
	ADCRuleDefinition_SPONSORIDENTITY	= 13,
	ADCRuleDefinition_APPLICATIONSERVICEPROVIDERIDENTITY	= 14,
	ADCRuleDefinition_REDIRECTINFORMATION	= 15,
	ADCRuleDefinition_MUTENOTIFICATION	= 16,
	ADCRuleDefinition_TRAFFICSTEERINGPOLICYIDENTIFIERDL	= 17,
	ADCRuleDefinition_TRAFFICSTEERINGPOLICYIDENTIFIERUL	= 18,
	ADCRuleDefinition_TOSTRAFFICCLASS	= 19,
}ADCRuleDefinition_tags;

		//! Class Definition
		/*!		ClassName is ADCRuleDefinition
		*/
class ADCRuleDefinition : public DiameterBaseInterface
{
	private:

		bitset<20> mTagsPresent;

		bitset<20> mMandatoryAvpCheckVal;

		bitset<20> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		OctetString*		mADCRuleName;

		OctetString*		mTDFApplicationIdentifier;

		Unsigned32*		mServiceIdentifier;

		Unsigned32*		mRatingGroup;

		ReportingLevel*		mReportingLevel;

		Online*		mOnline;

		Offline*		mOffline;

		MeteringMethod*		mMeteringMethod;

		Unsigned32*		mPrecedence;

		FlowStatus*		mFlowStatus;

		OctetString*		mMonitoringKey;

		OctetString*		mSponsorIdentity;

		OctetString*		mApplicationServiceProviderIdentity;

		MuteNotification*		mMuteNotification;

		OctetString*		mTrafficSteeringPolicyIdentifierDL;

		OctetString*		mTrafficSteeringPolicyIdentifierUL;

		OctetString*		mToSTrafficClass;




		list<FlowInformation*>*	mFlowInformationGrpList;
		list<FlowInformation*>::iterator	mFlowInformationGrpIterator;









		QoSInformation*	mQoSInformationGrp;




		list<RedirectInformation*>*	mRedirectInformationGrpList;
		list<RedirectInformation*>::iterator	mRedirectInformationGrpIterator;





	public:
		ADCRuleDefinition();

		ADCRuleDefinition(const ADCRuleDefinition &objADCRuleDefinition) {

		mTagsPresent = objADCRuleDefinition.mTagsPresent;

		mMandatoryAvpCheckVal = objADCRuleDefinition.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objADCRuleDefinition.mMandatoryAvpSetVal;

		mTag = objADCRuleDefinition.mTag;

		mDecodeFlag = objADCRuleDefinition.mDecodeFlag;

		if(objADCRuleDefinition.mADCRuleName != NULL)
		mADCRuleName = new OctetString(*(objADCRuleDefinition.mADCRuleName));

		if(objADCRuleDefinition.mTDFApplicationIdentifier != NULL)
		mTDFApplicationIdentifier = new OctetString(*(objADCRuleDefinition.mTDFApplicationIdentifier));

		if(objADCRuleDefinition.mFlowInformationGrpList != NULL)
		 {
		 mFlowInformationGrpList = new list<FlowInformation*>;
		 for( auto element : *objADCRuleDefinition.mFlowInformationGrpList)
		 {
				 FlowInformation *lFlowInformation =  new FlowInformation(*element);
				 mFlowInformationGrpList->push_back(lFlowInformation);
		 }
		 }
		if(objADCRuleDefinition.mServiceIdentifier != NULL)
		mServiceIdentifier = new Unsigned32(*(objADCRuleDefinition.mServiceIdentifier));

		if(objADCRuleDefinition.mRatingGroup != NULL)
		mRatingGroup = new Unsigned32(*(objADCRuleDefinition.mRatingGroup));

		if(objADCRuleDefinition.mReportingLevel != NULL)
		mReportingLevel = new ReportingLevel(*(objADCRuleDefinition.mReportingLevel));

		if(objADCRuleDefinition.mOnline != NULL)
		mOnline = new Online(*(objADCRuleDefinition.mOnline));

		if(objADCRuleDefinition.mOffline != NULL)
		mOffline = new Offline(*(objADCRuleDefinition.mOffline));

		if(objADCRuleDefinition.mMeteringMethod != NULL)
		mMeteringMethod = new MeteringMethod(*(objADCRuleDefinition.mMeteringMethod));

		if(objADCRuleDefinition.mPrecedence != NULL)
		mPrecedence = new Unsigned32(*(objADCRuleDefinition.mPrecedence));

		if(objADCRuleDefinition.mFlowStatus != NULL)
		mFlowStatus = new FlowStatus(*(objADCRuleDefinition.mFlowStatus));

		if(objADCRuleDefinition.mQoSInformationGrp != NULL)
		 {
				 mQoSInformationGrp =  new QoSInformation(*objADCRuleDefinition.mQoSInformationGrp);
		 }
		if(objADCRuleDefinition.mMonitoringKey != NULL)
		mMonitoringKey = new OctetString(*(objADCRuleDefinition.mMonitoringKey));

		if(objADCRuleDefinition.mSponsorIdentity != NULL)
		mSponsorIdentity = new OctetString(*(objADCRuleDefinition.mSponsorIdentity));

		if(objADCRuleDefinition.mApplicationServiceProviderIdentity != NULL)
		mApplicationServiceProviderIdentity = new OctetString(*(objADCRuleDefinition.mApplicationServiceProviderIdentity));

		if(objADCRuleDefinition.mRedirectInformationGrpList != NULL)
		 {
		 mRedirectInformationGrpList = new list<RedirectInformation*>;
		 for( auto element : *objADCRuleDefinition.mRedirectInformationGrpList)
		 {
				 RedirectInformation *lRedirectInformation =  new RedirectInformation(*element);
				 mRedirectInformationGrpList->push_back(lRedirectInformation);
		 }
		 }
		if(objADCRuleDefinition.mMuteNotification != NULL)
		mMuteNotification = new MuteNotification(*(objADCRuleDefinition.mMuteNotification));

		if(objADCRuleDefinition.mTrafficSteeringPolicyIdentifierDL != NULL)
		mTrafficSteeringPolicyIdentifierDL = new OctetString(*(objADCRuleDefinition.mTrafficSteeringPolicyIdentifierDL));

		if(objADCRuleDefinition.mTrafficSteeringPolicyIdentifierUL != NULL)
		mTrafficSteeringPolicyIdentifierUL = new OctetString(*(objADCRuleDefinition.mTrafficSteeringPolicyIdentifierUL));

		if(objADCRuleDefinition.mToSTrafficClass != NULL)
		mToSTrafficClass = new OctetString(*(objADCRuleDefinition.mToSTrafficClass));

		}

		void operator = (const ADCRuleDefinition &objADCRuleDefinition) {

		mTagsPresent = objADCRuleDefinition.mTagsPresent;

		mMandatoryAvpCheckVal = objADCRuleDefinition.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objADCRuleDefinition.mMandatoryAvpSetVal;

		mTag = objADCRuleDefinition.mTag;

		mDecodeFlag = objADCRuleDefinition.mDecodeFlag;

		if(objADCRuleDefinition.mADCRuleName != NULL)
		mADCRuleName = new OctetString(*(objADCRuleDefinition.mADCRuleName));

		if(objADCRuleDefinition.mTDFApplicationIdentifier != NULL)
		mTDFApplicationIdentifier = new OctetString(*(objADCRuleDefinition.mTDFApplicationIdentifier));

		if(objADCRuleDefinition.mFlowInformationGrpList != NULL)
		 {
		 mFlowInformationGrpList = new list<FlowInformation*>;
		 for( auto element : *objADCRuleDefinition.mFlowInformationGrpList)
		 {
				 FlowInformation *lFlowInformation =  new FlowInformation(*element);
				 mFlowInformationGrpList->push_back(lFlowInformation);
		 }
		 }
		if(objADCRuleDefinition.mServiceIdentifier != NULL)
		mServiceIdentifier = new Unsigned32(*(objADCRuleDefinition.mServiceIdentifier));

		if(objADCRuleDefinition.mRatingGroup != NULL)
		mRatingGroup = new Unsigned32(*(objADCRuleDefinition.mRatingGroup));

		if(objADCRuleDefinition.mReportingLevel != NULL)
		mReportingLevel = new ReportingLevel(*(objADCRuleDefinition.mReportingLevel));

		if(objADCRuleDefinition.mOnline != NULL)
		mOnline = new Online(*(objADCRuleDefinition.mOnline));

		if(objADCRuleDefinition.mOffline != NULL)
		mOffline = new Offline(*(objADCRuleDefinition.mOffline));

		if(objADCRuleDefinition.mMeteringMethod != NULL)
		mMeteringMethod = new MeteringMethod(*(objADCRuleDefinition.mMeteringMethod));

		if(objADCRuleDefinition.mPrecedence != NULL)
		mPrecedence = new Unsigned32(*(objADCRuleDefinition.mPrecedence));

		if(objADCRuleDefinition.mFlowStatus != NULL)
		mFlowStatus = new FlowStatus(*(objADCRuleDefinition.mFlowStatus));

		if(objADCRuleDefinition.mQoSInformationGrp != NULL)
		 {
				 mQoSInformationGrp =  new QoSInformation(*objADCRuleDefinition.mQoSInformationGrp);
		 }
		if(objADCRuleDefinition.mMonitoringKey != NULL)
		mMonitoringKey = new OctetString(*(objADCRuleDefinition.mMonitoringKey));

		if(objADCRuleDefinition.mSponsorIdentity != NULL)
		mSponsorIdentity = new OctetString(*(objADCRuleDefinition.mSponsorIdentity));

		if(objADCRuleDefinition.mApplicationServiceProviderIdentity != NULL)
		mApplicationServiceProviderIdentity = new OctetString(*(objADCRuleDefinition.mApplicationServiceProviderIdentity));

		if(objADCRuleDefinition.mRedirectInformationGrpList != NULL)
		 {
		 mRedirectInformationGrpList = new list<RedirectInformation*>;
		 for( auto element : *objADCRuleDefinition.mRedirectInformationGrpList)
		 {
				 RedirectInformation *lRedirectInformation =  new RedirectInformation(*element);
				 mRedirectInformationGrpList->push_back(lRedirectInformation);
		 }
		 }
		if(objADCRuleDefinition.mMuteNotification != NULL)
		mMuteNotification = new MuteNotification(*(objADCRuleDefinition.mMuteNotification));

		if(objADCRuleDefinition.mTrafficSteeringPolicyIdentifierDL != NULL)
		mTrafficSteeringPolicyIdentifierDL = new OctetString(*(objADCRuleDefinition.mTrafficSteeringPolicyIdentifierDL));

		if(objADCRuleDefinition.mTrafficSteeringPolicyIdentifierUL != NULL)
		mTrafficSteeringPolicyIdentifierUL = new OctetString(*(objADCRuleDefinition.mTrafficSteeringPolicyIdentifierUL));

		if(objADCRuleDefinition.mToSTrafficClass != NULL)
		mToSTrafficClass = new OctetString(*(objADCRuleDefinition.mToSTrafficClass));

		}

		virtual ~ADCRuleDefinition();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ADCRuleName for datatype ADCRuleDefinition
		*/
		OctetString* setADCRuleName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ADCRuleName for datatype ADCRuleDefinition
		*/
		void resetADCRuleName();

		//!Function to get values
		/*!		Function to get OctetString type of argument ADCRuleName for datatype ADCRuleDefinition
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getADCRuleName();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument TDFApplicationIdentifier for datatype ADCRuleDefinition
		*/
		OctetString* setTDFApplicationIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument TDFApplicationIdentifier for datatype ADCRuleDefinition
		*/
		void resetTDFApplicationIdentifier();

		//!Function to get values
		/*!		Function to get OctetString type of argument TDFApplicationIdentifier for datatype ADCRuleDefinition
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getTDFApplicationIdentifier();

		list<FlowInformation*>* getFlowInformationGrpList();

		list<FlowInformation*>* setFlowInformationGrpList();

		void resetFlowInformationGrpList();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ServiceIdentifier for datatype ADCRuleDefinition
		*/
		Unsigned32* setServiceIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ServiceIdentifier for datatype ADCRuleDefinition
		*/
		void resetServiceIdentifier();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ServiceIdentifier for datatype ADCRuleDefinition
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getServiceIdentifier();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument RatingGroup for datatype ADCRuleDefinition
		*/
		Unsigned32* setRatingGroup();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RatingGroup for datatype ADCRuleDefinition
		*/
		void resetRatingGroup();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument RatingGroup for datatype ADCRuleDefinition
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getRatingGroup();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument ReportingLevel for datatype ADCRuleDefinition
		*/
		ReportingLevel* setReportingLevel();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ReportingLevel for datatype ADCRuleDefinition
		*/
		void resetReportingLevel();

		//!Function to get values
		/*!		Function to get ReportingLevel type of argument ReportingLevel for datatype ADCRuleDefinition
		Throws exception of which type and Summary of Exception
		*/
		ReportingLevel* getReportingLevel();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument Online for datatype ADCRuleDefinition
		*/
		Online* setOnline();

		//! Function to reset 
		/*!		Function to reset NULL type of argument Online for datatype ADCRuleDefinition
		*/
		void resetOnline();

		//!Function to get values
		/*!		Function to get Online type of argument Online for datatype ADCRuleDefinition
		Throws exception of which type and Summary of Exception
		*/
		Online* getOnline();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument Offline for datatype ADCRuleDefinition
		*/
		Offline* setOffline();

		//! Function to reset 
		/*!		Function to reset NULL type of argument Offline for datatype ADCRuleDefinition
		*/
		void resetOffline();

		//!Function to get values
		/*!		Function to get Offline type of argument Offline for datatype ADCRuleDefinition
		Throws exception of which type and Summary of Exception
		*/
		Offline* getOffline();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument MeteringMethod for datatype ADCRuleDefinition
		*/
		MeteringMethod* setMeteringMethod();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MeteringMethod for datatype ADCRuleDefinition
		*/
		void resetMeteringMethod();

		//!Function to get values
		/*!		Function to get MeteringMethod type of argument MeteringMethod for datatype ADCRuleDefinition
		Throws exception of which type and Summary of Exception
		*/
		MeteringMethod* getMeteringMethod();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument Precedence for datatype ADCRuleDefinition
		*/
		Unsigned32* setPrecedence();

		//! Function to reset 
		/*!		Function to reset NULL type of argument Precedence for datatype ADCRuleDefinition
		*/
		void resetPrecedence();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument Precedence for datatype ADCRuleDefinition
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getPrecedence();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument FlowStatus for datatype ADCRuleDefinition
		*/
		FlowStatus* setFlowStatus();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FlowStatus for datatype ADCRuleDefinition
		*/
		void resetFlowStatus();

		//!Function to get values
		/*!		Function to get FlowStatus type of argument FlowStatus for datatype ADCRuleDefinition
		Throws exception of which type and Summary of Exception
		*/
		FlowStatus* getFlowStatus();

		QoSInformation* getQoSInformation();

		QoSInformation* setQoSInformation();

		void resetQoSInformation();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument MonitoringKey for datatype ADCRuleDefinition
		*/
		OctetString* setMonitoringKey();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MonitoringKey for datatype ADCRuleDefinition
		*/
		void resetMonitoringKey();

		//!Function to get values
		/*!		Function to get OctetString type of argument MonitoringKey for datatype ADCRuleDefinition
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getMonitoringKey();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SponsorIdentity for datatype ADCRuleDefinition
		*/
		OctetString* setSponsorIdentity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SponsorIdentity for datatype ADCRuleDefinition
		*/
		void resetSponsorIdentity();

		//!Function to get values
		/*!		Function to get OctetString type of argument SponsorIdentity for datatype ADCRuleDefinition
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSponsorIdentity();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ApplicationServiceProviderIdentity for datatype ADCRuleDefinition
		*/
		OctetString* setApplicationServiceProviderIdentity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ApplicationServiceProviderIdentity for datatype ADCRuleDefinition
		*/
		void resetApplicationServiceProviderIdentity();

		//!Function to get values
		/*!		Function to get OctetString type of argument ApplicationServiceProviderIdentity for datatype ADCRuleDefinition
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getApplicationServiceProviderIdentity();

		list<RedirectInformation*>* getRedirectInformationGrpList();

		list<RedirectInformation*>* setRedirectInformationGrpList();

		void resetRedirectInformationGrpList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument MuteNotification for datatype ADCRuleDefinition
		*/
		MuteNotification* setMuteNotification();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MuteNotification for datatype ADCRuleDefinition
		*/
		void resetMuteNotification();

		//!Function to get values
		/*!		Function to get MuteNotification type of argument MuteNotification for datatype ADCRuleDefinition
		Throws exception of which type and Summary of Exception
		*/
		MuteNotification* getMuteNotification();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument TrafficSteeringPolicyIdentifierDL for datatype ADCRuleDefinition
		*/
		OctetString* setTrafficSteeringPolicyIdentifierDL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument TrafficSteeringPolicyIdentifierDL for datatype ADCRuleDefinition
		*/
		void resetTrafficSteeringPolicyIdentifierDL();

		//!Function to get values
		/*!		Function to get OctetString type of argument TrafficSteeringPolicyIdentifierDL for datatype ADCRuleDefinition
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getTrafficSteeringPolicyIdentifierDL();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument TrafficSteeringPolicyIdentifierUL for datatype ADCRuleDefinition
		*/
		OctetString* setTrafficSteeringPolicyIdentifierUL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument TrafficSteeringPolicyIdentifierUL for datatype ADCRuleDefinition
		*/
		void resetTrafficSteeringPolicyIdentifierUL();

		//!Function to get values
		/*!		Function to get OctetString type of argument TrafficSteeringPolicyIdentifierUL for datatype ADCRuleDefinition
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getTrafficSteeringPolicyIdentifierUL();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ToSTrafficClass for datatype ADCRuleDefinition
		*/
		OctetString* setToSTrafficClass();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ToSTrafficClass for datatype ADCRuleDefinition
		*/
		void resetToSTrafficClass();

		//!Function to get values
		/*!		Function to get OctetString type of argument ToSTrafficClass for datatype ADCRuleDefinition
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getToSTrafficClass();

		//! Function to Decode
		/*!		Function to Decode datatype ADCRuleDefinition
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype ADCRuleDefinition
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype ADCRuleDefinition
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype ADCRuleDefinition
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ADCRuleDefinition
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
