#include "../include/Dicionario.hpp"
#include "../include/Grafo.hpp"
#include "../include/Tema.hpp"
#include "../include/Usuario.hpp"
#include <iostream>
#include <sstream>

#define CAPACIDADE_MAXIMA_INICIAL 30

int main(){
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);

    //cria um grafo no dicionario do tipo solicitado
    char c, tipoML;
    ss >> c >> tipoML;
    Dicionario Dicionario(tipoML);

    char comando;
    while(std::getline(std::cin, line)){
        if (line.empty())
            continue;

        std::stringstream ss(line);
        ss >> comando;

        switch (comando) {
        case 'A': {
            char tipo;
            ss >> tipo;
            if(tipo == 'M'){
                Dicionario.getGrafoSocial()->trocaTipo(0, 'M', Dicionario.getUsuarios(), Dicionario.getNumUsuarios(), Dicionario.getNumTemas());
                tipoML = 'M';

            }
            else if(tipo == 'L'){
                Dicionario.getGrafoSocial()->trocaTipo(0, 'L', Dicionario.getUsuarios(), Dicionario.getNumUsuarios(), Dicionario.getNumTemas());
                tipoML = 'L';
            }
            break;
        }

        case 'T': {
            std::string nome_tema, tipo_tema;
            ss >> nome_tema >> tipo_tema;
            Tema *novoTema = new Tema(nome_tema, tipo_tema);
            //adicionar o tema na lista de temas<<<<<<<
            Dicionario.setNumTemas(Dicionario.getNumTemas()+1);

            std::cout << "T "+Dicionario.getNumTemas();
            break;
        }

        case 'U': {
            std::string nome, idade;
            int idstemas;

            break;
        }
        
        default:
            break;
        }
        
    }
    
}
