#include "sd/include/MDTConfiguration.h"

using namespace SD;
BOOLEAN MDTConfiguration::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

MDTConfiguration::MDTConfiguration()
{
	mJobType = NULL;
	mAreaScopeGrp = NULL;
	mListOfMeasurements = NULL;
	mReportingTrigger = NULL;
	mReportInterval = NULL;
	mReportAmount = NULL;
	mEventThresholdRSRP = NULL;
	mEventThresholdRSRQ = NULL;
	mLoggingInterval = NULL;
	mLoggingDuration = NULL;
	mMeasurementPeriodLTE = NULL;
	mMeasurementPeriodUMTS = NULL;
	mCollectionPeriodRRMLTE = NULL;
	mCollectionPeriodRRMUMTS = NULL;
	mPositioningMethod = NULL;
	mMeasurementQuantity = NULL;
	mEventThresholdEvent1F = NULL;
	mEventThresholdEvent1I = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<18>(string("000000000000000001"));
	mMandatoryAvpSetVal.reset();
}

MDTConfiguration::~MDTConfiguration()
{
	if(mJobType != NULL)
		delete mJobType;
	if(mAreaScopeGrp != NULL)
		delete mAreaScopeGrp;
	if(mListOfMeasurements != NULL)
		delete mListOfMeasurements;
	if(mReportingTrigger != NULL)
		delete mReportingTrigger;
	if(mReportInterval != NULL)
		delete mReportInterval;
	if(mReportAmount != NULL)
		delete mReportAmount;
	if(mEventThresholdRSRP != NULL)
		delete mEventThresholdRSRP;
	if(mEventThresholdRSRQ != NULL)
		delete mEventThresholdRSRQ;
	if(mLoggingInterval != NULL)
		delete mLoggingInterval;
	if(mLoggingDuration != NULL)
		delete mLoggingDuration;
	if(mMeasurementPeriodLTE != NULL)
		delete mMeasurementPeriodLTE;
	if(mMeasurementPeriodUMTS != NULL)
		delete mMeasurementPeriodUMTS;
	if(mCollectionPeriodRRMLTE != NULL)
		delete mCollectionPeriodRRMLTE;
	if(mCollectionPeriodRRMUMTS != NULL)
		delete mCollectionPeriodRRMUMTS;
	if(mPositioningMethod != NULL)
		delete mPositioningMethod;
	if(mMeasurementQuantity != NULL)
		delete mMeasurementQuantity;
	if(mEventThresholdEvent1F != NULL)
		delete mEventThresholdEvent1F;
	if(mEventThresholdEvent1I != NULL)
		delete mEventThresholdEvent1I;
}

JobType* MDTConfiguration::setJobType(){
	mMandatoryAvpSetVal [MDTConfiguration_JOBTYPE] = 1;
	if(mJobType == NULL)
	{
		mJobType = new JobType();
		mTagsPresent[MDTConfiguration_JOBTYPE] = 1;
		return mJobType;
	}
	return mJobType;
}

void MDTConfiguration::resetJobType(){
	mTagsPresent[MDTConfiguration_JOBTYPE] = 0;
	if(mJobType != NULL)
	{
		delete mJobType; 
		mJobType = NULL;
	}
}

Unsigned32* MDTConfiguration::setListOfMeasurements(){
	if(mListOfMeasurements == NULL)
	{
		mListOfMeasurements = new Unsigned32();
		mTagsPresent[MDTConfiguration_LISTOFMEASUREMENTS] = 1;
		return mListOfMeasurements;
	}
	return mListOfMeasurements;
}

void MDTConfiguration::resetListOfMeasurements(){
	mTagsPresent[MDTConfiguration_LISTOFMEASUREMENTS] = 0;
	if(mListOfMeasurements != NULL)
	{
		delete mListOfMeasurements; 
		mListOfMeasurements = NULL;
	}
}

Unsigned32* MDTConfiguration::setReportingTrigger(){
	if(mReportingTrigger == NULL)
	{
		mReportingTrigger = new Unsigned32();
		mTagsPresent[MDTConfiguration_REPORTINGTRIGGER] = 1;
		return mReportingTrigger;
	}
	return mReportingTrigger;
}

void MDTConfiguration::resetReportingTrigger(){
	mTagsPresent[MDTConfiguration_REPORTINGTRIGGER] = 0;
	if(mReportingTrigger != NULL)
	{
		delete mReportingTrigger; 
		mReportingTrigger = NULL;
	}
}

ReportInterval* MDTConfiguration::setReportInterval(){
	if(mReportInterval == NULL)
	{
		mReportInterval = new ReportInterval();
		mTagsPresent[MDTConfiguration_REPORTINTERVAL] = 1;
		return mReportInterval;
	}
	return mReportInterval;
}

void MDTConfiguration::resetReportInterval(){
	mTagsPresent[MDTConfiguration_REPORTINTERVAL] = 0;
	if(mReportInterval != NULL)
	{
		delete mReportInterval; 
		mReportInterval = NULL;
	}
}

ReportAmount* MDTConfiguration::setReportAmount(){
	if(mReportAmount == NULL)
	{
		mReportAmount = new ReportAmount();
		mTagsPresent[MDTConfiguration_REPORTAMOUNT] = 1;
		return mReportAmount;
	}
	return mReportAmount;
}

void MDTConfiguration::resetReportAmount(){
	mTagsPresent[MDTConfiguration_REPORTAMOUNT] = 0;
	if(mReportAmount != NULL)
	{
		delete mReportAmount; 
		mReportAmount = NULL;
	}
}

Unsigned32* MDTConfiguration::setEventThresholdRSRP(){
	if(mEventThresholdRSRP == NULL)
	{
		mEventThresholdRSRP = new Unsigned32();
		mTagsPresent[MDTConfiguration_EVENTTHRESHOLDRSRP] = 1;
		return mEventThresholdRSRP;
	}
	return mEventThresholdRSRP;
}

void MDTConfiguration::resetEventThresholdRSRP(){
	mTagsPresent[MDTConfiguration_EVENTTHRESHOLDRSRP] = 0;
	if(mEventThresholdRSRP != NULL)
	{
		delete mEventThresholdRSRP; 
		mEventThresholdRSRP = NULL;
	}
}

Unsigned32* MDTConfiguration::setEventThresholdRSRQ(){
	if(mEventThresholdRSRQ == NULL)
	{
		mEventThresholdRSRQ = new Unsigned32();
		mTagsPresent[MDTConfiguration_EVENTTHRESHOLDRSRQ] = 1;
		return mEventThresholdRSRQ;
	}
	return mEventThresholdRSRQ;
}

void MDTConfiguration::resetEventThresholdRSRQ(){
	mTagsPresent[MDTConfiguration_EVENTTHRESHOLDRSRQ] = 0;
	if(mEventThresholdRSRQ != NULL)
	{
		delete mEventThresholdRSRQ; 
		mEventThresholdRSRQ = NULL;
	}
}

LoggingInterval* MDTConfiguration::setLoggingInterval(){
	if(mLoggingInterval == NULL)
	{
		mLoggingInterval = new LoggingInterval();
		mTagsPresent[MDTConfiguration_LOGGINGINTERVAL] = 1;
		return mLoggingInterval;
	}
	return mLoggingInterval;
}

void MDTConfiguration::resetLoggingInterval(){
	mTagsPresent[MDTConfiguration_LOGGINGINTERVAL] = 0;
	if(mLoggingInterval != NULL)
	{
		delete mLoggingInterval; 
		mLoggingInterval = NULL;
	}
}

LoggingDuration* MDTConfiguration::setLoggingDuration(){
	if(mLoggingDuration == NULL)
	{
		mLoggingDuration = new LoggingDuration();
		mTagsPresent[MDTConfiguration_LOGGINGDURATION] = 1;
		return mLoggingDuration;
	}
	return mLoggingDuration;
}

void MDTConfiguration::resetLoggingDuration(){
	mTagsPresent[MDTConfiguration_LOGGINGDURATION] = 0;
	if(mLoggingDuration != NULL)
	{
		delete mLoggingDuration; 
		mLoggingDuration = NULL;
	}
}

MeasurementPeriodLTE* MDTConfiguration::setMeasurementPeriodLTE(){
	if(mMeasurementPeriodLTE == NULL)
	{
		mMeasurementPeriodLTE = new MeasurementPeriodLTE();
		mTagsPresent[MDTConfiguration_MEASUREMENTPERIODLTE] = 1;
		return mMeasurementPeriodLTE;
	}
	return mMeasurementPeriodLTE;
}

void MDTConfiguration::resetMeasurementPeriodLTE(){
	mTagsPresent[MDTConfiguration_MEASUREMENTPERIODLTE] = 0;
	if(mMeasurementPeriodLTE != NULL)
	{
		delete mMeasurementPeriodLTE; 
		mMeasurementPeriodLTE = NULL;
	}
}

MeasurementPeriodUMTS* MDTConfiguration::setMeasurementPeriodUMTS(){
	if(mMeasurementPeriodUMTS == NULL)
	{
		mMeasurementPeriodUMTS = new MeasurementPeriodUMTS();
		mTagsPresent[MDTConfiguration_MEASUREMENTPERIODUMTS] = 1;
		return mMeasurementPeriodUMTS;
	}
	return mMeasurementPeriodUMTS;
}

void MDTConfiguration::resetMeasurementPeriodUMTS(){
	mTagsPresent[MDTConfiguration_MEASUREMENTPERIODUMTS] = 0;
	if(mMeasurementPeriodUMTS != NULL)
	{
		delete mMeasurementPeriodUMTS; 
		mMeasurementPeriodUMTS = NULL;
	}
}

CollectionPeriodRRMLTE* MDTConfiguration::setCollectionPeriodRRMLTE(){
	if(mCollectionPeriodRRMLTE == NULL)
	{
		mCollectionPeriodRRMLTE = new CollectionPeriodRRMLTE();
		mTagsPresent[MDTConfiguration_COLLECTIONPERIODRRMLTE] = 1;
		return mCollectionPeriodRRMLTE;
	}
	return mCollectionPeriodRRMLTE;
}

void MDTConfiguration::resetCollectionPeriodRRMLTE(){
	mTagsPresent[MDTConfiguration_COLLECTIONPERIODRRMLTE] = 0;
	if(mCollectionPeriodRRMLTE != NULL)
	{
		delete mCollectionPeriodRRMLTE; 
		mCollectionPeriodRRMLTE = NULL;
	}
}

CollectionPeriodRRMUMTS* MDTConfiguration::setCollectionPeriodRRMUMTS(){
	if(mCollectionPeriodRRMUMTS == NULL)
	{
		mCollectionPeriodRRMUMTS = new CollectionPeriodRRMUMTS();
		mTagsPresent[MDTConfiguration_COLLECTIONPERIODRRMUMTS] = 1;
		return mCollectionPeriodRRMUMTS;
	}
	return mCollectionPeriodRRMUMTS;
}

void MDTConfiguration::resetCollectionPeriodRRMUMTS(){
	mTagsPresent[MDTConfiguration_COLLECTIONPERIODRRMUMTS] = 0;
	if(mCollectionPeriodRRMUMTS != NULL)
	{
		delete mCollectionPeriodRRMUMTS; 
		mCollectionPeriodRRMUMTS = NULL;
	}
}

OctetString* MDTConfiguration::setPositioningMethod(){
	if(mPositioningMethod == NULL)
	{
		mPositioningMethod = new OctetString();
		mTagsPresent[MDTConfiguration_POSITIONINGMETHOD] = 1;
		return mPositioningMethod;
	}
	return mPositioningMethod;
}

void MDTConfiguration::resetPositioningMethod(){
	mTagsPresent[MDTConfiguration_POSITIONINGMETHOD] = 0;
	if(mPositioningMethod != NULL)
	{
		delete mPositioningMethod; 
		mPositioningMethod = NULL;
	}
}

OctetString* MDTConfiguration::setMeasurementQuantity(){
	if(mMeasurementQuantity == NULL)
	{
		mMeasurementQuantity = new OctetString();
		mTagsPresent[MDTConfiguration_MEASUREMENTQUANTITY] = 1;
		return mMeasurementQuantity;
	}
	return mMeasurementQuantity;
}

void MDTConfiguration::resetMeasurementQuantity(){
	mTagsPresent[MDTConfiguration_MEASUREMENTQUANTITY] = 0;
	if(mMeasurementQuantity != NULL)
	{
		delete mMeasurementQuantity; 
		mMeasurementQuantity = NULL;
	}
}

Integer32* MDTConfiguration::setEventThresholdEvent1F(){
	if(mEventThresholdEvent1F == NULL)
	{
		mEventThresholdEvent1F = new Integer32();
		mTagsPresent[MDTConfiguration_EVENTTHRESHOLDEVENT1F] = 1;
		return mEventThresholdEvent1F;
	}
	return mEventThresholdEvent1F;
}

void MDTConfiguration::resetEventThresholdEvent1F(){
	mTagsPresent[MDTConfiguration_EVENTTHRESHOLDEVENT1F] = 0;
	if(mEventThresholdEvent1F != NULL)
	{
		delete mEventThresholdEvent1F; 
		mEventThresholdEvent1F = NULL;
	}
}

Integer32* MDTConfiguration::setEventThresholdEvent1I(){
	if(mEventThresholdEvent1I == NULL)
	{
		mEventThresholdEvent1I = new Integer32();
		mTagsPresent[MDTConfiguration_EVENTTHRESHOLDEVENT1I] = 1;
		return mEventThresholdEvent1I;
	}
	return mEventThresholdEvent1I;
}

void MDTConfiguration::resetEventThresholdEvent1I(){
	mTagsPresent[MDTConfiguration_EVENTTHRESHOLDEVENT1I] = 0;
	if(mEventThresholdEvent1I != NULL)
	{
		delete mEventThresholdEvent1I; 
		mEventThresholdEvent1I = NULL;
	}
}

JobType* MDTConfiguration::getJobType(){
	if(NULL == mJobType) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "JobType is Null");
		throw lTssDiaMsgException;
	}
	if(!mJobType->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mJobType->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "JobType is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mJobType->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mJobType->Decode(mspByteArray.get(), mJobType->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding JobType")     ;
			throw lTssDiaMsgException;
		}
		mJobType->mAvpDecodedFlag = true;
	}
	return mJobType;
}

AreaScope* MDTConfiguration::getAreaScope()
{
	if(mAreaScopeGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AreaScope is Null");
		throw lTssDiaMsgException;
	}
	if(!mAreaScopeGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAreaScopeGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AreaScope is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAreaScopeGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAreaScopeGrp->Decode(mspByteArray.get(), mAreaScopeGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AreaScope")     ;
			throw lTssDiaMsgException;
		}
		mAreaScopeGrp->mAvpDecodedFlag = true;
	}
	return mAreaScopeGrp;
}

AreaScope* MDTConfiguration::setAreaScope(){
	if(mAreaScopeGrp == NULL)
		mAreaScopeGrp = new AreaScope();
	mTagsPresent[MDTConfiguration_AREASCOPE] = 1;
	return mAreaScopeGrp;
}

void MDTConfiguration::resetAreaScope(){
	mTagsPresent[MDTConfiguration_AREASCOPE] = 0;
	if(mAreaScopeGrp != NULL)
		delete mAreaScopeGrp;
}

Unsigned32* MDTConfiguration::getListOfMeasurements(){
	if(NULL == mListOfMeasurements) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ListOfMeasurements is Null");
		throw lTssDiaMsgException;
	}
	if(!mListOfMeasurements->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mListOfMeasurements->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ListOfMeasurements is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mListOfMeasurements->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mListOfMeasurements->Decode(mspByteArray.get(), mListOfMeasurements->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ListOfMeasurements")     ;
			throw lTssDiaMsgException;
		}
		mListOfMeasurements->mAvpDecodedFlag = true;
	}
	return mListOfMeasurements;
}

Unsigned32* MDTConfiguration::getReportingTrigger(){
	if(NULL == mReportingTrigger) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ReportingTrigger is Null");
		throw lTssDiaMsgException;
	}
	if(!mReportingTrigger->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mReportingTrigger->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ReportingTrigger is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mReportingTrigger->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mReportingTrigger->Decode(mspByteArray.get(), mReportingTrigger->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ReportingTrigger")     ;
			throw lTssDiaMsgException;
		}
		mReportingTrigger->mAvpDecodedFlag = true;
	}
	return mReportingTrigger;
}

ReportInterval* MDTConfiguration::getReportInterval(){
	if(NULL == mReportInterval) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ReportInterval is Null");
		throw lTssDiaMsgException;
	}
	if(!mReportInterval->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mReportInterval->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ReportInterval is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mReportInterval->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mReportInterval->Decode(mspByteArray.get(), mReportInterval->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ReportInterval")     ;
			throw lTssDiaMsgException;
		}
		mReportInterval->mAvpDecodedFlag = true;
	}
	return mReportInterval;
}

ReportAmount* MDTConfiguration::getReportAmount(){
	if(NULL == mReportAmount) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ReportAmount is Null");
		throw lTssDiaMsgException;
	}
	if(!mReportAmount->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mReportAmount->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ReportAmount is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mReportAmount->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mReportAmount->Decode(mspByteArray.get(), mReportAmount->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ReportAmount")     ;
			throw lTssDiaMsgException;
		}
		mReportAmount->mAvpDecodedFlag = true;
	}
	return mReportAmount;
}

Unsigned32* MDTConfiguration::getEventThresholdRSRP(){
	if(NULL == mEventThresholdRSRP) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "EventThresholdRSRP is Null");
		throw lTssDiaMsgException;
	}
	if(!mEventThresholdRSRP->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mEventThresholdRSRP->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "EventThresholdRSRP is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mEventThresholdRSRP->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mEventThresholdRSRP->Decode(mspByteArray.get(), mEventThresholdRSRP->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding EventThresholdRSRP")     ;
			throw lTssDiaMsgException;
		}
		mEventThresholdRSRP->mAvpDecodedFlag = true;
	}
	return mEventThresholdRSRP;
}

Unsigned32* MDTConfiguration::getEventThresholdRSRQ(){
	if(NULL == mEventThresholdRSRQ) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "EventThresholdRSRQ is Null");
		throw lTssDiaMsgException;
	}
	if(!mEventThresholdRSRQ->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mEventThresholdRSRQ->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "EventThresholdRSRQ is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mEventThresholdRSRQ->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mEventThresholdRSRQ->Decode(mspByteArray.get(), mEventThresholdRSRQ->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding EventThresholdRSRQ")     ;
			throw lTssDiaMsgException;
		}
		mEventThresholdRSRQ->mAvpDecodedFlag = true;
	}
	return mEventThresholdRSRQ;
}

LoggingInterval* MDTConfiguration::getLoggingInterval(){
	if(NULL == mLoggingInterval) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "LoggingInterval is Null");
		throw lTssDiaMsgException;
	}
	if(!mLoggingInterval->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mLoggingInterval->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "LoggingInterval is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mLoggingInterval->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mLoggingInterval->Decode(mspByteArray.get(), mLoggingInterval->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding LoggingInterval")     ;
			throw lTssDiaMsgException;
		}
		mLoggingInterval->mAvpDecodedFlag = true;
	}
	return mLoggingInterval;
}

LoggingDuration* MDTConfiguration::getLoggingDuration(){
	if(NULL == mLoggingDuration) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "LoggingDuration is Null");
		throw lTssDiaMsgException;
	}
	if(!mLoggingDuration->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mLoggingDuration->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "LoggingDuration is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mLoggingDuration->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mLoggingDuration->Decode(mspByteArray.get(), mLoggingDuration->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding LoggingDuration")     ;
			throw lTssDiaMsgException;
		}
		mLoggingDuration->mAvpDecodedFlag = true;
	}
	return mLoggingDuration;
}

MeasurementPeriodLTE* MDTConfiguration::getMeasurementPeriodLTE(){
	if(NULL == mMeasurementPeriodLTE) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MeasurementPeriodLTE is Null");
		throw lTssDiaMsgException;
	}
	if(!mMeasurementPeriodLTE->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMeasurementPeriodLTE->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MeasurementPeriodLTE is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMeasurementPeriodLTE->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMeasurementPeriodLTE->Decode(mspByteArray.get(), mMeasurementPeriodLTE->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MeasurementPeriodLTE")     ;
			throw lTssDiaMsgException;
		}
		mMeasurementPeriodLTE->mAvpDecodedFlag = true;
	}
	return mMeasurementPeriodLTE;
}

MeasurementPeriodUMTS* MDTConfiguration::getMeasurementPeriodUMTS(){
	if(NULL == mMeasurementPeriodUMTS) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MeasurementPeriodUMTS is Null");
		throw lTssDiaMsgException;
	}
	if(!mMeasurementPeriodUMTS->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMeasurementPeriodUMTS->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MeasurementPeriodUMTS is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMeasurementPeriodUMTS->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMeasurementPeriodUMTS->Decode(mspByteArray.get(), mMeasurementPeriodUMTS->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MeasurementPeriodUMTS")     ;
			throw lTssDiaMsgException;
		}
		mMeasurementPeriodUMTS->mAvpDecodedFlag = true;
	}
	return mMeasurementPeriodUMTS;
}

CollectionPeriodRRMLTE* MDTConfiguration::getCollectionPeriodRRMLTE(){
	if(NULL == mCollectionPeriodRRMLTE) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CollectionPeriodRRMLTE is Null");
		throw lTssDiaMsgException;
	}
	if(!mCollectionPeriodRRMLTE->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCollectionPeriodRRMLTE->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CollectionPeriodRRMLTE is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCollectionPeriodRRMLTE->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCollectionPeriodRRMLTE->Decode(mspByteArray.get(), mCollectionPeriodRRMLTE->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CollectionPeriodRRMLTE")     ;
			throw lTssDiaMsgException;
		}
		mCollectionPeriodRRMLTE->mAvpDecodedFlag = true;
	}
	return mCollectionPeriodRRMLTE;
}

CollectionPeriodRRMUMTS* MDTConfiguration::getCollectionPeriodRRMUMTS(){
	if(NULL == mCollectionPeriodRRMUMTS) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CollectionPeriodRRMUMTS is Null");
		throw lTssDiaMsgException;
	}
	if(!mCollectionPeriodRRMUMTS->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCollectionPeriodRRMUMTS->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CollectionPeriodRRMUMTS is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCollectionPeriodRRMUMTS->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCollectionPeriodRRMUMTS->Decode(mspByteArray.get(), mCollectionPeriodRRMUMTS->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CollectionPeriodRRMUMTS")     ;
			throw lTssDiaMsgException;
		}
		mCollectionPeriodRRMUMTS->mAvpDecodedFlag = true;
	}
	return mCollectionPeriodRRMUMTS;
}

OctetString* MDTConfiguration::getPositioningMethod(){
	if(NULL == mPositioningMethod) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PositioningMethod is Null");
		throw lTssDiaMsgException;
	}
	if(!mPositioningMethod->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPositioningMethod->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PositioningMethod is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPositioningMethod->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPositioningMethod->Decode(mspByteArray.get(), mPositioningMethod->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PositioningMethod")     ;
			throw lTssDiaMsgException;
		}
		mPositioningMethod->mAvpDecodedFlag = true;
	}
	return mPositioningMethod;
}

OctetString* MDTConfiguration::getMeasurementQuantity(){
	if(NULL == mMeasurementQuantity) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MeasurementQuantity is Null");
		throw lTssDiaMsgException;
	}
	if(!mMeasurementQuantity->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMeasurementQuantity->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MeasurementQuantity is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMeasurementQuantity->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMeasurementQuantity->Decode(mspByteArray.get(), mMeasurementQuantity->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MeasurementQuantity")     ;
			throw lTssDiaMsgException;
		}
		mMeasurementQuantity->mAvpDecodedFlag = true;
	}
	return mMeasurementQuantity;
}

Integer32* MDTConfiguration::getEventThresholdEvent1F(){
	if(NULL == mEventThresholdEvent1F) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "EventThresholdEvent1F is Null");
		throw lTssDiaMsgException;
	}
	if(!mEventThresholdEvent1F->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mEventThresholdEvent1F->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "EventThresholdEvent1F is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mEventThresholdEvent1F->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mEventThresholdEvent1F->Decode(mspByteArray.get(), mEventThresholdEvent1F->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding EventThresholdEvent1F")     ;
			throw lTssDiaMsgException;
		}
		mEventThresholdEvent1F->mAvpDecodedFlag = true;
	}
	return mEventThresholdEvent1F;
}

Integer32* MDTConfiguration::getEventThresholdEvent1I(){
	if(NULL == mEventThresholdEvent1I) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "EventThresholdEvent1I is Null");
		throw lTssDiaMsgException;
	}
	if(!mEventThresholdEvent1I->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mEventThresholdEvent1I->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "EventThresholdEvent1I is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mEventThresholdEvent1I->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mEventThresholdEvent1I->Decode(mspByteArray.get(), mEventThresholdEvent1I->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding EventThresholdEvent1I")     ;
			throw lTssDiaMsgException;
		}
		mEventThresholdEvent1I->mAvpDecodedFlag = true;
	}
	return mEventThresholdEvent1I;
}



int MDTConfiguration::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case MDTConfiguration_JOBTYPE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1623);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 192;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(192))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mJobType->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mJobType->getAvpOffsetLen().first], mJobType->getAvpOffsetLen().second);
						array->offset += mJobType->getAvpOffsetLen().second;
						array->size += mJobType->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding JobType");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mJobType->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding JobType");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MDTConfiguration_AREASCOPE:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(1624);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
				array->size++;
				array->byte[array->offset++] = 128;
				lengthOffset = array->offset; 
				array->offset += 3; 
				array->size += 3; 
				if( true == DiameterTLVUtil::isVenderSpecific(128))
 						{ 
						INT32 venderId=10415;
					array->size+=4;
					lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
						array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
				} 
				if((this->getAreaScope()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AreaScope");
					throw lTssDiaMsgException;
					}
				}
				break;
			case MDTConfiguration_LISTOFMEASUREMENTS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1625);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mListOfMeasurements->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mListOfMeasurements->getAvpOffsetLen().first], mListOfMeasurements->getAvpOffsetLen().second);
						array->offset += mListOfMeasurements->getAvpOffsetLen().second;
						array->size += mListOfMeasurements->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ListOfMeasurements");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mListOfMeasurements->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ListOfMeasurements");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MDTConfiguration_REPORTINGTRIGGER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1626);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mReportingTrigger->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mReportingTrigger->getAvpOffsetLen().first], mReportingTrigger->getAvpOffsetLen().second);
						array->offset += mReportingTrigger->getAvpOffsetLen().second;
						array->size += mReportingTrigger->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ReportingTrigger");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mReportingTrigger->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ReportingTrigger");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MDTConfiguration_REPORTINTERVAL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1627);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mReportInterval->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mReportInterval->getAvpOffsetLen().first], mReportInterval->getAvpOffsetLen().second);
						array->offset += mReportInterval->getAvpOffsetLen().second;
						array->size += mReportInterval->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ReportInterval");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mReportInterval->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ReportInterval");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MDTConfiguration_REPORTAMOUNT:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1628);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mReportAmount->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mReportAmount->getAvpOffsetLen().first], mReportAmount->getAvpOffsetLen().second);
						array->offset += mReportAmount->getAvpOffsetLen().second;
						array->size += mReportAmount->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ReportAmount");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mReportAmount->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ReportAmount");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MDTConfiguration_EVENTTHRESHOLDRSRP:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1629);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mEventThresholdRSRP->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mEventThresholdRSRP->getAvpOffsetLen().first], mEventThresholdRSRP->getAvpOffsetLen().second);
						array->offset += mEventThresholdRSRP->getAvpOffsetLen().second;
						array->size += mEventThresholdRSRP->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding EventThresholdRSRP");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mEventThresholdRSRP->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding EventThresholdRSRP");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MDTConfiguration_EVENTTHRESHOLDRSRQ:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1630);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mEventThresholdRSRQ->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mEventThresholdRSRQ->getAvpOffsetLen().first], mEventThresholdRSRQ->getAvpOffsetLen().second);
						array->offset += mEventThresholdRSRQ->getAvpOffsetLen().second;
						array->size += mEventThresholdRSRQ->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding EventThresholdRSRQ");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mEventThresholdRSRQ->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding EventThresholdRSRQ");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MDTConfiguration_LOGGINGINTERVAL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1631);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mLoggingInterval->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mLoggingInterval->getAvpOffsetLen().first], mLoggingInterval->getAvpOffsetLen().second);
						array->offset += mLoggingInterval->getAvpOffsetLen().second;
						array->size += mLoggingInterval->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding LoggingInterval");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mLoggingInterval->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding LoggingInterval");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MDTConfiguration_LOGGINGDURATION:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1632);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mLoggingDuration->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mLoggingDuration->getAvpOffsetLen().first], mLoggingDuration->getAvpOffsetLen().second);
						array->offset += mLoggingDuration->getAvpOffsetLen().second;
						array->size += mLoggingDuration->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding LoggingDuration");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mLoggingDuration->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding LoggingDuration");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MDTConfiguration_MEASUREMENTPERIODLTE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1655);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mMeasurementPeriodLTE->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMeasurementPeriodLTE->getAvpOffsetLen().first], mMeasurementPeriodLTE->getAvpOffsetLen().second);
						array->offset += mMeasurementPeriodLTE->getAvpOffsetLen().second;
						array->size += mMeasurementPeriodLTE->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MeasurementPeriodLTE");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mMeasurementPeriodLTE->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MeasurementPeriodLTE");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MDTConfiguration_MEASUREMENTPERIODUMTS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1656);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mMeasurementPeriodUMTS->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMeasurementPeriodUMTS->getAvpOffsetLen().first], mMeasurementPeriodUMTS->getAvpOffsetLen().second);
						array->offset += mMeasurementPeriodUMTS->getAvpOffsetLen().second;
						array->size += mMeasurementPeriodUMTS->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MeasurementPeriodUMTS");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mMeasurementPeriodUMTS->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MeasurementPeriodUMTS");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MDTConfiguration_COLLECTIONPERIODRRMLTE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1657);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mCollectionPeriodRRMLTE->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCollectionPeriodRRMLTE->getAvpOffsetLen().first], mCollectionPeriodRRMLTE->getAvpOffsetLen().second);
						array->offset += mCollectionPeriodRRMLTE->getAvpOffsetLen().second;
						array->size += mCollectionPeriodRRMLTE->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CollectionPeriodRRMLTE");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mCollectionPeriodRRMLTE->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CollectionPeriodRRMLTE");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MDTConfiguration_COLLECTIONPERIODRRMUMTS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1658);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mCollectionPeriodRRMUMTS->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCollectionPeriodRRMUMTS->getAvpOffsetLen().first], mCollectionPeriodRRMUMTS->getAvpOffsetLen().second);
						array->offset += mCollectionPeriodRRMUMTS->getAvpOffsetLen().second;
						array->size += mCollectionPeriodRRMUMTS->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CollectionPeriodRRMUMTS");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mCollectionPeriodRRMUMTS->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CollectionPeriodRRMUMTS");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MDTConfiguration_POSITIONINGMETHOD:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1659);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mPositioningMethod->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mPositioningMethod->getAvpOffsetLen().first], mPositioningMethod->getAvpOffsetLen().second);
						array->offset += mPositioningMethod->getAvpOffsetLen().second;
						array->size += mPositioningMethod->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mPositioningMethod->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mPositioningMethod->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PositioningMethod");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mPositioningMethod->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mPositioningMethod->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PositioningMethod");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MDTConfiguration_MEASUREMENTQUANTITY:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1660);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mMeasurementQuantity->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMeasurementQuantity->getAvpOffsetLen().first], mMeasurementQuantity->getAvpOffsetLen().second);
						array->offset += mMeasurementQuantity->getAvpOffsetLen().second;
						array->size += mMeasurementQuantity->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mMeasurementQuantity->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mMeasurementQuantity->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MeasurementQuantity");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mMeasurementQuantity->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mMeasurementQuantity->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MeasurementQuantity");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MDTConfiguration_EVENTTHRESHOLDEVENT1F:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1661);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mEventThresholdEvent1F->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mEventThresholdEvent1F->getAvpOffsetLen().first], mEventThresholdEvent1F->getAvpOffsetLen().second);
						array->offset += mEventThresholdEvent1F->getAvpOffsetLen().second;
						array->size += mEventThresholdEvent1F->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding EventThresholdEvent1F");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mEventThresholdEvent1F->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding EventThresholdEvent1F");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MDTConfiguration_EVENTTHRESHOLDEVENT1I:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1662);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mEventThresholdEvent1I->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mEventThresholdEvent1I->getAvpOffsetLen().first], mEventThresholdEvent1I->getAvpOffsetLen().second);
						array->offset += mEventThresholdEvent1I->getAvpOffsetLen().second;
						array->size += mEventThresholdEvent1I->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding EventThresholdEvent1I");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mEventThresholdEvent1I->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding EventThresholdEvent1I");
						throw lTssDiaMsgException;
					}
				}
				break;
			default:
				//printf("Unknown Tag received Tag:%d Offset:%d\n", mTagArray[lTemp], array->offset);
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE);
					throw lTssDiaMsgException;
				break;
		}
	}


	return DIAMETER_NO_ERR;
}


int MDTConfiguration::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
{
	mDecodeFlag = true;
	while( lMsgLen > 0)
	{
		UINT32  lAvpCode;
		UINT8   lAvpFlag = 0;
		UINT32  lAvpLen = 0;
		UINT32  lVenderId = 0;
		UINT32  lAvpHeaderLen = 8;
		UINT32  lAvpDataLen = 0;
		if(false == DiameterTLVUtil::decodeIntegerValue(array, lAvpCode, DIA_AVP_CODE_SIZE))
		{
			mDecodeFlag = false;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP code");
			throw lTssDiaMsgException;
		}
		memcpy( &lAvpFlag, &array->byte[array->offset++],sizeof(UINT8));
		if(false == DiameterTLVUtil::decodeAvpCmdIntegerValue(array, lAvpLen, DIA_AVP_LEN_SIZE))
		{
			mDecodeFlag = false;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP length");
			throw lTssDiaMsgException;
		}
		if(lAvpLen == 0)
		{
			mDecodeFlag = false;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP length");
			throw lTssDiaMsgException;
		}
		if( true == DiameterTLVUtil::isVenderSpecific(lAvpFlag))
		{ 
			lAvpHeaderLen = 12;
			if(false == DiameterTLVUtil::decodeIntegerValue(array, lVenderId, DIA_VENDER_SPEC_APPLN_ID_SIZE))
			{
				mDecodeFlag = false;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Vendor Id");
				throw lTssDiaMsgException;
			}

		}
		lAvpDataLen = lAvpLen-lAvpHeaderLen;
		switch(lAvpCode)
		{
			case 1623:
				{
						mMandatoryAvpSetVal [MDTConfiguration_JOBTYPE] = 1;
					if( NULL == this->setJobType())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding JobType");
						throw lTssDiaMsgException;
					}
					mJobType->setAvpCode(1623);
					mJobType->setAvpVendorId(lVenderId);
					mJobType->SetDataType((DiameterDataType)7);
					mJobType->mspByteArray = mspByteArray;
					mJobType->mAvpDecodedFlag = false;
					mJobType->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1624:
				{
					mTagsPresent[MDTConfiguration_AREASCOPE] = 1;
						if( NULL == this->setAreaScope()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AreaScope");
						throw lTssDiaMsgException;
						}
					mAreaScopeGrp->setAvpCode(1624);
					mAreaScopeGrp->SetDataType((DiameterDataType)6);
					mAreaScopeGrp->mspByteArray = mspByteArray;
					mAreaScopeGrp->mAvpDecodedFlag = false;
					mAreaScopeGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mAreaScopeGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1625:
				{
					if( NULL == this->setListOfMeasurements())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ListOfMeasurements");
						throw lTssDiaMsgException;
					}
					mListOfMeasurements->setAvpCode(1625);
					mListOfMeasurements->setAvpVendorId(lVenderId);
					mListOfMeasurements->SetDataType((DiameterDataType)3);
					mListOfMeasurements->mspByteArray = mspByteArray;
					mListOfMeasurements->mAvpDecodedFlag = false;
					mListOfMeasurements->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1626:
				{
					if( NULL == this->setReportingTrigger())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ReportingTrigger");
						throw lTssDiaMsgException;
					}
					mReportingTrigger->setAvpCode(1626);
					mReportingTrigger->setAvpVendorId(lVenderId);
					mReportingTrigger->SetDataType((DiameterDataType)3);
					mReportingTrigger->mspByteArray = mspByteArray;
					mReportingTrigger->mAvpDecodedFlag = false;
					mReportingTrigger->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1627:
				{
					if( NULL == this->setReportInterval())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ReportInterval");
						throw lTssDiaMsgException;
					}
					mReportInterval->setAvpCode(1627);
					mReportInterval->setAvpVendorId(lVenderId);
					mReportInterval->SetDataType((DiameterDataType)7);
					mReportInterval->mspByteArray = mspByteArray;
					mReportInterval->mAvpDecodedFlag = false;
					mReportInterval->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1628:
				{
					if( NULL == this->setReportAmount())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ReportAmount");
						throw lTssDiaMsgException;
					}
					mReportAmount->setAvpCode(1628);
					mReportAmount->setAvpVendorId(lVenderId);
					mReportAmount->SetDataType((DiameterDataType)7);
					mReportAmount->mspByteArray = mspByteArray;
					mReportAmount->mAvpDecodedFlag = false;
					mReportAmount->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1629:
				{
					if( NULL == this->setEventThresholdRSRP())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding EventThresholdRSRP");
						throw lTssDiaMsgException;
					}
					mEventThresholdRSRP->setAvpCode(1629);
					mEventThresholdRSRP->setAvpVendorId(lVenderId);
					mEventThresholdRSRP->SetDataType((DiameterDataType)3);
					mEventThresholdRSRP->mspByteArray = mspByteArray;
					mEventThresholdRSRP->mAvpDecodedFlag = false;
					mEventThresholdRSRP->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1630:
				{
					if( NULL == this->setEventThresholdRSRQ())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding EventThresholdRSRQ");
						throw lTssDiaMsgException;
					}
					mEventThresholdRSRQ->setAvpCode(1630);
					mEventThresholdRSRQ->setAvpVendorId(lVenderId);
					mEventThresholdRSRQ->SetDataType((DiameterDataType)3);
					mEventThresholdRSRQ->mspByteArray = mspByteArray;
					mEventThresholdRSRQ->mAvpDecodedFlag = false;
					mEventThresholdRSRQ->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1631:
				{
					if( NULL == this->setLoggingInterval())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding LoggingInterval");
						throw lTssDiaMsgException;
					}
					mLoggingInterval->setAvpCode(1631);
					mLoggingInterval->setAvpVendorId(lVenderId);
					mLoggingInterval->SetDataType((DiameterDataType)7);
					mLoggingInterval->mspByteArray = mspByteArray;
					mLoggingInterval->mAvpDecodedFlag = false;
					mLoggingInterval->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1632:
				{
					if( NULL == this->setLoggingDuration())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding LoggingDuration");
						throw lTssDiaMsgException;
					}
					mLoggingDuration->setAvpCode(1632);
					mLoggingDuration->setAvpVendorId(lVenderId);
					mLoggingDuration->SetDataType((DiameterDataType)7);
					mLoggingDuration->mspByteArray = mspByteArray;
					mLoggingDuration->mAvpDecodedFlag = false;
					mLoggingDuration->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1655:
				{
					if( NULL == this->setMeasurementPeriodLTE())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MeasurementPeriodLTE");
						throw lTssDiaMsgException;
					}
					mMeasurementPeriodLTE->setAvpCode(1655);
					mMeasurementPeriodLTE->setAvpVendorId(lVenderId);
					mMeasurementPeriodLTE->SetDataType((DiameterDataType)7);
					mMeasurementPeriodLTE->mspByteArray = mspByteArray;
					mMeasurementPeriodLTE->mAvpDecodedFlag = false;
					mMeasurementPeriodLTE->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1656:
				{
					if( NULL == this->setMeasurementPeriodUMTS())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MeasurementPeriodUMTS");
						throw lTssDiaMsgException;
					}
					mMeasurementPeriodUMTS->setAvpCode(1656);
					mMeasurementPeriodUMTS->setAvpVendorId(lVenderId);
					mMeasurementPeriodUMTS->SetDataType((DiameterDataType)7);
					mMeasurementPeriodUMTS->mspByteArray = mspByteArray;
					mMeasurementPeriodUMTS->mAvpDecodedFlag = false;
					mMeasurementPeriodUMTS->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1657:
				{
					if( NULL == this->setCollectionPeriodRRMLTE())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CollectionPeriodRRMLTE");
						throw lTssDiaMsgException;
					}
					mCollectionPeriodRRMLTE->setAvpCode(1657);
					mCollectionPeriodRRMLTE->setAvpVendorId(lVenderId);
					mCollectionPeriodRRMLTE->SetDataType((DiameterDataType)7);
					mCollectionPeriodRRMLTE->mspByteArray = mspByteArray;
					mCollectionPeriodRRMLTE->mAvpDecodedFlag = false;
					mCollectionPeriodRRMLTE->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1658:
				{
					if( NULL == this->setCollectionPeriodRRMUMTS())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CollectionPeriodRRMUMTS");
						throw lTssDiaMsgException;
					}
					mCollectionPeriodRRMUMTS->setAvpCode(1658);
					mCollectionPeriodRRMUMTS->setAvpVendorId(lVenderId);
					mCollectionPeriodRRMUMTS->SetDataType((DiameterDataType)7);
					mCollectionPeriodRRMUMTS->mspByteArray = mspByteArray;
					mCollectionPeriodRRMUMTS->mAvpDecodedFlag = false;
					mCollectionPeriodRRMUMTS->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1659:
				{
					if( NULL == this->setPositioningMethod())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PositioningMethod");
						throw lTssDiaMsgException;
					}
					mPositioningMethod->setAvpCode(1659);
					mPositioningMethod->setAvpVendorId(lVenderId);
					mPositioningMethod->SetDataType((DiameterDataType)5);
					mPositioningMethod->mspByteArray = mspByteArray;
					mPositioningMethod->mAvpDecodedFlag = false;
					mPositioningMethod->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1660:
				{
					if( NULL == this->setMeasurementQuantity())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MeasurementQuantity");
						throw lTssDiaMsgException;
					}
					mMeasurementQuantity->setAvpCode(1660);
					mMeasurementQuantity->setAvpVendorId(lVenderId);
					mMeasurementQuantity->SetDataType((DiameterDataType)5);
					mMeasurementQuantity->mspByteArray = mspByteArray;
					mMeasurementQuantity->mAvpDecodedFlag = false;
					mMeasurementQuantity->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1661:
				{
					if( NULL == this->setEventThresholdEvent1F())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding EventThresholdEvent1F");
						throw lTssDiaMsgException;
					}
					mEventThresholdEvent1F->setAvpCode(1661);
					mEventThresholdEvent1F->setAvpVendorId(lVenderId);
					mEventThresholdEvent1F->SetDataType((DiameterDataType)1);
					mEventThresholdEvent1F->mspByteArray = mspByteArray;
					mEventThresholdEvent1F->mAvpDecodedFlag = false;
					mEventThresholdEvent1F->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1662:
				{
					if( NULL == this->setEventThresholdEvent1I())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding EventThresholdEvent1I");
						throw lTssDiaMsgException;
					}
					mEventThresholdEvent1I->setAvpCode(1662);
					mEventThresholdEvent1I->setAvpVendorId(lVenderId);
					mEventThresholdEvent1I->SetDataType((DiameterDataType)1);
					mEventThresholdEvent1I->mspByteArray = mspByteArray;
					mEventThresholdEvent1I->mAvpDecodedFlag = false;
					mEventThresholdEvent1I->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			default:
				array->offset+=lAvpDataLen;
				//printf("Unknown AvpCode received Avp:%d \n", lAvpCode );
					//TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
					//throw lTssDiaMsgException;
				break;
		}

		if( (lAvpLen % 4) == 0 )
		{
			lMsgLen = lMsgLen -lAvpLen;
		}
		else
		{
			lMsgLen = lMsgLen -( lAvpLen + ( 4-(lAvpLen%4)));
			array->offset+= ( 4-(lAvpLen%4));
		}
	}
	return DIAMETER_NO_ERR;
}


DiameterBaseInterface* MDTConfiguration::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MDTConfiguration")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1623:
			{
				if(mJobType != NULL)
					return mJobType->Find(array, avpCode);
				else
					return NULL;
			}
			case 1625:
			{
				if(mListOfMeasurements != NULL)
					return mListOfMeasurements->Find(array, avpCode);
				else
					return NULL;
			}
			case 1626:
			{
				if(mReportingTrigger != NULL)
					return mReportingTrigger->Find(array, avpCode);
				else
					return NULL;
			}
			case 1627:
			{
				if(mReportInterval != NULL)
					return mReportInterval->Find(array, avpCode);
				else
					return NULL;
			}
			case 1628:
			{
				if(mReportAmount != NULL)
					return mReportAmount->Find(array, avpCode);
				else
					return NULL;
			}
			case 1629:
			{
				if(mEventThresholdRSRP != NULL)
					return mEventThresholdRSRP->Find(array, avpCode);
				else
					return NULL;
			}
			case 1630:
			{
				if(mEventThresholdRSRQ != NULL)
					return mEventThresholdRSRQ->Find(array, avpCode);
				else
					return NULL;
			}
			case 1631:
			{
				if(mLoggingInterval != NULL)
					return mLoggingInterval->Find(array, avpCode);
				else
					return NULL;
			}
			case 1632:
			{
				if(mLoggingDuration != NULL)
					return mLoggingDuration->Find(array, avpCode);
				else
					return NULL;
			}
			case 1655:
			{
				if(mMeasurementPeriodLTE != NULL)
					return mMeasurementPeriodLTE->Find(array, avpCode);
				else
					return NULL;
			}
			case 1656:
			{
				if(mMeasurementPeriodUMTS != NULL)
					return mMeasurementPeriodUMTS->Find(array, avpCode);
				else
					return NULL;
			}
			case 1657:
			{
				if(mCollectionPeriodRRMLTE != NULL)
					return mCollectionPeriodRRMLTE->Find(array, avpCode);
				else
					return NULL;
			}
			case 1658:
			{
				if(mCollectionPeriodRRMUMTS != NULL)
					return mCollectionPeriodRRMUMTS->Find(array, avpCode);
				else
					return NULL;
			}
			case 1659:
			{
				if(mPositioningMethod != NULL)
					return mPositioningMethod->Find(array, avpCode);
				else
					return NULL;
			}
			case 1660:
			{
				if(mMeasurementQuantity != NULL)
					return mMeasurementQuantity->Find(array, avpCode);
				else
					return NULL;
			}
			case 1661:
			{
				if(mEventThresholdEvent1F != NULL)
					return mEventThresholdEvent1F->Find(array, avpCode);
				else
					return NULL;
			}
			case 1662:
			{
				if(mEventThresholdEvent1I != NULL)
					return mEventThresholdEvent1I->Find(array, avpCode);
				else
					return NULL;
			}
			default:
			{
				for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
				{
					DiameterBaseInterface* inf = (*itr)->Find(array, avpCode);
					if(inf != NULL)
						return inf;
				}
				return NULL;
			}
		}
}


BOOLEAN MDTConfiguration::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MDTConfiguration")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1623:
			{
				if(mJobType != NULL)
				{
					DiameterBaseInterface* inf =  mJobType->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1624:
			{
				if(mAreaScopeGrp != NULL)
				{
						pBaseInterface.push_back(mAreaScopeGrp);
				}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1625:
			{
				if(mListOfMeasurements != NULL)
				{
					DiameterBaseInterface* inf =  mListOfMeasurements->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1626:
			{
				if(mReportingTrigger != NULL)
				{
					DiameterBaseInterface* inf =  mReportingTrigger->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1627:
			{
				if(mReportInterval != NULL)
				{
					DiameterBaseInterface* inf =  mReportInterval->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1628:
			{
				if(mReportAmount != NULL)
				{
					DiameterBaseInterface* inf =  mReportAmount->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1629:
			{
				if(mEventThresholdRSRP != NULL)
				{
					DiameterBaseInterface* inf =  mEventThresholdRSRP->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1630:
			{
				if(mEventThresholdRSRQ != NULL)
				{
					DiameterBaseInterface* inf =  mEventThresholdRSRQ->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1631:
			{
				if(mLoggingInterval != NULL)
				{
					DiameterBaseInterface* inf =  mLoggingInterval->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1632:
			{
				if(mLoggingDuration != NULL)
				{
					DiameterBaseInterface* inf =  mLoggingDuration->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1655:
			{
				if(mMeasurementPeriodLTE != NULL)
				{
					DiameterBaseInterface* inf =  mMeasurementPeriodLTE->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1656:
			{
				if(mMeasurementPeriodUMTS != NULL)
				{
					DiameterBaseInterface* inf =  mMeasurementPeriodUMTS->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1657:
			{
				if(mCollectionPeriodRRMLTE != NULL)
				{
					DiameterBaseInterface* inf =  mCollectionPeriodRRMLTE->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1658:
			{
				if(mCollectionPeriodRRMUMTS != NULL)
				{
					DiameterBaseInterface* inf =  mCollectionPeriodRRMUMTS->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1659:
			{
				if(mPositioningMethod != NULL)
				{
					DiameterBaseInterface* inf =  mPositioningMethod->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1660:
			{
				if(mMeasurementQuantity != NULL)
				{
					DiameterBaseInterface* inf =  mMeasurementQuantity->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1661:
			{
				if(mEventThresholdEvent1F != NULL)
				{
					DiameterBaseInterface* inf =  mEventThresholdEvent1F->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1662:
			{
				if(mEventThresholdEvent1I != NULL)
				{
					DiameterBaseInterface* inf =  mEventThresholdEvent1I->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			default:
			{
				if(!deepInspect)
					break;
				for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
				{
					(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
				}
			}
		}
		if(pBaseInterface.size() > 0)
			return true;
		else
			return false;
}
std::shared_ptr<byteArray> MDTConfiguration::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN MDTConfiguration::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MDTConfiguration")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
	if(avpCodeMap.empty() || key > size)
	{
		return false;
	}
	auto it = avpCodeMap.find(key);
	if( it == avpCodeMap.end())
	{
		return false;
	}
	UINT32 avpCode = it->second;
		switch(avpCode)
		{
			case 1623:
			{
				if(mJobType != NULL)
				{
					DiameterBaseInterface* inf =  mJobType->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1624:
			{
				if(mAreaScopeGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mAreaScopeGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mAreaScopeGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
				}
				}
				break;
			}
			case 1625:
			{
				if(mListOfMeasurements != NULL)
				{
					DiameterBaseInterface* inf =  mListOfMeasurements->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1626:
			{
				if(mReportingTrigger != NULL)
				{
					DiameterBaseInterface* inf =  mReportingTrigger->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1627:
			{
				if(mReportInterval != NULL)
				{
					DiameterBaseInterface* inf =  mReportInterval->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1628:
			{
				if(mReportAmount != NULL)
				{
					DiameterBaseInterface* inf =  mReportAmount->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1629:
			{
				if(mEventThresholdRSRP != NULL)
				{
					DiameterBaseInterface* inf =  mEventThresholdRSRP->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1630:
			{
				if(mEventThresholdRSRQ != NULL)
				{
					DiameterBaseInterface* inf =  mEventThresholdRSRQ->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1631:
			{
				if(mLoggingInterval != NULL)
				{
					DiameterBaseInterface* inf =  mLoggingInterval->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1632:
			{
				if(mLoggingDuration != NULL)
				{
					DiameterBaseInterface* inf =  mLoggingDuration->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1655:
			{
				if(mMeasurementPeriodLTE != NULL)
				{
					DiameterBaseInterface* inf =  mMeasurementPeriodLTE->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1656:
			{
				if(mMeasurementPeriodUMTS != NULL)
				{
					DiameterBaseInterface* inf =  mMeasurementPeriodUMTS->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1657:
			{
				if(mCollectionPeriodRRMLTE != NULL)
				{
					DiameterBaseInterface* inf =  mCollectionPeriodRRMLTE->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1658:
			{
				if(mCollectionPeriodRRMUMTS != NULL)
				{
					DiameterBaseInterface* inf =  mCollectionPeriodRRMUMTS->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1659:
			{
				if(mPositioningMethod != NULL)
				{
					DiameterBaseInterface* inf =  mPositioningMethod->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1660:
			{
				if(mMeasurementQuantity != NULL)
				{
					DiameterBaseInterface* inf =  mMeasurementQuantity->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1661:
			{
				if(mEventThresholdEvent1F != NULL)
				{
					DiameterBaseInterface* inf =  mEventThresholdEvent1F->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1662:
			{
				if(mEventThresholdEvent1I != NULL)
				{
					DiameterBaseInterface* inf =  mEventThresholdEvent1I->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			default:
			{
					break;
			}
		}
		if(pBaseInterface.size() > 0)
			return true;
		else
			return false;
}


INT32 MDTConfiguration::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 MDTConfiguration::getAvpCode()
{
	return mAvpCode;
}
INT32 MDTConfiguration::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 MDTConfiguration::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 MDTConfiguration::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> MDTConfiguration::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void MDTConfiguration::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case MDTConfiguration_JOBTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1623" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "JobType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getJobType()->Display(tab+1);
			}
				break;
			case MDTConfiguration_AREASCOPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1624" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AreaScope" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getAreaScope()->Display(tab+1);
			}
				break;
			case MDTConfiguration_LISTOFMEASUREMENTS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1625" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ListOfMeasurements" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getListOfMeasurements()->Display(tab+1);
			}
				break;
			case MDTConfiguration_REPORTINGTRIGGER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1626" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ReportingTrigger" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getReportingTrigger()->Display(tab+1);
			}
				break;
			case MDTConfiguration_REPORTINTERVAL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1627" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ReportInterval" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getReportInterval()->Display(tab+1);
			}
				break;
			case MDTConfiguration_REPORTAMOUNT:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1628" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ReportAmount" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getReportAmount()->Display(tab+1);
			}
				break;
			case MDTConfiguration_EVENTTHRESHOLDRSRP:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1629" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "EventThresholdRSRP" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getEventThresholdRSRP()->Display(tab+1);
			}
				break;
			case MDTConfiguration_EVENTTHRESHOLDRSRQ:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1630" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "EventThresholdRSRQ" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getEventThresholdRSRQ()->Display(tab+1);
			}
				break;
			case MDTConfiguration_LOGGINGINTERVAL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1631" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "LoggingInterval" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getLoggingInterval()->Display(tab+1);
			}
				break;
			case MDTConfiguration_LOGGINGDURATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1632" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "LoggingDuration" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getLoggingDuration()->Display(tab+1);
			}
				break;
			case MDTConfiguration_MEASUREMENTPERIODLTE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1655" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MeasurementPeriodLTE" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getMeasurementPeriodLTE()->Display(tab+1);
			}
				break;
			case MDTConfiguration_MEASUREMENTPERIODUMTS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1656" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MeasurementPeriodUMTS" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getMeasurementPeriodUMTS()->Display(tab+1);
			}
				break;
			case MDTConfiguration_COLLECTIONPERIODRRMLTE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1657" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CollectionPeriodRRMLTE" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getCollectionPeriodRRMLTE()->Display(tab+1);
			}
				break;
			case MDTConfiguration_COLLECTIONPERIODRRMUMTS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1658" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CollectionPeriodRRMUMTS" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getCollectionPeriodRRMUMTS()->Display(tab+1);
			}
				break;
			case MDTConfiguration_POSITIONINGMETHOD:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1659" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PositioningMethod" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getPositioningMethod()->Display(tab+1);
			}
				break;
			case MDTConfiguration_MEASUREMENTQUANTITY:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1660" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MeasurementQuantity" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getMeasurementQuantity()->Display(tab+1);
			}
				break;
			case MDTConfiguration_EVENTTHRESHOLDEVENT1F:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1661" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "EventThresholdEvent1F" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getEventThresholdEvent1F()->Display(tab+1);
			}
				break;
			case MDTConfiguration_EVENTTHRESHOLDEVENT1I:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1662" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "EventThresholdEvent1I" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getEventThresholdEvent1I()->Display(tab+1);
			}
				break;
			default:
				//printf("Unknown Tag received Tag:%d Offset:%d\n", mTagArray[lTemp], array->offset);
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE);
					throw lTssDiaMsgException;
				break;
		}
	}

}


BOOLEAN MDTConfiguration::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<18> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case MDTConfiguration_JOBTYPE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1623");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1623", lMissingAvpInfo);
			}
				break;
			case MDTConfiguration_AREASCOPE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1624");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1624", lMissingAvpInfo);
			}
				break;
			case MDTConfiguration_LISTOFMEASUREMENTS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1625");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1625", lMissingAvpInfo);
			}
				break;
			case MDTConfiguration_REPORTINGTRIGGER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1626");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1626", lMissingAvpInfo);
			}
				break;
			case MDTConfiguration_REPORTINTERVAL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1627");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1627", lMissingAvpInfo);
			}
				break;
			case MDTConfiguration_REPORTAMOUNT:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1628");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1628", lMissingAvpInfo);
			}
				break;
			case MDTConfiguration_EVENTTHRESHOLDRSRP:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1629");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1629", lMissingAvpInfo);
			}
				break;
			case MDTConfiguration_EVENTTHRESHOLDRSRQ:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1630");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1630", lMissingAvpInfo);
			}
				break;
			case MDTConfiguration_LOGGINGINTERVAL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1631");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1631", lMissingAvpInfo);
			}
				break;
			case MDTConfiguration_LOGGINGDURATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1632");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1632", lMissingAvpInfo);
			}
				break;
			case MDTConfiguration_MEASUREMENTPERIODLTE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1655");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1655", lMissingAvpInfo);
			}
				break;
			case MDTConfiguration_MEASUREMENTPERIODUMTS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1656");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1656", lMissingAvpInfo);
			}
				break;
			case MDTConfiguration_COLLECTIONPERIODRRMLTE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1657");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1657", lMissingAvpInfo);
			}
				break;
			case MDTConfiguration_COLLECTIONPERIODRRMUMTS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1658");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1658", lMissingAvpInfo);
			}
				break;
			case MDTConfiguration_POSITIONINGMETHOD:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1659");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1659", lMissingAvpInfo);
			}
				break;
			case MDTConfiguration_MEASUREMENTQUANTITY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1660");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1660", lMissingAvpInfo);
			}
				break;
			case MDTConfiguration_EVENTTHRESHOLDEVENT1F:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1661");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1661", lMissingAvpInfo);
			}
				break;
			case MDTConfiguration_EVENTTHRESHOLDEVENT1I:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1662");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1662", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
