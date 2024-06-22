#ifndef __COMPILEXER_HPP__
#define __COMPILEXER_HPP__

#include <iosfwd>
#include <string>
#include <unordered_map>
#include <vector>
#include <variant>
#include "CompiAst.hpp"


enum class Token: int {
    Eof = 0,
    Error = 256,
    Undef = 257,

    //tipos de datos
    Entero = 258,
    Real = 259,
    Cadena = 260,
    Booleano = 261,
    Caracter = 262,
    Arreglo = 263,
    Var = 264,

    //funciones
    Funcion = 265,
    Procedimiento = 266,
    Repita = 267,
    Escriba = 268,
    Llamar = 269,
    Tipo = 270,
    Lea = 271,
    
    //Ciclos
    Para = 272,
    Mientras = 273,
    Haga = 274,
    Hasta = 275,
  

    //Condicionales
    Si = 276,
    SiNoSi = 277,
    Entonces = 278,
    Sino = 279,
    Retorne = 280,
    
    C_O = 281,
    C_Y = 282,
    C_No = 283,
    Div = 284,
    Mod = 285,
    Verdadero = 286,
    Falso = 287,
    
    //Inicio
    Inicio = 288,
    Final = 289,
    Fin = 290,

    //extra
    Es = 291,
    De = 292,

    //Operadores y tokens de puntuacion
    OpenCorch = 293,
    CloseCorch = 294,
    Coma = 295,
    Colon = 296,
    OpenPar = 297,
    ClosePar = 298,
    OpPuntero = 299,
    OpAdd = 300,
    OpSub = 301,
    OpMult = 302,
    OpSombrero = 303,
    OpMenor = 304,
    OpMayor = 305,
    OpIgual = 306,
    OpDiple = 307,
    OpMenorI = 308,
    OpMayorI = 309,

    //Datos
    Number = 310,
    Ident = 311,
    Character = 312,
    String = 313,
    

};


class CompiLexer
{
public:
    using yyscan_t = void*;
    using ParserValueType = AstNode *;
    
public:
    CompiLexer(std::istream& _in);
    ~CompiLexer();

    Token nextToken(ParserValueType *lval)
    { return nextTokenHelper(yyscanner, lval); }

    std::string text() const;

    const int line() const;
   
private:
    Token nextTokenHelper(yyscan_t yyscanner, ParserValueType *lval);

private:
    std::istream& in;
   
    yyscan_t yyscanner;
};

#endif