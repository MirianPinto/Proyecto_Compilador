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
    Lectura = 270,
    Escritura = 271,
    Leer = 272,
    Escribir = 273,
    Tipo = 274,
    Registro = 275,
    Cerrar = 276,
    Archivo = 277,
    Abrir = 278,
    Como = 279,
    Lea = 280,
    
    //Ciclos
    Para = 281,
    Mientras = 282,
    Haga = 283,
    Hasta = 284,
    Secuencial = 285,

    //Condicionales
    Si = 286,
    SiNoSi = 287,
    Entonces = 288,
    Sino = 289,
    Retorne = 290,
    Caso = 291,
    C_O = 292,
    C_Y = 293,
    C_No = 294,
    Div = 295,
    Mod = 296,
    Verdadero = 297,
    Falso = 298,
    
    //Inicio
    Inicio = 299,
    Final = 300,
    Fin = 301,

    //extra
    Es = 302,
    De = 303,

    //Operadores y tokens de puntuacion
    OpenCorch = 304,
    CloseCorch = 305,
    Coma = 306,
    Colon = 307,
    OpenPar = 308,
    ClosePar = 309,
    OpPuntero = 310,
    OpAdd = 311,
    OpSub = 312,
    OpMult = 313,
    OpSombrero = 314,
    OpMenor = 315,
    OpMayor = 316,
    OpIgual = 317,
    OpDiple = 318,
    OpMenorI = 319,
    OpMayorI = 320,
    SemiColon = 321,
    Asignar = 322,

    //Datos
    Number = 323,
    Ident = 324,
    Character = 325,
    String = 326,
    

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