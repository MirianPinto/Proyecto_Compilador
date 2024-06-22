#ifndef __COMPI_PARSE_HPP__
#define __COMPI_PARSE_HPP__


#include "CompiLexer.hpp"
#include "CompiParserImpl.hpp"
#include "CompiAst.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <string>

class CompiParser
{
private:
   CompiLexer& lexer;
   AstNode* ast;
   Tipos tipos_var;
   std::string EAsm_Path = "../ejecutable/EasyASM-x86";
public:
    CompiParser(CompiLexer& lexer): lexer(lexer){};

    int parse();

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
    // Función para escribir el código ensamblador en un archivo y ejecutarlo

    int genArchivo(std::string nombre)
    {
       
       std::vector<int> posiciones;
       std::string tipoAn ;
        for (int i = 0; i < tipos_var.size(); i++) {
            if(tipos_var[i].Tipo == "lista")
            {
                posiciones.push_back(i);
            }else
            {
                tipoAn = tipos_var[i].Tipo;
                for(int j = 0; j < posiciones.size(); j++)
                {
                    tipos_var[posiciones[j]].Tipo = tipoAn;
                }
                posiciones.clear();
                tipoAn = "";
            }
           
        }

        
        std::ofstream archivo;
        archivo.open(nombre, std::ios::out | std::ios::trunc);
        if (!archivo.is_open()) {
           throw std::runtime_error("Failed to open asm file for writing!");
        }

        try {
           archivo << ast->Gencode(tipos_var);
        } catch (const std::runtime_error& e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }
        

    
        archivo.close();

        std::string cmd = EAsm_Path + " --run "+ nombre + " 2>&1";

        std::string final = "\n" + runCmd(cmd);

        std::cout<< final;


        return 0;
        
    };
    
    void addTipo(std::string tipos, std::string variable)
    {
        bool encontrado = false;
        for (const auto& var : tipos_var) {
            if (var.variable == variable) {
                encontrado = true;
                std::string msgcompleto = "Error:variable declarada dos veces " + variable;
                throw std::runtime_error(msgcompleto.c_str());\
                break;
            }
        }
        int posicion = 0;

        
        if (!encontrado) {
                
            tipos_var.push_back({tipos, variable});
                
        }
        
            
    };

    
   CompiLexer& getLexer() const
    {
        return lexer;
    }

    void setLpp(AstNode* root)
    {
        ast = root;
        
    }
   

    

};

#endif