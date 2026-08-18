#include "sd/include/ADCRuleRemove.h"

using namespace SD;
BOOLEAN ADCRuleRemove::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

ADCRuleRemove::ADCRuleRemove()
{
	mADCRuleNameList = NULL;
	mADCRuleBaseNameList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<2>(string("11"));
	mMandatoryAvpSetVal.reset();
}

ADCRuleRemove::~ADCRuleRemove()
{
	if(mADCRuleNameList != NULL){
		mADCRuleNameIterator = mADCRuleNameList->begin();
		while(mADCRuleNameIterator != mADCRuleNameList->end()){
			delete (*mADCRuleNameIterator);
			mADCRuleNameIterator++;
		}
		delete mADCRuleNameList;
	}
	if(mADCRuleBaseNameList != NULL){
		mADCRuleBaseNameIterator = mADCRuleBaseNameList->begin();
		while(mADCRuleBaseNameIterator != mADCRuleBaseNameList->end()){
			delete (*mADCRuleBaseNameIterator);
			mADCRuleBaseNameIterator++;
		}
		delete mADCRuleBaseNameList;
	}
}

list<OctetString*>* ADCRuleRemove::getADCRuleNameList()
{
	if(mADCRuleNameList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ADCRuleName is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mADCRuleNameList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ADCRuleName is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleName")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mADCRuleNameList;
}

list<OctetString*>* ADCRuleRemove::setADCRuleNameList() {
	mTagsPresent[ADCRuleRemove_ADCRULENAME] = 1;
	if(mADCRuleNameList == NULL)
		mADCRuleNameList = new list<OctetString*>;
	mMandatoryAvpSetVal [ADCRuleRemove_ADCRULENAME] = 1;
	mADCRuleNameList->clear();
	return mADCRuleNameList;
}

void ADCRuleRemove::resetADCRuleNameList(){
	mTagsPresent[ADCRuleRemove_ADCRULENAME] = 0;
	if(mADCRuleNameList != NULL)
		delete mADCRuleNameList;
}

list<OctetString*>* ADCRuleRemove::getADCRuleBaseNameList()
{
	if(mADCRuleBaseNameList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ADCRuleBaseName is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mADCRuleBaseNameList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ADCRuleBaseName is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleBaseName")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mADCRuleBaseNameList;
}

list<OctetString*>* ADCRuleRemove::setADCRuleBaseNameList() {
	mTagsPresent[ADCRuleRemove_ADCRULEBASENAME] = 1;
	if(mADCRuleBaseNameList == NULL)
		mADCRuleBaseNameList = new list<OctetString*>;
	mMandatoryAvpSetVal [ADCRuleRemove_ADCRULEBASENAME] = 1;
	mADCRuleBaseNameList->clear();
	return mADCRuleBaseNameList;
}

void ADCRuleRemove::resetADCRuleBaseNameList(){
	mTagsPresent[ADCRuleRemove_ADCRULEBASENAME] = 0;
	if(mADCRuleBaseNameList != NULL)
		delete mADCRuleBaseNameList;
}



int ADCRuleRemove::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case ADCRuleRemove_ADCRULENAME:
			{
					if( mADCRuleNameList->size() <= 0) {
						break;
					}

					mADCRuleNameIterator = this->getADCRuleNameList()->begin();
					while(mADCRuleNameIterator != mADCRuleNameList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(1096);
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
					if(!(*mADCRuleNameIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mADCRuleNameIterator)->getAvpOffsetLen().first], (*mADCRuleNameIterator)->getAvpOffsetLen().second);
						array->offset += (*mADCRuleNameIterator)->getAvpOffsetLen().second;
						array->size += (*mADCRuleNameIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mADCRuleNameIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mADCRuleNameIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ADCRuleName");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mADCRuleNameIterator++;
						continue;
					}
						if(((*mADCRuleNameIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mADCRuleNameIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ADCRuleName");
							throw lTssDiaMsgException;
						}
						mADCRuleNameIterator++;
				}
				}
				break;
			case ADCRuleRemove_ADCRULEBASENAME:
			{
					if( mADCRuleBaseNameList->size() <= 0) {
						break;
					}

					mADCRuleBaseNameIterator = this->getADCRuleBaseNameList()->begin();
					while(mADCRuleBaseNameIterator != mADCRuleBaseNameList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(1095);
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
					if(!(*mADCRuleBaseNameIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mADCRuleBaseNameIterator)->getAvpOffsetLen().first], (*mADCRuleBaseNameIterator)->getAvpOffsetLen().second);
						array->offset += (*mADCRuleBaseNameIterator)->getAvpOffsetLen().second;
						array->size += (*mADCRuleBaseNameIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mADCRuleBaseNameIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mADCRuleBaseNameIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ADCRuleBaseName");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mADCRuleBaseNameIterator++;
						continue;
					}
						if(((*mADCRuleBaseNameIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mADCRuleBaseNameIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ADCRuleBaseName");
							throw lTssDiaMsgException;
						}
						mADCRuleBaseNameIterator++;
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


int ADCRuleRemove::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 1096:
				{
						mMandatoryAvpSetVal [ADCRuleRemove_ADCRULENAME] = 1;
					mTagsPresent[ADCRuleRemove_ADCRULENAME] = 1;
					OctetString *lADCRuleName = new OctetString();
					if( lADCRuleName == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleName");
						throw lTssDiaMsgException;
					}
					lADCRuleName->setAvpCode(1096);
					lADCRuleName->setAvpVendorId(lVenderId);
					lADCRuleName->SetDataType((DiameterDataType)5);
					lADCRuleName->mspByteArray = mspByteArray;
					lADCRuleName->mAvpDecodedFlag = false;
					lADCRuleName->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mADCRuleNameList == NULL)
						this->setADCRuleNameList();
					mADCRuleNameList->push_back(lADCRuleName);
					
				}
				break;
			case 1095:
				{
						mMandatoryAvpSetVal [ADCRuleRemove_ADCRULEBASENAME] = 1;
					mTagsPresent[ADCRuleRemove_ADCRULEBASENAME] = 1;
					OctetString *lADCRuleBaseName = new OctetString();
					if( lADCRuleBaseName == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleBaseName");
						throw lTssDiaMsgException;
					}
					lADCRuleBaseName->setAvpCode(1095);
					lADCRuleBaseName->setAvpVendorId(lVenderId);
					lADCRuleBaseName->SetDataType((DiameterDataType)5);
					lADCRuleBaseName->mspByteArray = mspByteArray;
					lADCRuleBaseName->mAvpDecodedFlag = false;
					lADCRuleBaseName->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mADCRuleBaseNameList == NULL)
						this->setADCRuleBaseNameList();
					mADCRuleBaseNameList->push_back(lADCRuleBaseName);
					
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


DiameterBaseInterface* ADCRuleRemove::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleRemove")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1096:
			{
				if(mADCRuleNameList != NULL && mADCRuleNameList->size() > 0)
					return (mADCRuleNameList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 1095:
			{
				if(mADCRuleBaseNameList != NULL && mADCRuleBaseNameList->size() > 0)
					return (mADCRuleBaseNameList->back())->Find(array, avpCode);
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


BOOLEAN ADCRuleRemove::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleRemove")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1096:
			{
				if(mADCRuleNameList != NULL)
				{
					for(auto itr = mADCRuleNameList->begin(); itr != mADCRuleNameList->end(); ++itr)
					{
						DiameterBaseInterface* inf =  (*itr)->Find(this->mspByteArray.get(), avpCode);
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
				}
				break;
			}
			case 1095:
			{
				if(mADCRuleBaseNameList != NULL)
				{
					for(auto itr = mADCRuleBaseNameList->begin(); itr != mADCRuleBaseNameList->end(); ++itr)
					{
						DiameterBaseInterface* inf =  (*itr)->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> ADCRuleRemove::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN ADCRuleRemove::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleRemove")     ;
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
			case 1096:
			{
				if(mADCRuleNameList != NULL)
				{
					for(auto itr = mADCRuleNameList->begin(); itr != mADCRuleNameList->end(); ++itr)
					{
						DiameterBaseInterface* inf =  (*itr)->Find(this->mspByteArray.get(), avpCode);
						if(inf != NULL)
						{
							pBaseInterface.push_back(inf);
						}
					}

				}
				break;
			}
			case 1095:
			{
				if(mADCRuleBaseNameList != NULL)
				{
					for(auto itr = mADCRuleBaseNameList->begin(); itr != mADCRuleBaseNameList->end(); ++itr)
					{
						DiameterBaseInterface* inf =  (*itr)->Find(this->mspByteArray.get(), avpCode);
						if(inf != NULL)
						{
							pBaseInterface.push_back(inf);
						}
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


INT32 ADCRuleRemove::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 ADCRuleRemove::getAvpCode()
{
	return mAvpCode;
}
INT32 ADCRuleRemove::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 ADCRuleRemove::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 ADCRuleRemove::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> ADCRuleRemove::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void ADCRuleRemove::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case ADCRuleRemove_ADCRULENAME:
			{
				if( mADCRuleNameList->size() <= 0) {
					break;
				}

				mADCRuleNameIterator = this->getADCRuleNameList()->begin();
				while(mADCRuleNameIterator != this->getADCRuleNameList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1096" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ADCRuleName" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mADCRuleNameIterator)->Display(tab+1);
					mADCRuleNameIterator++;

				};

			}
				break;
			case ADCRuleRemove_ADCRULEBASENAME:
			{
				if( mADCRuleBaseNameList->size() <= 0) {
					break;
				}

				mADCRuleBaseNameIterator = this->getADCRuleBaseNameList()->begin();
				while(mADCRuleBaseNameIterator != this->getADCRuleBaseNameList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1095" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ADCRuleBaseName" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mADCRuleBaseNameIterator)->Display(tab+1);
					mADCRuleBaseNameIterator++;

				};

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


BOOLEAN ADCRuleRemove::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<2> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case ADCRuleRemove_ADCRULENAME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1096");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1096", lMissingAvpInfo);
			}
				break;
			case ADCRuleRemove_ADCRULEBASENAME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1095");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1095", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
