#include "Platform.h"

void Entities::Platform::initPlatform() 
{
	damaging = false;

	texture = pGraphic->loadTexture("InclusaoExterna/Imagens/Background/moonstone.jpg");

	body.setTexture(texture);
	body.setFillColor(sf::Color::Green);
	body.setSize(sf::Vector2f(100.f, 100.f));
	body.setScale(1.f, 0.2f);

	velocityMin = 0.f;
	velocityMaxY = velocityY;
	acceleration = 0.f;
	drag = 0.f;
	velocityMax = 0.f;

}

Entities::Platform::Platform(float x, float y) :
	Structures(entityID::platform), velocityY(0.f)
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

void Entities::Platform::save()
{
	std::ofstream platformFile;

	platformFile.open("InclusaoExterna/Saves/Platform.txt", std::ios::app);

	if (!platformFile) { std::cout << "ERROR::PLATFORM::SAVE::Erro ao abrir arquivo"; exit(1); }

	platformFile << getPosition().x << ' ' << getPosition().y <<  ' ' << std::endl;
	platformFile.close();
}
