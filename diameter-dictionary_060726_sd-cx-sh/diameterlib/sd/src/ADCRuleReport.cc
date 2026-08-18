#include "sd/include/ADCRuleReport.h"

using namespace SD;
BOOLEAN ADCRuleReport::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

ADCRuleReport::ADCRuleReport()
{
	mADCRuleNameList = NULL;
	mADCRuleBaseNameList = NULL;
	mPCCRuleStatus = NULL;
	mRuleFailureCode = NULL;
	mFinalUnitIndicationGrp = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<5>(string("11111"));
	mMandatoryAvpSetVal.reset();
}

ADCRuleReport::~ADCRuleReport()
{
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
	if(mPCCRuleStatus != NULL)
		delete mPCCRuleStatus;
	if(mRuleFailureCode != NULL)
		delete mRuleFailureCode;
	if(mFinalUnitIndicationGrp != NULL)
		delete mFinalUnitIndicationGrp;
}

PCCRuleStatus* ADCRuleReport::setPCCRuleStatus(){
	mMandatoryAvpSetVal [ADCRuleReport_PCCRULESTATUS] = 1;
	if(mPCCRuleStatus == NULL)
	{
		mPCCRuleStatus = new PCCRuleStatus();
		mTagsPresent[ADCRuleReport_PCCRULESTATUS] = 1;
		return mPCCRuleStatus;
	}
	return mPCCRuleStatus;
}

void ADCRuleReport::resetPCCRuleStatus(){
	mTagsPresent[ADCRuleReport_PCCRULESTATUS] = 0;
	if(mPCCRuleStatus != NULL)
	{
		delete mPCCRuleStatus; 
		mPCCRuleStatus = NULL;
	}
}

RuleFailureCode* ADCRuleReport::setRuleFailureCode(){
	mMandatoryAvpSetVal [ADCRuleReport_RULEFAILURECODE] = 1;
	if(mRuleFailureCode == NULL)
	{
		mRuleFailureCode = new RuleFailureCode();
		mTagsPresent[ADCRuleReport_RULEFAILURECODE] = 1;
		return mRuleFailureCode;
	}
	return mRuleFailureCode;
}

void ADCRuleReport::resetRuleFailureCode(){
	mTagsPresent[ADCRuleReport_RULEFAILURECODE] = 0;
	if(mRuleFailureCode != NULL)
	{
		delete mRuleFailureCode; 
		mRuleFailureCode = NULL;
	}
}

list<OctetString*>* ADCRuleReport::getADCRuleNameList()
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

list<OctetString*>* ADCRuleReport::setADCRuleNameList() {
	mTagsPresent[ADCRuleReport_ADCRULENAME] = 1;
	if(mADCRuleNameList == NULL)
		mADCRuleNameList = new list<OctetString*>;
	mMandatoryAvpSetVal [ADCRuleReport_ADCRULENAME] = 1;
	mADCRuleNameList->clear();
	return mADCRuleNameList;
}

void ADCRuleReport::resetADCRuleNameList(){
	mTagsPresent[ADCRuleReport_ADCRULENAME] = 0;
	if(mADCRuleNameList != NULL)
		delete mADCRuleNameList;
}

list<OctetString*>* ADCRuleReport::getADCRuleBaseNameList()
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

list<OctetString*>* ADCRuleReport::setADCRuleBaseNameList() {
	mTagsPresent[ADCRuleReport_ADCRULEBASENAME] = 1;
	if(mADCRuleBaseNameList == NULL)
		mADCRuleBaseNameList = new list<OctetString*>;
	mMandatoryAvpSetVal [ADCRuleReport_ADCRULEBASENAME] = 1;
	mADCRuleBaseNameList->clear();
	return mADCRuleBaseNameList;
}

void ADCRuleReport::resetADCRuleBaseNameList(){
	mTagsPresent[ADCRuleReport_ADCRULEBASENAME] = 0;
	if(mADCRuleBaseNameList != NULL)
		delete mADCRuleBaseNameList;
}

PCCRuleStatus* ADCRuleReport::getPCCRuleStatus(){
	if(NULL == mPCCRuleStatus) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PCCRuleStatus is Null");
		throw lTssDiaMsgException;
	}
	if(!mPCCRuleStatus->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPCCRuleStatus->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PCCRuleStatus is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPCCRuleStatus->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPCCRuleStatus->Decode(mspByteArray.get(), mPCCRuleStatus->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PCCRuleStatus")     ;
			throw lTssDiaMsgException;
		}
		mPCCRuleStatus->mAvpDecodedFlag = true;
	}
	return mPCCRuleStatus;
}

RuleFailureCode* ADCRuleReport::getRuleFailureCode(){
	if(NULL == mRuleFailureCode) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RuleFailureCode is Null");
		throw lTssDiaMsgException;
	}
	if(!mRuleFailureCode->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRuleFailureCode->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RuleFailureCode is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRuleFailureCode->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRuleFailureCode->Decode(mspByteArray.get(), mRuleFailureCode->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RuleFailureCode")     ;
			throw lTssDiaMsgException;
		}
		mRuleFailureCode->mAvpDecodedFlag = true;
	}
	return mRuleFailureCode;
}

FinalUnitIndication* ADCRuleReport::getFinalUnitIndication()
{
	if(mFinalUnitIndicationGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FinalUnitIndication is Null");
		throw lTssDiaMsgException;
	}
	if(!mFinalUnitIndicationGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mFinalUnitIndicationGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FinalUnitIndication is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mFinalUnitIndicationGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mFinalUnitIndicationGrp->Decode(mspByteArray.get(), mFinalUnitIndicationGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FinalUnitIndication")     ;
			throw lTssDiaMsgException;
		}
		mFinalUnitIndicationGrp->mAvpDecodedFlag = true;
	}
	return mFinalUnitIndicationGrp;
}

FinalUnitIndication* ADCRuleReport::setFinalUnitIndication(){
	if(mFinalUnitIndicationGrp == NULL)
		mFinalUnitIndicationGrp = new FinalUnitIndication();
	mTagsPresent[ADCRuleReport_FINALUNITINDICATION] = 1;
	mMandatoryAvpSetVal[ADCRuleReport_FINALUNITINDICATION] = 1;
	return mFinalUnitIndicationGrp;
}

void ADCRuleReport::resetFinalUnitIndication(){
	mTagsPresent[ADCRuleReport_FINALUNITINDICATION] = 0;
	if(mFinalUnitIndicationGrp != NULL)
		delete mFinalUnitIndicationGrp;
}



int ADCRuleReport::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case ADCRuleReport_ADCRULENAME:
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
			case ADCRuleReport_ADCRULEBASENAME:
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
			case ADCRuleReport_PCCRULESTATUS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1019);
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
					if(!mPCCRuleStatus->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mPCCRuleStatus->getAvpOffsetLen().first], mPCCRuleStatus->getAvpOffsetLen().second);
						array->offset += mPCCRuleStatus->getAvpOffsetLen().second;
						array->size += mPCCRuleStatus->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PCCRuleStatus");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mPCCRuleStatus->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PCCRuleStatus");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ADCRuleReport_RULEFAILURECODE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1031);
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
					if(!mRuleFailureCode->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRuleFailureCode->getAvpOffsetLen().first], mRuleFailureCode->getAvpOffsetLen().second);
						array->offset += mRuleFailureCode->getAvpOffsetLen().second;
						array->size += mRuleFailureCode->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RuleFailureCode");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mRuleFailureCode->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RuleFailureCode");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ADCRuleReport_FINALUNITINDICATION:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(430);
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
				if((this->getFinalUnitIndication()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FinalUnitIndication");
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


int ADCRuleReport::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 1096:
				{
						mMandatoryAvpSetVal [ADCRuleReport_ADCRULENAME] = 1;
					mTagsPresent[ADCRuleReport_ADCRULENAME] = 1;
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
						mMandatoryAvpSetVal [ADCRuleReport_ADCRULEBASENAME] = 1;
					mTagsPresent[ADCRuleReport_ADCRULEBASENAME] = 1;
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
			case 1019:
				{
						mMandatoryAvpSetVal [ADCRuleReport_PCCRULESTATUS] = 1;
					if( NULL == this->setPCCRuleStatus())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PCCRuleStatus");
						throw lTssDiaMsgException;
					}
					mPCCRuleStatus->setAvpCode(1019);
					mPCCRuleStatus->setAvpVendorId(lVenderId);
					mPCCRuleStatus->SetDataType((DiameterDataType)7);
					mPCCRuleStatus->mspByteArray = mspByteArray;
					mPCCRuleStatus->mAvpDecodedFlag = false;
					mPCCRuleStatus->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1031:
				{
						mMandatoryAvpSetVal [ADCRuleReport_RULEFAILURECODE] = 1;
					if( NULL == this->setRuleFailureCode())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RuleFailureCode");
						throw lTssDiaMsgException;
					}
					mRuleFailureCode->setAvpCode(1031);
					mRuleFailureCode->setAvpVendorId(lVenderId);
					mRuleFailureCode->SetDataType((DiameterDataType)7);
					mRuleFailureCode->mspByteArray = mspByteArray;
					mRuleFailureCode->mAvpDecodedFlag = false;
					mRuleFailureCode->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 430:
				{
						mMandatoryAvpSetVal [ADCRuleReport_FINALUNITINDICATION] = 1;
					mTagsPresent[ADCRuleReport_FINALUNITINDICATION] = 1;
						if( NULL == this->setFinalUnitIndication()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FinalUnitIndication");
						throw lTssDiaMsgException;
						}
					mFinalUnitIndicationGrp->setAvpCode(430);
					mFinalUnitIndicationGrp->SetDataType((DiameterDataType)6);
					mFinalUnitIndicationGrp->mspByteArray = mspByteArray;
					mFinalUnitIndicationGrp->mAvpDecodedFlag = false;
					mFinalUnitIndicationGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mFinalUnitIndicationGrp);
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


DiameterBaseInterface* ADCRuleReport::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleReport")     ;
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
			case 1019:
			{
				if(mPCCRuleStatus != NULL)
					return mPCCRuleStatus->Find(array, avpCode);
				else
					return NULL;
			}
			case 1031:
			{
				if(mRuleFailureCode != NULL)
					return mRuleFailureCode->Find(array, avpCode);
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


BOOLEAN ADCRuleReport::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleReport")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
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
			case 1019:
			{
				if(mPCCRuleStatus != NULL)
				{
					DiameterBaseInterface* inf =  mPCCRuleStatus->Find(this->mspByteArray.get(), avpCode);
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
			case 1031:
			{
				if(mRuleFailureCode != NULL)
				{
					DiameterBaseInterface* inf =  mRuleFailureCode->Find(this->mspByteArray.get(), avpCode);
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
			case 430:
			{
				if(mFinalUnitIndicationGrp != NULL)
				{
						pBaseInterface.push_back(mFinalUnitIndicationGrp);
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
std::shared_ptr<byteArray> ADCRuleReport::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN ADCRuleReport::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleReport")     ;
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
			case 1019:
			{
				if(mPCCRuleStatus != NULL)
				{
					DiameterBaseInterface* inf =  mPCCRuleStatus->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1031:
			{
				if(mRuleFailureCode != NULL)
				{
					DiameterBaseInterface* inf =  mRuleFailureCode->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 430:
			{
				if(mFinalUnitIndicationGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mFinalUnitIndicationGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mFinalUnitIndicationGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
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


INT32 ADCRuleReport::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 ADCRuleReport::getAvpCode()
{
	return mAvpCode;
}
INT32 ADCRuleReport::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 ADCRuleReport::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 ADCRuleReport::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> ADCRuleReport::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void ADCRuleReport::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case ADCRuleReport_ADCRULENAME:
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
			case ADCRuleReport_ADCRULEBASENAME:
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
			case ADCRuleReport_PCCRULESTATUS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1019" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PCCRuleStatus" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getPCCRuleStatus()->Display(tab+1);
			}
				break;
			case ADCRuleReport_RULEFAILURECODE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1031" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RuleFailureCode" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getRuleFailureCode()->Display(tab+1);
			}
				break;
			case ADCRuleReport_FINALUNITINDICATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "430" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FinalUnitIndication" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getFinalUnitIndication()->Display(tab+1);
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


BOOLEAN ADCRuleReport::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<5> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case ADCRuleReport_ADCRULENAME:
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
			case ADCRuleReport_ADCRULEBASENAME:
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
			case ADCRuleReport_PCCRULESTATUS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1019");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1019", lMissingAvpInfo);
			}
				break;
			case ADCRuleReport_RULEFAILURECODE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1031");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1031", lMissingAvpInfo);
			}
				break;
			case ADCRuleReport_FINALUNITINDICATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 430");
				}
				else
					sprintf(lMissingAvpInfo, "%s,430", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
