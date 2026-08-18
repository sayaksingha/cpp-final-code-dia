#include "sd/include/RedirectServer.h"

using namespace SD;
BOOLEAN RedirectServer::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

RedirectServer::RedirectServer()
{
	mRedirectAddressType = NULL;
	mRedirectServerAddress = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<2>(string("11"));
	mMandatoryAvpSetVal.reset();
}

RedirectServer::~RedirectServer()
{
	if(mRedirectAddressType != NULL)
		delete mRedirectAddressType;
	if(mRedirectServerAddress != NULL)
		delete mRedirectServerAddress;
}

RedirectAddressType* RedirectServer::setRedirectAddressType(){
	mMandatoryAvpSetVal [RedirectServer_REDIRECTADDRESSTYPE] = 1;
	if(mRedirectAddressType == NULL)
	{
		mRedirectAddressType = new RedirectAddressType();
		mTagsPresent[RedirectServer_REDIRECTADDRESSTYPE] = 1;
		return mRedirectAddressType;
	}
	return mRedirectAddressType;
}

void RedirectServer::resetRedirectAddressType(){
	mTagsPresent[RedirectServer_REDIRECTADDRESSTYPE] = 0;
	if(mRedirectAddressType != NULL)
	{
		delete mRedirectAddressType; 
		mRedirectAddressType = NULL;
	}
}

OctetString* RedirectServer::setRedirectServerAddress(){
	mMandatoryAvpSetVal [RedirectServer_REDIRECTSERVERADDRESS] = 1;
	if(mRedirectServerAddress == NULL)
	{
		mRedirectServerAddress = new OctetString();
		mTagsPresent[RedirectServer_REDIRECTSERVERADDRESS] = 1;
		return mRedirectServerAddress;
	}
	return mRedirectServerAddress;
}

void RedirectServer::resetRedirectServerAddress(){
	mTagsPresent[RedirectServer_REDIRECTSERVERADDRESS] = 0;
	if(mRedirectServerAddress != NULL)
	{
		delete mRedirectServerAddress; 
		mRedirectServerAddress = NULL;
	}
}

RedirectAddressType* RedirectServer::getRedirectAddressType(){
	if(NULL == mRedirectAddressType) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectAddressType is Null");
		throw lTssDiaMsgException;
	}
	if(!mRedirectAddressType->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRedirectAddressType->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectAddressType is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRedirectAddressType->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRedirectAddressType->Decode(mspByteArray.get(), mRedirectAddressType->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectAddressType")     ;
			throw lTssDiaMsgException;
		}
		mRedirectAddressType->mAvpDecodedFlag = true;
	}
	return mRedirectAddressType;
}

OctetString* RedirectServer::getRedirectServerAddress(){
	if(NULL == mRedirectServerAddress) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectServerAddress is Null");
		throw lTssDiaMsgException;
	}
	if(!mRedirectServerAddress->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRedirectServerAddress->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectServerAddress is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRedirectServerAddress->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRedirectServerAddress->Decode(mspByteArray.get(), mRedirectServerAddress->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectServerAddress")     ;
			throw lTssDiaMsgException;
		}
		mRedirectServerAddress->mAvpDecodedFlag = true;
	}
	return mRedirectServerAddress;
}



int RedirectServer::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case RedirectServer_REDIRECTADDRESSTYPE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(433);
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
					if(!mRedirectAddressType->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRedirectAddressType->getAvpOffsetLen().first], mRedirectAddressType->getAvpOffsetLen().second);
						array->offset += mRedirectAddressType->getAvpOffsetLen().second;
						array->size += mRedirectAddressType->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RedirectAddressType");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mRedirectAddressType->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RedirectAddressType");
						throw lTssDiaMsgException;
					}
				}
				break;
			case RedirectServer_REDIRECTSERVERADDRESS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(435);
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
					if(!mRedirectServerAddress->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRedirectServerAddress->getAvpOffsetLen().first], mRedirectServerAddress->getAvpOffsetLen().second);
						array->offset += mRedirectServerAddress->getAvpOffsetLen().second;
						array->size += mRedirectServerAddress->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mRedirectServerAddress->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mRedirectServerAddress->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RedirectServerAddress");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mRedirectServerAddress->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mRedirectServerAddress->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RedirectServerAddress");
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


int RedirectServer::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 433:
				{
						mMandatoryAvpSetVal [RedirectServer_REDIRECTADDRESSTYPE] = 1;
					if( NULL == this->setRedirectAddressType())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectAddressType");
						throw lTssDiaMsgException;
					}
					mRedirectAddressType->setAvpCode(433);
					mRedirectAddressType->setAvpVendorId(lVenderId);
					mRedirectAddressType->SetDataType((DiameterDataType)7);
					mRedirectAddressType->mspByteArray = mspByteArray;
					mRedirectAddressType->mAvpDecodedFlag = false;
					mRedirectAddressType->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 435:
				{
						mMandatoryAvpSetVal [RedirectServer_REDIRECTSERVERADDRESS] = 1;
					if( NULL == this->setRedirectServerAddress())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectServerAddress");
						throw lTssDiaMsgException;
					}
					mRedirectServerAddress->setAvpCode(435);
					mRedirectServerAddress->setAvpVendorId(lVenderId);
					mRedirectServerAddress->SetDataType((DiameterDataType)5);
					mRedirectServerAddress->mspByteArray = mspByteArray;
					mRedirectServerAddress->mAvpDecodedFlag = false;
					mRedirectServerAddress->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* RedirectServer::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectServer")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 433:
			{
				if(mRedirectAddressType != NULL)
					return mRedirectAddressType->Find(array, avpCode);
				else
					return NULL;
			}
			case 435:
			{
				if(mRedirectServerAddress != NULL)
					return mRedirectServerAddress->Find(array, avpCode);
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


BOOLEAN RedirectServer::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectServer")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 433:
			{
				if(mRedirectAddressType != NULL)
				{
					DiameterBaseInterface* inf =  mRedirectAddressType->Find(this->mspByteArray.get(), avpCode);
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
			case 435:
			{
				if(mRedirectServerAddress != NULL)
				{
					DiameterBaseInterface* inf =  mRedirectServerAddress->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> RedirectServer::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN RedirectServer::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectServer")     ;
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
			case 433:
			{
				if(mRedirectAddressType != NULL)
				{
					DiameterBaseInterface* inf =  mRedirectAddressType->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 435:
			{
				if(mRedirectServerAddress != NULL)
				{
					DiameterBaseInterface* inf =  mRedirectServerAddress->Find(this->mspByteArray.get(), avpCode);
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


INT32 RedirectServer::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 RedirectServer::getAvpCode()
{
	return mAvpCode;
}
INT32 RedirectServer::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 RedirectServer::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 RedirectServer::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> RedirectServer::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void RedirectServer::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case RedirectServer_REDIRECTADDRESSTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "433" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RedirectAddressType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getRedirectAddressType()->Display(tab+1);
			}
				break;
			case RedirectServer_REDIRECTSERVERADDRESS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "435" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RedirectServerAddress" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getRedirectServerAddress()->Display(tab+1);
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


BOOLEAN RedirectServer::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<2> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case RedirectServer_REDIRECTADDRESSTYPE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 433");
				}
				else
					sprintf(lMissingAvpInfo, "%s,433", lMissingAvpInfo);
			}
				break;
			case RedirectServer_REDIRECTSERVERADDRESS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 435");
				}
				else
					sprintf(lMissingAvpInfo, "%s,435", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
