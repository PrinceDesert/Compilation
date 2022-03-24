/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "ex4.y"

	#include <ctype.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <stdbool.h>
	#include <stdarg.h>
	#include <string.h>
	#include <math.h>
	#include <limits.h>
	#include "typesynth.h"
	#include "stable.h"
	
	int yylex(void);
	void yyerror(char const *);
	
	// Check type
	int is_same_type(size_t size_args, type_synth $1, type_synth $3, ...); /* $1 == BOOLEAN_T && $3 == BOOLEAN_T && value == BOOLEAN_T*/
	// Label asm
	static unsigned int new_label_number();
	static void create_label(char *buf, size_t buf_size, const char *format, ...);
	void fail_with(const char *format, ...);
	
	#define BUFFER_SIZE_MAX 256
	/**
		Dans le code assembleur :
		jmpc, le bit c est positionné (== 1), alors jumpc (écrit dans la doc de asm), pareil pour le bit z
	*/
	char lbl_s_errordiv[BUFFER_SIZE_MAX];
	symbol_table_entry *symbol;

#line 102 "ex4.tab.c"

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

#include "ex4.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_BOOLEAN = 4,                    /* BOOLEAN  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_TYPE = 6,                       /* TYPE  */
  YYSYMBOL_AND = 7,                        /* AND  */
  YYSYMBOL_OR = 8,                         /* OR  */
  YYSYMBOL_EQ = 9,                         /* EQ  */
  YYSYMBOL_NEQ = 10,                       /* NEQ  */
  YYSYMBOL_GT = 11,                        /* GT  */
  YYSYMBOL_LT = 12,                        /* LT  */
  YYSYMBOL_13_ = 13,                       /* '+'  */
  YYSYMBOL_14_ = 14,                       /* '-'  */
  YYSYMBOL_15_ = 15,                       /* '*'  */
  YYSYMBOL_16_ = 16,                       /* '/'  */
  YYSYMBOL_17_ = 17,                       /* '%'  */
  YYSYMBOL_18_ = 18,                       /* '^'  */
  YYSYMBOL_19_n_ = 19,                     /* '\n'  */
  YYSYMBOL_20_ = 20,                       /* ';'  */
  YYSYMBOL_21_ = 21,                       /* '='  */
  YYSYMBOL_22_ = 22,                       /* '('  */
  YYSYMBOL_23_ = 23,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 24,                  /* $accept  */
  YYSYMBOL_lignes = 25,                    /* lignes  */
  YYSYMBOL_decl = 26,                      /* decl  */
  YYSYMBOL_expr = 27                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   128

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  24
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  4
/* YYNRULES -- Number of rules.  */
#define YYNRULES  27
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  54

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   267


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      19,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    17,     2,     2,
      22,    23,    15,    13,     2,    14,     2,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    20,
       2,    21,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    18,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    71,    80,   109,   112,   124,   135,   147,   174,   208,
     215,   243,   271,   292,   313,   337,   361,   366
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "BOOLEAN",
  "ID", "TYPE", "AND", "OR", "EQ", "NEQ", "GT", "LT", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'^'", "'\\n'", "';'", "'='", "'('", "')'", "$accept",
  "lignes", "decl", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-14)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      29,   -10,   -14,   -14,     1,   -14,    33,     7,    -7,    49,
     -14,    26,    62,   -14,     8,   -14,    12,    93,   -14,    15,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,   -14,   -14,    33,   -14,   -14,   -14,   -14,   -14,
     104,   104,    27,    27,   110,   110,   -13,   -13,   -14,   -14,
     -14,   -14,    79,   -14
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    26,    27,     0,    10,     0,     0,     0,     0,
       4,     0,     0,     1,     0,     6,     0,     0,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,    11,     0,    13,     2,     8,     5,     3,
      22,    23,    20,    21,    24,    25,    14,    15,    16,    17,
      18,    19,     0,    12
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -14,   -14,    42,    -6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,     9
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      12,    17,    28,    29,    30,    31,    11,    13,    14,    10,
       2,     3,    18,     4,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    15,    36,    52,     6,
       1,    37,     2,     3,    39,     4,     2,     3,    24,    25,
      26,    27,    28,    29,    30,    31,    33,    34,     5,    16,
      19,     6,     0,     0,     0,     6,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     0,     0,     0,     0,    35,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,    53,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    38,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    26,    27,    28,    29,    30,    31
};

static const yytype_int8 yycheck[] =
{
       6,     7,    15,    16,    17,    18,     5,     0,     1,    19,
       3,     4,    19,     6,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    19,    19,    34,    22,
       1,    19,     3,     4,    19,     6,     3,     4,    11,    12,
      13,    14,    15,    16,    17,    18,    20,    21,    19,     7,
       1,    22,    -1,    -1,    -1,    22,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    23,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    20,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    13,    14,    15,    16,    17,    18
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     6,    19,    22,    25,    26,    27,
      19,     5,    27,     0,     1,    19,    26,    27,    19,     1,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    23,    19,    19,    19,    19,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    27,    20
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    24,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    26,    26,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    27,    27,    27,    27
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     2,     3,     2,     2,     3,     2,
       1,     3,     5,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* lignes: lignes error '\n'  */
#line 59 "ex4.y"
                                                { yyerrok; }
#line 1150 "ex4.tab.c"
    break;

  case 3: /* lignes: expr error '\n'  */
#line 60 "ex4.y"
                                                { yyerrok; }
#line 1156 "ex4.tab.c"
    break;

  case 4: /* lignes: error '\n'  */
#line 61 "ex4.y"
                                                { yyerrok; }
#line 1162 "ex4.tab.c"
    break;

  case 5: /* lignes: lignes expr '\n'  */
#line 62 "ex4.y"
                                                { /*printf("%d\n", stack[0]); stack_size = 0;*/ }
#line 1168 "ex4.tab.c"
    break;

  case 7: /* lignes: expr '\n'  */
#line 64 "ex4.y"
                                                        { /*printf("%d\n", stack[0]); stack_size = 0;*/ }
#line 1174 "ex4.tab.c"
    break;

  case 11: /* decl: TYPE ID ';'  */
#line 71 "ex4.y"
                            {
			// printf("déclaration de la variable %s\n", $2);
			// new_symbol_table_entry($2);
			// vérifier si ça existe pas déja
			// et on lui affecte un type
			// on remplit la structure symbol_table_entry symbol_table_entry->DESC
			// printf("type : %d - name : %s\n", $1, $2);
			// $$ = BOOLEAN_T;
			
		}
#line 1189 "ex4.tab.c"
    break;

  case 12: /* decl: TYPE ID '=' expr ';'  */
#line 80 "ex4.y"
                                         {
			char varname[64];
			sprintf(varname, "%s", (yyvsp[-3].id));
			if (symbol != NULL && symbol->name != NULL)
				printf("varname : %s, symbol : %s\n", varname, symbol->name);
			symbol = search_symbol_table(varname);
			if (symbol == NULL || strncmp(symbol->name, varname, sizeof(char) * strlen(varname)) != 0) {
				symbol = new_symbol_table_entry(varname);
				symbol->class = GLOBAL_VARIABLE;
				symbol->name = varname;
				symbol->desc[0] = (yyvsp[-4].stype); // le type de la variable dans desc[0] comme c écrit dans types.h
				char lbl_varname[BUFFER_SIZE_MAX];
				create_label(lbl_varname, BUFFER_SIZE_MAX, "%s:%s", "var", varname);
				// réserver de la place pour y stocker la valeur de la variable
				// il faut que la var à un nom fixe et y'a que le num qui change à demander
				printf("\tpop bx\n");
				printf("\tconst bx,%s\n", lbl_varname); // est ce qu'il faut l'enregistrer dans une liste ?
				printf("\tstorew ax,bx\n");
				printf("\tpush ax\n");
			} else {
				fail_with("Erreur, la variable %s existe déja dans la table des symboles !\n", varname);
			}
			if (symbol->next != NULL) {
				printf("AFFICHER MOI LE SUIVANT NEXT MAIS CA VEUT PAS AFFICHER LE NOM : %s\n", symbol->next->name);
			}
		}
#line 1220 "ex4.tab.c"
    break;

  case 13: /* expr: '(' expr ')'  */
#line 109 "ex4.y"
                             {
			/* on fait rien sur la pile sur les parenthèses, on remonte juste l'expression = $2 */
			(yyval.state) = (yyvsp[-1].state);
		}
#line 1229 "ex4.tab.c"
    break;

  case 14: /* expr: expr '+' expr  */
#line 112 "ex4.y"
                                  {
			/* $1 = expr, $2 = '+', $3 = expr */
			if (is_same_type(1, (yyvsp[-2].state), (yyvsp[0].state), ARITHMETIC_T)) {
				printf("\tpop ax\n"); // dépile la pile dont la valeur est mise dans ax
				printf("\tpop bx\n"); // dépile la pile dont la valeur est mise dans bx
				printf("\tadd ax,bx\n"); // fait le plus de ax+bx que on met sur ax
				printf("\tpush ax\n"); // push ax sur la pile qui a le nouveau résultat
				(yyval.state) = ARITHMETIC_T;
			} else {
				yyerror("[Erreur] '+' de typage");
				(yyval.state) = ERROR_TYPE;
			}
		}
#line 1247 "ex4.tab.c"
    break;

  case 15: /* expr: expr '-' expr  */
#line 124 "ex4.y"
                                  {
			if (is_same_type(1, (yyvsp[-2].state), (yyvsp[0].state), ARITHMETIC_T)) {
				printf("\tpop bx\n");
				printf("\tpop ax\n");
				printf("\tsub ax,bx\n");
				printf("\tpush ax\n");
				(yyval.state) = ARITHMETIC_T;
			} else {
				yyerror("[Erreur] '*' de typage");
				(yyval.state) = ERROR_TYPE;
			}
		}
#line 1264 "ex4.tab.c"
    break;

  case 16: /* expr: expr '*' expr  */
#line 135 "ex4.y"
                                  {
			 /* Si $1 == ERROR || $3 == ERROR pas de multiplication */
			if (is_same_type(1, (yyvsp[-2].state), (yyvsp[0].state), ARITHMETIC_T)) {
				printf("\tpop ax\n");
				printf("\tpop bx\n");
				printf("\tmul ax,bx\n");
				printf("\tpush ax\n");
				(yyval.state) = ARITHMETIC_T;
			} else {
				yyerror("[Erreur] '*' de typage");
				(yyval.state) = ERROR_TYPE;
			}
		}
#line 1282 "ex4.tab.c"
    break;

  case 17: /* expr: expr '/' expr  */
#line 147 "ex4.y"
                                  {
			/* $1 = expr, $2 = aucun car pas de non terminal mais un terminal '/', $3 = expr et test division par zéro */
			if (is_same_type(1, (yyvsp[-2].state), (yyvsp[0].state), ARITHMETIC_T)) {
				// Création d'étiquettes uniques
				char lbl_errordiv[BUFFER_SIZE_MAX];
				char lbl_end_div[BUFFER_SIZE_MAX];
				unsigned int ln = new_label_number();
				create_label(lbl_errordiv, BUFFER_SIZE_MAX, "%s:%s:%u", "err", "div0", ln);
				create_label(lbl_end_div, BUFFER_SIZE_MAX, "%s:%s:%u", "fin", "div", ln);
				printf("\tpop bx\n");
				printf("\tpop ax\n");
				printf("\tconst cx,%s\n", lbl_errordiv);
				printf("\tdiv ax,bx\n");
				printf("\tjmpe cx\n");
				printf("\tpush ax\n");
				printf("\tconst ax,%s\n", lbl_end_div);
				printf("\tjmp ax\n");
				printf(":%s\n", lbl_errordiv);
				printf("\tconst ax,%s\n", lbl_s_errordiv);
				printf("\tcallprintfs ax\n");
				printf("\tend\n");
				printf(":%s\n", lbl_end_div); // si pas d'erreur ça sort sur ce label qui fait rien
				(yyval.state) = ARITHMETIC_T;
			} else {
				yyerror("[Erreur] '/' de typage");
				(yyval.state) = ERROR_TYPE;
			}
		}
#line 1315 "ex4.tab.c"
    break;

  case 18: /* expr: expr '%' expr  */
#line 174 "ex4.y"
                                  {
			if (is_same_type(1, (yyvsp[-2].state), (yyvsp[0].state), ARITHMETIC_T)) {
				(yyval.state) = ARITHMETIC_T;
				char lbl_errordiv[BUFFER_SIZE_MAX];
				char lbl_end_div[BUFFER_SIZE_MAX];
				unsigned int ln = new_label_number();
				create_label(lbl_errordiv, BUFFER_SIZE_MAX, "%s:%s:%u", "err", "div0", ln);
				create_label(lbl_end_div, BUFFER_SIZE_MAX, "%s:%s:%u", "fin", "div", ln);
				printf("\tpop bx\n");
				printf("\tpop ax\n");
				printf("\tcp dx,ax\n");
				printf("\tconst cx,%s\n", lbl_errordiv);
				printf("\tdiv ax,bx\n");
				printf("\tjmpe cx\n");
				printf("\tcp cx,dx\n"); // copie dans cx de dx qui contient ax pour l'utiliser plustard
				printf("\tcp dx,bx\n");
				printf("\tpush ax\n");
				printf("\tconst ax,%s\n", lbl_end_div);
				printf("\tjmp ax\n");
				printf(":%s\n", lbl_errordiv);
				printf("\tconst ax,%s\n", lbl_s_errordiv);
				printf("\tcallprintfs ax\n");
				printf("\tend\n");
				printf(":%s\n", lbl_end_div);
				printf("\tpop ax\n");
				printf("\tmul ax,dx\n");
				printf("\tpush ax\n");
				printf("\tpop ax\n");
				printf("\tsub cx,ax\n");
				printf("\tpush cx\n");
			} else {
				yyerror("[Erreur] '%%' de typage");
				(yyval.state) = ERROR_TYPE;
			}
		}
#line 1355 "ex4.tab.c"
    break;

  case 19: /* expr: expr '^' expr  */
#line 208 "ex4.y"
                                  {
			if (is_same_type(1, (yyvsp[-2].state), (yyvsp[0].state), ARITHMETIC_T)) {
				(yyval.state) = ARITHMETIC_T;
			} else {
				yyerror("[Erreur] '^' de typage");
				(yyval.state) = ERROR_TYPE;
			}
		}
#line 1368 "ex4.tab.c"
    break;

  case 20: /* expr: expr EQ expr  */
#line 215 "ex4.y"
                                 {
			if (is_same_type(2, (yyvsp[-2].state), (yyvsp[0].state), ARITHMETIC_T, BOOLEAN_T)) {
				
				char lbl_eqtrue[BUFFER_SIZE_MAX];
				char lbl_endeqtrue[BUFFER_SIZE_MAX];
				unsigned int ln = new_label_number();
				create_label(lbl_eqtrue, BUFFER_SIZE_MAX, "%s:%s:%u", "eq", "true", ln);
				create_label(lbl_endeqtrue, BUFFER_SIZE_MAX, "%s:%s:%u", "endeq", "true", ln);
				
				printf("\tpop bx\n");
				printf("\tpop ax\n");
				printf("\tconst cx,%s\n", lbl_eqtrue);
				printf("\tcmp ax,bx\n");
				printf("\tjmpc cx\n");
				printf("\tconst ax,0\n");
				printf("\tpush ax\n");
				printf("\tconst cx,%s\n", lbl_endeqtrue);
				printf("\tjmp cx\n");
				printf(":%s\n", lbl_eqtrue);
				printf("\tconst ax,1\n");
				printf("\tpush ax\n");
				printf(":%s\n", lbl_endeqtrue);
				
				(yyval.state) = BOOLEAN_T;
			} else {
				yyerror("[Erreur] '==' de typage");
				(yyval.state) = ERROR_TYPE; /* si l'erreur vient de $1, on remonte $1 */
			}
		}
#line 1402 "ex4.tab.c"
    break;

  case 21: /* expr: expr NEQ expr  */
#line 243 "ex4.y"
                                  {
			if (is_same_type(2, (yyvsp[-2].state), (yyvsp[0].state), ARITHMETIC_T, BOOLEAN_T)) {
				
				char lbl_neqfalse[BUFFER_SIZE_MAX];
				char lbl_endneqfalse[BUFFER_SIZE_MAX];
				unsigned int ln = new_label_number();
				create_label(lbl_neqfalse, BUFFER_SIZE_MAX, "%s:%s:%u", "neq", "false", ln);
				create_label(lbl_endneqfalse, BUFFER_SIZE_MAX, "%s:%s:%u", "endneq", "false", ln);
				
				printf("\tpop bx\n");
				printf("\tpop ax\n");
				printf("\tconst cx,%s\n", lbl_neqfalse);
				printf("\tcmp ax,bx\n");
				printf("\tjmpc cx\n");
				printf("\tconst ax,1\n");
				printf("\tpush ax\n");
				printf("\tconst cx,%s\n", lbl_endneqfalse);
				printf("\tjmp cx\n");
				printf(":%s\n", lbl_neqfalse);
				printf("\tconst ax,0\n");
				printf("\tpush ax\n");
				printf(":%s\n", lbl_endneqfalse);
				
				(yyval.state) = BOOLEAN_T;
			} else {
				yyerror("[Erreur] '!=' de typage");
				(yyval.state) = ERROR_TYPE;
			}
		}
#line 1436 "ex4.tab.c"
    break;

  case 22: /* expr: expr AND expr  */
#line 271 "ex4.y"
                                  {
			// example : true && true, true && false 
			if (is_same_type(1, (yyvsp[-2].state), (yyvsp[0].state), BOOLEAN_T)) {
				printf("\tpop bx\n");
				printf("\tpop ax\n");
				printf("\tand ax,bx\n");
				printf("\tpush ax\n");
				(yyval.state) = (yyvsp[-2].state); // $1 = BOOLEAN_T
			} else if ((yyvsp[-2].state) != BOOLEAN_T) {
				if ((yyvsp[-2].state) == ARITHMETIC_T) {
					(yyval.state) = ERROR_TYPE;
				} else {
					(yyval.state) = (yyvsp[-2].state); // = ARITHMETIC_T
				}
			} else {
				if ((yyvsp[0].state) == ARITHMETIC_T) {
					(yyval.state) = ERROR_TYPE;
				} else {
					(yyval.state) = (yyvsp[0].state); // = ARITHMETIC_T
				}
			}
		}
#line 1463 "ex4.tab.c"
    break;

  case 23: /* expr: expr OR expr  */
#line 292 "ex4.y"
                                 {
			// example : true || true, true || false
			if (is_same_type(1, (yyvsp[-2].state), (yyvsp[0].state), BOOLEAN_T)) {
				printf("\tpop bx\n");
				printf("\tpop ax\n");
				printf("\tor ax,bx\n");
				printf("\tpush ax\n");
				(yyval.state) = (yyvsp[-2].state); // $1 = BOOLEAN_T
			} else if ((yyvsp[-2].state) != BOOLEAN_T) {
				if ((yyvsp[-2].state) == ARITHMETIC_T) {
					(yyval.state) = ERROR_TYPE;
				} else {
					(yyval.state) = (yyvsp[-2].state); // = ARITHMETIC_T
				}
			} else {
				if ((yyvsp[0].state) == ARITHMETIC_T) {
					(yyval.state) = ERROR_TYPE;
				} else {
					(yyval.state) = (yyvsp[0].state); // = ARITHMETIC_T
				}
			}
		}
#line 1490 "ex4.tab.c"
    break;

  case 24: /* expr: expr GT expr  */
#line 313 "ex4.y"
                                 {
			if (is_same_type(1, (yyvsp[-2].state), (yyvsp[0].state), ARITHMETIC_T)) {
				char lbl_true[BUFFER_SIZE_MAX];
				char lbl_endtrue[BUFFER_SIZE_MAX];
				unsigned int ln = new_label_number();
				create_label(lbl_true, BUFFER_SIZE_MAX, "%s:%s:%u", "gt", "true", ln);
				create_label(lbl_endtrue, BUFFER_SIZE_MAX, "%s:%s:%u", "gt", "endtrue", ln);
				printf("\tpop bx\n");
				printf("\tpop ax\n");
				printf("\tconst cx,%s\n", lbl_true);
				printf("\tsless bx,ax\n");
				printf("\tjmpc cx\n");
				printf("\tconst ax,0\n");
				printf("\tpush ax\n");
				printf("\tconst cx,%s\n", lbl_endtrue);
				printf("\tjmp cx\n");
				printf(":%s\n", lbl_true);
				printf("\tconst ax,1\n");
				printf("\tpush ax\n");
				printf(":%s\n", lbl_endtrue);
				(yyval.state) = BOOLEAN_T; // remonte un booléan comme résultat
			} else {
				(yyval.state) = ERROR_TYPE;
			}
		}
#line 1520 "ex4.tab.c"
    break;

  case 25: /* expr: expr LT expr  */
#line 337 "ex4.y"
                                 {
			if (is_same_type(1, (yyvsp[-2].state), (yyvsp[0].state), ARITHMETIC_T)) {
				char lbl_true[BUFFER_SIZE_MAX];
				char lbl_endtrue[BUFFER_SIZE_MAX];
				unsigned int ln = new_label_number();
				create_label(lbl_true, BUFFER_SIZE_MAX, "%s:%s:%u", "lt", "true", ln);
				create_label(lbl_endtrue, BUFFER_SIZE_MAX, "%s:%s:%u", "lt", "endtrue", ln);
				printf("\tpop bx\n");
				printf("\tpop ax\n");
				printf("\tconst cx,%s\n", lbl_true);
				printf("\tsless ax,bx\n");
				printf("\tjmpc cx\n");
				printf("\tconst ax,0\n");
				printf("\tpush ax\n");
				printf("\tconst cx,%s\n", lbl_endtrue);
				printf("\tjmp cx\n");
				printf(":%s\n", lbl_true);
				printf("\tconst ax,1\n");
				printf("\tpush ax\n");
				printf(":%s\n", lbl_endtrue);
				(yyval.state) = BOOLEAN_T;
			} else {
				(yyval.state) = ERROR_TYPE;
			}
		}
#line 1550 "ex4.tab.c"
    break;

  case 26: /* expr: NUMBER  */
#line 361 "ex4.y"
                           {
			// Affiche le code asm asipro correspondant
			printf("\tconst ax,%d\n", (yyvsp[0].integer)); // met la valeur dans le registre ax
			printf("\tpush ax\n"); // Push sur la pile, et donc ax n'est plus utilisé et peut pas besoin d'utiliser bx
			(yyval.state) = ARITHMETIC_T;
		}
#line 1561 "ex4.tab.c"
    break;

  case 27: /* expr: BOOLEAN  */
#line 366 "ex4.y"
                            {
			printf("\tconst ax,%d\n", (yyvsp[0].boolean)); // met la valeur dans le registre ax
			printf("\tpush ax\n"); // Push sur la pile
			(yyval.state) = BOOLEAN_T;
		}
#line 1571 "ex4.tab.c"
    break;


#line 1575 "ex4.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 372 "ex4.y"

	
int is_same_type(size_t size_args, type_synth $1, type_synth $3, ...) {
	va_list args;
	va_start(args, $3);
	int found = 0;
	type_synth type;
	for (int i = 0; i < size_args; i++) {
		type = (type_synth) va_arg(args, type_synth);
		if ($1 == type && $3 == type) {
			found = 1;
			break;
		}
	}
	va_end(args);
	// printf("found %d\n", found);
	return found;
}
	
void yyerror(char const *s) {
	fprintf(stderr, "%s\n", s);
}
	
	
// Label asm
static unsigned int new_label_number() {
	static unsigned int current_label_number = 0u;
	if ( current_label_number == UINT_MAX ) {
		fail_with("Error: maximum label number reached!\n");
	}
	return current_label_number++;
}
	
/*
 * Example :
 * char buf1[MAXBUF], char buf2[MAXBUF];
 * unsigned ln = new_label_number();
 * create_label(buf1, MAXBUF, "%s:%u:%s", "loop", ln, "begin");
 * create_label(buf2, MAXBUF, "%s:%u:%s", "loop", ln, "end");
*/
static void create_label(char *buf, size_t buf_size, const char *format, ...) {
	va_list ap;
	va_start(ap, format);
	if ( vsnprintf(buf, buf_size, format, ap) >= buf_size ) {
		va_end(ap);
		fail_with("Error in label generation: size of label exceeds maximum size!\n");
	}
	va_end(ap);
}
	
void fail_with(const char *format, ...) {
	va_list ap;
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
	exit(EXIT_FAILURE);
}
	
	
int main(void) {
	
	// Génère les instructions du début pour l'asm asipro avant l'analyse grammaticale
	printf("; Généré sur bison\n\n");
	
	printf("; Permet de passer la zone de stockage des constantes\n");
	printf("\tconst ax,debut\n");
	printf("\tjmp ax\n");
	
	// Déclarations des constantes (strings, int) qui peuvent être utiliser
	printf(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	printf("; Début de la zone de stockage des constantes\n");
	printf(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	
	// String pour division par zéro
	create_label(lbl_s_errordiv, BUFFER_SIZE_MAX, "%s:%s:%u", "s_err", "div0", new_label_number());
	printf("\n");
	printf(":%s\n", lbl_s_errordiv);
	printf("@string \"Erreur de division par 0\\n\"\n");
	printf("\n");
	
	
	printf(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	printf("; Fin de la zone de stockage des constantes\n");
	printf(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n\n");
	
	/*
	printf(";;;;;;;;;;;;;;;;;;;;\n");
	printf("; Début réel du code\n");
	printf(";;;;;;;;;;;;;;;;;;;;\n");
	*/
	
	printf(";;;;;;;;;;;;;;;;;;;;;\n");
	printf("; Fonction principale\n");
	printf(";;;;;;;;;;;;;;;;;;;;;\n");
	printf(":debut\n");
	printf("; Préparation de la pile\n");
	printf("\tconst bp,pile\n"); // bp : fond de la pile
	printf("\tconst sp,pile\n"); // sp : sommet de la pile
	printf("\tconst ax,2\n");
	printf("\tsub sp,ax\n"); // on fait la soustraction pour mettre le sommet de pile à - 2
	
	// Analyse grammaticale
	printf("; Résultat de bison\n");
	yyparse();

	// Génère les instructions de fin pour l'asm asipro avant l'analyse grammaticale
	printf("; Pour afficher la valeur calculée, qui se trouve normalement en sommet de pile\n");
	printf("\tcp ax,sp\n");
	printf("\tcallprintfd ax\n");
	printf("\tend\n");
	printf("\n");
	
	
	printf(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	printf("; Début de stockage de la zone de pile\n");
	printf(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	printf(":pile\n");
	printf("@int 0\n");
	printf(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	printf("; Fin de stockage de la zone de pile\n");
	printf(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	
	
	// L'initialisation des variables à zéro
	// est ce qu'il faut faire l'intialisation des variables à la fin ?
	for (symbol_table_entry *ste = symbol; ste != NULL; ste = ste->next) {
		printf(":var:%s\n", symbol->name);
		printf("@int 0\n\n");
	}
	
	
	return EXIT_SUCCESS;
}
