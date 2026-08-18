// @(#) $Id: DiameterBasicDecEnc.h,v 1.1.2.4.2.1.2.5 2020/05/29 18:59:24 gpanand Exp $";
//-----------------------------------------------------------------------------
// NAME           :  DiameterBasicDecEnc.h
//
// COPYRIGHT      :  TSS - Copyright (C) 2009 Tayana Software Solution Pvt Ltd.,
//                   All rights reserved. No part of this computer program
//                   may be used or reproduced in any form by any
//                   means without prior written permission of
//                   Tayana Software Solution Pvt Ltd.
//
// DESCRIPTION
//
// Originated By  :                                    Date:
//---------------------------------------------------------------------------
#ifndef DIAMETER_BASIC_DEC_ENC
#define DIAMETER_BASIC_DEC_ENC
#include "DiameterBaseInterface.h"
#define TSS_MAX_IPV6_ADDRESS_LEN 50

class Integer32 : public DiameterBaseInterface 
{
   public:
      Integer32();
      
      Integer32(const Integer32& obj)
      {
         mAvpDecodedFlag   = obj.mAvpDecodedFlag;
         value             = obj.value;
         minValue          = obj.minValue;
        	maxValue          = obj.maxValue;
         rangeSet          = obj.rangeSet;
         //errno             = obj.errno;
         mAvpCode          = obj.mAvpCode;
         mAvpVendorId      = obj.mAvpVendorId;
      }
      
      //Integer32& operator = (const Integer32& obj)
      void operator = (const Integer32& obj)
      {
         mAvpDecodedFlag   = obj.mAvpDecodedFlag;
         value             = obj.value;
         minValue          = obj.minValue;
        	maxValue          = obj.maxValue;
         rangeSet          = obj.rangeSet;
         //errno             = obj.errno;
         mAvpCode          = obj.mAvpCode;
         mAvpVendorId      = obj.mAvpVendorId;
      }

      Integer32(INT32 minVal, INT32 maxVal);

      Integer32(INT32 val);

      ~Integer32();

      //Integer32(const Integer32& obj);

      BOOLEAN operator==(const Integer32& obj);

      BOOLEAN operator<(const Integer32& obj);

      string ToString();

      INT32 		getValue();

      INT32 		setValue(INT32);

      UINT32 		getAvpCode();

      INT32 		setAvpCode(UINT32 avpCode);

      UINT32 		getAvpVendorId();

      INT32 		setAvpVendorId(UINT32 vendorId);

      pair<UINT32,UINT16> getAvpOffsetLen();

      INT32       setAvpOffsetLen(UINT32,UINT16);

      DiameterBaseInterface*	Find(byteArray *array,UINT32 avpCode);
      BOOLEAN	FindAll(byteArray *array,UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);

      BOOLEAN 		CheckBoundary(const INT32 value);

      INT32			Decode(byteArray *array, INT16 length, UINT16 *bytesParsed);

      // Added Overloaded funtion to decode Bytearray without passing lentgh from which to start decoding
      INT32 		Decode(byteArray* array, UINT16* bytesParsed);   

      INT32 		Encode(byteArray *array);

      void 			Display(UINT32 tab);

      std::shared_ptr<byteArray> mspByteArray;

      BOOLEAN     mAvpDecodedFlag = false;      

   private:

      INT32 		value;

      INT32 		minValue;

      INT32	 		maxValue;

      BOOLEAN 		rangeSet;

      INT32			errno;

      UINT32		mAvpCode;

      UINT32      mAvpVendorId = 0;

      pair<UINT32,UINT16> mAvpOffsetLen; //pair<offset,length>
};

class Integer64 : public DiameterBaseInterface
{
	public:
		Integer64();
      
      Integer64(const Integer64& obj)
      {
         mAvpDecodedFlag   = obj.mAvpDecodedFlag;
         value             = obj.value;
         minValue          = obj.minValue;
        	maxValue          = obj.maxValue;
         rangeSet          = obj.rangeSet;
         //errno             = obj.errno;
         mAvpCode          = obj.mAvpCode;
         mAvpVendorId      = obj.mAvpVendorId;
      }
      
      //Integer64& operator = (const Integer64& obj)
      void operator = (const Integer64& obj)
      {
         mAvpDecodedFlag   = obj.mAvpDecodedFlag;
         value             = obj.value;
         minValue          = obj.minValue;
        	maxValue          = obj.maxValue;
         rangeSet          = obj.rangeSet;
         //errno             = obj.errno;
         mAvpCode          = obj.mAvpCode;
         mAvpVendorId      = obj.mAvpVendorId;
      }

		Integer64(INT64 minVal, INT64 maxVal);

		Integer64(INT64 val);

		~Integer64();

		//Integer64(const Integer64& obj);

		BOOLEAN operator==(const Integer64& obj);

		BOOLEAN operator<(const Integer64& obj);

		string ToString();		

		INT64       getValue();

		INT32       setValue(INT64);

		UINT32 		getAvpCode();

		INT32 		setAvpCode(UINT32 avpCode);

		UINT32 		getAvpVendorId();

		INT32 		setAvpVendorId(UINT32 vendorId);

		pair<UINT32,UINT16> getAvpOffsetLen();

		INT32       setAvpOffsetLen(UINT32,UINT16);

		DiameterBaseInterface*	Find(byteArray *array,UINT32 avpCode);
		BOOLEAN	FindAll(byteArray *array,UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);

		BOOLEAN     CheckBoundary(const INT64 value);

		INT32       Decode(byteArray *array, INT16 length, UINT16 *bytesParsed);

		// Added Overloaded funtion to decode Bytearray without passing lentgh from which to start decoding
		INT32       Decode(byteArray* array, UINT16* bytesParsed);

		INT32       Encode(byteArray *array);

		void        Display(UINT32 tab);

		std::shared_ptr<byteArray> mspByteArray;

		BOOLEAN     mAvpDecodedFlag = false;      

	private:

		INT64       value;

		INT64     	minValue;

		INT64 	   maxValue;

		BOOLEAN     rangeSet;

		INT32			errno;

		UINT32		mAvpCode;

		UINT32      mAvpVendorId = 0;

		pair<UINT32,UINT16> mAvpOffsetLen; //pair<offset,length>
};


class Unsigned32 : public DiameterBaseInterface
{
	public:
		Unsigned32();
      
      Unsigned32(const Unsigned32& obj)
      {
         mAvpDecodedFlag   = obj.mAvpDecodedFlag;
         value             = obj.value;
         minValue          = obj.minValue;
        	maxValue          = obj.maxValue;
         rangeSet          = obj.rangeSet;
         //errno             = obj.errno;
         mAvpCode          = obj.mAvpCode;
         mAvpVendorId      = obj.mAvpVendorId;
      }
      
      //Unsigned32& operator = (const Unsigned32& obj)
      void operator = (const Unsigned32& obj)
      {
         mAvpDecodedFlag   = obj.mAvpDecodedFlag;
         value             = obj.value;
         minValue          = obj.minValue;
        	maxValue          = obj.maxValue;
         rangeSet          = obj.rangeSet;
         //errno             = obj.errno;
         mAvpCode          = obj.mAvpCode;
         mAvpVendorId      = obj.mAvpVendorId;
      }

		Unsigned32(UINT32 minVal, UINT32 maxVal);

		Unsigned32(UINT32 val);

		~Unsigned32();

		//Unsigned32(const Unsigned32& obj);

		BOOLEAN operator==(const Unsigned32& obj);

		BOOLEAN operator<(const Unsigned32& obj);

		string ToString();		

		UINT32       getValue();

		INT32       setValue(UINT32);

		UINT32 		getAvpCode();

		INT32 		setAvpCode(UINT32 avpCode);

		UINT32 		getAvpVendorId();

		INT32 		setAvpVendorId(UINT32 vendorId);

		pair<UINT32,UINT16> getAvpOffsetLen();

		INT32       setAvpOffsetLen(UINT32,UINT16);

		DiameterBaseInterface*	Find(byteArray *array,UINT32 avpCode);
		BOOLEAN	FindAll(byteArray *array,UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);

		BOOLEAN     CheckBoundary(const UINT32 value);

		INT32       Decode(byteArray *array, INT16 length, UINT16 *bytesParsed);

		// Added Overloaded funtion to decode Bytearray without passing lentgh from which to start decoding
		INT32       Decode(byteArray* array, UINT16* bytesParsed);

		INT32       Encode(byteArray *array);

		void        Display(UINT32 tab);

		std::shared_ptr<byteArray> mspByteArray;

		BOOLEAN     mAvpDecodedFlag = false;

	private:

		UINT32      value;

		UINT32      minValue;

		UINT32      maxValue;

		BOOLEAN     rangeSet;

		INT32       errno;

		UINT32		mAvpCode;

		UINT32      mAvpVendorId = 0;

		pair<UINT32,UINT16> mAvpOffsetLen; //pair<offset,length>
};

class Unsigned64 : public DiameterBaseInterface
{
	public:
		Unsigned64();
      
      Unsigned64(const Unsigned64& obj)
      {
         mAvpDecodedFlag   = obj.mAvpDecodedFlag;
         value             = obj.value;
         minValue          = obj.minValue;
        	maxValue          = obj.maxValue;
         rangeSet          = obj.rangeSet;
         //errno             = obj.errno;
         mAvpCode          = obj.mAvpCode;
         mAvpVendorId      = obj.mAvpVendorId;
      }
      
      //Unsigned64& operator = (const Unsigned64& obj)
      void operator = (const Unsigned64& obj)
      {
         mAvpDecodedFlag   = obj.mAvpDecodedFlag;
         value             = obj.value;
         minValue          = obj.minValue;
        	maxValue          = obj.maxValue;
         rangeSet          = obj.rangeSet;
         //errno             = obj.errno;
         mAvpCode          = obj.mAvpCode;
         mAvpVendorId      = obj.mAvpVendorId;
      }

		Unsigned64(UINT64 minVal, UINT64 maxVal);

		Unsigned64(UINT64 val);

		~Unsigned64();

		//Unsigned64(const Unsigned64& obj);

		BOOLEAN operator==(const Unsigned64& obj);

		BOOLEAN operator<(const Unsigned64& obj);

		string ToString();		

		UINT64      getValue();

		INT32       setValue(UINT64);

		UINT32 		getAvpCode();

		INT32 		setAvpCode(UINT32 avpCode);

		UINT32 		getAvpVendorId();

		INT32 		setAvpVendorId(UINT32 vendorId);

		pair<UINT32,UINT16> getAvpOffsetLen();

		INT32       setAvpOffsetLen(UINT32,UINT16);

		DiameterBaseInterface*	Find(byteArray *array,UINT32 avpCode);
		BOOLEAN	FindAll(byteArray *array,UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);

		BOOLEAN     CheckBoundary(const UINT64 value);

		INT32       Decode(byteArray *array, INT16 length, UINT16 *bytesParsed);

		// Added Overloaded funtion to decode Bytearray without passing lentgh from which to start decoding
		INT32       Decode(byteArray* array, UINT16* bytesParsed);

		INT32       Encode(byteArray *array);

		void        Display(UINT32 tab);

		std::shared_ptr<byteArray> mspByteArray;

		BOOLEAN     mAvpDecodedFlag = false;      

	private:

		UINT64      value;

		UINT64      minValue;

		UINT64      maxValue;

		BOOLEAN     rangeSet;

		INT32       errno;

		UINT32		mAvpCode;

		UINT32      mAvpVendorId = 0;

		pair<UINT32,UINT16> mAvpOffsetLen; //pair<offset,length>
};


class OctetString : public DiameterBaseInterface
{
	public:
		OctetString();
      
      OctetString(const OctetString& obj)
      {
         mAvpDecodedFlag   = obj.mAvpDecodedFlag;
         minSize          = obj.minSize;
        	maxSize          = obj.maxSize;
         mLength          = obj.mLength;
         mAvpCode          = obj.mAvpCode;
         mAvpVendorId      = obj.mAvpVendorId;
	
         value = (unsigned char *)calloc(mLength, sizeof(char));
	      memcpy(value, obj.value, mLength);	
      }
      
      //OctetString& operator = (const OctetString& obj)
      void operator = (const OctetString& obj)
      {
         mAvpDecodedFlag   = obj.mAvpDecodedFlag;
         minSize          = obj.minSize;
        	maxSize          = obj.maxSize;
         mLength          = obj.mLength;
         mAvpCode          = obj.mAvpCode;
         mAvpVendorId      = obj.mAvpVendorId;
	
         value = (unsigned char *)calloc(mLength, sizeof(char));
	      memcpy(value, obj.value, mLength);	
       }

		OctetString(UINT32 minSize, UINT32 maxSize);

		~OctetString();

		//OctetString(const OctetString& obj);

		//OctetString& operator=(const OctetString& obj);

		BOOLEAN operator==(const OctetString& obj);

		BOOLEAN operator<(const OctetString& obj);

		string ToString();		
		string ToHexString(UINT32 tab);

		UINT8* getValue();

		UINT32 setValue(UINT8* , UINT32 len);

		UINT32 setValue(TEXT *val);

		UINT32 		getAvpCode();

		INT32 		setAvpCode(UINT32 avpCode);

		UINT32 		getAvpVendorId();

		INT32 		setAvpVendorId(UINT32 vendorId);

		pair<UINT32,UINT16> getAvpOffsetLen();

		INT32       setAvpOffsetLen(UINT32,UINT16);

		DiameterBaseInterface*	Find(byteArray *array,UINT32 avpCode);
		BOOLEAN	FindAll(byteArray *array,UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);

		INT32 Decode(byteArray *array, INT16 length, UINT16 *bytesParsed);

		INT32 Encode(byteArray *array);

		void Display(UINT32 tab);

		UINT16 getLength();

		std::shared_ptr<byteArray> mspByteArray;

		BOOLEAN     mAvpDecodedFlag = false;      

	private:

		UINT32 minSize;

		UINT32 maxSize;

		UINT16 mLength;

		UINT8* value;

		UINT32	mAvpCode;

		UINT32      mAvpVendorId = 0;

		pair<UINT32,UINT16> mAvpOffsetLen; //pair<offset,length>
};

class Address : public DiameterBaseInterface
{
	public:
		Address();
      
      Address(const Address& obj)
      {
         mAvpDecodedFlag   = obj.mAvpDecodedFlag;
         minSize          = obj.minSize;
        	maxSize          = obj.maxSize;
         mAvpCode          = obj.mAvpCode;
         mAvpVendorId      = obj.mAvpVendorId;
   
         mLength = obj.mLength;
         memcpy(value, obj.value, mLength);
         ipAddress = new TEXT[TSS_MAX_IP_ADDRESS_LEN + 1];
         sprintf(ipAddress,obj.ipAddress);		
      }
      
      //Address& operator = (const Address& obj)
      void operator = (const Address& obj)
      {
         mAvpDecodedFlag   = obj.mAvpDecodedFlag;
         minSize          = obj.minSize;
        	maxSize          = obj.maxSize;
         mAvpCode          = obj.mAvpCode;
         mAvpVendorId      = obj.mAvpVendorId;
   
         mLength = obj.mLength;
         memcpy(value, obj.value, mLength);
         ipAddress = new TEXT[TSS_MAX_IP_ADDRESS_LEN + 1];
         sprintf(ipAddress,obj.ipAddress);		
       }

		~Address();

		//Address(const Address& obj);

		//Address& operator=(const Address& obj);

		BOOLEAN operator==(const Address& obj);

		BOOLEAN operator<(const Address& obj);

		string ToString();

		TEXT* getValue();

		UINT32 setValue(UINT8* , UINT32 len);
		UINT32 setValue(char* val);

		INT32 Decode(byteArray *array, INT16 length, UINT16 *bytesParsed);

		INT32 Encode(byteArray *array);

		void Display(UINT32 tab);

		UINT16 getLength();

		UINT32      getAvpCode();

		INT32       setAvpCode(UINT32 avpCode);

		UINT32 		getAvpVendorId();

		INT32 		setAvpVendorId(UINT32 vendorId);

		pair<UINT32,UINT16> getAvpOffsetLen();

		INT32       setAvpOffsetLen(UINT32,UINT16);

		DiameterBaseInterface*  Find(byteArray *array,UINT32 avpCode);
		BOOLEAN	FindAll(byteArray *array,UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);

		std::shared_ptr<byteArray> mspByteArray;

		BOOLEAN     mAvpDecodedFlag = false;

	private:

		UINT32 minSize;

		UINT32 maxSize;

		UINT16 mLength;

		UINT8 value[23];//32 bit/4 byte for IPV4 (IPV6 128 bit/16 byte not supported) + 2 bytes for address type identification

		TEXT* ipAddress;	

		UINT32   mAvpCode;

		UINT32      mAvpVendorId = 0;

		pair<UINT32,UINT16> mAvpOffsetLen; //pair<offset,length>
};

class Time : public DiameterBaseInterface
{
	public:
		Time();
      
      Time(const Time& obj)
      {
         mAvpDecodedFlag   = obj.mAvpDecodedFlag;
         minSize          = obj.minSize;
        	maxSize          = obj.maxSize;
         timeVal          = obj.timeVal;
         mAvpCode          = obj.mAvpCode;
         mAvpVendorId      = obj.mAvpVendorId;
         mLength           = obj.mLength;
         memcpy(value, obj.value, mLength);
      }
      
      //Time& operator = (const Time& obj)
      void operator = (const Time& obj)
      {
         mAvpDecodedFlag   = obj.mAvpDecodedFlag;
         minSize          = obj.minSize;
        	maxSize          = obj.maxSize;
         timeVal          = obj.timeVal;
         mAvpCode          = obj.mAvpCode;
         mAvpVendorId      = obj.mAvpVendorId;
         mLength           = obj.mLength;
         memcpy(value, obj.value, mLength);
      }

		~Time();

		//Time(const Time& obj);

		//Time& operator=(const Time& obj);

		BOOLEAN operator==(const Time& obj);

		BOOLEAN operator<(const Time& obj);

		string ToString();

		//UINT8* getValue() throw(const char*);
		time_t getValue();

		UINT32 setValue(time_t);

		INT32 Decode(byteArray *array, INT16 length, UINT16 *bytesParsed);
		INT32 Decode(byteArray* array, UINT16* bytesParsed);

		INT32 Encode(byteArray *array);

		void Display(UINT32 tab);

		UINT16 getLength();

		UINT32      getAvpCode();

		INT32       setAvpCode(UINT32 avpCode);

		UINT32 		getAvpVendorId();

		INT32 		setAvpVendorId(UINT32 vendorId);

		pair<UINT32,UINT16> getAvpOffsetLen();

		INT32       setAvpOffsetLen(UINT32,UINT16);

		DiameterBaseInterface*  Find(byteArray *array,UINT32 avpCode);
		BOOLEAN	FindAll(byteArray *array,UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);

		std::shared_ptr<byteArray> mspByteArray;

		BOOLEAN     mAvpDecodedFlag = false;

	private:

		UINT32 minSize;

		UINT32 maxSize;

		UINT16 mLength;

		UINT8 value[4];

		time_t timeVal; 

		UINT32   mAvpCode;

		UINT32      mAvpVendorId = 0;

		pair<UINT32,UINT16> mAvpOffsetLen; //pair<offset,length>
};

class Imsi : public DiameterBaseInterface
{
	public:

		Imsi();
      
      Imsi(const Imsi& obj)
      {
         mAvpDecodedFlag   = obj.mAvpDecodedFlag;
		   mAvpCode          = obj.mAvpCode;
		   mAvpVendorId      = obj.mAvpVendorId;
         memcpy(value, obj.value, strlen(obj.value));
      }
      
      //Imsi& operator = (const Imsi& obj)
      void operator = (const Imsi& obj)
      {
         mAvpDecodedFlag   = obj.mAvpDecodedFlag;
		   mAvpCode          = obj.mAvpCode;
		   mAvpVendorId      = obj.mAvpVendorId;
         memcpy(value, obj.value, strlen(obj.value));
      }

		~Imsi();

		//Imsi(const Imsi& obj);

		//Imsi& operator=(const Imsi& obj);

		BOOLEAN operator==(const Imsi& obj);

		BOOLEAN operator<(const Imsi& obj);

		string ToString();

		INT32  Decode(byteArray *array,  INT16 len, UINT16 *bytesParsed);

		INT32  Encode(byteArray *array);

		void   Display(UINT32 tab);

		TEXT*  getValue();

		UINT32 setValue(TEXT *);

		UINT32 getAvpCode();

		INT32  setAvpCode(UINT32 avpCode);

		UINT32 		getAvpVendorId();

		INT32 		setAvpVendorId(UINT32 vendorId);

		pair<UINT32,UINT16> getAvpOffsetLen();

		INT32       setAvpOffsetLen(UINT32,UINT16);

		DiameterBaseInterface*  Find(byteArray *array,UINT32 avpCode);
		BOOLEAN	FindAll(byteArray *array,UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);

		std::shared_ptr<byteArray> mspByteArray;

		BOOLEAN     mAvpDecodedFlag = false;      

	private:

		TEXT   value[MAX_IMSI_LEN + 1];

		UINT32   mAvpCode;

		UINT32      mAvpVendorId = 0;

		pair<UINT32,UINT16> mAvpOffsetLen; //pair<offset,length>
};

class GENERIC : public DiameterBaseInterface
{
	public:
		GENERIC();
      
      GENERIC(const GENERIC& obj)
      {
         mAvpDecodedFlag   = obj.mAvpDecodedFlag;
         mAvpCode          = obj.mAvpCode;
         mAvpVendorId      = obj.mAvpVendorId;
         mLength = obj.mLength;
         value = (unsigned char *)calloc(mLength, sizeof(char));
         memcpy(value, obj.value, mLength);
      }
      
      //GENERIC& operator = (const GENERIC& obj)
      void operator = (const GENERIC& obj)
      {
         mAvpDecodedFlag   = obj.mAvpDecodedFlag;
         mAvpCode          = obj.mAvpCode;
         mAvpVendorId      = obj.mAvpVendorId;
         mLength = obj.mLength;
         value = (unsigned char *)calloc(mLength, sizeof(char));
         memcpy(value, obj.value, mLength);
      }

		~GENERIC();

		//GENERIC(const GENERIC& obj);

		//GENERIC& operator=(const GENERIC& obj);

		BOOLEAN operator==(const GENERIC& obj);

		BOOLEAN operator<(const GENERIC& obj);

		string ToString();

		unsigned char* getValue();

		int setValue(char*);

		int Decode(byteArray *array, INT16 length, UINT16 *bytesParsed );

		int Encode(byteArray *array);

		int Display(int tab);

		UINT32  getAvpCode();

		INT32   setAvpCode(UINT32 avpCode);

		UINT32 		getAvpVendorId();

		INT32 		setAvpVendorId(UINT32 vendorId);

		pair<UINT32,UINT16> getAvpOffsetLen();

		INT32       setAvpOffsetLen(UINT32,UINT16);

		DiameterBaseInterface*  Find(byteArray *array,UINT32 avpCode);
		BOOLEAN	FindAll(byteArray *array,UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);

		std::shared_ptr<byteArray> mspByteArray;

		BOOLEAN     mAvpDecodedFlag = false;      

	private:

		unsigned mLength;

		unsigned char* value;

		UINT32   mAvpCode;

		UINT32      mAvpVendorId = 0;

		pair<UINT32,UINT16> mAvpOffsetLen; //pair<offset,length>
};
#endif
