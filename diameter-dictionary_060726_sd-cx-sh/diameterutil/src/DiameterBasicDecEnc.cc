static const char *id = " @(#) $Id: DiameterBasicDecEnc.cc,v 1.1.2.4.2.1.2.13 2019/12/03 22:55:10 gpanand Exp $";
//-----------------------------------------------------------------------------
// NAME           : DiameterBasicDecEnc.cc
//
// COPYRIGHT      : TSS -- Copyright (C) 2009 Tayana Software Solutions Pvt Ltd.,
//                  All rights reserved. No part of this computer program
//                  may be used or reproduced in any form by any
//                  means without prior written permission of
//                  Tayana Software Solutions Pvt Ltd.
//
// Originated     :                       Date:
//----------------------------------------------------------------------------
#include "DiameterBasicDecEnc.h"


//-----------------------------------------------------------------------------------------------
// METHOD       : nibbleswap_decode
// DESCRIPTION  :
// PARAMETER    : byteArray, address, length
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
static int  nibbleswap_decode(byteArray* param, unsigned char* address, unsigned length)
{
   static char AddressToString[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '#', 'a', 'b', 'c', 'f'};
   unsigned lByteIndex = 0;
   unsigned lEndOctet = param->offset + length - 1;

   for (lByteIndex = 0; param->offset < lEndOctet && lByteIndex < SS7_MAX_ADDRESS_LEN; param->offset++)
   {
      address[lByteIndex++] =
         AddressToString[(param->byte[param->offset] & LOWER_NIBBLE_MASK)];
      address[lByteIndex++] =
         AddressToString[((param->byte[param->offset] & UPPER_NIBBLE_MASK) >>
               ONE_NIBBLE_SHIFT)];
   }
   {
      address[lByteIndex++] =
         AddressToString[(param->byte[param->offset] & LOWER_NIBBLE_MASK)];
      if (NIBBLE_FILLER != (param->byte[param->offset] & UPPER_NIBBLE_MASK))
      {
         address[lByteIndex++] =
            AddressToString[((param->byte[param->offset] & UPPER_NIBBLE_MASK) >>
                  ONE_NIBBLE_SHIFT)];
      }
   }
   param->offset++;
   address[lByteIndex] = NULLPTR;

   return 1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : nibbleswap_encode
// DESCRIPTION  :
// PARAMETER    : byteArray*, unsigned, unsigned char*, unsigned
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
static int nibbleswap_encode(byteArray* param, unsigned lWriteIdx, unsigned char* address, unsigned lAddrLen)
{
   for (unsigned char lByteIndex = 0; lByteIndex < lAddrLen; lByteIndex += 2)
   {
      param->byte[param->offset] = BYTE_RESET_VAL;
      if ('\0' == address[lByteIndex +1])
      {
         param->byte[param->offset] = NIBBLE_FILLER;
      }
      else
      {
         switch (address[lByteIndex +1])
         {
            case '*':
               param->byte[param->offset] = 0xA0;
               break;
            case '#':
               param->byte[param->offset] = 0xB0;
               break;
            case 'a':
               param->byte[param->offset] = 0xC0;
               break;
            case 'b':
               param->byte[param->offset] = 0xD0;
               break;
            case 'c':
               param->byte[param->offset] = 0xE0;
               break;
            case 'f':
               param->byte[param->offset] = 0xF0;
               break;
            default:
               param->byte[param->offset] = ((address[lByteIndex +1] - ASCII_OFFSET) &
                     LOWER_NIBBLE_MASK) << ONE_NIBBLE_SHIFT;
            break;
         }
      }
      switch (address[lByteIndex])
      {
         case '*':
            param->byte[param->offset] |= 0x0A;
            break;
         case '#':
            param->byte[param->offset] |= 0x0B;
            break;
         case 'a':
            param->byte[param->offset] |= 0x0C;
            break;
         case 'b':
            param->byte[param->offset] |= 0x0D;
            break;
         case 'c':
            param->byte[param->offset] |= 0x0E;
            break;
         case 'f':
            param->byte[param->offset] |= 0x0F;
            break;
         default:
            param->byte[param->offset] |= ((address[lByteIndex] - ASCII_OFFSET) &
                  LOWER_NIBBLE_MASK);
         break;
      }

      param->offset++;
   }

   return 1;
}


//-----------------------------------------------------------------------------------------------
// METHOD       : NIBBLESWAP_DECODE
// DESCRIPTION  :
// PARAMETER    : byteArray, address, length
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32  NIBBLESWAP_DECODE(byteArray* param, TEXT* address, UINT16 length)
{
	static char AddressToString[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '#', 'a', 'b', 'c', 'f'};
   UINT16 lByteIndex = 0;
   UINT16 lEndOctet = param->offset + length - 1;

   for (lByteIndex = 0; param->offset < lEndOctet && lByteIndex < SS7_MAX_ADDRESS_LEN; param->offset++)
   {
      address[lByteIndex++] =
         AddressToString[(param->byte[param->offset] & LOWER_NIBBLE_MASK)];

      address[lByteIndex++] =
         AddressToString[((param->byte[param->offset] & UPPER_NIBBLE_MASK) >>
               ONE_NIBBLE_SHIFT)];
   }
   {
      address[lByteIndex++] =
         AddressToString[(param->byte[param->offset] & LOWER_NIBBLE_MASK)];
      if (NIBBLE_FILLER != (param->byte[param->offset] & UPPER_NIBBLE_MASK))
      {
         address[lByteIndex++] =
            AddressToString[((param->byte[param->offset] & UPPER_NIBBLE_MASK) >>
                  ONE_NIBBLE_SHIFT)];
      }
   }
   param->offset++;
   address[lByteIndex] = NULLPTR;

   return 1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : NIBBLESWAP_ENCODE
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
INT32  NIBBLESWAP_ENCODE(byteArray* param, UINT16 & lWriteIdx, TEXT* address, UINT16 lAddrLen)
{
   for (UINT8 lByteIndex = 0; lByteIndex < lAddrLen; lByteIndex += 2, lWriteIdx++)
   {
      param->byte[lWriteIdx] = BYTE_RESET_VAL;

      if ('\0' == address[lByteIndex +1])
      {
         param->byte[lWriteIdx] = NIBBLE_FILLER;
      }
      else
      {
         switch (address[lByteIndex +1])
         {
            case '*':
               param->byte[lWriteIdx] = 0xA0;
               break;
            case '#':
               param->byte[lWriteIdx] = 0xB0;
               break;
            case 'a':
               param->byte[lWriteIdx] = 0xC0;
               break;
            case 'b':
               param->byte[lWriteIdx] = 0xD0;
               break;
            case 'c':
               param->byte[lWriteIdx] = 0xE0;
               break;
            case 'f':
               param->byte[lWriteIdx] = 0xF0;
               break;
            default:
               param->byte[lWriteIdx] = ((address[lByteIndex +1] - ASCII_OFFSET) &
                     LOWER_NIBBLE_MASK) << ONE_NIBBLE_SHIFT;
               break;
         }
      }

      switch (address[lByteIndex])
      {
         case '*':
            param->byte[lWriteIdx] |= 0x0A;
            break;
         case '#':
            param->byte[lWriteIdx] |= 0x0B;
            break;
         case 'a':
            param->byte[lWriteIdx] |= 0x0C;
            break;
         case 'b':
            param->byte[lWriteIdx] |= 0x0D;
            break;
         case 'c':
            param->byte[lWriteIdx] |= 0x0E;
            break;
         case 'f':
            param->byte[lWriteIdx] |= 0x0F;
            break;
         default:
            param->byte[lWriteIdx] |= ((address[lByteIndex] - ASCII_OFFSET) &
                  LOWER_NIBBLE_MASK);
            break;
      }

      //return 1;
   }

   return 1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Constructor
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
Integer32::Integer32(INT32 minValue, INT32 maxValue):minValue(minValue),maxValue(maxValue)
{
   rangeSet = true;
   value = 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Constructor
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
Integer32::Integer32(INT32 val)
{
   value = val;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Constructor
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
Integer32::Integer32()
{
   value = 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Destructor
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
Integer32::~Integer32()
{

}

//-----------------------------------------------------------------------------------------------
// METHOD       : Destructor
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
//Integer32::Integer32(const Integer32& obj)
//{
	//cout<<"Integer32::copy constructor\n";
//	value = obj.value;
//}

//-----------------------------------------------------------------------------------------------
// METHOD       : operator overloaded ==
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN Integer32::operator==(const Integer32& obj)
{
   if(value == obj.value)
      return true;
   return false;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : operator overloaded <
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN Integer32::operator<(const Integer32& obj)
{
   if(value < obj.value)
      return true;
   return false;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : ToString
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
string Integer32::ToString()
{
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
      mAvpDecodedFlag = true;
   }

	return to_string(value);
}

//Added by Abhishek
string OctetString::ToHexString(UINT32 tab)
{
    if (!mAvpDecodedFlag)
    {
        mspByteArray.get()->offset = 0;
        mspByteArray.get()->offset = mAvpOffsetLen.first;
        UINT16 bytesParsed = 0;
        if (-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
            mAvpDecodedFlag = true;
    }

    // Use a stringstream to build the hex string
    std::stringstream ss;

    // Loop through each byte of the octet string's value
    for (UINT8 lTemp = 0; lTemp < mLength; ++lTemp)
    {
        // Set up the output format for hex, uppercase, and zero-padding
        ss << std::uppercase << std::hex << std::setw(2) << std::setfill('0')
           << static_cast<int>(value[lTemp]);

        // Add a space for readability, except after the last byte, If Required
        if (lTemp < mLength - 1)
        {
            ss << "";
        }
    }

    return ss.str();
}
//-----------------------------------------------------------------------------------------------
// METHOD       : getValue
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Integer32::getValue()
{
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
        mAvpDecodedFlag = true;
     else
     {
        TEXT lMessage[100] = "";
        snprintf(lMessage, sizeof(lMessage), "Error Decoding AVP %d Type:Integer32", mAvpCode);
        TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, lMessage);
        throw lTssDiaMsgException;
     } 
   }

   if(this != NULL)
      return this->value;
   else
      return -1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setValue
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Integer32::setValue(INT32 val)
{
   if(this->CheckBoundary(val))
   {
      value = val;
      mAvpDecodedFlag = true;
      return 0;
   }
    
	//errno = 1; //Value out of range
   return -1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpCode
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
UINT32 Integer32::getAvpCode()
{
	if(this != NULL)
		return this->mAvpCode;
	else
		return -1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpCode
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Integer32::setAvpCode(UINT32 avpCode)
{
      mAvpCode = avpCode;
      return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpVendorId
// DESCRIPTION  :
// PARAMETER    : 
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
UINT32 Integer32::getAvpVendorId()
{
   return this->mAvpVendorId;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpVendorId
// DESCRIPTION  :
// PARAMETER    : UINT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Integer32::setAvpVendorId(UINT32 avpVendorId)
{
   mAvpVendorId = avpVendorId;
   return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpOffsetLen
// DESCRIPTION  :
// PARAMETER    : 
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
pair<UINT32,UINT16> Integer32::getAvpOffsetLen()
{
   return mAvpOffsetLen;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpOffsetLen
// DESCRIPTION  :
// PARAMETER    : INT16,INT16
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32  Integer32::setAvpOffsetLen(UINT32 offset,UINT16 length)
{
   mAvpOffsetLen = make_pair(offset,length);
   return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Find
// DESCRIPTION  :
// PARAMETER    : UINT32
// RETURN       : DiameterBaseInterface*
//-----------------------------------------------------------------------------------------------
DiameterBaseInterface* Integer32::Find(byteArray *array,UINT32 avpCode)
{
	if( mAvpCode == avpCode)
		return this;	

	return NULL;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : FindAll
// DESCRIPTION  :
// PARAMETER    : byteArray,UINT32,list<DiameterBaseInterface*>&
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN	Integer32::FindAll(byteArray *array,UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect)
{
   return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Display 
// DESCRIPTION  :
// PARAMETER    : UINT32
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
void Integer32::Display(UINT32 tab)
{
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
      mAvpDecodedFlag = true;
   }

   TEXT temp[30];
   sprintf(temp, "%%%ds %%s %%d\n", tab * 3);
   printf(temp, " ", "Integer32 Value is : ", value);
}

//-----------------------------------------------------------------------------------------------
// METHOD       : CheckBoundary
// DESCRIPTION  :
// PARAMETER    : UINT32
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN Integer32::CheckBoundary(const INT32 value)
{
	// Not Using as of Now
	
   /*if(rangeSet && (value < minValue || value > maxValue))
   {
      errno = 1; //Value out of range
      return false;
   }
   else*/
      return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Decode
// DESCRIPTION  : Decodes integer value from Byte array
// PARAMETER    : byteArray, INT16, UINT16
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
INT32 Integer32::Decode(byteArray* array, INT16 length, UINT16* bytesParsed)
{
   *bytesParsed = length;

   for(INT16 lReadIdx = 0; lReadIdx < length; lReadIdx++)
   {
      value = (value << 8) | (array->byte[array->offset++] & 0xFF);
   }
   
   mAvpDecodedFlag = true;
   return this->CheckBoundary(value)?1:-1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Decode
// DESCRIPTION  : Decodes integer value from Byte array
// PARAMETER    : byteArray,  UINT16
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
INT32	Integer32::Decode(byteArray* array, UINT16* bytesParsed)
{
   *bytesParsed = 4;

   for(INT16 lReadIdx = 0; lReadIdx < *bytesParsed; lReadIdx++)
   {
      value = (value << 8) | (array->byte[array->offset++] & 0xFF);
   }

   mAvpDecodedFlag = true;
   return this->CheckBoundary(value)?1:-1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Encode
// DESCRIPTION  : Encodes integer value into Byte array in network byte order
// PARAMETER    : byteArray
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
//INT32 Integer32::Encode(array *byteArray)
INT32 Integer32::Encode(byteArray *array)
{
   UINT32 length = 4;

   array->size += length;

   for(UINT32 lTemp = 0; lTemp < length; lTemp++)
   {
      array->byte[array->offset++] = (TEXT)(value >> ((length - lTemp - 1) * 8)) & 0xFF;
   }

   return 0;
}


//-----------------------------------------------------------------------------------------------
// METHOD       : Constructor
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
Integer64::Integer64(INT64 minValue, INT64 maxValue):minValue(minValue),maxValue(maxValue)
{
   rangeSet = true;
   value = 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Constructor
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
Integer64::Integer64(INT64 val)
{
   value = val;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Constructor
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
Integer64::Integer64()
{
   value = 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Destructor
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
Integer64::~Integer64()
{
}

//-----------------------------------------------------------------------------------------------
// METHOD       : copy constructor
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
//Integer64::Integer64(const Integer64& obj)
//{
	//cout<<"Integer64::copy constructor\n";
//	value = obj.value;
//}

//-----------------------------------------------------------------------------------------------
// METHOD       : operator overloaded ==
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN Integer64::operator==(const Integer64& obj)
{
   if(value == obj.value)
      return true;
   return false;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : operator overloaded <
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN Integer64::operator<(const Integer64& obj)
{
   if(value < obj.value)
      return true;
   return false;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : ToString
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
string Integer64::ToString()
{
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
      mAvpDecodedFlag = true;
   }

	return to_string(value);
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getValue
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT64 Integer64::getValue()
{
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
        mAvpDecodedFlag = true;
     else
     {
        TEXT lMessage[100] = "";
        snprintf(lMessage, sizeof(lMessage), "Error Decoding AVP %d Type:Integer64", mAvpCode);
        TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, lMessage);
        throw lTssDiaMsgException;
     } 
   }

   if(this != NULL)
      return this->value;
   else
      return -1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setValue
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Integer64::setValue(INT64 val)
{
   if(this->CheckBoundary(val))
   {
      value = val;
      mAvpDecodedFlag = true;
      return 0;
   }

       // errno = 1; //Value out of range
   return -1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpCode
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
UINT32 Integer64::getAvpCode()
{
	if(this != NULL)
		return this->mAvpCode;
	else
		return -1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpCode
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Integer64::setAvpCode(UINT32 avpCode)
{
      mAvpCode = avpCode;
   
      return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpVendorId
// DESCRIPTION  :
// PARAMETER    : 
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
UINT32 Integer64::getAvpVendorId()
{
   return this->mAvpVendorId;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpVendorId
// DESCRIPTION  :
// PARAMETER    : UINT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Integer64::setAvpVendorId(UINT32 avpVendorId)
{
   mAvpVendorId = avpVendorId;
   return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpOffsetLen
// DESCRIPTION  :
// PARAMETER    : 
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
pair<UINT32,UINT16> Integer64::getAvpOffsetLen()
{
   return mAvpOffsetLen;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpOffsetLen
// DESCRIPTION  :
// PARAMETER    : INT16,INT16
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32  Integer64::setAvpOffsetLen(UINT32 offset,UINT16 length)
{
   mAvpOffsetLen = make_pair(offset,length);
   return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Find
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : DiameterBaseInterface*
//-----------------------------------------------------------------------------------------------
DiameterBaseInterface* Integer64::Find(byteArray *array,UINT32 avpCode)
{
   if( mAvpCode == avpCode)
      return this;

   return NULL;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : FindALl
// DESCRIPTION  :
// PARAMETER    : byteArray, UINT32, list<DiameterBaseInterface*>&
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN	Integer64::FindAll(byteArray *array,UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect)
{
   return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Display
// DESCRIPTION  :
// PARAMETER    : UINT32
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
void Integer64::Display(UINT32 tab)
{
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
      mAvpDecodedFlag = true;
   }

   TEXT temp[30];
   sprintf(temp, "%%%ds %%s %%ld\n", tab * 3);
   printf(temp, " ", "Integer64 Value is : ", value);
}

//-----------------------------------------------------------------------------------------------
// METHOD       : CheckBoundary
// DESCRIPTION  :
// PARAMETER    : UINT32
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN Integer64::CheckBoundary(const INT64 value)
{
        // Not Using as of Now

   /*if(rangeSet && (value < minValue || value > maxValue))
   {
      errno = 1; //Value out of range
      return false;
   }
   else*/
      return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Decode
// DESCRIPTION  : Decodes integer value from Byte array
// PARAMETER    : byteArray, INT16, UINT16
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
INT32 Integer64::Decode(byteArray* array, INT16 length, UINT16* bytesParsed)
{
   *bytesParsed = length;

   for(INT16 lReadIdx = 0; lReadIdx < length; lReadIdx++)
   {
      value = (value << 8) | (array->byte[array->offset++] & 0xFF);
   }

   mAvpDecodedFlag = true;
   return this->CheckBoundary(value)?1:-1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Decode
// DESCRIPTION  : Decodes integer value from Byte array
// PARAMETER    : byteArray,  UINT16
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
INT32   Integer64::Decode(byteArray* array, UINT16* bytesParsed)
{
   *bytesParsed = 8;

   for(INT16 lReadIdx = 0; lReadIdx < *bytesParsed; lReadIdx++)
   {
      value = (value << 8) | (array->byte[array->offset++] & 0xFF);
   }

   mAvpDecodedFlag = true;
   return this->CheckBoundary(value)?1:-1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Encode
// DESCRIPTION  : Encodes integer value into Byte array in network byte order
// PARAMETER    : byteArray
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
//INT32 Integer64::Encode(array *byteArray)
INT32 Integer64::Encode(byteArray* array)
{
   UINT32 length = 8;

   array->size += length;

   for(UINT32 lTemp = 0; lTemp < length; lTemp++)
   {
      array->byte[array->offset++] = (TEXT)(value >> ((length - lTemp - 1) * 8)) & 0xFF;
   }

   return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Constructor
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
Unsigned32::Unsigned32(UINT32 minValue, UINT32 maxValue):minValue(minValue),maxValue(maxValue)
{
   rangeSet = true;
   value = 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Constructor
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
Unsigned32::Unsigned32(UINT32 val)
{
   value = val;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Constructor
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
Unsigned32::Unsigned32()
{
   value = 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Destructor
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
Unsigned32::~Unsigned32()
{
}

//-----------------------------------------------------------------------------------------------
// METHOD       : copy constructor
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
//Unsigned32::Unsigned32(const Unsigned32& obj)
//{
	//cout<<"Unsigned32::copy constructor\n";
//	value = obj.value;
//}

//-----------------------------------------------------------------------------------------------
// METHOD       : operator overloaded == 
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN Unsigned32::operator==(const Unsigned32& obj)
{
	if(value == obj.value)
		return true;
	return false;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : operator overloaded < 
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN Unsigned32::operator<(const Unsigned32& obj)
{
	if(value	< obj.value)
		return true;
	return false;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getValue
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
UINT32 Unsigned32::getValue()
{
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
        mAvpDecodedFlag = true;
     else
     {
        TEXT lMessage[100] = "";
        snprintf(lMessage, sizeof(lMessage), "Error Decoding AVP %d Type:Unsigned32", mAvpCode);
        TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, lMessage);
        throw lTssDiaMsgException;
     } 
   }

   if(this != NULL)
      return this->value;
   else
      return -1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setValue
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Unsigned32::setValue(UINT32 val)
{
   if(this->CheckBoundary(val))
   {
      value = val;
      mAvpDecodedFlag = true;
      return 0;
   }
   
	//errno = 1; //Value out of range
   return -1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpCode
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
UINT32 Unsigned32::getAvpCode()
{
	if(this != NULL)
		return this->mAvpCode;
	else
		return -1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpCode
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Unsigned32::setAvpCode(UINT32 avpCode)
{
      mAvpCode = avpCode;
   
      return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpVendorId
// DESCRIPTION  :
// PARAMETER    : 
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
UINT32 Unsigned32::getAvpVendorId()
{
   return this->mAvpVendorId;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpVendorId
// DESCRIPTION  :
// PARAMETER    : UINT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Unsigned32::setAvpVendorId(UINT32 avpVendorId)
{
   mAvpVendorId = avpVendorId;
   return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpOffsetLen
// DESCRIPTION  :
// PARAMETER    : 
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
pair<UINT32,UINT16> Unsigned32::getAvpOffsetLen()
{
   return mAvpOffsetLen;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpOffsetLen
// DESCRIPTION  :
// PARAMETER    : INT16,INT16
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32  Unsigned32::setAvpOffsetLen(UINT32 offset,UINT16 length)
{
   mAvpOffsetLen = make_pair(offset,length);
   return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Find
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : DiameterBaseInterface*
//-----------------------------------------------------------------------------------------------
DiameterBaseInterface* Unsigned32::Find(byteArray *array,UINT32 avpCode)
{
   if( mAvpCode == avpCode)
      return this;

   return NULL;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : FindAll
// DESCRIPTION  :
// PARAMETER    : byteArray,UINT32,list<DiameterBaseInterface*>&
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN	Unsigned32::FindAll(byteArray *array,UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect)
{
   return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setValue
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
string Unsigned32::ToString()
{
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
      mAvpDecodedFlag = true;
   }

	return to_string(value);
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Display 
// DESCRIPTION  :
// PARAMETER    : UINT32
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
void Unsigned32::Display(UINT32 tab)
{
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
      mAvpDecodedFlag = true;
   }

   TEXT temp[30];
   sprintf(temp, "%%%ds %%s %%d\n", tab * 3);
   printf(temp, " ", "Unsigned32 Value is : ", value);
}

//-----------------------------------------------------------------------------------------------
// METHOD       : CheckBoundary
// DESCRIPTION  :
// PARAMETER    : UINT32
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN Unsigned32::CheckBoundary(const UINT32 value)
{
	// Not Using as of Now
	
   /*if(rangeSet && (value < minValue || value > maxValue))
   {
      errno = 1; //Value out of range
      return false;
   }
   else*/
      return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Decode
// DESCRIPTION  : Decodes integer value from Byte array
// PARAMETER    : byteArray, INT16, UINT16
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
INT32 Unsigned32::Decode(byteArray* array, INT16 length, UINT16* bytesParsed)
{
   *bytesParsed = length;

   for(INT16 lReadIdx = 0; lReadIdx < length; lReadIdx++)
   {
      value = (value << 8) | (array->byte[array->offset++] & 0xFF);
   }

   mAvpDecodedFlag = true;
   return this->CheckBoundary(value)?1:-1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Decode
// DESCRIPTION  : Decodes integer value from Byte array
// PARAMETER    : byteArray,  UINT16
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
INT32	Unsigned32::Decode(byteArray* array, UINT16* bytesParsed)
{
   *bytesParsed = 4;

   for(INT16 lReadIdx = 0; lReadIdx < *bytesParsed; lReadIdx++)
   {
      value = (value << 8) | (array->byte[array->offset++] & 0xFF);
   }

   mAvpDecodedFlag = true;
   return this->CheckBoundary(value)?1:-1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Encode
// DESCRIPTION  : Encodes integer value into Byte array in network byte order
// PARAMETER    : byteArray
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
INT32 Unsigned32::Encode(byteArray* array)
{
   UINT32 length = 4;

   array->size += length;

   for(UINT32 lTemp = 0; lTemp < length; lTemp++)
   {
      array->byte[array->offset++] = (TEXT)(value >> ((length - lTemp - 1) * 8)) & 0xFF;
   }

   return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Constructor
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
Unsigned64::Unsigned64(UINT64 minValue, UINT64 maxValue):minValue(minValue),maxValue(maxValue)
{
   rangeSet = true;
   value = 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Constructor
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
Unsigned64::Unsigned64(UINT64 val)
{
   value = val;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Constructor
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
Unsigned64::Unsigned64()
{
   value = 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Destructor
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
Unsigned64::~Unsigned64()
{
}

//-----------------------------------------------------------------------------------------------
// METHOD       : copy constructor
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
//Unsigned64::Unsigned64(const Unsigned64& obj)
//{
	//cout<<"Unsigned64::copy constructor\n";
//	value = obj.value;
//}

//-----------------------------------------------------------------------------------------------
// METHOD       : operator overloaded == 
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN Unsigned64::operator==(const Unsigned64& obj)
{
	if(value == obj.value)
		return true;
	return false;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : operator overloaded < 
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN Unsigned64::operator<(const Unsigned64& obj)
{
	if(value	< obj.value)
		return true;
	return false;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setValue
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
string Unsigned64::ToString()
{
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
      mAvpDecodedFlag = true;
   }

	return to_string(value);
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getValue
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
UINT64 Unsigned64::getValue()
{ 
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
        mAvpDecodedFlag = true;
     else
     {
        TEXT lMessage[100] = "";
        snprintf(lMessage, sizeof(lMessage), "Error Decoding AVP %d Type:Unsigned64", mAvpCode);
        TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, lMessage);
        throw lTssDiaMsgException;
     } 
   }

   if(this != NULL)
      return this->value;
   else
      return -1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setValue
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Unsigned64::setValue(UINT64 val)
{
   if(this->CheckBoundary(val))
   {
      value = val;
      mAvpDecodedFlag = true;
      return 0;
   }

        //errno = 1; //Value out of range
   return -1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpCode
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
UINT32 Unsigned64::getAvpCode()
{
	if(this != NULL)
		return this->mAvpCode;
	else
		return -1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpCode
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Unsigned64::setAvpCode(UINT32 avpCode)
{
      mAvpCode = avpCode;
   
      return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpVendorId
// DESCRIPTION  :
// PARAMETER    : 
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
UINT32 Unsigned64::getAvpVendorId()
{
   return this->mAvpVendorId;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpVendorId
// DESCRIPTION  :
// PARAMETER    : UINT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Unsigned64::setAvpVendorId(UINT32 avpVendorId)
{
   mAvpVendorId = avpVendorId;
   return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpOffsetLen
// DESCRIPTION  :
// PARAMETER    : 
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
pair<UINT32,UINT16> Unsigned64::getAvpOffsetLen()
{
   return mAvpOffsetLen;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpOffsetLen
// DESCRIPTION  :
// PARAMETER    : INT16,INT16
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32  Unsigned64::setAvpOffsetLen(UINT32 offset,UINT16 length)
{
   mAvpOffsetLen = make_pair(offset,length);
   return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Find
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : DiameterBaseInterface*
//-----------------------------------------------------------------------------------------------
DiameterBaseInterface* Unsigned64::Find(byteArray *array,UINT32 avpCode)
{
   if( mAvpCode == avpCode)
      return this;

   return NULL;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : FindAll
// DESCRIPTION  :
// PARAMETER    : byteArray,UINT32,list<DiameterBaseInterface*>&
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN	Unsigned64::FindAll(byteArray *array,UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect)
{
   return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Display
// DESCRIPTION  :
// PARAMETER    : UINT32
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
void Unsigned64::Display(UINT32 tab)
{
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
      mAvpDecodedFlag = true;
   }

   TEXT temp[30];
   sprintf(temp, "%%%ds %%s %%d\n", tab * 3);
   printf(temp, " ", "Unsigned64 Value is : ", value);
}

//-----------------------------------------------------------------------------------------------
// METHOD       : CheckBoundary
// DESCRIPTION  :
// PARAMETER    : UINT32
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN Unsigned64::CheckBoundary(const UINT64 value)
{
        // Not Using as of Now

   /*if(rangeSet && (value < minValue || value > maxValue))
   {
      errno = 1; //Value out of range
      return false;
   }
   else*/
      return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Decode
// DESCRIPTION  : Decodes integer value from Byte array
// PARAMETER    : byteArray, INT16, UINT16
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
INT32 Unsigned64::Decode(byteArray* array, INT16 length, UINT16* bytesParsed)
{
   *bytesParsed = length;

   for(INT16 lReadIdx = 0; lReadIdx < length; lReadIdx++)
   {
      value = (value << 8) | (array->byte[array->offset++] & 0xFF);
   }

   mAvpDecodedFlag = true;
   return this->CheckBoundary(value)?1:-1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Decode
// DESCRIPTION  : Decodes integer value from Byte array
// PARAMETER    : byteArray,  UINT16
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
INT32   Unsigned64::Decode(byteArray* array, UINT16* bytesParsed)
{
   *bytesParsed = 8;

   for(INT16 lReadIdx = 0; lReadIdx < *bytesParsed; lReadIdx++)
   {
      value = (value << 8) | (array->byte[array->offset++] & 0xFF);
   }

   mAvpDecodedFlag = true;
   return this->CheckBoundary(value)?1:-1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Encode
// DESCRIPTION  : Encodes integer value into Byte array in network byte order
// PARAMETER    : byteArray
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
INT32 Unsigned64::Encode(byteArray* array)
{
   UINT32 length = 8;

   array->size += length;

   for(UINT32 lTemp = 0; lTemp < length; lTemp++)
   {
      array->byte[array->offset++] = (TEXT)(value >> ((length - lTemp - 1) * 8)) & 0xFF;
   }

   return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : OctetString()
// DESCRIPTION  : Constructor
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
OctetString::OctetString()
{
   mLength = 0;
   value   = NULL;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : OctetString()
// DESCRIPTION  :	Constructor 
// PARAMETER    : UINT32, UINT32
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
OctetString::OctetString(UINT32 min, UINT32 max):minSize(min),maxSize(max)
{
   mLength = 0;
   value   = NULL;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : ~OctetString()
// DESCRIPTION  : Destructor
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
OctetString::~OctetString()
{
   if(value != NULL)
      free(value);
}

//-----------------------------------------------------------------------------------------------
// METHOD       : OctetString()
// DESCRIPTION  : Copy constructor
// PARAMETER    : OctetString&
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
//OctetString::OctetString(const OctetString& obj)
//{
	//cout<<"OctetString::copy constructor\n";
//	mLength = obj.mLength;
 //  value = (unsigned char *)calloc(mLength, sizeof(char));
//	memcpy(value, obj.value, mLength);	
//}

//-----------------------------------------------------------------------------------------------
// METHOD       : OctetString()
// DESCRIPTION  : Copy assignment operator
// PARAMETER    : OctetString&
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
//OctetString& OctetString::operator=(const OctetString& obj)
//{
//	mLength = obj.mLength;
//	value = (unsigned char *)calloc(mLength, sizeof(char));
//	memcpy(value, obj.value, mLength);
//}

//-----------------------------------------------------------------------------------------------
// METHOD       : operator overloaded == 
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN OctetString::operator==(const OctetString& obj)
{	
	if(mLength != obj.mLength) 
		return false;

	if(0 == memcmp (value,obj.value,mLength))
		return true;

	return false;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : operator overloaded < 
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN OctetString::operator<(const OctetString& obj)
{
	if(mLength != obj.mLength)
		return false;

	if(0 > memcmp (value,obj.value,mLength))
		return true;

	return false;
}


//-----------------------------------------------------------------------------------------------
// METHOD       : ToString
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : string
//-----------------------------------------------------------------------------------------------
string OctetString::ToString()
{
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
      mAvpDecodedFlag = true;
   }

	return string(value,value+mLength);
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpCode
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
UINT32 OctetString::getAvpCode()
{
	if(this != NULL)
		return this->mAvpCode;
	else
		return -1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpCode
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 OctetString::setAvpCode(UINT32 avpCode)
{
      mAvpCode = avpCode;
   
      return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpVendorId
// DESCRIPTION  :
// PARAMETER    : 
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
UINT32 OctetString::getAvpVendorId()
{
   return this->mAvpVendorId;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpVendorId
// DESCRIPTION  :
// PARAMETER    : UINT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 OctetString::setAvpVendorId(UINT32 avpVendorId)
{
   mAvpVendorId = avpVendorId;
   return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpOffsetLen
// DESCRIPTION  :
// PARAMETER    : 
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
pair<UINT32,UINT16> OctetString::getAvpOffsetLen()
{
   return mAvpOffsetLen;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpOffsetLen
// DESCRIPTION  :
// PARAMETER    : INT16,INT16
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 OctetString::setAvpOffsetLen(UINT32 offset,UINT16 length)
{
   mAvpOffsetLen = make_pair(offset,length);
   return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Find
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : DiameterBaseInterface*
//-----------------------------------------------------------------------------------------------
DiameterBaseInterface* OctetString::Find(byteArray *array,UINT32 avpCode)
{
   if( mAvpCode == avpCode)
      return this;

   return NULL;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : FindAll
// DESCRIPTION  :
// PARAMETER    : byteArray,UINT32,list<DiameterBaseInterface*>&
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN	OctetString::FindAll(byteArray *array,UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect)
{
   return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Decode
// DESCRIPTION  :	Decodes Byte array with DataType Octet String
// PARAMETER    : byteArray, INT16, UINT16
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 OctetString::Decode(byteArray *array, INT16 length, UINT16* parsedBytes)
{
   mLength = length;
   value = (unsigned char *)calloc(length, sizeof(char));
   memcpy(value, (array->byte) + array->offset, length);

   *parsedBytes = length;
   array->offset += length;

   mAvpDecodedFlag = true;
   return 1;
}
//-----------------------------------------------------------------------------------------------
// METHOD       : Encode
// DESCRIPTION  : Encodes Byte array with DataType Octet String
// PARAMETER    : byteArray
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 OctetString::Encode(byteArray *array)
{
	UINT8 lpadding = 0;

   memcpy( (array->byte) + array->offset , value , mLength);

	//for (int i=0; i < mLength; i++)
	//	printf("%c", value[i]);

	array->offset += mLength;

	if(mLength%4 != 0)
	{
		for(lpadding=1; lpadding <= (4-mLength%4); lpadding++)
		{
			array->byte[array->offset++] = 0x00;
		}
		array->size += mLength+(lpadding-1);
	}
	else
	{
		array->size += mLength;
	}

   return 1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getLength
// DESCRIPTION  : get octetstring length.
// PARAMETER    : UINT8*, UINT32
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
UINT16 OctetString::getLength()
{
	return mLength;
}
//-----------------------------------------------------------------------------------------------
// METHOD       : setValue
// DESCRIPTION  : Sets Value
// PARAMETER    : UINT8*, UINT32
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
UINT32 OctetString::setValue(UINT8* val, UINT32 len)
{
   if(value != NULL)
      free(value);

   mLength = len;
   value   = (unsigned char* )calloc(mLength, sizeof(char));

   if(value == NULL)
      return -1;

   memcpy(value, val, mLength);
   mAvpDecodedFlag = true;

   //value[mLength] = '\0';
   return 1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setValue
// DESCRIPTION  : Sets Value
// PARAMETER    : string&
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
UINT32 OctetString::setValue(char *val)
{
   if(value != NULL)
      free(value);

   if ( val == NULL )
      return -1;

   mLength = strlen(val);
   value   = (unsigned char* )calloc((mLength+1), sizeof(char));

   if(value == NULL)
      return -1;

   memcpy(value, val, mLength);
   mAvpDecodedFlag = true;

   value[mLength] = '\0';

   return 1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getValue()
// DESCRIPTION  :	Get Value
// PARAMETER    : NONE
// RETURN       : UINT8*
//-----------------------------------------------------------------------------------------------
UINT8* OctetString::getValue()
{
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
        mAvpDecodedFlag = true;
     else
     {
        TEXT lMessage[100] = "";
        snprintf(lMessage, sizeof(lMessage), "Error Decoding AVP %d Type:OctetString", mAvpCode);
        TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, lMessage);
        throw lTssDiaMsgException;
     } 
   }

	if(NULL != value)
		return value;
	else
   {
      TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, "Object OctetString is NULL");
		throw lTssDiaMsgException;
   }
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Display
// DESCRIPTION  : Displays value
// PARAMETER    : UINT32
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
void OctetString::Display(UINT32 tab)
{
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
      mAvpDecodedFlag = true;
   }

   TEXT temp[30];
   sprintf(temp, "%%%ds %%s \n", tab * 3);

   printf(temp, " ", "Octet String is : ");
   sprintf(temp, "%%%ds", tab * 4);
   printf(temp, "  ");

   for(UINT8 lTemp = 0; lTemp < mLength; lTemp++)
      printf(" %02X", value[lTemp]);

   printf("[%s]", value);
   printf("\n");
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Address()
// DESCRIPTION  : Constructor
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
Address::Address()
{
	mLength = 0;
	ipAddress = NULL;
	memset(value, 0, sizeof(value));
}

//-----------------------------------------------------------------------------------------------
// METHOD       : ~Address()
// DESCRIPTION  : Destructor
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
Address::~Address()
{
	if(ipAddress != NULL) 
		delete[] ipAddress;	
}


//-----------------------------------------------------------------------------------------------
// METHOD       : Address()
// DESCRIPTION  : Copy constructor
// PARAMETER    : Address&
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
//Address::Address(const Address& obj)
//{
//   mLength = obj.mLength;
//   memcpy(value, obj.value, mLength);
//   ipAddress = new TEXT[TSS_MAX_IP_ADDRESS_LEN + 1];
//   sprintf(ipAddress,obj.ipAddress);		
//}

//-----------------------------------------------------------------------------------------------
// METHOD       : Address()
// DESCRIPTION  : Copy assignment operator
// PARAMETER    : Address&
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
//Address& Address::operator=(const Address& obj)
//{
//   mLength = obj.mLength;
//   memcpy(value, obj.value, mLength);
//   ipAddress = new TEXT[TSS_MAX_IP_ADDRESS_LEN + 1];
//   sprintf(ipAddress,obj.ipAddress);		
//}

//-----------------------------------------------------------------------------------------------
// METHOD       : operator overloaded ==
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN Address::operator==(const Address& obj)
{
   if(mLength != obj.mLength)
      return false;

   if(0 == memcmp (value,obj.value,mLength))
      return true;

   return false;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : operator overloaded <
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN Address::operator<(const Address& obj)
{
   if(mLength != obj.mLength)
      return false;

   if(0 > memcmp (value,obj.value,mLength))
      return true;

   return false;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Decode
// DESCRIPTION  :	Decodes Byte array with DataType Octet String
// PARAMETER    : byteArray, INT16, UINT16
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Address::Decode(byteArray *array, INT16 length, UINT16* parsedBytes)
{

   UINT8 lTempValue[2];
   memcpy(lTempValue, (array->byte) + array->offset, 2);

   if(1 == lTempValue[1])
   {
      mLength = 6;
   }
   else if(2 == lTempValue[1])
   {
      mLength = 18;
   }
   else if(8 == lTempValue[1])
   {
      mLength = length;
   }

   memset(&value, 0, sizeof(value));
   memcpy(value, (array->byte) + array->offset, mLength);
   *parsedBytes = mLength;

   if(ipAddress)
      delete[] ipAddress;

   //ipAddress = new TEXT[TSS_MAX_IP_ADDRESS_LEN + 1];
   ipAddress = new TEXT[TSS_MAX_IPV6_ADDRESS_LEN + 1];
   //memset(ipAddress, 0, sizeof(TSS_MAX_IP_ADDRESS_LEN));
   memset(ipAddress, 0, sizeof(ipAddress));

   if(1 == value[1])
   {
      //snprintf(ipAddress, TSS_MAX_IP_ADDRESS_LEN, "%d.%d.%d.%d", value[2],value[3],value[4],value[5]);
      snprintf(ipAddress, TSS_MAX_IPV6_ADDRESS_LEN, "%d.%d.%d.%d", value[2],value[3],value[4],value[5]);
   }
   else if(2 == value[1])
   {
      snprintf(ipAddress, TSS_MAX_IPV6_ADDRESS_LEN, "%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x", value[2],value[3],value[4],value[5], value[6],value[7], value[8],value[9], value[10],value[11],value[12],value[13], value[14],value[15],value[16],value[17]);
   }
      // snprintf(ipAddress, TSS_MAX_IP_ADDRESS_LEN, "%d.%d.%d.%d", value[2],value[3],value[4],value[5]);
   else if(8 == value[1])
   {
      mLength = length-2;
      //  ============
      //value = (unsigned char *)calloc(length, sizeof(char));
      snprintf(ipAddress, TSS_MAX_IPV6_ADDRESS_LEN, "%s", value + 2);

      *parsedBytes = length;
      //array->offset += length;
   }
   //  ============
   array->offset += length;

   mAvpDecodedFlag = true;
   return 1;

}
//-----------------------------------------------------------------------------------------------
// METHOD       : Encode
// DESCRIPTION  : Encodes Byte array with DataType Octet String
// PARAMETER    : byteArray
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Address::Encode(byteArray *array)
{
   UINT8 lpadding = 0;
   //mLength = 6;	

   memcpy( (array->byte) + array->offset , value , mLength);
   array->offset += mLength;

   if(mLength%4 != 0)
   {
      for(lpadding=1; lpadding <= (4-mLength%4); lpadding++)
      {
         array->byte[array->offset++] = 0x00;
      }
      array->size += mLength+(lpadding-1);
   }
   else
   {
      array->size += mLength;
   }	

   return 1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getLength
// DESCRIPTION  : get octetstring length.
// PARAMETER    : UINT8*, UINT32
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
UINT16 Address::getLength()
{
   return mLength;
}
//-----------------------------------------------------------------------------------------------
// METHOD       : setValue
// DESCRIPTION  : Sets Value
// PARAMETER    : UINT8*, UINT32
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
UINT32 Address::setValue(UINT8* val, UINT32 len)
{
   TEXT     lIpValues[4][5];
   TEXT     *lTokens=NULL;

   memset(value, 0, sizeof(value));
   memset(lIpValues, 0, sizeof(lIpValues));

   if(ipAddress)
      delete[] ipAddress;	

   ipAddress = new TEXT[TSS_MAX_IP_ADDRESS_LEN + 1];
   memset(ipAddress, 0, sizeof(TSS_MAX_IP_ADDRESS_LEN));
   snprintf(ipAddress, TSS_MAX_IP_ADDRESS_LEN, "%s", val);

   lTokens = strtok((char*)ipAddress,".");

   for(int i = 0; i <= 3; i++)
   {
      if(lTokens == NULL)
         break;
      strcpy(lIpValues[i], lTokens);
      lTokens = strtok(NULL, ".");
   }

   mLength = 6;

   value[0] = 0X00;	
   value[1] = 0X01;
  
   try
   { 
      value[2] = stoi(lIpValues[0]);
      value[3] = stoi(lIpValues[1]);
      value[4] = stoi(lIpValues[2]);
      value[5] = stoi(lIpValues[3]);
   }
   catch (...)
   {

   }
   //value[6] = 0X00; 
   //value[7] = 0X00; 



   mAvpDecodedFlag = true;
   return 1;
}
//-----------------------------------------------------------------------------------------------
// METHOD       : setValue
// DESCRIPTION  : Sets Value
// PARAMETER    : char*
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
UINT32 Address::setValue(char* val)
{
   TEXT     lIpValues[4][5];
   TEXT     *lTokens;

   memset(value, 0, sizeof(value));
   memset(lIpValues, 0, sizeof(lIpValues));

   if(ipAddress)
      delete[] ipAddress;

   ipAddress = new TEXT[TSS_MAX_IP_ADDRESS_LEN + 1]; 
   memset(ipAddress, 0, sizeof(TSS_MAX_IP_ADDRESS_LEN));
   snprintf(ipAddress, TSS_MAX_IP_ADDRESS_LEN, "%s", val);

   lTokens = strtok(ipAddress,".");

   for(int i = 0; i <= 3; i++)
   {
      if(lTokens == NULL)
         break;
      strcpy(lIpValues[i], lTokens);
      lTokens = strtok(NULL, ".");
   }

   mLength = 6;

   value[0] = 0X00;	
   value[1] = 0X01;

   try
   {
      value[2] = stoi(lIpValues[0]);
      value[3] = stoi(lIpValues[1]);
      value[4] = stoi(lIpValues[2]);
      value[5] = stoi(lIpValues[3]);
   }
   catch (...)
   {

   }
   mAvpDecodedFlag = true;
   return 1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : ToString
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : string
//-----------------------------------------------------------------------------------------------
string Address::ToString()
{
   if(!mAvpDecodedFlag)
   {
      mspByteArray.get()->offset = 0;
      mspByteArray.get()->offset = mAvpOffsetLen.first; 
      UINT16 bytesParsed = 0;   
      if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
         mAvpDecodedFlag = true;
   }

   string(ipAddress,ipAddress+mLength);
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getValue()
// DESCRIPTION  :	Get Value
// PARAMETER    : NONE
// RETURN       : UINT8*
//-----------------------------------------------------------------------------------------------
TEXT* Address::getValue()
{
   if(!mAvpDecodedFlag)
   {
      mspByteArray.get()->offset = 0;
      mspByteArray.get()->offset = mAvpOffsetLen.first; 
      UINT16 bytesParsed = 0;   
      if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
         mAvpDecodedFlag = true;
      else
      {
         TEXT lMessage[100] = "";
         snprintf(lMessage, sizeof(lMessage), "Error Decoding AVP %d Type:Address", mAvpCode);
         TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, lMessage);
         throw lTssDiaMsgException;
      } 
   }

   if(NULL == ipAddress)
   {
      TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, "Object OctetString is NULL");
      throw lTssDiaMsgException;
   }	

   return ipAddress;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpCode
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
UINT32 Address::getAvpCode()
{
   if(this != NULL)
      return this->mAvpCode;
   else
      return -1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpCode
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Address::setAvpCode(UINT32 avpCode)
{
   mAvpCode = avpCode;

   return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpVendorId
// DESCRIPTION  :
// PARAMETER    : 
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
UINT32 Address::getAvpVendorId()
{
   return this->mAvpVendorId;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpVendorId
// DESCRIPTION  :
// PARAMETER    : UINT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Address::setAvpVendorId(UINT32 avpVendorId)
{
   mAvpVendorId = avpVendorId;
   return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpOffsetLen
// DESCRIPTION  :
// PARAMETER    : 
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
pair<UINT32,UINT16> Address::getAvpOffsetLen()
{
   return mAvpOffsetLen;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpOffsetLen
// DESCRIPTION  :
// PARAMETER    : INT16,INT16
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Address::setAvpOffsetLen(UINT32 offset,UINT16 length)
{
   mAvpOffsetLen = make_pair(offset,length);
   return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Find
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : DiameterBaseInterface*
//-----------------------------------------------------------------------------------------------
DiameterBaseInterface* Address::Find(byteArray *array,UINT32 avpCode)
{
   if( mAvpCode == avpCode)
      return this;

   return NULL;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : FindAll
// DESCRIPTION  :
// PARAMETER    : byteArray,UINT32,list<DiameterBaseInterface*>&
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN	Address::FindAll(byteArray *array,UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect)
{
   return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Display
// DESCRIPTION  : Displays value
// PARAMETER    : UINT32
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
void Address::Display(UINT32 tab)
{
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
      mAvpDecodedFlag = true;
   }

   TEXT temp[30];
   sprintf(temp, "%%%ds %%s \n", tab * 3);

   printf(temp, " ", "Octet String is : ");
   sprintf(temp, "%%%ds", tab * 4);
   printf(temp, "  ");

   for(UINT8 lTemp = 0; lTemp < mLength; lTemp++)
      printf(" %02X", value[lTemp]);

   printf("[%s]",value);
   printf("\n");
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Time()
// DESCRIPTION  : Constructor
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
Time::Time()
{
   mLength = 0;
   timeVal = 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : ~Time()
// DESCRIPTION  : Destructor
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
Time::~Time()
{
}


//-----------------------------------------------------------------------------------------------
// METHOD       : Time()
// DESCRIPTION  : Copy constructor
// PARAMETER    : Time&
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
//Time::Time(const Time& obj)
//{
   //cout<<"OctetString::copy constructor\n";
//   mLength = obj.mLength;
//   timeVal = obj.timeVal;
//   memcpy(value, obj.value, mLength);
//}

//-----------------------------------------------------------------------------------------------
// METHOD       : Time()
// DESCRIPTION  : Copy assignment operator
// PARAMETER    : Time&
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
//Time& Time::operator=(const Time& obj)
//{
//   mLength = obj.mLength;
//   timeVal = obj.timeVal;
//   memcpy(value, obj.value, mLength);
//}

//-----------------------------------------------------------------------------------------------
// METHOD       : operator overloaded ==
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN Time::operator==(const Time& obj)
{
   /*
   if(mLength != obj.mLength)
      return false;

   if(0 == memcmp (value,obj.value,mLength))
      return true;
  */

   if(0 == difftime(obj.timeVal, timeVal))
      return true;

   return false;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : operator overloaded <
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN Time::operator<(const Time& obj)
{
   /*
   if(mLength != obj.mLength)
      return false;

   if(0 > memcmp (value,obj.value,mLength))
      return true;
   */
   
   if( 0 < difftime(obj.timeVal, timeVal))
      return true;

   return false;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Decode
// DESCRIPTION  :	Decodes Byte array with DataType Octet String
// PARAMETER    : byteArray, INT16, UINT16
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Time::Decode(byteArray *array, INT16 length, UINT16* parsedBytes)
{
   mLength = length;
   memset(&value, 0, sizeof(value)); 
   memcpy(value, (array->byte) + array->offset, mLength);

   *parsedBytes = length;
   long NTPTime = 0;
   for(INT16 lReadIdx = 0; lReadIdx < *parsedBytes; lReadIdx++)
   {
      NTPTime = (NTPTime << 8) | (array->byte[array->offset++] & 0xFF);
   }
   NTPTime -= SYS_TIME_NTP_COMPENSATION;
   timeVal = NTPTime;

   mAvpDecodedFlag = true;
   return 1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Decode
// DESCRIPTION  : Decodes integer value from Byte array
// PARAMETER    : byteArray,  UINT16
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
INT32	Time::Decode(byteArray* array, UINT16* bytesParsed)
{
   mLength  =  4;
   memset(&value, 0, sizeof(value)); 
   memcpy(value, (array->byte) + array->offset, mLength);
   
   *bytesParsed = 4;

   long NTPTime = 0;
   for(INT16 lReadIdx = 0; lReadIdx < *bytesParsed; lReadIdx++)
   {
      NTPTime = (NTPTime << 8) | (array->byte[array->offset++] & 0xFF);
   }
   NTPTime -= SYS_TIME_NTP_COMPENSATION; 
   timeVal = NTPTime;

   mAvpDecodedFlag = true;
   return 1;
}
//-----------------------------------------------------------------------------------------------
// METHOD       : Encode
// DESCRIPTION  : Encodes Byte array with DataType Octet String
// PARAMETER    : byteArray
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Time::Encode(byteArray *array)
{
   memcpy( (array->byte) + array->offset , value , mLength);
   array->offset += mLength;	
   array->size += mLength;

   return 1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getLength
// DESCRIPTION  : get octetstring length.
// PARAMETER    : UINT8*, UINT32
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
UINT16 Time::getLength()
{
	return mLength;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : ToString
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : string
//-----------------------------------------------------------------------------------------------
string Time::ToString()
{
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
      mAvpDecodedFlag = true;
   }

   TEXT buf[100] = "";
   struct tm *timeptr = localtime(&timeVal); 
   strftime(buf,sizeof(buf), "%a, %d %b %Y %T", timeptr);
   return string(buf);
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setValue
// DESCRIPTION  : Sets Value
// PARAMETER    : UINT8*, UINT32
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
UINT32 Time::setValue(time_t val)
{
   mLength = 4;
   memset(&value, 0, sizeof(value));

   timeVal = val;
  
   long NTPTime = timeVal + SYS_TIME_NTP_COMPENSATION;

   for(UINT32 lTemp = 0; lTemp < mLength; lTemp++)
   {
      value[lTemp] = (TEXT)(NTPTime >> ((mLength - lTemp - 1) * 8)) & 0xFF;
   } 

   mAvpDecodedFlag = true;
   return 1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getValue()
// DESCRIPTION  :	Get Value
// PARAMETER    : NONE
// RETURN       : time_t
//-----------------------------------------------------------------------------------------------
time_t Time::getValue()
{
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
      mAvpDecodedFlag = true;
     else
     {
        TEXT lMessage[100] = "";
        snprintf(lMessage, sizeof(lMessage), "Error Decoding AVP %d Type:Time", mAvpCode);
        TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, lMessage);
        throw lTssDiaMsgException;
     }
   }

   return timeVal;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpCode
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
UINT32 Time::getAvpCode()
{
   if(this != NULL)
      return this->mAvpCode;
   else
      return -1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpCode
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Time::setAvpCode(UINT32 avpCode)
{
      mAvpCode = avpCode;

      return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpVendorId
// DESCRIPTION  :
// PARAMETER    : 
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
UINT32 Time::getAvpVendorId()
{
   return this->mAvpVendorId;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpVendorId
// DESCRIPTION  :
// PARAMETER    : UINT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Time::setAvpVendorId(UINT32 avpVendorId)
{
   mAvpVendorId = avpVendorId;
   return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpOffsetLen
// DESCRIPTION  :
// PARAMETER    : 
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
pair<UINT32,UINT16> Time::getAvpOffsetLen()
{
   return mAvpOffsetLen;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpOffsetLen
// DESCRIPTION  :
// PARAMETER    : INT16,INT16
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Time::setAvpOffsetLen(UINT32 offset,UINT16 length)
{
   mAvpOffsetLen = make_pair(offset,length);
   return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Find
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : DiameterBaseInterface*
//-----------------------------------------------------------------------------------------------
DiameterBaseInterface* Time::Find(byteArray *array,UINT32 avpCode)
{
   if( mAvpCode == avpCode)
      return this;

   return NULL;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : FindAll
// DESCRIPTION  :
// PARAMETER    : byteArray,UINT32,list<DiameterBaseInterface*>&
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN	Time::FindAll(byteArray *array,UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect)
{
   return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Display
// DESCRIPTION  : Displays value
// PARAMETER    : UINT32
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
void Time::Display(UINT32 tab)
{
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
      mAvpDecodedFlag = true;
   }

   TEXT temp[30];
   sprintf(temp, "%%%ds %%s \n", tab * 3);

   printf(temp, " ", "Time is : ");
   sprintf(temp, "%%%ds", tab * 4);
   printf(temp, "  ");

   for(UINT8 lTemp = 0; lTemp < mLength; lTemp++)
      printf(" %02X", value[lTemp]);
   printf("[%s]\n",ToString().c_str());
}





//-----------------------------------------------------------------------------------------------
// METHOD       : Imsi
// DESCRIPTION  : Constructor
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
Imsi::Imsi()
{
}

//-----------------------------------------------------------------------------------------------
// METHOD       : ~Imsi()
// DESCRIPTION  :	Destructor
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
Imsi::~Imsi()
{
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Imsi()
// DESCRIPTION  : Copy constructor
// PARAMETER    : Imsi&
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
//Imsi::Imsi(const Imsi& obj)
//{
   //mLength = obj.mLength;
   //value = (char *)calloc(strlen(obj.value), sizeof(char));
//   memcpy(value, obj.value, strlen(obj.value));
//}

//-----------------------------------------------------------------------------------------------
// METHOD       : Imsi()
// DESCRIPTION  : Copy assignment operator
// PARAMETER    : Imsi&
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
//Imsi& Imsi::operator=(const Imsi& obj)
//{
   //value = (char *)calloc(strlen(obj.value), sizeof(char));
//   memcpy(value, obj.value, strlen(obj.value));
//}

//-----------------------------------------------------------------------------------------------
// METHOD       : operator overloaded ==
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN Imsi::operator==(const Imsi& obj)
{
   if(strlen(value) != strlen(obj.value))
      return false;

   if(0 == memcmp (value,obj.value,strlen(obj.value)))
      return true;

   return false;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : operator overloaded <
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN Imsi::operator<(const Imsi& obj)
{
	if(strlen(value) != strlen(obj.value))
      return false;

   if(0 > memcmp (value,obj.value,strlen(obj.value)))
      return true;

   return false;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Decode
// DESCRIPTION  :	Decodes Imsi
// PARAMETER    : byteArray, UINT16, UINT16
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Imsi::Decode(byteArray* array, INT16 length , UINT16* bytesParsed)
{
	memcpy(value, (array->byte) + array->offset , length);
   
	*bytesParsed = length;

   mAvpDecodedFlag = true;
   return 1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Encode
// DESCRIPTION  :	Encodes Imsi Value
// PARAMETER    : byteArray
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Imsi::Encode(byteArray* array)
{
	INT16	lImsiLen = strlen(value);

	if(lImsiLen > 16)
	{
		return -1;	
	}

	for (int i=0; i<lImsiLen; i++)
	{
		array->byte[array->offset++] = value[i]; 
	}

   array->size   += lImsiLen;

   return 1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getValue
// DESCRIPTION  : Gets Imsi Value
// PARAMETER    : NONE
// RETURN       : TEXT*
//-----------------------------------------------------------------------------------------------
TEXT * Imsi::getValue()
{
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
        mAvpDecodedFlag = true;
     else
     {
        TEXT lMessage[100] = "";
        snprintf(lMessage, sizeof(lMessage), "Error Decoding AVP %d Type:Imsi", mAvpCode);
        TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, lMessage);
        throw lTssDiaMsgException;
     } 
   }

	if(NULL != value)
		return value;
	else
		return NULL;
		
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setValue
// DESCRIPTION  :	TEXT* 
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
UINT32 Imsi::setValue(TEXT* val)
{
   memcpy(value, val, sizeof(value));
   mAvpDecodedFlag = true;

   return 1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpCode
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
UINT32 Imsi::getAvpCode()
{
   if(this != NULL)
      return this->mAvpCode;
   else
      return -1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpCode
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Imsi::setAvpCode(UINT32 avpCode)
{
      mAvpCode = avpCode;

      return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpVendorId
// DESCRIPTION  :
// PARAMETER    : 
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
UINT32 Imsi::getAvpVendorId()
{
   return this->mAvpVendorId;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpVendorId
// DESCRIPTION  :
// PARAMETER    : UINT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 Imsi::setAvpVendorId(UINT32 avpVendorId)
{
   mAvpVendorId = avpVendorId;
   return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpOffsetLen
// DESCRIPTION  :
// PARAMETER    : 
// RETURN       : UINT32
//-----------------------------------------------------------------------------------------------
pair<UINT32,UINT16> Imsi::getAvpOffsetLen()
{
   return mAvpOffsetLen;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpOffsetLen
// DESCRIPTION  :
// PARAMETER    : INT16,INT16
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32  Imsi::setAvpOffsetLen(UINT32 offset,UINT16 length)
{
   mAvpOffsetLen = make_pair(offset,length);
   return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Find
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : DiameterBaseInterface*
//-----------------------------------------------------------------------------------------------
DiameterBaseInterface* Imsi::Find(byteArray *array,UINT32 avpCode)
{
   if( mAvpCode == avpCode)
      return this;

   return NULL;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : FindAll
// DESCRIPTION  :
// PARAMETER    : byteArray,UINT32,list<DiameterBaseInterface*>&
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN	Imsi::FindAll(byteArray *array,UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect)
{
   return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Display
// DESCRIPTION  :	Displays Imsi
// PARAMETER    : UINT32
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
void Imsi::Display(UINT32 tab)
{
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
      mAvpDecodedFlag = true;
   }

   TEXT temp[30];
   sprintf(temp, "%%%ds  %%s %%s\n", tab * 3);
   printf(temp, " ","IMSI : ",value);
}


GENERIC::GENERIC()
{
   value = NULL;
   mLength = 0;
}

GENERIC::~GENERIC()
{
   if(value != NULL)
      free(value);
}

//-----------------------------------------------------------------------------------------------
// METHOD       : GENERIC()
// DESCRIPTION  : Copy constructor
// PARAMETER    : GENERIC&
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
//GENERIC::GENERIC(const GENERIC& obj)
//{
   //cout<<"OctetString::copy constructor\n";
//   mLength = obj.mLength;
//   value = (unsigned char *)calloc(mLength, sizeof(char));
//   memcpy(value, obj.value, mLength);
//}

//-----------------------------------------------------------------------------------------------
// METHOD       : GENERIC()
// DESCRIPTION  : Copy assignment operator
// PARAMETER    : GENERIC&
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
//GENERIC& GENERIC::operator=(const GENERIC& obj)
//{
//   mLength = obj.mLength;
//   value = (unsigned char *)calloc(mLength, sizeof(char));
//   memcpy(value, obj.value, mLength);
//}

//-----------------------------------------------------------------------------------------------
// METHOD       : operator overloaded ==
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN GENERIC::operator==(const GENERIC& obj)
{
   if(mLength != obj.mLength)
      return false;

   if(0 == memcmp (value,obj.value,mLength))
      return true;

   return false;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : operator overloaded <
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN GENERIC::operator<(const GENERIC& obj)
{
   if(mLength != obj.mLength)
      return false;

   if(0 > memcmp (value,obj.value,mLength))
      return true;

   return false;
}

int GENERIC::Decode(byteArray *array, INT16 length, UINT16 *parsedBytes )
{
	mLength = length;

	value = (unsigned char*)calloc((length + 1), sizeof(char));

	memcpy(value, (array->byte) + array->offset, length);

	*parsedBytes = length;

	array->offset += length;

   mAvpDecodedFlag = true;
	return 1;
}

int GENERIC::Encode(byteArray *arraybyte)
{
   //arraybyte->size += mLength;

   for(int j=0; j < mLength ; j++)
      arraybyte->byte[arraybyte->offset++] =  value[j];

	INT32 lpadding=0;
	
	if(mLength%4 != 0)
	{
		for(lpadding=1; lpadding <= (4-mLength%4); lpadding++)
		{
			arraybyte->byte[arraybyte->offset++] = 0x00;
		}
		arraybyte->size += mLength+(lpadding-1);
	}
	else
	{
		arraybyte->size += mLength;
	}
   return 1;
}

int GENERIC::Display(int tab)
{
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
      mAvpDecodedFlag = true;
   }

   char temp[30];
   sprintf(temp, "%%%ds %%s \n", tab * 3);

   printf(temp, " ", "Generic Byte Array is : ");
   sprintf(temp, "%%%ds", tab * 3);
   printf(temp, "  ");
   for(unsigned lTemp = 0; lTemp < mLength; lTemp++)
      printf(" %02X", value[lTemp]);

   printf("\n");

   return 1;
}

int GENERIC::setValue(char* val)
{
   mLength = strlen(val);
   if(value != NULL)
      free(value);
   value = (unsigned char*)calloc(mLength, sizeof(char));
   if(value == NULL)
      return -1;
   memcpy(value, val, mLength);

   mAvpDecodedFlag = true;
   return 1;
}

unsigned char* GENERIC::getValue()
{
   if(!mAvpDecodedFlag)
   {
     mspByteArray.get()->offset = 0;
     mspByteArray.get()->offset = mAvpOffsetLen.first; 
     UINT16 bytesParsed = 0;   
     if(-1 != this->Decode(mspByteArray.get(), mAvpOffsetLen.second, &bytesParsed))
        mAvpDecodedFlag = true;
     else
     {
        TEXT lMessage[100] = "";
        snprintf(lMessage, sizeof(lMessage), "Error Decoding AVP %d Type:Generic", mAvpCode);
        TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, lMessage);
        throw lTssDiaMsgException;
     } 
   }

   if(NULL != value)
      return value;
   else
   {
        TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, "Object GENERIC is NULL");
        throw lTssDiaMsgException;
   }
}


//-----------------------------------------------------------------------------------------------
// METHOD       : getAvpCode
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
UINT32 GENERIC::getAvpCode()
{
   if(this != NULL)
      return this->mAvpCode;
   else
      return -1;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpCode
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : INT32
//-----------------------------------------------------------------------------------------------
INT32 GENERIC::setAvpCode(UINT32 avpCode)
{
      mAvpCode = avpCode;

      return 0;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Find
// DESCRIPTION  :
// PARAMETER    : INT32
// RETURN       : DiameterBaseInterface*
//-----------------------------------------------------------------------------------------------
DiameterBaseInterface* GENERIC::Find(byteArray *array,UINT32 avpCode)
{
   if( mAvpCode == avpCode)
      return this;

   return NULL;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : FindAll
// DESCRIPTION  :
// PARAMETER    : byteArray,UINT32,list<DiameterBaseInterface*>&
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN	GENERIC::FindAll(byteArray *array,UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect)
{
   return true;
}
