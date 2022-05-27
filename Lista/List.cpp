#include "List.h"

namespace Lists {

	//Node
	template<class type>
	List<type>::Node::Node(type* Info, Node* Prox, int Size) : info{ Info }, pNext{ Prox }, size{size}
	{

	}

	template<class type>
	List<type>::Node::~Node()
	{

	}

	//Personagens
	template<class type>
	List<type>::List() : inicio{ NULL }, fim{ NULL }, atual{ NULL } { }
	template<class type>
	List<type>::~List() { clear(); }

	template<class type>
	void List<type>::insert(type* Info)
	{
		if (Info)
		{
			Node* novo = new Node(Info);

			if (!inicio)
			{
				inicio = novo;
				fim = novo;
			}
			else
			{
				fim->setProx(novo);

				fim = novo;

			}
		}
		
	}
	template<class type>
	void List<type>::clear()
	{
		Node* Paux = inicio;
		atual = inicio;

		while (atual != NULL)
		{
			Paux = atual->getProx();
			delete atual;

			atual = Paux;
		}

		inicio = NULL;
		fim = NULL;
		atual = NULL;
	
	}
	template<class type>
	type* List<type>::voltarInicio()
	{
		atual = inicio;
		if (atual)
			return atual->getInfo();
		else
			return NULL;
	}

	template<class type>
	type* List<type>::irProximo()
	{
		atual = atual->getProx();

		return(atual) ? atual->getInfo() : NULL;

	}
	
	template<class type>
	void List<type>::remove(const int p)
	{
		int i = 0;
		Node* aux;
		aux = inicio;

		Node* anterior = inicio;  
		aux = inicio;

	
		if (p > getSize(); || p < 1) {
			printf("Valor incompativel com tamanho da lista\n");
		}
		else if (p == 1) {
			inicio = aux->getProx();
			delete aux;
		}
		else {  
			
			while (i != p- 1) {
				anterior = aux;  
				aux = aux->proximo;  
				i++;  
			}

			anterior->getProx() = aux->getProx();

			delete(aux);

		}

	}

	template<class type>
	type* List<type>::operator ++()
	{
		return irProximo();
	}

	template<class type>
	type* List<type>::operator [](const int i)
	{
		int tam = 0;
		tam = atual->getSize();

		if (i >= 0 && i < tam)
		{
			iT = inicio;
			for (int c = 0; c < i; c++)
			{
				iT++;
			}
			return iT;
		}
		else
			std::cout << "Operador de colchetes fora dos limites" << std::endl;
	}
	
