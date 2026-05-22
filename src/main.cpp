#include "../include/Dicionario.hpp"
#include "../include/Grafo.hpp"
#include "../include/Tema.hpp"
#include "../include/Usuario.hpp"
#include <iostream>
#include <sstream>

#define CAPACIDADE_MAXIMA_INICIAL 30

int main(){
    Usuario *usuarios[CAPACIDADE_MAXIMA_INICIAL];
    Tema *temas[CAPACIDADE_MAXIMA_INICIAL];
    Grafo grafo_social(CAPACIDADE_MAXIMA_INICIAL);
    Grafo grafo_temas(CAPACIDADE_MAXIMA_INICIAL);

    std::string line;
    char comando;

    while(std::getline(std::cin, line)){
        if (line.empty())
            continue;

        std::stringstream ss(line);
        ss >> comando;

        switch (comando) {
        case 'A':
        char tipo;
        ss >> tipo;
            if(tipo == 'L'){
                grafo_social.trocaTipo(0, 'L', usuarios);

            }
            else if(tipo == 'M'){
                grafo_social.trocaTipo(0, 'M', usuarios);
            }
            break;
        
        default:
            break;
        }
        
    }


    

    
}
