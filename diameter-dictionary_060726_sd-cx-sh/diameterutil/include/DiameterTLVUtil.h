// @(#) $Id: DiameterTLVUtil.h,v 1.1.2.4.2.1.2.1 2019/11/15 22:39:56 gpanand Exp $";
#ifndef TSS_DIAMETER_UTIL
#define TSS_DIAMETER_UTIL

#include "DiameterStruct.h"
#include "DiameterBasicDecEnc.h"

class DiameterTLVUtil
{
   public :
   static BOOLEAN avp_length_encode(UINT32 offset, byteArray *asn1);
	static BOOLEAN avp_msg_length_encode(UINT32 offset, byteArray *asn1);
	static BOOLEAN isVenderSpecific(UINT32 avpFlg);
	static BOOLEAN isMandatoryBitSet(UINT32 avpFlg);
	static BOOLEAN isProtectedBitSet(UINT32 avpFlg);
	static BOOLEAN avp_length_decode(byteArray *array, UINT32 &len);
	static BOOLEAN avp_length_encode(UINT32 offset, byteArray *array, UINT32 lLen);
	static BOOLEAN decodeMessageLength(byteArray *array, UINT32 &lLen);
	static BOOLEAN decodeCommandCode(byteArray *array, UINT32 &lLen);
	static BOOLEAN decodeIntegerValue(byteArray *array,  UINT32 &len, INT16 lLen);
	static BOOLEAN decodeAvpCmdIntegerValue(byteArray *array,  UINT32 &len, INT16 lLen);
	static BOOLEAN getErrMsg(INT32 mErrCode, TEXT* mName,TEXT* mErrMsg);
};

#endif
