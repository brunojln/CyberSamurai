#include "List.h"


//Node
template<class type>
List<type>::Node::Node(type* Info, Node* Ant, Node* Prox) : info{ Info }, pAnt{ Ant }, pNext{ Prox }
{

}

template<class type>
List<type>::Node::~Node()
{

}
/*
template<class type>
type* List<type>::Node::getInfo()
{
	return info;
}

template<class type>
void List<type>::Node::setInfo(type* Info)
{
	info = Info;
}

template<class type>
List<type>::Node* List<type>::Node::getAnt()
{
	return pAnt;
}
template<class type>
void List<type>::Node::setAnt(Node* Ant)
{
	pAnt = Ant;
}

template<class type>
List<type>::Node* List<type>::Node::getProx()
{
	return pNext;
}

template<class type>
void List<type>::Node::setProx(Node* Prox)
{
	pNext = Prox;
}*/

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
			novo->setAnt(fim);

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
type* List<type>::voltarAnt()
{
	atual = atual->getAnt();

	return(atual) ? atual->getInfo() : NULL;

}
template<class type>
type* List<type>::operator ++()
{
	return irProximo();
}
template<class type>
type* List<type>::operator --()
{
	return voltarAnt();
}
template<class type>
void List<type>::update(float t)
{
	type* p = voltarInicio();

	while (p)
	{
		//p->atualizar(t); // <----
		p = irProximo();
	}

}
template<class type>
void List<type>::render(sf::RenderWindow* janela)
{
	type* p = voltarInicio();

	while (p)
	{
		//p->desenhar(janela); //<---
		p = irProximo();
	}
}
template<class type>
void List<type>::deleteCharacters()
{
	type* p = voltarInicio();

	while (p)
	{
		delete p;

		p = irProximo();
	}
	clear();
}