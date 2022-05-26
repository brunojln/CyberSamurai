#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Character.h"

enum PLAYER_ANIMATION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, ATTACK };

namespace Entities {

	class Player: public Character
	{
	private:
		sf::Texture *textureSheet;
		sf::Sprite sprite;

		//Animation
		sf::Clock animationTimer;
		short animationState;
		sf::IntRect currentFrame;

		//movement
		bool moving;
		bool canJump;
		float jumpHeight;
	
		//core
		sf::RectangleShape hitBox;

		//initialization
		void initVariables();
		void initAnimations();
		void initPhysics();
		void initTexture();
		void initSprite();

	public:
		Player(const float atkCd, const float atkDis);
		Player(int hp, int xp, int atkDmg, const float atkCd, const float atkDis,
			int id, sf::Vector2f velocidade, float vMax, float vMin, 
			float accel, float dr, float grav, float vMaxY, sf::Vector2f size);
		~Player();

		//Accessors
		//const sf::Vector2f getPosition() const;
		const sf::FloatRect getGlobalBounds() const;

		//modifiers
		void setPosition(const float x, const float y);
		void resetVelocityY();

		void move(const float dirX, const float dirY);
		void setCanJump(bool can_jump);
		void jump();

		void updatePhysics();
		void updateMovement();
		void updateAnimations();

		void update();
		void render(sf::RenderTarget& target); //virtual <-

	};


}

