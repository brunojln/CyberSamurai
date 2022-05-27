#include "Character.h"

Entities::Character::Character():
	Entity()
{
	
}

Entities::Character::~Character()
{
}

const int Entities::Character::getLifePoints() const
{
	return lifePoints;
}

const int Entities::Character::getExp() const
{
	return exp;
}

void Entities::Character::setLifePoints(int hp)
{
	lifePoints = hp;
}

void Entities::Character::setExp(int xp)
{
	exp = xp;
}
