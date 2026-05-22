#include <string>

class Usuario {
private:
    static int _contador;
    unsigned int _id;
    std::string _nome;
    unsigned int _idade;
    unsigned int _num_seguidores;

public:
    Usuario(std::string nome, unsigned int idade);
    ~Usuario();
    int getId() const;
    int getSeguidores() const;
};

