#pragma once
#include "../Includes/stdafx.h"

namespace Lists 
{

	template<class type>

		class List 
		{
		private:

			class Node 
			{

			private:
				type* info;
				Node* pNext;
				int size;

			public:

				Node(type* Info = NULL, Node* Prox = NULL, int Size = 0);
				~Node();

				type* getInfo() { return info; }
				void setInfo(type* Info) { info = Info; size++; }

				Node* getProx() { return pNext; }
				void setProx(Node* Prox) { pNext = Prox; size++; }

				int getSize(){ return size; };
		};

	Node* inicio;
	Node* fim;
	Node* atual;

	public:
	List();
	~List();

	void insert(type* Info);
	void remove(const int pos);

	void clear();
	type* voltarInicio();
	type* irProximo();
	
	type* operator ++();
	type* operator [](const int i);

	};

}
