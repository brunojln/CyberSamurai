#pragma once
#include "../Includes/stdafx.h"

//Referência [5]
namespace Lists 
{

	template<class ListType>

	class List 
	{
	private:

		template<class NodeType>
		class Node 
		{

		private:
			NodeType* pInfo;
			Node<NodeType>* pNext;

		public:

			//Erros na implementacao em arquivos separados
			Node() : pNext{ NULL }, pInfo{NULL} {}
			~Node(){}

			NodeType* getInfo() { return pInfo; }
			void setInfo(NodeType* info) { pInfo = info;  }

			Node<NodeType>* getpNext() { return pNext; }
			void setpNext(Node<NodeType>* Next) { pNext = Next; }
		};
		
	Node<ListType>* pStart;
	Node<ListType>* pEnd;
	int size;

	public:
		List();
		~List();

		void insert(Node<ListType>* pNode);
		void push_back(ListType* pInfo);	
		ListType* remove(const int pos);

		void clear();
		int getSize();

		ListType* getFrist();
		ListType* getLast();
	
		// ListType* operator ++(Node<ListType>* pN);
		ListType* operator [](const int i);
	};

	template<class ListType>
	List<ListType>::List() : pStart{ NULL }, pEnd{ NULL }, size{ 0 } {}

	template<class ListType>
	List<ListType>::~List()
	{
		pStart = NULL;
		pEnd = NULL;
	}

	template<class ListType>
	void List<ListType>::insert(Node<ListType>* pNode)
	{
		//Se for o primeiro elemento
		if (pStart == NULL)
		{
			pStart = pNode;
			pEnd = pNode;
		}
		else
		{
			pEnd->setpNext(pNode);
			pEnd = pNode;
		}

		size++;
	}

	template<class ListType>
	void List<ListType>::push_back(ListType* pInfo)
	{
		Node<ListType>* pNew = NULL;
		pNew = new Node<ListType>(); //()
		pNew->setInfo(pInfo);
		insert(pNew);
	}

	template<class ListType>
	ListType* List<ListType>::remove(const int pos)
	{
		if (pos < 0 || pos > size + 1)
		{
			std::cout << "ERROR::LIST.CPP::REMOVE OUT OF RANGE" << std::endl;
			exit(1);
		}

		Node<ListType>* aux = NULL;
		Node<ListType>* aux2 = NULL;
		aux = pStart;

		for (int i = 0; i < pos; i++)
		{
			aux2 = aux;
			aux = aux->getpNext();
		}

		//Se o que se deseja remover for o primeiro
		if (aux = pStart)
		{
			pStart = aux->getpNext();
		}
		else if (aux = pEnd)
		{
			pEnd = aux2;
			aux2->setpNext(NULL);
		}
		else
		{
			aux2->setpNext(aux->getpNext());
		}

		ListType* auxInfo = aux->getInfo();

		delete(aux);
		size--;

		return auxInfo;

	}

	template<class ListType>
	void List<ListType>::clear()
	{
		Node<ListType>* aux1; 
		Node<ListType>* aux2;

		aux1 = pStart;
		aux2 = aux1;
		int i = 0;

		while (aux1 != NULL && i < size)
		{
			delete(aux1->getInfo());
			aux2 = aux1->getpNext();

			delete(aux1);
			aux1 = aux2;

			i++;
		}

		pStart = NULL; pEnd = NULL; size = 0;
	}

	template<class ListType>
	int List<ListType>::getSize() { return size; }

	template<class ListType>
	ListType* List<ListType>::getFrist()
	{
		return pStart;
	}

	template<class ListType>
	ListType* List<ListType>::getLast()
	{
		return pEnd;
	}

	/*
	template<class ListType>
	ListType* List<ListType>::operator ++(Node<ListType>* pN)
	{
		pN->getpNext();
		return pN->getInfo();
	}*/

	template<class ListType>
	ListType* List<ListType>::operator [](const int i)
	{
		if (i < 0 || i > size + 1)
		{
			std::cout << "ERROR::LIST.CPP::OPERATOR[] OUT OF RANGE" << std::endl;
			exit(1);
		}


		Node<ListType>* aux;
		aux = pStart;

		for (int c = 0; c < i; c++)
		{
			aux = aux->getpNext();
		}

		return aux->getInfo();

	}

}
