#include "TssDiameterMsgException.h"


//-----------------------------------------------------------------------------------------------
// METHOD       : 
// DESCRIPTION  : 
// PARAMETER    : 
// RETURN       : 
//-----------------------------------------------------------------------------------------------
TssDiameterMsgException::TssDiameterMsgException( INT32 ec, TEXT *name ):mErrCode(ec) {
	if (name != NULL) 
		snprintf(mName, TSS_MAX_EXCEPTION_NAME_LEN, "%s",name); 
	mErrMsg = NULL;
}
//-----------------------------------------------------------------------------------------------
// METHOD       : 
// DESCRIPTION  : 
// PARAMETER    : 
// RETURN       : 
//-----------------------------------------------------------------------------------------------
TssDiameterMsgException::~TssDiameterMsgException() throw() {
	if(mErrMsg != NULL) {
	delete[] mErrMsg;
	//	delete mErrMsg;
		mErrMsg=NULL;
	}
}

//-----------------------------------------------------------------------------------------------
// METHOD       : 
// DESCRIPTION  : 
// PARAMETER    : 
// RETURN       : 
//-----------------------------------------------------------------------------------------------
const char* TssDiameterMsgException::what() const throw(){
	return "DiameterMsgException";
}

//-----------------------------------------------------------------------------------------------
// METHOD       : 
// DESCRIPTION  : 
// PARAMETER    : 
// RETURN       : 
//-----------------------------------------------------------------------------------------------
const char* TssDiameterMsgException::getErrMessage(){
	//mErrMsg = new TEXT[TSS_MAX_EXCEPTION_STR_LEN];
	//DiameterTLVUtil::getErrMsg(mErrCode, mName, mErrMsg);
	return mName;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : 
// DESCRIPTION  : 
// PARAMETER    : 
// RETURN       : 
//-----------------------------------------------------------------------------------------------
int TssDiameterMsgException::getErrorCode(){
	return mErrCode;
}

