#include "CompiParser.hpp"


int CompiParser::parse()
{

    return yyparse(*this);
}
