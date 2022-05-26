#include "Collider.h"

namespace Managers {

	Collider::Collider()
	{
	}

	Collider::~Collider()
	{
	}


	bool Collider::checkCollision(Entities::Platform* other, Entities::Player* body, float push)
	{
		sf::Vector2f otherPosition = other->getPosition();
		sf::Vector2f otherHalfSize = other->getSize() / 2.0f;

		sf::Vector2f thisPosition = body->getPosition();
		sf::Vector2f thisHalfSize = body->getSize() / 2.0f;

		float deltaX = otherPosition.x - thisPosition.x;
		float deltaY = otherPosition.y - thisPosition.y;

		float intersectX = abs(deltaX) - (thisHalfSize.x + otherHalfSize.x);
		float intersectY = abs(deltaY) - (thisHalfSize.y + otherHalfSize.y);
    
		if (intersectX < 0.0f && intersectY < 0.0f) {

			push = std::min(std::max(push, 0.0f), 1.0f);

			if (intersectX > intersectY)
			{
				if (deltaX > 0.0f) {
					body->move(intersectX * (1.0f - push), 0.0f);
					other->move(-intersectX, 0.0f);
				}
				else {
					body->move(-intersectX * (1.0f - push), 0.0f);
					other->move(intersectX, 0.0f);
				}
			}
			else {
				if (deltaY > 0.0f) {
					body->move(0.0f, intersectY * (1.0f - push));
					other->move(0.0f, -intersectY);
				}
				else {
					body->move(0.0f, -intersectY * (1.0f - push));
					other->move(0.0f, intersectY);
				}
			}
			cout << "true\n";
			return true;
		}
		cout << "false\n";
		return false;
	}
}


