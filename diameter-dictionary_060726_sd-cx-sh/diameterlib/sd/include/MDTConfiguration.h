#ifndef SD_MDTCONFIGURATION_H
#define SD_MDTCONFIGURATION_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/JobType.h"
#include "sd/include/AreaScope.h"
#include "sd/include/ReportInterval.h"
#include "sd/include/ReportAmount.h"
#include "sd/include/LoggingInterval.h"
#include "sd/include/LoggingDuration.h"
#include "sd/include/MeasurementPeriodLTE.h"
#include "sd/include/MeasurementPeriodUMTS.h"
#include "sd/include/CollectionPeriodRRMLTE.h"
#include "sd/include/CollectionPeriodRRMUMTS.h"
using namespace std;

namespace SD{
typedef enum _tags_MDTConfiguration
{
	MDTConfiguration_JOBTYPE	= 0,
	MDTConfiguration_AREASCOPE	= 1,
	MDTConfiguration_LISTOFMEASUREMENTS	= 2,
	MDTConfiguration_REPORTINGTRIGGER	= 3,
	MDTConfiguration_REPORTINTERVAL	= 4,
	MDTConfiguration_REPORTAMOUNT	= 5,
	MDTConfiguration_EVENTTHRESHOLDRSRP	= 6,
	MDTConfiguration_EVENTTHRESHOLDRSRQ	= 7,
	MDTConfiguration_LOGGINGINTERVAL	= 8,
	MDTConfiguration_LOGGINGDURATION	= 9,
	MDTConfiguration_MEASUREMENTPERIODLTE	= 10,
	MDTConfiguration_MEASUREMENTPERIODUMTS	= 11,
	MDTConfiguration_COLLECTIONPERIODRRMLTE	= 12,
	MDTConfiguration_COLLECTIONPERIODRRMUMTS	= 13,
	MDTConfiguration_POSITIONINGMETHOD	= 14,
	MDTConfiguration_MEASUREMENTQUANTITY	= 15,
	MDTConfiguration_EVENTTHRESHOLDEVENT1F	= 16,
	MDTConfiguration_EVENTTHRESHOLDEVENT1I	= 17,
}MDTConfiguration_tags;

		//! Class Definition
		/*!		ClassName is MDTConfiguration
		*/
class MDTConfiguration : public DiameterBaseInterface
{
	private:

		bitset<18> mTagsPresent;

		bitset<18> mMandatoryAvpCheckVal;

		bitset<18> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		JobType*		mJobType;

		Unsigned32*		mListOfMeasurements;

		Unsigned32*		mReportingTrigger;

		ReportInterval*		mReportInterval;

		ReportAmount*		mReportAmount;

		Unsigned32*		mEventThresholdRSRP;

		Unsigned32*		mEventThresholdRSRQ;

		LoggingInterval*		mLoggingInterval;

		LoggingDuration*		mLoggingDuration;

		MeasurementPeriodLTE*		mMeasurementPeriodLTE;

		MeasurementPeriodUMTS*		mMeasurementPeriodUMTS;

		CollectionPeriodRRMLTE*		mCollectionPeriodRRMLTE;

		CollectionPeriodRRMUMTS*		mCollectionPeriodRRMUMTS;

		OctetString*		mPositioningMethod;

		OctetString*		mMeasurementQuantity;

		Integer32*		mEventThresholdEvent1F;

		Integer32*		mEventThresholdEvent1I;



		AreaScope*	mAreaScopeGrp;

















	public:
		MDTConfiguration();

		MDTConfiguration(const MDTConfiguration &objMDTConfiguration) {

		mTagsPresent = objMDTConfiguration.mTagsPresent;

		mMandatoryAvpCheckVal = objMDTConfiguration.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objMDTConfiguration.mMandatoryAvpSetVal;

		mTag = objMDTConfiguration.mTag;

		mDecodeFlag = objMDTConfiguration.mDecodeFlag;

		if(objMDTConfiguration.mJobType != NULL)
		mJobType = new JobType(*(objMDTConfiguration.mJobType));

		if(objMDTConfiguration.mAreaScopeGrp != NULL)
		 {
				 mAreaScopeGrp =  new AreaScope(*objMDTConfiguration.mAreaScopeGrp);
		 }
		if(objMDTConfiguration.mListOfMeasurements != NULL)
		mListOfMeasurements = new Unsigned32(*(objMDTConfiguration.mListOfMeasurements));

		if(objMDTConfiguration.mReportingTrigger != NULL)
		mReportingTrigger = new Unsigned32(*(objMDTConfiguration.mReportingTrigger));

		if(objMDTConfiguration.mReportInterval != NULL)
		mReportInterval = new ReportInterval(*(objMDTConfiguration.mReportInterval));

		if(objMDTConfiguration.mReportAmount != NULL)
		mReportAmount = new ReportAmount(*(objMDTConfiguration.mReportAmount));

		if(objMDTConfiguration.mEventThresholdRSRP != NULL)
		mEventThresholdRSRP = new Unsigned32(*(objMDTConfiguration.mEventThresholdRSRP));

		if(objMDTConfiguration.mEventThresholdRSRQ != NULL)
		mEventThresholdRSRQ = new Unsigned32(*(objMDTConfiguration.mEventThresholdRSRQ));

		if(objMDTConfiguration.mLoggingInterval != NULL)
		mLoggingInterval = new LoggingInterval(*(objMDTConfiguration.mLoggingInterval));

		if(objMDTConfiguration.mLoggingDuration != NULL)
		mLoggingDuration = new LoggingDuration(*(objMDTConfiguration.mLoggingDuration));

		if(objMDTConfiguration.mMeasurementPeriodLTE != NULL)
		mMeasurementPeriodLTE = new MeasurementPeriodLTE(*(objMDTConfiguration.mMeasurementPeriodLTE));

		if(objMDTConfiguration.mMeasurementPeriodUMTS != NULL)
		mMeasurementPeriodUMTS = new MeasurementPeriodUMTS(*(objMDTConfiguration.mMeasurementPeriodUMTS));

		if(objMDTConfiguration.mCollectionPeriodRRMLTE != NULL)
		mCollectionPeriodRRMLTE = new CollectionPeriodRRMLTE(*(objMDTConfiguration.mCollectionPeriodRRMLTE));

		if(objMDTConfiguration.mCollectionPeriodRRMUMTS != NULL)
		mCollectionPeriodRRMUMTS = new CollectionPeriodRRMUMTS(*(objMDTConfiguration.mCollectionPeriodRRMUMTS));

		if(objMDTConfiguration.mPositioningMethod != NULL)
		mPositioningMethod = new OctetString(*(objMDTConfiguration.mPositioningMethod));

		if(objMDTConfiguration.mMeasurementQuantity != NULL)
		mMeasurementQuantity = new OctetString(*(objMDTConfiguration.mMeasurementQuantity));

		if(objMDTConfiguration.mEventThresholdEvent1F != NULL)
		mEventThresholdEvent1F = new Integer32(*(objMDTConfiguration.mEventThresholdEvent1F));

		if(objMDTConfiguration.mEventThresholdEvent1I != NULL)
		mEventThresholdEvent1I = new Integer32(*(objMDTConfiguration.mEventThresholdEvent1I));

		}

		void operator = (const MDTConfiguration &objMDTConfiguration) {

		mTagsPresent = objMDTConfiguration.mTagsPresent;

		mMandatoryAvpCheckVal = objMDTConfiguration.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objMDTConfiguration.mMandatoryAvpSetVal;

		mTag = objMDTConfiguration.mTag;

		mDecodeFlag = objMDTConfiguration.mDecodeFlag;

		if(objMDTConfiguration.mJobType != NULL)
		mJobType = new JobType(*(objMDTConfiguration.mJobType));

		if(objMDTConfiguration.mAreaScopeGrp != NULL)
		 {
				 mAreaScopeGrp =  new AreaScope(*objMDTConfiguration.mAreaScopeGrp);
		 }
		if(objMDTConfiguration.mListOfMeasurements != NULL)
		mListOfMeasurements = new Unsigned32(*(objMDTConfiguration.mListOfMeasurements));

		if(objMDTConfiguration.mReportingTrigger != NULL)
		mReportingTrigger = new Unsigned32(*(objMDTConfiguration.mReportingTrigger));

		if(objMDTConfiguration.mReportInterval != NULL)
		mReportInterval = new ReportInterval(*(objMDTConfiguration.mReportInterval));

		if(objMDTConfiguration.mReportAmount != NULL)
		mReportAmount = new ReportAmount(*(objMDTConfiguration.mReportAmount));

		if(objMDTConfiguration.mEventThresholdRSRP != NULL)
		mEventThresholdRSRP = new Unsigned32(*(objMDTConfiguration.mEventThresholdRSRP));

		if(objMDTConfiguration.mEventThresholdRSRQ != NULL)
		mEventThresholdRSRQ = new Unsigned32(*(objMDTConfiguration.mEventThresholdRSRQ));

		if(objMDTConfiguration.mLoggingInterval != NULL)
		mLoggingInterval = new LoggingInterval(*(objMDTConfiguration.mLoggingInterval));

		if(objMDTConfiguration.mLoggingDuration != NULL)
		mLoggingDuration = new LoggingDuration(*(objMDTConfiguration.mLoggingDuration));

		if(objMDTConfiguration.mMeasurementPeriodLTE != NULL)
		mMeasurementPeriodLTE = new MeasurementPeriodLTE(*(objMDTConfiguration.mMeasurementPeriodLTE));

		if(objMDTConfiguration.mMeasurementPeriodUMTS != NULL)
		mMeasurementPeriodUMTS = new MeasurementPeriodUMTS(*(objMDTConfiguration.mMeasurementPeriodUMTS));

		if(objMDTConfiguration.mCollectionPeriodRRMLTE != NULL)
		mCollectionPeriodRRMLTE = new CollectionPeriodRRMLTE(*(objMDTConfiguration.mCollectionPeriodRRMLTE));

		if(objMDTConfiguration.mCollectionPeriodRRMUMTS != NULL)
		mCollectionPeriodRRMUMTS = new CollectionPeriodRRMUMTS(*(objMDTConfiguration.mCollectionPeriodRRMUMTS));

		if(objMDTConfiguration.mPositioningMethod != NULL)
		mPositioningMethod = new OctetString(*(objMDTConfiguration.mPositioningMethod));

		if(objMDTConfiguration.mMeasurementQuantity != NULL)
		mMeasurementQuantity = new OctetString(*(objMDTConfiguration.mMeasurementQuantity));

		if(objMDTConfiguration.mEventThresholdEvent1F != NULL)
		mEventThresholdEvent1F = new Integer32(*(objMDTConfiguration.mEventThresholdEvent1F));

		if(objMDTConfiguration.mEventThresholdEvent1I != NULL)
		mEventThresholdEvent1I = new Integer32(*(objMDTConfiguration.mEventThresholdEvent1I));

		}

		virtual ~MDTConfiguration();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument JobType for datatype MDTConfiguration
		*/
		JobType* setJobType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument JobType for datatype MDTConfiguration
		*/
		void resetJobType();

		//!Function to get values
		/*!		Function to get JobType type of argument JobType for datatype MDTConfiguration
		Throws exception of which type and Summary of Exception
		*/
		JobType* getJobType();

		AreaScope* getAreaScope();

		AreaScope* setAreaScope();

		void resetAreaScope();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ListOfMeasurements for datatype MDTConfiguration
		*/
		Unsigned32* setListOfMeasurements();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ListOfMeasurements for datatype MDTConfiguration
		*/
		void resetListOfMeasurements();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ListOfMeasurements for datatype MDTConfiguration
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getListOfMeasurements();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ReportingTrigger for datatype MDTConfiguration
		*/
		Unsigned32* setReportingTrigger();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ReportingTrigger for datatype MDTConfiguration
		*/
		void resetReportingTrigger();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ReportingTrigger for datatype MDTConfiguration
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getReportingTrigger();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument ReportInterval for datatype MDTConfiguration
		*/
		ReportInterval* setReportInterval();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ReportInterval for datatype MDTConfiguration
		*/
		void resetReportInterval();

		//!Function to get values
		/*!		Function to get ReportInterval type of argument ReportInterval for datatype MDTConfiguration
		Throws exception of which type and Summary of Exception
		*/
		ReportInterval* getReportInterval();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument ReportAmount for datatype MDTConfiguration
		*/
		ReportAmount* setReportAmount();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ReportAmount for datatype MDTConfiguration
		*/
		void resetReportAmount();

		//!Function to get values
		/*!		Function to get ReportAmount type of argument ReportAmount for datatype MDTConfiguration
		Throws exception of which type and Summary of Exception
		*/
		ReportAmount* getReportAmount();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument EventThresholdRSRP for datatype MDTConfiguration
		*/
		Unsigned32* setEventThresholdRSRP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument EventThresholdRSRP for datatype MDTConfiguration
		*/
		void resetEventThresholdRSRP();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument EventThresholdRSRP for datatype MDTConfiguration
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getEventThresholdRSRP();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument EventThresholdRSRQ for datatype MDTConfiguration
		*/
		Unsigned32* setEventThresholdRSRQ();

		//! Function to reset 
		/*!		Function to reset NULL type of argument EventThresholdRSRQ for datatype MDTConfiguration
		*/
		void resetEventThresholdRSRQ();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument EventThresholdRSRQ for datatype MDTConfiguration
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getEventThresholdRSRQ();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument LoggingInterval for datatype MDTConfiguration
		*/
		LoggingInterval* setLoggingInterval();

		//! Function to reset 
		/*!		Function to reset NULL type of argument LoggingInterval for datatype MDTConfiguration
		*/
		void resetLoggingInterval();

		//!Function to get values
		/*!		Function to get LoggingInterval type of argument LoggingInterval for datatype MDTConfiguration
		Throws exception of which type and Summary of Exception
		*/
		LoggingInterval* getLoggingInterval();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument LoggingDuration for datatype MDTConfiguration
		*/
		LoggingDuration* setLoggingDuration();

		//! Function to reset 
		/*!		Function to reset NULL type of argument LoggingDuration for datatype MDTConfiguration
		*/
		void resetLoggingDuration();

		//!Function to get values
		/*!		Function to get LoggingDuration type of argument LoggingDuration for datatype MDTConfiguration
		Throws exception of which type and Summary of Exception
		*/
		LoggingDuration* getLoggingDuration();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument MeasurementPeriodLTE for datatype MDTConfiguration
		*/
		MeasurementPeriodLTE* setMeasurementPeriodLTE();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MeasurementPeriodLTE for datatype MDTConfiguration
		*/
		void resetMeasurementPeriodLTE();

		//!Function to get values
		/*!		Function to get MeasurementPeriodLTE type of argument MeasurementPeriodLTE for datatype MDTConfiguration
		Throws exception of which type and Summary of Exception
		*/
		MeasurementPeriodLTE* getMeasurementPeriodLTE();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument MeasurementPeriodUMTS for datatype MDTConfiguration
		*/
		MeasurementPeriodUMTS* setMeasurementPeriodUMTS();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MeasurementPeriodUMTS for datatype MDTConfiguration
		*/
		void resetMeasurementPeriodUMTS();

		//!Function to get values
		/*!		Function to get MeasurementPeriodUMTS type of argument MeasurementPeriodUMTS for datatype MDTConfiguration
		Throws exception of which type and Summary of Exception
		*/
		MeasurementPeriodUMTS* getMeasurementPeriodUMTS();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument CollectionPeriodRRMLTE for datatype MDTConfiguration
		*/
		CollectionPeriodRRMLTE* setCollectionPeriodRRMLTE();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CollectionPeriodRRMLTE for datatype MDTConfiguration
		*/
		void resetCollectionPeriodRRMLTE();

		//!Function to get values
		/*!		Function to get CollectionPeriodRRMLTE type of argument CollectionPeriodRRMLTE for datatype MDTConfiguration
		Throws exception of which type and Summary of Exception
		*/
		CollectionPeriodRRMLTE* getCollectionPeriodRRMLTE();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument CollectionPeriodRRMUMTS for datatype MDTConfiguration
		*/
		CollectionPeriodRRMUMTS* setCollectionPeriodRRMUMTS();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CollectionPeriodRRMUMTS for datatype MDTConfiguration
		*/
		void resetCollectionPeriodRRMUMTS();

		//!Function to get values
		/*!		Function to get CollectionPeriodRRMUMTS type of argument CollectionPeriodRRMUMTS for datatype MDTConfiguration
		Throws exception of which type and Summary of Exception
		*/
		CollectionPeriodRRMUMTS* getCollectionPeriodRRMUMTS();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument PositioningMethod for datatype MDTConfiguration
		*/
		OctetString* setPositioningMethod();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PositioningMethod for datatype MDTConfiguration
		*/
		void resetPositioningMethod();

		//!Function to get values
		/*!		Function to get OctetString type of argument PositioningMethod for datatype MDTConfiguration
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getPositioningMethod();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument MeasurementQuantity for datatype MDTConfiguration
		*/
		OctetString* setMeasurementQuantity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MeasurementQuantity for datatype MDTConfiguration
		*/
		void resetMeasurementQuantity();

		//!Function to get values
		/*!		Function to get OctetString type of argument MeasurementQuantity for datatype MDTConfiguration
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getMeasurementQuantity();

		//!Function to set values
		/*!		Function to set the recent Integer32 type of argument EventThresholdEvent1F for datatype MDTConfiguration
		*/
		Integer32* setEventThresholdEvent1F();

		//! Function to reset 
		/*!		Function to reset NULL type of argument EventThresholdEvent1F for datatype MDTConfiguration
		*/
		void resetEventThresholdEvent1F();

		//!Function to get values
		/*!		Function to get Integer32 type of argument EventThresholdEvent1F for datatype MDTConfiguration
		Throws exception of which type and Summary of Exception
		*/
		Integer32* getEventThresholdEvent1F();

		//!Function to set values
		/*!		Function to set the recent Integer32 type of argument EventThresholdEvent1I for datatype MDTConfiguration
		*/
		Integer32* setEventThresholdEvent1I();

		//! Function to reset 
		/*!		Function to reset NULL type of argument EventThresholdEvent1I for datatype MDTConfiguration
		*/
		void resetEventThresholdEvent1I();

		//!Function to get values
		/*!		Function to get Integer32 type of argument EventThresholdEvent1I for datatype MDTConfiguration
		Throws exception of which type and Summary of Exception
		*/
		Integer32* getEventThresholdEvent1I();

		//! Function to Decode
		/*!		Function to Decode datatype MDTConfiguration
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype MDTConfiguration
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype MDTConfiguration
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype MDTConfiguration
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype MDTConfiguration
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
