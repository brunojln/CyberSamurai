#include "Spikes.h"

void Entities::Spikes::initSpikes()
{
	damaging = true;
	structureDamage = 0.01f;

	texture = new sf::Texture();
	if (!texture->loadFromFile("InclusaoExterna/Imagens/Background/spikes.png"))
	{
		std::cout << "ERROR::SPIKES::initSpikes::Failed to load texture image\n";
	}
	body.setTexture(texture);
	body.setSize(sf::Vector2f(100.f, 100.f));

	velocityMin = 1.f;
	velocityMaxY = 1.f;
	acceleration = 1.f;
	drag = 0.9f;
	velocityMax = 6.f;

	std::cout << "Spikes criado\n";
}

Entities::Spikes::Spikes(float x, float y):
	Structures(entityID::spikes)
{
	this->initSpikes();
	body.setPosition(x, y);
}

Entities::Spikes::~Spikes()
{
	delete texture;
}

void Entities::Spikes::update()
{
	//coisas com dano ao jogador
}
