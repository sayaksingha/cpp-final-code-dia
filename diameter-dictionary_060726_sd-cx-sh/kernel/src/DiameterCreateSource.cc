//static const char *id = " @(#) $Id: DiameterCreateSource.cc,v 1.1.2.4.2.1.2.16 2024/03/20 09:45:12 mrafi Exp $";
// @(#) $Id: DiameterCreateSource.cc,v 1.1.2.4.2.1.2.16 2024/03/20 09:45:12 mrafi Exp $
//----------------------------------------------------------------------
// NAME
//       DiameterCreateSource.cc
//
// COPYRIGHT
// Tayana Software Solutions Ltd -- Copyright(C) 2017
// All rights reserved. No part of this computer program
// may be used or reproduced in any form by any
// means without prior written permission of
// Tayana Software Solutions Ltd
//
// DESCRIPTION : This class will create source code for configured 
//               diameter disctionary.
//
//----------------------------------------------------------------------


#include "../include/DiameterCreateSource.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include "boost/dynamic_bitset.hpp"

vector<INT16> CommonFunctions({293,283,263,268,264,296,1,258,282,21258,21259,415,416,268,21250}); //common functions to be generated


#define FILENAME(s, d, ext,type,inf)\
   sprintf((d), "%s/%s/%s%s", inf, type, s, ext)

unsigned gTempVal = 0;
//-----------------------------------------------------------------------------------------------
// METHOD       : Init
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
DiameterCreateSource::DiameterCreateSource()
{
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Init
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
DiameterCreateSource::~DiameterCreateSource()
{
}

//-----------------------------------------------------------------------------------------------
// METHOD       : CreateFiles
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::CreateFiles(string classname, FILE** header, FILE** src)
{
	FILENAME(classname.c_str(), mHeaderFileName, ".h", "include",mInterfacePath);
	*header = fopen(mHeaderFileName, "w");
	if(src != NULL)
	{
		FILENAME(classname.c_str(), mSourceFileName, ".cc" , "src", mInterfacePath);
		*src = fopen(mSourceFileName, "w");
      string temp(to_upper(mInterface));
		fprintf(*header, "#ifndef %s_%s_H\n", temp.c_str(), to_upper(classname.c_str()));
		fprintf(*header, "#define %s_%s_H\n", temp.c_str(), to_upper(classname.c_str()));
		fprintf(*header, "#include \"%s\"\n\n", "DiameterTLVUtil.h");
		fprintf(*header, "#include \"%s\"\n\n", "DiameterBaseInterface.h");
		fprintf(*header, "#include \"%s\"\n\n", "DiameterBasicDecEnc.h");
		fprintf(*header, "#include \"%s\"\n\n", "TssDiameterMsgException.h");
		fprintf(*src, "#include \"%s/include/%s%s\"\n\n", mInterface, classname.c_str(), ".h");
	}

	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : SetInterfacePath
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::SetInterfacePath(char *inf)
{
	snprintf(mInterfacePath,sizeof(mInterfacePath), "%s", inf);
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : SetInterface
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::SetInterface(char *inf)
{
	snprintf(mInterface,sizeof(mInterface), "%s", inf);
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setClassName
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::SetClassName(char *name, int classType)
{
	mClassName = name;
	mMessage.enumMsgGrpClass = (EnumMsgGrpClass)classType;
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setCommandFlags
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::SetCommandFlags(char *flag1, char *flag2, char *flag3, char *flag4)
{
	// OR flags
	if(0 == strcmp(flag1, s_request))
		mCommandFlags |= REQUEST;
	if(0 == strcmp(flag2, s_proxyable))
		mCommandFlags |= PROXYABLE;
	if(0 == strcmp(flag3, s_error))
		mCommandFlags |= ERROR;
	if(0 == strcmp(flag4, s_transmit))
		mCommandFlags |= TRANSMIT;

	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setCommandCode
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::SetCommandCode(int code)
{
	// set code
	mCommandCode = code;
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setProtocolVersion
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::SetProtocolVersion(int protocolver)
{
	// set protocolver
	mProtocolVer = protocolver;
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setAvpNameType
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::SetAvpNameType(char *avpname, char *avptype)
{
	mAvpName = avpname;
	mAvpType = avptype;
	strcpy(mAvp.avpname, mAvpName.c_str());
	strcpy(mAvp.type, mAvpType.c_str());
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : SetAvpFlags
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::SetAvpFlags(char *flag1, char *flag2, char *flag3)
{
	mAvpFlags = 0;
	// OR flags
	if(0 == strcmp(flag1, s_vendor))
		mAvpFlags |= VENDORSPECIFIC;
	if(0 == strcmp(flag2, s_mandatory))
		mAvpFlags |= MANDATORY;
	if(0 == strcmp(flag3, s_protected))
		mAvpFlags |= PROTECTED;

	mAvp.avpFlags = mAvpFlags;
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : SetAvpCode
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::SetAvpCode(int code, char * encrypt, int avpgrp)
{
	mAvpCode = code;
	mAvp.avpCode = mAvpCode;
	mAvp.avpGrp = (EnumAvpGrp)avpgrp;

	if(0 == strcmp(encrypt, "yes"))
	{
		mAvp.encrypt = ENCRYPT_YES;
	}
	else if(0 == strcmp(encrypt, "no"))
	{
		mAvp.encrypt = ENCRYPT_NO;
	}
	
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : SetAvpCodeMultiple
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::SetAvpCodeMultiple(int code, char * encrypt, int avpgrp, char* multiple)
{
	mAvpCode = code;
	mAvp.avpCode = mAvpCode;
	mAvp.avpGrp = (EnumAvpGrp)avpgrp;

	if(0 == strcmp(encrypt, "yes"))
	{
		mAvp.encrypt = ENCRYPT_YES;
	}
	else if(0 == strcmp(encrypt, "no"))
	{
		mAvp.encrypt = ENCRYPT_NO;
	}
	
	if(0 == strcmp(multiple, "yes"))
	{
		mAvp.multiple = 1;
	}
	else
	{
		mAvp.multiple = 0;
	}

	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : SetVendorId
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::SetVendorId(int vendorid)
{
	mAvp.vendorid = vendorid;
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : InsertAvpDetails
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::InsertAvpDetails()
{
	mAvpArgs.push_back(mAvp);
	mAvp.enumValuesList.clear();
	memset(mAvp.type, 0, sizeof(mAvp.type));
	#if 0
	if(mAvpArgs.size() <= 0)
	{
		printf("^^^^^^^^^ Datatype with 0 params : No Size ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ \n");
	}
	else
	{
		printf("^^^^^^^^^ Datatype with Size :%d ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ \n", (mAvpArgs.size()));
	}
	#endif   
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : setGroupMark
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::setGroupMark(char *grpname, char* multiple)
{
	strcpy(mAvp.avpname, grpname);
	if(0 == strcmp(multiple, "yes"))
	{
		mAvp.multiple = 1;
	}
	else
	{
		mAvp.multiple = 0;
	}
	mAvp.avpGrp = GRP;

	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : InsertMessageDetails
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::InsertMessageDetails()
{
	strcpy(mMessage.command, mClassName.c_str());
	mMessage.commandFlags		= 	mCommandFlags;
	mMessage.commandCode			=	mCommandCode;
	mMessage.protocolVersion	=	mProtocolVer;
	mMessage.avpArgsList 		=	mAvpArgs;

#if 0	
	if(mMessage.avpArgsList.size() <= 0)
	{
		printf("!!!!!!!!! mMessage.avpArgsList.size  NO Size\n");
	}
	else
	{
		printf("^^^^^^^^^ Datatype with YES Size :%d ^^^^^^^^^^^^^^^^^^^^^ \n", (mMessage.avpArgsList.size()));
	}
#endif	
	mDictionary.insert(std::pair<string, message>(mMessage.command, mMessage));

	std::map<string, message>::iterator lList = mDictionary.find(mMessage.command);

	if(lList == mDictionary.end())
	{
		cout << "Failed to insert into map List " << mMessage.command << endl;
		return false;
	}
	else
	{
		mMessage = lList->second;
		mAvpArgs = mMessage.avpArgsList;

		if(mAvpArgs.size() <= 0)
		{
			//printf("@@@@@@@@@ Datatype with 0 params is %s\n", (lList->first).c_str());
		}

		vector<avp>::iterator list = mAvpArgs.begin();
		while(list != mAvpArgs.end())
		{
			//printf("$$$$$$ avpname:%s type:%s avpCode:%d avpFlags:%d multiple:%d avpGrp:%d\n", 
			//		list->avpname, list->type, list->avpCode, list->avpFlags, list->multiple, list->avpGrp);
			list++;
		}
		mAvpArgs.clear();
	}
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : GenerateSource
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::GenerateSource()
{
	string classname = "DiameterMsgHeader";
	
	if(strcmp(mInterface,"base") == 0)
	{
		this->CreateDiameterHeaderFile(classname );
	}

	std::map<string, message>::iterator lList = mDictionary.begin();
	while(lList != mDictionary.end())
	{
		mMessage = lList->second;
		mAvpArgs = mMessage.avpArgsList;
		if(mAvpArgs.size() <= 0)
		{
			printf("Datatype with 0 params is %s\n", (lList->first).c_str());
			lList++;
			continue;
		}
		else
		{
			//printf("\tNumber of Elements:%d\n",(int)mAvpArgs.size() );
			//printf("command:%s commandFlags:%d commandCode:%d protocolVersion:%d \n",
					//mMessage.command, mMessage.commandFlags, mMessage.commandCode, mMessage.protocolVersion );

			this->CreateFiles(mMessage.command, &mHeaderFile, &mSourceFile);
			fprintf(mHeaderFile, "#include \"%s.h\"\n\n", FILE_DIAMETER_DATA_TYPES);
			
			vector<avp>::iterator list = mAvpArgs.begin();
			while(list != mAvpArgs.end())
			{
				if(GRP == list->avpGrp)
				{  
               if(((strcmp(mInterface,"gx") == 0) || (strcmp(mInterface,"rx") == 0) || (strcmp(mInterface,"ro") == 0) || (strcmp(mInterface,"s6a") == 0)) 
                     && ((strcmp(list->avpname, "ProxyInfo") == 0) || (strcmp(list->avpname, "VendorSpecificApplicationId") == 0)))
               {
                  printf("111. %s:%s\n", mInterface, list->avpname);
               }
               else
               {
					   fprintf(mHeaderFile, "#include \"%s/include/%s.h\"\n", mInterface, list->avpname);
               }
				}
				
            if(AVP == list->avpGrp && strcmp(list->type,"Enumerated") == 0 )
				{
               // 17 May 2019 added for CCRequestType & ProxyInfo virtual function
               if(((strcmp(mInterface,"base") == 0)) 
                     && ((strcmp(list->avpname, "CCRequestType") == 0) || strcmp(list->avpname, "ProxyInfo") == 0))
               {
                  printf("1. %s:%s\n", mInterface, list->avpname);
                  fprintf(mHeaderFile, "#include \"%s/include/%s.h\"\n", mInterface, list->avpname);
               }
               else if(((strcmp(mInterface,"gx") == 0) || (strcmp(mInterface,"rx") == 0) || (strcmp(mInterface,"ro") == 0)) 
                     && ((strcmp(list->avpname, "ProxyInfo") == 0) || (strcmp(list->avpname, "CCRequestType") == 0)))
               {
                  printf("2. %s:%s\n", mInterface, list->avpname);
               }
               else if((strcmp(mInterface,"base") != 0) 
                     && (strcmp(list->avpname, "CCRequestType") != 0) )
               {
                  printf("3. %s:%s\n", mInterface, list->avpname);
                  fprintf(mHeaderFile, "#include \"%s/include/%s.h\"\n", mInterface, list->avpname);
               }
               //else
               //{
               //   printf("4. %s:%s\n", mInterface, list->avpname);
               //   fprintf(mHeaderFile, "#include \"%s/include/%s.h\"\n", mInterface, list->avpname);
              // }
               //else if(((strcmp(mInterface,"gx") == 0) || (strcmp(mInterface,"rx") == 0) || (strcmp(mInterface,"ro") == 0)) 
               //      && (strcmp(list->avpname, "ProxyInfo") != 0) )
               //{
               //   printf("4. %s:%s\n", mInterface, list->avpname);
               //   fprintf(mHeaderFile, "#include \"%s/include/%s.h\"\n", mInterface, list->avpname);
               //}
				}
				list++;
			}
			if (mMessage.enumMsgGrpClass == MSG_CLASS)
			{
				fprintf(mHeaderFile, "#include \"base/include/DiameterBase.h\"\n");
				fprintf(mHeaderFile, "#include \"DiameterBaseInterface.h\"\n");
				fprintf(mHeaderFile, "#include \"base/include/DiameterMsgHeader.h\"\n");
			}

			fprintf(mHeaderFile, "using namespace std;\n\n" );

			this->GenerateHeaderFile();
			fprintf(mHeaderFile, "\n\n#endif\n");
			fclose(mHeaderFile);
			fclose(mSourceFile);

			lList++;
		}
	}
	this->CreateDiameterBaseFile();
	this->GenerateEnums();
   this->GenerateMakeFile();

	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : to_upper
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
char* DiameterCreateSource::to_upper(const char* src_string)
{
	unsigned lTemp = 0;
	while(src_string[lTemp] != '\0')
	{
		mTempChar[lTemp] = toupper(src_string[lTemp]);
		lTemp++;
	}
	mTempChar[lTemp] = '\0';

	return mTempChar;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : GenerateHeaderFile
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::GenerateHeaderFile()
{
	fprintf(mHeaderFile, "namespace %s{\n", to_upper(mInterface));
	fprintf(mHeaderFile, "typedef enum _tags_%s\n{\n", mMessage.command);
	//unsigned long lTemp = 0;
	size_t numberOfParams = mAvpArgs.size();
	//cout<<"SIZE: "<<numberOfParams<<endl;	
	boost::dynamic_bitset<> lBitMap(numberOfParams);//store bits corresponding to AVP wise mandatory flag
	unsigned lTemp = 0;
	vector<avp>::iterator list = mAvpArgs.begin();
	while(list != mAvpArgs.end())
	{
		if (((list->avpFlags&0x40)?true:false))
		{
			lBitMap[lTemp] = 1; //set bit for AVP wise mandatory flag
		}
			fprintf(mHeaderFile, "\t%s_%s\t= %u,\n", mMessage.command, to_upper(list->avpname), lTemp);
			lTemp++;
		list++;
	}

	fprintf(mHeaderFile, "}%s_tags;\n\n", mMessage.command);
	fprintf(mHeaderFile, "\t\t//! Class Definition\n\t\t/*!");
	fprintf(mHeaderFile, "\t\tClassName is %s\n", mMessage.command);
	fprintf(mHeaderFile, "\t\t*/\n");
	if( mMessage.enumMsgGrpClass == MSG_CLASS) { 
	fprintf(mHeaderFile, "class %s : public DiameterBase \n", mMessage.command);
	} else {
	fprintf(mHeaderFile, "class %s : public DiameterBaseInterface\n", mMessage.command);
	}
	fprintf(mHeaderFile, "{\n");
	fprintf(mHeaderFile, "\tprivate:\n");
	fprintf(mHeaderFile, "\n");

	fprintf(mHeaderFile, "\t\tbitset<%ld> mTagsPresent;\n\n", numberOfParams);
	fprintf(mHeaderFile, "\t\tbitset<%ld> mMandatoryAvpCheckVal;\n\n", numberOfParams);
	fprintf(mHeaderFile, "\t\tbitset<%ld> mMandatoryAvpSetVal;\n\n", numberOfParams);
	fprintf(mHeaderFile, "\t\tunsigned mTag;\n\n");
	fprintf(mHeaderFile, "\t\tBOOLEAN mDecodeFlag = false;\n\n");
	fprintf(mHeaderFile, "\t\tvector<DiameterBaseInterface*> mBaseInterfaceList;\n\n");

	if( mMessage.enumMsgGrpClass != MSG_CLASS)
	{
		fprintf(mHeaderFile, "\t\tUINT32 mAvpCode = 0;\n\n");
		fprintf(mHeaderFile, "\t\tUINT32 mAvpVendorId = 0;\n\n");
		fprintf(mHeaderFile, "\t\tpair<INT16,INT16> mAvpOffsetLen;\n\n");
	}
	list = mAvpArgs.begin();

	while(list != mAvpArgs.end())
	{
		if(AVP == list->avpGrp)
		{
			if( list->multiple  == 0 )
			{
				if(strcmp(list->type, "NULL") == 0)
				{
					fprintf(mHeaderFile, "\t\tBOOLEAN \t\tm%s;\n\n", list->avpname);
				}
				else
				{
					if(strcmp(list->type, "Enumerated") == 0)
						fprintf(mHeaderFile, "\t\t%s*\t\tm%s;\n\n", list->avpname, list->avpname);
					else
						fprintf(mHeaderFile, "\t\t%s*\t\tm%s;\n\n", list->type, list->avpname);
				}
			} 
			else
		   {
				if(strcmp(list->type, "Enumerated") == 0)
				{
					fprintf(mHeaderFile, "\t\tlist<%s*>* \t\tm%sList;\n\n", list->avpname, list->avpname);
					fprintf(mHeaderFile, "\t\tlist<%s*>::iterator \t\tm%sIterator;\n\n", list->avpname, list->avpname);
				}
				else
				{
					fprintf(mHeaderFile, "\t\tlist<%s*>* \t\tm%sList;\n\n", list->type, list->avpname);
					fprintf(mHeaderFile, "\t\tlist<%s*>::iterator \t\tm%sIterator;\n\n", list->type, list->avpname);
				}
			}
		}
		list++;
	}
	list = mAvpArgs.begin();
	while(list != mAvpArgs.end())
	{
		fprintf(mHeaderFile, "\n");
		if(GRP == list->avpGrp && 1 == list->multiple)
		{
			fprintf(mHeaderFile, "\t\tlist<%s*>*\tm%sGrpList;\n", list->avpname, list->avpname);
			fprintf(mHeaderFile, "\t\tlist<%s*>::iterator\tm%sGrpIterator;\n", list->avpname, list->avpname);
		}
		else if(GRP == list->avpGrp && 0 == list->multiple)
		{
			fprintf(mHeaderFile, "\t\t%s*\tm%sGrp;\n", list->avpname, list->avpname);
		}
		list++;
	}
	fprintf(mHeaderFile, "\n");
	fprintf(mHeaderFile, "\tpublic:\n");
	fprintf(mHeaderFile, "\t\t%s();\n\n", mMessage.command);

   // Adding copy constructor 04/12/19 
	fprintf(mHeaderFile, "\t\t%s(const %s &obj%s) {\n\n", mMessage.command, mMessage.command, mMessage.command);
	
   fprintf(mHeaderFile, "\t\tmTagsPresent = obj%s.mTagsPresent;\n\n", mMessage.command);
	fprintf(mHeaderFile, "\t\tmMandatoryAvpCheckVal = obj%s.mMandatoryAvpCheckVal;\n\n", mMessage.command);
	fprintf(mHeaderFile, "\t\tmMandatoryAvpSetVal = obj%s.mMandatoryAvpSetVal;\n\n", mMessage.command);
	fprintf(mHeaderFile, "\t\tmTag = obj%s.mTag;\n\n", mMessage.command);
	fprintf(mHeaderFile, "\t\tmDecodeFlag = obj%s.mDecodeFlag;\n\n", mMessage.command);

	
   list = mAvpArgs.begin();
	while(list != mAvpArgs.end())
	{
   // Copy constructor for variables
		if(AVP == list->avpGrp)
		{
			if( list->multiple  == 0 )
         {
            //if(strcmp(list->type, "NULL") == 0)
            //{
            //		fprintf(mHeaderFile, "\t\tBOOLEAN \t\tm%s;\n\n", list->avpname);
            //	}
            //	else     
            if(strcmp(list->type, "Enumerated") == 0)
            {
               fprintf(mHeaderFile, "\t\tif(obj%s.m%s != NULL)\n", mMessage.command, list->avpname);
               fprintf(mHeaderFile, "\t\tm%s = new %s(*(obj%s.m%s));\n\n", list->avpname, list->avpname, mMessage.command, list->avpname);
            }
            else
            {
               //if(objTARequest.mActualTime != NULL)  TBR **************
               fprintf(mHeaderFile, "\t\tif(obj%s.m%s != NULL)\n", mMessage.command, list->avpname);
               fprintf(mHeaderFile, "\t\tm%s = new %s(*(obj%s.m%s));\n\n", list->avpname, list->type, mMessage.command, list->avpname);
            }
         }
      } 
      ////////////////////  
		if(GRP == list->avpGrp && 1 == list->multiple)
		{
         fprintf(mHeaderFile, "\t\tif(obj%s.m%sGrpList != NULL)\n", mMessage.command, list->avpname);
         fprintf(mHeaderFile, "\t\t {\n");
         fprintf(mHeaderFile, "\t\t m%sGrpList = new list<%s*>;\n", list->avpname, list->avpname);
         fprintf(mHeaderFile, "\t\t for( auto element : *obj%s.m%sGrpList)\n", mMessage.command, list->avpname);
         fprintf(mHeaderFile, "\t\t {\n");
         fprintf(mHeaderFile, "\t\t\t\t %s *l%s =  new %s(*element);\n", list->avpname, list->avpname, list->avpname);
			fprintf(mHeaderFile, "\t\t\t\t m%sGrpList->push_back(l%s);\n", list->avpname, list->avpname);
         fprintf(mHeaderFile, "\t\t }\n");
         fprintf(mHeaderFile, "\t\t }\n");
		}
		else if(GRP == list->avpGrp && 0 == list->multiple)
		{
			//fprintf(mHeaderFile, "\t\t m%sGrp = new %s*;\n", list->avpname, list->avpname);
         fprintf(mHeaderFile, "\t\tif(obj%s.m%sGrp != NULL)\n", mMessage.command, list->avpname);
         fprintf(mHeaderFile, "\t\t {\n");
         fprintf(mHeaderFile, "\t\t\t\t m%sGrp =  new %s(*obj%s.m%sGrp);\n", list->avpname, list->avpname, mMessage.command,list->avpname);
         fprintf(mHeaderFile, "\t\t }\n");
		}
		list++;
	}

   fprintf(mHeaderFile, "\t\t}\n\n");
   
   // Adding Assignment operator  04/12/19 
	//fprintf(mHeaderFile, "\t\t%s& operator = (const %s &obj%s) {\n\n", mMessage.command, mMessage.command, mMessage.command);
	fprintf(mHeaderFile, "\t\tvoid operator = (const %s &obj%s) {\n\n", mMessage.command, mMessage.command);
	
   fprintf(mHeaderFile, "\t\tmTagsPresent = obj%s.mTagsPresent;\n\n", mMessage.command);
	fprintf(mHeaderFile, "\t\tmMandatoryAvpCheckVal = obj%s.mMandatoryAvpCheckVal;\n\n", mMessage.command);
	fprintf(mHeaderFile, "\t\tmMandatoryAvpSetVal = obj%s.mMandatoryAvpSetVal;\n\n", mMessage.command);
	fprintf(mHeaderFile, "\t\tmTag = obj%s.mTag;\n\n", mMessage.command);
	fprintf(mHeaderFile, "\t\tmDecodeFlag = obj%s.mDecodeFlag;\n\n", mMessage.command);


 
   list = mAvpArgs.begin();
	while(list != mAvpArgs.end())
	{
   // Copy constructor for variables
		if(AVP == list->avpGrp)
		{
			if( list->multiple  == 0 )
         {
            //if(strcmp(list->type, "NULL") == 0)
            //{
            //		fprintf(mHeaderFile, "\t\tBOOLEAN \t\tm%s;\n\n", list->avpname);
            //	}
            //	else     
            if(strcmp(list->type, "Enumerated") == 0)
            {
               fprintf(mHeaderFile, "\t\tif(obj%s.m%s != NULL)\n", mMessage.command, list->avpname);
               fprintf(mHeaderFile, "\t\tm%s = new %s(*(obj%s.m%s));\n\n", list->avpname, list->avpname, mMessage.command, list->avpname);
            }
            else
            {
               fprintf(mHeaderFile, "\t\tif(obj%s.m%s != NULL)\n", mMessage.command, list->avpname);
               fprintf(mHeaderFile, "\t\tm%s = new %s(*(obj%s.m%s));\n\n", list->avpname, list->type, mMessage.command, list->avpname);
            }
         }
      } 
      ////////////////////  
      if(GRP == list->avpGrp && 1 == list->multiple)
		{
         fprintf(mHeaderFile, "\t\tif(obj%s.m%sGrpList != NULL)\n", mMessage.command, list->avpname);
         fprintf(mHeaderFile, "\t\t {\n");
			fprintf(mHeaderFile, "\t\t m%sGrpList = new list<%s*>;\n", list->avpname, list->avpname);
         fprintf(mHeaderFile, "\t\t for( auto element : *obj%s.m%sGrpList)\n", mMessage.command, list->avpname);
         fprintf(mHeaderFile, "\t\t {\n");
         fprintf(mHeaderFile, "\t\t\t\t %s *l%s =  new %s(*element);\n", list->avpname, list->avpname, list->avpname);
			fprintf(mHeaderFile, "\t\t\t\t m%sGrpList->push_back(l%s);\n", list->avpname, list->avpname);
         fprintf(mHeaderFile, "\t\t }\n");
         fprintf(mHeaderFile, "\t\t }\n");
		}
		else if(GRP == list->avpGrp && 0 == list->multiple)
		{
			//fprintf(mHeaderFile, "\t\t m%sGrp = new %s*;\n", list->avpname, list->avpname);
         fprintf(mHeaderFile, "\t\tif(obj%s.m%sGrp != NULL)\n", mMessage.command, list->avpname);
         fprintf(mHeaderFile, "\t\t {\n");
         fprintf(mHeaderFile, "\t\t\t\t m%sGrp =  new %s(*obj%s.m%sGrp);\n", list->avpname, list->avpname, mMessage.command,list->avpname);
         fprintf(mHeaderFile, "\t\t }\n");
		}
		list++;
	}
   
   fprintf(mHeaderFile, "\t\t}\n\n");
	
   // ---------------------------------------------------------------------------------------------
   // ---------------------------------------------------------------------------------------------

	fprintf(mHeaderFile, "\t\tvirtual ~%s();\n\n", mMessage.command);
	fprintf(mHeaderFile, "\t\tBOOLEAN isPresent(int);\n\n");
   fprintf(mHeaderFile, "\t\tBOOLEAN mAvpDecodedFlag = true;\n\n");
	fprintf(mHeaderFile, "\t\tstd::shared_ptr<byteArray> mspByteArray;\n\n");

	list = mAvpArgs.begin();
	while(list != mAvpArgs.end())
	{
		if(AVP == list->avpGrp)
		{
			if( 0 == list->multiple)
			{
				if(strcmp(list->type, "NULL") == 0)
				{
					fprintf(mHeaderFile, "\t\t//! Function to set new values\n\t\t/*!");
					fprintf(mHeaderFile, "\t\tFunction to set %s type of argument %s for datatype %s\n", "NULL", list->avpname, mMessage.command);
					fprintf(mHeaderFile, "\t\t*/\n");
					fprintf(mHeaderFile, "\t\tBOOLEAN* set%s();\n\n", list->avpname);
					
               // RESET functionality added.
               fprintf(mHeaderFile, "\t\t//! Function to reset \n\t\t/*!");
					fprintf(mHeaderFile, "\t\tFunction to reset %s type of argument %s for datatype %s\n", "NULL", list->avpname, mMessage.command);
					fprintf(mHeaderFile, "\t\t*/\n");
					fprintf(mHeaderFile, "\t\tvoid reset%s();\n\n", list->avpname);

					fprintf(mHeaderFile, "\t\t//! Function to get values\n\t\t/*!");
					fprintf(mHeaderFile, "\t\tFunction to get %s type of argument %s for datatype %s\n", "NULL", list->avpname, mMessage.command);
					fprintf(mHeaderFile, "\t\tThrows exception of which type and Summary of Exception\n");
					fprintf(mHeaderFile, "\t\t*/\n");
					fprintf(mHeaderFile, "\t\tBOOLEAN get%s();\n\n", list->avpname);
				}
				else
				{
					if(0 != strcmp(list->type, "Enumerated"))
					{
						fprintf(mHeaderFile, "\t\t//!Function to set values\n\t\t/*!");
						fprintf(mHeaderFile, "\t\tFunction to set the recent %s type of argument %s for datatype %s\n", list->type, list->avpname, mMessage.command);
						fprintf(mHeaderFile, "\t\t*/\n");
						fprintf(mHeaderFile, "\t\t%s* set%s();\n\n", list->type , list->avpname);
                  
                  // RESET functionality added.
                  fprintf(mHeaderFile, "\t\t//! Function to reset \n\t\t/*!");
                  fprintf(mHeaderFile, "\t\tFunction to reset %s type of argument %s for datatype %s\n", "NULL", list->avpname, mMessage.command);
                  fprintf(mHeaderFile, "\t\t*/\n");
                  fprintf(mHeaderFile, "\t\tvoid reset%s();\n\n", list->avpname);

						fprintf(mHeaderFile, "\t\t//!Function to get values\n\t\t/*!");
						fprintf(mHeaderFile, "\t\tFunction to get %s type of argument %s for datatype %s\n", list->type, list->avpname, mMessage.command);
						fprintf(mHeaderFile, "\t\tThrows exception of which type and Summary of Exception\n");
						fprintf(mHeaderFile, "\t\t*/\n");
						fprintf(mHeaderFile, "\t\t%s* get%s();\n\n",  list->type , list->avpname);
					}
					else
					{
						fprintf(mHeaderFile, "\t\t//!Function to set values\n\t\t/*!");
						fprintf(mHeaderFile, "\t\tFunction to set the recent %s type of argument %s for datatype %s\n", list->type, list->avpname, mMessage.command);
						fprintf(mHeaderFile, "\t\t*/\n");
						fprintf(mHeaderFile, "\t\t%s* set%s();\n\n", list->avpname , list->avpname);
               
                  // RESET functionality added.
                  fprintf(mHeaderFile, "\t\t//! Function to reset \n\t\t/*!");
                  fprintf(mHeaderFile, "\t\tFunction to reset %s type of argument %s for datatype %s\n", "NULL", list->avpname, mMessage.command);
                  fprintf(mHeaderFile, "\t\t*/\n");
                  fprintf(mHeaderFile, "\t\tvoid reset%s();\n\n", list->avpname);

						fprintf(mHeaderFile, "\t\t//!Function to get values\n\t\t/*!");
						fprintf(mHeaderFile, "\t\tFunction to get %s type of argument %s for datatype %s\n", list->avpname, list->avpname, mMessage.command);
						fprintf(mHeaderFile, "\t\tThrows exception of which type and Summary of Exception\n");
						fprintf(mHeaderFile, "\t\t*/\n");
						fprintf(mHeaderFile, "\t\t%s* get%s();\n\n",  list->avpname , list->avpname);

					}
				}
			}
			else
			{
				if(0 != strcmp(list->type, "Enumerated"))
				{
					fprintf(mHeaderFile, "\t\tlist<%s*>* get%sList();\n\n", list->type, list->avpname);
					fprintf(mHeaderFile, "\t\tlist<%s*>* set%sList();\n\n", list->type, list->avpname);
					fprintf(mHeaderFile, "\t\tvoid reset%sList();\n\n", list->avpname);
				}
				else
				{
					fprintf(mHeaderFile, "\t\tlist<%s*>* get%sList();\n\n", list->avpname, list->avpname);
					fprintf(mHeaderFile, "\t\tlist<%s*>* set%sList();\n\n", list->avpname, list->avpname);
					fprintf(mHeaderFile, "\t\tvoid reset%sList();\n\n", list->avpname);

				}
			}
		}
		else
		{
			if(1 == list->multiple)
			{
				fprintf(mHeaderFile, "\t\tlist<%s*>* get%sGrpList();\n\n", list->avpname, list->avpname);
				fprintf(mHeaderFile, "\t\tlist<%s*>* set%sGrpList();\n\n", list->avpname, list->avpname);
				fprintf(mHeaderFile, "\t\tvoid reset%sGrpList();\n\n", list->avpname);
			}
			else 
			{
				fprintf(mHeaderFile, "\t\t%s* get%s();\n\n", list->avpname, list->avpname);
				fprintf(mHeaderFile, "\t\t%s* set%s();\n\n", list->avpname, list->avpname);
				fprintf(mHeaderFile, "\t\tvoid reset%s();\n\n", list->avpname);
			} 
		}
		list++;
	}

	//Generating code for isPresent function, this will return bool if tag passed is present
   fprintf(mSourceFile, "using namespace %s;\n", to_upper(mInterface));
	fprintf(mSourceFile, "BOOLEAN %s::isPresent(int tag){\n", mMessage.command);
	fprintf(mSourceFile, "\treturn (mTagsPresent[tag])?true:false;\n");
	fprintf(mSourceFile, "}\n\n");

	fprintf(mHeaderFile, "\t\t//! Function to Decode\n\t\t/*!");
	fprintf(mHeaderFile, "\t\tFunction to Decode datatype %s\n", mMessage.command);
	fprintf(mHeaderFile, "\t\t*/\n");
	if( mMessage.enumMsgGrpClass == MSG_CLASS)
		fprintf(mHeaderFile, "\t\tint Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);\n");
	else
	{
		fprintf(mHeaderFile, "\t\tint Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);\n");
		fprintf(mHeaderFile, "\t\tUINT32 getAvpCode();\n");
		fprintf(mHeaderFile, "\t\tINT32 setAvpCode(UINT32 avpCode);\n");
		fprintf(mHeaderFile, "\t\tUINT32 getAvpVendorId();\n");
		fprintf(mHeaderFile, "\t\tINT32 setAvpVendorId(UINT32 avpVendorId);\n");
		fprintf(mHeaderFile, "\t\tpair<INT16,INT16> getAvpOffsetLen();\n");
		fprintf(mHeaderFile, "\t\tINT32 setAvpOffsetLen(INT16 offset, INT16 length);\n");
	}

	fprintf(mHeaderFile, "\t\t//! Function to Find\n\t\t/*!");
	fprintf(mHeaderFile, "\t\tFunction to Find datatype %s\n", mMessage.command);
	fprintf(mHeaderFile, "\t\t*/\n");
	fprintf(mHeaderFile, "\t\tDiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);\n");

	fprintf(mHeaderFile, "\t\t//! Function to Find multiple occurence\n\t\t/*!");
	fprintf(mHeaderFile, "\t\tFunction to Find datatype %s\n", mMessage.command);
	fprintf(mHeaderFile, "\t\t*/\n");
	fprintf(mHeaderFile, "\t\tBOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);\n");
	fprintf(mHeaderFile, "\t\tBOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);\n");
   // 28 May 19 Added Get Byte Array 
	fprintf(mHeaderFile, "\t\tstd::shared_ptr<byteArray> GetByteArray( );\n");

	fprintf(mHeaderFile, "\t\t//! Function to Encode\n\t\t/*!");
	fprintf(mHeaderFile, "\t\tFunction to Encode datatype %s\n", mMessage.command);
	fprintf(mHeaderFile, "\t\t*/\n");
	fprintf(mHeaderFile, "\t\tint Encode(byteArray *array);\n");
	fprintf(mHeaderFile, "\t\t//! Function to Display\n\t\t/*!");
	fprintf(mHeaderFile, "\t\tFunction to Display datatype %s\n", mMessage.command);
	fprintf(mHeaderFile, "\t\t*/\n");
	fprintf(mHeaderFile, "\t\tvoid Display(UINT32 tab);\n");
	
	fprintf(mHeaderFile, "\t\tBOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);\n");

	fprintf(mHeaderFile, "\n};\n");
	fprintf(mHeaderFile, "\n}\n");

	string buffer;
	boost::to_string(lBitMap, buffer);//get bit pattern as string
	this->GenerateSourceFile(buffer);

	lBitMap.reset();
	mAvpArgs.clear();

	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : Init
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::GenerateSourceFile(string& buffer)
{
	static int count = 1;
	//Generating Class Constructor
	fprintf(mSourceFile, "%s::%s()\n{\n", mMessage.command, mMessage.command);

	vector<avp>::iterator list = mAvpArgs.begin();

	while(list != mAvpArgs.end())
	{
		if(AVP == list->avpGrp)
		{
			if( list->multiple == false)
				fprintf(mSourceFile, "\tm%s = NULL;\n", list->avpname);
			else 
				fprintf(mSourceFile, "\tm%sList = NULL;\n", list->avpname);
		}
		else
		{
			if( list->multiple == false)
				fprintf(mSourceFile, "\tm%sGrp = NULL;\n", list->avpname);
			else 
				fprintf(mSourceFile, "\tm%sGrpList = NULL;\n", list->avpname);
		}
		list++;
	}
	fprintf(mSourceFile, "\tmTagsPresent.reset();\n");

	//restore bit pattern to bitset from string
	fprintf(mSourceFile, "\tmMandatoryAvpCheckVal= bitset<%ld>(string(\"%s\"));\n", mAvpArgs.size(), buffer.c_str());
	fprintf(mSourceFile, "\tmMandatoryAvpSetVal.reset();\n");
   //gTempVal = 0;
	fprintf(mSourceFile, "}\n\n");

	//Generating Class Destructor 
	fprintf(mSourceFile, "%s::~%s()\n{\n", mMessage.command, mMessage.command);
	list = mAvpArgs.begin();
	while(list != mAvpArgs.end())
	{
		if(AVP == list->avpGrp)
		{
			if(strcmp(list->type, "NULL"))
			{
				if( list->multiple == 0)
					//fprintf(mSourceFile, "\tif(m%s != NULL)\n\t\tdelete m%s;\n\t\tm%s = NULL;\n", list->avpname, list->avpname, list->avpname);
					fprintf(mSourceFile, "\tif(m%s != NULL)\n\t\tdelete m%s;\n", list->avpname, list->avpname, list->avpname);
				else
				{
					fprintf(mSourceFile, "\tif(m%sList != NULL){\n", list->avpname);
					fprintf(mSourceFile, "\t\tm%sIterator = m%sList->begin();\n", list->avpname, list->avpname );
					fprintf(mSourceFile, "\t\twhile(m%sIterator != m%sList->end()){\n", list->avpname, list->avpname );
					fprintf(mSourceFile, "\t\t\tdelete (*m%sIterator);\n", list->avpname);
					fprintf(mSourceFile, "\t\t\tm%sIterator++;\n",list->avpname );
					fprintf(mSourceFile, "\t\t}\n");
					//fprintf(mSourceFile, "\t\tdelete m%sList;\n\t\tm%sList = NULL;\n", list->avpname, list->avpname);
					fprintf(mSourceFile, "\t\tdelete m%sList;\n", list->avpname, list->avpname);
					fprintf(mSourceFile,"\t}\n");
				}
			}
		}
		else
		{
			if( list->multiple == 0)
				fprintf(mSourceFile, "\tif(m%sGrp != NULL)\n\t\tdelete m%sGrp;\n", list->avpname, list->avpname);
			else
			{
				fprintf(mSourceFile, "\tif(m%sGrpList != NULL){\n", list->avpname);
				fprintf(mSourceFile, "\t\tm%sGrpIterator = m%sGrpList->begin();\n", list->avpname, list->avpname );
				fprintf(mSourceFile, "\t\twhile(m%sGrpIterator != m%sGrpList->end()){\n", list->avpname, list->avpname );
				fprintf(mSourceFile, "\tif(*m%sGrpIterator != NULL)\n", list->avpname); // Added on 16Jan2020
				fprintf(mSourceFile, "\t\t\tdelete (*m%sGrpIterator);\n", list->avpname);
				fprintf(mSourceFile, "\t\t\tm%sGrpIterator++;\n", list->avpname);
				fprintf(mSourceFile, "\t\t}\n");
				//fprintf(mSourceFile, "\t\tdelete m%sGrpList;\n\t\tm%sGrpList = NULL;\n", list->avpname, list->avpname);
				fprintf(mSourceFile, "\t\tdelete m%sGrpList;\n", list->avpname, list->avpname);
				fprintf(mSourceFile, "\t}\n");
			}
		}
		list++;
	}
	fprintf(mSourceFile, "}\n\n");


	list = mAvpArgs.begin();
	char  lTemp[100] = "";

	while(list != mAvpArgs.end())
	{
		if(AVP == list->avpGrp)
		{
			if ( list->multiple == 0 )
			{
				if(strcmp(list->type, "NULL") == 0)
				{
					fprintf(mSourceFile, "BOOLEAN %s::set%s(){\n", mMessage.command, list->avpname);
				}
				else
				{
					if(0 == strcmp(list->type, "Enumerated"))
					{
						fprintf(mSourceFile, "%s* %s::set%s(){\n", list->avpname, mMessage.command, list->avpname);
					}
					else
					{
						fprintf(mSourceFile, "%s* %s::set%s(){\n", list->type, mMessage.command, list->avpname);
					}
				}
				sprintf(lTemp, "m%s", list->avpname);
				
				if (((list->avpFlags&0x40)?true:false))
					fprintf(mSourceFile, "\tmMandatoryAvpSetVal [%s_%s] = 1;\n", mMessage.command, to_upper(list->avpname));
				
				if(0 == strcmp(list->type, "Enumerated"))
				{
					 fprintf(mSourceFile, "\tif(%s == NULL)\n\t{\n\t\t%s = new %s();\n\t\tmTagsPresent[%s_%s] = 1;\n\t\treturn %s;\n\t}\n\treturn %s;",
                     lTemp, lTemp, list->avpname,  mMessage.command, to_upper(list->avpname), lTemp, lTemp);
				}
				else
				{
					fprintf(mSourceFile, "\tif(%s == NULL)\n\t{\n\t\t%s = new %s();\n\t\tmTagsPresent[%s_%s] = 1;\n\t\treturn %s;\n\t}\n\treturn %s;", 
							lTemp, lTemp, list->type,  mMessage.command, to_upper(list->avpname), lTemp, lTemp);
				}			
	
				fprintf(mSourceFile, "\n}\n\n");

			}
		}
	
      // Added RESET functionality	
      if(AVP == list->avpGrp)
      {
         //if (!((list->avpFlags&0x40)?true:false))
         {
            if ( list->multiple == 0 )
            {
               if(strcmp(list->type, "NULL") == 0)
               {
                  fprintf(mSourceFile, "void %s::reset%s(){\n", mMessage.command, list->avpname);
               }
               else
               {
                  if(0 == strcmp(list->type, "Enumerated"))
                  {
                     fprintf(mSourceFile, "void %s::reset%s(){\n", mMessage.command, list->avpname);
                  }
                  else
                  {
                     fprintf(mSourceFile, "void %s::reset%s(){\n", mMessage.command, list->avpname);
                  }
               }
               sprintf(lTemp, "m%s", list->avpname);

               //if(0 == strcmp(list->type, "Enumerated"))
               {
                  fprintf(mSourceFile, "\tmTagsPresent[%s_%s] = 0;\n", mMessage.command, to_upper(list->avpname));
                  //fprintf(mSourceFile, "\tif(%s != NULL)\n\t\t\tdelete %s;", lTemp, lTemp);
                  fprintf(mSourceFile, "\tif(%s != NULL)\n\t{\n\t\tdelete %s; \n\t\t%s = NULL;\n\t}", lTemp, lTemp, lTemp);
               }

               fprintf(mSourceFile, "\n}\n\n");

            }
         }
      }
      list++; 
   }

   list = mAvpArgs.begin();
   while(list != mAvpArgs.end())
   {
      if(AVP == list->avpGrp)
      {
         if ( list->multiple == 0 )
         {
            if(strcmp(list->type, "NULL") == 0)
            {
               fprintf(mSourceFile, "BOOLEAN %s::get%s(){\n", list->type, mMessage.command );
               fprintf(mSourceFile, "\tif(NULL == m%s){\n", list->avpname);
               fprintf(mSourceFile, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, \"%s is Null\");\n",list->avpname);
               fprintf(mSourceFile, "\t\tthrow lTssDiaMsgException;\n");
               fprintf(mSourceFile, "\t}\n" );
					fprintf(mSourceFile, "\tif(!m%s->mAvpDecodedFlag)\n", list->avpname );
					fprintf(mSourceFile, "\t{\n" );
               // mspByteArray shared memory check added to avoid seg fault
					fprintf(mSourceFile, "\tif(mspByteArray.get() == NULL)\n" );
					fprintf(mSourceFile, "\t\t{\n" );
					fprintf(mSourceFile, "\tm%s->mAvpDecodedFlag = true;\n", list->avpname );
               fprintf(mSourceFile, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, \"%s is Null\");\n",list->avpname);
               fprintf(mSourceFile, "\t\tthrow lTssDiaMsgException;\n");
               fprintf(mSourceFile, "\t}\n" );

					fprintf(mSourceFile, "\t\tmspByteArray.get()->offset = 0;\n" );
					fprintf(mSourceFile, "\t\tmspByteArray.get()->offset = m%s->getAvpOffsetLen().first;\n", list->avpname );
					fprintf(mSourceFile, "\t\tUINT16 lBytesDecoded = 0;\n" );
					fprintf(mSourceFile, "\t\tif(m%s->Decode(mspByteArray.get(), m%s->getAvpOffsetLen().second, &lBytesDecoded)< 0)\n", list->avpname, list->avpname );
					fprintf(mSourceFile, "\t\t{\n" );
               fprintf(mSourceFile, "\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,\"Error decoding %s\")     ;\n", list->avpname);
					fprintf(mSourceFile, "\t\t\tthrow lTssDiaMsgException;\n" );
					fprintf(mSourceFile, "\t\t}\n" );
					fprintf(mSourceFile, "\t\tm%s->mAvpDecodedFlag = true;\n", list->avpname );
					fprintf(mSourceFile, "\t}\n" );
					fprintf(mSourceFile, "\treturn m%s;", list->avpname);
					fprintf(mSourceFile, "\n}\n\n");
				}
				else
				{
					if(0 == strcmp(list->type, "Enumerated"))
						fprintf(mSourceFile, "%s* %s::get%s(){\n", list->avpname , mMessage.command, list->avpname);
					else
						fprintf(mSourceFile, "%s* %s::get%s(){\n", list->type , mMessage.command, list->avpname);
					fprintf(mSourceFile, "\tif(NULL == m%s) {\n", list->avpname);
					fprintf(mSourceFile, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, \"%s is Null\");\n",list->avpname);
					fprintf(mSourceFile, "\t\tthrow lTssDiaMsgException;\n");
					fprintf(mSourceFile, "\t}\n");
					fprintf(mSourceFile, "\tif(!m%s->mAvpDecodedFlag)\n", list->avpname );
					fprintf(mSourceFile, "\t{\n" );
               
               // 22 May 2019 mspByteArray shared memory check added to avoid seg fault
               fprintf(mSourceFile, "\t\t\tif(mspByteArray.get() == NULL)\n" );
               fprintf(mSourceFile, "\t\t\t{\n" );
               fprintf(mSourceFile, "\t\t\tm%s->mAvpDecodedFlag = true;\n", list->avpname );
               fprintf(mSourceFile, "\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, \"%s is Null\");\n",list->avpname);
               fprintf(mSourceFile, "\t\t\tthrow lTssDiaMsgException;\n");
               fprintf(mSourceFile, "\t\t\t}\n" );
               
               fprintf(mSourceFile, "\t\tmspByteArray.get()->offset = 0;\n" );
					fprintf(mSourceFile, "\t\tmspByteArray.get()->offset = m%s->getAvpOffsetLen().first;\n", list->avpname);
					fprintf(mSourceFile, "\t\tUINT16 lBytesDecoded = 0;\n" );
					fprintf(mSourceFile, "\t\tif(m%s->Decode(mspByteArray.get(), m%s->getAvpOffsetLen().second, &lBytesDecoded)< 0)\n", list->avpname, list->avpname);
					fprintf(mSourceFile, "\t\t{\n" );
               fprintf(mSourceFile, "\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,\"Error decoding %s\")     ;\n", list->avpname);
					fprintf(mSourceFile, "\t\t\tthrow lTssDiaMsgException;\n" );
					fprintf(mSourceFile, "\t\t}\n" );
					fprintf(mSourceFile, "\t\tm%s->mAvpDecodedFlag = true;\n", list->avpname );
					fprintf(mSourceFile, "\t}\n" );
					fprintf(mSourceFile, "\treturn m%s;", list->avpname);
					fprintf(mSourceFile, "\n}\n\n");

				}
			}
			else
			{
				if(0 == strcmp(list->type, "Enumerated"))
				{
					fprintf(mSourceFile, "list<%s*>* %s::get%sList()\n",list->avpname,mMessage.command, list->avpname);
               fprintf(mSourceFile, "{\n");
               fprintf(mSourceFile, "\tif(m%sList == NULL)\n", list->avpname);
               fprintf(mSourceFile, "\t{\n");
               fprintf(mSourceFile, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, \"%s is Null\");\n",list->avpname);
               fprintf(mSourceFile, "\t\tthrow lTssDiaMsgException;\n");
               fprintf(mSourceFile, "\t}\n");
               fprintf(mSourceFile, "\tfor(auto itr :* m%sList)\n", list->avpname);
               fprintf(mSourceFile, "\t{\n");
					fprintf(mSourceFile, "\t\tif(!itr->mAvpDecodedFlag)\n" );
					fprintf(mSourceFile, "\t\t{\n" );
               
               // mspByteArray shared memory check added to avoid seg fault
					fprintf(mSourceFile, "\tif(mspByteArray.get() == NULL)\n" );
					fprintf(mSourceFile, "\t\t{\n" );
					fprintf(mSourceFile, "\titr->mAvpDecodedFlag = true;\n");
               fprintf(mSourceFile, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, \"%s is Null\");\n",list->avpname);
               fprintf(mSourceFile, "\t\tthrow lTssDiaMsgException;\n");
               fprintf(mSourceFile, "\t}\n" );

					fprintf(mSourceFile, "\t\t\titr->mspByteArray.get()->offset = 0;\n" );
					fprintf(mSourceFile, "\t\t\titr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;\n" );
					fprintf(mSourceFile, "\t\t\tUINT16 lBytesDecoded = 0;\n" );
					fprintf(mSourceFile, "\t\t\tif(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)\n");
					fprintf(mSourceFile, "\t\t\t{\n" );
               fprintf(mSourceFile, "\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,\"Error decoding %s\")     ;\n", list->avpname);
					fprintf(mSourceFile, "\t\t\t\tthrow lTssDiaMsgException;\n" );
					fprintf(mSourceFile, "\t\t\t}\n" );
					fprintf(mSourceFile, "\t\t\titr->mAvpDecodedFlag = true;\n");
					fprintf(mSourceFile, "\t\t}\n" );
               fprintf(mSourceFile, "\t}\n");
               fprintf(mSourceFile, "\treturn m%sList;\n", list->avpname);
               fprintf(mSourceFile, "}\n\n");
				}
				else
				{		
					fprintf(mSourceFile, "list<%s*>* %s::get%sList()\n", list->type, mMessage.command, list->avpname);
               fprintf(mSourceFile, "{\n");
               fprintf(mSourceFile, "\tif(m%sList == NULL)\n", list->avpname);
               fprintf(mSourceFile, "\t{\n");
               fprintf(mSourceFile, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, \"%s is Null\");\n",list->avpname);
               fprintf(mSourceFile, "\t\tthrow lTssDiaMsgException;\n");
               fprintf(mSourceFile, "\t}\n");
               fprintf(mSourceFile, "\tfor(auto itr : *m%sList)\n", list->avpname);
               fprintf(mSourceFile, "\t{\n");
					fprintf(mSourceFile, "\t\tif(!itr->mAvpDecodedFlag)\n" );
					fprintf(mSourceFile, "\t\t{\n" );
               
               // mspByteArray shared memory check added to avoid seg fault
					fprintf(mSourceFile, "\t\t\tif(mspByteArray.get() == NULL)\n" );
					fprintf(mSourceFile, "\t\t\t{\n" );
					fprintf(mSourceFile, "\t\t\t\titr->mAvpDecodedFlag = true;\n");
               fprintf(mSourceFile, "\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, \"%s is Null\");\n",list->avpname);
               fprintf(mSourceFile, "\t\t\t\tthrow lTssDiaMsgException;\n");
               fprintf(mSourceFile, "\t\t\t}\n" );

					fprintf(mSourceFile, "\t\t\titr->mspByteArray.get()->offset = 0;\n" );
					fprintf(mSourceFile, "\t\t\titr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;\n" );
					fprintf(mSourceFile, "\t\t\tUINT16 lBytesDecoded = 0;\n" );
					fprintf(mSourceFile, "\t\t\tif(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)\n");
					fprintf(mSourceFile, "\t\t\t{\n" );
               fprintf(mSourceFile, "\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,\"Error decoding %s\")     ;\n", list->avpname);
					fprintf(mSourceFile, "\t\t\t\tthrow lTssDiaMsgException;\n" );
					fprintf(mSourceFile, "\t\t\t}\n" );
					fprintf(mSourceFile, "\t\t\titr->mAvpDecodedFlag = true;\n");
					fprintf(mSourceFile, "\t\t}\n" );
               fprintf(mSourceFile, "\t}\n");
               fprintf(mSourceFile, "\treturn m%sList;\n", list->avpname);
               fprintf(mSourceFile, "}\n\n");
				}
				
				if(0 == strcmp(list->type, "Enumerated"))
				{
					fprintf(mSourceFile, "list<%s*>* %s::set%sList() {\n\tmTagsPresent[%s_%s] = 1;\n\tif(m%sList == NULL)\n\t\tm%sList = new list<%s*>;\n", list->avpname, mMessage.command, list->avpname, mMessage.command,to_upper(list->avpname),  list->avpname, list->avpname, list->avpname);
				}
				else
				{
					fprintf(mSourceFile, "list<%s*>* %s::set%sList() {\n\tmTagsPresent[%s_%s] = 1;\n\tif(m%sList == NULL)\n\t\tm%sList = new list<%s*>;\n", list->type, mMessage.command, list->avpname, mMessage.command,to_upper(list->avpname),  list->avpname, list->avpname, list->type);
				}
				if (((list->avpFlags&0x40)?true:false))
					fprintf(mSourceFile, "\tmMandatoryAvpSetVal [%s_%s] = 1;\n", mMessage.command, to_upper(list->avpname));
				fprintf(mSourceFile, "\tm%sList->clear();\n", list->avpname );
				fprintf(mSourceFile, "\treturn m%sList;\n}\n\n", list->avpname );
            
            // RESET Functionality Added
				fprintf(mSourceFile, "void %s::reset%sList(){\n\tmTagsPresent[%s_%s] = 0;\n\tif(m%sList != NULL)\n\t\tdelete m%sList;\n", 
mMessage.command, list->avpname, mMessage.command,to_upper(list->avpname),list->avpname, list->avpname);
               
               fprintf(mSourceFile, "}\n\n");
			}
		}
		else
		{
			if(1 == list->multiple)
			{
				fprintf(mSourceFile, "list<%s*>* %s::get%sGrpList()\n", list->avpname, mMessage.command, list->avpname); 
            fprintf(mSourceFile, "{\n");
            fprintf(mSourceFile, "\tif(m%sGrpList == NULL)\n", list->avpname);
            fprintf(mSourceFile, "\t{\n");
            fprintf(mSourceFile, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, \"%s is Null\");\n",list->avpname);
            fprintf(mSourceFile, "\t\tthrow lTssDiaMsgException;\n");
            fprintf(mSourceFile, "\t}\n");
            fprintf(mSourceFile, "\tfor(auto itr : *m%sGrpList)\n", list->avpname);
            fprintf(mSourceFile, "\t{\n");
            // 22 May 2019 added for list element check if only set and object is not pushed. resetting the values
            fprintf(mSourceFile, "\t\tif(m%sGrpList != NULL)\n", list->avpname);
            fprintf(mSourceFile, "\t\t{\n");
            fprintf(mSourceFile, "\t\tif(m%sGrpList->size() == 0)\n", list->avpname);
            fprintf(mSourceFile, "\t\t{\n");
				fprintf(mSourceFile, "\t\t\tmTagsPresent[%s_%s] = 0;\n", mMessage.command,to_upper(list->avpname));
            fprintf(mSourceFile, "\t\t\tm%sGrpList = NULL;\n", list->avpname);
            fprintf(mSourceFile, "\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, \"%s is Null\");\n",list->avpname);
            fprintf(mSourceFile, "\t\t\tthrow lTssDiaMsgException;\n");
            fprintf(mSourceFile, "\t\t}\n");
            fprintf(mSourceFile, "\t}\n");

            fprintf(mSourceFile, "\t\tif(!itr->mAvpDecodedFlag)\n" );
            fprintf(mSourceFile, "\t\t{\n" );
            
            // mspByteArray shared memory check added to avoid seg fault
            fprintf(mSourceFile, "\t\t\tif(mspByteArray.get() == NULL)\n" );
            fprintf(mSourceFile, "\t\t\t{\n" );
            fprintf(mSourceFile, "\t\t\titr->mAvpDecodedFlag = true;\n" );
            fprintf(mSourceFile, "\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, \"%s is Null\");\n",list->avpname);
            fprintf(mSourceFile, "\t\t\tthrow lTssDiaMsgException;\n");
            fprintf(mSourceFile, "\t\t\t}\n" );

            fprintf(mSourceFile, "\t\t\titr->mspByteArray.get()->offset = 0;\n" );
            fprintf(mSourceFile, "\t\t\titr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;\n" );
            fprintf(mSourceFile, "\t\t\tUINT16 lBytesDecoded = 0;\n" );
            fprintf(mSourceFile, "\t\t\tif(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)\n");
            fprintf(mSourceFile, "\t\t\t{\n" );
            fprintf(mSourceFile, "\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,\"Error decoding %s\")     ;\n", list->avpname);
            fprintf(mSourceFile, "\t\t\t\tthrow lTssDiaMsgException;\n" );
            fprintf(mSourceFile, "\t\t\t}\n" );
            fprintf(mSourceFile, "\t\t\titr->mAvpDecodedFlag = true;\n");
            fprintf(mSourceFile, "\t\t}\n" );
            fprintf(mSourceFile, "\t}\n");
            fprintf(mSourceFile, "\treturn m%sGrpList;\n", list->avpname);
            fprintf(mSourceFile, "}\n\n");

				fprintf(mSourceFile, "list<%s*>* %s::set%sGrpList(){\n\tmTagsPresent[%s_%s] = 1;\n\tif(m%sGrpList == NULL)\n\t\tm%sGrpList = new list<%s*>;\n", list->avpname, mMessage.command, list->avpname, mMessage.command,to_upper(list->avpname),list->avpname,list->avpname, list->avpname);
				if (((list->avpFlags&0x40)?true:false))
					fprintf(mSourceFile, "\tmMandatoryAvpSetVal[%s_%s] = 1;\n", mMessage.command, to_upper(list->avpname));
				fprintf(mSourceFile, "\tm%sGrpList->clear();\n", list->avpname );
				fprintf(mSourceFile, "\treturn m%sGrpList;\n}\n\n", list->avpname );


            // RESET Functionality Added
				fprintf(mSourceFile, "void %s::reset%sGrpList(){\n\tmTagsPresent[%s_%s] = 0;\n\tif(m%sGrpList != NULL)\n\t\tdelete m%sGrpList;\n", 
mMessage.command, list->avpname, mMessage.command, to_upper(list->avpname),list->avpname, list->avpname);
               
               fprintf(mSourceFile, "}\n\n");

			}
			else 
			{
				fprintf(mSourceFile, "%s* %s::get%s()\n", list->avpname, mMessage.command, list->avpname);
            fprintf(mSourceFile, "{\n");
            fprintf(mSourceFile, "\tif(m%sGrp == NULL)\n", list->avpname);
            fprintf(mSourceFile, "\t{\n");
            fprintf(mSourceFile, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, \"%s is Null\");\n",list->avpname);
            fprintf(mSourceFile, "\t\tthrow lTssDiaMsgException;\n");
            fprintf(mSourceFile, "\t}\n");
            fprintf(mSourceFile, "\tif(!m%sGrp->mAvpDecodedFlag)\n", list->avpname );
            fprintf(mSourceFile, "\t{\n" );

            // 22 May 2019 mspByteArray shared memory check added to avoid seg fault
            fprintf(mSourceFile, "\t\t\tif(mspByteArray.get() == NULL)\n" );
            fprintf(mSourceFile, "\t\t\t{\n" );
            fprintf(mSourceFile, "\t\t\tm%sGrp->mAvpDecodedFlag = true;\n", list->avpname );
            fprintf(mSourceFile, "\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, \"%s is Null\");\n",list->avpname);
            fprintf(mSourceFile, "\t\t\tthrow lTssDiaMsgException;\n");
            fprintf(mSourceFile, "\t\t\t}\n" );

            fprintf(mSourceFile, "\t\tmspByteArray.get()->offset = 0;\n" );
            fprintf(mSourceFile, "\t\tmspByteArray.get()->offset = m%sGrp->getAvpOffsetLen().first;\n", list->avpname);
            fprintf(mSourceFile, "\t\tUINT16 lBytesDecoded = 0;\n" );
            fprintf(mSourceFile, "\t\tif(m%sGrp->Decode(mspByteArray.get(), m%sGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)\n", list->avpname , list->avpname);
            fprintf(mSourceFile, "\t\t{\n" );
            fprintf(mSourceFile, "\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,\"Error decoding %s\")     ;\n", list->avpname);
            fprintf(mSourceFile, "\t\t\tthrow lTssDiaMsgException;\n" );
            fprintf(mSourceFile, "\t\t}\n" );
            fprintf(mSourceFile, "\t\tm%sGrp->mAvpDecodedFlag = true;\n", list->avpname);
            fprintf(mSourceFile, "\t}\n" );
            fprintf(mSourceFile, "\treturn m%sGrp;\n", list->avpname);
            fprintf(mSourceFile, "}\n\n");

				fprintf(mSourceFile, "%s* %s::set%s(){\n\tif(m%sGrp == NULL)\n\t\tm%sGrp = new %s();\n\tmTagsPresent[%s_%s] = 1;\n", list->avpname, mMessage.command, list->avpname, list->avpname, list->avpname, list->avpname, mMessage.command, to_upper(list->avpname));
				if (((list->avpFlags&0x40)?true:false))
					fprintf(mSourceFile, "\tmMandatoryAvpSetVal[%s_%s] = 1;\n", mMessage.command, to_upper(list->avpname));
				fprintf(mSourceFile, "\treturn m%sGrp;\n}\n\n", list->avpname );
            
            // RESET Functionality Added
				fprintf(mSourceFile, "void %s::reset%s(){\n\tmTagsPresent[%s_%s] = 0;\n\tif(m%sGrp != NULL)\n\t\tdelete m%sGrp;\n", 
mMessage.command, list->avpname, mMessage.command,to_upper(list->avpname),list->avpname, list->avpname);
               
               fprintf(mSourceFile, "}\n\n");
			} 
		}
		list++;
	}

	this->generateSourceForEncode();

	this->generateSourceForDecode();

	this->generateSourceForFind();

	this->generateSourceForFindAll();
	
	this->generateSourceForFindAllwithPath();
	
	this->generateSourceForAvpSetGet();

	this->generateSourceForDisplay();

	this->generateSourceForMandatoryAvp();
	
	printf("File-%02d: %s Created\n", count++, mMessage.command);
	
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : generateSourceForDecode
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::generateSourceForDecode()
{
	fprintf(mSourceFile, "\n\n");
	if( mMessage.enumMsgGrpClass == MSG_CLASS) {
		fprintf(mSourceFile, "int %s::Decode(byteArray *array, INT16 lMLen, UINT16 *parsedBytes)\n{\n", mMessage.command );
		fprintf(mSourceFile, "\tif(mDiameterMsgHeader == NULL){\n");
		fprintf(mSourceFile, "\t\tmDiameterMsgHeader = new DiameterMsgHeader();\n");
		fprintf(mSourceFile, "\t\tif(mDiameterMsgHeader == NULL){\n");
		fprintf(mSourceFile, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
		fprintf(mSourceFile, "\t\tthrow lTssDiaMsgException;\n");
		fprintf(mSourceFile, "\t\t}\n");
		fprintf(mSourceFile, "\t}\n");

      fprintf(mSourceFile, "\tmspByteArray = make_shared<byteArray>();\n");
      fprintf(mSourceFile, "\tmemcpy(mspByteArray.get(), array, sizeof(byteArray));\n");
      fprintf(mSourceFile, "\tmAvpDecodedFlag = true;\n");
		fprintf(mSourceFile, "\tarray->offset = 0;\n");
		fprintf(mSourceFile, "\tUINT32  	lMsgLen = 0;\n");
		fprintf(mSourceFile, "\tUINT8   	lCmdFlag= 0;\n");
		fprintf(mSourceFile, "\tmemcpy( &mDiameterMsgHeader->mVersion, &array->byte[0],sizeof(UINT8));\n");
		fprintf(mSourceFile, "\tif( mDiameterMsgHeader->mVersion != 1){\n");
		fprintf(mSourceFile, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_VERSION_ERR, \"Version\");\n");
		fprintf(mSourceFile, "\t\tthrow lTssDiaMsgException;\n");
		fprintf(mSourceFile, "\t}\n\n");

		fprintf(mSourceFile, "\tarray->offset++;\n");

		fprintf(mSourceFile, "\tif(false == DiameterTLVUtil::decodeMessageLength(array, mDiameterMsgHeader->mMsgLen))\n\t{\n");
		fprintf(mSourceFile, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);\n");
		fprintf(mSourceFile, "\t\tthrow lTssDiaMsgException;\n");
		fprintf(mSourceFile, "\t}\n\n");

		fprintf(mSourceFile, "\tmemcpy( &lCmdFlag, &array->byte[array->offset++],sizeof(UINT8));\n");
		fprintf(mSourceFile, "\tthis->setCmdFlag(lCmdFlag)\n;");

		fprintf(mSourceFile, "\tif(false == DiameterTLVUtil::decodeAvpCmdIntegerValue(array, mDiameterMsgHeader->mCmdCode, DIA_CMD_CODE_SIZE))\n\t{\n");
		fprintf(mSourceFile, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);\n");
		fprintf(mSourceFile, "\t\tthrow lTssDiaMsgException;\n");
		fprintf(mSourceFile, "\t}\n\n");
		fprintf(mSourceFile, "\tif(false == DiameterTLVUtil::decodeIntegerValue(array, mDiameterMsgHeader->mApplId, DIA_APPLN_ID_SIZE))\n\t{\n");
		fprintf(mSourceFile, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);\n");
		fprintf(mSourceFile, "\t\tthrow lTssDiaMsgException;\n");
		fprintf(mSourceFile, "\t}\n\n");
		fprintf(mSourceFile, "\tif(false == DiameterTLVUtil::decodeIntegerValue(array, mDiameterMsgHeader->mHopByHopId, DIA_HOP_BY_HOP_ID_SIZE))\n\t{\n");
		fprintf(mSourceFile, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);\n");
		fprintf(mSourceFile, "\t\tthrow lTssDiaMsgException;\n");
		fprintf(mSourceFile, "\t}\n\n");
		fprintf(mSourceFile, "\tif(false == DiameterTLVUtil::decodeIntegerValue(array, mDiameterMsgHeader->mEndToEndId, DIA_END_TO_END_ID_SIZE))\n\t{\n");
		fprintf(mSourceFile, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);\n");
		fprintf(mSourceFile, "\t\tthrow lTssDiaMsgException;\n");
		fprintf(mSourceFile, "\t}\n\n");

		fprintf(mSourceFile,  "\tlMsgLen = (mDiameterMsgHeader->mMsgLen-array->offset);\n");
		fprintf(mSourceFile,  "\tif( mDiameterMsgHeader->mMsgLen != array->size){\n");
		fprintf(mSourceFile,  "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, \"Invalid Msg Len\");\n");
		fprintf(mSourceFile,  "\t\tthrow lTssDiaMsgException;\n");
		fprintf(mSourceFile,  "\t}\n");

	}
	else
	{
		fprintf(mSourceFile, "int %s::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)\n{\n", mMessage.command );
	}
	fprintf(mSourceFile, "\tmDecodeFlag = true;\n");
	if( mMessage.enumMsgGrpClass == MSG_CLASS) {
		vector<avp>::iterator list1 = mAvpArgs.begin();
		while(list1 != mAvpArgs.end()){
			char lHkey[100] = "";
			snprintf( lHkey, 100, "%s_%d", list1->avpname, list1->multiple );
			string lKey = lHkey;

			avp tmpAvp;
			tmpAvp.avpGrp = list1->avpGrp;
			sprintf( tmpAvp.avpname, "%s", list1->avpname);
			sprintf(tmpAvp.type, "%s", list1->type);
			tmpAvp.avpCode  = list1->avpCode;
			tmpAvp.avpFlags = list1->avpFlags;
			tmpAvp.multiple = list1->multiple;

			mDiameterBaseParam.insert( std::pair<string,avp> (lKey,tmpAvp));
			list1++;
		}
	}
	vector<avp>::iterator list = mAvpArgs.begin();
	fprintf(mSourceFile, "\twhile( lMsgLen > 0)\n\t{\n");
	fprintf(mSourceFile, "\t\tUINT32  lAvpCode;\n");
	fprintf(mSourceFile, "\t\tUINT8   lAvpFlag = 0;\n");
	fprintf(mSourceFile, "\t\tUINT32  lAvpLen = 0;\n");
	fprintf(mSourceFile, "\t\tUINT32  lVenderId = 0;\n");
	fprintf(mSourceFile, "\t\tUINT32  lAvpHeaderLen = 8;\n");
	fprintf(mSourceFile, "\t\tUINT32  lAvpDataLen = 0;\n");

	fprintf(mSourceFile, "\t\tif(false == DiameterTLVUtil::decodeIntegerValue(array, lAvpCode, DIA_AVP_CODE_SIZE))\n\t\t{\n");
	fprintf(mSourceFile, "\t\t\tmDecodeFlag = false;\n");
	fprintf(mSourceFile, "\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,\"Error decoding AVP code\");\n");
	fprintf(mSourceFile, "\t\t\tthrow lTssDiaMsgException;\n");
	fprintf(mSourceFile, "\t\t}\n");

	fprintf(mSourceFile, "\t\tmemcpy( &lAvpFlag, &array->byte[array->offset++],sizeof(UINT8));\n");
	fprintf(mSourceFile, "\t\tif(false == DiameterTLVUtil::decodeAvpCmdIntegerValue(array, lAvpLen, DIA_AVP_LEN_SIZE))\n\t\t{\n");
	fprintf(mSourceFile, "\t\t\tmDecodeFlag = false;\n");
	fprintf(mSourceFile, "\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,\"Error decoding AVP length\");\n");
	fprintf(mSourceFile, "\t\t\tthrow lTssDiaMsgException;\n");
	fprintf(mSourceFile, "\t\t}\n");

   fprintf(mSourceFile, "\t\tif(lAvpLen == 0)\n\t\t{\n");
   fprintf(mSourceFile, "\t\t\tmDecodeFlag = false;\n");
   fprintf(mSourceFile, "\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,\"Error decoding AVP length\");\n");
   fprintf(mSourceFile, "\t\t\tthrow lTssDiaMsgException;\n");
   fprintf(mSourceFile, "\t\t}\n");

	fprintf(mSourceFile, "\t\tif( true == DiameterTLVUtil::isVenderSpecific(lAvpFlag))\n\t\t{ \n");
	fprintf(mSourceFile, "\t\t\tlAvpHeaderLen = 12;\n");
	fprintf(mSourceFile, "\t\t\tif(false == DiameterTLVUtil::decodeIntegerValue(array, lVenderId, DIA_VENDER_SPEC_APPLN_ID_SIZE))\n\t\t\t{\n");
	fprintf(mSourceFile, "\t\t\t\tmDecodeFlag = false;\n");
	fprintf(mSourceFile, "\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,\"Error decoding Vendor Id\");\n");
	fprintf(mSourceFile, "\t\t\t\tthrow lTssDiaMsgException;\n");
	fprintf(mSourceFile, "\t\t\t}\n\n");
	fprintf(mSourceFile, "\t\t}\n");

	fprintf(mSourceFile, "\t\tlAvpDataLen = lAvpLen-lAvpHeaderLen;\n");

	fprintf(mSourceFile, "\t\tswitch(lAvpCode)\n\t\t{\n");

	while(list != mAvpArgs.end())
	{
		memset(&mAvp, 0, sizeof(avp));
		snprintf( mAvp.avpname, sizeof(mAvp.avpname), "%s", list->avpname);
		snprintf( mAvp.type, sizeof(mAvp.type), "%s", list->type);
		mAvp.avpCode = list->avpCode;
		mAvp.avpFlags= list->avpFlags;
		fprintf(mSourceFile, "\t\t\tcase %d:\n", list->avpCode);
		fprintf(mSourceFile, "\t\t\t\t{\n");
		if (((list->avpFlags&0x40)?true:false))
			fprintf(mSourceFile, "\t\t\t\t\t\tmMandatoryAvpSetVal [%s_%s] = 1;\n", mMessage.command, to_upper(list->avpname));
		if( list->avpGrp == AVP) {
			if( list->multiple == false) {
				fprintf(mSourceFile, "\t\t\t\t\tif( NULL == this->set%s())\n\t\t\t\t\t{\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\t\tmDecodeFlag = false;\n");
				fprintf(mSourceFile, "\t\t\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,\"Error decoding %s\");\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\t\tthrow lTssDiaMsgException;\n");
				fprintf(mSourceFile, "\t\t\t\t\t}\n");
				fprintf(mSourceFile, "\t\t\t\t\tm%s->setAvpCode(%d);\n", list->avpname, list->avpCode);
				fprintf(mSourceFile, "\t\t\t\t\tm%s->setAvpVendorId(lVenderId);\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\tm%s->SetDataType((DiameterDataType)%d);\n", list->avpname, this->ConvertDiameterTypeToEnum(list->type));
				fprintf(mSourceFile, "\t\t\t\t\tm%s->mspByteArray = mspByteArray;\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\tm%s->mAvpDecodedFlag = false;\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\tm%s->setAvpOffsetLen(array->offset,lAvpDataLen);\n", list->avpname);
            fprintf(mSourceFile, "\t\t\t\t\tarray->offset+=lAvpDataLen;\n\n"); 
			} else {
				fprintf(mSourceFile,"\t\t\t\t\tmTagsPresent[%s_%s] = 1;\n", mMessage.command, to_upper(list->avpname));
				if(0 == strcmp(list->type, "Enumerated"))
					fprintf(mSourceFile, "\t\t\t\t\t%s *l%s = new %s();\n", list->avpname, list->avpname, list->avpname );
				else
					fprintf(mSourceFile, "\t\t\t\t\t%s *l%s = new %s();\n", list->type, list->avpname, list->type );
				fprintf(mSourceFile, "\t\t\t\t\tif( l%s == NULL ){\n", list->avpname );
				fprintf(mSourceFile, "\t\t\t\t\t\tmDecodeFlag = false;\n");
				fprintf(mSourceFile, "\t\t\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,\"Error decoding %s\");\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\t\tthrow lTssDiaMsgException;\n");
				fprintf(mSourceFile, "\t\t\t\t\t}\n");

				fprintf(mSourceFile, "\t\t\t\t\tl%s->setAvpCode(%d);\n", list->avpname, list->avpCode);
				fprintf(mSourceFile, "\t\t\t\t\tl%s->setAvpVendorId(lVenderId);\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\tl%s->SetDataType((DiameterDataType)%d);\n", list->avpname, this->ConvertDiameterTypeToEnum(list->type));
				fprintf(mSourceFile, "\t\t\t\t\tl%s->mspByteArray = mspByteArray;\n",list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\tl%s->mAvpDecodedFlag = false;\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\tl%s->setAvpOffsetLen(array->offset,lAvpDataLen);\n", list->avpname);
            fprintf(mSourceFile, "\t\t\t\t\tarray->offset+=lAvpDataLen;\n\n"); 
				fprintf(mSourceFile, "\t\t\t\t\tif(m%sList == NULL)\n\t\t\t\t\t\tthis->set%sList();\n", list->avpname,list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\tm%sList->push_back(l%s);\n", list->avpname, list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\t\n");
			}
		} else {
			if( list->multiple == true) {
				fprintf(mSourceFile,"\t\t\t\t\tmTagsPresent[%s_%s] = 1;\n", mMessage.command, to_upper(list->avpname));
				fprintf(mSourceFile, "\t\t\t\t\t%s *l%s = new %s();\n", list->avpname, list->avpname, list->avpname );
				
				fprintf(mSourceFile, "\t\t\t\t\tif( l%s == NULL ){\n", list->avpname );
				fprintf(mSourceFile, "\t\t\t\t\tmDecodeFlag = false;\n");
				fprintf(mSourceFile, "\t\t\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,\"Error decoding %s\");\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\t\tthrow lTssDiaMsgException;\n");
				fprintf(mSourceFile, "\t\t\t\t\t}\n");
				fprintf(mSourceFile, "\t\t\t\t\tl%s->setAvpCode(%d);\n", list->avpname, list->avpCode);
				fprintf(mSourceFile, "\t\t\t\t\tl%s->SetDataType((DiameterDataType)%d);\n", list->avpname, this->ConvertDiameterTypeToEnum(list->type));
				fprintf(mSourceFile, "\t\t\t\t\tl%s->mspByteArray = mspByteArray;\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\tl%s->mAvpDecodedFlag = false;\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\tl%s->setAvpOffsetLen(array->offset,lAvpDataLen);\n", list->avpname);
			
            /*    Modified for bug - duplicate entry 26 June 18
				fprintf(mSourceFile, "\t\t\t\t\ttry{\n");
				fprintf(mSourceFile, "\t\t\t\t\t\tl%s->Decode(array, lAvpDataLen);\n",  list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\t} catch( TssDiameterMsgException  tdme) {\n");
				fprintf(mSourceFile, "\t\t\t\t\t\tmDecodeFlag = false;\n");
				fprintf(mSourceFile, "\t\t\t\t\t\tthrow tdme;\n");
				fprintf(mSourceFile, "\t\t\t\t\t}\n");
            */

            fprintf(mSourceFile, "\t\t\t\t\tarray->offset+=lAvpDataLen;\n\n");//added 27 June 18

				fprintf(mSourceFile, "\t\t\t\t\tif(m%sGrpList == NULL)\n\t\t\t\t\t\tthis->set%sGrpList();\n", list->avpname,list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\tm%sGrpList->push_back(l%s);\n", list->avpname, list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\tmBaseInterfaceList.push_back(l%s);\n",  list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\t\n");
			} else {
				fprintf(mSourceFile,"\t\t\t\t\tmTagsPresent[%s_%s] = 1;\n", mMessage.command, to_upper(list->avpname));
				fprintf(mSourceFile,"\t\t\t\t\t\tif( NULL == this->set%s()){\n",  list->avpname );
				fprintf(mSourceFile, "\t\t\t\t\t\tmDecodeFlag = false;\n");
				fprintf(mSourceFile, "\t\t\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,\"Error decoding %s\");\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\t\tthrow lTssDiaMsgException;\n");
				fprintf(mSourceFile,"\t\t\t\t\t\t}\n");
				fprintf(mSourceFile, "\t\t\t\t\tm%sGrp->setAvpCode(%d);\n", list->avpname, list->avpCode);
				fprintf(mSourceFile, "\t\t\t\t\tm%sGrp->SetDataType((DiameterDataType)%d);\n", list->avpname, this->ConvertDiameterTypeToEnum(list->type));
				fprintf(mSourceFile, "\t\t\t\t\tm%sGrp->mspByteArray = mspByteArray;\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\tm%sGrp->mAvpDecodedFlag = false;\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\tm%sGrp->setAvpOffsetLen(array->offset,lAvpDataLen);\n", list->avpname);
			
            /* Modified for bug - duplicate entry 26 June 18
				fprintf(mSourceFile, "\t\t\t\t\ttry{\n");
				fprintf(mSourceFile, "\t\t\t\t\t\tm%sGrp->Decode(array, lAvpDataLen);\n", list->avpname );
				fprintf(mSourceFile, "\t\t\t\t\t} catch( TssDiameterMsgException  tdme) {\n");
				fprintf(mSourceFile, "\t\t\t\t\t\tmDecodeFlag = false;\n");
				fprintf(mSourceFile, "\t\t\t\t\t\tthrow tdme;\n");
				fprintf(mSourceFile, "\t\t\t\t\t}\n");
            */
				fprintf(mSourceFile, "\t\t\t\t\tmBaseInterfaceList.push_back(m%sGrp);\n",  list->avpname);
            fprintf(mSourceFile, "\t\t\t\t\tarray->offset+=lAvpDataLen;\n\n");//added 27 June 18
			}
		}
		fprintf(mSourceFile, "\t\t\t\t}\n");
		fprintf(mSourceFile, "\t\t\t\tbreak;\n");

		list++;
	}
	fprintf(mSourceFile, "\t\t\tdefault:\n");
	fprintf(mSourceFile, "\t\t\t\tarray->offset+=lAvpDataLen;\n");
	fprintf(mSourceFile, "\t\t\t\t//printf(\"Unknown AvpCode received Avp:%%d \\n\", lAvpCode );\n");
	fprintf(mSourceFile, "\t\t\t\t\t//TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);\n");
	fprintf(mSourceFile, "\t\t\t\t\t//throw lTssDiaMsgException;\n");
	fprintf(mSourceFile, "\t\t\t\tbreak;\n");
	fprintf(mSourceFile, "\t\t}\n\n"); //End of switch


	fprintf(mSourceFile, "\t\tif( (lAvpLen %% 4) == 0 )\n\t\t{\n" );
	fprintf(mSourceFile, "\t\t\tlMsgLen = lMsgLen -lAvpLen;\n" );
	fprintf(mSourceFile, "\t\t}\n\t\telse\n\t\t{\n");
	fprintf(mSourceFile, "\t\t\tlMsgLen = lMsgLen -( lAvpLen + ( 4-(lAvpLen%%4)));\n");
	fprintf(mSourceFile, "\t\t\tarray->offset+= ( 4-(lAvpLen%%4));\n");
	fprintf(mSourceFile, "\t\t}\n");
	fprintf(mSourceFile, "\t}\n");

	fprintf(mSourceFile, "\treturn DIAMETER_NO_ERR;\n");
	fprintf(mSourceFile, "}\n");

	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : generateSourceForAvpSetGet
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::generateSourceForAvpSetGet()
{
	fprintf(mSourceFile, "\n\n");

	if( mMessage.enumMsgGrpClass == MSG_CLASS)
	{
		return true;
	}

	fprintf(mSourceFile, "INT32 %s::setAvpCode(UINT32 avpCode)\n{\n", mMessage.command );
	fprintf(mSourceFile, "\tmAvpCode = avpCode;\n");
	fprintf(mSourceFile, "\treturn 0;\n");
	fprintf(mSourceFile, "}\n");
	fprintf(mSourceFile, "UINT32 %s::getAvpCode()\n{\n", mMessage.command );
	fprintf(mSourceFile, "\treturn mAvpCode;\n");
	fprintf(mSourceFile, "}\n");	
	
   fprintf(mSourceFile, "INT32 %s::setAvpVendorId(UINT32 avpVendorId)\n{\n", mMessage.command );
	fprintf(mSourceFile, "\tmAvpVendorId = avpVendorId;\n");
	fprintf(mSourceFile, "\treturn 0;\n");
	fprintf(mSourceFile, "}\n");
	fprintf(mSourceFile, "UINT32 %s::getAvpVendorId()\n{\n", mMessage.command );
	fprintf(mSourceFile, "\treturn mAvpVendorId;\n");
	fprintf(mSourceFile, "}\n");	
	
   fprintf(mSourceFile, "INT32 %s::setAvpOffsetLen(INT16 offset, INT16 length)\n{\n", mMessage.command );
	fprintf(mSourceFile, "\tmAvpOffsetLen = make_pair(offset,length);\n");
	fprintf(mSourceFile, "\treturn 0;\n");
	fprintf(mSourceFile, "}\n");
	fprintf(mSourceFile, "pair<INT16,INT16> %s::getAvpOffsetLen()\n{\n", mMessage.command );
	fprintf(mSourceFile, "\treturn mAvpOffsetLen;\n");
	fprintf(mSourceFile, "}\n");	

	fprintf(mSourceFile, "\n");

	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : ConvertDiameterTypeToEnum
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
DiameterDataType DiameterCreateSource::ConvertDiameterTypeToEnum(TEXT* type)
{
	if(strcmp(type, "Integer32") == 0)
		return INTEGER32_TYPE;				
	else if(strcmp(type, "Integer64") == 0)
		return INTEGER64_TYPE;				
	else if(strcmp(type, "Unsigned32") == 0)
		return UNSIGNED32_TYPE;				
	else if(strcmp(type, "Unsigned64") == 0)
		return UNSIGNED64_TYPE;				
	else if(strcmp(type, "OctetString") == 0)
		return OCTETSTRING_TYPE;				
	else if(strcmp(type, "Enumerated") == 0)
		return ENUMERATED_TYPE;
   else if(strcmp(type, "Time") == 0)				
      return TIME_TYPE;
   else if(strcmp(type, "Address") == 0)
      return ADDRESS_TYPE;
	else
		return GROUPED_TYPE;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : generateSourceFind
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::generateSourceForFind()
{
	fprintf(mSourceFile, "\n\n");
	fprintf(mSourceFile, "DiameterBaseInterface* %s::Find(byteArray *array, UINT32 avpCode)\n{\n", mMessage.command );
	vector<avp>::iterator list = mAvpArgs.begin();

	if( mMessage.enumMsgGrpClass == MSG_CLASS)
	{
		fprintf(mSourceFile, "\t\tif(!mDecodeFlag && array != NULL)\n");
		fprintf(mSourceFile, "\t\t\tthis->Decode(array);\n\n");
	}

        if( mMessage.enumMsgGrpClass == GRP_CLASS)
        {
                fprintf(mSourceFile, "\tif(!this->mAvpDecodedFlag)\n");
                fprintf(mSourceFile, "\t{\n" );
                fprintf(mSourceFile, "\t\tthis->mspByteArray.get()->offset = 0;\n" );
                fprintf(mSourceFile, "\t\tthis->mspByteArray.get()->offset = this->getAvpOffsetLen().first;\n");
                fprintf(mSourceFile, "\t\tUINT16 lBytesDecoded = 0;\n" );
                fprintf(mSourceFile, "\t\tif(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)\n");
                fprintf(mSourceFile, "\t\t{\n" );
                fprintf(mSourceFile, "\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,\"Error decoding %s\")     ;\n", mMessage.command);
                fprintf(mSourceFile, "\t\t\tthrow lTssDiaMsgException;\n" );
                fprintf(mSourceFile, "\t\t}\n" );
                fprintf(mSourceFile, "\t\tthis->mAvpDecodedFlag = true;\n");
                fprintf(mSourceFile, "\t}\n" );
        }

	fprintf(mSourceFile, "\t\tswitch(avpCode)\n\t\t{\n");

	while(list != mAvpArgs.end())
	{
		if( list->avpGrp == AVP) {
			fprintf(mSourceFile, "\t\t\tcase %d:\n", list->avpCode);
			fprintf(mSourceFile, "\t\t\t{\n");
				if( list->multiple == false) 
				{
					fprintf(mSourceFile, "\t\t\t\tif(m%s != NULL)\n", list->avpname );
					fprintf(mSourceFile, "\t\t\t\t\treturn m%s->Find(array, avpCode);\n", list->avpname);
					fprintf(mSourceFile, "\t\t\t\telse\n");
					fprintf(mSourceFile, "\t\t\t\t\treturn NULL;\n");
					fprintf(mSourceFile, "\t\t\t}\n");
				}
				else
				{
					fprintf(mSourceFile, "\t\t\t\tif(m%sList != NULL && m%sList->size() > 0)\n", list->avpname, list->avpname);
					fprintf(mSourceFile, "\t\t\t\t\treturn (m%sList->back())->Find(array, avpCode);\n", list->avpname);
					fprintf(mSourceFile, "\t\t\t\telse\n" );
					fprintf(mSourceFile, "\t\t\t\t\treturn NULL;\n");
					fprintf(mSourceFile, "\t\t\t}\n");
				}
		}
		list++;
	}

	fprintf(mSourceFile, "\t\t\tdefault:\n");
	fprintf(mSourceFile, "\t\t\t{\n");
	fprintf(mSourceFile, "\t\t\t\tfor(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)\n");
	fprintf(mSourceFile, "\t\t\t\t{\n");
	fprintf(mSourceFile, "\t\t\t\t\tDiameterBaseInterface* inf = (*itr)->Find(array, avpCode);\n");
	fprintf(mSourceFile, "\t\t\t\t\tif(inf != NULL)\n");
	fprintf(mSourceFile, "\t\t\t\t\t\treturn inf;\n");
	fprintf(mSourceFile, "\t\t\t\t}\n");
	fprintf(mSourceFile, "\t\t\t\treturn NULL;\n");
	fprintf(mSourceFile, "\t\t\t}\n");
 
	fprintf(mSourceFile, "\t\t}\n");
	fprintf(mSourceFile, "}\n");

	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : generateSourceFindAll
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::generateSourceForFindAll()
{
	fprintf(mSourceFile, "\n\n");
	fprintf(mSourceFile, "BOOLEAN %s::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)\n{\n", mMessage.command );
	vector<avp>::iterator list = mAvpArgs.begin();

	if( mMessage.enumMsgGrpClass == MSG_CLASS)
	{
		fprintf(mSourceFile, "\t\tif(!mDecodeFlag && array != NULL)\n");
		fprintf(mSourceFile, "\t\t\tthis->Decode(array);\n\n");
	}

	if( mMessage.enumMsgGrpClass == GRP_CLASS)
	{
		fprintf(mSourceFile, "\tif(!this->mAvpDecodedFlag)\n");
		fprintf(mSourceFile, "\t{\n" );
		fprintf(mSourceFile, "\t\tthis->mspByteArray.get()->offset = 0;\n" );
		fprintf(mSourceFile, "\t\tthis->mspByteArray.get()->offset = this->getAvpOffsetLen().first;\n");
		fprintf(mSourceFile, "\t\tUINT16 lBytesDecoded = 0;\n" );
		fprintf(mSourceFile, "\t\tif(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)\n");
		fprintf(mSourceFile, "\t\t{\n" );
		fprintf(mSourceFile, "\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,\"Error decoding %s\")     ;\n", mMessage.command);
		fprintf(mSourceFile, "\t\t\tthrow lTssDiaMsgException;\n" );
		fprintf(mSourceFile, "\t\t}\n" );
		fprintf(mSourceFile, "\t\tthis->mAvpDecodedFlag = true;\n");
		fprintf(mSourceFile, "\t}\n" );
	}

	fprintf(mSourceFile, "\t\tswitch(avpCode)\n\t\t{\n");
	while(list != mAvpArgs.end())
	{
		if( list->avpGrp == AVP) {
			fprintf(mSourceFile, "\t\t\tcase %d:\n", list->avpCode);
			fprintf(mSourceFile, "\t\t\t{\n");
				if( list->multiple == false) 
				{
					fprintf(mSourceFile, "\t\t\t\tif(m%s != NULL)\n", list->avpname);
					fprintf(mSourceFile, "\t\t\t\t{\n");
					fprintf(mSourceFile, "\t\t\t\t\tDiameterBaseInterface* inf =  m%s->Find(this->mspByteArray.get(), avpCode);\n", list->avpname);
					fprintf(mSourceFile, "\t\t\t\t\tif(inf != NULL)\n");
					fprintf(mSourceFile, "\t\t\t\t\t{\n");
					fprintf(mSourceFile, "\t\t\t\t\t\tpBaseInterface.push_back(inf);\n");
					fprintf(mSourceFile, "\t\t\t\t\t}\n");
					fprintf(mSourceFile, "\t\t\t\t}\n\n");
					fprintf(mSourceFile, "\t\t\t\tif(deepInspect)\n");
					fprintf(mSourceFile, "\t\t\t\t{\n");
               fprintf(mSourceFile, "\t\t\t\t\tfor(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)\n");
               fprintf(mSourceFile, "\t\t\t\t\t{\n");
               fprintf(mSourceFile, "\t\t\t\t\t\t(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);\n");
               fprintf(mSourceFile, "\t\t\t\t\t}\n");
					fprintf(mSourceFile, "\t\t\t\t}\n");
					fprintf(mSourceFile, "\t\t\t\tbreak;\n");
					fprintf(mSourceFile, "\t\t\t}\n");
				}
				else
				{
               fprintf(mSourceFile, "\t\t\t\tif(m%sList != NULL)\n", list->avpname);
               fprintf(mSourceFile, "\t\t\t\t{\n");
					fprintf(mSourceFile, "\t\t\t\t\tfor(auto itr = m%sList->begin(); itr != m%sList->end(); ++itr)\n", list->avpname, list->avpname);
					fprintf(mSourceFile, "\t\t\t\t\t{\n");
					fprintf(mSourceFile, "\t\t\t\t\t\tDiameterBaseInterface* inf =  (*itr)->Find(this->mspByteArray.get(), avpCode);\n");
					fprintf(mSourceFile, "\t\t\t\t\t\tif(inf != NULL)\n");
					fprintf(mSourceFile, "\t\t\t\t\t\t{\n");
					fprintf(mSourceFile, "\t\t\t\t\t\t\tpBaseInterface.push_back(inf);\n");
					fprintf(mSourceFile, "\t\t\t\t\t\t}\n");
					fprintf(mSourceFile, "\t\t\t\t\t}\n\n");
					fprintf(mSourceFile, "\t\t\t\t\tif(deepInspect)\n");
					fprintf(mSourceFile, "\t\t\t\t\t{\n");
               fprintf(mSourceFile, "\t\t\t\t\t\tfor(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)\n");
               fprintf(mSourceFile, "\t\t\t\t\t\t{\n");
               fprintf(mSourceFile, "\t\t\t\t\t\t\t(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);\n");
               fprintf(mSourceFile, "\t\t\t\t\t\t}\n");
					fprintf(mSourceFile, "\t\t\t\t\t}\n");
               fprintf(mSourceFile, "\t\t\t\t}\n");
					fprintf(mSourceFile, "\t\t\t\tbreak;\n");
					fprintf(mSourceFile, "\t\t\t}\n");
				}
		}
      else
      {
         fprintf(mSourceFile, "\t\t\tcase %d:\n", list->avpCode);
         fprintf(mSourceFile, "\t\t\t{\n");
         if( list->multiple == false)
         {
            fprintf(mSourceFile, "\t\t\t\tif(m%sGrp != NULL)\n", list->avpname);
            fprintf(mSourceFile, "\t\t\t\t{\n");
            fprintf(mSourceFile, "\t\t\t\t\t\tpBaseInterface.push_back(m%sGrp);\n", list->avpname); 
            fprintf(mSourceFile, "\t\t\t\t}\n");
            fprintf(mSourceFile, "\t\t\t\tif(deepInspect)\n");
            fprintf(mSourceFile, "\t\t\t\t{\n");
            fprintf(mSourceFile, "\t\t\t\t\tfor(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)\n");
            fprintf(mSourceFile, "\t\t\t\t\t{\n");
            fprintf(mSourceFile, "\t\t\t\t\t\t(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);\n");
            fprintf(mSourceFile, "\t\t\t\t\t}\n");
            fprintf(mSourceFile, "\t\t\t\t}\n");

            fprintf(mSourceFile, "\t\t\t\tbreak;\n"); 
         }
         else
         {
            fprintf(mSourceFile, "\t\t\t\tif(m%sGrpList != NULL)\n", list->avpname);
            fprintf(mSourceFile, "\t\t\t\t{\n");
            fprintf(mSourceFile, "\t\t\t\t\tfor(auto itr = m%sGrpList->begin(); itr != m%sGrpList->end(); ++itr)\n", list->avpname, list->avpname);
            fprintf(mSourceFile, "\t\t\t\t\t{\n");
            fprintf(mSourceFile, "\t\t\t\t\t\tpBaseInterface.push_back(*itr);\n");
            fprintf(mSourceFile, "\t\t\t\t\t}\n\n");
            fprintf(mSourceFile, "\t\t\t\t\tif(deepInspect)\n");
            fprintf(mSourceFile, "\t\t\t\t\t{\n");
            fprintf(mSourceFile, "\t\t\t\t\t\tfor(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)\n");
            fprintf(mSourceFile, "\t\t\t\t\t\t{\n");
            fprintf(mSourceFile, "\t\t\t\t\t\t\t(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);\n");
            fprintf(mSourceFile, "\t\t\t\t\t\t}\n");
            fprintf(mSourceFile, "\t\t\t\t\t}\n");
            fprintf(mSourceFile, "\t\t\t\t}\n");
            fprintf(mSourceFile, "\t\t\t\tbreak;\n");
         } 
         fprintf(mSourceFile, "\t\t\t}\n");
      }
		list++;
	}

	fprintf(mSourceFile, "\t\t\tdefault:\n");
	fprintf(mSourceFile, "\t\t\t{\n");
   fprintf(mSourceFile, "\t\t\t\tif(!deepInspect)\n");
   fprintf(mSourceFile, "\t\t\t\t\tbreak;\n");
	fprintf(mSourceFile, "\t\t\t\tfor(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)\n");
	fprintf(mSourceFile, "\t\t\t\t{\n");
	fprintf(mSourceFile, "\t\t\t\t\t(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);\n");
	fprintf(mSourceFile, "\t\t\t\t}\n");
	fprintf(mSourceFile, "\t\t\t}\n");
 
	fprintf(mSourceFile, "\t\t}\n");
   fprintf(mSourceFile, "\t\tif(pBaseInterface.size() > 0)\n");
   fprintf(mSourceFile, "\t\t\treturn true;\n");
   fprintf(mSourceFile, "\t\telse\n" );
   fprintf(mSourceFile, "\t\t\treturn false;\n");
	fprintf(mSourceFile, "}\n");


   // 28 May Get Byte Array source added
	//fprintf(mSourceFile, "void %s::GetByteArray(byteArray *array, INT16 len)\n{\n", mMessage.command );
   fprintf(mSourceFile, "std::shared_ptr<byteArray> %s::GetByteArray()\n{\n", mMessage.command );
   //fprintf(mSourceFile, "\tmemcpy(array, mspByteArray.get(), sizeof(byteArray));\n");
   fprintf(mSourceFile, "\treturn mspByteArray;\n");
	fprintf(mSourceFile, "}\n");

	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : generateSourceForEncode
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::generateSourceForEncode()
{
	fprintf(mSourceFile, "\n\n");
	fprintf(mSourceFile, "int %s::Encode(byteArray *array)\n{\n", mMessage.command );

		fprintf(mSourceFile, "\tINT32 lTempHtonlVar = 0;\n");

	if( mMessage.enumMsgGrpClass == MSG_CLASS) {
		fprintf(mSourceFile, "\tunsigned lLengthOffset = 0;\n");
		fprintf(mSourceFile, "\tarray->size=0;\n\tarray->offset = 0;\n");
		fprintf(mSourceFile, "\tmemset(array, 0, sizeof(byteArray));\n");

		fprintf(mSourceFile, "\tmemcpy(&array->byte[ array->offset++], &mDiameterMsgHeader->mVersion, sizeof(UINT8));\n");
		fprintf(mSourceFile, "\tlLengthOffset = array->offset;\n");
		fprintf(mSourceFile, "\tarray->offset +=3;\n");
		fprintf(mSourceFile, "\tUINT8   lCmdFlg = this->getCmdFlag();\n");
		fprintf(mSourceFile, "\tmemcpy(&array->byte[ array->offset++], &lCmdFlg, sizeof(UINT8));\n");

		fprintf(mSourceFile, "\tarray->byte[array->offset++] = (%d>>16) & 0xFF;\n", mMessage.commandCode);
		fprintf(mSourceFile, "\tarray->byte[array->offset++] = (%d>>8) & 0xFF;\n", mMessage.commandCode);
		fprintf(mSourceFile, "\tarray->byte[array->offset++] = (%d) & 0xFF;\n", mMessage.commandCode);

		fprintf(mSourceFile, "\tlTempHtonlVar =  htonl(mDiameterMsgHeader->mApplId);\n");
		fprintf(mSourceFile, "\tmemcpy(array->byte+array->offset, &lTempHtonlVar, DIA_APPLN_ID_SIZE);\n");
		fprintf(mSourceFile, "\tarray->offset += DIA_APPLN_ID_SIZE; \n"); 
		
		fprintf(mSourceFile, "\tlTempHtonlVar =  htonl(mDiameterMsgHeader->mHopByHopId);\n");
		fprintf(mSourceFile, "\tmemcpy(array->byte+array->offset, &lTempHtonlVar, DIA_HOP_BY_HOP_ID_SIZE);\n");
		fprintf(mSourceFile, "\tarray->offset += DIA_HOP_BY_HOP_ID_SIZE; \n"); 

		fprintf(mSourceFile, "\tlTempHtonlVar =  htonl(mDiameterMsgHeader->mEndToEndId);\n");
		fprintf(mSourceFile, "\tmemcpy(array->byte+array->offset, &lTempHtonlVar, DIA_END_TO_END_ID_SIZE);\n");
		fprintf(mSourceFile, "\tarray->offset += DIA_END_TO_END_ID_SIZE;\n"); 
		
		fprintf(mSourceFile, "\tarray->size = array->offset;\n");
	}

	fprintf(mSourceFile, "\n\tfor(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )\n\t{\n");
   fprintf(mSourceFile, "\n\t\tif(!mTagsPresent[i])\n\t\t\tcontinue;\n");
	fprintf(mSourceFile, "\t\tunsigned lengthOffset = 0;\n");

	fprintf(mSourceFile, "\t\tswitch(i)\n\t\t{\n");

	vector<avp>::iterator list = mAvpArgs.begin();

	while(list != mAvpArgs.end())
	{
		memset(&mAvp, 0, sizeof(avp));

		snprintf( mAvp.avpname, sizeof(mAvp.avpname), "%s", list->avpname);
		snprintf( mAvp.type, sizeof(mAvp.type), "%s", list->type);
		mAvp.avpCode = list->avpCode;
		mAvp.avpFlags= list->avpFlags;
		mAvp.vendorid=list->vendorid;

		fprintf(mSourceFile, "\t\t\tcase %s_%s:\n", mMessage.command, to_upper(mAvp.avpname));
		fprintf(mSourceFile, "\t\t\t{\n");


		if( list->avpGrp == AVP){
			if( list->multiple == false) {

				fprintf(mSourceFile, "\t\t\t\t\tarray->size+=4;\n");
				
				fprintf(mSourceFile, "\t\t\t\t\tlTempHtonlVar =  htonl(%d);\n", mAvp.avpCode);
				fprintf(mSourceFile, "\t\t\t\t\tmemcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);\n");
				fprintf(mSourceFile, "\t\t\t\t\tarray->offset += DIA_AVP_CODE_SIZE;\n"); 

				fprintf(mSourceFile, "\t\t\t\t\tarray->size++;\n");
				fprintf(mSourceFile, "\t\t\t\t\tarray->byte[array->offset++] = %d;\n", mAvp.avpFlags);

				fprintf(mSourceFile, "\t\t\t\t\tlengthOffset = array->offset; \n");
				fprintf(mSourceFile, "\t\t\t\t\tarray->offset += 3; \n");
				fprintf(mSourceFile, "\t\t\t\t\tarray->size += 3; \n");

				fprintf(mSourceFile, "\t\t\t\t\tif( true == DiameterTLVUtil::isVenderSpecific(%d))\n\t\t\t\t\t{ \n", mAvp.avpFlags );
				fprintf(mSourceFile, "\t\t\t\t\t\tINT32 venderId=%d;\n", mAvp.vendorid);
				fprintf(mSourceFile, "\t\t\t\t\t\tarray->size+=4;\n");

				fprintf(mSourceFile, "\t\t\t\t\t\tlTempHtonlVar =  htonl(venderId);\n");
				fprintf(mSourceFile, "\t\t\t\t\t\tmemcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);\n");
				fprintf(mSourceFile, "\t\t\t\t\tarray->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;\n"); 
				fprintf(mSourceFile, "\t\t\t\t\t} \n");

				fprintf(mSourceFile, "\t\t\t\t\tif(!m%s->mAvpDecodedFlag)\n", list->avpname );
				fprintf(mSourceFile, "\t\t\t\t\t{\n");
				fprintf(mSourceFile, "\t\t\t\t\t\tmemcpy(array->byte+array->offset, &mspByteArray.get()->byte[m%s->getAvpOffsetLen().first], m%s->getAvpOffsetLen().second);\n", list->avpname, list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\t\tarray->offset += m%s->getAvpOffsetLen().second;\n", list->avpname );
				fprintf(mSourceFile, "\t\t\t\t\t\tarray->size += m%s->getAvpOffsetLen().second;\n", list->avpname );
            if( strcasecmp(mAvp.type, "octetstring") == 0 || strcasecmp(mAvp.type, "Address") == 0 || strcasecmp(mAvp.type, "Time") == 0){
            fprintf(mSourceFile, "\t\t\t\t\t\tUINT8 lPaddingLen = 0;\n");
            fprintf(mSourceFile, "\t\t\t\t\t\tif ( m%s->getAvpOffsetLen().second%4 != 0)\n", list->avpname );
            fprintf(mSourceFile, "\t\t\t\t\t\t{\n");
            fprintf(mSourceFile, "\t\t\t\t\t\t\tlPaddingLen = (4 -(m%s->getAvpOffsetLen().second%4));\n",list->avpname);
            fprintf(mSourceFile, "\t\t\t\t\t\t}\n");
	
	       if(strcasecmp(mAvp.type, "Address") != 0)		
	       {	
               fprintf(mSourceFile, "\t\t\t\t\t\tif(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){\n");
               fprintf(mSourceFile, "\t\t\t\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,\"Error encoding %s\");\n", list->avpname);
               fprintf(mSourceFile, "\t\t\t\t\t\t\tthrow lTssDiaMsgException;\n");
               fprintf(mSourceFile, "\t\t\t\t\t\t}\n");
	       }
          else if(strcasecmp(mAvp.type, "Time") != 0)
          {
               fprintf(mSourceFile, "\t\t\t\t\t\tif(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array,TSS_MAX_DIAMETER_TIME_LEN)){\n");
               fprintf(mSourceFile, "\t\t\t\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,\"Error encoding %s\");\n", list->avpname);
               fprintf(mSourceFile, "\t\t\t\t\t\t\tthrow lTssDiaMsgException;\n");
               fprintf(mSourceFile, "\t\t\t\t\t\t}\n");
          }     
	       else{	
               fprintf(mSourceFile, "\t\t\t\t\t\tif(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array,TSS_MAX_DIAMETER_IPV4_LEN)){\n");
               fprintf(mSourceFile, "\t\t\t\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,\"Error encoding %s\");\n", list->avpname);
               fprintf(mSourceFile, "\t\t\t\t\t\t\tthrow lTssDiaMsgException;\n");
               fprintf(mSourceFile, "\t\t\t\t\t\t}\n");
	       }	
            fprintf(mSourceFile, "\t\t\t\t\t\tarray->offset += lPaddingLen;\n");
            fprintf(mSourceFile, "\t\t\t\t\t\tarray->size += lPaddingLen;\n");
            }
            else
            {
               fprintf(mSourceFile, "\t\t\t\t\t\tif(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){\n");
               fprintf(mSourceFile, "\t\t\t\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,\"Error encoding %s\");\n", list->avpname);
               fprintf(mSourceFile, "\t\t\t\t\t\t\tthrow lTssDiaMsgException;\n");
               fprintf(mSourceFile, "\t\t\t\t\t\t}\n");
            }
				fprintf(mSourceFile, "\t\t\t\t\t\tcontinue;\n");
				fprintf(mSourceFile, "\t\t\t\t\t}\n");


				if( strcasecmp(mAvp.type, "octetstring") == 0 || strcasecmp(mAvp.type, "Address") == 0 || strcasecmp(mAvp.type, "Time") == 0){
					fprintf(mSourceFile, "\t\t\t\t\tif((m%s->Encode(array) < 0) || \n", list->avpname);
					fprintf(mSourceFile, "\t\t\t\t\t\t\t(DiameterTLVUtil::avp_length_encode(lengthOffset, array, m%s->getLength()) == false)){ \n", list->avpname );
					fprintf(mSourceFile, "\t\t\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,\"Error encoding %s\");\n", list->avpname);
					fprintf(mSourceFile, "\t\t\t\t\t\tthrow lTssDiaMsgException;\n");
					fprintf(mSourceFile, "\t\t\t\t\t}\n");
				} else {
					fprintf(mSourceFile, "\t\t\t\t\tif((m%s->Encode(array) < 0) || \n", list->avpname);
					fprintf(mSourceFile, "\t\t\t\t\t\t(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ \n");
					fprintf(mSourceFile, "\t\t\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,\"Error encoding %s\");\n", list->avpname);
					fprintf(mSourceFile, "\t\t\t\t\t\tthrow lTssDiaMsgException;\n");
					fprintf(mSourceFile, "\t\t\t\t\t}\n");
				}
			} else {
				fprintf(mSourceFile, "\t\t\t\t\tif( m%sList->size() <= 0) {\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\t\tbreak;\n");
				fprintf(mSourceFile, "\t\t\t\t\t}\n\n");
				fprintf(mSourceFile, "\t\t\t\t\tm%sIterator = this->get%sList()->begin();\n", list->avpname, list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\twhile(m%sIterator != m%sList->end())\n", list->avpname, list->avpname );
				fprintf(mSourceFile, "\t\t\t\t\t{\n");

				fprintf(mSourceFile, "\t\t\t\t\t\tlengthOffset = 0;\n");

				fprintf(mSourceFile, "\t\t\t\t\t\tarray->size+=4;\n");
				
				fprintf(mSourceFile, "\t\t\t\t\tlTempHtonlVar =  htonl(%d);\n", mAvp.avpCode);
				fprintf(mSourceFile, "\t\t\t\t\tmemcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);\n");
				fprintf(mSourceFile, "\t\t\t\t\tarray->offset += DIA_AVP_CODE_SIZE;\n"); 
				
				fprintf(mSourceFile, "\t\t\t\t\tarray->size++;\n");
				fprintf(mSourceFile, "\t\t\t\t\tarray->byte[array->offset++] = %d;\n", mAvp.avpFlags);

				fprintf(mSourceFile, "\t\t\t\t\tlengthOffset = array->offset; \n");
				fprintf(mSourceFile, "\t\t\t\t\tarray->offset += 3; \n");
				fprintf(mSourceFile, "\t\t\t\t\tarray->size += 3; \n");

				fprintf(mSourceFile, "\t\t\t\t\tif( true == DiameterTLVUtil::isVenderSpecific(%d))\n \t\t\t\t\t{ \n", mAvp.avpFlags );
				fprintf(mSourceFile, "\t\t\t\t\t\tINT32 venderId=%d;\n", mAvp.vendorid);
				fprintf(mSourceFile, "\t\t\t\t\t\tarray->size+=4;\n");
				
				fprintf(mSourceFile, "\t\t\t\t\t\tlTempHtonlVar =  htonl(venderId);\n");
				fprintf(mSourceFile, "\t\t\t\t\t\tmemcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);\n");
				fprintf(mSourceFile, "\t\t\t\t\tarray->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;\n"); 
				fprintf(mSourceFile, "\t\t\t\t\t} \n");

				fprintf(mSourceFile, "\t\t\t\t\tif(!(*m%sIterator)->mAvpDecodedFlag)\n", list->avpname );
				fprintf(mSourceFile, "\t\t\t\t\t{\n");
				fprintf(mSourceFile, "\t\t\t\t\t\tmemcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*m%sIterator)->getAvpOffsetLen().first], (*m%sIterator)->getAvpOffsetLen().second);\n", list->avpname, list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\t\tarray->offset += (*m%sIterator)->getAvpOffsetLen().second;\n", list->avpname );
				fprintf(mSourceFile, "\t\t\t\t\t\tarray->size += (*m%sIterator)->getAvpOffsetLen().second;\n", list->avpname );
            if( strcasecmp(mAvp.type, "octetstring") == 0 || strcasecmp(mAvp.type, "Address") == 0 || strcasecmp(mAvp.type, "Time") == 0){
               fprintf(mSourceFile, "\t\t\t\t\t\tUINT8 lPaddingLen = 0;\n");
               fprintf(mSourceFile, "\t\t\t\t\t\tif ( (*m%sIterator)->getAvpOffsetLen().second%4 != 0)\n", list->avpname );
               fprintf(mSourceFile, "\t\t\t\t\t\t{\n");
               fprintf(mSourceFile, "\t\t\t\t\t\t\tlPaddingLen = (4 -((*m%sIterator)->getAvpOffsetLen().second%4));\n",list->avpname);
               fprintf(mSourceFile, "\t\t\t\t\t\t}\n");

               if(strcasecmp(mAvp.type, "Address") != 0)		
               {	
                  fprintf(mSourceFile, "\t\t\t\t\t\tif(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){\n");
                  fprintf(mSourceFile, "\t\t\t\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,\"Error encoding %s\");\n", list->avpname);
                  fprintf(mSourceFile, "\t\t\t\t\t\t\tthrow lTssDiaMsgException;\n");
                  fprintf(mSourceFile, "\t\t\t\t\t\t}\n");
               }
               else if(strcasecmp(mAvp.type, "Time") != 0)
               {
                  fprintf(mSourceFile, "\t\t\t\t\t\tif(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array,TSS_MAX_DIAMETER_TIME_LEN)){\n");
                  fprintf(mSourceFile, "\t\t\t\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,\"Error encoding %s\");\n", list->avpname);
                  fprintf(mSourceFile, "\t\t\t\t\t\t\tthrow lTssDiaMsgException;\n");
                  fprintf(mSourceFile, "\t\t\t\t\t\t}\n");
               }     
               else{	
                  fprintf(mSourceFile, "\t\t\t\t\t\tif(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array,TSS_MAX_DIAMETER_IPV4_LEN)){\n");
                  fprintf(mSourceFile, "\t\t\t\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,\"Error encoding %s\");\n", list->avpname);
                  fprintf(mSourceFile, "\t\t\t\t\t\t\tthrow lTssDiaMsgException;\n");
                  fprintf(mSourceFile, "\t\t\t\t\t\t}\n");
               }	
               fprintf(mSourceFile, "\t\t\t\t\t\tarray->offset += lPaddingLen;\n");
               fprintf(mSourceFile, "\t\t\t\t\t\tarray->size += lPaddingLen;\n");
            }
            else
            {
               fprintf(mSourceFile, "\t\t\t\t\t\tif(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)\n");
               fprintf(mSourceFile, "\t\t\t\t\t\t{\n");
               fprintf(mSourceFile, "\t\t\t\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,\"Error encoding %s\");\n",list->avpname);
               fprintf(mSourceFile, "\t\t\t\t\t\t\tthrow lTssDiaMsgException;\n");
               fprintf(mSourceFile, "\t\t\t\t\t\t}\n");
            }
            fprintf(mSourceFile, "\t\t\t\t\t\tm%sIterator++;\n", list->avpname);
            fprintf(mSourceFile, "\t\t\t\t\t\tcontinue;\n");
            fprintf(mSourceFile, "\t\t\t\t\t}\n");

            if( strcasecmp(mAvp.type, "octetstring") == 0 || strcasecmp(mAvp.type, "Address") == 0){
               fprintf(mSourceFile, "\t\t\t\t\t\tif(((*m%sIterator)->Encode(array) < 0) || \n", list->avpname);
               fprintf(mSourceFile, "\t\t\t\t\t\t\t(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*m%sIterator)->getLength()) == false)){ \n", list->avpname );
               fprintf(mSourceFile, "\t\t\t\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,\"Error encoding %s\");\n", list->avpname);
               fprintf(mSourceFile, "\t\t\t\t\t\t\tthrow lTssDiaMsgException;\n");
               fprintf(mSourceFile, "\t\t\t\t\t\t}\n");
					fprintf(mSourceFile, "\t\t\t\t\t\tm%sIterator++;\n", list->avpname);
					fprintf(mSourceFile, "\t\t\t\t}\n");
				} 
				else 
				{
					fprintf(mSourceFile, "\t\t\t\t\tif(((*m%sIterator)->Encode(array) < 0) || \n", list->avpname);
					fprintf(mSourceFile, "\t\t\t\t\t\t\t(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ \n");
					fprintf(mSourceFile, "\t\t\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,\"Error encoding %s\");\n", list->avpname);
					fprintf(mSourceFile, "\t\t\t\t\t\tthrow lTssDiaMsgException;\n");
					fprintf(mSourceFile, "\t\t\t\t\t}\n");
					fprintf(mSourceFile, "\t\t\t\t\tm%sIterator++;\n", list->avpname);
					fprintf(mSourceFile, "\t\t\t\t}\n");
				}
			}
		} 
		else 
		{
			if( list->multiple == true) {
				fprintf(mSourceFile, "\t\t\t\tif( m%sGrpList->size() <= 0) {\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\tbreak;\n");
				fprintf(mSourceFile, "\t\t\t\t}\n\n");
				fprintf(mSourceFile, "\t\t\t\tm%sGrpIterator = this->get%sGrpList()->begin();\n", list->avpname, list->avpname);
				fprintf(mSourceFile, "\t\t\t\twhile(m%sGrpIterator != m%sGrpList->end())\n", list->avpname, list->avpname );
				fprintf(mSourceFile, "\t\t\t\t{\n");
				fprintf(mSourceFile, "\t\t\t\t\tlengthOffset = 0;\n");

				fprintf(mSourceFile, "\t\t\t\t\tarray->size+=4;\n");
				
				fprintf(mSourceFile, "\t\t\t\t\tlTempHtonlVar =  htonl(%d);\n", mAvp.avpCode);
				fprintf(mSourceFile, "\t\t\t\t\tmemcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);\n");
				fprintf(mSourceFile, "\t\t\t\t\tarray->offset += DIA_AVP_CODE_SIZE;\n"); 

				fprintf(mSourceFile, "\t\t\t\t\tarray->size++;\n");
				fprintf(mSourceFile, "\t\t\t\t\tarray->byte[array->offset++] = %d;\n", mAvp.avpFlags);

				fprintf(mSourceFile, "\t\t\t\t\tlengthOffset = array->offset; \n");
				fprintf(mSourceFile, "\t\t\t\t\tarray->offset += 3; \n");
				fprintf(mSourceFile, "\t\t\t\t\tarray->size += 3; \n");

				fprintf(mSourceFile, "\t\t\t\t\tif( true == DiameterTLVUtil::isVenderSpecific(%d))\n\t\t\t\t\t\t{ \n", mAvp.avpFlags );
				fprintf(mSourceFile, "\t\t\t\t\t\tINT32 venderId=%d;\n", mAvp.vendorid);
				fprintf(mSourceFile, "\t\t\t\t\t\tarray->size+=4;\n");
				
				fprintf(mSourceFile, "\t\t\t\t\t\tlTempHtonlVar =  htonl(venderId);\n");
				fprintf(mSourceFile, "\t\t\t\t\t\tmemcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);\n");
				fprintf(mSourceFile, "\t\t\t\t\tarray->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;\n"); 
				fprintf(mSourceFile, "\t\t\t\t\t} \n");
				fprintf(mSourceFile, "\t\t\t\t\tif(((*m%sGrpIterator)->Encode(array) < 0) || \n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\t\t\t(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ \n");
				fprintf(mSourceFile, "\t\t\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,\"Error encoding %s\");\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\t\tthrow lTssDiaMsgException;\n");
				fprintf(mSourceFile, "\t\t\t\t\t}\n");
				fprintf(mSourceFile, "\t\t\t\t\t\n");
				fprintf(mSourceFile, "\t\t\t\t\tm%sGrpIterator++;\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t}\n");

			} else { 
				fprintf(mSourceFile, "\t\t\t\tarray->size+=4;\n");
				
				fprintf(mSourceFile, "\t\t\t\t\tlTempHtonlVar =  htonl(%d);\n", mAvp.avpCode);
				fprintf(mSourceFile, "\t\t\t\t\tmemcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);\n");
				fprintf(mSourceFile, "\t\t\t\t\tarray->offset += DIA_AVP_CODE_SIZE;\n"); 
				
				fprintf(mSourceFile, "\t\t\t\tarray->size++;\n");
				fprintf(mSourceFile, "\t\t\t\tarray->byte[array->offset++] = %d;\n", mAvp.avpFlags);

				fprintf(mSourceFile, "\t\t\t\tlengthOffset = array->offset; \n");
				fprintf(mSourceFile, "\t\t\t\tarray->offset += 3; \n");
				fprintf(mSourceFile, "\t\t\t\tarray->size += 3; \n");

				fprintf(mSourceFile, "\t\t\t\tif( true == DiameterTLVUtil::isVenderSpecific(%d))\n \t\t\t\t\t\t{ \n", mAvp.avpFlags );
				fprintf(mSourceFile, "\t\t\t\t\t\tINT32 venderId=%d;\n", mAvp.vendorid);
				fprintf(mSourceFile, "\t\t\t\t\tarray->size+=4;\n");
				
				fprintf(mSourceFile, "\t\t\t\t\tlTempHtonlVar =  htonl(venderId);\n");
				fprintf(mSourceFile, "\t\t\t\t\t\tmemcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);\n");
				fprintf(mSourceFile, "\t\t\t\t\t\tarray->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;\n"); 
				fprintf(mSourceFile, "\t\t\t\t} \n");
				fprintf(mSourceFile, "\t\t\t\tif((this->get%s()->Encode(array) < 0) || \n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\t\t(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {\n");
				fprintf(mSourceFile, "\t\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,\"Error encoding %s\");\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\tthrow lTssDiaMsgException;\n");
				fprintf(mSourceFile, "\t\t\t\t\t}\n");

			}
		}
		fprintf(mSourceFile, "\t\t\t\t}\n");

		fprintf(mSourceFile, "\t\t\t\tbreak;\n");
		list++;
	}

	fprintf(mSourceFile, "\t\t\tdefault:\n");
	fprintf(mSourceFile, "\t\t\t\t//printf(\"Unknown Tag received Tag:%%d Offset:%%d\\n\", mTagArray[lTemp], array->offset);\n");
	fprintf(mSourceFile, "\t\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE);\n");
	fprintf(mSourceFile, "\t\t\t\t\tthrow lTssDiaMsgException;\n");
	fprintf(mSourceFile, "\t\t\t\tbreak;\n");
	fprintf(mSourceFile, "\t\t}\n");

	fprintf(mSourceFile, "\t}\n\n");
	
	if( mMessage.enumMsgGrpClass == MSG_CLASS) {
		fprintf(mSourceFile, "\tif(DiameterTLVUtil::avp_msg_length_encode(lLengthOffset, array) == false){\n");
		fprintf(mSourceFile, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE);\n");
		fprintf(mSourceFile, "\t\tthrow lTssDiaMsgException;\n");
		fprintf(mSourceFile, "\t}\n");
	}
	fprintf(mSourceFile, "\n\treturn DIAMETER_NO_ERR;\n");
	fprintf(mSourceFile, "}\n");

	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : CreateDiameterHeaderFile
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::CreateDiameterHeaderFile(string classname)
{
	FILE *diaHeaderFPtr = NULL;
	FILENAME(classname.c_str(), mSourceFileName, ".h" , "include",mInterfacePath);
	diaHeaderFPtr  = fopen(mSourceFileName, "w");
   string temp(to_upper(mInterface));
	fprintf(diaHeaderFPtr, "#ifndef %s_%s_H\n", temp.c_str(), to_upper(classname.c_str()));
	fprintf(diaHeaderFPtr, "#define %s_%s_H\n\n", temp.c_str(), to_upper(classname.c_str()));
	fprintf(diaHeaderFPtr, "#include \"%s\"\n", "DiameterConstDef.h");
	fprintf(diaHeaderFPtr, "struct diamerterCmdFlag\n");
	fprintf(diaHeaderFPtr, "{\n");
	fprintf(diaHeaderFPtr, "\tUINT8 rBit:1;\n");
	fprintf(diaHeaderFPtr, "\tUINT8 pBit:1;\n");
	fprintf(diaHeaderFPtr, "\tUINT8 eBit:1;\n");
	fprintf(diaHeaderFPtr, "\tUINT8 tBit:1;\n");
	fprintf(diaHeaderFPtr, "\tUINT8 reservedBits:4;\n");
	fprintf(diaHeaderFPtr, "};\n\n\n");

	fprintf(diaHeaderFPtr, "class %s\n{\n", classname.c_str() );
	fprintf(diaHeaderFPtr, "\tpublic:\n");
	fprintf(diaHeaderFPtr, "\t%s():\n\t\tmVersion(1),\n\t\tmMsgLen(0),\n\t\tmCmdCode(0),\n\t\tmApplId(0),\n\t\tmHopByHopId(0),\n\t\tmEndToEndId(0)\n\t{\n", classname.c_str() );
	fprintf(diaHeaderFPtr, "\t\t memset(&mCmdFlg, 0, sizeof(diamerterCmdFlag));\n");
	fprintf(diaHeaderFPtr, "\t}\n\n");
	fprintf(diaHeaderFPtr, "\t~%s()\n\t{\n",  classname.c_str());
	fprintf(diaHeaderFPtr, "\t}\n\n");
	fprintf(diaHeaderFPtr, "\tUINT8  mVersion;\n");
	fprintf(diaHeaderFPtr, "\tUINT32 mMsgLen;\n ");
	fprintf(diaHeaderFPtr, "\tdiamerterCmdFlag mCmdFlg;\n");
	fprintf(diaHeaderFPtr, "\tUINT32 mCmdCode;\n");
	fprintf(diaHeaderFPtr, "\tUINT32 mApplId;\n");
	fprintf(diaHeaderFPtr, "\tUINT32 mHopByHopId;\n");
	fprintf(diaHeaderFPtr, "\tUINT32 mEndToEndId;\n");
	fprintf(diaHeaderFPtr, "};\n\n");
	fprintf(diaHeaderFPtr, "#endif\n" );
	fclose(diaHeaderFPtr);
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : CreateDiameterBaseInterfaceFile
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::CreateDiameterBaseInterfaceFile()
{
   if(strcmp(mInterface,"base") == 0)
	{
		string  classname = "DiameterBaseInterface";
		FILE *diaHeaderFPtr = NULL;
		FILENAME(classname.c_str(), mSourceFileName, ".h" , "include",mInterfacePath);
		diaHeaderFPtr  = fopen(mSourceFileName, "w");
   
		fprintf(diaHeaderFPtr, "#ifndef %s_%s_H\n", to_upper(mInterface),to_upper(classname.c_str()));
		fprintf(diaHeaderFPtr, "#define %s_%s_H\n\n", to_upper(mInterface),to_upper(classname.c_str()));
		fprintf(diaHeaderFPtr, "#include \"%s\"\n", "TssDiameterMsgException.h");

		fprintf(diaHeaderFPtr, "class %s\n{\n", classname.c_str() );
		fprintf(diaHeaderFPtr, "\tpublic:\n");
		fprintf(diaHeaderFPtr, "\tvirtual int\t\t\t\t\t\t\t\tDecode(byteArray *array,  INT16 lMLen, UINT16 *parsedBytes) = 0;\n");
		fprintf(diaHeaderFPtr, "\tvirtual int\t\t\t\t\t\t\t\tEncode(byteArray *array) = 0;\n");
		fprintf(diaHeaderFPtr, "\tvirtual void\t\t\t\t\t\t\tDisplay(UINT32 tab) = 0;\n");
		fprintf(diaHeaderFPtr, "\tvirtual DiameterBaseInterface*\tFind(UINT32 avpCode) = 0;\n");	
		fprintf(diaHeaderFPtr, "};\n");
		fprintf(diaHeaderFPtr, "#endif\n" );
		fclose(diaHeaderFPtr);
		diaHeaderFPtr=NULL;
	}	
}

//-----------------------------------------------------------------------------------------------
// METHOD       : CreateDiameterBaseFile
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::CreateDiameterBaseFile()
{
   if(strcmp(mInterface,"base") == 0)
   {
      string  classname = "DiameterBase";
      FILE *diaHeaderFPtr = NULL;
      FILENAME(classname.c_str(), mSourceFileName, ".h" , "include",mInterfacePath);
      diaHeaderFPtr  = fopen(mSourceFileName, "w");
      fprintf(diaHeaderFPtr, "#ifndef %s\n", to_upper(classname.c_str()));
      fprintf(diaHeaderFPtr, "#define %s\n\n", to_upper(classname.c_str()));
      fprintf(diaHeaderFPtr, "#include \"%s\"\n", "DiameterTLVUtil.h");
      fprintf(diaHeaderFPtr, "#include \"%s\"\n", "DiameterBasicDecEnc.h");
      fprintf(diaHeaderFPtr, "#include \"%s\"\n\n", "DiameterBaseInterface.h");
      fprintf(diaHeaderFPtr, "#include \"%s\"\n", "TssDiameterMsgException.h");
      fprintf(diaHeaderFPtr, "#include \"base/include/%s\"\n\n","DiameterMsgHeader.h");
      std::map<string,avp>::iterator list2  = mDiameterBaseParam.begin();
      for ( list2 =mDiameterBaseParam.begin(); list2 != mDiameterBaseParam.end(); ++list2) 
      {
         if(GRP == list2->second.avpGrp)
         {
            fprintf(diaHeaderFPtr, "#include \"base/include/%s.h\"\n", list2->second.avpname);
         }
         // 16 May 2019 - added for CCRequestType
         if(AVP == list2->second.avpGrp && strcmp(list2->second.type,"Enumerated") == 0 )
         {
            fprintf(mHeaderFile, "#include \"%s/include/%s.h\"\n", mInterface, list2->second.avpname);
         }
      }
      fprintf(diaHeaderFPtr, "#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))\n");
      fprintf(diaHeaderFPtr, "using namespace %s; ", to_upper(mInterface));

      fprintf(diaHeaderFPtr, "\n\n");

      fprintf(diaHeaderFPtr, "class %s : public DiameterBaseInterface\n{\n", classname.c_str() );
      fprintf(diaHeaderFPtr, "\tpublic:\n");
      fprintf(diaHeaderFPtr, "\t %s();\n", classname.c_str() );
      fprintf(diaHeaderFPtr, "\tvirtual ~%s();\n\n",  classname.c_str());
      fprintf(diaHeaderFPtr, "\tDiameterMsgHeader*\t\t\t\tdecodeDiameterMsgHeader (byteArray *array);\n");
      fprintf(diaHeaderFPtr, "\tDiameterMsgHeader*\t\t\t\tgetDiameterMsgHeader();\n");
      fprintf(diaHeaderFPtr, "\tBOOLEAN\t\t\t\t\t\t\t\tsetDiameterMsgHeader( UINT8 mVersion, \n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t UINT8 mCmdFlg, UINT32 mCmdCode, UINT32 mApplId, UINT32 mHopByHopId, UINT32 mEndToEndId);\n");
      fprintf(diaHeaderFPtr, "\n");
      fprintf(diaHeaderFPtr, "\tBOOLEAN\t\t\t\t\t\t\t\tsetVersion(UINT8  mVersion);\n");
      fprintf(diaHeaderFPtr, "\tBOOLEAN\t\t\t\t\t\t\t\tsetCmdFlag(UINT8 mCmdFlg);\n");
      fprintf(diaHeaderFPtr, "\tBOOLEAN\t\t\t\t\t\t\t\tsetCmdCode(UINT32 mCmdCode); \n");
      fprintf(diaHeaderFPtr, "\tBOOLEAN\t\t\t\t\t\t\t\tsetApplnId(UINT32 mApplId);\n");
      fprintf(diaHeaderFPtr, "\tBOOLEAN\t\t\t\t\t\t\t\tsetHopByHopId(UINT32 mHopByHopId);\n");
      fprintf(diaHeaderFPtr, "\tBOOLEAN\t\t\t\t\t\t\t\tsetEndToEndId(UINT32 mEndToEndId);\n");
      fprintf(diaHeaderFPtr, "\tBOOLEAN\t\t\t\t\t\t\t\tsetRequestBit(BOOLEAN rBit);\n");
      fprintf(diaHeaderFPtr, "\tBOOLEAN\t\t\t\t\t\t\t\tsetErrorBit(BOOLEAN eBit);\n");
      fprintf(diaHeaderFPtr, "\tBOOLEAN\t\t\t\t\t\t\t\tsetProxyBit(BOOLEAN pBit);\n");
      fprintf(diaHeaderFPtr, "\tBOOLEAN\t\t\t\t\t\t\t\tsetTransBit(BOOLEAN tBit);\n");
      fprintf(diaHeaderFPtr, "\t\n");
      fprintf(diaHeaderFPtr, "\tUINT8\t\t\t\t\t\t\t\t\tgetVersion();\n");
      fprintf(diaHeaderFPtr, "\tUINT8\t\t\t\t\t\t\t\t\tgetCmdFlag();\n");
      fprintf(diaHeaderFPtr, "\tUINT32\t\t\t\t\t\t\t\tgetCmdCode();\n");
      fprintf(diaHeaderFPtr, "\tUINT32\t\t\t\t\t\t\t\tgetApplnId();\n");
      fprintf(diaHeaderFPtr, "\tUINT32\t\t\t\t\t\t\t\tgetHopByHopId();\n");
      fprintf(diaHeaderFPtr, "\tUINT32\t\t\t\t\t\t\t\tgetEndToEndId();\n");
      fprintf(diaHeaderFPtr, "\tBOOLEAN\t\t\t\t\t\t\t\tgetRequestBit();\n");
      fprintf(diaHeaderFPtr, "\tBOOLEAN\t\t\t\t\t\t\t\tgetErrorBit();\n");
      fprintf(diaHeaderFPtr, "\tBOOLEAN\t\t\t\t\t\t\t\tgetProxyBit();\n");
      fprintf(diaHeaderFPtr, "\tBOOLEAN\t\t\t\t\t\t\t\tgetTransBit();\n");


      fprintf(diaHeaderFPtr, "\tINT32\t\t\t\t\t\t\tDecode(byteArray *array,INT16 lMLen = 0, UINT16 *parsedBytes = NULL);\n");
      fprintf(diaHeaderFPtr, "\tINT32\t\t\t\t\t\t\tEncode(byteArray *array);\n");
      fprintf(diaHeaderFPtr, "\tvoid\t\t\t\t\t\tDisplay(UINT32 tab);\n");
      fprintf(diaHeaderFPtr, "\tDiameterBaseInterface*\t\t\t\t\t\tFind(byteArray *array, UINT32 avpCode);\n");
      fprintf(diaHeaderFPtr, "\tBOOLEAN\t\t\t\t\t\tFindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);\n");
      fprintf(diaHeaderFPtr, "\tBOOLEAN\t\t\t\t\t\tFindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);\n");
      fprintf(diaHeaderFPtr, "\t\n");
      //#if 0
      std::map<string,avp>::iterator list1  = mDiameterBaseParam.begin();
      for ( list1 =mDiameterBaseParam.begin(); list1 != mDiameterBaseParam.end(); ++list1) 
      {
         INT16 code = list1->second.avpCode;
         if(find(CommonFunctions.begin(), CommonFunctions.end(), code) != CommonFunctions.end()){} 
         else	
            continue;	

         if(AVP == list1->second.avpGrp)
         {
            if(0 == list1->second.multiple)
            {
               if(strcmp(list1->second.type, "NULL") == 0)
               {
                  //fprintf(diaHeaderFPtr, "\t\t//! Function to set values as given Object\n\t\t/*!");
                  //fprintf(diaHeaderFPtr, "\t\tFunction to set %s type of argument %s for datatype %s\n", "NULL", list1->second.avpname, mMessage.command);
                  //fprintf(diaHeaderFPtr, "\t\t*/\n");
                  //fprintf(diaHeaderFPtr, "\tvirtual BOOLEAN\t\t\t\tset%s(BOOLEAN %s);\n", list1->second.avpname, list1->second.avpname);
                  //fprintf(diaHeaderFPtr, "\t\t//! Function to set new values\n\t\t/*!");
                  //fprintf(diaHeaderFPtr, "\t\tFunction to set %s type of argument %s for datatype %s\n", "NULL", list1->second.avpname, mMessage.command);
                  //fprintf(diaHeaderFPtr, "\t\t*/\n");
                  fprintf(diaHeaderFPtr, "\tvirtual BOOLEAN*\t\t\t\tset%s();\n", list1->second.avpname);
                  //fprintf(diaHeaderFPtr, "\t\t//! Function to get values\n\t\t/*!");
                  //fprintf(diaHeaderFPtr, "\t\tFunction to get %s type of argument %s for datatype %s\n", "NULL", list1->second.avpname, mMessage.command);
                  //fprintf(diaHeaderFPtr, "\t\tThrows exception of which type and Summary of Exception\n");
                  //fprintf(diaHeaderFPtr, "\t\t*/\n");
                  fprintf(diaHeaderFPtr, "\tvirtual BOOLEAN\t\t\t\tget%s();\n", list1->second.avpname);

                  // RESET functionality added
                  //fprintf(diaHeaderFPtr, "\t\t//! Function to get values\n\t\t/*!");
                  //fprintf(diaHeaderFPtr, "\t\tFunction to get %s type of argument %s for datatype %s\n", "NULL", list1->second.avpname, mMessage.command);
                  //fprintf(diaHeaderFPtr, "\t\tThrows exception of which type and Summary of Exception\n");
                  //fprintf(diaHeaderFPtr, "\t\t*/\n");
                  fprintf(diaHeaderFPtr, "\tvirtual void\t\t\t\treset();\n");
               } // 16 May 2019 - added for CCRequest Type addition in Base file
               else if(strcmp(list1->second.type, "Enumerated") == 0)
               {
                  //fprintf(diaHeaderFPtr, "\t\t//!Function to set values\n\t\t/*!");
                  //fprintf(diaHeaderFPtr, "\t\tFunction to set %s type of argument %s for datatype %s\n", list1->second.type, list1->second.avpname, mMessage.command);
                  //fprintf(diaHeaderFPtr, "\t\t*/\n");
                  //fprintf(diaHeaderFPtr, "\tvirtual BOOLEAN\t\t\t\tset%s(%s* %s);\n", list1->second.avpname, list1->second.type , list1->second.avpname);
                  //fprintf(diaHeaderFPtr, "\t\t//!Function to set values\n\t\t/*!");
                  //fprintf(diaHeaderFPtr, "\t\tFunction to set the recent %s type of argument %s for datatype %s\n", list1->second.type, list1->second.avpname, mMessage.command);
                  //fprintf(diaHeaderFPtr, "\t\t*/\n");
                  fprintf(diaHeaderFPtr, "\tvirtual %s* \t\tset%s();\n", list1->second.avpname , list1->second.avpname);

                  //fprintf(diaHeaderFPtr, "\t\t//!Function to set values\n\t\t/*!");
                  //fprintf(diaHeaderFPtr, "\t\tFunction to get %s type of argument %s for datatype %s\n", list1->second.type, list1->second.avpname, mMessage.command);
                  //fprintf(diaHeaderFPtr, "\t\tThrows exception of which type and Summary of Exception\n");
                  //fprintf(diaHeaderFPtr, "\t\t*/\n");
                  fprintf(diaHeaderFPtr, "\tvirtual %s* \t\tget%s();\n",  list1->second.avpname , list1->second.avpname);

                  // RESET functionality added
                  //fprintf(diaHeaderFPtr, "\t\t//! Function to get values\n\t\t/*!");
                  //fprintf(diaHeaderFPtr, "\t\tFunction to get %s type of argument %s for datatype %s\n", "NULL", list1->second.avpname, mMessage.command);
                  //fprintf(diaHeaderFPtr, "\t\tThrows exception of which type and Summary of Exception\n");
                  //fprintf(diaHeaderFPtr, "\t\t*/\n");
                  fprintf(diaHeaderFPtr, "\tvirtual void \t\treset%s();\n",  list1->second.avpname);
               }
               else
               {
                  //fprintf(diaHeaderFPtr, "\t\t//!Function to set values\n\t\t/*!");
                  //fprintf(diaHeaderFPtr, "\t\tFunction to set %s type of argument %s for datatype %s\n", list1->second.type, list1->second.avpname, mMessage.command);
                  //fprintf(diaHeaderFPtr, "\t\t*/\n");
                  //fprintf(diaHeaderFPtr, "\tvirtual BOOLEAN\t\t\t\tset%s(%s* %s);\n", list1->second.avpname, list1->second.type , list1->second.avpname);
                  //fprintf(diaHeaderFPtr, "\t\t//!Function to set values\n\t\t/*!");
                  //fprintf(diaHeaderFPtr, "\t\tFunction to set the recent %s type of argument %s for datatype %s\n", list1->second.type, list1->second.avpname, mMessage.command);
                  //fprintf(diaHeaderFPtr, "\t\t*/\n");
                  fprintf(diaHeaderFPtr, "\tvirtual %s* \t\tset%s();\n", list1->second.type , list1->second.avpname);

                  //fprintf(diaHeaderFPtr, "\t\t//!Function to set values\n\t\t/*!");
                  //fprintf(diaHeaderFPtr, "\t\tFunction to get %s type of argument %s for datatype %s\n", list1->second.type, list1->second.avpname, mMessage.command);
                  //fprintf(diaHeaderFPtr, "\t\tThrows exception of which type and Summary of Exception\n");
                  //fprintf(diaHeaderFPtr, "\t\t*/\n");
                  fprintf(diaHeaderFPtr, "\tvirtual %s* \t\tget%s();\n",  list1->second.type , list1->second.avpname);

                  // RESET functionality added
                  //fprintf(diaHeaderFPtr, "\t\t//! Function to get values\n\t\t/*!");
                  //fprintf(diaHeaderFPtr, "\t\tFunction to get %s type of argument %s for datatype %s\n", "NULL", list1->second.avpname, mMessage.command);
                  //fprintf(diaHeaderFPtr, "\t\tThrows exception of which type and Summary of Exception\n");
                  //fprintf(diaHeaderFPtr, "\t\t*/\n");
                  fprintf(diaHeaderFPtr, "\tvirtual void \t\treset%s();\n",  list1->second.avpname);
               }
            }
            else 
            {
               fprintf(diaHeaderFPtr, "\tvirtual list<%s*>*\tget%sList();\n", list1->second.type, list1->second.avpname);
               fprintf(diaHeaderFPtr, "\tvirtual list<%s*>*\tset%sList();\n", list1->second.type, list1->second.avpname);
               fprintf(diaHeaderFPtr, "\tvirtual void\treset%sList();\n", list1->second.avpname);
            }
         } else {
            if(1 == list1->second.multiple)
            {
               fprintf(diaHeaderFPtr, "\tvirtual list<%s*>*\tget%sGrpList();\n", list1->second.avpname, list1->second.avpname);
               fprintf(diaHeaderFPtr, "\tvirtual list<%s*>*\tset%sGrpList();\n", list1->second.avpname, list1->second.avpname);
               fprintf(diaHeaderFPtr, "\tvirtual void\treset%sGrpList();\n", list1->second.avpname);
            }
            else 
            {
               fprintf(diaHeaderFPtr, "\tvirtual %s*\tget%s();\n", list1->second.avpname, list1->second.avpname);
               fprintf(diaHeaderFPtr, "\tvirtual %s*\tset%s();\n", list1->second.avpname, list1->second.avpname);
               fprintf(diaHeaderFPtr, "\tvirtual void\treset%s();\n", list1->second.avpname);
            } 
         }
      }
      // 28 May 19 Added Get Byte Array 
      //fprintf(mHeaderFile, "\t\tvoid GetByteArray(byteArray *array, INT16 len);\n");
      fprintf(mHeaderFile, "\t\tvirtual std::shared_ptr<byteArray> GetByteArray( );\n");

      fprintf(diaHeaderFPtr, "\t\n");

      fprintf(diaHeaderFPtr, "\tprotected:\n");
      fprintf(diaHeaderFPtr, "\tDiameterMsgHeader\t\t\t*mDiameterMsgHeader;\n");
      fprintf(diaHeaderFPtr, "};\n\n");
      fprintf(diaHeaderFPtr, "#endif\n" );
      fclose(diaHeaderFPtr);

      diaHeaderFPtr=NULL;

      FILENAME(classname.c_str(), mSourceFileName, ".cc" , "src",mInterfacePath);
      diaHeaderFPtr  = fopen(mSourceFileName, "w");

      fprintf(diaHeaderFPtr, "#include \"%s/include/%s.h\"\n\n", mInterface, classname.c_str() );

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", classname.c_str(), "Constructor", "NONE", "NONE");
      fprintf(diaHeaderFPtr, "%s::%s()\n{\n", classname.c_str(), classname.c_str());
      fprintf(diaHeaderFPtr, "\tmDiameterMsgHeader = new DiameterMsgHeader();\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", classname.c_str(), "DESTRUCTOR", "NONE", "NONE");
      fprintf(diaHeaderFPtr, "%s::~%s()\n{\n", classname.c_str(), classname.c_str());
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader!= NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tdelete mDiameterMsgHeader;\n");
      fprintf(diaHeaderFPtr, "\t\tmDiameterMsgHeader = NULL;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "decodeDiameterMsgHeader", "Decodes diameter message header", "byteArray", "DiameterMsgHeader");
      fprintf(diaHeaderFPtr, "DiameterMsgHeader* %s::decodeDiameterMsgHeader(byteArray *array)\n{\n", classname.c_str());

      fprintf(diaHeaderFPtr, "\tUINT8\t\tlCmdFlag = 0;\n\n");
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tmDiameterMsgHeader = new DiameterMsgHeader();\n\n");
      fprintf(diaHeaderFPtr, "\t\tif(mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);\n");
      fprintf(diaHeaderFPtr, "\t\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t\t}\n");
      fprintf(diaHeaderFPtr, "\t}\n\n");
      fprintf(diaHeaderFPtr, "\tmemcpy( &mDiameterMsgHeader->mVersion, &array->byte[0],sizeof(UINT8));\n");
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader->mVersion != 1)\n\t{\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_VERSION_ERR,\"Version\");\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n\n");
      fprintf(diaHeaderFPtr, "\tarray->offset = 1;\n");
      fprintf(diaHeaderFPtr, "\tif(false == DiameterTLVUtil::decodeMessageLength(array, mDiameterMsgHeader->mMsgLen))\n\t{\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n\n");

      fprintf(diaHeaderFPtr, "\tmemcpy( &lCmdFlag, &array->byte[array->offset++],sizeof(UINT8));\n");
      fprintf(diaHeaderFPtr, "\tthis->setCmdFlag(lCmdFlag);");

      fprintf(diaHeaderFPtr, "\tif(false == DiameterTLVUtil::decodeAvpCmdIntegerValue(array, mDiameterMsgHeader->mCmdCode, DIA_CMD_CODE_SIZE))\n\t{\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n\n");
      fprintf(diaHeaderFPtr, "\tif(false == DiameterTLVUtil::decodeIntegerValue(array, mDiameterMsgHeader->mApplId, DIA_APPLN_ID_SIZE))\n\t{\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n\n");
      fprintf(diaHeaderFPtr, "\tif(false == DiameterTLVUtil::decodeIntegerValue(array, mDiameterMsgHeader->mHopByHopId, DIA_HOP_BY_HOP_ID_SIZE))\n\t{\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n\n");
      fprintf(diaHeaderFPtr, "\tif(false == DiameterTLVUtil::decodeIntegerValue(array, mDiameterMsgHeader->mEndToEndId, DIA_END_TO_END_ID_SIZE))\n\t{\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n\n");

      fprintf(diaHeaderFPtr, "\tarray->offset=0;//reseting the value\n");
      fprintf(diaHeaderFPtr, "\treturn mDiameterMsgHeader;\n");
      fprintf(diaHeaderFPtr, "\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "getDiameterMsgHeader", "Get Diameter message header", "NONE", "DiameterMsgHeader");
      fprintf(diaHeaderFPtr, "DiameterMsgHeader* %s::getDiameterMsgHeader()\n{\n", classname.c_str());
      fprintf(diaHeaderFPtr, "\tif( mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "\treturn mDiameterMsgHeader;\n");
      fprintf(diaHeaderFPtr, "}\n\n");


      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "setDiameterMsgHeader", "Set diameter message header", "UINT8,UINT8,UINT32,UINT32,UINT32,UINT32", "BOOLEAN");
      fprintf(diaHeaderFPtr, "BOOLEAN %s::setDiameterMsgHeader( UINT8 mVersion, UINT8 mCmdFlg, UINT32 mCmdCode,\n\t\t\t\t  UINT32 mApplId, UINT32 mHopByHopId, UINT32 mEndToEndId )\n{\n", classname.c_str());
      fprintf(diaHeaderFPtr, "\tif( mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "\ttry {\n");
      fprintf(diaHeaderFPtr, "\t\tthis->setVersion(mVersion);\n");
      fprintf(diaHeaderFPtr, "\t\tthis->setCmdFlag(mCmdFlg);\n");
      fprintf(diaHeaderFPtr, "\t\tthis->setCmdCode(mCmdCode);\n");
      fprintf(diaHeaderFPtr, "\t\tthis->setApplnId(mApplId);;\n");
      fprintf(diaHeaderFPtr, "\t\tthis->setHopByHopId(mHopByHopId);\n");
      fprintf(diaHeaderFPtr, "\t\tthis->setEndToEndId(mEndToEndId);\n");
      fprintf(diaHeaderFPtr, "\t} catch( TssDiameterMsgException tmde){\n");
      fprintf(diaHeaderFPtr, "\t\tthrow tmde;\n\n");
      fprintf(diaHeaderFPtr, "\t}\n\n");
      fprintf(diaHeaderFPtr, "\treturn true;\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "setVersion", "Set diameter version", "UINT8", "BOOLEAN");
      fprintf(diaHeaderFPtr, "BOOLEAN %s::setVersion(UINT8 mVersion)\n{\n", classname.c_str());
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "\tmDiameterMsgHeader->mVersion = mVersion;\n");
      fprintf(diaHeaderFPtr, "\treturn true;\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "setCmdCode", "Set command code", "UINT32", "BOOLEAN");
      fprintf(diaHeaderFPtr, "BOOLEAN %s::setCmdCode(UINT32 cmdCode)\n{\n", classname.c_str());
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "\tmDiameterMsgHeader->mCmdCode = cmdCode;\n");
      fprintf(diaHeaderFPtr, "\treturn true;\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "setApplnId", "Set application id", "UINT32", "BOOLEAN");
      fprintf(diaHeaderFPtr, "BOOLEAN %s::setApplnId(UINT32 applnId)\n{\n", classname.c_str());
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "\tmDiameterMsgHeader->mApplId = applnId;\n");
      fprintf(diaHeaderFPtr, "\treturn true;\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "setHopByHopId", "set hop by hop id", "UINT32", "BOOLEAN");
      fprintf(diaHeaderFPtr, "BOOLEAN %s::setHopByHopId(UINT32 hopByHopId)\n{\n", classname.c_str());
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "\tmDiameterMsgHeader->mHopByHopId = hopByHopId;\n");
      fprintf(diaHeaderFPtr, "\treturn true;\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "setEndToEndId", "Set end to end id", "UINT32", "BOOLEAN");
      fprintf(diaHeaderFPtr, "BOOLEAN %s::setEndToEndId(UINT32 endToEndId)\n{\n", classname.c_str());
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "\tmDiameterMsgHeader->mEndToEndId = endToEndId;\n");
      fprintf(diaHeaderFPtr, "\treturn true;\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "setCmdFlag", "Set command flags", "UINT8", "BOOLEAN");
      fprintf(diaHeaderFPtr, "BOOLEAN %s::setCmdFlag(UINT8 cmdFlg)\n{\n", classname.c_str());
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "\tmDiameterMsgHeader->mCmdFlg.rBit = (0!=CHECK_BIT(cmdFlg,TSS_DIA_MSG_REQ_BIT_POS))?1:0;\n");
      fprintf(diaHeaderFPtr, "\tmDiameterMsgHeader->mCmdFlg.pBit = (0!=CHECK_BIT(cmdFlg,TSS_DIA_MSG_PXY_BIT_POS))?1:0;\n");
      fprintf(diaHeaderFPtr, "\tmDiameterMsgHeader->mCmdFlg.eBit = (0!=CHECK_BIT(cmdFlg,TSS_DIA_MSG_ERR_BIT_POS))?1:0;\n");
      fprintf(diaHeaderFPtr, "\tmDiameterMsgHeader->mCmdFlg.tBit = (0!=CHECK_BIT(cmdFlg,TSS_DIA_MSG_TRANS_BIT_POS))?1:0;\n");
      fprintf(diaHeaderFPtr, "\treturn true;\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "setRequestBit", "Set request bit", "BOOLEAN", "BOOLEAN");
      fprintf(diaHeaderFPtr, "BOOLEAN %s::setRequestBit(BOOLEAN rBit)\n{\n", classname.c_str());
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "\tmDiameterMsgHeader->mCmdFlg.rBit = rBit;\n");
      fprintf(diaHeaderFPtr, "\treturn true;\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "setErrorBit", "Set Error Bit", "BOOLEAN", "BOOLEAN");
      fprintf(diaHeaderFPtr, "BOOLEAN %s::setErrorBit(BOOLEAN eBit)\n{\n", classname.c_str());
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "\tmDiameterMsgHeader->mCmdFlg.eBit = eBit;\n");
      fprintf(diaHeaderFPtr, "\treturn true;\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "setProxyBit", "set proxy bit", "BOOLEAN", "BOOLEAN");
      fprintf(diaHeaderFPtr, "BOOLEAN\t%s::setProxyBit(BOOLEAN pBit)\n{\n", classname.c_str());
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "\tmDiameterMsgHeader->mCmdFlg.pBit = pBit;\n");
      fprintf(diaHeaderFPtr, "\treturn true;\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "setTransBit", "set transmission bit", "BOOLEAN", "BOOLEAN");
      fprintf(diaHeaderFPtr, "BOOLEAN\t%s::setTransBit(BOOLEAN tBit)\n{\n", classname.c_str());
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "\tmDiameterMsgHeader->mCmdFlg.tBit = tBit ;\n");
      fprintf(diaHeaderFPtr, "\treturn true;\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "getVersion", "Get version", "NONE", "UINT8");
      fprintf(diaHeaderFPtr, "UINT8\t%s::getVersion()\n{\n", classname.c_str());
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "\treturn mDiameterMsgHeader->mVersion;\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "getCmdFlag", "Get command flag", "NONE", "UINT8");
      fprintf(diaHeaderFPtr, "UINT8\t%s::getCmdFlag()\n{\n", classname.c_str());
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "\tUINT8 lCmdFlg=0;\n");
      fprintf(diaHeaderFPtr, "\tlCmdFlg = ( mDiameterMsgHeader->mCmdFlg.rBit << TSS_DIA_MSG_REQ_BIT_POS\n\t\t\t\t| mDiameterMsgHeader->mCmdFlg.pBit << TSS_DIA_MSG_PXY_BIT_POS\n\t\t\t\t| mDiameterMsgHeader->mCmdFlg.eBit << TSS_DIA_MSG_ERR_BIT_POS\n\t\t\t\t| mDiameterMsgHeader->mCmdFlg.tBit << TSS_DIA_MSG_TRANS_BIT_POS);\n");
      fprintf(diaHeaderFPtr, "\treturn lCmdFlg;\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "getCmdCode", "Get command code", "NONE", "UINT32");
      fprintf(diaHeaderFPtr, "UINT32\t%s::getCmdCode()\n{\n", classname.c_str());
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "\treturn mDiameterMsgHeader->mCmdCode;\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "getApplnId", "Get application id", "NONE", "UINT32");
      fprintf(diaHeaderFPtr, "UINT32\t%s::getApplnId()\n{\n", classname.c_str());
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "\treturn mDiameterMsgHeader->mApplId;\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "getHopByHopId", "Get hop by hop id", "NONE", "UINT32");
      fprintf(diaHeaderFPtr, "UINT32\t%s::getHopByHopId()\n{\n", classname.c_str());
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "\treturn mDiameterMsgHeader->mHopByHopId;\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "getEndToEndId", "Get end to end id", "NONE", "UINT32");
      fprintf(diaHeaderFPtr, "UINT32\t%s::getEndToEndId()\n{\n", classname.c_str());
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "\treturn mDiameterMsgHeader->mEndToEndId;\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "getRequestBit", "Get request bit", "NONE", "BOOLEAN");
      fprintf(diaHeaderFPtr, "BOOLEAN\t%s::getRequestBit()\n{\n", classname.c_str());
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "\treturn mDiameterMsgHeader->mCmdFlg.rBit;\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "getErrorBit", "Get error bit", "NONE", "BOOLEAN");
      fprintf(diaHeaderFPtr, "BOOLEAN\t%s::getErrorBit()\n{\n", classname.c_str());
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "\treturn mDiameterMsgHeader->mCmdFlg.eBit;\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "getProxyBit", "Get proxy bit", "NONE", "BOOLEAN");
      fprintf(diaHeaderFPtr, "BOOLEAN\t%s::getProxyBit()\n{\n", classname.c_str());
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "\treturn mDiameterMsgHeader->mCmdFlg.pBit;\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "getTransBit", "Returns transmission bit", "NONE", "BOOLEAN");
      fprintf(diaHeaderFPtr, "BOOLEAN\t%s::getTransBit()\n{\n", classname.c_str());
      fprintf(diaHeaderFPtr, "\tif(mDiameterMsgHeader == NULL){\n");
      fprintf(diaHeaderFPtr, "\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);\n");
      fprintf(diaHeaderFPtr, "\t\tthrow lTssDiaMsgException;\n");
      fprintf(diaHeaderFPtr, "\t}\n");
      fprintf(diaHeaderFPtr, "\treturn mDiameterMsgHeader->mCmdFlg.tBit;\n");
      fprintf(diaHeaderFPtr, "}\n\n");

      //Modified on 6-jan-2017 start

      fprintf(diaHeaderFPtr, "INT32 %s::Decode(byteArray *array,  INT16 lMLen, UINT16 *parsedBytes)\n{\n\treturn -1;\n}\n", classname.c_str());	
      fprintf(diaHeaderFPtr, "INT32 %s::Encode(byteArray *array)\n{\n\treturn -1;\n}\n", classname.c_str());	
      fprintf(diaHeaderFPtr, "void %s::Display(UINT32 tab)\n{\n\treturn;\n}\n", classname.c_str());	
      fprintf(diaHeaderFPtr, "DiameterBaseInterface* %s::Find(byteArray *array, UINT32 avpCode)\n{\n\treturn NULL;\n}\n\n", classname.c_str());	
      fprintf(diaHeaderFPtr, "BOOLEAN %s::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect)\n{\n\treturn false;\n}\n\n", classname.c_str());	
      fprintf(diaHeaderFPtr, "BOOLEAN %s::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect)\n{\n\treturn false;\n}\n\n", classname.c_str());	

      //Modified on 4-jan-2017 stop
      for ( list1 =mDiameterBaseParam.begin(); list1 != mDiameterBaseParam.end(); ++list1) 
      {
         INT16 code = list1->second.avpCode;
         //check if it is a common function
         if(find(CommonFunctions.begin(), CommonFunctions.end(), code) != CommonFunctions.end()){}
         else
            continue;


         if(AVP == list1->second.avpGrp)
         {
            if(0 == list1->second.multiple)
            {
               if(strcmp(list1->second.type, "NULL") == 0)
               {
                  fprintf(diaHeaderFPtr, "BOOLEAN* %s::set%s(){\n\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);\n\tthrow lTssDiaMsgException;\n\treturn true;\n}\n\n", classname.c_str(), list1->second.avpname);
                  fprintf(diaHeaderFPtr, "BOOLEAN %s::get%s(){\n\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);\n\tthrow lTssDiaMsgException;\n\treturn true;\n}\n\n", classname.c_str(), list1->second.avpname);
                  fprintf(diaHeaderFPtr, "void %s::reset%s(){\n\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);\n\tthrow lTssDiaMsgException;\n}\n\n", classname.c_str(), list1->second.avpname);
               }
               else if(strcmp(list1->second.type, "Enumerated") == 0)
               {
                  fprintf(diaHeaderFPtr, "%s* %s::set%s(){\n\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);\n\tthrow lTssDiaMsgException;\n\treturn NULL;\n}\n\n", list1->second.avpname, classname.c_str(), list1->second.avpname );

                  fprintf(diaHeaderFPtr, "%s* %s::get%s(){\n\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);\n\tthrow lTssDiaMsgException;\n\treturn NULL;\n}\n\n",  list1->second.avpname ,classname.c_str(), list1->second.avpname );
                  fprintf(diaHeaderFPtr, "void %s::reset%s(){\n\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);\n\tthrow lTssDiaMsgException;\n}\n\n",  classname.c_str(), list1->second.avpname );
               }
               else
               {
                  fprintf(diaHeaderFPtr, "%s* %s::set%s(){\n\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);\n\tthrow lTssDiaMsgException;\n\treturn NULL;\n}\n\n", list1->second.type, classname.c_str(), list1->second.avpname );

                  fprintf(diaHeaderFPtr, "%s* %s::get%s(){\n\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);\n\tthrow lTssDiaMsgException;\n\treturn NULL;\n}\n\n",  list1->second.type ,classname.c_str(), list1->second.avpname );
                  fprintf(diaHeaderFPtr, "void %s::reset%s(){\n\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);\n\tthrow lTssDiaMsgException;\n}\n\n",  classname.c_str(), list1->second.avpname );
               }
            }
            else {
               fprintf(diaHeaderFPtr, "list<%s*>* %s::get%sList(){\n\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);\n\tthrow lTssDiaMsgException;\n\treturn NULL;\n}\n\n", list1->second.type, classname.c_str(), list1->second.avpname);
               fprintf(diaHeaderFPtr, "list<%s*>* %s::set%sList(){\n\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);\n\tthrow lTssDiaMsgException;\n\treturn NULL;\n}\n\n", list1->second.type, classname.c_str(), list1->second.avpname);
               fprintf(diaHeaderFPtr, "void %s::reset%sList(){\n\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);\n\tthrow lTssDiaMsgException;\n}\n\n", classname.c_str(), list1->second.avpname);
            }
         } else {
            if(1 == list1->second.multiple)
            {
               fprintf(diaHeaderFPtr, "list<%s*>* %s::get%sGrpList(){\n\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);\n\tthrow lTssDiaMsgException;\n\treturn NULL;\n}\n\n", list1->second.avpname, classname.c_str(), list1->second.avpname );
               fprintf(diaHeaderFPtr, "list<%s*>* %s::set%sGrpList(){\n\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);\n\tthrow lTssDiaMsgException;\n\treturn NULL;\n}\n\n", list1->second.avpname, classname.c_str(), list1->second.avpname);
               fprintf(diaHeaderFPtr, "void %s::reset%sGrpList(){\n\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);\n\tthrow lTssDiaMsgException;\n}\n\n", classname.c_str(), list1->second.avpname);
            }
            else 
            {
               fprintf(diaHeaderFPtr, "%s* %s::get%s(){\n\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);\n\tthrow lTssDiaMsgException;\n\t return NULL;\n}\n\n", list1->second.avpname, classname.c_str(), list1->second.avpname);
               fprintf(diaHeaderFPtr, "%s* %s::set%s(){\n\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);\n\tthrow lTssDiaMsgException;\n\treturn NULL;\n}\n\n", list1->second.avpname, classname.c_str(), list1->second.avpname);
               fprintf(diaHeaderFPtr, "void %s::reset%s(){\n\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);\n\tthrow lTssDiaMsgException;\n}\n\n", classname.c_str(), list1->second.avpname);
            } 
         }
      }
               fprintf(diaHeaderFPtr, "std::shared_ptr<byteArray> %s::GetByteArray(){\n\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_BASE_FUNC_CALLED_ERR);\n\tthrow lTssDiaMsgException;\n\treturn NULL; \n}\n\n", classname.c_str());
   }	
   return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : CreateDiameterExceptionClass
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::CreateDiameterExceptionClass()
{
   string classname = "TssDiameterMsgException";
   FILE *diaHeaderFPtr = NULL;

   FILENAME(classname.c_str(), mSourceFileName, ".h" , "include", mInterfacePath);
   diaHeaderFPtr  = fopen(mSourceFileName, "w");

   fprintf(diaHeaderFPtr, "#ifndef %s\n", to_upper(classname.c_str()));
   fprintf(diaHeaderFPtr, "#define %s\n\n", to_upper(classname.c_str()));
   fprintf(diaHeaderFPtr, "#include \"%s\"\n", "DiameterConstDef.h");
   fprintf(diaHeaderFPtr, "#include \"%s\"\n\n", "DiameterTLVUtil.h");

	fprintf(diaHeaderFPtr, "class %s : public exception {\n", classname.c_str() );
	fprintf(diaHeaderFPtr, "\tINT32\t\tmErrCode;\n");
	fprintf(diaHeaderFPtr, "\tTEXT\t\tmName[TSS_MAX_EXCEPTION_NAME_LEN+1];\n");
	fprintf(diaHeaderFPtr, "\tTEXT\t\t*mErrMsg;\n\n");
	fprintf(diaHeaderFPtr, "\tpublic:\n");
	fprintf(diaHeaderFPtr, "\t%s( INT32 ec, TEXT *name=NULL );\n", classname.c_str());

	fprintf(diaHeaderFPtr, "\t~%s() throw();\n", classname.c_str());

	fprintf(diaHeaderFPtr, "\t\n");
	fprintf(diaHeaderFPtr, "\tconst char *\twhat() const throw();\n");
	fprintf(diaHeaderFPtr, "\tconst char *\tgetErrMessage();\n");
	fprintf(diaHeaderFPtr, "\tint \t\t\t\tgetErrorCode();\n");
	fprintf(diaHeaderFPtr, "};\n\n");
	fprintf(diaHeaderFPtr, "#endif\n" );
	fclose(diaHeaderFPtr);

	FILENAME(classname.c_str(), mSourceFileName, ".cc" , "src", mInterfacePath);
	diaHeaderFPtr  = fopen(mSourceFileName, "w");

	fprintf(diaHeaderFPtr, "#include \"%s/include/%s.h\"\n\n\n", mInterface, classname.c_str());
	fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "", "", "", "");
	fprintf(diaHeaderFPtr, "%s::%s( INT32 ec, TEXT *name ):mErrCode(ec) {\n", classname.c_str(), classname.c_str());
	fprintf(diaHeaderFPtr, "\tif (name != NULL) \n");
	fprintf(diaHeaderFPtr, "\t\tsnprintf(mName, TSS_MAX_EXCEPTION_NAME_LEN+1, \"%%s\",name); \n");
	fprintf(diaHeaderFPtr, "\tmErrMsg = NULL;\n");
	fprintf(diaHeaderFPtr, "}\n");

	fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "", "", "", "");
	fprintf(diaHeaderFPtr, "%s::~%s() throw() {\n", classname.c_str(), classname.c_str());
	fprintf(diaHeaderFPtr, "\tif(mErrMsg != NULL) {\n");
	fprintf(diaHeaderFPtr, "\t\tdelete mErrMsg;\n");
	fprintf(diaHeaderFPtr, "\t\tmErrMsg=NULL;\n");
	fprintf(diaHeaderFPtr, "\t}\n");
	fprintf(diaHeaderFPtr, "}\n");

	fprintf(diaHeaderFPtr, "\n");
	fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "", "", "", "");
	fprintf(diaHeaderFPtr, "const char* %s::what() const throw(){\n", classname.c_str());
	fprintf(diaHeaderFPtr, "\treturn \"DiameterMsgException\";\n");
	fprintf(diaHeaderFPtr, "}\n");
	fprintf(diaHeaderFPtr, "\n");
	fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "", "", "", "");
	fprintf(diaHeaderFPtr, "const char* %s::getErrMessage(){\n", classname.c_str());
	fprintf(diaHeaderFPtr, "\tmErrMsg = new TEXT[TSS_MAX_EXCEPTION_STR_LEN];\n");
	fprintf(diaHeaderFPtr, "\t//DiameterTLVUtil::getErrMsg(mErrCode, mName, mErrMsg);\n");
	fprintf(diaHeaderFPtr, "\treturn mName;\n");
	fprintf(diaHeaderFPtr, "}\n");
	fprintf(diaHeaderFPtr, "\n");
	fprintf(diaHeaderFPtr,"//-----------------------------------------------------------------------------------------------\n// METHOD       : %s\n// DESCRIPTION  : %s\n// PARAMETER    : %s\n// RETURN       : %s\n//-----------------------------------------------------------------------------------------------\n", "", "", "", "");
	fprintf(diaHeaderFPtr, "int %s::getErrorCode(){\n", classname.c_str());
	fprintf(diaHeaderFPtr, "\treturn mErrCode;\n");
	fprintf(diaHeaderFPtr, "}\n");
	fprintf(diaHeaderFPtr, "\n");
	fclose(diaHeaderFPtr);
	return true;
}


//-----------------------------------------------------------------------------------------------
// METHOD       : CreateDiameterConstDef
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::CreateDiameterConstDef()
{
	string classname = "DiameterConstDef";
	FILE *diaHeaderFPtr = NULL;
	FILENAME(classname.c_str(), mSourceFileName, ".h" , "include", mInterfacePath);
	diaHeaderFPtr  = fopen(mSourceFileName, "w");

	fprintf(diaHeaderFPtr, "#ifndef INCL_TSS_DIAMETER_CONST_DEF_H\n#define INCL_TSS_DIAMETER_CONST_DEF_H\n#include <cstring>\n#include <cstdio>\n#include <string>\n#include <cstdlib>\n#include <iostream>\n#include <iomanip>\n#include <sstream>\nusing namespace std;\n\n#include <signal.h>\n#include <unistd.h>\n#include <libgen.h>\n#include <sys/types.h>\n#include <sys/wait.h>\n#include <signal.h>\n#include <sys/poll.h>\n#include <openssl/md5.h>\n#include <sys/syscall.h>\n#include <vector>\n#include <algorithm>\n#include <map>\n#include <expat.h>\n#include \"Types.h\"\n#include <sys/stat.h>\n#include <list>\n#include <bits/stdc++.h>\n");

	fprintf(diaHeaderFPtr,"#define DIA_APPLN_ID_SIZE\t\t\t\t\t\t4\n");
	fprintf(diaHeaderFPtr,"#define DIA_HOP_BY_HOP_ID_SIZE\t\t\t\t\t4\n");
	fprintf(diaHeaderFPtr,"#define DIA_END_TO_END_ID_SIZE\t\t\t\t\t4\n");
	fprintf(diaHeaderFPtr,"#define DIA_AVP_CODE_SIZE\t\t\t\t\t\t4\n");
	fprintf(diaHeaderFPtr,"#define DIA_AVPCODE_N_FLAG_SIZE\t\t\t\t\t5\n");
	fprintf(diaHeaderFPtr,"#define DIA_AVP_LEN_SIZE\t\t\t\t\t\t3\n");
	fprintf(diaHeaderFPtr,"#define DIA_CMD_CODE_SIZE\t\t\t\t\t\t3\n");
	fprintf(diaHeaderFPtr,"#define DIA_VERSION_SIZE\t\t\t\t\t\t1\n");
	fprintf(diaHeaderFPtr,"#define DIA_VENDER_SPEC_APPLN_ID_SIZE\t\t4\n");
	fprintf(diaHeaderFPtr,"#define DIA_DEFAULT_VENDER_SPEC_APPLN_ID\t10415\n");
	fprintf(diaHeaderFPtr,"#define DIA_GET_VENDER_SPEC_BIT\t\t\t0x80\n");
	fprintf(diaHeaderFPtr,"#define DIA_GET_MANDATARY_SPEC_BIT\t\t\t0x40\n");
	fprintf(diaHeaderFPtr,"#define DIA_GET_PROTECTED_SPEC_BIT\t\t\t0x20\n");
	fprintf(diaHeaderFPtr,"#define DIA_HEADER_LEN\t\t\t\t\t\t20\n");
	fprintf(diaHeaderFPtr,"#define DIA_CMD_CODE_START_INDEX\t\t\t\t5\n");
	fprintf(diaHeaderFPtr, "#define TSS_DIA_MSG_REQ_BIT_POS\t\t\t7\n");
	fprintf(diaHeaderFPtr, "#define TSS_DIA_MSG_PXY_BIT_POS\t\t\t6\n");
	fprintf(diaHeaderFPtr, "#define TSS_DIA_MSG_ERR_BIT_POS\t\t\t5\n");
	fprintf(diaHeaderFPtr, "#define TSS_DIA_MSG_TRANS_BIT_POS\t\t4\n");
	fprintf(diaHeaderFPtr, "#define TSS_MAX_EXCEPTION_NAME_LEN\t\t50\n");
	fprintf(diaHeaderFPtr, "#define TSS_MAX_EXCEPTION_STR_LEN\t\t300\n");

	fprintf(diaHeaderFPtr, "\n\n" );
	fprintf(diaHeaderFPtr, "#endif\n" );
	fclose(diaHeaderFPtr);
	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : CreateDiameterConstDef
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::CreateDiameterStruct()
{
	string classname = "DiameterStruct";
	FILE *diaHeaderFPtr = NULL;
	FILENAME(classname.c_str(), mSourceFileName, ".h" , "include", mInterfacePath);
	diaHeaderFPtr  = fopen(mSourceFileName, "w");

	fprintf(diaHeaderFPtr,"#ifndef INCL_DIAMETER_STRUCTS_DEF_H\n#define INCL_DIAMETER_STRUCTS_DEF_H\n#include \"DiameterConstDef.h\"\n\n");
	fprintf(diaHeaderFPtr,"enum DiameterMsgErr\n{\n");
	fprintf(diaHeaderFPtr, "\tDIAMETER_NO_ERR,\n" );
	fprintf(diaHeaderFPtr, "\tDIAMETER_ERR_ENCODE,\n" );
	fprintf(diaHeaderFPtr, "\tDIAMETER_VERSION_ERR,\n" );
	fprintf(diaHeaderFPtr, "\tDIAMETER_ERR_DECODE,\n" );
	fprintf(diaHeaderFPtr, "\tDIAMETER_NULL_HEADER_ERR,\n" );
	fprintf(diaHeaderFPtr, "\tDIAMETER_OBJ_NULL,\n" );
	fprintf(diaHeaderFPtr, "\tDIAMETER_BASE_FUNC_CALLED_ERR,\n" );
	fprintf(diaHeaderFPtr, "\tDIAMETER_MANDATORY_PARAM_ERR\n" );
	fprintf(diaHeaderFPtr, "};\n\n" );

	fprintf(diaHeaderFPtr, "\n\n" );
	fprintf(diaHeaderFPtr, "#endif\n" );
	fclose(diaHeaderFPtr);
	return true;
}


//-----------------------------------------------------------------------------------------------
// METHOD       : generateSourceForDisplay
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::generateSourceForDisplay()
{
	fprintf(mSourceFile, "\n\n");
	fprintf(mSourceFile, "void %s::Display(UINT32 tab)\n{\n", mMessage.command );

	if( mMessage.enumMsgGrpClass == MSG_CLASS) {
		fprintf(mSourceFile, "\tcout << setw(tab) << \"\" << \"|\" << setfill('=') << setw(59) << \"|\\n\" << setfill(' '); \n\n");
		fprintf(mSourceFile, "\tcout << setw(tab) << \"\" << \"|\"  << left <<  setw(12) << \"Version\" << \":\" << setw(15) << (int)mDiameterMsgHeader->mVersion << \"|\" << setw(12)  << \"MsgLen\" << \":\" << setw(15) << mDiameterMsgHeader->mMsgLen << \"|\" << \"\\n\"; \n" );
		fprintf(mSourceFile, "\tTEXT lCmdFlg[100];\n");
		fprintf(mSourceFile, "\tsprintf( lCmdFlg, \"%%s %%s %%s %%s\", ((mDiameterMsgHeader->mCmdFlg.rBit==1)?\"Request\":\"Response\"), ((mDiameterMsgHeader->mCmdFlg.pBit==1)?\"Proxiable\":\"\"), ((mDiameterMsgHeader->mCmdFlg.eBit==1)?\"Error\":\"\"),((mDiameterMsgHeader->mCmdFlg.tBit ==1)?\"Retransmitted\":\"\"));\n");

		fprintf(mSourceFile, "\tcout << setw(tab) << \"\" << \"|\"  << left <<  setw(12) << \"CmdFlag\" << \":\" << setw(44) << lCmdFlg << \"|\\n\"; \n");

		fprintf(mSourceFile, "\tcout << setw(tab) << \"\" <<\"|\"  << left <<  setw(12) << \"CmdCode\" << \":\" << setw(15) << mDiameterMsgHeader->mCmdCode << \"|\" << setw(12)  << \"ApplnId\" << \":\" << setw(15) << mDiameterMsgHeader->mApplId << \"|\\n\";\n");

		fprintf(mSourceFile, "\tcout << setw(tab) << \"\" << \"|\"  << left <<  setw(12) << \"HopByHopId\" << \":\" << setw(15) << mDiameterMsgHeader->mHopByHopId << \"|\" << setw(12)  << \"EndToEndId\" << \":\" << setw(15) << mDiameterMsgHeader->mEndToEndId << \"|\\n\";\n");

		fprintf(mSourceFile, "\tcout << setw(tab) << \"\" << \"|\" << right << setfill('=') << setw(59) << \"|\\n\" << setfill(' '); \n\n");
	}

	fprintf(mSourceFile, "\tint tempTab = tab * 3; \n");

	fprintf(mSourceFile, "\n\tfor(int i = 0; i < mTagsPresent.size() ; ++i)\n\t{\n");
   fprintf(mSourceFile, "\n\t\tif(!mTagsPresent[i])\n\t\t\tcontinue;\n");

	fprintf(mSourceFile, "\t\tswitch(i)\n\t\t{\n");

	vector<avp>::iterator list = mAvpArgs.begin();

	while(list != mAvpArgs.end())
	{
		memset(&mAvp, 0, sizeof(avp));

		snprintf( mAvp.avpname, sizeof(mAvp.avpname), "%s", list->avpname);
		snprintf( mAvp.type, sizeof(mAvp.type), "%s", list->type);
		mAvp.avpCode = list->avpCode;
		mAvp.avpFlags= list->avpFlags;
		mAvp.vendorid=list->vendorid;

		fprintf(mSourceFile, "\t\t\tcase %s_%s:\n", mMessage.command, to_upper(mAvp.avpname));
		fprintf(mSourceFile, "\t\t\t{\n");
		if( list->avpGrp == AVP){
			if( list->multiple == false) {
			fprintf(mSourceFile, "\t\t\t\tcout << setw(tempTab) << \"\" << \"|\"  << left <<  setw(12) << \"AvpCode\" << \":\" << setw(15) << \"%d\" << \"|\" << setw(12)  << \"AvpType\" << \":\" << setw(15) << \"SINGLE\" << \"|\" << \"\\n\"; \n", list->avpCode );
			fprintf(mSourceFile, "\t\t\t\tcout << setw(tempTab) << \"\" << \"|\"  << left <<  setw(12) << \"AvpName\" << \":\" << setw(44) << \"%s\" << \"\\n\"; \n", list->avpname );

			fprintf(mSourceFile, "\t\t\t\tTEXT lAvpFlg[100];\n");
			fprintf(mSourceFile, "\t\t\t\t//Hardcoded value.;\n");
			fprintf(mSourceFile, "\t\t\t\tsprintf( lAvpFlg, \"%%s %%s %%s\", ((DiameterTLVUtil::isVenderSpecific(%d)==true)?\"Vendor\":\"\"), ((DiameterTLVUtil::isMandatoryBitSet(%d)==true)?\"Mandatory\":\"\"), ((DiameterTLVUtil::isProtectedBitSet(%d)==true)?\"Protected\":\"\"));\n", list->avpFlags, list->avpFlags, list->avpFlags );
			fprintf(mSourceFile, "\t\t\t\tthis->get%s()->Display(tab+1);\n", list->avpname );
			}
			else {
				fprintf(mSourceFile, "\t\t\t\tif( m%sList->size() <= 0) {\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\tbreak;\n");
				fprintf(mSourceFile, "\t\t\t\t}\n\n");
				fprintf(mSourceFile, "\t\t\t\tm%sIterator = this->get%sList()->begin();\n", list->avpname, list->avpname);
				fprintf(mSourceFile, "\t\t\t\twhile(m%sIterator != this->get%sList()->end()) {\n", list->avpname, list->avpname );

				fprintf(mSourceFile, "\t\t\t\t\tcout << setw(tempTab)  << \"\" << \"|\"  << left <<  setw(12) << \"AvpCode\" << \":\" << setw(15) << \"%d\" << \"|\" << setw(12)  << \"AvpType\" << \":\" << setw(15) << \"SINGLE\" << \"|\" << \"\\n\"; \n", list->avpCode );
				fprintf(mSourceFile, "\t\t\t\t\tcout << setw(tempTab) << \"\" << \"|\"  << left <<  setw(12) << \"AvpName\" << \":\" << setw(44) << \"%s\" << \"\\n\"; \n", list->avpname );

				fprintf(mSourceFile, "\t\t\t\t\tTEXT lAvpFlg[100];\n");
				fprintf(mSourceFile, "\t\t\t\t\t//Hardcoded value.;\n");
				fprintf(mSourceFile, "\t\t\t\t\tsprintf( lAvpFlg, \"%%s %%s %%s\", ((DiameterTLVUtil::isVenderSpecific(%d)==true)?\"Vendor\":\"\"), ((DiameterTLVUtil::isMandatoryBitSet(%d)==true)?\"Mandatory\":\"\"), ((DiameterTLVUtil::isProtectedBitSet(%d)==true)?\"Protected\":\"\"));\n", list->avpFlags, list->avpFlags, list->avpFlags );
				fprintf(mSourceFile, "\t\t\t\t\t(*m%sIterator)->Display(tab+1);\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\tm%sIterator++;\n\n",  list->avpname);
				fprintf(mSourceFile, "\t\t\t\t};\n\n");

			}
		}
		else
		{
			if( list->multiple == true) {
				fprintf(mSourceFile, "\t\t\t\tif( m%sGrpList->size() <= 0) {\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\tbreak;\n");
				fprintf(mSourceFile, "\t\t\t\t}\n\n");
				fprintf(mSourceFile, "\t\t\t\tm%sGrpIterator = this->get%sGrpList()->begin();\n", list->avpname, list->avpname);
				fprintf(mSourceFile, "\t\t\t\twhile(m%sGrpIterator != this->get%sGrpList()->end()) {\n", list->avpname, list->avpname );

				fprintf(mSourceFile, "\t\t\t\t\tcout << setw(tempTab)  << \"\" << \"|\"  << left <<  setw(12) << \"AvpCode\" << \":\" << setw(15) << \"%d\" << \"|\" << setw(12)  << \"AvpType\" << \":\" << setw(15) << \"GROUPED\" << \"|\" << \"\\n\"; \n", list->avpCode );
				fprintf(mSourceFile, "\t\t\t\t\tcout << setw(tempTab) << \"\" << \"|\"  << left <<  setw(12) << \"AvpName\" << \":\" << setw(44) << \"%s\" << \"\\n\"; \n", list->avpname );

				fprintf(mSourceFile, "\t\t\t\t\tTEXT lAvpFlg[100];\n");
				fprintf(mSourceFile, "\t\t\t\t\t//Hardcoded value.;\n");
				fprintf(mSourceFile, "\t\t\t\t\tsprintf( lAvpFlg, \"%%s %%s %%s\", ((DiameterTLVUtil::isVenderSpecific(%d)==true)?\"Vendor\":\"\"), ((DiameterTLVUtil::isMandatoryBitSet(%d)==true)?\"Mandatory\":\"\"), ((DiameterTLVUtil::isProtectedBitSet(%d)==true)?\"Protected\":\"\"));\n", list->avpFlags, list->avpFlags, list->avpFlags );
				fprintf(mSourceFile, "\t\t\t\t\t(*m%sGrpIterator)->Display(tab+1);\n", list->avpname);
				fprintf(mSourceFile, "\t\t\t\t\tm%sGrpIterator++;\n\n",  list->avpname);
				fprintf(mSourceFile, "\t\t\t\t};\n\n");

			} else {
				fprintf(mSourceFile, "\t\t\t\tcout << setw(tempTab) << \"\" << \"|\"  << left <<  setw(12) << \"AvpCode\" << \":\" << setw(15) << \"%d\" << \"|\" << setw(12)  << \"AvpType\" << \":\" << setw(15) << \"GROUPED\" << \"|\" << \"\\n\"; \n", list->avpCode );
				fprintf(mSourceFile, "\t\t\t\tcout << setw(tempTab) << \"\" << \"|\"  << left <<  setw(12) << \"AvpName\" << \":\" << setw(44) << \"%s\" << \"\\n\"; \n", list->avpname );

				fprintf(mSourceFile, "\t\t\t\tTEXT lAvpFlg[100];\n");
				fprintf(mSourceFile, "\t\t\t\t//Hardcoded value.;\n");
				fprintf(mSourceFile, "\t\t\t\tsprintf( lAvpFlg, \"%%s %%s %%s\", ((DiameterTLVUtil::isVenderSpecific(%d)==true)?\"Vendor\":\"\"), ((DiameterTLVUtil::isMandatoryBitSet(%d)==true)?\"Mandatory\":\"\"), ((DiameterTLVUtil::isProtectedBitSet(%d)==true)?\"Protected\":\"\"));\n", list->avpFlags, list->avpFlags, list->avpFlags );
				fprintf(mSourceFile, "\t\t\t\tthis->get%s()->Display(tab+1);\n", list->avpname );
			}
		}
		fprintf(mSourceFile, "\t\t\t}\n");
		fprintf(mSourceFile, "\t\t\t\tbreak;\n");
		list++;
	}

	fprintf(mSourceFile, "\t\t\tdefault:\n");
	fprintf(mSourceFile, "\t\t\t\t//printf(\"Unknown Tag received Tag:%%d Offset:%%d\\n\", mTagArray[lTemp], array->offset);\n");
	fprintf(mSourceFile, "\t\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE);\n");
	fprintf(mSourceFile, "\t\t\t\t\tthrow lTssDiaMsgException;\n");
	fprintf(mSourceFile, "\t\t\t\tbreak;\n");
	fprintf(mSourceFile, "\t\t}\n");

	fprintf(mSourceFile, "\t}\n\n");
	fprintf(mSourceFile, "}\n");

	return true;
}


//-----------------------------------------------------------------------------------------------
// METHOD       : generateSourceForEncode
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::generateSourceForMandatoryAvp()
{
	fprintf(mSourceFile, "\n\n");
	fprintf(mSourceFile, "BOOLEAN %s::GetMissingAvpInfo(TEXT *lMissingAvpInfo)\n{\n", mMessage.command );

	fprintf(mSourceFile, 
				"\tbitset<%ld> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);\n",
				mAvpArgs.size());
	fprintf(mSourceFile, "\tBOOLEAN lFirstRec = true;\n");

	fprintf(mSourceFile, "\n\tfor(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)\n\t{\n");
	fprintf(mSourceFile, "\t\tif(!lMissingAvpTag[i])\n\t\t\tcontinue;\n");
	fprintf(mSourceFile, "\t\tswitch(i)\n\t\t{\n");
	vector<avp>::iterator list = mAvpArgs.begin();
	while(list != mAvpArgs.end())
	{
		memset(&mAvp, 0, sizeof(avp));

		snprintf( mAvp.avpname, sizeof(mAvp.avpname), "%s", list->avpname);
		snprintf( mAvp.type, sizeof(mAvp.type), "%s", list->type);
		mAvp.avpCode = list->avpCode;
		mAvp.avpFlags= list->avpFlags;
		mAvp.vendorid=list->vendorid;

		fprintf(mSourceFile, "\t\t\tcase %s_%s:\n", mMessage.command, to_upper(mAvp.avpname));
		fprintf(mSourceFile, "\t\t\t{\n");
		fprintf(mSourceFile, "\t\t\t\tif(lFirstRec == true)\n");
		fprintf(mSourceFile, "\t\t\t\t{\n");
		fprintf(mSourceFile, "\t\t\t\t\tlFirstRec = false;\n");
		fprintf(mSourceFile, "\t\t\t\t\tsprintf(lMissingAvpInfo, \"Missing Avps List: %d\");\n", mAvp.avpCode);
		fprintf(mSourceFile, "\t\t\t\t}\n");
		fprintf(mSourceFile, "\t\t\t\telse\n");
		fprintf(mSourceFile, "\t\t\t\t\tsprintf(lMissingAvpInfo, \"%%s,%d\", lMissingAvpInfo);\n", mAvp.avpCode );
		fprintf(mSourceFile, "\t\t\t}\n");
		fprintf(mSourceFile, "\t\t\t\tbreak;\n");
		list++;
	}

	fprintf(mSourceFile, "\t\t\tdefault:\n");
	fprintf(mSourceFile, "\t\t\t\tbreak;\n");
	fprintf(mSourceFile, "\t\t}\n");

	fprintf(mSourceFile, "\t}\n\n");
	
	fprintf(mSourceFile, "\n\treturn true;\n");
	fprintf(mSourceFile, "}\n");

	return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : pushEnumList
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::pushEnumList(UINT32 item,string itemName)
{
	printf("pushEnumList :%d\n", item);
	mAvp.enumValuesList.push_back(item);
	return true;	
}

//-----------------------------------------------------------------------------------------------
// METHOD       : GenerateEnums
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::GenerateEnums()
{
	std::map<string, message>::iterator lList = mDictionary.begin();

	enumValues lenumValues;

	while(lList != mDictionary.end())
	{
		mMessage = lList->second;
		mAvpArgs = mMessage.avpArgsList;
		if(mAvpArgs.size() <= 0)
		{
			printf("Datatype with 0 params is %s\n", (lList->first).c_str());
			lList++;
			continue;
		}
		else
		{
			vector<avp>::iterator list = mAvpArgs.begin();
			while(list != mAvpArgs.end())
			{
				if(strcmp(list->type, "Enumerated") != 0)
				{
					list++;
					continue;
				}

				lenumValues = list->enumValuesList;

				memset(mHeaderFileName, 0, sizeof(mHeaderFileName));		
				FILENAME(list->avpname, mHeaderFileName, ".h" , "include",mInterfacePath);	
				FILE *pEnumFPtr = fopen(mHeaderFileName, "w");
				if(NULL != pEnumFPtr)
				{
               string temp(to_upper(mInterface));	
					fprintf(pEnumFPtr, "#ifndef %s_%s_H\n", temp.c_str(), to_upper(list->avpname));
					fprintf(pEnumFPtr, "#define %s_%s_H\n\n", temp.c_str(), to_upper(list->avpname));
					fprintf(pEnumFPtr, "#include \"%s\"\n", "DiameterTLVUtil.h");
					fprintf(pEnumFPtr, "#include \"%s\"\n\n", "DiameterBaseInterface.h");
					fprintf(pEnumFPtr, "#include \"%s\"\n", "DiameterBasicDecEnc.h");
					fprintf(pEnumFPtr, "#include \"%s\"\n", "TssDiameterMsgException.h");
					fprintf(pEnumFPtr, "#include \"base/include/%s\"\n\n", "DiameterMsgHeader.h");
               fprintf(pEnumFPtr, "namespace %s {", to_upper(mInterface));
					fprintf(pEnumFPtr, "class %s:public Integer32\n",list->avpname);
					fprintf(pEnumFPtr, "{\n");
					fprintf(pEnumFPtr, "public:\n");
					fprintf(pEnumFPtr, "\tINT32  setValue(UINT32 val)\n");		
					fprintf(pEnumFPtr, "\t{\n");
					fprintf(pEnumFPtr, "\t\tswitch(val)\n");
					fprintf(pEnumFPtr, "\t\t\{\n");
					{
						vector<int>::iterator enumlist = lenumValues.begin();
						while(enumlist != lenumValues.end())
						{
							fprintf(pEnumFPtr, "\t\t\tcase %d:\n", *enumlist);
							enumlist++;
						}
							lenumValues.clear();
						{
							fprintf(pEnumFPtr, "\t\t\t\tInteger32::setValue(val);\n");
							fprintf(pEnumFPtr, "\t\t\t\treturn 0;\n");
						}
					}
					fprintf(pEnumFPtr, "\t\t\tdefault:\n");
					fprintf(pEnumFPtr, "\t\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE, \"Unsupported Enumerated value\");\n\t\t\t\tthrow lTssDiaMsgException;\n\t\t}\n");
					fprintf(pEnumFPtr, "\t}\n");
					fprintf(pEnumFPtr, "};\n");
					fprintf(pEnumFPtr, "}\n");
					fprintf(pEnumFPtr, "#endif\n\n");
					fclose(pEnumFPtr);
					printf("[SUCCESS] File: %s created.\n", mHeaderFileName);
				}
				else
				{
					printf("[ERROR] Failed to create file: %s\n", mHeaderFileName);
				}
				list++;
			}
		}
		++lList;
	}

	return true;
}


//-----------------------------------------------------------------------------------------------
// METHOD       : GenerateMakeFile
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : BOOLEAN
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::GenerateMakeFile()
{ 
   string major_version = "$(DIAMETER_MAJOR_VERSION)";

   string minor_version = "$(DIAMETER_MINOR_VERSION)";

   string build_version = "$(DIAMETER_BUILD_VERSION)";

   vector<string> v;
   this->read_directory(string(mInterfacePath), v);

   if(strcmp(mInterface,"base") == 0)
   {
      ofstream outputfile;
      string fileName = string(mInterfacePath) + "/Makefile";
      outputfile.open(fileName, ios::out);
      if(outputfile.fail())
      {
         printf("Failed to generate Makefile\n");
         return false;
      }

      outputfile<<"# @(#) $Id:"<<endl;
      outputfile<<"ROOTDIR = $(DIAPARSE_HOME)"<<endl;
      outputfile<<"\n";
      outputfile<<"include $(ROOTDIR)/makeutil/header.mod\n"<<endl;
      outputfile<<"DEFS += -DCOMMONOAM"<<endl;
      outputfile<<"#SONAME=libBaseInterface.so"<<"."<<major_version<<"."<<minor_version<<endl;
      outputfile<<"######################################################################"<<endl;
      outputfile<<"# define the include flags."<<endl;
      outputfile<<"# define the list of source files."<<endl;
      outputfile<<"SRCS = \\"<<endl;

      for (auto & p : v)
         outputfile<<p<<".cc\\"<<endl;         

      outputfile<<"\nSRCS := $(SRCS:%=$(SRCDIR)/%)"<<endl;
      outputfile<<"######################################################################"<<endl;
      outputfile<<"INCLFLAGS = -I $(DIAPARSE_HOME)/include\\"<<endl;
      outputfile<<"            -I $(DIAPARSE_HOME)/diameterlib/\\"<<endl;
      outputfile<<"            -I $(DIAPARSE_HOME)/diameterutil/include\\"<<endl;
      outputfile<<"            -I $(UTIL_HOME)/include\\"<<endl;
      outputfile<<"\n"<<endl;
      outputfile<<"######################################################################"<<endl;
      outputfile<<"LIBFLAGS =  #$(DIAPARSE_HOME)/diameterutil/lib/libDiameterUtil.a\\\n"<<endl;
      outputfile<<"LIBDIR = lib\n"<<endl;
      outputfile<<"######################################################################"<<endl;
      outputfile<<"#    ********** For Library creation ***********"<<endl;
      outputfile<<"# list of generated object files."<<endl;
      outputfile<<"OBJS1= \\"<<endl;

      for (auto & p : v)
         outputfile<<p<<".o\\"<<endl;         

      outputfile<<"\nOBJS1:= $(OBJS1:%=$(OBJDIR)/%)\n"<<endl;
      outputfile<<"# list of libraries."<<endl;
      outputfile<<"LIBS1= $(DIAPARSE_HOME)/diameterutil/lib/libDiameterUtil.a\\\n"<<endl;
      outputfile<<"# output file name."<<endl;
      outputfile<<"OFILE1= libBaseInterface.a\n"<<endl;
      outputfile<<"# Program dependencies"<<endl;
      outputfile<<"$(OFILE1): $(LIBDIR)/$(OFILE1)"<<endl;
      outputfile<<"$(LIBDIR)/$(OFILE1): $(OBJS1) $(LIBS1)\n"<<endl;
      outputfile<<"######################################################################"<<endl;
      outputfile<<"#    ********** For Library creation ***********"<<endl;
      outputfile<<"# list of generated object files."<<endl;
      outputfile<<"OBJS2= \\"<<endl;

      for (auto & p : v)
         outputfile<<p<<".o\\"<<endl;         
      
      outputfile<<"\n\nOBJS2:= $(OBJS2:%=$(OBJDIR)/%)\n"<<endl;
      outputfile<<"# list of libraries.\n"<<endl;
      outputfile<<"LIBS2= $(DIAPARSE_HOME)/diameterutil/lib/libDiameterUtil.a\\\n"<<endl;
      outputfile<<"# output file name."<<endl;
      outputfile<<"OFILE2= libBaseInterface.so"<<endl<<endl;
      outputfile<<"# Program dependencies"<<endl;
      outputfile<<"$(OFILE2): $(LIBDIR)/$(OFILE2)"<<endl;
      outputfile<<"$(LIBDIR)/$(OFILE2): $(OBJS2) $(LIBS2)\n"<<endl;
      outputfile<<"######################################################################"<<endl;
      outputfile<<"# List of all object files"<<endl;
      outputfile<<"OBJS = $(OBJS1) $(OBJS2)\n"<<endl;
      outputfile<<"######################################################################"<<endl;
      outputfile<<"# List of all libraries to be created"<<endl;
      outputfile<<"OLIB =  $(OFILE1)"<<endl;
      outputfile<<"OLIB := $(OLIB:%=$(LIBDIR)/%)\n"<<endl;
      outputfile<<"OSLIB =  $(OFILE2)"<<endl;
      outputfile<<"OSLIB := $(OSLIB:%=$(LIBDIR)/%)"<<endl;
      outputfile<<"######################################################################"<<endl;
      outputfile<<"# List of all executables to be created"<<endl;
      outputfile<<"PROG ="<<endl;
      outputfile<<"PROG := $(PROG:%=$(BINDIR)/%)\n"<<endl;
      outputfile<<"########################################################################\n"<<endl;
      outputfile<<"include $(ROOTDIR)/makeutil/footer.mod"<<endl;
      outputfile<<"# DO NOT DELETE"<<endl;
      outputfile.close();
   }
   else
   {
      std::locale loc;
      string temp = string(mInterface);
      temp[0] = toupper(temp[0],loc);

      ofstream outputfile;
      string fileName = string(mInterfacePath) + "/Makefile";
      outputfile.open(fileName, ios::out);
      if(outputfile.fail())
      {
         printf("Failed to generate Makefile\n");
         return false;
      }

      outputfile<<"# @(#) $Id:"<<endl;
      outputfile<<"ROOTDIR = $(DIAPARSE_HOME)"<<endl;
      outputfile<<"\n";
      outputfile<<"include $(ROOTDIR)/makeutil/header.mod\n"<<endl;
      outputfile<<"DEFS += -DCOMMONOAM"<<endl;
      outputfile<<"#SONAME=lib"<<temp<<"Interface.so"<<"."<<major_version<<"."<<minor_version<<endl<<endl;
      outputfile<<"######################################################################"<<endl;
      outputfile<<"# define the include flags."<<endl;
      outputfile<<"# define the list of source files."<<endl;
      outputfile<<"SRCS = \\"<<endl;

      for (auto & p : v)
         outputfile<<p<<".cc\\"<<endl;         

      outputfile<<"\nSRCS := $(SRCS:%=$(SRCDIR)/%)"<<endl;
      outputfile<<"######################################################################"<<endl;
      outputfile<<"INCLFLAGS = -I $(DIAPARSE_HOME)/include\\"<<endl;
      outputfile<<"            -I $(DIAPARSE_HOME)/diameterlib/\\"<<endl;
      outputfile<<"            -I $(DIAPARSE_HOME)/diameterutil/include\\"<<endl;
      outputfile<<"            -I $(UTIL_HOME)/include\\"<<endl;
      outputfile<<"\n"<<endl;
      outputfile<<"######################################################################"<<endl;
      outputfile<<"LIBFLAGS =  #$(DIAPARSE_HOME)/diameterutil/lib/libDiameterUtil.a\\"<<endl;
      outputfile<<"            $(DIAPARSE_HOME)/diameterlib/base/lib/libBaseInterface.a\\\n"<<endl;
      outputfile<<"LIBDIR = lib\n"<<endl;
      outputfile<<"######################################################################"<<endl;
      outputfile<<"#    ********** For Library creation ***********"<<endl;
      outputfile<<"# list of generated object files."<<endl;
      outputfile<<"OBJS1= \\"<<endl;

      for (auto & p : v)
         outputfile<<p<<".o\\"<<endl;         

      outputfile<<"\nOBJS1:= $(OBJS1:%=$(OBJDIR)/%)\n"<<endl;
      outputfile<<"# list of libraries."<<endl;
      outputfile<<"LIBS1= $(DIAPARSE_HOME)/diameterutil/lib/libDiameterUtil.a\\"<<endl<<endl;
      outputfile<<"# output file name."<<endl;
      outputfile<<"OFILE1= lib"<<temp<<"Interface.a\n"<<endl;
      outputfile<<"# Program dependencies"<<endl;
      outputfile<<"$(OFILE1): $(LIBDIR)/$(OFILE1)"<<endl;
      outputfile<<"$(LIBDIR)/$(OFILE1): $(OBJS1) $(LIBS1)\n"<<endl;
      outputfile<<"######################################################################"<<endl;
      outputfile<<"#    ********** For Library creation ***********"<<endl;
      outputfile<<"# list of generated object files."<<endl;
      outputfile<<"OBJS2= \\"<<endl;

      for (auto & p : v)
         outputfile<<p<<".o\\"<<endl;         
      
      outputfile<<"\n\nOBJS2:= $(OBJS2:%=$(OBJDIR)/%)\n"<<endl;
      outputfile<<"# list of libraries.\n"<<endl;
      outputfile<<"LIBS2= $(DIAPARSE_HOME)/diameterutil/lib/libDiameterUtil.a\\"<<endl<<endl;
      outputfile<<"# output file name."<<endl;
      outputfile<<"OFILE2= lib"<<temp<<"Interface.so"<<endl<<endl;
      outputfile<<"# Program dependencies"<<endl;
      outputfile<<"$(OFILE2): $(LIBDIR)/$(OFILE2)"<<endl;
      outputfile<<"$(LIBDIR)/$(OFILE2): $(OBJS2) $(LIBS2)\n"<<endl;
      outputfile<<"######################################################################"<<endl;
      outputfile<<"# List of all object files"<<endl;
      outputfile<<"OBJS = $(OBJS1) $(OBJS2)\n"<<endl;
      outputfile<<"######################################################################"<<endl;
      outputfile<<"# List of all libraries to be created"<<endl;
      outputfile<<"OLIB =  $(OFILE1)"<<endl;
      outputfile<<"OLIB := $(OLIB:%=$(LIBDIR)/%)\n"<<endl;
      outputfile<<"OSLIB =  $(OFILE2)"<<endl;
      outputfile<<"OSLIB := $(OSLIB:%=$(LIBDIR)/%)"<<endl;
      outputfile<<"######################################################################"<<endl;
      outputfile<<"# List of all executables to be created"<<endl;
      outputfile<<"PROG ="<<endl;
      outputfile<<"PROG := $(PROG:%=$(BINDIR)/%)\n"<<endl;
      outputfile<<"########################################################################\n"<<endl;
      outputfile<<"include $(ROOTDIR)/makeutil/footer.mod"<<endl;
      outputfile<<"# DO NOT DELETE"<<endl;
      outputfile.close();
   }

   return true;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : read_directory
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
void DiameterCreateSource::read_directory(const string& name, vector<string>& v)
{
   string path = name + string("/src");
   DIR* dirp = opendir(path.c_str());
   struct dirent * dp;
   while ((dp = readdir(dirp)) != NULL) {
      string temp(basename(dp->d_name));
      int pos = 0;
      if(-1 != (pos = temp.find_last_of(".")))
      {
         temp = temp.substr(0,pos);
         if(temp.compare(".") != 0 && temp.compare("") != 0)
            v.push_back(temp);
        }
    }
    closedir(dirp);
}

//-----------------------------------------------------------------------------------------------
// METHOD       : generateSourceForFindAllwithPath
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
BOOLEAN DiameterCreateSource::generateSourceForFindAllwithPath()
{
	fprintf(mSourceFile, "\n\n");
	fprintf(mSourceFile, "BOOLEAN %s::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)\n{\n", mMessage.command );
	vector<avp>::iterator list = mAvpArgs.begin();

	if( mMessage.enumMsgGrpClass == MSG_CLASS)
	{
		fprintf(mSourceFile, "\t\tif(!mDecodeFlag && array != NULL)\n");
		fprintf(mSourceFile, "\t\t\tthis->Decode(array);\n\n");
	}

	if( mMessage.enumMsgGrpClass == GRP_CLASS)
	{
		fprintf(mSourceFile, "\tif(!this->mAvpDecodedFlag)\n");
		fprintf(mSourceFile, "\t{\n" );
		fprintf(mSourceFile, "\t\tthis->mspByteArray.get()->offset = 0;\n" );
		fprintf(mSourceFile, "\t\tthis->mspByteArray.get()->offset = this->getAvpOffsetLen().first;\n");
		fprintf(mSourceFile, "\t\tUINT16 lBytesDecoded = 0;\n" );
		fprintf(mSourceFile, "\t\tif(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)\n");
		fprintf(mSourceFile, "\t\t{\n" );
		fprintf(mSourceFile, "\t\t\tTssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,\"Error decoding %s\")     ;\n", mMessage.command);
		fprintf(mSourceFile, "\t\t\tthrow lTssDiaMsgException;\n" );
		fprintf(mSourceFile, "\t\t}\n" );
		fprintf(mSourceFile, "\t\tthis->mAvpDecodedFlag = true;\n");
		fprintf(mSourceFile, "\t}\n" );
	}
	
	fprintf(mSourceFile, "\tif(avpCodeMap.empty() || key > size)\n");
	fprintf(mSourceFile, "\t{\n" );
	fprintf(mSourceFile, "\t\treturn false;\n" );
	fprintf(mSourceFile, "\t}\n" );

	fprintf(mSourceFile, "\tauto it = avpCodeMap.find(key);\n");
	fprintf(mSourceFile, "\tif( it == avpCodeMap.end())\n");
	fprintf(mSourceFile, "\t{\n" );
	fprintf(mSourceFile, "\t\treturn false;\n" );
	fprintf(mSourceFile, "\t}\n" );

	fprintf(mSourceFile, "\tUINT32 avpCode = it->second;\n");

	fprintf(mSourceFile, "\t\tswitch(avpCode)\n\t\t{\n");
	while(list != mAvpArgs.end())
	{
		if( list->avpGrp == AVP) {
			fprintf(mSourceFile, "\t\t\tcase %d:\n", list->avpCode);
			fprintf(mSourceFile, "\t\t\t{\n");
				if( list->multiple == false) 
				{
					fprintf(mSourceFile, "\t\t\t\tif(m%s != NULL)\n", list->avpname);
					fprintf(mSourceFile, "\t\t\t\t{\n");
					fprintf(mSourceFile, "\t\t\t\t\tDiameterBaseInterface* inf =  m%s->Find(this->mspByteArray.get(), avpCode);\n", list->avpname);
					fprintf(mSourceFile, "\t\t\t\t\tif(inf != NULL)\n");
					fprintf(mSourceFile, "\t\t\t\t\t{\n");
					fprintf(mSourceFile, "\t\t\t\t\t\tpBaseInterface.push_back(inf);\n");
					fprintf(mSourceFile, "\t\t\t\t\t}\n");
					fprintf(mSourceFile, "\t\t\t\t}\n\n");
					fprintf(mSourceFile, "\t\t\t\tbreak;\n");
					fprintf(mSourceFile, "\t\t\t}\n");
				}
				else
				{
               fprintf(mSourceFile, "\t\t\t\tif(m%sList != NULL)\n", list->avpname);
               fprintf(mSourceFile, "\t\t\t\t{\n");
					fprintf(mSourceFile, "\t\t\t\t\tfor(auto itr = m%sList->begin(); itr != m%sList->end(); ++itr)\n", list->avpname, list->avpname);
					fprintf(mSourceFile, "\t\t\t\t\t{\n");
					fprintf(mSourceFile, "\t\t\t\t\t\tDiameterBaseInterface* inf =  (*itr)->Find(this->mspByteArray.get(), avpCode);\n");
					fprintf(mSourceFile, "\t\t\t\t\t\tif(inf != NULL)\n");
					fprintf(mSourceFile, "\t\t\t\t\t\t{\n");
					fprintf(mSourceFile, "\t\t\t\t\t\t\tpBaseInterface.push_back(inf);\n");
					fprintf(mSourceFile, "\t\t\t\t\t\t}\n");
					fprintf(mSourceFile, "\t\t\t\t\t}\n\n");
               fprintf(mSourceFile, "\t\t\t\t}\n");
					fprintf(mSourceFile, "\t\t\t\tbreak;\n");
					fprintf(mSourceFile, "\t\t\t}\n");
				}
		}
      else
      {
         fprintf(mSourceFile, "\t\t\tcase %d:\n", list->avpCode);
         fprintf(mSourceFile, "\t\t\t{\n");
         if( list->multiple == false)
         {
            fprintf(mSourceFile, "\t\t\t\tif(m%sGrp != NULL)\n", list->avpname);
            fprintf(mSourceFile, "\t\t\t\t{\n");
				fprintf(mSourceFile, "\t\t\t\t\tif(key == size)\n");
				fprintf(mSourceFile, "\t\t\t\t\t{\n" );
            fprintf(mSourceFile, "\t\t\t\t\t\tpBaseInterface.push_back(m%sGrp);\n", list->avpname); 
            fprintf(mSourceFile, "\t\t\t\t\t}\n");
            fprintf(mSourceFile, "\t\t\t\tif(deepInspect)\n");
            fprintf(mSourceFile, "\t\t\t\t{\n");
            fprintf(mSourceFile, "\t\t\t\t\tfor(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)\n");
            fprintf(mSourceFile, "\t\t\t\t\t{\n");
            fprintf(mSourceFile, "\t\t\t\t\t\tm%sGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);\n", list->avpname);
            fprintf(mSourceFile, "\t\t\t\t\t}\n");
            fprintf(mSourceFile, "\t\t\t\t}\n");
            fprintf(mSourceFile, "\t\t\t\t}\n");

            fprintf(mSourceFile, "\t\t\t\tbreak;\n"); 
         }
         else
         {
            fprintf(mSourceFile, "\t\t\t\tif(m%sGrpList != NULL)\n", list->avpname);
            fprintf(mSourceFile, "\t\t\t\t{\n");
				fprintf(mSourceFile, "\t\t\t\tif(key == size)\n");
				fprintf(mSourceFile, "\t\t\t\t{\n" );
            fprintf(mSourceFile, "\t\t\t\t\tfor(auto itr = m%sGrpList->begin(); itr != m%sGrpList->end(); ++itr)\n", list->avpname, list->avpname);
            fprintf(mSourceFile, "\t\t\t\t\t{\n");
            fprintf(mSourceFile, "\t\t\t\t\t\tpBaseInterface.push_back(*itr);\n");
            fprintf(mSourceFile, "\t\t\t\t\t}\n\n");
            fprintf(mSourceFile, "\t\t\t\t}\n");
            fprintf(mSourceFile, "\t\t\t\t\tif(deepInspect)\n");
            fprintf(mSourceFile, "\t\t\t\t\t{\n");
            fprintf(mSourceFile, "\t\t\t\t\tfor(auto itr = m%sGrpList->begin(); itr != m%sGrpList->end(); ++itr)\n", list->avpname, list->avpname);
            fprintf(mSourceFile, "\t\t\t\t\t\t{\n");
            fprintf(mSourceFile, "\t\t\t\t\t\t\t(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);\n");
            fprintf(mSourceFile, "\t\t\t\t\t\t}\n");
            fprintf(mSourceFile, "\t\t\t\t\t}\n");
				fprintf(mSourceFile, "\t\t\t\t}\n" );
            fprintf(mSourceFile, "\t\t\t\tbreak;\n");
         } 
         fprintf(mSourceFile, "\t\t\t}\n");
      }
		list++;
	}

	fprintf(mSourceFile, "\t\t\tdefault:\n");
	fprintf(mSourceFile, "\t\t\t{\n");
   fprintf(mSourceFile, "\t\t\t\t\tbreak;\n");
	fprintf(mSourceFile, "\t\t\t}\n");
 
	fprintf(mSourceFile, "\t\t}\n");
   fprintf(mSourceFile, "\t\tif(pBaseInterface.size() > 0)\n");
   fprintf(mSourceFile, "\t\t\treturn true;\n");
   fprintf(mSourceFile, "\t\telse\n" );
   fprintf(mSourceFile, "\t\t\treturn false;\n");
	fprintf(mSourceFile, "}\n");

	return true;
}


