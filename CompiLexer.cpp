#include <fstream>
#include "CompiLexer.hpp"
#include "CompiLexerImpl.hpp"
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

