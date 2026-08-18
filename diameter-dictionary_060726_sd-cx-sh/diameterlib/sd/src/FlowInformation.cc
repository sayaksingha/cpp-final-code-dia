#include "sd/include/FlowInformation.h"

using namespace SD;
BOOLEAN FlowInformation::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

FlowInformation::FlowInformation()
{
	mFlowDescription = NULL;
	mPacketFilterIdentifier = NULL;
	mPacketFilterUsage = NULL;
	mToSTrafficClass = NULL;
	mSecurityParameterIndex = NULL;
	mFlowLabel = NULL;
	mFlowDirection = NULL;
	mRoutingRuleIdentifier = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<8>(string("00001001"));
	mMandatoryAvpSetVal.reset();
}

FlowInformation::~FlowInformation()
{
	if(mFlowDescription != NULL)
		delete mFlowDescription;
	if(mPacketFilterIdentifier != NULL)
		delete mPacketFilterIdentifier;
	if(mPacketFilterUsage != NULL)
		delete mPacketFilterUsage;
	if(mToSTrafficClass != NULL)
		delete mToSTrafficClass;
	if(mSecurityParameterIndex != NULL)
		delete mSecurityParameterIndex;
	if(mFlowLabel != NULL)
		delete mFlowLabel;
	if(mFlowDirection != NULL)
		delete mFlowDirection;
	if(mRoutingRuleIdentifier != NULL)
		delete mRoutingRuleIdentifier;
}

OctetString* FlowInformation::setFlowDescription(){
	mMandatoryAvpSetVal [FlowInformation_FLOWDESCRIPTION] = 1;
	if(mFlowDescription == NULL)
	{
		mFlowDescription = new OctetString();
		mTagsPresent[FlowInformation_FLOWDESCRIPTION] = 1;
		return mFlowDescription;
	}
	return mFlowDescription;
}

void FlowInformation::resetFlowDescription(){
	mTagsPresent[FlowInformation_FLOWDESCRIPTION] = 0;
	if(mFlowDescription != NULL)
	{
		delete mFlowDescription; 
		mFlowDescription = NULL;
	}
}

OctetString* FlowInformation::setPacketFilterIdentifier(){
	if(mPacketFilterIdentifier == NULL)
	{
		mPacketFilterIdentifier = new OctetString();
		mTagsPresent[FlowInformation_PACKETFILTERIDENTIFIER] = 1;
		return mPacketFilterIdentifier;
	}
	return mPacketFilterIdentifier;
}

void FlowInformation::resetPacketFilterIdentifier(){
	mTagsPresent[FlowInformation_PACKETFILTERIDENTIFIER] = 0;
	if(mPacketFilterIdentifier != NULL)
	{
		delete mPacketFilterIdentifier; 
		mPacketFilterIdentifier = NULL;
	}
}

PacketFilterUsage* FlowInformation::setPacketFilterUsage(){
	if(mPacketFilterUsage == NULL)
	{
		mPacketFilterUsage = new PacketFilterUsage();
		mTagsPresent[FlowInformation_PACKETFILTERUSAGE] = 1;
		return mPacketFilterUsage;
	}
	return mPacketFilterUsage;
}

void FlowInformation::resetPacketFilterUsage(){
	mTagsPresent[FlowInformation_PACKETFILTERUSAGE] = 0;
	if(mPacketFilterUsage != NULL)
	{
		delete mPacketFilterUsage; 
		mPacketFilterUsage = NULL;
	}
}

OctetString* FlowInformation::setToSTrafficClass(){
	mMandatoryAvpSetVal [FlowInformation_TOSTRAFFICCLASS] = 1;
	if(mToSTrafficClass == NULL)
	{
		mToSTrafficClass = new OctetString();
		mTagsPresent[FlowInformation_TOSTRAFFICCLASS] = 1;
		return mToSTrafficClass;
	}
	return mToSTrafficClass;
}

void FlowInformation::resetToSTrafficClass(){
	mTagsPresent[FlowInformation_TOSTRAFFICCLASS] = 0;
	if(mToSTrafficClass != NULL)
	{
		delete mToSTrafficClass; 
		mToSTrafficClass = NULL;
	}
}

OctetString* FlowInformation::setSecurityParameterIndex(){
	if(mSecurityParameterIndex == NULL)
	{
		mSecurityParameterIndex = new OctetString();
		mTagsPresent[FlowInformation_SECURITYPARAMETERINDEX] = 1;
		return mSecurityParameterIndex;
	}
	return mSecurityParameterIndex;
}

void FlowInformation::resetSecurityParameterIndex(){
	mTagsPresent[FlowInformation_SECURITYPARAMETERINDEX] = 0;
	if(mSecurityParameterIndex != NULL)
	{
		delete mSecurityParameterIndex; 
		mSecurityParameterIndex = NULL;
	}
}

OctetString* FlowInformation::setFlowLabel(){
	if(mFlowLabel == NULL)
	{
		mFlowLabel = new OctetString();
		mTagsPresent[FlowInformation_FLOWLABEL] = 1;
		return mFlowLabel;
	}
	return mFlowLabel;
}

void FlowInformation::resetFlowLabel(){
	mTagsPresent[FlowInformation_FLOWLABEL] = 0;
	if(mFlowLabel != NULL)
	{
		delete mFlowLabel; 
		mFlowLabel = NULL;
	}
}

FlowDirection* FlowInformation::setFlowDirection(){
	if(mFlowDirection == NULL)
	{
		mFlowDirection = new FlowDirection();
		mTagsPresent[FlowInformation_FLOWDIRECTION] = 1;
		return mFlowDirection;
	}
	return mFlowDirection;
}

void FlowInformation::resetFlowDirection(){
	mTagsPresent[FlowInformation_FLOWDIRECTION] = 0;
	if(mFlowDirection != NULL)
	{
		delete mFlowDirection; 
		mFlowDirection = NULL;
	}
}

OctetString* FlowInformation::setRoutingRuleIdentifier(){
	if(mRoutingRuleIdentifier == NULL)
	{
		mRoutingRuleIdentifier = new OctetString();
		mTagsPresent[FlowInformation_ROUTINGRULEIDENTIFIER] = 1;
		return mRoutingRuleIdentifier;
	}
	return mRoutingRuleIdentifier;
}

void FlowInformation::resetRoutingRuleIdentifier(){
	mTagsPresent[FlowInformation_ROUTINGRULEIDENTIFIER] = 0;
	if(mRoutingRuleIdentifier != NULL)
	{
		delete mRoutingRuleIdentifier; 
		mRoutingRuleIdentifier = NULL;
	}
}

OctetString* FlowInformation::getFlowDescription(){
	if(NULL == mFlowDescription) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowDescription is Null");
		throw lTssDiaMsgException;
	}
	if(!mFlowDescription->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mFlowDescription->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowDescription is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mFlowDescription->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mFlowDescription->Decode(mspByteArray.get(), mFlowDescription->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowDescription")     ;
			throw lTssDiaMsgException;
		}
		mFlowDescription->mAvpDecodedFlag = true;
	}
	return mFlowDescription;
}

OctetString* FlowInformation::getPacketFilterIdentifier(){
	if(NULL == mPacketFilterIdentifier) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PacketFilterIdentifier is Null");
		throw lTssDiaMsgException;
	}
	if(!mPacketFilterIdentifier->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPacketFilterIdentifier->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PacketFilterIdentifier is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPacketFilterIdentifier->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPacketFilterIdentifier->Decode(mspByteArray.get(), mPacketFilterIdentifier->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PacketFilterIdentifier")     ;
			throw lTssDiaMsgException;
		}
		mPacketFilterIdentifier->mAvpDecodedFlag = true;
	}
	return mPacketFilterIdentifier;
}

PacketFilterUsage* FlowInformation::getPacketFilterUsage(){
	if(NULL == mPacketFilterUsage) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PacketFilterUsage is Null");
		throw lTssDiaMsgException;
	}
	if(!mPacketFilterUsage->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPacketFilterUsage->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PacketFilterUsage is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPacketFilterUsage->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPacketFilterUsage->Decode(mspByteArray.get(), mPacketFilterUsage->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PacketFilterUsage")     ;
			throw lTssDiaMsgException;
		}
		mPacketFilterUsage->mAvpDecodedFlag = true;
	}
	return mPacketFilterUsage;
}

OctetString* FlowInformation::getToSTrafficClass(){
	if(NULL == mToSTrafficClass) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ToSTrafficClass is Null");
		throw lTssDiaMsgException;
	}
	if(!mToSTrafficClass->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mToSTrafficClass->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ToSTrafficClass is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mToSTrafficClass->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mToSTrafficClass->Decode(mspByteArray.get(), mToSTrafficClass->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ToSTrafficClass")     ;
			throw lTssDiaMsgException;
		}
		mToSTrafficClass->mAvpDecodedFlag = true;
	}
	return mToSTrafficClass;
}

OctetString* FlowInformation::getSecurityParameterIndex(){
	if(NULL == mSecurityParameterIndex) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SecurityParameterIndex is Null");
		throw lTssDiaMsgException;
	}
	if(!mSecurityParameterIndex->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSecurityParameterIndex->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SecurityParameterIndex is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSecurityParameterIndex->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSecurityParameterIndex->Decode(mspByteArray.get(), mSecurityParameterIndex->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SecurityParameterIndex")     ;
			throw lTssDiaMsgException;
		}
		mSecurityParameterIndex->mAvpDecodedFlag = true;
	}
	return mSecurityParameterIndex;
}

OctetString* FlowInformation::getFlowLabel(){
	if(NULL == mFlowLabel) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowLabel is Null");
		throw lTssDiaMsgException;
	}
	if(!mFlowLabel->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mFlowLabel->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowLabel is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mFlowLabel->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mFlowLabel->Decode(mspByteArray.get(), mFlowLabel->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowLabel")     ;
			throw lTssDiaMsgException;
		}
		mFlowLabel->mAvpDecodedFlag = true;
	}
	return mFlowLabel;
}

FlowDirection* FlowInformation::getFlowDirection(){
	if(NULL == mFlowDirection) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowDirection is Null");
		throw lTssDiaMsgException;
	}
	if(!mFlowDirection->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mFlowDirection->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowDirection is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mFlowDirection->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mFlowDirection->Decode(mspByteArray.get(), mFlowDirection->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowDirection")     ;
			throw lTssDiaMsgException;
		}
		mFlowDirection->mAvpDecodedFlag = true;
	}
	return mFlowDirection;
}

OctetString* FlowInformation::getRoutingRuleIdentifier(){
	if(NULL == mRoutingRuleIdentifier) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RoutingRuleIdentifier is Null");
		throw lTssDiaMsgException;
	}
	if(!mRoutingRuleIdentifier->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRoutingRuleIdentifier->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RoutingRuleIdentifier is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRoutingRuleIdentifier->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRoutingRuleIdentifier->Decode(mspByteArray.get(), mRoutingRuleIdentifier->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RoutingRuleIdentifier")     ;
			throw lTssDiaMsgException;
		}
		mRoutingRuleIdentifier->mAvpDecodedFlag = true;
	}
	return mRoutingRuleIdentifier;
}



int FlowInformation::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case FlowInformation_FLOWDESCRIPTION:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(507);
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
					if(!mFlowDescription->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mFlowDescription->getAvpOffsetLen().first], mFlowDescription->getAvpOffsetLen().second);
						array->offset += mFlowDescription->getAvpOffsetLen().second;
						array->size += mFlowDescription->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mFlowDescription->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mFlowDescription->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FlowDescription");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mFlowDescription->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mFlowDescription->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FlowDescription");
						throw lTssDiaMsgException;
					}
				}
				break;
			case FlowInformation_PACKETFILTERIDENTIFIER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1060);
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
					if(!mPacketFilterIdentifier->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mPacketFilterIdentifier->getAvpOffsetLen().first], mPacketFilterIdentifier->getAvpOffsetLen().second);
						array->offset += mPacketFilterIdentifier->getAvpOffsetLen().second;
						array->size += mPacketFilterIdentifier->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mPacketFilterIdentifier->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mPacketFilterIdentifier->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PacketFilterIdentifier");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mPacketFilterIdentifier->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mPacketFilterIdentifier->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PacketFilterIdentifier");
						throw lTssDiaMsgException;
					}
				}
				break;
			case FlowInformation_PACKETFILTERUSAGE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1072);
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
					if(!mPacketFilterUsage->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mPacketFilterUsage->getAvpOffsetLen().first], mPacketFilterUsage->getAvpOffsetLen().second);
						array->offset += mPacketFilterUsage->getAvpOffsetLen().second;
						array->size += mPacketFilterUsage->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PacketFilterUsage");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mPacketFilterUsage->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PacketFilterUsage");
						throw lTssDiaMsgException;
					}
				}
				break;
			case FlowInformation_TOSTRAFFICCLASS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1014);
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
					if(!mToSTrafficClass->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mToSTrafficClass->getAvpOffsetLen().first], mToSTrafficClass->getAvpOffsetLen().second);
						array->offset += mToSTrafficClass->getAvpOffsetLen().second;
						array->size += mToSTrafficClass->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mToSTrafficClass->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mToSTrafficClass->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ToSTrafficClass");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mToSTrafficClass->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mToSTrafficClass->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ToSTrafficClass");
						throw lTssDiaMsgException;
					}
				}
				break;
			case FlowInformation_SECURITYPARAMETERINDEX:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1056);
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
					if(!mSecurityParameterIndex->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSecurityParameterIndex->getAvpOffsetLen().first], mSecurityParameterIndex->getAvpOffsetLen().second);
						array->offset += mSecurityParameterIndex->getAvpOffsetLen().second;
						array->size += mSecurityParameterIndex->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mSecurityParameterIndex->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mSecurityParameterIndex->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SecurityParameterIndex");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mSecurityParameterIndex->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mSecurityParameterIndex->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SecurityParameterIndex");
						throw lTssDiaMsgException;
					}
				}
				break;
			case FlowInformation_FLOWLABEL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1057);
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
					if(!mFlowLabel->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mFlowLabel->getAvpOffsetLen().first], mFlowLabel->getAvpOffsetLen().second);
						array->offset += mFlowLabel->getAvpOffsetLen().second;
						array->size += mFlowLabel->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mFlowLabel->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mFlowLabel->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FlowLabel");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mFlowLabel->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mFlowLabel->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FlowLabel");
						throw lTssDiaMsgException;
					}
				}
				break;
			case FlowInformation_FLOWDIRECTION:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1080);
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
					if(!mFlowDirection->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mFlowDirection->getAvpOffsetLen().first], mFlowDirection->getAvpOffsetLen().second);
						array->offset += mFlowDirection->getAvpOffsetLen().second;
						array->size += mFlowDirection->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FlowDirection");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mFlowDirection->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FlowDirection");
						throw lTssDiaMsgException;
					}
				}
				break;
			case FlowInformation_ROUTINGRULEIDENTIFIER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1077);
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
					if(!mRoutingRuleIdentifier->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRoutingRuleIdentifier->getAvpOffsetLen().first], mRoutingRuleIdentifier->getAvpOffsetLen().second);
						array->offset += mRoutingRuleIdentifier->getAvpOffsetLen().second;
						array->size += mRoutingRuleIdentifier->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mRoutingRuleIdentifier->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mRoutingRuleIdentifier->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RoutingRuleIdentifier");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mRoutingRuleIdentifier->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mRoutingRuleIdentifier->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RoutingRuleIdentifier");
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


int FlowInformation::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 507:
				{
						mMandatoryAvpSetVal [FlowInformation_FLOWDESCRIPTION] = 1;
					if( NULL == this->setFlowDescription())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowDescription");
						throw lTssDiaMsgException;
					}
					mFlowDescription->setAvpCode(507);
					mFlowDescription->setAvpVendorId(lVenderId);
					mFlowDescription->SetDataType((DiameterDataType)5);
					mFlowDescription->mspByteArray = mspByteArray;
					mFlowDescription->mAvpDecodedFlag = false;
					mFlowDescription->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1060:
				{
					if( NULL == this->setPacketFilterIdentifier())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PacketFilterIdentifier");
						throw lTssDiaMsgException;
					}
					mPacketFilterIdentifier->setAvpCode(1060);
					mPacketFilterIdentifier->setAvpVendorId(lVenderId);
					mPacketFilterIdentifier->SetDataType((DiameterDataType)5);
					mPacketFilterIdentifier->mspByteArray = mspByteArray;
					mPacketFilterIdentifier->mAvpDecodedFlag = false;
					mPacketFilterIdentifier->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1072:
				{
					if( NULL == this->setPacketFilterUsage())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PacketFilterUsage");
						throw lTssDiaMsgException;
					}
					mPacketFilterUsage->setAvpCode(1072);
					mPacketFilterUsage->setAvpVendorId(lVenderId);
					mPacketFilterUsage->SetDataType((DiameterDataType)7);
					mPacketFilterUsage->mspByteArray = mspByteArray;
					mPacketFilterUsage->mAvpDecodedFlag = false;
					mPacketFilterUsage->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1014:
				{
						mMandatoryAvpSetVal [FlowInformation_TOSTRAFFICCLASS] = 1;
					if( NULL == this->setToSTrafficClass())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ToSTrafficClass");
						throw lTssDiaMsgException;
					}
					mToSTrafficClass->setAvpCode(1014);
					mToSTrafficClass->setAvpVendorId(lVenderId);
					mToSTrafficClass->SetDataType((DiameterDataType)5);
					mToSTrafficClass->mspByteArray = mspByteArray;
					mToSTrafficClass->mAvpDecodedFlag = false;
					mToSTrafficClass->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1056:
				{
					if( NULL == this->setSecurityParameterIndex())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SecurityParameterIndex");
						throw lTssDiaMsgException;
					}
					mSecurityParameterIndex->setAvpCode(1056);
					mSecurityParameterIndex->setAvpVendorId(lVenderId);
					mSecurityParameterIndex->SetDataType((DiameterDataType)5);
					mSecurityParameterIndex->mspByteArray = mspByteArray;
					mSecurityParameterIndex->mAvpDecodedFlag = false;
					mSecurityParameterIndex->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1057:
				{
					if( NULL == this->setFlowLabel())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowLabel");
						throw lTssDiaMsgException;
					}
					mFlowLabel->setAvpCode(1057);
					mFlowLabel->setAvpVendorId(lVenderId);
					mFlowLabel->SetDataType((DiameterDataType)5);
					mFlowLabel->mspByteArray = mspByteArray;
					mFlowLabel->mAvpDecodedFlag = false;
					mFlowLabel->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1080:
				{
					if( NULL == this->setFlowDirection())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowDirection");
						throw lTssDiaMsgException;
					}
					mFlowDirection->setAvpCode(1080);
					mFlowDirection->setAvpVendorId(lVenderId);
					mFlowDirection->SetDataType((DiameterDataType)7);
					mFlowDirection->mspByteArray = mspByteArray;
					mFlowDirection->mAvpDecodedFlag = false;
					mFlowDirection->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1077:
				{
					if( NULL == this->setRoutingRuleIdentifier())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RoutingRuleIdentifier");
						throw lTssDiaMsgException;
					}
					mRoutingRuleIdentifier->setAvpCode(1077);
					mRoutingRuleIdentifier->setAvpVendorId(lVenderId);
					mRoutingRuleIdentifier->SetDataType((DiameterDataType)5);
					mRoutingRuleIdentifier->mspByteArray = mspByteArray;
					mRoutingRuleIdentifier->mAvpDecodedFlag = false;
					mRoutingRuleIdentifier->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* FlowInformation::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowInformation")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 507:
			{
				if(mFlowDescription != NULL)
					return mFlowDescription->Find(array, avpCode);
				else
					return NULL;
			}
			case 1060:
			{
				if(mPacketFilterIdentifier != NULL)
					return mPacketFilterIdentifier->Find(array, avpCode);
				else
					return NULL;
			}
			case 1072:
			{
				if(mPacketFilterUsage != NULL)
					return mPacketFilterUsage->Find(array, avpCode);
				else
					return NULL;
			}
			case 1014:
			{
				if(mToSTrafficClass != NULL)
					return mToSTrafficClass->Find(array, avpCode);
				else
					return NULL;
			}
			case 1056:
			{
				if(mSecurityParameterIndex != NULL)
					return mSecurityParameterIndex->Find(array, avpCode);
				else
					return NULL;
			}
			case 1057:
			{
				if(mFlowLabel != NULL)
					return mFlowLabel->Find(array, avpCode);
				else
					return NULL;
			}
			case 1080:
			{
				if(mFlowDirection != NULL)
					return mFlowDirection->Find(array, avpCode);
				else
					return NULL;
			}
			case 1077:
			{
				if(mRoutingRuleIdentifier != NULL)
					return mRoutingRuleIdentifier->Find(array, avpCode);
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


BOOLEAN FlowInformation::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowInformation")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 507:
			{
				if(mFlowDescription != NULL)
				{
					DiameterBaseInterface* inf =  mFlowDescription->Find(this->mspByteArray.get(), avpCode);
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
			case 1060:
			{
				if(mPacketFilterIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mPacketFilterIdentifier->Find(this->mspByteArray.get(), avpCode);
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
			case 1072:
			{
				if(mPacketFilterUsage != NULL)
				{
					DiameterBaseInterface* inf =  mPacketFilterUsage->Find(this->mspByteArray.get(), avpCode);
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
			case 1014:
			{
				if(mToSTrafficClass != NULL)
				{
					DiameterBaseInterface* inf =  mToSTrafficClass->Find(this->mspByteArray.get(), avpCode);
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
			case 1056:
			{
				if(mSecurityParameterIndex != NULL)
				{
					DiameterBaseInterface* inf =  mSecurityParameterIndex->Find(this->mspByteArray.get(), avpCode);
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
			case 1057:
			{
				if(mFlowLabel != NULL)
				{
					DiameterBaseInterface* inf =  mFlowLabel->Find(this->mspByteArray.get(), avpCode);
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
			case 1080:
			{
				if(mFlowDirection != NULL)
				{
					DiameterBaseInterface* inf =  mFlowDirection->Find(this->mspByteArray.get(), avpCode);
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
			case 1077:
			{
				if(mRoutingRuleIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mRoutingRuleIdentifier->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> FlowInformation::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN FlowInformation::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowInformation")     ;
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
			case 507:
			{
				if(mFlowDescription != NULL)
				{
					DiameterBaseInterface* inf =  mFlowDescription->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1060:
			{
				if(mPacketFilterIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mPacketFilterIdentifier->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1072:
			{
				if(mPacketFilterUsage != NULL)
				{
					DiameterBaseInterface* inf =  mPacketFilterUsage->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1014:
			{
				if(mToSTrafficClass != NULL)
				{
					DiameterBaseInterface* inf =  mToSTrafficClass->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1056:
			{
				if(mSecurityParameterIndex != NULL)
				{
					DiameterBaseInterface* inf =  mSecurityParameterIndex->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1057:
			{
				if(mFlowLabel != NULL)
				{
					DiameterBaseInterface* inf =  mFlowLabel->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1080:
			{
				if(mFlowDirection != NULL)
				{
					DiameterBaseInterface* inf =  mFlowDirection->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1077:
			{
				if(mRoutingRuleIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mRoutingRuleIdentifier->Find(this->mspByteArray.get(), avpCode);
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


INT32 FlowInformation::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 FlowInformation::getAvpCode()
{
	return mAvpCode;
}
INT32 FlowInformation::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 FlowInformation::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 FlowInformation::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> FlowInformation::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void FlowInformation::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case FlowInformation_FLOWDESCRIPTION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "507" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FlowDescription" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getFlowDescription()->Display(tab+1);
			}
				break;
			case FlowInformation_PACKETFILTERIDENTIFIER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1060" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PacketFilterIdentifier" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getPacketFilterIdentifier()->Display(tab+1);
			}
				break;
			case FlowInformation_PACKETFILTERUSAGE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1072" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PacketFilterUsage" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getPacketFilterUsage()->Display(tab+1);
			}
				break;
			case FlowInformation_TOSTRAFFICCLASS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1014" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ToSTrafficClass" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getToSTrafficClass()->Display(tab+1);
			}
				break;
			case FlowInformation_SECURITYPARAMETERINDEX:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1056" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SecurityParameterIndex" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getSecurityParameterIndex()->Display(tab+1);
			}
				break;
			case FlowInformation_FLOWLABEL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1057" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FlowLabel" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getFlowLabel()->Display(tab+1);
			}
				break;
			case FlowInformation_FLOWDIRECTION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1080" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FlowDirection" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getFlowDirection()->Display(tab+1);
			}
				break;
			case FlowInformation_ROUTINGRULEIDENTIFIER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1077" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RoutingRuleIdentifier" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getRoutingRuleIdentifier()->Display(tab+1);
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


BOOLEAN FlowInformation::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<8> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case FlowInformation_FLOWDESCRIPTION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 507");
				}
				else
					sprintf(lMissingAvpInfo, "%s,507", lMissingAvpInfo);
			}
				break;
			case FlowInformation_PACKETFILTERIDENTIFIER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1060");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1060", lMissingAvpInfo);
			}
				break;
			case FlowInformation_PACKETFILTERUSAGE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1072");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1072", lMissingAvpInfo);
			}
				break;
			case FlowInformation_TOSTRAFFICCLASS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1014");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1014", lMissingAvpInfo);
			}
				break;
			case FlowInformation_SECURITYPARAMETERINDEX:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1056");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1056", lMissingAvpInfo);
			}
				break;
			case FlowInformation_FLOWLABEL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1057");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1057", lMissingAvpInfo);
			}
				break;
			case FlowInformation_FLOWDIRECTION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1080");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1080", lMissingAvpInfo);
			}
				break;
			case FlowInformation_ROUTINGRULEIDENTIFIER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1077");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1077", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
