#include "rx/include/OCOLR.h"

using namespace RX;
BOOLEAN OCOLR::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

OCOLR::OCOLR()
{
	mOCSequenceNumber = NULL;
	mOCReportType = NULL;
	mOCReductionPercentage = NULL;
	mOCValidityDuration = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<4>(string("0000"));
	mMandatoryAvpSetVal.reset();
}

OCOLR::~OCOLR()
{
	if(mOCSequenceNumber != NULL)
		delete mOCSequenceNumber;
	if(mOCReportType != NULL)
		delete mOCReportType;
	if(mOCReductionPercentage != NULL)
		delete mOCReductionPercentage;
	if(mOCValidityDuration != NULL)
		delete mOCValidityDuration;
}

Unsigned64* OCOLR::setOCSequenceNumber(){
	if(mOCSequenceNumber == NULL)
	{
		mOCSequenceNumber = new Unsigned64();
		mTagsPresent[OCOLR_OCSEQUENCENUMBER] = 1;
		return mOCSequenceNumber;
	}
	return mOCSequenceNumber;
}

void OCOLR::resetOCSequenceNumber(){
	mTagsPresent[OCOLR_OCSEQUENCENUMBER] = 0;
	if(mOCSequenceNumber != NULL)
	{
		delete mOCSequenceNumber; 
		mOCSequenceNumber = NULL;
	}
}

OCReportType* OCOLR::setOCReportType(){
	if(mOCReportType == NULL)
	{
		mOCReportType = new OCReportType();
		mTagsPresent[OCOLR_OCREPORTTYPE] = 1;
		return mOCReportType;
	}
	return mOCReportType;
}

void OCOLR::resetOCReportType(){
	mTagsPresent[OCOLR_OCREPORTTYPE] = 0;
	if(mOCReportType != NULL)
	{
		delete mOCReportType; 
		mOCReportType = NULL;
	}
}

Unsigned32* OCOLR::setOCReductionPercentage(){
	if(mOCReductionPercentage == NULL)
	{
		mOCReductionPercentage = new Unsigned32();
		mTagsPresent[OCOLR_OCREDUCTIONPERCENTAGE] = 1;
		return mOCReductionPercentage;
	}
	return mOCReductionPercentage;
}

void OCOLR::resetOCReductionPercentage(){
	mTagsPresent[OCOLR_OCREDUCTIONPERCENTAGE] = 0;
	if(mOCReductionPercentage != NULL)
	{
		delete mOCReductionPercentage; 
		mOCReductionPercentage = NULL;
	}
}

Unsigned32* OCOLR::setOCValidityDuration(){
	if(mOCValidityDuration == NULL)
	{
		mOCValidityDuration = new Unsigned32();
		mTagsPresent[OCOLR_OCVALIDITYDURATION] = 1;
		return mOCValidityDuration;
	}
	return mOCValidityDuration;
}

void OCOLR::resetOCValidityDuration(){
	mTagsPresent[OCOLR_OCVALIDITYDURATION] = 0;
	if(mOCValidityDuration != NULL)
	{
		delete mOCValidityDuration; 
		mOCValidityDuration = NULL;
	}
}

Unsigned64* OCOLR::getOCSequenceNumber(){
	if(NULL == mOCSequenceNumber) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OCSequenceNumber is Null");
		throw lTssDiaMsgException;
	}
	if(!mOCSequenceNumber->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mOCSequenceNumber->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OCSequenceNumber is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mOCSequenceNumber->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mOCSequenceNumber->Decode(mspByteArray.get(), mOCSequenceNumber->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OCSequenceNumber")     ;
			throw lTssDiaMsgException;
		}
		mOCSequenceNumber->mAvpDecodedFlag = true;
	}
	return mOCSequenceNumber;
}

OCReportType* OCOLR::getOCReportType(){
	if(NULL == mOCReportType) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OCReportType is Null");
		throw lTssDiaMsgException;
	}
	if(!mOCReportType->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mOCReportType->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OCReportType is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mOCReportType->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mOCReportType->Decode(mspByteArray.get(), mOCReportType->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OCReportType")     ;
			throw lTssDiaMsgException;
		}
		mOCReportType->mAvpDecodedFlag = true;
	}
	return mOCReportType;
}

Unsigned32* OCOLR::getOCReductionPercentage(){
	if(NULL == mOCReductionPercentage) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OCReductionPercentage is Null");
		throw lTssDiaMsgException;
	}
	if(!mOCReductionPercentage->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mOCReductionPercentage->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OCReductionPercentage is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mOCReductionPercentage->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mOCReductionPercentage->Decode(mspByteArray.get(), mOCReductionPercentage->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OCReductionPercentage")     ;
			throw lTssDiaMsgException;
		}
		mOCReductionPercentage->mAvpDecodedFlag = true;
	}
	return mOCReductionPercentage;
}

Unsigned32* OCOLR::getOCValidityDuration(){
	if(NULL == mOCValidityDuration) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OCValidityDuration is Null");
		throw lTssDiaMsgException;
	}
	if(!mOCValidityDuration->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mOCValidityDuration->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OCValidityDuration is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mOCValidityDuration->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mOCValidityDuration->Decode(mspByteArray.get(), mOCValidityDuration->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OCValidityDuration")     ;
			throw lTssDiaMsgException;
		}
		mOCValidityDuration->mAvpDecodedFlag = true;
	}
	return mOCValidityDuration;
}



int OCOLR::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case OCOLR_OCSEQUENCENUMBER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(624);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 0;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(0))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mOCSequenceNumber->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mOCSequenceNumber->getAvpOffsetLen().first], mOCSequenceNumber->getAvpOffsetLen().second);
						array->offset += mOCSequenceNumber->getAvpOffsetLen().second;
						array->size += mOCSequenceNumber->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OCSequenceNumber");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mOCSequenceNumber->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OCSequenceNumber");
						throw lTssDiaMsgException;
					}
				}
				break;
			case OCOLR_OCREPORTTYPE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(626);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 0;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(0))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mOCReportType->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mOCReportType->getAvpOffsetLen().first], mOCReportType->getAvpOffsetLen().second);
						array->offset += mOCReportType->getAvpOffsetLen().second;
						array->size += mOCReportType->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OCReportType");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mOCReportType->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OCReportType");
						throw lTssDiaMsgException;
					}
				}
				break;
			case OCOLR_OCREDUCTIONPERCENTAGE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(627);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 0;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(0))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mOCReductionPercentage->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mOCReductionPercentage->getAvpOffsetLen().first], mOCReductionPercentage->getAvpOffsetLen().second);
						array->offset += mOCReductionPercentage->getAvpOffsetLen().second;
						array->size += mOCReductionPercentage->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OCReductionPercentage");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mOCReductionPercentage->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OCReductionPercentage");
						throw lTssDiaMsgException;
					}
				}
				break;
			case OCOLR_OCVALIDITYDURATION:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(625);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 0;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(0))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mOCValidityDuration->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mOCValidityDuration->getAvpOffsetLen().first], mOCValidityDuration->getAvpOffsetLen().second);
						array->offset += mOCValidityDuration->getAvpOffsetLen().second;
						array->size += mOCValidityDuration->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OCValidityDuration");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mOCValidityDuration->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OCValidityDuration");
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


int OCOLR::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 624:
				{
					if( NULL == this->setOCSequenceNumber())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OCSequenceNumber");
						throw lTssDiaMsgException;
					}
					mOCSequenceNumber->setAvpCode(624);
					mOCSequenceNumber->setAvpVendorId(lVenderId);
					mOCSequenceNumber->SetDataType((DiameterDataType)4);
					mOCSequenceNumber->mspByteArray = mspByteArray;
					mOCSequenceNumber->mAvpDecodedFlag = false;
					mOCSequenceNumber->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 626:
				{
					if( NULL == this->setOCReportType())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OCReportType");
						throw lTssDiaMsgException;
					}
					mOCReportType->setAvpCode(626);
					mOCReportType->setAvpVendorId(lVenderId);
					mOCReportType->SetDataType((DiameterDataType)7);
					mOCReportType->mspByteArray = mspByteArray;
					mOCReportType->mAvpDecodedFlag = false;
					mOCReportType->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 627:
				{
					if( NULL == this->setOCReductionPercentage())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OCReductionPercentage");
						throw lTssDiaMsgException;
					}
					mOCReductionPercentage->setAvpCode(627);
					mOCReductionPercentage->setAvpVendorId(lVenderId);
					mOCReductionPercentage->SetDataType((DiameterDataType)3);
					mOCReductionPercentage->mspByteArray = mspByteArray;
					mOCReductionPercentage->mAvpDecodedFlag = false;
					mOCReductionPercentage->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 625:
				{
					if( NULL == this->setOCValidityDuration())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OCValidityDuration");
						throw lTssDiaMsgException;
					}
					mOCValidityDuration->setAvpCode(625);
					mOCValidityDuration->setAvpVendorId(lVenderId);
					mOCValidityDuration->SetDataType((DiameterDataType)3);
					mOCValidityDuration->mspByteArray = mspByteArray;
					mOCValidityDuration->mAvpDecodedFlag = false;
					mOCValidityDuration->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* OCOLR::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OCOLR")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 624:
			{
				if(mOCSequenceNumber != NULL)
					return mOCSequenceNumber->Find(array, avpCode);
				else
					return NULL;
			}
			case 626:
			{
				if(mOCReportType != NULL)
					return mOCReportType->Find(array, avpCode);
				else
					return NULL;
			}
			case 627:
			{
				if(mOCReductionPercentage != NULL)
					return mOCReductionPercentage->Find(array, avpCode);
				else
					return NULL;
			}
			case 625:
			{
				if(mOCValidityDuration != NULL)
					return mOCValidityDuration->Find(array, avpCode);
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


BOOLEAN OCOLR::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OCOLR")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 624:
			{
				if(mOCSequenceNumber != NULL)
				{
					DiameterBaseInterface* inf =  mOCSequenceNumber->Find(this->mspByteArray.get(), avpCode);
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
			case 626:
			{
				if(mOCReportType != NULL)
				{
					DiameterBaseInterface* inf =  mOCReportType->Find(this->mspByteArray.get(), avpCode);
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
			case 627:
			{
				if(mOCReductionPercentage != NULL)
				{
					DiameterBaseInterface* inf =  mOCReductionPercentage->Find(this->mspByteArray.get(), avpCode);
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
			case 625:
			{
				if(mOCValidityDuration != NULL)
				{
					DiameterBaseInterface* inf =  mOCValidityDuration->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> OCOLR::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN OCOLR::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OCOLR")     ;
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
			case 624:
			{
				if(mOCSequenceNumber != NULL)
				{
					DiameterBaseInterface* inf =  mOCSequenceNumber->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 626:
			{
				if(mOCReportType != NULL)
				{
					DiameterBaseInterface* inf =  mOCReportType->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 627:
			{
				if(mOCReductionPercentage != NULL)
				{
					DiameterBaseInterface* inf =  mOCReductionPercentage->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 625:
			{
				if(mOCValidityDuration != NULL)
				{
					DiameterBaseInterface* inf =  mOCValidityDuration->Find(this->mspByteArray.get(), avpCode);
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


INT32 OCOLR::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 OCOLR::getAvpCode()
{
	return mAvpCode;
}
INT32 OCOLR::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 OCOLR::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 OCOLR::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> OCOLR::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void OCOLR::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case OCOLR_OCSEQUENCENUMBER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "624" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OCSequenceNumber" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getOCSequenceNumber()->Display(tab+1);
			}
				break;
			case OCOLR_OCREPORTTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "626" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OCReportType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getOCReportType()->Display(tab+1);
			}
				break;
			case OCOLR_OCREDUCTIONPERCENTAGE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "627" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OCReductionPercentage" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getOCReductionPercentage()->Display(tab+1);
			}
				break;
			case OCOLR_OCVALIDITYDURATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "625" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OCValidityDuration" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getOCValidityDuration()->Display(tab+1);
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


BOOLEAN OCOLR::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<4> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case OCOLR_OCSEQUENCENUMBER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 624");
				}
				else
					sprintf(lMissingAvpInfo, "%s,624", lMissingAvpInfo);
			}
				break;
			case OCOLR_OCREPORTTYPE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 626");
				}
				else
					sprintf(lMissingAvpInfo, "%s,626", lMissingAvpInfo);
			}
				break;
			case OCOLR_OCREDUCTIONPERCENTAGE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 627");
				}
				else
					sprintf(lMissingAvpInfo, "%s,627", lMissingAvpInfo);
			}
				break;
			case OCOLR_OCVALIDITYDURATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 625");
				}
				else
					sprintf(lMissingAvpInfo, "%s,625", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
