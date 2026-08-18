#include "rx/include/AcceptableServiceInfo.h"

using namespace RX;
BOOLEAN AcceptableServiceInfo::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

AcceptableServiceInfo::AcceptableServiceInfo()
{
	mMediaComponentDescriptionGrpList = NULL;
	mMaxRequestedBandwidthUL = NULL;
	mMaxRequestedBandwidthDL = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<3>(string("111"));
	mMandatoryAvpSetVal.reset();
}

AcceptableServiceInfo::~AcceptableServiceInfo()
{
	if(mMediaComponentDescriptionGrpList != NULL){
		mMediaComponentDescriptionGrpIterator = mMediaComponentDescriptionGrpList->begin();
		while(mMediaComponentDescriptionGrpIterator != mMediaComponentDescriptionGrpList->end()){
	if(*mMediaComponentDescriptionGrpIterator != NULL)
			delete (*mMediaComponentDescriptionGrpIterator);
			mMediaComponentDescriptionGrpIterator++;
		}
		delete mMediaComponentDescriptionGrpList;
	}
	if(mMaxRequestedBandwidthUL != NULL)
		delete mMaxRequestedBandwidthUL;
	if(mMaxRequestedBandwidthDL != NULL)
		delete mMaxRequestedBandwidthDL;
}

Unsigned32* AcceptableServiceInfo::setMaxRequestedBandwidthUL(){
	mMandatoryAvpSetVal [AcceptableServiceInfo_MAXREQUESTEDBANDWIDTHUL] = 1;
	if(mMaxRequestedBandwidthUL == NULL)
	{
		mMaxRequestedBandwidthUL = new Unsigned32();
		mTagsPresent[AcceptableServiceInfo_MAXREQUESTEDBANDWIDTHUL] = 1;
		return mMaxRequestedBandwidthUL;
	}
	return mMaxRequestedBandwidthUL;
}

void AcceptableServiceInfo::resetMaxRequestedBandwidthUL(){
	mTagsPresent[AcceptableServiceInfo_MAXREQUESTEDBANDWIDTHUL] = 0;
	if(mMaxRequestedBandwidthUL != NULL)
	{
		delete mMaxRequestedBandwidthUL; 
		mMaxRequestedBandwidthUL = NULL;
	}
}

Unsigned32* AcceptableServiceInfo::setMaxRequestedBandwidthDL(){
	mMandatoryAvpSetVal [AcceptableServiceInfo_MAXREQUESTEDBANDWIDTHDL] = 1;
	if(mMaxRequestedBandwidthDL == NULL)
	{
		mMaxRequestedBandwidthDL = new Unsigned32();
		mTagsPresent[AcceptableServiceInfo_MAXREQUESTEDBANDWIDTHDL] = 1;
		return mMaxRequestedBandwidthDL;
	}
	return mMaxRequestedBandwidthDL;
}

void AcceptableServiceInfo::resetMaxRequestedBandwidthDL(){
	mTagsPresent[AcceptableServiceInfo_MAXREQUESTEDBANDWIDTHDL] = 0;
	if(mMaxRequestedBandwidthDL != NULL)
	{
		delete mMaxRequestedBandwidthDL; 
		mMaxRequestedBandwidthDL = NULL;
	}
}

list<MediaComponentDescription*>* AcceptableServiceInfo::getMediaComponentDescriptionGrpList()
{
	if(mMediaComponentDescriptionGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MediaComponentDescription is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mMediaComponentDescriptionGrpList)
	{
		if(mMediaComponentDescriptionGrpList != NULL)
		{
		if(mMediaComponentDescriptionGrpList->size() == 0)
		{
			mTagsPresent[AcceptableServiceInfo_MEDIACOMPONENTDESCRIPTION] = 0;
			mMediaComponentDescriptionGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MediaComponentDescription is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MediaComponentDescription is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MediaComponentDescription")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mMediaComponentDescriptionGrpList;
}

list<MediaComponentDescription*>* AcceptableServiceInfo::setMediaComponentDescriptionGrpList(){
	mTagsPresent[AcceptableServiceInfo_MEDIACOMPONENTDESCRIPTION] = 1;
	if(mMediaComponentDescriptionGrpList == NULL)
		mMediaComponentDescriptionGrpList = new list<MediaComponentDescription*>;
	mMandatoryAvpSetVal[AcceptableServiceInfo_MEDIACOMPONENTDESCRIPTION] = 1;
	mMediaComponentDescriptionGrpList->clear();
	return mMediaComponentDescriptionGrpList;
}

void AcceptableServiceInfo::resetMediaComponentDescriptionGrpList(){
	mTagsPresent[AcceptableServiceInfo_MEDIACOMPONENTDESCRIPTION] = 0;
	if(mMediaComponentDescriptionGrpList != NULL)
		delete mMediaComponentDescriptionGrpList;
}

Unsigned32* AcceptableServiceInfo::getMaxRequestedBandwidthUL(){
	if(NULL == mMaxRequestedBandwidthUL) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MaxRequestedBandwidthUL is Null");
		throw lTssDiaMsgException;
	}
	if(!mMaxRequestedBandwidthUL->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMaxRequestedBandwidthUL->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MaxRequestedBandwidthUL is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMaxRequestedBandwidthUL->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMaxRequestedBandwidthUL->Decode(mspByteArray.get(), mMaxRequestedBandwidthUL->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MaxRequestedBandwidthUL")     ;
			throw lTssDiaMsgException;
		}
		mMaxRequestedBandwidthUL->mAvpDecodedFlag = true;
	}
	return mMaxRequestedBandwidthUL;
}

Unsigned32* AcceptableServiceInfo::getMaxRequestedBandwidthDL(){
	if(NULL == mMaxRequestedBandwidthDL) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MaxRequestedBandwidthDL is Null");
		throw lTssDiaMsgException;
	}
	if(!mMaxRequestedBandwidthDL->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMaxRequestedBandwidthDL->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MaxRequestedBandwidthDL is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMaxRequestedBandwidthDL->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMaxRequestedBandwidthDL->Decode(mspByteArray.get(), mMaxRequestedBandwidthDL->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MaxRequestedBandwidthDL")     ;
			throw lTssDiaMsgException;
		}
		mMaxRequestedBandwidthDL->mAvpDecodedFlag = true;
	}
	return mMaxRequestedBandwidthDL;
}



int AcceptableServiceInfo::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case AcceptableServiceInfo_MEDIACOMPONENTDESCRIPTION:
			{
				if( mMediaComponentDescriptionGrpList->size() <= 0) {
					break;
				}

				mMediaComponentDescriptionGrpIterator = this->getMediaComponentDescriptionGrpList()->begin();
				while(mMediaComponentDescriptionGrpIterator != mMediaComponentDescriptionGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(517);
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
					if(((*mMediaComponentDescriptionGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MediaComponentDescription");
						throw lTssDiaMsgException;
					}
					
					mMediaComponentDescriptionGrpIterator++;
				}
				}
				break;
			case AcceptableServiceInfo_MAXREQUESTEDBANDWIDTHUL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(515);
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
					if(!mMaxRequestedBandwidthUL->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMaxRequestedBandwidthUL->getAvpOffsetLen().first], mMaxRequestedBandwidthUL->getAvpOffsetLen().second);
						array->offset += mMaxRequestedBandwidthUL->getAvpOffsetLen().second;
						array->size += mMaxRequestedBandwidthUL->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MaxRequestedBandwidthUL");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mMaxRequestedBandwidthUL->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MaxRequestedBandwidthUL");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AcceptableServiceInfo_MAXREQUESTEDBANDWIDTHDL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(516);
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
					if(!mMaxRequestedBandwidthDL->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMaxRequestedBandwidthDL->getAvpOffsetLen().first], mMaxRequestedBandwidthDL->getAvpOffsetLen().second);
						array->offset += mMaxRequestedBandwidthDL->getAvpOffsetLen().second;
						array->size += mMaxRequestedBandwidthDL->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MaxRequestedBandwidthDL");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mMaxRequestedBandwidthDL->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MaxRequestedBandwidthDL");
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


int AcceptableServiceInfo::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 517:
				{
						mMandatoryAvpSetVal [AcceptableServiceInfo_MEDIACOMPONENTDESCRIPTION] = 1;
					mTagsPresent[AcceptableServiceInfo_MEDIACOMPONENTDESCRIPTION] = 1;
					MediaComponentDescription *lMediaComponentDescription = new MediaComponentDescription();
					if( lMediaComponentDescription == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MediaComponentDescription");
						throw lTssDiaMsgException;
					}
					lMediaComponentDescription->setAvpCode(517);
					lMediaComponentDescription->SetDataType((DiameterDataType)6);
					lMediaComponentDescription->mspByteArray = mspByteArray;
					lMediaComponentDescription->mAvpDecodedFlag = false;
					lMediaComponentDescription->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mMediaComponentDescriptionGrpList == NULL)
						this->setMediaComponentDescriptionGrpList();
					mMediaComponentDescriptionGrpList->push_back(lMediaComponentDescription);
					mBaseInterfaceList.push_back(lMediaComponentDescription);
					
				}
				break;
			case 515:
				{
						mMandatoryAvpSetVal [AcceptableServiceInfo_MAXREQUESTEDBANDWIDTHUL] = 1;
					if( NULL == this->setMaxRequestedBandwidthUL())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MaxRequestedBandwidthUL");
						throw lTssDiaMsgException;
					}
					mMaxRequestedBandwidthUL->setAvpCode(515);
					mMaxRequestedBandwidthUL->setAvpVendorId(lVenderId);
					mMaxRequestedBandwidthUL->SetDataType((DiameterDataType)3);
					mMaxRequestedBandwidthUL->mspByteArray = mspByteArray;
					mMaxRequestedBandwidthUL->mAvpDecodedFlag = false;
					mMaxRequestedBandwidthUL->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 516:
				{
						mMandatoryAvpSetVal [AcceptableServiceInfo_MAXREQUESTEDBANDWIDTHDL] = 1;
					if( NULL == this->setMaxRequestedBandwidthDL())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MaxRequestedBandwidthDL");
						throw lTssDiaMsgException;
					}
					mMaxRequestedBandwidthDL->setAvpCode(516);
					mMaxRequestedBandwidthDL->setAvpVendorId(lVenderId);
					mMaxRequestedBandwidthDL->SetDataType((DiameterDataType)3);
					mMaxRequestedBandwidthDL->mspByteArray = mspByteArray;
					mMaxRequestedBandwidthDL->mAvpDecodedFlag = false;
					mMaxRequestedBandwidthDL->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* AcceptableServiceInfo::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AcceptableServiceInfo")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 515:
			{
				if(mMaxRequestedBandwidthUL != NULL)
					return mMaxRequestedBandwidthUL->Find(array, avpCode);
				else
					return NULL;
			}
			case 516:
			{
				if(mMaxRequestedBandwidthDL != NULL)
					return mMaxRequestedBandwidthDL->Find(array, avpCode);
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


BOOLEAN AcceptableServiceInfo::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AcceptableServiceInfo")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 517:
			{
				if(mMediaComponentDescriptionGrpList != NULL)
				{
					for(auto itr = mMediaComponentDescriptionGrpList->begin(); itr != mMediaComponentDescriptionGrpList->end(); ++itr)
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
			case 515:
			{
				if(mMaxRequestedBandwidthUL != NULL)
				{
					DiameterBaseInterface* inf =  mMaxRequestedBandwidthUL->Find(this->mspByteArray.get(), avpCode);
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
			case 516:
			{
				if(mMaxRequestedBandwidthDL != NULL)
				{
					DiameterBaseInterface* inf =  mMaxRequestedBandwidthDL->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> AcceptableServiceInfo::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN AcceptableServiceInfo::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AcceptableServiceInfo")     ;
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
			case 517:
			{
				if(mMediaComponentDescriptionGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mMediaComponentDescriptionGrpList->begin(); itr != mMediaComponentDescriptionGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mMediaComponentDescriptionGrpList->begin(); itr != mMediaComponentDescriptionGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 515:
			{
				if(mMaxRequestedBandwidthUL != NULL)
				{
					DiameterBaseInterface* inf =  mMaxRequestedBandwidthUL->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 516:
			{
				if(mMaxRequestedBandwidthDL != NULL)
				{
					DiameterBaseInterface* inf =  mMaxRequestedBandwidthDL->Find(this->mspByteArray.get(), avpCode);
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


INT32 AcceptableServiceInfo::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 AcceptableServiceInfo::getAvpCode()
{
	return mAvpCode;
}
INT32 AcceptableServiceInfo::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 AcceptableServiceInfo::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 AcceptableServiceInfo::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> AcceptableServiceInfo::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void AcceptableServiceInfo::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case AcceptableServiceInfo_MEDIACOMPONENTDESCRIPTION:
			{
				if( mMediaComponentDescriptionGrpList->size() <= 0) {
					break;
				}

				mMediaComponentDescriptionGrpIterator = this->getMediaComponentDescriptionGrpList()->begin();
				while(mMediaComponentDescriptionGrpIterator != this->getMediaComponentDescriptionGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "517" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MediaComponentDescription" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mMediaComponentDescriptionGrpIterator)->Display(tab+1);
					mMediaComponentDescriptionGrpIterator++;

				};

			}
				break;
			case AcceptableServiceInfo_MAXREQUESTEDBANDWIDTHUL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "515" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MaxRequestedBandwidthUL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getMaxRequestedBandwidthUL()->Display(tab+1);
			}
				break;
			case AcceptableServiceInfo_MAXREQUESTEDBANDWIDTHDL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "516" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MaxRequestedBandwidthDL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getMaxRequestedBandwidthDL()->Display(tab+1);
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


BOOLEAN AcceptableServiceInfo::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<3> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case AcceptableServiceInfo_MEDIACOMPONENTDESCRIPTION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 517");
				}
				else
					sprintf(lMissingAvpInfo, "%s,517", lMissingAvpInfo);
			}
				break;
			case AcceptableServiceInfo_MAXREQUESTEDBANDWIDTHUL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 515");
				}
				else
					sprintf(lMissingAvpInfo, "%s,515", lMissingAvpInfo);
			}
				break;
			case AcceptableServiceInfo_MAXREQUESTEDBANDWIDTHDL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 516");
				}
				else
					sprintf(lMissingAvpInfo, "%s,516", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
