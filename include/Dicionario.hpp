#include "Usuario.hpp"
#include "Tema.hpp"
#include "Grafo.hpp"

#define CAPACIDADE_MAXIMA_INICIAL 30

class Dicionario {
private:
    int _num_usuarios, _num_temas;
    int _max_usuarios, _max_temas;
    Usuario **_usuarios;
    Tema **_temas;
    Grafo *_grafo_social;
    Grafo *_grafo_temas;
public:
    Dicionario(char tipoML);
    ~Dicionario();

    //getters
    Usuario **getUsuarios();
    Tema **getTemas();
    Grafo *getGrafoSocial() const;
    Grafo *getGrafoTemas() const;

    int getNumUsuarios() const;
    int getNumTemas() const;

    //setters
    void setNumUsuarios(int novo_num_usuarios);
    void setNumTemas(int novo_num_temas);

    //outras funcoes
    void adicionarUsuario(Usuario *usuario);
    void adicionarTema(Tema *tema);


};
