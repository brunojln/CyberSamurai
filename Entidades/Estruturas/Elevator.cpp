#include "Elevator.h"

void Entities::Elevator::initElevator()
{
	damaging = false;

	texture = new sf::Texture();
	if (!texture->loadFromFile("InclusaoExterna/Imagens/Background/moonstone.jpg"))
	{
		std::cout << "ERROR::Elevator::initElevator::Failed to load texture image\n";
	}
	body.setTexture(texture);
	body.setFillColor(sf::Color::Cyan);
	body.setSize(sf::Vector2f(150.f, 100.f));

	velocityMin = 1.f;
	velocityMaxY = 70.f;
	acceleration = 0.5f;
	drag = 0.7f;
	velocityMax = 6.f;

	std::cout << "Elevator criado\n";
}

Entities::Elevator::Elevator(float x, float y) :
	Structures(entityID::elevator)
{	
	this->initElevator();
	body.setPosition(x, y);
}

Entities::Elevator::~Elevator()
{
	delete texture;
}

void Entities::Elevator::updateMovement()
{
	this->velocity.y += 0.02 * GRAVITY;

	//collision bottom screen
	if (std::abs(this->velocity.y) > velocityMaxY) {
		this->velocity.y = velocityMaxY; //* ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}
	if (this->getPosition().y + this->getGlobalBounds().height >= pGraphic->getWindow()->getSize().y)
	{
		velocity.y *= -1;

	}
	//collision top screen
	if (this->getPosition().y <= 0.f)
	{
		velocity.y *= 1;
		this->setPosition(this->getPosition().x, 0.f);
	}
	
	this->body.move(this->velocity);
}

void Entities::Elevator::update()
{
	this->updateMovement();
}
