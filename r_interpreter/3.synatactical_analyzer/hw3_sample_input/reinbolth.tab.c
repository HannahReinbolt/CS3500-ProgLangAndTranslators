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
#line 35 "reinbolth.y" /* yacc.c:339  */

#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stack>
#include "SymbolTable.h"

void printRule(const char *lhs, const char *rhs);
int yyerror(const char *s);
void printTokenInfo(const char* tokenType, const char* lexeme);
void endScope( );
void beginScope( );
bool findEntryInAnyScope(const string theName);
void printAddSymb(const string symbName);
void printUnDefinedError(const string symbName);
void printMulDefinedError(const string symbName);

int numLines = 1;
int comments = 0;
int spaces = 0;
stack<SYMBOL_TABLE> scopeStack;


extern "C" {
	int yyparse(void);
	int yylex(void);
	int yywrap() {return 1;}
	}
	

#line 98 "reinbolth.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif


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
    T_ASSIGN = 258,
    T_IF = 259,
    T_WHILE = 260,
    T_FUNCTION = 261,
    T_FOR = 262,
    T_IN = 263,
    T_NEXT = 264,
    T_BREAK = 265,
    T_TRUE = 266,
    T_FALSE = 267,
    T_QUIT = 268,
    T_PRINT = 269,
    T_CAT = 270,
    T_READ = 271,
    T_LIST = 272,
    T_COMMENT = 273,
    T_WSPACE = 274,
    T_COMMA = 275,
    T_LBRACE = 276,
    T_RBRACE = 277,
    T_LPAREN = 278,
    T_RBRACKET = 279,
    T_LBRACKET = 280,
    T_ADD = 281,
    T_SUB = 282,
    T_MULT = 283,
    T_DIV = 284,
    T_MOD = 285,
    T_POWER = 286,
    T_LT = 287,
    T_GT = 288,
    T_LE = 289,
    T_GE = 290,
    T_EQ = 291,
    T_NE = 292,
    T_NOT = 293,
    T_AND = 294,
    T_OR = 295,
    T_SEMICOLON = 296,
    T_STRCONST = 297,
    T_FLOATCONST = 298,
    T_LETTER = 299,
    T_DIGIT = 300,
    T_UNKNOWN = 301,
    T_INTCONST = 302,
    T_IDENT = 303,
    T_RPAREN = 304,
    T_ELSE = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 68 "reinbolth.y" /* yacc.c:355  */

char* text;

#line 190 "reinbolth.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 207 "reinbolth.tab.c" /* yacc.c:358  */

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
#define YYFINAL  56
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   143

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    89,    89,    97,   101,   105,   109,   113,   117,   121,
     125,   129,   133,   137,   141,   147,   151,   155,   159,   163,
     168,   173,   178,   182,   186,   191,   197,   196,   208,   212,
     216,   221,   226,   231,   236,   240,   246,   245,   257,   262,
     266,   271,   275,   280,   286,   285,   298,   302,   308,   312,
     330,   349,   359,   363,   369,   373,   377,   382,   386,   391,
     396,   401,   405,   410,   415,   419,   423,   427,   431,   436,
     440,   444,   449,   453,   457,   461,   465,   470,   474,   478,
     482,   486,   490,   495,   499,   504,   514
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_ASSIGN", "T_IF", "T_WHILE",
  "T_FUNCTION", "T_FOR", "T_IN", "T_NEXT", "T_BREAK", "T_TRUE", "T_FALSE",
  "T_QUIT", "T_PRINT", "T_CAT", "T_READ", "T_LIST", "T_COMMENT",
  "T_WSPACE", "T_COMMA", "T_LBRACE", "T_RBRACE", "T_LPAREN", "T_RBRACKET",
  "T_LBRACKET", "T_ADD", "T_SUB", "T_MULT", "T_DIV", "T_MOD", "T_POWER",
  "T_LT", "T_GT", "T_LE", "T_GE", "T_EQ", "T_NE", "T_NOT", "T_AND", "T_OR",
  "T_SEMICOLON", "T_STRCONST", "T_FLOATCONST", "T_LETTER", "T_DIGIT",
  "T_UNKNOWN", "T_INTCONST", "T_IDENT", "T_RPAREN", "T_ELSE", "$accept",
  "N_START", "N_EXPR", "N_CONST", "N_COMPOUND_EXPR", "N_EXPR_LIST",
  "N_IF_EXPR", "N_WHILE_EXPR", "N_FOR_EXPR", "$@1", "N_LOOP_EXPR",
  "N_BREAK_EXPR", "N_NEXT_EXPR", "N_LIST_EXPR", "N_CONST_LIST",
  "N_ASSIGNMENT_EXPR", "$@2", "N_INDEX", "N_QUIT_EXPR", "N_OUTPUT_EXPR",
  "N_INPUT_EXPR", "N_FUNCTION_DEF", "$@3", "N_PARAM_LIST", "N_NO_PARAMS",
  "N_PARAMS", "N_FUNCTION_CALL", "N_ARG_LIST", "N_NO_ARGS", "N_ARGS",
  "N_ARITHLOGIC_EXPR", "N_SIMPLE_ARITHLOGIC", "N_ADD_OP_LIST", "N_TERM",
  "N_MULT_OP_LIST", "N_FACTOR", "N_ADD_OP", "N_MULT_OP", "N_REL_OP",
  "N_VAR", "N_SINGLE_ELEMENT", "N_ENTIRE_VAR", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF -48

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-48)))

#define YYTABLE_NINF -40

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      60,   -18,   -17,   -48,   -16,   -48,   -48,   -14,   -13,    -5,
       6,     9,    60,    60,    67,   -48,   -48,   -48,     5,    36,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   105,    11,    91,   -48,   -48,   -48,
      60,    60,    19,   -37,    -6,    60,    60,    -4,    -8,     8,
      -2,    25,   -48,    60,    29,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,    67,   -48,   -48,   -48,   -48,    67,   -48,
     -48,   -48,   -48,   -48,   -48,    67,     7,    12,    20,   -48,
     -48,    21,    31,    33,    35,    38,    60,    37,   -48,    44,
      40,    39,   -48,   -48,    60,    81,   -48,    11,    91,    60,
      10,    65,    42,   -48,   -48,    84,   -48,   -48,   -48,    -8,
     -48,     8,   -48,    60,    60,   -48,    69,    60,   -48,   -48,
      45,   -48,   -48,   -48,   -48,   -48,   -48,    20,    68,    60,
     -48,   -48,    72,   -48,    73,   -48,    60,   -48,   -48,    52,
      80,   103,   -48,    10,   -48,   -48
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    44,     0,    18,    19,     0,     0,     0,
       0,     0,     0,     0,     0,    16,    17,    15,    86,     0,
       2,    66,     6,     3,     4,     5,    11,     8,    14,     9,
      10,    12,    13,     7,    57,    61,    64,    65,    84,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       0,    86,    68,    54,     0,    36,     1,    77,    78,    79,
      80,    81,    82,     0,    69,    70,    71,    59,     0,    72,
      73,    75,    76,    74,    62,     0,     0,     0,    48,    26,
      40,     0,     0,     0,    35,     0,     0,     0,    67,     0,
      55,     0,    53,    52,     0,     0,    58,    61,    64,     0,
       0,    49,     0,    47,    46,     0,    41,    42,    43,     0,
      33,    22,    20,     0,     0,    51,     0,     0,    60,    63,
      23,    32,    31,    28,    25,    29,    30,     0,     0,     0,
      34,    21,     0,    56,     0,    37,     0,    50,    45,     0,
       0,    85,    24,     0,    85,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,   -48,     0,   -47,   -10,     1,   -48,   -48,   -48,   -48,
     -32,   -48,   -48,   -48,    14,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   -11,   -48,   -48,   -48,    13,
     -48,    61,    28,    58,    30,   -12,   -48,   -48,   -48,    85,
     -48,   -48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    19,    90,    21,    22,    87,    23,    24,    25,   105,
     124,   125,   126,    26,    85,    27,    95,    55,    28,    29,
      30,    31,    42,   102,   103,   104,    32,    91,    92,    93,
      33,    34,    67,    35,    74,    36,    68,    75,    63,    37,
      38,    39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,    84,    52,     5,     6,    40,    41,    43,   -39,    44,
      45,    79,    49,    50,     1,     2,     3,     4,    46,   121,
     122,     5,     6,     7,     8,     9,    10,    11,    53,    47,
      54,    12,    48,    13,    15,    16,    56,    64,    65,    17,
      76,    77,    78,    80,    51,    81,    82,    88,    14,    86,
      89,    66,    15,    16,    94,   109,    99,    17,    18,   112,
     114,   100,    84,    98,     1,     2,     3,     4,   101,   113,
     106,     5,     6,     7,     8,     9,    10,    11,     5,     6,
     107,    12,   108,    13,   117,   127,   111,   110,   115,    12,
      13,   128,   129,   134,   116,   136,   140,   141,    14,   120,
     123,   143,    15,    16,   144,    14,   -38,    17,    18,    15,
      16,   145,   131,   132,    17,    51,   137,   135,   138,    69,
      70,    71,    72,   130,    96,   118,    97,   133,   119,   139,
      73,     0,    83,     0,     0,     0,   142,    57,    58,    59,
      60,    61,    62,   123
};

static const yytype_int16 yycheck[] =
{
       0,    48,    14,    11,    12,    23,    23,    23,     3,    23,
      23,    48,    12,    13,     4,     5,     6,     7,    23,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    23,    23,
      25,    21,    23,    23,    42,    43,     0,    26,    27,    47,
      40,    41,    23,    49,    48,    45,    46,    49,    38,    41,
      25,    40,    42,    43,    25,    20,    49,    47,    48,    22,
      20,    49,   109,    75,     4,     5,     6,     7,    48,    25,
      49,    11,    12,    13,    14,    15,    16,    17,    11,    12,
      49,    21,    49,    23,     3,    20,    86,    49,    49,    21,
      23,    49,     8,    24,    94,    50,    24,    24,    38,    99,
     100,    49,    42,    43,    24,    38,     3,    47,    48,    42,
      43,   143,   111,   113,    47,    48,   127,   117,   128,    28,
      29,    30,    31,   109,    63,    97,    68,   114,    98,   129,
      39,    -1,    47,    -1,    -1,    -1,   136,    32,    33,    34,
      35,    36,    37,   143
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,    11,    12,    13,    14,    15,
      16,    17,    21,    23,    38,    42,    43,    47,    48,    52,
      53,    54,    55,    57,    58,    59,    64,    66,    69,    70,
      71,    72,    77,    81,    82,    84,    86,    90,    91,    92,
      23,    23,    73,    23,    23,    23,    23,    23,    23,    53,
      53,    48,    86,    23,    25,    68,     0,    32,    33,    34,
      35,    36,    37,    89,    26,    27,    40,    83,    87,    28,
      29,    30,    31,    39,    85,    88,    53,    53,    23,    48,
      49,    53,    53,    90,    54,    65,    41,    56,    49,    25,
      53,    78,    79,    80,    25,    67,    82,    84,    86,    49,
      49,    48,    74,    75,    76,    60,    49,    49,    49,    20,
      49,    53,    22,    25,    20,    49,    53,     3,    83,    85,
      53,     9,    10,    53,    61,    62,    63,    20,    49,     8,
      65,    56,    53,    80,    24,    53,    50,    76,    55,    53,
      24,    24,    53,    49,    24,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    54,    54,    54,    54,    54,
      55,    56,    56,    57,    57,    58,    60,    59,    61,    61,
      61,    62,    63,    64,    65,    65,    67,    66,    68,    68,
      69,    70,    70,    71,    73,    72,    74,    74,    75,    76,
      76,    77,    78,    78,    79,    80,    80,    81,    81,    82,
      83,    83,    84,    85,    85,    86,    86,    86,    86,    87,
      87,    87,    88,    88,    88,    88,    88,    89,    89,    89,
      89,    89,    89,    90,    90,    91,    92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     0,     5,     7,     5,     0,     8,     1,     1,
       1,     1,     1,     4,     3,     1,     0,     5,     5,     0,
       3,     4,     4,     4,     0,     6,     1,     1,     0,     1,
       3,     4,     1,     1,     0,     1,     3,     1,     3,     2,
       3,     0,     2,     3,     0,     1,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     6,     1
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
#line 90 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule ("START", "EXPR");
										endScope();
										printf("\n ---- Completed parsing ----\n\n");
										return 0;
										}
#line 1404 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 98 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("EXPR", "IF_EXPR");
										}
#line 1412 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 102 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("EXPR", "WHILE_EXPR");
										}
#line 1420 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 106 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("EXPR", "FOR_EXPR");
										}
#line 1428 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 110 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("EXPR", "COMPOUND_EXPR");
										}
#line 1436 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 114 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("EXPR", "ARITHLOGIC_EXPR");
										}
#line 1444 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 118 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("EXPR", "ASSIGNMENT_EXPR");
										}
#line 1452 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 122 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("EXPR", "OUTPUT_EXPR");
										}
#line 1460 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 126 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("EXPR", "INPUT_EXPR");
										}
#line 1468 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 130 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("EXPR", "LIST_EXPR");
										}
#line 1476 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 134 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("EXPR", "FUNCTION_DEF");
										}
#line 1484 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 138 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("EXPR", "FUNCTION_CALL");
										}
#line 1492 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 142 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("EXPR", "QUIT_EXPR");
										exit(1);
										}
#line 1501 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 148 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("CONST", "INTCONST");
										}
#line 1509 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 152 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("CONST", "STRCONST");
										}
#line 1517 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 156 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("CONST", "FLOATCONST");
										}
#line 1525 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 160 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("CONST", "TRUE");
										}
#line 1533 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 164 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("CONST", "FALSE");
										}
#line 1541 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 169 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("COMPOUND_EXPR", "{ EXPR EXPR_LIST }");
										}
#line 1549 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 174 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("EXPR_LIST", "; EXPR EXPR_LIST");
										}
#line 1557 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 178 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("EXPR_LIST", "epsilon");
										}
#line 1565 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 183 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("IF_EXPR", "IF ( EXPR ) EXPR");
										}
#line 1573 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 187 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("IF_EXPR", "IF ( EXPR ) EXPR ELSE EXPR");
										}
#line 1581 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 192 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("WHILE_EXPR", "WHILE ( EXPR ) LOOP_EXPR");
										}
#line 1589 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 197 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("FOR_EXPR", "FOR ( IDENT IN EXPR ) LOOP_EXPR");
										// add T_IDENT to the most recent scope if it's not in one
										string lexeme = string((yyvsp[0].text));
										if(!scopeStack.top().findEntry(lexeme))
											{
											printAddSymb(lexeme);
											}
								}
#line 1603 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 209 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("LOOP_EXPR", "EXPR");
										}
#line 1611 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 213 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("LOOP_EXPR", "BREAK_EXPR");
										}
#line 1619 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 217 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("LOOP_EXPR", "NEXT_EXPR");
										}
#line 1627 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 222 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("BREAK_EXPR", "BREAK");
										}
#line 1635 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 227 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("NEXT_EXPR", "NEXT");
										}
#line 1643 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 232 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("LIST_EXPR", "LIST ( CONST_LIST )");
										}
#line 1651 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 237 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("CONST_LIST", "CONST, CONST_LIST");
										}
#line 1659 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 241 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("CONST_LIST", "CONST");
										}
#line 1667 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 246 "reinbolth.y" /* yacc.c:1646  */
    {
										// add T_IDENT to the most recent scope if it's not in a scope
										printRule("ASSIGNMENT_EXPR", "IDENT INDEX ASSIGN EXPR");
										string lexeme = string((yyvsp[-1].text));
										if(!scopeStack.top().findEntry(lexeme))
											{
											printAddSymb(lexeme);
											}
										}
#line 1681 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 258 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("INDEX", "[[ EXPR ]]");
										}
#line 1689 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 262 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("INDEX", "epsilon");
										}
#line 1697 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 267 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("QUIT_EXPR", "QUIT()");
										}
#line 1705 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 272 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("OUTPUT_EXPR", "PRINT ( EXPR )");
										}
#line 1713 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 276 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("OUTPUT_EXPR", "CAT ( EXPR )");
										}
#line 1721 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 281 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("INPUT_EXPR", "READ ( VAR )");
										}
#line 1729 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 286 "reinbolth.y" /* yacc.c:1646  */
    {
										// new symbol table
										beginScope();
										
										}
#line 1739 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 292 "reinbolth.y" /* yacc.c:1646  */
    {
									printRule("FUNCTION_DEF", "FUNCTION ( PARAM_LIST ) COMPOUND_EXPR");
										//close the symbol table for this function
										endScope();
								}
#line 1749 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 299 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("PARAM_LIST", "PARAMS");
										}
#line 1757 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 303 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("PARAM_LIST", "NO_PARAMS");
										}
#line 1765 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 308 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("NO_PARAMS", "epsilon");
										}
#line 1773 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 313 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("PARAMS", "IDENT");

										// add T_IDENT to the most recent scope if it's not in a scope
										string lexeme = string((yyvsp[0].text));
										if(findEntryInAnyScope(lexeme))
											{
											printAddSymb(lexeme);
											printMulDefinedError(lexeme);
											}
										// if it's not in a scope then add to recent scope
										else
											{
											printAddSymb(lexeme);
											}
										
										}
#line 1795 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 331 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("PARAMS", "IDENT, PARAMS");
										
										// add T_IDENT to the most recent scope if it's not in a scope
										string lexeme = string((yyvsp[-2].text));
										if(findEntryInAnyScope(lexeme))
											{
											printAddSymb(lexeme);
											printMulDefinedError(lexeme);
											}
										// if it's not in a scope then add to recent scope
										else
											{
											printAddSymb(lexeme);
											}
								
										}
#line 1817 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 350 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("FUNCTION_CALL", "IDENT ( ARG_LIST )");
										string lexeme = string((yyvsp[-3].text));
										if(!findEntryInAnyScope(lexeme))
											{
											printUnDefinedError(lexeme);
											}
										}
#line 1830 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 360 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("ARG_LIST", "ARGS");
										}
#line 1838 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 364 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("ARG_LIST", "NO_ARGS");
										}
#line 1846 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 369 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("NO_ARGS", "epsilon");
										}
#line 1854 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 374 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("ARGS", "EXPR");
										}
#line 1862 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 378 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("ARGS", "EXPR, ARGS");
										}
#line 1870 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 383 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("ARITHLOGIC_EXPR", "SIMPLE_ARITHLOGIC");
										}
#line 1878 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 387 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("ARITHLOGIC_EXPR", "SIMPLE_ARITHLOGIC REL_OP SIMPLE_ARITHLOGIC");
										}
#line 1886 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 392 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("SIMPLE_ARITHLOGIC", "TERM ADD_OP_LIST");
										}
#line 1894 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 397 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("ADD_OP_LIST", "ADD_OP TERM ADD_OP_LIST");
										}
#line 1902 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 401 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("ADD_OP_LIST", "epsilon");
										}
#line 1910 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 406 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("TERM", "FACTOR MULT_OP_LIST");
										}
#line 1918 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 411 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("MULT_OP_LIST", "MULT_OP FACTOR MULT_OP_LIST");
										}
#line 1926 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 415 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("MULT_OP_LIST", "epsilon");
										}
#line 1934 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 420 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("FACTOR", "VAR");
										}
#line 1942 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 424 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("FACTOR", "CONST");
										}
#line 1950 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 428 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("FACTOR", "( EXPR )");
										}
#line 1958 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 432 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("FACTOR", "! FACTOR");
										}
#line 1966 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 437 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("ADD_OP", "+");
										}
#line 1974 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 441 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("ADD_OP", "-");
										}
#line 1982 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 445 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("ADD_OP", "|");
										}
#line 1990 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 450 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("MULT_OP", "*");
										}
#line 1998 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 454 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("MULT_OP", "/");
										}
#line 2006 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 458 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("MULT_OP", "&");
										}
#line 2014 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 462 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("MULT_OP", "%%");
										}
#line 2022 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 466 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("MULT_OP", "^");
										}
#line 2030 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 471 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("REL_OP", "<");
										}
#line 2038 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 475 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("REL_OP", ">");
										}
#line 2046 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 479 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("REL_OP", "<=");
										}
#line 2054 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 483 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("REL_OP", ">=");
										}
#line 2062 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 487 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("REL_OP", "==");
										}
#line 2070 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 491 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("REL_OP", "!=");
										}
#line 2078 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 496 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("VAR", "ENTIRE_VAR");
										}
#line 2086 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 500 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("VAR", "SINGLE_ELEMENT");
										}
#line 2094 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 505 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("SINGLE_ELEMENT", "IDENT [[ EXPR ]]");
										string lexeme = string((yyvsp[-5].text));
										if(!findEntryInAnyScope(lexeme))
											{
											printUnDefinedError(lexeme);
											}
										}
#line 2107 "reinbolth.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 515 "reinbolth.y" /* yacc.c:1646  */
    {
										printRule("ENTIRE_VAR", "IDENT");
										//check if undefined
										string lexeme = string((yyvsp[0].text));
										if(!findEntryInAnyScope(lexeme))
											{
											printUnDefinedError(lexeme);
											}
										}
#line 2121 "reinbolth.tab.c" /* yacc.c:1646  */
    break;


#line 2125 "reinbolth.tab.c" /* yacc.c:1646  */
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
#line 525 "reinbolth.y" /* yacc.c:1906  */


//symbol table files
#include <stack>
#include "SymbolTable.h" //we dont need the other one because it is included in this one

#include "lex.yy.c"
extern FILE *yyin;

void printRule(const char *lhs, const char *rhs)
{
	printf("%s -> %s\n", lhs, rhs);
}

int yyerror(const char *s)
{
	char str[9];
	sprintf(str, "%d", numLines);
	printf("Line %s", str);
	printf(": %s\n",s);
	return(1);
}

void printTokenInfo(const char* tokenType, const char* lexeme)
{
	printf("TOKEN: %s	LEXEME: %s\n", tokenType, lexeme);
}


void printMulDefinedError(const string symbName)
{
	char str[9];
	sprintf(str, "%d", numLines);
	printf("Line %s", str);
	printf(": Multiply defined identifier\n");
	exit(1);
}

void printUnDefinedError(const string symbName)
{
	char str[9];
	sprintf(str, "%d", numLines);
	printf("Line %s", str);
	printf(": Undefined identifier\n");
	exit(1);
}

void printAddSymb(const string symbName)
{
	scopeStack.top().addEntry(SYMBOL_TABLE_ENTRY(symbName, UNDEFINED));
	printf("___Adding %s to symbol table\n", symbName.c_str());
}

bool findEntryInAnyScope(const string theName)
{
	if (scopeStack.empty()) return(false);
	bool found = scopeStack.top().findEntry(theName);
	if (found)
		return(true);
	else { // check in "next higher" scope
		SYMBOL_TABLE symbolTable = scopeStack.top();
		scopeStack.pop();
		found = findEntryInAnyScope(theName);
		scopeStack.push(symbolTable); // restore the stack
		return(found);
	}
}

void beginScope( )
{
	scopeStack.push(SYMBOL_TABLE( ));
	printf("\n___Entering new scope...\n\n");
}

void endScope( )
{
	scopeStack.pop( );
	printf("\n___Exiting scope...\n\n");
}

int main()
{
	// make the global table
	beginScope();
	
	do
	{
		yyparse();
		numLines++;
	} while(!feof(yyin));
	
	return 0;
}
