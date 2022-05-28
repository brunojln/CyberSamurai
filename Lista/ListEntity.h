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
			lEntity.insert(pEntity);
		}

		void remove(unsigned int i)
		{
			lEntity.remove(i);
		}

		Entities::Entity* operator [](int i)
		{
			return (Entities::Entity*)(lEntity.operator[](i));
		}

	};


}
