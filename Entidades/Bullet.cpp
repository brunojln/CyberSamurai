#include "Bullet.h"

void Entities::Bullet::initBullet()
{
	texture = pGraphic->loadTexture("InclusaoExterna/Imagens/Background/bullet.png");
	body.setTexture(texture);
	body.setSize(sf::Vector2f(40.f, 10.f));

	//physics
	velocityMax = 1.f;
	velocityMin = 1.f;
	acceleration = 5.f;
	drag = 0.9f;
	velocityMaxY = 0.f;
}

Entities::Bullet::Bullet(float pos_x, float pos_y, float dir_x, float dir_y):
	Entity(0)
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
void Entities::Bullet::update()
{
	this->shoot();
}


