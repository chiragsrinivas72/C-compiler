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
#line 1 "icg_quad_switch.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <ctype.h>

  void print_message();
  int top=-1;
  void yyerror(char *);
  extern FILE *yyin;
  #define YYSTYPE char*
  typedef struct quadruples
  {
    char *op;
    char *arg1;
    char *arg2;
    char *res;
  }quad;
  int quadlen = 0;
  quad q[100];

#line 92 "y.tab.c"

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
    ID = 258,
    NUM = 259,
    T_lt = 260,
    T_gt = 261,
    T_lteq = 262,
    T_gteq = 263,
    T_neq = 264,
    T_noteq = 265,
    T_eqeq = 266,
    T_and = 267,
    T_or = 268,
    T_incr = 269,
    T_decr = 270,
    T_not = 271,
    T_eq = 272,
    INT = 273,
    CHAR = 274,
    FLOAT = 275,
    VOID = 276,
    H = 277,
    MAINTOK = 278,
    INCLUDE = 279,
    BREAK = 280,
    CONTINUE = 281,
    IF = 282,
    ELSE = 283,
    COUT = 284,
    STRING = 285,
    PRINTF = 286,
    T_ques = 287,
    T_colon = 288,
    T_op = 289,
    T_cp = 290,
    T_ob = 291,
    T_cb = 292,
    T_cop = 293,
    T_ccp = 294,
    T_comma = 295,
    T_dims = 296,
    FLNUM = 297,
    CHARACTER = 298,
    SWITCH = 299,
    CASE = 300,
    DEFAULT = 301,
    T_pl = 302,
    T_min = 303,
    T_mul = 304,
    T_div = 305
  };
#endif
/* Tokens.  */
#define ID 258
#define NUM 259
#define T_lt 260
#define T_gt 261
#define T_lteq 262
#define T_gteq 263
#define T_neq 264
#define T_noteq 265
#define T_eqeq 266
#define T_and 267
#define T_or 268
#define T_incr 269
#define T_decr 270
#define T_not 271
#define T_eq 272
#define INT 273
#define CHAR 274
#define FLOAT 275
#define VOID 276
#define H 277
#define MAINTOK 278
#define INCLUDE 279
#define BREAK 280
#define CONTINUE 281
#define IF 282
#define ELSE 283
#define COUT 284
#define STRING 285
#define PRINTF 286
#define T_ques 287
#define T_colon 288
#define T_op 289
#define T_cp 290
#define T_ob 291
#define T_cb 292
#define T_cop 293
#define T_ccp 294
#define T_comma 295
#define T_dims 296
#define FLNUM 297
#define CHARACTER 298
#define SWITCH 299
#define CASE 300
#define DEFAULT 301
#define T_pl 302
#define T_min 303
#define T_mul 304
#define T_div 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   265

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  176

#define YYUNDEFTOK  2
#define YYMAXUTOK   305


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
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
static const yytype_uint8 yyrline[] =
{
       0,    33,    33,    37,    41,    42,    46,    50,    51,    52,
      53,    54,    58,    59,    59,    60,    64,    64,    68,    72,
      72,    72,    76,    77,    81,    81,    81,    82,    86,    86,
      87,    87,    91,    94,    95,   100,   101,   102,   106,   107,
     108,   109,   113,   114,   115,   118,   119,   119,   120,   120,
     121,   124,   124,   125,   125,   126,   126,   127,   127,   128,
     128,   129,   129,   130,   131,   134,   137,   141,   141,   141,
     142,   142,   142,   143,   143,   143,   144,   144,   144,   148,
     149,   149,   150,   150,   154,   155,   155,   156,   156,   160,
     161,   161,   162,   162,   166,   167,   171,   175,   176,   177,
     178,   182,   183,   184
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "T_lt", "T_gt", "T_lteq",
  "T_gteq", "T_neq", "T_noteq", "T_eqeq", "T_and", "T_or", "T_incr",
  "T_decr", "T_not", "T_eq", "INT", "CHAR", "FLOAT", "VOID", "H",
  "MAINTOK", "INCLUDE", "BREAK", "CONTINUE", "IF", "ELSE", "COUT",
  "STRING", "PRINTF", "T_ques", "T_colon", "T_op", "T_cp", "T_ob", "T_cb",
  "T_cop", "T_ccp", "T_comma", "T_dims", "FLNUM", "CHARACTER", "SWITCH",
  "CASE", "DEFAULT", "T_pl", "T_min", "T_mul", "T_div", "';'", "$accept",
  "S", "START", "MAIN", "BODY", "C", "LOOPS", "$@1", "IF_COND", "$@2",
  "ELSE_COND", "STMT_SWITCH", "$@3", "$@4", "SWITCHBODY", "CASES", "$@5",
  "$@6", "BREAKSTMT", "$@7", "$@8", "DEFAULTSTMT", "DE", "LOOPBODY",
  "LOOPC", "statement", "COND", "$@9", "$@10", "B", "$@11", "$@12", "$@13",
  "$@14", "$@15", "$@16", "F", "V", "ASSIGN_EXPR", "$@17", "$@18", "$@19",
  "$@20", "$@21", "$@22", "$@23", "$@24", "EXP", "$@25", "$@26", "ADDSUB",
  "$@27", "$@28", "TERM", "$@29", "$@30", "FACTOR", "PRINT", "LIT", "TYPE", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,    59
};
# endif

#define YYPACT_NINF (-148)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-84)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -16,    11,    41,  -148,    -4,  -148,    57,    -6,    54,    59,
    -148,    46,    46,     1,  -148,  -148,    38,  -148,  -148,  -148,
    -148,  -148,    68,    70,     6,  -148,  -148,  -148,   114,  -148,
      65,  -148,    56,  -148,    31,  -148,    12,  -148,  -148,    92,
      77,  -148,    30,    83,    18,  -148,    82,  -148,  -148,    78,
     103,  -148,  -148,  -148,  -148,  -148,  -148,  -148,   125,    -2,
    -148,     4,     4,   108,    13,   119,   109,  -148,     6,  -148,
      72,  -148,     6,     6,     6,     6,     6,     6,  -148,   132,
     110,   116,  -148,   115,  -148,  -148,   141,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,    25,   221,  -148,  -148,   104,    31,
     -24,   -22,    12,    12,  -148,  -148,     6,  -148,   142,   156,
    -148,    72,    30,    30,    77,    77,    77,    77,    77,    77,
    -148,  -148,   143,   113,  -148,    31,     6,  -148,   128,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,   129,
    -148,  -148,   117,  -148,    31,   136,   152,   126,  -148,  -148,
    -148,   168,   134,   133,   148,  -148,  -148,   147,  -148,  -148,
     150,     1,  -148,   172,     1,   130,  -148,   192,  -148,  -148,
    -148,   126,   137,  -148,   126,  -148
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,     0,     0,
       3,     0,     0,     0,     5,     4,     0,    97,    98,   101,
     102,   103,     0,     0,     0,    99,   100,    19,     0,    10,
      12,    15,     0,    42,    43,    79,    84,    89,    44,    94,
       0,    11,     0,     0,     0,    94,     0,     6,     8,     0,
       0,     9,    80,    82,    85,    87,    90,    92,     0,    70,
      66,     0,     0,     0,    45,    64,     0,    95,     0,     7,
       0,    14,     0,     0,     0,     0,     0,     0,    68,     0,
       0,     0,    50,     0,    16,    46,     0,    55,    53,    59,
      61,    57,    51,    96,     0,     0,    36,    18,     0,     0,
      79,    79,    86,    88,    91,    93,     0,    71,     0,     0,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,    41,     0,     0,    37,    69,     0,    74,     0,    17,
      47,    49,    56,    65,    54,    60,    62,    58,    52,     0,
      35,    39,     0,    40,    72,     0,     0,    27,    38,    75,
      77,     0,     0,    22,     0,    24,    21,     0,    23,    78,
       0,     0,    25,    34,     0,     0,    32,    30,    33,    28,
      26,    27,     0,    31,    27,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -148,  -148,  -148,  -148,   177,  -147,   -27,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -100,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,    73,  -148,   -28,   -43,  -148,  -148,    50,
    -148,  -148,  -148,  -148,  -148,  -148,    79,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,   -21,  -148,  -148,
      14,  -148,  -148,    47,  -148,  -148,    61,  -148,   -18,  -148
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    14,    28,    29,    50,    30,   111,
      71,    31,    46,   139,   152,   153,   160,   164,   170,   172,
     171,   158,   166,    97,   122,    32,    63,   112,    86,    64,
     119,   115,   114,   118,   116,   117,   132,    65,    33,    58,
     106,    79,   126,    80,   145,    81,   154,    34,    72,    73,
      35,    74,    75,    36,    76,    77,    37,    38,    39,    40
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    48,    16,    44,    17,    18,    45,    60,     1,    17,
      18,   -81,     8,   -83,   163,     9,     4,   167,     6,    19,
      20,    21,    59,    52,    53,    85,   -48,   -81,    22,   -83,
      52,    53,    23,    60,   -76,    24,    52,    53,    62,   -73,
      24,     5,    98,    25,    26,    27,    61,    94,    25,    26,
      45,    99,    99,    67,    45,    45,    45,    45,    45,    45,
     120,    56,    57,     7,    62,    54,    55,   123,   121,   130,
     131,   173,    54,    55,   175,    17,    18,    11,    54,    55,
      17,    18,    12,    98,    13,   125,   100,   101,    45,    41,
      19,    20,    21,   -13,   142,   141,   133,   133,   135,   136,
     137,   138,    42,    23,    43,   144,    24,    51,    45,   -67,
      95,    82,    83,    66,    25,    26,    68,    17,    18,    25,
      26,   102,   103,    96,    87,    88,    89,    90,    91,    69,
      92,    70,    19,    20,    21,    49,    48,   104,   105,    49,
      48,    22,    78,    84,    93,    23,    17,    18,    24,   107,
     110,   108,   109,    47,   113,   124,    25,    26,    27,   127,
     128,    19,    20,    21,   143,   146,   149,   147,   148,   150,
      22,   151,   155,   156,    23,    17,    18,    24,   159,   157,
     161,   168,   140,   162,   129,    25,    26,    27,   174,    15,
      19,    20,    21,     0,   134,    17,    18,   165,     0,    22,
       0,     0,     0,    23,     0,     0,    24,     0,     0,     0,
      19,    20,    21,     0,    25,    26,    27,   169,     0,    22,
       0,     0,     0,    23,    17,    18,    24,     0,     0,     0,
       0,     0,     0,     0,    25,    26,    27,     0,     0,    19,
      20,    21,     0,     0,     0,     0,     0,     0,    22,     0,
       0,     0,    23,     0,     0,    24,     0,     0,     0,     0,
       0,     0,     0,    25,    26,    27
};

static const yytype_int16 yycheck[] =
{
      28,    28,     1,    24,     3,     4,    24,     3,    24,     3,
       4,    35,    18,    35,   161,    21,     5,   164,    22,    18,
      19,    20,    40,     5,     6,    12,    13,    51,    27,    51,
       5,     6,    31,     3,    36,    34,     5,     6,    34,    41,
      34,     0,    70,    42,    43,    44,    16,    68,    42,    43,
      68,    72,    73,    35,    72,    73,    74,    75,    76,    77,
      35,    49,    50,     6,    34,    47,    48,    95,    95,   112,
     113,   171,    47,    48,   174,     3,     4,    23,    47,    48,
       3,     4,    23,   111,    38,   106,    72,    73,   106,    51,
      18,    19,    20,    28,   122,   122,   114,   115,   116,   117,
     118,   119,    34,    31,    34,   126,    34,    51,   126,    17,
      38,    61,    62,    30,    42,    43,    34,     3,     4,    42,
      43,    74,    75,    51,     5,     6,     7,     8,     9,    51,
      11,    28,    18,    19,    20,   163,   163,    76,    77,   167,
     167,    27,    17,    35,    35,    31,     3,     4,    34,    17,
      35,    41,    36,    39,    13,    51,    42,    43,    44,    17,
       4,    18,    19,    20,    51,    37,    30,    38,    51,    17,
      27,    45,     4,    39,    31,     3,     4,    34,    30,    46,
      33,    51,    39,    33,   111,    42,    43,    44,    51,    12,
      18,    19,    20,    -1,   115,     3,     4,    25,    -1,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    -1,    -1,    -1,
      18,    19,    20,    -1,    42,    43,    44,    25,    -1,    27,
      -1,    -1,    -1,    31,     3,     4,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    -1,    -1,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    24,    53,    54,     5,     0,    22,     6,    18,    21,
      55,    23,    23,    38,    56,    56,     1,     3,     4,    18,
      19,    20,    27,    31,    34,    42,    43,    44,    57,    58,
      60,    63,    77,    90,    99,   102,   105,   108,   109,   110,
     111,    51,    34,    34,    99,   110,    64,    39,    58,    77,
      59,    51,     5,     6,    47,    48,    49,    50,    91,   110,
       3,    16,    34,    78,    81,    89,    30,    35,    34,    51,
      28,    62,   100,   101,   103,   104,   106,   107,    17,    93,
      95,    97,    81,    81,    35,    12,    80,     5,     6,     7,
       8,     9,    11,    35,    99,    38,    51,    75,    77,    99,
     102,   102,   105,   105,   108,   108,    92,    17,    41,    36,
      35,    61,    79,    13,    84,    83,    86,    87,    85,    82,
      35,    58,    76,    77,    51,    99,    94,    17,     4,    75,
      78,    78,    88,   110,    88,   110,   110,   110,   110,    65,
      39,    58,    77,    51,    99,    96,    37,    38,    51,    30,
      17,    45,    66,    67,    98,     4,    39,    46,    73,    30,
      68,    33,    33,    57,    69,    25,    74,    57,    51,    25,
      70,    72,    71,    67,    51,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    55,    55,    56,    57,    57,    57,
      57,    57,    58,    59,    58,    58,    61,    60,    62,    64,
      65,    63,    66,    66,    68,    69,    67,    67,    71,    70,
      72,    70,    73,    74,    74,    75,    75,    75,    76,    76,
      76,    76,    77,    77,    77,    78,    79,    78,    80,    78,
      78,    82,    81,    83,    81,    84,    81,    85,    81,    86,
      81,    87,    81,    81,    81,    88,    89,    91,    92,    90,
      93,    94,    90,    95,    96,    90,    97,    98,    90,    99,
     100,    99,   101,    99,   102,   103,   102,   104,   102,   105,
     106,   105,   107,   105,   108,   108,   109,   110,   110,   110,
     110,   111,   111,   111
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     5,     3,     3,     3,     3,     2,     2,
       1,     2,     1,     0,     3,     1,     0,     6,     2,     0,
       0,     9,     1,     2,     0,     0,     7,     0,     0,     4,
       0,     2,     4,     2,     0,     3,     1,     2,     3,     2,
       2,     1,     1,     1,     1,     1,     0,     4,     0,     4,
       2,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     3,     1,     1,     1,     0,     0,     5,
       0,     0,     6,     0,     0,     7,     0,     0,     9,     1,
       0,     4,     0,     4,     1,     0,     4,     0,     4,     1,
       0,     4,     0,     4,     1,     3,     4,     1,     1,     1,
       1,     1,     1,     1
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
#line 33 "icg_quad_switch.y"
            {print_message();}
#line 1563 "y.tab.c"
    break;

  case 11:
#line 54 "icg_quad_switch.y"
                  {yyerrok; yyclearin; }
#line 1569 "y.tab.c"
    break;

  case 12:
#line 58 "icg_quad_switch.y"
                {if3();}
#line 1575 "y.tab.c"
    break;

  case 13:
#line 59 "icg_quad_switch.y"
              {ifelse2();}
#line 1581 "y.tab.c"
    break;

  case 16:
#line 64 "icg_quad_switch.y"
                        {ifelse1();}
#line 1587 "y.tab.c"
    break;

  case 18:
#line 68 "icg_quad_switch.y"
                   {ifelse3();}
#line 1593 "y.tab.c"
    break;

  case 19:
#line 72 "icg_quad_switch.y"
            {switch_start();}
#line 1599 "y.tab.c"
    break;

  case 20:
#line 72 "icg_quad_switch.y"
                                            {switch_copy_var();}
#line 1605 "y.tab.c"
    break;

  case 21:
#line 72 "icg_quad_switch.y"
                                                                                       {switch_end();}
#line 1611 "y.tab.c"
    break;

  case 24:
#line 81 "icg_quad_switch.y"
               {push();}
#line 1617 "y.tab.c"
    break;

  case 25:
#line 81 "icg_quad_switch.y"
                                 {case_start();}
#line 1623 "y.tab.c"
    break;

  case 28:
#line 86 "icg_quad_switch.y"
           {case_end();}
#line 1629 "y.tab.c"
    break;

  case 30:
#line 87 "icg_quad_switch.y"
          {case_end_without_break();}
#line 1635 "y.tab.c"
    break;

  case 32:
#line 91 "icg_quad_switch.y"
                          {default_end();}
#line 1641 "y.tab.c"
    break;

  case 45:
#line 118 "icg_quad_switch.y"
          {codegen_assigna();}
#line 1647 "y.tab.c"
    break;

  case 46:
#line 119 "icg_quad_switch.y"
               {codegen_assigna();}
#line 1653 "y.tab.c"
    break;

  case 48:
#line 120 "icg_quad_switch.y"
          {codegen_assigna();}
#line 1659 "y.tab.c"
    break;

  case 50:
#line 121 "icg_quad_switch.y"
               {codegen_assigna();}
#line 1665 "y.tab.c"
    break;

  case 51:
#line 124 "icg_quad_switch.y"
            {push();}
#line 1671 "y.tab.c"
    break;

  case 52:
#line 124 "icg_quad_switch.y"
                         {pusha();}
#line 1677 "y.tab.c"
    break;

  case 53:
#line 125 "icg_quad_switch.y"
          {push();}
#line 1683 "y.tab.c"
    break;

  case 55:
#line 126 "icg_quad_switch.y"
          {push();}
#line 1689 "y.tab.c"
    break;

  case 57:
#line 127 "icg_quad_switch.y"
           {push();}
#line 1695 "y.tab.c"
    break;

  case 58:
#line 127 "icg_quad_switch.y"
                        {pusha();}
#line 1701 "y.tab.c"
    break;

  case 59:
#line 128 "icg_quad_switch.y"
            {push();}
#line 1707 "y.tab.c"
    break;

  case 60:
#line 128 "icg_quad_switch.y"
                         {pusha();}
#line 1713 "y.tab.c"
    break;

  case 61:
#line 129 "icg_quad_switch.y"
            {push();}
#line 1719 "y.tab.c"
    break;

  case 62:
#line 129 "icg_quad_switch.y"
                         {pusha();}
#line 1725 "y.tab.c"
    break;

  case 64:
#line 131 "icg_quad_switch.y"
      {pushab();}
#line 1731 "y.tab.c"
    break;

  case 65:
#line 134 "icg_quad_switch.y"
       {pusha();}
#line 1737 "y.tab.c"
    break;

  case 66:
#line 137 "icg_quad_switch.y"
      {push();}
#line 1743 "y.tab.c"
    break;

  case 67:
#line 141 "icg_quad_switch.y"
          {push();}
#line 1749 "y.tab.c"
    break;

  case 68:
#line 141 "icg_quad_switch.y"
                         {push();}
#line 1755 "y.tab.c"
    break;

  case 69:
#line 141 "icg_quad_switch.y"
                                       {codegen_assign();}
#line 1761 "y.tab.c"
    break;

  case 70:
#line 142 "icg_quad_switch.y"
               {push();}
#line 1767 "y.tab.c"
    break;

  case 71:
#line 142 "icg_quad_switch.y"
                              {push();}
#line 1773 "y.tab.c"
    break;

  case 72:
#line 142 "icg_quad_switch.y"
                                            {codegen_assign();}
#line 1779 "y.tab.c"
    break;

  case 73:
#line 143 "icg_quad_switch.y"
               {push();}
#line 1785 "y.tab.c"
    break;

  case 74:
#line 143 "icg_quad_switch.y"
                                     {push();}
#line 1791 "y.tab.c"
    break;

  case 75:
#line 143 "icg_quad_switch.y"
                                                     {push(); codegen_assign();}
#line 1797 "y.tab.c"
    break;

  case 76:
#line 144 "icg_quad_switch.y"
               {push();}
#line 1803 "y.tab.c"
    break;

  case 77:
#line 144 "icg_quad_switch.y"
                                            {push();}
#line 1809 "y.tab.c"
    break;

  case 78:
#line 144 "icg_quad_switch.y"
                                                            {push(); codegen_assign();}
#line 1815 "y.tab.c"
    break;

  case 80:
#line 149 "icg_quad_switch.y"
                   {push();}
#line 1821 "y.tab.c"
    break;

  case 81:
#line 149 "icg_quad_switch.y"
                                    {codegen();}
#line 1827 "y.tab.c"
    break;

  case 82:
#line 150 "icg_quad_switch.y"
                   {push();}
#line 1833 "y.tab.c"
    break;

  case 83:
#line 150 "icg_quad_switch.y"
                                    {codegen();}
#line 1839 "y.tab.c"
    break;

  case 85:
#line 155 "icg_quad_switch.y"
               {push();}
#line 1845 "y.tab.c"
    break;

  case 86:
#line 155 "icg_quad_switch.y"
                              {codegen();}
#line 1851 "y.tab.c"
    break;

  case 87:
#line 156 "icg_quad_switch.y"
                {push();}
#line 1857 "y.tab.c"
    break;

  case 88:
#line 156 "icg_quad_switch.y"
                               {codegen();}
#line 1863 "y.tab.c"
    break;

  case 90:
#line 161 "icg_quad_switch.y"
                 {push();}
#line 1869 "y.tab.c"
    break;

  case 91:
#line 161 "icg_quad_switch.y"
                                  {codegen();}
#line 1875 "y.tab.c"
    break;

  case 92:
#line 162 "icg_quad_switch.y"
                 {push();}
#line 1881 "y.tab.c"
    break;

  case 93:
#line 162 "icg_quad_switch.y"
                                  {codegen();}
#line 1887 "y.tab.c"
    break;

  case 97:
#line 175 "icg_quad_switch.y"
         {push();}
#line 1893 "y.tab.c"
    break;

  case 98:
#line 176 "icg_quad_switch.y"
          {push();}
#line 1899 "y.tab.c"
    break;

  case 99:
#line 177 "icg_quad_switch.y"
            {push();}
#line 1905 "y.tab.c"
    break;

  case 100:
#line 178 "icg_quad_switch.y"
                {push();}
#line 1911 "y.tab.c"
    break;


#line 1915 "y.tab.c"

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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
#line 187 "icg_quad_switch.y"


#include "lex.yy.c"
#include<ctype.h>
char st[100][100];

char i_[2]="0";
int temp_i=0;
char tmp_i[3];
char temp[2]="t";
int label[20];
int lnum=0;
int ltop=0;
int switchlabel[10];
int switch_lbl = 0;
int chk = 0;
char switch_var[20];

int main(int argc,char *args[])
{

    yyin = fopen(args[1],"r");
    switch_lbl = -1;
    chk = 0;

    if(!yyparse())  //yyparse-> 0 if success
    {
        printf("Parsing Complete\n");
        printf("---------------------Quadruples-------------------------\n\n");
        printf("Operator \t Arg1 \t\t Arg2 \t\t Result \n");
        int i;
        for(i=0;i<quadlen;i++)
        {
            printf("%-8s \t %-8s \t %-8s \t %-6s \n",q[i].op,q[i].arg1,q[i].arg2,q[i].res);
        }
    }
    else
    {
        printf("Parsing failed\n");
    }

    write_to_file();

    fclose(yyin);
    return 0;
}

void print_message()
{
    if(chk != 1)
        printf("\n\nNo Syntax Errors Detected.\n");
}

void yyerror(char *s)
{ 
    printf("Error : %s at %d \n",yytext,yylineno);
    chk = 1;
}

void write_to_file()
{
    FILE *ptr = fopen("inp_codeopt.txt","w");
    int i;
    for(i=0;i<quadlen;i++)
    {
        fprintf(ptr,"%s %s %s %s\n",q[i].op,q[i].arg1,q[i].arg2,q[i].res);
    }
    fclose(ptr);
}

push()
{
    strcpy(st[++top],yytext);
}
pusha()
{
    strcpy(st[++top],"  ");
}

pushab()
{
    strcpy(st[++top],"  ");
    strcpy(st[++top],"  ");
    strcpy(st[++top],"  ");
}

codegen()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = %s %s %s\n",temp,st[top-2],st[top-1],st[top]);

    q[quadlen].op = (char*)malloc(sizeof(char)*strlen(st[top-1]));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top-2]));
    q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,st[top-1]);
    strcpy(q[quadlen].arg1,st[top-2]);
    strcpy(q[quadlen].arg2,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;

    top-=2;
    strcpy(st[top],temp);

    temp_i++;
}
codegen_assigna()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = %s %s %s %s\n",temp,st[top-3],st[top-2],st[top-1],st[top]);

    if(strlen(st[top])==1)
    {
        
        char t[20];
        strcpy(t,st[top-2]);
        strcat(t,st[top-1]);
        q[quadlen].op = (char*)malloc(sizeof(char)*strlen(t));
        q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top-3]));
        q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top]));
        q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
        strcpy(q[quadlen].op,t);
        strcpy(q[quadlen].arg1,st[top-3]);
        strcpy(q[quadlen].arg2,st[top]);
        strcpy(q[quadlen].res,temp);
        quadlen++;
        
    }
    else
    {
        q[quadlen].op = (char*)malloc(sizeof(char)*strlen(st[top-2]));
        q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top-3]));
        q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top-1]));
        q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
        strcpy(q[quadlen].op,st[top-2]);
        strcpy(q[quadlen].arg1,st[top-3]);
        strcpy(q[quadlen].arg2,st[top-1]);
        strcpy(q[quadlen].res,temp);
        quadlen++;
    }
    top-=4;

    temp_i++;
    strcpy(st[++top],temp);
}

codegen_assign()
{
    printf("%s = %s\n",st[top-3],st[top]);

    q[quadlen].op = (char*)malloc(sizeof(char));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(st[top-3]));
    strcpy(q[quadlen].op,"=");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,st[top-3]);
    quadlen++;

    top-=2;
}

switch_start()
{
    ++switch_lbl;
}

switch_copy_var()
{
    strcpy(switch_var,st[top]);
}

case_start()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);

    printf("%s = %s == %s\n",temp,switch_var,st[top]);
    strcpy(st[++top],temp);

    q[quadlen].op = (char*)malloc(sizeof(char)*strlen("=="));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(switch_var));
    q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"==");
    strcpy(q[quadlen].arg1,switch_var);
    strcpy(q[quadlen].arg2,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;

    temp_i++;

    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);

    printf("%s = not %s\n",temp,st[top]);

    q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"not");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;

    printf("if %s goto L%d\n",temp,lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"if");
    strcpy(q[quadlen].arg1,temp);
    char x[10];
    sprintf(x,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;

    temp_i++;
    label[++ltop]=lnum;
    top-=2;

}

case_end()
{
    printf("goto next%d\n\n",switch_lbl);

    q[quadlen].op = (char*)malloc(sizeof(char)*10);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*10);
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",switch_lbl);
    char l[]="next";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;

    int x = lnum;
    printf("L%d: \n",x);
    q[quadlen].op = (char*)malloc(sizeof(char)*10);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*10);
    strcpy(q[quadlen].op,"Label");
    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;

    label[++ltop]=lnum;
    ++lnum;
}
case_end_without_break()
{
    int x = lnum;
    printf("\nL%d: \n",x);
    q[quadlen].op = (char*)malloc(sizeof(char)*10);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*10);
    strcpy(q[quadlen].op,"Label");
    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;

    label[++ltop]=lnum;
    ++lnum;
}

default_end()
{
    printf("goto next%d\n",switch_lbl);

    q[quadlen].op = (char*)malloc(sizeof(char)*10);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*10);
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",switch_lbl);
    char l[]="next";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;
}

switch_end()
{
    int x = switch_lbl;
    printf("\nnext%d: \n",x);
    q[quadlen].op = (char*)malloc(sizeof(char)*10);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*10);
    strcpy(q[quadlen].op,"Label");
    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="next";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;
}

if3()
{
    int y;
    y=label[ltop--];
    printf("L%d: \n",y);

    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(y+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",y);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;

    lnum++;
}

ifelse1()
{
    lnum++;
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = not %s\n",temp,st[top]);

    q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"not");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;

    printf("if %s goto L%d\n",temp,lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"if");
    strcpy(q[quadlen].arg1,temp);
    char x[10];
    sprintf(x,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;

    temp_i++;
    label[++ltop]=lnum;
}

ifelse2()
{
    int x;
    lnum++;
    x=label[ltop--];
    printf("goto L%d\n",lnum);

    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;

    printf("L%d: \n",x);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(x+2));
    strcpy(q[quadlen].op,"Label");
    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;

    label[++ltop]=lnum;
}

ifelse3()
{
    int y;
    y=label[ltop--];
    printf("L%d: \n",y);

    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(y+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",y);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;

    lnum++;
}
