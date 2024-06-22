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
    void genArchivo(std::string nombre, std::string code)
    {
       // tipos_var.push_back({"int", "a"});
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

        std::string nombre2 = "main.asm";
        std::ofstream archivo;
        archivo.open(nombre, std::ios::out );
        if (!archivo.is_open()) {
            std::cerr << "Error al abrir el archivo " << nombre << std::endl;
        
        }
        archivo << ast->Gencode(tipos_var);
        archivo.close();


        
    };
    
    void addTipo(std::string tipos, std::string variable)
    {
        bool encontrado = false;
        for (const auto& var : tipos_var) {
            if (var.variable == variable) {
                encontrado = true;
                    
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