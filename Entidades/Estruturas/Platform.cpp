#include "Platform.h"

void Entities::Platform::initPlatform() 
{
	damaging = false;

	texture = pGraphic->loadTexture("InclusaoExterna/Imagens/Background/moonstone.jpg");

	body.setTexture(texture);
	body.setFillColor(sf::Color(50, 50, 300));
	body.setSize(sf::Vector2f(100.f, 100.f));
	body.setScale(1.f, 0.2f);

	velocityMin = 0.f;
	velocityMaxY = 0.f;
	acceleration = 0.f;
	drag = 0.f;
	velocityMax = 0.f;

}

Entities::Platform::Platform(float x, float y) :
	Structures(entityID::platform)
{
	this->initPlatform();
	body.setPosition(x, y);
}

Entities::Platform::~Platform()
{
}
void Entities::Platform::update()
{
	this->updatePhysics();
}
