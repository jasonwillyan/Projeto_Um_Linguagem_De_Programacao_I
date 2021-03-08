#ifndef list_h ///< Estrutura de condição que verifica se arquivo .h já foi incluído
#define list_h ///< Faz a inserção caso o arquivo .h não tenha sido inserido 
#include <iostream>
#include <exception>
#include <string>
using namespace std;

//Define uma excessão de acesso inválido

struct inexistent_element : std::exception
{
    const char* what() const noexcept
    {
        return "O elemento em questao nao existe";
    }
};

//******************************************

template <typename tipoLista>

class List  //Classe que representa uma lista encadeada.
{
    private:
		struct node  //Declarando struct que define um nó
		{
			tipoLista dado;  //Variável do tipo declarado
			node *next = nullptr;  //Ponteiro para o próximo nó
		};
        node *head = nullptr;  //Cabeça da lista
        node *tail = nullptr;  //Cauda da lista
		size_t tam = 0;	//Tamanho da lista
    public:
        List()
		{
			//Construtor padrão
		}

        size_t size()const // Retorna o tamanho da lista
		{
			return tam;
		}

		///< Acessa os elementos da lista

		tipoLista& operator[](size_t index)const
		{
			if (index >= size())
			{
				throw inexistent_element();
				//erro (lançar exceção)
			}

			node* current = head;
			size_t currentIndex = 0;

			while (currentIndex < index)
			{
				current = current->next;
				currentIndex++;
			}

			return current->dado;
		}

		//*********************************
		void erase()
		{
			while(head != nullptr)
			{
				this->delet(0);
			}
		}

		List& operator=(const List&auxiliar)
		{
			this->erase();
			for(size_t i = 0; i < auxiliar.size(); i++)
			{
				this->insert(auxiliar[i]);
			}
			return *this;
		}

		friend List& operator>>(List& lista, tipoLista& dado)
		{
			dado = lista[lista.size()-1];
			lista.delet(lista.size()-1);
			return lista;
		}
		friend List<tipoLista>& operator<<(List<tipoLista>& lista, const tipoLista& dado)
		{
			if(dado == nullptr)
			{
				return lista;
			}
			lista.insert(dado);
			return lista;
		}

		friend List operator-(const List&auxiliar, const List&auxiliar2)
		{
			List lista;
			lista.insert(auxiliar);
			for(size_t i = 0; i < auxiliar2.size(); i++)
			{
				for(size_t j = 0; j < lista.size();)
				{
					if(lista[j] == auxiliar2[i])
					{ 
						lista.delet(j);
					}else
					{
						j++;
					}
				}
			}
			return lista;
		}

		friend List operator+(const List&auxiliar, const List&auxiliar2)
		{
			List lista;
			lista.insert(auxiliar);
			lista.insert(auxiliar2);
			return lista;
		}

		void insert(const tipoLista &value)  //Método para criação do nó
		{
			tam++;
			node *temp = new node;
			temp->dado = value;
			temp->next = NULL;

			if(head == NULL)  //Verificando se a lista está vazia
			{
				head = temp;
				tail = temp;
				temp = NULL;
			}
			else
			{	
				tail->next = temp;
				tail = temp;
			}
		}

		void insert(const List& auxiliar)	//Método sobrecarregado da função
		{
			for(size_t i = 0; i < auxiliar.size(); i++)
			{
				this->insert(auxiliar[i]);
			}
		}

		void delet(const List& auxiliar)	//Método sobrecarregado da função
		{
			for(size_t i = 0; i < auxiliar.size(); i++)
			{
				for(size_t j = 0; j < this->size(); j++)
				{
					if(auxiliar[i] == (*this)[j])
					{
						this->delet(j);
					}
				}
			}
		}
		
        void delet(size_t pos)  //Método que deleta um elemento
		{	
			if (pos >= size())
			{
				return;
			}

			size_t currentPos = 0;
			node* previousNode = nullptr;
			node* currentNode = head;

			while (currentPos < pos)
			{
				previousNode = currentNode;
				currentNode = currentNode->next;

				currentPos++;
			}

			if (pos == 0)
			{
				head = currentNode->next;
			}
			else
			{
				previousNode->next = currentNode->next;
			}

			delete currentNode;
			--tam;
		}
        ~List()
		{
			//Destrutor padrão
		};	
		List(const List&auxiliar)	//Construtor copia
		{
			for(size_t i = 0; i < auxiliar.size(); i++)
			{
				this->insert(auxiliar[i]);
			}
		};
};

#endif ///< Fim da estrutura de condição