inf              [<]
sup              [>]
equal            [=]
bslash           [\/]

%x SPECIAL
%x COMMENTS

%{
#include "diameter.tab.h"
#include "iostream"
using namespace std;
#define YY_DECL extern "C" int yylex()
int line_num = 1;
%}
%%
[ \t]          ;
\n             {++line_num;}

<INITIAL>"//"          {BEGIN COMMENTS;}
"--"          {BEGIN COMMENTS;}
<COMMENTS>[a-zA-Z0-9]+ {}
<COMMENTS>\n    {BEGIN INITIAL;}

<INITIAL>{inf}       			{BEGIN SPECIAL; return T_INF;}
<SPECIAL>{bslash}"message"   	{return T_MESSAGEEND; }
<SPECIAL>message     			{return T_MESSAGE; }
<SPECIAL>command     			{return T_COMMAND; }
<SPECIAL>{bslash}"command"   	{return T_COMMAND; }
<SPECIAL>{equal}     			{return T_EQUAL;}
<SPECIAL>cmd-code    			{return T_CMDCODE; }
<SPECIAL>protocol-version  	{return T_PROTOCOLVERSION; }
<SPECIAL>command-flags      	{return T_COMMANDFLAGS; }
<SPECIAL>avp-flags       		{return T_AVPFLAGS; }
<SPECIAL>avp       				{return T_AVP; }
<SPECIAL>avp-name    			{return T_AVPNAME; }
<SPECIAL>avp-code    			{return T_AVPCODE; }
<SPECIAL>type    					{return T_TYPE; }
<SPECIAL>enum      				{return T_ENUM; }
<SPECIAL>name    					{return T_NAME; }
<SPECIAL>code    					{return T_CODE; }
<SPECIAL>{bslash}"enum"     	{return T_ENUMEND; }
<SPECIAL>{bslash}"avp"     	{return T_AVPEND; }

<SPECIAL>grouped-avp			  	{return T_GROUPEDAVP; }
<SPECIAL>{bslash}grouped-avp	{return T_GROUPEDAVPEND; }
<SPECIAL>grouped-avp-name    	{return T_GROUPEDAVPNAME; }
<SPECIAL>count   					{return T_COUNT; }
<SPECIAL>grouped-avp-code		{return T_GROUPEDAVPCODE; }
<SPECIAL>grouped-avp-flags		{return T_GROUPEDAVPFLAGS; }
<SPECIAL>grouped-vendor-id		{return T_GROUPEDVENDORID; }

<SPECIAL>sub-avp					{return T_SUBAVP; }
<SPECIAL>{bslash}sub-avp		{return T_SUBAVPEND; }
<SPECIAL>sub-avp-name			{return T_SUBAVPNAME; }
<SPECIAL>sub-avp-code			{return T_SUBAVPCODE; }
<SPECIAL>sub-avp-flags			{return T_SUBAVPFLAGS; }
<SPECIAL>grouped					{return T_GROUPED; }
<SPECIAL>{bslash}"grouped"   	{return T_GROUPEDEND; }
<SPECIAL>multiple					{return T_MULTIPLE; }
<SPECIAL>vendor-id				{return T_VENDORID; }
<SPECIAL>encrypt					{return T_ENCRYPT; }

<SPECIAL>[a-zA-Z]+   			{yylval.sval = strdup(yytext); return STRING; }
<SPECIAL>[0-9]+      			{yylval.ival = atoi(yytext); return INT; }
<SPECIAL>[a-zA-Z0-9_]+   			{yylval.sval = strdup(yytext); return STRING; }
<SPECIAL>{sup}       			{BEGIN INITIAL;return T_SUP;}
.              ;
%%

//<SPECIAL>[a-zA-Z]"-"[a-zA-Z]  {return STRING; }

//<SPECIAL>{equal}        {cout<<yytext<<endl;return T_EQUAL;}
//<SPECIAL>[a-zA-Z]+   {cout << yytext << endl;return T_STRING; }
//%%
//[ \t]          ; 
//<INITIAL>{inf}          { BEGIN SPECIAL; cout<<yytext<<endl;return T_INF; }
//<SPECIAL>setfield       { cout << yytext << endl;return T_STRING; }
//<SPECIAL>name           { cout << yytext << endl; return T_STRING; }
//<SPECIAL>{equal}        { cout<<yytext<<endl;return T_EQUAL; }
//<SPECIAL>flags          { cout << yytext << endl; return T_STRING; }
//<SPECIAL>value          { cout << yytext << endl; return T_STRING; }
//[0-9]+                  { yylval.ival = atoi(yytext); return INT; }
//<SPECIAL>{sup}          { BEGIN INITIAL; cout<<yytext<<endl;return T_SUP; }
//.              ;
//%%

//<SPECIAL>{equal}        { cout<<yytext<<endl;return T_EQUAL; }
//@(#) $Id: diameter.l,v 1.1.2.1 2025/01/29 15:33:27 mram Exp $
//----------------------------------------------------------------------
// NAME
//       diameter.l
//
// COPYRIGHT
// Tayana Software Solutions Ltd -- Copyright(C) 2017
// All rights reserved. No part of this computer program
// may be used or reproduced in any form by any
// means without prior written permission of
// Tayana Software Solutions Ltd
//
// DESCRIPTION : This file constitutes lex file, where we mention 
//					  required regular expressions to match the input
//					  from dictionary file. 
//
// AUTHOR         : Ram Prasad M                             27-MAR-2017
//
// 1.MODIFIED BY  :
//   MODIFICATION :
//----------------------------------------------------------------------
