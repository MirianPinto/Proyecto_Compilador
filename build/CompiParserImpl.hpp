/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_HOME_MIRIAN_COMPILADORES_2_PROYECTO_COMPILADOR_BUILD_COMPIPARSERIMPL_HPP_INCLUDED
# define YY_YY_HOME_MIRIAN_COMPILADORES_2_PROYECTO_COMPILADOR_BUILD_COMPIPARSERIMPL_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 27 "CompiParserImpl.y"

      
      #include <string>
      #include "CompiAst.hpp"

      class CompiParser;

      using ParserValueType = AstNode *;

      #define YYSTYPE ParserValueType
      #define YYSTYPE_IS_DECLARED 1

#line 62 "/home/mirian/Compiladores_2/Proyecto_Compilador/build/CompiParserImpl.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    Entero = 258,                  /* "Entero"  */
    Real = 259,                    /* "Real"  */
    Cadena = 260,                  /* "Cadena"  */
    Booleano = 261,                /* "Booleano"  */
    Caracter = 262,                /* "Caracter"  */
    Arreglo = 263,                 /* "Arreglo"  */
    Var = 264,                     /* "Var"  */
    Funcion = 265,                 /* "Funcion"  */
    Procedimeinto = 266,           /* "Procedimeinto"  */
    Repita = 267,                  /* "Repita"  */
    Escriba = 268,                 /* "Escriba"  */
    Llamar = 269,                  /* "Llamar"  */
    Tipo = 270,                    /* "Tipo"  */
    Lea = 271,                     /* "Lea"  */
    Para = 272,                    /* "Para"  */
    Mientras = 273,                /* "Mientras"  */
    Haga = 274,                    /* "Haga"  */
    Hasta = 275,                   /* "Hasta"  */
    Si = 276,                      /* "Si"  */
    SiNoSi = 277,                  /* "Sino Si"  */
    Entonces = 278,                /* "Entonces"  */
    Sino = 279,                    /* "Sino"  */
    Retorne = 280,                 /* "Retorne"  */
    C_O = 281,                     /* "o"  */
    C_Y = 282,                     /* "y"  */
    C_No = 283,                    /* "no"  */
    Div = 284,                     /* "div"  */
    Mod = 285,                     /* "mod"  */
    Verdadero = 286,               /* "Verdadero"  */
    Falso = 287,                   /* "Falso"  */
    Inicio = 288,                  /* "Inicio"  */
    Final = 289,                   /* "Final"  */
    Fin = 290,                     /* "Fin"  */
    Es = 291,                      /* "Es"  */
    De = 292,                      /* "De"  */
    OpenCorch = 293,               /* "["  */
    CloseCorch = 294,              /* "]"  */
    Coma = 295,                    /* ","  */
    Colon = 296,                   /* ":"  */
    OpenPar = 297,                 /* "("  */
    ClosePar = 298,                /* ")"  */
    OpPuntero = 299,               /* "<-"  */
    OpAdd = 300,                   /* "+"  */
    OpSub = 301,                   /* "-"  */
    OpMult = 302,                  /* "*"  */
    OpSombrero = 303,              /* "^"  */
    OpMenor = 304,                 /* "<"  */
    OpMayor = 305,                 /* ">"  */
    OpIgual = 306,                 /* "="  */
    OpDiple = 307,                 /* "<>"  */
    OpMenorI = 308,                /* "<="  */
    OpMayorI = 309,                /* ">="  */
    Number = 310,                  /* "Number"  */
    Ident = 311,                   /* "Ident"  */
    Character = 312,               /* "Character"  */
    String = 313                   /* "String"  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int yyparse (CompiParser& parse);


#endif /* !YY_YY_HOME_MIRIAN_COMPILADORES_2_PROYECTO_COMPILADOR_BUILD_COMPIPARSERIMPL_HPP_INCLUDED  */
