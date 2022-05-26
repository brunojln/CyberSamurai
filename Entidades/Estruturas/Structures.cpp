#include "Structures.h"

Entities::Structures::Structures(bool dmg, int id, sf::Vector2f velocidade, float vMax, 
	float vMin, float accel, float dr, float grav, float vMaxY, sf::Vector2f size) : 
	
	Entity(id, velocidade, vMax, vMin, accel, dr, grav, vMaxY, size)
{
	damaging = dmg;
}

Entities::Structures::~Structures()
{
}
