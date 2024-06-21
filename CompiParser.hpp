#ifndef __COMPI_PARSE_HPP__
#define __COMPI_PARSE_HPP__


#include "CompiLexer.hpp"
#include "CompiParserImpl.hpp"
#include "CompiAst.hpp"


class CompiParser
{
private:
   CompiLexer& lexer;
   AstNode* ast;
   
public:
    CompiParser(CompiLexer& lexer): lexer(lexer){};

    int parse();


    CompiLexer& getLexer() const
    {
        return lexer;
    }

    void setRoot(AstNode* root)
    {
        ast = root;
        std::cout<<root->Gencode();
    }

    AstNode* getRoot() const
    {
        return ast;
    }


};

#endif