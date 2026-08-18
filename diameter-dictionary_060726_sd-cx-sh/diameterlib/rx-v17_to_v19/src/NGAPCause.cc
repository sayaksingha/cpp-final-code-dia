#include "rx/include/NGAPCause.h"

using namespace RX;
BOOLEAN NGAPCause::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

NGAPCause::NGAPCause()
{
	mNGAPGroup = NULL;
	mNGAPValue = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<2>(string("00"));
	mMandatoryAvpSetVal.reset();
}

NGAPCause::~NGAPCause()
{
	if(mNGAPGroup != NULL)
		delete mNGAPGroup;
	if(mNGAPValue != NULL)
		delete mNGAPValue;
}

Unsigned32* NGAPCause::setNGAPGroup(){
	if(mNGAPGroup == NULL)
	{
		mNGAPGroup = new Unsigned32();
		mTagsPresent[NGAPCause_NGAPGROUP] = 1;
		return mNGAPGroup;
	}
	return mNGAPGroup;
}

void NGAPCause::resetNGAPGroup(){
	mTagsPresent[NGAPCause_NGAPGROUP] = 0;
	if(mNGAPGroup != NULL)
	{
		delete mNGAPGroup; 
		mNGAPGroup = NULL;
	}
}

Unsigned32* NGAPCause::setNGAPValue(){
	if(mNGAPValue == NULL)
	{
		mNGAPValue = new Unsigned32();
		mTagsPresent[NGAPCause_NGAPVALUE] = 1;
		return mNGAPValue;
	}
	return mNGAPValue;
}

void NGAPCause::resetNGAPValue(){
	mTagsPresent[NGAPCause_NGAPVALUE] = 0;
	if(mNGAPValue != NULL)
	{
		delete mNGAPValue; 
		mNGAPValue = NULL;
	}
}

Unsigned32* NGAPCause::getNGAPGroup(){
	if(NULL == mNGAPGroup) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "NGAPGroup is Null");
		throw lTssDiaMsgException;
	}
	if(!mNGAPGroup->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mNGAPGroup->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "NGAPGroup is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mNGAPGroup->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mNGAPGroup->Decode(mspByteArray.get(), mNGAPGroup->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding NGAPGroup")     ;
			throw lTssDiaMsgException;
		}
		mNGAPGroup->mAvpDecodedFlag = true;
	}
	return mNGAPGroup;
}

Unsigned32* NGAPCause::getNGAPValue(){
	if(NULL == mNGAPValue) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "NGAPValue is Null");
		throw lTssDiaMsgException;
	}
	if(!mNGAPValue->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mNGAPValue->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "NGAPValue is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mNGAPValue->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mNGAPValue->Decode(mspByteArray.get(), mNGAPValue->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding NGAPValue")     ;
			throw lTssDiaMsgException;
		}
		mNGAPValue->mAvpDecodedFlag = true;
	}
	return mNGAPValue;
}



int NGAPCause::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case NGAPCause_NGAPGROUP:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(576);
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
					if(!mNGAPGroup->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mNGAPGroup->getAvpOffsetLen().first], mNGAPGroup->getAvpOffsetLen().second);
						array->offset += mNGAPGroup->getAvpOffsetLen().second;
						array->size += mNGAPGroup->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding NGAPGroup");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mNGAPGroup->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding NGAPGroup");
						throw lTssDiaMsgException;
					}
				}
				break;
			case NGAPCause_NGAPVALUE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(577);
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
					if(!mNGAPValue->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mNGAPValue->getAvpOffsetLen().first], mNGAPValue->getAvpOffsetLen().second);
						array->offset += mNGAPValue->getAvpOffsetLen().second;
						array->size += mNGAPValue->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding NGAPValue");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mNGAPValue->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding NGAPValue");
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


int NGAPCause::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 576:
				{
					if( NULL == this->setNGAPGroup())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding NGAPGroup");
						throw lTssDiaMsgException;
					}
					mNGAPGroup->setAvpCode(576);
					mNGAPGroup->setAvpVendorId(lVenderId);
					mNGAPGroup->SetDataType((DiameterDataType)3);
					mNGAPGroup->mspByteArray = mspByteArray;
					mNGAPGroup->mAvpDecodedFlag = false;
					mNGAPGroup->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 577:
				{
					if( NULL == this->setNGAPValue())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding NGAPValue");
						throw lTssDiaMsgException;
					}
					mNGAPValue->setAvpCode(577);
					mNGAPValue->setAvpVendorId(lVenderId);
					mNGAPValue->SetDataType((DiameterDataType)3);
					mNGAPValue->mspByteArray = mspByteArray;
					mNGAPValue->mAvpDecodedFlag = false;
					mNGAPValue->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* NGAPCause::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding NGAPCause")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 576:
			{
				if(mNGAPGroup != NULL)
					return mNGAPGroup->Find(array, avpCode);
				else
					return NULL;
			}
			case 577:
			{
				if(mNGAPValue != NULL)
					return mNGAPValue->Find(array, avpCode);
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


BOOLEAN NGAPCause::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding NGAPCause")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 576:
			{
				if(mNGAPGroup != NULL)
				{
					DiameterBaseInterface* inf =  mNGAPGroup->Find(this->mspByteArray.get(), avpCode);
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
			case 577:
			{
				if(mNGAPValue != NULL)
				{
					DiameterBaseInterface* inf =  mNGAPValue->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> NGAPCause::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN NGAPCause::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding NGAPCause")     ;
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
			case 576:
			{
				if(mNGAPGroup != NULL)
				{
					DiameterBaseInterface* inf =  mNGAPGroup->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 577:
			{
				if(mNGAPValue != NULL)
				{
					DiameterBaseInterface* inf =  mNGAPValue->Find(this->mspByteArray.get(), avpCode);
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


INT32 NGAPCause::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 NGAPCause::getAvpCode()
{
	return mAvpCode;
}
INT32 NGAPCause::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 NGAPCause::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 NGAPCause::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> NGAPCause::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void NGAPCause::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case NGAPCause_NGAPGROUP:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "576" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "NGAPGroup" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getNGAPGroup()->Display(tab+1);
			}
				break;
			case NGAPCause_NGAPVALUE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "577" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "NGAPValue" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getNGAPValue()->Display(tab+1);
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


BOOLEAN NGAPCause::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<2> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case NGAPCause_NGAPGROUP:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 576");
				}
				else
					sprintf(lMissingAvpInfo, "%s,576", lMissingAvpInfo);
			}
				break;
			case NGAPCause_NGAPVALUE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 577");
				}
				else
					sprintf(lMissingAvpInfo, "%s,577", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
