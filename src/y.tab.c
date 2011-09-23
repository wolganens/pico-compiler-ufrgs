
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
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "pico.y"

  /* Aqui, pode-se inserir qualquer codigo C necessario ah compilacao
   * final do parser. Sera copiado tal como esta no inicio do y.tab.c
   * gerado por Yacc.
   */
  #include <stdio.h>
  #include <stdlib.h>
  #include "node.h"


/* Line 189 of yacc.c  */
#line 84 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
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
     IDF = 258,
     INT = 259,
     DOUBLE = 260,
     REAL = 261,
     CHAR = 262,
     QUOTE = 263,
     LE = 264,
     GE = 265,
     EQ = 266,
     NE = 267,
     AND = 268,
     OR = 269,
     NOT = 270,
     IF = 271,
     THEN = 272,
     ELSE = 273,
     WHILE = 274,
     INT_LIT = 275,
     F_LIT = 276,
     END = 277,
     TRUE = 278,
     FALSE = 279,
     STRING = 280,
     CONST = 281,
     STR_LIT = 282,
     FOR = 283,
     NEXT = 284
   };
#endif
/* Tokens.  */
#define IDF 258
#define INT 259
#define DOUBLE 260
#define REAL 261
#define CHAR 262
#define QUOTE 263
#define LE 264
#define GE 265
#define EQ 266
#define NE 267
#define AND 268
#define OR 269
#define NOT 270
#define IF 271
#define THEN 272
#define ELSE 273
#define WHILE 274
#define INT_LIT 275
#define F_LIT 276
#define END 277
#define TRUE 278
#define FALSE 279
#define STRING 280
#define CONST 281
#define STR_LIT 282
#define FOR 283
#define NEXT 284




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 13 "pico.y"

  char* cadeia;
  struct _node * no;



/* Line 214 of yacc.c  */
#line 185 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 210 "y.tab.c"

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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   154

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNRULES -- Number of states.  */
#define YYNSTATES  115

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      23,    24,    15,    13,    20,    14,     2,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    22,    21,
      19,    17,    18,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    27,     2,    28,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,    26,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    15,    19,    21,    25,
      27,    29,    31,    33,    35,    37,    42,    47,    52,    57,
      61,    67,    70,    74,    78,    80,    82,    87,    89,    93,
      97,   101,   105,   109,   113,   115,   117,   119,   121,   126,
     128,   136,   144,   146,   150,   152,   154,   158,   162,   166,
     169,   173,   177,   181,   185,   189
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    55,    -1,    55,    -1,    49,    21,
      -1,    48,    49,    21,    -1,    51,    22,    50,    -1,     3,
      -1,     3,    20,    50,    -1,    52,    -1,    53,    -1,     4,
      -1,     5,    -1,     6,    -1,     7,    -1,     4,    23,    54,
      24,    -1,     5,    23,    54,    24,    -1,     6,    23,    54,
      24,    -1,     7,    23,    54,    24,    -1,    36,    22,    36,
      -1,    36,    22,    36,    20,    54,    -1,    56,    21,    -1,
      56,    21,    55,    -1,    57,    17,    59,    -1,    61,    -1,
       3,    -1,     3,    27,    58,    28,    -1,    59,    -1,    59,
      20,    58,    -1,    59,    13,    59,    -1,    59,    14,    59,
      -1,    59,    15,    59,    -1,    59,    16,    59,    -1,    23,
      59,    24,    -1,    36,    -1,    37,    -1,    57,    -1,    60,
      -1,     3,    23,    58,    24,    -1,    59,    -1,    32,    23,
      63,    24,    33,    55,    62,    -1,    35,    23,    63,    24,
      25,    55,    26,    -1,    38,    -1,    34,    55,    38,    -1,
      39,    -1,    40,    -1,    23,    63,    24,    -1,    63,    29,
      63,    -1,    63,    30,    63,    -1,    31,    63,    -1,    59,
      18,    59,    -1,    59,    19,    59,    -1,    59,     9,    59,
      -1,    59,    10,    59,    -1,    59,    11,    59,    -1,    59,
      12,    59,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    90,    90,    91,    94,    97,   101,   105,   106,   111,
     112,   115,   116,   117,   118,   121,   126,   131,   136,   142,
     147,   154,   157,   161,   163,   166,   168,   174,   175,   179,
     182,   185,   188,   191,   195,   197,   199,   201,   204,   210,
     211,   217,   225,   226,   231,   232,   234,   238,   241,   244,
     247,   250,   253,   256,   259,   262
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDF", "INT", "DOUBLE", "REAL", "CHAR",
  "QUOTE", "LE", "GE", "EQ", "NE", "'+'", "'-'", "'*'", "'/'", "'='",
  "'>'", "'<'", "','", "';'", "':'", "'('", "')'", "'{'", "'}'", "'['",
  "']'", "AND", "OR", "NOT", "IF", "THEN", "ELSE", "WHILE", "INT_LIT",
  "F_LIT", "END", "TRUE", "FALSE", "STRING", "CONST", "STR_LIT", "FOR",
  "NEXT", "$accept", "code", "declaracoes", "declaracao",
  "listadeclaracao", "tipo", "tipounico", "tipolista", "listadupla",
  "acoes", "comando", "lvalue", "listaexpr", "expr", "chamaproc",
  "enunciado", "fiminstcontrole", "expbool", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,    43,    45,    42,    47,    61,    62,    60,
      44,    59,    58,    40,    41,   123,   125,    91,    93,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    49,    50,    50,    51,
      51,    52,    52,    52,    52,    53,    53,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    61,
      61,    61,    62,    62,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     3,
       5,     2,     3,     3,     1,     1,     4,     1,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     4,     1,
       7,     7,     1,     3,     1,     1,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    25,    11,    12,    13,    14,     0,     0,     0,    34,
      35,     0,     0,     0,     0,     9,    10,     3,     0,    36,
      39,    37,    24,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,     1,     0,     2,     4,     0,    21,     0,
       0,     0,     0,     0,     0,    27,     0,     0,     0,     0,
       0,     0,    33,     0,     0,    44,    45,     0,     0,     0,
       5,     7,     6,    22,    23,    29,    30,    31,    32,    38,
       0,    26,     0,    15,    16,    17,    18,     0,     0,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,    19,    46,    52,    53,    54,    55,    50,    51,
       0,    47,    48,     0,     8,     0,     0,     0,    20,     0,
      42,    40,    41,     0,    43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    11,    12,    13,    62,    14,    15,    16,    48,    17,
      18,    29,    44,    20,    21,    22,   111,    58
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -28
static const yytype_int16 yypact[] =
{
      12,     6,   -13,    -3,     5,    13,    22,    18,    27,   -28,
     -28,    56,    12,    36,    38,   -28,   -28,   -28,    40,    50,
      91,   -28,   -28,    22,    22,    32,    32,    32,    32,   -28,
       8,     3,     3,   -28,    48,   -28,   -28,    73,    43,    22,
      22,    22,    22,    22,    62,   134,    59,    68,    67,    71,
      72,    75,   -28,     3,     3,   -28,   -28,   127,   -16,    53,
     -28,    77,   -28,   -28,    91,    91,    91,    91,    91,   -28,
      22,   -28,    66,   -28,   -28,   -28,   -28,   111,    64,    23,
      22,    22,    22,    22,    22,    22,    84,     3,     3,    83,
      73,   -28,    90,   -28,    91,    91,    91,    91,    91,    91,
      43,    23,    23,    43,   -28,    32,   -27,   102,   -28,    43,
     -28,   -28,   -28,    93,   -28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -28,   -28,   -28,   120,    44,   -28,   -28,   -28,   -24,   -11,
     -28,     0,   -19,    31,   -28,   -28,   -28,   -23
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      19,    35,    49,    50,    51,    46,     1,   109,    86,    59,
      25,   110,    19,    87,    88,     1,     2,     3,     4,     5,
      26,    40,    41,    42,    43,     1,    53,    63,    27,    23,
      78,    79,    52,    24,    54,     6,    28,    30,    19,     9,
      10,    31,    55,    56,     7,     6,     1,     8,     9,    10,
      32,    91,    87,    88,    45,    45,    33,    36,     9,    10,
      37,    38,    57,    57,   101,   102,     6,    39,    47,    60,
      64,    65,    66,    67,    68,     7,    61,    89,     8,     9,
      10,   108,    87,    88,    77,    57,    69,    71,    93,   106,
      72,    73,   107,    87,    88,    74,    75,    90,   113,    76,
      19,    45,    92,    19,    40,    41,    42,    43,   103,    19,
     105,    94,    95,    96,    97,    98,    99,   100,    57,    57,
      80,    81,    82,    83,    40,    41,    42,    43,   112,    84,
      85,   114,    34,     0,   104,    52,    80,    81,    82,    83,
      40,    41,    42,    43,     0,    84,    85,    40,    41,    42,
      43,     0,     0,     0,    70
};

static const yytype_int8 yycheck[] =
{
       0,    12,    26,    27,    28,    24,     3,    34,    24,    32,
      23,    38,    12,    29,    30,     3,     4,     5,     6,     7,
      23,    13,    14,    15,    16,     3,    23,    38,    23,    23,
      53,    54,    24,    27,    31,    23,    23,     6,    38,    36,
      37,    23,    39,    40,    32,    23,     3,    35,    36,    37,
      23,    70,    29,    30,    23,    24,     0,    21,    36,    37,
      22,    21,    31,    32,    87,    88,    23,    17,    36,    21,
      39,    40,    41,    42,    43,    32,     3,    24,    35,    36,
      37,   105,    29,    30,    53,    54,    24,    28,    24,   100,
      22,    24,   103,    29,    30,    24,    24,    20,   109,    24,
     100,    70,    36,   103,    13,    14,    15,    16,    25,   109,
      20,    80,    81,    82,    83,    84,    85,    33,    87,    88,
       9,    10,    11,    12,    13,    14,    15,    16,    26,    18,
      19,    38,    12,    -1,    90,    24,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    18,    19,    13,    14,    15,
      16,    -1,    -1,    -1,    20
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    23,    32,    35,    36,
      37,    47,    48,    49,    51,    52,    53,    55,    56,    57,
      59,    60,    61,    23,    27,    23,    23,    23,    23,    57,
      59,    23,    23,     0,    49,    55,    21,    22,    21,    17,
      13,    14,    15,    16,    58,    59,    58,    36,    54,    54,
      54,    54,    24,    23,    31,    39,    40,    59,    63,    63,
      21,     3,    50,    55,    59,    59,    59,    59,    59,    24,
      20,    28,    22,    24,    24,    24,    24,    59,    63,    63,
       9,    10,    11,    12,    18,    19,    24,    29,    30,    24,
      20,    58,    36,    24,    59,    59,    59,    59,    59,    59,
      33,    63,    63,    25,    50,    20,    55,    55,    54,    34,
      38,    62,    26,    55,    38
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

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

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

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
       `yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
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
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 90 "pico.y"
    { (yyval.no) = create_node( (yyloc).first_line, code_node, NULL, (yyvsp[(1) - (2)].no), (yyvsp[(2) - (2)].no), NULL);  syntax_tree = (yyval.no); }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 91 "pico.y"
    { (yyval.no) = (yyvsp[(1) - (1)].no); syntax_tree = (yyval.no); }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 94 "pico.y"
    {   Node *filho2 = create_node( (yylsp[(2) - (2)]).first_line, semicolon_node, (yyvsp[(2) - (2)].cadeia), NULL, NULL);
    			    	(yyval.no) = create_node( (yyloc).first_line, declaracoes_node, NULL, (yyvsp[(1) - (2)].no), filho2, NULL);  }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 97 "pico.y"
    {   Node* filho3 = create_node( (yylsp[(3) - (3)]).first_line, semicolon_node, (yyvsp[(3) - (3)].cadeia), NULL, NULL);
    			    		    (yyval.no) = create_node( (yylsp[(1) - (3)]).first_line, declaracoes_node, NULL, (yyvsp[(1) - (3)].no), (yyvsp[(2) - (3)].no), filho3, NULL);  }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 101 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, colon_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
					 (yyval.no) = create_node( (yyloc).first_line, declaracao_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 105 "pico.y"
    {   (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, idf_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL); }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 106 "pico.y"
    {   Node* filho1 = create_node( (yylsp[(1) - (3)]).first_line, idf_node, (yyvsp[(1) - (3)].cadeia), NULL, NULL);
					       Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, comma_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
					       (yyval.no) = create_node( (yyloc).first_line, listadeclaracao_node, NULL, filho1, filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 111 "pico.y"
    { (yyval.no) = (yyvsp[(1) - (1)].no); }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 112 "pico.y"
    { (yyval.no) = (yyvsp[(1) - (1)].no); }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 115 "pico.y"
    { (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, int_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL); }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 116 "pico.y"
    { (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, double_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL); }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 117 "pico.y"
    { (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, real_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL); }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 118 "pico.y"
    { (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, char_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL); }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 121 "pico.y"
    {  Node* filho1 = create_node( (yylsp[(1) - (4)]).first_line, int_node, (yyvsp[(1) - (4)].cadeia), NULL, NULL);
					 Node* filho2 = create_node( (yylsp[(2) - (4)]).first_line, rightbracket_node, (yyvsp[(2) - (4)].cadeia), NULL, NULL);
					 Node* filho4 = create_node( (yylsp[(4) - (4)]).first_line, leftbracket_node, (yyvsp[(4) - (4)].cadeia), NULL, NULL);
    			    		 (yyval.no) = create_node( (yyloc).first_line, tipolista_node, NULL, filho1, filho2, (yyvsp[(3) - (4)].no), filho4, NULL);  }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 126 "pico.y"
    {  Node* filho1 = create_node( (yylsp[(1) - (4)]).first_line, double_node, (yyvsp[(1) - (4)].cadeia), NULL, NULL);
					 Node* filho2 = create_node( (yylsp[(2) - (4)]).first_line, rightbracket_node, (yyvsp[(2) - (4)].cadeia), NULL, NULL);
					 Node* filho4 = create_node( (yylsp[(4) - (4)]).first_line, leftbracket_node, (yyvsp[(4) - (4)].cadeia), NULL, NULL);
    			    		 (yyval.no) = create_node( (yyloc).first_line, tipolista_node, NULL, filho1, filho2, (yyvsp[(3) - (4)].no), filho4, NULL);  }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 131 "pico.y"
    {  Node* filho1 = create_node( (yylsp[(1) - (4)]).first_line, real_node, (yyvsp[(1) - (4)].cadeia), NULL, NULL);
					 Node* filho2 = create_node( (yylsp[(2) - (4)]).first_line, rightbracket_node, (yyvsp[(2) - (4)].cadeia), NULL, NULL);
					 Node* filho4 = create_node( (yylsp[(4) - (4)]).first_line, leftbracket_node, (yyvsp[(4) - (4)].cadeia), NULL, NULL);
    			    		 (yyval.no) = create_node( (yyloc).first_line, tipolista_node, NULL, filho1, filho2, (yyvsp[(3) - (4)].no), filho4, NULL);  }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 136 "pico.y"
    {  Node* filho1 = create_node( (yylsp[(1) - (4)]).first_line, char_node, (yyvsp[(1) - (4)].cadeia), NULL, NULL);
					 Node* filho2 = create_node( (yylsp[(2) - (4)]).first_line, rightbracket_node, (yyvsp[(2) - (4)].cadeia), NULL, NULL);
					 Node* filho4 = create_node( (yylsp[(4) - (4)]).first_line, leftbracket_node, (yyvsp[(4) - (4)].cadeia), NULL, NULL);
    			    		 (yyval.no) = create_node( (yyloc).first_line, tipolista_node, NULL, filho1, filho2, (yyvsp[(3) - (4)].no), filho4, NULL);  }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 142 "pico.y"
    {  Node* filho1 = create_node( (yylsp[(1) - (3)]).first_line, int_lit_node, (yyvsp[(1) - (3)].cadeia), NULL, NULL);
					   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, colon_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
					   Node* filho3 = create_node( (yylsp[(3) - (3)]).first_line, int_lit_node, (yyvsp[(3) - (3)].cadeia), NULL, NULL);
    			    		   (yyval.no) = create_node( (yyloc).first_line, listadupla_node, NULL, filho1, filho2, filho3, NULL);  }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 147 "pico.y"
    {  Node* filho1 = create_node( (yylsp[(1) - (5)]).first_line, int_lit_node, (yyvsp[(1) - (5)].cadeia), NULL, NULL);
						   Node* filho2 = create_node( (yylsp[(2) - (5)]).first_line, colon_node, (yyvsp[(2) - (5)].cadeia), NULL, NULL);
					           Node* filho3 = create_node( (yylsp[(3) - (5)]).first_line, int_lit_node, (yyvsp[(3) - (5)].cadeia), NULL, NULL);
						   Node* filho4 = create_node( (yylsp[(4) - (5)]).first_line, comma_node, (yyvsp[(4) - (5)].cadeia), NULL, NULL);
    			    		           (yyval.no) = create_node( (yyloc).first_line, listadupla_node, NULL, filho1, filho2, filho3, filho4, (yyvsp[(5) - (5)].no), NULL);  }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 154 "pico.y"
    {	Node* filho2 = create_node( (yylsp[(2) - (2)]).first_line, semicolon_node, (yyvsp[(2) - (2)].cadeia), NULL, NULL);
    			(yyval.no) = create_node( (yyloc).first_line, acoes_node, NULL, (yyvsp[(1) - (2)].no), filho2, NULL);  }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 157 "pico.y"
    {  Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, semicolon_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
    			      (yyval.no) = create_node( (yyloc).first_line, acoes_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL); }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 161 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, attr_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				     (yyval.no) = create_node( (yyloc).first_line, comando_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 163 "pico.y"
    { (yyval.no) = (yyvsp[(1) - (1)].no); }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 166 "pico.y"
    { (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, idf_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL); }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 168 "pico.y"
    {  Node* filho1 = create_node( (yylsp[(1) - (4)]).first_line, idf_node, (yyvsp[(1) - (4)].cadeia), NULL, NULL);
			             Node* filho2 = create_node( (yylsp[(2) - (4)]).first_line, rightbracket3_node, (yyvsp[(2) - (4)].cadeia), NULL, NULL);
				     Node* filho4 = create_node( (yylsp[(4) - (4)]).first_line, leftbracket3_node, (yyvsp[(4) - (4)].cadeia), NULL, NULL);
    			    	     (yyval.no) = create_node( (yyloc).first_line, lvalue_node, NULL, filho1, filho2, (yyvsp[(3) - (4)].no), filho4, NULL);  }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 174 "pico.y"
    { (yyval.no) = (yyvsp[(1) - (1)].no); }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 175 "pico.y"
    {    Node* filho2 = create_node( (yylsp[(1) - (3)]).first_line, comma_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				     (yyval.no) = create_node( (yyloc).first_line, listaexpr_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 179 "pico.y"
    {  Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, plus_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
    			(yyval.no) = create_node( (yyloc).first_line, expr_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 182 "pico.y"
    {  Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, minus_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
    			(yyval.no) = create_node( (yyloc).first_line, expr_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL); }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 185 "pico.y"
    {  Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, mul_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
    			(yyval.no) = create_node( (yyloc).first_line, expr_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL); }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 188 "pico.y"
    {  Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, div_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
    			(yyval.no) = create_node( (yyloc).first_line, expr_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL); }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 191 "pico.y"
    {  Node* filho1 = create_node( (yylsp[(1) - (3)]).first_line, rightbracket_node, (yyvsp[(1) - (3)].cadeia), NULL, NULL);
			Node* filho3 = create_node( (yylsp[(3) - (3)]).first_line, leftbracket_node, (yyvsp[(3) - (3)].cadeia), NULL, NULL);
    			(yyval.no) = create_node( (yyloc).first_line, expr_node, NULL, filho1, (yyvsp[(2) - (3)].no), filho3, NULL); }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 195 "pico.y"
    { (yyval.no) = create_node((yyloc).first_line, int_lit_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL); }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 197 "pico.y"
    { (yyval.no) = create_node((yyloc).first_line, f_lit_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL); }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 199 "pico.y"
    { (yyval.no) = (yyvsp[(1) - (1)].no); }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 201 "pico.y"
    { (yyval.no) = (yyvsp[(1) - (1)].no); }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 204 "pico.y"
    {  Node* filho1 = create_node( (yylsp[(1) - (4)]).first_line, idf_node, (yyvsp[(1) - (4)].cadeia), NULL, NULL);
				      Node* filho2 = create_node( (yylsp[(2) - (4)]).first_line, rightbracket_node, (yyvsp[(2) - (4)].cadeia), NULL, NULL);
				      Node* filho4 = create_node( (yylsp[(4) - (4)]).first_line, leftbracket_node, (yyvsp[(4) - (4)].cadeia), NULL, NULL);
    			    	      (yyval.no) = create_node( (yyloc).first_line, chamaproc_node, NULL, filho1, filho2, (yyvsp[(3) - (4)].no), filho4, NULL);  }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 210 "pico.y"
    { (yyval.no) = (yyvsp[(1) - (1)].no) ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 211 "pico.y"
    {   Node* filho1 = create_node( (yylsp[(1) - (7)]).first_line, if_node, (yyvsp[(1) - (7)].cadeia), NULL, NULL);
								Node* filho2 = create_node( (yylsp[(2) - (7)]).first_line, rightbracket_node, (yyvsp[(2) - (7)].cadeia), NULL, NULL);
								Node* filho4 = create_node( (yylsp[(4) - (7)]).first_line, leftbracket_node, (yyvsp[(4) - (7)].cadeia), NULL, NULL);
								Node* filho5 = create_node( (yylsp[(5) - (7)]).first_line, then_node, (yyvsp[(5) - (7)].cadeia), NULL, NULL);
    			  (yyval.no) = create_node( (yyloc).first_line, enunciado_node, NULL, filho1, filho2, (yyvsp[(3) - (7)].no), filho4, filho5, (yyvsp[(6) - (7)].no), (yyvsp[(7) - (7)].no), NULL);  }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 217 "pico.y"
    {   Node* filho1 = create_node( (yylsp[(1) - (7)]).first_line, while_node, (yyvsp[(1) - (7)].cadeia), NULL, NULL);
						    Node* filho2 = create_node( (yylsp[(2) - (7)]).first_line, rightbracket_node, (yyvsp[(2) - (7)].cadeia), NULL, NULL);
 						    Node* filho4 = create_node( (yylsp[(4) - (7)]).first_line, leftbracket_node, (yyvsp[(4) - (7)].cadeia), NULL, NULL);
         					    Node* filho5 = create_node( (yylsp[(5) - (7)]).first_line, rightbracket2_node, (yyvsp[(5) - (7)].cadeia), NULL, NULL);
 						    Node* filho7 = create_node( (yylsp[(7) - (7)]).first_line, leftbracket2_node, (yyvsp[(7) - (7)].cadeia), NULL, NULL);
    	 (yyval.no) = create_node( (yyloc).first_line, enunciado_node, NULL, filho1, filho2, (yyvsp[(3) - (7)].no), filho4, filho5, (yyvsp[(6) - (7)].no), filho7, NULL);  }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 225 "pico.y"
    { (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, end_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 226 "pico.y"
    {   Node* filho1 = create_node( (yylsp[(1) - (3)]).first_line, else_node, (yyvsp[(1) - (3)].cadeia), NULL, NULL);
				       Node* filho3 = create_node( (yylsp[(3) - (3)]).first_line, end_node, (yyvsp[(3) - (3)].cadeia), NULL, NULL);
    			    	       (yyval.no) = create_node( (yyloc).first_line, fiminstcontrole_node, NULL, filho1, (yyvsp[(2) - (3)].no), filho3, NULL);  }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 231 "pico.y"
    { (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, true_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL); }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 232 "pico.y"
    { (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, false_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL); }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 234 "pico.y"
    {  Node* filho1 = create_node( (yylsp[(1) - (3)]).first_line, rightbracket_node, (yyvsp[(1) - (3)].cadeia), NULL, NULL);
       			      Node* filho3 = create_node( (yylsp[(3) - (3)]).first_line, leftbracket_node, (yyvsp[(3) - (3)].cadeia), NULL, NULL);  
    			      (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, filho1, (yyvsp[(2) - (3)].no), filho3, NULL); }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 238 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, and_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 241 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, or_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 244 "pico.y"
    {   Node* filho1 = create_node( (yylsp[(1) - (2)]).first_line, not_node, (yyvsp[(1) - (2)].cadeia), NULL, NULL);
    			    	       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, filho1, (yyvsp[(2) - (2)].no), NULL);  }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 247 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, greater_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 250 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, lower_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 253 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, le_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 256 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, ge_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 259 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, eq_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 262 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, ne_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;



/* Line 1455 of yacc.c  */
#line 1982 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
#line 265 "pico.y"


