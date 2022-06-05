#include "Spikes.h"

void Entities::Spikes::initSpikes()
{
	damaging = true;
	structureDamage = 0.01f;

	texture = pGraphic->loadTexture("InclusaoExterna/Imagens/Background/spikes.png");

	body.setTexture(texture);
	body.setSize(sf::Vector2f(100.f, 100.f));

	velocityMin = 1.f;
	velocityMaxY = 1.f;
	acceleration = 1.f;
	drag = 0.9f;
	velocityMax = 6.f;

	//std::cout << "Spikes criado\n";
}

Entities::Spikes::Spikes(float x, float y):
	Structures(entityID::spikes)
{
	this->initSpikes();
	body.setPosition(x, y);
}

Entities::Spikes::~Spikes()
{
}

void Entities::Spikes::update()
{
}
