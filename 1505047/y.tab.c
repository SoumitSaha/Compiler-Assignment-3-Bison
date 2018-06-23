/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "1505047.y" /* yacc.c:339  */

#include<iostream>
#include<cstdlib>
#include<cstring>
#include <limits>
#include<stack>
#include<cmath>
#include <vector>
#include "SymTab.h"


using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;

string lastVarType;
extern int line_count;
int semErrors;
int IDarguments = 0;
vector<string> argumentlist;
int warnings = 0;
int argset = 0;
int paraset = 0;


void yyerror(const char *s){
}

ofstream logFile, errorFile;

SymbolTable table(15);
vector<SymbolInfo> parameters;

#include "actionFuncs.h"



#line 106 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 41 "1505047.y" /* yacc.c:355  */
 SymbolInfo* value; 

#line 223 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 240 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   133

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    89,   101,   113,   123,   133,   145,   164,
     183,   183,   205,   226,   240,   257,   269,   277,   287,   277,
     302,   316,   329,   343,   357,   371,   387,   400,   416,   428,
     445,   455,   468,   478,   488,   498,   516,   530,   547,   561,
     576,   593,   608,   623,   634,   646,   659,   674,   694,   705,
     723,   734,   752,   763,   781,   792,   810,   821,   839,   854,
     869,   882,   892,   927,   940,   954,   968,   981,   996,  1006,
    1012,  1024
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "DO",
  "INT", "CHAR", "FLOAT", "DOUBLE", "VOID", "RETURN", "PRINTLN", "INCOP",
  "DECOP", "NOT", "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD",
  "COMMA", "SEMICOLON", "STRING", "COMMENT", "ASSIGNOP", "ADDOP",
  "LOGICOP", "MULOP", "RELOP", "ID", "CONST_INT", "CONST_FLOAT",
  "CONST_CHAR", "second_precedence", "$accept", "start", "program", "unit",
  "func_declaration", "func_definition", "$@1", "parameter_list",
  "compound_statement", "$@2", "$@3", "var_declaration", "type_specifier",
  "declaration_list", "statements", "statement", "expression_statement",
  "variable", "expression", "logic_expression", "rel_expression",
  "simple_expression", "term", "unary_expression", "factor",
  "argument_list", "arguments", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

#define YYPACT_NINF -68

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-68)))

#define YYTABLE_NINF -11

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      42,   -68,   -68,   -68,    26,    42,   -68,   -68,   -68,   -68,
      -6,   -68,   -68,    38,     0,    42,    19,   -68,    -5,   -68,
      -3,    30,    36,    43,    13,    42,   -68,   -68,    41,   -68,
     -68,    44,    34,    49,    56,   -68,   -68,   -68,   -68,    68,
      61,    65,    66,    78,    69,    78,    78,   -68,    78,    40,
     -68,   -68,   -68,   -68,    57,    68,   -68,   -68,    33,     9,
     -68,    59,   -12,    60,   -68,   -68,    78,    81,    78,    10,
      67,     3,   -68,    73,   -68,    78,    78,    72,    83,   -68,
     -68,   -68,    78,   -68,   -68,    78,    78,    78,    78,    86,
      81,    89,   -68,   -68,    90,   -68,   -68,    98,    94,    96,
     -68,   -68,   -68,    60,    91,   -68,    68,    78,    68,    22,
     -68,    78,   -68,   117,   103,   -68,   -68,   -68,   -68,    68,
      68,   -68,   -68
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    23,    24,    25,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    28,     0,    16,     0,    22,     0,    21,
       0,    15,     0,    26,     0,     0,    14,    29,     0,     9,
       8,     0,    13,     0,    17,    11,    12,    27,    20,     0,
       0,     0,     0,     0,     0,     0,     0,    43,     0,    46,
      64,    65,    34,    32,     0,    18,    30,    33,    61,     0,
      48,    50,    52,    54,    56,    60,     0,     0,     0,     0,
       0,    61,    59,     0,    58,    69,     0,    28,     0,    31,
      66,    67,     0,    45,    44,     0,     0,     0,     0,     0,
       0,     0,    42,    41,     0,    63,    71,     0,    68,     0,
      19,    49,    51,    55,    53,    57,     0,     0,     0,     0,
      62,     0,    47,    36,     0,    38,    40,    39,    70,     0,
       0,    37,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -68,   -68,   -68,   118,   -68,   -68,   -68,   -68,    93,   -68,
     -68,    46,     7,   -68,   -68,   -51,   -54,   -45,   -37,   -67,
      45,    39,    47,   -43,   -68,   -68,   -68
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    31,    20,    52,    39,
      78,    53,    54,    14,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    97,    98
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      71,    17,    72,    71,    79,    74,    69,    10,    96,    73,
      83,    92,    10,    90,    29,   101,    24,    86,    80,    81,
      87,    25,    21,   116,    18,    19,    11,    13,    23,    89,
      71,    91,    32,   -10,    84,    93,   107,    71,    30,    99,
      71,    71,    71,    71,   118,   105,     9,   117,    80,    81,
       1,     9,     2,    22,     3,   113,    15,   115,    75,    27,
      16,    82,    76,    26,    34,    28,    71,    36,   121,   122,
     114,    40,    37,    41,    42,    33,     1,    38,     2,    66,
       3,    43,    44,    67,    68,    45,    46,    70,    34,    85,
      77,    88,    95,    47,    16,    45,    46,    48,    45,    46,
      94,    49,    50,    51,   100,   106,    47,    48,   108,   109,
      48,    49,    50,    51,    49,    50,    51,   110,   111,   112,
      86,   119,   120,    12,    35,     0,   104,     0,     0,     0,
     102,     0,     0,   103
};

static const yytype_int8 yycheck[] =
{
      45,     1,    45,    48,    55,    48,    43,     0,    75,    46,
       1,     1,     5,    67,     1,    82,    19,    29,    15,    16,
      32,    24,    15,     1,    24,    25,     0,    33,    33,    66,
      75,    68,    25,    20,    25,    25,    90,    82,    25,    76,
      85,    86,    87,    88,   111,    88,     0,    25,    15,    16,
       8,     5,    10,    34,    12,   106,    18,   108,    18,    23,
      22,    28,    22,    33,    20,    22,   111,    33,   119,   120,
     107,     3,    23,     5,     6,    34,     8,    21,    10,    18,
      12,    13,    14,    18,    18,    17,    18,    18,    20,    30,
      33,    31,    19,    25,    22,    17,    18,    29,    17,    18,
      33,    33,    34,    35,    21,    19,    25,    29,    19,    19,
      29,    33,    34,    35,    33,    34,    35,    19,    24,    23,
      29,     4,    19,     5,    31,    -1,    87,    -1,    -1,    -1,
      85,    -1,    -1,    86
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    10,    12,    39,    40,    41,    42,    43,    49,
      50,     0,    41,    33,    51,    18,    22,     1,    24,    25,
      45,    50,    34,    33,    19,    24,    33,    23,    22,     1,
      25,    44,    50,    34,    20,    46,    33,    23,    21,    47,
       3,     5,     6,    13,    14,    17,    18,    25,    29,    33,
      34,    35,    46,    49,    50,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    18,    18,    18,    56,
      18,    55,    61,    56,    61,    18,    22,    33,    48,    53,
      15,    16,    28,     1,    25,    30,    29,    32,    31,    56,
      54,    56,     1,    25,    33,    19,    57,    63,    64,    56,
      21,    57,    58,    60,    59,    61,    19,    54,    19,    19,
      19,    24,    23,    53,    56,    53,     1,    25,    57,     4,
      19,    53,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    42,    42,
      44,    43,    45,    45,    45,    45,    45,    47,    48,    46,
      46,    49,    49,    50,    50,    50,    51,    51,    51,    51,
      52,    52,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    54,    54,    54,    55,    55,    56,    56,
      57,    57,    58,    58,    59,    59,    60,    60,    61,    61,
      61,    62,    62,    62,    62,    62,    62,    62,    63,    63,
      64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     6,
       0,     7,     4,     3,     2,     1,     0,     0,     0,     5,
       2,     3,     3,     1,     1,     1,     3,     6,     1,     4,
       1,     2,     1,     1,     1,     7,     5,     7,     5,     5,
       5,     3,     3,     1,     2,     2,     1,     4,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     2,     2,
       1,     1,     4,     3,     1,     1,     2,     2,     1,     0,
       3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 85 "1505047.y" /* yacc.c:1646  */
    {	//writelog("start : program");			
			}
#line 1410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 89 "1505047.y" /* yacc.c:1646  */
    {	
				writelog("program : program unit");		
				
				logline();
				string str = "";
				str.append((yyvsp[-1].value)->Getsname());
				str.append(" ");
				str.append((yyvsp[0].value)->Getsname());
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();
			}
#line 1427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 101 "1505047.y" /* yacc.c:1646  */
    {	
				writelog("program : unit");
				
				logline();
				string str = "";
				str.append((yyvsp[0].value)->Getsname());
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();	
			}
#line 1442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 113 "1505047.y" /* yacc.c:1646  */
    {	
				writelog("unit : var_declaration");
				
				logline();
				string str = "";
				str.append((yyvsp[0].value)->Getsname());
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();	
			}
#line 1457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 123 "1505047.y" /* yacc.c:1646  */
    {	
     			writelog("unit : func_declaration");
     			
     			logline();
     			string str = "";
				str.append((yyvsp[0].value)->Getsname());
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();		
     		}
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 133 "1505047.y" /* yacc.c:1646  */
    {	
     			writelog("unit : func_definition");		
     			
     			logline();
     			string str = "";
				str.append((yyvsp[0].value)->Getsname());
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();
     		}
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 145 "1505047.y" /* yacc.c:1646  */
    {
				writelog("func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
				func_dec((yyvsp[-5].value),(yyvsp[-4].value));
				
				logline();
				string str = "";
				str.append((yyvsp[-5].value)->Getsname());
				str.append((yyvsp[-4].value)->Getsname());
				str.append((yyvsp[-3].value)->Getsname());
				if(paraset == 1){
					str.append((yyvsp[-2].value)->Getsname());
				}
				str.append((yyvsp[-1].value)->Getsname());
				str.append((yyvsp[0].value)->Getsname());
				str.append("\n");
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();
			}
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 164 "1505047.y" /* yacc.c:1646  */
    {
				writeerr("expected ;");
				
				logline();
				string str = "";
				str.append((yyvsp[-5].value)->Getsname());
				str.append((yyvsp[-4].value)->Getsname());
				str.append((yyvsp[-3].value)->Getsname());
				if(paraset == 1){
					str.append((yyvsp[-2].value)->Getsname());
				}
				str.append((yyvsp[-1].value)->Getsname());
				str.append("\n");
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();
			}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 183 "1505047.y" /* yacc.c:1646  */
    { 
				writelog("func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");
				func_def((yyvsp[-4].value),(yyvsp[-3].value));
			}
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 186 "1505047.y" /* yacc.c:1646  */
    {
				
				logline();
				string str = "";
				str.append((yyvsp[-6].value)->Getsname());
				str.append((yyvsp[-5].value)->Getsname());
				str.append((yyvsp[-4].value)->Getsname());
				if(paraset == 1){
					str.append((yyvsp[-3].value)->Getsname());
				}
				str.append((yyvsp[-2].value)->Getsname());
				str.append((yyvsp[0].value)->Getsname());
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();
			}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 205 "1505047.y" /* yacc.c:1646  */
    {
				writelog("parameter_list  : parameter_list COMMA type_specifier ID");
				argumentlist.push_back(lastVarType);
				IDarguments++;
				(yyvsp[0].value)->kindofID = "VAR";
				(yyvsp[0].value)->kindofVariable = lastVarType;
				SymbolInfo* temp = makenewSymInfobyname((yyvsp[0].value)->Getsname(), (yyvsp[0].value)->Getstype());
				temp->kindofID = "VAR";
				parameters.push_back(*temp);
				paraset = 1;
				
				logline();
				string str = "";
				str.append((yyvsp[-3].value)->Getsname());
				str.append((yyvsp[-2].value)->Getsname());
				str.append((yyvsp[-1].value)->Getsname());
				str.append((yyvsp[0].value)->Getsname());
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();
			}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 226 "1505047.y" /* yacc.c:1646  */
    {
				writelog("parameter_list  : parameter_list COMMA type_specifier");
				argumentlist.push_back((yyvsp[0].value)->kindofVariable);
				paraset = 1;

				logline();
				string str = "";
				str.append((yyvsp[-2].value)->Getsname());
				str.append((yyvsp[-1].value)->Getsname());
				str.append((yyvsp[0].value)->Getsname());
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();
			}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 240 "1505047.y" /* yacc.c:1646  */
    {
 				writelog("parameter_list  : type_specifier ID");
				argumentlist.push_back(lastVarType);
				IDarguments++;
				(yyvsp[0].value)->kindofID = "VAR";
				(yyvsp[0].value)->kindofVariable = lastVarType;
				parameters.push_back(*(yyvsp[0].value));
				paraset = 1;

				logline();
				string str = "";
				str.append((yyvsp[-1].value)->Getsname());
				str.append((yyvsp[0].value)->Getsname());
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();
 			}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 257 "1505047.y" /* yacc.c:1646  */
    {
				writelog("parameter_list  : type_specifier.");
				argumentlist.push_back(lastVarType);
				paraset = 1;

				logline();
				string str = "";
				str.append((yyvsp[0].value)->Getsname());
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();
			}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 269 "1505047.y" /* yacc.c:1646  */
    {	
				writelog("parameter_list  : empty");
				paraset = 0;

			}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 277 "1505047.y" /* yacc.c:1646  */
    {
				writelog("compound_statement : LCURL statements RCURL");
				table.EnterScope(logFile);
				for(int i = 0; i<parameters.size(); i++) {
					table.Insert(parameters[i].Getsname(), parameters[i].Getstype());
					SymbolInfo* temp = table.LookUp(parameters[i].Getsname());
					temp->kindofID = parameters[i].kindofID;
					temp->kindofVariable = parameters[i].kindofVariable;
				}
				parameters.clear();
			}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 287 "1505047.y" /* yacc.c:1646  */
    {	table.PrintAllinFile(logFile);	}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 287 "1505047.y" /* yacc.c:1646  */
    {	
				table.ExitScope(logFile);

				logline();
				string str = "";
				str.append("\n");
				str.append((yyvsp[-4].value)->Getsname());
				str.append("\n");
				str.append((yyvsp[-2].value)->Getsname());
				str.append((yyvsp[0].value)->Getsname());
				str.append("\n");
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();
			}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 302 "1505047.y" /* yacc.c:1646  */
    {	
 		    	writelog("compound_statement : LCURL RCURL");

 		    	logline();
 		    	string str = "";
 		    	str.append((yyvsp[-1].value)->Getsname());
				str.append(" ");
				str.append((yyvsp[0].value)->Getsname());
				printstr(str);
				(yyval.value)->Setsname(str);
 		    	logline();
 		    }
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 316 "1505047.y" /* yacc.c:1646  */
    {	
				writelog("var_declaration : type_specifier declaration_list SEMICOLON");

				logline();
				string str = "";
				str.append((yyvsp[-2].value)->Getsname());
				str.append((yyvsp[-1].value)->Getsname());
				str.append((yyvsp[0].value)->Getsname());
				str.append("\n");
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();
			}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 329 "1505047.y" /* yacc.c:1646  */
    {	
				writeerr("expected ;");

				logline();
				string str = "";
				str.append((yyvsp[-2].value)->Getsname());
				str.append((yyvsp[-1].value)->Getsname());
				str.append("\n");
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();	
			}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 343 "1505047.y" /* yacc.c:1646  */
    {
				writelog("type_specifier : INT");
				SymbolInfo* s= makenewSymInfo("INT");
				lastVarType = "INT";
				(yyval.value) = s;

				logline();
				string str = "";
				str.append((yyvsp[0].value)->Getsname());
				str.append(" ");
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();
			}
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 357 "1505047.y" /* yacc.c:1646  */
    {
 				writelog("type_specifier : FLOAT");
				SymbolInfo* s= makenewSymInfo("FLOAT");
				lastVarType = "FLOAT";
				(yyval.value) = s;

				logline();
				string str = "";
				str.append((yyvsp[0].value)->Getsname());
				str.append(" ");
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();
 			}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 371 "1505047.y" /* yacc.c:1646  */
    {
 				writelog("type_specifier : VOID");
				SymbolInfo* s= makenewSymInfo("VOID");
				lastVarType = "VOID";
				(yyval.value) = s;

				logline();
				string str = "";
				str.append((yyvsp[0].value)->Getsname());
				str.append(" ");
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();
 			}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 387 "1505047.y" /* yacc.c:1646  */
    {
				writelog("declaration_list : 	declaration_list COMMA ID");
				declistcomid((yyvsp[0].value));

				logline();
				string str = "";
				str.append((yyvsp[-2].value)->Getsname());
				str.append((yyvsp[-1].value)->Getsname());
				str.append((yyvsp[0].value)->Getsname());
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();
			}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 400 "1505047.y" /* yacc.c:1646  */
    {
 				writelog("declaration_list : 	declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
				declistarr((yyvsp[-3].value),(yyvsp[-1].value));

				logline();
				string str = "";
				str.append((yyvsp[-5].value)->Getsname());
				str.append((yyvsp[-4].value)->Getsname());
				str.append((yyvsp[-3].value)->Getsname());
				str.append((yyvsp[-2].value)->Getsname());
				str.append((yyvsp[-1].value)->Getsname());
				str.append((yyvsp[0].value)->Getsname());
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();
 			}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 416 "1505047.y" /* yacc.c:1646  */
    {
 				writelog("declaration_list : ID");
				onlyid((yyvsp[0].value));

				logline();
				string str = "";
				str.append((yyvsp[0].value)->Getsname());
				str.append(" ");
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();
 			}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 428 "1505047.y" /* yacc.c:1646  */
    {
 				writelog("declaration_list :	ID LTHIRD CONST_INT RTHIRD");
				onlyarray((yyvsp[-3].value),(yyvsp[-1].value));

				logline();
				string str = "";
				str.append((yyvsp[-3].value)->Getsname());
				str.append((yyvsp[-2].value)->Getsname());
				str.append((yyvsp[-1].value)->Getsname());
				str.append((yyvsp[0].value)->Getsname());
				str.append(" ");
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();	
 			}
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 445 "1505047.y" /* yacc.c:1646  */
    {	
				writelog("statements : statement");

				logline();
				string str = "";
				str.append((yyvsp[0].value)->Getsname());
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();
			}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 455 "1505047.y" /* yacc.c:1646  */
    {	
	   			writelog("statements : statements statement");

	   			logline();
				string str = "";
	   			str.append((yyvsp[-1].value)->Getsname());
				str.append((yyvsp[0].value)->Getsname());
				printstr(str);
				(yyval.value)->Setsname(str);
	   			logline();	
	   		}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 468 "1505047.y" /* yacc.c:1646  */
    {	
				writelog("statement : var_declaration");	

				logline();
				string str = "";
				str.append((yyvsp[0].value)->Getsname());
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();
			}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 478 "1505047.y" /* yacc.c:1646  */
    {	
	  			writelog("statement : expression_statement");	

	  			logline();
				string str = "";
	  			str.append((yyvsp[0].value)->Getsname());
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();	
	  		}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 488 "1505047.y" /* yacc.c:1646  */
    {	
	  			writelog("statement : compound_statement");	

	  			logline();
				string str = "";
	  			str.append((yyvsp[0].value)->Getsname());
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();	
	  		}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 498 "1505047.y" /* yacc.c:1646  */
    {	
	  			writelog("statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement");

	  			logline();
				string str = "";
	  			str.append((yyvsp[-6].value)->Getsname());
				str.append((yyvsp[-5].value)->Getsname());
				str.append((yyvsp[-4].value)->Getsname());
				str.append(" ");
				str.append((yyvsp[-3].value)->Getsname());
				str.append(" ");
				str.append((yyvsp[-2].value)->Getsname());
				str.append((yyvsp[-1].value)->Getsname());
				str.append((yyvsp[0].value)->Getsname());
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();	
	  		}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 516 "1505047.y" /* yacc.c:1646  */
    {	
	  			writelog("statement : IF LPAREN expression RPAREN statement");	

	  			logline();
				string str = "";
	  			str.append((yyvsp[-4].value)->Getsname());
				str.append((yyvsp[-3].value)->Getsname());
				str.append((yyvsp[-2].value)->Getsname());
				str.append((yyvsp[-1].value)->Getsname());
				str.append((yyvsp[0].value)->Getsname());
				printstr(str);
				(yyval.value)->Setsname(str);
	  			logline();
	  		}
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 530 "1505047.y" /* yacc.c:1646  */
    {	
	  			writelog("statement : IF LPAREN expression RPAREN statement ELSE statement");

	  			logline();
				string str = "";
	  			str.append((yyvsp[-6].value)->Getsname());
				str.append((yyvsp[-5].value)->Getsname());
				str.append((yyvsp[-4].value)->Getsname());
				str.append((yyvsp[-3].value)->Getsname());
				str.append((yyvsp[-2].value)->Getsname());
				str.append(" ");
				str.append((yyvsp[-1].value)->Getsname());
				str.append((yyvsp[0].value)->Getsname());
				printstr(str);
				(yyval.value)->Setsname(str);
	  			logline();	
	  		}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 547 "1505047.y" /* yacc.c:1646  */
    {	
	  			writelog("statement : WHILE LPAREN expression RPAREN statement");

	  			logline();
				string str = "";
	  			str.append((yyvsp[-4].value)->Getsname());
				str.append((yyvsp[-3].value)->Getsname());
				str.append((yyvsp[-2].value)->Getsname());
				str.append((yyvsp[-1].value)->Getsname());
				str.append((yyvsp[0].value)->Getsname());
				printstr(str);
				(yyval.value)->Setsname(str);
	  			logline();
	  		}
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 561 "1505047.y" /* yacc.c:1646  */
    {	
	  			writelog("statement : PRINTLN LPAREN ID RPAREN SEMICOLON");

	  			logline();
				string str = "";
	  			str.append((yyvsp[-4].value)->Getsname());
				str.append((yyvsp[-3].value)->Getsname());
				str.append((yyvsp[-2].value)->Getsname());
				str.append((yyvsp[-1].value)->Getsname());
				str.append((yyvsp[0].value)->Getsname());
				str.append("\n");
	  			printstr(str);
				(yyval.value)->Setsname(str);
	  			logline();
	  		}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 576 "1505047.y" /* yacc.c:1646  */
    {	
	  			writeerr("expected ;");

	  			logline();
				string str = "";
	  			str.append((yyvsp[-4].value)->Getsname());
				str.append(" ");
				str.append((yyvsp[-3].value)->Getsname());
				str.append(" ");
				str.append((yyvsp[-2].value)->Getsname());
				str.append(" ");
				str.append((yyvsp[-1].value)->Getsname());
				str.append("\n");
				printstr(str);
				(yyval.value)->Setsname(str);
	  			logline();
	  		}
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 593 "1505047.y" /* yacc.c:1646  */
    {	
	  			writelog("statement : RETURN expression SEMICOLON");

	  			logline();
				string str = "";
	  			str.append((yyvsp[-2].value)->Getsname());
				str.append(" ");
				str.append((yyvsp[-1].value)->Getsname());
				str.append(" ");
				str.append((yyvsp[0].value)->Getsname());
	  			str.append("\n");
				printstr(str);
				(yyval.value)->Setsname(str);
	  			logline();
	  		}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 608 "1505047.y" /* yacc.c:1646  */
    {	
	  			writeerr("expected ;");

	  			logline();
				string str = "";
	  			str.append((yyvsp[-2].value)->Getsname());
				str.append(" ");
				str.append((yyvsp[-1].value)->Getsname());
	  			str.append("\n");
				printstr(str);
				(yyval.value)->Setsname(str);
	  			logline();	
	  		}
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 623 "1505047.y" /* yacc.c:1646  */
    {	
				writelog("expression_statement : SEMICOLON");

				logline();
				string str = "";
				str.append((yyvsp[0].value)->Getsname());
				str.append("\n");
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();
			}
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 634 "1505047.y" /* yacc.c:1646  */
    {	
				writelog("expression_statement : expression SEMICOLON");

				logline();
				string str = "";
				str.append((yyvsp[-1].value)->Getsname());
				str.append((yyvsp[0].value)->Getsname());
				str.append("\n");
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();
			}
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 646 "1505047.y" /* yacc.c:1646  */
    {	
				writeerr("expected ;");

				logline();
				string str = "";
				str.append((yyvsp[-1].value)->Getsname());
				str.append("\n");
				printstr(str);
				(yyval.value)->Setsname(str);
				logline();
			}
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 659 "1505047.y" /* yacc.c:1646  */
    {
			writelog("variable : ID");
			SymbolInfo* temp = variabletoid((yyval.value),(yyvsp[0].value));
			if (temp != 0){
				(yyval.value) = temp;
			}

			logline();
			string str = "";
			str.append((yyvsp[0].value)->Getsname());
			str.append(" ");
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
		}
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 674 "1505047.y" /* yacc.c:1646  */
    {
	 		writelog("variable : ID LTHIRD expression RTHIRD");
			SymbolInfo* temp = variabletoarray((yyval.value),(yyvsp[-3].value),(yyvsp[-1].value));
			if (temp != 0){
				(yyval.value) = temp;
			}

			logline();
			string str = "";
			str.append((yyvsp[-3].value)->Getsname());
			str.append((yyvsp[-2].value)->Getsname());
			str.append((yyvsp[-1].value)->Getsname());
			str.append((yyvsp[0].value)->Getsname());
			str.append(" ");
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
	 	}
#line 2215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 694 "1505047.y" /* yacc.c:1646  */
    {
			writelog("expression : logic_expression");
			(yyval.value) = (yyvsp[0].value);

			logline();
			string str = "";
			str.append((yyvsp[0].value)->Getsname());
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
		}
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 705 "1505047.y" /* yacc.c:1646  */
    {
			writelog("expression : variable ASSIGNOP logic_expression");	
			SymbolInfo* temp = varassignlogic((yyval.value),(yyvsp[-2].value),(yyvsp[0].value));
			if (temp != 0){
				(yyval.value) = temp;
			}

			logline();
			string str = "";
			str.append((yyvsp[-2].value)->Getsname());
			str.append((yyvsp[-1].value)->Getsname());
			str.append((yyvsp[0].value)->Getsname());
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
		}
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 723 "1505047.y" /* yacc.c:1646  */
    {
			writelog("logic_expression : rel_expression");
			(yyval.value) = (yyvsp[0].value);

			logline();
			string str = "";
			str.append((yyvsp[0].value)->Getsname());
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
		}
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 734 "1505047.y" /* yacc.c:1646  */
    {
			writelog("logic_expression : rel_expression LOGICOP rel_expression");
			SymbolInfo* temp = rellogicrel((yyval.value),(yyvsp[-2].value),(yyvsp[-1].value),(yyvsp[0].value));
			if (temp != 0){
				(yyval.value) = temp;
			}

			logline();
			string str = "";
			str.append((yyvsp[-2].value)->Getsname());
			str.append((yyvsp[-1].value)->Getsname());
			str.append((yyvsp[0].value)->Getsname());
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
		}
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 752 "1505047.y" /* yacc.c:1646  */
    {
			writelog("rel_expression : simple_expression");
			(yyval.value) = (yyvsp[0].value);

			logline();
			string str = "";
			str.append((yyvsp[0].value)->Getsname());
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
		}
#line 2305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 763 "1505047.y" /* yacc.c:1646  */
    {
			writelog("rel_expression : simple_expression RELOP simple_expression");
			SymbolInfo* temp = simprelopsimp((yyval.value),(yyvsp[-2].value),(yyvsp[-1].value),(yyvsp[0].value));
			if (temp != 0){
				(yyval.value) = temp;
			}

			logline();
			string str = "";
			str.append((yyvsp[-2].value)->Getsname());
			str.append((yyvsp[-1].value)->Getsname());
			str.append((yyvsp[0].value)->Getsname());
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
		}
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 781 "1505047.y" /* yacc.c:1646  */
    {
			writelog("simple_expression : term");
			(yyval.value) = (yyvsp[0].value);

			logline();
			string str = "";
			str.append((yyvsp[0].value)->Getsname());
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
		}
#line 2342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 792 "1505047.y" /* yacc.c:1646  */
    {
			writelog("simple_expression : simple_expression ADDOP term");
			SymbolInfo* temp = simexpaddopterm((yyval.value),(yyvsp[-2].value),(yyvsp[-1].value),(yyvsp[0].value));
     		if (temp != 0){
				(yyval.value) = temp;
			}

			logline();
			string str = "";
			str.append((yyvsp[-2].value)->Getsname());
			str.append((yyvsp[-1].value)->Getsname());
			str.append((yyvsp[0].value)->Getsname());
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
		}
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 810 "1505047.y" /* yacc.c:1646  */
    {
			writelog("term : unary_expression");
			(yyval.value) = (yyvsp[0].value);

			logline();
			string str = "";
			str.append((yyvsp[0].value)->Getsname());
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
		}
#line 2379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 821 "1505047.y" /* yacc.c:1646  */
    {
     		writelog("term : term MULOP unary_expression");
     		SymbolInfo* temp = termmulopunary((yyval.value),(yyvsp[-2].value),(yyvsp[-1].value),(yyvsp[0].value));
     		if (temp != 0){
				(yyval.value) = temp;
			}

			logline();
			string str = "";
			str.append((yyvsp[-2].value)->Getsname());
			str.append((yyvsp[-1].value)->Getsname());
			str.append((yyvsp[0].value)->Getsname());
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
     	}
#line 2400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 839 "1505047.y" /* yacc.c:1646  */
    {
			writelog("unary_expression : ADDOP unary_expression");
			SymbolInfo* temp = addopuna((yyval.value),(yyvsp[-1].value),(yyvsp[0].value));
     		if (temp != 0){
				(yyval.value) = temp;
			}

			logline();
			string str = "";
			str.append((yyvsp[-1].value)->Getsname());
			str.append((yyvsp[0].value)->Getsname());
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
		}
#line 2420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 854 "1505047.y" /* yacc.c:1646  */
    {
			writelog("unary_expression : NOT unary_expression");
			SymbolInfo* temp = notuna((yyval.value),(yyvsp[0].value));
     		if (temp != 0){
				(yyval.value) = temp;
			}

			logline();
			string str = "";
			str.append((yyvsp[-1].value)->Getsname());
			str.append((yyvsp[0].value)->Getsname());
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
		}
#line 2440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 869 "1505047.y" /* yacc.c:1646  */
    {
			writelog("unary_expression : factor");
			(yyval.value) = (yyvsp[0].value);

			logline();
			string str = "";
			str.append((yyvsp[0].value)->Getsname());
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
		}
#line 2456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 882 "1505047.y" /* yacc.c:1646  */
    {	
			writelog("factor : variable");

			logline();
			string str = "";
			str.append((yyvsp[0].value)->Getsname());
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
		}
#line 2471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 892 "1505047.y" /* yacc.c:1646  */
    {
			writelog("factor : ID LPAREN argument_list RPAREN");
			SymbolInfo *temp = makenewemptySymInfo();
			temp = table.LookUp((yyvsp[-3].value)->Getsname());
			if(temp == NULL){
				string str = "";
				str.append("Undeclared Variable : ");
				str.append((yyvsp[-3].value)->Getsname());
				writeerr(str);
			}
			else{
				if(temp->funcrettype == "VOID"){
					string str = "";
					str.append((yyvsp[-3].value)->Getsname());
					str.append(" returns void.");
					writeerr(str);
				} 
				else{ 
					SymbolInfo *temp2 = makenewSymInfo((yyvsp[-3].value)->funcrettype);
					(yyval.value) = temp2;
				}
			}

			logline();
			string str = "";
			str.append((yyvsp[-3].value)->Getsname());
			str.append((yyvsp[-2].value)->Getsname());
			if(argset == 1){
				str.append((yyvsp[-1].value)->Getsname());
			}
			str.append((yyvsp[0].value)->Getsname());
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
		}
#line 2511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 927 "1505047.y" /* yacc.c:1646  */
    {	
			writelog("factor : LPAREN expression RPAREN"); 
			(yyval.value)=(yyvsp[-1].value);

			logline();
			string str = "";
			str.append((yyvsp[-2].value)->Getsname());
			str.append((yyvsp[-1].value)->Getsname());
			str.append((yyvsp[0].value)->Getsname());
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
		}
#line 2529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 940 "1505047.y" /* yacc.c:1646  */
    {	
			writelog("factor : CONST_INT");
			(yyvsp[0].value)->kindofVariable = "INT";
			(yyvsp[0].value)->kindofID = "VAR";
			(yyval.value) = (yyvsp[0].value);	

			logline();
			string str = "";
			str.append((yyvsp[0].value)->Getsname());
			str.append(" ");
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
		}
#line 2548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 954 "1505047.y" /* yacc.c:1646  */
    {	
			writelog("factor : CONST_FLOAT");
			(yyvsp[0].value)->kindofVariable = "FLOAT";
			(yyvsp[0].value)->kindofID = "VAR";
			(yyval.value) = (yyvsp[0].value);

			logline();
			string str = "";
			str.append((yyvsp[0].value)->Getsname());
			str.append(" ");
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();	
		}
#line 2567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 968 "1505047.y" /* yacc.c:1646  */
    {
			writelog("factor : variable INCOP");
			SymbolInfo * temp = varinc((yyvsp[-1].value));
			if(temp != 0) (yyval.value) = (yyvsp[-1].value);

			logline();
			string str = "";
			str.append((yyvsp[-1].value)->Getsname());
			str.append((yyvsp[0].value)->Getsname());
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
		}
#line 2585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 981 "1505047.y" /* yacc.c:1646  */
    {
			writelog("factor : variable DECOP");
			SymbolInfo * temp = vardec((yyvsp[-1].value));
			if(temp != 0) (yyval.value) = (yyvsp[-1].value);

			logline();
			string str = "";
			str.append((yyvsp[-1].value)->Getsname());
			str.append((yyvsp[0].value)->Getsname());
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
		}
#line 2603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 996 "1505047.y" /* yacc.c:1646  */
    {	
			writelog("argument_list : arguments");

			logline();
			string str = "";
			str.append((yyvsp[0].value)->Getsname());
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
		}
#line 2618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1006 "1505047.y" /* yacc.c:1646  */
    {	
			writelog("argument_list : empty");
			argset = 0;
		}
#line 2627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1012 "1505047.y" /* yacc.c:1646  */
    {	
			writelog("arguments : arguments COMMA logic_expression");

			logline();
			string str = "";
			str.append((yyvsp[-2].value)->Getsname());
			str.append((yyvsp[-1].value)->Getsname());
			str.append((yyvsp[0].value)->Getsname());
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
		}
#line 2644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1024 "1505047.y" /* yacc.c:1646  */
    {	
	      	writelog("arguments : logic_expression");

	      	logline();
			string str = "";
	      	str.append((yyvsp[0].value)->Getsname());
			printstr(str);
			(yyval.value)->Setsname(str);
			logline();
	    }
#line 2659 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2663 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1037 "1505047.y" /* yacc.c:1906  */

int main(int argc,char *argv[])
{

	if((yyin=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	logFile.open("1505047_log.txt");
	errorFile.open("1505047_err.txt");
	yyparse();
	errorFile << "Total Errors 	: " << semErrors << endl;
	errorFile << "Total Warnings 	: " << warnings << endl;

	logFile << "\t\tSymbol Table :" << endl;
	table.PrintAllinFile(logFile);

	logFile << "Total line 	: " << line_count << endl;
	logFile << "Total Errors 	: " << semErrors << endl;
	logFile << "Total Warnings 	: " << warnings << endl;

	logFile.close();
	errorFile.close();
	return 0;
}
