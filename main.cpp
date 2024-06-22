#include <iostream>
#include <fstream>
#include "CompiLexer.hpp"
#include "CompiParser.hpp"
#include <unordered_map>

int main(int argc, char *argv[]) 
{
    //std::cout<< argc;
    if (argc != 3) {
        std::cerr << "Not enough CLI arguments\n";
        return 1;
    }
    
    std::string lpp_f = argv[1];
    std::string asm_f = argv[2];


    
    std::ifstream in(lpp_f, std::ios::in);
    if (!in.is_open()) {
        std::cerr << "Cannot open input file\n";
        return 1;
    }

    CompiLexer lexer(in);
    CompiParser parser(lexer);
   
   try
   {
        parser.parse();

        std::cout << parser.genArchivo(asm_f);
   }
   catch(const std::exception& e)
   {
        std::cerr << e.what() << '\n';
   }
   
}