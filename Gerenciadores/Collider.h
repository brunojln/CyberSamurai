#pragma once
#include <SFML/Graphics.hpp>
 
class Collider
{
private:
	sf::Sprite& body;

public:
	Collider(sf::Sprite& body);
	~Collider();

	void move(float delta_x, float delta_y);

	bool checkCollision(Collider& other, float push);
	sf::Vector2f getPosition();
	sf::Vector2f getHalfSize();
};

