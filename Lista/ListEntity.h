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
		ListEntity();
		~ListEntity();

		void push_back(Entities::Entity* pEntity);

		void pop(unsigned int i);

		void EntityDelete(unsigned int i);

		Entities::Entity* operator[](int i);

	};


}
