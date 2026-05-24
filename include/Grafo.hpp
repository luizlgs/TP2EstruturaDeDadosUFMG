#include <cstdlib>
#include <iostream>
#include <math.h>
#include "../include/Usuario.hpp"
#include "../include/Tema.hpp"

class Grafo {
private:
    char _tipoML; // B para nenhum dos dois (valor inicial), L para lista de adjacência, M para matriz de adjacência
    int **_matriz; //[usuario do no][usuario com quem ele se relaciona]
    int **_lista;
public:
    Grafo(Usuario **usuarios, int num_usuarios, int num_temas, char tipoML, bool tipo_grafoST);
    ~Grafo();

    void trocaTipo(bool tipo_grafoST, char tipo, Usuario *usuarios[], int num_usuarios, int num_temas); //tipo_grafoST = 0 para grafo social e 1 para grafo de tema
    void tipoLparaM(Usuario *usuarios[], int num_usuarios);
    void tipoLparaM(Usuario *usuarios[], int num_usuarios, int num_temas);

    void TipoMparaL(Usuario *usuarios[], int num_usuarios);
    void TipoMparaL(Usuario *usuarios[], int num_usuarios, int num_temas);

    //getters
    char getTipoML() const;
    int **getMatriz() const;
    int **getLista() const;
    

    //setters
    void setTipoML(char tipoML);
    void setMatriz(int **nova_matriz);
    void setLista(int **nova_lista);
};

