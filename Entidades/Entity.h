#pragma once
#include "../Ente.h"
#include "SFML/Graphics.hpp"
#include "../Gerenciadores/GraphicManager.h"

#define GRAVITY 980.f

namespace Entities {

	class Entity : public Ente
	{
	protected:
		//física
		sf::Vector2f velocity;
		/*
		float velocityMax;
		float velocityMin;
		float acceleration;
		float drag;
		float velocityMaxY;
		*/
		sf::RectangleShape body;
		sf::Texture texture;

		Managers::GraphicManager* pGraphic;


		unsigned int damage;
	public:
		Entity();
		Entity(int id);
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

