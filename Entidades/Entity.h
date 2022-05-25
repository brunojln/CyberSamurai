#pragma once
#include "../Ente.h"
#include "SFML/Graphics.hpp"

namespace Entities {

	class Entity : public Ente
	{
	protected:
		//física
		sf::Vector2f velocity;
		float velocityMax;
		float velocityMin;
		float acceleration;
		float drag;
		float gravity;
		float velocityMaxY;

		sf::Sprite sprite;
		sf::Texture texture;

	public:
		Entity();
		Entity(int id, sf::Vector2f velocidade, float vMax, float vMin, float accel, 
			float dr, float grav, float vMaxY);
		~Entity();

		//set e get coordenadas(?)
		//int getX();
		//int getY();

		//accessors
		const sf::FloatRect getGlobalBounds() const;
		const sf::Vector2f getPosition() const;

		//modifiers
		//void setPosition(const float x, const float y);

		//virtual void update() = 0;
		//virtual void render() = 0;

		//virtual void run() = 0;
	};

}

