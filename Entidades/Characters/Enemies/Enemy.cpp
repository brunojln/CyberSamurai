#include "Enemy.h"

Entities::Enemy::Enemy(entityID id) :
	Character(id)
{
	isAttacking = true;
}

Entities::Enemy::~Enemy()
{
}

void Entities::Enemy::setPlayer(Entities::Player* p)
{
	pPlayer = p;
}

void Entities::Enemy::followPlayer()
{
	if (this->getPosition().x > pPlayer->getPosition().x)
	{
		body.move(-1, 0);
	}
	else
	{
		body.move(1, 0);
	}

	if (this->getPosition().y > pPlayer->getPosition().y)
	{
		body.move(0, -1);
	}
	else
	{
		body.move(0, 1);
	}
}

void Entities::Enemy::attackPlayer()
{
	updateCooldown();
	if (isNear && canAttack && !pPlayer->getIsAttacking())
	{
		//updateAnimation
		pPlayer->setLifePoints(pPlayer->getLifePoints() - this->atkDamage);
		canAttack = false;
	}
}

void Entities::Enemy::update()
{
	this->followPlayer();
	this->attackPlayer();
	this->updatePhysics();
}

