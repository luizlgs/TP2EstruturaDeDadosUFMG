#include <string>

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
    unsigned int getId() const;
    unsigned int getNumSeguidores() const;
    unsigned int getNumTemas() const; 
};

