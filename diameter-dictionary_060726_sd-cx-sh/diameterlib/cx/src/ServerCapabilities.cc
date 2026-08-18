#include "cx/include/ServerCapabilities.h"

using namespace CX;
BOOLEAN ServerCapabilities::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

ServerCapabilities::ServerCapabilities()
{
	mMandatoryCapabilityList = NULL;
	mOptionalCapabilityList = NULL;
	mServerNameList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<3>(string("111"));
	mMandatoryAvpSetVal.reset();
}

ServerCapabilities::~ServerCapabilities()
{
	if(mMandatoryCapabilityList != NULL){
		mMandatoryCapabilityIterator = mMandatoryCapabilityList->begin();
		while(mMandatoryCapabilityIterator != mMandatoryCapabilityList->end()){
			delete (*mMandatoryCapabilityIterator);
			mMandatoryCapabilityIterator++;
		}
		delete mMandatoryCapabilityList;
	}
	if(mOptionalCapabilityList != NULL){
		mOptionalCapabilityIterator = mOptionalCapabilityList->begin();
		while(mOptionalCapabilityIterator != mOptionalCapabilityList->end()){
			delete (*mOptionalCapabilityIterator);
			mOptionalCapabilityIterator++;
		}
		delete mOptionalCapabilityList;
	}
	if(mServerNameList != NULL){
		mServerNameIterator = mServerNameList->begin();
		while(mServerNameIterator != mServerNameList->end()){
			delete (*mServerNameIterator);
			mServerNameIterator++;
		}
		delete mServerNameList;
	}
}

list<Unsigned32*>* ServerCapabilities::getMandatoryCapabilityList()
{
	if(mMandatoryCapabilityList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MandatoryCapability is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mMandatoryCapabilityList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MandatoryCapability is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MandatoryCapability")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mMandatoryCapabilityList;
}

list<Unsigned32*>* ServerCapabilities::setMandatoryCapabilityList() {
	mTagsPresent[ServerCapabilities_MANDATORYCAPABILITY] = 1;
	if(mMandatoryCapabilityList == NULL)
		mMandatoryCapabilityList = new list<Unsigned32*>;
	mMandatoryAvpSetVal [ServerCapabilities_MANDATORYCAPABILITY] = 1;
	mMandatoryCapabilityList->clear();
	return mMandatoryCapabilityList;
}

void ServerCapabilities::resetMandatoryCapabilityList(){
	mTagsPresent[ServerCapabilities_MANDATORYCAPABILITY] = 0;
	if(mMandatoryCapabilityList != NULL)
		delete mMandatoryCapabilityList;
}

list<Unsigned32*>* ServerCapabilities::getOptionalCapabilityList()
{
	if(mOptionalCapabilityList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OptionalCapability is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mOptionalCapabilityList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OptionalCapability is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OptionalCapability")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mOptionalCapabilityList;
}

list<Unsigned32*>* ServerCapabilities::setOptionalCapabilityList() {
	mTagsPresent[ServerCapabilities_OPTIONALCAPABILITY] = 1;
	if(mOptionalCapabilityList == NULL)
		mOptionalCapabilityList = new list<Unsigned32*>;
	mMandatoryAvpSetVal [ServerCapabilities_OPTIONALCAPABILITY] = 1;
	mOptionalCapabilityList->clear();
	return mOptionalCapabilityList;
}

void ServerCapabilities::resetOptionalCapabilityList(){
	mTagsPresent[ServerCapabilities_OPTIONALCAPABILITY] = 0;
	if(mOptionalCapabilityList != NULL)
		delete mOptionalCapabilityList;
}

list<OctetString*>* ServerCapabilities::getServerNameList()
{
	if(mServerNameList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ServerName is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mServerNameList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ServerName is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ServerName")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mServerNameList;
}

list<OctetString*>* ServerCapabilities::setServerNameList() {
	mTagsPresent[ServerCapabilities_SERVERNAME] = 1;
	if(mServerNameList == NULL)
		mServerNameList = new list<OctetString*>;
	mMandatoryAvpSetVal [ServerCapabilities_SERVERNAME] = 1;
	mServerNameList->clear();
	return mServerNameList;
}

void ServerCapabilities::resetServerNameList(){
	mTagsPresent[ServerCapabilities_SERVERNAME] = 0;
	if(mServerNameList != NULL)
		delete mServerNameList;
}



int ServerCapabilities::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case ServerCapabilities_MANDATORYCAPABILITY:
			{
					if( mMandatoryCapabilityList->size() <= 0) {
						break;
					}

					mMandatoryCapabilityIterator = this->getMandatoryCapabilityList()->begin();
					while(mMandatoryCapabilityIterator != mMandatoryCapabilityList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(604);
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
					if(!(*mMandatoryCapabilityIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mMandatoryCapabilityIterator)->getAvpOffsetLen().first], (*mMandatoryCapabilityIterator)->getAvpOffsetLen().second);
						array->offset += (*mMandatoryCapabilityIterator)->getAvpOffsetLen().second;
						array->size += (*mMandatoryCapabilityIterator)->getAvpOffsetLen().second;
						if(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)
						{
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MandatoryCapability");
							throw lTssDiaMsgException;
						}
						mMandatoryCapabilityIterator++;
						continue;
					}
					if(((*mMandatoryCapabilityIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MandatoryCapability");
						throw lTssDiaMsgException;
					}
					mMandatoryCapabilityIterator++;
				}
				}
				break;
			case ServerCapabilities_OPTIONALCAPABILITY:
			{
					if( mOptionalCapabilityList->size() <= 0) {
						break;
					}

					mOptionalCapabilityIterator = this->getOptionalCapabilityList()->begin();
					while(mOptionalCapabilityIterator != mOptionalCapabilityList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(605);
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
					if(!(*mOptionalCapabilityIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mOptionalCapabilityIterator)->getAvpOffsetLen().first], (*mOptionalCapabilityIterator)->getAvpOffsetLen().second);
						array->offset += (*mOptionalCapabilityIterator)->getAvpOffsetLen().second;
						array->size += (*mOptionalCapabilityIterator)->getAvpOffsetLen().second;
						if(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)
						{
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OptionalCapability");
							throw lTssDiaMsgException;
						}
						mOptionalCapabilityIterator++;
						continue;
					}
					if(((*mOptionalCapabilityIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OptionalCapability");
						throw lTssDiaMsgException;
					}
					mOptionalCapabilityIterator++;
				}
				}
				break;
			case ServerCapabilities_SERVERNAME:
			{
					if( mServerNameList->size() <= 0) {
						break;
					}

					mServerNameIterator = this->getServerNameList()->begin();
					while(mServerNameIterator != mServerNameList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(602);
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
					if(!(*mServerNameIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mServerNameIterator)->getAvpOffsetLen().first], (*mServerNameIterator)->getAvpOffsetLen().second);
						array->offset += (*mServerNameIterator)->getAvpOffsetLen().second;
						array->size += (*mServerNameIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mServerNameIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mServerNameIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ServerName");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mServerNameIterator++;
						continue;
					}
						if(((*mServerNameIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mServerNameIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ServerName");
							throw lTssDiaMsgException;
						}
						mServerNameIterator++;
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


int ServerCapabilities::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 604:
				{
						mMandatoryAvpSetVal [ServerCapabilities_MANDATORYCAPABILITY] = 1;
					mTagsPresent[ServerCapabilities_MANDATORYCAPABILITY] = 1;
					Unsigned32 *lMandatoryCapability = new Unsigned32();
					if( lMandatoryCapability == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MandatoryCapability");
						throw lTssDiaMsgException;
					}
					lMandatoryCapability->setAvpCode(604);
					lMandatoryCapability->setAvpVendorId(lVenderId);
					lMandatoryCapability->SetDataType((DiameterDataType)3);
					lMandatoryCapability->mspByteArray = mspByteArray;
					lMandatoryCapability->mAvpDecodedFlag = false;
					lMandatoryCapability->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mMandatoryCapabilityList == NULL)
						this->setMandatoryCapabilityList();
					mMandatoryCapabilityList->push_back(lMandatoryCapability);
					
				}
				break;
			case 605:
				{
						mMandatoryAvpSetVal [ServerCapabilities_OPTIONALCAPABILITY] = 1;
					mTagsPresent[ServerCapabilities_OPTIONALCAPABILITY] = 1;
					Unsigned32 *lOptionalCapability = new Unsigned32();
					if( lOptionalCapability == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OptionalCapability");
						throw lTssDiaMsgException;
					}
					lOptionalCapability->setAvpCode(605);
					lOptionalCapability->setAvpVendorId(lVenderId);
					lOptionalCapability->SetDataType((DiameterDataType)3);
					lOptionalCapability->mspByteArray = mspByteArray;
					lOptionalCapability->mAvpDecodedFlag = false;
					lOptionalCapability->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mOptionalCapabilityList == NULL)
						this->setOptionalCapabilityList();
					mOptionalCapabilityList->push_back(lOptionalCapability);
					
				}
				break;
			case 602:
				{
						mMandatoryAvpSetVal [ServerCapabilities_SERVERNAME] = 1;
					mTagsPresent[ServerCapabilities_SERVERNAME] = 1;
					OctetString *lServerName = new OctetString();
					if( lServerName == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ServerName");
						throw lTssDiaMsgException;
					}
					lServerName->setAvpCode(602);
					lServerName->setAvpVendorId(lVenderId);
					lServerName->SetDataType((DiameterDataType)5);
					lServerName->mspByteArray = mspByteArray;
					lServerName->mAvpDecodedFlag = false;
					lServerName->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mServerNameList == NULL)
						this->setServerNameList();
					mServerNameList->push_back(lServerName);
					
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


DiameterBaseInterface* ServerCapabilities::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ServerCapabilities")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 604:
			{
				if(mMandatoryCapabilityList != NULL && mMandatoryCapabilityList->size() > 0)
					return (mMandatoryCapabilityList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 605:
			{
				if(mOptionalCapabilityList != NULL && mOptionalCapabilityList->size() > 0)
					return (mOptionalCapabilityList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 602:
			{
				if(mServerNameList != NULL && mServerNameList->size() > 0)
					return (mServerNameList->back())->Find(array, avpCode);
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


BOOLEAN ServerCapabilities::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ServerCapabilities")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 604:
			{
				if(mMandatoryCapabilityList != NULL)
				{
					for(auto itr = mMandatoryCapabilityList->begin(); itr != mMandatoryCapabilityList->end(); ++itr)
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
			case 605:
			{
				if(mOptionalCapabilityList != NULL)
				{
					for(auto itr = mOptionalCapabilityList->begin(); itr != mOptionalCapabilityList->end(); ++itr)
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
			case 602:
			{
				if(mServerNameList != NULL)
				{
					for(auto itr = mServerNameList->begin(); itr != mServerNameList->end(); ++itr)
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
std::shared_ptr<byteArray> ServerCapabilities::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN ServerCapabilities::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ServerCapabilities")     ;
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
			case 604:
			{
				if(mMandatoryCapabilityList != NULL)
				{
					for(auto itr = mMandatoryCapabilityList->begin(); itr != mMandatoryCapabilityList->end(); ++itr)
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
			case 605:
			{
				if(mOptionalCapabilityList != NULL)
				{
					for(auto itr = mOptionalCapabilityList->begin(); itr != mOptionalCapabilityList->end(); ++itr)
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
			case 602:
			{
				if(mServerNameList != NULL)
				{
					for(auto itr = mServerNameList->begin(); itr != mServerNameList->end(); ++itr)
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


INT32 ServerCapabilities::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 ServerCapabilities::getAvpCode()
{
	return mAvpCode;
}
INT32 ServerCapabilities::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 ServerCapabilities::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 ServerCapabilities::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> ServerCapabilities::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void ServerCapabilities::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case ServerCapabilities_MANDATORYCAPABILITY:
			{
				if( mMandatoryCapabilityList->size() <= 0) {
					break;
				}

				mMandatoryCapabilityIterator = this->getMandatoryCapabilityList()->begin();
				while(mMandatoryCapabilityIterator != this->getMandatoryCapabilityList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "604" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MandatoryCapability" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mMandatoryCapabilityIterator)->Display(tab+1);
					mMandatoryCapabilityIterator++;

				};

			}
				break;
			case ServerCapabilities_OPTIONALCAPABILITY:
			{
				if( mOptionalCapabilityList->size() <= 0) {
					break;
				}

				mOptionalCapabilityIterator = this->getOptionalCapabilityList()->begin();
				while(mOptionalCapabilityIterator != this->getOptionalCapabilityList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "605" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OptionalCapability" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mOptionalCapabilityIterator)->Display(tab+1);
					mOptionalCapabilityIterator++;

				};

			}
				break;
			case ServerCapabilities_SERVERNAME:
			{
				if( mServerNameList->size() <= 0) {
					break;
				}

				mServerNameIterator = this->getServerNameList()->begin();
				while(mServerNameIterator != this->getServerNameList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "602" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ServerName" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mServerNameIterator)->Display(tab+1);
					mServerNameIterator++;

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


BOOLEAN ServerCapabilities::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<3> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case ServerCapabilities_MANDATORYCAPABILITY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 604");
				}
				else
					sprintf(lMissingAvpInfo, "%s,604", lMissingAvpInfo);
			}
				break;
			case ServerCapabilities_OPTIONALCAPABILITY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 605");
				}
				else
					sprintf(lMissingAvpInfo, "%s,605", lMissingAvpInfo);
			}
				break;
			case ServerCapabilities_SERVERNAME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 602");
				}
				else
					sprintf(lMissingAvpInfo, "%s,602", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
