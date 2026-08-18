#include "sd/include/ConditionalAPNAggregateMaxBitrate.h"

using namespace SD;
BOOLEAN ConditionalAPNAggregateMaxBitrate::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

ConditionalAPNAggregateMaxBitrate::ConditionalAPNAggregateMaxBitrate()
{
	mAPNAggregateMaxBitrateUL = NULL;
	mAPNAggregateMaxBitrateDL = NULL;
	mExtendedAPNAMBRUL = NULL;
	mExtendedAPNAMBRDL = NULL;
	mIPCANTypeList = NULL;
	mRATTypeList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<6>(string("010000"));
	mMandatoryAvpSetVal.reset();
}

ConditionalAPNAggregateMaxBitrate::~ConditionalAPNAggregateMaxBitrate()
{
	if(mAPNAggregateMaxBitrateUL != NULL)
		delete mAPNAggregateMaxBitrateUL;
	if(mAPNAggregateMaxBitrateDL != NULL)
		delete mAPNAggregateMaxBitrateDL;
	if(mExtendedAPNAMBRUL != NULL)
		delete mExtendedAPNAMBRUL;
	if(mExtendedAPNAMBRDL != NULL)
		delete mExtendedAPNAMBRDL;
	if(mIPCANTypeList != NULL){
		mIPCANTypeIterator = mIPCANTypeList->begin();
		while(mIPCANTypeIterator != mIPCANTypeList->end()){
			delete (*mIPCANTypeIterator);
			mIPCANTypeIterator++;
		}
		delete mIPCANTypeList;
	}
	if(mRATTypeList != NULL){
		mRATTypeIterator = mRATTypeList->begin();
		while(mRATTypeIterator != mRATTypeList->end()){
			delete (*mRATTypeIterator);
			mRATTypeIterator++;
		}
		delete mRATTypeList;
	}
}

Unsigned32* ConditionalAPNAggregateMaxBitrate::setAPNAggregateMaxBitrateUL(){
	if(mAPNAggregateMaxBitrateUL == NULL)
	{
		mAPNAggregateMaxBitrateUL = new Unsigned32();
		mTagsPresent[ConditionalAPNAggregateMaxBitrate_APNAGGREGATEMAXBITRATEUL] = 1;
		return mAPNAggregateMaxBitrateUL;
	}
	return mAPNAggregateMaxBitrateUL;
}

void ConditionalAPNAggregateMaxBitrate::resetAPNAggregateMaxBitrateUL(){
	mTagsPresent[ConditionalAPNAggregateMaxBitrate_APNAGGREGATEMAXBITRATEUL] = 0;
	if(mAPNAggregateMaxBitrateUL != NULL)
	{
		delete mAPNAggregateMaxBitrateUL; 
		mAPNAggregateMaxBitrateUL = NULL;
	}
}

Unsigned32* ConditionalAPNAggregateMaxBitrate::setAPNAggregateMaxBitrateDL(){
	if(mAPNAggregateMaxBitrateDL == NULL)
	{
		mAPNAggregateMaxBitrateDL = new Unsigned32();
		mTagsPresent[ConditionalAPNAggregateMaxBitrate_APNAGGREGATEMAXBITRATEDL] = 1;
		return mAPNAggregateMaxBitrateDL;
	}
	return mAPNAggregateMaxBitrateDL;
}

void ConditionalAPNAggregateMaxBitrate::resetAPNAggregateMaxBitrateDL(){
	mTagsPresent[ConditionalAPNAggregateMaxBitrate_APNAGGREGATEMAXBITRATEDL] = 0;
	if(mAPNAggregateMaxBitrateDL != NULL)
	{
		delete mAPNAggregateMaxBitrateDL; 
		mAPNAggregateMaxBitrateDL = NULL;
	}
}

Unsigned32* ConditionalAPNAggregateMaxBitrate::setExtendedAPNAMBRUL(){
	if(mExtendedAPNAMBRUL == NULL)
	{
		mExtendedAPNAMBRUL = new Unsigned32();
		mTagsPresent[ConditionalAPNAggregateMaxBitrate_EXTENDEDAPNAMBRUL] = 1;
		return mExtendedAPNAMBRUL;
	}
	return mExtendedAPNAMBRUL;
}

void ConditionalAPNAggregateMaxBitrate::resetExtendedAPNAMBRUL(){
	mTagsPresent[ConditionalAPNAggregateMaxBitrate_EXTENDEDAPNAMBRUL] = 0;
	if(mExtendedAPNAMBRUL != NULL)
	{
		delete mExtendedAPNAMBRUL; 
		mExtendedAPNAMBRUL = NULL;
	}
}

Unsigned32* ConditionalAPNAggregateMaxBitrate::setExtendedAPNAMBRDL(){
	if(mExtendedAPNAMBRDL == NULL)
	{
		mExtendedAPNAMBRDL = new Unsigned32();
		mTagsPresent[ConditionalAPNAggregateMaxBitrate_EXTENDEDAPNAMBRDL] = 1;
		return mExtendedAPNAMBRDL;
	}
	return mExtendedAPNAMBRDL;
}

void ConditionalAPNAggregateMaxBitrate::resetExtendedAPNAMBRDL(){
	mTagsPresent[ConditionalAPNAggregateMaxBitrate_EXTENDEDAPNAMBRDL] = 0;
	if(mExtendedAPNAMBRDL != NULL)
	{
		delete mExtendedAPNAMBRDL; 
		mExtendedAPNAMBRDL = NULL;
	}
}

Unsigned32* ConditionalAPNAggregateMaxBitrate::getAPNAggregateMaxBitrateUL(){
	if(NULL == mAPNAggregateMaxBitrateUL) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "APNAggregateMaxBitrateUL is Null");
		throw lTssDiaMsgException;
	}
	if(!mAPNAggregateMaxBitrateUL->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAPNAggregateMaxBitrateUL->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "APNAggregateMaxBitrateUL is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAPNAggregateMaxBitrateUL->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAPNAggregateMaxBitrateUL->Decode(mspByteArray.get(), mAPNAggregateMaxBitrateUL->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding APNAggregateMaxBitrateUL")     ;
			throw lTssDiaMsgException;
		}
		mAPNAggregateMaxBitrateUL->mAvpDecodedFlag = true;
	}
	return mAPNAggregateMaxBitrateUL;
}

Unsigned32* ConditionalAPNAggregateMaxBitrate::getAPNAggregateMaxBitrateDL(){
	if(NULL == mAPNAggregateMaxBitrateDL) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "APNAggregateMaxBitrateDL is Null");
		throw lTssDiaMsgException;
	}
	if(!mAPNAggregateMaxBitrateDL->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAPNAggregateMaxBitrateDL->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "APNAggregateMaxBitrateDL is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAPNAggregateMaxBitrateDL->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAPNAggregateMaxBitrateDL->Decode(mspByteArray.get(), mAPNAggregateMaxBitrateDL->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding APNAggregateMaxBitrateDL")     ;
			throw lTssDiaMsgException;
		}
		mAPNAggregateMaxBitrateDL->mAvpDecodedFlag = true;
	}
	return mAPNAggregateMaxBitrateDL;
}

Unsigned32* ConditionalAPNAggregateMaxBitrate::getExtendedAPNAMBRUL(){
	if(NULL == mExtendedAPNAMBRUL) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExtendedAPNAMBRUL is Null");
		throw lTssDiaMsgException;
	}
	if(!mExtendedAPNAMBRUL->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mExtendedAPNAMBRUL->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExtendedAPNAMBRUL is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mExtendedAPNAMBRUL->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mExtendedAPNAMBRUL->Decode(mspByteArray.get(), mExtendedAPNAMBRUL->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExtendedAPNAMBRUL")     ;
			throw lTssDiaMsgException;
		}
		mExtendedAPNAMBRUL->mAvpDecodedFlag = true;
	}
	return mExtendedAPNAMBRUL;
}

Unsigned32* ConditionalAPNAggregateMaxBitrate::getExtendedAPNAMBRDL(){
	if(NULL == mExtendedAPNAMBRDL) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExtendedAPNAMBRDL is Null");
		throw lTssDiaMsgException;
	}
	if(!mExtendedAPNAMBRDL->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mExtendedAPNAMBRDL->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExtendedAPNAMBRDL is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mExtendedAPNAMBRDL->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mExtendedAPNAMBRDL->Decode(mspByteArray.get(), mExtendedAPNAMBRDL->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExtendedAPNAMBRDL")     ;
			throw lTssDiaMsgException;
		}
		mExtendedAPNAMBRDL->mAvpDecodedFlag = true;
	}
	return mExtendedAPNAMBRDL;
}

list<IPCANType*>* ConditionalAPNAggregateMaxBitrate::getIPCANTypeList()
{
	if(mIPCANTypeList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "IPCANType is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr :* mIPCANTypeList)
	{
		if(!itr->mAvpDecodedFlag)
		{
	if(mspByteArray.get() == NULL)
		{
	itr->mAvpDecodedFlag = true;
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "IPCANType is Null");
		throw lTssDiaMsgException;
	}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding IPCANType")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mIPCANTypeList;
}

list<IPCANType*>* ConditionalAPNAggregateMaxBitrate::setIPCANTypeList() {
	mTagsPresent[ConditionalAPNAggregateMaxBitrate_IPCANTYPE] = 1;
	if(mIPCANTypeList == NULL)
		mIPCANTypeList = new list<IPCANType*>;
	mMandatoryAvpSetVal [ConditionalAPNAggregateMaxBitrate_IPCANTYPE] = 1;
	mIPCANTypeList->clear();
	return mIPCANTypeList;
}

void ConditionalAPNAggregateMaxBitrate::resetIPCANTypeList(){
	mTagsPresent[ConditionalAPNAggregateMaxBitrate_IPCANTYPE] = 0;
	if(mIPCANTypeList != NULL)
		delete mIPCANTypeList;
}

list<RATType*>* ConditionalAPNAggregateMaxBitrate::getRATTypeList()
{
	if(mRATTypeList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RATType is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr :* mRATTypeList)
	{
		if(!itr->mAvpDecodedFlag)
		{
	if(mspByteArray.get() == NULL)
		{
	itr->mAvpDecodedFlag = true;
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RATType is Null");
		throw lTssDiaMsgException;
	}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RATType")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mRATTypeList;
}

list<RATType*>* ConditionalAPNAggregateMaxBitrate::setRATTypeList() {
	mTagsPresent[ConditionalAPNAggregateMaxBitrate_RATTYPE] = 1;
	if(mRATTypeList == NULL)
		mRATTypeList = new list<RATType*>;
	mRATTypeList->clear();
	return mRATTypeList;
}

void ConditionalAPNAggregateMaxBitrate::resetRATTypeList(){
	mTagsPresent[ConditionalAPNAggregateMaxBitrate_RATTYPE] = 0;
	if(mRATTypeList != NULL)
		delete mRATTypeList;
}



int ConditionalAPNAggregateMaxBitrate::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case ConditionalAPNAggregateMaxBitrate_APNAGGREGATEMAXBITRATEUL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1041);
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
					if(!mAPNAggregateMaxBitrateUL->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAPNAggregateMaxBitrateUL->getAvpOffsetLen().first], mAPNAggregateMaxBitrateUL->getAvpOffsetLen().second);
						array->offset += mAPNAggregateMaxBitrateUL->getAvpOffsetLen().second;
						array->size += mAPNAggregateMaxBitrateUL->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding APNAggregateMaxBitrateUL");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mAPNAggregateMaxBitrateUL->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding APNAggregateMaxBitrateUL");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ConditionalAPNAggregateMaxBitrate_APNAGGREGATEMAXBITRATEDL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1040);
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
					if(!mAPNAggregateMaxBitrateDL->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAPNAggregateMaxBitrateDL->getAvpOffsetLen().first], mAPNAggregateMaxBitrateDL->getAvpOffsetLen().second);
						array->offset += mAPNAggregateMaxBitrateDL->getAvpOffsetLen().second;
						array->size += mAPNAggregateMaxBitrateDL->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding APNAggregateMaxBitrateDL");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mAPNAggregateMaxBitrateDL->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding APNAggregateMaxBitrateDL");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ConditionalAPNAggregateMaxBitrate_EXTENDEDAPNAMBRUL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2849);
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
					if(!mExtendedAPNAMBRUL->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mExtendedAPNAMBRUL->getAvpOffsetLen().first], mExtendedAPNAMBRUL->getAvpOffsetLen().second);
						array->offset += mExtendedAPNAMBRUL->getAvpOffsetLen().second;
						array->size += mExtendedAPNAMBRUL->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExtendedAPNAMBRUL");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mExtendedAPNAMBRUL->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExtendedAPNAMBRUL");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ConditionalAPNAggregateMaxBitrate_EXTENDEDAPNAMBRDL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2848);
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
					if(!mExtendedAPNAMBRDL->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mExtendedAPNAMBRDL->getAvpOffsetLen().first], mExtendedAPNAMBRDL->getAvpOffsetLen().second);
						array->offset += mExtendedAPNAMBRDL->getAvpOffsetLen().second;
						array->size += mExtendedAPNAMBRDL->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExtendedAPNAMBRDL");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mExtendedAPNAMBRDL->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExtendedAPNAMBRDL");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ConditionalAPNAggregateMaxBitrate_IPCANTYPE:
			{
					if( mIPCANTypeList->size() <= 0) {
						break;
					}

					mIPCANTypeIterator = this->getIPCANTypeList()->begin();
					while(mIPCANTypeIterator != mIPCANTypeList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(1027);
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
					if(!(*mIPCANTypeIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mIPCANTypeIterator)->getAvpOffsetLen().first], (*mIPCANTypeIterator)->getAvpOffsetLen().second);
						array->offset += (*mIPCANTypeIterator)->getAvpOffsetLen().second;
						array->size += (*mIPCANTypeIterator)->getAvpOffsetLen().second;
						if(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)
						{
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding IPCANType");
							throw lTssDiaMsgException;
						}
						mIPCANTypeIterator++;
						continue;
					}
					if(((*mIPCANTypeIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding IPCANType");
						throw lTssDiaMsgException;
					}
					mIPCANTypeIterator++;
				}
				}
				break;
			case ConditionalAPNAggregateMaxBitrate_RATTYPE:
			{
					if( mRATTypeList->size() <= 0) {
						break;
					}

					mRATTypeIterator = this->getRATTypeList()->begin();
					while(mRATTypeIterator != mRATTypeList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(1032);
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
					if(!(*mRATTypeIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mRATTypeIterator)->getAvpOffsetLen().first], (*mRATTypeIterator)->getAvpOffsetLen().second);
						array->offset += (*mRATTypeIterator)->getAvpOffsetLen().second;
						array->size += (*mRATTypeIterator)->getAvpOffsetLen().second;
						if(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)
						{
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RATType");
							throw lTssDiaMsgException;
						}
						mRATTypeIterator++;
						continue;
					}
					if(((*mRATTypeIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RATType");
						throw lTssDiaMsgException;
					}
					mRATTypeIterator++;
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


int ConditionalAPNAggregateMaxBitrate::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 1041:
				{
					if( NULL == this->setAPNAggregateMaxBitrateUL())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding APNAggregateMaxBitrateUL");
						throw lTssDiaMsgException;
					}
					mAPNAggregateMaxBitrateUL->setAvpCode(1041);
					mAPNAggregateMaxBitrateUL->setAvpVendorId(lVenderId);
					mAPNAggregateMaxBitrateUL->SetDataType((DiameterDataType)3);
					mAPNAggregateMaxBitrateUL->mspByteArray = mspByteArray;
					mAPNAggregateMaxBitrateUL->mAvpDecodedFlag = false;
					mAPNAggregateMaxBitrateUL->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1040:
				{
					if( NULL == this->setAPNAggregateMaxBitrateDL())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding APNAggregateMaxBitrateDL");
						throw lTssDiaMsgException;
					}
					mAPNAggregateMaxBitrateDL->setAvpCode(1040);
					mAPNAggregateMaxBitrateDL->setAvpVendorId(lVenderId);
					mAPNAggregateMaxBitrateDL->SetDataType((DiameterDataType)3);
					mAPNAggregateMaxBitrateDL->mspByteArray = mspByteArray;
					mAPNAggregateMaxBitrateDL->mAvpDecodedFlag = false;
					mAPNAggregateMaxBitrateDL->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2849:
				{
					if( NULL == this->setExtendedAPNAMBRUL())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExtendedAPNAMBRUL");
						throw lTssDiaMsgException;
					}
					mExtendedAPNAMBRUL->setAvpCode(2849);
					mExtendedAPNAMBRUL->setAvpVendorId(lVenderId);
					mExtendedAPNAMBRUL->SetDataType((DiameterDataType)3);
					mExtendedAPNAMBRUL->mspByteArray = mspByteArray;
					mExtendedAPNAMBRUL->mAvpDecodedFlag = false;
					mExtendedAPNAMBRUL->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2848:
				{
					if( NULL == this->setExtendedAPNAMBRDL())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExtendedAPNAMBRDL");
						throw lTssDiaMsgException;
					}
					mExtendedAPNAMBRDL->setAvpCode(2848);
					mExtendedAPNAMBRDL->setAvpVendorId(lVenderId);
					mExtendedAPNAMBRDL->SetDataType((DiameterDataType)3);
					mExtendedAPNAMBRDL->mspByteArray = mspByteArray;
					mExtendedAPNAMBRDL->mAvpDecodedFlag = false;
					mExtendedAPNAMBRDL->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1027:
				{
						mMandatoryAvpSetVal [ConditionalAPNAggregateMaxBitrate_IPCANTYPE] = 1;
					mTagsPresent[ConditionalAPNAggregateMaxBitrate_IPCANTYPE] = 1;
					IPCANType *lIPCANType = new IPCANType();
					if( lIPCANType == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding IPCANType");
						throw lTssDiaMsgException;
					}
					lIPCANType->setAvpCode(1027);
					lIPCANType->setAvpVendorId(lVenderId);
					lIPCANType->SetDataType((DiameterDataType)7);
					lIPCANType->mspByteArray = mspByteArray;
					lIPCANType->mAvpDecodedFlag = false;
					lIPCANType->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mIPCANTypeList == NULL)
						this->setIPCANTypeList();
					mIPCANTypeList->push_back(lIPCANType);
					
				}
				break;
			case 1032:
				{
					mTagsPresent[ConditionalAPNAggregateMaxBitrate_RATTYPE] = 1;
					RATType *lRATType = new RATType();
					if( lRATType == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RATType");
						throw lTssDiaMsgException;
					}
					lRATType->setAvpCode(1032);
					lRATType->setAvpVendorId(lVenderId);
					lRATType->SetDataType((DiameterDataType)7);
					lRATType->mspByteArray = mspByteArray;
					lRATType->mAvpDecodedFlag = false;
					lRATType->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mRATTypeList == NULL)
						this->setRATTypeList();
					mRATTypeList->push_back(lRATType);
					
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


DiameterBaseInterface* ConditionalAPNAggregateMaxBitrate::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ConditionalAPNAggregateMaxBitrate")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1041:
			{
				if(mAPNAggregateMaxBitrateUL != NULL)
					return mAPNAggregateMaxBitrateUL->Find(array, avpCode);
				else
					return NULL;
			}
			case 1040:
			{
				if(mAPNAggregateMaxBitrateDL != NULL)
					return mAPNAggregateMaxBitrateDL->Find(array, avpCode);
				else
					return NULL;
			}
			case 2849:
			{
				if(mExtendedAPNAMBRUL != NULL)
					return mExtendedAPNAMBRUL->Find(array, avpCode);
				else
					return NULL;
			}
			case 2848:
			{
				if(mExtendedAPNAMBRDL != NULL)
					return mExtendedAPNAMBRDL->Find(array, avpCode);
				else
					return NULL;
			}
			case 1027:
			{
				if(mIPCANTypeList != NULL && mIPCANTypeList->size() > 0)
					return (mIPCANTypeList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 1032:
			{
				if(mRATTypeList != NULL && mRATTypeList->size() > 0)
					return (mRATTypeList->back())->Find(array, avpCode);
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


BOOLEAN ConditionalAPNAggregateMaxBitrate::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ConditionalAPNAggregateMaxBitrate")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1041:
			{
				if(mAPNAggregateMaxBitrateUL != NULL)
				{
					DiameterBaseInterface* inf =  mAPNAggregateMaxBitrateUL->Find(this->mspByteArray.get(), avpCode);
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
			case 1040:
			{
				if(mAPNAggregateMaxBitrateDL != NULL)
				{
					DiameterBaseInterface* inf =  mAPNAggregateMaxBitrateDL->Find(this->mspByteArray.get(), avpCode);
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
			case 2849:
			{
				if(mExtendedAPNAMBRUL != NULL)
				{
					DiameterBaseInterface* inf =  mExtendedAPNAMBRUL->Find(this->mspByteArray.get(), avpCode);
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
			case 2848:
			{
				if(mExtendedAPNAMBRDL != NULL)
				{
					DiameterBaseInterface* inf =  mExtendedAPNAMBRDL->Find(this->mspByteArray.get(), avpCode);
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
			case 1027:
			{
				if(mIPCANTypeList != NULL)
				{
					for(auto itr = mIPCANTypeList->begin(); itr != mIPCANTypeList->end(); ++itr)
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
			case 1032:
			{
				if(mRATTypeList != NULL)
				{
					for(auto itr = mRATTypeList->begin(); itr != mRATTypeList->end(); ++itr)
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
std::shared_ptr<byteArray> ConditionalAPNAggregateMaxBitrate::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN ConditionalAPNAggregateMaxBitrate::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ConditionalAPNAggregateMaxBitrate")     ;
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
			case 1041:
			{
				if(mAPNAggregateMaxBitrateUL != NULL)
				{
					DiameterBaseInterface* inf =  mAPNAggregateMaxBitrateUL->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1040:
			{
				if(mAPNAggregateMaxBitrateDL != NULL)
				{
					DiameterBaseInterface* inf =  mAPNAggregateMaxBitrateDL->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2849:
			{
				if(mExtendedAPNAMBRUL != NULL)
				{
					DiameterBaseInterface* inf =  mExtendedAPNAMBRUL->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2848:
			{
				if(mExtendedAPNAMBRDL != NULL)
				{
					DiameterBaseInterface* inf =  mExtendedAPNAMBRDL->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1027:
			{
				if(mIPCANTypeList != NULL)
				{
					for(auto itr = mIPCANTypeList->begin(); itr != mIPCANTypeList->end(); ++itr)
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
			case 1032:
			{
				if(mRATTypeList != NULL)
				{
					for(auto itr = mRATTypeList->begin(); itr != mRATTypeList->end(); ++itr)
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


INT32 ConditionalAPNAggregateMaxBitrate::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 ConditionalAPNAggregateMaxBitrate::getAvpCode()
{
	return mAvpCode;
}
INT32 ConditionalAPNAggregateMaxBitrate::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 ConditionalAPNAggregateMaxBitrate::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 ConditionalAPNAggregateMaxBitrate::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> ConditionalAPNAggregateMaxBitrate::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void ConditionalAPNAggregateMaxBitrate::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case ConditionalAPNAggregateMaxBitrate_APNAGGREGATEMAXBITRATEUL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1041" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "APNAggregateMaxBitrateUL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getAPNAggregateMaxBitrateUL()->Display(tab+1);
			}
				break;
			case ConditionalAPNAggregateMaxBitrate_APNAGGREGATEMAXBITRATEDL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1040" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "APNAggregateMaxBitrateDL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getAPNAggregateMaxBitrateDL()->Display(tab+1);
			}
				break;
			case ConditionalAPNAggregateMaxBitrate_EXTENDEDAPNAMBRUL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2849" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ExtendedAPNAMBRUL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getExtendedAPNAMBRUL()->Display(tab+1);
			}
				break;
			case ConditionalAPNAggregateMaxBitrate_EXTENDEDAPNAMBRDL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2848" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ExtendedAPNAMBRDL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getExtendedAPNAMBRDL()->Display(tab+1);
			}
				break;
			case ConditionalAPNAggregateMaxBitrate_IPCANTYPE:
			{
				if( mIPCANTypeList->size() <= 0) {
					break;
				}

				mIPCANTypeIterator = this->getIPCANTypeList()->begin();
				while(mIPCANTypeIterator != this->getIPCANTypeList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1027" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "IPCANType" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mIPCANTypeIterator)->Display(tab+1);
					mIPCANTypeIterator++;

				};

			}
				break;
			case ConditionalAPNAggregateMaxBitrate_RATTYPE:
			{
				if( mRATTypeList->size() <= 0) {
					break;
				}

				mRATTypeIterator = this->getRATTypeList()->begin();
				while(mRATTypeIterator != this->getRATTypeList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1032" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RATType" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mRATTypeIterator)->Display(tab+1);
					mRATTypeIterator++;

				};

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


BOOLEAN ConditionalAPNAggregateMaxBitrate::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<6> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case ConditionalAPNAggregateMaxBitrate_APNAGGREGATEMAXBITRATEUL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1041");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1041", lMissingAvpInfo);
			}
				break;
			case ConditionalAPNAggregateMaxBitrate_APNAGGREGATEMAXBITRATEDL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1040");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1040", lMissingAvpInfo);
			}
				break;
			case ConditionalAPNAggregateMaxBitrate_EXTENDEDAPNAMBRUL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2849");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2849", lMissingAvpInfo);
			}
				break;
			case ConditionalAPNAggregateMaxBitrate_EXTENDEDAPNAMBRDL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2848");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2848", lMissingAvpInfo);
			}
				break;
			case ConditionalAPNAggregateMaxBitrate_IPCANTYPE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1027");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1027", lMissingAvpInfo);
			}
				break;
			case ConditionalAPNAggregateMaxBitrate_RATTYPE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1032");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1032", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
