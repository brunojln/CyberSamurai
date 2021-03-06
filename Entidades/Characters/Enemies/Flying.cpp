#include "Flying.h"

void Entities::Flying::initFlying()
{
	texture = pGraphic->loadTexture("InclusaoExterna/Imagens/Personagens/flying.png");
	body.setTexture(texture);
	currentFrame = sf::IntRect(0, 0, 120, 125);
	body.setTextureRect(currentFrame);

	body.setSize(sf::Vector2f(80.f, 80.f));

	//core
	lifePoints = 1.f;
	exp = 10;
	atkDamage = flyingDamage;
	atkCooldown = 3.0f;
	canAttack = true;

	//physics
	velocityMax = 3.f;
	velocityMin = 1.f;
	acceleration = 1.f;
	drag = 0.9f;
	velocityMaxY = 0.f;
	
	//std::cout << "flying criado\n";
}

Entities::Flying::Flying(float x, float y) :
	Enemy(entityID::flying), flyingDamage(0.2f)
{
	this->initFlying();
	body.setPosition(x, y);
}

Entities::Flying::~Flying()
{
}

void Entities::Flying::save()
{
	std::ofstream flyingFile;

	flyingFile.open("InclusaoExterna/Saves/flying.txt", std::ios::app);

	if (!flyingFile) { std::cout << "ERROR::FLYING::SAVE::Erro ao abrir arquivo"; exit(1); }

	flyingFile << getPosition().x << ' ' << getPosition().y << ' ' << getLifePoints() << ' ' << getPlayerIndex() << std::endl;
	flyingFile.close();
}

