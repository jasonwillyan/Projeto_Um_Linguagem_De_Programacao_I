#ifndef musica_h ///< Estrutura de condição que verifica se arquivo .h já foi incluído
#define musica_h ///< Faz a inserção caso o arquivo .h não tenha sido inserido 
#include <string>
#include "list.h"
using namespace std;

class Musica  //Classe que representa uma música
{
    private:
        string nome;  //Atributo
    public:
        Musica();
        Musica(string str);
        string getNome();
        ~Musica();
        Musica(const Musica&auxiliar);
        Musica& operator=(const Musica&auxiliar);
        bool operator==(const Musica&auxiliar);
};

//Assinaturas das funções

void buscar(List<Musica*>&value, string value2);    
void acessar(List<Musica*>&value, string value2);
void print(List<Musica*>&value);

//***************************

#endif ///< Fim da estrutura de condição