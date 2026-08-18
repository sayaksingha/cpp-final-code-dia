#include "sd/include/ADCRuleInstall.h"

using namespace SD;
BOOLEAN ADCRuleInstall::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

ADCRuleInstall::ADCRuleInstall()
{
	mADCRuleDefinitionGrpList = NULL;
	mADCRuleNameList = NULL;
	mADCRuleBaseNameList = NULL;
	mMonitoringFlags = NULL;
	mRuleActivationTime = NULL;
	mRuleDeactivationTime = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<6>(string("110111"));
	mMandatoryAvpSetVal.reset();
}

ADCRuleInstall::~ADCRuleInstall()
{
	if(mADCRuleDefinitionGrpList != NULL){
		mADCRuleDefinitionGrpIterator = mADCRuleDefinitionGrpList->begin();
		while(mADCRuleDefinitionGrpIterator != mADCRuleDefinitionGrpList->end()){
	if(*mADCRuleDefinitionGrpIterator != NULL)
			delete (*mADCRuleDefinitionGrpIterator);
			mADCRuleDefinitionGrpIterator++;
		}
		delete mADCRuleDefinitionGrpList;
	}
	if(mADCRuleNameList != NULL){
		mADCRuleNameIterator = mADCRuleNameList->begin();
		while(mADCRuleNameIterator != mADCRuleNameList->end()){
			delete (*mADCRuleNameIterator);
			mADCRuleNameIterator++;
		}
		delete mADCRuleNameList;
	}
	if(mADCRuleBaseNameList != NULL){
		mADCRuleBaseNameIterator = mADCRuleBaseNameList->begin();
		while(mADCRuleBaseNameIterator != mADCRuleBaseNameList->end()){
			delete (*mADCRuleBaseNameIterator);
			mADCRuleBaseNameIterator++;
		}
		delete mADCRuleBaseNameList;
	}
	if(mMonitoringFlags != NULL)
		delete mMonitoringFlags;
	if(mRuleActivationTime != NULL)
		delete mRuleActivationTime;
	if(mRuleDeactivationTime != NULL)
		delete mRuleDeactivationTime;
}

Unsigned32* ADCRuleInstall::setMonitoringFlags(){
	if(mMonitoringFlags == NULL)
	{
		mMonitoringFlags = new Unsigned32();
		mTagsPresent[ADCRuleInstall_MONITORINGFLAGS] = 1;
		return mMonitoringFlags;
	}
	return mMonitoringFlags;
}

void ADCRuleInstall::resetMonitoringFlags(){
	mTagsPresent[ADCRuleInstall_MONITORINGFLAGS] = 0;
	if(mMonitoringFlags != NULL)
	{
		delete mMonitoringFlags; 
		mMonitoringFlags = NULL;
	}
}

Time* ADCRuleInstall::setRuleActivationTime(){
	mMandatoryAvpSetVal [ADCRuleInstall_RULEACTIVATIONTIME] = 1;
	if(mRuleActivationTime == NULL)
	{
		mRuleActivationTime = new Time();
		mTagsPresent[ADCRuleInstall_RULEACTIVATIONTIME] = 1;
		return mRuleActivationTime;
	}
	return mRuleActivationTime;
}

void ADCRuleInstall::resetRuleActivationTime(){
	mTagsPresent[ADCRuleInstall_RULEACTIVATIONTIME] = 0;
	if(mRuleActivationTime != NULL)
	{
		delete mRuleActivationTime; 
		mRuleActivationTime = NULL;
	}
}

Time* ADCRuleInstall::setRuleDeactivationTime(){
	mMandatoryAvpSetVal [ADCRuleInstall_RULEDEACTIVATIONTIME] = 1;
	if(mRuleDeactivationTime == NULL)
	{
		mRuleDeactivationTime = new Time();
		mTagsPresent[ADCRuleInstall_RULEDEACTIVATIONTIME] = 1;
		return mRuleDeactivationTime;
	}
	return mRuleDeactivationTime;
}

void ADCRuleInstall::resetRuleDeactivationTime(){
	mTagsPresent[ADCRuleInstall_RULEDEACTIVATIONTIME] = 0;
	if(mRuleDeactivationTime != NULL)
	{
		delete mRuleDeactivationTime; 
		mRuleDeactivationTime = NULL;
	}
}

list<ADCRuleDefinition*>* ADCRuleInstall::getADCRuleDefinitionGrpList()
{
	if(mADCRuleDefinitionGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ADCRuleDefinition is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mADCRuleDefinitionGrpList)
	{
		if(mADCRuleDefinitionGrpList != NULL)
		{
		if(mADCRuleDefinitionGrpList->size() == 0)
		{
			mTagsPresent[ADCRuleInstall_ADCRULEDEFINITION] = 0;
			mADCRuleDefinitionGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ADCRuleDefinition is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ADCRuleDefinition is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleDefinition")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mADCRuleDefinitionGrpList;
}

list<ADCRuleDefinition*>* ADCRuleInstall::setADCRuleDefinitionGrpList(){
	mTagsPresent[ADCRuleInstall_ADCRULEDEFINITION] = 1;
	if(mADCRuleDefinitionGrpList == NULL)
		mADCRuleDefinitionGrpList = new list<ADCRuleDefinition*>;
	mMandatoryAvpSetVal[ADCRuleInstall_ADCRULEDEFINITION] = 1;
	mADCRuleDefinitionGrpList->clear();
	return mADCRuleDefinitionGrpList;
}

void ADCRuleInstall::resetADCRuleDefinitionGrpList(){
	mTagsPresent[ADCRuleInstall_ADCRULEDEFINITION] = 0;
	if(mADCRuleDefinitionGrpList != NULL)
		delete mADCRuleDefinitionGrpList;
}

list<OctetString*>* ADCRuleInstall::getADCRuleNameList()
{
	if(mADCRuleNameList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ADCRuleName is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mADCRuleNameList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ADCRuleName is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleName")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mADCRuleNameList;
}

list<OctetString*>* ADCRuleInstall::setADCRuleNameList() {
	mTagsPresent[ADCRuleInstall_ADCRULENAME] = 1;
	if(mADCRuleNameList == NULL)
		mADCRuleNameList = new list<OctetString*>;
	mMandatoryAvpSetVal [ADCRuleInstall_ADCRULENAME] = 1;
	mADCRuleNameList->clear();
	return mADCRuleNameList;
}

void ADCRuleInstall::resetADCRuleNameList(){
	mTagsPresent[ADCRuleInstall_ADCRULENAME] = 0;
	if(mADCRuleNameList != NULL)
		delete mADCRuleNameList;
}

list<OctetString*>* ADCRuleInstall::getADCRuleBaseNameList()
{
	if(mADCRuleBaseNameList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ADCRuleBaseName is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mADCRuleBaseNameList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ADCRuleBaseName is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleBaseName")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mADCRuleBaseNameList;
}

list<OctetString*>* ADCRuleInstall::setADCRuleBaseNameList() {
	mTagsPresent[ADCRuleInstall_ADCRULEBASENAME] = 1;
	if(mADCRuleBaseNameList == NULL)
		mADCRuleBaseNameList = new list<OctetString*>;
	mMandatoryAvpSetVal [ADCRuleInstall_ADCRULEBASENAME] = 1;
	mADCRuleBaseNameList->clear();
	return mADCRuleBaseNameList;
}

void ADCRuleInstall::resetADCRuleBaseNameList(){
	mTagsPresent[ADCRuleInstall_ADCRULEBASENAME] = 0;
	if(mADCRuleBaseNameList != NULL)
		delete mADCRuleBaseNameList;
}

Unsigned32* ADCRuleInstall::getMonitoringFlags(){
	if(NULL == mMonitoringFlags) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MonitoringFlags is Null");
		throw lTssDiaMsgException;
	}
	if(!mMonitoringFlags->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMonitoringFlags->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MonitoringFlags is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMonitoringFlags->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMonitoringFlags->Decode(mspByteArray.get(), mMonitoringFlags->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MonitoringFlags")     ;
			throw lTssDiaMsgException;
		}
		mMonitoringFlags->mAvpDecodedFlag = true;
	}
	return mMonitoringFlags;
}

Time* ADCRuleInstall::getRuleActivationTime(){
	if(NULL == mRuleActivationTime) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RuleActivationTime is Null");
		throw lTssDiaMsgException;
	}
	if(!mRuleActivationTime->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRuleActivationTime->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RuleActivationTime is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRuleActivationTime->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRuleActivationTime->Decode(mspByteArray.get(), mRuleActivationTime->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RuleActivationTime")     ;
			throw lTssDiaMsgException;
		}
		mRuleActivationTime->mAvpDecodedFlag = true;
	}
	return mRuleActivationTime;
}

Time* ADCRuleInstall::getRuleDeactivationTime(){
	if(NULL == mRuleDeactivationTime) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RuleDeactivationTime is Null");
		throw lTssDiaMsgException;
	}
	if(!mRuleDeactivationTime->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRuleDeactivationTime->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RuleDeactivationTime is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRuleDeactivationTime->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRuleDeactivationTime->Decode(mspByteArray.get(), mRuleDeactivationTime->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RuleDeactivationTime")     ;
			throw lTssDiaMsgException;
		}
		mRuleDeactivationTime->mAvpDecodedFlag = true;
	}
	return mRuleDeactivationTime;
}



int ADCRuleInstall::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case ADCRuleInstall_ADCRULEDEFINITION:
			{
				if( mADCRuleDefinitionGrpList->size() <= 0) {
					break;
				}

				mADCRuleDefinitionGrpIterator = this->getADCRuleDefinitionGrpList()->begin();
				while(mADCRuleDefinitionGrpIterator != mADCRuleDefinitionGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(1094);
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
					if(((*mADCRuleDefinitionGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ADCRuleDefinition");
						throw lTssDiaMsgException;
					}
					
					mADCRuleDefinitionGrpIterator++;
				}
				}
				break;
			case ADCRuleInstall_ADCRULENAME:
			{
					if( mADCRuleNameList->size() <= 0) {
						break;
					}

					mADCRuleNameIterator = this->getADCRuleNameList()->begin();
					while(mADCRuleNameIterator != mADCRuleNameList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(1096);
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
					if(!(*mADCRuleNameIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mADCRuleNameIterator)->getAvpOffsetLen().first], (*mADCRuleNameIterator)->getAvpOffsetLen().second);
						array->offset += (*mADCRuleNameIterator)->getAvpOffsetLen().second;
						array->size += (*mADCRuleNameIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mADCRuleNameIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mADCRuleNameIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ADCRuleName");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mADCRuleNameIterator++;
						continue;
					}
						if(((*mADCRuleNameIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mADCRuleNameIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ADCRuleName");
							throw lTssDiaMsgException;
						}
						mADCRuleNameIterator++;
				}
				}
				break;
			case ADCRuleInstall_ADCRULEBASENAME:
			{
					if( mADCRuleBaseNameList->size() <= 0) {
						break;
					}

					mADCRuleBaseNameIterator = this->getADCRuleBaseNameList()->begin();
					while(mADCRuleBaseNameIterator != mADCRuleBaseNameList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(1095);
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
					if(!(*mADCRuleBaseNameIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mADCRuleBaseNameIterator)->getAvpOffsetLen().first], (*mADCRuleBaseNameIterator)->getAvpOffsetLen().second);
						array->offset += (*mADCRuleBaseNameIterator)->getAvpOffsetLen().second;
						array->size += (*mADCRuleBaseNameIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mADCRuleBaseNameIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mADCRuleBaseNameIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ADCRuleBaseName");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mADCRuleBaseNameIterator++;
						continue;
					}
						if(((*mADCRuleBaseNameIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mADCRuleBaseNameIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ADCRuleBaseName");
							throw lTssDiaMsgException;
						}
						mADCRuleBaseNameIterator++;
				}
				}
				break;
			case ADCRuleInstall_MONITORINGFLAGS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2828);
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
					if(!mMonitoringFlags->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMonitoringFlags->getAvpOffsetLen().first], mMonitoringFlags->getAvpOffsetLen().second);
						array->offset += mMonitoringFlags->getAvpOffsetLen().second;
						array->size += mMonitoringFlags->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MonitoringFlags");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mMonitoringFlags->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MonitoringFlags");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ADCRuleInstall_RULEACTIVATIONTIME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1043);
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
					if(!mRuleActivationTime->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRuleActivationTime->getAvpOffsetLen().first], mRuleActivationTime->getAvpOffsetLen().second);
						array->offset += mRuleActivationTime->getAvpOffsetLen().second;
						array->size += mRuleActivationTime->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mRuleActivationTime->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mRuleActivationTime->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RuleActivationTime");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mRuleActivationTime->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mRuleActivationTime->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RuleActivationTime");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ADCRuleInstall_RULEDEACTIVATIONTIME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1044);
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
					if(!mRuleDeactivationTime->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRuleDeactivationTime->getAvpOffsetLen().first], mRuleDeactivationTime->getAvpOffsetLen().second);
						array->offset += mRuleDeactivationTime->getAvpOffsetLen().second;
						array->size += mRuleDeactivationTime->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mRuleDeactivationTime->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mRuleDeactivationTime->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RuleDeactivationTime");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mRuleDeactivationTime->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mRuleDeactivationTime->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RuleDeactivationTime");
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


int ADCRuleInstall::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 1094:
				{
						mMandatoryAvpSetVal [ADCRuleInstall_ADCRULEDEFINITION] = 1;
					mTagsPresent[ADCRuleInstall_ADCRULEDEFINITION] = 1;
					ADCRuleDefinition *lADCRuleDefinition = new ADCRuleDefinition();
					if( lADCRuleDefinition == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleDefinition");
						throw lTssDiaMsgException;
					}
					lADCRuleDefinition->setAvpCode(1094);
					lADCRuleDefinition->SetDataType((DiameterDataType)6);
					lADCRuleDefinition->mspByteArray = mspByteArray;
					lADCRuleDefinition->mAvpDecodedFlag = false;
					lADCRuleDefinition->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mADCRuleDefinitionGrpList == NULL)
						this->setADCRuleDefinitionGrpList();
					mADCRuleDefinitionGrpList->push_back(lADCRuleDefinition);
					mBaseInterfaceList.push_back(lADCRuleDefinition);
					
				}
				break;
			case 1096:
				{
						mMandatoryAvpSetVal [ADCRuleInstall_ADCRULENAME] = 1;
					mTagsPresent[ADCRuleInstall_ADCRULENAME] = 1;
					OctetString *lADCRuleName = new OctetString();
					if( lADCRuleName == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleName");
						throw lTssDiaMsgException;
					}
					lADCRuleName->setAvpCode(1096);
					lADCRuleName->setAvpVendorId(lVenderId);
					lADCRuleName->SetDataType((DiameterDataType)5);
					lADCRuleName->mspByteArray = mspByteArray;
					lADCRuleName->mAvpDecodedFlag = false;
					lADCRuleName->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mADCRuleNameList == NULL)
						this->setADCRuleNameList();
					mADCRuleNameList->push_back(lADCRuleName);
					
				}
				break;
			case 1095:
				{
						mMandatoryAvpSetVal [ADCRuleInstall_ADCRULEBASENAME] = 1;
					mTagsPresent[ADCRuleInstall_ADCRULEBASENAME] = 1;
					OctetString *lADCRuleBaseName = new OctetString();
					if( lADCRuleBaseName == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleBaseName");
						throw lTssDiaMsgException;
					}
					lADCRuleBaseName->setAvpCode(1095);
					lADCRuleBaseName->setAvpVendorId(lVenderId);
					lADCRuleBaseName->SetDataType((DiameterDataType)5);
					lADCRuleBaseName->mspByteArray = mspByteArray;
					lADCRuleBaseName->mAvpDecodedFlag = false;
					lADCRuleBaseName->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mADCRuleBaseNameList == NULL)
						this->setADCRuleBaseNameList();
					mADCRuleBaseNameList->push_back(lADCRuleBaseName);
					
				}
				break;
			case 2828:
				{
					if( NULL == this->setMonitoringFlags())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MonitoringFlags");
						throw lTssDiaMsgException;
					}
					mMonitoringFlags->setAvpCode(2828);
					mMonitoringFlags->setAvpVendorId(lVenderId);
					mMonitoringFlags->SetDataType((DiameterDataType)3);
					mMonitoringFlags->mspByteArray = mspByteArray;
					mMonitoringFlags->mAvpDecodedFlag = false;
					mMonitoringFlags->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1043:
				{
						mMandatoryAvpSetVal [ADCRuleInstall_RULEACTIVATIONTIME] = 1;
					if( NULL == this->setRuleActivationTime())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RuleActivationTime");
						throw lTssDiaMsgException;
					}
					mRuleActivationTime->setAvpCode(1043);
					mRuleActivationTime->setAvpVendorId(lVenderId);
					mRuleActivationTime->SetDataType((DiameterDataType)9);
					mRuleActivationTime->mspByteArray = mspByteArray;
					mRuleActivationTime->mAvpDecodedFlag = false;
					mRuleActivationTime->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1044:
				{
						mMandatoryAvpSetVal [ADCRuleInstall_RULEDEACTIVATIONTIME] = 1;
					if( NULL == this->setRuleDeactivationTime())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RuleDeactivationTime");
						throw lTssDiaMsgException;
					}
					mRuleDeactivationTime->setAvpCode(1044);
					mRuleDeactivationTime->setAvpVendorId(lVenderId);
					mRuleDeactivationTime->SetDataType((DiameterDataType)9);
					mRuleDeactivationTime->mspByteArray = mspByteArray;
					mRuleDeactivationTime->mAvpDecodedFlag = false;
					mRuleDeactivationTime->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* ADCRuleInstall::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleInstall")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1096:
			{
				if(mADCRuleNameList != NULL && mADCRuleNameList->size() > 0)
					return (mADCRuleNameList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 1095:
			{
				if(mADCRuleBaseNameList != NULL && mADCRuleBaseNameList->size() > 0)
					return (mADCRuleBaseNameList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 2828:
			{
				if(mMonitoringFlags != NULL)
					return mMonitoringFlags->Find(array, avpCode);
				else
					return NULL;
			}
			case 1043:
			{
				if(mRuleActivationTime != NULL)
					return mRuleActivationTime->Find(array, avpCode);
				else
					return NULL;
			}
			case 1044:
			{
				if(mRuleDeactivationTime != NULL)
					return mRuleDeactivationTime->Find(array, avpCode);
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


BOOLEAN ADCRuleInstall::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleInstall")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1094:
			{
				if(mADCRuleDefinitionGrpList != NULL)
				{
					for(auto itr = mADCRuleDefinitionGrpList->begin(); itr != mADCRuleDefinitionGrpList->end(); ++itr)
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
			case 1096:
			{
				if(mADCRuleNameList != NULL)
				{
					for(auto itr = mADCRuleNameList->begin(); itr != mADCRuleNameList->end(); ++itr)
					{
						DiameterBaseInterface* inf =  (*itr)->Find(this->mspByteArray.get(), avpCode);
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
				}
				break;
			}
			case 1095:
			{
				if(mADCRuleBaseNameList != NULL)
				{
					for(auto itr = mADCRuleBaseNameList->begin(); itr != mADCRuleBaseNameList->end(); ++itr)
					{
						DiameterBaseInterface* inf =  (*itr)->Find(this->mspByteArray.get(), avpCode);
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
				}
				break;
			}
			case 2828:
			{
				if(mMonitoringFlags != NULL)
				{
					DiameterBaseInterface* inf =  mMonitoringFlags->Find(this->mspByteArray.get(), avpCode);
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
			case 1043:
			{
				if(mRuleActivationTime != NULL)
				{
					DiameterBaseInterface* inf =  mRuleActivationTime->Find(this->mspByteArray.get(), avpCode);
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
			case 1044:
			{
				if(mRuleDeactivationTime != NULL)
				{
					DiameterBaseInterface* inf =  mRuleDeactivationTime->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> ADCRuleInstall::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN ADCRuleInstall::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleInstall")     ;
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
			case 1094:
			{
				if(mADCRuleDefinitionGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mADCRuleDefinitionGrpList->begin(); itr != mADCRuleDefinitionGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mADCRuleDefinitionGrpList->begin(); itr != mADCRuleDefinitionGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 1096:
			{
				if(mADCRuleNameList != NULL)
				{
					for(auto itr = mADCRuleNameList->begin(); itr != mADCRuleNameList->end(); ++itr)
					{
						DiameterBaseInterface* inf =  (*itr)->Find(this->mspByteArray.get(), avpCode);
						if(inf != NULL)
						{
							pBaseInterface.push_back(inf);
						}
					}

				}
				break;
			}
			case 1095:
			{
				if(mADCRuleBaseNameList != NULL)
				{
					for(auto itr = mADCRuleBaseNameList->begin(); itr != mADCRuleBaseNameList->end(); ++itr)
					{
						DiameterBaseInterface* inf =  (*itr)->Find(this->mspByteArray.get(), avpCode);
						if(inf != NULL)
						{
							pBaseInterface.push_back(inf);
						}
					}

				}
				break;
			}
			case 2828:
			{
				if(mMonitoringFlags != NULL)
				{
					DiameterBaseInterface* inf =  mMonitoringFlags->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1043:
			{
				if(mRuleActivationTime != NULL)
				{
					DiameterBaseInterface* inf =  mRuleActivationTime->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1044:
			{
				if(mRuleDeactivationTime != NULL)
				{
					DiameterBaseInterface* inf =  mRuleDeactivationTime->Find(this->mspByteArray.get(), avpCode);
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


INT32 ADCRuleInstall::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 ADCRuleInstall::getAvpCode()
{
	return mAvpCode;
}
INT32 ADCRuleInstall::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 ADCRuleInstall::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 ADCRuleInstall::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> ADCRuleInstall::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void ADCRuleInstall::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case ADCRuleInstall_ADCRULEDEFINITION:
			{
				if( mADCRuleDefinitionGrpList->size() <= 0) {
					break;
				}

				mADCRuleDefinitionGrpIterator = this->getADCRuleDefinitionGrpList()->begin();
				while(mADCRuleDefinitionGrpIterator != this->getADCRuleDefinitionGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1094" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ADCRuleDefinition" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mADCRuleDefinitionGrpIterator)->Display(tab+1);
					mADCRuleDefinitionGrpIterator++;

				};

			}
				break;
			case ADCRuleInstall_ADCRULENAME:
			{
				if( mADCRuleNameList->size() <= 0) {
					break;
				}

				mADCRuleNameIterator = this->getADCRuleNameList()->begin();
				while(mADCRuleNameIterator != this->getADCRuleNameList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1096" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ADCRuleName" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mADCRuleNameIterator)->Display(tab+1);
					mADCRuleNameIterator++;

				};

			}
				break;
			case ADCRuleInstall_ADCRULEBASENAME:
			{
				if( mADCRuleBaseNameList->size() <= 0) {
					break;
				}

				mADCRuleBaseNameIterator = this->getADCRuleBaseNameList()->begin();
				while(mADCRuleBaseNameIterator != this->getADCRuleBaseNameList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1095" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ADCRuleBaseName" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mADCRuleBaseNameIterator)->Display(tab+1);
					mADCRuleBaseNameIterator++;

				};

			}
				break;
			case ADCRuleInstall_MONITORINGFLAGS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2828" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MonitoringFlags" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getMonitoringFlags()->Display(tab+1);
			}
				break;
			case ADCRuleInstall_RULEACTIVATIONTIME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1043" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RuleActivationTime" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getRuleActivationTime()->Display(tab+1);
			}
				break;
			case ADCRuleInstall_RULEDEACTIVATIONTIME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1044" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RuleDeactivationTime" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getRuleDeactivationTime()->Display(tab+1);
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


BOOLEAN ADCRuleInstall::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<6> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case ADCRuleInstall_ADCRULEDEFINITION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1094");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1094", lMissingAvpInfo);
			}
				break;
			case ADCRuleInstall_ADCRULENAME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1096");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1096", lMissingAvpInfo);
			}
				break;
			case ADCRuleInstall_ADCRULEBASENAME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1095");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1095", lMissingAvpInfo);
			}
				break;
			case ADCRuleInstall_MONITORINGFLAGS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2828");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2828", lMissingAvpInfo);
			}
				break;
			case ADCRuleInstall_RULEACTIVATIONTIME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1043");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1043", lMissingAvpInfo);
			}
				break;
			case ADCRuleInstall_RULEDEACTIVATIONTIME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1044");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1044", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
