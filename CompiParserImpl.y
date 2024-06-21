
%define parse.error verbose
%define api.pure full

%parse-param {CompiParser& parse}

%code top {
      
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

      }

%code requires
{
      
      #include <string>
      #include "CompiAst.hpp"

      class CompiParser;

      using ParserValueType = AstNode *;

      #define YYSTYPE ParserValueType
      #define YYSTYPE_IS_DECLARED 1
}


%token Entero           "Entero"
%token Real             "Real"
%token Cadena           "Cadena"
%token Booleano         "Booleano"
%token Caracter         "Caracter"
%token Arreglo          "Arreglo"
%token Var              "Var"

%token Funcion          "Funcion"
%token Procedimeinto    "Procedimeinto"
%token Repita           "Repita"
%token Escriba          "Escriba"
%token Llamar           "Llamar"
%token Lectura          "Lectura"
%token Escritura        "Escritura"
%token Leer             "Leer"
%token Escribir         "Escribir"
%token Tipo             "Tipo"
%token Registro         "Registro"
%token Cerrar           "Cerrar"
%token Archivo          "Archivo"
%token Abrir            "Abrir"
%token Como             "Como"
%token Lea              "Lea"

%token Para             "Para"
%token Mientras         "Mientras"
%token Haga             "Haga"
%token Hasta            "Hasta"
%token Secuencial       "Secuencial"

%token Si               "Si"
%token SiNoSi           "Sino Si"
%token Entonces         "Entonces"
%token Sino             "Sino"
%token Retorne          "Retorne"
%token Caso             "Caso"
%token C_O              "o"
%token C_Y              "y"
%token C_No             "no"
%token Div              "div"
%token Mod              "mod"
%token Verdadero        "Verdadero"
%token Falso            "Falso"

%token Inicio           "Inicio"
%token Final            "Final"
%token Fin              "Fin"

%token Es               "Es"
%token De               "De"

%token OpenCorch        "["
%token CloseCorch       "]"
%token Coma             ","
%token Colon            ":"
%token OpenPar          "("
%token ClosePar         ")"
%token OpPuntero        "<-"
%token OpAdd            "+"
%token OpSub            "-"
%token OpMult           "*"
%token OpSombrero       "^"
%token OpMenor          "<"
%token OpMayor          ">"
%token OpIgual          "=="
%token OpDiple          "<>"
%token OpMenorI         "<="
%token OpMayorI         ">="
%token SemiColon        ";"
%token Asignar          "="

%token Number           "Number"
%token Ident            "Ident"
%token Character        "Character"
%token String           "String"
%%

input: program { parse.setRoot(new Program(new BlockStmts(new Declaracionvariable(new DeclaracionStmt(new IdentExpr("a"), new IdentExpr("y")), new IdentExpr("x")) , new BlockStmts(new AddExpr(new IdentExpr("x"), new IdentExpr("y")), new EscribaStmt(new NumExpr(5)))))); }
;

program: subtypes-section decl_Var block_decl main {  }
;

//no generara ningun nodo
subtypes-section: subtypes-section Tipo Ident Es type-subtypes
                  | Tipo Ident Es type-subtypes {}
                  | 
;

//estructura con recursion de declaracion de variables
decl_Var: decl_Var tipos_variables { }
      | tipos_variables { }
      | 
;   

type-subtypes: tipo
            | Arreglo OpenCorch Number CloseCorch De tipo 
;

tipos_variables: Arreglo OpenCorch Number CloseCorch De tipo Ident
            | tipo Ident more_iden {  }
            | Ident Ident {}
;

//estrucutra para crear mas varibels del mismo tipo
more_iden: more_iden Coma Ident { }
      | Coma Ident { $$ = $2; }
      |            { }
;

//block de declaracion de variables
block_decl: block_decl declaraciones 
          | declaraciones
          | %empty
;

//declaraciones hantes de inicio
declaraciones: decl_funcion
            |  decl_procedieminto
;

//estructura del procediemiento
decl_procedieminto: Procedimeinto Ident decl_parametros_funcion decl_Var Inicio block_actions Fin
;


//estructura de la funcion
decl_funcion: Funcion Ident decl_parametros_funcion Colon tipo decl_Var Inicio block_actions Fin
;

//estructura de parametros de funciones y procedimientos
decl_parametros_funcion: OpenPar decl_var_funcion ClosePar
                  | %empty 
;

//multiples parametros para funciones y procedimeintos
decl_var_funcion: decl_var_funcion Coma tipos_paramettros
            | tipos_paramettros 
            
;

//tipos dde parametros
tipos_paramettros: Var Arreglo OpenCorch Number CloseCorch De tipo Ident
            | Var tipo Ident
            | Var Ident Ident
            | Ident Ident
            | tipo Ident 
            | Arreglo OpenCorch Number CloseCorch De tipo Ident        
;

//***************************************************************************************************************
//estructura del main
main: Inicio block_actions Fin
;

//block de acciones del main
block_actions: block_actions actions
            | actions   
;

//acciones del main
actions: asign_Var //ya
      | f_escriba //ya
      | cliclo_for 
      | retorne //retornara por el ecx
      | estructura_llamar // 
      | cliclo_While //
      | cliclo_Repeat // 
      | struct_lea //
      | si_statement //
      | %empty
;




//estructura Lea - sirve para leer un dato del usuario
struct_lea: Lea asignar
;

//llamado de arreglo
llamar_arreglo: Ident OpenCorch expr CloseCorch { }
;

//estructura de funcion llamar
estructura_llamar: Llamar funcion_llamado
;

//asignacion de variables
asign_Var: asign_Var asignar OpPuntero valores { }
        |  asignar OpPuntero valores
;

asignar: Ident
      | llamar_arreglo
;

//Funcion- Escriba
f_escriba: Escriba escriba_list
;

//estructura de un For/Para
cliclo_for: Para asignar OpPuntero valores_ciclos Hasta expr Haga block_actions Fin Para
;

cliclo_While: Mientras condi Haga block_actions Fin Mientras
;

cliclo_Repeat: Repita block_actions Hasta condi
;

si_statement: Si expr Entonces block_actions SiNoSi si2_statement 
            | Si expr Entonces block_actions Sino block_actions Fin Si  
            | Si expr Entonces block_actions Fin Si  
;
si2_statement: expr Entonces block_actions SiNoSi si2_statement   
            | expr Entonces block_actions Sino block_actions Fin Si  
            | expr Entonces block_actions Fin Si  
;

//estructura de retorn
retorne: Retorne valores
;

//estructura de llamado de funcion
funcion_llamado: Ident parametros
;

parametros: OpenPar parametros_mult ClosePar
      | OpenPar ClosePar
      | %empty
;

parametros_mult: valores
            | parametros_mult Coma valores
;



//valores para asignar

escriba_list: escriba_list Coma valores
            | valores
;

valores: expr 
      |   Verdadero
      |   Falso
      |   Character
      |   String  
;

//tipos de datos 
tipo: Entero
      | Real
      | Cadena
      | Booleano
      | Caracter
;

//tipo de valores para ciclos 
valores_ciclos: enteros
            | expr
            
;

expr:   expr OpAdd term 
    |   expr OpSub term 
    |   term      
;

term:   term OpMult condi 
    |   term Div condi
    |   term Mod condi
    |   condi
;

condi: condi OpMayor factor
      | condi OpMenor factor
      | condi OpMayorI factor
      | condi OpMenorI factor
      | condi OpDiple factor
      | condi OpSombrero factor
      | condi C_O factor
      | condi C_Y factor
      | condi OpIgual factor
      | factor
;

factor: OpenPar expr ClosePar
    |   enteros  {  }
    |   Ident  { }
    |   C_No Ident     
    |   Verdadero {  }
    |   Falso     { }
    |   llamar_arreglo
    |   funcion_llamado 
;

enteros: Number {  }
      | OpSub Number {  }
;
