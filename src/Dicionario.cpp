#include "../include/Dicionario.hpp"

Dicionario::Dicionario(char tipoML){
    _grafo_social = new Grafo(_usuarios, CAPACIDADE_MAXIMA_INICIAL, CAPACIDADE_MAXIMA_INICIAL, tipoML, 0);
    _grafo_temas = new Grafo(_usuarios, CAPACIDADE_MAXIMA_INICIAL, CAPACIDADE_MAXIMA_INICIAL, tipoML, 1);
    _usuarios = new Usuario*[CAPACIDADE_MAXIMA_INICIAL];
    _temas = new Tema*[CAPACIDADE_MAXIMA_INICIAL];

    _num_temas = _num_usuarios = 0;
    _max_temas = _max_usuarios = CAPACIDADE_MAXIMA_INICIAL;
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

int Dicionario::getNumUsuarios() const{
    return _num_usuarios;
}

int Dicionario::getNumTemas() const{
    return _num_temas;
}

void Dicionario::setNumUsuarios(int novo_num_usuarios){
    _num_usuarios = novo_num_usuarios;
}

void Dicionario::setNumTemas(int novo_num_temas){
    _num_temas = novo_num_temas;
}

void Dicionario::adicionarUsuario(Usuario *novo_usuario, int indices_temas[], int num_temas_usuario){ //comando U que tambem adiciona os temas de interesse do usuario novo
    if(_num_usuarios+1 <= _max_usuarios){
        _usuarios[_num_usuarios] = novo_usuario;
        _num_usuarios++;
        if(_grafo_temas->getTipoML() == 'L')
            _grafo_temas->getLista()[novo_usuario->getId()] = new int[num_temas_usuario]();
        for(int i=0; i<num_temas_usuario; i++){
            if(_grafo_temas->getTipoML() == 'M')
                _grafo_temas->getMatriz()[novo_usuario->getId()][_temas[indices_temas[i]]->getId()] = 1;
            else{
                _grafo_temas->getLista()[novo_usuario->getId()][i] = _temas[indices_temas[i]]->getId();
            }


        }
    }

    else{ //aumentando a capacidade do grafo_social
        if(_grafo_social->getTipoML() == 'M'){
            int **nova_matriz = new int*[_max_usuarios+ORDEM_DE_CRESCIMENTO_DE_USUARIOSeTEMAS];
            for(int i=0; i<_max_usuarios+ORDEM_DE_CRESCIMENTO_DE_USUARIOSeTEMAS; i++){ //preenchendo a nova matriz de adjacencia e apagando a antiga
                nova_matriz[i] = new int[_max_usuarios+ORDEM_DE_CRESCIMENTO_DE_USUARIOSeTEMAS]();
                for(int j=0; (i< _max_usuarios) && j<_max_usuarios; j++)
                    nova_matriz[i][j] = _grafo_social->getMatriz()[i][j];
                if(i < _max_usuarios)
                    delete[] _grafo_social->getMatriz()[i];
            }
            delete[] _grafo_social->getMatriz();
            _grafo_social->setMatriz(nova_matriz);
        }
        else{
            int **nova_lista = new int*[_max_usuarios+ORDEM_DE_CRESCIMENTO_DE_USUARIOSeTEMAS];
            for(int i=0; i<_max_usuarios+ORDEM_DE_CRESCIMENTO_DE_USUARIOSeTEMAS; i++){ //preenchendo a nova lista de adjacencia e apagando a antiga
                if(i < _max_usuarios)
                    nova_lista[i] = new int[_usuarios[i]->getNumSeguidores()]();
                else
                    nova_lista[i] = nullptr;
                for(int j=0; (i< _max_usuarios) && j<_usuarios[i]->getNumSeguidores(); j++)
                    nova_lista[i][j] = _grafo_social->getLista()[i][j];
                if(i < _max_usuarios)
                    delete[] _grafo_social->getLista()[i];
            }
            delete[] _grafo_social->getLista();
            _grafo_social->setLista(nova_lista);
        }

        //adicionando linhas para os usuarios no grafo de temas
        if(_grafo_temas->getTipoML() == 'M'){
            int **nova_matriz_temas = new int*[_max_usuarios+ORDEM_DE_CRESCIMENTO_DE_USUARIOSeTEMAS];
            for(int i=0; i<_max_usuarios+ORDEM_DE_CRESCIMENTO_DE_USUARIOSeTEMAS; i++){ 
                // Colunas representam o total de temas do sistema
                nova_matriz_temas[i] = new int[_num_temas](); 
                for(int j=0; (i < _max_usuarios) && j < _num_temas; j++)
                    nova_matriz_temas[i][j] = _grafo_temas->getMatriz()[i][j];
                if(i < _max_usuarios)
                    delete[] _grafo_temas->getMatriz()[i];
            }
            delete[] _grafo_temas->getMatriz();
            _grafo_temas->setMatriz(nova_matriz_temas);
        }
        else{
            int **nova_lista_temas = new int*[_max_usuarios+ORDEM_DE_CRESCIMENTO_DE_USUARIOSeTEMAS];
            for(int i=0; i<_max_usuarios+ORDEM_DE_CRESCIMENTO_DE_USUARIOSeTEMAS; i++){ 
                if(i < _max_usuarios)
                    nova_lista_temas[i] = new int[_usuarios[i]->getNumTemas()]();
                else
                    nova_lista_temas[i] = nullptr;
                for(int j=0; (i < _max_usuarios) && j < _usuarios[i]->getNumTemas(); j++)
                    nova_lista_temas[i][j] = _grafo_temas->getLista()[i][j];
                if(i < _max_usuarios)
                    delete[] _grafo_temas->getLista()[i];
            }
            delete[] _grafo_temas->getLista();
            _grafo_temas->setLista(nova_lista_temas);
        }

        //adicionando o novo usuario no array de usuarios
        Usuario **novo_vetor_usuarios = new Usuario*[_max_usuarios+ORDEM_DE_CRESCIMENTO_DE_USUARIOSeTEMAS];
        for (int i = 0; i < _num_usuarios; i++)
            novo_vetor_usuarios[i] = _usuarios[i];
        
        delete[] _usuarios;
        _usuarios = novo_vetor_usuarios;
        
        _max_usuarios += ORDEM_DE_CRESCIMENTO_DE_USUARIOSeTEMAS;

        adicionarUsuario(novo_usuario, indices_temas, num_temas_usuario);
    }
}

void Dicionario::adicionarTema(Tema *novo_tema){
    if(_num_temas+1 <= _max_temas){
        _temas[_num_temas] = novo_tema;
        _num_temas++;
    }
    else{
        //aumentando o lista de temas
        Tema **nova_lista_temas = new Tema*[_max_temas+ORDEM_DE_CRESCIMENTO_DE_USUARIOSeTEMAS];
        for(int i=0; i<_num_temas; i++){
            nova_lista_temas[i] = _temas[i];
        }
        delete[] _temas;
        _temas = nova_lista_temas;

        //aumentando a capacidade do grafo de temas
        if(_grafo_temas->getTipoML() == 'M'){
            int **novo_grafo_temas = new int*[_max_usuarios];
            for(int i=0; i<_max_usuarios; i++){
                novo_grafo_temas[i] = new int[_max_temas+ORDEM_DE_CRESCIMENTO_DE_USUARIOSeTEMAS]();
                for(int j=0; j<_num_temas; j++){
                    novo_grafo_temas[i][j] = _grafo_temas->getMatriz()[i][j];
                }
                delete[] _grafo_temas->getMatriz()[i];
            }
            delete[] _grafo_temas->getMatriz();
            _grafo_temas->setMatriz(novo_grafo_temas);
        }
        _max_temas += ORDEM_DE_CRESCIMENTO_DE_USUARIOSeTEMAS;
        adicionarTema(novo_tema);
    }
}

void Dicionario::seguir(unsigned int id1, unsigned int id2) {
    if(_grafo_social->getTipoML() == 'M' && _grafo_social->getMatriz()[id1][id2] == 0){
        _grafo_social->getMatriz()[id1][id2] = 1;
    }
    else{
        //verificando se o usuario do id1 ja segue o do id2
        for(int i=0; i<_usuarios[id1]->getNumSeguidores(); i++){
            if(_grafo_social->getLista()[id1][i] == id2){
                return;
            }
        }

        //adicionando o usuario do id2 na lista de seguidores do usuario do id1
        int *nova_lista_seguidores = new int[_usuarios[id1]->getNumSeguidores()+1];
        for(int i=0; i<_usuarios[id1]->getNumSeguidores(); i++)
            nova_lista_seguidores[i] = _grafo_social->getLista()[id1][i];
        nova_lista_seguidores[_usuarios[id1]->getNumSeguidores()] = id2;
        delete[] _grafo_social->getLista()[id1];
        _grafo_social->getLista()[id1] = nova_lista_seguidores;
    }
    _usuarios[id1]->setNumSeguidores(_usuarios[id1]->getNumSeguidores()+1);
}

void Dicionario::remocaoSeguidor(unsigned int id1, unsigned int id2){
    if(_usuarios[id1]->getNumSeguidores() == 0)
        return;

    if(_grafo_social->getTipoML() == 'M'){
        if(_grafo_social->getMatriz()[id1][id2]){
            _grafo_social->getMatriz()[id1][id2] = 0;
            _usuarios[id1]->setNumSeguidores(_usuarios[id1]->getNumSeguidores()-1);
        }
    }
    else{
        bool segue = 0; //para verificar se o id1 realmente segue o id2
        for(int i=0; i<_usuarios[id1]->getNumSeguidores(); i++){
            if(_grafo_social->getLista()[id1][i] == id2)
                segue = 1;
        }
        if(!segue)
            return;
        int *nova_lista_seguidores = new int[_usuarios[id1]->getNumSeguidores()-1];
        for(int i=0, j=0; i<_usuarios[id1]->getNumSeguidores(); i++, j++){
            if(_grafo_social->getLista()[id1][i] != id2){
                nova_lista_seguidores[j] = _grafo_social->getLista()[id1][i];
            }
            else{
                j--;
            }
        }
        delete[] _grafo_social->getLista()[id1];
        _grafo_social->getLista()[id1] = nova_lista_seguidores;
        _usuarios[id1]->setNumSeguidores(_usuarios[id1]->getNumSeguidores()-1);
        if(_usuarios[id1]->getNumSeguidores() == 0){
            delete[] _grafo_social->getLista()[id1];
            _grafo_social->getLista()[id1] = nullptr;
        }
    }
}

void Dicionario::listaTemas(unsigned int id){
    if(_grafo_temas->getTipoML() == 'M'){
        for(int i=0, j=0; i<_num_temas; i++){
            if(_grafo_temas->getMatriz()[id][i]){
                std::cout << _temas[i]->getNome();
                j++;
                if(j != _usuarios[id]->getNumTemas())
                    std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    else{
        for(int i=0; i<_usuarios[id]->getNumTemas(); i++){
            std::cout << _temas[_grafo_temas->getLista()[id][i]]->getNome();
            if(i!=_usuarios[id]->getNumTemas()-1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void Dicionario::consultaSeguidores(unsigned int id){
    if(_grafo_social->getTipoML() == 'M'){
        for(int i=0, j=0; i<_num_usuarios; i++){
            if(_grafo_social->getMatriz()[i][id]){
                if(j > 0)
                    std::cout << " ";
                std::cout << _usuarios[i]->getNome();
                j++;
            }
        }
        std::cout << std::endl;
    }
    else{
        int k=0;
        for(int i=0; i<_num_usuarios; i++){
            if(i != id){
                for(int j=0; j<_usuarios[i]->getNumSeguidores(); j++){
                    if(_grafo_social->getLista()[i][j] == id){
                        if(k > 0)
                            std::cout << " ";
                        std::cout << _usuarios[i]->getNome();
                        k++;
                        break;
                    }
                }
            }
        }
        std::cout << std::endl; 
    }
}

void Dicionario::consultaSeguidos(unsigned int id){
    if(_grafo_social->getTipoML() == 'M'){
        for(int i=0, j=0; i<_num_usuarios; i++){
            if(_grafo_social->getMatriz()[id][i]){
                std::cout << _usuarios[i]->getNome();
                j++;
                if(j != _usuarios[id]->getNumSeguidores())
                    std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    else{
        for(int i=0; i<_usuarios[id]->getNumSeguidores(); i++){
            std::cout << _usuarios[_grafo_social->getLista()[id][i]]->getNome();
            if(i != _usuarios[id]->getNumSeguidores()-1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void Dicionario::consultaAmigos(unsigned int id) {
    if(_grafo_social->getTipoML() == 'M'){
        for(int i=0, j=0; i<_num_usuarios; i++){
            if(_grafo_social->getMatriz()[id][i] && _grafo_social->getMatriz()[i][id]){
                if(j>0)
                    std::cout << " ";
                std::cout << _usuarios[i]->getNome();
                j++;
            }
        }
        std::cout << std::endl;
    }
    else{
        int k=0;
        for(int i=0; i<_usuarios[id]->getNumSeguidores(); i++){
            int id_amigo = _grafo_social->getLista()[id][i];
            for(int j=0; j<_usuarios[id_amigo]->getNumSeguidores(); j++){
                if(_grafo_social->getLista()[id_amigo][j] == id){
                    if(k>0)
                        std::cout << " ";
                    std::cout << _usuarios[id_amigo]->getNome();
                    k++;
                }
            }
            
        }
        std::cout << std::endl;
    }
}

int Dicionario::consultaRelacao(unsigned int id1, unsigned int id2){
    int relacao = 0;
    if(_grafo_social->getTipoML() == 'M'){
        if(!_grafo_social->getMatriz()[id1][id2] && !_grafo_social->getMatriz()[id2][id1])
            relacao = 0;
        else if(_grafo_social->getMatriz()[id1][id2] && !_grafo_social->getMatriz()[id2][id1])
            relacao = 1;
        else if(!_grafo_social->getMatriz()[id1][id2] && _grafo_social->getMatriz()[id2][id1])
            relacao = 2;
        else if(_grafo_social->getMatriz()[id1][id2] && _grafo_social->getMatriz()[id2][id1])
            relacao = 3;
    }

    else{
        bool seg1, seg2;
        seg1 = seg2 = 0;
        for(int i=0; i<_usuarios[id1]->getNumSeguidores(); i++){
            if(_grafo_social->getLista()[id1][i] == id2){
                seg1 = 1;  
                break; 
            }
        }
        for(int i=0; i<_usuarios[id2]->getNumSeguidores(); i++){
            if(_grafo_social->getLista()[id2][i] == id1){
                seg2 = 1;
                break; 
            }
        }

        if(!seg1 && !seg2){
            relacao = 0;
        }
        if(seg1 && !seg2){
            relacao = 1;
        }
        if(!seg1 && seg2){
            relacao = 2;
        }
        if(seg1 && seg2){
            relacao = 3;
        }

    }
    return relacao;
}

int Dicionario::consultaDeInteresse(unsigned int id_usuario, unsigned int id_tema){
    if(_grafo_temas->getTipoML() == 'M'){
        if(_grafo_temas->getMatriz()[id_usuario][id_tema])
            return 1;
        else
            return 0;
    }
    else{
        for(int i=0; i<_usuarios[id_usuario]->getNumTemas(); i++){
            if(_grafo_temas->getLista()[id_usuario][i] == id_tema){
                return 1;
            }
        }
        return 0;
    }
}

int Dicionario::consultaDePopularidade(unsigned int id_tema){
    int popularidade = 0;
    if(_grafo_temas->getTipoML() == 'M'){
        for(int i=0; i<_num_usuarios; i++){
            if(_grafo_temas->getMatriz()[i][id_tema])
                popularidade++;
        }
    }
    else{
        for(int i=0; i<_num_usuarios; i++){
            for(int j=0; j<_usuarios[i]->getNumTemas(); j++){
                if(_grafo_temas->getLista()[i][j] == id_tema){
                    popularidade++;
                    break;
                }
                    
            }
        }
    }
    return popularidade;
}

