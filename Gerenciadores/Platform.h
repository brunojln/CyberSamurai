#pragma once
#include <SFML/Graphics.hpp>
#include "../Gerenciadores/Collider.h"
class Platform
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	int topSide;
	int bottomSide;
	int leftSide;
	int rightSide;

	void initTexture();
	void initSprite();

public:
	Platform(sf::Vector2f size, sf::Vector2f position);
	~Platform();

	const sf::FloatRect getGlobalBounds() const;

	void render(sf::RenderTarget& target);
	Collider getCollider();
};

