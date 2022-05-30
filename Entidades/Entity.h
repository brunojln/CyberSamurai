#pragma once
#include "../Ente.h"
#include "SFML/Graphics.hpp"
#include "../Gerenciadores/GraphicManager.h"


#define GRAVITY 4.f

namespace Entities {

	class Entity : public Ente
	{
	protected:
		//física
		sf::Vector2f velocity;
		float acceleration;
		float velocityMax;
		float velocityMin;
		float velocityMaxY;
		float drag;

		sf::RectangleShape body;
		sf::Texture *texture;

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
		sf::RectangleShape* getBody();
		//modifiers

		void move(float dirX, float dirY);
		void updatePhysics();
		//void setPosition(const float x, const float y);

		//virtual void update() = 0;
		//virtual void render() = 0;
		void render();
		//virtual void run() = 0;
	};

}

