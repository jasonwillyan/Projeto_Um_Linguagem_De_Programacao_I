#include "playlist.h"
#include <string>
using namespace std;

Playlist::Playlist()
{
    //Construtor padrão
}
Playlist::~Playlist()
{
    //Destrutor padrão
}
Playlist::Playlist(const Playlist&auxiliar)
{
    this->nome = auxiliar.nome;
    for(size_t i = 0; i < auxiliar.musicas.size(); i++)
    {
        this->musicas.insert(auxiliar.musicas[i]);
    }
}
Playlist& Playlist::operator=(const Playlist&auxiliar)
{
    this->nome = auxiliar.nome;
    for(size_t i = 0; i < auxiliar.musicas.size(); i++)
    {
        this->musicas.insert(auxiliar.musicas[i]);
    }
    return *this;
}

void printList(List<Playlist>&value, List<Musica*>&value2)    //Método de adicionar músicas em uma playlist
{
    for(size_t i = 0; i < value.size(); i++)
    {
        cout << i+1 << " - " << value[i].nome << endl;
    }
    cout << "Digite numero da playlist" << endl;
    int j, k;
    cin >> j;
    for(size_t i = 0; i < value2.size(); i++) 
    {
        cout << i+1 << " - " << value2[i]->getNome() << endl;
    }
    cout << "Digite o numero da musica" << endl;
    cin >> k;
    value[j-1].musicas.insert(value2[k-1]);
}

void Playlist::printPlaylist()  //Método que imprime músicas de uma playlists
{
    
    for(size_t i = 0; i < this->musicas.size(); i++)
    {
        cout << i+1 << " - " << musicas[i]->getNome() << endl;
    }
}

void printListPlaylist(List<Playlist>&value)    //Método que imprime o nome das playlists
{
    for(size_t i = 0; i < value.size(); i++)
    {
        cout << i+1 << " - " << value[i].nome << endl;
    }
    
}

void removerMusicaPlaylist(List<Playlist>&value)    //Método que remove músicas de uma playlist
{
    printListPlaylist(value);
    int var;
    cout << "Digite o numero da playlist" << endl;
    cin >> var;
    value[var-1].printPlaylist();
    int aux;
    cout << "Digite o numero da musica" << endl;
    cin >> aux;
    value[var-1].musicas.delet(aux-1);

}

void removerPlaylist(List<Playlist>&value)  //Método que remove uma playlist
{
    printListPlaylist(value);
    int var;
    cout << "Digite o numero da playlist" << endl;
    cin >> var;
    value.delet(var-1);
}
void removerMusica(List<Musica*>&value, List<Playlist>&value2)  //Método que remove música da lista e das playlist
{
    int aux;
    print(value);
    cout << "Digite o numero da musica" << endl;
    cin >> aux;
    string nome = value[aux-1]->getNome();
    for(size_t i = 0; i < value2.size(); i++)
    {
        for(size_t j = 0; j < value2[i].musicas.size(); j++)
        {
            size_t pos = value2[i].musicas[j]->getNome().find(nome);
            if(pos != string::npos)
            {
                value2[i].musicas.delet(j);
                break;   
            }
        }
    }

    value.delet(aux-1);
}


