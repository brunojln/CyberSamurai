#include "Collider.h"

namespace Managers {

	Collider::Collider()
	{
	}

	Collider::~Collider()
	{
	}


	bool Collider::checkCollision(Entities::Entity* other, Entities::Player* body, float push, bool cross)
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
			if (cross) { return true;  }
			push = std::min(std::max(push, 0.0f), 1.0f);

			if (intersectX > intersectY)
			{
				if (deltaX > 0.0f) {
					body->move(intersectX * (1.0f - push), 0.0f);
					other->move(-intersectX * push, 0.0f);
				}
				else {
					body->move(-intersectX * (1.0f - push), 0.0f);
					other->move(intersectX * push, 0.0f); 
				}
			}
			else {
				body->setCanJump(true);
				if (deltaY > 0.0f) {
					body->move(0.0f, intersectY * (1.0f - push));
					other->move(0.0f, -intersectY * push);
				}
				else {
					body->move(0.0f, -intersectY * (1.0f - push));
					other->move(0.0f, intersectY * push);
				}
			}
			//std::cout << "true\n";
			isColliding = true;
			return isColliding;
		}
		//std::cout << "false\n";
		isColliding = false;
		return isColliding;
	}
}


