#pragma once
#include "../Includes/stdafx.h"


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

		type* getInfo(){ return info; }
		void setInfo(type* Info){ info = Info; }

		Node* getAnt(){ return pAnt; }
		void setAnt(Node* Ant){ pAnt = Ant; }

		Node* getProx(){ return pNext; }
		void setProx(Node* Prox){ pNext = Prox; }

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
	type* voltarAnt();
	
	type* operator ++();
	type* operator --();

	void update(float t);
	void render(sf::RenderWindow* janela);
	void deleteCharacters();


};
