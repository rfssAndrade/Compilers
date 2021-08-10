/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "fir_parser.y"

//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include "ast/all.h"
#define LINE                         compiler->scanner()->lineno()
#define yylex()                      compiler->scanner()->scan()
#define yyerror(compiler, s)         compiler->scanner()->error(s)
//-- don't change *any* of these --- END!

#line 84 "fir_parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_FIR_PARSER_TAB_H_INCLUDED
# define YY_YY_FIR_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tTYPE_INT = 258,
    tTYPE_FLOAT = 259,
    tTYPE_STRING = 260,
    tTYPE_VOID = 261,
    tSIZEOF = 262,
    tIF = 263,
    tTHEN = 264,
    tELSE = 265,
    tWHILE = 266,
    tDO = 267,
    tFINALLY = 268,
    tLEAVE = 269,
    tRESTART = 270,
    tGE = 271,
    tLE = 272,
    tEQ = 273,
    tNE = 274,
    tAND = 275,
    tOR = 276,
    tRETURN = 277,
    tWRITE = 278,
    tWRITELN = 279,
    tARROW = 280,
    tEPILOGUE = 281,
    tPUBLIC = 282,
    tPRIVATE = 283,
    tINTEGER = 284,
    tFLOAT = 285,
    tSTRING = 286,
    tIDENTIFIER = 287,
    tNULL = 288,
    tUMINUS = 289
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "fir_parser.y"

  //--- don't change *any* of these: if you do, you'll break the compiler.
  YYSTYPE() : type(cdk::primitive_type::create(0, cdk::TYPE_VOID)) {}
  ~YYSTYPE() {}
  YYSTYPE(const YYSTYPE &other) { *this = other; }
  YYSTYPE& operator=(const YYSTYPE &other) { type = other.type; return *this; }

  std::shared_ptr<cdk::basic_type> type;        /* expression type */
  //-- don't change *any* of these --- END!

  int                   i;	/* integer value */
  double                d;
  std::string          *s;	/* symbol name or string literal */
  
  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::lvalue_node     *lvalue;

  fir::block_node      *block;
  fir::body_node       *b;

#line 194 "fir_parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (std::shared_ptr<cdk::compiler> compiler);

#endif /* !YY_YY_FIR_PARSER_TAB_H_INCLUDED  */

/* Second part of user prologue.  */
#line 76 "fir_parser.y"

//-- The rules below will be included in yyparse, the main parsing function.

#line 214 "fir_parser.tab.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   395

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

#define YYUNDEFTOK  2
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    42,     2,     2,
      46,    47,    40,    38,    48,    39,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
      36,    34,    37,    45,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,    35,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    80,    80,    83,    84,    87,    88,    89,    92,    93,
      96,    97,   100,   101,   102,   107,   108,   109,   110,   113,
     114,   117,   118,   119,   120,   121,   122,   125,   126,   127,
     128,   129,   130,   133,   134,   135,   138,   141,   142,   143,
     144,   147,   148,   149,   150,   151,   152,   153,   156,   159,
     160,   163,   164,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   183,   184,   187,   188,
     191,   192,   193,   194,   196,   198,   200,   201,   202,   203,
     204,   206,   207,   208,   209,   210,   211,   212,   213,   215,
     216,   217,   219,   220,   221,   222,   223,   224,   227,   228,
     229,   230,   233,   236,   239,   242,   243
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tTYPE_INT", "tTYPE_FLOAT",
  "tTYPE_STRING", "tTYPE_VOID", "tSIZEOF", "tIF", "tTHEN", "tELSE",
  "tWHILE", "tDO", "tFINALLY", "tLEAVE", "tRESTART", "tGE", "tLE", "tEQ",
  "tNE", "tAND", "tOR", "tRETURN", "tWRITE", "tWRITELN", "tARROW",
  "tEPILOGUE", "tPUBLIC", "tPRIVATE", "tINTEGER", "tFLOAT", "tSTRING",
  "tIDENTIFIER", "tNULL", "'='", "'~'", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "tUMINUS", "';'", "'?'", "'('", "')'", "','", "'@'", "'{'",
  "'}'", "'['", "']'", "$accept", "file", "declarations", "declaration",
  "vardecs", "opt_vardecs", "vardec", "data_type", "opt_initializer",
  "fundec", "fundef", "argdecs", "argdec", "literal", "body", "block",
  "instructions", "opt_instructions", "instruction", "expressions",
  "opt_expressions", "expression", "lvalue", "integer", "float", "null",
  "string", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    61,   126,    60,    62,    43,    45,
      42,    47,    37,   289,    59,    63,    40,    41,    44,    64,
     123,   125,    91,    93
};
# endif

#define YYPACT_NINF (-130)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      93,  -130,  -130,  -130,   -24,    37,     4,    93,  -130,   -38,
     168,  -130,  -130,   -19,    12,    31,   100,  -130,  -130,  -130,
     102,    49,   143,    37,   132,   134,  -130,    36,    37,  -130,
     220,   157,   175,   136,  -130,    37,    37,   190,  -130,  -130,
    -130,   191,  -130,    36,    36,    36,    36,  -130,    36,   339,
     280,  -130,  -130,  -130,   207,   138,    37,  -130,    37,  -130,
     114,    37,   154,   162,    36,    36,   353,  -130,  -130,   259,
     151,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,  -130,    36,  -130,   105,   164,
     186,   189,   189,    37,  -130,   229,  -130,   114,  -130,   271,
     208,   210,   339,   212,  -130,   221,   221,    76,    76,   353,
     346,   221,   221,   103,   103,  -130,  -130,  -130,   339,   178,
     199,  -130,   156,  -130,  -130,   -21,    37,   127,   223,   195,
     189,  -130,  -130,    36,   213,    36,  -130,   114,  -130,  -130,
    -130,   207,   199,  -130,   189,   255,   238,    36,    36,    57,
     117,  -130,    36,    36,  -130,   127,   233,  -130,   310,  -130,
     249,   254,   261,  -130,   339,    36,   205,  -130,   114,  -130,
     189,  -130,    -6,   303,   250,  -130,   258,  -130,    43,    46,
    -130,  -130,  -130,   249,  -130,   232,  -130,  -130,  -130,   127,
     127,  -130,  -130,  -130,  -130,  -130,   293,   291,   127,   127,
    -130,  -130
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    16,    17,    15,     0,     0,     0,     2,     3,     0,
       0,     6,     7,     0,     0,     0,     0,     1,     4,     5,
      19,     0,     0,    33,     0,     0,    18,     0,    33,    14,
      19,    12,     0,     0,    34,    33,    33,     0,   102,   103,
     105,    98,   104,     0,     0,     0,     0,    92,     0,    20,
      74,    70,    71,    73,    72,     0,    33,    13,    33,    36,
      24,     0,     0,     0,     0,    68,    91,    89,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,     0,   106,    21,     0,
       0,     0,     0,    10,    29,    42,    35,    26,    25,     0,
      69,     0,    66,    96,    95,    84,    82,    83,    86,    88,
      87,    81,    85,    76,    77,    78,    79,    80,    75,     0,
       0,    31,    23,    22,    43,    41,    11,    51,     0,     0,
       0,    30,    94,     0,    93,     0,    99,     0,    37,    38,
      40,    39,     0,    32,     0,    44,     0,     0,     0,     0,
       0,    58,     0,     0,    57,    52,     0,    49,     0,     8,
      19,     0,     0,    46,    67,     0,     0,    27,     0,    45,
       0,     9,     0,     0,     0,    61,     0,    59,     0,     0,
      50,    48,    65,    19,    12,     0,   100,    28,    47,     0,
       0,    62,    60,    63,    64,   101,    53,    55,     0,     0,
      54,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,  -130,  -130,   298,  -130,  -130,   -23,     2,   -30,  -130,
    -130,    44,   256,   174,   -60,   -66,  -130,  -130,   -79,  -129,
    -130,   -26,  -130,   -37,   -36,     5,    32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,   126,   127,     9,    32,    29,    11,
      12,    33,    34,   137,    94,    95,   155,   156,   157,   100,
     101,   158,    50,    51,    52,    53,    54
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    49,    10,   189,    17,   144,    19,    16,    13,    10,
      71,    72,    73,    74,    75,    76,    14,    66,    67,    68,
      69,    15,    70,   178,   179,   124,   125,    23,   121,    93,
      77,    78,    79,    80,    81,    82,    83,   131,    99,   102,
       1,     2,     3,    37,    24,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   145,
     119,   154,   143,    25,   163,    38,    39,    40,    41,    42,
     128,    43,    55,     5,    44,    45,   180,   167,   169,    62,
      63,    30,    46,   138,   139,    47,   174,   193,    48,   154,
     194,   133,    71,    72,   133,   129,     1,     2,     3,     4,
      89,   175,    90,   146,   188,   138,   139,   164,   187,   166,
     196,   197,    77,    78,    79,    80,    81,    82,    83,   200,
     201,   172,   173,   154,   154,   140,   102,   102,   129,     5,
     120,    91,   154,   154,    37,   147,    27,    26,   148,   185,
      91,   149,   150,    81,    82,    83,   176,   140,    28,   151,
     152,   153,   141,    57,    92,    93,    38,    39,    40,    41,
      42,   177,    43,    92,    93,    44,    45,    71,    72,    73,
      74,    75,    76,    46,   141,    31,    47,    93,    35,    48,
      36,   142,    91,    60,    61,    88,    61,    77,    78,    79,
      80,    81,    82,    83,    71,    72,    73,    74,    75,    76,
      20,    97,    61,    58,   104,    92,    93,    59,    21,    98,
      61,   122,    61,    22,    77,    78,    79,    80,    81,    82,
      83,    71,    72,    73,    74,    75,    76,   160,    38,    39,
      40,   136,    42,   123,    61,   161,    64,    65,    87,    93,
     162,    77,    78,    79,    80,    81,    82,    83,    71,    72,
      73,    74,    75,    76,    27,   130,   133,   134,   186,    79,
      80,    81,    82,    83,   135,   165,    56,   159,    77,    78,
      79,    80,    81,    82,    83,    71,    72,    73,    74,    75,
      76,   170,   171,    27,   181,   195,   183,    71,    72,    73,
      74,    75,    76,   184,   191,    77,    78,    79,    80,    81,
      82,    83,   192,   198,   199,    18,   103,    77,    78,    79,
      80,    81,    82,    83,    84,   190,   168,    96,   132,    71,
      72,    73,    74,    75,    76,    85,    71,    72,    73,    74,
      75,    76,    86,     0,     0,     0,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    77,    78,    79,    80,
      81,    82,    83,     0,   182,    71,    72,    73,    74,    75,
      76,     0,    71,    72,    73,    74,    75,     0,     0,    71,
      72,    73,    74,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    77,    78,    79,    80,    81,    82,    83,    77,
      78,    79,    80,    81,    82,    83
};

static const yytype_int16 yycheck[] =
{
      30,    27,     0,     9,     0,    26,    44,     5,    32,     7,
      16,    17,    18,    19,    20,    21,    40,    43,    44,    45,
      46,    45,    48,   152,   153,    91,    92,    46,    88,    50,
      36,    37,    38,    39,    40,    41,    42,    97,    64,    65,
       3,     4,     5,     7,    32,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,   125,
      86,   127,   122,    32,   130,    29,    30,    31,    32,    33,
      93,    35,    28,    36,    38,    39,   155,   137,   144,    35,
      36,    32,    46,   120,   120,    49,    29,    44,    52,   155,
      44,    48,    16,    17,    48,    93,     3,     4,     5,     6,
      56,    44,    58,   126,   170,   142,   142,   133,   168,   135,
     189,   190,    36,    37,    38,    39,    40,    41,    42,   198,
     199,   147,   148,   189,   190,   120,   152,   153,   126,    36,
      25,    26,   198,   199,     7,     8,    34,    37,    11,   165,
      26,    14,    15,    40,    41,    42,    29,   142,    46,    22,
      23,    24,   120,   183,    49,    50,    29,    30,    31,    32,
      33,    44,    35,    49,    50,    38,    39,    16,    17,    18,
      19,    20,    21,    46,   142,    32,    49,    50,    46,    52,
      46,    25,    26,    47,    48,    47,    48,    36,    37,    38,
      39,    40,    41,    42,    16,    17,    18,    19,    20,    21,
      32,    47,    48,    46,    53,    49,    50,    32,    40,    47,
      48,    47,    48,    45,    36,    37,    38,    39,    40,    41,
      42,    16,    17,    18,    19,    20,    21,    32,    29,    30,
      31,    53,    33,    47,    48,    40,    46,    46,    31,    50,
      45,    36,    37,    38,    39,    40,    41,    42,    16,    17,
      18,    19,    20,    21,    34,    26,    48,    47,    53,    38,
      39,    40,    41,    42,    52,    52,    46,    44,    36,    37,
      38,    39,    40,    41,    42,    16,    17,    18,    19,    20,
      21,    26,    44,    34,    51,    53,    32,    16,    17,    18,
      19,    20,    21,    32,    44,    36,    37,    38,    39,    40,
      41,    42,    44,    10,    13,     7,    47,    36,    37,    38,
      39,    40,    41,    42,    34,    12,   142,    61,    47,    16,
      17,    18,    19,    20,    21,    45,    16,    17,    18,    19,
      20,    21,    52,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    36,    37,    38,    39,
      40,    41,    42,    -1,    44,    16,    17,    18,    19,    20,
      21,    -1,    16,    17,    18,    19,    20,    -1,    -1,    16,
      17,    18,    19,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    36,    37,    38,    39,    40,    41,    42,    36,
      37,    38,    39,    40,    41,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    36,    55,    56,    57,    60,
      61,    63,    64,    32,    40,    45,    61,     0,    57,    44,
      32,    40,    45,    46,    32,    32,    37,    34,    46,    62,
      32,    32,    61,    65,    66,    46,    46,     7,    29,    30,
      31,    32,    33,    35,    38,    39,    46,    49,    52,    75,
      76,    77,    78,    79,    80,    65,    46,    62,    46,    32,
      47,    48,    65,    65,    46,    46,    75,    75,    75,    75,
      75,    16,    17,    18,    19,    20,    21,    36,    37,    38,
      39,    40,    41,    42,    34,    45,    52,    31,    47,    65,
      65,    26,    49,    50,    68,    69,    66,    47,    47,    75,
      73,    74,    75,    47,    53,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      25,    68,    47,    47,    69,    69,    58,    59,    60,    61,
      26,    68,    47,    48,    47,    52,    53,    67,    77,    78,
      79,    80,    25,    68,    26,    69,    60,     8,    11,    14,
      15,    22,    23,    24,    69,    70,    71,    72,    75,    44,
      32,    40,    45,    69,    75,    52,    75,    68,    67,    69,
      26,    44,    75,    75,    29,    44,    29,    44,    73,    73,
      72,    51,    44,    32,    32,    75,    53,    68,    69,     9,
      12,    44,    44,    44,    44,    53,    72,    72,    10,    13,
      72,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    57,    58,    58,
      59,    59,    60,    60,    60,    61,    61,    61,    61,    62,
      62,    63,    63,    63,    63,    63,    63,    64,    64,    64,
      64,    64,    64,    65,    65,    65,    66,    67,    67,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    69,    70,
      70,    71,    71,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    73,    73,    74,    74,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    76,    76,
      76,    76,    77,    78,    79,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     2,     3,
       0,     1,     3,     4,     3,     1,     1,     1,     3,     0,
       2,     5,     6,     6,     5,     6,     6,     8,     9,     6,
       7,     6,     7,     0,     1,     3,     2,     1,     1,     1,
       1,     2,     1,     2,     3,     4,     3,     5,     4,     1,
       2,     0,     1,     4,     6,     4,     6,     1,     1,     2,
       3,     2,     3,     3,     3,     2,     1,     3,     0,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     1,     4,     4,     3,     3,     2,     1,     4,
       6,     7,     1,     1,     1,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        yyerror (compiler, YY_("syntax error: cannot back up")); \
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
                  Type, Value, compiler); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (compiler);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, compiler);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, std::shared_ptr<cdk::compiler> compiler)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              , compiler);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, compiler); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YYUSE (yyvaluep);
  YYUSE (compiler);
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
yyparse (std::shared_ptr<cdk::compiler> compiler)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 80 "fir_parser.y"
                    { compiler->ast((yyval.sequence) = (yyvsp[0].sequence)); }
#line 1555 "fir_parser.tab.c"
    break;

  case 3:
#line 83 "fir_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1561 "fir_parser.tab.c"
    break;

  case 4:
#line 84 "fir_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1567 "fir_parser.tab.c"
    break;

  case 5:
#line 87 "fir_parser.y"
                          { (yyval.node) = (yyvsp[-1].node); }
#line 1573 "fir_parser.tab.c"
    break;

  case 6:
#line 88 "fir_parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1579 "fir_parser.tab.c"
    break;

  case 7:
#line 89 "fir_parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1585 "fir_parser.tab.c"
    break;

  case 8:
#line 92 "fir_parser.y"
                                  { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node)); }
#line 1591 "fir_parser.tab.c"
    break;

  case 9:
#line 93 "fir_parser.y"
                                  { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node), (yyvsp[-2].sequence)); }
#line 1597 "fir_parser.tab.c"
    break;

  case 10:
#line 96 "fir_parser.y"
                              { (yyval.sequence) = nullptr; }
#line 1603 "fir_parser.tab.c"
    break;

  case 11:
#line 97 "fir_parser.y"
                              { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1609 "fir_parser.tab.c"
    break;

  case 12:
#line 100 "fir_parser.y"
                                                         { (yyval.node) = new fir::variable_declaration_node(LINE, tPUBLIC, (yyvsp[-2].type), *(yyvsp[0].s), nullptr); }
#line 1615 "fir_parser.tab.c"
    break;

  case 13:
#line 101 "fir_parser.y"
                                                         { (yyval.node) = new fir::variable_declaration_node(LINE, tPUBLIC, (yyvsp[-3].type), *(yyvsp[-1].s), (yyvsp[0].expression)); }
#line 1621 "fir_parser.tab.c"
    break;

  case 14:
#line 102 "fir_parser.y"
                                                         { (yyval.node) = new fir::variable_declaration_node(LINE, tPRIVATE, (yyvsp[-2].type), *(yyvsp[-1].s), (yyvsp[0].expression)); }
#line 1627 "fir_parser.tab.c"
    break;

  case 15:
#line 107 "fir_parser.y"
                                             { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_STRING); }
#line 1633 "fir_parser.tab.c"
    break;

  case 16:
#line 108 "fir_parser.y"
                                             { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_INT); }
#line 1639 "fir_parser.tab.c"
    break;

  case 17:
#line 109 "fir_parser.y"
                                             { (yyval.type) = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE); }
#line 1645 "fir_parser.tab.c"
    break;

  case 18:
#line 110 "fir_parser.y"
                                             { (yyval.type) = cdk::reference_type::create(4, (yyvsp[-1].type)); }
#line 1651 "fir_parser.tab.c"
    break;

  case 19:
#line 113 "fir_parser.y"
                                   { (yyval.expression) = nullptr; }
#line 1657 "fir_parser.tab.c"
    break;

  case 20:
#line 114 "fir_parser.y"
                                   { (yyval.expression) = (yyvsp[0].expression); }
#line 1663 "fir_parser.tab.c"
    break;

  case 21:
#line 117 "fir_parser.y"
                                                          { (yyval.node) = new fir::function_declaration_node(LINE, tPRIVATE, (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1669 "fir_parser.tab.c"
    break;

  case 22:
#line 118 "fir_parser.y"
                                                          { (yyval.node) = new fir::function_declaration_node(LINE, tPUBLIC, (yyvsp[-5].type), *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1675 "fir_parser.tab.c"
    break;

  case 23:
#line 119 "fir_parser.y"
                                                          { (yyval.node) = new fir::function_declaration_node(LINE, tPUBLIC, (yyvsp[-5].type), *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1681 "fir_parser.tab.c"
    break;

  case 24:
#line 120 "fir_parser.y"
                                                          { (yyval.node) = new fir::function_declaration_node(LINE, tPRIVATE, *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1687 "fir_parser.tab.c"
    break;

  case 25:
#line 121 "fir_parser.y"
                                                          { (yyval.node) = new fir::function_declaration_node(LINE, tPUBLIC, *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1693 "fir_parser.tab.c"
    break;

  case 26:
#line 122 "fir_parser.y"
                                                          { (yyval.node) = new fir::function_declaration_node(LINE, tPUBLIC, *(yyvsp[-3].s), (yyvsp[-1].sequence)); }
#line 1699 "fir_parser.tab.c"
    break;

  case 27:
#line 125 "fir_parser.y"
                                                                              { (yyval.node) = new fir::function_definition_node(LINE, tPRIVATE, (yyvsp[-7].type), *(yyvsp[-6].s), (yyvsp[-4].sequence), (yyvsp[0].b), (yyvsp[-1].expression)); }
#line 1705 "fir_parser.tab.c"
    break;

  case 28:
#line 126 "fir_parser.y"
                                                                              { (yyval.node) = new fir::function_definition_node(LINE, tPUBLIC, (yyvsp[-8].type), *(yyvsp[-6].s), (yyvsp[-4].sequence), (yyvsp[0].b), (yyvsp[-1].expression)); }
#line 1711 "fir_parser.tab.c"
    break;

  case 29:
#line 127 "fir_parser.y"
                                                                              { (yyval.node) = new fir::function_definition_node(LINE, tPRIVATE, *(yyvsp[-4].s), (yyvsp[-2].sequence), (yyvsp[0].b), nullptr); }
#line 1717 "fir_parser.tab.c"
    break;

  case 30:
#line 128 "fir_parser.y"
                                                                              { (yyval.node) = new fir::function_definition_node(LINE, tPUBLIC, *(yyvsp[-4].s), (yyvsp[-2].sequence), (yyvsp[0].b), nullptr); }
#line 1723 "fir_parser.tab.c"
    break;

  case 31:
#line 129 "fir_parser.y"
                                                                              { (yyval.node) = new fir::function_definition_node(LINE, tPRIVATE, (yyvsp[-5].type), *(yyvsp[-4].s), (yyvsp[-2].sequence), (yyvsp[0].b), nullptr); }
#line 1729 "fir_parser.tab.c"
    break;

  case 32:
#line 130 "fir_parser.y"
                                                                              { (yyval.node) = new fir::function_definition_node(LINE, tPUBLIC, (yyvsp[-6].type), *(yyvsp[-4].s), (yyvsp[-2].sequence), (yyvsp[0].b), nullptr); }
#line 1735 "fir_parser.tab.c"
    break;

  case 33:
#line 133 "fir_parser.y"
                                   { (yyval.sequence) = new cdk::sequence_node(LINE); }
#line 1741 "fir_parser.tab.c"
    break;

  case 34:
#line 134 "fir_parser.y"
                                   { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1747 "fir_parser.tab.c"
    break;

  case 35:
#line 135 "fir_parser.y"
                                   { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-2].sequence)); }
#line 1753 "fir_parser.tab.c"
    break;

  case 36:
#line 138 "fir_parser.y"
                                     { (yyval.node) = new fir::variable_declaration_node(LINE, tPRIVATE, (yyvsp[-1].type), *(yyvsp[0].s), nullptr); }
#line 1759 "fir_parser.tab.c"
    break;

  case 37:
#line 141 "fir_parser.y"
                         { (yyval.expression) = (yyvsp[0].expression); }
#line 1765 "fir_parser.tab.c"
    break;

  case 38:
#line 142 "fir_parser.y"
                         { (yyval.expression) = (yyvsp[0].expression); }
#line 1771 "fir_parser.tab.c"
    break;

  case 39:
#line 143 "fir_parser.y"
                         { (yyval.expression) = new cdk::string_node(LINE, (yyvsp[0].s)); }
#line 1777 "fir_parser.tab.c"
    break;

  case 40:
#line 144 "fir_parser.y"
                         { (yyval.expression) = (yyvsp[0].expression); }
#line 1783 "fir_parser.tab.c"
    break;

  case 41:
#line 147 "fir_parser.y"
                                                     { (yyval.b) = new fir::body_node(LINE, new fir::prologue_node(LINE, (yyvsp[0].block)), nullptr, nullptr); }
#line 1789 "fir_parser.tab.c"
    break;

  case 42:
#line 148 "fir_parser.y"
                                                     { (yyval.b) = new fir::body_node(LINE, nullptr, (yyvsp[0].block), nullptr); }
#line 1795 "fir_parser.tab.c"
    break;

  case 43:
#line 149 "fir_parser.y"
                                                     { (yyval.b) = new fir::body_node(LINE, nullptr, nullptr, (yyvsp[0].block)); }
#line 1801 "fir_parser.tab.c"
    break;

  case 44:
#line 150 "fir_parser.y"
                                                     { (yyval.b) = new fir::body_node(LINE, new fir::prologue_node(LINE, (yyvsp[-1].block)), (yyvsp[0].block), nullptr); }
#line 1807 "fir_parser.tab.c"
    break;

  case 45:
#line 151 "fir_parser.y"
                                                     { (yyval.b) = new fir::body_node(LINE, new fir::prologue_node(LINE, (yyvsp[-2].block)), nullptr, (yyvsp[0].block)); }
#line 1813 "fir_parser.tab.c"
    break;

  case 46:
#line 152 "fir_parser.y"
                                                     { (yyval.b) = new fir::body_node(LINE, nullptr, (yyvsp[-2].block), (yyvsp[0].block)); }
#line 1819 "fir_parser.tab.c"
    break;

  case 47:
#line 153 "fir_parser.y"
                                                     { (yyval.b) = new fir::body_node(LINE, new fir::prologue_node(LINE, (yyvsp[-3].block)), (yyvsp[-2].block), (yyvsp[0].block)); }
#line 1825 "fir_parser.tab.c"
    break;

  case 48:
#line 156 "fir_parser.y"
                                                    { (yyval.block) = new fir::block_node(LINE, (yyvsp[-2].sequence), (yyvsp[-1].sequence)); }
#line 1831 "fir_parser.tab.c"
    break;

  case 49:
#line 159 "fir_parser.y"
                                            { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1837 "fir_parser.tab.c"
    break;

  case 50:
#line 160 "fir_parser.y"
                                            { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1843 "fir_parser.tab.c"
    break;

  case 51:
#line 163 "fir_parser.y"
                                { (yyval.sequence) = new cdk::sequence_node(LINE); }
#line 1849 "fir_parser.tab.c"
    break;

  case 52:
#line 164 "fir_parser.y"
                                { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1855 "fir_parser.tab.c"
    break;

  case 53:
#line 168 "fir_parser.y"
                                                                          { (yyval.node) = new fir::if_node(LINE, (yyvsp[-2].expression), (yyvsp[0].node)); }
#line 1861 "fir_parser.tab.c"
    break;

  case 54:
#line 169 "fir_parser.y"
                                                                          { (yyval.node) = new fir::if_else_node(LINE, (yyvsp[-4].expression), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1867 "fir_parser.tab.c"
    break;

  case 55:
#line 170 "fir_parser.y"
                                                                          { (yyval.node) = new fir::while_node(LINE, (yyvsp[-2].expression), (yyvsp[0].node), nullptr); }
#line 1873 "fir_parser.tab.c"
    break;

  case 56:
#line 171 "fir_parser.y"
                                                                          { (yyval.node) = new fir::while_node(LINE, (yyvsp[-4].expression), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1879 "fir_parser.tab.c"
    break;

  case 57:
#line 172 "fir_parser.y"
                                                                          { (yyval.node) = (yyvsp[0].block); }
#line 1885 "fir_parser.tab.c"
    break;

  case 58:
#line 173 "fir_parser.y"
                                                                          { (yyval.node) = new fir::return_node(LINE); }
#line 1891 "fir_parser.tab.c"
    break;

  case 59:
#line 174 "fir_parser.y"
                                                                          { (yyval.node) = new fir::restart_node(LINE); }
#line 1897 "fir_parser.tab.c"
    break;

  case 60:
#line 175 "fir_parser.y"
                                                                          { (yyval.node) = new fir::restart_node(LINE, (yyvsp[-1].i)); }
#line 1903 "fir_parser.tab.c"
    break;

  case 61:
#line 176 "fir_parser.y"
                                                                          { (yyval.node) = new fir::leave_node(LINE); }
#line 1909 "fir_parser.tab.c"
    break;

  case 62:
#line 177 "fir_parser.y"
                                                                          { (yyval.node) = new fir::leave_node(LINE, (yyvsp[-1].i)); }
#line 1915 "fir_parser.tab.c"
    break;

  case 63:
#line 178 "fir_parser.y"
                                                                          { (yyval.node) = new fir::print_node(LINE, (yyvsp[-1].sequence)); }
#line 1921 "fir_parser.tab.c"
    break;

  case 64:
#line 179 "fir_parser.y"
                                                                          { (yyval.node) = new fir::print_node(LINE, (yyvsp[-1].sequence), true); }
#line 1927 "fir_parser.tab.c"
    break;

  case 65:
#line 180 "fir_parser.y"
                                                                          { (yyval.node) = new fir::evaluation_node(LINE, (yyvsp[-1].expression)); }
#line 1933 "fir_parser.tab.c"
    break;

  case 66:
#line 183 "fir_parser.y"
                                              { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression)); }
#line 1939 "fir_parser.tab.c"
    break;

  case 67:
#line 184 "fir_parser.y"
                                              { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression), (yyvsp[-2].sequence)); }
#line 1945 "fir_parser.tab.c"
    break;

  case 68:
#line 187 "fir_parser.y"
                               { (yyval.sequence) = new cdk::sequence_node(LINE); }
#line 1951 "fir_parser.tab.c"
    break;

  case 69:
#line 188 "fir_parser.y"
                               { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1957 "fir_parser.tab.c"
    break;

  case 70:
#line 191 "fir_parser.y"
                                             { (yyval.expression) = (yyvsp[0].expression); }
#line 1963 "fir_parser.tab.c"
    break;

  case 71:
#line 192 "fir_parser.y"
                                             { (yyval.expression) = (yyvsp[0].expression); }
#line 1969 "fir_parser.tab.c"
    break;

  case 72:
#line 193 "fir_parser.y"
                                             { (yyval.expression) = new cdk::string_node(LINE, (yyvsp[0].s)); }
#line 1975 "fir_parser.tab.c"
    break;

  case 73:
#line 194 "fir_parser.y"
                                             { (yyval.expression) = (yyvsp[0].expression); }
#line 1981 "fir_parser.tab.c"
    break;

  case 74:
#line 196 "fir_parser.y"
                                             { (yyval.expression) = new cdk::rvalue_node(LINE, (yyvsp[0].lvalue)); }
#line 1987 "fir_parser.tab.c"
    break;

  case 75:
#line 198 "fir_parser.y"
                                             { (yyval.expression) = new cdk::assignment_node(LINE, (yyvsp[-2].lvalue), (yyvsp[0].expression)); }
#line 1993 "fir_parser.tab.c"
    break;

  case 76:
#line 200 "fir_parser.y"
                                             { (yyval.expression) = new cdk::add_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1999 "fir_parser.tab.c"
    break;

  case 77:
#line 201 "fir_parser.y"
                                             { (yyval.expression) = new cdk::sub_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2005 "fir_parser.tab.c"
    break;

  case 78:
#line 202 "fir_parser.y"
                                             { (yyval.expression) = new cdk::mul_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2011 "fir_parser.tab.c"
    break;

  case 79:
#line 203 "fir_parser.y"
                                             { (yyval.expression) = new cdk::div_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2017 "fir_parser.tab.c"
    break;

  case 80:
#line 204 "fir_parser.y"
                                             { (yyval.expression) = new cdk::mod_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2023 "fir_parser.tab.c"
    break;

  case 81:
#line 206 "fir_parser.y"
                                              { (yyval.expression) = new cdk::lt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2029 "fir_parser.tab.c"
    break;

  case 82:
#line 207 "fir_parser.y"
                                              { (yyval.expression) = new cdk::le_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2035 "fir_parser.tab.c"
    break;

  case 83:
#line 208 "fir_parser.y"
                                              { (yyval.expression) = new cdk::eq_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2041 "fir_parser.tab.c"
    break;

  case 84:
#line 209 "fir_parser.y"
                                              { (yyval.expression) = new cdk::ge_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2047 "fir_parser.tab.c"
    break;

  case 85:
#line 210 "fir_parser.y"
                                              { (yyval.expression) = new cdk::gt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2053 "fir_parser.tab.c"
    break;

  case 86:
#line 211 "fir_parser.y"
                                              { (yyval.expression) = new cdk::ne_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2059 "fir_parser.tab.c"
    break;

  case 87:
#line 212 "fir_parser.y"
                                              { (yyval.expression) = new cdk::or_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2065 "fir_parser.tab.c"
    break;

  case 88:
#line 213 "fir_parser.y"
                                              { (yyval.expression) = new cdk::and_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2071 "fir_parser.tab.c"
    break;

  case 89:
#line 215 "fir_parser.y"
                                                { (yyval.expression) = new fir::identity_node(LINE, (yyvsp[0].expression)); }
#line 2077 "fir_parser.tab.c"
    break;

  case 90:
#line 216 "fir_parser.y"
                                                { (yyval.expression) = new cdk::neg_node(LINE, (yyvsp[0].expression)); }
#line 2083 "fir_parser.tab.c"
    break;

  case 91:
#line 217 "fir_parser.y"
                                                 { (yyval.expression) = new cdk::not_node(LINE, (yyvsp[0].expression)); }
#line 2089 "fir_parser.tab.c"
    break;

  case 92:
#line 219 "fir_parser.y"
                                                       { (yyval.expression) = new fir::read_node(LINE); }
#line 2095 "fir_parser.tab.c"
    break;

  case 93:
#line 220 "fir_parser.y"
                                                       { (yyval.expression) = new fir::function_call_node(LINE, *(yyvsp[-3].s), (yyvsp[-1].sequence)); delete (yyvsp[-3].s); }
#line 2101 "fir_parser.tab.c"
    break;

  case 94:
#line 221 "fir_parser.y"
                                                       { (yyval.expression) = new fir::sizeof_node(LINE, (yyvsp[-1].expression)); }
#line 2107 "fir_parser.tab.c"
    break;

  case 95:
#line 222 "fir_parser.y"
                                                       { (yyval.expression) = new fir::stack_alloc_node(LINE, (yyvsp[-1].expression)); }
#line 2113 "fir_parser.tab.c"
    break;

  case 96:
#line 223 "fir_parser.y"
                                                       { (yyval.expression) = (yyvsp[-1].expression); }
#line 2119 "fir_parser.tab.c"
    break;

  case 97:
#line 224 "fir_parser.y"
                                                       { (yyval.expression) = new fir::address_of_node(LINE, (yyvsp[-1].lvalue)); }
#line 2125 "fir_parser.tab.c"
    break;

  case 98:
#line 227 "fir_parser.y"
                                                                          { (yyval.lvalue) = new cdk::variable_node(LINE, *(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2131 "fir_parser.tab.c"
    break;

  case 99:
#line 228 "fir_parser.y"
                                                                          { (yyval.lvalue) = new fir::index_node(LINE, new cdk::rvalue_node(LINE, (yyvsp[-3].lvalue)), (yyvsp[-1].expression)); }
#line 2137 "fir_parser.tab.c"
    break;

  case 100:
#line 229 "fir_parser.y"
                                                                          { (yyval.lvalue) = new fir::index_node(LINE, (yyvsp[-4].expression), (yyvsp[-1].expression)); }
#line 2143 "fir_parser.tab.c"
    break;

  case 101:
#line 230 "fir_parser.y"
                                                                          { (yyval.lvalue) = new fir::index_node(LINE, new fir::function_call_node(LINE, *(yyvsp[-6].s), (yyvsp[-4].sequence)), (yyvsp[-1].expression)); }
#line 2149 "fir_parser.tab.c"
    break;

  case 102:
#line 233 "fir_parser.y"
                           { (yyval.expression) = new cdk::integer_node(LINE, (yyvsp[0].i)); }
#line 2155 "fir_parser.tab.c"
    break;

  case 103:
#line 236 "fir_parser.y"
                           { (yyval.expression) = new cdk::double_node(LINE, (yyvsp[0].d)); }
#line 2161 "fir_parser.tab.c"
    break;

  case 104:
#line 239 "fir_parser.y"
                           { (yyval.expression) = new fir::null_node(LINE); }
#line 2167 "fir_parser.tab.c"
    break;

  case 105:
#line 242 "fir_parser.y"
                           { (yyval.s) = (yyvsp[0].s); }
#line 2173 "fir_parser.tab.c"
    break;

  case 106:
#line 243 "fir_parser.y"
                           { (yyval.s) = (yyvsp[-1].s); (yyval.s)->append(*(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2179 "fir_parser.tab.c"
    break;


#line 2183 "fir_parser.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
      yyerror (compiler, YY_("syntax error"));
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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
        yyerror (compiler, yymsgp);
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
                      yytoken, &yylval, compiler);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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
                  yystos[yystate], yyvsp, compiler);
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
  yyerror (compiler, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, compiler);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, compiler);
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
#line 246 "fir_parser.y"

