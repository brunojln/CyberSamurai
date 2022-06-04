#include "Structures.h"

Entities::Structures::Structures(entityID id) :
	Entity(id)
{
	damaging = true; //mudar isso
}

Entities::Structures::~Structures()
{
}

float Entities::Structures::getStructureDamage()
{
	return structureDamage;
}

bool Entities::Structures::isDamaging()
{
	return damaging;
}
