#include "cx/include/RestorationInfo.h"

using namespace CX;
BOOLEAN RestorationInfo::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

RestorationInfo::RestorationInfo()
{
	mPath = NULL;
	mContact = NULL;
	mInitialCSeqSequenceNumber = NULL;
	mCallIDSIPHeader = NULL;
	mSubscriptionInfoGrp = NULL;
	mPCSCFSubscriptionInfoGrp = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<6>(string("000000"));
	mMandatoryAvpSetVal.reset();
}

RestorationInfo::~RestorationInfo()
{
	if(mPath != NULL)
		delete mPath;
	if(mContact != NULL)
		delete mContact;
	if(mInitialCSeqSequenceNumber != NULL)
		delete mInitialCSeqSequenceNumber;
	if(mCallIDSIPHeader != NULL)
		delete mCallIDSIPHeader;
	if(mSubscriptionInfoGrp != NULL)
		delete mSubscriptionInfoGrp;
	if(mPCSCFSubscriptionInfoGrp != NULL)
		delete mPCSCFSubscriptionInfoGrp;
}

OctetString* RestorationInfo::setPath(){
	if(mPath == NULL)
	{
		mPath = new OctetString();
		mTagsPresent[RestorationInfo_PATH] = 1;
		return mPath;
	}
	return mPath;
}

void RestorationInfo::resetPath(){
	mTagsPresent[RestorationInfo_PATH] = 0;
	if(mPath != NULL)
	{
		delete mPath; 
		mPath = NULL;
	}
}

OctetString* RestorationInfo::setContact(){
	if(mContact == NULL)
	{
		mContact = new OctetString();
		mTagsPresent[RestorationInfo_CONTACT] = 1;
		return mContact;
	}
	return mContact;
}

void RestorationInfo::resetContact(){
	mTagsPresent[RestorationInfo_CONTACT] = 0;
	if(mContact != NULL)
	{
		delete mContact; 
		mContact = NULL;
	}
}

Unsigned32* RestorationInfo::setInitialCSeqSequenceNumber(){
	if(mInitialCSeqSequenceNumber == NULL)
	{
		mInitialCSeqSequenceNumber = new Unsigned32();
		mTagsPresent[RestorationInfo_INITIALCSEQSEQUENCENUMBER] = 1;
		return mInitialCSeqSequenceNumber;
	}
	return mInitialCSeqSequenceNumber;
}

void RestorationInfo::resetInitialCSeqSequenceNumber(){
	mTagsPresent[RestorationInfo_INITIALCSEQSEQUENCENUMBER] = 0;
	if(mInitialCSeqSequenceNumber != NULL)
	{
		delete mInitialCSeqSequenceNumber; 
		mInitialCSeqSequenceNumber = NULL;
	}
}

OctetString* RestorationInfo::setCallIDSIPHeader(){
	if(mCallIDSIPHeader == NULL)
	{
		mCallIDSIPHeader = new OctetString();
		mTagsPresent[RestorationInfo_CALLIDSIPHEADER] = 1;
		return mCallIDSIPHeader;
	}
	return mCallIDSIPHeader;
}

void RestorationInfo::resetCallIDSIPHeader(){
	mTagsPresent[RestorationInfo_CALLIDSIPHEADER] = 0;
	if(mCallIDSIPHeader != NULL)
	{
		delete mCallIDSIPHeader; 
		mCallIDSIPHeader = NULL;
	}
}

OctetString* RestorationInfo::getPath(){
	if(NULL == mPath) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Path is Null");
		throw lTssDiaMsgException;
	}
	if(!mPath->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPath->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Path is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPath->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPath->Decode(mspByteArray.get(), mPath->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Path")     ;
			throw lTssDiaMsgException;
		}
		mPath->mAvpDecodedFlag = true;
	}
	return mPath;
}

OctetString* RestorationInfo::getContact(){
	if(NULL == mContact) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Contact is Null");
		throw lTssDiaMsgException;
	}
	if(!mContact->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mContact->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Contact is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mContact->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mContact->Decode(mspByteArray.get(), mContact->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Contact")     ;
			throw lTssDiaMsgException;
		}
		mContact->mAvpDecodedFlag = true;
	}
	return mContact;
}

Unsigned32* RestorationInfo::getInitialCSeqSequenceNumber(){
	if(NULL == mInitialCSeqSequenceNumber) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "InitialCSeqSequenceNumber is Null");
		throw lTssDiaMsgException;
	}
	if(!mInitialCSeqSequenceNumber->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mInitialCSeqSequenceNumber->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "InitialCSeqSequenceNumber is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mInitialCSeqSequenceNumber->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mInitialCSeqSequenceNumber->Decode(mspByteArray.get(), mInitialCSeqSequenceNumber->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding InitialCSeqSequenceNumber")     ;
			throw lTssDiaMsgException;
		}
		mInitialCSeqSequenceNumber->mAvpDecodedFlag = true;
	}
	return mInitialCSeqSequenceNumber;
}

OctetString* RestorationInfo::getCallIDSIPHeader(){
	if(NULL == mCallIDSIPHeader) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CallIDSIPHeader is Null");
		throw lTssDiaMsgException;
	}
	if(!mCallIDSIPHeader->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCallIDSIPHeader->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CallIDSIPHeader is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCallIDSIPHeader->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCallIDSIPHeader->Decode(mspByteArray.get(), mCallIDSIPHeader->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CallIDSIPHeader")     ;
			throw lTssDiaMsgException;
		}
		mCallIDSIPHeader->mAvpDecodedFlag = true;
	}
	return mCallIDSIPHeader;
}

SubscriptionInfo* RestorationInfo::getSubscriptionInfo()
{
	if(mSubscriptionInfoGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SubscriptionInfo is Null");
		throw lTssDiaMsgException;
	}
	if(!mSubscriptionInfoGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSubscriptionInfoGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SubscriptionInfo is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSubscriptionInfoGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSubscriptionInfoGrp->Decode(mspByteArray.get(), mSubscriptionInfoGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SubscriptionInfo")     ;
			throw lTssDiaMsgException;
		}
		mSubscriptionInfoGrp->mAvpDecodedFlag = true;
	}
	return mSubscriptionInfoGrp;
}

SubscriptionInfo* RestorationInfo::setSubscriptionInfo(){
	if(mSubscriptionInfoGrp == NULL)
		mSubscriptionInfoGrp = new SubscriptionInfo();
	mTagsPresent[RestorationInfo_SUBSCRIPTIONINFO] = 1;
	return mSubscriptionInfoGrp;
}

void RestorationInfo::resetSubscriptionInfo(){
	mTagsPresent[RestorationInfo_SUBSCRIPTIONINFO] = 0;
	if(mSubscriptionInfoGrp != NULL)
		delete mSubscriptionInfoGrp;
}

PCSCFSubscriptionInfo* RestorationInfo::getPCSCFSubscriptionInfo()
{
	if(mPCSCFSubscriptionInfoGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PCSCFSubscriptionInfo is Null");
		throw lTssDiaMsgException;
	}
	if(!mPCSCFSubscriptionInfoGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPCSCFSubscriptionInfoGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PCSCFSubscriptionInfo is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPCSCFSubscriptionInfoGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPCSCFSubscriptionInfoGrp->Decode(mspByteArray.get(), mPCSCFSubscriptionInfoGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PCSCFSubscriptionInfo")     ;
			throw lTssDiaMsgException;
		}
		mPCSCFSubscriptionInfoGrp->mAvpDecodedFlag = true;
	}
	return mPCSCFSubscriptionInfoGrp;
}

PCSCFSubscriptionInfo* RestorationInfo::setPCSCFSubscriptionInfo(){
	if(mPCSCFSubscriptionInfoGrp == NULL)
		mPCSCFSubscriptionInfoGrp = new PCSCFSubscriptionInfo();
	mTagsPresent[RestorationInfo_PCSCFSUBSCRIPTIONINFO] = 1;
	return mPCSCFSubscriptionInfoGrp;
}

void RestorationInfo::resetPCSCFSubscriptionInfo(){
	mTagsPresent[RestorationInfo_PCSCFSUBSCRIPTIONINFO] = 0;
	if(mPCSCFSubscriptionInfoGrp != NULL)
		delete mPCSCFSubscriptionInfoGrp;
}



int RestorationInfo::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case RestorationInfo_PATH:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(640);
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
					if(!mPath->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mPath->getAvpOffsetLen().first], mPath->getAvpOffsetLen().second);
						array->offset += mPath->getAvpOffsetLen().second;
						array->size += mPath->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mPath->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mPath->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Path");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mPath->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mPath->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Path");
						throw lTssDiaMsgException;
					}
				}
				break;
			case RestorationInfo_CONTACT:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(641);
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
					if(!mContact->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mContact->getAvpOffsetLen().first], mContact->getAvpOffsetLen().second);
						array->offset += mContact->getAvpOffsetLen().second;
						array->size += mContact->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mContact->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mContact->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Contact");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mContact->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mContact->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Contact");
						throw lTssDiaMsgException;
					}
				}
				break;
			case RestorationInfo_INITIALCSEQSEQUENCENUMBER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(654);
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
					if(!mInitialCSeqSequenceNumber->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mInitialCSeqSequenceNumber->getAvpOffsetLen().first], mInitialCSeqSequenceNumber->getAvpOffsetLen().second);
						array->offset += mInitialCSeqSequenceNumber->getAvpOffsetLen().second;
						array->size += mInitialCSeqSequenceNumber->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding InitialCSeqSequenceNumber");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mInitialCSeqSequenceNumber->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding InitialCSeqSequenceNumber");
						throw lTssDiaMsgException;
					}
				}
				break;
			case RestorationInfo_CALLIDSIPHEADER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(643);
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
					if(!mCallIDSIPHeader->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCallIDSIPHeader->getAvpOffsetLen().first], mCallIDSIPHeader->getAvpOffsetLen().second);
						array->offset += mCallIDSIPHeader->getAvpOffsetLen().second;
						array->size += mCallIDSIPHeader->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mCallIDSIPHeader->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mCallIDSIPHeader->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CallIDSIPHeader");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mCallIDSIPHeader->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mCallIDSIPHeader->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CallIDSIPHeader");
						throw lTssDiaMsgException;
					}
				}
				break;
			case RestorationInfo_SUBSCRIPTIONINFO:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(642);
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
				if((this->getSubscriptionInfo()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SubscriptionInfo");
					throw lTssDiaMsgException;
					}
				}
				break;
			case RestorationInfo_PCSCFSUBSCRIPTIONINFO:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(660);
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
				if((this->getPCSCFSubscriptionInfo()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PCSCFSubscriptionInfo");
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


int RestorationInfo::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 640:
				{
					if( NULL == this->setPath())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Path");
						throw lTssDiaMsgException;
					}
					mPath->setAvpCode(640);
					mPath->setAvpVendorId(lVenderId);
					mPath->SetDataType((DiameterDataType)5);
					mPath->mspByteArray = mspByteArray;
					mPath->mAvpDecodedFlag = false;
					mPath->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 641:
				{
					if( NULL == this->setContact())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Contact");
						throw lTssDiaMsgException;
					}
					mContact->setAvpCode(641);
					mContact->setAvpVendorId(lVenderId);
					mContact->SetDataType((DiameterDataType)5);
					mContact->mspByteArray = mspByteArray;
					mContact->mAvpDecodedFlag = false;
					mContact->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 654:
				{
					if( NULL == this->setInitialCSeqSequenceNumber())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding InitialCSeqSequenceNumber");
						throw lTssDiaMsgException;
					}
					mInitialCSeqSequenceNumber->setAvpCode(654);
					mInitialCSeqSequenceNumber->setAvpVendorId(lVenderId);
					mInitialCSeqSequenceNumber->SetDataType((DiameterDataType)3);
					mInitialCSeqSequenceNumber->mspByteArray = mspByteArray;
					mInitialCSeqSequenceNumber->mAvpDecodedFlag = false;
					mInitialCSeqSequenceNumber->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 643:
				{
					if( NULL == this->setCallIDSIPHeader())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CallIDSIPHeader");
						throw lTssDiaMsgException;
					}
					mCallIDSIPHeader->setAvpCode(643);
					mCallIDSIPHeader->setAvpVendorId(lVenderId);
					mCallIDSIPHeader->SetDataType((DiameterDataType)5);
					mCallIDSIPHeader->mspByteArray = mspByteArray;
					mCallIDSIPHeader->mAvpDecodedFlag = false;
					mCallIDSIPHeader->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 642:
				{
					mTagsPresent[RestorationInfo_SUBSCRIPTIONINFO] = 1;
						if( NULL == this->setSubscriptionInfo()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SubscriptionInfo");
						throw lTssDiaMsgException;
						}
					mSubscriptionInfoGrp->setAvpCode(642);
					mSubscriptionInfoGrp->SetDataType((DiameterDataType)6);
					mSubscriptionInfoGrp->mspByteArray = mspByteArray;
					mSubscriptionInfoGrp->mAvpDecodedFlag = false;
					mSubscriptionInfoGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mSubscriptionInfoGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			case 660:
				{
					mTagsPresent[RestorationInfo_PCSCFSUBSCRIPTIONINFO] = 1;
						if( NULL == this->setPCSCFSubscriptionInfo()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PCSCFSubscriptionInfo");
						throw lTssDiaMsgException;
						}
					mPCSCFSubscriptionInfoGrp->setAvpCode(660);
					mPCSCFSubscriptionInfoGrp->SetDataType((DiameterDataType)6);
					mPCSCFSubscriptionInfoGrp->mspByteArray = mspByteArray;
					mPCSCFSubscriptionInfoGrp->mAvpDecodedFlag = false;
					mPCSCFSubscriptionInfoGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mPCSCFSubscriptionInfoGrp);
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


DiameterBaseInterface* RestorationInfo::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RestorationInfo")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 640:
			{
				if(mPath != NULL)
					return mPath->Find(array, avpCode);
				else
					return NULL;
			}
			case 641:
			{
				if(mContact != NULL)
					return mContact->Find(array, avpCode);
				else
					return NULL;
			}
			case 654:
			{
				if(mInitialCSeqSequenceNumber != NULL)
					return mInitialCSeqSequenceNumber->Find(array, avpCode);
				else
					return NULL;
			}
			case 643:
			{
				if(mCallIDSIPHeader != NULL)
					return mCallIDSIPHeader->Find(array, avpCode);
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


BOOLEAN RestorationInfo::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RestorationInfo")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 640:
			{
				if(mPath != NULL)
				{
					DiameterBaseInterface* inf =  mPath->Find(this->mspByteArray.get(), avpCode);
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
			case 641:
			{
				if(mContact != NULL)
				{
					DiameterBaseInterface* inf =  mContact->Find(this->mspByteArray.get(), avpCode);
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
			case 654:
			{
				if(mInitialCSeqSequenceNumber != NULL)
				{
					DiameterBaseInterface* inf =  mInitialCSeqSequenceNumber->Find(this->mspByteArray.get(), avpCode);
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
			case 643:
			{
				if(mCallIDSIPHeader != NULL)
				{
					DiameterBaseInterface* inf =  mCallIDSIPHeader->Find(this->mspByteArray.get(), avpCode);
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
			case 642:
			{
				if(mSubscriptionInfoGrp != NULL)
				{
						pBaseInterface.push_back(mSubscriptionInfoGrp);
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
			case 660:
			{
				if(mPCSCFSubscriptionInfoGrp != NULL)
				{
						pBaseInterface.push_back(mPCSCFSubscriptionInfoGrp);
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
std::shared_ptr<byteArray> RestorationInfo::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN RestorationInfo::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RestorationInfo")     ;
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
			case 640:
			{
				if(mPath != NULL)
				{
					DiameterBaseInterface* inf =  mPath->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 641:
			{
				if(mContact != NULL)
				{
					DiameterBaseInterface* inf =  mContact->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 654:
			{
				if(mInitialCSeqSequenceNumber != NULL)
				{
					DiameterBaseInterface* inf =  mInitialCSeqSequenceNumber->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 643:
			{
				if(mCallIDSIPHeader != NULL)
				{
					DiameterBaseInterface* inf =  mCallIDSIPHeader->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 642:
			{
				if(mSubscriptionInfoGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mSubscriptionInfoGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mSubscriptionInfoGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
				}
				}
				break;
			}
			case 660:
			{
				if(mPCSCFSubscriptionInfoGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mPCSCFSubscriptionInfoGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mPCSCFSubscriptionInfoGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
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


INT32 RestorationInfo::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 RestorationInfo::getAvpCode()
{
	return mAvpCode;
}
INT32 RestorationInfo::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 RestorationInfo::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 RestorationInfo::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> RestorationInfo::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void RestorationInfo::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case RestorationInfo_PATH:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "640" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "Path" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getPath()->Display(tab+1);
			}
				break;
			case RestorationInfo_CONTACT:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "641" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "Contact" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getContact()->Display(tab+1);
			}
				break;
			case RestorationInfo_INITIALCSEQSEQUENCENUMBER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "654" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "InitialCSeqSequenceNumber" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getInitialCSeqSequenceNumber()->Display(tab+1);
			}
				break;
			case RestorationInfo_CALLIDSIPHEADER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "643" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CallIDSIPHeader" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getCallIDSIPHeader()->Display(tab+1);
			}
				break;
			case RestorationInfo_SUBSCRIPTIONINFO:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "642" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SubscriptionInfo" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getSubscriptionInfo()->Display(tab+1);
			}
				break;
			case RestorationInfo_PCSCFSUBSCRIPTIONINFO:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "660" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PCSCFSubscriptionInfo" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getPCSCFSubscriptionInfo()->Display(tab+1);
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


BOOLEAN RestorationInfo::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<6> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case RestorationInfo_PATH:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 640");
				}
				else
					sprintf(lMissingAvpInfo, "%s,640", lMissingAvpInfo);
			}
				break;
			case RestorationInfo_CONTACT:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 641");
				}
				else
					sprintf(lMissingAvpInfo, "%s,641", lMissingAvpInfo);
			}
				break;
			case RestorationInfo_INITIALCSEQSEQUENCENUMBER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 654");
				}
				else
					sprintf(lMissingAvpInfo, "%s,654", lMissingAvpInfo);
			}
				break;
			case RestorationInfo_CALLIDSIPHEADER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 643");
				}
				else
					sprintf(lMissingAvpInfo, "%s,643", lMissingAvpInfo);
			}
				break;
			case RestorationInfo_SUBSCRIPTIONINFO:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 642");
				}
				else
					sprintf(lMissingAvpInfo, "%s,642", lMissingAvpInfo);
			}
				break;
			case RestorationInfo_PCSCFSUBSCRIPTIONINFO:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 660");
				}
				else
					sprintf(lMissingAvpInfo, "%s,660", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
