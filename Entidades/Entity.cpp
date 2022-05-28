#include "Entity.h"

Entities::Entity::Entity():
	pGraphic(Managers::GraphicManager::getGraphics())
{
}

Entities::Entity::Entity(int id):
	Ente(id), pGraphic(Managers::GraphicManager::getGraphics())
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

sf::RectangleShape* Entities::Entity::getBody()
{
	return &body;
}

void Entities::Entity::move(float dirX, float dirY)
{
	body.move(dirX * velocity.x, dirY * velocity.y);
}

void Entities::Entity::render()
{
	pGraphic->render(&body);
}

