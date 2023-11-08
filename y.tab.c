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
#line 1 "parse.y"
     /* pars1.y    Pascal Parser      Gordon S. Novak Jr.  ; 08 Jul 22   */

/* Copyright (c) 2022 Gordon S. Novak Jr. and
   The University of Texas at Austin. 
   
   
   
   Eylam Tagor
   et23634
   09/27/2023*/

/* 14 Feb 01; 01 Oct 04; 02 Mar 07; 27 Feb 08; 24 Jul 09; 02 Aug 12;
   30 Jul 13; 25 Jul 19 ; 28 Feb 22 */

/*
; This program is free software; you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation; either version 2 of the License, or
; (at your option) any later version.

; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.

; You should have received a copy of the GNU General Public License
; along with this program; if not, see <http://www.gnu.org/licenses/>.
  */


/* NOTE:   Copy your lexan.l lexical analyzer to this directory.      */

       /* To use:
                     make pars1y              has 1 shift/reduce conflict
                     pars1y                   execute the parser
                     i:=j .
                     ^D                       control-D to end input

                     pars1y                   execute the parser
                     begin i:=j; if i+j then x:=a+b*c else x:=a*b+c; k:=i end.
                     ^D

                     pars1y                   execute the parser
                     if x+y then if y+z then i:=j else k:=2.
                     ^D

           You may copy pars1.y to be parse.y and extend it for your
           assignment.  Then use   make parser   as above.
        */

        /* Yacc reports 1 shift/reduce conflict, due to the ELSE part of
           the IF statement, but Yacc's default resolves it in the right way.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "token.h"
#include "lexan.h"
#include "symtab.h"
#include "parse.h"
#include "pprint.h"

        /* define the type of the Yacc stack element to be TOKEN */

#define YYSTYPE TOKEN

TOKEN parseresult;


#line 141 "y.tab.c"

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
    IDENTIFIER = 258,
    STRING = 259,
    NUMBER = 260,
    PLUS = 261,
    MINUS = 262,
    TIMES = 263,
    DIVIDE = 264,
    ASSIGN = 265,
    EQ = 266,
    NE = 267,
    LT = 268,
    LE = 269,
    GE = 270,
    GT = 271,
    POINT = 272,
    DOT = 273,
    AND = 274,
    OR = 275,
    NOT = 276,
    DIV = 277,
    MOD = 278,
    IN = 279,
    COMMA = 280,
    SEMICOLON = 281,
    COLON = 282,
    LPAREN = 283,
    RPAREN = 284,
    LBRACKET = 285,
    RBRACKET = 286,
    DOTDOT = 287,
    ARRAY = 288,
    BEGINBEGIN = 289,
    CASE = 290,
    CONST = 291,
    DO = 292,
    DOWNTO = 293,
    ELSE = 294,
    END = 295,
    FILEFILE = 296,
    FOR = 297,
    FUNCTION = 298,
    GOTO = 299,
    IF = 300,
    LABEL = 301,
    NIL = 302,
    OF = 303,
    PACKED = 304,
    PROCEDURE = 305,
    PROGRAM = 306,
    RECORD = 307,
    REPEAT = 308,
    SET = 309,
    THEN = 310,
    TO = 311,
    TYPE = 312,
    UNTIL = 313,
    VAR = 314,
    WHILE = 315,
    WITH = 316,
    thenthen = 317
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define STRING 259
#define NUMBER 260
#define PLUS 261
#define MINUS 262
#define TIMES 263
#define DIVIDE 264
#define ASSIGN 265
#define EQ 266
#define NE 267
#define LT 268
#define LE 269
#define GE 270
#define GT 271
#define POINT 272
#define DOT 273
#define AND 274
#define OR 275
#define NOT 276
#define DIV 277
#define MOD 278
#define IN 279
#define COMMA 280
#define SEMICOLON 281
#define COLON 282
#define LPAREN 283
#define RPAREN 284
#define LBRACKET 285
#define RBRACKET 286
#define DOTDOT 287
#define ARRAY 288
#define BEGINBEGIN 289
#define CASE 290
#define CONST 291
#define DO 292
#define DOWNTO 293
#define ELSE 294
#define END 295
#define FILEFILE 296
#define FOR 297
#define FUNCTION 298
#define GOTO 299
#define IF 300
#define LABEL 301
#define NIL 302
#define OF 303
#define PACKED 304
#define PROCEDURE 305
#define PROGRAM 306
#define RECORD 307
#define REPEAT 308
#define SET 309
#define THEN 310
#define TO 311
#define TYPE 312
#define UNTIL 313
#define VAR 314
#define WHILE 315
#define WITH 316
#define thenthen 317

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   248

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  195

#define YYUNDEFTOK  2
#define YYMAXUTOK   317


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    91,    91,    93,    95,    96,    97,    98,    99,   100,
     101,   102,   104,   105,   107,   108,   110,   112,   113,   114,
     115,   116,   117,   118,   119,   121,   122,   123,   124,   125,
     126,   128,   129,   130,   131,   132,   133,   134,   136,   137,
     138,   139,   142,   144,   146,   148,   149,   151,   152,   154,
     157,   158,   159,   160,   162,   163,   164,   167,   170,   173,
     174,   177,   178,   181,   182,   185,   186,   187,   188,   189,
     190,   191,   194,   196,   197,   200,   201,   204,   207,   208,
     211,   212,   213,   214,   215,   216,   219,   221,   222,   225,
     226,   229,   230,   233,   234
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "NUMBER", "PLUS",
  "MINUS", "TIMES", "DIVIDE", "ASSIGN", "EQ", "NE", "LT", "LE", "GE", "GT",
  "POINT", "DOT", "AND", "OR", "NOT", "DIV", "MOD", "IN", "COMMA",
  "SEMICOLON", "COLON", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET",
  "DOTDOT", "ARRAY", "BEGINBEGIN", "CASE", "CONST", "DO", "DOWNTO", "ELSE",
  "END", "FILEFILE", "FOR", "FUNCTION", "GOTO", "IF", "LABEL", "NIL", "OF",
  "PACKED", "PROCEDURE", "PROGRAM", "RECORD", "REPEAT", "SET", "THEN",
  "TO", "TYPE", "UNTIL", "VAR", "WHILE", "WITH", "thenthen", "$accept",
  "program", "statement", "endpart", "endif", "assignment", "expr", "term",
  "factor", "variable", "mergelist", "idlist", "vblock", "varspecs",
  "vargroup", "type", "simpletype", "block", "funcall", "expr_list",
  "cblock", "tblock", "constant", "const_def", "constspecs", "typespecs",
  "type_def", "stlist", "simpleexpr", "fields", "field_list", "lblock",
  "labellist", "simtypelist", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317
};
# endif

#define YYPACT_NINF (-83)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-66)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -40,    12,    19,    -4,   -83,    32,    13,    14,    32,    31,
     -83,    34,    22,    42,    57,    62,    32,   -83,   -83,   -83,
     -83,    51,    53,    61,    22,    99,   105,   109,    22,   109,
     -14,   -83,    11,   -83,   -83,   115,   102,    75,   108,   110,
     127,    40,   118,   116,   107,   129,   -83,   109,    22,   -14,
     -83,   101,   -83,   -83,   -83,   114,   114,   114,   109,   -83,
      35,   154,   -83,   204,   -83,   133,   132,   106,   135,    22,
     -83,   -83,   109,   -83,   157,   109,   190,    42,   -83,    57,
      95,    27,   -83,    62,    27,   -83,    32,   195,   138,   -83,
     -83,   109,   154,   154,   -83,   174,   109,   109,   109,   109,
     109,   109,   109,    22,   114,   114,   114,   114,   114,   114,
     114,   114,    22,   109,    22,   -14,   201,   -83,   143,   -83,
     -83,   -83,    49,    93,   -83,   -83,   -83,   -83,   159,   172,
      32,   169,    32,   -83,   -83,   170,   -83,   -83,   -83,   109,
     -83,   168,   -83,   133,   133,   133,   133,   133,   133,   133,
     161,   -83,   -83,   -83,   -83,   -83,   154,   154,   154,   -83,
     201,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   175,
     117,   191,   197,   184,   190,   -83,    22,    22,   -83,   -83,
     176,   202,    27,    32,   -83,   -83,   -83,   -83,   117,   187,
     -83,   -83,   -83,    27,   -83
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    44,     0,     0,     0,
      43,     0,     0,     0,     0,     0,     0,    64,    46,    90,
      62,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     0,    41,     6,     0,     0,     0,    92,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
      38,     0,     9,    34,    33,     0,     0,     0,     0,    35,
       0,    80,    30,    32,    37,    24,    79,     0,     0,     0,
      13,    57,     0,    39,     0,     0,     0,    74,    61,     0,
       0,     0,    63,    76,     0,    45,    48,    60,     0,     8,
       3,     0,    81,    82,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,    40,     0,    65,
      71,    68,     0,     0,    72,    73,    91,    89,    54,     0,
       0,     0,     0,    77,    50,     0,    75,    49,    47,     0,
      58,     0,    31,    17,    18,    20,    22,    21,    19,    23,
      15,    25,    26,    29,    27,    28,    83,    84,    85,    78,
       7,    10,    12,    42,    66,    69,    67,    70,    51,     0,
       0,     0,    88,     0,     0,    59,     0,     0,     4,    55,
      94,     0,     0,     0,    52,    56,    11,    14,     0,     0,
      86,    87,    93,     0,    53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -83,   -83,    -6,   -44,   -83,   211,   -19,   -33,   -21,   -11,
     -83,    -5,   196,   152,   -83,   -82,   -81,   198,    -8,   -66,
     160,   206,   -69,   -83,   162,   158,   -83,   134,   130,   -83,
      64,   -83,   165,    60
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    66,    71,   178,    31,    87,    61,    62,    63,
      33,    43,    17,    44,    45,   133,   134,    18,    64,    88,
      19,    20,   135,    36,    37,    41,    42,    67,    65,   172,
     173,    21,    39,   181
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       7,    32,   137,    10,    34,    90,    30,   124,    60,   118,
      68,     1,    69,    32,    32,     3,    34,    32,    49,     4,
      34,    72,    92,    93,     5,    22,    70,    23,    73,    74,
     128,   120,   121,   122,   123,     6,    94,    32,     8,    95,
      34,    75,    89,     9,   129,    35,    96,    97,    98,    99,
     100,   101,   164,   116,   165,   130,    24,    11,    32,   102,
     131,    34,    38,   115,    25,    40,    26,    27,    12,    46,
      13,   162,   141,   175,    12,    28,   156,   157,   158,   132,
      14,    47,    29,   151,   152,   153,   154,   155,    48,   180,
     103,    15,    32,    16,   160,    34,   166,   150,   167,    16,
     190,    32,    50,    32,    34,   185,    34,   180,   161,    12,
      52,   194,    22,    53,    54,    55,    56,    22,    53,    54,
     128,   120,   121,   122,   123,   169,    76,   171,    77,    12,
      57,    13,    15,    79,    16,    57,    80,    58,    81,   109,
     110,    12,    58,    84,    83,   130,    96,    97,    98,    99,
     100,   101,    15,   111,    16,    86,    59,    91,   112,   102,
     117,    59,   104,   105,   113,    32,    32,   140,    34,    34,
     186,   187,   114,   106,   163,   168,   107,   108,   171,    96,
      97,    98,    99,   100,   101,    96,    97,    98,    99,   100,
     101,   -65,   102,   119,   120,   121,   122,   123,   102,   170,
     177,   188,   174,   142,   179,   176,    96,    97,    98,    99,
     100,   101,    96,    97,    98,    99,   100,   101,   182,   102,
     139,    73,    74,   183,   184,   102,   143,   144,   145,   146,
     147,   148,   149,   189,    75,   193,    51,    82,   138,   125,
     127,   136,    85,    78,   126,     0,   159,   191,   192
};

static const yytype_int16 yycheck[] =
{
       5,    12,    84,     8,    12,    49,    12,    76,    27,    75,
      29,    51,    26,    24,    25,     3,    24,    28,    24,     0,
      28,    10,    55,    56,    28,     3,    40,     5,    17,    18,
       3,     4,     5,     6,     7,     3,    57,    48,    25,    58,
      48,    30,    48,    29,    17,     3,    11,    12,    13,    14,
      15,    16,     3,    72,     5,    28,    34,    26,    69,    24,
      33,    69,     5,    69,    42,     3,    44,    45,    34,    18,
      36,   115,    91,   139,    34,    53,   109,   110,   111,    52,
      46,    28,    60,   104,   105,   106,   107,   108,    27,   170,
      55,    57,   103,    59,   113,   103,     3,   103,     5,    59,
     182,   112,     3,   114,   112,   174,   114,   188,   114,    34,
       5,   193,     3,     4,     5,     6,     7,     3,     4,     5,
       3,     4,     5,     6,     7,   130,    11,   132,    26,    34,
      21,    36,    57,    25,    59,    21,    26,    28,    11,     6,
       7,    34,    28,    27,    26,    28,    11,    12,    13,    14,
      15,    16,    57,    20,    59,    26,    47,    56,    26,    24,
       3,    47,     8,     9,    58,   176,   177,    29,   176,   177,
     176,   177,    37,    19,    31,     3,    22,    23,   183,    11,
      12,    13,    14,    15,    16,    11,    12,    13,    14,    15,
      16,    32,    24,     3,     4,     5,     6,     7,    24,    30,
      39,    25,    32,    29,    29,    37,    11,    12,    13,    14,
      15,    16,    11,    12,    13,    14,    15,    16,    27,    24,
      25,    17,    18,    26,    40,    24,    96,    97,    98,    99,
     100,   101,   102,    31,    30,    48,    25,    41,    86,    77,
      80,    83,    44,    37,    79,    -1,   112,   183,   188
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,    64,     3,     0,    28,     3,    74,    25,    29,
      74,    26,    34,    36,    46,    57,    59,    75,    80,    83,
      84,    94,     3,     5,    34,    42,    44,    45,    53,    60,
      65,    68,    72,    73,    81,     3,    86,    87,     5,    95,
       3,    88,    89,    74,    76,    77,    18,    28,    27,    65,
       3,    68,     5,     4,     5,     6,     7,    21,    28,    47,
      69,    70,    71,    72,    81,    91,    65,    90,    69,    26,
      40,    66,    10,    17,    18,    30,    11,    26,    84,    25,
      26,    11,    75,    26,    27,    80,    26,    69,    82,    65,
      66,    56,    70,    70,    71,    69,    11,    12,    13,    14,
      15,    16,    24,    55,     8,     9,    19,    22,    23,     6,
       7,    20,    26,    58,    37,    65,    69,     3,    82,     3,
       4,     5,     6,     7,    85,    87,    95,    83,     3,    17,
      28,    33,    52,    78,    79,    85,    88,    78,    76,    25,
      29,    69,    29,    91,    91,    91,    91,    91,    91,    91,
      65,    71,    71,    71,    71,    71,    70,    70,    70,    90,
      69,    65,    66,    31,     3,     5,     3,     5,     3,    74,
      30,    74,    92,    93,    32,    82,    37,    39,    67,    29,
      79,    96,    27,    26,    40,    85,    65,    65,    25,    31,
      78,    93,    96,    48,    78
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    66,    66,    67,    67,    68,    69,    69,    69,
      69,    69,    69,    69,    69,    70,    70,    70,    70,    70,
      70,    71,    71,    71,    71,    71,    71,    71,    72,    72,
      72,    72,    73,    74,    74,    75,    75,    76,    76,    77,
      78,    78,    78,    78,    79,    79,    79,    80,    81,    82,
      82,    83,    83,    84,    84,    85,    85,    85,    85,    85,
      85,    85,    86,    87,    87,    88,    88,    89,    90,    90,
      91,    91,    91,    91,    91,    91,    92,    93,    93,    94,
      94,    95,    95,    96,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     3,     5,     1,     1,     4,     3,     2,
       4,     6,     3,     1,     2,     0,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       1,     3,     1,     1,     1,     1,     2,     1,     1,     2,
       3,     1,     4,     3,     1,     3,     1,     3,     2,     3,
       1,     2,     3,     6,     1,     3,     3,     3,     4,     3,
       1,     3,     1,     3,     1,     1,     2,     2,     1,     2,
       2,     1,     3,     3,     2,     3,     2,     3,     3,     1,
       1,     2,     2,     3,     3,     3,     3,     3,     1,     4,
       1,     3,     1,     3,     1
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
#line 91 "parse.y"
                                                                           { parseresult = makeprogram(yyvsp[-6], yyvsp[-4], yyvsp[-1]); }
#line 1633 "y.tab.c"
    break;

  case 3:
#line 94 "parse.y"
                                       { yyval = makeprogn(yyvsp[-2],cons(yyvsp[-1], yyvsp[0])); }
#line 1639 "y.tab.c"
    break;

  case 4:
#line 95 "parse.y"
                                               { yyval = makeif(yyvsp[-4], yyvsp[-3], yyvsp[-1], yyvsp[0]); }
#line 1645 "y.tab.c"
    break;

  case 7:
#line 98 "parse.y"
                                        { yyval = makerepeat(yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1651 "y.tab.c"
    break;

  case 8:
#line 99 "parse.y"
                                      { yyval = dolabel(yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1657 "y.tab.c"
    break;

  case 9:
#line 100 "parse.y"
                           { yyval = dogoto(yyvsp[-1], yyvsp[0]); }
#line 1663 "y.tab.c"
    break;

  case 10:
#line 101 "parse.y"
                                       { yyval = makewhile(yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1669 "y.tab.c"
    break;

  case 11:
#line 102 "parse.y"
                                                   { yyval = makefor(1, yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1675 "y.tab.c"
    break;

  case 12:
#line 104 "parse.y"
                                               { yyval = cons(yyvsp[-1], yyvsp[0]); }
#line 1681 "y.tab.c"
    break;

  case 13:
#line 105 "parse.y"
                                               { yyval = NULL; }
#line 1687 "y.tab.c"
    break;

  case 14:
#line 107 "parse.y"
                                               { yyval = yyvsp[0]; }
#line 1693 "y.tab.c"
    break;

  case 15:
#line 108 "parse.y"
                                               { yyval = NULL; }
#line 1699 "y.tab.c"
    break;

  case 16:
#line 110 "parse.y"
                                               { yyval = binop(yyvsp[-1], yyvsp[-2], yyvsp[0]); }
#line 1705 "y.tab.c"
    break;

  case 17:
#line 112 "parse.y"
                                   {yyval = binop(yyvsp[-1], yyvsp[-2], yyvsp[0]); }
#line 1711 "y.tab.c"
    break;

  case 18:
#line 113 "parse.y"
                                   {yyval = binop(yyvsp[-1], yyvsp[-2], yyvsp[0]); }
#line 1717 "y.tab.c"
    break;

  case 19:
#line 114 "parse.y"
                                   {yyval = binop(yyvsp[-1], yyvsp[-2], yyvsp[0]); }
#line 1723 "y.tab.c"
    break;

  case 20:
#line 115 "parse.y"
                                   {yyval = binop(yyvsp[-1], yyvsp[-2], yyvsp[0]); }
#line 1729 "y.tab.c"
    break;

  case 21:
#line 116 "parse.y"
                                   {yyval = binop(yyvsp[-1], yyvsp[-2], yyvsp[0]); }
#line 1735 "y.tab.c"
    break;

  case 22:
#line 117 "parse.y"
                                   {yyval = binop(yyvsp[-1], yyvsp[-2], yyvsp[0]); }
#line 1741 "y.tab.c"
    break;

  case 23:
#line 118 "parse.y"
                                   {yyval = binop(yyvsp[-1], yyvsp[-2], yyvsp[0]); }
#line 1747 "y.tab.c"
    break;

  case 25:
#line 121 "parse.y"
                                               { yyval = binop(yyvsp[-1], yyvsp[-2], yyvsp[0]); }
#line 1753 "y.tab.c"
    break;

  case 26:
#line 122 "parse.y"
                                   { yyval = binop(yyvsp[-1], yyvsp[-2], yyvsp[0]); }
#line 1759 "y.tab.c"
    break;

  case 27:
#line 123 "parse.y"
                                { yyval = binop(yyvsp[-1], yyvsp[-2], yyvsp[0]); }
#line 1765 "y.tab.c"
    break;

  case 28:
#line 124 "parse.y"
                                { yyval = binop(yyvsp[-1], yyvsp[-2], yyvsp[0]); }
#line 1771 "y.tab.c"
    break;

  case 29:
#line 125 "parse.y"
                                { yyval = binop(yyvsp[-1], yyvsp[-2], yyvsp[0]); }
#line 1777 "y.tab.c"
    break;

  case 31:
#line 128 "parse.y"
                                               { yyval = yyvsp[-1]; }
#line 1783 "y.tab.c"
    break;

  case 36:
#line 133 "parse.y"
                           { yyval = unaryop(yyvsp[-1], yyvsp[0]); }
#line 1789 "y.tab.c"
    break;

  case 38:
#line 136 "parse.y"
                          { yyval = findid(yyvsp[0]); }
#line 1795 "y.tab.c"
    break;

  case 39:
#line 137 "parse.y"
                              { yyval = dopoint(yyvsp[-1], yyvsp[0]); }
#line 1801 "y.tab.c"
    break;

  case 40:
#line 138 "parse.y"
                                       { yyval = reducedot(yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1807 "y.tab.c"
    break;

  case 42:
#line 142 "parse.y"
                                                    { yyval = arrayref(yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1813 "y.tab.c"
    break;

  case 43:
#line 145 "parse.y"
                          { yyval = cons(yyvsp[-2], yyvsp[0]); }
#line 1819 "y.tab.c"
    break;

  case 44:
#line 146 "parse.y"
                          { yyval = cons(yyvsp[0], NULL); }
#line 1825 "y.tab.c"
    break;

  case 45:
#line 148 "parse.y"
                                       { yyval = yyvsp[0]; }
#line 1831 "y.tab.c"
    break;

  case 49:
#line 155 "parse.y"
                              { instvars(yyvsp[-2], yyvsp[0]); }
#line 1837 "y.tab.c"
    break;

  case 51:
#line 158 "parse.y"
                             { yyval = instpoint(yyvsp[-1], yyvsp[0]); }
#line 1843 "y.tab.c"
    break;

  case 52:
#line 159 "parse.y"
                                  { yyval = instrec(yyvsp[-2], yyvsp[-1]); }
#line 1849 "y.tab.c"
    break;

  case 53:
#line 160 "parse.y"
                                                        { yyval = instarray(yyvsp[-3], yyvsp[0]); }
#line 1855 "y.tab.c"
    break;

  case 54:
#line 162 "parse.y"
                             { yyval = findtype(yyvsp[0]); }
#line 1861 "y.tab.c"
    break;

  case 55:
#line 163 "parse.y"
                                     { yyval = instenum(yyvsp[-1]); }
#line 1867 "y.tab.c"
    break;

  case 56:
#line 164 "parse.y"
                                         { yyval = instdotdot(yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1873 "y.tab.c"
    break;

  case 57:
#line 168 "parse.y"
              { yyval = makeprogn(yyvsp[-2],cons(yyvsp[-1], yyvsp[0])); }
#line 1879 "y.tab.c"
    break;

  case 58:
#line 170 "parse.y"
                                                { yyval = makefuncall(yyvsp[-2], yyvsp[-3], yyvsp[-1]); }
#line 1885 "y.tab.c"
    break;

  case 59:
#line 173 "parse.y"
                                  { yyval = cons(yyvsp[-2], yyvsp[0]); }
#line 1891 "y.tab.c"
    break;

  case 60:
#line 174 "parse.y"
                  { yyval = cons(yyvsp[0], NULL); }
#line 1897 "y.tab.c"
    break;

  case 61:
#line 177 "parse.y"
                                     { yyval = yyvsp[0]; }
#line 1903 "y.tab.c"
    break;

  case 63:
#line 181 "parse.y"
                                   { yyval = yyvsp[0]; }
#line 1909 "y.tab.c"
    break;

  case 66:
#line 186 "parse.y"
                             { yyval = unaryop(yyvsp[-1], yyvsp[0]); }
#line 1915 "y.tab.c"
    break;

  case 67:
#line 187 "parse.y"
                              { yyval = unaryop(yyvsp[-1], yyvsp[0]); }
#line 1921 "y.tab.c"
    break;

  case 69:
#line 189 "parse.y"
                         { yyval = unaryop(yyvsp[-1], yyvsp[0]); }
#line 1927 "y.tab.c"
    break;

  case 70:
#line 190 "parse.y"
                          { yyval = unaryop(yyvsp[-1], yyvsp[0]); }
#line 1933 "y.tab.c"
    break;

  case 72:
#line 194 "parse.y"
                                    { instconst(yyvsp[-2], yyvsp[0]); }
#line 1939 "y.tab.c"
    break;

  case 77:
#line 204 "parse.y"
                                 { insttype(yyvsp[-2], yyvsp[0]); }
#line 1945 "y.tab.c"
    break;

  case 78:
#line 207 "parse.y"
                                         { yyval = cons(yyvsp[-2], yyvsp[0]); }
#line 1951 "y.tab.c"
    break;

  case 79:
#line 208 "parse.y"
                        { yyval = cons(yyvsp[0], NULL); }
#line 1957 "y.tab.c"
    break;

  case 81:
#line 212 "parse.y"
                        { yyval = unaryop(yyvsp[-1], yyvsp[0]); }
#line 1963 "y.tab.c"
    break;

  case 82:
#line 213 "parse.y"
                         { yyval = unaryop(yyvsp[-1], yyvsp[0]); }
#line 1969 "y.tab.c"
    break;

  case 83:
#line 214 "parse.y"
                                   { yyval = binop(yyvsp[-1], yyvsp[-2], yyvsp[0]); }
#line 1975 "y.tab.c"
    break;

  case 84:
#line 215 "parse.y"
                                    { yyval = binop(yyvsp[-1], yyvsp[-2], yyvsp[0]); }
#line 1981 "y.tab.c"
    break;

  case 85:
#line 216 "parse.y"
                                 { yyval = binop(yyvsp[-1], yyvsp[-2], yyvsp[0]); }
#line 1987 "y.tab.c"
    break;

  case 86:
#line 219 "parse.y"
                                { yyval = instfields(yyvsp[-2], yyvsp[0]); }
#line 1993 "y.tab.c"
    break;

  case 87:
#line 221 "parse.y"
                                          { yyval = nconc(yyvsp[-2], yyvsp[0]); }
#line 1999 "y.tab.c"
    break;

  case 89:
#line 225 "parse.y"
                                               { yyval = yyvsp[0]; }
#line 2005 "y.tab.c"
    break;

  case 91:
#line 229 "parse.y"
                                     { instlabel(yyvsp[-2]); }
#line 2011 "y.tab.c"
    break;

  case 92:
#line 230 "parse.y"
                     { instlabel(yyvsp[0]); }
#line 2017 "y.tab.c"
    break;

  case 93:
#line 233 "parse.y"
                                            { yyval = cons(yyvsp[-2], yyvsp[0]); }
#line 2023 "y.tab.c"
    break;

  case 94:
#line 234 "parse.y"
                         { yyval = cons(yyvsp[0], NULL); }
#line 2029 "y.tab.c"
    break;


#line 2033 "y.tab.c"

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
#line 237 "parse.y"


/* You should add your own debugging flags below, and add debugging
   printouts to your programs.

   You will want to change DEBUG to turn off printouts once things
   are working.
  */

#define DEBUG           0             /* set bits here for debugging, 0 = off  */
#define DB_CONS         1             /* bit to trace cons */
#define DB_BINOP        2             /* bit to trace binop */
#define DB_MAKEIF       4             /* bit to trace makeif */
#define DB_MAKEPROGN    8             /* bit to trace makeprogn */
#define DB_PARSERES    16             /* bit to trace parseresult */
#define DB_MAKEPROGRAM 32             /* bit to trace makeprogram */
#define DB_MAKEFOR     64             /* bit to trace makefor */

 int labelnumber = 0;  /* sequential counter for internal label numbers */

 int label_table[50];

   /*  Note: you should add to the above values and insert debugging
       printouts in your routines similar to those that are shown here.     */

TOKEN cons(TOKEN item, TOKEN list)           /* add item to front of list */
  { item->link = list;
    if (DEBUG & DB_CONS)
       { printf("cons\n");
         dbugprinttok(item);
         dbugprinttok(list);
       };
    return item;
  }

TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs)        /* reduce binary operator */
  { op->operands = lhs;          /* link operands to operator       */
    lhs->link = rhs;             /* link second operand to first    */
    rhs->link = NULL;            /* terminate operand list          */
    if (DEBUG & DB_BINOP)
       { printf("binop\n");
         dbugprinttok(op);
         dbugprinttok(lhs);
         dbugprinttok(rhs);
       };

    /* TYPE INFERENCE */
    TOKEN tok_fixed;

    if (lhs->basicdt == INTEGER) {
      if (rhs->basicdt == INTEGER) {
        // both are ints
        op->basicdt = INTEGER;
      } else if (rhs->basicdt == REAL) {
        // lhs is int, rhs is real
      
        // if assign op -> fix rhs
        if (op->whichval == ASSIGNOP) {
          tok_fixed = makefix(rhs);
          op->basicdt = INTEGER;
          lhs->link = tok_fixed;
        } else {
          // if any other op -> becomes real
          tok_fixed = makefloat(lhs);
          op->basicdt = REAL;
          op->operands = tok_fixed;
          tok_fixed->link = rhs;
        }
      }
    } else if (lhs->basicdt == REAL) {
      op->basicdt = REAL;

      // if both are real do nothing
      if (rhs->basicdt == INTEGER) {
        tok_fixed = makefloat(rhs);
        lhs->link = tok_fixed;
      }
    }

    return op;
  }
// int isReal(TOKEN tok) {
//   if(tok->basicdt == REAL)
//     return 1;
//   else 
//     return 0;
// }

// int isInt(TOKEN tok) {
//   if(tok->basicdt == INTEGER)
//     return 1;
//   else 
//     return 0;
// }

// TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs)        /* reduce binary operator */
//   {     
//     if (rhs->whichval == (NIL - RESERVED_BIAS)) {
//       rhs = makeintc(0);
//     }

//     op->operands = lhs;          /* link operands to operator       */
//     lhs->link = rhs;             /* link second operand to first    */
//     rhs->link = NULL;            /* terminate operand list          */



//     if (isReal(lhs) && isReal(rhs)) {
//       op->basicdt = REAL;     
//     } else if (isReal(lhs) && isInt(rhs)) {
//       op->basicdt = REAL;
//       TOKEN ftok = makefloat(rhs);
//       lhs->link = ftok;
//     } else if (isInt(lhs) && isReal(rhs)) {
//       if (op->whichval == ASSIGNOP) {
//         op->basicdt = INTEGER;
//         TOKEN fixtok = makefix(rhs);
//         lhs->link = fixtok;
//       } else {
//         op->basicdt = REAL;
//         TOKEN ftok = makefloat(lhs);
//         ftok->link = rhs;
//       }
//     } 

//     return op;
//   }

TOKEN makeif(TOKEN tok, TOKEN exp, TOKEN thenpart, TOKEN elsepart)
  {  tok->tokentype = OPERATOR;  /* Make it look like an operator   */
     tok->whichval = IFOP;
     if (elsepart != NULL) elsepart->link = NULL;
     thenpart->link = elsepart;
     exp->link = thenpart;
     tok->operands = exp;
     if (DEBUG & DB_MAKEIF)
        { printf("makeif\n");
          dbugprinttok(tok);
          dbugprinttok(exp);
          dbugprinttok(thenpart);
          dbugprinttok(elsepart);
        };
     return tok;
   }

TOKEN makeprogn(TOKEN tok, TOKEN statements)
  {  tok->tokentype = OPERATOR;
     tok->whichval = PROGNOP;
     tok->operands = statements;
     if (DEBUG & DB_MAKEPROGN)
       { printf("makeprogn\n");
         dbugprinttok(tok);
         dbugprinttok(statements);
       };
     return tok;
   }

int wordaddress(int n, int wordsize)
  { return ((n + wordsize - 1) / wordsize) * wordsize; }
 
void yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}

/* makes tree for top-level prog */
TOKEN makeprogram(TOKEN name, TOKEN args, TOKEN statements) {
  TOKEN tok = makeop(PROGRAMOP);
  tok->operands = name;

  TOKEN progtok = makeprogn(talloc(), args);
  name->link = progtok;
  progtok->link = statements;

  if (DEBUG & DB_MAKEPROGRAM)
       { printf("makeprogram\n");
         dbugprinttok(name);
         dbugprinttok(args);
         dbugprinttok(statements);
       };
  return tok;
}
// TOKEN makeprogram(TOKEN name, TOKEN args, TOKEN statements) {
//     TOKEN tok = talloc();
//     TOKEN nameToArgs = talloc();
//     tok->tokentype = OPERATOR;
//     tok->whichval = PROGRAMOP;
//     tok->operands = name;
//     nameToArgs = makeprogn(nameToArgs, args);
//     name->link = nameToArgs;
//     nameToArgs->link = statements;
//     return tok;
//   }

/* Make a token into an integer constant */
TOKEN fillintc(TOKEN tok, int num) 
  {  
     tok->tokentype = NUMBERTOK;
     tok->basicdt = INTEGER;
     tok->intval = num;
     tok->link = NULL;
     return tok;
   }

/* Make an integer constant token */
TOKEN makeintc(int num) { return fillintc(talloc(), num); }
// TOKEN makeintc(int number) {
//   TOKEN tok = talloc();
//   tok->tokentype = NUMBERTOK;
//   tok->basicdt = INTEGER;
//   tok->intval = number;
//   return tok;
// }

/* Make an identifier token */
TOKEN makeid(char name[])
  {  TOKEN tok; int i;
     tok = (TOKEN) talloc();
     tok->tokentype = IDENTIFIERTOK;
     tok->link = NULL;
     for (i=0; i<16; i++)
          tok->stringval[i] = name[i];
     return tok;
   }

/* Make an operator token */
TOKEN makeop(int op)
  {  TOKEN tok;
     tok = (TOKEN) talloc();
     tok->tokentype = OPERATOR;
     tok->link = NULL;
     tok->operands = NULL;
     tok->whichval = op;
     return tok;
   }
// TOKEN makeop(int op){
//     TOKEN tok = talloc();
//     tok->tokentype = OPERATOR;
//     tok->whichval = op;
//     return tok;
// }

/* install variables in symbol table */
void instvars(TOKEN idlist, TOKEN typetok)
  {  SYMBOL sym, typesym; int align;
     typesym = typetok->symtype;
     align = alignsize(typesym);
     while ( idlist != NULL )   /* for each id */
       {  sym = insertsym(idlist->stringval);
          sym->kind = VARSYM;
          sym->offset =     /* "next" */
              wordaddress(blockoffs[blocknumber],
                          align);
          sym->size = typesym->size;
          blockoffs[blocknumber] =   /* "next" */
                         sym->offset + sym->size;
          sym->datatype = typesym;
          sym->basicdt = typesym->basicdt;
          idlist = idlist->link;
        };
  }

TOKEN findid(TOKEN tok) { /* the ID token */
  SYMBOL sym = searchst(tok->stringval);
  tok->symentry = sym;
  SYMBOL typ = sym->datatype;
  tok->symtype = typ;

  // int const
  if (sym->kind == CONSTSYM && sym->basicdt == INTEGER) {
    tok->basicdt = INTEGER;
    tok->intval = sym->constval.intnum;
    tok->tokentype = NUMBERTOK;
  }

  // real number const
  else if (sym->kind == CONSTSYM && sym->basicdt == REAL) {
    tok->basicdt = REAL;
    tok->realval = sym->constval.realnum;
    tok->tokentype = NUMBERTOK;
  }

  // not const
  else if ( typ->kind == BASICTYPE ||
      typ->kind == POINTERSYM)
      tok->basicdt = typ->basicdt;
  return tok;
}
// TOKEN findid(TOKEN tok) { /* the ID token */
//     SYMBOL sym, typ;
//     sym = searchst(tok->stringval);
//     tok->symentry = sym;
    
//     if (sym->kind == CONSTSYM) {
//       if (sym->basicdt == REAL) {
//         tok->tokentype = NUMBERTOK;
//         tok->basicdt = REAL;
//         tok->realval = sym->constval.realnum;
//       }
//       else if (sym->basicdt == INTEGER) {
//         tok->tokentype = NUMBERTOK;
//         tok->basicdt = INTEGER;
//         tok->intval = sym->constval.intnum;
//       }

//       return tok;
//     }

//     typ = sym->datatype;
//     tok->symtype = typ;
//     if ( typ->kind == BASICTYPE ||
//          typ->kind == POINTERSYM)
//         tok->basicdt = typ->basicdt;

//     return tok;
//   }

/* determines data type of token */
TOKEN findtype(TOKEN tok) {
  SYMBOL sym = searchst(tok->stringval);

  if (sym->kind == TYPESYM) {
    sym = sym->datatype;
  }

  tok->symtype = sym;
  return tok;
}
// TOKEN findtype(TOKEN tok) {
//     SYMBOL sym = searchst(tok->stringval);
//     if (sym->kind == TYPESYM) {
//       sym = sym->datatype;
//    }
//     tok->symtype = sym;
//     return tok;
//   }

/* Make a new token that is a copy of the given token. borrowed from subst.c */
TOKEN copytok(TOKEN origtok)
  {  TOKEN tok; int i;
     tok = (TOKEN) talloc();
     tok->tokentype = origtok->tokentype;
     tok->basicdt  = origtok->basicdt;
     tok->symtype   = origtok->symtype;
     tok->symentry  = origtok->symentry;
     for (i=0; i<16; i++)
          tok->stringval[i] = origtok->stringval[i];

     tok->link = origtok->link;

     return tok;
   }
// TOKEN copytok(TOKEN target) {
//   TOKEN copy = talloc();
//   copy->tokentype = target->tokentype;
//   copy->basicdt = target->basicdt;
//   copy->symtype = target->symtype;
//   copy->symentry = target->symentry;
//   copy->link = target->link;
//   copy->whichval = target->whichval;
//   copy->intval = target->intval;
//   copy->realval = target->realval;
//   return copy;
// }

TOKEN makegoto(int label) {
  TOKEN tok = makeop(GOTOOP);
  TOKEN ops_tok = talloc();
  ops_tok->tokentype = NUMBERTOK;
  ops_tok->basicdt = INTEGER;
  ops_tok->intval = label;
  tok->operands = ops_tok;
  return tok;
}
// TOKEN makegoto(int num){
//   TOKEN tok = talloc();
//   tok->tokentype = OPERATOR;
//   tok->whichval = GOTOOP;
//   tok->operands = makeintc(num);
//   return tok;
// }

TOKEN makenum(int number) {
  TOKEN tok = talloc();
  tok->intval = number;
  tok->basicdt = INTEGER;
  tok->tokentype = NUMBERTOK;

  return copytok(tok);
}

TOKEN makelabel() {
  TOKEN tok = talloc();
  tok->operands = makenum(labelnumber++);
  tok->whichval = LABELOP;
  tok->tokentype = OPERATOR;

  return tok;
}

/* makes structures for the for statement in Pascal
    assignment: assignment statement such as := i 1  */
TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, TOKEN endexpr,
              TOKEN tokc, TOKEN statement) {
  // make label
  TOKEN label = makelabel();
  asg->link = label;

  TOKEN tok_body = makeprogn(talloc(), statement);
  
  TOKEN tok_leop = makeop(LEOP);
  TOKEN tok_incr = makeop(PLUSOP);
  TOKEN tok_assign = makeop(ASSIGNOP);

  TOKEN ifs = makeif(talloc(), tok_leop, tok_body, NULL);

  TOKEN identifiers[3];

  for (int i = 0; i < 3; i++) {
    identifiers[i] = talloc();
    identifiers[i] = copytok(asg->operands);
  }

  tok = makeprogn(tok, asg);

  identifiers[0]->link = endexpr;
  tok_leop->operands = identifiers[0];

  tok_leop->link = tok_body;

  identifiers[2]->link = makenum(1);
  tok_incr->operands = identifiers[2];

  identifiers[1]->link = tok_incr;
  tok_assign->operands = identifiers[1];

  // goto
  TOKEN tok_goto = makegoto(labelnumber - 1);
  tok_assign->link = tok_goto;

  // connect final links of tree
  statement->link = tok_assign;

  ifs->operands = tok_leop;

  label->link = ifs;
  return tok;
}
// TOKEN makefor(int sign, TOKEN tok, TOKEN assign, TOKEN tokb, TOKEN expr, TOKEN tokc, TOKEN statements) {
//     tok = makeprogn(tok, assign);
//     TOKEN label = makelabel();
//     int current = labelnumber - 1;
//     assign->link = label;

//     TOKEN ifs = tokb;
//     TOKEN body = tokc;
//     body = makeprogn(body, statements);

//     TOKEN leoper = makeop(LEOP);
//     ifs = makeif(ifs, leoper, body, NULL);
//     TOKEN iden = copytok(assign->operands);
//     TOKEN iden2 = copytok(iden);
//     TOKEN iden3 = copytok(iden);
//     iden->link = expr;
//     leoper->operands = iden;

//     TOKEN assgn = makeop(ASSIGNOP);
//     TOKEN increment = makeop(PLUSOP);

//     iden3->link=makeintc(1);
//     increment->operands=iden3;
//     iden2->link=increment;
//     assgn->operands=iden2;

//     TOKEN gototok = makegoto(current);
//     assgn->link = gototok;
//     statements->link = assgn;

//     leoper->link = body;
//     ifs->operands = leoper;
//     label->link = ifs;
//     return tok;
// }

/* makefuncall makes a FUNCALL operator and links it to the fn and args.
   tok is a (now) unused token that is recycled. */
TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args) {
  if (strcmp(fn->stringval, "new") == 0) {
    tok = makeop(ASSIGNOP);
    tok->operands = args;

    TOKEN funcall = makeop(FUNCALLOP);
    funcall->operands = fn;
    args->link = funcall;

    fn->link = makeintc(searchst(args->stringval)->datatype->datatype->datatype->size);
  } else {
    tok = makeop(FUNCALLOP);
    tok->operands = fn;


    tok->basicdt = searchst(fn->stringval)->datatype->basicdt;
    fn->link = args;
  }

  return tok;
}
// TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args) {
//   if (strcmp(fn->stringval, "new") == 0) {
//     tok = makeop(ASSIGNOP);
//     tok->operands = args;

//     SYMBOL typsym = args->symtype;
//     typsym = typsym->datatype;

//     TOKEN funcal = talloc();
//     funcal->tokentype = OPERATOR;
//     funcal->whichval = FUNCALLOP;
//     funcal->operands = fn;
//     fn->link = makeintc(typsym->size);
//     args->link = funcal;

//   } else {
//     tok->tokentype = OPERATOR;
//     tok->whichval = FUNCALLOP;
//     tok->operands = fn;
//     fn->link=args;
//   }
//   return tok;
// }

/* instconst installs a constant in the symbol table */
void  instconst(TOKEN idtok, TOKEN consttok) {
  SYMBOL sym = insertsym(idtok->stringval);
  sym->basicdt = consttok->basicdt;
  sym->kind = CONSTSYM;

  if (sym->basicdt == INTEGER) {
    // int so size 4
    sym->size = 4;
    sym->constval.intnum = consttok->intval;
  } else {
    // real so size 8
    sym->size = 8;
    sym->constval.realnum = consttok->realval;
  }
}
// void  instconst(TOKEN idtok, TOKEN consttok) {
//   SYMBOL sym;
//   sym = insertsym(idtok->stringval);
//   sym->kind = CONSTSYM;
//   sym->basicdt = consttok->basicdt;
//   if(sym->basicdt == REAL) {
//       sym->constval.realnum = consttok->realval;
//   }

//   if(sym->basicdt == INTEGER) 
//   {
//       sym->constval.intnum = consttok->intval;
//   }
// }

/* makerepeat makes structures for a repeat statement.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokb, TOKEN expr) {
  TOKEN label = makelabel();
  TOKEN tok_body = makeprogn(tokb, statements);
  label->link = tok_body;

  TOKEN tok_goto = makegoto(labelnumber - 1);
  TOKEN tok_done = makeprogn(talloc(), NULL);
  tok_done->link = tok_goto;

  TOKEN tok_if = makeif(talloc(), expr, tok_done, tok_goto);
  tok = makeprogn(tok, label);

  tok_body->link = tok_if;
  
  return tok;
}
// TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokb, TOKEN expr) {

//    TOKEN label = makelabel();
//    int current = labelnumber - 1;
//    tok = makeprogn(tok, label);

//    TOKEN body = tokb;
//    body = makeprogn(body, statements);
//    label->link = body;

//    TOKEN gototok = makegoto(current);
//    TOKEN emptytok = makeprogn((TOKEN) talloc(), NULL);
//    emptytok->link = gototok;

//    TOKEN ifs = talloc();
//    ifs = makeif(ifs, expr, emptytok, gototok);
//    body->link = ifs;

//    return tok;  
// }

/* unaryop links a unary operator op to one operand, lhs */
TOKEN unaryop(TOKEN op, TOKEN lhs) {
  op->operands = lhs;
  lhs->link = NULL;
  return op;
}

/* makefloat forces the item tok to be floating, by floating a constant
   or by inserting a FLOATOP operator */
TOKEN makefloat(TOKEN tok) {
  TOKEN tok_float;

  if (tok->tokentype == NUMBERTOK) {
    tok->basicdt = REAL;
    tok->realval = (double) tok->intval;
    tok_float = tok;
  } else { // (float ...)
    tok_float = makeop(FLOATOP);
    tok_float->operands = tok;
  }

  return tok_float;
}
// TOKEN makefloat(TOKEN tok) {
//   if(tok->tokentype == NUMBERTOK) {
//     tok->basicdt = REAL;
//     tok->realval = (double) tok->intval;
//     return tok;
//   } else {
//     TOKEN floatop = makeop(FLOATOP);
//     floatop->operands = tok;
//     return floatop;
//   }
// }

/* makefix forces the item tok to be integer, by truncating a constant
   or by inserting a FIXOP operator */
TOKEN makefix(TOKEN tok) {
  TOKEN tok_fix = makeop(FIXOP);
  tok_fix->operands = tok;
  return tok_fix;
}
// TOKEN makefix(TOKEN tok) {
//   if(tok->tokentype == NUMBERTOK) {
//     tok->basicdt = INTEGER;
//     tok->intval = (int) tok->realval;
//     return tok;
//   } else { 
//     TOKEN fixop = makeop(FIXOP);
//     fixop->operands = tok;
//     return fixop;
//   }
// }

/* instfields will install type in a list idlist of field name tokens:
   re, im: real    put the pointer to REAL in the RE, IM tokens.
   typetok is a token whose symtype is a symbol table pointer.
   Note that nconc() can be used to combine these lists after instrec() */
TOKEN instfields(TOKEN idlist, TOKEN typetok) {
  SYMBOL symtype = typetok->symtype;
  TOKEN curr = idlist;

  while(curr) {
    curr->symtype = symtype;
    curr = curr->link;
  }

  return idlist;
}
// TOKEN instfields(TOKEN idlist, TOKEN typetok) {
//   SYMBOL typesym = typetok->symtype;
//   TOKEN temp = idlist;
//   while(temp) {
//     temp->symtype = typesym;     
//     temp = temp->link;
//   }

//   return idlist;
// }

/***************************************************************/
/***************************************************************/
/***************************************************************/
/***************************************************************/
/***************************************************************/
/***************************************************************/
/***************************************************************/
/***************************************************************/
/***************************************************************/
/***************************************************************/
/***************************************************************/
/***************************************************************/
/***************************************************************/
/***************************************************************/
/***************************************************************/
/***************************************************************/
/***************************************************************/
/***************************************************************/
/***************************************************************/
/***************************************************************/
/***************************************************************/
int findlabelnumber(int label) {
  for(int i = 0; i < labelnumber; i ++) {
    if (label_table[i] == label) {
      return i;
    }
  }
  return -1;
}

/* dolabel is the action for a label of the form   <number>: <statement>
   tok is a (now) unused token that is recycled. */
TOKEN dolabel(TOKEN labeltok, TOKEN tok, TOKEN statement) {
  int i = 0;
  while (i < labelnumber && label_table[i] != labeltok->intval) {
    ++i;
  }

  i = i == labelnumber ? -1 : i;

  TOKEN tokprogn = makeop(PROGNOP);
  TOKEN toklabel = makeop(LABELOP);
  TOKEN toki = makeintc(i);

  toklabel->operands = toki;
  toklabel->link = statement;

  tokprogn->operands = toklabel;

  return (!tokprogn || !toklabel || !toki) ? NULL : tokprogn;
}
// TOKEN dolabel(TOKEN labeltok, TOKEN tok, TOKEN statement) {
//     int real_label = findlabelnumber(labeltok->intval);
//     if (real_label == -1) {
//       printf("Error: user defined label not found");
//     }

//     labeltok = makeop(LABELOP);
//     TOKEN tokb = makeintc(real_label);
//     labeltok->operands=tokb;
//     labeltok->link = statement;
//     tok = makeprogn(tok, labeltok);

//     return tok;
// }

// /* instlabel installs a user label into the label table */
void  instlabel (TOKEN num) {
  label_table[labelnumber] = num->intval;
  ++labelnumber;
}
// void  instlabel (TOKEN num) {
//   label_table[labelnumber++] = num->intval;  
// }

/* nconc concatenates two token lists, destructively, by making the last link
   of lista point to listb.
   (nconc '(a b) '(c d e))  =  (a b c d e)  */
/* nconc is useful for putting together two fieldlist groups to
   make them into a single list in a record declaration. */
/* nconc should return lista, or listb if lista is NULL. */
TOKEN nconc(TOKEN lista, TOKEN listb) {
  if (!lista || !listb) {
    return NULL;
  }

  // fencepost
  TOKEN tok = lista, curr = tok->link;

  while (curr) {
    tok = curr;
    curr = curr->link;
  }

  tok->link = listb;

  return tok;
}
// TOKEN nconc(TOKEN lista, TOKEN listb) {
//   TOKEN temp = lista;
//   while(temp->link) {
//     temp = temp->link;
//   }
//   temp->link = listb;
//   return temp;
// }

/* dogoto is the action for a goto statement.
   tok is a (now) unused token that is recycled. */
TOKEN dogoto(TOKEN tok, TOKEN labeltok) {
  int i = 0;
  while (i < labelnumber && label_table[i] != labeltok->intval) {
    ++i;
  }

  i = i == labelnumber ? -1 : i;

  return makegoto(i);
}
// TOKEN dogoto(TOKEN tok, TOKEN labeltok) {
//     int real_label = findlabelnumber(labeltok->intval);
//     if (real_label == -1) {
//       printf("Error: user defined label not found");
//     }  

//     tok = makegoto(real_label);

//     return tok;
// }

/* instrec will install a record definition.  Each token in the linked list
   argstok has a pointer its type.  rectok is just a trash token to be
   used to return the result in its symtype */
TOKEN instrec(TOKEN rectok, TOKEN argstok) {
  SYMBOL record = symalloc();
  record->kind = RECORDSYM;
  record->datatype = argstok->symtype;

  SYMBOL prev;

  // fencepost
  int next = 0;
  int size = wordaddress(argstok->symtype->size, 8);
  while(argstok) {
    SYMBOL field = makesym(argstok->stringval);
    field->offset = wordaddress(next, 8);
    field->datatype = argstok->symtype;
    field->size = field->datatype->size;

    if (next == 0) {
      record->datatype = field;
      prev = field;
    } else {
      prev->link = field;
      prev = field;
    }

    next = field->size + field->offset;
    argstok = argstok->link;
    field->link = NULL;
  }

  record->size = wordaddress(next, 16);
  rectok->symtype = record;
  return rectok;
}
// TOKEN instrec(TOKEN rectok, TOKEN argstok) {
//   //Do storage allocation algorithm
//   SYMBOL recsym = symalloc();
//   recsym->kind = RECORDSYM;
//   int count = 0, next = 0, align;

//   SYMBOL prev = NULL;
//   while (argstok) {
//     align = alignsize(argstok->symtype);
//     SYMBOL recfield = makesym(argstok->stringval);
//     recfield->datatype = argstok->symtype;
//     recfield->offset = wordaddress(next, align);
//     recfield->size = argstok->symtype->size;
//     next = recfield->offset + recfield->size;
//     if (count == 0) {
//       recsym->datatype = recfield;
//       prev = recfield;
//     } else {
//       prev->link = recfield;
//       prev = recfield;
//     }
//     recfield->link = NULL;
//     count ++;
//     argstok = argstok->link;
//   }

//   recsym->size = wordaddress(next, 16); 
//   rectok->symtype = recsym;

//   return rectok;
// }

/* insttype will install a type name in symbol table.
   typetok is a token containing symbol table pointers. */
void  insttype(TOKEN typename, TOKEN typetok) {
  SYMBOL type = searchins(typename->stringval);
  type->datatype = typetok->symtype;
  type->kind = TYPESYM;
  type->size = typetok->symtype->size;
  type->basicdt = typetok->symtype->basicdt;
}
// void  insttype(TOKEN typename, TOKEN typetok) {
//   SYMBOL typesym = searchins(typename->stringval);
//   typesym->kind = TYPESYM;
//   typesym->datatype = typetok->symtype;
//   typesym->size = typetok->symtype->size;
// }

/* instpoint will install a pointer type in symbol table */
TOKEN instpoint(TOKEN tok, TOKEN typename) {
  SYMBOL ptr = symalloc();
  ptr->basicdt = POINTER;
  ptr->kind = POINTERSYM;
  ptr->datatype = searchins(typename->stringval);
  ptr->size = 8;

  tok->symtype = ptr;
  return tok;
}
// TOKEN instpoint(TOKEN tok, TOKEN typename) {

//   SYMBOL typesym = searchins(typename->stringval);


//   SYMBOL pointsym = symalloc();
//   pointsym->datatype = typesym;
//   pointsym->kind = POINTERSYM;
//   pointsym->size = basicsizes[POINTER];
//   pointsym->basicdt = POINTER;

//   tok->symtype = pointsym;

//   return tok;
// }

/* instarray installs an array declaration into the symbol table.
   bounds points to a SUBRANGE symbol table entry.
   The symbol table pointer is returned in token typetok. */
TOKEN instarray(TOKEN bounds, TOKEN typetok) {
  TOKEN bound = bounds;
  SYMBOL prev = NULL;

  int lower_bound = bound->symtype->lowbound, upper_bound = bound->symtype->highbound;
  while (bound) {
    lower_bound = bound->symtype->lowbound;
    upper_bound = bound->symtype->highbound;

    SYMBOL array = symalloc();
    array->kind = ARRAYSYM;
    array->size = searchst(typetok->stringval)->size * (upper_bound - lower_bound + 1);

    if (searchst(typetok->stringval)) {
      array->datatype = searchst(typetok->stringval);
    }

    if (prev != NULL) {
      array->datatype = typetok->symtype;
      array->size = prev->size * (upper_bound - lower_bound + 1);
    }

    prev = array;
    typetok->symtype = array;

    bound = bound->link;
    array->lowbound = lower_bound;
    array->highbound = upper_bound;
  }

  return typetok;
}
// TOKEN instarray(TOKEN bounds, TOKEN typetok) {
//   if (bounds->link) {
//     typetok = instarray(bounds->link, typetok);

//     SYMBOL subrange = bounds->symtype;
//     SYMBOL typesym = typetok->symtype;
//     SYMBOL arraysym = symalloc();

//     arraysym->kind = ARRAYSYM;
//     arraysym->datatype = typesym;
//     arraysym->lowbound = subrange->lowbound;
//     arraysym->highbound = subrange->highbound;
//     arraysym->size = (arraysym->lowbound + arraysym->highbound - 1) * (typesym->size);
//     typetok->symtype = arraysym;

//   return typetok;


//   } else {

//     SYMBOL subrange = bounds->symtype;
//     SYMBOL typesym = typetok->symtype;
//     SYMBOL arraysym = symalloc();
//     arraysym->kind = ARRAYSYM;
//     arraysym->datatype = typesym;
//     arraysym->lowbound = subrange->lowbound;
//     arraysym->highbound = subrange->highbound;
//     arraysym->size = (arraysym->highbound - arraysym->lowbound +  1) * (typesym->size);
//     typetok->symtype = arraysym;

//     return typetok;
//   }
// }

/* instdotdot installs a .. subrange in the symbol table.
   dottok is a (now) unused token that is recycled. */
TOKEN instdotdot(TOKEN lowtok, TOKEN dottok, TOKEN hightok) {
  return makesubrange(dottok, lowtok->intval, hightok->intval);
}
// TOKEN instdotdot(TOKEN lowtok, TOKEN dottok, TOKEN hightok) {
//   int low = lowtok->intval;
//   int high = hightok->intval;

//   return makesubrange(dottok, low, high);
// }

/* makesubrange makes a SUBRANGE symbol table entry, puts the pointer to it
   into tok, and returns tok. */
TOKEN makesubrange(TOKEN tok, int low, int high) {
  SYMBOL sub = symalloc();
  sub->basicdt = INTEGER;
  sub->kind = SUBRANGE;

  sub->lowbound = low;
  sub->highbound = high;

  sub->size = 4;

  tok->symtype = sub;
  return tok;
}
// TOKEN makesubrange(TOKEN tok, int low, int high) {

//   SYMBOL subrange = symalloc();
//   subrange->kind = SUBRANGE;
//   subrange->basicdt = INTEGER;
//   subrange->lowbound = low;
//   subrange->highbound = high;
//   subrange->size = basicsizes[INTEGER];
//   tok->symtype = subrange;

//   return tok;
// }

/* instenum installs an enumerated subrange in the symbol table,
   e.g., type color = (red, white, blue)
   by calling makesubrange and returning the token it returns. */
TOKEN instenum(TOKEN idlist) {
  int size = -1;
  
  TOKEN idlist_copy = copytok(idlist);
  while (idlist_copy) {
    instconst(idlist_copy, makeintc(size++));
    idlist_copy = idlist_copy->link;
  }

  return makesubrange(idlist, 0, size);
}
// TOKEN instenum(TOKEN idlist) {
//   int count = 0;

//   TOKEN list = copytok(idlist);
//   while (list) {
//     instconst(list, makeintc(count));
//     count ++;
//     list = list->link;
//   }

//   TOKEN tok = makesubrange(idlist, 0, count - 1);

//   return tok;
// }

/* dopoint handles a ^ operator.  john^ becomes (^ john) with type record
   tok is a (now) unused token that is recycled. */
TOKEN dopoint(TOKEN var, TOKEN tok) {
  tok->operands = var;
  tok->symentry = var->symentry->datatype->datatype;
  return tok;
}
// TOKEN dopoint(TOKEN var, TOKEN tok) {
//   tok->symentry = var->symentry->datatype->datatype;
//   tok->operands = var;

//   return tok;
// }

/* arrayref processes an array reference a[i]
   subs is a list of subscript expressions.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN arrayref(TOKEN arr, TOKEN tok, TOKEN subs, TOKEN tokb) {
  int lower_bound = arr->symtype->lowbound, upper_bound = arr->symtype->highbound;
  int size = arr->symtype->size / (upper_bound + lower_bound - 1);

  TOKEN sizetok = makeintc(-size);
  sizetok->link = makeop(TIMESOP);
  sizetok->link->operands = makeintc(size);
  if (!subs->link) {
    sizetok->link->operands->link = subs;
  } else {
    sizetok->link->operands->link = copytok(subs);
    sizetok->link->operands->link->link = NULL;
  }

  TOKEN plustok = makeop(PLUSOP);
  plustok->operands = sizetok;

  TOKEN subarray_ref_tok = makearef(arr, plustok, tokb);
  subarray_ref_tok->symtype = arr->symtype->datatype;

  if (!subs->link) {
    return makearef(arr, plustok, tokb);
  }

  return arrayref(subarray_ref_tok, tok, subs->link, tokb);
}
// TOKEN arrayref(TOKEN arr, TOKEN tok, TOKEN subs, TOKEN tokb) {
//   if (subs->link) {
//     TOKEN timesop = makeop(TIMESOP);
//     int low = arr->symtype->lowbound;
//     int high = arr->symtype->highbound;
//     int size = (arr->symtype->size / (high + low - 1));

//     TOKEN s = copytok(subs);
//     s->link = NULL;
//     TOKEN elesize = makeintc(size);
//     elesize->link = s;
//     timesop->operands = elesize;

//     TOKEN nsize = makeintc(-1 * size);
//     nsize->link = timesop;
//     TOKEN plusop = makeop(PLUSOP);
//     plusop->operands = nsize;

//     TOKEN subarref = makearef(arr, plusop, tokb);
    
//     subarref->symtype = arr->symtype->datatype;

//     return arrayref(subarref, tok, subs->link, tokb);


//   } else {
//     TOKEN timesop = makeop(TIMESOP);
//     int low = arr->symtype->lowbound;
//     int high = arr->symtype->highbound;
//     int size = (arr->symtype->size / (high + low - 1));

//     TOKEN elesize = makeintc(size);
//     elesize->link = subs;
//     timesop->operands = elesize;

//     TOKEN nsize = makeintc(-1 * size);
//     nsize->link = timesop;
//     TOKEN plusop = makeop(PLUSOP);
//     plusop->operands = nsize;

//     return makearef(arr, plusop, tokb);
//   }

  
// }

/* reducedot handles a record reference.
   dot is a (now) unused token that is recycled. */
TOKEN reducedot(TOKEN var, TOKEN dot, TOKEN field) {
  SYMBOL curr = var->symentry->datatype->datatype;

  int offset = 0;
  while(curr && strcmp(field->stringval, curr->namestring)) {
    offset = curr->offset;
    curr = curr->link;
  }

  var->symentry = curr;
  return makearef(var, makeintc(offset), dot);
}
// TOKEN reducedot(TOKEN var, TOKEN dot, TOKEN field) {

//   SYMBOL recsym = var->symentry;
//   SYMBOL curfield = recsym->datatype->datatype;
//   int offset = 0;
//   while(curfield) {
//     if (strcmp(curfield->namestring, field->stringval) == 0) {
//       offset = curfield->offset;
//       var->symentry = curfield;
//       break;
//     } else {
//       curfield = curfield->link;
//     }
//   }

//   dot = makearef(var, makeintc(offset), dot);

//   return dot;
 
// }

/* makearef makes an array reference operation.
   off is be an integer constant token
   tok (if not NULL) is a (now) unused token that is recycled. */
TOKEN makearef(TOKEN var, TOKEN off, TOKEN tok) {
  TOKEN areftok = makeop(AREFOP);

  var->link = off;
  areftok->operands = var;
  areftok->symentry = var->symentry;

  // handle special case
  if (var->whichval == AREFOP && off->basicdt == INTEGER) {
    if (var->operands->link->whichval == PLUSOP) {
      TOKEN offtok_new = makeintc(off->intval + var->operands->link->operands->intval);
      var->operands->link->operands = offtok_new;
      offtok_new->link = var->operands->link->operands->link;
    }
  }

  return areftok;
}
// TOKEN makearef(TOKEN var, TOKEN off, TOKEN tok){
//   if (var->whichval == AREFOP && off->basicdt == INTEGER) {
    
//     TOKEN off1 = var->operands->link;
//     if (off1->whichval == PLUSOP) {
//       int num = off1->operands->intval;  
//       int num2 = off->intval;
//       TOKEN newoff = makeintc(num + num2);
//       newoff->link = off1->operands->link;
//       off1->operands = newoff;
//     }
//   }

//   TOKEN areftok = makeop(AREFOP);
//   var->link = off;
//   areftok->operands = var;
//   areftok->symentry = var->symentry;   

//   return areftok;
// }

/* makewhile makes structures for a while statement.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN makewhile(TOKEN tok, TOKEN expr, TOKEN tokb, TOKEN statement) {
  TOKEN labeltok = makelabel();

  statement->link = makegoto(labelnumber - 1);
  
  TOKEN ifs = talloc();
  ifs = makeif(ifs, expr, makeprogn(tokb, statement), NULL);
  labeltok->link = ifs;

  tok = makeprogn(tok, labeltok);
  return tok;
}
// TOKEN makewhile(TOKEN tok, TOKEN expr, TOKEN tokb, TOKEN statement) {
  
//   TOKEN label = makelabel();
//   int current = labelnumber - 1;
//   tok = makeprogn(tok, label);

//   TOKEN gototok = makegoto(current);
//   statement->link = gototok;
//   TOKEN body = makeprogn(tokb, statement);

//   TOKEN ifs = talloc();
//   ifs = makeif(ifs, expr, body, NULL);
//   label->link = ifs;

//   return tok;
  
// }

int main(void)
  { int res;
    initsyms();
    res = yyparse();
    printst();       /* to shorten, change to:  printstlevel(1);  */
    printf("yyparse result = %8d\n", res);
    if (DEBUG & DB_PARSERES) dbugprinttok(parseresult);
    ppexpr(parseresult);           /* Pretty-print the result tree */
    /* uncomment following to call code generator. */
     /* 
    gencode(parseresult, blockoffs[blocknumber], labelnumber);
 */
  }
