#include "Character.h"

Entities::Character::Character(entityID id):
	Entity(id)
{
	
}

Entities::Character::~Character()
{
}

const float Entities::Character::getLifePoints() const
{
	return lifePoints;
}

const int Entities::Character::getExp() const
{
	return exp;
}

bool Entities::Character::getIsAttacking()
{
	return isAttacking;
}

void Entities::Character::setIsNear(bool near)
{
	isNear = near;
}

void Entities::Character::setLifePoints(float hp)
{
	lifePoints = hp;
}

void Entities::Character::setExp(int xp)
{
	exp = xp;
}

void Entities::Character::updateCooldown()
{
	if (cooldown.getElapsedTime().asSeconds() >= atkCooldown)
	{
		canAttack = true;
		cooldown.restart();
	}
	//std::cout << cooldown.getElapsedTime().asSeconds() << "\n";
}

void Entities::Character::attack(Entities::Character* pCharacter, bool isNear)
{
	updateCooldown();
	if (isNear && canAttack && isAttacking)
	{
		//updateAnimation
		float newHP = pCharacter->getLifePoints() - this->atkDamage;
		pCharacter->setLifePoints(newHP);
		//std::cout << pCharacter->getLifePoints() << "\n";
		canAttack = false;
		//std::cout << "atk\n";
	}
	isAttacking = false;
	
}
