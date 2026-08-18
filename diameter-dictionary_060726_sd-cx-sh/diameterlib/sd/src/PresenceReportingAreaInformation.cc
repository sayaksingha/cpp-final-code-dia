#include "sd/include/PresenceReportingAreaInformation.h"

using namespace SD;
BOOLEAN PresenceReportingAreaInformation::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

PresenceReportingAreaInformation::PresenceReportingAreaInformation()
{
	mPresenceReportingAreaIdentifier = NULL;
	mPresenceReportingAreaStatus = NULL;
	mPresenceReportingAreaElementsList = NULL;
	mPresenceReportingAreaNode = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<4>(string("0000"));
	mMandatoryAvpSetVal.reset();
}

PresenceReportingAreaInformation::~PresenceReportingAreaInformation()
{
	if(mPresenceReportingAreaIdentifier != NULL)
		delete mPresenceReportingAreaIdentifier;
	if(mPresenceReportingAreaStatus != NULL)
		delete mPresenceReportingAreaStatus;
	if(mPresenceReportingAreaElementsList != NULL)
		delete mPresenceReportingAreaElementsList;
	if(mPresenceReportingAreaNode != NULL)
		delete mPresenceReportingAreaNode;
}

OctetString* PresenceReportingAreaInformation::setPresenceReportingAreaIdentifier(){
	if(mPresenceReportingAreaIdentifier == NULL)
	{
		mPresenceReportingAreaIdentifier = new OctetString();
		mTagsPresent[PresenceReportingAreaInformation_PRESENCEREPORTINGAREAIDENTIFIER] = 1;
		return mPresenceReportingAreaIdentifier;
	}
	return mPresenceReportingAreaIdentifier;
}

void PresenceReportingAreaInformation::resetPresenceReportingAreaIdentifier(){
	mTagsPresent[PresenceReportingAreaInformation_PRESENCEREPORTINGAREAIDENTIFIER] = 0;
	if(mPresenceReportingAreaIdentifier != NULL)
	{
		delete mPresenceReportingAreaIdentifier; 
		mPresenceReportingAreaIdentifier = NULL;
	}
}

Unsigned32* PresenceReportingAreaInformation::setPresenceReportingAreaStatus(){
	if(mPresenceReportingAreaStatus == NULL)
	{
		mPresenceReportingAreaStatus = new Unsigned32();
		mTagsPresent[PresenceReportingAreaInformation_PRESENCEREPORTINGAREASTATUS] = 1;
		return mPresenceReportingAreaStatus;
	}
	return mPresenceReportingAreaStatus;
}

void PresenceReportingAreaInformation::resetPresenceReportingAreaStatus(){
	mTagsPresent[PresenceReportingAreaInformation_PRESENCEREPORTINGAREASTATUS] = 0;
	if(mPresenceReportingAreaStatus != NULL)
	{
		delete mPresenceReportingAreaStatus; 
		mPresenceReportingAreaStatus = NULL;
	}
}

OctetString* PresenceReportingAreaInformation::setPresenceReportingAreaElementsList(){
	if(mPresenceReportingAreaElementsList == NULL)
	{
		mPresenceReportingAreaElementsList = new OctetString();
		mTagsPresent[PresenceReportingAreaInformation_PRESENCEREPORTINGAREAELEMENTSLIST] = 1;
		return mPresenceReportingAreaElementsList;
	}
	return mPresenceReportingAreaElementsList;
}

void PresenceReportingAreaInformation::resetPresenceReportingAreaElementsList(){
	mTagsPresent[PresenceReportingAreaInformation_PRESENCEREPORTINGAREAELEMENTSLIST] = 0;
	if(mPresenceReportingAreaElementsList != NULL)
	{
		delete mPresenceReportingAreaElementsList; 
		mPresenceReportingAreaElementsList = NULL;
	}
}

Unsigned32* PresenceReportingAreaInformation::setPresenceReportingAreaNode(){
	if(mPresenceReportingAreaNode == NULL)
	{
		mPresenceReportingAreaNode = new Unsigned32();
		mTagsPresent[PresenceReportingAreaInformation_PRESENCEREPORTINGAREANODE] = 1;
		return mPresenceReportingAreaNode;
	}
	return mPresenceReportingAreaNode;
}

void PresenceReportingAreaInformation::resetPresenceReportingAreaNode(){
	mTagsPresent[PresenceReportingAreaInformation_PRESENCEREPORTINGAREANODE] = 0;
	if(mPresenceReportingAreaNode != NULL)
	{
		delete mPresenceReportingAreaNode; 
		mPresenceReportingAreaNode = NULL;
	}
}

OctetString* PresenceReportingAreaInformation::getPresenceReportingAreaIdentifier(){
	if(NULL == mPresenceReportingAreaIdentifier) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PresenceReportingAreaIdentifier is Null");
		throw lTssDiaMsgException;
	}
	if(!mPresenceReportingAreaIdentifier->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPresenceReportingAreaIdentifier->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PresenceReportingAreaIdentifier is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPresenceReportingAreaIdentifier->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPresenceReportingAreaIdentifier->Decode(mspByteArray.get(), mPresenceReportingAreaIdentifier->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PresenceReportingAreaIdentifier")     ;
			throw lTssDiaMsgException;
		}
		mPresenceReportingAreaIdentifier->mAvpDecodedFlag = true;
	}
	return mPresenceReportingAreaIdentifier;
}

Unsigned32* PresenceReportingAreaInformation::getPresenceReportingAreaStatus(){
	if(NULL == mPresenceReportingAreaStatus) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PresenceReportingAreaStatus is Null");
		throw lTssDiaMsgException;
	}
	if(!mPresenceReportingAreaStatus->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPresenceReportingAreaStatus->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PresenceReportingAreaStatus is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPresenceReportingAreaStatus->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPresenceReportingAreaStatus->Decode(mspByteArray.get(), mPresenceReportingAreaStatus->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PresenceReportingAreaStatus")     ;
			throw lTssDiaMsgException;
		}
		mPresenceReportingAreaStatus->mAvpDecodedFlag = true;
	}
	return mPresenceReportingAreaStatus;
}

OctetString* PresenceReportingAreaInformation::getPresenceReportingAreaElementsList(){
	if(NULL == mPresenceReportingAreaElementsList) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PresenceReportingAreaElementsList is Null");
		throw lTssDiaMsgException;
	}
	if(!mPresenceReportingAreaElementsList->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPresenceReportingAreaElementsList->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PresenceReportingAreaElementsList is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPresenceReportingAreaElementsList->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPresenceReportingAreaElementsList->Decode(mspByteArray.get(), mPresenceReportingAreaElementsList->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PresenceReportingAreaElementsList")     ;
			throw lTssDiaMsgException;
		}
		mPresenceReportingAreaElementsList->mAvpDecodedFlag = true;
	}
	return mPresenceReportingAreaElementsList;
}

Unsigned32* PresenceReportingAreaInformation::getPresenceReportingAreaNode(){
	if(NULL == mPresenceReportingAreaNode) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PresenceReportingAreaNode is Null");
		throw lTssDiaMsgException;
	}
	if(!mPresenceReportingAreaNode->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPresenceReportingAreaNode->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PresenceReportingAreaNode is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPresenceReportingAreaNode->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPresenceReportingAreaNode->Decode(mspByteArray.get(), mPresenceReportingAreaNode->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PresenceReportingAreaNode")     ;
			throw lTssDiaMsgException;
		}
		mPresenceReportingAreaNode->mAvpDecodedFlag = true;
	}
	return mPresenceReportingAreaNode;
}



int PresenceReportingAreaInformation::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case PresenceReportingAreaInformation_PRESENCEREPORTINGAREAIDENTIFIER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2821);
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
					if(!mPresenceReportingAreaIdentifier->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mPresenceReportingAreaIdentifier->getAvpOffsetLen().first], mPresenceReportingAreaIdentifier->getAvpOffsetLen().second);
						array->offset += mPresenceReportingAreaIdentifier->getAvpOffsetLen().second;
						array->size += mPresenceReportingAreaIdentifier->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mPresenceReportingAreaIdentifier->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mPresenceReportingAreaIdentifier->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PresenceReportingAreaIdentifier");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mPresenceReportingAreaIdentifier->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mPresenceReportingAreaIdentifier->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PresenceReportingAreaIdentifier");
						throw lTssDiaMsgException;
					}
				}
				break;
			case PresenceReportingAreaInformation_PRESENCEREPORTINGAREASTATUS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2823);
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
					if(!mPresenceReportingAreaStatus->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mPresenceReportingAreaStatus->getAvpOffsetLen().first], mPresenceReportingAreaStatus->getAvpOffsetLen().second);
						array->offset += mPresenceReportingAreaStatus->getAvpOffsetLen().second;
						array->size += mPresenceReportingAreaStatus->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PresenceReportingAreaStatus");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mPresenceReportingAreaStatus->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PresenceReportingAreaStatus");
						throw lTssDiaMsgException;
					}
				}
				break;
			case PresenceReportingAreaInformation_PRESENCEREPORTINGAREAELEMENTSLIST:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2820);
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
					if(!mPresenceReportingAreaElementsList->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mPresenceReportingAreaElementsList->getAvpOffsetLen().first], mPresenceReportingAreaElementsList->getAvpOffsetLen().second);
						array->offset += mPresenceReportingAreaElementsList->getAvpOffsetLen().second;
						array->size += mPresenceReportingAreaElementsList->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mPresenceReportingAreaElementsList->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mPresenceReportingAreaElementsList->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PresenceReportingAreaElementsList");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mPresenceReportingAreaElementsList->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mPresenceReportingAreaElementsList->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PresenceReportingAreaElementsList");
						throw lTssDiaMsgException;
					}
				}
				break;
			case PresenceReportingAreaInformation_PRESENCEREPORTINGAREANODE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2855);
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
					if(!mPresenceReportingAreaNode->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mPresenceReportingAreaNode->getAvpOffsetLen().first], mPresenceReportingAreaNode->getAvpOffsetLen().second);
						array->offset += mPresenceReportingAreaNode->getAvpOffsetLen().second;
						array->size += mPresenceReportingAreaNode->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PresenceReportingAreaNode");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mPresenceReportingAreaNode->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PresenceReportingAreaNode");
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


int PresenceReportingAreaInformation::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 2821:
				{
					if( NULL == this->setPresenceReportingAreaIdentifier())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PresenceReportingAreaIdentifier");
						throw lTssDiaMsgException;
					}
					mPresenceReportingAreaIdentifier->setAvpCode(2821);
					mPresenceReportingAreaIdentifier->setAvpVendorId(lVenderId);
					mPresenceReportingAreaIdentifier->SetDataType((DiameterDataType)5);
					mPresenceReportingAreaIdentifier->mspByteArray = mspByteArray;
					mPresenceReportingAreaIdentifier->mAvpDecodedFlag = false;
					mPresenceReportingAreaIdentifier->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2823:
				{
					if( NULL == this->setPresenceReportingAreaStatus())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PresenceReportingAreaStatus");
						throw lTssDiaMsgException;
					}
					mPresenceReportingAreaStatus->setAvpCode(2823);
					mPresenceReportingAreaStatus->setAvpVendorId(lVenderId);
					mPresenceReportingAreaStatus->SetDataType((DiameterDataType)3);
					mPresenceReportingAreaStatus->mspByteArray = mspByteArray;
					mPresenceReportingAreaStatus->mAvpDecodedFlag = false;
					mPresenceReportingAreaStatus->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2820:
				{
					if( NULL == this->setPresenceReportingAreaElementsList())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PresenceReportingAreaElementsList");
						throw lTssDiaMsgException;
					}
					mPresenceReportingAreaElementsList->setAvpCode(2820);
					mPresenceReportingAreaElementsList->setAvpVendorId(lVenderId);
					mPresenceReportingAreaElementsList->SetDataType((DiameterDataType)5);
					mPresenceReportingAreaElementsList->mspByteArray = mspByteArray;
					mPresenceReportingAreaElementsList->mAvpDecodedFlag = false;
					mPresenceReportingAreaElementsList->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2855:
				{
					if( NULL == this->setPresenceReportingAreaNode())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PresenceReportingAreaNode");
						throw lTssDiaMsgException;
					}
					mPresenceReportingAreaNode->setAvpCode(2855);
					mPresenceReportingAreaNode->setAvpVendorId(lVenderId);
					mPresenceReportingAreaNode->SetDataType((DiameterDataType)3);
					mPresenceReportingAreaNode->mspByteArray = mspByteArray;
					mPresenceReportingAreaNode->mAvpDecodedFlag = false;
					mPresenceReportingAreaNode->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* PresenceReportingAreaInformation::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PresenceReportingAreaInformation")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 2821:
			{
				if(mPresenceReportingAreaIdentifier != NULL)
					return mPresenceReportingAreaIdentifier->Find(array, avpCode);
				else
					return NULL;
			}
			case 2823:
			{
				if(mPresenceReportingAreaStatus != NULL)
					return mPresenceReportingAreaStatus->Find(array, avpCode);
				else
					return NULL;
			}
			case 2820:
			{
				if(mPresenceReportingAreaElementsList != NULL)
					return mPresenceReportingAreaElementsList->Find(array, avpCode);
				else
					return NULL;
			}
			case 2855:
			{
				if(mPresenceReportingAreaNode != NULL)
					return mPresenceReportingAreaNode->Find(array, avpCode);
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


BOOLEAN PresenceReportingAreaInformation::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PresenceReportingAreaInformation")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 2821:
			{
				if(mPresenceReportingAreaIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mPresenceReportingAreaIdentifier->Find(this->mspByteArray.get(), avpCode);
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
			case 2823:
			{
				if(mPresenceReportingAreaStatus != NULL)
				{
					DiameterBaseInterface* inf =  mPresenceReportingAreaStatus->Find(this->mspByteArray.get(), avpCode);
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
			case 2820:
			{
				if(mPresenceReportingAreaElementsList != NULL)
				{
					DiameterBaseInterface* inf =  mPresenceReportingAreaElementsList->Find(this->mspByteArray.get(), avpCode);
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
			case 2855:
			{
				if(mPresenceReportingAreaNode != NULL)
				{
					DiameterBaseInterface* inf =  mPresenceReportingAreaNode->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> PresenceReportingAreaInformation::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN PresenceReportingAreaInformation::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PresenceReportingAreaInformation")     ;
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
			case 2821:
			{
				if(mPresenceReportingAreaIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mPresenceReportingAreaIdentifier->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2823:
			{
				if(mPresenceReportingAreaStatus != NULL)
				{
					DiameterBaseInterface* inf =  mPresenceReportingAreaStatus->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2820:
			{
				if(mPresenceReportingAreaElementsList != NULL)
				{
					DiameterBaseInterface* inf =  mPresenceReportingAreaElementsList->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2855:
			{
				if(mPresenceReportingAreaNode != NULL)
				{
					DiameterBaseInterface* inf =  mPresenceReportingAreaNode->Find(this->mspByteArray.get(), avpCode);
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


INT32 PresenceReportingAreaInformation::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 PresenceReportingAreaInformation::getAvpCode()
{
	return mAvpCode;
}
INT32 PresenceReportingAreaInformation::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 PresenceReportingAreaInformation::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 PresenceReportingAreaInformation::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> PresenceReportingAreaInformation::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void PresenceReportingAreaInformation::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case PresenceReportingAreaInformation_PRESENCEREPORTINGAREAIDENTIFIER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2821" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PresenceReportingAreaIdentifier" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getPresenceReportingAreaIdentifier()->Display(tab+1);
			}
				break;
			case PresenceReportingAreaInformation_PRESENCEREPORTINGAREASTATUS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2823" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PresenceReportingAreaStatus" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getPresenceReportingAreaStatus()->Display(tab+1);
			}
				break;
			case PresenceReportingAreaInformation_PRESENCEREPORTINGAREAELEMENTSLIST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2820" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PresenceReportingAreaElementsList" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getPresenceReportingAreaElementsList()->Display(tab+1);
			}
				break;
			case PresenceReportingAreaInformation_PRESENCEREPORTINGAREANODE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2855" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PresenceReportingAreaNode" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getPresenceReportingAreaNode()->Display(tab+1);
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


BOOLEAN PresenceReportingAreaInformation::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<4> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case PresenceReportingAreaInformation_PRESENCEREPORTINGAREAIDENTIFIER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2821");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2821", lMissingAvpInfo);
			}
				break;
			case PresenceReportingAreaInformation_PRESENCEREPORTINGAREASTATUS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2823");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2823", lMissingAvpInfo);
			}
				break;
			case PresenceReportingAreaInformation_PRESENCEREPORTINGAREAELEMENTSLIST:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2820");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2820", lMissingAvpInfo);
			}
				break;
			case PresenceReportingAreaInformation_PRESENCEREPORTINGAREANODE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2855");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2855", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
