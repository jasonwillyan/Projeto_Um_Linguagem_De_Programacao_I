#ifndef reprodutor_h ///< Estrutura de condição que verifica se arquivo .h já foi incluído
#define reprodutor_h ///< Faz a inserção caso o arquivo .h não tenha sido inserido 
#include <string>
#include "list.h"
#include "playlist.h"
#include "musica.h"
using namespace std;

class Reprodutor  //Classe que gerencia o que está sendo tocado / "Player de música"
{
    private:
        
    public:
        Reprodutor();
        ~Reprodutor();
        Musica *reprodutorMusica(List<Playlist>&value);
};

#endif ///< Fim da estrutura de condição