
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 ".\\grammar.y"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parse_tree.h"
#include "praser.h"
#include "code_printer.h"
using namespace std;

extern char *yytext;
extern int column;
extern FILE * yyin;
extern FILE * yyout;
extern int yylineno;

class ParseTree *root;
int yylex(void);
void yyerror(const char*); 


/* Line 189 of yacc.c  */
#line 94 "grammar.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANT = 259,
     STRING_LITERAL = 260,
     SIZEOF = 261,
     CONSTANT_INT = 262,
     CONSTANT_FLOAT = 263,
     CONSTANT_CHAR = 264,
     PTR_OP = 265,
     INC_OP = 266,
     DEC_OP = 267,
     LEFT_OP = 268,
     RIGHT_OP = 269,
     LE_OP = 270,
     GE_OP = 271,
     EQ_OP = 272,
     NE_OP = 273,
     AND_OP = 274,
     OR_OP = 275,
     MUL_ASSIGN = 276,
     DIV_ASSIGN = 277,
     MOD_ASSIGN = 278,
     ADD_ASSIGN = 279,
     SUB_ASSIGN = 280,
     LEFT_ASSIGN = 281,
     RIGHT_ASSIGN = 282,
     AND_ASSIGN = 283,
     XOR_ASSIGN = 284,
     OR_ASSIGN = 285,
     TYPE_NAME = 286,
     TYPEDEF = 287,
     EXTERN = 288,
     STATIC = 289,
     AUTO = 290,
     REGISTER = 291,
     CHAR = 292,
     SHORT = 293,
     INT = 294,
     LONG = 295,
     SIGNED = 296,
     UNSIGNED = 297,
     FLOAT = 298,
     DOUBLE = 299,
     CONST = 300,
     VOLATILE = 301,
     VOID = 302,
     STRUCT = 303,
     UNION = 304,
     ENUM = 305,
     ELLIPSIS = 306,
     CASE = 307,
     DEFAULT = 308,
     IF = 309,
     ELSE = 310,
     SWITCH = 311,
     WHILE = 312,
     DO = 313,
     FOR = 314,
     GOTO = 315,
     CONTINUE = 316,
     BREAK = 317,
     RETURN = 318,
     BOOL = 319,
     COMPLEX = 320,
     IMAGINARY = 321,
     INLINE = 322,
     RESTRICT = 323
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 21 ".\\grammar.y"

	class ParseTree *pt;



/* Line 214 of yacc.c  */
#line 204 "grammar.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 216 "grammar.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1297

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  217
/* YYNRULES -- Number of states.  */
#define YYNSTATES  358

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   323

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,     2,     2,     2,    78,    71,     2,
      86,    87,    76,    75,    65,    74,    70,    77,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,    64,
      79,    67,    80,    83,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,    81,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    84,    82,    85,    73,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    88,
      89,    90,    91,    92
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    19,
      21,    26,    30,    35,    39,    43,    46,    49,    51,    55,
      57,    60,    63,    66,    69,    74,    76,    78,    80,    82,
      84,    86,    88,    93,    95,    99,   103,   107,   109,   113,
     117,   119,   123,   127,   129,   133,   137,   141,   145,   147,
     151,   155,   157,   161,   163,   167,   169,   173,   175,   179,
     181,   185,   187,   193,   195,   199,   201,   203,   205,   207,
     209,   211,   213,   215,   217,   219,   221,   223,   227,   229,
     232,   236,   238,   241,   243,   246,   248,   251,   253,   257,
     259,   263,   265,   267,   269,   271,   273,   275,   277,   279,
     281,   283,   285,   287,   289,   291,   293,   295,   297,   303,
     308,   311,   313,   315,   317,   320,   324,   327,   329,   332,
     334,   336,   340,   342,   345,   349,   354,   360,   363,   365,
     369,   371,   375,   377,   379,   382,   384,   386,   390,   395,
     399,   404,   409,   413,   415,   418,   421,   425,   427,   430,
     432,   436,   438,   442,   445,   448,   450,   452,   456,   458,
     461,   463,   465,   468,   472,   475,   479,   483,   488,   492,
     497,   500,   504,   508,   513,   515,   519,   524,   526,   530,
     532,   534,   536,   538,   540,   542,   546,   551,   555,   558,
     562,   564,   567,   569,   571,   573,   576,   582,   590,   596,
     602,   610,   617,   625,   632,   640,   644,   647,   650,   653,
     657,   659,   662,   664,   666,   671,   675,   677
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      94,     0,    -1,   155,    -1,     3,    -1,     7,    -1,     8,
      -1,     5,    -1,     9,    -1,    86,   114,    87,    -1,    95,
      -1,    96,    68,   114,    69,    -1,    96,    86,    87,    -1,
      96,    86,    97,    87,    -1,    96,    70,     3,    -1,    96,
      10,     3,    -1,    96,    11,    -1,    96,    12,    -1,   112,
      -1,    97,    65,   112,    -1,    96,    -1,    11,    98,    -1,
      12,    98,    -1,    99,   100,    -1,     6,    98,    -1,     6,
      86,   141,    87,    -1,    71,    -1,    76,    -1,    75,    -1,
      74,    -1,    73,    -1,    72,    -1,    98,    -1,    86,   141,
      87,   100,    -1,   100,    -1,   101,    76,   100,    -1,   101,
      77,   100,    -1,   101,    78,   100,    -1,   101,    -1,   102,
      75,   101,    -1,   102,    74,   101,    -1,   102,    -1,   103,
      13,   102,    -1,   103,    14,   102,    -1,   103,    -1,   104,
      79,   103,    -1,   104,    80,   103,    -1,   104,    15,   103,
      -1,   104,    16,   103,    -1,   104,    -1,   105,    17,   104,
      -1,   105,    18,   104,    -1,   105,    -1,   106,    71,   105,
      -1,   106,    -1,   107,    81,   106,    -1,   107,    -1,   108,
      82,   107,    -1,   108,    -1,   109,    19,   108,    -1,   109,
      -1,   110,    20,   109,    -1,   110,    -1,   110,    83,   114,
      66,   111,    -1,   111,    -1,    98,   113,   112,    -1,    67,
      -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,    25,
      -1,    26,    -1,    27,    -1,    28,    -1,    29,    -1,    30,
      -1,   112,    -1,   114,    65,   112,    -1,   111,    -1,   117,
      64,    -1,   117,   118,    64,    -1,   120,    -1,   120,   117,
      -1,   121,    -1,   121,   117,    -1,   132,    -1,   132,   117,
      -1,   119,    -1,   118,    65,   119,    -1,   133,    -1,   133,
      67,   144,    -1,    32,    -1,    33,    -1,    34,    -1,    35,
      -1,    36,    -1,    47,    -1,    37,    -1,    38,    -1,    39,
      -1,    40,    -1,    43,    -1,    44,    -1,    41,    -1,    42,
      -1,   122,    -1,   129,    -1,    31,    -1,   123,     3,    84,
     124,    85,    -1,   123,    84,   124,    85,    -1,   123,     3,
      -1,    48,    -1,    49,    -1,   125,    -1,   124,   125,    -1,
     126,   127,    64,    -1,   121,   126,    -1,   121,    -1,   132,
     126,    -1,   132,    -1,   128,    -1,   127,    65,   128,    -1,
     133,    -1,    66,   115,    -1,   133,    66,   115,    -1,    50,
      84,   130,    85,    -1,    50,     3,    84,   130,    85,    -1,
      50,     3,    -1,   131,    -1,   130,    65,   131,    -1,     3,
      -1,     3,    67,   115,    -1,    45,    -1,    46,    -1,   135,
     134,    -1,   134,    -1,     3,    -1,    86,   133,    87,    -1,
     134,    68,   112,    69,    -1,   134,    68,    69,    -1,   134,
      86,   137,    87,    -1,   134,    86,   140,    87,    -1,   134,
      86,    87,    -1,    76,    -1,    76,   136,    -1,    76,   135,
      -1,    76,   136,   135,    -1,   132,    -1,   136,   132,    -1,
     138,    -1,   138,    65,    51,    -1,   139,    -1,   138,    65,
     139,    -1,   117,   133,    -1,   117,   142,    -1,   117,    -1,
       3,    -1,   140,    65,     3,    -1,   126,    -1,   126,   142,
      -1,   135,    -1,   143,    -1,   135,   143,    -1,    86,   142,
      87,    -1,    68,    69,    -1,    68,   112,    69,    -1,   143,
      68,    69,    -1,   143,    68,   112,    69,    -1,    68,    76,
      69,    -1,   143,    68,    76,    69,    -1,    86,    87,    -1,
      86,   137,    87,    -1,   143,    86,    87,    -1,   143,    86,
     137,    87,    -1,   112,    -1,    84,   145,    85,    -1,    84,
     145,    65,    85,    -1,   144,    -1,   145,    65,   144,    -1,
     147,    -1,   148,    -1,   151,    -1,   152,    -1,   153,    -1,
     154,    -1,     3,    66,   146,    -1,    52,   115,    66,   146,
      -1,    53,    66,   146,    -1,    84,    85,    -1,    84,   149,
      85,    -1,   150,    -1,   149,   150,    -1,   116,    -1,   146,
      -1,    64,    -1,   114,    64,    -1,    54,    86,   114,    87,
     146,    -1,    54,    86,   114,    87,   146,    55,   146,    -1,
      56,    86,   114,    87,   146,    -1,    57,    86,   114,    87,
     146,    -1,    58,   146,    57,    86,   114,    87,    64,    -1,
      59,    86,   151,   151,    87,   146,    -1,    59,    86,   151,
     151,   114,    87,   146,    -1,    59,    86,   116,   151,    87,
     146,    -1,    59,    86,   116,   151,   114,    87,   146,    -1,
      60,     3,    64,    -1,    61,    64,    -1,    62,    64,    -1,
      63,    64,    -1,    63,   114,    64,    -1,   156,    -1,   155,
     156,    -1,   157,    -1,   116,    -1,   117,   133,   158,   148,
      -1,   117,   133,   148,    -1,   116,    -1,   158,   116,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    59,    59,    64,    67,    70,    73,    76,    79,    85,
      88,    91,    94,    97,   100,   103,   106,   112,   115,   121,
     124,   127,   130,   133,   136,   142,   145,   148,   151,   154,
     157,   163,   166,   172,   175,   178,   181,   187,   190,   193,
     199,   202,   205,   211,   214,   217,   220,   223,   229,   232,
     235,   241,   244,   250,   253,   259,   262,   268,   271,   277,
     280,   286,   289,   295,   298,   304,   307,   310,   313,   316,
     319,   322,   325,   328,   331,   334,   340,   343,   349,   355,
     358,   364,   367,   370,   373,   376,   379,   385,   388,   394,
     397,   403,   406,   409,   412,   415,   421,   424,   427,   430,
     433,   436,   439,   442,   445,   448,   451,   454,   460,   463,
     466,   472,   475,   481,   484,   490,   496,   499,   502,   505,
     511,   514,   520,   523,   526,   532,   535,   538,   544,   547,
     553,   556,   562,   565,   571,   574,   580,   583,   586,   589,
     592,   595,   598,   604,   607,   610,   613,   619,   622,   628,
     631,   637,   640,   646,   649,   652,   658,   661,   667,   670,
     676,   679,   682,   688,   691,   694,   697,   700,   703,   706,
     709,   712,   715,   718,   724,   727,   730,   736,   739,   745,
     748,   751,   754,   757,   760,   766,   769,   772,   778,   781,
     787,   790,   796,   799,   805,   808,   814,   817,   820,   826,
     829,   832,   835,   838,   841,   847,   850,   853,   856,   859,
     865,   868,   874,   877,   883,   886,   892,   895
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "CONSTANT_INT", "CONSTANT_FLOAT",
  "CONSTANT_CHAR", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP",
  "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN",
  "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "TYPE_NAME",
  "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR", "SHORT",
  "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "';'", "','", "':'", "'='", "'['", "']'",
  "'.'", "'&'", "'!'", "'~'", "'-'", "'+'", "'*'", "'/'", "'%'", "'<'",
  "'>'", "'^'", "'|'", "'?'", "'{'", "'}'", "'('", "')'", "BOOL",
  "COMPLEX", "IMAGINARY", "INLINE", "RESTRICT", "$accept", "Program",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "declaration_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,    59,    44,    58,    61,    91,    93,
      46,    38,    33,   126,    45,    43,    42,    47,    37,    60,
      62,    94,   124,    63,   123,   125,    40,    41,   319,   320,
     321,   322,   323
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    95,    95,    95,    95,    95,    95,    96,
      96,    96,    96,    96,    96,    96,    96,    97,    97,    98,
      98,    98,    98,    98,    98,    99,    99,    99,    99,    99,
      99,   100,   100,   101,   101,   101,   101,   102,   102,   102,
     103,   103,   103,   104,   104,   104,   104,   104,   105,   105,
     105,   106,   106,   107,   107,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   112,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   114,   114,   115,   116,
     116,   117,   117,   117,   117,   117,   117,   118,   118,   119,
     119,   120,   120,   120,   120,   120,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   122,   122,
     122,   123,   123,   124,   124,   125,   126,   126,   126,   126,
     127,   127,   128,   128,   128,   129,   129,   129,   130,   130,
     131,   131,   132,   132,   133,   133,   134,   134,   134,   134,
     134,   134,   134,   135,   135,   135,   135,   136,   136,   137,
     137,   138,   138,   139,   139,   139,   140,   140,   141,   141,
     142,   142,   142,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   144,   144,   144,   145,   145,   146,
     146,   146,   146,   146,   146,   147,   147,   147,   148,   148,
     149,   149,   150,   150,   151,   151,   152,   152,   152,   153,
     153,   153,   153,   153,   153,   154,   154,   154,   154,   154,
     155,   155,   156,   156,   157,   157,   158,   158
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       4,     3,     4,     3,     3,     2,     2,     1,     3,     1,
       2,     2,     2,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     5,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     2,
       3,     1,     2,     1,     2,     1,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     4,
       2,     1,     1,     1,     2,     3,     2,     1,     2,     1,
       1,     3,     1,     2,     3,     4,     5,     2,     1,     3,
       1,     3,     1,     1,     2,     1,     1,     3,     4,     3,
       4,     4,     3,     1,     2,     2,     3,     1,     2,     1,
       3,     1,     3,     2,     2,     1,     1,     3,     1,     2,
       1,     1,     2,     3,     2,     3,     3,     4,     3,     4,
       2,     3,     3,     4,     1,     3,     4,     1,     3,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     2,     3,
       1,     2,     1,     1,     1,     2,     5,     7,     5,     5,
       7,     6,     7,     6,     7,     3,     2,     2,     2,     3,
       1,     2,     1,     1,     4,     3,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   107,    91,    92,    93,    94,    95,    97,    98,    99,
     100,   103,   104,   101,   102,   132,   133,    96,   111,   112,
       0,     0,   213,     0,    81,    83,   105,     0,   106,    85,
       2,   210,   212,   127,     0,     1,   136,    79,   143,     0,
       0,    87,    89,   135,     0,    82,    84,   110,     0,    86,
     211,     0,   130,     0,   128,   147,   145,   144,     0,    80,
       0,     0,     0,   216,     0,   215,     0,     0,     0,   134,
       0,   117,     0,   113,     0,   119,     0,     0,     0,   125,
     148,   146,   137,    88,    89,     3,     6,     0,     4,     5,
       7,     0,     0,    25,    30,    29,    28,    27,    26,     0,
       0,     9,    19,    31,     0,    33,    37,    40,    43,    48,
      51,    53,    55,    57,    59,    61,    63,   174,    90,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   194,   188,    76,     0,   192,   193,   179,   180,     0,
     190,   181,   182,   183,   184,   217,   214,   139,     0,   156,
     142,   155,     0,   149,   151,     0,     0,   116,   109,   114,
       0,     0,   120,   122,   118,   126,    31,    78,   131,   129,
       0,    23,     0,    20,    21,   177,     0,     0,   158,     0,
       0,    15,    16,     0,     0,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    65,     0,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   206,   207,   208,
       0,   195,     0,   189,   191,   138,     0,     0,   153,   160,
     154,   161,   140,     0,     0,   141,   108,   123,   115,     0,
       0,     0,     0,   175,     8,     0,   160,   159,     0,    14,
       0,    13,    11,     0,    17,    64,    34,    35,    36,    39,
      38,    41,    42,    46,    47,    44,    45,    49,    50,    52,
      54,    56,    58,    60,     0,   185,     0,   187,     0,     0,
       0,     0,     0,     0,   205,   209,    77,   164,    26,     0,
     170,     0,     0,   162,     0,     0,   150,   152,   157,   121,
     124,    24,   176,   178,    32,    10,     0,    12,     0,   186,
       0,     0,     0,     0,     0,     0,   168,   165,   171,   163,
     166,    26,     0,   172,     0,    18,    62,   196,   198,   199,
       0,     0,     0,     0,     0,   169,   167,   173,     0,     0,
     203,     0,   201,     0,   197,   200,   204,   202
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    21,   101,   102,   263,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   133,
     197,   134,   168,    22,    64,    40,    41,    24,    25,    26,
      27,    72,    73,    74,   161,   162,    28,    53,    54,    29,
      58,    43,    44,    57,   301,   153,   154,   155,   179,   302,
     241,   118,   176,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    30,    31,    32,    66
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -183
static const yytype_int16 yypact[] =
{
    1247,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
      13,    22,  -183,    16,  1247,  1247,  -183,    24,  -183,  1247,
    1247,  -183,  -183,   -26,    60,  -183,  -183,  -183,   -10,    17,
      65,  -183,  1139,   101,    23,  -183,  -183,   -19,   495,  -183,
    -183,    60,    21,    -6,  -183,  -183,  -183,   -10,    28,  -183,
      17,   780,   432,  -183,    16,  -183,  1193,   810,   292,   101,
     495,   495,  1064,  -183,    92,   495,   109,   938,    60,  -183,
    -183,  -183,  -183,  -183,    54,  -183,  -183,   956,  -183,  -183,
    -183,   994,   994,  -183,  -183,  -183,  -183,  -183,  -183,   780,
     650,  -183,   112,   183,   938,  -183,   149,   111,   238,    40,
     236,     6,    46,    89,   154,    -8,  -183,  -183,  -183,   113,
     938,   115,   155,   161,   163,   698,   179,   185,   152,   225,
     826,  -183,  -183,  -183,   193,  -183,  -183,  -183,  -183,   516,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,   231,  -183,
    -183,   107,   217,   241,  -183,   -34,  1084,  -183,  -183,  -183,
     938,   197,  -183,   244,  -183,  -183,  -183,  -183,  -183,  -183,
     650,  -183,   938,  -183,  -183,  -183,   130,   -17,   156,   220,
     309,  -183,  -183,   938,   310,   285,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,   938,  -183,   938,
     938,   938,   938,   938,   938,   938,   938,   938,   938,   938,
     938,   938,   938,   938,   938,   938,   938,   938,   698,   248,
     698,   938,   938,   938,   258,   600,   252,  -183,  -183,  -183,
     199,  -183,   938,  -183,  -183,  -183,   862,   235,  -183,    10,
    -183,   128,  -183,  1213,   314,  -183,  -183,  -183,  -183,    92,
     938,   232,   726,  -183,  -183,  1013,   162,  -183,   938,  -183,
       7,  -183,  -183,   -14,  -183,  -183,  -183,  -183,  -183,   149,
     149,   111,   111,   238,   238,   238,   238,    40,    40,   236,
       6,    46,    89,   154,   221,  -183,   698,  -183,    -5,     4,
      25,   234,   902,   902,  -183,  -183,  -183,  -183,   249,   275,
    -183,   263,   266,   128,   918,   358,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,   938,  -183,   938,  -183,
     698,   698,   698,   938,   340,   375,  -183,  -183,  -183,  -183,
    -183,   286,   293,  -183,   267,  -183,  -183,   308,  -183,  -183,
      39,   698,    48,   698,   102,  -183,  -183,  -183,   698,   300,
    -183,   698,  -183,   698,  -183,  -183,  -183,  -183
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -183,  -183,  -183,  -183,  -183,   -59,  -183,   -94,    96,    97,
      11,    98,   153,   157,   159,   151,   158,  -183,   -73,   -60,
    -183,   -89,  -111,   -28,     0,  -183,   307,  -183,    90,  -183,
    -183,   298,   -57,   -54,  -183,   120,  -183,   324,   299,    14,
     -20,   -36,   -15,  -183,   -66,  -183,   133,  -183,   215,  -114,
    -182,   -93,  -183,  -120,  -183,     1,  -183,   270,  -175,  -183,
    -183,  -183,  -183,   380,  -183,  -183
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      23,   117,   152,    42,   167,   224,   175,   148,    69,   219,
     198,   177,   216,    36,    63,   159,    33,   157,   166,    36,
      36,   164,    35,    56,    45,    46,    36,    47,   171,    49,
      23,   244,   173,   174,   135,    15,    16,   240,   145,   117,
      84,   230,    81,    65,    84,   166,   178,   167,   232,   247,
     293,   316,    55,   245,   163,   206,   207,   303,    51,    78,
     232,   166,    75,    52,   257,    70,    38,   146,   151,   232,
     254,    80,   232,   317,   303,   217,   315,   212,   236,    79,
      37,   177,   320,   177,    75,    75,    75,   167,    77,    75,
     232,   321,    38,    38,   260,    36,   237,    34,   285,   159,
     287,   166,    39,    39,   232,   266,   267,   268,    48,    39,
      36,   135,   322,   232,    75,    82,   178,   324,   325,   208,
     209,    61,   180,   181,   182,   264,   349,   213,   284,    59,
      60,   238,   288,   289,   290,   351,   239,   265,    71,   310,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   160,   313,
      71,    71,    71,   256,   314,    71,   319,   232,    38,    67,
      75,   214,   296,   215,    78,   236,   299,   167,    39,   218,
     183,   220,   184,    38,    75,   202,   203,    68,   226,   353,
      71,   166,   117,   237,   165,   252,   304,   292,   185,   166,
     337,   338,   339,    69,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   305,   253,   227,   273,   274,   275,
     276,   350,   239,   352,   236,   199,   200,   201,   354,   163,
     236,   356,    38,   357,   340,   342,   344,   151,    36,   334,
     256,   221,   255,   151,   332,   336,    71,   222,   255,   223,
     196,   204,   205,   210,   211,   151,   335,   231,   232,   166,
      71,   248,   249,   295,   232,   225,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,   232,   318,    85,   228,
      86,    87,    88,    89,    90,   149,    91,    92,   269,   270,
     235,   271,   272,   236,   242,   151,   243,   258,   277,   278,
     250,    38,   259,   261,   286,   291,   294,   308,   326,   311,
     323,   237,   300,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    85,   327,    86,    87,    88,    89,    90,
     328,    91,    92,   329,   347,   345,    93,    94,    95,    96,
      97,    98,   346,   348,   355,   279,   282,    83,   156,   309,
     280,   100,   262,   281,   283,    76,   307,   169,    85,   150,
      86,    87,    88,    89,    90,   251,    91,    92,     0,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   234,
      50,    93,    94,    95,    96,    97,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,   341,     0,     0,
       0,     0,     0,     0,     0,   119,     0,    86,    87,    88,
      89,    90,     0,    91,    92,   333,    93,    94,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   343,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,   120,   121,   122,     0,   123,   124,
     125,   126,   127,   128,   129,   130,   131,     0,     0,     0,
       0,     0,     0,    93,    94,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,     0,    62,   132,   100,   119,
       0,    86,    87,    88,    89,    90,     1,    91,    92,     0,
       0,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,   120,   121,
     122,     0,   123,   124,   125,   126,   127,   128,   129,   130,
     131,     0,     0,     0,     0,     0,     0,    93,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,     0,
      62,   233,   100,    85,     0,    86,    87,    88,    89,    90,
       0,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     0,    85,     0,    86,    87,    88,    89,    90,
       0,    91,    92,     0,   131,     0,     0,     0,     0,     0,
       0,    93,    94,    95,    96,    97,    98,     0,     0,     0,
       0,     1,     0,     0,     0,     0,   100,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   119,     0,    86,    87,    88,    89,    90,     0,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,    94,    95,    96,    97,    98,     0,     0,    85,
       0,    86,    87,    88,    89,    90,   100,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,   121,   122,     0,   123,   124,   125,   126,   127,   128,
     129,   130,   131,     0,     0,     0,     0,     0,     0,    93,
      94,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,     0,    62,    85,   100,    86,    87,    88,    89,    90,
       0,    91,    92,     0,     0,     0,     0,    93,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,     0,
      99,   312,   100,    85,     0,    86,    87,    88,    89,    90,
       0,    91,    92,     0,     0,     0,     0,     0,     0,    85,
       0,    86,    87,    88,    89,    90,     0,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,    94,    95,    96,    97,    98,     0,     0,     0,
       0,     0,     0,     0,    99,    85,   100,    86,    87,    88,
      89,    90,     0,    91,    92,     0,     0,     0,     0,   147,
       0,    93,    94,    95,    96,    97,    98,     0,     0,     0,
     229,     0,     0,     0,     0,     0,   100,    93,    94,    95,
      96,    97,    98,     0,     0,    85,     0,    86,    87,    88,
      89,    90,   100,    91,    92,     0,     0,     0,     0,     0,
       0,    85,     0,    86,    87,    88,    89,    90,     0,    91,
      92,   297,     0,    93,    94,    95,    96,    97,   298,     0,
       0,    85,     0,    86,    87,    88,    89,    90,   100,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,    85,
       0,    86,    87,    88,    89,    90,   131,    91,    92,     0,
       0,     0,     0,    93,    94,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,     0,     0,   330,   100,    93,
      94,    95,    96,    97,   331,     0,     0,    85,     0,    86,
      87,    88,    89,    90,   100,    91,    92,     0,     0,    93,
      94,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,     0,     0,    93,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,    93,    94,    95,    96,    97,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     172,   236,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,     0,     0,     0,     1,     0,     0,     0,   255,
     300,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     1,     0,     0,     0,     0,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   158,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   246,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    62,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   306,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20
};

static const yytype_int16 yycheck[] =
{
       0,    61,    68,    23,    77,   125,    99,    67,    44,   120,
     104,   100,    20,     3,    42,    72,     3,    71,    77,     3,
       3,    75,     0,    38,    24,    25,     3,     3,    87,    29,
      30,    65,    91,    92,    62,    45,    46,   151,    66,    99,
      60,   130,    57,    42,    64,   104,   100,   120,    65,   160,
     225,    65,    38,    87,    74,    15,    16,   239,    84,    65,
      65,   120,    48,     3,   178,    84,    76,    66,    68,    65,
      87,    57,    65,    87,   256,    83,    69,    71,    68,    85,
      64,   170,    87,   172,    70,    71,    72,   160,    67,    75,
      65,    87,    76,    76,   183,     3,    86,    84,   218,   156,
     220,   160,    86,    86,    65,   199,   200,   201,    84,    86,
       3,   139,    87,    65,   100,    87,   170,   292,   293,    79,
      80,    67,    10,    11,    12,   185,    87,    81,   217,    64,
      65,   151,   221,   222,   223,    87,   151,   197,    48,   250,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    66,   252,
      70,    71,    72,   178,   258,    75,   286,    65,    76,    68,
     156,    82,   232,    19,    65,    68,   236,   250,    86,    66,
      68,    66,    70,    76,   170,    74,    75,    86,     3,    87,
     100,   250,   252,    86,    85,    65,    68,   225,    86,   258,
     320,   321,   322,   239,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    86,    85,    64,   206,   207,   208,
     209,   341,   237,   343,    68,    76,    77,    78,   348,   249,
      68,   351,    76,   353,   323,   324,   325,   237,     3,   305,
     255,    86,    86,   243,   304,   318,   156,    86,    86,    86,
      67,    13,    14,    17,    18,   255,   316,    64,    65,   318,
     170,    64,    65,    64,    65,    86,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    65,    66,     3,    64,
       5,     6,     7,     8,     9,     3,    11,    12,   202,   203,
      69,   204,   205,    68,    87,   305,    65,    87,   210,   211,
      66,    76,     3,     3,    66,    57,    64,     3,    69,    87,
      86,    86,    87,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,     3,    69,     5,     6,     7,     8,     9,
      87,    11,    12,    87,    87,    69,    71,    72,    73,    74,
      75,    76,    69,    55,    64,   212,   215,    60,    70,   249,
     213,    86,    87,   214,   216,    51,   243,    78,     3,    87,
       5,     6,     7,     8,     9,   170,    11,    12,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,   139,
      30,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    -1,    11,    12,    87,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,     3,
      -1,     5,     6,     7,     8,     9,    31,    11,    12,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    86,     3,    -1,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    86,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,     3,    -1,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    -1,    -1,     3,
      -1,     5,     6,     7,     8,     9,    86,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,     3,    86,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    86,     3,    -1,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,     3,    86,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,    69,
      -1,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      64,    -1,    -1,    -1,    -1,    -1,    86,    71,    72,    73,
      74,    75,    76,    -1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    86,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    -1,    11,
      12,    69,    -1,    71,    72,    73,    74,    75,    76,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    86,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,     5,     6,     7,     8,     9,    64,    11,    12,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    86,    71,
      72,    73,    74,    75,    76,    -1,    -1,     3,    -1,     5,
       6,     7,     8,     9,    86,    11,    12,    -1,    -1,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    86,
      87,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    31,    -1,    -1,    -1,    -1,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    94,   116,   117,   120,   121,   122,   123,   129,   132,
     155,   156,   157,     3,    84,     0,     3,    64,    76,    86,
     118,   119,   133,   134,   135,   117,   117,     3,    84,   117,
     156,    84,     3,   130,   131,   132,   135,   136,   133,    64,
      65,    67,    84,   116,   117,   148,   158,    68,    86,   134,
      84,   121,   124,   125,   126,   132,   130,    67,    65,    85,
     132,   135,    87,   119,   133,     3,     5,     6,     7,     8,
       9,    11,    12,    71,    72,    73,    74,    75,    76,    84,
      86,    95,    96,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   144,     3,
      52,    53,    54,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    85,   112,   114,   116,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   116,   148,    69,   112,     3,
      87,   117,   137,   138,   139,   140,   124,   126,    85,   125,
      66,   127,   128,   133,   126,    85,    98,   111,   115,   131,
      86,    98,    86,    98,    98,   144,   145,   114,   126,   141,
      10,    11,    12,    68,    70,    86,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    67,   113,   100,    76,
      77,    78,    74,    75,    13,    14,    15,    16,    79,    80,
      17,    18,    71,    81,    82,    19,    20,    83,    66,   115,
      66,    86,    86,    86,   146,    86,     3,    64,    64,    64,
     114,    64,    65,    85,   150,    69,    68,    86,   133,   135,
     142,   143,    87,    65,    65,    87,    85,   115,    64,    65,
      66,   141,    65,    85,    87,    86,   135,   142,    87,     3,
     114,     3,    87,    97,   112,   112,   100,   100,   100,   101,
     101,   102,   102,   103,   103,   103,   103,   104,   104,   105,
     106,   107,   108,   109,   114,   146,    66,   146,   114,   114,
     114,    57,   116,   151,    64,    64,   112,    69,    76,   112,
      87,   137,   142,   143,    68,    86,    51,   139,     3,   128,
     115,    87,    85,   144,   100,    69,    65,    87,    66,   146,
      87,    87,    87,    86,   151,   151,    69,    69,    87,    87,
      69,    76,   112,    87,   137,   112,   111,   146,   146,   146,
     114,    87,   114,    87,   114,    69,    69,    87,    55,    87,
     146,    87,   146,    87,   146,    64,   146,   146
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 59 ".\\grammar.y"
    {
    root = new ParseTree("Program", 1, (yyvsp[(1) - (1)].pt));
;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 64 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("primary_expression", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 67 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("primary_expression", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 70 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("primary_expression", 1 ,(yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 73 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("primary_expression", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 76 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("primary_expression", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 79 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("primary_expression", 3,  (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 85 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("postfix_expression", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 88 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("postfix_expression", 4, (yyvsp[(1) - (4)].pt), (yyvsp[(2) - (4)].pt), (yyvsp[(3) - (4)].pt), (yyvsp[(4) - (4)].pt));
    ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 91 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("postfix_expression", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt)); 
    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 94 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("postfix_expression", 4, (yyvsp[(1) - (4)].pt), (yyvsp[(2) - (4)].pt), (yyvsp[(3) - (4)].pt), (yyvsp[(4) - (4)].pt));
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 97 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("postfix_expression", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt)); 
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 100 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("postfix_expression", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 103 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("postfix_expression", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 106 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("postfix_expression", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 112 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("argument_experssion_list", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 115 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("argument_expression_list", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt) ,(yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 121 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("unary_expression", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 124 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("unary_expression", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 127 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("unary_expression", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 130 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("unary_expression", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 133 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("unary_expression", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 136 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("unary_expression", 4, (yyvsp[(1) - (4)].pt), (yyvsp[(2) - (4)].pt), (yyvsp[(3) - (4)].pt), (yyvsp[(4) - (4)].pt));
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 142 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("unary_operator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 145 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("unary_operator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 148 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("unary_operator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 151 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("unary_operator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 154 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("unary_operator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 157 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("unary_operator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 163 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("cast_expression", 1 ,(yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 166 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("cast_expression", 4, (yyvsp[(1) - (4)].pt), (yyvsp[(2) - (4)].pt), (yyvsp[(3) - (4)].pt), (yyvsp[(4) - (4)].pt));
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 172 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("multiplicative_expression", 1 ,(yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 175 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("multiplicative_expression", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 178 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("multiplicative_expression", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 181 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("multiplicative_expression", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 187 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("additive_expression", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 190 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("additive_expression", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 193 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("additive_expression", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 199 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("shift_expression", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 202 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("shift_expression", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 205 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("shift_expression", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 211 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("relational_expression", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 214 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("relational_expression", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 217 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("relational_expression", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 220 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("relational_expression", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 223 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("relational_expression", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 229 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("equality_expression", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 232 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("equality_expression", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 235 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("equality_expression", 1, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 241 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("and_expression", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 244 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("and_expression", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 250 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("exclusive_or_expression", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 253 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("exclusive_or_expression", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 259 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("inclusive_or_expression", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 262 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("inclusive_or_expression", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 268 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("logical_and_expression", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 271 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("logical_and_expression", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 277 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("logical_or_expression", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 280 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("logical_or_expression", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 286 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("conditional_expression", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 289 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("conditional_expression", 5, (yyvsp[(1) - (5)].pt), (yyvsp[(2) - (5)].pt), (yyvsp[(3) - (5)].pt), (yyvsp[(4) - (5)].pt), (yyvsp[(5) - (5)].pt));
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 295 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("assignment_expression", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 298 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("assignment_expression", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 304 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("assignment_operator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 307 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("assignment_operator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 310 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("assignment_operator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 313 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("assignment_operator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 316 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("assignment_operator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 319 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("assignment_operator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 322 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("assignment_operator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 325 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("assignment_operator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 328 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("assignment_operator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 331 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("assignment_operator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 334 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("assignment_operator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 340 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("expression", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 343 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("expression", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 349 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("constant_expression", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 355 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("declaration", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 358 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("declaration", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 364 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("declaration_specifer", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 367 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("declaration_specifer", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 370 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("declaration_specifer", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 373 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("declaration_specifer", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 376 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("declaration_specifer", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 379 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("declaration_specifer", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 385 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("init_declarator_list", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 388 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("init_declarator_list", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 394 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("init_declarator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 397 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("init_declarator", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 403 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("storage_class_specifier", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 406 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("storage_class_specifier", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 409 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("storage_class_specifier", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 412 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("storage_class_specifier", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 415 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("storage_class_specifier", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 421 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("type_specifier", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 424 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("type_specifier", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 427 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("type_specifier", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 430 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("type_specifier", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 433 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("type_specifier", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 436 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("type_specifier", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 439 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("type_specifier", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 442 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("type_specifier", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 445 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("type_specifier", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 448 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("type_specifier", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 451 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("type_specifier", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 454 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("type_specifier", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 460 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("struct_or_union_specifier", 5, (yyvsp[(1) - (5)].pt), (yyvsp[(2) - (5)].pt), (yyvsp[(3) - (5)].pt), (yyvsp[(4) - (5)].pt), (yyvsp[(5) - (5)].pt));
    ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 463 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("struct_or_union_specifier", 4, (yyvsp[(1) - (4)].pt), (yyvsp[(2) - (4)].pt), (yyvsp[(3) - (4)].pt), (yyvsp[(4) - (4)].pt));
    ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 466 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("struct_or_union_specifier", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 472 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("struct_or_union", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 475 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("struct_or_union", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 481 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("struct_declaration_list", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 484 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("struct_declaration_list", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 490 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("struct_declaration", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 496 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("specifier_qualifier_list", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 499 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("specifier_qualifier_list", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 502 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("specifier_qualifier_list", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 505 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("specifier_qualifier_list", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 511 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("struct_declarator_list", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 514 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("struct_declarator_list", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 520 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("struct_declarator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 523 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("struct_declarator", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 526 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("struct_declarator_list", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 532 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("enum_specifier", 4, (yyvsp[(1) - (4)].pt), (yyvsp[(2) - (4)].pt), (yyvsp[(3) - (4)].pt), (yyvsp[(4) - (4)].pt));
    ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 535 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("enum_specifier", 5, (yyvsp[(1) - (5)].pt), (yyvsp[(2) - (5)].pt), (yyvsp[(3) - (5)].pt), (yyvsp[(4) - (5)].pt) ,(yyvsp[(5) - (5)].pt));
    ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 538 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("enum_specifier", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 544 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("enum_list", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 547 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("enum_list", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 553 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("enumerator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 556 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("enumerator", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 562 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("type_qualifier", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 565 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("type_qualifier", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 571 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("declarator", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 574 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("declarator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 580 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("direct_declarator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 583 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("direct_declarator", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 586 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("direct_declarator", 4, (yyvsp[(1) - (4)].pt), (yyvsp[(2) - (4)].pt), (yyvsp[(3) - (4)].pt), (yyvsp[(4) - (4)].pt));
    ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 589 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("direct_declarator", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 592 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("direct_declarator", 4, (yyvsp[(1) - (4)].pt), (yyvsp[(2) - (4)].pt), (yyvsp[(3) - (4)].pt), (yyvsp[(4) - (4)].pt));
    ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 595 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("direct_declarator", 4, (yyvsp[(1) - (4)].pt), (yyvsp[(2) - (4)].pt), (yyvsp[(3) - (4)].pt), (yyvsp[(4) - (4)].pt));
    ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 598 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("direct_declarator", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 604 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("pointer", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 607 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("pointer", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 610 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("pointer", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 613 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("pointer", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 619 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("type_qualifier_list", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 622 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("type_qualifier_list", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 628 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("parameter_type_list", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 631 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("parameter_type_list", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 637 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("parameter_list", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 640 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("parameter_list", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 646 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("parameter_declaration", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 649 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("parameter_declaration", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 652 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("parameter_declaration", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 658 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("identifier_list", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 661 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("identifier_list", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 667 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("type_name", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 670 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("type_name", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 676 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("abstract_declarator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 679 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("abstract_declarator", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 682 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("abstract_declarator", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 688 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("direct_abstract_declarator", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 691 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("direct_abstract_declarator", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 694 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("direct_abstract_declarator", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 697 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("direct_abstract_declarator", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 700 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("direct_abstract_declarator", 4, (yyvsp[(1) - (4)].pt), (yyvsp[(2) - (4)].pt), (yyvsp[(3) - (4)].pt), (yyvsp[(4) - (4)].pt));
    ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 703 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("direct_abstract_declarator", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 706 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("direct_abstract_declarator", 4, (yyvsp[(1) - (4)].pt), (yyvsp[(2) - (4)].pt), (yyvsp[(3) - (4)].pt), (yyvsp[(4) - (4)].pt));
    ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 709 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("direct_abstract_declarator", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 712 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("direct_abstract_declarator", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 715 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("direct_abstract_declarator", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 718 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("direct_abstract_declarator", 4, (yyvsp[(1) - (4)].pt), (yyvsp[(2) - (4)].pt), (yyvsp[(3) - (4)].pt), (yyvsp[(4) - (4)].pt));
    ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 724 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("initializer", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 727 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("initializer", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 730 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("initializer", 4, (yyvsp[(1) - (4)].pt), (yyvsp[(2) - (4)].pt), (yyvsp[(3) - (4)].pt), (yyvsp[(4) - (4)].pt));
    ;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 736 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("initializer_list", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 739 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("initializer_list", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 745 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("statement", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 748 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("statement", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 751 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("statement", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 754 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("statement", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 757 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("statement", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 760 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("statement", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 766 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("labeled_statement", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 769 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("labeled_statement", 4, (yyvsp[(1) - (4)].pt), (yyvsp[(2) - (4)].pt), (yyvsp[(3) - (4)].pt), (yyvsp[(4) - (4)].pt));
    ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 772 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("labeled_statement", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 778 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("compound_statement", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 781 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("compound_statement", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 787 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("block_item_list", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 790 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("block_item_list", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 796 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("block_item", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 799 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("block_item", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 805 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("expression_statement", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 808 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("expression_statement", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 814 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("selection_statement", 5, (yyvsp[(1) - (5)].pt), (yyvsp[(2) - (5)].pt), (yyvsp[(3) - (5)].pt), (yyvsp[(4) - (5)].pt), (yyvsp[(5) - (5)].pt));
    ;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 817 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("selection_statement", 7, (yyvsp[(1) - (7)].pt), (yyvsp[(2) - (7)].pt), (yyvsp[(3) - (7)].pt), (yyvsp[(4) - (7)].pt), (yyvsp[(5) - (7)].pt), (yyvsp[(6) - (7)].pt), (yyvsp[(7) - (7)].pt));
    ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 820 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("selection_statement", 5, (yyvsp[(1) - (5)].pt), (yyvsp[(2) - (5)].pt), (yyvsp[(3) - (5)].pt), (yyvsp[(4) - (5)].pt), (yyvsp[(5) - (5)].pt));
    ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 826 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("iteration_statement", 5, (yyvsp[(1) - (5)].pt), (yyvsp[(2) - (5)].pt), (yyvsp[(3) - (5)].pt), (yyvsp[(4) - (5)].pt), (yyvsp[(5) - (5)].pt));
    ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 829 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("iteration_statement", 7, (yyvsp[(1) - (7)].pt), (yyvsp[(2) - (7)].pt), (yyvsp[(3) - (7)].pt), (yyvsp[(4) - (7)].pt), (yyvsp[(5) - (7)].pt), (yyvsp[(6) - (7)].pt), (yyvsp[(7) - (7)].pt));
    ;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 832 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("iteration_statement", 6, (yyvsp[(1) - (6)].pt), (yyvsp[(2) - (6)].pt), (yyvsp[(3) - (6)].pt), (yyvsp[(4) - (6)].pt), (yyvsp[(5) - (6)].pt), (yyvsp[(6) - (6)].pt));
    ;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 835 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("iteration_statement", 7, (yyvsp[(1) - (7)].pt), (yyvsp[(2) - (7)].pt), (yyvsp[(3) - (7)].pt), (yyvsp[(4) - (7)].pt), (yyvsp[(5) - (7)].pt), (yyvsp[(6) - (7)].pt), (yyvsp[(7) - (7)].pt));
    ;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 838 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("iteration_statement", 6, (yyvsp[(1) - (6)].pt), (yyvsp[(2) - (6)].pt), (yyvsp[(3) - (6)].pt), (yyvsp[(4) - (6)].pt), (yyvsp[(5) - (6)].pt), (yyvsp[(6) - (6)].pt));
    ;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 841 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("iteration_statement", 7, (yyvsp[(1) - (7)].pt), (yyvsp[(2) - (7)].pt), (yyvsp[(3) - (7)].pt), (yyvsp[(4) - (7)].pt), (yyvsp[(5) - (7)].pt), (yyvsp[(6) - (7)].pt), (yyvsp[(7) - (7)].pt));
    ;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 847 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("jump_statement", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 850 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("jump_statement", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 853 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("jump_statement", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 856 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("jump_statement", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 859 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("jump_statement", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 865 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("translation_unit", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 868 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("translation_unit", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 874 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("external_declaration", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 877 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("external_declaration", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 883 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("function_definition", 4, (yyvsp[(1) - (4)].pt), (yyvsp[(2) - (4)].pt), (yyvsp[(3) - (4)].pt), (yyvsp[(4) - (4)].pt));
    ;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 886 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("function_definition", 3, (yyvsp[(1) - (3)].pt), (yyvsp[(2) - (3)].pt), (yyvsp[(3) - (3)].pt));
    ;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 892 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("declaration_list", 1, (yyvsp[(1) - (1)].pt));
    ;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 895 ".\\grammar.y"
    {
        (yyval.pt) = new ParseTree("declaration_list", 2, (yyvsp[(1) - (2)].pt), (yyvsp[(2) - (2)].pt));
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 3913 "grammar.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 900 ".\\grammar.y"


void yyerror(char const *s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}


int main(int argc,char* argv[]) {

	yyin = fopen(argv[1],"r");
	
	yyparse();
	printf("\n");
    
    root->levalTrase();
    Praser praser = Praser(root);
	fclose(yyin);
	return 0;
}

