#include "slh/include/ExperimentalResult.h"

using namespace SLH;
BOOLEAN ExperimentalResult::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

ExperimentalResult::ExperimentalResult()
{
	mVendorId = NULL;
	mExperimentalResultCode = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<2>(string("11"));
	mMandatoryAvpSetVal.reset();
}

ExperimentalResult::~ExperimentalResult()
{
	if(mVendorId != NULL)
		delete mVendorId;
	if(mExperimentalResultCode != NULL)
		delete mExperimentalResultCode;
}

Integer32* ExperimentalResult::setVendorId(){
	mMandatoryAvpSetVal [ExperimentalResult_VENDORID] = 1;
	if(mVendorId == NULL)
	{
		mVendorId = new Integer32();
		mTagsPresent[ExperimentalResult_VENDORID] = 1;
		return mVendorId;
	}
	return mVendorId;
}

void ExperimentalResult::resetVendorId(){
	mTagsPresent[ExperimentalResult_VENDORID] = 0;
	if(mVendorId != NULL)
	{
		delete mVendorId; 
		mVendorId = NULL;
	}
}

Unsigned32* ExperimentalResult::setExperimentalResultCode(){
	mMandatoryAvpSetVal [ExperimentalResult_EXPERIMENTALRESULTCODE] = 1;
	if(mExperimentalResultCode == NULL)
	{
		mExperimentalResultCode = new Unsigned32();
		mTagsPresent[ExperimentalResult_EXPERIMENTALRESULTCODE] = 1;
		return mExperimentalResultCode;
	}
	return mExperimentalResultCode;
}

void ExperimentalResult::resetExperimentalResultCode(){
	mTagsPresent[ExperimentalResult_EXPERIMENTALRESULTCODE] = 0;
	if(mExperimentalResultCode != NULL)
	{
		delete mExperimentalResultCode; 
		mExperimentalResultCode = NULL;
	}
}

Integer32* ExperimentalResult::getVendorId(){
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

Unsigned32* ExperimentalResult::getExperimentalResultCode(){
	if(NULL == mExperimentalResultCode) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExperimentalResultCode is Null");
		throw lTssDiaMsgException;
	}
	if(!mExperimentalResultCode->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mExperimentalResultCode->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExperimentalResultCode is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mExperimentalResultCode->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mExperimentalResultCode->Decode(mspByteArray.get(), mExperimentalResultCode->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExperimentalResultCode")     ;
			throw lTssDiaMsgException;
		}
		mExperimentalResultCode->mAvpDecodedFlag = true;
	}
	return mExperimentalResultCode;
}



int ExperimentalResult::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case ExperimentalResult_VENDORID:
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
			case ExperimentalResult_EXPERIMENTALRESULTCODE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(298);
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
					if(!mExperimentalResultCode->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mExperimentalResultCode->getAvpOffsetLen().first], mExperimentalResultCode->getAvpOffsetLen().second);
						array->offset += mExperimentalResultCode->getAvpOffsetLen().second;
						array->size += mExperimentalResultCode->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExperimentalResultCode");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mExperimentalResultCode->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExperimentalResultCode");
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


int ExperimentalResult::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
						mMandatoryAvpSetVal [ExperimentalResult_VENDORID] = 1;
					if( NULL == this->setVendorId())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding VendorId");
						throw lTssDiaMsgException;
					}
					mVendorId->setAvpCode(266);
					mVendorId->setAvpVendorId(lVenderId);
					mVendorId->SetDataType((DiameterDataType)1);
					mVendorId->mspByteArray = mspByteArray;
					mVendorId->mAvpDecodedFlag = false;
					mVendorId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 298:
				{
						mMandatoryAvpSetVal [ExperimentalResult_EXPERIMENTALRESULTCODE] = 1;
					if( NULL == this->setExperimentalResultCode())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExperimentalResultCode");
						throw lTssDiaMsgException;
					}
					mExperimentalResultCode->setAvpCode(298);
					mExperimentalResultCode->setAvpVendorId(lVenderId);
					mExperimentalResultCode->SetDataType((DiameterDataType)3);
					mExperimentalResultCode->mspByteArray = mspByteArray;
					mExperimentalResultCode->mAvpDecodedFlag = false;
					mExperimentalResultCode->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* ExperimentalResult::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExperimentalResult")     ;
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
			case 298:
			{
				if(mExperimentalResultCode != NULL)
					return mExperimentalResultCode->Find(array, avpCode);
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


BOOLEAN ExperimentalResult::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExperimentalResult")     ;
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
			case 298:
			{
				if(mExperimentalResultCode != NULL)
				{
					DiameterBaseInterface* inf =  mExperimentalResultCode->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> ExperimentalResult::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN ExperimentalResult::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExperimentalResult")     ;
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
			case 298:
			{
				if(mExperimentalResultCode != NULL)
				{
					DiameterBaseInterface* inf =  mExperimentalResultCode->Find(this->mspByteArray.get(), avpCode);
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


INT32 ExperimentalResult::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 ExperimentalResult::getAvpCode()
{
	return mAvpCode;
}
INT32 ExperimentalResult::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 ExperimentalResult::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 ExperimentalResult::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> ExperimentalResult::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void ExperimentalResult::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case ExperimentalResult_VENDORID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "266" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "VendorId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getVendorId()->Display(tab+1);
			}
				break;
			case ExperimentalResult_EXPERIMENTALRESULTCODE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "298" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ExperimentalResultCode" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getExperimentalResultCode()->Display(tab+1);
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


BOOLEAN ExperimentalResult::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<2> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case ExperimentalResult_VENDORID:
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
			case ExperimentalResult_EXPERIMENTALRESULTCODE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 298");
				}
				else
					sprintf(lMissingAvpInfo, "%s,298", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
