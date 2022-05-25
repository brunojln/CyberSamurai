#include "Entity.h"

Entities::Entity::Entity()
{
}

Entities::Entity::Entity(int id, sf::Vector2f velocidade, float vMax, float vMin, float accel,
	float dr, float grav, float vMaxY):
	Ente(id)
{
	velocity = velocidade;
	velocityMax = vMax;
	velocityMin = vMin;
	acceleration = accel;
	drag = dr;
	gravity = grav;
	velocityMaxY = vMaxY;
}

Entities::Entity::~Entity()
{
}

const sf::FloatRect Entities::Entity::getGlobalBounds() const
{
	return sprite.getGlobalBounds();
}

const sf::Vector2f Entities::Entity::getPosition() const
{
	return sprite.getPosition();
}
