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
	#include <typesynth_expression.h>
	#include <types.h>
	#include <stable.h>
	
	#define BUFFER_SIZE_MAX 256
	
	int yylex(void);
	void yyerror(char const *);
	
	int is_same_type(size_t size_args, type_synth_expression $1, type_synth_expression $3, ...); /* $1 == T_BOOLEAN && $3 == T_BOOLEAN && value == T_BOOLEAN*/
	static unsigned int new_label_number();
	static void create_label(char *buf, size_t buf_size, const char *format, ...);
	void fail_with(const char *format, ...);
	void get_symbol_from_type_synth_expression(symbol_type *symbol, type_synth_expression *tse);
	type_synth_expression *get_type_synth_expression_from_symbol(type_synth_expression *type, symbol_type *symbol);
	
	
	/**
		Dans le code assembleur :
		jmpc, le bit c est positionn?? (== 1), alors jumpc (??crit dans la doc de asm), pareil pour le bit z
	*/
	char lbl_s_errordiv[BUFFER_SIZE_MAX];
	symbol_table_entry *symbol;
	
	
	#define stack_if_CAPACITY 4096
	static size_t stack_if[stack_if_CAPACITY];
	static size_t stack_if_size = 0;
	
	// Fichier assembleur
	FILE *file;
	
	
	/**
	 * pour une fonction factorielle 3
	 * empile 3 en haut de la pile
	 * push ax
	 * const dx,factorielle
	 * call
	 * ret retour au d??part
	 * dans factorielle
	 * cp cx,sp
	 * const bx,2
	 * sub cx,bx -> permet de se retrouver sur l'argument de la pile
	*/
	
	/**
	Fonction :
	
	pile :
	les arguments sur la pile
	et les variables en arguments
	
	*/
	
	
	
	
	

#line 141 "ex4.tab.c"

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
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_PRINT = 11,                     /* PRINT  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_AND = 13,                       /* AND  */
  YYSYMBOL_OR = 14,                        /* OR  */
  YYSYMBOL_EQ = 15,                        /* EQ  */
  YYSYMBOL_NEQ = 16,                       /* NEQ  */
  YYSYMBOL_GT = 17,                        /* GT  */
  YYSYMBOL_LT = 18,                        /* LT  */
  YYSYMBOL_19_ = 19,                       /* '+'  */
  YYSYMBOL_20_ = 20,                       /* '-'  */
  YYSYMBOL_21_ = 21,                       /* '*'  */
  YYSYMBOL_22_ = 22,                       /* '/'  */
  YYSYMBOL_23_ = 23,                       /* '%'  */
  YYSYMBOL_24_ = 24,                       /* '^'  */
  YYSYMBOL_25_ = 25,                       /* '{'  */
  YYSYMBOL_26_ = 26,                       /* '}'  */
  YYSYMBOL_27_ = 27,                       /* '('  */
  YYSYMBOL_28_ = 28,                       /* ')'  */
  YYSYMBOL_29_ = 29,                       /* ';'  */
  YYSYMBOL_30_ = 30,                       /* '='  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_program = 32,                   /* program  */
  YYSYMBOL_declaration_list = 33,          /* declaration_list  */
  YYSYMBOL_statement_list = 34,            /* statement_list  */
  YYSYMBOL_statement = 35,                 /* statement  */
  YYSYMBOL_compound_statement = 36,        /* compound_statement  */
  YYSYMBOL_selection_statement = 37,       /* selection_statement  */
  YYSYMBOL_else = 38,                      /* else  */
  YYSYMBOL_begin_if = 39,                  /* begin_if  */
  YYSYMBOL_end_if = 40,                    /* end_if  */
  YYSYMBOL_fi = 41,                        /* fi  */
  YYSYMBOL_iteration_statement = 42,       /* iteration_statement  */
  YYSYMBOL_expression_statement = 43,      /* expression_statement  */
  YYSYMBOL_print_statement = 44,           /* print_statement  */
  YYSYMBOL_return_statement = 45,          /* return_statement  */
  YYSYMBOL_declaration = 46,               /* declaration  */
  YYSYMBOL_expression = 47                 /* expression  */
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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   355

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  101

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   273


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    23,     2,     2,
      27,    28,    21,    19,     2,    20,     2,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
       2,    30,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    24,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   116,   116,   120,   121,   126,   126,   128,   129,   130,
     131,   132,   133,   137,   138,   139,   140,   144,   177,   178,
     181,   196,   210,   223,   226,   229,   235,   236,   237,   256,
     265,   266,   271,   280,   314,   317,   329,   340,   352,   379,
     413,   420,   447,   475,   496,   517,   541,   565,   570,   574
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
  "ID", "TYPE", "IF", "ELSE", "FOR", "WHILE", "PRINT", "RETURN", "AND",
  "OR", "EQ", "NEQ", "GT", "LT", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'",
  "'{'", "'}'", "'('", "')'", "';'", "'='", "$accept", "program",
  "declaration_list", "statement_list", "statement", "compound_statement",
  "selection_statement", "else", "begin_if", "end_if", "fi",
  "iteration_statement", "expression_statement", "print_statement",
  "return_statement", "declaration", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-32)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,     2,    10,   114,   -32,   -27,   -32,   -32,   -32,    17,
      21,    23,    25,    27,    22,    77,    58,   -32,   161,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,   179,   -32,    58,
      58,    58,    26,    58,    58,   -32,   -32,   196,   -32,    87,
     124,   247,   -32,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,   -32,   213,   230,   263,    26,
     279,   295,   -32,   -32,   151,   -32,   -32,   325,   325,    -6,
      -6,   331,   331,    35,    35,   -32,   -32,   -32,   -32,   -32,
     -32,   -32,   178,   161,    31,   -32,   161,   161,   311,   -32,
     -32,   -32,   -32,   161,    56,   -32,   161,   161,   -32,   -32,
     -32
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     4,     0,     1,    47,    48,    49,
       0,     0,     0,     0,     0,     0,     0,    26,     2,     6,
       7,     8,     9,    10,    11,    12,     3,     0,    32,     0,
       0,     0,     0,     0,     0,    49,    30,     0,    13,     0,
       0,     0,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,     0,     0,     0,
       0,     0,    31,    15,     0,    14,    34,    43,    44,    41,
      42,    45,    46,    35,    36,    37,    38,    39,    40,    33,
      28,    20,     0,     0,     0,    16,     0,     0,     0,    23,
      29,    21,    24,     0,    19,    25,     0,     0,    18,    22,
      17
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -32,   -32,    51,    -7,   -18,   -32,   -32,   -32,   -32,   -32,
     -32,   -32,   -31,   -32,   -32,     6,   -10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,    18,    19,    20,    21,    97,    86,    94,
     100,    22,    23,    24,    25,     4,    27
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      42,    59,    28,    29,    37,     1,    41,     5,    40,    26,
       6,    47,    48,    49,    50,    51,    52,    53,    54,    56,
      57,    58,    42,    60,    61,     7,     8,    35,    82,     7,
       8,     9,    64,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    26,    42,    30,    31,    16,
      32,    36,    33,    16,    34,    17,    51,    52,    53,    54,
      90,     7,     8,    35,    96,    89,    39,     0,    91,    92,
       0,     0,    88,     0,     0,    95,     0,     0,    98,    99,
       7,     8,     9,     1,    10,    16,    11,    12,    13,    14,
       7,     8,     9,     1,    10,     0,    11,    12,    13,    14,
       0,     0,    15,    38,    16,     0,    17,     0,     0,     0,
       0,     0,    15,    63,    16,     0,    17,     7,     8,     9,
       1,    10,     0,    11,    12,    13,    14,     7,     8,     9,
       0,    10,     0,    11,    12,    13,    14,     0,     0,    15,
       0,    16,     0,    17,     0,     0,     0,     0,     0,    15,
      65,    16,     0,    17,     7,     8,     9,     0,    10,     0,
      11,    12,    13,    14,     7,     8,     9,     0,    10,     0,
      11,    12,    13,    14,     0,     0,    15,    85,    16,     0,
      17,     7,     8,    35,     0,     0,    15,     0,    16,     0,
      17,     0,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,     0,    16,    87,     0,    55,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,     0,     0,     0,     0,    62,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,     0,     0,
       0,     0,    79,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,     0,     0,     0,     0,    80,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,     0,     0,     0,    66,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,     0,     0,
       0,    81,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,     0,     0,     0,    83,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
       0,     0,     0,    84,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,     0,     0,     0,    93,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      49,    50,    51,    52,    53,    54
};

static const yytype_int8 yycheck[] =
{
      18,    32,    29,    30,    14,     6,    16,     5,    15,     3,
       0,    17,    18,    19,    20,    21,    22,    23,    24,    29,
      30,    31,    40,    33,    34,     3,     4,     5,    59,     3,
       4,     5,    39,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    39,    64,    30,    27,    27,
      27,    29,    27,    27,    27,    29,    21,    22,    23,    24,
      29,     3,     4,     5,     8,    83,    15,    -1,    86,    87,
      -1,    -1,    82,    -1,    -1,    93,    -1,    -1,    96,    97,
       3,     4,     5,     6,     7,    27,     9,    10,    11,    12,
       3,     4,     5,     6,     7,    -1,     9,    10,    11,    12,
      -1,    -1,    25,    26,    27,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    -1,    29,     3,     4,     5,
       6,     7,    -1,     9,    10,    11,    12,     3,     4,     5,
      -1,     7,    -1,     9,    10,    11,    12,    -1,    -1,    25,
      -1,    27,    -1,    29,    -1,    -1,    -1,    -1,    -1,    25,
      26,    27,    -1,    29,     3,     4,     5,    -1,     7,    -1,
       9,    10,    11,    12,     3,     4,     5,    -1,     7,    -1,
       9,    10,    11,    12,    -1,    -1,    25,    26,    27,    -1,
      29,     3,     4,     5,    -1,    -1,    25,    -1,    27,    -1,
      29,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    27,    28,    -1,    29,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    29,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    29,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    29,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    28,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    28,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    28,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    28,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    28,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      19,    20,    21,    22,    23,    24
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    32,    33,    46,     5,     0,     3,     4,     5,
       7,     9,    10,    11,    12,    25,    27,    29,    34,    35,
      36,    37,    42,    43,    44,    45,    46,    47,    29,    30,
      30,    27,    27,    27,    27,     5,    29,    47,    26,    33,
      34,    47,    35,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    29,    47,    47,    47,    43,
      47,    47,    29,    26,    34,    26,    28,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    29,
      29,    28,    43,    28,    28,    26,    39,    28,    47,    35,
      29,    35,    35,    28,    40,    35,     8,    38,    35,    35,
      41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    35,    35,    35,
      35,    35,    35,    36,    36,    36,    36,    37,    38,    38,
      39,    40,    41,    42,    42,    42,    43,    43,    43,    44,
      45,    45,    46,    46,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     3,     4,    10,     2,     0,
       0,     0,     0,     5,     6,     7,     1,     2,     4,     5,
       2,     3,     3,     5,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1
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
  case 17: /* selection_statement: IF '(' expression ')' begin_if statement end_if else statement fi  */
#line 144 "ex4.y"
                                                                                  {
			if ((yyvsp[-7].state) == T_BOOLEAN) {
				char lbl_beginif[BUFFER_SIZE_MAX];
				create_label(lbl_beginif, BUFFER_SIZE_MAX, "%s:%u", "begin_if", stack_if[stack_if_size]);
				char lbl_endif[BUFFER_SIZE_MAX];
				create_label(lbl_endif, BUFFER_SIZE_MAX, "%s:%u", "end_if", stack_if[stack_if_size]);
				
				// D??pile le bool??en de l'expression
				fprintf(file, "DEMARRAGE\n");
				fprintf(file, "\tpop ax\n");
				
				// Compare si la condition est fausse, saut ?? la fin du if
				
				fprintf(file, "\tconst cx,%s\n", lbl_endif);
				fprintf(file, "\tcmp ax,0\n");
				fprintf(file, "\tjmpc cx\n");
				fprintf(file, "\tconst cx,%s\n", lbl_beginif);
				fprintf(file, "\tjmp cx\n");
				
				fprintf(file, "\tjmp ax\n");
				fprintf(file, ":%s\n", lbl_beginif);
				fprintf(file, ":%s\n", lbl_endif);
				
				(yyval.state) = T_BOOLEAN;
				
			} else {
				yyerror("[Erreur] IF expression pas bool??en");
				(yyval.state) = ERROR_TYPE;
			}
		}
#line 1312 "ex4.tab.c"
    break;

  case 20: /* begin_if: %empty  */
#line 181 "ex4.y"
                          {
		unsigned int ln = new_label_number();
		stack_if[stack_if_size++] = ln;
		char lbl_else[BUFFER_SIZE_MAX];
		create_label(lbl_else, BUFFER_SIZE_MAX, "%s:%u", "else", stack_if[stack_if_size]);
		
		// test la valeur de sp si faux saute ?? else:1
		fprintf(file, "\tconst ax,sp\n");
		fprintf(file, "\tconst bx,%s\n", lbl_else);
		fprintf(file, "\tcmp ax,0\n");
		fprintf(file, "\tjmpc ax\n");
		
	}
#line 1330 "ex4.tab.c"
    break;

  case 21: /* end_if: %empty  */
#line 196 "ex4.y"
                        {
		char lbl_fi[BUFFER_SIZE_MAX];
		create_label(lbl_fi, BUFFER_SIZE_MAX, "%s:%u", "fi", stack_if[stack_if_size]);
		char lbl_else[BUFFER_SIZE_MAX];
		create_label(lbl_else, BUFFER_SIZE_MAX, "%s:%u", "else", stack_if[stack_if_size]);
		
		// saute fi:1
		fprintf(file, "\tconst ax,%s\n", lbl_fi);
		fprintf(file, "\tjmp ax\n");
		// ??tiquette else:1
		fprintf(file, ":%s\n", lbl_else);
	}
#line 1347 "ex4.tab.c"
    break;

  case 22: /* fi: %empty  */
#line 210 "ex4.y"
                    {
		// fin de la condition
		char lbl_fi[BUFFER_SIZE_MAX];
		create_label(lbl_fi, BUFFER_SIZE_MAX, "%s:%u", "fi", stack_if[stack_if_size]);
		fprintf(file, ":%s\n", lbl_fi);
		
		// D??pile le if sortie
		stack_if[stack_if_size--] = 0;
	}
#line 1361 "ex4.tab.c"
    break;

  case 23: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 223 "ex4.y"
                                                     {
			
		}
#line 1369 "ex4.tab.c"
    break;

  case 24: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 226 "ex4.y"
                                                                                  {
			
		}
#line 1377 "ex4.tab.c"
    break;

  case 25: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 229 "ex4.y"
                                                                                             {
			(yyval.state) = ERROR_TYPE;
		}
#line 1385 "ex4.tab.c"
    break;

  case 28: /* expression_statement: ID '=' expression ';'  */
#line 237 "ex4.y"
                                        {
			char varname[64];
			sprintf(varname, "%s", (yyvsp[-3].id));
			symbol = search_symbol_table(varname);
			if (symbol != NULL) {
				char lbl_varname[BUFFER_SIZE_MAX];
				create_label(lbl_varname, BUFFER_SIZE_MAX, "%s:%s", "var", varname);
				fprintf(file, "\tpop bx\n");
				fprintf(file, "\tconst bx,%s\n", lbl_varname);
				fprintf(file, "\tstorew ax,bx\n");
				fprintf(file, "\tpush ax\n");
				// $$ = $3; 
			} else {
				fail_with("Erreur, la variable %s n'existe pas dans la table des symboles !\n", varname);
			}
		}
#line 1406 "ex4.tab.c"
    break;

  case 29: /* print_statement: PRINT '(' expression ')' ';'  */
#line 256 "ex4.y"
                                               {
			if ((yyvsp[-2].state) == T_INT || (yyvsp[-2].state) == T_BOOLEAN) {
				fprintf(file, "\tcallprintfd sp\n");
				fprintf(file, "\tpop\n");
			}
		}
#line 1417 "ex4.tab.c"
    break;

  case 30: /* return_statement: RETURN ';'  */
#line 265 "ex4.y"
                             {}
#line 1423 "ex4.tab.c"
    break;

  case 31: /* return_statement: RETURN expression ';'  */
#line 266 "ex4.y"
                                        {}
#line 1429 "ex4.tab.c"
    break;

  case 32: /* declaration: TYPE ID ';'  */
#line 271 "ex4.y"
                            {
			// fprintf(file, "d??claration de la variable %s\n", $2);
			// new_symbol_table_entry($2);
			// v??rifier si ??a existe pas d??ja
			// et on lui affecte un type
			// on remplit la structure symbol_table_entry symbol_table_entry->DESC
			// fprintf(file, "type : %d - name : %s\n", $1, $2);
			// $$ = T_BOOLEAN;
			
		}
#line 1444 "ex4.tab.c"
    break;

  case 33: /* declaration: TYPE ID '=' expression ';'  */
#line 280 "ex4.y"
                                               {
			// TYPE : types.h
			// expression : typesynth_expressionession.h
			// -> get_symbol_from_type_synth_expression
			type_synth_expression tse = (yyvsp[-1].state);
			symbol_type *s = malloc(sizeof(symbol_type));
			get_symbol_from_type_synth_expression(s, &tse);
			if (COMPATIBLE_TYPES((yyvsp[-4].stype), *s)) {
				char varname[64];
				sprintf(varname, "%s", (yyvsp[-3].id));
				symbol = search_symbol_table(varname);
				if (symbol == NULL || strncmp(symbol->name, varname, sizeof(char) * strlen(varname)) != 0) {
					symbol = new_symbol_table_entry(varname);
					symbol->class = GLOBAL_VARIABLE;
					symbol->desc[0] = (yyvsp[-4].stype); // le type de la variable dans desc[0] comme c ??crit dans types.h
					char lbl_varname[BUFFER_SIZE_MAX];
					create_label(lbl_varname, BUFFER_SIZE_MAX, "%s:%s", "var", varname);
					fprintf(file, "\tpop bx\n");
					fprintf(file, "\tconst bx,%s\n", lbl_varname); // est ce qu'il faut l'enregistrer dans une liste ?
					fprintf(file, "\tstorew ax,bx\n");
					fprintf(file, "\tpush ax\n");
					(yyval.state) = (yyvsp[-1].state);
				} else {
					fail_with("Erreur, la variable %s existe d??ja dans la table des symboles !\n", varname);
				}
			} else {
				yyerror("[Erreur] d??claration, erreur de typage");
				(yyval.state) = ERROR_TYPE;
			}
			free(s);
		}
#line 1480 "ex4.tab.c"
    break;

  case 34: /* expression: '(' expression ')'  */
#line 314 "ex4.y"
                                   {
			/* on fait rien sur la pile sur les parenth??ses, on remonte juste l'expressionession = $2 */
			(yyval.state) = (yyvsp[-1].state);
		}
#line 1489 "ex4.tab.c"
    break;

  case 35: /* expression: expression '+' expression  */
#line 317 "ex4.y"
                                              {
			/* $1 = expression, $2 = '+', $3 = expression */
			if (is_same_type(1, (yyvsp[-2].state), (yyvsp[0].state), T_INT)) {
				fprintf(file, "\tpop ax\n"); // d??pile la pile dont la valeur est mise dans ax
				fprintf(file, "\tpop bx\n"); // d??pile la pile dont la valeur est mise dans bx
				fprintf(file, "\tadd ax,bx\n"); // fait le plus de ax+bx que on met sur ax
				fprintf(file, "\tpush ax\n"); // push ax sur la pile qui a le nouveau r??sultat
				(yyval.state) = T_INT;
			} else {
				yyerror("[Erreur] '+' de typage");
				(yyval.state) = ERROR_TYPE;
			}
		}
#line 1507 "ex4.tab.c"
    break;

  case 36: /* expression: expression '-' expression  */
#line 329 "ex4.y"
                                              {
			if (is_same_type(1, (yyvsp[-2].state), (yyvsp[0].state), T_INT)) {
				fprintf(file, "\tpop bx\n");
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tsub ax,bx\n");
				fprintf(file, "\tpush ax\n");
				(yyval.state) = T_INT;
			} else {
				yyerror("[Erreur] '*' de typage");
				(yyval.state) = ERROR_TYPE;
			}
		}
#line 1524 "ex4.tab.c"
    break;

  case 37: /* expression: expression '*' expression  */
#line 340 "ex4.y"
                                              {
			 /* Si $1 == ERROR || $3 == ERROR pas de multiplication */
			if (is_same_type(1, (yyvsp[-2].state), (yyvsp[0].state), T_INT)) {
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tpop bx\n");
				fprintf(file, "\tmul ax,bx\n");
				fprintf(file, "\tpush ax\n");
				(yyval.state) = T_INT;
			} else {
				yyerror("[Erreur] '*' de typage");
				(yyval.state) = ERROR_TYPE;
			}
		}
#line 1542 "ex4.tab.c"
    break;

  case 38: /* expression: expression '/' expression  */
#line 352 "ex4.y"
                                              {
			/* $1 = expression, $2 = aucun car pas de non terminal mais un terminal '/', $3 = expression et test division par z??ro */
			if (is_same_type(1, (yyvsp[-2].state), (yyvsp[0].state), T_INT)) {
				// Cr??ation d'??tiquettes uniques
				char lbl_errordiv[BUFFER_SIZE_MAX];
				char lbl_end_div[BUFFER_SIZE_MAX];
				unsigned int ln = new_label_number();
				create_label(lbl_errordiv, BUFFER_SIZE_MAX, "%s:%s:%u", "err", "div0", ln);
				create_label(lbl_end_div, BUFFER_SIZE_MAX, "%s:%s:%u", "fin", "div", ln);
				fprintf(file, "\tpop bx\n");
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tconst cx,%s\n", lbl_errordiv);
				fprintf(file, "\tdiv ax,bx\n");
				fprintf(file, "\tjmpe cx\n");
				fprintf(file, "\tpush ax\n");
				fprintf(file, "\tconst ax,%s\n", lbl_end_div);
				fprintf(file, "\tjmp ax\n");
				fprintf(file, ":%s\n", lbl_errordiv);
				fprintf(file, "\tconst ax,%s\n", lbl_s_errordiv);
				fprintf(file, "\tcallprintfs ax\n");
				fprintf(file, "\tend\n");
				fprintf(file, ":%s\n", lbl_end_div); // si pas d'erreur ??a sort sur ce label qui fait rien
				(yyval.state) = T_INT;
			} else {
				yyerror("[Erreur] '/' de typage");
				(yyval.state) = ERROR_TYPE;
			}
		}
#line 1575 "ex4.tab.c"
    break;

  case 39: /* expression: expression '%' expression  */
#line 379 "ex4.y"
                                              {
			if (is_same_type(1, (yyvsp[-2].state), (yyvsp[0].state), T_INT)) {
				(yyval.state) = T_INT;
				char lbl_errordiv[BUFFER_SIZE_MAX];
				char lbl_end_div[BUFFER_SIZE_MAX];
				unsigned int ln = new_label_number();
				create_label(lbl_errordiv, BUFFER_SIZE_MAX, "%s:%s:%u", "err", "div0", ln);
				create_label(lbl_end_div, BUFFER_SIZE_MAX, "%s:%s:%u", "fin", "div", ln);
				fprintf(file, "\tpop bx\n");
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tcp dx,ax\n");
				fprintf(file, "\tconst cx,%s\n", lbl_errordiv);
				fprintf(file, "\tdiv ax,bx\n");
				fprintf(file, "\tjmpe cx\n");
				fprintf(file, "\tcp cx,dx\n"); // copie dans cx de dx qui contient ax pour l'utiliser plustard
				fprintf(file, "\tcp dx,bx\n");
				fprintf(file, "\tpush ax\n");
				fprintf(file, "\tconst ax,%s\n", lbl_end_div);
				fprintf(file, "\tjmp ax\n");
				fprintf(file, ":%s\n", lbl_errordiv);
				fprintf(file, "\tconst ax,%s\n", lbl_s_errordiv);
				fprintf(file, "\tcallprintfs ax\n");
				fprintf(file, "\tend\n");
				fprintf(file, ":%s\n", lbl_end_div);
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tmul ax,dx\n");
				fprintf(file, "\tpush ax\n");
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tsub cx,ax\n");
				fprintf(file, "\tpush cx\n");
			} else {
				yyerror("[Erreur] '%%' de typage");
				(yyval.state) = ERROR_TYPE;
			}
		}
#line 1615 "ex4.tab.c"
    break;

  case 40: /* expression: expression '^' expression  */
#line 413 "ex4.y"
                                              {
			if (is_same_type(1, (yyvsp[-2].state), (yyvsp[0].state), T_INT)) {
				(yyval.state) = T_INT;
			} else {
				yyerror("[Erreur] '^' de typage");
				(yyval.state) = ERROR_TYPE;
			}
		}
#line 1628 "ex4.tab.c"
    break;

  case 41: /* expression: expression EQ expression  */
#line 420 "ex4.y"
                                             {
			if (is_same_type(2, (yyvsp[-2].state), (yyvsp[0].state), T_INT, T_BOOLEAN)) {
				char lbl_eqtrue[BUFFER_SIZE_MAX];
				char lbl_endeqtrue[BUFFER_SIZE_MAX];
				unsigned int ln = new_label_number();
				create_label(lbl_eqtrue, BUFFER_SIZE_MAX, "%s:%s:%u", "eq", "true", ln);
				create_label(lbl_endeqtrue, BUFFER_SIZE_MAX, "%s:%s:%u", "endeq", "true", ln);
				
				fprintf(file, "\tpop bx\n");
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tconst cx,%s\n", lbl_eqtrue);
				fprintf(file, "\tcmp ax,bx\n");
				fprintf(file, "\tjmpc cx\n");
				fprintf(file, "\tconst ax,0\n");
				fprintf(file, "\tpush ax\n");
				fprintf(file, "\tconst cx,%s\n", lbl_endeqtrue);
				fprintf(file, "\tjmp cx\n");
				fprintf(file, ":%s\n", lbl_eqtrue);
				fprintf(file, "\tconst ax,1\n");
				fprintf(file, "\tpush ax\n");
				fprintf(file, ":%s\n", lbl_endeqtrue);
				
				(yyval.state) = T_BOOLEAN;
			} else {
				yyerror("[Erreur] '==' de typage");
				(yyval.state) = ERROR_TYPE; /* si l'erreur vient de $1, on remonte $1 */
			}
		}
#line 1661 "ex4.tab.c"
    break;

  case 42: /* expression: expression NEQ expression  */
#line 447 "ex4.y"
                                              {
			if (is_same_type(2, (yyvsp[-2].state), (yyvsp[0].state), T_INT, T_BOOLEAN)) {
				
				char lbl_neqfalse[BUFFER_SIZE_MAX];
				char lbl_endneqfalse[BUFFER_SIZE_MAX];
				unsigned int ln = new_label_number();
				create_label(lbl_neqfalse, BUFFER_SIZE_MAX, "%s:%s:%u", "neq", "false", ln);
				create_label(lbl_endneqfalse, BUFFER_SIZE_MAX, "%s:%s:%u", "endneq", "false", ln);
				
				fprintf(file, "\tpop bx\n");
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tconst cx,%s\n", lbl_neqfalse);
				fprintf(file, "\tcmp ax,bx\n");
				fprintf(file, "\tjmpc cx\n");
				fprintf(file, "\tconst ax,1\n");
				fprintf(file, "\tpush ax\n");
				fprintf(file, "\tconst cx,%s\n", lbl_endneqfalse);
				fprintf(file, "\tjmp cx\n");
				fprintf(file, ":%s\n", lbl_neqfalse);
				fprintf(file, "\tconst ax,0\n");
				fprintf(file, "\tpush ax\n");
				fprintf(file, ":%s\n", lbl_endneqfalse);
				
				(yyval.state) = T_BOOLEAN;
			} else {
				yyerror("[Erreur] '!=' de typage");
				(yyval.state) = ERROR_TYPE;
			}
		}
#line 1695 "ex4.tab.c"
    break;

  case 43: /* expression: expression AND expression  */
#line 475 "ex4.y"
                                              {
			// example : true && true, true && false 
			if (is_same_type(1, (yyvsp[-2].state), (yyvsp[0].state), T_BOOLEAN)) {
				fprintf(file, "\tpop bx\n");
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tand ax,bx\n");
				fprintf(file, "\tpush ax\n");
				(yyval.state) = (yyvsp[-2].state); // $1 = T_BOOLEAN
			} else if ((yyvsp[-2].state) != T_BOOLEAN) {
				if ((yyvsp[-2].state) == T_INT) {
					(yyval.state) = ERROR_TYPE;
				} else {
					(yyval.state) = (yyvsp[-2].state); // = T_INT
				}
			} else {
				if ((yyvsp[0].state) == T_INT) {
					(yyval.state) = ERROR_TYPE;
				} else {
					(yyval.state) = (yyvsp[0].state); // = T_INT
				}
			}
		}
#line 1722 "ex4.tab.c"
    break;

  case 44: /* expression: expression OR expression  */
#line 496 "ex4.y"
                                             {
			// example : true || true, true || false
			if (is_same_type(1, (yyvsp[-2].state), (yyvsp[0].state), T_BOOLEAN)) {
				fprintf(file, "\tpop bx\n");
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tor ax,bx\n");
				fprintf(file, "\tpush ax\n");
				(yyval.state) = (yyvsp[-2].state); // $1 = T_BOOLEAN
			} else if ((yyvsp[-2].state) != T_BOOLEAN) {
				if ((yyvsp[-2].state) == T_INT) {
					(yyval.state) = ERROR_TYPE;
				} else {
					(yyval.state) = (yyvsp[-2].state); // = T_INT
				}
			} else {
				if ((yyvsp[0].state) == T_INT) {
					(yyval.state) = ERROR_TYPE;
				} else {
					(yyval.state) = (yyvsp[0].state); // = T_INT
				}
			}
		}
#line 1749 "ex4.tab.c"
    break;

  case 45: /* expression: expression GT expression  */
#line 517 "ex4.y"
                                             {
			if (is_same_type(1, (yyvsp[-2].state), (yyvsp[0].state), T_INT)) {
				char lbl_true[BUFFER_SIZE_MAX];
				char lbl_endtrue[BUFFER_SIZE_MAX];
				unsigned int ln = new_label_number();
				create_label(lbl_true, BUFFER_SIZE_MAX, "%s:%s:%u", "gt", "true", ln);
				create_label(lbl_endtrue, BUFFER_SIZE_MAX, "%s:%s:%u", "gt", "endtrue", ln);
				fprintf(file, "\tpop bx\n");
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tconst cx,%s\n", lbl_true);
				fprintf(file, "\tsless bx,ax\n");
				fprintf(file, "\tjmpc cx\n");
				fprintf(file, "\tconst ax,0\n");
				fprintf(file, "\tpush ax\n");
				fprintf(file, "\tconst cx,%s\n", lbl_endtrue);
				fprintf(file, "\tjmp cx\n");
				fprintf(file, ":%s\n", lbl_true);
				fprintf(file, "\tconst ax,1\n");
				fprintf(file, "\tpush ax\n");
				fprintf(file, ":%s\n", lbl_endtrue);
				(yyval.state) = T_BOOLEAN; // remonte un bool??an comme r??sultat
			} else {
				(yyval.state) = ERROR_TYPE;
			}
		}
#line 1779 "ex4.tab.c"
    break;

  case 46: /* expression: expression LT expression  */
#line 541 "ex4.y"
                                             {
			if (is_same_type(1, (yyvsp[-2].state), (yyvsp[0].state), T_INT)) {
				char lbl_true[BUFFER_SIZE_MAX];
				char lbl_endtrue[BUFFER_SIZE_MAX];
				unsigned int ln = new_label_number();
				create_label(lbl_true, BUFFER_SIZE_MAX, "%s:%s:%u", "lt", "true", ln);
				create_label(lbl_endtrue, BUFFER_SIZE_MAX, "%s:%s:%u", "lt", "endtrue", ln);
				fprintf(file, "\tpop bx\n");
				fprintf(file, "\tpop ax\n");
				fprintf(file, "\tconst cx,%s\n", lbl_true);
				fprintf(file, "\tsless ax,bx\n");
				fprintf(file, "\tjmpc cx\n");
				fprintf(file, "\tconst ax,0\n");
				fprintf(file, "\tpush ax\n");
				fprintf(file, "\tconst cx,%s\n", lbl_endtrue);
				fprintf(file, "\tjmp cx\n");
				fprintf(file, ":%s\n", lbl_true);
				fprintf(file, "\tconst ax,1\n");
				fprintf(file, "\tpush ax\n");
				fprintf(file, ":%s\n", lbl_endtrue);
				(yyval.state) = T_BOOLEAN;
			} else {
				(yyval.state) = ERROR_TYPE;
			}
		}
#line 1809 "ex4.tab.c"
    break;

  case 47: /* expression: NUMBER  */
#line 565 "ex4.y"
                           {
			// Affiche le code asm asipro correspondant
			fprintf(file, "\tconst ax,%d\n", (yyvsp[0].integer)); // met la valeur dans le registre ax
			fprintf(file, "\tpush ax\n"); // Push sur la pile, et donc ax n'est plus utilis?? et peut pas besoin d'utiliser bx
			(yyval.state) = T_INT;
		}
#line 1820 "ex4.tab.c"
    break;

  case 48: /* expression: BOOLEAN  */
#line 570 "ex4.y"
                            {
			fprintf(file, "\tconst ax,%d\n", (yyvsp[0].boolean)); // met la valeur dans le registre ax
			fprintf(file, "\tpush ax\n"); // Push sur la pile
			(yyval.state) = T_BOOLEAN;
		}
#line 1830 "ex4.tab.c"
    break;

  case 49: /* expression: ID  */
#line 574 "ex4.y"
                       {
			symbol_table_entry *ste;
			if ((ste = search_symbol_table((yyvsp[0].id))) == NULL) {
				yyerror("[Erreur] symbol inconnu");
				(yyval.state) = ERROR_TYPE;
			} else {
				type_synth_expression *tse = malloc(sizeof(type_synth_expression));
				if ((tse = get_type_synth_expression_from_symbol(tse, &ste->desc[0])) == NULL) {
					yyerror("[Erreur] symbol non enregistr??");
					(yyval.state) = ERROR_TYPE;
				}	
				(yyval.state) = *tse;
				free(tse);
			}
		}
#line 1850 "ex4.tab.c"
    break;


#line 1854 "ex4.tab.c"

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

#line 590 "ex4.y"


/**
 * Comme dans la conception, j'ai d??cid?? de s??par?? les types expressionessions
 * de ce des symboles d'une d??claration (ex : une erreur de type)
 * cette fonction sert ?? r??cup??rer le type de symbole du type de l'expressionession
*/
void get_symbol_from_type_synth_expression(symbol_type *symbol, type_synth_expression *tse) {
	if (tse == NULL) return;
	if (symbol == NULL) return;
	if (*tse == T_INT) {
		*symbol = INT_T_LVALUE;
	} else if (*tse == T_BOOLEAN) {
		*symbol = BOOL_T_LVALUE;
	}
}
	
type_synth_expression *get_type_synth_expression_from_symbol(type_synth_expression *type, symbol_type *symbol) {
	if (symbol == NULL) return NULL;
	if (type == NULL) return NULL;
	if (*symbol == INT_T) {
		*type = T_INT;
	} else if (*symbol == BOOL_T) {
		*type = T_BOOLEAN;
	}
	return type;
}
	
int is_same_type(size_t size_args, type_synth_expression $1, type_synth_expression $3, ...) {
	va_list args;
	va_start(args, $3);
	int found = 0;
	type_synth_expression type;
	for (int i = 0; i < size_args; i++) {
		type = (type_synth_expression) va_arg(args, type_synth_expression);
		if ($1 == type && $3 == type) {
			found = 1;
			break;
		}
	}
	va_end(args);
	// fprintf(file, "found %d\n", found);
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
	const char *full_filename = "ex4.asm";
	printf("==================================================================\n");
	printf("== Code assembleur ASIPRO g??n??r?? dans le fichier : %s\n", full_filename);
	printf("== D??s lorsque l'analyse syntaxicale et grammaticale termin??e, il faut utiliser ASIPRO et SIPRO pour l'??x??cuter\n");
	printf("==================================================================\n");
	
	// Ouverture du fichier d'assembleur pour y ??crire le code assembleur
	file = fopen(full_filename, "w");
	if (file == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	
	// G??n??re les statementuctions du d??but pour l'asm asipro avant l'analyse grammaticale
	fprintf(file, "; G??n??r?? sur bison\n\n");
	
	fprintf(file, "; Permet de passer la zone de stockage des constantes\n");
	fprintf(file, "\tconst ax,debut\n");
	fprintf(file, "\tjmp ax\n");
	
	// D??clarations des constantes (strings, int) qui peuvent ??tre utiliser
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	fprintf(file, "; D??but de la zone de stockage des constantes\n");
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	
	// String pour division par z??ro
	create_label(lbl_s_errordiv, BUFFER_SIZE_MAX, "%s:%s:%u", "s_err", "div0", new_label_number());
	fprintf(file, "\n");
	fprintf(file, ":%s\n", lbl_s_errordiv);
	fprintf(file, "@string \"Erreur de division par 0\\n\"\n");
	fprintf(file, "\n");
	
	
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	fprintf(file, "; Fin de la zone de stockage des constantes\n");
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n\n");
	
	/*
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;\n");
	fprintf(file, "; D??but r??el du code\n");
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;\n");
	*/
	
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;\n");
	fprintf(file, "; Fonction principale\n");
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;\n");
	fprintf(file, ":debut\n");
	fprintf(file, "; Pr??paration de la pile\n");
	fprintf(file, "\tconst bp,pile\n"); // bp : fond de la pile
	fprintf(file, "\tconst sp,pile\n"); // sp : sommet de la pile
	fprintf(file, "\tconst ax,2\n");
	fprintf(file, "\tsub sp,ax\n"); // on fait la soustraction pour mettre le sommet de pile ?? - 2
	
	// Analyse grammaticale
	fprintf(file, "; Cod?? g??n??r?? ?? partir de bison\n");
	yyparse();

	// G??n??re les statementuctions de fin pour l'asm asipro avant l'analyse grammaticale
	/*
	fprintf(file, "; Pour afficher la valeur calcul??e, qui se trouve normalement en sommet de pile\n");
	fprintf(file, "\tcp ax,sp\n");
	fprintf(file, "\tcallprintfd ax\n");
	fprintf(file, "\tend\n");
	*/
	fprintf(file, "\n");
	
	
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	fprintf(file, "; D??but de stockage de la zone de pile\n");
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	fprintf(file, ":pile\n");
	fprintf(file, "@int 0\n");
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	fprintf(file, "; Fin de stockage de la zone de pile\n");
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	
	
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	fprintf(file, "; D??but de d??claration des variables\n");
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	// L'initialisation des variables initialis??es ?? z??ro
	for (symbol_table_entry *ste = symbol; ste != NULL; ste = ste->next) {
		fprintf(file, ":var:%s\n", ste->name);
		fprintf(file, "@int 0\n");
		free_first_symbol_table_entry();
	}
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	fprintf(file, "; Fin de d??claration des variables\n");
	fprintf(file, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	
	if (fclose(file) == EOF) {
		perror("fclose");
		exit(EXIT_FAILURE);
	}
	
	return EXIT_SUCCESS;
}
