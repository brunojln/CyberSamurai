#pragma once
#include "../Includes/stdafx.h"

class Personagem; //alterar, temporario

template<class type>

class List {
private:

	class Node {
	private:
		type* info;
		Node* pAnt;
		Node* pNext;


	public:

		Node(type* Info = NULL, Node* Ant = NULL, Node* Prox = NULL);
		~Node();

		type* getInfo();
		void setInfo(type* Info);

		Node* getAnt();
		void setAnt(Node* Ant);

		Node* getProx();
		void setProx(Node* Prox);

	};

	Node* inicio;
	Node* fim;
	Node* atual;


public:
	List();
	~List();

	void insert(Personagem* Info);
	void clear();

	Personagem* voltarInicio();
	Personagem* irProximo();
	Personagem* voltarAnt();
	
	Personagem* operator ++();
	Personagem* operator --();

	void update(float t);
	void render(sf::RenderWindow* janela);
	void deleteCharacters();


};
