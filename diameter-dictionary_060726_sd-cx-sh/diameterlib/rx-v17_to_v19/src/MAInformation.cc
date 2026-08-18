#include "rx/include/MAInformation.h"

using namespace RX;
BOOLEAN MAInformation::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

MAInformation::MAInformation()
{
	mIPCANType = NULL;
	mRATType = NULL;
	mMAInformationAction = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<3>(string("001"));
	mMandatoryAvpSetVal.reset();
}

MAInformation::~MAInformation()
{
	if(mIPCANType != NULL)
		delete mIPCANType;
	if(mRATType != NULL)
		delete mRATType;
	if(mMAInformationAction != NULL)
		delete mMAInformationAction;
}

IPCANType* MAInformation::setIPCANType(){
	mMandatoryAvpSetVal [MAInformation_IPCANTYPE] = 1;
	if(mIPCANType == NULL)
	{
		mIPCANType = new IPCANType();
		mTagsPresent[MAInformation_IPCANTYPE] = 1;
		return mIPCANType;
	}
	return mIPCANType;
}

void MAInformation::resetIPCANType(){
	mTagsPresent[MAInformation_IPCANTYPE] = 0;
	if(mIPCANType != NULL)
	{
		delete mIPCANType; 
		mIPCANType = NULL;
	}
}

Unsigned32* MAInformation::setRATType(){
	if(mRATType == NULL)
	{
		mRATType = new Unsigned32();
		mTagsPresent[MAInformation_RATTYPE] = 1;
		return mRATType;
	}
	return mRATType;
}

void MAInformation::resetRATType(){
	mTagsPresent[MAInformation_RATTYPE] = 0;
	if(mRATType != NULL)
	{
		delete mRATType; 
		mRATType = NULL;
	}
}

Unsigned32* MAInformation::setMAInformationAction(){
	if(mMAInformationAction == NULL)
	{
		mMAInformationAction = new Unsigned32();
		mTagsPresent[MAInformation_MAINFORMATIONACTION] = 1;
		return mMAInformationAction;
	}
	return mMAInformationAction;
}

void MAInformation::resetMAInformationAction(){
	mTagsPresent[MAInformation_MAINFORMATIONACTION] = 0;
	if(mMAInformationAction != NULL)
	{
		delete mMAInformationAction; 
		mMAInformationAction = NULL;
	}
}

IPCANType* MAInformation::getIPCANType(){
	if(NULL == mIPCANType) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "IPCANType is Null");
		throw lTssDiaMsgException;
	}
	if(!mIPCANType->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mIPCANType->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "IPCANType is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mIPCANType->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mIPCANType->Decode(mspByteArray.get(), mIPCANType->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding IPCANType")     ;
			throw lTssDiaMsgException;
		}
		mIPCANType->mAvpDecodedFlag = true;
	}
	return mIPCANType;
}

Unsigned32* MAInformation::getRATType(){
	if(NULL == mRATType) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RATType is Null");
		throw lTssDiaMsgException;
	}
	if(!mRATType->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRATType->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RATType is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRATType->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRATType->Decode(mspByteArray.get(), mRATType->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RATType")     ;
			throw lTssDiaMsgException;
		}
		mRATType->mAvpDecodedFlag = true;
	}
	return mRATType;
}

Unsigned32* MAInformation::getMAInformationAction(){
	if(NULL == mMAInformationAction) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MAInformationAction is Null");
		throw lTssDiaMsgException;
	}
	if(!mMAInformationAction->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMAInformationAction->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MAInformationAction is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMAInformationAction->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMAInformationAction->Decode(mspByteArray.get(), mMAInformationAction->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MAInformationAction")     ;
			throw lTssDiaMsgException;
		}
		mMAInformationAction->mAvpDecodedFlag = true;
	}
	return mMAInformationAction;
}



int MAInformation::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case MAInformation_IPCANTYPE:
			{
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
					if(!mIPCANType->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mIPCANType->getAvpOffsetLen().first], mIPCANType->getAvpOffsetLen().second);
						array->offset += mIPCANType->getAvpOffsetLen().second;
						array->size += mIPCANType->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding IPCANType");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mIPCANType->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding IPCANType");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MAInformation_RATTYPE:
			{
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
					if(!mRATType->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRATType->getAvpOffsetLen().first], mRATType->getAvpOffsetLen().second);
						array->offset += mRATType->getAvpOffsetLen().second;
						array->size += mRATType->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RATType");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mRATType->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RATType");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MAInformation_MAINFORMATIONACTION:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(571);
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
					if(!mMAInformationAction->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMAInformationAction->getAvpOffsetLen().first], mMAInformationAction->getAvpOffsetLen().second);
						array->offset += mMAInformationAction->getAvpOffsetLen().second;
						array->size += mMAInformationAction->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MAInformationAction");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mMAInformationAction->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MAInformationAction");
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


int MAInformation::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 1027:
				{
						mMandatoryAvpSetVal [MAInformation_IPCANTYPE] = 1;
					if( NULL == this->setIPCANType())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding IPCANType");
						throw lTssDiaMsgException;
					}
					mIPCANType->setAvpCode(1027);
					mIPCANType->setAvpVendorId(lVenderId);
					mIPCANType->SetDataType((DiameterDataType)7);
					mIPCANType->mspByteArray = mspByteArray;
					mIPCANType->mAvpDecodedFlag = false;
					mIPCANType->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1032:
				{
					if( NULL == this->setRATType())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RATType");
						throw lTssDiaMsgException;
					}
					mRATType->setAvpCode(1032);
					mRATType->setAvpVendorId(lVenderId);
					mRATType->SetDataType((DiameterDataType)3);
					mRATType->mspByteArray = mspByteArray;
					mRATType->mAvpDecodedFlag = false;
					mRATType->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 571:
				{
					if( NULL == this->setMAInformationAction())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MAInformationAction");
						throw lTssDiaMsgException;
					}
					mMAInformationAction->setAvpCode(571);
					mMAInformationAction->setAvpVendorId(lVenderId);
					mMAInformationAction->SetDataType((DiameterDataType)3);
					mMAInformationAction->mspByteArray = mspByteArray;
					mMAInformationAction->mAvpDecodedFlag = false;
					mMAInformationAction->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* MAInformation::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MAInformation")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1027:
			{
				if(mIPCANType != NULL)
					return mIPCANType->Find(array, avpCode);
				else
					return NULL;
			}
			case 1032:
			{
				if(mRATType != NULL)
					return mRATType->Find(array, avpCode);
				else
					return NULL;
			}
			case 571:
			{
				if(mMAInformationAction != NULL)
					return mMAInformationAction->Find(array, avpCode);
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


BOOLEAN MAInformation::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MAInformation")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1027:
			{
				if(mIPCANType != NULL)
				{
					DiameterBaseInterface* inf =  mIPCANType->Find(this->mspByteArray.get(), avpCode);
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
			case 1032:
			{
				if(mRATType != NULL)
				{
					DiameterBaseInterface* inf =  mRATType->Find(this->mspByteArray.get(), avpCode);
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
			case 571:
			{
				if(mMAInformationAction != NULL)
				{
					DiameterBaseInterface* inf =  mMAInformationAction->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> MAInformation::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN MAInformation::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MAInformation")     ;
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
			case 1027:
			{
				if(mIPCANType != NULL)
				{
					DiameterBaseInterface* inf =  mIPCANType->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1032:
			{
				if(mRATType != NULL)
				{
					DiameterBaseInterface* inf =  mRATType->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 571:
			{
				if(mMAInformationAction != NULL)
				{
					DiameterBaseInterface* inf =  mMAInformationAction->Find(this->mspByteArray.get(), avpCode);
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


INT32 MAInformation::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 MAInformation::getAvpCode()
{
	return mAvpCode;
}
INT32 MAInformation::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 MAInformation::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 MAInformation::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> MAInformation::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void MAInformation::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case MAInformation_IPCANTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1027" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "IPCANType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getIPCANType()->Display(tab+1);
			}
				break;
			case MAInformation_RATTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1032" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RATType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getRATType()->Display(tab+1);
			}
				break;
			case MAInformation_MAINFORMATIONACTION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "571" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MAInformationAction" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getMAInformationAction()->Display(tab+1);
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


BOOLEAN MAInformation::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<3> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case MAInformation_IPCANTYPE:
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
			case MAInformation_RATTYPE:
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
			case MAInformation_MAINFORMATIONACTION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 571");
				}
				else
					sprintf(lMissingAvpInfo, "%s,571", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
