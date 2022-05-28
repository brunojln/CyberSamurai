#include "Spikes.h"

void Entities::Spikes::initSpikes()
{
	damaging = true;

	texture = new sf::Texture();
	if (!texture->loadFromFile("InclusaoExterna/Imagens/Background/moonstone.jpg"))
	{
		std::cout << "ERROR::SPIKES::initSpikes::Failed to load texture image\n";
	}
	body.setTexture(texture);
	body.setFillColor(sf::Color(100, 250, 50));
	body.setSize(sf::Vector2f(100.f, 100.f));

	std::cout << "Spikes criado\n";
}

Entities::Spikes::Spikes():
	Structures()
{
	this->initSpikes();
}

Entities::Spikes::~Spikes()
{
	delete texture;
}
