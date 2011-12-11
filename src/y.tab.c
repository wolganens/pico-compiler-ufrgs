
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
  #include "symbol_table.h"
  #include "labels.h"
  #include "lista.h"
  #include "inherited.h"

  int variable_desloc = 0;
  int temp_desloc = 0;

  int t_counter = 0;
  int l_counter = 0;
  
  extern symbol_t variable_table;
  extern symbol_t temp_table;


/* Line 189 of yacc.c  */
#line 97 "y.tab.c"

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
     PRINTF = 268,
     AND = 269,
     OR = 270,
     NOT = 271,
     IF = 272,
     THEN = 273,
     ELSE = 274,
     WHILE = 275,
     INT_LIT = 276,
     F_LIT = 277,
     END = 278,
     TRUE = 279,
     FALSE = 280,
     STRING = 281,
     CONST = 282,
     STR_LIT = 283,
     FOR = 284,
     NEXT = 285
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
#define PRINTF 268
#define AND 269
#define OR 270
#define NOT 271
#define IF 272
#define THEN 273
#define ELSE 274
#define WHILE 275
#define INT_LIT 276
#define F_LIT 277
#define END 278
#define TRUE 279
#define FALSE 280
#define STRING 281
#define CONST 282
#define STR_LIT 283
#define FOR 284
#define NEXT 285




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 26 "pico.y"

  char* cadeia;
  struct _node * no;



/* Line 214 of yacc.c  */
#line 200 "y.tab.c"
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
#line 225 "y.tab.c"

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
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNRULES -- Number of states.  */
#define YYNSTATES  120

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      24,    25,    16,    14,    21,    15,     2,    17,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    23,    22,
      20,    18,    19,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    28,     2,    29,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    15,    19,    21,    25,
      27,    29,    31,    33,    35,    37,    42,    47,    52,    57,
      61,    67,    70,    74,    78,    80,    82,    85,    89,    93,
      97,   101,   105,   109,   113,   115,   117,   119,   121,   126,
     128,   136,   144,   149,   151,   155,   157,   159,   163,   167,
     171,   174,   178,   182,   186,   190,   194
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    56,    -1,    56,    -1,    50,    22,
      -1,    49,    50,    22,    -1,    52,    23,    51,    -1,     3,
      -1,     3,    21,    51,    -1,    53,    -1,    54,    -1,     4,
      -1,     5,    -1,     6,    -1,     7,    -1,     4,    24,    55,
      25,    -1,     5,    24,    55,    25,    -1,     6,    24,    55,
      25,    -1,     7,    24,    55,    25,    -1,    37,    23,    37,
      -1,    37,    23,    37,    21,    55,    -1,    57,    22,    -1,
      57,    22,    56,    -1,    58,    18,    60,    -1,    62,    -1,
       3,    -1,    59,    29,    -1,    59,    21,    60,    -1,     3,
      28,    60,    -1,    60,    14,    60,    -1,    60,    15,    60,
      -1,    60,    16,    60,    -1,    60,    17,    60,    -1,    24,
      60,    25,    -1,    37,    -1,    38,    -1,    58,    -1,    61,
      -1,     3,    24,    59,    25,    -1,    60,    -1,    33,    24,
      64,    25,    34,    56,    63,    -1,    36,    24,    64,    25,
      26,    56,    27,    -1,    13,    24,    60,    25,    -1,    39,
      -1,    35,    56,    39,    -1,    40,    -1,    41,    -1,    24,
      64,    25,    -1,    64,    30,    64,    -1,    64,    31,    64,
      -1,    32,    64,    -1,    60,    19,    60,    -1,    60,    20,
      60,    -1,    60,     9,    60,    -1,    60,    10,    60,    -1,
      60,    11,    60,    -1,    60,    12,    60,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   111,   111,   115,   121,   125,   130,   140,   143,   149,
     150,   153,   160,   167,   174,   182,   192,   202,   212,   223,
     250,   279,   284,   291,   322,   325,   339,   397,   429,   440,
     458,   476,   494,   512,   521,   527,   529,   557,   560,   568,
     570,   580,   590,   603,   605,   613,   615,   617,   621,   624,
     627,   630,   633,   636,   639,   642,   645
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDF", "INT", "DOUBLE", "REAL", "CHAR",
  "QUOTE", "LE", "GE", "EQ", "NE", "PRINTF", "'+'", "'-'", "'*'", "'/'",
  "'='", "'>'", "'<'", "','", "';'", "':'", "'('", "')'", "'{'", "'}'",
  "'['", "']'", "AND", "OR", "NOT", "IF", "THEN", "ELSE", "WHILE",
  "INT_LIT", "F_LIT", "END", "TRUE", "FALSE", "STRING", "CONST", "STR_LIT",
  "FOR", "NEXT", "$accept", "code", "declaracoes", "declaracao",
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
     265,   266,   267,   268,    43,    45,    42,    47,    61,    62,
      60,    44,    59,    58,    40,    41,   123,   125,    91,    93,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    49,    49,    50,    51,    51,    52,
      52,    53,    53,    53,    53,    54,    54,    54,    54,    55,
      55,    56,    56,    57,    57,    58,    58,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    61,    62,
      62,    62,    62,    63,    63,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     3,
       5,     2,     3,     3,     1,     1,     2,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     4,     1,
       7,     7,     4,     1,     3,     1,     1,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    25,    11,    12,    13,    14,     0,     0,     0,     0,
      34,    35,     0,     0,     0,     0,     9,    10,     3,     0,
      36,     0,    39,    37,    24,     0,     0,     0,     0,     0,
       0,     0,    36,     0,     0,     0,     1,     0,     2,     4,
       0,    21,     0,     0,    26,     0,     0,     0,     0,     0,
       0,    28,     0,     0,     0,     0,     0,     0,    33,     0,
       0,    45,    46,     0,     0,     0,     5,     7,     6,    22,
      23,    27,    29,    30,    31,    32,    38,     0,    15,    16,
      17,    18,    42,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    47,    53,
      54,    55,    56,    51,    52,     0,    48,    49,     0,     8,
       0,     0,     0,    20,     0,    43,    40,    41,     0,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    12,    13,    14,    68,    15,    16,    17,    53,    18,
      19,    32,    21,    22,    23,    24,   116,    64
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -34
static const yytype_int16 yypact[] =
{
      94,    82,    -6,     1,     9,    10,    12,    11,    26,    29,
     -34,   -34,    24,    94,   -10,    36,   -34,   -34,   -34,    46,
      74,   -18,    63,   -34,   -34,    91,    11,    58,    58,    58,
      58,    11,   -34,     5,    14,    14,   -34,    81,   -34,   -34,
     101,    34,    11,    11,   -34,    11,    11,    11,    11,    38,
      88,    63,    89,    92,    95,    96,    97,    48,   -34,    14,
      14,   -34,   -34,   136,   -15,    44,   -34,    98,   -34,   -34,
      63,    63,   -11,   -11,   -34,   -34,   -34,    79,   -34,   -34,
     -34,   -34,   -34,   124,    51,   -34,    11,    11,    11,    11,
      11,    11,    90,    14,    14,    99,   101,   102,   -34,    63,
      63,    63,    63,    63,    63,    34,   -34,   107,    34,   -34,
      58,    76,   115,   -34,    34,   -34,   -34,   -34,    87,   -34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -34,   -34,   -34,   116,    32,   -34,   -34,   -34,   -21,   -12,
     -34,     0,   129,    -3,   -34,   -34,   -34,   -33
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      20,    38,    65,    43,    33,    47,    48,    54,    55,    56,
      92,    44,    39,    20,     1,    93,    94,     1,    27,    45,
      46,    47,    48,    51,    36,    28,    84,    85,    57,    69,
      58,    63,    63,    29,    30,     7,    31,     1,    59,    70,
      71,    20,    72,    73,    74,    75,    60,     6,    10,    11,
      34,    10,    11,    35,    61,    62,    83,    63,     7,    40,
     106,   107,    45,    46,    47,    48,    26,     8,    41,    95,
       9,    10,    11,    82,    93,    94,    98,    45,    46,    47,
      48,    93,    94,    99,   100,   101,   102,   103,   104,   113,
      63,    63,    42,   111,    49,    52,   112,     1,     2,     3,
       4,     5,   118,    66,    67,    20,    25,     6,    20,    43,
      26,   114,    77,    76,    20,   115,    97,    78,     7,    96,
      79,    80,    81,   110,   105,   108,   119,     8,   109,    37,
       9,    10,    11,    86,    87,    88,    89,    93,    45,    46,
      47,    48,   117,    90,    91,    86,    87,    88,    89,    58,
      45,    46,    47,    48,    50,    90,    91
};

static const yytype_uint8 yycheck[] =
{
       0,    13,    35,    21,     7,    16,    17,    28,    29,    30,
      25,    29,    22,    13,     3,    30,    31,     3,    24,    14,
      15,    16,    17,    26,     0,    24,    59,    60,    31,    41,
      25,    34,    35,    24,    24,    24,    24,     3,    24,    42,
      43,    41,    45,    46,    47,    48,    32,    13,    37,    38,
      24,    37,    38,    24,    40,    41,    59,    60,    24,    23,
      93,    94,    14,    15,    16,    17,    28,    33,    22,    25,
      36,    37,    38,    25,    30,    31,    25,    14,    15,    16,
      17,    30,    31,    86,    87,    88,    89,    90,    91,   110,
      93,    94,    18,   105,     3,    37,   108,     3,     4,     5,
       6,     7,   114,    22,     3,   105,    24,    13,   108,    21,
      28,    35,    23,    25,   114,    39,    37,    25,    24,    21,
      25,    25,    25,    21,    34,    26,    39,    33,    96,    13,
      36,    37,    38,     9,    10,    11,    12,    30,    14,    15,
      16,    17,    27,    19,    20,     9,    10,    11,    12,    25,
      14,    15,    16,    17,    25,    19,    20
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    13,    24,    33,    36,
      37,    38,    48,    49,    50,    52,    53,    54,    56,    57,
      58,    59,    60,    61,    62,    24,    28,    24,    24,    24,
      24,    24,    58,    60,    24,    24,     0,    50,    56,    22,
      23,    22,    18,    21,    29,    14,    15,    16,    17,     3,
      59,    60,    37,    55,    55,    55,    55,    60,    25,    24,
      32,    40,    41,    60,    64,    64,    22,     3,    51,    56,
      60,    60,    60,    60,    60,    60,    25,    23,    25,    25,
      25,    25,    25,    60,    64,    64,     9,    10,    11,    12,
      19,    20,    25,    30,    31,    25,    21,    37,    25,    60,
      60,    60,    60,    60,    60,    34,    64,    64,    26,    51,
      21,    56,    56,    55,    35,    39,    63,    27,    56,    39
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
#line 111 "pico.y"
    {	(yyval.no) = create_node( (yyloc).first_line, code_node, NULL, (yyvsp[(1) - (2)].no), (yyvsp[(2) - (2)].no), NULL);
	           		syntax_tree = (yyval.no); 
	   			cat_tac(&((yyval.no)->code), &((yyvsp[(2) - (2)].no)->code));
	 		}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 115 "pico.y"
    { 
    				(yyval.no) = (yyvsp[(1) - (1)].no);
    				syntax_tree = (yyval.no);
    			}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 121 "pico.y"
    {   Node *filho2 = create_node( (yylsp[(2) - (2)]).first_line, semicolon_node, (yyvsp[(2) - (2)].cadeia), NULL, NULL);
    			    	(yyval.no) = create_node( (yyloc).first_line, declaracoes_node, NULL, (yyvsp[(1) - (2)].no), filho2, NULL);  
			    }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 125 "pico.y"
    {   	Node* filho3 = create_node( (yylsp[(3) - (3)]).first_line, semicolon_node, (yyvsp[(3) - (3)].cadeia), NULL, NULL);
    		    				(yyval.no) = create_node( (yylsp[(1) - (3)]).first_line, declaracoes_node, NULL, (yyvsp[(1) - (3)].no), (yyvsp[(2) - (3)].no), filho3, NULL);  
					}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 130 "pico.y"
    {	Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, colon_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
					(yyval.no) = create_node( (yyloc).first_line, declaracao_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);

					if ((yyvsp[(1) - (3)].no)->variable->extra == NULL)	//simple variable
						do_variable_insertion ((yyval.no), &variable_table, (yyvsp[(1) - (3)].no)->variable);
					else					//array
						do_vector_insertion ((yyval.no), &variable_table, (yyvsp[(1) - (3)].no)->variable);
					}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 140 "pico.y"
    {  (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, idf_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL);	}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 143 "pico.y"
    {	Node* filho1 = create_node( (yylsp[(1) - (3)]).first_line, idf_node, (yyvsp[(1) - (3)].cadeia), NULL, NULL);        					
						Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, comma_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);               					
						(yyval.no) = create_node( (yyloc).first_line, listadeclaracao_node, NULL, filho1, filho2, (yyvsp[(3) - (3)].no), NULL);
					 }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 149 "pico.y"
    { (yyval.no) = (yyvsp[(1) - (1)].no); }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 150 "pico.y"
    { (yyval.no) = (yyvsp[(1) - (1)].no); }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 153 "pico.y"
    {  	(yyval.no) = create_node((yylsp[(1) - (1)]).first_line, int_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL);
	      		(yyval.no)->type = int_node;
	      		
	      		(yyval.no)->variable = (entry_t *) malloc(sizeof(entry_t));
	      		(yyval.no)->variable->type = int_node;
	  		(yyval.no)->variable->size = INT_SIZE; }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 160 "pico.y"
    {	(yyval.no) = create_node((yylsp[(1) - (1)]).first_line, double_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL);
        		(yyval.no)->type = double_node;
        		
		   	(yyval.no)->variable = (entry_t *) malloc(sizeof(entry_t));
	      		(yyval.no)->variable->type = double_node;
	  		(yyval.no)->variable->size = DOUBLE_SIZE; }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 167 "pico.y"
    {	(yyval.no) = create_node((yylsp[(1) - (1)]).first_line, real_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL);
         		(yyval.no)->type = real_node;
         		
	      		(yyval.no)->variable = (entry_t *) malloc(sizeof(entry_t));
	      		(yyval.no)->variable->type = real_node;
	  		(yyval.no)->variable->size = REAL_SIZE; }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 174 "pico.y"
    { 	(yyval.no) = create_node((yylsp[(1) - (1)]).first_line, char_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL);
         		(yyval.no)->type = char_node;
         		
	      		(yyval.no)->variable = (entry_t *) malloc(sizeof(entry_t));
	      		(yyval.no)->variable->type = char_node;
	  		(yyval.no)->variable->size = CHAR_SIZE; }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 182 "pico.y"
    { Node* filho1 = create_node( (yylsp[(1) - (4)]).first_line, int_node, (yyvsp[(1) - (4)].cadeia), NULL, NULL);
 					Node* filho2 = create_node( (yylsp[(2) - (4)]).first_line, leftbracket_node, (yyvsp[(2) - (4)].cadeia), NULL, NULL);
					Node* filho4 = create_node( (yylsp[(4) - (4)]).first_line, rightbracket_node, (yyvsp[(4) - (4)].cadeia), NULL, NULL);
    		 			(yyval.no) = create_node( (yyloc).first_line, tipolista_node, NULL, filho1, filho2, (yyvsp[(3) - (4)].no), filho4, NULL);  
    			    		 				
    		 			(yyval.no)->variable = (yyvsp[(3) - (4)].no)->variable;
    		 			(yyval.no)->variable->type = int_node;
    		 			(yyval.no)->variable->size *= INT_SIZE;  		 				
    		 		 	}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 192 "pico.y"
    { Node* filho1 = create_node( (yylsp[(1) - (4)]).first_line, double_node, (yyvsp[(1) - (4)].cadeia), NULL, NULL);
 					Node* filho2 = create_node( (yylsp[(2) - (4)]).first_line, leftbracket_node, (yyvsp[(2) - (4)].cadeia), NULL, NULL);
 					Node* filho4 = create_node( (yylsp[(4) - (4)]).first_line, rightbracket_node, (yyvsp[(4) - (4)].cadeia), NULL, NULL);
    		 			(yyval.no) = create_node( (yyloc).first_line, tipolista_node, NULL, filho1, filho2, (yyvsp[(3) - (4)].no), filho4, NULL); 

    		 			(yyval.no)->variable = (yyvsp[(3) - (4)].no)->variable;
	 				(yyval.no)->variable->type = double_node;
	 				(yyval.no)->variable->size *= DOUBLE_SIZE; 
    		 			}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 202 "pico.y"
    { Node* filho1 = create_node( (yylsp[(1) - (4)]).first_line, real_node, (yyvsp[(1) - (4)].cadeia), NULL, NULL);
 					Node* filho2 = create_node( (yylsp[(2) - (4)]).first_line, leftbracket_node, (yyvsp[(2) - (4)].cadeia), NULL, NULL);
 					Node* filho4 = create_node( (yylsp[(4) - (4)]).first_line, rightbracket_node, (yyvsp[(4) - (4)].cadeia), NULL, NULL);
    		 			(yyval.no) = create_node( (yyloc).first_line, tipolista_node, NULL, filho1, filho2, (yyvsp[(3) - (4)].no), filho4, NULL);
    			    		 			
    		 			(yyval.no)->variable = (yyvsp[(3) - (4)].no)->variable;
	 				(yyval.no)->variable->type = real_node;
	 				(yyval.no)->variable->size *= REAL_SIZE; 
    		 			}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 212 "pico.y"
    { Node* filho1 = create_node( (yylsp[(1) - (4)]).first_line, char_node, (yyvsp[(1) - (4)].cadeia), NULL, NULL);
 					Node* filho2 = create_node( (yylsp[(2) - (4)]).first_line, leftbracket_node, (yyvsp[(2) - (4)].cadeia), NULL, NULL);
					Node* filho4 = create_node( (yylsp[(4) - (4)]).first_line, rightbracket_node, (yyvsp[(4) - (4)].cadeia), NULL, NULL);
    		 			(yyval.no) = create_node( (yyloc).first_line, tipolista_node, NULL, filho1, filho2, (yyvsp[(3) - (4)].no), filho4, NULL);
    		 			
    		 			(yyval.no)->variable = (yyvsp[(3) - (4)].no)->variable;
	 				(yyval.no)->variable->type = char_node;
	 				(yyval.no)->variable->size *= CHAR_SIZE; 
	 				}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 223 "pico.y"
    {  	Node* filho1 = create_node( (yylsp[(1) - (3)]).first_line, int_lit_node, (yyvsp[(1) - (3)].cadeia), NULL, NULL);
						Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, colon_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
	   					Node* filho3 = create_node( (yylsp[(3) - (3)]).first_line, int_lit_node, (yyvsp[(3) - (3)].cadeia), NULL, NULL);
	    		  			(yyval.no) = create_node( (yyloc).first_line, listadupla_node, NULL, filho1, filho2, filho3, NULL);
	    		  			   		  			
	    		  			(yyval.no)->variable = (entry_t *) malloc(sizeof(entry_t));
	    		  			(yyval.no)->variable->extra = (vector_info *) malloc(sizeof(vector_info));
	    		  			
	    		  			(yyval.no)->variable->extra->ndim = 1;
	    		  			
	    		  			(yyval.no)->variable->extra->limits = (limNode *) malloc(sizeof(limNode));    			    		  			
	    		  			
	    		  			int inf_lim = (yyval.no)->variable->extra->limits->inf_lim = atoi((yyvsp[(1) - (3)].cadeia));
				  		int sup_lim = (yyval.no)->variable->extra->limits->sup_lim = atoi((yyvsp[(3) - (3)].cadeia));
	    		  			    		  			
	    		  			(yyval.no)->variable->extra->limits->next = NULL;
	    		  			
	    		  			(yyval.no)->variable->size += sup_lim - inf_lim + 1;
				  			
			  			if (sup_lim < inf_lim)
			  			{
							printf("ERROR(%d). Ilegal array limits.\n", (yyval.no)->num_line);
							exit(1);
				      		}
				      		
    			    		 }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 250 "pico.y"
    {  	Node* filho1 = create_node( (yylsp[(1) - (5)]).first_line, int_lit_node, (yyvsp[(1) - (5)].cadeia), NULL, NULL);
   							Node* filho2 = create_node( (yylsp[(2) - (5)]).first_line, colon_node, (yyvsp[(2) - (5)].cadeia), NULL, NULL);
   							Node* filho3 = create_node( (yylsp[(3) - (5)]).first_line, int_lit_node, (yyvsp[(3) - (5)].cadeia), NULL, NULL);
   							Node* filho4 = create_node( (yylsp[(4) - (5)]).first_line, comma_node, (yyvsp[(4) - (5)].cadeia), NULL, NULL);
			    		           	
			    		           	(yyval.no) = create_node( (yyloc).first_line, listadupla_node, NULL, filho1, filho2, filho3, filho4, (yyvsp[(5) - (5)].no), NULL);
			    		           			    		           	
			    		           	(yyval.no)->variable = (yyvsp[(5) - (5)].no)->variable;
				  			(yyval.no)->variable->extra->ndim += 1;
				  			
							limNode *new_limit = (limNode *) malloc(sizeof(limNode));
							
							int inf_lim = new_limit->inf_lim= atoi((yyvsp[(1) - (5)].cadeia));
				  			int sup_lim = new_limit->sup_lim = atoi((yyvsp[(3) - (5)].cadeia));
							new_limit->next = NULL;							
							
							new_limit->next = (yyval.no)->variable->extra->limits;
							(yyval.no)->variable->extra->limits = new_limit;
				  			
				  			(yyval.no)->variable->size *= sup_lim - inf_lim + 1;
				  			
				  			if (sup_lim < inf_lim)
				  			{
								printf("ERROR(%d). Ilegal array limits.\n", (yyval.no)->num_line);
								exit(1);
					      		}
					      	}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 279 "pico.y"
    {	Node* filho2 = create_node( (yylsp[(2) - (2)]).first_line, semicolon_node, (yyvsp[(2) - (2)].cadeia), NULL, NULL);
			(yyval.no) = create_node( (yyloc).first_line, acoes_node, NULL, (yyvsp[(1) - (2)].no), filho2, NULL);
			cat_tac(&((yyval.no)->code), &((yyvsp[(1) - (2)].no)->code));
		    }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 284 "pico.y"
    { 	Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, semicolon_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
	      		  	(yyval.no) = create_node( (yyloc).first_line, acoes_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL); 
	     			cat_tac(&((yyvsp[(1) - (3)].no)->code), &((yyvsp[(3) - (3)].no)->code));
				cat_tac(&((yyval.no)->code), &((yyvsp[(1) - (3)].no)->code));				
		    	   }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 291 "pico.y"
    {	Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, attr_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
			     	(yyval.no) = create_node( (yyloc).first_line, comando_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);

				if ((yyvsp[(1) - (3)].no)->array == NULL)
				{		     
					printf("AQUI");				     
				     entry_t * variable;

				     if (((variable) = lookup(variable_table, (yyvsp[(1) - (3)].no)->local)) == NULL)
				     { 
						printf("ERROR(%d). The variable %s was not declared.\n", (yyval.no)->num_line, (yyval.no)->lexeme);
						exit(1);
				     }
					  
				     struct tac* new_instruction = create_inst_tac(variable->name, (yyvsp[(3) - (3)].no)->local, "", "");
				     append_inst_tac(&((yyvsp[(3) - (3)].no)->code), new_instruction);

				     cat_tac(&((yyval.no)->code), &((yyvsp[(3) - (3)].no)->code));				     
				}
				else
				{
					char *indirect_access = (char *) malloc(sizeof(char)*30);
					sprintf(indirect_access, "%s(%s)", (yyvsp[(1) - (3)].no)->local, (yyvsp[(1) - (3)].no)->array);
					
					struct tac *instruction1 = create_inst_tac(indirect_access, (yyvsp[(3) - (3)].no)->local, "", "");
					append_inst_tac(&((yyvsp[(3) - (3)].no)->code), instruction1);

					cat_tac(&((yyvsp[(1) - (3)].no)->code), &((yyvsp[(3) - (3)].no)->code));
					cat_tac(&((yyval.no)->code), &((yyvsp[(1) - (3)].no)->code));				
			 	}
			 }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 322 "pico.y"
    { (yyval.no) = (yyvsp[(1) - (1)].no); }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 325 "pico.y"
    { 	(yyval.no) = create_node((yylsp[(1) - (1)]).first_line, idf_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL);
		
		entry_t * variable;
		
		if ((variable = lookup(variable_table, (yyval.no)->lexeme)) == NULL)
		{
			printf("ERROR(%d). The variable %s was not declared.\n", (yyval.no)->num_line, (yyval.no)->lexeme);
			exit(1);
		}
		
		(yyval.no)->local = variable->name;		
		(yyval.no)->code  = NULL;
	    }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 339 "pico.y"
    {	Node* filho2 = create_node((yylsp[(2) - (2)]).first_line, rightbracket3_node, (yyvsp[(2) - (2)].cadeia), NULL, NULL);
				(yyval.no) = create_node((yyloc).first_line, lvalue_node, NULL, (yyvsp[(1) - (2)].no), filho2, NULL, NULL);
						
				char *temp1 = new_temp(t_counter++);				
				entry_t *temp_variable1 = new_variable(temp1, int_node, INT_SIZE, temp_desloc, NULL);    			
		    		temp_desloc = temp_desloc + INT_SIZE;    			
    				insert(&temp_table, temp_variable1);	
    				
    				entry_t *array;
    				if ((array = lookup(variable_table, (yyvsp[(1) - (2)].no)->array)) == NULL)
				{
					printf("ERROR(%d). The variable %s was not declared.\n", (yyvsp[(1) - (2)].no)->num_line, (yyvsp[(1) - (2)].no)->array);
					exit(1);
				}				
				
				char *weight = (char *) malloc(sizeof(char)*20);
    				switch(array->type)
				{
					case int_node:
						sprintf(weight, "%d", INT_SIZE);
						break;
	
					case double_node:
						sprintf(weight, "%d", DOUBLE_SIZE);
						break;
	
					case real_node:
						sprintf(weight, "%d", REAL_SIZE);
						break;
	
					case char_node:
						sprintf(weight, "%d", CHAR_SIZE);
						break;
				}	
				
				struct tac *instruction1 = create_inst_tac(temp1, (yyvsp[(1) - (2)].no)->local, "MUL", weight);				
				append_inst_tac(&((yyvsp[(1) - (2)].no)->code), instruction1);
				
				char *temp2 = new_temp(t_counter++);				
				entry_t * temp_variable2 = new_variable (temp2, int_node, INT_SIZE, temp_desloc, NULL);			
		    		temp_desloc = temp_desloc + INT_SIZE;    			
    				insert(&temp_table, temp_variable2);
				    				
				int offset = array_constant((yyvsp[(1) - (2)].no)->array, variable_table);
				array->extra->offset = offset;
				char *constant = (char *) malloc(sizeof(char)*35);
				sprintf(constant, "%d", offset, (yyvsp[(1) - (2)].no)->array);
							
				struct tac *instruction2 = create_inst_tac(temp2, temp1, "ADD", constant);
				append_inst_tac(&((yyvsp[(1) - (2)].no)->code), instruction2);		
				
				cat_tac(&((yyval.no)->code), &((yyvsp[(1) - (2)].no)->code));						
    				
    				(yyval.no)->local = temp2;
    				(yyval.no)->array = (yyvsp[(1) - (2)].no)->array;
		}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 397 "pico.y"
    {	Node* filho2 = create_node((yylsp[(2) - (3)]).first_line, comma_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
					(yyval.no) = create_node((yyloc).first_line, listaexpr_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL, NULL);
						
					char *temp = new_temp(t_counter++);
					entry_t *temp_variable = new_variable (temp, int_node, INT_SIZE, temp_desloc, NULL);    			
		    			temp_desloc = temp_desloc + INT_SIZE;
    					insert(&temp_table, temp_variable);

					int m = (yyvsp[(1) - (3)].no)->ndim + 1;
					
					char *limit = (char *) malloc(sizeof(char)*22);
					sprintf(limit, "%d", array_limit((yyvsp[(1) - (3)].no)->array, m, variable_table));
					
					struct tac *instruction1 = create_inst_tac(temp, (yyvsp[(1) - (3)].no)->local, "MUL", limit);
					append_inst_tac(&((yyvsp[(1) - (3)].no)->code), instruction1);					
					
					char *temp2 = new_temp(t_counter++);
					entry_t *temp_variable2 = new_variable (temp2, int_node, INT_SIZE, temp_desloc, NULL);    			
		    			temp_desloc = temp_desloc + INT_SIZE;
    					insert(&temp_table, temp_variable2);
									
					struct tac *instruction2 = create_inst_tac(temp2, temp, "ADD", (yyvsp[(3) - (3)].no)->local);
					append_inst_tac(&((yyvsp[(1) - (3)].no)->code), instruction2);
					
					cat_tac(&((yyvsp[(1) - (3)].no)->code), &((yyvsp[(3) - (3)].no)->code));
					cat_tac(&((yyval.no)->code), &((yyvsp[(1) - (3)].no)->code));

					(yyval.no)->array = (yyvsp[(1) - (3)].no)->array;
					(yyval.no)->local = temp2;
					(yyval.no)->ndim = m;					
				}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 429 "pico.y"
    {    Node* filho1 = create_node( (yylsp[(1) - (3)]).first_line, idf_node, (yyvsp[(1) - (3)].cadeia), NULL, NULL);
	 			     Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, leftbracket3_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				     (yyval.no) = create_node((yyloc).first_line, listaexpr_node, NULL, filho1, filho2, (yyvsp[(3) - (3)].no), NULL);
				     
				     (yyval.no)->array = (yyvsp[(1) - (3)].cadeia);
				     (yyval.no)->local = (yyvsp[(3) - (3)].no)->local;
				     (yyval.no)->ndim = 1;
				     cat_tac(&((yyval.no)->code), &((yyvsp[(3) - (3)].no)->code));			     	     
				}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 440 "pico.y"
    {  Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, plus_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
    			(yyval.no) = create_node( (yyloc).first_line, expr_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL); 

    			(yyval.no)->local = new_temp(t_counter++);
    			
    			entry_t * temp_variable = new_variable ((yyval.no)->local, int_node, INT_SIZE, temp_desloc, NULL);
    			
    			temp_desloc = temp_desloc + INT_SIZE;
    			
    			insert(&temp_table, temp_variable);
    			
			struct tac* new_instruction = create_inst_tac((yyval.no)->local, (yyvsp[(1) - (3)].no)->local, "ADD", (yyvsp[(3) - (3)].no)->local);
			append_inst_tac(&((yyvsp[(3) - (3)].no)->code), new_instruction); 

			cat_tac(&((yyvsp[(1) - (3)].no)->code), &((yyvsp[(3) - (3)].no)->code));
			cat_tac(&((yyval.no)->code), &((yyvsp[(1) - (3)].no)->code));
		     }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 458 "pico.y"
    {  Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, minus_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
    			(yyval.no) = create_node( (yyloc).first_line, expr_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL); 
    			
    			(yyval.no)->local = new_temp(t_counter++);
    			
    			entry_t * temp_variable = new_variable ((yyval.no)->local, int_node, INT_SIZE, temp_desloc, NULL);
    			
    			temp_desloc = temp_desloc + INT_SIZE;
    			
    			insert(&temp_table, temp_variable);			
			
			struct tac* new_instruction = create_inst_tac((yyval.no)->local, (yyvsp[(1) - (3)].no)->local, "SUB", (yyvsp[(3) - (3)].no)->local);
			append_inst_tac(&((yyvsp[(3) - (3)].no)->code), new_instruction); 

			cat_tac(&((yyvsp[(1) - (3)].no)->code), &((yyvsp[(3) - (3)].no)->code));
			cat_tac(&((yyval.no)->code), &((yyvsp[(1) - (3)].no)->code));
		     }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 476 "pico.y"
    {  Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, mul_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
    			(yyval.no) = create_node( (yyloc).first_line, expr_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL); 

    			(yyval.no)->local = new_temp(t_counter++);
    			
    			entry_t * temp_variable = new_variable ((yyval.no)->local, int_node, INT_SIZE, temp_desloc, NULL);
    			
    			temp_desloc = temp_desloc + INT_SIZE;
    			
    			insert(&temp_table, temp_variable);			
			
			struct tac* new_instruction = create_inst_tac((yyval.no)->local, (yyvsp[(1) - (3)].no)->local, "MUL", (yyvsp[(3) - (3)].no)->local);
			append_inst_tac(&((yyvsp[(3) - (3)].no)->code), new_instruction); 

			cat_tac(&((yyvsp[(1) - (3)].no)->code), &((yyvsp[(3) - (3)].no)->code));
			cat_tac(&((yyval.no)->code), &((yyvsp[(1) - (3)].no)->code));
		     }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 494 "pico.y"
    {  Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, div_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
    			(yyval.no) = create_node( (yyloc).first_line, expr_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL); 

    			(yyval.no)->local = new_temp(t_counter++);
    			
    			entry_t * temp_variable = new_variable ((yyval.no)->local, int_node, INT_SIZE, temp_desloc, NULL);
    			
    			temp_desloc = temp_desloc + INT_SIZE;
    			
    			insert(&temp_table, temp_variable);
    			
			struct tac* new_instruction = create_inst_tac((yyval.no)->local, (yyvsp[(1) - (3)].no)->local, "DIV", (yyvsp[(3) - (3)].no)->local);
			append_inst_tac(&((yyvsp[(3) - (3)].no)->code), new_instruction); 

			cat_tac(&((yyvsp[(1) - (3)].no)->code), &((yyvsp[(3) - (3)].no)->code));
			cat_tac(&((yyval.no)->code), &((yyvsp[(1) - (3)].no)->code));
		     }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 512 "pico.y"
    {  
    			Node* filho1 = create_node( (yylsp[(1) - (3)]).first_line, leftbracket_node, (yyvsp[(1) - (3)].cadeia), NULL, NULL);
			Node* filho3 = create_node( (yylsp[(3) - (3)]).first_line, rightbracket_node, (yyvsp[(3) - (3)].cadeia), NULL, NULL);
			(yyval.no) = create_node( (yyloc).first_line, expr_node, NULL, filho1, (yyvsp[(2) - (3)].no), filho3, NULL); 

			(yyval.no)->local = (yyvsp[(2) - (3)].no)->local;
			cat_tac(&((yyval.no)->code), &((yyvsp[(2) - (3)].no)->code));
		     }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 521 "pico.y"
    { 	
    			(yyval.no) = create_node((yyloc).first_line, int_lit_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL); 
  		       	(yyval.no)->local = (yyvsp[(1) - (1)].cadeia);
			(yyval.no)->code = NULL; 
			}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 527 "pico.y"
    { (yyval.no) = create_node((yyloc).first_line, f_lit_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL); }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 529 "pico.y"
    {	
    			(yyval.no) = create_node((yyloc).first_line, expr_node, NULL, (yyvsp[(1) - (1)].no), NULL, NULL);
    			
    			
    			if ((yyvsp[(1) - (1)].no)->array != NULL)
    			{
	    			char *temp = new_temp(t_counter++);
				entry_t *temp_variable = new_variable (temp, int_node, INT_SIZE, temp_desloc, NULL);    			
				temp_desloc = temp_desloc + INT_SIZE;
				insert(&temp_table, temp_variable);
	    						
				char *indirect_access = (char *) malloc(sizeof(char)*30);
				sprintf(indirect_access, "%s(%s)", (yyvsp[(1) - (1)].no)->local, (yyvsp[(1) - (1)].no)->array);
					
				struct tac *instruction1 = create_inst_tac(temp, indirect_access, "", "");
				append_inst_tac(&((yyvsp[(1) - (1)].no)->code), instruction1);
				   						
				cat_tac(&((yyval.no)->code), &((yyvsp[(1) - (1)].no)->code));			
				(yyval.no)->array = (yyvsp[(1) - (1)].no)->array;			
				(yyval.no)->local = temp;
			}
			
			else
			{
				(yyval.no)->local = (yyvsp[(1) - (1)].no)->local;
			}
		}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 557 "pico.y"
    { (yyval.no) = (yyvsp[(1) - (1)].no); }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 560 "pico.y"
    {  
					Node* filho1 = create_node( (yylsp[(1) - (4)]).first_line, idf_node, (yyvsp[(1) - (4)].cadeia), NULL, NULL);
					Node* filho2 = create_node( (yylsp[(2) - (4)]).first_line, leftbracket_node, (yyvsp[(2) - (4)].cadeia), NULL, NULL);
					Node* filho4 = create_node( (yylsp[(4) - (4)]).first_line, rightbracket_node, (yyvsp[(4) - (4)].cadeia), NULL, NULL);
					(yyval.no) = create_node( (yyloc).first_line, chamaproc_node, NULL, filho1, filho2, (yyvsp[(3) - (4)].no), filho4, NULL);  
					}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 568 "pico.y"
    { (yyval.no) = (yyvsp[(1) - (1)].no) ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 570 "pico.y"
    {   
         							Node* filho1 = create_node( (yylsp[(1) - (7)]).first_line, if_node, (yyvsp[(1) - (7)].cadeia), NULL, NULL);
								Node* filho2 = create_node( (yylsp[(2) - (7)]).first_line, leftbracket_node, (yyvsp[(2) - (7)].cadeia), NULL, NULL);
								Node* filho4 = create_node( (yylsp[(4) - (7)]).first_line, rightbracket_node, (yyvsp[(4) - (7)].cadeia), NULL, NULL);
								Node* filho5 = create_node( (yylsp[(5) - (7)]).first_line, then_node, (yyvsp[(5) - (7)].cadeia), NULL, NULL);
								(yyval.no) = create_node( (yyloc).first_line, enunciado_node, NULL, filho1, filho2, (yyvsp[(3) - (7)].no), filho4, filho5, (yyvsp[(6) - (7)].no), (yyvsp[(7) - (7)].no), NULL);  
								cat_tac(&((yyval.no)->code), &((yyvsp[(6) - (7)].no)->code));
								cat_tac(&((yyval.no)->code), &((yyvsp[(7) - (7)].no)->code));
								}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 580 "pico.y"
    {  	
	 						Node* filho1 = create_node( (yylsp[(1) - (7)]).first_line, while_node, (yyvsp[(1) - (7)].cadeia), NULL, NULL);
						    	Node* filho2 = create_node( (yylsp[(2) - (7)]).first_line, leftbracket_node, (yyvsp[(2) - (7)].cadeia), NULL, NULL);
 						    	Node* filho4 = create_node( (yylsp[(4) - (7)]).first_line, rightbracket_node, (yyvsp[(4) - (7)].cadeia), NULL, NULL);
	 					    	Node* filho5 = create_node( (yylsp[(5) - (7)]).first_line, leftbracket2_node, (yyvsp[(5) - (7)].cadeia), NULL, NULL);
 						    	Node* filho7 = create_node( (yylsp[(7) - (7)]).first_line, rightbracket2_node, (yyvsp[(7) - (7)].cadeia), NULL, NULL);
						    	(yyval.no) = create_node( (yyloc).first_line, enunciado_node, NULL, filho1, filho2, (yyvsp[(3) - (7)].no), filho4, filho5, (yyvsp[(6) - (7)].no), filho7, NULL);
						    	cat_tac(&((yyval.no)->code), &((yyvsp[(6) - (7)].no)->code));  
						 }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 590 "pico.y"
    {   	
    	 				Node* filho1 = create_node( (yylsp[(1) - (4)]).first_line, print_node, (yyvsp[(1) - (4)].cadeia), NULL, NULL);
				  	Node* filho2 = create_node( (yylsp[(2) - (4)]).first_line, leftbracket_node, (yyvsp[(2) - (4)].cadeia), NULL, NULL);
				  	Node* filho4 = create_node( (yylsp[(4) - (4)]).first_line, rightbracket_node, (yyvsp[(4) - (4)].cadeia), NULL, NULL);

		    			(yyval.no) = create_node( (yyloc).first_line, enunciado_node, NULL, filho1, filho2, (yyvsp[(3) - (4)].no), filho4, NULL);
					struct tac* new_instruction = create_inst_tac("PRINT", (yyvsp[(3) - (4)].no)->local, "", "");
					append_inst_tac(&((yyvsp[(3) - (4)].no)->code), new_instruction);
					cat_tac(&((yyval.no)->code), &((yyvsp[(3) - (4)].no)->code));
			  	}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 603 "pico.y"
    { (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, end_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL); }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 605 "pico.y"
    {   
               				Node* filho1 = create_node( (yylsp[(1) - (3)]).first_line, else_node, (yyvsp[(1) - (3)].cadeia), NULL, NULL);
					Node* filho3 = create_node( (yylsp[(3) - (3)]).first_line, end_node, (yyvsp[(3) - (3)].cadeia), NULL, NULL);
    			    	      	(yyval.no) = create_node( (yyloc).first_line, fiminstcontrole_node, NULL, filho1, (yyvsp[(2) - (3)].no), filho3, NULL);  
    			    	       	cat_tac(&((yyval.no)->code), &((yyvsp[(2) - (3)].no)->code));
    			    	   }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 613 "pico.y"
    { (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, true_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL); }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 615 "pico.y"
    { (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, false_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL); }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 617 "pico.y"
    {  Node* filho1 = create_node( (yylsp[(1) - (3)]).first_line, leftbracket_node, (yyvsp[(1) - (3)].cadeia), NULL, NULL);
       			      Node* filho3 = create_node( (yylsp[(3) - (3)]).first_line, rightbracket_node, (yyvsp[(3) - (3)].cadeia), NULL, NULL);  
    			      (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, filho1, (yyvsp[(2) - (3)].no), filho3, NULL); }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 621 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, and_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 624 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, or_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 627 "pico.y"
    {   Node* filho1 = create_node( (yylsp[(1) - (2)]).first_line, not_node, (yyvsp[(1) - (2)].cadeia), NULL, NULL);
    			    	       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, filho1, (yyvsp[(2) - (2)].no), NULL);  }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 630 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, greater_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 633 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, lower_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 636 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, le_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 639 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, ge_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 642 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, eq_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 645 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, ne_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;



/* Line 1455 of yacc.c  */
#line 2354 "y.tab.c"
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
#line 648 "pico.y"


