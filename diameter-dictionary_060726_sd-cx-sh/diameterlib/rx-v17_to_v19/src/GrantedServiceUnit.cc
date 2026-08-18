#include "rx/include/GrantedServiceUnit.h"

using namespace RX;
BOOLEAN GrantedServiceUnit::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

GrantedServiceUnit::GrantedServiceUnit()
{
	mTariffTimeChange = NULL;
	mCCTime = NULL;
	mCCMoneyGrpList = NULL;
	mCCTotalOctets = NULL;
	mCCInputOctets = NULL;
	mCCOutputOctets = NULL;
	mCCServiceSpecificUnits = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<7>(string("1111111"));
	mMandatoryAvpSetVal.reset();
}

GrantedServiceUnit::~GrantedServiceUnit()
{
	if(mTariffTimeChange != NULL)
		delete mTariffTimeChange;
	if(mCCTime != NULL)
		delete mCCTime;
	if(mCCMoneyGrpList != NULL){
		mCCMoneyGrpIterator = mCCMoneyGrpList->begin();
		while(mCCMoneyGrpIterator != mCCMoneyGrpList->end()){
	if(*mCCMoneyGrpIterator != NULL)
			delete (*mCCMoneyGrpIterator);
			mCCMoneyGrpIterator++;
		}
		delete mCCMoneyGrpList;
	}
	if(mCCTotalOctets != NULL)
		delete mCCTotalOctets;
	if(mCCInputOctets != NULL)
		delete mCCInputOctets;
	if(mCCOutputOctets != NULL)
		delete mCCOutputOctets;
	if(mCCServiceSpecificUnits != NULL)
		delete mCCServiceSpecificUnits;
}

TariffTimeChange* GrantedServiceUnit::setTariffTimeChange(){
	mMandatoryAvpSetVal [GrantedServiceUnit_TARIFFTIMECHANGE] = 1;
	if(mTariffTimeChange == NULL)
	{
		mTariffTimeChange = new TariffTimeChange();
		mTagsPresent[GrantedServiceUnit_TARIFFTIMECHANGE] = 1;
		return mTariffTimeChange;
	}
	return mTariffTimeChange;
}

void GrantedServiceUnit::resetTariffTimeChange(){
	mTagsPresent[GrantedServiceUnit_TARIFFTIMECHANGE] = 0;
	if(mTariffTimeChange != NULL)
	{
		delete mTariffTimeChange; 
		mTariffTimeChange = NULL;
	}
}

Unsigned32* GrantedServiceUnit::setCCTime(){
	mMandatoryAvpSetVal [GrantedServiceUnit_CCTIME] = 1;
	if(mCCTime == NULL)
	{
		mCCTime = new Unsigned32();
		mTagsPresent[GrantedServiceUnit_CCTIME] = 1;
		return mCCTime;
	}
	return mCCTime;
}

void GrantedServiceUnit::resetCCTime(){
	mTagsPresent[GrantedServiceUnit_CCTIME] = 0;
	if(mCCTime != NULL)
	{
		delete mCCTime; 
		mCCTime = NULL;
	}
}

Unsigned64* GrantedServiceUnit::setCCTotalOctets(){
	mMandatoryAvpSetVal [GrantedServiceUnit_CCTOTALOCTETS] = 1;
	if(mCCTotalOctets == NULL)
	{
		mCCTotalOctets = new Unsigned64();
		mTagsPresent[GrantedServiceUnit_CCTOTALOCTETS] = 1;
		return mCCTotalOctets;
	}
	return mCCTotalOctets;
}

void GrantedServiceUnit::resetCCTotalOctets(){
	mTagsPresent[GrantedServiceUnit_CCTOTALOCTETS] = 0;
	if(mCCTotalOctets != NULL)
	{
		delete mCCTotalOctets; 
		mCCTotalOctets = NULL;
	}
}

Unsigned64* GrantedServiceUnit::setCCInputOctets(){
	mMandatoryAvpSetVal [GrantedServiceUnit_CCINPUTOCTETS] = 1;
	if(mCCInputOctets == NULL)
	{
		mCCInputOctets = new Unsigned64();
		mTagsPresent[GrantedServiceUnit_CCINPUTOCTETS] = 1;
		return mCCInputOctets;
	}
	return mCCInputOctets;
}

void GrantedServiceUnit::resetCCInputOctets(){
	mTagsPresent[GrantedServiceUnit_CCINPUTOCTETS] = 0;
	if(mCCInputOctets != NULL)
	{
		delete mCCInputOctets; 
		mCCInputOctets = NULL;
	}
}

Unsigned64* GrantedServiceUnit::setCCOutputOctets(){
	mMandatoryAvpSetVal [GrantedServiceUnit_CCOUTPUTOCTETS] = 1;
	if(mCCOutputOctets == NULL)
	{
		mCCOutputOctets = new Unsigned64();
		mTagsPresent[GrantedServiceUnit_CCOUTPUTOCTETS] = 1;
		return mCCOutputOctets;
	}
	return mCCOutputOctets;
}

void GrantedServiceUnit::resetCCOutputOctets(){
	mTagsPresent[GrantedServiceUnit_CCOUTPUTOCTETS] = 0;
	if(mCCOutputOctets != NULL)
	{
		delete mCCOutputOctets; 
		mCCOutputOctets = NULL;
	}
}

Unsigned64* GrantedServiceUnit::setCCServiceSpecificUnits(){
	mMandatoryAvpSetVal [GrantedServiceUnit_CCSERVICESPECIFICUNITS] = 1;
	if(mCCServiceSpecificUnits == NULL)
	{
		mCCServiceSpecificUnits = new Unsigned64();
		mTagsPresent[GrantedServiceUnit_CCSERVICESPECIFICUNITS] = 1;
		return mCCServiceSpecificUnits;
	}
	return mCCServiceSpecificUnits;
}

void GrantedServiceUnit::resetCCServiceSpecificUnits(){
	mTagsPresent[GrantedServiceUnit_CCSERVICESPECIFICUNITS] = 0;
	if(mCCServiceSpecificUnits != NULL)
	{
		delete mCCServiceSpecificUnits; 
		mCCServiceSpecificUnits = NULL;
	}
}

TariffTimeChange* GrantedServiceUnit::getTariffTimeChange(){
	if(NULL == mTariffTimeChange) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TariffTimeChange is Null");
		throw lTssDiaMsgException;
	}
	if(!mTariffTimeChange->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mTariffTimeChange->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TariffTimeChange is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mTariffTimeChange->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mTariffTimeChange->Decode(mspByteArray.get(), mTariffTimeChange->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TariffTimeChange")     ;
			throw lTssDiaMsgException;
		}
		mTariffTimeChange->mAvpDecodedFlag = true;
	}
	return mTariffTimeChange;
}

Unsigned32* GrantedServiceUnit::getCCTime(){
	if(NULL == mCCTime) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCTime is Null");
		throw lTssDiaMsgException;
	}
	if(!mCCTime->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCCTime->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCTime is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCCTime->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCCTime->Decode(mspByteArray.get(), mCCTime->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCTime")     ;
			throw lTssDiaMsgException;
		}
		mCCTime->mAvpDecodedFlag = true;
	}
	return mCCTime;
}

list<CCMoney*>* GrantedServiceUnit::getCCMoneyGrpList()
{
	if(mCCMoneyGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCMoney is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mCCMoneyGrpList)
	{
		if(mCCMoneyGrpList != NULL)
		{
		if(mCCMoneyGrpList->size() == 0)
		{
			mTagsPresent[GrantedServiceUnit_CCMONEY] = 0;
			mCCMoneyGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCMoney is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCMoney is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCMoney")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mCCMoneyGrpList;
}

list<CCMoney*>* GrantedServiceUnit::setCCMoneyGrpList(){
	mTagsPresent[GrantedServiceUnit_CCMONEY] = 1;
	if(mCCMoneyGrpList == NULL)
		mCCMoneyGrpList = new list<CCMoney*>;
	mMandatoryAvpSetVal[GrantedServiceUnit_CCMONEY] = 1;
	mCCMoneyGrpList->clear();
	return mCCMoneyGrpList;
}

void GrantedServiceUnit::resetCCMoneyGrpList(){
	mTagsPresent[GrantedServiceUnit_CCMONEY] = 0;
	if(mCCMoneyGrpList != NULL)
		delete mCCMoneyGrpList;
}

Unsigned64* GrantedServiceUnit::getCCTotalOctets(){
	if(NULL == mCCTotalOctets) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCTotalOctets is Null");
		throw lTssDiaMsgException;
	}
	if(!mCCTotalOctets->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCCTotalOctets->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCTotalOctets is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCCTotalOctets->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCCTotalOctets->Decode(mspByteArray.get(), mCCTotalOctets->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCTotalOctets")     ;
			throw lTssDiaMsgException;
		}
		mCCTotalOctets->mAvpDecodedFlag = true;
	}
	return mCCTotalOctets;
}

Unsigned64* GrantedServiceUnit::getCCInputOctets(){
	if(NULL == mCCInputOctets) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCInputOctets is Null");
		throw lTssDiaMsgException;
	}
	if(!mCCInputOctets->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCCInputOctets->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCInputOctets is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCCInputOctets->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCCInputOctets->Decode(mspByteArray.get(), mCCInputOctets->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCInputOctets")     ;
			throw lTssDiaMsgException;
		}
		mCCInputOctets->mAvpDecodedFlag = true;
	}
	return mCCInputOctets;
}

Unsigned64* GrantedServiceUnit::getCCOutputOctets(){
	if(NULL == mCCOutputOctets) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCOutputOctets is Null");
		throw lTssDiaMsgException;
	}
	if(!mCCOutputOctets->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCCOutputOctets->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCOutputOctets is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCCOutputOctets->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCCOutputOctets->Decode(mspByteArray.get(), mCCOutputOctets->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCOutputOctets")     ;
			throw lTssDiaMsgException;
		}
		mCCOutputOctets->mAvpDecodedFlag = true;
	}
	return mCCOutputOctets;
}

Unsigned64* GrantedServiceUnit::getCCServiceSpecificUnits(){
	if(NULL == mCCServiceSpecificUnits) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCServiceSpecificUnits is Null");
		throw lTssDiaMsgException;
	}
	if(!mCCServiceSpecificUnits->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCCServiceSpecificUnits->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCServiceSpecificUnits is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCCServiceSpecificUnits->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCCServiceSpecificUnits->Decode(mspByteArray.get(), mCCServiceSpecificUnits->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCServiceSpecificUnits")     ;
			throw lTssDiaMsgException;
		}
		mCCServiceSpecificUnits->mAvpDecodedFlag = true;
	}
	return mCCServiceSpecificUnits;
}



int GrantedServiceUnit::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case GrantedServiceUnit_TARIFFTIMECHANGE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(452);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 96;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(96))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mTariffTimeChange->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mTariffTimeChange->getAvpOffsetLen().first], mTariffTimeChange->getAvpOffsetLen().second);
						array->offset += mTariffTimeChange->getAvpOffsetLen().second;
						array->size += mTariffTimeChange->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TariffTimeChange");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mTariffTimeChange->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TariffTimeChange");
						throw lTssDiaMsgException;
					}
				}
				break;
			case GrantedServiceUnit_CCTIME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(420);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 96;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(96))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mCCTime->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCCTime->getAvpOffsetLen().first], mCCTime->getAvpOffsetLen().second);
						array->offset += mCCTime->getAvpOffsetLen().second;
						array->size += mCCTime->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCTime");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mCCTime->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCTime");
						throw lTssDiaMsgException;
					}
				}
				break;
			case GrantedServiceUnit_CCMONEY:
			{
				if( mCCMoneyGrpList->size() <= 0) {
					break;
				}

				mCCMoneyGrpIterator = this->getCCMoneyGrpList()->begin();
				while(mCCMoneyGrpIterator != mCCMoneyGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(413);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 96;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(96))
						{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(((*mCCMoneyGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCMoney");
						throw lTssDiaMsgException;
					}
					
					mCCMoneyGrpIterator++;
				}
				}
				break;
			case GrantedServiceUnit_CCTOTALOCTETS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(421);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 96;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(96))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mCCTotalOctets->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCCTotalOctets->getAvpOffsetLen().first], mCCTotalOctets->getAvpOffsetLen().second);
						array->offset += mCCTotalOctets->getAvpOffsetLen().second;
						array->size += mCCTotalOctets->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCTotalOctets");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mCCTotalOctets->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCTotalOctets");
						throw lTssDiaMsgException;
					}
				}
				break;
			case GrantedServiceUnit_CCINPUTOCTETS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(412);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 96;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(96))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mCCInputOctets->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCCInputOctets->getAvpOffsetLen().first], mCCInputOctets->getAvpOffsetLen().second);
						array->offset += mCCInputOctets->getAvpOffsetLen().second;
						array->size += mCCInputOctets->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCInputOctets");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mCCInputOctets->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCInputOctets");
						throw lTssDiaMsgException;
					}
				}
				break;
			case GrantedServiceUnit_CCOUTPUTOCTETS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(414);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 96;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(96))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mCCOutputOctets->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCCOutputOctets->getAvpOffsetLen().first], mCCOutputOctets->getAvpOffsetLen().second);
						array->offset += mCCOutputOctets->getAvpOffsetLen().second;
						array->size += mCCOutputOctets->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCOutputOctets");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mCCOutputOctets->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCOutputOctets");
						throw lTssDiaMsgException;
					}
				}
				break;
			case GrantedServiceUnit_CCSERVICESPECIFICUNITS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(417);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 96;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(96))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mCCServiceSpecificUnits->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCCServiceSpecificUnits->getAvpOffsetLen().first], mCCServiceSpecificUnits->getAvpOffsetLen().second);
						array->offset += mCCServiceSpecificUnits->getAvpOffsetLen().second;
						array->size += mCCServiceSpecificUnits->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCServiceSpecificUnits");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mCCServiceSpecificUnits->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCServiceSpecificUnits");
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


int GrantedServiceUnit::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 452:
				{
						mMandatoryAvpSetVal [GrantedServiceUnit_TARIFFTIMECHANGE] = 1;
					if( NULL == this->setTariffTimeChange())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TariffTimeChange");
						throw lTssDiaMsgException;
					}
					mTariffTimeChange->setAvpCode(452);
					mTariffTimeChange->setAvpVendorId(lVenderId);
					mTariffTimeChange->SetDataType((DiameterDataType)7);
					mTariffTimeChange->mspByteArray = mspByteArray;
					mTariffTimeChange->mAvpDecodedFlag = false;
					mTariffTimeChange->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 420:
				{
						mMandatoryAvpSetVal [GrantedServiceUnit_CCTIME] = 1;
					if( NULL == this->setCCTime())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCTime");
						throw lTssDiaMsgException;
					}
					mCCTime->setAvpCode(420);
					mCCTime->setAvpVendorId(lVenderId);
					mCCTime->SetDataType((DiameterDataType)3);
					mCCTime->mspByteArray = mspByteArray;
					mCCTime->mAvpDecodedFlag = false;
					mCCTime->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 413:
				{
						mMandatoryAvpSetVal [GrantedServiceUnit_CCMONEY] = 1;
					mTagsPresent[GrantedServiceUnit_CCMONEY] = 1;
					CCMoney *lCCMoney = new CCMoney();
					if( lCCMoney == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCMoney");
						throw lTssDiaMsgException;
					}
					lCCMoney->setAvpCode(413);
					lCCMoney->SetDataType((DiameterDataType)6);
					lCCMoney->mspByteArray = mspByteArray;
					lCCMoney->mAvpDecodedFlag = false;
					lCCMoney->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mCCMoneyGrpList == NULL)
						this->setCCMoneyGrpList();
					mCCMoneyGrpList->push_back(lCCMoney);
					mBaseInterfaceList.push_back(lCCMoney);
					
				}
				break;
			case 421:
				{
						mMandatoryAvpSetVal [GrantedServiceUnit_CCTOTALOCTETS] = 1;
					if( NULL == this->setCCTotalOctets())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCTotalOctets");
						throw lTssDiaMsgException;
					}
					mCCTotalOctets->setAvpCode(421);
					mCCTotalOctets->setAvpVendorId(lVenderId);
					mCCTotalOctets->SetDataType((DiameterDataType)4);
					mCCTotalOctets->mspByteArray = mspByteArray;
					mCCTotalOctets->mAvpDecodedFlag = false;
					mCCTotalOctets->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 412:
				{
						mMandatoryAvpSetVal [GrantedServiceUnit_CCINPUTOCTETS] = 1;
					if( NULL == this->setCCInputOctets())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCInputOctets");
						throw lTssDiaMsgException;
					}
					mCCInputOctets->setAvpCode(412);
					mCCInputOctets->setAvpVendorId(lVenderId);
					mCCInputOctets->SetDataType((DiameterDataType)4);
					mCCInputOctets->mspByteArray = mspByteArray;
					mCCInputOctets->mAvpDecodedFlag = false;
					mCCInputOctets->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 414:
				{
						mMandatoryAvpSetVal [GrantedServiceUnit_CCOUTPUTOCTETS] = 1;
					if( NULL == this->setCCOutputOctets())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCOutputOctets");
						throw lTssDiaMsgException;
					}
					mCCOutputOctets->setAvpCode(414);
					mCCOutputOctets->setAvpVendorId(lVenderId);
					mCCOutputOctets->SetDataType((DiameterDataType)4);
					mCCOutputOctets->mspByteArray = mspByteArray;
					mCCOutputOctets->mAvpDecodedFlag = false;
					mCCOutputOctets->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 417:
				{
						mMandatoryAvpSetVal [GrantedServiceUnit_CCSERVICESPECIFICUNITS] = 1;
					if( NULL == this->setCCServiceSpecificUnits())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCServiceSpecificUnits");
						throw lTssDiaMsgException;
					}
					mCCServiceSpecificUnits->setAvpCode(417);
					mCCServiceSpecificUnits->setAvpVendorId(lVenderId);
					mCCServiceSpecificUnits->SetDataType((DiameterDataType)4);
					mCCServiceSpecificUnits->mspByteArray = mspByteArray;
					mCCServiceSpecificUnits->mAvpDecodedFlag = false;
					mCCServiceSpecificUnits->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* GrantedServiceUnit::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding GrantedServiceUnit")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 452:
			{
				if(mTariffTimeChange != NULL)
					return mTariffTimeChange->Find(array, avpCode);
				else
					return NULL;
			}
			case 420:
			{
				if(mCCTime != NULL)
					return mCCTime->Find(array, avpCode);
				else
					return NULL;
			}
			case 421:
			{
				if(mCCTotalOctets != NULL)
					return mCCTotalOctets->Find(array, avpCode);
				else
					return NULL;
			}
			case 412:
			{
				if(mCCInputOctets != NULL)
					return mCCInputOctets->Find(array, avpCode);
				else
					return NULL;
			}
			case 414:
			{
				if(mCCOutputOctets != NULL)
					return mCCOutputOctets->Find(array, avpCode);
				else
					return NULL;
			}
			case 417:
			{
				if(mCCServiceSpecificUnits != NULL)
					return mCCServiceSpecificUnits->Find(array, avpCode);
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


BOOLEAN GrantedServiceUnit::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding GrantedServiceUnit")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 452:
			{
				if(mTariffTimeChange != NULL)
				{
					DiameterBaseInterface* inf =  mTariffTimeChange->Find(this->mspByteArray.get(), avpCode);
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
			case 420:
			{
				if(mCCTime != NULL)
				{
					DiameterBaseInterface* inf =  mCCTime->Find(this->mspByteArray.get(), avpCode);
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
			case 413:
			{
				if(mCCMoneyGrpList != NULL)
				{
					for(auto itr = mCCMoneyGrpList->begin(); itr != mCCMoneyGrpList->end(); ++itr)
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
			case 421:
			{
				if(mCCTotalOctets != NULL)
				{
					DiameterBaseInterface* inf =  mCCTotalOctets->Find(this->mspByteArray.get(), avpCode);
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
			case 412:
			{
				if(mCCInputOctets != NULL)
				{
					DiameterBaseInterface* inf =  mCCInputOctets->Find(this->mspByteArray.get(), avpCode);
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
			case 414:
			{
				if(mCCOutputOctets != NULL)
				{
					DiameterBaseInterface* inf =  mCCOutputOctets->Find(this->mspByteArray.get(), avpCode);
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
			case 417:
			{
				if(mCCServiceSpecificUnits != NULL)
				{
					DiameterBaseInterface* inf =  mCCServiceSpecificUnits->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> GrantedServiceUnit::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN GrantedServiceUnit::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding GrantedServiceUnit")     ;
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
			case 452:
			{
				if(mTariffTimeChange != NULL)
				{
					DiameterBaseInterface* inf =  mTariffTimeChange->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 420:
			{
				if(mCCTime != NULL)
				{
					DiameterBaseInterface* inf =  mCCTime->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 413:
			{
				if(mCCMoneyGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mCCMoneyGrpList->begin(); itr != mCCMoneyGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mCCMoneyGrpList->begin(); itr != mCCMoneyGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 421:
			{
				if(mCCTotalOctets != NULL)
				{
					DiameterBaseInterface* inf =  mCCTotalOctets->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 412:
			{
				if(mCCInputOctets != NULL)
				{
					DiameterBaseInterface* inf =  mCCInputOctets->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 414:
			{
				if(mCCOutputOctets != NULL)
				{
					DiameterBaseInterface* inf =  mCCOutputOctets->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 417:
			{
				if(mCCServiceSpecificUnits != NULL)
				{
					DiameterBaseInterface* inf =  mCCServiceSpecificUnits->Find(this->mspByteArray.get(), avpCode);
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


INT32 GrantedServiceUnit::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 GrantedServiceUnit::getAvpCode()
{
	return mAvpCode;
}
INT32 GrantedServiceUnit::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 GrantedServiceUnit::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 GrantedServiceUnit::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> GrantedServiceUnit::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void GrantedServiceUnit::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case GrantedServiceUnit_TARIFFTIMECHANGE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "452" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "TariffTimeChange" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getTariffTimeChange()->Display(tab+1);
			}
				break;
			case GrantedServiceUnit_CCTIME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "420" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CCTime" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getCCTime()->Display(tab+1);
			}
				break;
			case GrantedServiceUnit_CCMONEY:
			{
				if( mCCMoneyGrpList->size() <= 0) {
					break;
				}

				mCCMoneyGrpIterator = this->getCCMoneyGrpList()->begin();
				while(mCCMoneyGrpIterator != this->getCCMoneyGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "413" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CCMoney" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
					(*mCCMoneyGrpIterator)->Display(tab+1);
					mCCMoneyGrpIterator++;

				};

			}
				break;
			case GrantedServiceUnit_CCTOTALOCTETS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "421" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CCTotalOctets" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getCCTotalOctets()->Display(tab+1);
			}
				break;
			case GrantedServiceUnit_CCINPUTOCTETS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "412" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CCInputOctets" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getCCInputOctets()->Display(tab+1);
			}
				break;
			case GrantedServiceUnit_CCOUTPUTOCTETS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "414" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CCOutputOctets" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getCCOutputOctets()->Display(tab+1);
			}
				break;
			case GrantedServiceUnit_CCSERVICESPECIFICUNITS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "417" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CCServiceSpecificUnits" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getCCServiceSpecificUnits()->Display(tab+1);
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


BOOLEAN GrantedServiceUnit::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<7> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case GrantedServiceUnit_TARIFFTIMECHANGE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 452");
				}
				else
					sprintf(lMissingAvpInfo, "%s,452", lMissingAvpInfo);
			}
				break;
			case GrantedServiceUnit_CCTIME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 420");
				}
				else
					sprintf(lMissingAvpInfo, "%s,420", lMissingAvpInfo);
			}
				break;
			case GrantedServiceUnit_CCMONEY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 413");
				}
				else
					sprintf(lMissingAvpInfo, "%s,413", lMissingAvpInfo);
			}
				break;
			case GrantedServiceUnit_CCTOTALOCTETS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 421");
				}
				else
					sprintf(lMissingAvpInfo, "%s,421", lMissingAvpInfo);
			}
				break;
			case GrantedServiceUnit_CCINPUTOCTETS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 412");
				}
				else
					sprintf(lMissingAvpInfo, "%s,412", lMissingAvpInfo);
			}
				break;
			case GrantedServiceUnit_CCOUTPUTOCTETS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 414");
				}
				else
					sprintf(lMissingAvpInfo, "%s,414", lMissingAvpInfo);
			}
				break;
			case GrantedServiceUnit_CCSERVICESPECIFICUNITS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 417");
				}
				else
					sprintf(lMissingAvpInfo, "%s,417", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
