#include "cx/include/PCSCFSubscriptionInfo.h"

using namespace CX;
BOOLEAN PCSCFSubscriptionInfo::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

PCSCFSubscriptionInfo::PCSCFSubscriptionInfo()
{
	mCallIDSIPHeader = NULL;
	mFromSIPHeader = NULL;
	mToSIPHeader = NULL;
	mContact = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<4>(string("0000"));
	mMandatoryAvpSetVal.reset();
}

PCSCFSubscriptionInfo::~PCSCFSubscriptionInfo()
{
	if(mCallIDSIPHeader != NULL)
		delete mCallIDSIPHeader;
	if(mFromSIPHeader != NULL)
		delete mFromSIPHeader;
	if(mToSIPHeader != NULL)
		delete mToSIPHeader;
	if(mContact != NULL)
		delete mContact;
}

OctetString* PCSCFSubscriptionInfo::setCallIDSIPHeader(){
	if(mCallIDSIPHeader == NULL)
	{
		mCallIDSIPHeader = new OctetString();
		mTagsPresent[PCSCFSubscriptionInfo_CALLIDSIPHEADER] = 1;
		return mCallIDSIPHeader;
	}
	return mCallIDSIPHeader;
}

void PCSCFSubscriptionInfo::resetCallIDSIPHeader(){
	mTagsPresent[PCSCFSubscriptionInfo_CALLIDSIPHEADER] = 0;
	if(mCallIDSIPHeader != NULL)
	{
		delete mCallIDSIPHeader; 
		mCallIDSIPHeader = NULL;
	}
}

OctetString* PCSCFSubscriptionInfo::setFromSIPHeader(){
	if(mFromSIPHeader == NULL)
	{
		mFromSIPHeader = new OctetString();
		mTagsPresent[PCSCFSubscriptionInfo_FROMSIPHEADER] = 1;
		return mFromSIPHeader;
	}
	return mFromSIPHeader;
}

void PCSCFSubscriptionInfo::resetFromSIPHeader(){
	mTagsPresent[PCSCFSubscriptionInfo_FROMSIPHEADER] = 0;
	if(mFromSIPHeader != NULL)
	{
		delete mFromSIPHeader; 
		mFromSIPHeader = NULL;
	}
}

OctetString* PCSCFSubscriptionInfo::setToSIPHeader(){
	if(mToSIPHeader == NULL)
	{
		mToSIPHeader = new OctetString();
		mTagsPresent[PCSCFSubscriptionInfo_TOSIPHEADER] = 1;
		return mToSIPHeader;
	}
	return mToSIPHeader;
}

void PCSCFSubscriptionInfo::resetToSIPHeader(){
	mTagsPresent[PCSCFSubscriptionInfo_TOSIPHEADER] = 0;
	if(mToSIPHeader != NULL)
	{
		delete mToSIPHeader; 
		mToSIPHeader = NULL;
	}
}

OctetString* PCSCFSubscriptionInfo::setContact(){
	if(mContact == NULL)
	{
		mContact = new OctetString();
		mTagsPresent[PCSCFSubscriptionInfo_CONTACT] = 1;
		return mContact;
	}
	return mContact;
}

void PCSCFSubscriptionInfo::resetContact(){
	mTagsPresent[PCSCFSubscriptionInfo_CONTACT] = 0;
	if(mContact != NULL)
	{
		delete mContact; 
		mContact = NULL;
	}
}

OctetString* PCSCFSubscriptionInfo::getCallIDSIPHeader(){
	if(NULL == mCallIDSIPHeader) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CallIDSIPHeader is Null");
		throw lTssDiaMsgException;
	}
	if(!mCallIDSIPHeader->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCallIDSIPHeader->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CallIDSIPHeader is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCallIDSIPHeader->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCallIDSIPHeader->Decode(mspByteArray.get(), mCallIDSIPHeader->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CallIDSIPHeader")     ;
			throw lTssDiaMsgException;
		}
		mCallIDSIPHeader->mAvpDecodedFlag = true;
	}
	return mCallIDSIPHeader;
}

OctetString* PCSCFSubscriptionInfo::getFromSIPHeader(){
	if(NULL == mFromSIPHeader) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FromSIPHeader is Null");
		throw lTssDiaMsgException;
	}
	if(!mFromSIPHeader->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mFromSIPHeader->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FromSIPHeader is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mFromSIPHeader->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mFromSIPHeader->Decode(mspByteArray.get(), mFromSIPHeader->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FromSIPHeader")     ;
			throw lTssDiaMsgException;
		}
		mFromSIPHeader->mAvpDecodedFlag = true;
	}
	return mFromSIPHeader;
}

OctetString* PCSCFSubscriptionInfo::getToSIPHeader(){
	if(NULL == mToSIPHeader) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ToSIPHeader is Null");
		throw lTssDiaMsgException;
	}
	if(!mToSIPHeader->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mToSIPHeader->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ToSIPHeader is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mToSIPHeader->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mToSIPHeader->Decode(mspByteArray.get(), mToSIPHeader->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ToSIPHeader")     ;
			throw lTssDiaMsgException;
		}
		mToSIPHeader->mAvpDecodedFlag = true;
	}
	return mToSIPHeader;
}

OctetString* PCSCFSubscriptionInfo::getContact(){
	if(NULL == mContact) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Contact is Null");
		throw lTssDiaMsgException;
	}
	if(!mContact->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mContact->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Contact is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mContact->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mContact->Decode(mspByteArray.get(), mContact->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Contact")     ;
			throw lTssDiaMsgException;
		}
		mContact->mAvpDecodedFlag = true;
	}
	return mContact;
}



int PCSCFSubscriptionInfo::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case PCSCFSubscriptionInfo_CALLIDSIPHEADER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(643);
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
					if(!mCallIDSIPHeader->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCallIDSIPHeader->getAvpOffsetLen().first], mCallIDSIPHeader->getAvpOffsetLen().second);
						array->offset += mCallIDSIPHeader->getAvpOffsetLen().second;
						array->size += mCallIDSIPHeader->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mCallIDSIPHeader->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mCallIDSIPHeader->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CallIDSIPHeader");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mCallIDSIPHeader->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mCallIDSIPHeader->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CallIDSIPHeader");
						throw lTssDiaMsgException;
					}
				}
				break;
			case PCSCFSubscriptionInfo_FROMSIPHEADER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(644);
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
					if(!mFromSIPHeader->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mFromSIPHeader->getAvpOffsetLen().first], mFromSIPHeader->getAvpOffsetLen().second);
						array->offset += mFromSIPHeader->getAvpOffsetLen().second;
						array->size += mFromSIPHeader->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mFromSIPHeader->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mFromSIPHeader->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FromSIPHeader");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mFromSIPHeader->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mFromSIPHeader->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FromSIPHeader");
						throw lTssDiaMsgException;
					}
				}
				break;
			case PCSCFSubscriptionInfo_TOSIPHEADER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(645);
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
					if(!mToSIPHeader->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mToSIPHeader->getAvpOffsetLen().first], mToSIPHeader->getAvpOffsetLen().second);
						array->offset += mToSIPHeader->getAvpOffsetLen().second;
						array->size += mToSIPHeader->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mToSIPHeader->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mToSIPHeader->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ToSIPHeader");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mToSIPHeader->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mToSIPHeader->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ToSIPHeader");
						throw lTssDiaMsgException;
					}
				}
				break;
			case PCSCFSubscriptionInfo_CONTACT:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(641);
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
					if(!mContact->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mContact->getAvpOffsetLen().first], mContact->getAvpOffsetLen().second);
						array->offset += mContact->getAvpOffsetLen().second;
						array->size += mContact->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mContact->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mContact->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Contact");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mContact->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mContact->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Contact");
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


int PCSCFSubscriptionInfo::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 643:
				{
					if( NULL == this->setCallIDSIPHeader())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CallIDSIPHeader");
						throw lTssDiaMsgException;
					}
					mCallIDSIPHeader->setAvpCode(643);
					mCallIDSIPHeader->setAvpVendorId(lVenderId);
					mCallIDSIPHeader->SetDataType((DiameterDataType)5);
					mCallIDSIPHeader->mspByteArray = mspByteArray;
					mCallIDSIPHeader->mAvpDecodedFlag = false;
					mCallIDSIPHeader->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 644:
				{
					if( NULL == this->setFromSIPHeader())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FromSIPHeader");
						throw lTssDiaMsgException;
					}
					mFromSIPHeader->setAvpCode(644);
					mFromSIPHeader->setAvpVendorId(lVenderId);
					mFromSIPHeader->SetDataType((DiameterDataType)5);
					mFromSIPHeader->mspByteArray = mspByteArray;
					mFromSIPHeader->mAvpDecodedFlag = false;
					mFromSIPHeader->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 645:
				{
					if( NULL == this->setToSIPHeader())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ToSIPHeader");
						throw lTssDiaMsgException;
					}
					mToSIPHeader->setAvpCode(645);
					mToSIPHeader->setAvpVendorId(lVenderId);
					mToSIPHeader->SetDataType((DiameterDataType)5);
					mToSIPHeader->mspByteArray = mspByteArray;
					mToSIPHeader->mAvpDecodedFlag = false;
					mToSIPHeader->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 641:
				{
					if( NULL == this->setContact())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Contact");
						throw lTssDiaMsgException;
					}
					mContact->setAvpCode(641);
					mContact->setAvpVendorId(lVenderId);
					mContact->SetDataType((DiameterDataType)5);
					mContact->mspByteArray = mspByteArray;
					mContact->mAvpDecodedFlag = false;
					mContact->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* PCSCFSubscriptionInfo::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PCSCFSubscriptionInfo")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 643:
			{
				if(mCallIDSIPHeader != NULL)
					return mCallIDSIPHeader->Find(array, avpCode);
				else
					return NULL;
			}
			case 644:
			{
				if(mFromSIPHeader != NULL)
					return mFromSIPHeader->Find(array, avpCode);
				else
					return NULL;
			}
			case 645:
			{
				if(mToSIPHeader != NULL)
					return mToSIPHeader->Find(array, avpCode);
				else
					return NULL;
			}
			case 641:
			{
				if(mContact != NULL)
					return mContact->Find(array, avpCode);
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


BOOLEAN PCSCFSubscriptionInfo::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PCSCFSubscriptionInfo")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 643:
			{
				if(mCallIDSIPHeader != NULL)
				{
					DiameterBaseInterface* inf =  mCallIDSIPHeader->Find(this->mspByteArray.get(), avpCode);
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
			case 644:
			{
				if(mFromSIPHeader != NULL)
				{
					DiameterBaseInterface* inf =  mFromSIPHeader->Find(this->mspByteArray.get(), avpCode);
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
			case 645:
			{
				if(mToSIPHeader != NULL)
				{
					DiameterBaseInterface* inf =  mToSIPHeader->Find(this->mspByteArray.get(), avpCode);
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
			case 641:
			{
				if(mContact != NULL)
				{
					DiameterBaseInterface* inf =  mContact->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> PCSCFSubscriptionInfo::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN PCSCFSubscriptionInfo::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PCSCFSubscriptionInfo")     ;
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
			case 643:
			{
				if(mCallIDSIPHeader != NULL)
				{
					DiameterBaseInterface* inf =  mCallIDSIPHeader->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 644:
			{
				if(mFromSIPHeader != NULL)
				{
					DiameterBaseInterface* inf =  mFromSIPHeader->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 645:
			{
				if(mToSIPHeader != NULL)
				{
					DiameterBaseInterface* inf =  mToSIPHeader->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 641:
			{
				if(mContact != NULL)
				{
					DiameterBaseInterface* inf =  mContact->Find(this->mspByteArray.get(), avpCode);
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


INT32 PCSCFSubscriptionInfo::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 PCSCFSubscriptionInfo::getAvpCode()
{
	return mAvpCode;
}
INT32 PCSCFSubscriptionInfo::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 PCSCFSubscriptionInfo::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 PCSCFSubscriptionInfo::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> PCSCFSubscriptionInfo::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void PCSCFSubscriptionInfo::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case PCSCFSubscriptionInfo_CALLIDSIPHEADER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "643" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CallIDSIPHeader" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getCallIDSIPHeader()->Display(tab+1);
			}
				break;
			case PCSCFSubscriptionInfo_FROMSIPHEADER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "644" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FromSIPHeader" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getFromSIPHeader()->Display(tab+1);
			}
				break;
			case PCSCFSubscriptionInfo_TOSIPHEADER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "645" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ToSIPHeader" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getToSIPHeader()->Display(tab+1);
			}
				break;
			case PCSCFSubscriptionInfo_CONTACT:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "641" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "Contact" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getContact()->Display(tab+1);
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


BOOLEAN PCSCFSubscriptionInfo::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<4> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case PCSCFSubscriptionInfo_CALLIDSIPHEADER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 643");
				}
				else
					sprintf(lMissingAvpInfo, "%s,643", lMissingAvpInfo);
			}
				break;
			case PCSCFSubscriptionInfo_FROMSIPHEADER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 644");
				}
				else
					sprintf(lMissingAvpInfo, "%s,644", lMissingAvpInfo);
			}
				break;
			case PCSCFSubscriptionInfo_TOSIPHEADER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 645");
				}
				else
					sprintf(lMissingAvpInfo, "%s,645", lMissingAvpInfo);
			}
				break;
			case PCSCFSubscriptionInfo_CONTACT:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 641");
				}
				else
					sprintf(lMissingAvpInfo, "%s,641", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
