#include "sd/include/AllocationRetentionPriority.h"

using namespace SD;
BOOLEAN AllocationRetentionPriority::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

AllocationRetentionPriority::AllocationRetentionPriority()
{
	mPriorityLevel = NULL;
	mPreemptionCapability = NULL;
	mPreemptionVulnerability = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<3>(string("000"));
	mMandatoryAvpSetVal.reset();
}

AllocationRetentionPriority::~AllocationRetentionPriority()
{
	if(mPriorityLevel != NULL)
		delete mPriorityLevel;
	if(mPreemptionCapability != NULL)
		delete mPreemptionCapability;
	if(mPreemptionVulnerability != NULL)
		delete mPreemptionVulnerability;
}

Unsigned32* AllocationRetentionPriority::setPriorityLevel(){
	if(mPriorityLevel == NULL)
	{
		mPriorityLevel = new Unsigned32();
		mTagsPresent[AllocationRetentionPriority_PRIORITYLEVEL] = 1;
		return mPriorityLevel;
	}
	return mPriorityLevel;
}

void AllocationRetentionPriority::resetPriorityLevel(){
	mTagsPresent[AllocationRetentionPriority_PRIORITYLEVEL] = 0;
	if(mPriorityLevel != NULL)
	{
		delete mPriorityLevel; 
		mPriorityLevel = NULL;
	}
}

PreemptionCapability* AllocationRetentionPriority::setPreemptionCapability(){
	if(mPreemptionCapability == NULL)
	{
		mPreemptionCapability = new PreemptionCapability();
		mTagsPresent[AllocationRetentionPriority_PREEMPTIONCAPABILITY] = 1;
		return mPreemptionCapability;
	}
	return mPreemptionCapability;
}

void AllocationRetentionPriority::resetPreemptionCapability(){
	mTagsPresent[AllocationRetentionPriority_PREEMPTIONCAPABILITY] = 0;
	if(mPreemptionCapability != NULL)
	{
		delete mPreemptionCapability; 
		mPreemptionCapability = NULL;
	}
}

PreemptionVulnerability* AllocationRetentionPriority::setPreemptionVulnerability(){
	if(mPreemptionVulnerability == NULL)
	{
		mPreemptionVulnerability = new PreemptionVulnerability();
		mTagsPresent[AllocationRetentionPriority_PREEMPTIONVULNERABILITY] = 1;
		return mPreemptionVulnerability;
	}
	return mPreemptionVulnerability;
}

void AllocationRetentionPriority::resetPreemptionVulnerability(){
	mTagsPresent[AllocationRetentionPriority_PREEMPTIONVULNERABILITY] = 0;
	if(mPreemptionVulnerability != NULL)
	{
		delete mPreemptionVulnerability; 
		mPreemptionVulnerability = NULL;
	}
}

Unsigned32* AllocationRetentionPriority::getPriorityLevel(){
	if(NULL == mPriorityLevel) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PriorityLevel is Null");
		throw lTssDiaMsgException;
	}
	if(!mPriorityLevel->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPriorityLevel->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PriorityLevel is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPriorityLevel->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPriorityLevel->Decode(mspByteArray.get(), mPriorityLevel->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PriorityLevel")     ;
			throw lTssDiaMsgException;
		}
		mPriorityLevel->mAvpDecodedFlag = true;
	}
	return mPriorityLevel;
}

PreemptionCapability* AllocationRetentionPriority::getPreemptionCapability(){
	if(NULL == mPreemptionCapability) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PreemptionCapability is Null");
		throw lTssDiaMsgException;
	}
	if(!mPreemptionCapability->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPreemptionCapability->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PreemptionCapability is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPreemptionCapability->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPreemptionCapability->Decode(mspByteArray.get(), mPreemptionCapability->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PreemptionCapability")     ;
			throw lTssDiaMsgException;
		}
		mPreemptionCapability->mAvpDecodedFlag = true;
	}
	return mPreemptionCapability;
}

PreemptionVulnerability* AllocationRetentionPriority::getPreemptionVulnerability(){
	if(NULL == mPreemptionVulnerability) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PreemptionVulnerability is Null");
		throw lTssDiaMsgException;
	}
	if(!mPreemptionVulnerability->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPreemptionVulnerability->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PreemptionVulnerability is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPreemptionVulnerability->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPreemptionVulnerability->Decode(mspByteArray.get(), mPreemptionVulnerability->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PreemptionVulnerability")     ;
			throw lTssDiaMsgException;
		}
		mPreemptionVulnerability->mAvpDecodedFlag = true;
	}
	return mPreemptionVulnerability;
}



int AllocationRetentionPriority::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case AllocationRetentionPriority_PRIORITYLEVEL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1046);
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
					if(!mPriorityLevel->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mPriorityLevel->getAvpOffsetLen().first], mPriorityLevel->getAvpOffsetLen().second);
						array->offset += mPriorityLevel->getAvpOffsetLen().second;
						array->size += mPriorityLevel->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PriorityLevel");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mPriorityLevel->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PriorityLevel");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AllocationRetentionPriority_PREEMPTIONCAPABILITY:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1047);
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
					if(!mPreemptionCapability->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mPreemptionCapability->getAvpOffsetLen().first], mPreemptionCapability->getAvpOffsetLen().second);
						array->offset += mPreemptionCapability->getAvpOffsetLen().second;
						array->size += mPreemptionCapability->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PreemptionCapability");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mPreemptionCapability->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PreemptionCapability");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AllocationRetentionPriority_PREEMPTIONVULNERABILITY:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1048);
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
					if(!mPreemptionVulnerability->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mPreemptionVulnerability->getAvpOffsetLen().first], mPreemptionVulnerability->getAvpOffsetLen().second);
						array->offset += mPreemptionVulnerability->getAvpOffsetLen().second;
						array->size += mPreemptionVulnerability->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PreemptionVulnerability");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mPreemptionVulnerability->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PreemptionVulnerability");
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


int AllocationRetentionPriority::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 1046:
				{
					if( NULL == this->setPriorityLevel())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PriorityLevel");
						throw lTssDiaMsgException;
					}
					mPriorityLevel->setAvpCode(1046);
					mPriorityLevel->setAvpVendorId(lVenderId);
					mPriorityLevel->SetDataType((DiameterDataType)3);
					mPriorityLevel->mspByteArray = mspByteArray;
					mPriorityLevel->mAvpDecodedFlag = false;
					mPriorityLevel->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1047:
				{
					if( NULL == this->setPreemptionCapability())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PreemptionCapability");
						throw lTssDiaMsgException;
					}
					mPreemptionCapability->setAvpCode(1047);
					mPreemptionCapability->setAvpVendorId(lVenderId);
					mPreemptionCapability->SetDataType((DiameterDataType)7);
					mPreemptionCapability->mspByteArray = mspByteArray;
					mPreemptionCapability->mAvpDecodedFlag = false;
					mPreemptionCapability->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1048:
				{
					if( NULL == this->setPreemptionVulnerability())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PreemptionVulnerability");
						throw lTssDiaMsgException;
					}
					mPreemptionVulnerability->setAvpCode(1048);
					mPreemptionVulnerability->setAvpVendorId(lVenderId);
					mPreemptionVulnerability->SetDataType((DiameterDataType)7);
					mPreemptionVulnerability->mspByteArray = mspByteArray;
					mPreemptionVulnerability->mAvpDecodedFlag = false;
					mPreemptionVulnerability->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* AllocationRetentionPriority::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AllocationRetentionPriority")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1046:
			{
				if(mPriorityLevel != NULL)
					return mPriorityLevel->Find(array, avpCode);
				else
					return NULL;
			}
			case 1047:
			{
				if(mPreemptionCapability != NULL)
					return mPreemptionCapability->Find(array, avpCode);
				else
					return NULL;
			}
			case 1048:
			{
				if(mPreemptionVulnerability != NULL)
					return mPreemptionVulnerability->Find(array, avpCode);
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


BOOLEAN AllocationRetentionPriority::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AllocationRetentionPriority")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1046:
			{
				if(mPriorityLevel != NULL)
				{
					DiameterBaseInterface* inf =  mPriorityLevel->Find(this->mspByteArray.get(), avpCode);
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
			case 1047:
			{
				if(mPreemptionCapability != NULL)
				{
					DiameterBaseInterface* inf =  mPreemptionCapability->Find(this->mspByteArray.get(), avpCode);
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
			case 1048:
			{
				if(mPreemptionVulnerability != NULL)
				{
					DiameterBaseInterface* inf =  mPreemptionVulnerability->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> AllocationRetentionPriority::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN AllocationRetentionPriority::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AllocationRetentionPriority")     ;
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
			case 1046:
			{
				if(mPriorityLevel != NULL)
				{
					DiameterBaseInterface* inf =  mPriorityLevel->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1047:
			{
				if(mPreemptionCapability != NULL)
				{
					DiameterBaseInterface* inf =  mPreemptionCapability->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1048:
			{
				if(mPreemptionVulnerability != NULL)
				{
					DiameterBaseInterface* inf =  mPreemptionVulnerability->Find(this->mspByteArray.get(), avpCode);
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


INT32 AllocationRetentionPriority::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 AllocationRetentionPriority::getAvpCode()
{
	return mAvpCode;
}
INT32 AllocationRetentionPriority::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 AllocationRetentionPriority::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 AllocationRetentionPriority::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> AllocationRetentionPriority::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void AllocationRetentionPriority::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case AllocationRetentionPriority_PRIORITYLEVEL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1046" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PriorityLevel" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getPriorityLevel()->Display(tab+1);
			}
				break;
			case AllocationRetentionPriority_PREEMPTIONCAPABILITY:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1047" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PreemptionCapability" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getPreemptionCapability()->Display(tab+1);
			}
				break;
			case AllocationRetentionPriority_PREEMPTIONVULNERABILITY:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1048" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PreemptionVulnerability" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getPreemptionVulnerability()->Display(tab+1);
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


BOOLEAN AllocationRetentionPriority::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<3> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case AllocationRetentionPriority_PRIORITYLEVEL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1046");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1046", lMissingAvpInfo);
			}
				break;
			case AllocationRetentionPriority_PREEMPTIONCAPABILITY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1047");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1047", lMissingAvpInfo);
			}
				break;
			case AllocationRetentionPriority_PREEMPTIONVULNERABILITY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1048");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1048", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
