#pragma once
#include "../Includes/stdafx.h"

 //alterar, temporario

template <class type>

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

		Node* getAnt() { return pAnt; }
		void setAnt(Node* Ant);

		Node* getProx() { return pProx;  }
		void setProx(Node* Prox);

	};

	Node* inicio;
	Node* fim;
	Node* atual;

public:
	List();
	~List();

	void insert(type* Info);
	void clear();

	type* voltarInicio();
	type* irProximo();

	void update(float t);
	void render(sf::RenderWindow* janela);
	void deleteCharacters();


};
