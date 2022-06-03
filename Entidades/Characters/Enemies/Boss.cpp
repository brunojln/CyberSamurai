#include "Boss.h"

void Entities::Boss::initBoss()
{
	texture = pGraphic->loadTexture("InclusaoExterna/Imagens/Personagens/boss.png");
	body.setTexture(texture);
	currentFrame = sf::IntRect(0, 0, 40, 50);
	body.setTextureRect(currentFrame);

	body.setSize(sf::Vector2f(95.f, 120.f));
	body.setFillColor(sf::Color::Magenta);

	lifePoints = 10.f;
	exp = 100;
	atkDamage = 0.5f;
	atkCooldown = 1.2f;

	velocityMax = 2.f;
	velocityMin = 1.f;
	acceleration = 1.f;
	drag = 0.9f;
	velocityMaxY = 50.f;
	canAttack = false;

	direction = 1.f;
	std::cout << "Boss criado\n";
}

Entities::Boss::Boss(float x, float y) :
	Enemy(entityID::boss)
{
	this->initBoss();
	body.setPosition(x, y);
}

Entities::Boss::~Boss()
{
}

void Entities::Boss::update()
{
	updateMovement();
	updateCooldown();
	if (canAttack)
	{
		if (direction > 0) {
			bullets.push_back(new Bullet(this->body.getPosition().x + 50.f, (this->body.getPosition().y + 50.f), direction, 0.f));
		}
		else
		{
			bullets.push_back(new Bullet(this->body.getPosition().x - 50.f, (this->body.getPosition().y + 50.f), direction, 0.f));
		}
		
		//std::cout << bullets.size() << "\n";
	}
	updateBullets();
	updatePhysics();
}

void Entities::Boss::render()
{
	pGraphic->render(&body);
	for (auto* bullet : this->bullets) {
		pGraphic->render(bullet->getBody());
	}
}

void Entities::Boss::updateMovement()
{
	if (this->getPosition().x > this->getPlayer()->getPosition().x)
	{
		body.move(-1, 0);
		body.setScale(-1.f, 1.f);
		this->body.setOrigin(this->body.getGlobalBounds().width / 2.5f, 0.f);
		direction = -1.f;
	}
	else
	{
		body.move(1, 0);
		body.setScale(1.f, 1.f);
		this->body.setOrigin(0.f, 0.f);
		direction = 1.f;
	}

	if (this->getPosition().y > this->getPlayer()->getPosition().y)
	{
		body.move(0, -1);
	}
	else
	{
		body.move(0, 1);
	}
}


void Entities::Boss::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets) {
		bullet->shoot();
		canAttack = false;
		/*bullet culling(left-side of the screen)*/
		if (bullet->getGlobalBounds().left + bullet->getGlobalBounds().width < 0.f
			|| bullet->getGlobalBounds().left + bullet->getGlobalBounds().width > 1720.f)
		{
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		
		if (collider.checkCollision(bullet, this->getPlayer(), 1.f, true))
		{
			this->getPlayer()->setLifePoints(this->getPlayer()->getLifePoints() - atkDamage);
			this->getPlayer()->setisTakingDamage(true);
		}
		//std::cout << this->bullets.size() << "\n";
		++counter;
	}

}