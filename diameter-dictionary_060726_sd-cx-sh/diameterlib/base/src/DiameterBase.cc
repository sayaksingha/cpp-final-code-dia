#include "base/include/DiameterBase.h"

//-----------------------------------------------------------------------------------------------
// METHOD       : DiameterBase
// DESCRIPTION  : Constructor
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
DiameterBase::DiameterBase()
{
	mDiameterMsgHeader = new DiameterMsgHeader();
}

//-----------------------------------------------------------------------------------------------
// METHOD       : DiameterBase
// DESCRIPTION  : DESTRUCTOR
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
DiameterBase::~DiameterBase()
{
	if(mDiameterMsgHeader!= NULL){
		delete mDiameterMsgHeader;
		mDiameterMsgHeader = NULL;
	}
}

//-----------------------------------------------------------------------------------------------
// METHOD       : decodeDiameterMsgHeader
// DESCRIPTION  : Decodes diameter message header
// PARAMETER    : byteArray
// RETURN       : DiameterMsgHeader
//-----------------------------------------------------------------------------------------------
DiameterMsgHeader* DiameterBase::decodeDiameterMsgHeader(byteArray *array)
{
	UINT8		lCmdFlag = 0;

	if(mDiameterMsgHeader == NULL){
		mDiameterMsgHeader = new DiameterMsgHeader();

		if(mDiameterMsgHeader == NULL){
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
			throw lTssDiaMsgException;
		}
	}

	memcpy( &mDiameterMsgHeader->mVersion, &array->byte[0],sizeof(UINT8));
	if(mDiameterMsgHeader->mVersion != 1)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_VERSION_ERR,"Version");
		throw lTssDiaMsgException;
	}

	array->offset = 1;
	if(false == DiameterTLVUtil::decodeMessageLength(array, mDiameterMsgHeader->mMsgLen))
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
		throw lTssDiaMsgException;
	}

	memcpy( &lCmdFlag, &array->byte[array->offset++],sizeof(UINT8));
	this->setCmdFlag(lCmdFlag);	if(false == DiameterTLVUtil::decodeAvpCmdIntegerValue(array, mDiameterMsgHeader->mCmdCode, DIA_CMD_CODE_SIZE))
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
		throw lTssDiaMsgException;
	}

	if(false == DiameterTLVUtil::decodeIntegerValue(array, mDiameterMsgHeader->mApplId, DIA_APPLN_ID_SIZE))
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
		throw lTssDiaMsgException;
	}

	if(false == DiameterTLVUtil::decodeIntegerValue(array, mDiameterMsgHeader->mHopByHopId, DIA_HOP_BY_HOP_ID_SIZE))
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
		throw lTssDiaMsgException;
	}

	if(false == DiameterTLVUtil::decodeIntegerValue(array, mDiameterMsgHeader->mEndToEndId, DIA_END_TO_END_ID_SIZE))
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
		throw lTssDiaMsgException;
	}

	array->offset=0;//reseting the value
	return mDiameterMsgHeader;

}

//-----------------------------------------------------------------------------------------------
// METHOD       : getDiameterMsgHeader
// DESCRIPTION  : Get Diameter message header
// PARAMETER    : NONE
// RETURN       : DiameterMsgHeader
//-----------------------------------------------------------------------------------------------
DiameterMsgHeader* DiameterBase::getDiameterMsgHeader()
{
	if( mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
	}
	return mDiameterMsgHeader;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setDiameterMsgHeader
// DESCRIPTION  : Set diameter message header
// PARAMETER    : UINT8,UINT8,UINT32,UINT32,UINT32,UINT32
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterBase::setDiameterMsgHeader( UINT8 mVersion, UINT8 mCmdFlg, UINT32 mCmdCode,
				  UINT32 mApplId, UINT32 mHopByHopId, UINT32 mEndToEndId )
{
	if( mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
	}
	try {
		this->setVersion(mVersion);
		this->setCmdFlag(mCmdFlg);
		this->setCmdCode(mCmdCode);
		this->setApplnId(mApplId);;
		this->setHopByHopId(mHopByHopId);
		this->setEndToEndId(mEndToEndId);
	} catch( TssDiameterMsgException tmde){
		throw tmde;

	}

	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setVersion
// DESCRIPTION  : Set diameter version
// PARAMETER    : UINT8
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterBase::setVersion(UINT8 mVersion)
{
	if(mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
	}
	mDiameterMsgHeader->mVersion = mVersion;
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setCmdCode
// DESCRIPTION  : Set command code
// PARAMETER    : UINT32
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterBase::setCmdCode(UINT32 cmdCode)
{
	if(mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
	}
	mDiameterMsgHeader->mCmdCode = cmdCode;
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setApplnId
// DESCRIPTION  : Set application id
// PARAMETER    : UINT32
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterBase::setApplnId(UINT32 applnId)
{
	if(mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
	}
	mDiameterMsgHeader->mApplId = applnId;
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setHopByHopId
// DESCRIPTION  : set hop by hop id
// PARAMETER    : UINT32
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterBase::setHopByHopId(UINT32 hopByHopId)
{
	if(mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
	}
	mDiameterMsgHeader->mHopByHopId = hopByHopId;
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setEndToEndId
// DESCRIPTION  : Set end to end id
// PARAMETER    : UINT32
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterBase::setEndToEndId(UINT32 endToEndId)
{
	if(mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
	}
	mDiameterMsgHeader->mEndToEndId = endToEndId;
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setCmdFlag
// DESCRIPTION  : Set command flags
// PARAMETER    : UINT8
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterBase::setCmdFlag(UINT8 cmdFlg)
{
	if(mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
	}
	mDiameterMsgHeader->mCmdFlg.rBit = (0!=CHECK_BIT(cmdFlg,TSS_DIA_MSG_REQ_BIT_POS))?1:0;
	mDiameterMsgHeader->mCmdFlg.pBit = (0!=CHECK_BIT(cmdFlg,TSS_DIA_MSG_PXY_BIT_POS))?1:0;
	mDiameterMsgHeader->mCmdFlg.eBit = (0!=CHECK_BIT(cmdFlg,TSS_DIA_MSG_ERR_BIT_POS))?1:0;
	mDiameterMsgHeader->mCmdFlg.tBit = (0!=CHECK_BIT(cmdFlg,TSS_DIA_MSG_TRANS_BIT_POS))?1:0;
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setRequestBit
// DESCRIPTION  : Set request bit
// PARAMETER    : BOOLEAN
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterBase::setRequestBit(BOOLEAN rBit)
{
	if(mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
	}
	mDiameterMsgHeader->mCmdFlg.rBit = rBit;
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setErrorBit
// DESCRIPTION  : Set Error Bit
// PARAMETER    : BOOLEAN
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterBase::setErrorBit(BOOLEAN eBit)
{
	if(mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
	}
	mDiameterMsgHeader->mCmdFlg.eBit = eBit;
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setProxyBit
// DESCRIPTION  : set proxy bit
// PARAMETER    : BOOLEAN
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN	DiameterBase::setProxyBit(BOOLEAN pBit)
{
	if(mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
	}
	mDiameterMsgHeader->mCmdFlg.pBit = pBit;
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setTransBit
// DESCRIPTION  : set transmission bit
// PARAMETER    : BOOLEAN
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN	DiameterBase::setTransBit(BOOLEAN tBit)
{
	if(mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
	}
	mDiameterMsgHeader->mCmdFlg.tBit = tBit ;
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getVersion
// DESCRIPTION  : Get version
// PARAMETER    : NONE
// RETURN       : UINT8
//-----------------------------------------------------------------------------------------------
UINT8	DiameterBase::getVersion()
{
	if(mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
	}
	return mDiameterMsgHeader->mVersion;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getCmdFlag
// DESCRIPTION  : Get command flag
// PARAMETER    : NONE
// RETURN       : UINT8
//-----------------------------------------------------------------------------------------------
UINT8	DiameterBase::getCmdFlag()
{
	if(mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
	}
	UINT8 lCmdFlg=0;
	lCmdFlg = ( mDiameterMsgHeader->mCmdFlg.rBit << TSS_DIA_MSG_REQ_BIT_POS
				| mDiameterMsgHeader->mCmdFlg.pBit << TSS_DIA_MSG_PXY_BIT_POS
				| mDiameterMsgHeader->mCmdFlg.eBit << TSS_DIA_MSG_ERR_BIT_POS
				| mDiameterMsgHeader->mCmdFlg.tBit << TSS_DIA_MSG_TRANS_BIT_POS);
	return lCmdFlg;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getCmdCode
// DESCRIPTION  : Get command code
// PARAMETER    : NONE
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
UINT32	DiameterBase::getCmdCode()
{
	if(mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
	}
	return mDiameterMsgHeader->mCmdCode;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getApplnId
// DESCRIPTION  : Get application id
// PARAMETER    : NONE
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
UINT32	DiameterBase::getApplnId()
{
	if(mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
	}
	return mDiameterMsgHeader->mApplId;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getHopByHopId
// DESCRIPTION  : Get hop by hop id
// PARAMETER    : NONE
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
UINT32	DiameterBase::getHopByHopId()
{
	if(mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
	}
	return mDiameterMsgHeader->mHopByHopId;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getEndToEndId
// DESCRIPTION  : Get end to end id
// PARAMETER    : NONE
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
UINT32	DiameterBase::getEndToEndId()
{
	if(mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
	}
	return mDiameterMsgHeader->mEndToEndId;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getRequestBit
// DESCRIPTION  : Get request bit
// PARAMETER    : NONE
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN	DiameterBase::getRequestBit()
{
	if(mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
	}
	return mDiameterMsgHeader->mCmdFlg.rBit;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getErrorBit
// DESCRIPTION  : Get error bit
// PARAMETER    : NONE
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN	DiameterBase::getErrorBit()
{
	if(mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
	}
	return mDiameterMsgHeader->mCmdFlg.eBit;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getProxyBit
// DESCRIPTION  : Get proxy bit
// PARAMETER    : NONE
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN	DiameterBase::getProxyBit()
{
	if(mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
	}
	return mDiameterMsgHeader->mCmdFlg.pBit;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getTransBit
// DESCRIPTION  : Returns transmission bit
// PARAMETER    : NONE
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN	DiameterBase::getTransBit()
{
	if(mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
	}
	return mDiameterMsgHeader->mCmdFlg.tBit;
}

INT32 DiameterBase::Decode(byteArray *array,  INT16 lMLen, UINT16 *parsedBytes)
{
	return -1;
}
INT32 DiameterBase::Encode(byteArray *array)
{
	return -1;
}
void DiameterBase::Display(UINT32 tab)
{
	return;
}
DiameterBaseInterface* DiameterBase::Find(byteArray *array, UINT32 avpCode)
{
	return NULL;
}

BOOLEAN DiameterBase::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect)
{
	return false;
}

BOOLEAN DiameterBase::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect)
{
	return false;
}

Integer32* DiameterBase::setAuthApplicationId(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

Integer32* DiameterBase::getAuthApplicationId(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

void DiameterBase::resetAuthApplicationId(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
}

list<Integer32*>* DiameterBase::getAuthApplicationIdList(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

list<Integer32*>* DiameterBase::setAuthApplicationIdList(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

void DiameterBase::resetAuthApplicationIdList(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
}

Unsigned32* DiameterBase::setCCRequestNumber(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

Unsigned32* DiameterBase::getCCRequestNumber(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

void DiameterBase::resetCCRequestNumber(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
}

CCRequestType* DiameterBase::setCCRequestType(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

CCRequestType* DiameterBase::getCCRequestType(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

void DiameterBase::resetCCRequestType(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
}

Integer32* DiameterBase::setDestModuleId(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

Integer32* DiameterBase::getDestModuleId(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

void DiameterBase::resetDestModuleId(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
}

OctetString* DiameterBase::setDestinationHost(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

OctetString* DiameterBase::getDestinationHost(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

void DiameterBase::resetDestinationHost(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
}

OctetString* DiameterBase::setDestinationRealm(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

OctetString* DiameterBase::getDestinationRealm(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

void DiameterBase::resetDestinationRealm(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
}

OctetString* DiameterBase::setOriginHost(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

OctetString* DiameterBase::getOriginHost(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

void DiameterBase::resetOriginHost(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
}

OctetString* DiameterBase::setOriginRealm(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

OctetString* DiameterBase::getOriginRealm(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

void DiameterBase::resetOriginRealm(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
}

Unsigned32* DiameterBase::setResultCode(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

Unsigned32* DiameterBase::getResultCode(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

void DiameterBase::resetResultCode(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
}

list<OctetString*>* DiameterBase::getRouteRecordList(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

list<OctetString*>* DiameterBase::setRouteRecordList(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

void DiameterBase::resetRouteRecordList(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
}

OctetString* DiameterBase::setSessionId(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

OctetString* DiameterBase::getSessionId(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

void DiameterBase::resetSessionId(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
}

Integer32* DiameterBase::setSourceModuleId(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

Integer32* DiameterBase::getSourceModuleId(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

void DiameterBase::resetSourceModuleId(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
}

OctetString* DiameterBase::setUniqueMsgRefNo(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

OctetString* DiameterBase::getUniqueMsgRefNo(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

void DiameterBase::resetUniqueMsgRefNo(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
}

OctetString* DiameterBase::setUserName(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

OctetString* DiameterBase::getUserName(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL;
}

void DiameterBase::resetUserName(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
}

std::shared_ptr<byteArray> DiameterBase::GetByteArray(){
	TssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);
	throw lTssDiaMsgException;
	return NULL; 
}

