#pragma once
#include "List.h"
#include "../Entidades/Entity.h"

namespace Lists {

	class ListEntity
	{
	private:
		List<Entities::Entity> lEntity;

	public:
		ListEntity();
		~ListEntity();

		void push_back(Entities::Entity* pEntity);
		void remove(Entities::Entity* pEntity);
		void remove(unsigned int i);
	};


}
