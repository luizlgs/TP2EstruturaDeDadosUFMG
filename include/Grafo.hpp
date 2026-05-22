#include <cstdlib>
#include <iostream>
#include "../include/Usuario.hpp"
#include "../include/Tema.hpp"

class Grafo {
private:
    char _tipo; // B para nenhum dos dois (valor inicial), L para lista de adjacência, M para matriz de adjacência
    int _num_nos;
    int **_matriz; //[usuario do no][usuario com quem ele se relaciona]
    int **_lista;
public:
    Grafo(int num_nos);
    ~Grafo();

    void trocaTipo(bool tipo_grafo, char tipo, Usuario *usuarios[]); //0 para grafo social e 1 para grafo de tema
    void tipoLparaM(Usuario *usuarios[]);
    void tipoLparaM(Usuario *usuarios[], Tema *temas[]);
    void TipoMparaL(Usuario *usuarios[]);
};

