#include "Platform.h"

void Platform::initTexture()
{
	if (!this->texture.loadFromFile("InclusaoExterna/Imagens/Background/moonstone.jpg"))
	{
		std::cout << "ERROR::PLATFORM::INITTEXTURE\n";
	}
}

void Platform::initSprite()
{
	this->sprite.setTexture(this->texture);
}

Platform::Platform(sf::Vector2f size, sf::Vector2f position)
{
	this->initTexture();
	this->initSprite(); //talvez tirar essa função

	sprite.setScale(size);
	sprite.setOrigin(size / 2.0f);
	sprite.setPosition(position);


	this->leftSide = sprite.getPosition().x;
	this->rightSide = sprite.getPosition().x + (sprite.getGlobalBounds().width * size.x);
	this->topSide = sprite.getPosition().y;
	this->bottomSide = sprite.getPosition().y + (sprite.getGlobalBounds().height * size.y);
}

Platform::~Platform()
{
}

const sf::FloatRect Platform::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Platform::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
