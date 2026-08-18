// @(#) $Id: diameter.y,v 1.1.2.1 2025/01/29 15:33:27 mram Exp $
//----------------------------------------------------------------------
// NAME
//       diameter.y
//
// COPYRIGHT
// Tayana Software Solutions Ltd -- Copyright(C) 2017
// All rights reserved. No part of this computer program
// may be used or reproduced in any form by any
// means without prior written permission of
// Tayana Software Solutions Ltd
//
// DESCRIPTION : This file constitutes bison file which takes care of
//					  syntex and semantics of input dictionary file. Accordingly 
//						it generates the source file.
//
// AUTHOR         : Ram Prasad M                             27-MAR-2017
//
// 1.MODIFIED BY  :
//   MODIFICATION :
//----------------------------------------------------------------------
%{
#include <cstdio>
#include <unistd.h>
#include <sys/stat.h>
#include <iostream>
#include <string>
#include "../include/DiameterCreateSource.h"	

using namespace std;

   // stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int line_num;
    
void yyerror(const char *s);

DiameterCreateSource mDiameterCreateSource;

%}

   // Bison fundamentally works by asking flex to get the next token, which it
   // returns as an object of type "yystype".  But tokens could be of any
   // arbitrary data type!  So we deal with that in Bison by defining a C union
   // holding each of the types of tokens that Flex could return, and have Bison
   // use that union instead of "int" for the definition of "yystype":
%union {
int ival;
float fval;
char *sval;
}

// define the constant-string tokens:
%token T_INF
%token T_SUP
%token T_EQUAL
//%token T_STRING
%token T_COMMAND
%token T_COMMANDFLAGS
%token T_AVPFLAGS
%token T_CMDCODE
%token T_PROTOCOLVERSION
%token T_AVP
%token T_AVPEND
%token T_AVPNAME
%token T_TYPE
%token T_AVPCODE
%token T_MESSAGE
%token T_MESSAGEEND
%token T_GROUPEDAVPNAME
%token T_COUNT
%token T_SUBAVP
%token T_GROUPEDAVPCODE
%token T_SUBAVPFLAGS
%token T_SUBAVPNAME
%token T_GROUPEDAVP
%token T_GROUPEDAVPFLAGS
%token T_SUBAVPEND
%token T_SUBAVPCODE
%token T_GROUPEDAVPEND
%token T_GROUPED
%token T_GROUPEDEND
%token T_MULTIPLE
%token T_ENCRYPT
%token T_VENDORID
%token T_GROUPEDVENDORID
%token T_ENUM
%token T_ENUMEND
%token T_NAME
%token T_CODE
//%start xml_definition
//%token END ENDL

// define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the union:
%token <ival> INT
%token <sval> STRING
//%token <fval> FLOAT

%%
// the first rule defined is the highest-level rule, which in our
xml_definition:
   
	xml_definition message {}
   | xml_definition commandstart
   | xml_definition groupedstart { }
   | xml_definition groupedavpmark
   | xml_definition groupedend
	| xml_definition messageend
	| message
   ;

message:
   T_INF T_MESSAGE T_SUP {}
   ;
commandstart: 
   command {}
   | commandflags
   | commandcode
   | protocolversion
 	| commandend {}
   ;
command:
   T_INF T_COMMAND T_EQUAL STRING T_SUP { mDiameterCreateSource.SetClassName(yylval.sval, 1);}
   ;
commandflags:
   T_INF T_COMMANDFLAGS T_EQUAL STRING STRING STRING STRING T_SUP {mDiameterCreateSource.SetCommandFlags($4,$5,$6,$7);  }
   ;
commandcode:
   T_INF T_CMDCODE T_EQUAL INT T_SUP { mDiameterCreateSource.SetCommandCode($4); }
   ;
protocolversion:
   T_INF T_PROTOCOLVERSION T_EQUAL INT T_SUP { mDiameterCreateSource.SetProtocolVersion($4); }
   ;
commandend:
   T_INF T_COMMAND T_SUP { }
   ;
enumstart:
	enum {}
	| name {}
	| enumend {}
	;
enum:
   T_INF T_ENUM T_SUP { }
	;
name:
	T_INF T_NAME T_EQUAL STRING T_CODE T_EQUAL INT T_SUP { mDiameterCreateSource.pushEnumList($7, $4);}
   ;
enumend:
   T_INF T_ENUMEND T_SUP { }
   ;
	
avpstart:
   avp {}
   | avpname
   | avpcode
   | avpflags
	| vendorid
   | avpend {}
	| enumstart {}
   ;
avp:
   T_INF T_AVP T_SUP {  }
   ;
avpname:
	T_INF T_AVPNAME T_EQUAL STRING T_TYPE T_EQUAL STRING T_SUP {mDiameterCreateSource.SetAvpNameType($4,$7);}
   ;
avpcode:
   T_INF T_AVPCODE T_EQUAL INT T_ENCRYPT T_EQUAL STRING T_MULTIPLE T_EQUAL STRING T_SUP { mDiameterCreateSource.SetAvpCodeMultiple($4,$7, 1, $10); }
   ;
avpflags:
   T_INF T_AVPFLAGS T_EQUAL STRING STRING STRING T_SUP { mDiameterCreateSource.SetAvpFlags($4, $5, $6); }
   ;
avpend:
   T_INF T_AVPEND T_SUP { mDiameterCreateSource.InsertAvpDetails(); }
   ;
vendorid:
   T_INF T_VENDORID T_EQUAL INT T_SUP { mDiameterCreateSource.SetVendorId($4); }
   ;

groupedstart:
	groupedavpstart
	| groupedavpend
	| avpstart
	; 

groupedavpstart:
	groupedavp {}
	| groupedavpname
	| groupedavpcode
	| groupedavpflags
	| groupedvendorid
	;

groupedavp:
   T_INF T_GROUPEDAVP T_SUP {  }
   ;
groupedavpname:
	T_INF T_GROUPEDAVPNAME T_EQUAL STRING T_TYPE T_EQUAL STRING T_SUP {mDiameterCreateSource.SetClassName($4, 2);}
   ;
groupedavpcode:
   T_INF T_GROUPEDAVPCODE T_EQUAL INT T_ENCRYPT T_EQUAL STRING T_SUP { mDiameterCreateSource.SetAvpCode($4,$7, 2); }
   ;
groupedavpflags:
   T_INF T_GROUPEDAVPFLAGS T_EQUAL STRING STRING STRING T_SUP { mDiameterCreateSource.SetAvpFlags($4, $5, $6);  }
   ;
groupedvendorid:
   T_INF T_GROUPEDVENDORID T_EQUAL INT T_SUP { mDiameterCreateSource.SetVendorId($4); }
   ;
groupedavpend:
   T_INF T_GROUPEDAVPEND T_SUP { mDiameterCreateSource.InsertMessageDetails(); }
   ;

groupedavpmark:
   T_INF T_GROUPED T_EQUAL STRING T_MULTIPLE T_EQUAL STRING T_SUP { mDiameterCreateSource.setGroupMark($4, $7);}

groupedend:
   T_INF T_GROUPEDEND T_SUP { mDiameterCreateSource.InsertAvpDetails(); }
   ;

messageend:
   T_INF T_MESSAGEEND T_SUP { mDiameterCreateSource.InsertMessageDetails(); }
   ;
%%

//----------------------------------------------------------------------
// METHOD      : PrintHelp
// DESCRIPTION :
// PARAMETER   :
// RETURN      : 0
//----------------------------------------------------------------------
int PrintHelp (TEXT * pExe)
{
   printf ("usage: %s [arguments]\n\n", pExe);
   printf ("Arguments:\n");
   printf ("\t-d <file>\t\tSet Diameter Dictionary file(Mandatory).Full path not required.\n");
   printf ("\t-i <file>\t\tSet Diameter Interface(Mandatory)\n");

   return EXIT_SUCCESS;
}

//----------------------------------------------------------------------
// METHOD      : CheckDirectory
// DESCRIPTION :
// PARAMETER   :
// RETURN      : BOOLEAN
//----------------------------------------------------------------------
BOOLEAN CheckDirectory (TEXT * pDir)
{
   struct stat lStat;

   if (NULL == pDir || '\0' == pDir[0])
      return false;

   if (stat (pDir, &lStat) == 0 && S_ISDIR (lStat.st_mode))
   {
      return true;
   }
	
	return false;
}

int main(int argc, char* argv[]) 
{
	if (2 == argc && 0 == strcmp (argv[1], "-h"))
	{
		return PrintHelp (basename (argv[0]));
	}

	if (5 > argc)
	{
		printf ("[Error] %s: Mandatory Arguments Missing. Use -h for help\n",
				basename (argv[0]));

		return EXIT_FAILURE;
	}

	if(NULL == getenv("DIAPARSE_HOME"))
	{
      printf ("[Error] %s: DIAPARSE_HOME env not set\n",
            basename (argv[0]));
	
		return EXIT_FAILURE;
	}

	int lOpt = 0;
	TEXT lFileName[512] = "";
	TEXT lInterfaceName[10] = "";
	TEXT lDiameterLibPath[512] = "";
	while ((lOpt = getopt (argc, argv, "d:i:")) != -1)
	{
		switch (lOpt)
		{
			case 'd':
				if(NULL == optarg)
				{
					printf ("[Error] %s: -d requires dictionary file name as argument. Use -h for help\n",
							basename (argv[0]));
					return EXIT_FAILURE;
				}
				
				snprintf(lFileName, sizeof(lFileName), "%s/dictionary/%s", getenv("DIAPARSE_HOME"), optarg);

				break;

			case 'i':
				if(NULL == optarg)
				{
					printf ("[Error] %s: -i requires diameter interface name as argument. Use -h for help\n",
							basename (argv[0]));
					return EXIT_FAILURE;
				}

				snprintf(lInterfaceName, sizeof(lInterfaceName), "%s", optarg);
				for ( int i = 0; lInterfaceName[i] != '\0'; ++i) lInterfaceName[i] = tolower(lInterfaceName[i]);			
			
				break;

			default:
				printf ("[Warning] %s: Unknown Argument \'%c\'. Use -h for help\n", 
						basename (argv[0]),	lOpt);
				break;
		}
	}

	snprintf( lDiameterLibPath, sizeof(lDiameterLibPath), "%s/diameterlib/%s",
			getenv("DIAPARSE_HOME"),lInterfaceName);

	printf ("[Info] %s: Interface:%s File:%s\n", basename (argv[0]),  lInterfaceName, lFileName);
	
	printf("\n\n==========================================================================================================================\n");
	printf("Diameter Interface:\t\t%s\n", lInterfaceName);
	printf("Diameter File Name:\t\t%s\n", lFileName);
	printf("Diameter Library Path:\t\t%s\n", lDiameterLibPath);
	printf("==========================================================================================================================\n\n");
	
	printf("Generate Interface wise code\n");
	string reply = "";
	do{
		reply="";
		printf("Is this ok [Y/N]:");
		getline (cin, reply);

		if(reply.compare("Y") == 0||reply.compare("y") == 0)	
			break;
	
		if(reply.compare("N") == 0||reply.compare("n") == 0)
			return EXIT_SUCCESS;
		
	}while(1);

	if(!CheckDirectory(lDiameterLibPath))
	{
		printf("Interface Directory not present\n");
		reply = "";
		do{
			reply="";
			printf("Do you want to create it [Y/N]:");
			getline (cin, reply);

			if(reply.compare("Y") == 0||reply.compare("y") == 0)
			{	
				char cmd[300] = "";
				snprintf(cmd, sizeof(cmd), "mkdir -p %s",lDiameterLibPath);
				system(cmd);
				memset(cmd, 0, sizeof(cmd));
				snprintf(cmd, sizeof(cmd), "mkdir -p %s/include",lDiameterLibPath);
				system(cmd);
				memset(cmd, 0, sizeof(cmd));
				snprintf(cmd, sizeof(cmd), "mkdir -p %s/src",lDiameterLibPath);
				system(cmd);
				memset(cmd, 0, sizeof(cmd));
				snprintf(cmd, sizeof(cmd), "mkdir -p %s/lib",lDiameterLibPath);
				system(cmd);
				memset(cmd, 0, sizeof(cmd));
				snprintf(cmd, sizeof(cmd), "mkdir -p %s/obj",lDiameterLibPath);
				system(cmd);
				break;
			}

			if(reply.compare("N") == 0||reply.compare("n") == 0)
				return EXIT_SUCCESS;

		}while(1);
	}

	mDiameterCreateSource.SetInterfacePath(lDiameterLibPath);
	mDiameterCreateSource.SetInterface(lInterfaceName);

	int   L_parse_result ;
	// open a file handle to a particular file:
	//FILE *myfile = fopen("diameter.dictionary", "r");
	FILE *myfile = fopen(lFileName, "r");
	// make sure it's valid:
	if (!myfile) {
		cout << "I can't open "<< lFileName <<" file!" << endl;
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;

	// parse through the input until there is no more:

   do {
   L_parse_result = yyparse();
   } while (!feof(yyin));

   if(L_parse_result != 0)
   {
      cout << " Error on parsing! : " << L_parse_result << endl;
   }
   else
   {
      cout << "parsing success!" << endl;
   }
	
	mDiameterCreateSource.GenerateSource();
}

void yyerror(const char *s) {
   cout << "EEK, parse error on line " << line_num << "!  Message: " << s << endl;
   // might as well halt now:
   //  exit(-1);
}
