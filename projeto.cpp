#include <iostream>  
//jason willyan
#include <string>
#include <cstdlib>
#include "musica.h"
#include "list.h"
#include "playlist.h"
#include "reprodutor.h"
#include "sistema.h"
#ifdef _WIN32
#define cls system("cls")
#else
#define cls system("clear")
#endif
#define pause cin.get(); cin.clear(); cout << "Pressione qualquer tecla para continuar. . ." << endl; cin.get();
using namespace std; 

int main(){

    //Construtores parametrizados

    Musica a("Musica 1");  
    Musica b("Musica 2");  
    Musica c("Musica 3");  
    Musica d("Musica 4");  
    Musica e("Musica 5");  
    Musica f("Musica 6");  

    //*******************************

    Sistema nucleo_01;
    Sistema nucleo_02;

    //Adiociando músicas na lista

    nucleo_01.musicas.insert(&a);
    nucleo_01.musicas.insert(&b);
    nucleo_01.musicas.insert(&c);

    nucleo_02.musicas.insert(&d);
    nucleo_02.musicas.insert(&e);
    nucleo_02.musicas.insert(&f);  

    //***********************************

    List<Musica*>lista_01(nucleo_01.musicas);  //Criando lista 1
    List<Musica*>lista_02(nucleo_02.musicas);  //Criando lista 2

    Musica *t;  //Criando ponteiro de Música
    Musica z("MUSICA TESTE");   //Criando música

    cout << endl;
    cout << "lista_01: metodo de insercao (inserindo MUSICA TESTE)" << endl;
    lista_01 << (&z);    //Inserindo elemento no final da lista (método de inserção)
    print(lista_01);
    cout << endl;

    cout << "lista_01: metodo de extracao (extraindo MUSICA TESTE)" << endl;
    lista_01 >> t;      //Extraindo o elemento final da lista para um ponteiro (método de extração)
    print(lista_01);
    cout << endl;

    cout << "lista_03: lista_01 + lista_02 (OPERADOR \"+\")" << endl;
    List<Musica*>lista_03(lista_01 + lista_02);  //Criando uma nova lista através do construtor cópia e usando o método de adição (operador "+")
    print(lista_03);
    cout << endl;

    cout << "lista_03: lista_03 + lista_01 (OPERADOR \"-\")" << endl;
    lista_03 = lista_03 - lista_01;     //Usando o método de adição (operador "+")
    print(lista_03);
    cout << endl;
    return 0;
/*

    while(1)
    {   
        cls;    //Limpa tela
        cout<<"\n***************************************************\n";
        cout<<"*                      MENU                         *\n";
        cout<<"*                                                   *\n";
        cout<<"* 1 - Buscar elemento na lista                      *\n";
        cout<<"* 2 - Acessar elemento na lista                     *\n";
        cout<<"* 3 - Inserir elemento na lista                     *\n";
        cout<<"* 4 - Remover elemento na lista                     *\n";
        cout<<"* 5 - Imprimir lista                                *\n";
        cout<<"* 6 - Criar Playlist                                *\n";
        cout<<"* 7 - Remover Playlist                              *\n";
        cout<<"* 8 - Adicionar musica na playlist                  *\n";
        cout<<"* 9 - remover musica da playlist                    *\n";
        cout<<"* 10 - Imprimir playlist                            *\n";
        cout<<"* 11 - Play musica                                  *\n";
        cout<<"* 0 - Sair                                          *\n";
        cout<<"\n***************************************************\n";
        cout << endl;
    
        //Criando várivaies do tipo inteiro para auxiliar 

        int menu;
        int aux;

        ***********************************************

        //Criando váriaveis do tipo string para auxiliar

        string palavra;
        string palavra2;
        string nomeMusica;
        string nomePlaylist;

        *********************************************

        cin >> menu;    //Recebendo opção do menu

        //Associando as funções do menu no switch case

        switch(menu)
        {
            case 1:
            {
                cout << "Digite o nome da musica que deseja buscar: " << endl;
                cin.ignore();
                getline(cin, palavra);
                buscar(nucleo.musicas, palavra);
                break;
            }
            case 2:
            {
                cout << "Digite o nome da musica que deseja buscar (retorna posicao): " << endl;
                cin.ignore();
                getline(cin, palavra2);
                acessar(nucleo.musicas, palavra2);
                break;
            }
            case 3:
            {
                cin.ignore();
                getline(cin, nomeMusica);
                Musica *novaMusica = new Musica(nomeMusica);
                nucleo.musicas.insert(novaMusica);
                break;
            }
            case 4:
            {
                removerMusica(nucleo.musicas, nucleo.playlists);
                break;
            }
            case 5:
            {
                print(nucleo.musicas);
                break;
            }
            case 6:
            {
                cout << "Digite o nome da Playlist: " << endl;
                cin.ignore();
                getline(cin, nomePlaylist);
                Playlist play;
                play.nome = nomePlaylist;
                nucleo.playlists.insert(play);
                break;
            }
            case 7:
            {
                removerPlaylist(nucleo.playlists);
                break;
            }
            case 8:
            {
                printList(nucleo.playlists, nucleo.musicas);
                break;
            }
            case 9:
            {
                removerMusicaPlaylist(nucleo.playlists);
                break;
            }
            case 10:
            {   
                printListPlaylist(nucleo.playlists);
                cout << "Digite numero da playlist" << endl;
                cin >> aux;
                nucleo.playlists[aux-1].printPlaylist();
                break;
            }
            case 11:
            {
                nucleo.reprodutor.reprodutorMusica(nucleo.playlists);

            }
        }
        if(menu == 0)   //Condição de parada do programa
        {
            break;
        }
        pause;  
    }

    *****************************************************************************
    return 0;
    */
}