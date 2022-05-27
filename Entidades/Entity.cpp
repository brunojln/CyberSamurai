#include "Entity.h"

Entities::Entity::Entity()
{
}

Entities::Entity::Entity(int id):
	Ente(id)
{
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
	body.move(dirX * velocity.x, dirY * velocity.y);
}

