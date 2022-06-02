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
	atkDamage = 0.1f;
	atkCooldown = 1.2f;
	atkDistance = 2.0f;

	velocityMax = 2.f;
	velocityMin = 1.f;
	acceleration = 1.f;
	drag = 0.9f;
	velocityMaxY = 50.f;
	canAttack = false;

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
	updateCooldown();
	if (canAttack)
	{
		bullets.push_back(new Bullet(this->getPosition().x + 50.f, (this->getPosition().y + 50.f), 1.f, 0.f));
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


void Entities::Boss::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets) {
		bullet->shoot();
		canAttack = false;
		/*bullet culling(left-side of the screen)*/
		if (bullet->getGlobalBounds().left + bullet->getGlobalBounds().width < 0.f)
		{
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		//std::cout << this->bullets.size() << "\n";
		++counter;
	}

}