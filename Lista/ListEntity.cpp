#include "ListEntity.h"


Lists::ListEntity::ListEntity() 
{

}
Lists::ListEntity::~ListEntity() 
{
	lEntity.clear();
}

void Lists::ListEntity::push_back(Entities::Entity* pEntity)
{
	lEntity.insert(pEntity);
}


void Lists::ListEntity::remove(unsigned int i)
{
	lEntity.remove(i);
}

Entity* Lists::ListEntity::operator [](const int i)
{
	return (Entity*)lEntity.operator[](i);
}