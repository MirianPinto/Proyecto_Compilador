#include <fstream>
#include "CompiLexer.hpp"
#include "CompiLexerImpl.h"
#include <iostream>
#include <string>
#include <algorithm> 

CompiLexer::CompiLexer(std::istream& _in)
  : in(_in)
{
    yylex_init_extra(&in, &yyscanner);
}

CompiLexer::~CompiLexer()
{
    yylex_destroy(yyscanner);
}

std::string CompiLexer::text() const
{
    return std::string(yyget_text(yyscanner));
}

const int CompiLexer::line() const
{
    return yyget_lineno(yyscanner);
}

const char *CompiLexer::tokenString(Token tk)
{
    switch (tk)
    {
        case Token::Eof: 
            return "TkEof";
        case Token::OpAdd: 
            return "TkOpAdd";
        case Token::OpMult: 
            return "TkOpMult";
        case Token::OpSub: 
            return "TkOpSub";
        case Token::OpenPar: 
            return "TkOpenPar";
        case Token::ClosePar: 
            return "TkClosePar";
        case Token::SemiColon: 
            return "TkSemiColon";
        case Token::Ident: 
            return "TkIndet";
        case Token::Number: 
            return "Number";
        default:
            return "Unknown";
    }
    return "Unknown";
}