#include "../include/Tema.hpp"

int Tema::_contador = 0;

Tema::Tema(std::string nome, std::string tipo) : _nome(nome), _tipo(tipo) {
    _id = _contador;
    _contador++;
}

Tema::~Tema() {}

unsigned int Tema::getId() const{
    return _id;
}

std::string Tema::getNome() const {
    return _nome;
}