//@(#) $Id: DiameterTLVUtil.cc,v 1.1.2.4.2.1.2.1 2019/11/15 22:38:09 gpanand Exp $";
#include "DiameterTLVUtil.h"

//-----------------------------------------------------------------------------------------------
// METHOD       : avp_length_encode
// DESCRIPTION  :
// PARAMETER    : UINT32, byteArray
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterTLVUtil::avp_length_encode(UINT32 offset, byteArray *array)
{
	UINT32 lLength    = ((array->offset - offset ) + DIA_AVPCODE_N_FLAG_SIZE); 
	
	for ( INT32 lIndex=1; lIndex <= DIA_AVP_LEN_SIZE; lIndex++)
	{
		array->byte[offset++] = (lLength>>(8*(DIA_AVP_LEN_SIZE-lIndex)));
	}
   return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : avp_length_encode
// DESCRIPTION  :
// PARAMETER    : UINT32, byteArray
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterTLVUtil::avp_length_encode(UINT32 offset, byteArray *array, UINT32 lLen)
{
	UINT8 lPaddingLen = 0;
	if ( lLen%4 != 0)
	{
		lPaddingLen = (4 -(lLen%4));
	}

	UINT32 lLength    = (((array->offset - offset ) + DIA_AVPCODE_N_FLAG_SIZE) - lPaddingLen); 
	
	for ( INT32 lIndex=1; lIndex <= DIA_AVP_LEN_SIZE; lIndex++)
	{
		array->byte[offset++] = (lLength>>(8*(DIA_AVP_LEN_SIZE-lIndex)));
	}
   return true;
}
//-----------------------------------------------------------------------------------------------
// METHOD       : avp_msg_length_encode
// DESCRIPTION  :
// PARAMETER    : UINT32, byteArray
// RETURN       : BOOLEAN 
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterTLVUtil::avp_msg_length_encode(UINT32 offset, byteArray *array)
{ 	
	for ( int lIndex=1; lIndex <= DIA_AVP_LEN_SIZE; lIndex++)
	{
		array->byte[offset++]	= (array->offset>>(8*(DIA_AVP_LEN_SIZE-lIndex)));
	}
   return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : isVenderSpecific
// DESCRIPTION  :
// PARAMETER    : UINT32
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterTLVUtil::isVenderSpecific(UINT32 avpFlg)
{
	return ((avpFlg&DIA_GET_VENDER_SPEC_BIT)?true:false);	
}

//-----------------------------------------------------------------------------------------------
// METHOD       : isMandatoryBitSet
// DESCRIPTION  :
// PARAMETER    : UINT32
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterTLVUtil::isMandatoryBitSet(UINT32 avpFlg)
{
	return ((avpFlg&DIA_GET_MANDATARY_SPEC_BIT)?true:false);	
}

//-----------------------------------------------------------------------------------------------
// METHOD       : isProtectedBitSet
// DESCRIPTION  :
// PARAMETER    : UINT32
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterTLVUtil::isProtectedBitSet(UINT32 avpFlg)
{
	return ((avpFlg&DIA_GET_PROTECTED_SPEC_BIT)?true:false);	
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getHeaderLength
// DESCRIPTION  :
// PARAMETER    : byteArray, UINT32
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterTLVUtil::decodeMessageLength(byteArray *array, UINT32 &len)
{
	if(array->size <= DIA_HEADER_LEN)
	{
		return false;
	}
	len = ((array->byte[array->offset] << 16) | (array->byte[array->offset+1] << 8 ) | (array->byte[array->offset+2]));
	array->offset +=3;

   /* 
	if(len != array->size)
   {
      //errno = 2;
      printf (" Length Error --%d %d\n" , len, array->size);
      return false;
   } 
	*/

   return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getCommandCode
// DESCRIPTION  :
// PARAMETER    : byteArray, UINT32
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterTLVUtil::decodeCommandCode(byteArray *array, UINT32 &len )
{
	if(array->size <= DIA_HEADER_LEN)
	{
		return false;
	}
	
	INT32 lIndex = DIA_CMD_CODE_START_INDEX;
	len = ((array->byte[lIndex] << 16) | (array->byte[lIndex+1] << 8 ) | (array->byte[lIndex+2]));
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : decodeIntegerValue
// DESCRIPTION  :
// PARAMETER    : byteArray, UINT32, INT16 
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterTLVUtil::decodeIntegerValue(byteArray *array, UINT32 &len, INT16 lByteSize)
{
	INT32 lTempLen = 0;
	len = 0;
	
	if ( array->size < (array->offset + lByteSize))
	{	
		return false;
	}

	if ( lByteSize == 4)
	{
		memcpy( &lTempLen, array->byte + array->offset, lByteSize);
		len = ntohl(lTempLen);
		array->offset += lByteSize;
	}
	else
   {
      printf("DiameterTLVUtil::decodeIntegerValue lByteSize:%d \n", lByteSize);
		return false;

		//for ( INT32 lIndex=1; lIndex<= lByteSize; lIndex++)
		//{
	  // 		len |= array->byte[array->offset++]<< ((lByteSize-lIndex)*8);
	  // }
	}
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : decodeAvpCmdIntegerValue
// DESCRIPTION  :
// PARAMETER    : byteArray, UINT32, INT16 
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterTLVUtil::decodeAvpCmdIntegerValue(byteArray *array, UINT32 &len, INT16 lByteSize)
{
	INT32 lTempLen = 0;
	len = 0;
	
	if ( array->size < (array->offset + lByteSize))
	{	
		return false;
	}

	if ( lByteSize == 3)
   {
		for ( INT32 lIndex=1; lIndex<= lByteSize; lIndex++)
		{
	 		len |= array->byte[array->offset++]<< ((lByteSize-lIndex)*8);
	   }
	}
   else
   {
      printf("DiameterTLVUtil::decodeIntegerValue lByteSize:%d \n", lByteSize);
      return false;
   }
	return true;
}


//-----------------------------------------------------------------------------------------------
// METHOD       : decodeIntegerValue
// DESCRIPTION  :
// PARAMETER    : byteArray, UINT32, INT16 
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterTLVUtil::getErrMsg(INT32 mErrCode, TEXT* mName,TEXT* mErrMsg) 
{
	return true;
}

