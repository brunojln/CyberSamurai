#include "Entity.h"

Entities::Entity::Entity(entityID id):
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
	this->velocity.x += dirX * this->acceleration;
	this->velocity.y += dirY * this->acceleration;

	///limit velocity
	if (std::abs(this->velocity.x) > this->velocityMax) {
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
	body.move(dirX, dirY);
}

void Entities::Entity::updatePhysics()
{
	this->velocity.y += GRAVITY;

	if (std::abs(this->velocity.y) > velocityMaxY) {
		this->velocity.y = velocityMaxY * ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}


	velocity *= drag;

	if (std::abs(this->velocity.x) < this->velocityMin)
		this->velocity.x = 0.f;
	if (std::abs(this->velocity.y) < this->velocityMin)
		this->velocity.y = 0.f;

	this->body.move(this->velocity);
}

void Entities::Entity::setPosition(const float x, const float y)
{
	this->body.setPosition(x, y);
}

void Entities::Entity::resetVelocityY()
{
	this->velocity.y = 0.0f;
}

void Entities::Entity::setCanJump(bool can_jump)
{
	canJump = can_jump;
}

void Entities::Entity::render()
{
	pGraphic->render(&body);
}

