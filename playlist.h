#ifndef playlist_h ///< Estrutura de condição que verifica se arquivo .h já foi incluído
#define playlist_h ///< Faz a inserção caso o arquivo .h não tenha sido inserido 
#include <string>
#include "list.h"
#include "musica.h"
using namespace std;

class Playlist  //Classe que representa uma música do sistema
{
    private:

    public:
        Playlist();
        List<Musica*> musicas;
        string nome;
        ~Playlist();
        void printPlaylist();
        Playlist(const Playlist&auxiliar);
        Playlist& operator=(const Playlist&auxiliar);

};

//Assinaturas das funções

void printList(List<Playlist>&value, List<Musica*>&value2);
void printListPlaylist(List<Playlist>&value);
void removerMusicaPlaylist(List<Playlist>&value);
void removerPlaylist(List<Playlist>&value);
void removerMusica(List<Musica*>&value, List<Playlist>&value2);

//***************************

#endif ///< Fim da estrutura de condição