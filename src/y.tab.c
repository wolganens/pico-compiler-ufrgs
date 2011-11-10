
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
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   159

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNRULES -- Number of states.  */
#define YYNSTATES  119

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
      61,    67,    70,    74,    78,    80,    82,    87,    89,    93,
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
       3,    -1,     3,    28,    59,    29,    -1,    60,    -1,    60,
      21,    59,    -1,    60,    14,    60,    -1,    60,    15,    60,
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
       0,   111,   111,   117,   123,   127,   132,   143,   146,   152,
     153,   156,   160,   164,   168,   173,   178,   183,   188,   194,
     199,   206,   212,   220,   239,   242,   258,   264,   265,   269,
     287,   305,   323,   341,   349,   353,   355,   357,   360,   366,
     367,   374,   382,   389,   390,   397,   399,   401,   405,   408,
     411,   414,   417,   420,   423,   426,   429
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
       5,     2,     3,     3,     1,     1,     4,     1,     3,     3,
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
      36,    39,    37,    24,     0,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,     1,     0,     2,     4,     0,
      21,     0,     0,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,    33,     0,     0,    45,    46,
       0,     0,     0,     5,     7,     6,    22,    23,    29,    30,
      31,    32,    38,     0,    26,     0,    15,    16,    17,    18,
      42,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    19,    47,    53,    54,
      55,    56,    51,    52,     0,    48,    49,     0,     8,     0,
       0,     0,    20,     0,    43,    40,    41,     0,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    12,    13,    14,    65,    15,    16,    17,    50,    18,
      19,    31,    46,    21,    22,    23,   115,    61
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -28
static const yytype_int16 yypact[] =
{
      93,   -14,   -16,    -9,    17,    18,    24,    13,    28,    31,
     -28,   -28,    56,    93,    35,    38,   -28,   -28,   -28,    41,
      48,   108,   -28,   -28,    13,    13,    43,    43,    43,    43,
      13,   -28,     6,    30,    30,   -28,    59,   -28,   -28,    79,
      36,    13,    13,    13,    13,    13,    60,    62,    73,    80,
      87,    89,    91,   102,    94,   -28,    30,    30,   -28,   -28,
     135,   -19,    -6,   -28,    84,   -28,   -28,   108,     1,     1,
     -28,   -28,   -28,    13,   -28,    81,   -28,   -28,   -28,   -28,
     -28,   123,    90,   -28,    13,    13,    13,    13,    13,    13,
     107,    30,    30,   110,    79,   -28,   132,   -28,   108,   108,
     108,   108,   108,   108,    36,   -28,    98,    36,   -28,    43,
      -1,   129,   -28,    36,   -28,   -28,   -28,   118,   -28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -28,   -28,   -28,   145,    65,   -28,   -28,   -28,   -25,   -12,
     -28,     0,   -20,     2,   -28,   -28,   -28,   -27
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      20,    37,    51,    52,    53,    48,    90,    62,    26,    32,
      24,    91,    92,    20,    25,    27,     1,    44,    45,    93,
      42,    43,    44,    45,    91,    92,    47,    47,    66,    82,
      83,    55,    54,     1,   113,    60,    60,     7,   114,     1,
      20,    28,    29,    67,    68,    69,    70,    71,    30,     6,
      10,    11,    33,    95,    56,    34,    35,    38,    81,    60,
       7,    39,    57,    40,   105,   106,    41,    10,    11,     8,
      58,    59,     9,    10,    11,    47,    42,    43,    44,    45,
      49,    63,    64,    73,   112,    72,    98,    99,   100,   101,
     102,   103,   110,    60,    60,   111,     1,     2,     3,     4,
       5,   117,    74,    75,    20,    94,     6,    20,    42,    43,
      44,    45,    76,    20,    77,    97,    78,     7,    96,    80,
      91,    92,    42,    43,    44,    45,     8,    79,    91,     9,
      10,    11,    84,    85,    86,    87,   107,    42,    43,    44,
      45,   104,    88,    89,    84,    85,    86,    87,    55,    42,
      43,    44,    45,   109,    88,    89,   116,   118,    36,   108
};

static const yytype_uint8 yycheck[] =
{
       0,    13,    27,    28,    29,    25,    25,    34,    24,     7,
      24,    30,    31,    13,    28,    24,     3,    16,    17,    25,
      14,    15,    16,    17,    30,    31,    24,    25,    40,    56,
      57,    25,    30,     3,    35,    33,    34,    24,    39,     3,
      40,    24,    24,    41,    42,    43,    44,    45,    24,    13,
      37,    38,    24,    73,    24,    24,     0,    22,    56,    57,
      24,    23,    32,    22,    91,    92,    18,    37,    38,    33,
      40,    41,    36,    37,    38,    73,    14,    15,    16,    17,
      37,    22,     3,    21,   109,    25,    84,    85,    86,    87,
      88,    89,   104,    91,    92,   107,     3,     4,     5,     6,
       7,   113,    29,    23,   104,    21,    13,   107,    14,    15,
      16,    17,    25,   113,    25,    25,    25,    24,    37,    25,
      30,    31,    14,    15,    16,    17,    33,    25,    30,    36,
      37,    38,     9,    10,    11,    12,    26,    14,    15,    16,
      17,    34,    19,    20,     9,    10,    11,    12,    25,    14,
      15,    16,    17,    21,    19,    20,    27,    39,    13,    94
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    13,    24,    33,    36,
      37,    38,    48,    49,    50,    52,    53,    54,    56,    57,
      58,    60,    61,    62,    24,    28,    24,    24,    24,    24,
      24,    58,    60,    24,    24,     0,    50,    56,    22,    23,
      22,    18,    14,    15,    16,    17,    59,    60,    59,    37,
      55,    55,    55,    55,    60,    25,    24,    32,    40,    41,
      60,    64,    64,    22,     3,    51,    56,    60,    60,    60,
      60,    60,    25,    21,    29,    23,    25,    25,    25,    25,
      25,    60,    64,    64,     9,    10,    11,    12,    19,    20,
      25,    30,    31,    25,    21,    59,    37,    25,    60,    60,
      60,    60,    60,    60,    34,    64,    64,    26,    51,    21,
      56,    56,    55,    35,    39,    63,    27,    56,    39
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
    { (yyval.no) = create_node( (yyloc).first_line, code_node, NULL, (yyvsp[(1) - (2)].no), (yyvsp[(2) - (2)].no), NULL);
			           syntax_tree = (yyval.no); 

				   cat_tac(&((yyval.no)->code), &((yyvsp[(2) - (2)].no)->code));
				   print_tac (stdout, (yyval.no)->code);
				 }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 117 "pico.y"
    { (yyval.no) = (yyvsp[(1) - (1)].no);
    				   syntax_tree = (yyval.no); 
    				   print_tac (stdout, (yyval.no)->code);
				 }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 123 "pico.y"
    {   Node *filho2 = create_node( (yylsp[(2) - (2)]).first_line, semicolon_node, (yyvsp[(2) - (2)].cadeia), NULL, NULL);
    			    	(yyval.no) = create_node( (yyloc).first_line, declaracoes_node, NULL, (yyvsp[(1) - (2)].no), filho2, NULL);  
			    }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 127 "pico.y"
    {   Node* filho3 = create_node( (yylsp[(3) - (3)]).first_line, semicolon_node, (yyvsp[(3) - (3)].cadeia), NULL, NULL);
    			    		    (yyval.no) = create_node( (yylsp[(1) - (3)]).first_line, declaracoes_node, NULL, (yyvsp[(1) - (3)].no), (yyvsp[(2) - (3)].no), filho3, NULL);  
					}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 132 "pico.y"
    {	Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, colon_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
					(yyval.no) = create_node( (yyloc).first_line, declaracao_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);

					do_symbol_insertion ((yyval.no), &variable_table, (yyvsp[(1) - (3)].no)->type, (yyvsp[(1) - (3)].no)->size);
					
					//print_table(variable_table);
					//print_table(variable_table);

				     }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 143 "pico.y"
    {  (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, idf_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL);	}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 146 "pico.y"
    {	Node* filho1 = create_node( (yylsp[(1) - (3)]).first_line, idf_node, (yyvsp[(1) - (3)].cadeia), NULL, NULL);        					
               					Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, comma_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);               					
						(yyval.no) = create_node( (yyloc).first_line, listadeclaracao_node, NULL, filho1, filho2, (yyvsp[(3) - (3)].no), NULL);
					 }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 152 "pico.y"
    { (yyval.no) = (yyvsp[(1) - (1)].no); }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 153 "pico.y"
    { (yyval.no) = (yyvsp[(1) - (1)].no); }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 156 "pico.y"
    { (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, int_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL);
		      (yyval.no)->type = int_node;
	              (yyval.no)->size = INT_SIZE; }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 160 "pico.y"
    { (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, double_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL);
		      (yyval.no)->type = double_node;
		      (yyval.no)->size = DOUBLE_SIZE; }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 164 "pico.y"
    { (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, real_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL);
		      (yyval.no)->type = real_node;
		      (yyval.no)->size = REAL_SIZE; }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 168 "pico.y"
    { (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, char_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL);
		      (yyval.no)->type = char_node;
		      (yyval.no)->size = CHAR_SIZE; }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 173 "pico.y"
    {  Node* filho1 = create_node( (yylsp[(1) - (4)]).first_line, int_node, (yyvsp[(1) - (4)].cadeia), NULL, NULL);
					 Node* filho2 = create_node( (yylsp[(2) - (4)]).first_line, rightbracket_node, (yyvsp[(2) - (4)].cadeia), NULL, NULL);
					 Node* filho4 = create_node( (yylsp[(4) - (4)]).first_line, leftbracket_node, (yyvsp[(4) - (4)].cadeia), NULL, NULL);
    			    		 (yyval.no) = create_node( (yyloc).first_line, tipolista_node, NULL, filho1, filho2, (yyvsp[(3) - (4)].no), filho4, NULL);  }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 178 "pico.y"
    {  Node* filho1 = create_node( (yylsp[(1) - (4)]).first_line, double_node, (yyvsp[(1) - (4)].cadeia), NULL, NULL);
					 Node* filho2 = create_node( (yylsp[(2) - (4)]).first_line, rightbracket_node, (yyvsp[(2) - (4)].cadeia), NULL, NULL);
					 Node* filho4 = create_node( (yylsp[(4) - (4)]).first_line, leftbracket_node, (yyvsp[(4) - (4)].cadeia), NULL, NULL);
    			    		 (yyval.no) = create_node( (yyloc).first_line, tipolista_node, NULL, filho1, filho2, (yyvsp[(3) - (4)].no), filho4, NULL);  }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 183 "pico.y"
    {  Node* filho1 = create_node( (yylsp[(1) - (4)]).first_line, real_node, (yyvsp[(1) - (4)].cadeia), NULL, NULL);
					 Node* filho2 = create_node( (yylsp[(2) - (4)]).first_line, rightbracket_node, (yyvsp[(2) - (4)].cadeia), NULL, NULL);
					 Node* filho4 = create_node( (yylsp[(4) - (4)]).first_line, leftbracket_node, (yyvsp[(4) - (4)].cadeia), NULL, NULL);
    			    		 (yyval.no) = create_node( (yyloc).first_line, tipolista_node, NULL, filho1, filho2, (yyvsp[(3) - (4)].no), filho4, NULL);  }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 188 "pico.y"
    {  Node* filho1 = create_node( (yylsp[(1) - (4)]).first_line, char_node, (yyvsp[(1) - (4)].cadeia), NULL, NULL);
					 Node* filho2 = create_node( (yylsp[(2) - (4)]).first_line, rightbracket_node, (yyvsp[(2) - (4)].cadeia), NULL, NULL);
					 Node* filho4 = create_node( (yylsp[(4) - (4)]).first_line, leftbracket_node, (yyvsp[(4) - (4)].cadeia), NULL, NULL);
    			    		 (yyval.no) = create_node( (yyloc).first_line, tipolista_node, NULL, filho1, filho2, (yyvsp[(3) - (4)].no), filho4, NULL);  }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 194 "pico.y"
    {  Node* filho1 = create_node( (yylsp[(1) - (3)]).first_line, int_lit_node, (yyvsp[(1) - (3)].cadeia), NULL, NULL);
					   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, colon_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
					   Node* filho3 = create_node( (yylsp[(3) - (3)]).first_line, int_lit_node, (yyvsp[(3) - (3)].cadeia), NULL, NULL);
    			    		   (yyval.no) = create_node( (yyloc).first_line, listadupla_node, NULL, filho1, filho2, filho3, NULL);  }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 199 "pico.y"
    {  Node* filho1 = create_node( (yylsp[(1) - (5)]).first_line, int_lit_node, (yyvsp[(1) - (5)].cadeia), NULL, NULL);
						   Node* filho2 = create_node( (yylsp[(2) - (5)]).first_line, colon_node, (yyvsp[(2) - (5)].cadeia), NULL, NULL);
					           Node* filho3 = create_node( (yylsp[(3) - (5)]).first_line, int_lit_node, (yyvsp[(3) - (5)].cadeia), NULL, NULL);
						   Node* filho4 = create_node( (yylsp[(4) - (5)]).first_line, comma_node, (yyvsp[(4) - (5)].cadeia), NULL, NULL);
    			    		           (yyval.no) = create_node( (yyloc).first_line, listadupla_node, NULL, filho1, filho2, filho3, filho4, (yyvsp[(5) - (5)].no), NULL);  }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 206 "pico.y"
    {	Node* filho2 = create_node( (yylsp[(2) - (2)]).first_line, semicolon_node, (yyvsp[(2) - (2)].cadeia), NULL, NULL);
    			(yyval.no) = create_node( (yyloc).first_line, acoes_node, NULL, (yyvsp[(1) - (2)].no), filho2, NULL);
			
			cat_tac(&((yyval.no)->code), &((yyvsp[(1) - (2)].no)->code));
		    }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 212 "pico.y"
    {  Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, semicolon_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
    			      (yyval.no) = create_node( (yyloc).first_line, acoes_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL); 

			      cat_tac(&((yyvsp[(1) - (3)].no)->code), &((yyvsp[(3) - (3)].no)->code));
			      cat_tac(&((yyval.no)->code), &((yyvsp[(1) - (3)].no)->code));			      
		    	   }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 220 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, attr_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
			     (yyval.no) = create_node( (yyloc).first_line, comando_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);
			     
			     entry_t * variable;
		
			     if (((variable) = lookup(variable_table, (yyvsp[(1) - (3)].no)->local)) == NULL)
			     { 
				printf("Error (%d). The variable %s was not declared.\n", (yyval.no)->num_line, (yyval.no)->lexeme);
				exit(1);
			     }
			     
			     char *blank_space = (char *) malloc(sizeof(char));
			     strcpy(blank_space, "");
			     
			     struct tac* new_instruction = create_inst_tac(variable->name, (yyvsp[(3) - (3)].no)->local, blank_space, blank_space);
			     append_inst_tac(&((yyvsp[(3) - (3)].no)->code), new_instruction);
			
			     cat_tac(&((yyval.no)->code), &((yyvsp[(3) - (3)].no)->code));
			 }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 239 "pico.y"
    { (yyval.no) = (yyvsp[(1) - (1)].no); }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 242 "pico.y"
    { 	(yyval.no) = create_node((yylsp[(1) - (1)]).first_line, idf_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL);
		
		entry_t * variable;
		
		if ((variable = lookup(variable_table, (yyval.no)->lexeme)) == NULL)
		{
			printf("Error (%d). The variable %s was not declared.\n", (yyval.no)->num_line, (yyval.no)->lexeme);
			exit(1);
		}
		
		(yyval.no)->local = variable->name;
		
		(yyval.no)->code  = NULL;
	    }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 258 "pico.y"
    {  Node* filho1 = create_node( (yylsp[(1) - (4)]).first_line, idf_node, (yyvsp[(1) - (4)].cadeia), NULL, NULL);
			             Node* filho2 = create_node( (yylsp[(2) - (4)]).first_line, rightbracket3_node, (yyvsp[(2) - (4)].cadeia), NULL, NULL);
				     Node* filho4 = create_node( (yylsp[(4) - (4)]).first_line, leftbracket3_node, (yyvsp[(4) - (4)].cadeia), NULL, NULL);
    			    	     (yyval.no) = create_node( (yyloc).first_line, lvalue_node, NULL, filho1, filho2, (yyvsp[(3) - (4)].no), filho4, NULL);  }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 264 "pico.y"
    { (yyval.no) = (yyvsp[(1) - (1)].no); }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 265 "pico.y"
    {    Node* filho2 = create_node( (yylsp[(1) - (3)]).first_line, comma_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				     (yyval.no) = create_node( (yyloc).first_line, listaexpr_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 269 "pico.y"
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
#line 287 "pico.y"
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
#line 305 "pico.y"
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
#line 323 "pico.y"
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
#line 341 "pico.y"
    {  Node* filho1 = create_node( (yylsp[(1) - (3)]).first_line, rightbracket_node, (yyvsp[(1) - (3)].cadeia), NULL, NULL);
			Node* filho3 = create_node( (yylsp[(3) - (3)]).first_line, leftbracket_node, (yyvsp[(3) - (3)].cadeia), NULL, NULL);
    			(yyval.no) = create_node( (yyloc).first_line, expr_node, NULL, filho1, (yyvsp[(2) - (3)].no), filho3, NULL); 

			(yyval.no)->local = (yyvsp[(2) - (3)].no)->local;
		        (yyval.no)->code = (yyvsp[(2) - (3)].no)->code;
		     }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 349 "pico.y"
    { (yyval.no) = create_node((yyloc).first_line, int_lit_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL); 
  		       (yyval.no)->local = (yyvsp[(1) - (1)].cadeia);
		       (yyval.no)->code = NULL; }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 353 "pico.y"
    { (yyval.no) = create_node((yyloc).first_line, f_lit_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL); }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 355 "pico.y"
    { (yyval.no) = (yyvsp[(1) - (1)].no); }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 357 "pico.y"
    { (yyval.no) = (yyvsp[(1) - (1)].no); }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 360 "pico.y"
    {  Node* filho1 = create_node( (yylsp[(1) - (4)]).first_line, idf_node, (yyvsp[(1) - (4)].cadeia), NULL, NULL);
				      Node* filho2 = create_node( (yylsp[(2) - (4)]).first_line, rightbracket_node, (yyvsp[(2) - (4)].cadeia), NULL, NULL);
				      Node* filho4 = create_node( (yylsp[(4) - (4)]).first_line, leftbracket_node, (yyvsp[(4) - (4)].cadeia), NULL, NULL);
    			    	      (yyval.no) = create_node( (yyloc).first_line, chamaproc_node, NULL, filho1, filho2, (yyvsp[(3) - (4)].no), filho4, NULL);  }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 366 "pico.y"
    { (yyval.no) = (yyvsp[(1) - (1)].no) ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 367 "pico.y"
    {   Node* filho1 = create_node( (yylsp[(1) - (7)]).first_line, if_node, (yyvsp[(1) - (7)].cadeia), NULL, NULL);
								Node* filho2 = create_node( (yylsp[(2) - (7)]).first_line, rightbracket_node, (yyvsp[(2) - (7)].cadeia), NULL, NULL);
								Node* filho4 = create_node( (yylsp[(4) - (7)]).first_line, leftbracket_node, (yyvsp[(4) - (7)].cadeia), NULL, NULL);
								Node* filho5 = create_node( (yylsp[(5) - (7)]).first_line, then_node, (yyvsp[(5) - (7)].cadeia), NULL, NULL);
    			  (yyval.no) = create_node( (yyloc).first_line, enunciado_node, NULL, filho1, filho2, (yyvsp[(3) - (7)].no), filho4, filho5, (yyvsp[(6) - (7)].no), (yyvsp[(7) - (7)].no), NULL);  
    			  cat_tac(&((yyval.no)->code), &((yyvsp[(6) - (7)].no)->code));}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 374 "pico.y"
    {   Node* filho1 = create_node( (yylsp[(1) - (7)]).first_line, while_node, (yyvsp[(1) - (7)].cadeia), NULL, NULL);
						    Node* filho2 = create_node( (yylsp[(2) - (7)]).first_line, rightbracket_node, (yyvsp[(2) - (7)].cadeia), NULL, NULL);
 						    Node* filho4 = create_node( (yylsp[(4) - (7)]).first_line, leftbracket_node, (yyvsp[(4) - (7)].cadeia), NULL, NULL);
         					    Node* filho5 = create_node( (yylsp[(5) - (7)]).first_line, rightbracket2_node, (yyvsp[(5) - (7)].cadeia), NULL, NULL);
 						    Node* filho7 = create_node( (yylsp[(7) - (7)]).first_line, leftbracket2_node, (yyvsp[(7) - (7)].cadeia), NULL, NULL);
    	 (yyval.no) = create_node( (yyloc).first_line, enunciado_node, NULL, filho1, filho2, (yyvsp[(3) - (7)].no), filho4, filho5, (yyvsp[(6) - (7)].no), filho7, NULL);
    	 cat_tac(&((yyval.no)->code), &((yyvsp[(6) - (7)].no)->code));  }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 382 "pico.y"
    {   Node* filho1 = create_node( (yylsp[(1) - (4)]).first_line, print_node, (yyvsp[(1) - (4)].cadeia), NULL, NULL);
				   Node* filho2 = create_node( (yylsp[(2) - (4)]).first_line, rightbracket_node, (yyvsp[(2) - (4)].cadeia), NULL, NULL);
				   Node* filho4 = create_node( (yylsp[(4) - (4)]).first_line, leftbracket_node, (yyvsp[(4) - (4)].cadeia), NULL, NULL);
    			(yyval.no) = create_node( (yyloc).first_line, enunciado_node, NULL, filho1, filho2, (yyvsp[(3) - (4)].no), filho4, NULL);  }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 389 "pico.y"
    { (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, end_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL); }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 390 "pico.y"
    {   Node* filho1 = create_node( (yylsp[(1) - (3)]).first_line, else_node, (yyvsp[(1) - (3)].cadeia), NULL, NULL);
				       Node* filho3 = create_node( (yylsp[(3) - (3)]).first_line, end_node, (yyvsp[(3) - (3)].cadeia), NULL, NULL);
    			    	       (yyval.no) = create_node( (yyloc).first_line, fiminstcontrole_node, NULL, filho1, (yyvsp[(2) - (3)].no), filho3, NULL);  
    			    	       cat_tac(&((yyval.no)->code), &((yyvsp[(2) - (3)].no)->code));
    			    	   }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 397 "pico.y"
    { (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, true_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL); }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 399 "pico.y"
    { (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, false_node, (yyvsp[(1) - (1)].cadeia), NULL, NULL); }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 401 "pico.y"
    {  Node* filho1 = create_node( (yylsp[(1) - (3)]).first_line, rightbracket_node, (yyvsp[(1) - (3)].cadeia), NULL, NULL);
       			      Node* filho3 = create_node( (yylsp[(3) - (3)]).first_line, leftbracket_node, (yyvsp[(3) - (3)].cadeia), NULL, NULL);  
    			      (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, filho1, (yyvsp[(2) - (3)].no), filho3, NULL); }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 405 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, and_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 408 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, or_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 411 "pico.y"
    {   Node* filho1 = create_node( (yylsp[(1) - (2)]).first_line, not_node, (yyvsp[(1) - (2)].cadeia), NULL, NULL);
    			    	       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, filho1, (yyvsp[(2) - (2)].no), NULL);  }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 414 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, greater_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 417 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, lower_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 420 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, le_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 423 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, ge_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 426 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, eq_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 429 "pico.y"
    {   Node* filho2 = create_node( (yylsp[(2) - (3)]).first_line, ne_node, (yyvsp[(2) - (3)].cadeia), NULL, NULL);
				       (yyval.no) = create_node( (yyloc).first_line, expbool_node, NULL, (yyvsp[(1) - (3)].no), filho2, (yyvsp[(3) - (3)].no), NULL);  }
    break;



/* Line 1455 of yacc.c  */
#line 2140 "y.tab.c"
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
#line 433 "pico.y"


