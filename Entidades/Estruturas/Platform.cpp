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
	body.setSize(sf::Vector2f(100.f, 100.f));
	body.setScale(1.f, 0.2f);

	velocityMin = 1.f;
	velocityMaxY = 1.f;
	acceleration = 1.f;
	drag = 0.9f;
	velocityMax = 6.f;
	std::cout << "Plataforma criada\n";
}

Entities::Platform::Platform(float x, float y) :
	Structures(entityID::platform)
{
	this->initPlatform();
	body.setPosition(x, y);
}

Entities::Platform::~Platform()
{
	delete texture;
}
void Entities::Platform::update()
{
	this->updatePhysics();
}
/*
void Entities::Platform::render(sf::RenderTarget& target)
{
	target.draw(body);
}
*/