#include "../include/Dicionario.hpp"
#include "../include/Grafo.hpp"
#include "../include/Tema.hpp"
#include "../include/Usuario.hpp"
#include <iostream>
#include <sstream>


int main(){
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);

    //cria um grafo no dicionario do tipo solicitado
    char c, tipoML;
    ss >> c >> tipoML;
    Dicionario Dicionario(tipoML);
    std::cout << "A " << tipoML << std::endl;

    std::string comando;
    while(std::getline(std::cin, line)){
        if (line.empty())
            continue;

        std::stringstream ss(line);
        ss >> comando;

        switch (comando[0]) {
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
            std::cout << "A " << tipo << std::endl;
            break;
        }

        case 'T': {
            std::string nome_tema, tipo_tema;
            ss >> nome_tema >> tipo_tema;
            Tema *novoTema = new Tema(nome_tema, tipo_tema);
            Dicionario.adicionarTema(novoTema);
            std::cout << "T " << novoTema->getId() << std::endl;
            break;
        }

        case 'U': {
            std::string nome;
            int num_temas, id, idstemas[Dicionario.getNumTemas()];
            unsigned int idade;
            ss >> nome >> idade;

            Usuario *novo_usuario = new Usuario(nome, idade);

            int i=0;
            while(ss >> id){
                idstemas[i] = id;
                i++;
            }
            novo_usuario->setNumTemas(i);
            Dicionario.adicionarUsuario(novo_usuario, idstemas, i);
            std::cout << "U " << novo_usuario->getId() << std::endl;
            break;
        }

        case 'S': {
            unsigned int id1, id2;
            ss >> id1 >> id2;
            Dicionario.seguir(id1, id2);
            std::cout << "S " << Dicionario.getUsuarios()[id1]->getNome() << " " << Dicionario.getUsuarios()[id2]->getNome() << std::endl;
            break;
        }

        case 'R': {
            unsigned int id1, id2;
            ss >> id1 >> id2;
            Dicionario.remocaoSeguidor(id1, id2);
            std::cout << "R " << Dicionario.getUsuarios()[id1]->getNome() << " " << Dicionario.getUsuarios()[id2]->getNome() << std::endl;
            break;
        }


        case 'Q': {
            unsigned int id1, id2;
            ss >> id1 >> id2;
            std::cout << "Q " << Dicionario.getUsuarios()[id1]->getNome() << " " << Dicionario.getUsuarios()[id2]->getNome() << " " <<
            Dicionario.consultaRelacao(id1, id2) << std::endl;
            break;
        }

        case 'G': {
            unsigned int id_usuario, id_tema;
            ss >> id_usuario >> id_tema;
            std::cout << "G " << Dicionario.getUsuarios()[id_usuario]->getNome() << " " << Dicionario.getTemas()[id_tema]->getNome() << " " <<
            Dicionario.consultaDeInteresse(id_usuario, id_tema) << std::endl;
            break;
        }

        case 'F':{
            unsigned int id_tema;
            ss >> id_tema;
            std::cout << "F " << Dicionario.getTemas()[id_tema]->getNome() << " " << Dicionario.consultaDePopularidade(id_tema) << std::endl;
            break;
        }
        
        default:
            break;
        }

        //casos com dois caracteres
        if(comando == "LT") {
            unsigned int id;
            ss >> id;
            std::cout << "LT " << Dicionario.getUsuarios()[id]->getNome() << " ";
            Dicionario.listaTemas(id);
        }

        if(comando == "LC") {
            unsigned int id;
            ss >> id;
            std::cout << "LC " <<  Dicionario.getUsuarios()[id]->getNome() << " ";
            Dicionario.consultaSeguidores(id);
        }

        if(comando == "LS") {
            unsigned int id;
            ss >> id;
            std::cout << "LS " <<  Dicionario.getUsuarios()[id]->getNome() << " ";
            Dicionario.consultaSeguidos(id);
        }

        if(comando == "LA") {
            unsigned int id;
            ss >> id;
            std::cout << "LA " << Dicionario.getUsuarios()[id]->getNome() << " ";
            Dicionario.consultaAmigos(id);
        }
        
    }
    
}
