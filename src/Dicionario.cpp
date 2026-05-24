#include "../include/Dicionario.hpp"

Dicionario::Dicionario(char tipoML){
    _grafo_social = new Grafo(_usuarios, CAPACIDADE_MAXIMA_INICIAL, CAPACIDADE_MAXIMA_INICIAL, tipoML, 0);
    _grafo_temas = new Grafo(_usuarios, CAPACIDADE_MAXIMA_INICIAL, CAPACIDADE_MAXIMA_INICIAL, tipoML, 1);
    _usuarios = new Usuario*[CAPACIDADE_MAXIMA_INICIAL];
    _temas = new Tema*[CAPACIDADE_MAXIMA_INICIAL];

    
    _max_temas = CAPACIDADE_MAXIMA_INICIAL;
    _max_usuarios = CAPACIDADE_MAXIMA_INICIAL;
}

Dicionario::~Dicionario(){}

Usuario **Dicionario::getUsuarios() {
    return _usuarios;
}
Tema **Dicionario::getTemas() {
    return _temas;
}
Grafo *Dicionario::getGrafoSocial() const{
    return _grafo_social;
}
Grafo *Dicionario::getGrafoTemas() const{
    return _grafo_temas;
}

void Dicionario::setNumUsuarios(int novo_num_usuarios){
    _num_usuarios = novo_num_usuarios;
}

void Dicionario::setNumUsuarios(int novo_num_temas){
    _num_temas = novo_num_temas;
}

void Dicionario::adicionarUsuario(Usuario *novo_usuario){
    if(_num_usuarios+1 <= _max_usuarios)
        _usuarios[_num_usuarios] = novo_usuario;
    else{
        if(_grafo_social->getTipoML() == 'M'){
            int **nova_matriz = new int*[_max_usuarios+10];
            for(int i=0; i<_max_usuarios+10; i++){ //preenchendo a nova matriz de adjacencia e apagando a antiga
                nova_matriz[i] = new int[_max_usuarios+10];
                for(int j=0; j<_max_usuarios; j++)
                    nova_matriz[i][j] = _grafo_social->getMatriz()[i][j];
                delete[] _grafo_social->getMatriz()[i];
            }
            delete[] _grafo_social->getMatriz();
            _grafo_social->setMatriz(nova_matriz);
        }
        else{
            int **nova_lista = new int*[_max_usuarios+10];
            for(int i=0; i<_max_usuarios+10; i++){ //preenchendo a nova lista de adjacencia e apagando a antiga
                nova_lista[i] = new int[_usuarios[i]->getNumSeguidores()];
                for(int j=0; j<_usuarios[i]->getNumSeguidores(); j++)
                    nova_lista[i][j] = _grafo_social->getLista()[i][j];
                delete[] _grafo_social->getLista()[i];
            }
            delete[] _grafo_social->getLista();
            _grafo_social->setLista(nova_lista);
        }

        Usuario **novo_vetor_usuarios = new Usuario*[_max_usuarios+10];
        for (int i = 0; i < _num_usuarios; i++)
            novo_vetor_usuarios[i] = _usuarios[i];
        
        delete[] _usuarios;
        _usuarios = novo_vetor_usuarios;
        

        _max_usuarios += 10;
    }
}

void Dicionario::adicionarTema(Tema *novo_tema){
    if(_num_temas+1 <= _max_temas)
        _temas[_num_temas] = novo_tema;
}

