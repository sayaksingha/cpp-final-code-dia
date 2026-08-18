#include "sd/include/TraceData.h"

using namespace SD;
BOOLEAN TraceData::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

TraceData::TraceData()
{
	mTraceReference = NULL;
	mTraceDepth = NULL;
	mTraceNETypeList = NULL;
	mTraceInterfaceList = NULL;
	mTraceEventList = NULL;
	mOMCId = NULL;
	mTraceCollectionEntity = NULL;
	mMDTConfigurationGrp = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<8>(string("01011111"));
	mMandatoryAvpSetVal.reset();
}

TraceData::~TraceData()
{
	if(mTraceReference != NULL)
		delete mTraceReference;
	if(mTraceDepth != NULL)
		delete mTraceDepth;
	if(mTraceNETypeList != NULL)
		delete mTraceNETypeList;
	if(mTraceInterfaceList != NULL)
		delete mTraceInterfaceList;
	if(mTraceEventList != NULL)
		delete mTraceEventList;
	if(mOMCId != NULL)
		delete mOMCId;
	if(mTraceCollectionEntity != NULL)
		delete mTraceCollectionEntity;
	if(mMDTConfigurationGrp != NULL)
		delete mMDTConfigurationGrp;
}

OctetString* TraceData::setTraceReference(){
	mMandatoryAvpSetVal [TraceData_TRACEREFERENCE] = 1;
	if(mTraceReference == NULL)
	{
		mTraceReference = new OctetString();
		mTagsPresent[TraceData_TRACEREFERENCE] = 1;
		return mTraceReference;
	}
	return mTraceReference;
}

void TraceData::resetTraceReference(){
	mTagsPresent[TraceData_TRACEREFERENCE] = 0;
	if(mTraceReference != NULL)
	{
		delete mTraceReference; 
		mTraceReference = NULL;
	}
}

TraceDepth* TraceData::setTraceDepth(){
	mMandatoryAvpSetVal [TraceData_TRACEDEPTH] = 1;
	if(mTraceDepth == NULL)
	{
		mTraceDepth = new TraceDepth();
		mTagsPresent[TraceData_TRACEDEPTH] = 1;
		return mTraceDepth;
	}
	return mTraceDepth;
}

void TraceData::resetTraceDepth(){
	mTagsPresent[TraceData_TRACEDEPTH] = 0;
	if(mTraceDepth != NULL)
	{
		delete mTraceDepth; 
		mTraceDepth = NULL;
	}
}

OctetString* TraceData::setTraceNETypeList(){
	mMandatoryAvpSetVal [TraceData_TRACENETYPELIST] = 1;
	if(mTraceNETypeList == NULL)
	{
		mTraceNETypeList = new OctetString();
		mTagsPresent[TraceData_TRACENETYPELIST] = 1;
		return mTraceNETypeList;
	}
	return mTraceNETypeList;
}

void TraceData::resetTraceNETypeList(){
	mTagsPresent[TraceData_TRACENETYPELIST] = 0;
	if(mTraceNETypeList != NULL)
	{
		delete mTraceNETypeList; 
		mTraceNETypeList = NULL;
	}
}

OctetString* TraceData::setTraceInterfaceList(){
	mMandatoryAvpSetVal [TraceData_TRACEINTERFACELIST] = 1;
	if(mTraceInterfaceList == NULL)
	{
		mTraceInterfaceList = new OctetString();
		mTagsPresent[TraceData_TRACEINTERFACELIST] = 1;
		return mTraceInterfaceList;
	}
	return mTraceInterfaceList;
}

void TraceData::resetTraceInterfaceList(){
	mTagsPresent[TraceData_TRACEINTERFACELIST] = 0;
	if(mTraceInterfaceList != NULL)
	{
		delete mTraceInterfaceList; 
		mTraceInterfaceList = NULL;
	}
}

OctetString* TraceData::setTraceEventList(){
	mMandatoryAvpSetVal [TraceData_TRACEEVENTLIST] = 1;
	if(mTraceEventList == NULL)
	{
		mTraceEventList = new OctetString();
		mTagsPresent[TraceData_TRACEEVENTLIST] = 1;
		return mTraceEventList;
	}
	return mTraceEventList;
}

void TraceData::resetTraceEventList(){
	mTagsPresent[TraceData_TRACEEVENTLIST] = 0;
	if(mTraceEventList != NULL)
	{
		delete mTraceEventList; 
		mTraceEventList = NULL;
	}
}

OctetString* TraceData::setOMCId(){
	if(mOMCId == NULL)
	{
		mOMCId = new OctetString();
		mTagsPresent[TraceData_OMCID] = 1;
		return mOMCId;
	}
	return mOMCId;
}

void TraceData::resetOMCId(){
	mTagsPresent[TraceData_OMCID] = 0;
	if(mOMCId != NULL)
	{
		delete mOMCId; 
		mOMCId = NULL;
	}
}

Address* TraceData::setTraceCollectionEntity(){
	mMandatoryAvpSetVal [TraceData_TRACECOLLECTIONENTITY] = 1;
	if(mTraceCollectionEntity == NULL)
	{
		mTraceCollectionEntity = new Address();
		mTagsPresent[TraceData_TRACECOLLECTIONENTITY] = 1;
		return mTraceCollectionEntity;
	}
	return mTraceCollectionEntity;
}

void TraceData::resetTraceCollectionEntity(){
	mTagsPresent[TraceData_TRACECOLLECTIONENTITY] = 0;
	if(mTraceCollectionEntity != NULL)
	{
		delete mTraceCollectionEntity; 
		mTraceCollectionEntity = NULL;
	}
}

OctetString* TraceData::getTraceReference(){
	if(NULL == mTraceReference) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TraceReference is Null");
		throw lTssDiaMsgException;
	}
	if(!mTraceReference->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mTraceReference->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TraceReference is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mTraceReference->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mTraceReference->Decode(mspByteArray.get(), mTraceReference->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TraceReference")     ;
			throw lTssDiaMsgException;
		}
		mTraceReference->mAvpDecodedFlag = true;
	}
	return mTraceReference;
}

TraceDepth* TraceData::getTraceDepth(){
	if(NULL == mTraceDepth) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TraceDepth is Null");
		throw lTssDiaMsgException;
	}
	if(!mTraceDepth->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mTraceDepth->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TraceDepth is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mTraceDepth->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mTraceDepth->Decode(mspByteArray.get(), mTraceDepth->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TraceDepth")     ;
			throw lTssDiaMsgException;
		}
		mTraceDepth->mAvpDecodedFlag = true;
	}
	return mTraceDepth;
}

OctetString* TraceData::getTraceNETypeList(){
	if(NULL == mTraceNETypeList) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TraceNETypeList is Null");
		throw lTssDiaMsgException;
	}
	if(!mTraceNETypeList->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mTraceNETypeList->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TraceNETypeList is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mTraceNETypeList->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mTraceNETypeList->Decode(mspByteArray.get(), mTraceNETypeList->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TraceNETypeList")     ;
			throw lTssDiaMsgException;
		}
		mTraceNETypeList->mAvpDecodedFlag = true;
	}
	return mTraceNETypeList;
}

OctetString* TraceData::getTraceInterfaceList(){
	if(NULL == mTraceInterfaceList) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TraceInterfaceList is Null");
		throw lTssDiaMsgException;
	}
	if(!mTraceInterfaceList->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mTraceInterfaceList->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TraceInterfaceList is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mTraceInterfaceList->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mTraceInterfaceList->Decode(mspByteArray.get(), mTraceInterfaceList->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TraceInterfaceList")     ;
			throw lTssDiaMsgException;
		}
		mTraceInterfaceList->mAvpDecodedFlag = true;
	}
	return mTraceInterfaceList;
}

OctetString* TraceData::getTraceEventList(){
	if(NULL == mTraceEventList) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TraceEventList is Null");
		throw lTssDiaMsgException;
	}
	if(!mTraceEventList->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mTraceEventList->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TraceEventList is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mTraceEventList->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mTraceEventList->Decode(mspByteArray.get(), mTraceEventList->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TraceEventList")     ;
			throw lTssDiaMsgException;
		}
		mTraceEventList->mAvpDecodedFlag = true;
	}
	return mTraceEventList;
}

OctetString* TraceData::getOMCId(){
	if(NULL == mOMCId) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OMCId is Null");
		throw lTssDiaMsgException;
	}
	if(!mOMCId->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mOMCId->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OMCId is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mOMCId->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mOMCId->Decode(mspByteArray.get(), mOMCId->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OMCId")     ;
			throw lTssDiaMsgException;
		}
		mOMCId->mAvpDecodedFlag = true;
	}
	return mOMCId;
}

Address* TraceData::getTraceCollectionEntity(){
	if(NULL == mTraceCollectionEntity) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TraceCollectionEntity is Null");
		throw lTssDiaMsgException;
	}
	if(!mTraceCollectionEntity->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mTraceCollectionEntity->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TraceCollectionEntity is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mTraceCollectionEntity->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mTraceCollectionEntity->Decode(mspByteArray.get(), mTraceCollectionEntity->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TraceCollectionEntity")     ;
			throw lTssDiaMsgException;
		}
		mTraceCollectionEntity->mAvpDecodedFlag = true;
	}
	return mTraceCollectionEntity;
}

MDTConfiguration* TraceData::getMDTConfiguration()
{
	if(mMDTConfigurationGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MDTConfiguration is Null");
		throw lTssDiaMsgException;
	}
	if(!mMDTConfigurationGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMDTConfigurationGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MDTConfiguration is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMDTConfigurationGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMDTConfigurationGrp->Decode(mspByteArray.get(), mMDTConfigurationGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MDTConfiguration")     ;
			throw lTssDiaMsgException;
		}
		mMDTConfigurationGrp->mAvpDecodedFlag = true;
	}
	return mMDTConfigurationGrp;
}

MDTConfiguration* TraceData::setMDTConfiguration(){
	if(mMDTConfigurationGrp == NULL)
		mMDTConfigurationGrp = new MDTConfiguration();
	mTagsPresent[TraceData_MDTCONFIGURATION] = 1;
	return mMDTConfigurationGrp;
}

void TraceData::resetMDTConfiguration(){
	mTagsPresent[TraceData_MDTCONFIGURATION] = 0;
	if(mMDTConfigurationGrp != NULL)
		delete mMDTConfigurationGrp;
}



int TraceData::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case TraceData_TRACEREFERENCE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1459);
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
					if(!mTraceReference->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mTraceReference->getAvpOffsetLen().first], mTraceReference->getAvpOffsetLen().second);
						array->offset += mTraceReference->getAvpOffsetLen().second;
						array->size += mTraceReference->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mTraceReference->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mTraceReference->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TraceReference");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mTraceReference->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mTraceReference->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TraceReference");
						throw lTssDiaMsgException;
					}
				}
				break;
			case TraceData_TRACEDEPTH:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1462);
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
					if(!mTraceDepth->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mTraceDepth->getAvpOffsetLen().first], mTraceDepth->getAvpOffsetLen().second);
						array->offset += mTraceDepth->getAvpOffsetLen().second;
						array->size += mTraceDepth->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TraceDepth");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mTraceDepth->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TraceDepth");
						throw lTssDiaMsgException;
					}
				}
				break;
			case TraceData_TRACENETYPELIST:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1463);
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
					if(!mTraceNETypeList->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mTraceNETypeList->getAvpOffsetLen().first], mTraceNETypeList->getAvpOffsetLen().second);
						array->offset += mTraceNETypeList->getAvpOffsetLen().second;
						array->size += mTraceNETypeList->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mTraceNETypeList->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mTraceNETypeList->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TraceNETypeList");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mTraceNETypeList->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mTraceNETypeList->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TraceNETypeList");
						throw lTssDiaMsgException;
					}
				}
				break;
			case TraceData_TRACEINTERFACELIST:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1464);
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
					if(!mTraceInterfaceList->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mTraceInterfaceList->getAvpOffsetLen().first], mTraceInterfaceList->getAvpOffsetLen().second);
						array->offset += mTraceInterfaceList->getAvpOffsetLen().second;
						array->size += mTraceInterfaceList->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mTraceInterfaceList->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mTraceInterfaceList->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TraceInterfaceList");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mTraceInterfaceList->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mTraceInterfaceList->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TraceInterfaceList");
						throw lTssDiaMsgException;
					}
				}
				break;
			case TraceData_TRACEEVENTLIST:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1465);
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
					if(!mTraceEventList->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mTraceEventList->getAvpOffsetLen().first], mTraceEventList->getAvpOffsetLen().second);
						array->offset += mTraceEventList->getAvpOffsetLen().second;
						array->size += mTraceEventList->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mTraceEventList->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mTraceEventList->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TraceEventList");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mTraceEventList->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mTraceEventList->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TraceEventList");
						throw lTssDiaMsgException;
					}
				}
				break;
			case TraceData_OMCID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1466);
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
					if(!mOMCId->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mOMCId->getAvpOffsetLen().first], mOMCId->getAvpOffsetLen().second);
						array->offset += mOMCId->getAvpOffsetLen().second;
						array->size += mOMCId->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mOMCId->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mOMCId->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OMCId");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mOMCId->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mOMCId->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OMCId");
						throw lTssDiaMsgException;
					}
				}
				break;
			case TraceData_TRACECOLLECTIONENTITY:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1452);
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
					if(!mTraceCollectionEntity->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mTraceCollectionEntity->getAvpOffsetLen().first], mTraceCollectionEntity->getAvpOffsetLen().second);
						array->offset += mTraceCollectionEntity->getAvpOffsetLen().second;
						array->size += mTraceCollectionEntity->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mTraceCollectionEntity->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mTraceCollectionEntity->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array,TSS_MAX_DIAMETER_TIME_LEN)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TraceCollectionEntity");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mTraceCollectionEntity->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mTraceCollectionEntity->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TraceCollectionEntity");
						throw lTssDiaMsgException;
					}
				}
				break;
			case TraceData_MDTCONFIGURATION:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(1622);
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
				if((this->getMDTConfiguration()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MDTConfiguration");
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


int TraceData::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 1459:
				{
						mMandatoryAvpSetVal [TraceData_TRACEREFERENCE] = 1;
					if( NULL == this->setTraceReference())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TraceReference");
						throw lTssDiaMsgException;
					}
					mTraceReference->setAvpCode(1459);
					mTraceReference->setAvpVendorId(lVenderId);
					mTraceReference->SetDataType((DiameterDataType)5);
					mTraceReference->mspByteArray = mspByteArray;
					mTraceReference->mAvpDecodedFlag = false;
					mTraceReference->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1462:
				{
						mMandatoryAvpSetVal [TraceData_TRACEDEPTH] = 1;
					if( NULL == this->setTraceDepth())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TraceDepth");
						throw lTssDiaMsgException;
					}
					mTraceDepth->setAvpCode(1462);
					mTraceDepth->setAvpVendorId(lVenderId);
					mTraceDepth->SetDataType((DiameterDataType)7);
					mTraceDepth->mspByteArray = mspByteArray;
					mTraceDepth->mAvpDecodedFlag = false;
					mTraceDepth->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1463:
				{
						mMandatoryAvpSetVal [TraceData_TRACENETYPELIST] = 1;
					if( NULL == this->setTraceNETypeList())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TraceNETypeList");
						throw lTssDiaMsgException;
					}
					mTraceNETypeList->setAvpCode(1463);
					mTraceNETypeList->setAvpVendorId(lVenderId);
					mTraceNETypeList->SetDataType((DiameterDataType)5);
					mTraceNETypeList->mspByteArray = mspByteArray;
					mTraceNETypeList->mAvpDecodedFlag = false;
					mTraceNETypeList->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1464:
				{
						mMandatoryAvpSetVal [TraceData_TRACEINTERFACELIST] = 1;
					if( NULL == this->setTraceInterfaceList())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TraceInterfaceList");
						throw lTssDiaMsgException;
					}
					mTraceInterfaceList->setAvpCode(1464);
					mTraceInterfaceList->setAvpVendorId(lVenderId);
					mTraceInterfaceList->SetDataType((DiameterDataType)5);
					mTraceInterfaceList->mspByteArray = mspByteArray;
					mTraceInterfaceList->mAvpDecodedFlag = false;
					mTraceInterfaceList->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1465:
				{
						mMandatoryAvpSetVal [TraceData_TRACEEVENTLIST] = 1;
					if( NULL == this->setTraceEventList())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TraceEventList");
						throw lTssDiaMsgException;
					}
					mTraceEventList->setAvpCode(1465);
					mTraceEventList->setAvpVendorId(lVenderId);
					mTraceEventList->SetDataType((DiameterDataType)5);
					mTraceEventList->mspByteArray = mspByteArray;
					mTraceEventList->mAvpDecodedFlag = false;
					mTraceEventList->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1466:
				{
					if( NULL == this->setOMCId())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OMCId");
						throw lTssDiaMsgException;
					}
					mOMCId->setAvpCode(1466);
					mOMCId->setAvpVendorId(lVenderId);
					mOMCId->SetDataType((DiameterDataType)5);
					mOMCId->mspByteArray = mspByteArray;
					mOMCId->mAvpDecodedFlag = false;
					mOMCId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1452:
				{
						mMandatoryAvpSetVal [TraceData_TRACECOLLECTIONENTITY] = 1;
					if( NULL == this->setTraceCollectionEntity())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TraceCollectionEntity");
						throw lTssDiaMsgException;
					}
					mTraceCollectionEntity->setAvpCode(1452);
					mTraceCollectionEntity->setAvpVendorId(lVenderId);
					mTraceCollectionEntity->SetDataType((DiameterDataType)8);
					mTraceCollectionEntity->mspByteArray = mspByteArray;
					mTraceCollectionEntity->mAvpDecodedFlag = false;
					mTraceCollectionEntity->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1622:
				{
					mTagsPresent[TraceData_MDTCONFIGURATION] = 1;
						if( NULL == this->setMDTConfiguration()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MDTConfiguration");
						throw lTssDiaMsgException;
						}
					mMDTConfigurationGrp->setAvpCode(1622);
					mMDTConfigurationGrp->SetDataType((DiameterDataType)6);
					mMDTConfigurationGrp->mspByteArray = mspByteArray;
					mMDTConfigurationGrp->mAvpDecodedFlag = false;
					mMDTConfigurationGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mMDTConfigurationGrp);
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


DiameterBaseInterface* TraceData::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TraceData")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1459:
			{
				if(mTraceReference != NULL)
					return mTraceReference->Find(array, avpCode);
				else
					return NULL;
			}
			case 1462:
			{
				if(mTraceDepth != NULL)
					return mTraceDepth->Find(array, avpCode);
				else
					return NULL;
			}
			case 1463:
			{
				if(mTraceNETypeList != NULL)
					return mTraceNETypeList->Find(array, avpCode);
				else
					return NULL;
			}
			case 1464:
			{
				if(mTraceInterfaceList != NULL)
					return mTraceInterfaceList->Find(array, avpCode);
				else
					return NULL;
			}
			case 1465:
			{
				if(mTraceEventList != NULL)
					return mTraceEventList->Find(array, avpCode);
				else
					return NULL;
			}
			case 1466:
			{
				if(mOMCId != NULL)
					return mOMCId->Find(array, avpCode);
				else
					return NULL;
			}
			case 1452:
			{
				if(mTraceCollectionEntity != NULL)
					return mTraceCollectionEntity->Find(array, avpCode);
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


BOOLEAN TraceData::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TraceData")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1459:
			{
				if(mTraceReference != NULL)
				{
					DiameterBaseInterface* inf =  mTraceReference->Find(this->mspByteArray.get(), avpCode);
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
			case 1462:
			{
				if(mTraceDepth != NULL)
				{
					DiameterBaseInterface* inf =  mTraceDepth->Find(this->mspByteArray.get(), avpCode);
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
			case 1463:
			{
				if(mTraceNETypeList != NULL)
				{
					DiameterBaseInterface* inf =  mTraceNETypeList->Find(this->mspByteArray.get(), avpCode);
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
			case 1464:
			{
				if(mTraceInterfaceList != NULL)
				{
					DiameterBaseInterface* inf =  mTraceInterfaceList->Find(this->mspByteArray.get(), avpCode);
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
			case 1465:
			{
				if(mTraceEventList != NULL)
				{
					DiameterBaseInterface* inf =  mTraceEventList->Find(this->mspByteArray.get(), avpCode);
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
			case 1466:
			{
				if(mOMCId != NULL)
				{
					DiameterBaseInterface* inf =  mOMCId->Find(this->mspByteArray.get(), avpCode);
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
			case 1452:
			{
				if(mTraceCollectionEntity != NULL)
				{
					DiameterBaseInterface* inf =  mTraceCollectionEntity->Find(this->mspByteArray.get(), avpCode);
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
			case 1622:
			{
				if(mMDTConfigurationGrp != NULL)
				{
						pBaseInterface.push_back(mMDTConfigurationGrp);
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
std::shared_ptr<byteArray> TraceData::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN TraceData::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TraceData")     ;
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
			case 1459:
			{
				if(mTraceReference != NULL)
				{
					DiameterBaseInterface* inf =  mTraceReference->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1462:
			{
				if(mTraceDepth != NULL)
				{
					DiameterBaseInterface* inf =  mTraceDepth->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1463:
			{
				if(mTraceNETypeList != NULL)
				{
					DiameterBaseInterface* inf =  mTraceNETypeList->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1464:
			{
				if(mTraceInterfaceList != NULL)
				{
					DiameterBaseInterface* inf =  mTraceInterfaceList->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1465:
			{
				if(mTraceEventList != NULL)
				{
					DiameterBaseInterface* inf =  mTraceEventList->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1466:
			{
				if(mOMCId != NULL)
				{
					DiameterBaseInterface* inf =  mOMCId->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1452:
			{
				if(mTraceCollectionEntity != NULL)
				{
					DiameterBaseInterface* inf =  mTraceCollectionEntity->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1622:
			{
				if(mMDTConfigurationGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mMDTConfigurationGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mMDTConfigurationGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
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


INT32 TraceData::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 TraceData::getAvpCode()
{
	return mAvpCode;
}
INT32 TraceData::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 TraceData::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 TraceData::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> TraceData::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void TraceData::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case TraceData_TRACEREFERENCE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1459" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "TraceReference" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getTraceReference()->Display(tab+1);
			}
				break;
			case TraceData_TRACEDEPTH:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1462" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "TraceDepth" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getTraceDepth()->Display(tab+1);
			}
				break;
			case TraceData_TRACENETYPELIST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1463" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "TraceNETypeList" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getTraceNETypeList()->Display(tab+1);
			}
				break;
			case TraceData_TRACEINTERFACELIST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1464" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "TraceInterfaceList" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getTraceInterfaceList()->Display(tab+1);
			}
				break;
			case TraceData_TRACEEVENTLIST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1465" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "TraceEventList" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getTraceEventList()->Display(tab+1);
			}
				break;
			case TraceData_OMCID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1466" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OMCId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getOMCId()->Display(tab+1);
			}
				break;
			case TraceData_TRACECOLLECTIONENTITY:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1452" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "TraceCollectionEntity" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getTraceCollectionEntity()->Display(tab+1);
			}
				break;
			case TraceData_MDTCONFIGURATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1622" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MDTConfiguration" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getMDTConfiguration()->Display(tab+1);
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


BOOLEAN TraceData::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<8> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case TraceData_TRACEREFERENCE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1459");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1459", lMissingAvpInfo);
			}
				break;
			case TraceData_TRACEDEPTH:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1462");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1462", lMissingAvpInfo);
			}
				break;
			case TraceData_TRACENETYPELIST:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1463");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1463", lMissingAvpInfo);
			}
				break;
			case TraceData_TRACEINTERFACELIST:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1464");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1464", lMissingAvpInfo);
			}
				break;
			case TraceData_TRACEEVENTLIST:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1465");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1465", lMissingAvpInfo);
			}
				break;
			case TraceData_OMCID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1466");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1466", lMissingAvpInfo);
			}
				break;
			case TraceData_TRACECOLLECTIONENTITY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1452");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1452", lMissingAvpInfo);
			}
				break;
			case TraceData_MDTCONFIGURATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1622");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1622", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
