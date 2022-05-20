#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

enum PLAYER_ANIMATION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING };

class Player
{
private:
	sf::Texture textureSheet;
	sf::Sprite sprite;

	//Animation
	sf::Clock animationTimer;
	short animationState;
	sf::IntRect currentFrame;
	//movemente
	bool moving;
	//core

	//physics
	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;
	float gravity;
	float velocityMaxY;

	//initialization
	void initVariables();
	void initAnimations();
	void initPhysics();
	void initTexture();
	void initSprite();
public:
	Player();
	~Player();

	//Accessors
	const sf::Vector2f getPosition() const;
	const sf::FloatRect getGlobalBounds() const;

	//modifiers
	void setPosition(const float x, const float y);
	void resetVelocityY();

	void move(const float dirX, const float dirY);

	void updatePhysics();
	void updateMovement();
	void updateAnimations();

	void update();
	void render(sf::RenderTarget& target);

};

