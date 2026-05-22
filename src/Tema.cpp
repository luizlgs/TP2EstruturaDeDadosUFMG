#include "../include/Tema.hpp"

Tema::Tema(std::string nome, std::string tipo) : _nome(nome), _tipo(tipo) {
    _contador++;
    _id = _contador;
}

Tema::~Tema() {

}