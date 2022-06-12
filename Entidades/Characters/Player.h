#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Character.h"
#include "../../States/Estado.h"
#include "../../States/GerenciadorEstado.h"


enum PLAYER_ANIMATION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, ATTACK };

namespace Entities {

	class Player: public Character
	{
	private:
		//Animation
		sf::Clock animationTimer;
		short animationState;
		sf::IntRect currentFrame;

		sf::Clock cooldownClock;

		float jumpHeight;
	
		//core
		sf::Keyboard::Key left;
		sf::Keyboard::Key right;
		sf::Keyboard::Key jump;
		sf::Keyboard::Key atk;
		sf::Color defaultColor;
		bool isP1;

		//initialization
		void initVariables();
		void initAnimations();
		void initTexture();
		void initSprite();

	public:
		//Player();
		Player(bool player2);
		~Player();

		void setCanJump(bool can_jump);

		friend std::ostream& operator<<(std::ostream& output, Entities::Player &P);

		void updateMovement();
		void updateAnimations();

		virtual void update();

		virtual void save();
	};


}

