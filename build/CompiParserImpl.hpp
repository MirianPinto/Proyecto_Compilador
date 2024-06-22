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
    Lectura = 270,                 /* "Lectura"  */
    Escritura = 271,               /* "Escritura"  */
    Leer = 272,                    /* "Leer"  */
    Escribir = 273,                /* "Escribir"  */
    Tipo = 274,                    /* "Tipo"  */
    Registro = 275,                /* "Registro"  */
    Cerrar = 276,                  /* "Cerrar"  */
    Archivo = 277,                 /* "Archivo"  */
    Abrir = 278,                   /* "Abrir"  */
    Como = 279,                    /* "Como"  */
    Lea = 280,                     /* "Lea"  */
    Para = 281,                    /* "Para"  */
    Mientras = 282,                /* "Mientras"  */
    Haga = 283,                    /* "Haga"  */
    Hasta = 284,                   /* "Hasta"  */
    Secuencial = 285,              /* "Secuencial"  */
    Si = 286,                      /* "Si"  */
    SiNoSi = 287,                  /* "Sino Si"  */
    Entonces = 288,                /* "Entonces"  */
    Sino = 289,                    /* "Sino"  */
    Retorne = 290,                 /* "Retorne"  */
    Caso = 291,                    /* "Caso"  */
    C_O = 292,                     /* "o"  */
    C_Y = 293,                     /* "y"  */
    C_No = 294,                    /* "no"  */
    Div = 295,                     /* "div"  */
    Mod = 296,                     /* "mod"  */
    Verdadero = 297,               /* "Verdadero"  */
    Falso = 298,                   /* "Falso"  */
    Inicio = 299,                  /* "Inicio"  */
    Final = 300,                   /* "Final"  */
    Fin = 301,                     /* "Fin"  */
    Es = 302,                      /* "Es"  */
    De = 303,                      /* "De"  */
    OpenCorch = 304,               /* "["  */
    CloseCorch = 305,              /* "]"  */
    Coma = 306,                    /* ","  */
    Colon = 307,                   /* ":"  */
    OpenPar = 308,                 /* "("  */
    ClosePar = 309,                /* ")"  */
    OpPuntero = 310,               /* "<-"  */
    OpAdd = 311,                   /* "+"  */
    OpSub = 312,                   /* "-"  */
    OpMult = 313,                  /* "*"  */
    OpSombrero = 314,              /* "^"  */
    OpMenor = 315,                 /* "<"  */
    OpMayor = 316,                 /* ">"  */
    OpIgual = 317,                 /* "="  */
    OpDiple = 318,                 /* "<>"  */
    OpMenorI = 319,                /* "<="  */
    OpMayorI = 320,                /* ">="  */
    SemiColon = 321,               /* ";"  */
    Asignar = 322,                 /* "=="  */
    Number = 323,                  /* "Number"  */
    Ident = 324,                   /* "Ident"  */
    Character = 325,               /* "Character"  */
    String = 326                   /* "String"  */
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
