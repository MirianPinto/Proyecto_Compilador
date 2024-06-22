%option noyywrap
%option reentrant
%option yylineno
%option case-insensitive
%option extra-type = "std::istream *"
%{
    
    #include <iostream>
    #include <cstdlib>
    #include <algorithm>
    #include <string>
    #include "CompiLexer.hpp"
    #include "CompiAst.hpp"

    #define YY_DECL Token CompiLexer::nextTokenHelper(yyscan_t yyscanner, ParserValueType *lval)
    #define yyterminate() return Token::Eof

    #define YY_INPUT(buf, result, max_size) \
        { \
            auto *in = yyget_extra(yyscanner); \
            in->read(buf, max_size); \
            result = in->gcount(); \
        }

%}

%x comment

%%

[ \t\n]	            {  }
"//"[^\n]*\n        { }
"/*"                { BEGIN(comment); }
[\r\n]              {  }
"Entero"            { return Token::Entero; }
"Real"              { return Token::Real; }
"Cadena"            { return Token::Cadena; }
"Booleano"          { return Token::Booleano; }
"Caracter"          { return Token::Caracter; }
"Arreglo"           { return Token::Arreglo; }
"Var"               { return Token::Var; }

"Funcion"           { return Token::Funcion; }
"Procedimiento"     { return Token::Procedimiento; }
"Repita"            { return Token::Repita; }
"Escriba"           { return Token::Escriba; }
"Llamar"            { return Token::Llamar; }
"Tipo"              { return Token::Tipo; }
"Lea"               { return Token::Lea; }

"Para"              { return Token::Para; }
"Mientras"          { return Token::Mientras; }
"Haga"              { return Token::Haga; }
"Hasta"             { return Token::Hasta; }

"Si"                { return Token::Si; }
"Sino Si"           { return Token::SiNoSi; }
"Entonces"          { return Token::Entonces; }
"Sino"              { return Token::Sino; }
"Retorne"           { return Token::Retorne; }
"o"                 { return Token::C_O; }
"y"                 { return Token::C_Y; }
"no"                { return Token::C_No; }
"div"               { return Token::Div; }
"mod"               { return Token::Mod; }
"Verdadero"         { return Token::Verdadero; }
"Falso"             { return Token::Falso; }

"Inicio"            { return Token::Inicio; }
"Final"             { return Token::Final; }
"Fin"               { return Token::Fin; }

"Es"                { return Token::Es; }
"De"                { return Token::De; }

"["		            { return Token::OpenCorch; }
"]"		            { return Token::CloseCorch; }
","		            { return Token::Coma; }
":"		            { return Token::Colon; }
"("		            { return Token::OpenPar; }
")"		            { return Token::ClosePar; }
"<-"	            { return Token::OpPuntero; }
"+"		            { return Token::OpAdd; }
"-"                 { return Token::OpSub; }
"*"		            { return Token::OpMult; }
"^"		            { return Token::OpSombrero; }
"<"		            { return Token::OpMenor; }
">"		            { return Token::OpMayor; }
"="		            { return Token::OpIgual; }
"<>"		        { return Token::OpDiple; }
"<="		        { return Token::OpMenorI; }
">="		        { return Token::OpMayorI; }

\'[^\n]\' {   *lval = new CaracterExpr(yytext[1]); return Token::Character; }
\"[0-9a-zA-Z_ ]*[^\n]*\" { std::string cadena = std::string(yytext); cadena.erase(std::remove(cadena.begin(), cadena.end(), '\"'), cadena.end()); *lval = new CadenaExpr(cadena) ;return Token::String; }
[0-9]+	            {*lval = new NumExpr(std::atof(yytext)); return Token::Number; }
[a-zA-Z_][0-9a-zA-Z_]* { *lval = new IdentExpr(std::string(yytext));  return Token::Ident; }

.		{ std::cerr << "Invalid symbol\n"; std::cout<< yytext; return Token::Error; }

<comment>"*/" { BEGIN(INITIAL); }
<comment>.|\n { /* Nothing */ }
<comment><<EOF>> { std::cerr << "Warning: Block comment without close\n";  }
%%