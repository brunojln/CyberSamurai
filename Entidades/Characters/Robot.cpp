#include "Robot.h"

void Entities::Robot::initRobot()
{
	texture = new sf::Texture();
	if (!texture->loadFromFile("InclusaoExterna/Imagens/Personagens/robot.png"))
	{
		std::cout << "ERROR::Robot::initRobot::Failed to load texture image\n";
	}
	body.setTexture(texture);
	currentFrame = sf::IntRect(0, 0, 125, 100);
	//body.setFillColor(sf::Color::Yellow);
	body.setTextureRect(currentFrame);
	body.setSize(sf::Vector2f(80.f, 80.f));

	lifePoints = 4;
	exp = 20; 
	atkDamage = 1.0f;
	atkCooldown = 5.0f;
	atkDistance = 2.0f;

	velocityMax = 5.f;
	velocityMin = 1.f;
	acceleration = 1.f;
	drag = 0.9f;
	velocityMaxY = 50.f;
	canAttack = false;

	std::cout << "Robot criado\n";
}

Entities::Robot::Robot(float x, float y):
	Enemy(entityID::robot)
{
	this->initRobot();
	body.setPosition(x, y);
}

Entities::Robot::~Robot()
{
	delete texture;
}
