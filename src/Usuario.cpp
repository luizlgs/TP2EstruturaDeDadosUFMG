#include "../include/Usuario.hpp"

Usuario::Usuario(std::string nome, unsigned int idade) : _nome(nome), _idade(idade) {
    _contador++;
    _id = _contador;
}

Usuario::~Usuario() {
}

int Usuario::getId() const{
    return _id;
}

int Usuario::getSeguidores() const{
    return _num_seguidores;
}