#include "List.h"


//Node

List::Node::Node(Personagem* Info, Node* Ant, Node* Prox) : info{ Info }, pAnt{ Ant }, pNext{ Prox }
{

}

List::Node::~Node()
{

}


Personagem* List::Node::getInfo()
{
	return info;
}
void List::Node::setInfo(Personagem* Info)
{
	info = Info;
}

List::Node* List::Node::getAnt()
{
	return pAnt;
}
void List::Node::setAnt(Node* Ant)
{
	pAnt = Ant;
}

List::Node* List::Node::getProx()
{
	return pNext;
}
void List::Node::setProx(Node* Prox)
{
	pNext = Prox;
}

//Personagens

List::List() : inicio{ NULL }, fim{ NULL }, atual{ NULL } { }
List::~List() { clear(); }


void List::insert(Personagem* Info)
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
void List::clear()
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

Personagem* List::voltarInicio()
{
	atual = inicio;
	if (atual)
		return atual->getInfo();
	else
		return NULL;
}
Personagem* List::irProximo()
{
	atual = atual->getProx();

	return(atual) ? atual->getInfo() : NULL;


}

void List::update(float t)
{
	Personagem* p = voltarInicio();

	while (p)
	{
		//p->atualizar(t); // <----
		p = irProximo();
	}

}
void List::render(sf::RenderWindow* janela)
{
	Personagem* p = voltarInicio();

	while (p)
	{
		//p->desenhar(janela); //<---
		p = irProximo();
	}
}

void List::deleteCharacters()
{
	Personagem* p = voltarInicio();

	while (p)
	{
		delete p;

		p = irProximo();
	}
	clear();
}

