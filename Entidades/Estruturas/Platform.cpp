#include "Platform.h"

void Entities::Platform::initPlatform() 
{
	damaging = false;

	texture = new sf::Texture();

	if (!texture->loadFromFile("InclusaoExterna/Imagens/Background/moonstone.jpg"))
	{
		std::cout << "ERROR::Platform::initPlatform::unable to open texture file\n";
	}

	body.setTexture(texture);
	body.setFillColor(sf::Color(50, 50, 300));
	body.setPosition(50, 50);
	body.setSize(sf::Vector2f(100.f, 100.f));

	std::cout << "Plataforma criada\n";
}

Entities::Platform::Platform() :
	Structures()
{
	this->initPlatform();
}

Entities::Platform::~Platform()
{
	delete texture;
}
/*
void Entities::Platform::render(sf::RenderTarget& target)
{
	target.draw(body);
}
*/