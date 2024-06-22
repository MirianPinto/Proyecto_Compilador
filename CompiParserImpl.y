
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
%token Tipo             "Tipo"
%token Lea              "Lea"

%token Para             "Para"
%token Mientras         "Mientras"
%token Haga             "Haga"
%token Hasta            "Hasta"


%token Si               "Si"
%token SiNoSi           "Sino Si"
%token Entonces         "Entonces"
%token Sino             "Sino"
%token Retorne          "Retorne"

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
%token OpIgual          "="
%token OpDiple          "<>"
%token OpMenorI         "<="
%token OpMayorI         ">="

%token Number           "Number"
%token Ident            "Ident"
%token Character        "Character"
%token String           "String"
%%

input: program { parse.setLpp($1); }
;

program: subtypes-section decl_Var block_decl main { $$ = new Program($2,$3,$4);}
;

//no generara ningun nodo
subtypes-section: subtypes-section Tipo Ident Es type-subtypes
                  | Tipo Ident Es type-subtypes {}
                  | 
;

//estructura con recursion de declaracion de variables
decl_Var: decl_Var tipos_variables { $$ = new Declaracionvariable($1,$2); }
      | tipos_variables { $$ = $1;}
      | {$$ = new Vacio();}
;   

type-subtypes: tipo
            | Arreglo OpenCorch Number CloseCorch De tipo 
;

tipos_variables: Arreglo OpenCorch Number CloseCorch De tipo Ident
            | tipo Ident more_iden { $$ = new DeclaracionStmt($2,$3); parse.addTipo(((IdentExpr*)($1))->text, ((IdentExpr*)($2))->text); }
            | Ident Ident {}
;

//estrucutra para crear mas varibels del mismo tipo
more_iden: more_iden Coma Ident { $$ = new DeclaracionStmt($1,$3); parse.addTipo("lista", ((IdentExpr*)($3))->text);}
      | Coma Ident { $$ = $2; parse.addTipo("lista", ((IdentExpr*)($2))->text);}
      |            { $$ = new Vacio();}
;

//block de declaracion de variables
block_decl: block_decl declaraciones 
          | declaraciones
          | %empty {$$ = new Vacio();}
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
main: Inicio block_actions Fin { $$ = $2; }
;

//block de acciones del main
block_actions: block_actions actions {$$ = new BlockStmts($1,$2);}
            | actions   {$$ = $1; }
;

//acciones del main
actions: asign_Var { $$ = $1;} //si
      | f_escriba { $$ = $1;} //si
      | cliclo_for { $$ = $1;} //si
      | retorne { $$ = $1;} //si
      | estructura_llamar { $$ = $1;} 
      | cliclo_While { $$ = $1;} //si
      | cliclo_Repeat { $$ = $1;} //si
      | struct_lea { $$ = $1;} //si
      | si_statement { $$ = $1;} //si
      | %empty { $$ = new Vacio();}
;




struct_lea: Lea asignar { $$ = new LeaStmt($2); }
;


llamar_arreglo: Ident OpenCorch expr CloseCorch { }
;


estructura_llamar: Llamar funcion_llamado
;


asign_Var: asignar OpPuntero valores {$$ = new AsignarStmt((IdentExpr*)$1,$3); }
;

asignar: Ident { $$ = $1; }
      | llamar_arreglo
;

f_escriba: Escriba escriba_list {$$ = new EscribaStmt($2); }
;

cliclo_for: Para asignar OpPuntero valores_ciclos Hasta expr Haga block_actions Fin Para { $$ = new ForStmt(new AsignarStmt((IdentExpr*)$2,$3),(Expr*)$6,$8 ); }
;

cliclo_While: Mientras condi Haga block_actions Fin Mientras { $$ = new WhileStmt($2,$4); }
;

cliclo_Repeat: Repita block_actions Hasta condi { $$ = new RepitaStmt($2,(Expr*)$4); }
;

si_statement: Si expr Entonces block_actions SiNoSi si2_statement { $$ = new IfStmt($2,$4,$6); }
            | Si expr Entonces block_actions Sino block_actions Fin Si  { $$ = new IfStmt($2,$4,$6); }
            | Si expr Entonces block_actions Fin Si  { $$ = new IfStmt($2,$4,new Vacio()); }
;
si2_statement: expr Entonces block_actions SiNoSi si2_statement   { $$ = new IfStmt($1,$3,$5); } 
            | expr Entonces block_actions Sino block_actions Fin Si  { $$ = new IfStmt($1,$3,$5); }
            | expr Entonces block_actions Fin Si   { $$ = new IfStmt($1,$3,new Vacio()); }
;

retorne: Retorne valores
;

funcion_llamado: Ident parametros
;

parametros: OpenPar parametros_mult ClosePar
      | OpenPar ClosePar
      | %empty
;

parametros_mult: valores
            | parametros_mult Coma valores
;




escriba_list: escriba_list Coma valores
            | valores {$$ = $1;}
;

valores: expr {$$ = $1;}
      |   Verdadero {$$ = new BoolExpr(1);}
      |   Falso   {$$ = new BoolExpr(0);}
      |   Character {$$ = $1;}
      |   String  {$$ = $1;}
;

tipo: Entero { $$ = new IdentExpr("Entero"); }
      | Real  { $$ = new IdentExpr("Real"); }
      | Cadena
      | Booleano { $$ = new IdentExpr("Booleano"); }
      | Caracter { $$ = new IdentExpr("Caracter"); }
;


valores_ciclos: enteros { $$ = $1; }
            | expr { $$ = $1; }
            
;

expr:   expr OpAdd term { $$ = new AddExpr((Expr*)$1,(Expr*)$3);}
    |   expr OpSub term { $$ = new SubExpr((Expr*)$1,(Expr*)$3);}
    |   term { $$ = $1; }
;

term:   term OpMult condi { $$ = new MulExpr((Expr*)$1,(Expr*)$3);}
    |   term Div condi { $$ = new DivExpr((Expr*)$1,(Expr*)$3);}
    |   term Mod condi { $$ = new ModExpr((Expr*)$1,(Expr*)$3);}
    |   condi { $$ = $1;}
;

condi: condi OpMayor factor {$$ = new MayorExpr((Expr*)$1,(Expr*)$3); }
      | condi OpMenor factor {$$ = new MenorExpr((Expr*)$1,(Expr*)$3); }
      | condi OpMayorI factor {$$ = new MayorIExpr((Expr*)$1,(Expr*)$3); }
      | condi OpMenorI factor {$$ = new MenorIExpr((Expr*)$1,(Expr*)$3); }
      | condi OpDiple factor {$$ = new DesigualExpr((Expr*)$1,(Expr*)$3); }
      | condi OpSombrero factor 
      | condi C_O factor {$$ = new OrExpr((Expr*)$1,(Expr*)$3);}
      | condi C_Y factor {$$ = new AndExpr((Expr*)$1,(Expr*)$3);}
      | condi OpIgual factor {$$ = new IgualExpr((Expr*)$1,(Expr*)$3); }
      | factor {$$ = $1; }
;

factor: OpenPar expr ClosePar {$$ = $2;}
    |   enteros  { $$ = $1; }
    |   Ident  { $$ = $1; }
    |   C_No Ident  { }   
    |   Verdadero {$$ = new BoolExpr(1);}
    |   Falso     {$$ = new BoolExpr(0);}
    |   llamar_arreglo
    |   funcion_llamado 
;

enteros: Number { $$ = $1; }
      | OpSub Number { $$ = $1; }
;
