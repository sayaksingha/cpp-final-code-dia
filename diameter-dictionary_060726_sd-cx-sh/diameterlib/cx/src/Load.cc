#include "cx/include/Load.h"

using namespace CX;
BOOLEAN Load::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

Load::Load()
{
	mLoadType = NULL;
	mLoadValue = NULL;
	mSourceID = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<3>(string("000"));
	mMandatoryAvpSetVal.reset();
}

Load::~Load()
{
	if(mLoadType != NULL)
		delete mLoadType;
	if(mLoadValue != NULL)
		delete mLoadValue;
	if(mSourceID != NULL)
		delete mSourceID;
}

LoadType* Load::setLoadType(){
	if(mLoadType == NULL)
	{
		mLoadType = new LoadType();
		mTagsPresent[Load_LOADTYPE] = 1;
		return mLoadType;
	}
	return mLoadType;
}

void Load::resetLoadType(){
	mTagsPresent[Load_LOADTYPE] = 0;
	if(mLoadType != NULL)
	{
		delete mLoadType; 
		mLoadType = NULL;
	}
}

Unsigned64* Load::setLoadValue(){
	if(mLoadValue == NULL)
	{
		mLoadValue = new Unsigned64();
		mTagsPresent[Load_LOADVALUE] = 1;
		return mLoadValue;
	}
	return mLoadValue;
}

void Load::resetLoadValue(){
	mTagsPresent[Load_LOADVALUE] = 0;
	if(mLoadValue != NULL)
	{
		delete mLoadValue; 
		mLoadValue = NULL;
	}
}

OctetString* Load::setSourceID(){
	if(mSourceID == NULL)
	{
		mSourceID = new OctetString();
		mTagsPresent[Load_SOURCEID] = 1;
		return mSourceID;
	}
	return mSourceID;
}

void Load::resetSourceID(){
	mTagsPresent[Load_SOURCEID] = 0;
	if(mSourceID != NULL)
	{
		delete mSourceID; 
		mSourceID = NULL;
	}
}

LoadType* Load::getLoadType(){
	if(NULL == mLoadType) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "LoadType is Null");
		throw lTssDiaMsgException;
	}
	if(!mLoadType->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mLoadType->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "LoadType is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mLoadType->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mLoadType->Decode(mspByteArray.get(), mLoadType->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding LoadType")     ;
			throw lTssDiaMsgException;
		}
		mLoadType->mAvpDecodedFlag = true;
	}
	return mLoadType;
}

Unsigned64* Load::getLoadValue(){
	if(NULL == mLoadValue) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "LoadValue is Null");
		throw lTssDiaMsgException;
	}
	if(!mLoadValue->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mLoadValue->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "LoadValue is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mLoadValue->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mLoadValue->Decode(mspByteArray.get(), mLoadValue->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding LoadValue")     ;
			throw lTssDiaMsgException;
		}
		mLoadValue->mAvpDecodedFlag = true;
	}
	return mLoadValue;
}

OctetString* Load::getSourceID(){
	if(NULL == mSourceID) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SourceID is Null");
		throw lTssDiaMsgException;
	}
	if(!mSourceID->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSourceID->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SourceID is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSourceID->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSourceID->Decode(mspByteArray.get(), mSourceID->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SourceID")     ;
			throw lTssDiaMsgException;
		}
		mSourceID->mAvpDecodedFlag = true;
	}
	return mSourceID;
}



int Load::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case Load_LOADTYPE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(651);
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
					if(!mLoadType->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mLoadType->getAvpOffsetLen().first], mLoadType->getAvpOffsetLen().second);
						array->offset += mLoadType->getAvpOffsetLen().second;
						array->size += mLoadType->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding LoadType");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mLoadType->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding LoadType");
						throw lTssDiaMsgException;
					}
				}
				break;
			case Load_LOADVALUE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(652);
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
					if(!mLoadValue->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mLoadValue->getAvpOffsetLen().first], mLoadValue->getAvpOffsetLen().second);
						array->offset += mLoadValue->getAvpOffsetLen().second;
						array->size += mLoadValue->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding LoadValue");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mLoadValue->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding LoadValue");
						throw lTssDiaMsgException;
					}
				}
				break;
			case Load_SOURCEID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(649);
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
					if(!mSourceID->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSourceID->getAvpOffsetLen().first], mSourceID->getAvpOffsetLen().second);
						array->offset += mSourceID->getAvpOffsetLen().second;
						array->size += mSourceID->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mSourceID->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mSourceID->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SourceID");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mSourceID->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mSourceID->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SourceID");
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


int Load::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 651:
				{
					if( NULL == this->setLoadType())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding LoadType");
						throw lTssDiaMsgException;
					}
					mLoadType->setAvpCode(651);
					mLoadType->setAvpVendorId(lVenderId);
					mLoadType->SetDataType((DiameterDataType)7);
					mLoadType->mspByteArray = mspByteArray;
					mLoadType->mAvpDecodedFlag = false;
					mLoadType->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 652:
				{
					if( NULL == this->setLoadValue())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding LoadValue");
						throw lTssDiaMsgException;
					}
					mLoadValue->setAvpCode(652);
					mLoadValue->setAvpVendorId(lVenderId);
					mLoadValue->SetDataType((DiameterDataType)4);
					mLoadValue->mspByteArray = mspByteArray;
					mLoadValue->mAvpDecodedFlag = false;
					mLoadValue->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 649:
				{
					if( NULL == this->setSourceID())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SourceID");
						throw lTssDiaMsgException;
					}
					mSourceID->setAvpCode(649);
					mSourceID->setAvpVendorId(lVenderId);
					mSourceID->SetDataType((DiameterDataType)5);
					mSourceID->mspByteArray = mspByteArray;
					mSourceID->mAvpDecodedFlag = false;
					mSourceID->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* Load::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Load")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 651:
			{
				if(mLoadType != NULL)
					return mLoadType->Find(array, avpCode);
				else
					return NULL;
			}
			case 652:
			{
				if(mLoadValue != NULL)
					return mLoadValue->Find(array, avpCode);
				else
					return NULL;
			}
			case 649:
			{
				if(mSourceID != NULL)
					return mSourceID->Find(array, avpCode);
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


BOOLEAN Load::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Load")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 651:
			{
				if(mLoadType != NULL)
				{
					DiameterBaseInterface* inf =  mLoadType->Find(this->mspByteArray.get(), avpCode);
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
			case 652:
			{
				if(mLoadValue != NULL)
				{
					DiameterBaseInterface* inf =  mLoadValue->Find(this->mspByteArray.get(), avpCode);
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
			case 649:
			{
				if(mSourceID != NULL)
				{
					DiameterBaseInterface* inf =  mSourceID->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> Load::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN Load::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Load")     ;
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
			case 651:
			{
				if(mLoadType != NULL)
				{
					DiameterBaseInterface* inf =  mLoadType->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 652:
			{
				if(mLoadValue != NULL)
				{
					DiameterBaseInterface* inf =  mLoadValue->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 649:
			{
				if(mSourceID != NULL)
				{
					DiameterBaseInterface* inf =  mSourceID->Find(this->mspByteArray.get(), avpCode);
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


INT32 Load::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 Load::getAvpCode()
{
	return mAvpCode;
}
INT32 Load::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 Load::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 Load::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> Load::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void Load::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case Load_LOADTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "651" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "LoadType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getLoadType()->Display(tab+1);
			}
				break;
			case Load_LOADVALUE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "652" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "LoadValue" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getLoadValue()->Display(tab+1);
			}
				break;
			case Load_SOURCEID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "649" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SourceID" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getSourceID()->Display(tab+1);
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


BOOLEAN Load::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<3> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case Load_LOADTYPE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 651");
				}
				else
					sprintf(lMissingAvpInfo, "%s,651", lMissingAvpInfo);
			}
				break;
			case Load_LOADVALUE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 652");
				}
				else
					sprintf(lMissingAvpInfo, "%s,652", lMissingAvpInfo);
			}
				break;
			case Load_SOURCEID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 649");
				}
				else
					sprintf(lMissingAvpInfo, "%s,649", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
