#include "slh/include/AdditionalServingNode.h"

using namespace SLH;
BOOLEAN AdditionalServingNode::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

AdditionalServingNode::AdditionalServingNode()
{
	mSGSNNumber = NULL;
	mSGSNName = NULL;
	mSGSNRealm = NULL;
	mMMEName = NULL;
	mMMERealm = NULL;
	mMSCNumber = NULL;
	m3GPPAAAServerName = NULL;
	mLCSCapabilitiesSets = NULL;
	mGMLCAddressList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<9>(string("111101001"));
	mMandatoryAvpSetVal.reset();
}

AdditionalServingNode::~AdditionalServingNode()
{
	if(mSGSNNumber != NULL)
		delete mSGSNNumber;
	if(mSGSNName != NULL)
		delete mSGSNName;
	if(mSGSNRealm != NULL)
		delete mSGSNRealm;
	if(mMMEName != NULL)
		delete mMMEName;
	if(mMMERealm != NULL)
		delete mMMERealm;
	if(mMSCNumber != NULL)
		delete mMSCNumber;
	if(m3GPPAAAServerName != NULL)
		delete m3GPPAAAServerName;
	if(mLCSCapabilitiesSets != NULL)
		delete mLCSCapabilitiesSets;
	if(mGMLCAddressList != NULL){
		mGMLCAddressIterator = mGMLCAddressList->begin();
		while(mGMLCAddressIterator != mGMLCAddressList->end()){
			delete (*mGMLCAddressIterator);
			mGMLCAddressIterator++;
		}
		delete mGMLCAddressList;
	}
}

OctetString* AdditionalServingNode::setSGSNNumber(){
	mMandatoryAvpSetVal [AdditionalServingNode_SGSNNUMBER] = 1;
	if(mSGSNNumber == NULL)
	{
		mSGSNNumber = new OctetString();
		mTagsPresent[AdditionalServingNode_SGSNNUMBER] = 1;
		return mSGSNNumber;
	}
	return mSGSNNumber;
}

void AdditionalServingNode::resetSGSNNumber(){
	mTagsPresent[AdditionalServingNode_SGSNNUMBER] = 0;
	if(mSGSNNumber != NULL)
	{
		delete mSGSNNumber; 
		mSGSNNumber = NULL;
	}
}

OctetString* AdditionalServingNode::setSGSNName(){
	if(mSGSNName == NULL)
	{
		mSGSNName = new OctetString();
		mTagsPresent[AdditionalServingNode_SGSNNAME] = 1;
		return mSGSNName;
	}
	return mSGSNName;
}

void AdditionalServingNode::resetSGSNName(){
	mTagsPresent[AdditionalServingNode_SGSNNAME] = 0;
	if(mSGSNName != NULL)
	{
		delete mSGSNName; 
		mSGSNName = NULL;
	}
}

OctetString* AdditionalServingNode::setSGSNRealm(){
	if(mSGSNRealm == NULL)
	{
		mSGSNRealm = new OctetString();
		mTagsPresent[AdditionalServingNode_SGSNREALM] = 1;
		return mSGSNRealm;
	}
	return mSGSNRealm;
}

void AdditionalServingNode::resetSGSNRealm(){
	mTagsPresent[AdditionalServingNode_SGSNREALM] = 0;
	if(mSGSNRealm != NULL)
	{
		delete mSGSNRealm; 
		mSGSNRealm = NULL;
	}
}

OctetString* AdditionalServingNode::setMMEName(){
	mMandatoryAvpSetVal [AdditionalServingNode_MMENAME] = 1;
	if(mMMEName == NULL)
	{
		mMMEName = new OctetString();
		mTagsPresent[AdditionalServingNode_MMENAME] = 1;
		return mMMEName;
	}
	return mMMEName;
}

void AdditionalServingNode::resetMMEName(){
	mTagsPresent[AdditionalServingNode_MMENAME] = 0;
	if(mMMEName != NULL)
	{
		delete mMMEName; 
		mMMEName = NULL;
	}
}

OctetString* AdditionalServingNode::setMMERealm(){
	if(mMMERealm == NULL)
	{
		mMMERealm = new OctetString();
		mTagsPresent[AdditionalServingNode_MMEREALM] = 1;
		return mMMERealm;
	}
	return mMMERealm;
}

void AdditionalServingNode::resetMMERealm(){
	mTagsPresent[AdditionalServingNode_MMEREALM] = 0;
	if(mMMERealm != NULL)
	{
		delete mMMERealm; 
		mMMERealm = NULL;
	}
}

OctetString* AdditionalServingNode::setMSCNumber(){
	mMandatoryAvpSetVal [AdditionalServingNode_MSCNUMBER] = 1;
	if(mMSCNumber == NULL)
	{
		mMSCNumber = new OctetString();
		mTagsPresent[AdditionalServingNode_MSCNUMBER] = 1;
		return mMSCNumber;
	}
	return mMSCNumber;
}

void AdditionalServingNode::resetMSCNumber(){
	mTagsPresent[AdditionalServingNode_MSCNUMBER] = 0;
	if(mMSCNumber != NULL)
	{
		delete mMSCNumber; 
		mMSCNumber = NULL;
	}
}

OctetString* AdditionalServingNode::set3GPPAAAServerName(){
	mMandatoryAvpSetVal [AdditionalServingNode_3GPPAAASERVERNAME] = 1;
	if(m3GPPAAAServerName == NULL)
	{
		m3GPPAAAServerName = new OctetString();
		mTagsPresent[AdditionalServingNode_3GPPAAASERVERNAME] = 1;
		return m3GPPAAAServerName;
	}
	return m3GPPAAAServerName;
}

void AdditionalServingNode::reset3GPPAAAServerName(){
	mTagsPresent[AdditionalServingNode_3GPPAAASERVERNAME] = 0;
	if(m3GPPAAAServerName != NULL)
	{
		delete m3GPPAAAServerName; 
		m3GPPAAAServerName = NULL;
	}
}

Unsigned32* AdditionalServingNode::setLCSCapabilitiesSets(){
	mMandatoryAvpSetVal [AdditionalServingNode_LCSCAPABILITIESSETS] = 1;
	if(mLCSCapabilitiesSets == NULL)
	{
		mLCSCapabilitiesSets = new Unsigned32();
		mTagsPresent[AdditionalServingNode_LCSCAPABILITIESSETS] = 1;
		return mLCSCapabilitiesSets;
	}
	return mLCSCapabilitiesSets;
}

void AdditionalServingNode::resetLCSCapabilitiesSets(){
	mTagsPresent[AdditionalServingNode_LCSCAPABILITIESSETS] = 0;
	if(mLCSCapabilitiesSets != NULL)
	{
		delete mLCSCapabilitiesSets; 
		mLCSCapabilitiesSets = NULL;
	}
}

OctetString* AdditionalServingNode::getSGSNNumber(){
	if(NULL == mSGSNNumber) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SGSNNumber is Null");
		throw lTssDiaMsgException;
	}
	if(!mSGSNNumber->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSGSNNumber->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SGSNNumber is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSGSNNumber->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSGSNNumber->Decode(mspByteArray.get(), mSGSNNumber->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SGSNNumber")     ;
			throw lTssDiaMsgException;
		}
		mSGSNNumber->mAvpDecodedFlag = true;
	}
	return mSGSNNumber;
}

OctetString* AdditionalServingNode::getSGSNName(){
	if(NULL == mSGSNName) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SGSNName is Null");
		throw lTssDiaMsgException;
	}
	if(!mSGSNName->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSGSNName->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SGSNName is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSGSNName->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSGSNName->Decode(mspByteArray.get(), mSGSNName->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SGSNName")     ;
			throw lTssDiaMsgException;
		}
		mSGSNName->mAvpDecodedFlag = true;
	}
	return mSGSNName;
}

OctetString* AdditionalServingNode::getSGSNRealm(){
	if(NULL == mSGSNRealm) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SGSNRealm is Null");
		throw lTssDiaMsgException;
	}
	if(!mSGSNRealm->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSGSNRealm->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SGSNRealm is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSGSNRealm->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSGSNRealm->Decode(mspByteArray.get(), mSGSNRealm->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SGSNRealm")     ;
			throw lTssDiaMsgException;
		}
		mSGSNRealm->mAvpDecodedFlag = true;
	}
	return mSGSNRealm;
}

OctetString* AdditionalServingNode::getMMEName(){
	if(NULL == mMMEName) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MMEName is Null");
		throw lTssDiaMsgException;
	}
	if(!mMMEName->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMMEName->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MMEName is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMMEName->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMMEName->Decode(mspByteArray.get(), mMMEName->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MMEName")     ;
			throw lTssDiaMsgException;
		}
		mMMEName->mAvpDecodedFlag = true;
	}
	return mMMEName;
}

OctetString* AdditionalServingNode::getMMERealm(){
	if(NULL == mMMERealm) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MMERealm is Null");
		throw lTssDiaMsgException;
	}
	if(!mMMERealm->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMMERealm->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MMERealm is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMMERealm->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMMERealm->Decode(mspByteArray.get(), mMMERealm->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MMERealm")     ;
			throw lTssDiaMsgException;
		}
		mMMERealm->mAvpDecodedFlag = true;
	}
	return mMMERealm;
}

OctetString* AdditionalServingNode::getMSCNumber(){
	if(NULL == mMSCNumber) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MSCNumber is Null");
		throw lTssDiaMsgException;
	}
	if(!mMSCNumber->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMSCNumber->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MSCNumber is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMSCNumber->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMSCNumber->Decode(mspByteArray.get(), mMSCNumber->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MSCNumber")     ;
			throw lTssDiaMsgException;
		}
		mMSCNumber->mAvpDecodedFlag = true;
	}
	return mMSCNumber;
}

OctetString* AdditionalServingNode::get3GPPAAAServerName(){
	if(NULL == m3GPPAAAServerName) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPAAAServerName is Null");
		throw lTssDiaMsgException;
	}
	if(!m3GPPAAAServerName->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			m3GPPAAAServerName->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPAAAServerName is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = m3GPPAAAServerName->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(m3GPPAAAServerName->Decode(mspByteArray.get(), m3GPPAAAServerName->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPAAAServerName")     ;
			throw lTssDiaMsgException;
		}
		m3GPPAAAServerName->mAvpDecodedFlag = true;
	}
	return m3GPPAAAServerName;
}

Unsigned32* AdditionalServingNode::getLCSCapabilitiesSets(){
	if(NULL == mLCSCapabilitiesSets) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "LCSCapabilitiesSets is Null");
		throw lTssDiaMsgException;
	}
	if(!mLCSCapabilitiesSets->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mLCSCapabilitiesSets->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "LCSCapabilitiesSets is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mLCSCapabilitiesSets->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mLCSCapabilitiesSets->Decode(mspByteArray.get(), mLCSCapabilitiesSets->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding LCSCapabilitiesSets")     ;
			throw lTssDiaMsgException;
		}
		mLCSCapabilitiesSets->mAvpDecodedFlag = true;
	}
	return mLCSCapabilitiesSets;
}

list<OctetString*>* AdditionalServingNode::getGMLCAddressList()
{
	if(mGMLCAddressList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "GMLCAddress is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mGMLCAddressList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "GMLCAddress is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding GMLCAddress")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mGMLCAddressList;
}

list<OctetString*>* AdditionalServingNode::setGMLCAddressList() {
	mTagsPresent[AdditionalServingNode_GMLCADDRESS] = 1;
	if(mGMLCAddressList == NULL)
		mGMLCAddressList = new list<OctetString*>;
	mMandatoryAvpSetVal [AdditionalServingNode_GMLCADDRESS] = 1;
	mGMLCAddressList->clear();
	return mGMLCAddressList;
}

void AdditionalServingNode::resetGMLCAddressList(){
	mTagsPresent[AdditionalServingNode_GMLCADDRESS] = 0;
	if(mGMLCAddressList != NULL)
		delete mGMLCAddressList;
}



int AdditionalServingNode::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case AdditionalServingNode_SGSNNUMBER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1489);
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
					if(!mSGSNNumber->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSGSNNumber->getAvpOffsetLen().first], mSGSNNumber->getAvpOffsetLen().second);
						array->offset += mSGSNNumber->getAvpOffsetLen().second;
						array->size += mSGSNNumber->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mSGSNNumber->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mSGSNNumber->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SGSNNumber");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mSGSNNumber->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mSGSNNumber->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SGSNNumber");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AdditionalServingNode_SGSNNAME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2409);
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
					if(!mSGSNName->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSGSNName->getAvpOffsetLen().first], mSGSNName->getAvpOffsetLen().second);
						array->offset += mSGSNName->getAvpOffsetLen().second;
						array->size += mSGSNName->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mSGSNName->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mSGSNName->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SGSNName");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mSGSNName->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mSGSNName->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SGSNName");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AdditionalServingNode_SGSNREALM:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2410);
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
					if(!mSGSNRealm->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSGSNRealm->getAvpOffsetLen().first], mSGSNRealm->getAvpOffsetLen().second);
						array->offset += mSGSNRealm->getAvpOffsetLen().second;
						array->size += mSGSNRealm->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mSGSNRealm->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mSGSNRealm->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SGSNRealm");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mSGSNRealm->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mSGSNRealm->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SGSNRealm");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AdditionalServingNode_MMENAME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2402);
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
					if(!mMMEName->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMMEName->getAvpOffsetLen().first], mMMEName->getAvpOffsetLen().second);
						array->offset += mMMEName->getAvpOffsetLen().second;
						array->size += mMMEName->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mMMEName->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mMMEName->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MMEName");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mMMEName->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mMMEName->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MMEName");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AdditionalServingNode_MMEREALM:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2408);
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
					if(!mMMERealm->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMMERealm->getAvpOffsetLen().first], mMMERealm->getAvpOffsetLen().second);
						array->offset += mMMERealm->getAvpOffsetLen().second;
						array->size += mMMERealm->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mMMERealm->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mMMERealm->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MMERealm");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mMMERealm->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mMMERealm->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MMERealm");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AdditionalServingNode_MSCNUMBER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2403);
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
					if(!mMSCNumber->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMSCNumber->getAvpOffsetLen().first], mMSCNumber->getAvpOffsetLen().second);
						array->offset += mMSCNumber->getAvpOffsetLen().second;
						array->size += mMSCNumber->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mMSCNumber->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mMSCNumber->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MSCNumber");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mMSCNumber->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mMSCNumber->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MSCNumber");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AdditionalServingNode_3GPPAAASERVERNAME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(318);
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
					if(!m3GPPAAAServerName->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[m3GPPAAAServerName->getAvpOffsetLen().first], m3GPPAAAServerName->getAvpOffsetLen().second);
						array->offset += m3GPPAAAServerName->getAvpOffsetLen().second;
						array->size += m3GPPAAAServerName->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( m3GPPAAAServerName->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(m3GPPAAAServerName->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPAAAServerName");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((m3GPPAAAServerName->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, m3GPPAAAServerName->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPAAAServerName");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AdditionalServingNode_LCSCAPABILITIESSETS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2404);
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
					if(!mLCSCapabilitiesSets->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mLCSCapabilitiesSets->getAvpOffsetLen().first], mLCSCapabilitiesSets->getAvpOffsetLen().second);
						array->offset += mLCSCapabilitiesSets->getAvpOffsetLen().second;
						array->size += mLCSCapabilitiesSets->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding LCSCapabilitiesSets");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mLCSCapabilitiesSets->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding LCSCapabilitiesSets");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AdditionalServingNode_GMLCADDRESS:
			{
					if( mGMLCAddressList->size() <= 0) {
						break;
					}

					mGMLCAddressIterator = this->getGMLCAddressList()->begin();
					while(mGMLCAddressIterator != mGMLCAddressList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(2405);
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
					if(!(*mGMLCAddressIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mGMLCAddressIterator)->getAvpOffsetLen().first], (*mGMLCAddressIterator)->getAvpOffsetLen().second);
						array->offset += (*mGMLCAddressIterator)->getAvpOffsetLen().second;
						array->size += (*mGMLCAddressIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mGMLCAddressIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mGMLCAddressIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding GMLCAddress");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mGMLCAddressIterator++;
						continue;
					}
						if(((*mGMLCAddressIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mGMLCAddressIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding GMLCAddress");
							throw lTssDiaMsgException;
						}
						mGMLCAddressIterator++;
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


int AdditionalServingNode::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 1489:
				{
						mMandatoryAvpSetVal [AdditionalServingNode_SGSNNUMBER] = 1;
					if( NULL == this->setSGSNNumber())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SGSNNumber");
						throw lTssDiaMsgException;
					}
					mSGSNNumber->setAvpCode(1489);
					mSGSNNumber->setAvpVendorId(lVenderId);
					mSGSNNumber->SetDataType((DiameterDataType)5);
					mSGSNNumber->mspByteArray = mspByteArray;
					mSGSNNumber->mAvpDecodedFlag = false;
					mSGSNNumber->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2409:
				{
					if( NULL == this->setSGSNName())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SGSNName");
						throw lTssDiaMsgException;
					}
					mSGSNName->setAvpCode(2409);
					mSGSNName->setAvpVendorId(lVenderId);
					mSGSNName->SetDataType((DiameterDataType)5);
					mSGSNName->mspByteArray = mspByteArray;
					mSGSNName->mAvpDecodedFlag = false;
					mSGSNName->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2410:
				{
					if( NULL == this->setSGSNRealm())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SGSNRealm");
						throw lTssDiaMsgException;
					}
					mSGSNRealm->setAvpCode(2410);
					mSGSNRealm->setAvpVendorId(lVenderId);
					mSGSNRealm->SetDataType((DiameterDataType)5);
					mSGSNRealm->mspByteArray = mspByteArray;
					mSGSNRealm->mAvpDecodedFlag = false;
					mSGSNRealm->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2402:
				{
						mMandatoryAvpSetVal [AdditionalServingNode_MMENAME] = 1;
					if( NULL == this->setMMEName())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MMEName");
						throw lTssDiaMsgException;
					}
					mMMEName->setAvpCode(2402);
					mMMEName->setAvpVendorId(lVenderId);
					mMMEName->SetDataType((DiameterDataType)5);
					mMMEName->mspByteArray = mspByteArray;
					mMMEName->mAvpDecodedFlag = false;
					mMMEName->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2408:
				{
					if( NULL == this->setMMERealm())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MMERealm");
						throw lTssDiaMsgException;
					}
					mMMERealm->setAvpCode(2408);
					mMMERealm->setAvpVendorId(lVenderId);
					mMMERealm->SetDataType((DiameterDataType)5);
					mMMERealm->mspByteArray = mspByteArray;
					mMMERealm->mAvpDecodedFlag = false;
					mMMERealm->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2403:
				{
						mMandatoryAvpSetVal [AdditionalServingNode_MSCNUMBER] = 1;
					if( NULL == this->setMSCNumber())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MSCNumber");
						throw lTssDiaMsgException;
					}
					mMSCNumber->setAvpCode(2403);
					mMSCNumber->setAvpVendorId(lVenderId);
					mMSCNumber->SetDataType((DiameterDataType)5);
					mMSCNumber->mspByteArray = mspByteArray;
					mMSCNumber->mAvpDecodedFlag = false;
					mMSCNumber->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 318:
				{
						mMandatoryAvpSetVal [AdditionalServingNode_3GPPAAASERVERNAME] = 1;
					if( NULL == this->set3GPPAAAServerName())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPAAAServerName");
						throw lTssDiaMsgException;
					}
					m3GPPAAAServerName->setAvpCode(318);
					m3GPPAAAServerName->setAvpVendorId(lVenderId);
					m3GPPAAAServerName->SetDataType((DiameterDataType)5);
					m3GPPAAAServerName->mspByteArray = mspByteArray;
					m3GPPAAAServerName->mAvpDecodedFlag = false;
					m3GPPAAAServerName->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2404:
				{
						mMandatoryAvpSetVal [AdditionalServingNode_LCSCAPABILITIESSETS] = 1;
					if( NULL == this->setLCSCapabilitiesSets())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding LCSCapabilitiesSets");
						throw lTssDiaMsgException;
					}
					mLCSCapabilitiesSets->setAvpCode(2404);
					mLCSCapabilitiesSets->setAvpVendorId(lVenderId);
					mLCSCapabilitiesSets->SetDataType((DiameterDataType)3);
					mLCSCapabilitiesSets->mspByteArray = mspByteArray;
					mLCSCapabilitiesSets->mAvpDecodedFlag = false;
					mLCSCapabilitiesSets->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2405:
				{
						mMandatoryAvpSetVal [AdditionalServingNode_GMLCADDRESS] = 1;
					mTagsPresent[AdditionalServingNode_GMLCADDRESS] = 1;
					OctetString *lGMLCAddress = new OctetString();
					if( lGMLCAddress == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding GMLCAddress");
						throw lTssDiaMsgException;
					}
					lGMLCAddress->setAvpCode(2405);
					lGMLCAddress->setAvpVendorId(lVenderId);
					lGMLCAddress->SetDataType((DiameterDataType)5);
					lGMLCAddress->mspByteArray = mspByteArray;
					lGMLCAddress->mAvpDecodedFlag = false;
					lGMLCAddress->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mGMLCAddressList == NULL)
						this->setGMLCAddressList();
					mGMLCAddressList->push_back(lGMLCAddress);
					
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


DiameterBaseInterface* AdditionalServingNode::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AdditionalServingNode")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1489:
			{
				if(mSGSNNumber != NULL)
					return mSGSNNumber->Find(array, avpCode);
				else
					return NULL;
			}
			case 2409:
			{
				if(mSGSNName != NULL)
					return mSGSNName->Find(array, avpCode);
				else
					return NULL;
			}
			case 2410:
			{
				if(mSGSNRealm != NULL)
					return mSGSNRealm->Find(array, avpCode);
				else
					return NULL;
			}
			case 2402:
			{
				if(mMMEName != NULL)
					return mMMEName->Find(array, avpCode);
				else
					return NULL;
			}
			case 2408:
			{
				if(mMMERealm != NULL)
					return mMMERealm->Find(array, avpCode);
				else
					return NULL;
			}
			case 2403:
			{
				if(mMSCNumber != NULL)
					return mMSCNumber->Find(array, avpCode);
				else
					return NULL;
			}
			case 318:
			{
				if(m3GPPAAAServerName != NULL)
					return m3GPPAAAServerName->Find(array, avpCode);
				else
					return NULL;
			}
			case 2404:
			{
				if(mLCSCapabilitiesSets != NULL)
					return mLCSCapabilitiesSets->Find(array, avpCode);
				else
					return NULL;
			}
			case 2405:
			{
				if(mGMLCAddressList != NULL && mGMLCAddressList->size() > 0)
					return (mGMLCAddressList->back())->Find(array, avpCode);
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


BOOLEAN AdditionalServingNode::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AdditionalServingNode")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1489:
			{
				if(mSGSNNumber != NULL)
				{
					DiameterBaseInterface* inf =  mSGSNNumber->Find(this->mspByteArray.get(), avpCode);
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
			case 2409:
			{
				if(mSGSNName != NULL)
				{
					DiameterBaseInterface* inf =  mSGSNName->Find(this->mspByteArray.get(), avpCode);
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
			case 2410:
			{
				if(mSGSNRealm != NULL)
				{
					DiameterBaseInterface* inf =  mSGSNRealm->Find(this->mspByteArray.get(), avpCode);
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
			case 2402:
			{
				if(mMMEName != NULL)
				{
					DiameterBaseInterface* inf =  mMMEName->Find(this->mspByteArray.get(), avpCode);
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
			case 2408:
			{
				if(mMMERealm != NULL)
				{
					DiameterBaseInterface* inf =  mMMERealm->Find(this->mspByteArray.get(), avpCode);
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
			case 2403:
			{
				if(mMSCNumber != NULL)
				{
					DiameterBaseInterface* inf =  mMSCNumber->Find(this->mspByteArray.get(), avpCode);
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
			case 318:
			{
				if(m3GPPAAAServerName != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPAAAServerName->Find(this->mspByteArray.get(), avpCode);
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
			case 2404:
			{
				if(mLCSCapabilitiesSets != NULL)
				{
					DiameterBaseInterface* inf =  mLCSCapabilitiesSets->Find(this->mspByteArray.get(), avpCode);
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
			case 2405:
			{
				if(mGMLCAddressList != NULL)
				{
					for(auto itr = mGMLCAddressList->begin(); itr != mGMLCAddressList->end(); ++itr)
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
std::shared_ptr<byteArray> AdditionalServingNode::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN AdditionalServingNode::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AdditionalServingNode")     ;
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
			case 1489:
			{
				if(mSGSNNumber != NULL)
				{
					DiameterBaseInterface* inf =  mSGSNNumber->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2409:
			{
				if(mSGSNName != NULL)
				{
					DiameterBaseInterface* inf =  mSGSNName->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2410:
			{
				if(mSGSNRealm != NULL)
				{
					DiameterBaseInterface* inf =  mSGSNRealm->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2402:
			{
				if(mMMEName != NULL)
				{
					DiameterBaseInterface* inf =  mMMEName->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2408:
			{
				if(mMMERealm != NULL)
				{
					DiameterBaseInterface* inf =  mMMERealm->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2403:
			{
				if(mMSCNumber != NULL)
				{
					DiameterBaseInterface* inf =  mMSCNumber->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 318:
			{
				if(m3GPPAAAServerName != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPAAAServerName->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2404:
			{
				if(mLCSCapabilitiesSets != NULL)
				{
					DiameterBaseInterface* inf =  mLCSCapabilitiesSets->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2405:
			{
				if(mGMLCAddressList != NULL)
				{
					for(auto itr = mGMLCAddressList->begin(); itr != mGMLCAddressList->end(); ++itr)
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


INT32 AdditionalServingNode::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 AdditionalServingNode::getAvpCode()
{
	return mAvpCode;
}
INT32 AdditionalServingNode::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 AdditionalServingNode::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 AdditionalServingNode::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> AdditionalServingNode::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void AdditionalServingNode::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case AdditionalServingNode_SGSNNUMBER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1489" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SGSNNumber" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getSGSNNumber()->Display(tab+1);
			}
				break;
			case AdditionalServingNode_SGSNNAME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2409" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SGSNName" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getSGSNName()->Display(tab+1);
			}
				break;
			case AdditionalServingNode_SGSNREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2410" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SGSNRealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getSGSNRealm()->Display(tab+1);
			}
				break;
			case AdditionalServingNode_MMENAME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2402" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MMEName" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getMMEName()->Display(tab+1);
			}
				break;
			case AdditionalServingNode_MMEREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2408" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MMERealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getMMERealm()->Display(tab+1);
			}
				break;
			case AdditionalServingNode_MSCNUMBER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2403" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MSCNumber" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getMSCNumber()->Display(tab+1);
			}
				break;
			case AdditionalServingNode_3GPPAAASERVERNAME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "318" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPPAAAServerName" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->get3GPPAAAServerName()->Display(tab+1);
			}
				break;
			case AdditionalServingNode_LCSCAPABILITIESSETS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2404" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "LCSCapabilitiesSets" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getLCSCapabilitiesSets()->Display(tab+1);
			}
				break;
			case AdditionalServingNode_GMLCADDRESS:
			{
				if( mGMLCAddressList->size() <= 0) {
					break;
				}

				mGMLCAddressIterator = this->getGMLCAddressList()->begin();
				while(mGMLCAddressIterator != this->getGMLCAddressList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2405" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "GMLCAddress" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mGMLCAddressIterator)->Display(tab+1);
					mGMLCAddressIterator++;

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


BOOLEAN AdditionalServingNode::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<9> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case AdditionalServingNode_SGSNNUMBER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1489");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1489", lMissingAvpInfo);
			}
				break;
			case AdditionalServingNode_SGSNNAME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2409");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2409", lMissingAvpInfo);
			}
				break;
			case AdditionalServingNode_SGSNREALM:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2410");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2410", lMissingAvpInfo);
			}
				break;
			case AdditionalServingNode_MMENAME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2402");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2402", lMissingAvpInfo);
			}
				break;
			case AdditionalServingNode_MMEREALM:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2408");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2408", lMissingAvpInfo);
			}
				break;
			case AdditionalServingNode_MSCNUMBER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2403");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2403", lMissingAvpInfo);
			}
				break;
			case AdditionalServingNode_3GPPAAASERVERNAME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 318");
				}
				else
					sprintf(lMissingAvpInfo, "%s,318", lMissingAvpInfo);
			}
				break;
			case AdditionalServingNode_LCSCAPABILITIESSETS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2404");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2404", lMissingAvpInfo);
			}
				break;
			case AdditionalServingNode_GMLCADDRESS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2405");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2405", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
