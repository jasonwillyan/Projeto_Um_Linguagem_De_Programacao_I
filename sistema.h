#ifndef sistema_h ///< Estrutura de condição que verifica se arquivo .h já foi incluído
#define sistema_h ///< Faz a inserção caso o arquivo .h não tenha sido inserido 
#include <string>
#include "list.h"
#include "reprodutor.h"
#include "musica.h"
using namespace std;

class Sistema  //Classe que representa uma música do sistema
{
    private:

    public:
        Sistema();
        ~Sistema();
        List<Musica*> musicas;  //Criando lista que armazena objetos do tipo musica
        List<Playlist> playlists;   //Criando uma lista de playlists 
        Reprodutor reprodutor;  //Criando um objeto padrão

};

#endif ///< Fim da estrutura de condição