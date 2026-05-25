#include <string>
#pragma once
class Usuario {
private:
    static int _contador;
    unsigned int _id;
    std::string _nome;
    unsigned int _idade;
    unsigned int _num_seguidores, _num_seguindo, _num_temas;

public:
    Usuario(){_id=-1;};
    Usuario(std::string nome, unsigned int idade);
    ~Usuario();

    //getters
    unsigned int getId() const;
    unsigned int getNumSeguidores() const;
    unsigned int getNumTemas() const;
    std::string getNome() const;

    //setters
    void setNumSeguidores(unsigned int novo_num_seguidores);
    void setNumTemas(unsigned int novo_num_temas);
};

