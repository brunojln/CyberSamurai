#include "Collider.h"

Collider::Collider(sf::Sprite& body) :
	body(body)
{
}

Collider::~Collider()
{
}

void Collider::move(float delta_x, float delta_y)
{
	this->body.move(delta_x, delta_y);
}

bool Collider::checkCollision(Collider& other, float push)
{
	sf::Vector2f otherPosition = other.getPosition();
	sf::Vector2f otherHalfSize = other.getHalfSize();
	sf::Vector2f thisPosition = this->getPosition();
	sf::Vector2f thisHalfSize = this->getHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (thisHalfSize.x + otherHalfSize.x);
	float intersectY = abs(deltaY) - (thisHalfSize.y + otherHalfSize.y);
	
	if (intersectX < 0.0f && intersectY < 0.0f) {

		if (abs(intersectX) < abs(intersectY))
		{
			if (deltaX > 0.0f) {
				this->move(intersectX, 0.0f);
				other.move(-intersectX, 0.0f);
			}
			else {
				this->move(-intersectX, 0.0f);
				other.move(intersectX, 0.0f);
			}
		}
		else {
			if (deltaY > 0.0f) {
				this->move(0.0f, intersectY);
				other.move(0.0f, -intersectY);
			}
			else {
				this->move(0.0f, -intersectY);
				other.move(0.0f, intersectY);
			}
		}

		return true;
	}
	return false;
}

sf::Vector2f Collider::getPosition()
{
	return this->body.getPosition();
}

sf::Vector2f Collider::getHalfSize()
{
	return this->body.getPosition() / 2.0f;
}
