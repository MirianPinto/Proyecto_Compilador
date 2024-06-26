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
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* "%code top" blocks.  */
#line 7 "CompiParserImpl.y"

      
      #include <iostream>
      #include <stdexcept>
      #include "CompiLexer.hpp"
      #include "CompiParser.hpp"
      #include "CompiAst.hpp"
      
      #define yylex(v) static_cast<int>(parse.getLexer().nextToken(v))

      void yyerror(const CompiParser& parse, const char *msg)\
      {\
            std::string complemento = " at the line ";
            std::string msgcompleto  = msg + complemento + std::to_string(parse.getLexer().line());

            throw std::runtime_error(msgcompleto.c_str());\
            }\
      

#line 88 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"




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

#include "CompiParserImpl.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_Entero = 3,                     /* "Entero"  */
  YYSYMBOL_Real = 4,                       /* "Real"  */
  YYSYMBOL_Cadena = 5,                     /* "Cadena"  */
  YYSYMBOL_Booleano = 6,                   /* "Booleano"  */
  YYSYMBOL_Caracter = 7,                   /* "Caracter"  */
  YYSYMBOL_Arreglo = 8,                    /* "Arreglo"  */
  YYSYMBOL_Var = 9,                        /* "Var"  */
  YYSYMBOL_Funcion = 10,                   /* "Funcion"  */
  YYSYMBOL_Procedimeinto = 11,             /* "Procedimeinto"  */
  YYSYMBOL_Repita = 12,                    /* "Repita"  */
  YYSYMBOL_Escriba = 13,                   /* "Escriba"  */
  YYSYMBOL_Llamar = 14,                    /* "Llamar"  */
  YYSYMBOL_Tipo = 15,                      /* "Tipo"  */
  YYSYMBOL_Lea = 16,                       /* "Lea"  */
  YYSYMBOL_Para = 17,                      /* "Para"  */
  YYSYMBOL_Mientras = 18,                  /* "Mientras"  */
  YYSYMBOL_Haga = 19,                      /* "Haga"  */
  YYSYMBOL_Hasta = 20,                     /* "Hasta"  */
  YYSYMBOL_Si = 21,                        /* "Si"  */
  YYSYMBOL_SiNoSi = 22,                    /* "Sino Si"  */
  YYSYMBOL_Entonces = 23,                  /* "Entonces"  */
  YYSYMBOL_Sino = 24,                      /* "Sino"  */
  YYSYMBOL_Retorne = 25,                   /* "Retorne"  */
  YYSYMBOL_C_O = 26,                       /* "o"  */
  YYSYMBOL_C_Y = 27,                       /* "y"  */
  YYSYMBOL_C_No = 28,                      /* "no"  */
  YYSYMBOL_Div = 29,                       /* "div"  */
  YYSYMBOL_Mod = 30,                       /* "mod"  */
  YYSYMBOL_Verdadero = 31,                 /* "Verdadero"  */
  YYSYMBOL_Falso = 32,                     /* "Falso"  */
  YYSYMBOL_Inicio = 33,                    /* "Inicio"  */
  YYSYMBOL_Final = 34,                     /* "Final"  */
  YYSYMBOL_Fin = 35,                       /* "Fin"  */
  YYSYMBOL_Es = 36,                        /* "Es"  */
  YYSYMBOL_De = 37,                        /* "De"  */
  YYSYMBOL_OpenCorch = 38,                 /* "["  */
  YYSYMBOL_CloseCorch = 39,                /* "]"  */
  YYSYMBOL_Coma = 40,                      /* ","  */
  YYSYMBOL_Colon = 41,                     /* ":"  */
  YYSYMBOL_OpenPar = 42,                   /* "("  */
  YYSYMBOL_ClosePar = 43,                  /* ")"  */
  YYSYMBOL_OpPuntero = 44,                 /* "<-"  */
  YYSYMBOL_OpAdd = 45,                     /* "+"  */
  YYSYMBOL_OpSub = 46,                     /* "-"  */
  YYSYMBOL_OpMult = 47,                    /* "*"  */
  YYSYMBOL_OpSombrero = 48,                /* "^"  */
  YYSYMBOL_OpMenor = 49,                   /* "<"  */
  YYSYMBOL_OpMayor = 50,                   /* ">"  */
  YYSYMBOL_OpIgual = 51,                   /* "="  */
  YYSYMBOL_OpDiple = 52,                   /* "<>"  */
  YYSYMBOL_OpMenorI = 53,                  /* "<="  */
  YYSYMBOL_OpMayorI = 54,                  /* ">="  */
  YYSYMBOL_Number = 55,                    /* "Number"  */
  YYSYMBOL_Ident = 56,                     /* "Ident"  */
  YYSYMBOL_Character = 57,                 /* "Character"  */
  YYSYMBOL_String = 58,                    /* "String"  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_input = 60,                     /* input  */
  YYSYMBOL_program = 61,                   /* program  */
  YYSYMBOL_62_subtypes_section = 62,       /* subtypes-section  */
  YYSYMBOL_decl_Var = 63,                  /* decl_Var  */
  YYSYMBOL_64_type_subtypes = 64,          /* type-subtypes  */
  YYSYMBOL_tipos_variables = 65,           /* tipos_variables  */
  YYSYMBOL_more_iden = 66,                 /* more_iden  */
  YYSYMBOL_block_decl = 67,                /* block_decl  */
  YYSYMBOL_declaraciones = 68,             /* declaraciones  */
  YYSYMBOL_decl_procedieminto = 69,        /* decl_procedieminto  */
  YYSYMBOL_decl_funcion = 70,              /* decl_funcion  */
  YYSYMBOL_decl_parametros_funcion = 71,   /* decl_parametros_funcion  */
  YYSYMBOL_decl_var_funcion = 72,          /* decl_var_funcion  */
  YYSYMBOL_tipos_paramettros = 73,         /* tipos_paramettros  */
  YYSYMBOL_main = 74,                      /* main  */
  YYSYMBOL_block_actions = 75,             /* block_actions  */
  YYSYMBOL_actions = 76,                   /* actions  */
  YYSYMBOL_struct_lea = 77,                /* struct_lea  */
  YYSYMBOL_llamar_arreglo = 78,            /* llamar_arreglo  */
  YYSYMBOL_estructura_llamar = 79,         /* estructura_llamar  */
  YYSYMBOL_asign_Var = 80,                 /* asign_Var  */
  YYSYMBOL_asignar = 81,                   /* asignar  */
  YYSYMBOL_f_escriba = 82,                 /* f_escriba  */
  YYSYMBOL_cliclo_for = 83,                /* cliclo_for  */
  YYSYMBOL_cliclo_While = 84,              /* cliclo_While  */
  YYSYMBOL_cliclo_Repeat = 85,             /* cliclo_Repeat  */
  YYSYMBOL_si_statement = 86,              /* si_statement  */
  YYSYMBOL_si2_statement = 87,             /* si2_statement  */
  YYSYMBOL_retorne = 88,                   /* retorne  */
  YYSYMBOL_funcion_llamado = 89,           /* funcion_llamado  */
  YYSYMBOL_parametros = 90,                /* parametros  */
  YYSYMBOL_parametros_mult = 91,           /* parametros_mult  */
  YYSYMBOL_escriba_list = 92,              /* escriba_list  */
  YYSYMBOL_valores = 93,                   /* valores  */
  YYSYMBOL_tipo = 94,                      /* tipo  */
  YYSYMBOL_valores_ciclos = 95,            /* valores_ciclos  */
  YYSYMBOL_expr = 96,                      /* expr  */
  YYSYMBOL_term = 97,                      /* term  */
  YYSYMBOL_condi = 98,                     /* condi  */
  YYSYMBOL_factor = 99,                    /* factor  */
  YYSYMBOL_enteros = 100                   /* enteros  */
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

#if 1

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
#endif /* 1 */

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
#define YYLAST   507

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  232

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   313


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
      55,    56,    57,    58
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   108,   108,   111,   115,   116,   117,   121,   122,   123,
     126,   127,   130,   131,   132,   136,   137,   138,   142,   143,
     144,   148,   149,   153,   158,   162,   163,   167,   168,   173,
     174,   175,   176,   177,   178,   183,   187,   188,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   207,   211,
     215,   219,   222,   223,   226,   229,   232,   235,   238,   239,
     240,   242,   243,   244,   247,   250,   253,   254,   255,   258,
     259,   265,   266,   269,   270,   271,   272,   273,   276,   277,
     278,   279,   280,   284,   285,   289,   290,   291,   294,   295,
     296,   297,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   312,   313,   314,   315,   316,   317,   318,   319,
     322,   323
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "\"Entero\"",
  "\"Real\"", "\"Cadena\"", "\"Booleano\"", "\"Caracter\"", "\"Arreglo\"",
  "\"Var\"", "\"Funcion\"", "\"Procedimeinto\"", "\"Repita\"",
  "\"Escriba\"", "\"Llamar\"", "\"Tipo\"", "\"Lea\"", "\"Para\"",
  "\"Mientras\"", "\"Haga\"", "\"Hasta\"", "\"Si\"", "\"Sino Si\"",
  "\"Entonces\"", "\"Sino\"", "\"Retorne\"", "\"o\"", "\"y\"", "\"no\"",
  "\"div\"", "\"mod\"", "\"Verdadero\"", "\"Falso\"", "\"Inicio\"",
  "\"Final\"", "\"Fin\"", "\"Es\"", "\"De\"", "\"[\"", "\"]\"", "\",\"",
  "\":\"", "\"(\"", "\")\"", "\"<-\"", "\"+\"", "\"-\"", "\"*\"", "\"^\"",
  "\"<\"", "\">\"", "\"=\"", "\"<>\"", "\"<=\"", "\">=\"", "\"Number\"",
  "\"Ident\"", "\"Character\"", "\"String\"", "$accept", "input",
  "program", "subtypes-section", "decl_Var", "type-subtypes",
  "tipos_variables", "more_iden", "block_decl", "declaraciones",
  "decl_procedieminto", "decl_funcion", "decl_parametros_funcion",
  "decl_var_funcion", "tipos_paramettros", "main", "block_actions",
  "actions", "struct_lea", "llamar_arreglo", "estructura_llamar",
  "asign_Var", "asignar", "f_escriba", "cliclo_for", "cliclo_While",
  "cliclo_Repeat", "si_statement", "si2_statement", "retorne",
  "funcion_llamado", "parametros", "parametros_mult", "escriba_list",
  "valores", "tipo", "valores_ciclos", "expr", "term", "condi", "factor",
  "enteros", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-51)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-108)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -7,   -46,    22,   -51,    26,   -10,   -51,   -51,   -51,   -51,
     -51,   -51,     1,     5,     7,    67,   -51,    20,   125,    11,
      52,   -51,    25,    38,   -51,    10,   -51,   -51,   -51,    16,
      63,   -51,   -51,    64,   125,    78,    78,   362,   -51,   -51,
      49,    81,    69,    85,   -51,   105,    84,   133,   362,   377,
      70,    86,    86,   451,   451,   377,    96,   225,   -51,   -51,
     -51,   -51,   -51,   106,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,    97,   115,   252,   118,   198,   102,   -15,   -51,   103,
     252,    46,   251,   107,   395,   424,   451,   110,   -51,   -29,
     -51,   -51,   -51,   -51,   122,   -51,    13,   -23,   410,   -51,
     -51,   127,   -51,   -51,   123,   -51,   -51,   343,    19,   -51,
     451,   -51,   -51,   377,   -51,   135,   119,   128,   140,   131,
     132,   -51,   105,   -51,   -51,   133,   362,   451,   -51,    -8,
     -51,   358,   -51,   377,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   362,
     362,    54,   -51,   252,   -51,   152,   137,   -51,   -51,   -51,
     192,   261,   410,   -51,   -51,     4,   -51,   -51,   -23,   -23,
     410,   410,   410,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   190,    13,   194,   276,   195,   -51,   -51,   178,
     179,   362,   -51,   377,   -51,   451,   203,   451,   362,   208,
     252,   196,   302,   -51,     0,   -51,   -51,    45,   317,   -51,
     180,   252,   -51,   362,   362,   219,   -51,   188,   332,   210,
     -51,   -51,   230,   451,   362,   228,   -51,   -51,   347,   -51,
     231,   -51
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     0,     0,     2,     9,     0,     1,    78,    79,    80,
      81,    82,     0,     0,     0,    20,     8,     0,     0,     0,
       0,    14,     0,     0,     7,     0,    19,    22,    21,    17,
       0,     5,    10,     0,     0,    26,    26,    47,    18,     3,
       0,    13,     0,     0,     4,     0,     0,     9,    47,     0,
       0,     0,     0,     0,     0,     0,    52,     0,    37,    45,
      53,    42,    38,     0,    39,    40,    43,    44,    46,    41,
      16,     0,     0,     0,     0,     0,     0,     0,    28,     0,
       0,     0,     0,     0,    74,    75,     0,     0,   110,    68,
      76,    77,   108,   109,    54,    72,    73,    87,    91,   101,
     103,    68,    50,    48,     0,   106,   107,     0,     0,    64,
       0,    35,    36,     0,    15,     0,     0,     0,     0,     0,
       0,    32,     0,    25,    33,     9,    47,     0,   105,     0,
     111,     0,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      47,     0,    51,     0,    12,     0,     0,    31,    30,    27,
       0,     0,    57,   102,    67,     0,    69,    71,    85,    86,
      89,    90,    88,    98,    99,    97,    93,    92,   100,    96,
      95,    94,     0,    84,   103,     0,     0,    49,    11,     0,
       0,    47,    23,     0,    66,     0,     0,     0,    47,     0,
       0,     0,     0,    70,     0,    56,    58,     0,     0,    60,
       0,     0,    24,    47,    47,     0,    34,     0,     0,     0,
      59,    29,     0,     0,    47,     0,    55,    61,     0,    63,
       0,    62
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -51,   -51,   -51,   -51,   -45,   227,   -14,   -51,   -51,   237,
     -51,   -51,   217,   -51,   148,   -51,   -43,   -42,   -51,   -34,
     -51,   -51,    33,   -51,   -51,   -51,   -51,   -51,    57,   -51,
     233,   -51,   -51,   -51,   -44,   -18,   -51,   -50,   -17,   -41,
     345,   136
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    15,    31,    16,    41,    25,    26,
      27,    28,    46,    77,    78,    39,    57,    58,    59,    92,
      61,    62,    63,    64,    65,    66,    67,    68,   206,    69,
      93,   132,   165,    94,    95,    17,   182,    96,    97,    98,
      99,   100
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    24,    81,    60,   108,    82,   136,   137,     1,   110,
       5,   109,   107,   131,    60,   112,    32,    60,    60,   213,
      22,    23,     6,    60,   138,   122,    18,    79,   123,     7,
       8,     9,    10,    11,    12,   163,   129,   134,   135,    19,
     112,    13,   150,    37,   193,   134,   135,   194,    60,     7,
       8,     9,    10,    11,    12,   116,    40,   120,   134,   135,
     151,    20,   125,    21,   134,   135,    33,    24,   214,   152,
       7,     8,     9,    10,    11,    12,    29,    22,    23,   126,
     160,    35,    14,   161,   103,   104,   162,   166,    34,   167,
     134,   135,    60,   187,    36,   170,   171,   172,   183,   134,
     135,    42,    14,    43,    79,    70,   185,   186,     7,     8,
       9,    10,    11,    74,    75,    60,    60,   168,   169,   112,
      45,    71,    73,    14,    72,    80,   101,    60,     7,     8,
       9,    10,    11,    30,   110,   188,     7,     8,     9,    10,
      11,    12,    56,   112,   112,   204,    24,   207,   202,   203,
     113,    60,    60,   114,   115,   208,   117,    60,   121,   124,
     112,    76,   133,   128,    60,   130,   112,   148,    60,   131,
     218,   219,   153,   207,    60,   154,   112,   112,   156,    60,
      60,   228,   210,   155,    60,    60,   112,   157,   158,    14,
      60,   189,   190,   217,    60,     7,     8,     9,    10,    11,
      12,     7,     8,     9,    10,    11,   118,    48,    49,    50,
     195,    51,    52,    53,   -83,   200,    54,   197,   201,   198,
      55,   205,    48,    49,    50,   191,    51,    52,    53,   209,
     199,    54,   223,   211,   224,    55,   216,    48,    49,    50,
     220,    51,    52,    53,   221,   225,    54,   226,    14,   229,
      55,    56,   231,    47,   119,     7,     8,     9,    10,    11,
     111,    44,    38,    48,    49,    50,    56,    51,    52,    53,
     159,   127,    54,    48,    49,    50,    55,    51,    52,    53,
     227,    56,    54,   102,   184,     0,    55,     0,    48,    49,
      50,     0,    51,    52,    53,     0,   192,    54,     0,     0,
       0,    55,     0,     0,     0,     0,     0,    56,     0,     0,
       0,   196,     0,     0,    48,    49,    50,    56,    51,    52,
      53,     0,     0,    54,     0,     0,     0,    55,     0,    48,
      49,    50,    56,    51,    52,    53,     0,   212,    54,     0,
       0,     0,    55,     0,    48,    49,    50,     0,    51,    52,
      53,     0,   215,    54,     0,     0,     0,    55,    56,    48,
      49,    50,   149,    51,    52,    53,     0,   222,    54,   139,
     140,     0,    55,    56,    48,    49,    50,     0,    51,    52,
      53,     0,   230,    54,     0,     0,    83,    55,    56,    84,
      85,   141,   142,   143,   144,   145,   146,   147,     0,     0,
      86,   164,     0,    56,    87,    83,     0,     0,    84,    85,
       0,     0,     0,    88,    89,    90,    91,     0,    56,    86,
       0,  -106,  -106,    87,  -106,  -106,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,   139,   140,     0,     0,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
    -107,  -107,     0,  -107,  -107,     0,     0,     0,   141,   142,
     143,   144,   145,   146,   147,     0,     0,     0,     0,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,    83,
       0,     0,   105,   106,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    86,     0,     0,     0,    87,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89
};

static const yytype_int16 yycheck[] =
{
      18,    15,    47,    37,    54,    48,    29,    30,    15,    38,
      56,    55,    53,    42,    48,    57,    34,    51,    52,    19,
      10,    11,     0,    57,    47,    40,    36,    45,    43,     3,
       4,     5,     6,     7,     8,    43,    86,    45,    46,    38,
      82,    15,    23,    33,    40,    45,    46,    43,    82,     3,
       4,     5,     6,     7,     8,    73,    40,    75,    45,    46,
     110,    56,    80,    56,    45,    46,    55,    81,    23,   113,
       3,     4,     5,     6,     7,     8,    56,    10,    11,    33,
     125,    56,    56,   126,    51,    52,   127,   131,    36,   133,
      45,    46,   126,    39,    56,   136,   137,   138,   148,    45,
      46,    38,    56,    39,   122,    56,   149,   150,     3,     4,
       5,     6,     7,     8,     9,   149,   150,   134,   135,   161,
      42,    40,    37,    56,    55,    41,    56,   161,     3,     4,
       5,     6,     7,     8,    38,   153,     3,     4,     5,     6,
       7,     8,    56,   185,   186,   195,   160,   197,   191,   193,
      44,   185,   186,    56,    39,   198,    38,   191,    56,    56,
     202,    56,    40,    56,   198,    55,   208,    44,   202,    42,
     213,   214,    37,   223,   208,    56,   218,   219,    38,   213,
     214,   224,   200,    55,   218,   219,   228,    56,    56,    56,
     224,    39,    55,   211,   228,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,    12,    13,    14,
      20,    16,    17,    18,    20,    37,    21,    22,    39,    24,
      25,    18,    12,    13,    14,    33,    16,    17,    18,    21,
      35,    21,    22,    37,    24,    25,    56,    12,    13,    14,
      21,    16,    17,    18,    56,    35,    21,    17,    56,    21,
      25,    56,    21,    36,    56,     3,     4,     5,     6,     7,
      35,    34,    25,    12,    13,    14,    56,    16,    17,    18,
     122,    20,    21,    12,    13,    14,    25,    16,    17,    18,
     223,    56,    21,    50,   148,    -1,    25,    -1,    12,    13,
      14,    -1,    16,    17,    18,    -1,    35,    21,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    35,    -1,    -1,    12,    13,    14,    56,    16,    17,
      18,    -1,    -1,    21,    -1,    -1,    -1,    25,    -1,    12,
      13,    14,    56,    16,    17,    18,    -1,    35,    21,    -1,
      -1,    -1,    25,    -1,    12,    13,    14,    -1,    16,    17,
      18,    -1,    35,    21,    -1,    -1,    -1,    25,    56,    12,
      13,    14,    19,    16,    17,    18,    -1,    35,    21,    26,
      27,    -1,    25,    56,    12,    13,    14,    -1,    16,    17,
      18,    -1,    35,    21,    -1,    -1,    28,    25,    56,    31,
      32,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      42,    43,    -1,    56,    46,    28,    -1,    -1,    31,    32,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    56,    42,
      -1,    26,    27,    46,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    26,    27,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      26,    27,    -1,    29,    30,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    28,
      -1,    -1,    31,    32,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    42,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    60,    61,    62,    56,     0,     3,     4,     5,
       6,     7,     8,    15,    56,    63,    65,    94,    36,    38,
      56,    56,    10,    11,    65,    67,    68,    69,    70,    56,
       8,    64,    94,    55,    36,    56,    56,    33,    68,    74,
      40,    66,    38,    39,    64,    42,    71,    71,    12,    13,
      14,    16,    17,    18,    21,    25,    56,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    88,
      56,    40,    55,    37,     8,     9,    56,    72,    73,    94,
      41,    63,    75,    28,    31,    32,    42,    46,    55,    56,
      57,    58,    78,    89,    92,    93,    96,    97,    98,    99,
     100,    56,    89,    81,    81,    31,    32,    98,    96,    93,
      38,    35,    76,    44,    56,    39,    94,    38,     8,    56,
      94,    56,    40,    43,    56,    94,    33,    20,    56,    96,
      55,    42,    90,    40,    45,    46,    29,    30,    47,    26,
      27,    48,    49,    50,    51,    52,    53,    54,    44,    19,
      23,    96,    93,    37,    56,    55,    38,    56,    56,    73,
      63,    75,    98,    43,    43,    91,    93,    93,    97,    97,
      98,    98,    98,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    95,    96,   100,    75,    75,    39,    94,    39,
      55,    33,    35,    40,    43,    20,    35,    22,    24,    35,
      37,    39,    75,    93,    96,    18,    87,    96,    75,    21,
      94,    37,    35,    19,    23,    35,    56,    94,    75,    75,
      21,    56,    35,    22,    24,    35,    17,    87,    75,    21,
      35,    21
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    61,    62,    62,    62,    63,    63,    63,
      64,    64,    65,    65,    65,    66,    66,    66,    67,    67,
      67,    68,    68,    69,    70,    71,    71,    72,    72,    73,
      73,    73,    73,    73,    73,    74,    75,    75,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    77,    78,
      79,    80,    81,    81,    82,    83,    84,    85,    86,    86,
      86,    87,    87,    87,    88,    89,    90,    90,    90,    91,
      91,    92,    92,    93,    93,    93,    93,    93,    94,    94,
      94,    94,    94,    95,    95,    96,    96,    96,    97,    97,
      97,    97,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    99,    99,    99,    99,    99,    99,    99,    99,
     100,   100
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     4,     5,     4,     0,     2,     1,     0,
       1,     6,     7,     3,     2,     3,     2,     0,     2,     1,
       0,     1,     1,     7,     9,     3,     0,     3,     1,     8,
       3,     3,     2,     2,     7,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     2,     4,
       2,     3,     1,     1,     2,    10,     6,     4,     6,     8,
       6,     5,     7,     5,     2,     2,     3,     2,     0,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     1,     1,     2,     1,     1,     1,     1,
       1,     2
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
        yyerror (parse, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, parse); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, CompiParser& parse)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (parse);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, CompiParser& parse)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, parse);
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
                 int yyrule, CompiParser& parse)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], parse);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, parse); \
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, CompiParser& parse)
{
  YY_USE (yyvaluep);
  YY_USE (parse);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (CompiParser& parse)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
      yychar = yylex (&yylval);
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
  case 2: /* input: program  */
#line 108 "CompiParserImpl.y"
               { parse.setLpp(yyvsp[0]); }
#line 1677 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 3: /* program: subtypes-section decl_Var block_decl main  */
#line 111 "CompiParserImpl.y"
                                                   { yyval = new Program(yyvsp[-2],yyvsp[-1],yyvsp[0]);}
#line 1683 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 5: /* subtypes-section: "Tipo" "Ident" "Es" type-subtypes  */
#line 116 "CompiParserImpl.y"
                                                {}
#line 1689 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 7: /* decl_Var: decl_Var tipos_variables  */
#line 121 "CompiParserImpl.y"
                                   { yyval = new Declaracionvariable(yyvsp[-1],yyvsp[0]); }
#line 1695 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 8: /* decl_Var: tipos_variables  */
#line 122 "CompiParserImpl.y"
                        { yyval = yyvsp[0];}
#line 1701 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 9: /* decl_Var: %empty  */
#line 123 "CompiParserImpl.y"
        {yyval = new Vacio();}
#line 1707 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 13: /* tipos_variables: tipo "Ident" more_iden  */
#line 131 "CompiParserImpl.y"
                                   { yyval = new DeclaracionStmt(yyvsp[-1],yyvsp[0]); parse.addTipo(((IdentExpr*)(yyvsp[-2]))->text, ((IdentExpr*)(yyvsp[-1]))->text); }
#line 1713 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 14: /* tipos_variables: "Ident" "Ident"  */
#line 132 "CompiParserImpl.y"
                          {}
#line 1719 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 15: /* more_iden: more_iden "," "Ident"  */
#line 136 "CompiParserImpl.y"
                                { yyval = new DeclaracionStmt(yyvsp[-2],yyvsp[0]); parse.addTipo("lista", ((IdentExpr*)(yyvsp[0]))->text);}
#line 1725 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 16: /* more_iden: "," "Ident"  */
#line 137 "CompiParserImpl.y"
                   { yyval = yyvsp[0]; parse.addTipo("lista", ((IdentExpr*)(yyvsp[0]))->text);}
#line 1731 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 17: /* more_iden: %empty  */
#line 138 "CompiParserImpl.y"
                   { yyval = new Vacio();}
#line 1737 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 20: /* block_decl: %empty  */
#line 144 "CompiParserImpl.y"
                   {yyval = new Vacio();}
#line 1743 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 35: /* main: "Inicio" block_actions "Fin"  */
#line 183 "CompiParserImpl.y"
                               { yyval = yyvsp[-1]; }
#line 1749 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 36: /* block_actions: block_actions actions  */
#line 187 "CompiParserImpl.y"
                                     {yyval = new BlockStmts(yyvsp[-1],yyvsp[0]);}
#line 1755 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 37: /* block_actions: actions  */
#line 188 "CompiParserImpl.y"
                        {yyval = yyvsp[0]; }
#line 1761 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 38: /* actions: asign_Var  */
#line 192 "CompiParserImpl.y"
                   { yyval = yyvsp[0];}
#line 1767 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 39: /* actions: f_escriba  */
#line 193 "CompiParserImpl.y"
                  { yyval = yyvsp[0];}
#line 1773 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 40: /* actions: cliclo_for  */
#line 194 "CompiParserImpl.y"
                   { yyval = yyvsp[0];}
#line 1779 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 41: /* actions: retorne  */
#line 195 "CompiParserImpl.y"
                { yyval = yyvsp[0];}
#line 1785 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 42: /* actions: estructura_llamar  */
#line 196 "CompiParserImpl.y"
                          { yyval = yyvsp[0];}
#line 1791 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 43: /* actions: cliclo_While  */
#line 197 "CompiParserImpl.y"
                     { yyval = yyvsp[0];}
#line 1797 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 44: /* actions: cliclo_Repeat  */
#line 198 "CompiParserImpl.y"
                      { yyval = yyvsp[0];}
#line 1803 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 45: /* actions: struct_lea  */
#line 199 "CompiParserImpl.y"
                   { yyval = yyvsp[0];}
#line 1809 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 46: /* actions: si_statement  */
#line 200 "CompiParserImpl.y"
                     { yyval = yyvsp[0];}
#line 1815 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 47: /* actions: %empty  */
#line 201 "CompiParserImpl.y"
               { yyval = new Vacio();}
#line 1821 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 48: /* struct_lea: "Lea" asignar  */
#line 207 "CompiParserImpl.y"
                        { yyval = new LeaStmt(yyvsp[0]); }
#line 1827 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 49: /* llamar_arreglo: "Ident" "[" expr "]"  */
#line 211 "CompiParserImpl.y"
                                                { }
#line 1833 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 51: /* asign_Var: asignar "<-" valores  */
#line 219 "CompiParserImpl.y"
                                     {yyval = new AsignarStmt((IdentExpr*)yyvsp[-2],yyvsp[0]); }
#line 1839 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 52: /* asignar: "Ident"  */
#line 222 "CompiParserImpl.y"
               { yyval = yyvsp[0]; }
#line 1845 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 54: /* f_escriba: "Escriba" escriba_list  */
#line 226 "CompiParserImpl.y"
                                {yyval = new EscribaStmt(yyvsp[0]); }
#line 1851 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 55: /* cliclo_for: "Para" asignar "<-" valores_ciclos "Hasta" expr "Haga" block_actions "Fin" "Para"  */
#line 229 "CompiParserImpl.y"
                                                                                         { yyval = new ForStmt(new AsignarStmt((IdentExpr*)yyvsp[-8],yyvsp[-7]),(Expr*)yyvsp[-4],yyvsp[-2] ); }
#line 1857 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 56: /* cliclo_While: "Mientras" condi "Haga" block_actions "Fin" "Mientras"  */
#line 232 "CompiParserImpl.y"
                                                             { yyval = new WhileStmt(yyvsp[-4],yyvsp[-2]); }
#line 1863 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 57: /* cliclo_Repeat: "Repita" block_actions "Hasta" condi  */
#line 235 "CompiParserImpl.y"
                                                { yyval = new RepitaStmt(yyvsp[-2],(Expr*)yyvsp[0]); }
#line 1869 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 58: /* si_statement: "Si" expr "Entonces" block_actions "Sino Si" si2_statement  */
#line 238 "CompiParserImpl.y"
                                                                  { yyval = new IfStmt(yyvsp[-4],yyvsp[-2],yyvsp[0]); }
#line 1875 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 59: /* si_statement: "Si" expr "Entonces" block_actions "Sino" block_actions "Fin" "Si"  */
#line 239 "CompiParserImpl.y"
                                                                        { yyval = new IfStmt(yyvsp[-6],yyvsp[-4],yyvsp[-2]); }
#line 1881 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 60: /* si_statement: "Si" expr "Entonces" block_actions "Fin" "Si"  */
#line 240 "CompiParserImpl.y"
                                                     { yyval = new IfStmt(yyvsp[-4],yyvsp[-2],new Vacio()); }
#line 1887 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 61: /* si2_statement: expr "Entonces" block_actions "Sino Si" si2_statement  */
#line 242 "CompiParserImpl.y"
                                                                  { yyval = new IfStmt(yyvsp[-4],yyvsp[-2],yyvsp[0]); }
#line 1893 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 62: /* si2_statement: expr "Entonces" block_actions "Sino" block_actions "Fin" "Si"  */
#line 243 "CompiParserImpl.y"
                                                                     { yyval = new IfStmt(yyvsp[-6],yyvsp[-4],yyvsp[-2]); }
#line 1899 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 63: /* si2_statement: expr "Entonces" block_actions "Fin" "Si"  */
#line 244 "CompiParserImpl.y"
                                                   { yyval = new IfStmt(yyvsp[-4],yyvsp[-2],new Vacio()); }
#line 1905 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 72: /* escriba_list: valores  */
#line 266 "CompiParserImpl.y"
                      {yyval = yyvsp[0];}
#line 1911 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 73: /* valores: expr  */
#line 269 "CompiParserImpl.y"
              {yyval = yyvsp[0];}
#line 1917 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 74: /* valores: "Verdadero"  */
#line 270 "CompiParserImpl.y"
                    {yyval = new BoolExpr(1);}
#line 1923 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 75: /* valores: "Falso"  */
#line 271 "CompiParserImpl.y"
                  {yyval = new BoolExpr(0);}
#line 1929 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 76: /* valores: "Character"  */
#line 272 "CompiParserImpl.y"
                    {yyval = yyvsp[0];}
#line 1935 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 77: /* valores: "String"  */
#line 273 "CompiParserImpl.y"
                  {yyval = yyvsp[0];}
#line 1941 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 78: /* tipo: "Entero"  */
#line 276 "CompiParserImpl.y"
             { yyval = new IdentExpr("Entero"); }
#line 1947 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 79: /* tipo: "Real"  */
#line 277 "CompiParserImpl.y"
              { yyval = new IdentExpr("Real"); }
#line 1953 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 81: /* tipo: "Booleano"  */
#line 279 "CompiParserImpl.y"
                 { yyval = new IdentExpr("Booleano"); }
#line 1959 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 82: /* tipo: "Caracter"  */
#line 280 "CompiParserImpl.y"
                 { yyval = new IdentExpr("Caracter"); }
#line 1965 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 83: /* valores_ciclos: enteros  */
#line 284 "CompiParserImpl.y"
                        { yyval = yyvsp[0]; }
#line 1971 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 84: /* valores_ciclos: expr  */
#line 285 "CompiParserImpl.y"
                   { yyval = yyvsp[0]; }
#line 1977 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 85: /* expr: expr "+" term  */
#line 289 "CompiParserImpl.y"
                        { yyval = new AddExpr((Expr*)yyvsp[-2],(Expr*)yyvsp[0]);}
#line 1983 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 86: /* expr: expr "-" term  */
#line 290 "CompiParserImpl.y"
                        { yyval = new SubExpr((Expr*)yyvsp[-2],(Expr*)yyvsp[0]);}
#line 1989 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 87: /* expr: term  */
#line 291 "CompiParserImpl.y"
             { yyval = yyvsp[0]; }
#line 1995 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 88: /* term: term "*" condi  */
#line 294 "CompiParserImpl.y"
                          { yyval = new MulExpr((Expr*)yyvsp[-2],(Expr*)yyvsp[0]);}
#line 2001 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 89: /* term: term "div" condi  */
#line 295 "CompiParserImpl.y"
                       { yyval = new DivExpr((Expr*)yyvsp[-2],(Expr*)yyvsp[0]);}
#line 2007 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 90: /* term: term "mod" condi  */
#line 296 "CompiParserImpl.y"
                       { yyval = new ModExpr((Expr*)yyvsp[-2],(Expr*)yyvsp[0]);}
#line 2013 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 91: /* term: condi  */
#line 297 "CompiParserImpl.y"
              { yyval = yyvsp[0];}
#line 2019 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 92: /* condi: condi ">" factor  */
#line 300 "CompiParserImpl.y"
                            {yyval = new MayorExpr((Expr*)yyvsp[-2],(Expr*)yyvsp[0]); }
#line 2025 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 93: /* condi: condi "<" factor  */
#line 301 "CompiParserImpl.y"
                             {yyval = new MenorExpr((Expr*)yyvsp[-2],(Expr*)yyvsp[0]); }
#line 2031 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 94: /* condi: condi ">=" factor  */
#line 302 "CompiParserImpl.y"
                              {yyval = new MayorIExpr((Expr*)yyvsp[-2],(Expr*)yyvsp[0]); }
#line 2037 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 95: /* condi: condi "<=" factor  */
#line 303 "CompiParserImpl.y"
                              {yyval = new MenorIExpr((Expr*)yyvsp[-2],(Expr*)yyvsp[0]); }
#line 2043 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 96: /* condi: condi "<>" factor  */
#line 304 "CompiParserImpl.y"
                             {yyval = new DesigualExpr((Expr*)yyvsp[-2],(Expr*)yyvsp[0]); }
#line 2049 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 98: /* condi: condi "o" factor  */
#line 306 "CompiParserImpl.y"
                         {yyval = new OrExpr((Expr*)yyvsp[-2],(Expr*)yyvsp[0]);}
#line 2055 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 99: /* condi: condi "y" factor  */
#line 307 "CompiParserImpl.y"
                         {yyval = new AndExpr((Expr*)yyvsp[-2],(Expr*)yyvsp[0]);}
#line 2061 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 100: /* condi: condi "=" factor  */
#line 308 "CompiParserImpl.y"
                             {yyval = new IgualExpr((Expr*)yyvsp[-2],(Expr*)yyvsp[0]); }
#line 2067 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 101: /* condi: factor  */
#line 309 "CompiParserImpl.y"
               {yyval = yyvsp[0]; }
#line 2073 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 102: /* factor: "(" expr ")"  */
#line 312 "CompiParserImpl.y"
                              {yyval = yyvsp[-1];}
#line 2079 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 103: /* factor: enteros  */
#line 313 "CompiParserImpl.y"
                 { yyval = yyvsp[0]; }
#line 2085 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 104: /* factor: "Ident"  */
#line 314 "CompiParserImpl.y"
               { yyval = yyvsp[0]; }
#line 2091 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 105: /* factor: "no" "Ident"  */
#line 315 "CompiParserImpl.y"
                    { }
#line 2097 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 106: /* factor: "Verdadero"  */
#line 316 "CompiParserImpl.y"
                  {yyval = new BoolExpr(1);}
#line 2103 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 107: /* factor: "Falso"  */
#line 317 "CompiParserImpl.y"
                  {yyval = new BoolExpr(0);}
#line 2109 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 110: /* enteros: "Number"  */
#line 322 "CompiParserImpl.y"
                { yyval = yyvsp[0]; }
#line 2115 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;

  case 111: /* enteros: "-" "Number"  */
#line 323 "CompiParserImpl.y"
                     { yyval = yyvsp[-1]; }
#line 2121 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"
    break;


#line 2125 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.cpp"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (parse, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
                      yytoken, &yylval, parse);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, parse);
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
  yyerror (parse, YY_("memory exhausted"));
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
                  yytoken, &yylval, parse);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, parse);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

