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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IF = 258,
    ELSE = 259,
    FOR = 260,
    WHILE = 261,
    DO = 262,
    INT = 263,
    CHAR = 264,
    FLOAT = 265,
    DOUBLE = 266,
    VOID = 267,
    RETURN = 268,
    PRINTLN = 269,
    INCOP = 270,
    DECOP = 271,
    NOT = 272,
    LPAREN = 273,
    RPAREN = 274,
    LCURL = 275,
    RCURL = 276,
    LTHIRD = 277,
    RTHIRD = 278,
    COMMA = 279,
    SEMICOLON = 280,
    STRING = 281,
    COMMENT = 282,
    ASSIGNOP = 283,
    ADDOP = 284,
    LOGICOP = 285,
    MULOP = 286,
    RELOP = 287,
    ID = 288,
    CONST_INT = 289,
    CONST_FLOAT = 290,
    CONST_CHAR = 291,
    second_precedence = 292
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define DO 262
#define INT 263
#define CHAR 264
#define FLOAT 265
#define DOUBLE 266
#define VOID 267
#define RETURN 268
#define PRINTLN 269
#define INCOP 270
#define DECOP 271
#define NOT 272
#define LPAREN 273
#define RPAREN 274
#define LCURL 275
#define RCURL 276
#define LTHIRD 277
#define RTHIRD 278
#define COMMA 279
#define SEMICOLON 280
#define STRING 281
#define COMMENT 282
#define ASSIGNOP 283
#define ADDOP 284
#define LOGICOP 285
#define MULOP 286
#define RELOP 287
#define ID 288
#define CONST_INT 289
#define CONST_FLOAT 290
#define CONST_CHAR 291
#define second_precedence 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 44 "1505047.y" /* yacc.c:1909  */
 SymbolInfo* value; 

#line 131 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
