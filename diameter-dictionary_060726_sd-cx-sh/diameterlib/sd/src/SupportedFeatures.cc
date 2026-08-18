#include "sd/include/SupportedFeatures.h"

using namespace SD;
BOOLEAN SupportedFeatures::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

SupportedFeatures::SupportedFeatures()
{
	mVendorId = NULL;
	mFeatureListID = NULL;
	mFeatureList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<3>(string("001"));
	mMandatoryAvpSetVal.reset();
}

SupportedFeatures::~SupportedFeatures()
{
	if(mVendorId != NULL)
		delete mVendorId;
	if(mFeatureListID != NULL)
		delete mFeatureListID;
	if(mFeatureList != NULL)
		delete mFeatureList;
}

Unsigned32* SupportedFeatures::setVendorId(){
	mMandatoryAvpSetVal [SupportedFeatures_VENDORID] = 1;
	if(mVendorId == NULL)
	{
		mVendorId = new Unsigned32();
		mTagsPresent[SupportedFeatures_VENDORID] = 1;
		return mVendorId;
	}
	return mVendorId;
}

void SupportedFeatures::resetVendorId(){
	mTagsPresent[SupportedFeatures_VENDORID] = 0;
	if(mVendorId != NULL)
	{
		delete mVendorId; 
		mVendorId = NULL;
	}
}

Unsigned32* SupportedFeatures::setFeatureListID(){
	if(mFeatureListID == NULL)
	{
		mFeatureListID = new Unsigned32();
		mTagsPresent[SupportedFeatures_FEATURELISTID] = 1;
		return mFeatureListID;
	}
	return mFeatureListID;
}

void SupportedFeatures::resetFeatureListID(){
	mTagsPresent[SupportedFeatures_FEATURELISTID] = 0;
	if(mFeatureListID != NULL)
	{
		delete mFeatureListID; 
		mFeatureListID = NULL;
	}
}

Unsigned32* SupportedFeatures::setFeatureList(){
	if(mFeatureList == NULL)
	{
		mFeatureList = new Unsigned32();
		mTagsPresent[SupportedFeatures_FEATURELIST] = 1;
		return mFeatureList;
	}
	return mFeatureList;
}

void SupportedFeatures::resetFeatureList(){
	mTagsPresent[SupportedFeatures_FEATURELIST] = 0;
	if(mFeatureList != NULL)
	{
		delete mFeatureList; 
		mFeatureList = NULL;
	}
}

Unsigned32* SupportedFeatures::getVendorId(){
	if(NULL == mVendorId) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "VendorId is Null");
		throw lTssDiaMsgException;
	}
	if(!mVendorId->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mVendorId->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "VendorId is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mVendorId->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mVendorId->Decode(mspByteArray.get(), mVendorId->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding VendorId")     ;
			throw lTssDiaMsgException;
		}
		mVendorId->mAvpDecodedFlag = true;
	}
	return mVendorId;
}

Unsigned32* SupportedFeatures::getFeatureListID(){
	if(NULL == mFeatureListID) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FeatureListID is Null");
		throw lTssDiaMsgException;
	}
	if(!mFeatureListID->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mFeatureListID->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FeatureListID is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mFeatureListID->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mFeatureListID->Decode(mspByteArray.get(), mFeatureListID->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FeatureListID")     ;
			throw lTssDiaMsgException;
		}
		mFeatureListID->mAvpDecodedFlag = true;
	}
	return mFeatureListID;
}

Unsigned32* SupportedFeatures::getFeatureList(){
	if(NULL == mFeatureList) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FeatureList is Null");
		throw lTssDiaMsgException;
	}
	if(!mFeatureList->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mFeatureList->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FeatureList is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mFeatureList->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mFeatureList->Decode(mspByteArray.get(), mFeatureList->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FeatureList")     ;
			throw lTssDiaMsgException;
		}
		mFeatureList->mAvpDecodedFlag = true;
	}
	return mFeatureList;
}



int SupportedFeatures::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case SupportedFeatures_VENDORID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(266);
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
					if(!mVendorId->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mVendorId->getAvpOffsetLen().first], mVendorId->getAvpOffsetLen().second);
						array->offset += mVendorId->getAvpOffsetLen().second;
						array->size += mVendorId->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding VendorId");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mVendorId->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding VendorId");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SupportedFeatures_FEATURELISTID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(629);
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
					if(!mFeatureListID->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mFeatureListID->getAvpOffsetLen().first], mFeatureListID->getAvpOffsetLen().second);
						array->offset += mFeatureListID->getAvpOffsetLen().second;
						array->size += mFeatureListID->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FeatureListID");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mFeatureListID->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FeatureListID");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SupportedFeatures_FEATURELIST:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(630);
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
					if(!mFeatureList->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mFeatureList->getAvpOffsetLen().first], mFeatureList->getAvpOffsetLen().second);
						array->offset += mFeatureList->getAvpOffsetLen().second;
						array->size += mFeatureList->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FeatureList");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mFeatureList->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FeatureList");
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


int SupportedFeatures::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 266:
				{
						mMandatoryAvpSetVal [SupportedFeatures_VENDORID] = 1;
					if( NULL == this->setVendorId())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding VendorId");
						throw lTssDiaMsgException;
					}
					mVendorId->setAvpCode(266);
					mVendorId->setAvpVendorId(lVenderId);
					mVendorId->SetDataType((DiameterDataType)3);
					mVendorId->mspByteArray = mspByteArray;
					mVendorId->mAvpDecodedFlag = false;
					mVendorId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 629:
				{
					if( NULL == this->setFeatureListID())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FeatureListID");
						throw lTssDiaMsgException;
					}
					mFeatureListID->setAvpCode(629);
					mFeatureListID->setAvpVendorId(lVenderId);
					mFeatureListID->SetDataType((DiameterDataType)3);
					mFeatureListID->mspByteArray = mspByteArray;
					mFeatureListID->mAvpDecodedFlag = false;
					mFeatureListID->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 630:
				{
					if( NULL == this->setFeatureList())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FeatureList");
						throw lTssDiaMsgException;
					}
					mFeatureList->setAvpCode(630);
					mFeatureList->setAvpVendorId(lVenderId);
					mFeatureList->SetDataType((DiameterDataType)3);
					mFeatureList->mspByteArray = mspByteArray;
					mFeatureList->mAvpDecodedFlag = false;
					mFeatureList->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* SupportedFeatures::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SupportedFeatures")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 266:
			{
				if(mVendorId != NULL)
					return mVendorId->Find(array, avpCode);
				else
					return NULL;
			}
			case 629:
			{
				if(mFeatureListID != NULL)
					return mFeatureListID->Find(array, avpCode);
				else
					return NULL;
			}
			case 630:
			{
				if(mFeatureList != NULL)
					return mFeatureList->Find(array, avpCode);
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


BOOLEAN SupportedFeatures::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SupportedFeatures")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 266:
			{
				if(mVendorId != NULL)
				{
					DiameterBaseInterface* inf =  mVendorId->Find(this->mspByteArray.get(), avpCode);
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
			case 629:
			{
				if(mFeatureListID != NULL)
				{
					DiameterBaseInterface* inf =  mFeatureListID->Find(this->mspByteArray.get(), avpCode);
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
			case 630:
			{
				if(mFeatureList != NULL)
				{
					DiameterBaseInterface* inf =  mFeatureList->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> SupportedFeatures::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN SupportedFeatures::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SupportedFeatures")     ;
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
			case 266:
			{
				if(mVendorId != NULL)
				{
					DiameterBaseInterface* inf =  mVendorId->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 629:
			{
				if(mFeatureListID != NULL)
				{
					DiameterBaseInterface* inf =  mFeatureListID->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 630:
			{
				if(mFeatureList != NULL)
				{
					DiameterBaseInterface* inf =  mFeatureList->Find(this->mspByteArray.get(), avpCode);
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


INT32 SupportedFeatures::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 SupportedFeatures::getAvpCode()
{
	return mAvpCode;
}
INT32 SupportedFeatures::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 SupportedFeatures::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 SupportedFeatures::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> SupportedFeatures::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void SupportedFeatures::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case SupportedFeatures_VENDORID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "266" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "VendorId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getVendorId()->Display(tab+1);
			}
				break;
			case SupportedFeatures_FEATURELISTID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "629" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FeatureListID" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getFeatureListID()->Display(tab+1);
			}
				break;
			case SupportedFeatures_FEATURELIST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "630" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FeatureList" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getFeatureList()->Display(tab+1);
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


BOOLEAN SupportedFeatures::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<3> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case SupportedFeatures_VENDORID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 266");
				}
				else
					sprintf(lMissingAvpInfo, "%s,266", lMissingAvpInfo);
			}
				break;
			case SupportedFeatures_FEATURELISTID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 629");
				}
				else
					sprintf(lMissingAvpInfo, "%s,629", lMissingAvpInfo);
			}
				break;
			case SupportedFeatures_FEATURELIST:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 630");
				}
				else
					sprintf(lMissingAvpInfo, "%s,630", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
