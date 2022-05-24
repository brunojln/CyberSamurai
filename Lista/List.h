#pragma once
#include "../Includes/stdafx.h"

class Personagem; //alterar, temporario

class List {
private:

	class Node {
	private:
		Personagem* info;
		Node* pAnt;
		Node* pNext;


	public:

		Node(Personagem* Info = NULL, Node* Ant = NULL, Node* Prox = NULL);
		~Node();

		Personagem* getInfo();
		void setInfo(Personagem* Info);

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

	void update(float t);
	void render(sf::RenderWindow* janela);
	void deleteCharacters();


};
