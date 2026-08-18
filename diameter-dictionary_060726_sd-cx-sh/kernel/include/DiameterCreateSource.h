// @(#) $Id: DiameterCreateSource.h,v 1.1.2.4.2.1.2.1 2024/03/20 09:44:33 mrafi Exp $";
#ifndef DIA_CRT1_SRC_H
#define DIA_CRT1_SRC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string>

#include <vector>
#include <map>
#include "Types.h"
#include "DiameterStruct.h"

#define FILE_DIAMETER_DATA_TYPES "DiameterDataTypes"

using namespace std;

#define BIT_01    1
#define BIT_02    2
#define BIT_03    4
#define BIT_04    8
#define BIT_05    16
#define BIT_06    32
#define BIT_07    64
#define BIT_08    128

#define REQUEST	BIT_08
#define PROXYABLE	BIT_07
#define ERROR		BIT_06
#define TRANSMIT  BIT_05

#define VENDORSPECIFIC	BIT_08
#define MANDATORY			BIT_07
#define PROTECTED			BIT_06

#define s_request			"request"
#define s_proxyable		"proxyable"
#define s_error			"error"
#define s_transmit		"transmit"

#define s_vendor			"vendor"
#define s_mandatory		"mandatory"
#define s_protected		"protected"

enum EnumAvpDataType
{
   OctetString =  1,
   Integer32   =  2,
   Integer64   =  3,
   Unsigned32  =  4,
   Unsigned64  =  5,
   Float32     =  6,
   Float64     =  7,
   Grouped     =  8
};

enum EnumAvpGrp
{
   AVP =  1,
   GRP =  2
};

enum EnumMsgGrpClass
{
   MSG_CLASS =  1,
   GRP_CLASS =  2
};

enum EnumEncrypt
{
   ENCRYPT_NO  =  0,
   ENCRYPT_YES =  1
};
 	
typedef vector<int> enumValues;

typedef struct Avp
{
   BOOLEAN  multiple;

   EnumAvpGrp  avpGrp;
   EnumEncrypt encrypt;

   TEXT  avpname[70];
   TEXT  type[50];

   INT16 avpCode;
   INT16 avpFlags;
   INT32 vendorid;
 	enumValues enumValuesList;
}avp;

typedef vector<avp> avpArgs;

typedef struct Message
{
	TEXT			command[100];
	INT16			commandFlags;
	INT16			commandCode;
	INT16			protocolVersion;
	avpArgs		avpArgsList;
	EnumMsgGrpClass	enumMsgGrpClass;
}message;

typedef std::map<string, message> dictionary;

class DiameterCreateSource
{
   public:

      DiameterCreateSource();

      ~DiameterCreateSource();
      
		BOOLEAN GenerateSource();
		
		BOOLEAN 	SetClassName(char *name, int);
		BOOLEAN 	SetCommandFlags(char *, char *, char*, char*);
		BOOLEAN 	SetCommandCode(int);
		BOOLEAN 	SetProtocolVersion(int);
		
		BOOLEAN 	SetAvpNameType(char *, char*);
		BOOLEAN 	SetAvpFlags(char *, char*, char*);
		//BOOLEAN 	SetAvpCode(int);
		BOOLEAN  SetAvpCode(int, char*, int );
		BOOLEAN  SetAvpCodeMultiple(int, char*, int, char*);
		BOOLEAN	InsertAvpDetails();
		BOOLEAN	InsertMessageDetails();
		BOOLEAN  SetVendorId(int);

		BOOLEAN setGroupMark(char *, char*);

		BOOLEAN SetInterfacePath(char*);
		BOOLEAN SetInterface(char*);
   
		BOOLEAN pushEnumList(UINT32 item,string itemName);
		BOOLEAN GenerateEnums();

	private:
		std::map<string,Avp> mDiameterBaseParam;      
		FILE*    mDiameterDataTypeHeaderFile;

      FILE*    mDiamterDataTypeSourceFile;
      
		BOOLEAN 	CreateFiles(string name, FILE** headerFile, FILE** srcFile);

		TEXT		mHeaderFileName[100];

		TEXT     mSourceFileName[100];
      
		TEXT     mTempChar[100];

		TEXT  	mInterfacePath[512];
		TEXT  	mInterface[15];
      
		TEXT* 	to_upper(const char*);
      void     read_directory(const string&, vector<string>& v);

		vector<UINT32>		mEnumList;
      
		string 	mClassName;
		string 	mAvpName;
		string 	mAvpType;
      
		INT16		mCommandFlags; 
		INT16		mCommandCode; 
		INT16		mAvpFlags; 
		INT16		mAvpCode; 
		INT16		mProtocolVer; 

		avp		mAvp;
		avpArgs	mAvpArgs;

      //INT16    mCode;

		message			 mMessage;
      dictionary      mDictionary;
      
		FILE*       mHeaderFile;
      FILE*       mSourceFile;
      
		BOOLEAN GenerateHeaderFile();

      BOOLEAN GenerateSourceFile(string& bitMap);
      
		BOOLEAN generateSourceForEncode();
		
		BOOLEAN generateSourceForDecode();
		
		BOOLEAN generateSourceForFind();

		BOOLEAN generateSourceForFindAll();
		
		BOOLEAN generateSourceForFindAllwithPath();

		BOOLEAN generateSourceForAvpSetGet();

		DiameterDataType ConvertDiameterTypeToEnum(TEXT* type);

		BOOLEAN CreateDiameterHeaderFile(string classname );

		BOOLEAN CreateDiameterBaseFile();

		BOOLEAN CreateDiameterBaseInterfaceFile();

		BOOLEAN CreateDiameterExceptionClass();

		BOOLEAN CreateDiameterConstDef();

		BOOLEAN CreateDiameterStruct();

		BOOLEAN generateSourceForDisplay();

		BOOLEAN generateSourceForMandatoryAvp();

      BOOLEAN GenerateMakeFile();
 };

#endif
