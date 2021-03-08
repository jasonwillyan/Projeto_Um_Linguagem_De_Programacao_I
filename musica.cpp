#include "musica.h"
#include "list.h"
#include <string>
using namespace std;

Musica::Musica()
{
    //Construtor padrão
}
string Musica::getNome()    //Método de acesso
{
    return nome;
}
Musica::Musica(string str)  //Construtor parametrizado
{ 
    nome = str;
}
Musica::~Musica()
{
    //Destrutor padrão
}
Musica::Musica(const Musica&auxiliar)	//Construtor copia
{
    this->nome = auxiliar.nome;
}
Musica& Musica::operator=(const Musica&auxiliar)
{
    this->nome = auxiliar.nome;
    return *this;
}
bool Musica::operator==(const Musica&auxiliar)
{
    return this->nome == auxiliar.nome;
}






void buscar(List<Musica*>&value, string value2)     //Método de buscar elemento na lista 
{	
    for(size_t i = 0; i < value.size(); i++)
    {
        size_t pos = value[i]->getNome().find(value2);

        if(pos != string::npos)
        {
            cout << value[i]->getNome() << endl;    //Imprime a música quando pos é diferente de npos
        }
    }
}

void acessar(List<Musica*>&value, string value2)    //Método que retorna a posição da música (desnecessario)
{	
    for(size_t i = 0; i < value.size(); i++)
    {
        size_t pos = value[i]->getNome().find(value2);
        if(pos != string::npos)
        {
            cout << i+1 << endl;    
        }
    }
}

void print(List<Musica*>&value)  //Método que imprime a lista
{
    for(size_t i = 0; i < value.size(); i++)
    {
        cout << i+1 << " - " << value[i]->getNome() << "\t";
        cout << endl;
    }
}