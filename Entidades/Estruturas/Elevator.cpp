#include "Elevator.h"

void Entities::Elevator::initElevator()
{
	damaging = false;

	texture = pGraphic->loadTexture("InclusaoExterna/Imagens/Background/moonstone.jpg");

	defaultColor = sf::Color::Cyan;

	body.setTexture(texture);
	body.setFillColor(defaultColor);
	body.setSize(sf::Vector2f(100.f, 100.f));
	body.setScale(1.f, 0.15f);

	velocityMin = 1.f;
	velocityMaxY = 70.f;
	acceleration = 0.5f;
	drag = 0.7f;
	velocityMax = 6.f;


	//std::cout << "Elevator criado\n";
}

Entities::Elevator::Elevator(float x, float y) :
	Structures(entityID::elevator)
{	
	this->initElevator();
	body.setPosition(x, y);
}

Entities::Elevator::~Elevator()
{
}

void Entities::Elevator::updateMovement()
{
	this->velocity.y += 0.02 * GRAVITY;

	
	if (std::abs(this->velocity.y) > velocityMaxY) {
		this->velocity.y = velocityMaxY; 
	}

	//collision bottom screen
	if (this->getPosition().y + this->getGlobalBounds().height >= pGraphic->getWindow()->getSize().y)
	{
		velocity.y *= -1;
		body.setFillColor(defaultColor);
	}
	//collision top screen
	if (this->getPosition().y <= 0.f)
	{
		velocity.y *= 1;
		this->setPosition(this->getPosition().x, 0.f);
		body.setFillColor(sf::Color::Magenta);
	}
	
	this->body.move(this->velocity);
}

void Entities::Elevator::update()
{
	this->updateMovement();
}

void Entities::Elevator::save()
{
	std::ofstream elevatorFile;

	elevatorFile.open("InclusaoExterna/Saves/Elevator.txt", std::ios::app);

	if (!elevatorFile) { std::cout << "ERROR::ELEVATOR::SAVE::Erro ao abrir arquivo"; exit(1); }

	elevatorFile << getPosition().x << ' ' << getPosition().y << ' ' << std::endl;
	elevatorFile.close();
}
