#include <string>
#pragma once

class Tema {
private:
    static int _contador;
    unsigned int _id;
    std::string _nome;
    std::string _tipo;
public:
    Tema(){_id=-1;};
    Tema(std::string nome, std::string tipo);
    ~Tema();

    //getters
    unsigned int getId() const;
    std::string getNome() const;
};
