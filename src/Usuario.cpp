#include "../include/Usuario.hpp"

Usuario::Usuario(std::string nome, unsigned int idade) : _nome(nome), _idade(idade) {
    _contador++;
    _id = _contador;
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