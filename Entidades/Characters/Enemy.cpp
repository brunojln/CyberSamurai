#include "Enemy.h"

Entities::Enemy::Enemy(entityID id) :
	Character(id)
{
	isAttacking = true;
}

Entities::Enemy::~Enemy()
{
}

void Entities::Enemy::followPlayer(Player* pPlayer)
{
	if (this->getPosition().x > pPlayer->getPosition().x)
	{
		body.move(-3, 0);
	}
	else
	{
		body.move(3, 0);
	}

	if (this->getPosition().y > pPlayer->getPosition().y)
	{
		body.move(0, -3);
	}
	else
	{
		body.move(0, 3);
	}
}

void Entities::Enemy::attackPlayer(Player* pPlayer, bool isNear)
{
	updateCooldown();
	if (isNear && canAttack)
	{
		//updateAnimation
		pPlayer->setLifePoints(pPlayer->getLifePoints() - this->atkDamage);
		canAttack = false;
	}
}

void Entities::Enemy::update(Player* pPlayer, bool isNear)
{
	this->followPlayer(pPlayer);
	this->attackPlayer(pPlayer, isNear);
	this->updatePhysics();
}

