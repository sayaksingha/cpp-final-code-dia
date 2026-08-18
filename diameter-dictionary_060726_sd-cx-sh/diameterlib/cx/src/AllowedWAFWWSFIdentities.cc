#include "cx/include/AllowedWAFWWSFIdentities.h"

using namespace CX;
BOOLEAN AllowedWAFWWSFIdentities::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

AllowedWAFWWSFIdentities::AllowedWAFWWSFIdentities()
{
	mWebRTCAuthenticationFunctionNameList = NULL;
	mWebRTCWebServerFunctionNameList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<2>(string("00"));
	mMandatoryAvpSetVal.reset();
}

AllowedWAFWWSFIdentities::~AllowedWAFWWSFIdentities()
{
	if(mWebRTCAuthenticationFunctionNameList != NULL){
		mWebRTCAuthenticationFunctionNameIterator = mWebRTCAuthenticationFunctionNameList->begin();
		while(mWebRTCAuthenticationFunctionNameIterator != mWebRTCAuthenticationFunctionNameList->end()){
			delete (*mWebRTCAuthenticationFunctionNameIterator);
			mWebRTCAuthenticationFunctionNameIterator++;
		}
		delete mWebRTCAuthenticationFunctionNameList;
	}
	if(mWebRTCWebServerFunctionNameList != NULL){
		mWebRTCWebServerFunctionNameIterator = mWebRTCWebServerFunctionNameList->begin();
		while(mWebRTCWebServerFunctionNameIterator != mWebRTCWebServerFunctionNameList->end()){
			delete (*mWebRTCWebServerFunctionNameIterator);
			mWebRTCWebServerFunctionNameIterator++;
		}
		delete mWebRTCWebServerFunctionNameList;
	}
}

list<OctetString*>* AllowedWAFWWSFIdentities::getWebRTCAuthenticationFunctionNameList()
{
	if(mWebRTCAuthenticationFunctionNameList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "WebRTCAuthenticationFunctionName is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mWebRTCAuthenticationFunctionNameList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "WebRTCAuthenticationFunctionName is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding WebRTCAuthenticationFunctionName")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mWebRTCAuthenticationFunctionNameList;
}

list<OctetString*>* AllowedWAFWWSFIdentities::setWebRTCAuthenticationFunctionNameList() {
	mTagsPresent[AllowedWAFWWSFIdentities_WEBRTCAUTHENTICATIONFUNCTIONNAME] = 1;
	if(mWebRTCAuthenticationFunctionNameList == NULL)
		mWebRTCAuthenticationFunctionNameList = new list<OctetString*>;
	mWebRTCAuthenticationFunctionNameList->clear();
	return mWebRTCAuthenticationFunctionNameList;
}

void AllowedWAFWWSFIdentities::resetWebRTCAuthenticationFunctionNameList(){
	mTagsPresent[AllowedWAFWWSFIdentities_WEBRTCAUTHENTICATIONFUNCTIONNAME] = 0;
	if(mWebRTCAuthenticationFunctionNameList != NULL)
		delete mWebRTCAuthenticationFunctionNameList;
}

list<OctetString*>* AllowedWAFWWSFIdentities::getWebRTCWebServerFunctionNameList()
{
	if(mWebRTCWebServerFunctionNameList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "WebRTCWebServerFunctionName is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mWebRTCWebServerFunctionNameList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "WebRTCWebServerFunctionName is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding WebRTCWebServerFunctionName")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mWebRTCWebServerFunctionNameList;
}

list<OctetString*>* AllowedWAFWWSFIdentities::setWebRTCWebServerFunctionNameList() {
	mTagsPresent[AllowedWAFWWSFIdentities_WEBRTCWEBSERVERFUNCTIONNAME] = 1;
	if(mWebRTCWebServerFunctionNameList == NULL)
		mWebRTCWebServerFunctionNameList = new list<OctetString*>;
	mWebRTCWebServerFunctionNameList->clear();
	return mWebRTCWebServerFunctionNameList;
}

void AllowedWAFWWSFIdentities::resetWebRTCWebServerFunctionNameList(){
	mTagsPresent[AllowedWAFWWSFIdentities_WEBRTCWEBSERVERFUNCTIONNAME] = 0;
	if(mWebRTCWebServerFunctionNameList != NULL)
		delete mWebRTCWebServerFunctionNameList;
}



int AllowedWAFWWSFIdentities::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case AllowedWAFWWSFIdentities_WEBRTCAUTHENTICATIONFUNCTIONNAME:
			{
					if( mWebRTCAuthenticationFunctionNameList->size() <= 0) {
						break;
					}

					mWebRTCAuthenticationFunctionNameIterator = this->getWebRTCAuthenticationFunctionNameList()->begin();
					while(mWebRTCAuthenticationFunctionNameIterator != mWebRTCAuthenticationFunctionNameList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(657);
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
					if(!(*mWebRTCAuthenticationFunctionNameIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mWebRTCAuthenticationFunctionNameIterator)->getAvpOffsetLen().first], (*mWebRTCAuthenticationFunctionNameIterator)->getAvpOffsetLen().second);
						array->offset += (*mWebRTCAuthenticationFunctionNameIterator)->getAvpOffsetLen().second;
						array->size += (*mWebRTCAuthenticationFunctionNameIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mWebRTCAuthenticationFunctionNameIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mWebRTCAuthenticationFunctionNameIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding WebRTCAuthenticationFunctionName");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mWebRTCAuthenticationFunctionNameIterator++;
						continue;
					}
						if(((*mWebRTCAuthenticationFunctionNameIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mWebRTCAuthenticationFunctionNameIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding WebRTCAuthenticationFunctionName");
							throw lTssDiaMsgException;
						}
						mWebRTCAuthenticationFunctionNameIterator++;
				}
				}
				break;
			case AllowedWAFWWSFIdentities_WEBRTCWEBSERVERFUNCTIONNAME:
			{
					if( mWebRTCWebServerFunctionNameList->size() <= 0) {
						break;
					}

					mWebRTCWebServerFunctionNameIterator = this->getWebRTCWebServerFunctionNameList()->begin();
					while(mWebRTCWebServerFunctionNameIterator != mWebRTCWebServerFunctionNameList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(658);
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
					if(!(*mWebRTCWebServerFunctionNameIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mWebRTCWebServerFunctionNameIterator)->getAvpOffsetLen().first], (*mWebRTCWebServerFunctionNameIterator)->getAvpOffsetLen().second);
						array->offset += (*mWebRTCWebServerFunctionNameIterator)->getAvpOffsetLen().second;
						array->size += (*mWebRTCWebServerFunctionNameIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mWebRTCWebServerFunctionNameIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mWebRTCWebServerFunctionNameIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding WebRTCWebServerFunctionName");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mWebRTCWebServerFunctionNameIterator++;
						continue;
					}
						if(((*mWebRTCWebServerFunctionNameIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mWebRTCWebServerFunctionNameIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding WebRTCWebServerFunctionName");
							throw lTssDiaMsgException;
						}
						mWebRTCWebServerFunctionNameIterator++;
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


int AllowedWAFWWSFIdentities::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 657:
				{
					mTagsPresent[AllowedWAFWWSFIdentities_WEBRTCAUTHENTICATIONFUNCTIONNAME] = 1;
					OctetString *lWebRTCAuthenticationFunctionName = new OctetString();
					if( lWebRTCAuthenticationFunctionName == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding WebRTCAuthenticationFunctionName");
						throw lTssDiaMsgException;
					}
					lWebRTCAuthenticationFunctionName->setAvpCode(657);
					lWebRTCAuthenticationFunctionName->setAvpVendorId(lVenderId);
					lWebRTCAuthenticationFunctionName->SetDataType((DiameterDataType)5);
					lWebRTCAuthenticationFunctionName->mspByteArray = mspByteArray;
					lWebRTCAuthenticationFunctionName->mAvpDecodedFlag = false;
					lWebRTCAuthenticationFunctionName->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mWebRTCAuthenticationFunctionNameList == NULL)
						this->setWebRTCAuthenticationFunctionNameList();
					mWebRTCAuthenticationFunctionNameList->push_back(lWebRTCAuthenticationFunctionName);
					
				}
				break;
			case 658:
				{
					mTagsPresent[AllowedWAFWWSFIdentities_WEBRTCWEBSERVERFUNCTIONNAME] = 1;
					OctetString *lWebRTCWebServerFunctionName = new OctetString();
					if( lWebRTCWebServerFunctionName == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding WebRTCWebServerFunctionName");
						throw lTssDiaMsgException;
					}
					lWebRTCWebServerFunctionName->setAvpCode(658);
					lWebRTCWebServerFunctionName->setAvpVendorId(lVenderId);
					lWebRTCWebServerFunctionName->SetDataType((DiameterDataType)5);
					lWebRTCWebServerFunctionName->mspByteArray = mspByteArray;
					lWebRTCWebServerFunctionName->mAvpDecodedFlag = false;
					lWebRTCWebServerFunctionName->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mWebRTCWebServerFunctionNameList == NULL)
						this->setWebRTCWebServerFunctionNameList();
					mWebRTCWebServerFunctionNameList->push_back(lWebRTCWebServerFunctionName);
					
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


DiameterBaseInterface* AllowedWAFWWSFIdentities::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AllowedWAFWWSFIdentities")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 657:
			{
				if(mWebRTCAuthenticationFunctionNameList != NULL && mWebRTCAuthenticationFunctionNameList->size() > 0)
					return (mWebRTCAuthenticationFunctionNameList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 658:
			{
				if(mWebRTCWebServerFunctionNameList != NULL && mWebRTCWebServerFunctionNameList->size() > 0)
					return (mWebRTCWebServerFunctionNameList->back())->Find(array, avpCode);
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


BOOLEAN AllowedWAFWWSFIdentities::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AllowedWAFWWSFIdentities")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 657:
			{
				if(mWebRTCAuthenticationFunctionNameList != NULL)
				{
					for(auto itr = mWebRTCAuthenticationFunctionNameList->begin(); itr != mWebRTCAuthenticationFunctionNameList->end(); ++itr)
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
			case 658:
			{
				if(mWebRTCWebServerFunctionNameList != NULL)
				{
					for(auto itr = mWebRTCWebServerFunctionNameList->begin(); itr != mWebRTCWebServerFunctionNameList->end(); ++itr)
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
std::shared_ptr<byteArray> AllowedWAFWWSFIdentities::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN AllowedWAFWWSFIdentities::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AllowedWAFWWSFIdentities")     ;
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
			case 657:
			{
				if(mWebRTCAuthenticationFunctionNameList != NULL)
				{
					for(auto itr = mWebRTCAuthenticationFunctionNameList->begin(); itr != mWebRTCAuthenticationFunctionNameList->end(); ++itr)
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
			case 658:
			{
				if(mWebRTCWebServerFunctionNameList != NULL)
				{
					for(auto itr = mWebRTCWebServerFunctionNameList->begin(); itr != mWebRTCWebServerFunctionNameList->end(); ++itr)
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


INT32 AllowedWAFWWSFIdentities::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 AllowedWAFWWSFIdentities::getAvpCode()
{
	return mAvpCode;
}
INT32 AllowedWAFWWSFIdentities::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 AllowedWAFWWSFIdentities::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 AllowedWAFWWSFIdentities::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> AllowedWAFWWSFIdentities::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void AllowedWAFWWSFIdentities::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case AllowedWAFWWSFIdentities_WEBRTCAUTHENTICATIONFUNCTIONNAME:
			{
				if( mWebRTCAuthenticationFunctionNameList->size() <= 0) {
					break;
				}

				mWebRTCAuthenticationFunctionNameIterator = this->getWebRTCAuthenticationFunctionNameList()->begin();
				while(mWebRTCAuthenticationFunctionNameIterator != this->getWebRTCAuthenticationFunctionNameList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "657" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "WebRTCAuthenticationFunctionName" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mWebRTCAuthenticationFunctionNameIterator)->Display(tab+1);
					mWebRTCAuthenticationFunctionNameIterator++;

				};

			}
				break;
			case AllowedWAFWWSFIdentities_WEBRTCWEBSERVERFUNCTIONNAME:
			{
				if( mWebRTCWebServerFunctionNameList->size() <= 0) {
					break;
				}

				mWebRTCWebServerFunctionNameIterator = this->getWebRTCWebServerFunctionNameList()->begin();
				while(mWebRTCWebServerFunctionNameIterator != this->getWebRTCWebServerFunctionNameList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "658" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "WebRTCWebServerFunctionName" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mWebRTCWebServerFunctionNameIterator)->Display(tab+1);
					mWebRTCWebServerFunctionNameIterator++;

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


BOOLEAN AllowedWAFWWSFIdentities::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<2> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case AllowedWAFWWSFIdentities_WEBRTCAUTHENTICATIONFUNCTIONNAME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 657");
				}
				else
					sprintf(lMissingAvpInfo, "%s,657", lMissingAvpInfo);
			}
				break;
			case AllowedWAFWWSFIdentities_WEBRTCWEBSERVERFUNCTIONNAME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 658");
				}
				else
					sprintf(lMissingAvpInfo, "%s,658", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
