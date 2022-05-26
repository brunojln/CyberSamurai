#include "Entity.h"

Entities::Entity::Entity()
{
}

Entities::Entity::Entity(int id, sf::Vector2f velocidade, float vMax, float vMin, float accel,
	float dr, float grav, float vMaxY, sf::Vector2f size):
	Ente(id)
{
	velocity = velocidade;
	velocityMax = vMax;
	velocityMin = vMin;
	acceleration = accel;
	drag = dr;
	gravity = grav;
	velocityMaxY = vMaxY;


	body.setSize(size);

}

Entities::Entity::~Entity()
{
}

const sf::FloatRect Entities::Entity::getGlobalBounds() const
{
	return body.getGlobalBounds();
}

const sf::Vector2f Entities::Entity::getPosition() const
{
	return body.getPosition();
}

const sf::Vector2f Entities::Entity::getSize() const
{
	return body.getSize();
}

void Entities::Entity::move(float dirX, float dirY)
{
	body.move(dirX, dirY);
}

