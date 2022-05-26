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

		sf::RectangleShape body;
		sf::Texture texture;

	public:
		Entity();
		Entity(int id, sf::Vector2f velocidade, float vMax, float vMin, float accel, 
			float dr, float grav, float vMaxY, sf::Vector2f size);
		~Entity();

		//accessors
		const sf::FloatRect getGlobalBounds() const;
		const sf::Vector2f getPosition() const;
		const sf::Vector2f getSize() const;
		//modifiers

		void move(float dirX, float dirY);
		//void setPosition(const float x, const float y);

		//virtual void update() = 0;
		//virtual void render() = 0;

		//virtual void run() = 0;
	};

}

