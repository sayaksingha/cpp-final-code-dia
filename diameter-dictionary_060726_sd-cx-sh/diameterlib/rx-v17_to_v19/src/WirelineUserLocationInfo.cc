#include "rx/include/WirelineUserLocationInfo.h"

using namespace RX;
BOOLEAN WirelineUserLocationInfo::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

WirelineUserLocationInfo::WirelineUserLocationInfo()
{
	mHFCNodeIdentifierAVP = NULL;
	mGLIIdentifierAVP = NULL;
	mLineTypeAVP = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<3>(string("000"));
	mMandatoryAvpSetVal.reset();
}

WirelineUserLocationInfo::~WirelineUserLocationInfo()
{
	if(mHFCNodeIdentifierAVP != NULL)
		delete mHFCNodeIdentifierAVP;
	if(mGLIIdentifierAVP != NULL)
		delete mGLIIdentifierAVP;
	if(mLineTypeAVP != NULL)
		delete mLineTypeAVP;
}

OctetString* WirelineUserLocationInfo::setHFCNodeIdentifierAVP(){
	if(mHFCNodeIdentifierAVP == NULL)
	{
		mHFCNodeIdentifierAVP = new OctetString();
		mTagsPresent[WirelineUserLocationInfo_HFCNODEIDENTIFIERAVP] = 1;
		return mHFCNodeIdentifierAVP;
	}
	return mHFCNodeIdentifierAVP;
}

void WirelineUserLocationInfo::resetHFCNodeIdentifierAVP(){
	mTagsPresent[WirelineUserLocationInfo_HFCNODEIDENTIFIERAVP] = 0;
	if(mHFCNodeIdentifierAVP != NULL)
	{
		delete mHFCNodeIdentifierAVP; 
		mHFCNodeIdentifierAVP = NULL;
	}
}

OctetString* WirelineUserLocationInfo::setGLIIdentifierAVP(){
	if(mGLIIdentifierAVP == NULL)
	{
		mGLIIdentifierAVP = new OctetString();
		mTagsPresent[WirelineUserLocationInfo_GLIIDENTIFIERAVP] = 1;
		return mGLIIdentifierAVP;
	}
	return mGLIIdentifierAVP;
}

void WirelineUserLocationInfo::resetGLIIdentifierAVP(){
	mTagsPresent[WirelineUserLocationInfo_GLIIDENTIFIERAVP] = 0;
	if(mGLIIdentifierAVP != NULL)
	{
		delete mGLIIdentifierAVP; 
		mGLIIdentifierAVP = NULL;
	}
}

Unsigned32* WirelineUserLocationInfo::setLineTypeAVP(){
	if(mLineTypeAVP == NULL)
	{
		mLineTypeAVP = new Unsigned32();
		mTagsPresent[WirelineUserLocationInfo_LINETYPEAVP] = 1;
		return mLineTypeAVP;
	}
	return mLineTypeAVP;
}

void WirelineUserLocationInfo::resetLineTypeAVP(){
	mTagsPresent[WirelineUserLocationInfo_LINETYPEAVP] = 0;
	if(mLineTypeAVP != NULL)
	{
		delete mLineTypeAVP; 
		mLineTypeAVP = NULL;
	}
}

OctetString* WirelineUserLocationInfo::getHFCNodeIdentifierAVP(){
	if(NULL == mHFCNodeIdentifierAVP) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "HFCNodeIdentifierAVP is Null");
		throw lTssDiaMsgException;
	}
	if(!mHFCNodeIdentifierAVP->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mHFCNodeIdentifierAVP->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "HFCNodeIdentifierAVP is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mHFCNodeIdentifierAVP->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mHFCNodeIdentifierAVP->Decode(mspByteArray.get(), mHFCNodeIdentifierAVP->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding HFCNodeIdentifierAVP")     ;
			throw lTssDiaMsgException;
		}
		mHFCNodeIdentifierAVP->mAvpDecodedFlag = true;
	}
	return mHFCNodeIdentifierAVP;
}

OctetString* WirelineUserLocationInfo::getGLIIdentifierAVP(){
	if(NULL == mGLIIdentifierAVP) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "GLIIdentifierAVP is Null");
		throw lTssDiaMsgException;
	}
	if(!mGLIIdentifierAVP->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mGLIIdentifierAVP->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "GLIIdentifierAVP is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mGLIIdentifierAVP->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mGLIIdentifierAVP->Decode(mspByteArray.get(), mGLIIdentifierAVP->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding GLIIdentifierAVP")     ;
			throw lTssDiaMsgException;
		}
		mGLIIdentifierAVP->mAvpDecodedFlag = true;
	}
	return mGLIIdentifierAVP;
}

Unsigned32* WirelineUserLocationInfo::getLineTypeAVP(){
	if(NULL == mLineTypeAVP) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "LineTypeAVP is Null");
		throw lTssDiaMsgException;
	}
	if(!mLineTypeAVP->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mLineTypeAVP->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "LineTypeAVP is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mLineTypeAVP->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mLineTypeAVP->Decode(mspByteArray.get(), mLineTypeAVP->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding LineTypeAVP")     ;
			throw lTssDiaMsgException;
		}
		mLineTypeAVP->mAvpDecodedFlag = true;
	}
	return mLineTypeAVP;
}



int WirelineUserLocationInfo::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case WirelineUserLocationInfo_HFCNODEIDENTIFIERAVP:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(579);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 160;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(160))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mHFCNodeIdentifierAVP->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mHFCNodeIdentifierAVP->getAvpOffsetLen().first], mHFCNodeIdentifierAVP->getAvpOffsetLen().second);
						array->offset += mHFCNodeIdentifierAVP->getAvpOffsetLen().second;
						array->size += mHFCNodeIdentifierAVP->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mHFCNodeIdentifierAVP->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mHFCNodeIdentifierAVP->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding HFCNodeIdentifierAVP");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mHFCNodeIdentifierAVP->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mHFCNodeIdentifierAVP->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding HFCNodeIdentifierAVP");
						throw lTssDiaMsgException;
					}
				}
				break;
			case WirelineUserLocationInfo_GLIIDENTIFIERAVP:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(580);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 160;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(160))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mGLIIdentifierAVP->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mGLIIdentifierAVP->getAvpOffsetLen().first], mGLIIdentifierAVP->getAvpOffsetLen().second);
						array->offset += mGLIIdentifierAVP->getAvpOffsetLen().second;
						array->size += mGLIIdentifierAVP->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mGLIIdentifierAVP->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mGLIIdentifierAVP->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding GLIIdentifierAVP");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mGLIIdentifierAVP->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mGLIIdentifierAVP->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding GLIIdentifierAVP");
						throw lTssDiaMsgException;
					}
				}
				break;
			case WirelineUserLocationInfo_LINETYPEAVP:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(581);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 160;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(160))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mLineTypeAVP->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mLineTypeAVP->getAvpOffsetLen().first], mLineTypeAVP->getAvpOffsetLen().second);
						array->offset += mLineTypeAVP->getAvpOffsetLen().second;
						array->size += mLineTypeAVP->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding LineTypeAVP");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mLineTypeAVP->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding LineTypeAVP");
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


int WirelineUserLocationInfo::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 579:
				{
					if( NULL == this->setHFCNodeIdentifierAVP())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding HFCNodeIdentifierAVP");
						throw lTssDiaMsgException;
					}
					mHFCNodeIdentifierAVP->setAvpCode(579);
					mHFCNodeIdentifierAVP->setAvpVendorId(lVenderId);
					mHFCNodeIdentifierAVP->SetDataType((DiameterDataType)5);
					mHFCNodeIdentifierAVP->mspByteArray = mspByteArray;
					mHFCNodeIdentifierAVP->mAvpDecodedFlag = false;
					mHFCNodeIdentifierAVP->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 580:
				{
					if( NULL == this->setGLIIdentifierAVP())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding GLIIdentifierAVP");
						throw lTssDiaMsgException;
					}
					mGLIIdentifierAVP->setAvpCode(580);
					mGLIIdentifierAVP->setAvpVendorId(lVenderId);
					mGLIIdentifierAVP->SetDataType((DiameterDataType)5);
					mGLIIdentifierAVP->mspByteArray = mspByteArray;
					mGLIIdentifierAVP->mAvpDecodedFlag = false;
					mGLIIdentifierAVP->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 581:
				{
					if( NULL == this->setLineTypeAVP())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding LineTypeAVP");
						throw lTssDiaMsgException;
					}
					mLineTypeAVP->setAvpCode(581);
					mLineTypeAVP->setAvpVendorId(lVenderId);
					mLineTypeAVP->SetDataType((DiameterDataType)3);
					mLineTypeAVP->mspByteArray = mspByteArray;
					mLineTypeAVP->mAvpDecodedFlag = false;
					mLineTypeAVP->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* WirelineUserLocationInfo::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding WirelineUserLocationInfo")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 579:
			{
				if(mHFCNodeIdentifierAVP != NULL)
					return mHFCNodeIdentifierAVP->Find(array, avpCode);
				else
					return NULL;
			}
			case 580:
			{
				if(mGLIIdentifierAVP != NULL)
					return mGLIIdentifierAVP->Find(array, avpCode);
				else
					return NULL;
			}
			case 581:
			{
				if(mLineTypeAVP != NULL)
					return mLineTypeAVP->Find(array, avpCode);
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


BOOLEAN WirelineUserLocationInfo::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding WirelineUserLocationInfo")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 579:
			{
				if(mHFCNodeIdentifierAVP != NULL)
				{
					DiameterBaseInterface* inf =  mHFCNodeIdentifierAVP->Find(this->mspByteArray.get(), avpCode);
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
			case 580:
			{
				if(mGLIIdentifierAVP != NULL)
				{
					DiameterBaseInterface* inf =  mGLIIdentifierAVP->Find(this->mspByteArray.get(), avpCode);
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
			case 581:
			{
				if(mLineTypeAVP != NULL)
				{
					DiameterBaseInterface* inf =  mLineTypeAVP->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> WirelineUserLocationInfo::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN WirelineUserLocationInfo::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding WirelineUserLocationInfo")     ;
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
			case 579:
			{
				if(mHFCNodeIdentifierAVP != NULL)
				{
					DiameterBaseInterface* inf =  mHFCNodeIdentifierAVP->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 580:
			{
				if(mGLIIdentifierAVP != NULL)
				{
					DiameterBaseInterface* inf =  mGLIIdentifierAVP->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 581:
			{
				if(mLineTypeAVP != NULL)
				{
					DiameterBaseInterface* inf =  mLineTypeAVP->Find(this->mspByteArray.get(), avpCode);
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


INT32 WirelineUserLocationInfo::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 WirelineUserLocationInfo::getAvpCode()
{
	return mAvpCode;
}
INT32 WirelineUserLocationInfo::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 WirelineUserLocationInfo::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 WirelineUserLocationInfo::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> WirelineUserLocationInfo::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void WirelineUserLocationInfo::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case WirelineUserLocationInfo_HFCNODEIDENTIFIERAVP:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "579" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "HFCNodeIdentifierAVP" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getHFCNodeIdentifierAVP()->Display(tab+1);
			}
				break;
			case WirelineUserLocationInfo_GLIIDENTIFIERAVP:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "580" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "GLIIdentifierAVP" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getGLIIdentifierAVP()->Display(tab+1);
			}
				break;
			case WirelineUserLocationInfo_LINETYPEAVP:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "581" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "LineTypeAVP" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getLineTypeAVP()->Display(tab+1);
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


BOOLEAN WirelineUserLocationInfo::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<3> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case WirelineUserLocationInfo_HFCNODEIDENTIFIERAVP:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 579");
				}
				else
					sprintf(lMissingAvpInfo, "%s,579", lMissingAvpInfo);
			}
				break;
			case WirelineUserLocationInfo_GLIIDENTIFIERAVP:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 580");
				}
				else
					sprintf(lMissingAvpInfo, "%s,580", lMissingAvpInfo);
			}
				break;
			case WirelineUserLocationInfo_LINETYPEAVP:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 581");
				}
				else
					sprintf(lMissingAvpInfo, "%s,581", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
