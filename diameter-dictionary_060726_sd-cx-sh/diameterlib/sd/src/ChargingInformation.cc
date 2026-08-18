#include "sd/include/ChargingInformation.h"

using namespace SD;
BOOLEAN ChargingInformation::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

ChargingInformation::ChargingInformation()
{
	mPrimaryEventChargingFunctionName = NULL;
	mSecondaryEventChargingFunctionName = NULL;
	mPrimaryChargingCollectionFunctionName = NULL;
	mSecondaryChargingCollectionFunctionName = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<4>(string("1111"));
	mMandatoryAvpSetVal.reset();
}

ChargingInformation::~ChargingInformation()
{
	if(mPrimaryEventChargingFunctionName != NULL)
		delete mPrimaryEventChargingFunctionName;
	if(mSecondaryEventChargingFunctionName != NULL)
		delete mSecondaryEventChargingFunctionName;
	if(mPrimaryChargingCollectionFunctionName != NULL)
		delete mPrimaryChargingCollectionFunctionName;
	if(mSecondaryChargingCollectionFunctionName != NULL)
		delete mSecondaryChargingCollectionFunctionName;
}

OctetString* ChargingInformation::setPrimaryEventChargingFunctionName(){
	mMandatoryAvpSetVal [ChargingInformation_PRIMARYEVENTCHARGINGFUNCTIONNAME] = 1;
	if(mPrimaryEventChargingFunctionName == NULL)
	{
		mPrimaryEventChargingFunctionName = new OctetString();
		mTagsPresent[ChargingInformation_PRIMARYEVENTCHARGINGFUNCTIONNAME] = 1;
		return mPrimaryEventChargingFunctionName;
	}
	return mPrimaryEventChargingFunctionName;
}

void ChargingInformation::resetPrimaryEventChargingFunctionName(){
	mTagsPresent[ChargingInformation_PRIMARYEVENTCHARGINGFUNCTIONNAME] = 0;
	if(mPrimaryEventChargingFunctionName != NULL)
	{
		delete mPrimaryEventChargingFunctionName; 
		mPrimaryEventChargingFunctionName = NULL;
	}
}

OctetString* ChargingInformation::setSecondaryEventChargingFunctionName(){
	mMandatoryAvpSetVal [ChargingInformation_SECONDARYEVENTCHARGINGFUNCTIONNAME] = 1;
	if(mSecondaryEventChargingFunctionName == NULL)
	{
		mSecondaryEventChargingFunctionName = new OctetString();
		mTagsPresent[ChargingInformation_SECONDARYEVENTCHARGINGFUNCTIONNAME] = 1;
		return mSecondaryEventChargingFunctionName;
	}
	return mSecondaryEventChargingFunctionName;
}

void ChargingInformation::resetSecondaryEventChargingFunctionName(){
	mTagsPresent[ChargingInformation_SECONDARYEVENTCHARGINGFUNCTIONNAME] = 0;
	if(mSecondaryEventChargingFunctionName != NULL)
	{
		delete mSecondaryEventChargingFunctionName; 
		mSecondaryEventChargingFunctionName = NULL;
	}
}

OctetString* ChargingInformation::setPrimaryChargingCollectionFunctionName(){
	mMandatoryAvpSetVal [ChargingInformation_PRIMARYCHARGINGCOLLECTIONFUNCTIONNAME] = 1;
	if(mPrimaryChargingCollectionFunctionName == NULL)
	{
		mPrimaryChargingCollectionFunctionName = new OctetString();
		mTagsPresent[ChargingInformation_PRIMARYCHARGINGCOLLECTIONFUNCTIONNAME] = 1;
		return mPrimaryChargingCollectionFunctionName;
	}
	return mPrimaryChargingCollectionFunctionName;
}

void ChargingInformation::resetPrimaryChargingCollectionFunctionName(){
	mTagsPresent[ChargingInformation_PRIMARYCHARGINGCOLLECTIONFUNCTIONNAME] = 0;
	if(mPrimaryChargingCollectionFunctionName != NULL)
	{
		delete mPrimaryChargingCollectionFunctionName; 
		mPrimaryChargingCollectionFunctionName = NULL;
	}
}

OctetString* ChargingInformation::setSecondaryChargingCollectionFunctionName(){
	mMandatoryAvpSetVal [ChargingInformation_SECONDARYCHARGINGCOLLECTIONFUNCTIONNAME] = 1;
	if(mSecondaryChargingCollectionFunctionName == NULL)
	{
		mSecondaryChargingCollectionFunctionName = new OctetString();
		mTagsPresent[ChargingInformation_SECONDARYCHARGINGCOLLECTIONFUNCTIONNAME] = 1;
		return mSecondaryChargingCollectionFunctionName;
	}
	return mSecondaryChargingCollectionFunctionName;
}

void ChargingInformation::resetSecondaryChargingCollectionFunctionName(){
	mTagsPresent[ChargingInformation_SECONDARYCHARGINGCOLLECTIONFUNCTIONNAME] = 0;
	if(mSecondaryChargingCollectionFunctionName != NULL)
	{
		delete mSecondaryChargingCollectionFunctionName; 
		mSecondaryChargingCollectionFunctionName = NULL;
	}
}

OctetString* ChargingInformation::getPrimaryEventChargingFunctionName(){
	if(NULL == mPrimaryEventChargingFunctionName) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PrimaryEventChargingFunctionName is Null");
		throw lTssDiaMsgException;
	}
	if(!mPrimaryEventChargingFunctionName->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPrimaryEventChargingFunctionName->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PrimaryEventChargingFunctionName is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPrimaryEventChargingFunctionName->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPrimaryEventChargingFunctionName->Decode(mspByteArray.get(), mPrimaryEventChargingFunctionName->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PrimaryEventChargingFunctionName")     ;
			throw lTssDiaMsgException;
		}
		mPrimaryEventChargingFunctionName->mAvpDecodedFlag = true;
	}
	return mPrimaryEventChargingFunctionName;
}

OctetString* ChargingInformation::getSecondaryEventChargingFunctionName(){
	if(NULL == mSecondaryEventChargingFunctionName) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SecondaryEventChargingFunctionName is Null");
		throw lTssDiaMsgException;
	}
	if(!mSecondaryEventChargingFunctionName->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSecondaryEventChargingFunctionName->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SecondaryEventChargingFunctionName is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSecondaryEventChargingFunctionName->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSecondaryEventChargingFunctionName->Decode(mspByteArray.get(), mSecondaryEventChargingFunctionName->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SecondaryEventChargingFunctionName")     ;
			throw lTssDiaMsgException;
		}
		mSecondaryEventChargingFunctionName->mAvpDecodedFlag = true;
	}
	return mSecondaryEventChargingFunctionName;
}

OctetString* ChargingInformation::getPrimaryChargingCollectionFunctionName(){
	if(NULL == mPrimaryChargingCollectionFunctionName) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PrimaryChargingCollectionFunctionName is Null");
		throw lTssDiaMsgException;
	}
	if(!mPrimaryChargingCollectionFunctionName->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPrimaryChargingCollectionFunctionName->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PrimaryChargingCollectionFunctionName is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPrimaryChargingCollectionFunctionName->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPrimaryChargingCollectionFunctionName->Decode(mspByteArray.get(), mPrimaryChargingCollectionFunctionName->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PrimaryChargingCollectionFunctionName")     ;
			throw lTssDiaMsgException;
		}
		mPrimaryChargingCollectionFunctionName->mAvpDecodedFlag = true;
	}
	return mPrimaryChargingCollectionFunctionName;
}

OctetString* ChargingInformation::getSecondaryChargingCollectionFunctionName(){
	if(NULL == mSecondaryChargingCollectionFunctionName) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SecondaryChargingCollectionFunctionName is Null");
		throw lTssDiaMsgException;
	}
	if(!mSecondaryChargingCollectionFunctionName->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSecondaryChargingCollectionFunctionName->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SecondaryChargingCollectionFunctionName is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSecondaryChargingCollectionFunctionName->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSecondaryChargingCollectionFunctionName->Decode(mspByteArray.get(), mSecondaryChargingCollectionFunctionName->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SecondaryChargingCollectionFunctionName")     ;
			throw lTssDiaMsgException;
		}
		mSecondaryChargingCollectionFunctionName->mAvpDecodedFlag = true;
	}
	return mSecondaryChargingCollectionFunctionName;
}



int ChargingInformation::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case ChargingInformation_PRIMARYEVENTCHARGINGFUNCTIONNAME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(619);
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
					if(!mPrimaryEventChargingFunctionName->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mPrimaryEventChargingFunctionName->getAvpOffsetLen().first], mPrimaryEventChargingFunctionName->getAvpOffsetLen().second);
						array->offset += mPrimaryEventChargingFunctionName->getAvpOffsetLen().second;
						array->size += mPrimaryEventChargingFunctionName->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mPrimaryEventChargingFunctionName->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mPrimaryEventChargingFunctionName->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PrimaryEventChargingFunctionName");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mPrimaryEventChargingFunctionName->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mPrimaryEventChargingFunctionName->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PrimaryEventChargingFunctionName");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ChargingInformation_SECONDARYEVENTCHARGINGFUNCTIONNAME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(620);
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
					if(!mSecondaryEventChargingFunctionName->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSecondaryEventChargingFunctionName->getAvpOffsetLen().first], mSecondaryEventChargingFunctionName->getAvpOffsetLen().second);
						array->offset += mSecondaryEventChargingFunctionName->getAvpOffsetLen().second;
						array->size += mSecondaryEventChargingFunctionName->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mSecondaryEventChargingFunctionName->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mSecondaryEventChargingFunctionName->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SecondaryEventChargingFunctionName");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mSecondaryEventChargingFunctionName->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mSecondaryEventChargingFunctionName->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SecondaryEventChargingFunctionName");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ChargingInformation_PRIMARYCHARGINGCOLLECTIONFUNCTIONNAME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(621);
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
					if(!mPrimaryChargingCollectionFunctionName->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mPrimaryChargingCollectionFunctionName->getAvpOffsetLen().first], mPrimaryChargingCollectionFunctionName->getAvpOffsetLen().second);
						array->offset += mPrimaryChargingCollectionFunctionName->getAvpOffsetLen().second;
						array->size += mPrimaryChargingCollectionFunctionName->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mPrimaryChargingCollectionFunctionName->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mPrimaryChargingCollectionFunctionName->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PrimaryChargingCollectionFunctionName");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mPrimaryChargingCollectionFunctionName->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mPrimaryChargingCollectionFunctionName->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PrimaryChargingCollectionFunctionName");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ChargingInformation_SECONDARYCHARGINGCOLLECTIONFUNCTIONNAME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(622);
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
					if(!mSecondaryChargingCollectionFunctionName->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSecondaryChargingCollectionFunctionName->getAvpOffsetLen().first], mSecondaryChargingCollectionFunctionName->getAvpOffsetLen().second);
						array->offset += mSecondaryChargingCollectionFunctionName->getAvpOffsetLen().second;
						array->size += mSecondaryChargingCollectionFunctionName->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mSecondaryChargingCollectionFunctionName->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mSecondaryChargingCollectionFunctionName->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SecondaryChargingCollectionFunctionName");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mSecondaryChargingCollectionFunctionName->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mSecondaryChargingCollectionFunctionName->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SecondaryChargingCollectionFunctionName");
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


int ChargingInformation::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 619:
				{
						mMandatoryAvpSetVal [ChargingInformation_PRIMARYEVENTCHARGINGFUNCTIONNAME] = 1;
					if( NULL == this->setPrimaryEventChargingFunctionName())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PrimaryEventChargingFunctionName");
						throw lTssDiaMsgException;
					}
					mPrimaryEventChargingFunctionName->setAvpCode(619);
					mPrimaryEventChargingFunctionName->setAvpVendorId(lVenderId);
					mPrimaryEventChargingFunctionName->SetDataType((DiameterDataType)5);
					mPrimaryEventChargingFunctionName->mspByteArray = mspByteArray;
					mPrimaryEventChargingFunctionName->mAvpDecodedFlag = false;
					mPrimaryEventChargingFunctionName->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 620:
				{
						mMandatoryAvpSetVal [ChargingInformation_SECONDARYEVENTCHARGINGFUNCTIONNAME] = 1;
					if( NULL == this->setSecondaryEventChargingFunctionName())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SecondaryEventChargingFunctionName");
						throw lTssDiaMsgException;
					}
					mSecondaryEventChargingFunctionName->setAvpCode(620);
					mSecondaryEventChargingFunctionName->setAvpVendorId(lVenderId);
					mSecondaryEventChargingFunctionName->SetDataType((DiameterDataType)5);
					mSecondaryEventChargingFunctionName->mspByteArray = mspByteArray;
					mSecondaryEventChargingFunctionName->mAvpDecodedFlag = false;
					mSecondaryEventChargingFunctionName->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 621:
				{
						mMandatoryAvpSetVal [ChargingInformation_PRIMARYCHARGINGCOLLECTIONFUNCTIONNAME] = 1;
					if( NULL == this->setPrimaryChargingCollectionFunctionName())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PrimaryChargingCollectionFunctionName");
						throw lTssDiaMsgException;
					}
					mPrimaryChargingCollectionFunctionName->setAvpCode(621);
					mPrimaryChargingCollectionFunctionName->setAvpVendorId(lVenderId);
					mPrimaryChargingCollectionFunctionName->SetDataType((DiameterDataType)5);
					mPrimaryChargingCollectionFunctionName->mspByteArray = mspByteArray;
					mPrimaryChargingCollectionFunctionName->mAvpDecodedFlag = false;
					mPrimaryChargingCollectionFunctionName->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 622:
				{
						mMandatoryAvpSetVal [ChargingInformation_SECONDARYCHARGINGCOLLECTIONFUNCTIONNAME] = 1;
					if( NULL == this->setSecondaryChargingCollectionFunctionName())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SecondaryChargingCollectionFunctionName");
						throw lTssDiaMsgException;
					}
					mSecondaryChargingCollectionFunctionName->setAvpCode(622);
					mSecondaryChargingCollectionFunctionName->setAvpVendorId(lVenderId);
					mSecondaryChargingCollectionFunctionName->SetDataType((DiameterDataType)5);
					mSecondaryChargingCollectionFunctionName->mspByteArray = mspByteArray;
					mSecondaryChargingCollectionFunctionName->mAvpDecodedFlag = false;
					mSecondaryChargingCollectionFunctionName->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* ChargingInformation::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ChargingInformation")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 619:
			{
				if(mPrimaryEventChargingFunctionName != NULL)
					return mPrimaryEventChargingFunctionName->Find(array, avpCode);
				else
					return NULL;
			}
			case 620:
			{
				if(mSecondaryEventChargingFunctionName != NULL)
					return mSecondaryEventChargingFunctionName->Find(array, avpCode);
				else
					return NULL;
			}
			case 621:
			{
				if(mPrimaryChargingCollectionFunctionName != NULL)
					return mPrimaryChargingCollectionFunctionName->Find(array, avpCode);
				else
					return NULL;
			}
			case 622:
			{
				if(mSecondaryChargingCollectionFunctionName != NULL)
					return mSecondaryChargingCollectionFunctionName->Find(array, avpCode);
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


BOOLEAN ChargingInformation::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ChargingInformation")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 619:
			{
				if(mPrimaryEventChargingFunctionName != NULL)
				{
					DiameterBaseInterface* inf =  mPrimaryEventChargingFunctionName->Find(this->mspByteArray.get(), avpCode);
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
			case 620:
			{
				if(mSecondaryEventChargingFunctionName != NULL)
				{
					DiameterBaseInterface* inf =  mSecondaryEventChargingFunctionName->Find(this->mspByteArray.get(), avpCode);
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
			case 621:
			{
				if(mPrimaryChargingCollectionFunctionName != NULL)
				{
					DiameterBaseInterface* inf =  mPrimaryChargingCollectionFunctionName->Find(this->mspByteArray.get(), avpCode);
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
			case 622:
			{
				if(mSecondaryChargingCollectionFunctionName != NULL)
				{
					DiameterBaseInterface* inf =  mSecondaryChargingCollectionFunctionName->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> ChargingInformation::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN ChargingInformation::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ChargingInformation")     ;
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
			case 619:
			{
				if(mPrimaryEventChargingFunctionName != NULL)
				{
					DiameterBaseInterface* inf =  mPrimaryEventChargingFunctionName->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 620:
			{
				if(mSecondaryEventChargingFunctionName != NULL)
				{
					DiameterBaseInterface* inf =  mSecondaryEventChargingFunctionName->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 621:
			{
				if(mPrimaryChargingCollectionFunctionName != NULL)
				{
					DiameterBaseInterface* inf =  mPrimaryChargingCollectionFunctionName->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 622:
			{
				if(mSecondaryChargingCollectionFunctionName != NULL)
				{
					DiameterBaseInterface* inf =  mSecondaryChargingCollectionFunctionName->Find(this->mspByteArray.get(), avpCode);
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


INT32 ChargingInformation::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 ChargingInformation::getAvpCode()
{
	return mAvpCode;
}
INT32 ChargingInformation::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 ChargingInformation::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 ChargingInformation::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> ChargingInformation::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void ChargingInformation::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case ChargingInformation_PRIMARYEVENTCHARGINGFUNCTIONNAME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "619" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PrimaryEventChargingFunctionName" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getPrimaryEventChargingFunctionName()->Display(tab+1);
			}
				break;
			case ChargingInformation_SECONDARYEVENTCHARGINGFUNCTIONNAME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "620" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SecondaryEventChargingFunctionName" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getSecondaryEventChargingFunctionName()->Display(tab+1);
			}
				break;
			case ChargingInformation_PRIMARYCHARGINGCOLLECTIONFUNCTIONNAME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "621" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PrimaryChargingCollectionFunctionName" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getPrimaryChargingCollectionFunctionName()->Display(tab+1);
			}
				break;
			case ChargingInformation_SECONDARYCHARGINGCOLLECTIONFUNCTIONNAME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "622" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SecondaryChargingCollectionFunctionName" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getSecondaryChargingCollectionFunctionName()->Display(tab+1);
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


BOOLEAN ChargingInformation::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<4> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case ChargingInformation_PRIMARYEVENTCHARGINGFUNCTIONNAME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 619");
				}
				else
					sprintf(lMissingAvpInfo, "%s,619", lMissingAvpInfo);
			}
				break;
			case ChargingInformation_SECONDARYEVENTCHARGINGFUNCTIONNAME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 620");
				}
				else
					sprintf(lMissingAvpInfo, "%s,620", lMissingAvpInfo);
			}
				break;
			case ChargingInformation_PRIMARYCHARGINGCOLLECTIONFUNCTIONNAME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 621");
				}
				else
					sprintf(lMissingAvpInfo, "%s,621", lMissingAvpInfo);
			}
				break;
			case ChargingInformation_SECONDARYCHARGINGCOLLECTIONFUNCTIONNAME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 622");
				}
				else
					sprintf(lMissingAvpInfo, "%s,622", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
