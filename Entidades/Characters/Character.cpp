#include "Character.h"

Entities::Character::Character(entityID id):
	Entity(id)
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
	/*if (pCharacter->getID() == entityID::robot)
	{
		Entities::Robot
	}*/
	updateCooldown();
	if (isNear && canAttack && isAttacking)
	{
		//updateAnimation
		float newHP = pCharacter->getLifePoints() - this->atkDamage;
		pCharacter->setLifePoints(newHP);
		std::cout << pCharacter->getLifePoints() << "\n";
		canAttack = false;
		//std::cout << "atk\n";
	}
	isAttacking = false;
	
}
