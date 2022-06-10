#include "Spikes.h"

void Entities::Spikes::initSpikes()
{
	damaging = true;
	structureDamage = 0.01f;

	texture = pGraphic->loadTexture("InclusaoExterna/Imagens/Background/spikes.png");

	body.setTexture(texture);
	body.setSize(sf::Vector2f(100.f, 100.f));
	body.setFillColor(sf::Color::Yellow);

	velocityMin = 0.f;
	velocityMaxY = 0.f;
	acceleration = 0.f;
	drag = 0.f;
	velocityMax = 0.f;
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
	updatePhysics();
}

void Entities::Spikes::save()
{
	std::ofstream spikesFile;

	spikesFile.open("InclusaoExterna/Saves/Spikes.txt", std::ios::app);

	if (!spikesFile) { std::cout << "ERROR::BOSS::SAVE::Erro ao abrir arquivo"; exit(1); }

	spikesFile << getPosition().x << ' ' << getPosition().y  << ' ' << std::endl;
	spikesFile.close();
}
