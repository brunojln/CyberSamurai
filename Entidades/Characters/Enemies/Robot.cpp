#include "Robot.h"

void Entities::Robot::initRobot()
{
	texture = pGraphic->loadTexture("InclusaoExterna/Imagens/Personagens/robot.png");

	body.setTexture(texture);
	currentFrame = sf::IntRect(0, 0, 125, 100);

	body.setTextureRect(currentFrame);
	body.setSize(sf::Vector2f(80.f, 80.f));
		
	lifePoints = 4.f;
	exp = 20; 
	atkDamage = robotDamage;
	atkCooldown = 5.0f;

	velocityMax = 2.f;
	velocityMin = 1.f;
	acceleration = 1.f;
	drag = 0.9f;
	velocityMaxY = 50.f;
	canAttack = false;

	//std::cout << "Robot criado\n";
}

Entities::Robot::Robot(float x, float y, bool isGolden):
	Enemy(entityID::robot), robotDamage(0.1f)
{
	this->initRobot();
	body.setPosition(x, y);

	this->isGolden = isGolden;
	if (isGolden) {
		body.setFillColor(sf::Color::Yellow);
	}
}

Entities::Robot::~Robot()
{
}

void Entities::Robot::save()
{
	std::ofstream robotFile;
	
	robotFile.open("InclusaoExterna/Saves/Robot.txt", std::ios::app);

	if (!robotFile) { std::cout << "ERROR::ROBOT::SAVE::Erro ao abrir arquivo"; exit(1); }

	robotFile << getPosition().x << ' ' << getPosition().y << ' ' << getLifePoints() << ' ' << getPlayerIndex() << ' ' << isGolden <<std::endl;
	robotFile.close();

}
