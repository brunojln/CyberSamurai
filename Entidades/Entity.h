#pragma once
#include "../Ente.h"
#include "SFML/Graphics.hpp"

namespace Entities {

	class Entity : public Ente
	{
	protected:
		//coordenadas
		int x;
		int y;

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
		~Entity();

		//set e get coordenadas(?)
		//int getX();
		//int getY();

		//accessors
		const sf::FloatRect getGlobalBounds() const;
		const sf::Vector2f getPosition() const;

		//modifiers
		//void setPosition(const float x, const float y);

		virtual void update() = 0;
		virtual void render() = 0;

		virtual void run() = 0;
	};

}

