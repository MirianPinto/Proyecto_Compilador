#include <iostream>
#include <fstream>
#include "CompiLexer.hpp"
#include "CompiParser.hpp"
#include <unordered_map>

int main(int argc, char *argv[]) 
{
    std::unordered_map<std::string, int, int> vr_map;
    if (argc != 2) {
        std::cerr << "Not enough CLI arguments\n";
        return 1;
    }
    std::ifstream in(argv[1], std::ios::in);
    
    if (!in.is_open()) {
        std::cerr << "Cannot open file\n";
        return 1;
    }

    
    CompiLexer lexer(in);
    CompiParser parser(lexer);
   
   try
   {
        parser.parse();
        
   }
   catch(const std::exception& e)
   {
        std::cerr << e.what() << '\n';
   }
   
}