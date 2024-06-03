#ifndef __COMPI_PARSE_HPP__
#define __COMPI_PARSE_HPP__


#include "CompiLexer.hpp"
#include "CompiParserImpl.h"

class CompiParser
{
private:
   CompiLexer& lexer;
   bool error;
   
public:
    CompiParser(CompiLexer& lexer): lexer(lexer){};

    int parse();

    CompiLexer& getLexer() const
    {
        return lexer;
    }

};

#endif