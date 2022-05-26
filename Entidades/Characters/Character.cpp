#include "Character.h"

Entities::Character::Character(const float atkCd, const float atkDis): Entity(),
	atkCooldown(atkCd), atkDistance(atkDis)
{
}

Entities::Character::Character(int hp, int xp, int atkDmg, const float atkCd, const float atkDis,
	int id, sf::Vector2f velocidade, float vMax, float vMin, float accel, float dr, float grav, float vMaxY, sf::Vector2f size):

	Entity(id, velocidade, vMax, vMin, accel, dr, grav, vMaxY, size),
	atkCooldown(atkCd), atkDistance(atkDis)
{
	lifePoints = hp;
	exp = xp;
	atkDamage = atkDmg;
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
