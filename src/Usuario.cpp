#include "../include/Usuario.hpp"

int Usuario::_contador = 0;

Usuario::Usuario(std::string nome, unsigned int idade) : _nome(nome), _idade(idade) {
    _id = _contador;
    _contador++;
}

Usuario::~Usuario() {
}

unsigned int Usuario::getId() const{
    return _id;
}

unsigned int Usuario::getNumSeguidores() const{
    return _num_seguidores;
}

unsigned int Usuario::getNumTemas() const{
    return _num_temas;
}

void Usuario::setNumSeguidores(unsigned int novo_num_seguidores) {
    _num_seguidores = novo_num_seguidores;
}

void Usuario::setNumTemas(unsigned int novo_num_temas) {
    _num_temas = novo_num_temas;
}

std::string Usuario::getNome() const{
    return _nome;
}
