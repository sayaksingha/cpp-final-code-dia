#include "cx/include/SCSCFRestorationInfo.h"

using namespace CX;
BOOLEAN SCSCFRestorationInfo::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

SCSCFRestorationInfo::SCSCFRestorationInfo()
{
	mUserName = NULL;
	mRestorationInfoGrpList = NULL;
	mRegistrationTimeOut = NULL;
	mSIPAuthenticationScheme = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<4>(string("1001"));
	mMandatoryAvpSetVal.reset();
}

SCSCFRestorationInfo::~SCSCFRestorationInfo()
{
	if(mUserName != NULL)
		delete mUserName;
	if(mRestorationInfoGrpList != NULL){
		mRestorationInfoGrpIterator = mRestorationInfoGrpList->begin();
		while(mRestorationInfoGrpIterator != mRestorationInfoGrpList->end()){
	if(*mRestorationInfoGrpIterator != NULL)
			delete (*mRestorationInfoGrpIterator);
			mRestorationInfoGrpIterator++;
		}
		delete mRestorationInfoGrpList;
	}
	if(mRegistrationTimeOut != NULL)
		delete mRegistrationTimeOut;
	if(mSIPAuthenticationScheme != NULL)
		delete mSIPAuthenticationScheme;
}

OctetString* SCSCFRestorationInfo::setUserName(){
	mMandatoryAvpSetVal [SCSCFRestorationInfo_USERNAME] = 1;
	if(mUserName == NULL)
	{
		mUserName = new OctetString();
		mTagsPresent[SCSCFRestorationInfo_USERNAME] = 1;
		return mUserName;
	}
	return mUserName;
}

void SCSCFRestorationInfo::resetUserName(){
	mTagsPresent[SCSCFRestorationInfo_USERNAME] = 0;
	if(mUserName != NULL)
	{
		delete mUserName; 
		mUserName = NULL;
	}
}

Time* SCSCFRestorationInfo::setRegistrationTimeOut(){
	if(mRegistrationTimeOut == NULL)
	{
		mRegistrationTimeOut = new Time();
		mTagsPresent[SCSCFRestorationInfo_REGISTRATIONTIMEOUT] = 1;
		return mRegistrationTimeOut;
	}
	return mRegistrationTimeOut;
}

void SCSCFRestorationInfo::resetRegistrationTimeOut(){
	mTagsPresent[SCSCFRestorationInfo_REGISTRATIONTIMEOUT] = 0;
	if(mRegistrationTimeOut != NULL)
	{
		delete mRegistrationTimeOut; 
		mRegistrationTimeOut = NULL;
	}
}

OctetString* SCSCFRestorationInfo::setSIPAuthenticationScheme(){
	mMandatoryAvpSetVal [SCSCFRestorationInfo_SIPAUTHENTICATIONSCHEME] = 1;
	if(mSIPAuthenticationScheme == NULL)
	{
		mSIPAuthenticationScheme = new OctetString();
		mTagsPresent[SCSCFRestorationInfo_SIPAUTHENTICATIONSCHEME] = 1;
		return mSIPAuthenticationScheme;
	}
	return mSIPAuthenticationScheme;
}

void SCSCFRestorationInfo::resetSIPAuthenticationScheme(){
	mTagsPresent[SCSCFRestorationInfo_SIPAUTHENTICATIONSCHEME] = 0;
	if(mSIPAuthenticationScheme != NULL)
	{
		delete mSIPAuthenticationScheme; 
		mSIPAuthenticationScheme = NULL;
	}
}

OctetString* SCSCFRestorationInfo::getUserName(){
	if(NULL == mUserName) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserName is Null");
		throw lTssDiaMsgException;
	}
	if(!mUserName->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUserName->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserName is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUserName->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUserName->Decode(mspByteArray.get(), mUserName->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserName")     ;
			throw lTssDiaMsgException;
		}
		mUserName->mAvpDecodedFlag = true;
	}
	return mUserName;
}

list<RestorationInfo*>* SCSCFRestorationInfo::getRestorationInfoGrpList()
{
	if(mRestorationInfoGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RestorationInfo is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mRestorationInfoGrpList)
	{
		if(mRestorationInfoGrpList != NULL)
		{
		if(mRestorationInfoGrpList->size() == 0)
		{
			mTagsPresent[SCSCFRestorationInfo_RESTORATIONINFO] = 0;
			mRestorationInfoGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RestorationInfo is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RestorationInfo is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RestorationInfo")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mRestorationInfoGrpList;
}

list<RestorationInfo*>* SCSCFRestorationInfo::setRestorationInfoGrpList(){
	mTagsPresent[SCSCFRestorationInfo_RESTORATIONINFO] = 1;
	if(mRestorationInfoGrpList == NULL)
		mRestorationInfoGrpList = new list<RestorationInfo*>;
	mRestorationInfoGrpList->clear();
	return mRestorationInfoGrpList;
}

void SCSCFRestorationInfo::resetRestorationInfoGrpList(){
	mTagsPresent[SCSCFRestorationInfo_RESTORATIONINFO] = 0;
	if(mRestorationInfoGrpList != NULL)
		delete mRestorationInfoGrpList;
}

Time* SCSCFRestorationInfo::getRegistrationTimeOut(){
	if(NULL == mRegistrationTimeOut) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RegistrationTimeOut is Null");
		throw lTssDiaMsgException;
	}
	if(!mRegistrationTimeOut->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRegistrationTimeOut->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RegistrationTimeOut is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRegistrationTimeOut->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRegistrationTimeOut->Decode(mspByteArray.get(), mRegistrationTimeOut->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RegistrationTimeOut")     ;
			throw lTssDiaMsgException;
		}
		mRegistrationTimeOut->mAvpDecodedFlag = true;
	}
	return mRegistrationTimeOut;
}

OctetString* SCSCFRestorationInfo::getSIPAuthenticationScheme(){
	if(NULL == mSIPAuthenticationScheme) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SIPAuthenticationScheme is Null");
		throw lTssDiaMsgException;
	}
	if(!mSIPAuthenticationScheme->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSIPAuthenticationScheme->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SIPAuthenticationScheme is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSIPAuthenticationScheme->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSIPAuthenticationScheme->Decode(mspByteArray.get(), mSIPAuthenticationScheme->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SIPAuthenticationScheme")     ;
			throw lTssDiaMsgException;
		}
		mSIPAuthenticationScheme->mAvpDecodedFlag = true;
	}
	return mSIPAuthenticationScheme;
}



int SCSCFRestorationInfo::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case SCSCFRestorationInfo_USERNAME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1);
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
					if(!mUserName->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mUserName->getAvpOffsetLen().first], mUserName->getAvpOffsetLen().second);
						array->offset += mUserName->getAvpOffsetLen().second;
						array->size += mUserName->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mUserName->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mUserName->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserName");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mUserName->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mUserName->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserName");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SCSCFRestorationInfo_RESTORATIONINFO:
			{
				if( mRestorationInfoGrpList->size() <= 0) {
					break;
				}

				mRestorationInfoGrpIterator = this->getRestorationInfoGrpList()->begin();
				while(mRestorationInfoGrpIterator != mRestorationInfoGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(649);
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
					if(((*mRestorationInfoGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RestorationInfo");
						throw lTssDiaMsgException;
					}
					
					mRestorationInfoGrpIterator++;
				}
				}
				break;
			case SCSCFRestorationInfo_REGISTRATIONTIMEOUT:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(661);
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
					if(!mRegistrationTimeOut->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRegistrationTimeOut->getAvpOffsetLen().first], mRegistrationTimeOut->getAvpOffsetLen().second);
						array->offset += mRegistrationTimeOut->getAvpOffsetLen().second;
						array->size += mRegistrationTimeOut->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mRegistrationTimeOut->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mRegistrationTimeOut->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RegistrationTimeOut");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mRegistrationTimeOut->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mRegistrationTimeOut->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RegistrationTimeOut");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SCSCFRestorationInfo_SIPAUTHENTICATIONSCHEME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(608);
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
					if(!mSIPAuthenticationScheme->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSIPAuthenticationScheme->getAvpOffsetLen().first], mSIPAuthenticationScheme->getAvpOffsetLen().second);
						array->offset += mSIPAuthenticationScheme->getAvpOffsetLen().second;
						array->size += mSIPAuthenticationScheme->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mSIPAuthenticationScheme->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mSIPAuthenticationScheme->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SIPAuthenticationScheme");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mSIPAuthenticationScheme->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mSIPAuthenticationScheme->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SIPAuthenticationScheme");
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


int SCSCFRestorationInfo::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 1:
				{
						mMandatoryAvpSetVal [SCSCFRestorationInfo_USERNAME] = 1;
					if( NULL == this->setUserName())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserName");
						throw lTssDiaMsgException;
					}
					mUserName->setAvpCode(1);
					mUserName->setAvpVendorId(lVenderId);
					mUserName->SetDataType((DiameterDataType)5);
					mUserName->mspByteArray = mspByteArray;
					mUserName->mAvpDecodedFlag = false;
					mUserName->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 649:
				{
					mTagsPresent[SCSCFRestorationInfo_RESTORATIONINFO] = 1;
					RestorationInfo *lRestorationInfo = new RestorationInfo();
					if( lRestorationInfo == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RestorationInfo");
						throw lTssDiaMsgException;
					}
					lRestorationInfo->setAvpCode(649);
					lRestorationInfo->SetDataType((DiameterDataType)6);
					lRestorationInfo->mspByteArray = mspByteArray;
					lRestorationInfo->mAvpDecodedFlag = false;
					lRestorationInfo->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mRestorationInfoGrpList == NULL)
						this->setRestorationInfoGrpList();
					mRestorationInfoGrpList->push_back(lRestorationInfo);
					mBaseInterfaceList.push_back(lRestorationInfo);
					
				}
				break;
			case 661:
				{
					if( NULL == this->setRegistrationTimeOut())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RegistrationTimeOut");
						throw lTssDiaMsgException;
					}
					mRegistrationTimeOut->setAvpCode(661);
					mRegistrationTimeOut->setAvpVendorId(lVenderId);
					mRegistrationTimeOut->SetDataType((DiameterDataType)9);
					mRegistrationTimeOut->mspByteArray = mspByteArray;
					mRegistrationTimeOut->mAvpDecodedFlag = false;
					mRegistrationTimeOut->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 608:
				{
						mMandatoryAvpSetVal [SCSCFRestorationInfo_SIPAUTHENTICATIONSCHEME] = 1;
					if( NULL == this->setSIPAuthenticationScheme())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SIPAuthenticationScheme");
						throw lTssDiaMsgException;
					}
					mSIPAuthenticationScheme->setAvpCode(608);
					mSIPAuthenticationScheme->setAvpVendorId(lVenderId);
					mSIPAuthenticationScheme->SetDataType((DiameterDataType)5);
					mSIPAuthenticationScheme->mspByteArray = mspByteArray;
					mSIPAuthenticationScheme->mAvpDecodedFlag = false;
					mSIPAuthenticationScheme->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* SCSCFRestorationInfo::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SCSCFRestorationInfo")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1:
			{
				if(mUserName != NULL)
					return mUserName->Find(array, avpCode);
				else
					return NULL;
			}
			case 661:
			{
				if(mRegistrationTimeOut != NULL)
					return mRegistrationTimeOut->Find(array, avpCode);
				else
					return NULL;
			}
			case 608:
			{
				if(mSIPAuthenticationScheme != NULL)
					return mSIPAuthenticationScheme->Find(array, avpCode);
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


BOOLEAN SCSCFRestorationInfo::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SCSCFRestorationInfo")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1:
			{
				if(mUserName != NULL)
				{
					DiameterBaseInterface* inf =  mUserName->Find(this->mspByteArray.get(), avpCode);
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
				if(mRestorationInfoGrpList != NULL)
				{
					for(auto itr = mRestorationInfoGrpList->begin(); itr != mRestorationInfoGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
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
			case 661:
			{
				if(mRegistrationTimeOut != NULL)
				{
					DiameterBaseInterface* inf =  mRegistrationTimeOut->Find(this->mspByteArray.get(), avpCode);
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
			case 608:
			{
				if(mSIPAuthenticationScheme != NULL)
				{
					DiameterBaseInterface* inf =  mSIPAuthenticationScheme->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> SCSCFRestorationInfo::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN SCSCFRestorationInfo::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SCSCFRestorationInfo")     ;
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
			case 1:
			{
				if(mUserName != NULL)
				{
					DiameterBaseInterface* inf =  mUserName->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 649:
			{
				if(mRestorationInfoGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mRestorationInfoGrpList->begin(); itr != mRestorationInfoGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mRestorationInfoGrpList->begin(); itr != mRestorationInfoGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 661:
			{
				if(mRegistrationTimeOut != NULL)
				{
					DiameterBaseInterface* inf =  mRegistrationTimeOut->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 608:
			{
				if(mSIPAuthenticationScheme != NULL)
				{
					DiameterBaseInterface* inf =  mSIPAuthenticationScheme->Find(this->mspByteArray.get(), avpCode);
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


INT32 SCSCFRestorationInfo::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 SCSCFRestorationInfo::getAvpCode()
{
	return mAvpCode;
}
INT32 SCSCFRestorationInfo::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 SCSCFRestorationInfo::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 SCSCFRestorationInfo::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> SCSCFRestorationInfo::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void SCSCFRestorationInfo::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case SCSCFRestorationInfo_USERNAME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserName" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getUserName()->Display(tab+1);
			}
				break;
			case SCSCFRestorationInfo_RESTORATIONINFO:
			{
				if( mRestorationInfoGrpList->size() <= 0) {
					break;
				}

				mRestorationInfoGrpIterator = this->getRestorationInfoGrpList()->begin();
				while(mRestorationInfoGrpIterator != this->getRestorationInfoGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "649" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RestorationInfo" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mRestorationInfoGrpIterator)->Display(tab+1);
					mRestorationInfoGrpIterator++;

				};

			}
				break;
			case SCSCFRestorationInfo_REGISTRATIONTIMEOUT:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "661" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RegistrationTimeOut" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getRegistrationTimeOut()->Display(tab+1);
			}
				break;
			case SCSCFRestorationInfo_SIPAUTHENTICATIONSCHEME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "608" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SIPAuthenticationScheme" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getSIPAuthenticationScheme()->Display(tab+1);
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


BOOLEAN SCSCFRestorationInfo::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<4> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case SCSCFRestorationInfo_USERNAME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1", lMissingAvpInfo);
			}
				break;
			case SCSCFRestorationInfo_RESTORATIONINFO:
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
			case SCSCFRestorationInfo_REGISTRATIONTIMEOUT:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 661");
				}
				else
					sprintf(lMissingAvpInfo, "%s,661", lMissingAvpInfo);
			}
				break;
			case SCSCFRestorationInfo_SIPAUTHENTICATIONSCHEME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 608");
				}
				else
					sprintf(lMissingAvpInfo, "%s,608", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
