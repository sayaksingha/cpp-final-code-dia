#ifndef TSSDIAMETERMSGEXCEPTION
#define TSSDIAMETERMSGEXCEPTION

#include "DiameterConstDef.h"

class TssDiameterMsgException : public std::exception {
	INT32		mErrCode;
	TEXT		mName[TSS_MAX_EXCEPTION_NAME_LEN+1];
	TEXT		*mErrMsg;

	public:
	TssDiameterMsgException( INT32 ec, TEXT *name=NULL );
	~TssDiameterMsgException() throw();
	
	const char *	what() const throw();
	const char *	getErrMessage();
	int 				getErrorCode();
};

#endif
