#include "sd/include/UsageMonitoringInformation.h"

using namespace SD;
BOOLEAN UsageMonitoringInformation::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

UsageMonitoringInformation::UsageMonitoringInformation()
{
	mMonitoringKey = NULL;
	mGrantedServiceUnitGrpList = NULL;
	mUsedServiceUnitGrpList = NULL;
	mQuotaConsumptionTime = NULL;
	mUsageMonitoringLevel = NULL;
	mUsageMonitoringReport = NULL;
	mUsageMonitoringSupport = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<7>(string("0000110"));
	mMandatoryAvpSetVal.reset();
}

UsageMonitoringInformation::~UsageMonitoringInformation()
{
	if(mMonitoringKey != NULL)
		delete mMonitoringKey;
	if(mGrantedServiceUnitGrpList != NULL){
		mGrantedServiceUnitGrpIterator = mGrantedServiceUnitGrpList->begin();
		while(mGrantedServiceUnitGrpIterator != mGrantedServiceUnitGrpList->end()){
	if(*mGrantedServiceUnitGrpIterator != NULL)
			delete (*mGrantedServiceUnitGrpIterator);
			mGrantedServiceUnitGrpIterator++;
		}
		delete mGrantedServiceUnitGrpList;
	}
	if(mUsedServiceUnitGrpList != NULL){
		mUsedServiceUnitGrpIterator = mUsedServiceUnitGrpList->begin();
		while(mUsedServiceUnitGrpIterator != mUsedServiceUnitGrpList->end()){
	if(*mUsedServiceUnitGrpIterator != NULL)
			delete (*mUsedServiceUnitGrpIterator);
			mUsedServiceUnitGrpIterator++;
		}
		delete mUsedServiceUnitGrpList;
	}
	if(mQuotaConsumptionTime != NULL)
		delete mQuotaConsumptionTime;
	if(mUsageMonitoringLevel != NULL)
		delete mUsageMonitoringLevel;
	if(mUsageMonitoringReport != NULL)
		delete mUsageMonitoringReport;
	if(mUsageMonitoringSupport != NULL)
		delete mUsageMonitoringSupport;
}

OctetString* UsageMonitoringInformation::setMonitoringKey(){
	if(mMonitoringKey == NULL)
	{
		mMonitoringKey = new OctetString();
		mTagsPresent[UsageMonitoringInformation_MONITORINGKEY] = 1;
		return mMonitoringKey;
	}
	return mMonitoringKey;
}

void UsageMonitoringInformation::resetMonitoringKey(){
	mTagsPresent[UsageMonitoringInformation_MONITORINGKEY] = 0;
	if(mMonitoringKey != NULL)
	{
		delete mMonitoringKey; 
		mMonitoringKey = NULL;
	}
}

Unsigned32* UsageMonitoringInformation::setQuotaConsumptionTime(){
	if(mQuotaConsumptionTime == NULL)
	{
		mQuotaConsumptionTime = new Unsigned32();
		mTagsPresent[UsageMonitoringInformation_QUOTACONSUMPTIONTIME] = 1;
		return mQuotaConsumptionTime;
	}
	return mQuotaConsumptionTime;
}

void UsageMonitoringInformation::resetQuotaConsumptionTime(){
	mTagsPresent[UsageMonitoringInformation_QUOTACONSUMPTIONTIME] = 0;
	if(mQuotaConsumptionTime != NULL)
	{
		delete mQuotaConsumptionTime; 
		mQuotaConsumptionTime = NULL;
	}
}

UsageMonitoringLevel* UsageMonitoringInformation::setUsageMonitoringLevel(){
	if(mUsageMonitoringLevel == NULL)
	{
		mUsageMonitoringLevel = new UsageMonitoringLevel();
		mTagsPresent[UsageMonitoringInformation_USAGEMONITORINGLEVEL] = 1;
		return mUsageMonitoringLevel;
	}
	return mUsageMonitoringLevel;
}

void UsageMonitoringInformation::resetUsageMonitoringLevel(){
	mTagsPresent[UsageMonitoringInformation_USAGEMONITORINGLEVEL] = 0;
	if(mUsageMonitoringLevel != NULL)
	{
		delete mUsageMonitoringLevel; 
		mUsageMonitoringLevel = NULL;
	}
}

UsageMonitoringReport* UsageMonitoringInformation::setUsageMonitoringReport(){
	if(mUsageMonitoringReport == NULL)
	{
		mUsageMonitoringReport = new UsageMonitoringReport();
		mTagsPresent[UsageMonitoringInformation_USAGEMONITORINGREPORT] = 1;
		return mUsageMonitoringReport;
	}
	return mUsageMonitoringReport;
}

void UsageMonitoringInformation::resetUsageMonitoringReport(){
	mTagsPresent[UsageMonitoringInformation_USAGEMONITORINGREPORT] = 0;
	if(mUsageMonitoringReport != NULL)
	{
		delete mUsageMonitoringReport; 
		mUsageMonitoringReport = NULL;
	}
}

UsageMonitoringSupport* UsageMonitoringInformation::setUsageMonitoringSupport(){
	if(mUsageMonitoringSupport == NULL)
	{
		mUsageMonitoringSupport = new UsageMonitoringSupport();
		mTagsPresent[UsageMonitoringInformation_USAGEMONITORINGSUPPORT] = 1;
		return mUsageMonitoringSupport;
	}
	return mUsageMonitoringSupport;
}

void UsageMonitoringInformation::resetUsageMonitoringSupport(){
	mTagsPresent[UsageMonitoringInformation_USAGEMONITORINGSUPPORT] = 0;
	if(mUsageMonitoringSupport != NULL)
	{
		delete mUsageMonitoringSupport; 
		mUsageMonitoringSupport = NULL;
	}
}

OctetString* UsageMonitoringInformation::getMonitoringKey(){
	if(NULL == mMonitoringKey) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MonitoringKey is Null");
		throw lTssDiaMsgException;
	}
	if(!mMonitoringKey->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMonitoringKey->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MonitoringKey is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMonitoringKey->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMonitoringKey->Decode(mspByteArray.get(), mMonitoringKey->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MonitoringKey")     ;
			throw lTssDiaMsgException;
		}
		mMonitoringKey->mAvpDecodedFlag = true;
	}
	return mMonitoringKey;
}

list<GrantedServiceUnit*>* UsageMonitoringInformation::getGrantedServiceUnitGrpList()
{
	if(mGrantedServiceUnitGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "GrantedServiceUnit is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mGrantedServiceUnitGrpList)
	{
		if(mGrantedServiceUnitGrpList != NULL)
		{
		if(mGrantedServiceUnitGrpList->size() == 0)
		{
			mTagsPresent[UsageMonitoringInformation_GRANTEDSERVICEUNIT] = 0;
			mGrantedServiceUnitGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "GrantedServiceUnit is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "GrantedServiceUnit is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding GrantedServiceUnit")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mGrantedServiceUnitGrpList;
}

list<GrantedServiceUnit*>* UsageMonitoringInformation::setGrantedServiceUnitGrpList(){
	mTagsPresent[UsageMonitoringInformation_GRANTEDSERVICEUNIT] = 1;
	if(mGrantedServiceUnitGrpList == NULL)
		mGrantedServiceUnitGrpList = new list<GrantedServiceUnit*>;
	mMandatoryAvpSetVal[UsageMonitoringInformation_GRANTEDSERVICEUNIT] = 1;
	mGrantedServiceUnitGrpList->clear();
	return mGrantedServiceUnitGrpList;
}

void UsageMonitoringInformation::resetGrantedServiceUnitGrpList(){
	mTagsPresent[UsageMonitoringInformation_GRANTEDSERVICEUNIT] = 0;
	if(mGrantedServiceUnitGrpList != NULL)
		delete mGrantedServiceUnitGrpList;
}

list<UsedServiceUnit*>* UsageMonitoringInformation::getUsedServiceUnitGrpList()
{
	if(mUsedServiceUnitGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UsedServiceUnit is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mUsedServiceUnitGrpList)
	{
		if(mUsedServiceUnitGrpList != NULL)
		{
		if(mUsedServiceUnitGrpList->size() == 0)
		{
			mTagsPresent[UsageMonitoringInformation_USEDSERVICEUNIT] = 0;
			mUsedServiceUnitGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UsedServiceUnit is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UsedServiceUnit is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UsedServiceUnit")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mUsedServiceUnitGrpList;
}

list<UsedServiceUnit*>* UsageMonitoringInformation::setUsedServiceUnitGrpList(){
	mTagsPresent[UsageMonitoringInformation_USEDSERVICEUNIT] = 1;
	if(mUsedServiceUnitGrpList == NULL)
		mUsedServiceUnitGrpList = new list<UsedServiceUnit*>;
	mMandatoryAvpSetVal[UsageMonitoringInformation_USEDSERVICEUNIT] = 1;
	mUsedServiceUnitGrpList->clear();
	return mUsedServiceUnitGrpList;
}

void UsageMonitoringInformation::resetUsedServiceUnitGrpList(){
	mTagsPresent[UsageMonitoringInformation_USEDSERVICEUNIT] = 0;
	if(mUsedServiceUnitGrpList != NULL)
		delete mUsedServiceUnitGrpList;
}

Unsigned32* UsageMonitoringInformation::getQuotaConsumptionTime(){
	if(NULL == mQuotaConsumptionTime) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "QuotaConsumptionTime is Null");
		throw lTssDiaMsgException;
	}
	if(!mQuotaConsumptionTime->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mQuotaConsumptionTime->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "QuotaConsumptionTime is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mQuotaConsumptionTime->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mQuotaConsumptionTime->Decode(mspByteArray.get(), mQuotaConsumptionTime->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding QuotaConsumptionTime")     ;
			throw lTssDiaMsgException;
		}
		mQuotaConsumptionTime->mAvpDecodedFlag = true;
	}
	return mQuotaConsumptionTime;
}

UsageMonitoringLevel* UsageMonitoringInformation::getUsageMonitoringLevel(){
	if(NULL == mUsageMonitoringLevel) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UsageMonitoringLevel is Null");
		throw lTssDiaMsgException;
	}
	if(!mUsageMonitoringLevel->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUsageMonitoringLevel->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UsageMonitoringLevel is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUsageMonitoringLevel->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUsageMonitoringLevel->Decode(mspByteArray.get(), mUsageMonitoringLevel->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UsageMonitoringLevel")     ;
			throw lTssDiaMsgException;
		}
		mUsageMonitoringLevel->mAvpDecodedFlag = true;
	}
	return mUsageMonitoringLevel;
}

UsageMonitoringReport* UsageMonitoringInformation::getUsageMonitoringReport(){
	if(NULL == mUsageMonitoringReport) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UsageMonitoringReport is Null");
		throw lTssDiaMsgException;
	}
	if(!mUsageMonitoringReport->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUsageMonitoringReport->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UsageMonitoringReport is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUsageMonitoringReport->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUsageMonitoringReport->Decode(mspByteArray.get(), mUsageMonitoringReport->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UsageMonitoringReport")     ;
			throw lTssDiaMsgException;
		}
		mUsageMonitoringReport->mAvpDecodedFlag = true;
	}
	return mUsageMonitoringReport;
}

UsageMonitoringSupport* UsageMonitoringInformation::getUsageMonitoringSupport(){
	if(NULL == mUsageMonitoringSupport) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UsageMonitoringSupport is Null");
		throw lTssDiaMsgException;
	}
	if(!mUsageMonitoringSupport->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUsageMonitoringSupport->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UsageMonitoringSupport is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUsageMonitoringSupport->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUsageMonitoringSupport->Decode(mspByteArray.get(), mUsageMonitoringSupport->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UsageMonitoringSupport")     ;
			throw lTssDiaMsgException;
		}
		mUsageMonitoringSupport->mAvpDecodedFlag = true;
	}
	return mUsageMonitoringSupport;
}



int UsageMonitoringInformation::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case UsageMonitoringInformation_MONITORINGKEY:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1066);
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
					if(!mMonitoringKey->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMonitoringKey->getAvpOffsetLen().first], mMonitoringKey->getAvpOffsetLen().second);
						array->offset += mMonitoringKey->getAvpOffsetLen().second;
						array->size += mMonitoringKey->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mMonitoringKey->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mMonitoringKey->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MonitoringKey");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mMonitoringKey->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mMonitoringKey->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MonitoringKey");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UsageMonitoringInformation_GRANTEDSERVICEUNIT:
			{
				if( mGrantedServiceUnitGrpList->size() <= 0) {
					break;
				}

				mGrantedServiceUnitGrpIterator = this->getGrantedServiceUnitGrpList()->begin();
				while(mGrantedServiceUnitGrpIterator != mGrantedServiceUnitGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(431);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 64;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(64))
						{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(((*mGrantedServiceUnitGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding GrantedServiceUnit");
						throw lTssDiaMsgException;
					}
					
					mGrantedServiceUnitGrpIterator++;
				}
				}
				break;
			case UsageMonitoringInformation_USEDSERVICEUNIT:
			{
				if( mUsedServiceUnitGrpList->size() <= 0) {
					break;
				}

				mUsedServiceUnitGrpIterator = this->getUsedServiceUnitGrpList()->begin();
				while(mUsedServiceUnitGrpIterator != mUsedServiceUnitGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(446);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 64;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(64))
						{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(((*mUsedServiceUnitGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UsedServiceUnit");
						throw lTssDiaMsgException;
					}
					
					mUsedServiceUnitGrpIterator++;
				}
				}
				break;
			case UsageMonitoringInformation_QUOTACONSUMPTIONTIME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(881);
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
					if(!mQuotaConsumptionTime->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mQuotaConsumptionTime->getAvpOffsetLen().first], mQuotaConsumptionTime->getAvpOffsetLen().second);
						array->offset += mQuotaConsumptionTime->getAvpOffsetLen().second;
						array->size += mQuotaConsumptionTime->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding QuotaConsumptionTime");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mQuotaConsumptionTime->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding QuotaConsumptionTime");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UsageMonitoringInformation_USAGEMONITORINGLEVEL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1068);
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
					if(!mUsageMonitoringLevel->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mUsageMonitoringLevel->getAvpOffsetLen().first], mUsageMonitoringLevel->getAvpOffsetLen().second);
						array->offset += mUsageMonitoringLevel->getAvpOffsetLen().second;
						array->size += mUsageMonitoringLevel->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UsageMonitoringLevel");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mUsageMonitoringLevel->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UsageMonitoringLevel");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UsageMonitoringInformation_USAGEMONITORINGREPORT:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1069);
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
					if(!mUsageMonitoringReport->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mUsageMonitoringReport->getAvpOffsetLen().first], mUsageMonitoringReport->getAvpOffsetLen().second);
						array->offset += mUsageMonitoringReport->getAvpOffsetLen().second;
						array->size += mUsageMonitoringReport->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UsageMonitoringReport");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mUsageMonitoringReport->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UsageMonitoringReport");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UsageMonitoringInformation_USAGEMONITORINGSUPPORT:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1070);
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
					if(!mUsageMonitoringSupport->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mUsageMonitoringSupport->getAvpOffsetLen().first], mUsageMonitoringSupport->getAvpOffsetLen().second);
						array->offset += mUsageMonitoringSupport->getAvpOffsetLen().second;
						array->size += mUsageMonitoringSupport->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UsageMonitoringSupport");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mUsageMonitoringSupport->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UsageMonitoringSupport");
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


int UsageMonitoringInformation::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 1066:
				{
					if( NULL == this->setMonitoringKey())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MonitoringKey");
						throw lTssDiaMsgException;
					}
					mMonitoringKey->setAvpCode(1066);
					mMonitoringKey->setAvpVendorId(lVenderId);
					mMonitoringKey->SetDataType((DiameterDataType)5);
					mMonitoringKey->mspByteArray = mspByteArray;
					mMonitoringKey->mAvpDecodedFlag = false;
					mMonitoringKey->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 431:
				{
						mMandatoryAvpSetVal [UsageMonitoringInformation_GRANTEDSERVICEUNIT] = 1;
					mTagsPresent[UsageMonitoringInformation_GRANTEDSERVICEUNIT] = 1;
					GrantedServiceUnit *lGrantedServiceUnit = new GrantedServiceUnit();
					if( lGrantedServiceUnit == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding GrantedServiceUnit");
						throw lTssDiaMsgException;
					}
					lGrantedServiceUnit->setAvpCode(431);
					lGrantedServiceUnit->SetDataType((DiameterDataType)6);
					lGrantedServiceUnit->mspByteArray = mspByteArray;
					lGrantedServiceUnit->mAvpDecodedFlag = false;
					lGrantedServiceUnit->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mGrantedServiceUnitGrpList == NULL)
						this->setGrantedServiceUnitGrpList();
					mGrantedServiceUnitGrpList->push_back(lGrantedServiceUnit);
					mBaseInterfaceList.push_back(lGrantedServiceUnit);
					
				}
				break;
			case 446:
				{
						mMandatoryAvpSetVal [UsageMonitoringInformation_USEDSERVICEUNIT] = 1;
					mTagsPresent[UsageMonitoringInformation_USEDSERVICEUNIT] = 1;
					UsedServiceUnit *lUsedServiceUnit = new UsedServiceUnit();
					if( lUsedServiceUnit == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UsedServiceUnit");
						throw lTssDiaMsgException;
					}
					lUsedServiceUnit->setAvpCode(446);
					lUsedServiceUnit->SetDataType((DiameterDataType)6);
					lUsedServiceUnit->mspByteArray = mspByteArray;
					lUsedServiceUnit->mAvpDecodedFlag = false;
					lUsedServiceUnit->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mUsedServiceUnitGrpList == NULL)
						this->setUsedServiceUnitGrpList();
					mUsedServiceUnitGrpList->push_back(lUsedServiceUnit);
					mBaseInterfaceList.push_back(lUsedServiceUnit);
					
				}
				break;
			case 881:
				{
					if( NULL == this->setQuotaConsumptionTime())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding QuotaConsumptionTime");
						throw lTssDiaMsgException;
					}
					mQuotaConsumptionTime->setAvpCode(881);
					mQuotaConsumptionTime->setAvpVendorId(lVenderId);
					mQuotaConsumptionTime->SetDataType((DiameterDataType)3);
					mQuotaConsumptionTime->mspByteArray = mspByteArray;
					mQuotaConsumptionTime->mAvpDecodedFlag = false;
					mQuotaConsumptionTime->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1068:
				{
					if( NULL == this->setUsageMonitoringLevel())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UsageMonitoringLevel");
						throw lTssDiaMsgException;
					}
					mUsageMonitoringLevel->setAvpCode(1068);
					mUsageMonitoringLevel->setAvpVendorId(lVenderId);
					mUsageMonitoringLevel->SetDataType((DiameterDataType)7);
					mUsageMonitoringLevel->mspByteArray = mspByteArray;
					mUsageMonitoringLevel->mAvpDecodedFlag = false;
					mUsageMonitoringLevel->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1069:
				{
					if( NULL == this->setUsageMonitoringReport())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UsageMonitoringReport");
						throw lTssDiaMsgException;
					}
					mUsageMonitoringReport->setAvpCode(1069);
					mUsageMonitoringReport->setAvpVendorId(lVenderId);
					mUsageMonitoringReport->SetDataType((DiameterDataType)7);
					mUsageMonitoringReport->mspByteArray = mspByteArray;
					mUsageMonitoringReport->mAvpDecodedFlag = false;
					mUsageMonitoringReport->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1070:
				{
					if( NULL == this->setUsageMonitoringSupport())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UsageMonitoringSupport");
						throw lTssDiaMsgException;
					}
					mUsageMonitoringSupport->setAvpCode(1070);
					mUsageMonitoringSupport->setAvpVendorId(lVenderId);
					mUsageMonitoringSupport->SetDataType((DiameterDataType)7);
					mUsageMonitoringSupport->mspByteArray = mspByteArray;
					mUsageMonitoringSupport->mAvpDecodedFlag = false;
					mUsageMonitoringSupport->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* UsageMonitoringInformation::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UsageMonitoringInformation")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1066:
			{
				if(mMonitoringKey != NULL)
					return mMonitoringKey->Find(array, avpCode);
				else
					return NULL;
			}
			case 881:
			{
				if(mQuotaConsumptionTime != NULL)
					return mQuotaConsumptionTime->Find(array, avpCode);
				else
					return NULL;
			}
			case 1068:
			{
				if(mUsageMonitoringLevel != NULL)
					return mUsageMonitoringLevel->Find(array, avpCode);
				else
					return NULL;
			}
			case 1069:
			{
				if(mUsageMonitoringReport != NULL)
					return mUsageMonitoringReport->Find(array, avpCode);
				else
					return NULL;
			}
			case 1070:
			{
				if(mUsageMonitoringSupport != NULL)
					return mUsageMonitoringSupport->Find(array, avpCode);
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


BOOLEAN UsageMonitoringInformation::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UsageMonitoringInformation")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1066:
			{
				if(mMonitoringKey != NULL)
				{
					DiameterBaseInterface* inf =  mMonitoringKey->Find(this->mspByteArray.get(), avpCode);
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
			case 431:
			{
				if(mGrantedServiceUnitGrpList != NULL)
				{
					for(auto itr = mGrantedServiceUnitGrpList->begin(); itr != mGrantedServiceUnitGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

					if(deepInspect)
					{
						for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 446:
			{
				if(mUsedServiceUnitGrpList != NULL)
				{
					for(auto itr = mUsedServiceUnitGrpList->begin(); itr != mUsedServiceUnitGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

					if(deepInspect)
					{
						for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 881:
			{
				if(mQuotaConsumptionTime != NULL)
				{
					DiameterBaseInterface* inf =  mQuotaConsumptionTime->Find(this->mspByteArray.get(), avpCode);
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
			case 1068:
			{
				if(mUsageMonitoringLevel != NULL)
				{
					DiameterBaseInterface* inf =  mUsageMonitoringLevel->Find(this->mspByteArray.get(), avpCode);
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
			case 1069:
			{
				if(mUsageMonitoringReport != NULL)
				{
					DiameterBaseInterface* inf =  mUsageMonitoringReport->Find(this->mspByteArray.get(), avpCode);
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
			case 1070:
			{
				if(mUsageMonitoringSupport != NULL)
				{
					DiameterBaseInterface* inf =  mUsageMonitoringSupport->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> UsageMonitoringInformation::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN UsageMonitoringInformation::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UsageMonitoringInformation")     ;
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
			case 1066:
			{
				if(mMonitoringKey != NULL)
				{
					DiameterBaseInterface* inf =  mMonitoringKey->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 431:
			{
				if(mGrantedServiceUnitGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mGrantedServiceUnitGrpList->begin(); itr != mGrantedServiceUnitGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mGrantedServiceUnitGrpList->begin(); itr != mGrantedServiceUnitGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 446:
			{
				if(mUsedServiceUnitGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mUsedServiceUnitGrpList->begin(); itr != mUsedServiceUnitGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mUsedServiceUnitGrpList->begin(); itr != mUsedServiceUnitGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 881:
			{
				if(mQuotaConsumptionTime != NULL)
				{
					DiameterBaseInterface* inf =  mQuotaConsumptionTime->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1068:
			{
				if(mUsageMonitoringLevel != NULL)
				{
					DiameterBaseInterface* inf =  mUsageMonitoringLevel->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1069:
			{
				if(mUsageMonitoringReport != NULL)
				{
					DiameterBaseInterface* inf =  mUsageMonitoringReport->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1070:
			{
				if(mUsageMonitoringSupport != NULL)
				{
					DiameterBaseInterface* inf =  mUsageMonitoringSupport->Find(this->mspByteArray.get(), avpCode);
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


INT32 UsageMonitoringInformation::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 UsageMonitoringInformation::getAvpCode()
{
	return mAvpCode;
}
INT32 UsageMonitoringInformation::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 UsageMonitoringInformation::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 UsageMonitoringInformation::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> UsageMonitoringInformation::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void UsageMonitoringInformation::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case UsageMonitoringInformation_MONITORINGKEY:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1066" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MonitoringKey" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getMonitoringKey()->Display(tab+1);
			}
				break;
			case UsageMonitoringInformation_GRANTEDSERVICEUNIT:
			{
				if( mGrantedServiceUnitGrpList->size() <= 0) {
					break;
				}

				mGrantedServiceUnitGrpIterator = this->getGrantedServiceUnitGrpList()->begin();
				while(mGrantedServiceUnitGrpIterator != this->getGrantedServiceUnitGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "431" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "GrantedServiceUnit" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
					(*mGrantedServiceUnitGrpIterator)->Display(tab+1);
					mGrantedServiceUnitGrpIterator++;

				};

			}
				break;
			case UsageMonitoringInformation_USEDSERVICEUNIT:
			{
				if( mUsedServiceUnitGrpList->size() <= 0) {
					break;
				}

				mUsedServiceUnitGrpIterator = this->getUsedServiceUnitGrpList()->begin();
				while(mUsedServiceUnitGrpIterator != this->getUsedServiceUnitGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "446" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UsedServiceUnit" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
					(*mUsedServiceUnitGrpIterator)->Display(tab+1);
					mUsedServiceUnitGrpIterator++;

				};

			}
				break;
			case UsageMonitoringInformation_QUOTACONSUMPTIONTIME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "881" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "QuotaConsumptionTime" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getQuotaConsumptionTime()->Display(tab+1);
			}
				break;
			case UsageMonitoringInformation_USAGEMONITORINGLEVEL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1068" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UsageMonitoringLevel" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getUsageMonitoringLevel()->Display(tab+1);
			}
				break;
			case UsageMonitoringInformation_USAGEMONITORINGREPORT:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1069" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UsageMonitoringReport" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getUsageMonitoringReport()->Display(tab+1);
			}
				break;
			case UsageMonitoringInformation_USAGEMONITORINGSUPPORT:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1070" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UsageMonitoringSupport" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getUsageMonitoringSupport()->Display(tab+1);
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


BOOLEAN UsageMonitoringInformation::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<7> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case UsageMonitoringInformation_MONITORINGKEY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1066");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1066", lMissingAvpInfo);
			}
				break;
			case UsageMonitoringInformation_GRANTEDSERVICEUNIT:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 431");
				}
				else
					sprintf(lMissingAvpInfo, "%s,431", lMissingAvpInfo);
			}
				break;
			case UsageMonitoringInformation_USEDSERVICEUNIT:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 446");
				}
				else
					sprintf(lMissingAvpInfo, "%s,446", lMissingAvpInfo);
			}
				break;
			case UsageMonitoringInformation_QUOTACONSUMPTIONTIME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 881");
				}
				else
					sprintf(lMissingAvpInfo, "%s,881", lMissingAvpInfo);
			}
				break;
			case UsageMonitoringInformation_USAGEMONITORINGLEVEL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1068");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1068", lMissingAvpInfo);
			}
				break;
			case UsageMonitoringInformation_USAGEMONITORINGREPORT:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1069");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1069", lMissingAvpInfo);
			}
				break;
			case UsageMonitoringInformation_USAGEMONITORINGSUPPORT:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1070");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1070", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
