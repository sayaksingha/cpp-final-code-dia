#include "sh/include/CallReferenceInfo.h"

using namespace SH;
BOOLEAN CallReferenceInfo::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

CallReferenceInfo::CallReferenceInfo()
{
	mCallReferenceNumber = NULL;
	mASNumber = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<2>(string("00"));
	mMandatoryAvpSetVal.reset();
}

CallReferenceInfo::~CallReferenceInfo()
{
	if(mCallReferenceNumber != NULL)
		delete mCallReferenceNumber;
	if(mASNumber != NULL)
		delete mASNumber;
}

OctetString* CallReferenceInfo::setCallReferenceNumber(){
	if(mCallReferenceNumber == NULL)
	{
		mCallReferenceNumber = new OctetString();
		mTagsPresent[CallReferenceInfo_CALLREFERENCENUMBER] = 1;
		return mCallReferenceNumber;
	}
	return mCallReferenceNumber;
}

void CallReferenceInfo::resetCallReferenceNumber(){
	mTagsPresent[CallReferenceInfo_CALLREFERENCENUMBER] = 0;
	if(mCallReferenceNumber != NULL)
	{
		delete mCallReferenceNumber; 
		mCallReferenceNumber = NULL;
	}
}

OctetString* CallReferenceInfo::setASNumber(){
	if(mASNumber == NULL)
	{
		mASNumber = new OctetString();
		mTagsPresent[CallReferenceInfo_ASNUMBER] = 1;
		return mASNumber;
	}
	return mASNumber;
}

void CallReferenceInfo::resetASNumber(){
	mTagsPresent[CallReferenceInfo_ASNUMBER] = 0;
	if(mASNumber != NULL)
	{
		delete mASNumber; 
		mASNumber = NULL;
	}
}

OctetString* CallReferenceInfo::getCallReferenceNumber(){
	if(NULL == mCallReferenceNumber) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CallReferenceNumber is Null");
		throw lTssDiaMsgException;
	}
	if(!mCallReferenceNumber->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCallReferenceNumber->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CallReferenceNumber is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCallReferenceNumber->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCallReferenceNumber->Decode(mspByteArray.get(), mCallReferenceNumber->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CallReferenceNumber")     ;
			throw lTssDiaMsgException;
		}
		mCallReferenceNumber->mAvpDecodedFlag = true;
	}
	return mCallReferenceNumber;
}

OctetString* CallReferenceInfo::getASNumber(){
	if(NULL == mASNumber) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ASNumber is Null");
		throw lTssDiaMsgException;
	}
	if(!mASNumber->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mASNumber->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ASNumber is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mASNumber->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mASNumber->Decode(mspByteArray.get(), mASNumber->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ASNumber")     ;
			throw lTssDiaMsgException;
		}
		mASNumber->mAvpDecodedFlag = true;
	}
	return mASNumber;
}



int CallReferenceInfo::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case CallReferenceInfo_CALLREFERENCENUMBER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(721);
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
					if(!mCallReferenceNumber->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCallReferenceNumber->getAvpOffsetLen().first], mCallReferenceNumber->getAvpOffsetLen().second);
						array->offset += mCallReferenceNumber->getAvpOffsetLen().second;
						array->size += mCallReferenceNumber->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mCallReferenceNumber->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mCallReferenceNumber->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CallReferenceNumber");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mCallReferenceNumber->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mCallReferenceNumber->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CallReferenceNumber");
						throw lTssDiaMsgException;
					}
				}
				break;
			case CallReferenceInfo_ASNUMBER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(722);
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
					if(!mASNumber->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mASNumber->getAvpOffsetLen().first], mASNumber->getAvpOffsetLen().second);
						array->offset += mASNumber->getAvpOffsetLen().second;
						array->size += mASNumber->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mASNumber->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mASNumber->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ASNumber");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mASNumber->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mASNumber->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ASNumber");
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


int CallReferenceInfo::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 721:
				{
					if( NULL == this->setCallReferenceNumber())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CallReferenceNumber");
						throw lTssDiaMsgException;
					}
					mCallReferenceNumber->setAvpCode(721);
					mCallReferenceNumber->setAvpVendorId(lVenderId);
					mCallReferenceNumber->SetDataType((DiameterDataType)5);
					mCallReferenceNumber->mspByteArray = mspByteArray;
					mCallReferenceNumber->mAvpDecodedFlag = false;
					mCallReferenceNumber->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 722:
				{
					if( NULL == this->setASNumber())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ASNumber");
						throw lTssDiaMsgException;
					}
					mASNumber->setAvpCode(722);
					mASNumber->setAvpVendorId(lVenderId);
					mASNumber->SetDataType((DiameterDataType)5);
					mASNumber->mspByteArray = mspByteArray;
					mASNumber->mAvpDecodedFlag = false;
					mASNumber->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* CallReferenceInfo::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CallReferenceInfo")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 721:
			{
				if(mCallReferenceNumber != NULL)
					return mCallReferenceNumber->Find(array, avpCode);
				else
					return NULL;
			}
			case 722:
			{
				if(mASNumber != NULL)
					return mASNumber->Find(array, avpCode);
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


BOOLEAN CallReferenceInfo::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CallReferenceInfo")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 721:
			{
				if(mCallReferenceNumber != NULL)
				{
					DiameterBaseInterface* inf =  mCallReferenceNumber->Find(this->mspByteArray.get(), avpCode);
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
			case 722:
			{
				if(mASNumber != NULL)
				{
					DiameterBaseInterface* inf =  mASNumber->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> CallReferenceInfo::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN CallReferenceInfo::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CallReferenceInfo")     ;
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
			case 721:
			{
				if(mCallReferenceNumber != NULL)
				{
					DiameterBaseInterface* inf =  mCallReferenceNumber->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 722:
			{
				if(mASNumber != NULL)
				{
					DiameterBaseInterface* inf =  mASNumber->Find(this->mspByteArray.get(), avpCode);
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


INT32 CallReferenceInfo::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 CallReferenceInfo::getAvpCode()
{
	return mAvpCode;
}
INT32 CallReferenceInfo::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 CallReferenceInfo::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 CallReferenceInfo::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> CallReferenceInfo::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void CallReferenceInfo::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case CallReferenceInfo_CALLREFERENCENUMBER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "721" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CallReferenceNumber" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getCallReferenceNumber()->Display(tab+1);
			}
				break;
			case CallReferenceInfo_ASNUMBER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "722" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ASNumber" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getASNumber()->Display(tab+1);
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


BOOLEAN CallReferenceInfo::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<2> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case CallReferenceInfo_CALLREFERENCENUMBER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 721");
				}
				else
					sprintf(lMissingAvpInfo, "%s,721", lMissingAvpInfo);
			}
				break;
			case CallReferenceInfo_ASNUMBER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 722");
				}
				else
					sprintf(lMissingAvpInfo, "%s,722", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
