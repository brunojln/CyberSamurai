#include "ListEntity.h"


namespace Lists{

	ListEntity::ListEntity(){
		lEntity.clear();
	}
	ListEntity::~ListEntity()
	{
		//lEntity.clear();
	}

	void ListEntity::push_back(Entities::Entity* pEntity)
	{
		lEntity.push_back(pEntity);
	}

	void ListEntity::pop(unsigned int i)
	{
		lEntity.remove(i);
	}

	void ListEntity::EntityDelete(unsigned int i)
	{
		Entities::Entity* aux;
		aux = NULL;

		aux = lEntity.remove(i);

		delete(aux);
	}


	Entities::Entity* ListEntity::operator [](int i)
	{
		return lEntity[i];
	}

}
