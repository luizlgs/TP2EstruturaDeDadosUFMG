#include "../include/Grafo.hpp"

Grafo::Grafo(int num_nos) : _num_nos(num_nos) {}

Grafo::~Grafo() {}

void Grafo::tipoLparaM(Usuario *usuarios[]){
    //deletando a matriz antiga
    for(int i = 0; i<_num_nos; i++){
        delete[] _matriz[i];
    }
    delete[] _matriz;

    //alocando memoria para a mtriz de adjacencia
    _matriz = new int*[_num_nos];
    for(int i = 0; i<_num_nos; i++){
        _matriz[i] = new int[_num_nos](); //preenchendo com zeros
    }
    
    //preenchendo a matriz de adjacencia
    for(int i = 0; i<_num_nos; i++){
        for(int j=0; j<usuarios[i]->getSeguidores(); j++){
            _matriz[i][_lista[i][j]] = 1;
        }
    }

}

void Grafo::tipoLparaM(Usuario *usuarios[], Tema *temas[]){
    //deletando a matriz antiga
    for(int i = 0; i<_num_nos; i++){
        delete[] _matriz[i];
    }
    delete[] _matriz;

    //alocando memoria para a mtriz de adjacencia
    _matriz = new int*[_num_nos];
    for(int i = 0; i<_num_nos; i++){
        _matriz[i] = new int[_num_nos](); //preenchendo com zeros
    }
    
    //preenchendo a matriz de adjacencia
    for(int i = 0; i<_num_nos; i++){
        for(int j=0; j<usuarios[i]->getSeguidores(); j++){
            _matriz[i][_lista[i][j]] = 1;
        }
    }
}

//[[1, 2, 3], [5, 3, 2], [3, 4]]

void Grafo::TipoMparaL(Usuario *usuarios[]){

}

void Grafo::trocaTipo(bool tipo_grafo, char tipo, Usuario *usuarios[]){
    if(tipo == _tipo){
        return;
    }
    else if(tipo == 'B'){
        
    }
    else if(tipo != 'B'){
        if(_tipo == 'L' && tipo == 'M')
            tipoLparaM(usuarios);
            _tipo = 'M';
        if(_tipo == 'M' && tipo == 'L')
            TipoMparaL(usuarios);
            _tipo = 'L';
    }
}

