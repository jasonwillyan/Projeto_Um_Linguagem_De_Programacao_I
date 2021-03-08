#include "reprodutor.h"
#define cls system("cls")
#define pause cin.get(); cin.clear(); cout << "Pressione qualquer tecla para continuar. . ." << endl; cin.get();
 

Reprodutor::Reprodutor()
{
    //Construtor padrão
}
Reprodutor::~Reprodutor()
{
    //Destrutor padrão
}

Musica *Reprodutor::reprodutorMusica(List<Playlist>&value)  //Método de "reproduzir" músicas de uma playlist
{
    printListPlaylist(value);   //Imprime as playlists
    int aux;
    int var;
    cin >> aux;
    for(size_t i = 0; i < value[aux-1].musicas.size();)
    {
        cls; 
        cout << "tocando: " << value[aux-1].musicas[i]->getNome() << endl;
        cout << "Digite 1 para proxima musica" << endl;
        cin >> var;
        if(var == 1)    //Se o auxiliar for igual a 1, toca próxima música
        {
            i++;
        }
        else    //Se não, para
        {
            break;
        }

    }
    return nullptr;     //Retorna NULL se não existir próxima música
}

