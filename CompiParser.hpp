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
   std::string EAsm_Path = "../EasyASM-x86";
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
        
    }

    AstNode* getRoot() const
    {
        return ast;
    }

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

    void genArchivo(std::string nombre)
    {
       
       std::vector<int> posiciones;
       std::string tipoAn ;
        for (int i = 0; i < tipos_var.size(); i++) {
            //std::cout << "indice = "<< i<<" " <<tipos_var[i].Tipo << " " << tipos_var[i].variable << std::endl;
            if(tipos_var[i].Tipo == "siguiente")
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
           // std::cout << "indice = "<< i<<" " <<tipos_var[i].Tipo << " " << tipos_var[i].variable << std::endl;
        }

        for (int i = 0; i < tipos_var.size(); i++) {
            std::cout << "indice = "<< i<<" " <<tipos_var[i].Tipo << " " << tipos_var[i].variable << std::endl;
        }

        
        std::ofstream archivo;
        archivo.open(nombre, std::ios::out | std::ios::trunc);
        if (!archivo.is_open()) {
           throw std::runtime_error("Failed to open asm file for writing!");
        }
        archivo << ast->Gencode(tipos_var);
        archivo.close();

        std::string cmd = EAsm_Path + " --run " + nombre + " 2>&1";

        runCmd(cmd);
        
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

        if(tipos == "anterior")
        {
            if (!encontrado) {
                

                tipos_var.push_back({"siguiente", variable});
                
            }

        }else {
            if (!encontrado) {
                
                tipos_var.push_back({tipos, variable});
                
            }
        }
            
    };

   

    

};

#endif