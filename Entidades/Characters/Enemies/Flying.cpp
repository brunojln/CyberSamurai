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
	atkDamage = 0.4f;
	atkCooldown = 3.0f;
	atkDistance = 2.0f; //talvez tirar isso
	canAttack = true;

	//physics
	velocityMax = 2.f;
	velocityMin = 1.f;
	acceleration = 1.f;
	drag = 0.9f;
	velocityMaxY = 0.f;
	
	std::cout << "flying criado\n";
}

Entities::Flying::Flying(float x, float y) :
	Enemy(entityID::flying)
{
	this->initFlying();
	body.setPosition(x, y);
}

Entities::Flying::~Flying()
{
}
