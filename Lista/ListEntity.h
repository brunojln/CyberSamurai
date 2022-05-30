#pragma once
#include "List.h"
#include "../Entidades/Entity.h"


class Entity;

namespace Lists {

	class ListEntity
	{
	private:
		List<Entities::Entity> lEntity;

	public:
		ListEntity(){};
		~ListEntity()
		{ 
			lEntity.clear();
		}

		void push_back(Entities::Entity* pEntity)
		{
			lEntity.push_back(pEntity);
		}

		void pop(unsigned int i)
		{
			lEntity.remove(i);
		}

		void EntityDelete(unsigned int i)
		{
			Entities::Entity* aux;
			aux = NULL;

			aux = lEntity.remove(i);

			delete(aux);
		}

		Entities::Entity* operator [](int i)
		{
			return lEntity[i];
		}

	};


}
