#include "Usuario.hpp"
#include "Tema.hpp"
#include "Grafo.hpp"

#define CAPACIDADE_MAXIMA_INICIAL 30
#define ORDEM_DE_CRESCIMENTO_DE_USUARIOSeTEMAS 10

#pragma once
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
    void adicionarUsuario(Usuario *usuario, int indices_temas[], int num_temas_usuario);
    void adicionarTema(Tema *tema);
    void seguir(unsigned int id1, unsigned int id2);
    void remocaoSeguidor(unsigned int id1, unsigned int id2);
    void listaTemas(unsigned int id);
    void consultaSeguidores(unsigned int id);
    void consultaSeguidos(unsigned int id);
    void consultaAmigos(unsigned int id);
    int consultaRelacao(unsigned int id1, unsigned int id2);
    int consultaDeInteresse(unsigned int id_usuario, unsigned int id_tema);
    int consultaDePopularidade(unsigned int id_tema);


};
