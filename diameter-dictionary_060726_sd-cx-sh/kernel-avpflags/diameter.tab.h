/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_DIAMETER_TAB_H_INCLUDED
# define YY_YY_DIAMETER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_INF = 258,
    T_SUP = 259,
    T_EQUAL = 260,
    T_COMMAND = 261,
    T_COMMANDFLAGS = 262,
    T_AVPFLAGS = 263,
    T_CMDCODE = 264,
    T_PROTOCOLVERSION = 265,
    T_AVP = 266,
    T_AVPEND = 267,
    T_AVPNAME = 268,
    T_TYPE = 269,
    T_AVPCODE = 270,
    T_MESSAGE = 271,
    T_MESSAGEEND = 272,
    T_GROUPEDAVPNAME = 273,
    T_COUNT = 274,
    T_SUBAVP = 275,
    T_GROUPEDAVPCODE = 276,
    T_SUBAVPFLAGS = 277,
    T_SUBAVPNAME = 278,
    T_GROUPEDAVP = 279,
    T_GROUPEDAVPFLAGS = 280,
    T_SUBAVPEND = 281,
    T_SUBAVPCODE = 282,
    T_GROUPEDAVPEND = 283,
    T_GROUPED = 284,
    T_GROUPEDEND = 285,
    T_MULTIPLE = 286,
    T_ENCRYPT = 287,
    T_VENDORID = 288,
    T_GROUPEDVENDORID = 289,
    T_ENUM = 290,
    T_ENUMEND = 291,
    T_NAME = 292,
    T_CODE = 293,
    INT = 294,
    STRING = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 49 "src/diameter.y" /* yacc.c:1909  */

int ival;
float fval;
char *sval;

#line 101 "diameter.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_DIAMETER_TAB_H_INCLUDED  */
