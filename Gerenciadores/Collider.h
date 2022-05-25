#pragma once
#include "SFML/Graphics.hpp"

class Collider
{

public:

	bool checkCollision(sf::RectangleShape other, sf::Sprite body);
};

