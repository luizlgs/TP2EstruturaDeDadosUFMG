#include "../include/Grafo.hpp"

Grafo::Grafo(Usuario **usuarios, int num_usuarios, int num_temas, char tipoML, bool tipo_grafoST){
    _matriz = nullptr;
    _lista = nullptr;
    _tipoML = tipoML;

    if(tipoML == 'M'){ //tipo matriz de adjacencia
        _tipoML = 'M';
        _matriz = new int*[num_usuarios];
        if(!tipo_grafoST){ // se for grafo social
            for(int i=0; i<num_usuarios; i++)
                _matriz[i] = new int[num_usuarios]();
        }
        else{ //se for grafo de temas
            for(int i=0; i<num_usuarios; i++)
                _matriz[i] = new int[num_temas]();
        }
    }
    if(tipoML == 'L'){ //tipo lista de adjacencia
        _tipoML = 'L';
        _lista = new int*[num_usuarios];
        if(!tipo_grafoST){ // se for grafo social
            for(int i=0; i<num_usuarios; i++)
                _lista[i] = new int[num_usuarios]();
        }
        else{ //se for grafo de temas
            for(int i=0; i<num_usuarios; i++)
                _lista[i] = new int[num_temas]();
        }
    }
}

Grafo::~Grafo() {}

void Grafo::tipoLparaM(Usuario *usuarios[], int num_usuarios){ // para o grafo social
    //alocando memoria para a matriz de adjacencia
    _matriz = new int*[num_usuarios];
    for(int i = 0; i<num_usuarios; i++){
        _matriz[i] = new int[num_usuarios](); //preenchendo com zeros
    }
    
    //preenchendo a matriz de adjacencia e deletando a lista de adjacencia
    for(int i = 0; i<num_usuarios; i++){
        for(int j=0; j<usuarios[i]->getNumSeguidores(); j++){
            _matriz[i][_lista[i][j]] = 1;
        }
        delete[] _lista[i];
    }
    delete[] _lista;
    _lista = nullptr;
}

void Grafo::tipoLparaM(Usuario *usuarios[], int num_usuarios, int num_temas){ //para o grafo de temas
    //alocando memoria para a matriz de adjacencia
    _matriz = new int*[num_usuarios];
    for(int i = 0; i<num_usuarios; i++){
        _matriz[i] = new int[num_temas](); //preenchendo com zeros
    }
    
    //preenchendo a matriz de adjacencia e deletando a lista de adjacencia
    for(int i = 0; i<num_usuarios; i++){
        for(int j=0; j<usuarios[i]->getNumTemas(); j++){
            _matriz[i][_lista[i][j]] = 1;
        }
        delete[] _lista[i];
    }
    delete[] _lista;
    _lista = nullptr;
}


void Grafo::TipoMparaL(Usuario *usuarios[], int num_usuarios){ //para o grafo social
    //alocando memoria para a lista de adjacencia
    _lista = new int*[num_usuarios];
    for(int i = 0; i<num_usuarios; i++){
        _lista[i] = new int[usuarios[i]->getNumSeguidores()](); //preenchendo com zeros
    }

    //preenchendo a lista de adjacencia e deletando a matriz de adjacencia
    for(int i=0; i<num_usuarios; i++){
        for(int j=0, k=0; j<num_usuarios; j++){
            if(_matriz[i][j] == 1){
                _lista[i][k] = j;
                k++;
            }
        }
        delete[] _matriz[i];
    }
    delete[] _matriz;
    _matriz = nullptr;
}

void Grafo::TipoMparaL(Usuario *usuarios[], int num_usuarios, int num_temas){ //para o grafo de temas
    //alocando memoria para a lista de adjacencia
    _lista = new int*[num_usuarios];
    for(int i = 0; i<num_usuarios; i++){
        _lista[i] = new int[usuarios[i]->getNumTemas()](); //preenchendo com zeros
    }

    //preenchendo a lista de adjacencia e deletando a matriz de adjacencia
    for(int i=0; i<num_usuarios; i++){
        for(int j=0, k=0; j<num_temas; j++){
            if(_matriz[i][j] == 1){
                _lista[i][k] = j;
                k++;
            }
        }
        delete[] _matriz[i];
    }
    delete[] _matriz;
    _matriz = nullptr;
}

void Grafo::trocaTipo(bool tipo_grafoST, char tipo, Usuario *usuarios[], int num_usuarios, int num_temas){
    if(tipo == _tipoML || tipo == 'B'){
        return;
    }

    if(_tipoML == 'L' && tipo == 'M'){
        if(tipo_grafoST == 0)
            tipoLparaM(usuarios, num_usuarios);
        else 
            tipoLparaM(usuarios, num_usuarios, num_temas);
        _tipoML = 'M';
    }
    else{
        if(tipo_grafoST == 0)
            TipoMparaL(usuarios, num_usuarios);
        else
            TipoMparaL(usuarios, num_usuarios, num_temas);
        _tipoML = 'L';
    }
}

char Grafo::getTipoML() const{
    return _tipoML;
}

int **Grafo::getMatriz() const{
    return _matriz;
}

int **Grafo::getLista() const{
    return _lista;
}


void Grafo::setTipoML(char tipoML){
    _tipoML = tipoML; 
}

void Grafo::setMatriz(int **nova_matriz){
    _matriz = nova_matriz;
}

void Grafo::setLista(int **nova_lista){
    _lista = nova_lista;
}


