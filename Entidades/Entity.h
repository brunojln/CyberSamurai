#pragma once
#include "../Ente.h"
#include "SFML/Graphics.hpp"
#include "../Gerenciadores/GraphicManager.h"

#define GRAVITY 4.f

namespace Entities {

	enum entityID {
		unknown = 0,
		player, 
		robot,
		flying,
		boss,
		platform,
		spikes,
		elevator
	};

	class Entity : public Ente
	{
	protected:
		entityID ID;

		//física
		sf::Vector2f velocity;
		float acceleration;
		float velocityMax;
		float velocityMin;
		float velocityMaxY;
		float drag;

		bool canJump;

		sf::RectangleShape body;
		sf::Texture *texture;
		sf::IntRect currentFrame;

		Managers::GraphicManager* pGraphic;
	
		unsigned int damage;
	public:
		Entity(entityID id);
		Entity(int id);
		~Entity();

		//accessors
		const sf::FloatRect getGlobalBounds() const;
		const sf::Vector2f getPosition() const;
		const sf::Vector2f getSize() const;
		const entityID getID() { return ID; }
		sf::RectangleShape* getBody();
		//modifiers

		void move(float dirX, float dirY);
		void updatePhysics();
		void setPosition(const float x, const float y);
		void resetVelocityY();
		void setCanJump(bool can_jump);

		virtual void update() = 0;

		virtual void render();
		
	};

}

