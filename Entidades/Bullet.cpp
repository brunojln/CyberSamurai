#include "Bullet.h"

void Entities::Bullet::initBullet()
{
	body.setSize(sf::Vector2f(20.f, 20.f));
	body.setFillColor(sf::Color::Yellow);
	//core
	lifePoints = 0.1f;
	exp = 0;
	atkDamage = 0.2f;
	atkCooldown = 3.0f;
	atkDistance = 2.0f; //talvez tirar isso
	canAttack = true;

	//physics
	velocityMax = 1.f;
	velocityMin = 1.f;
	acceleration = 3.f;
	drag = 0.9f;
	velocityMaxY = 0.f;
}

Entities::Bullet::Bullet(float pos_x, float pos_y, float dir_x, float dir_y):
	Enemy(entityID::unknown)
{
	this->initBullet();
	body.setPosition(pos_x, pos_y);
	direction.x = dir_x;
	direction.y = dir_y;
}

Entities::Bullet::~Bullet()
{
}

void Entities::Bullet::shoot()
{
	body.move(acceleration * direction);
}	

/*void Entities::Bullet::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets) {
		bullet->update();

		//bullet culling (top of the screen)
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;

			//std::cout << this->bullets.size() << "\n";
		}

		++counter;
	}


}*/
