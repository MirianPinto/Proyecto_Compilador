#include <iostream>
#include <fstream>
#include "CompiLexer.hpp"
#include "CompiParser.hpp"
#include <unordered_map>

std::string EAsm_Path = "../EasyASM-x86";

// Función para ejecutar un comando y capturar su salida
std::string runCmd(const std::string& cmd)
{
    FILE *stream = popen(cmd.c_str(), "r");
    if (stream == nullptr) {
        throw std::runtime_error("popen() failed!");
    }

    std::ostringstream ssdata;
    char buffer[256] = {0};

    while (fgets(buffer, sizeof(buffer) - 1, stream))
        ssdata << buffer;

    pclose(stream);
    return ssdata.str();
}




int main(int argc, char *argv[]) 
{
    std::cout<< argc;
    if (argc != 3) {
        std::cerr << "Not enough CLI arguments\n";
        return 1;
    }
    
    std::string inputFile = argv[1];
    std::string outputFile = argv[2];


    
    std::ifstream in(inputFile, std::ios::in);
    if (!in.is_open()) {
        std::cerr << "Cannot open input file\n";
        return 1;
    }

    CompiLexer lexer(in);
    CompiParser parser(lexer);
   
   try
   {
        parser.parse();

        parser.genArchivo(outputFile);
   }
   catch(const std::exception& e)
   {
        std::cerr << e.what() << '\n';
   }
   
}