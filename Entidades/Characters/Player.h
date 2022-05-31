#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Character.h"
#include "../../States/Estado.h"


enum PLAYER_ANIMATION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, ATTACK };

namespace Entities {

	class Enemy;

	class Player: public Character
	{
	private:
		sf::Texture* textureSheet;
		sf::Texture* heartTexture;
		sf::Sprite heartSprite;
		//Animation
		sf::Clock animationTimer;
		short animationState;
		sf::IntRect currentFrame;
		sf::IntRect heartFrame;
		//movement
		bool moving;
		sf::Clock cooldownClock;
		//bool canJump;
		float jumpHeight;
	
		//core

		//initialization
		void initVariables();
		void initAnimations();
		void initPhysics();
		void initTexture();
		void initSprite();

	public:
		Player();
		~Player();

		void setCanJump(bool can_jump);

		//void attack(Entities::Enemy* pEnemy, bool isNear);
		//void updateCooldown();
		void updateMovement();
		void updateAnimations();
		void updateHearts(sf::RenderWindow* window);

		void update();

	};


}

