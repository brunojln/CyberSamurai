#include "Platform.h"

Entities::Platform::Platform(bool dmg, int id, sf::Vector2f velocidade, float vMax,
	float vMin, float accel, float dr, float grav, float vMaxY, sf::Vector2f size) :

	Structures(dmg, id, velocidade, vMax, vMin, accel, dr, grav, vMaxY, size)
{

}

Entities::Platform::~Platform()
{
}

void Entities::Platform::render(sf::RenderTarget& target)
{
	target.draw(body);
}
