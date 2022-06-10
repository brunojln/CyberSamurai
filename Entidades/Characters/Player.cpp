#include "Player.h"

namespace Entities {

	void Player::initVariables()
	{
		this->animationState = IDLE;
		cooldownClock.restart();
		canJump = true;
		canAttack = true;
		isAttacking = false;

		velocityMax = 5.f;
		velocityMin = 1.f;
		acceleration = 1.f;
		drag = 0.9f;
		velocityMaxY = 60.f;
		jumpHeight = 1000.f;

		lifePoints = 100;
		atkCooldown = 1.f;
		atkDamage = 2.f;
		exp = 0;
		isTakingDamage = false;
	}

	void Player::initAnimations()
	{
		this->animationTimer.restart();
	}

	void Player::initTexture()
	{
		texture = pGraphic->loadTexture("InclusaoExterna/Imagens/Personagens/BontenmaruSheet.png");
	}

	void Player::initSprite()
	{
		this->body.setTexture(texture);
		this->currentFrame = sf::IntRect(0, 0, 125, 100);
		this->body.setTextureRect(this->currentFrame);
		this->body.setSize(sf::Vector2f(125.f, 100.f));
		this->body.setPosition(860.f, 440.f);
	}

	Player::Player(bool player2) :
		Character(entityID::player)
	{
		this->initVariables();
		this->initAnimations();
		this->initTexture();
		this->initSprite();

		if (player2) {
			left = sf::Keyboard::Left;
			right = sf::Keyboard::Right;
			jump = sf::Keyboard::Up;
			atk = sf::Keyboard::K;

			defaultColor = sf::Color(250, 0, 252, 500);
			isP1 = false;
		}
		else {
			left = sf::Keyboard::A;
			right = sf::Keyboard::D;
			jump = sf::Keyboard::Space;
			atk = sf::Keyboard::G;

			defaultColor = sf::Color(164, 223, 245, 500);
			isP1 = true;
		}
	}

	Player::~Player()
	{
	}

	void Player::setCanJump(bool can_jump)
	{
		canJump = can_jump;
	}

	void Player::updateMovement()
	{
		this->animationState = IDLE;

		if (sf::Keyboard::isKeyPressed(left)) {
			this->move(-3.f, 0.f);
			this->animationState = MOVING_LEFT;
		}
		else if (sf::Keyboard::isKeyPressed(right)) {
			this->move(3.f, 0.f);
			this->animationState = MOVING_RIGHT;
		}
		if (sf::Keyboard::isKeyPressed(jump) && canJump) {
			canJump = false;
			this->velocity.y = -sqrtf(2.0f * GRAVITY * this->jumpHeight);
			this->animationState = JUMPING;
		}
		if (sf::Keyboard::isKeyPressed(atk) && canAttack) {
			isAttacking = true;
			this->animationState = ATTACK;
		}


	}

	void Player::updateAnimations()
	{
		body.setFillColor(sf::Color(defaultColor));
		if (isTakingDamage) { body.setFillColor(sf::Color::Red); isTakingDamage = false;  }

		if (this->animationState == IDLE)
		{
			if (this->animationTimer.getElapsedTime().asSeconds() >= 0.3f)
			{
				this->currentFrame.top = 0.f;
				this->currentFrame.left += 120.f;
				if (this->currentFrame.left >= 375)
				{
					this->currentFrame.left = 0;
				}
				this->animationTimer.restart();
				this->body.setTextureRect(this->currentFrame);
			}
		}
		else if (this->animationState == MOVING_RIGHT)
		{
			if (this->animationTimer.getElapsedTime().asSeconds() >= 0.22f)
			{
				this->currentFrame.top = 230.f;
				this->currentFrame.left += 120.f;
				if (this->currentFrame.left >= 625)
				{
					this->currentFrame.left = 0;
				}
				this->animationTimer.restart();
				this->body.setTextureRect(this->currentFrame);
			}
			this->body.setScale(1.f, 1.f);
			this->body.setOrigin(0.f, 0.f);
		}
		else if (this->animationState == MOVING_LEFT)
		{
			if (this->animationTimer.getElapsedTime().asSeconds() >= 0.22f)
			{
				this->currentFrame.top = 230.f;
				this->currentFrame.left += 120.f;
				if (this->currentFrame.left >= 625)
				{
					this->currentFrame.left = 0;
				}
				this->animationTimer.restart();
				this->body.setTextureRect(this->currentFrame);
			}
			this->body.setScale(-1.f, 1.f);
			this->body.setOrigin(this->body.getGlobalBounds().width / 2.5f, 0.f);
		}
		else if (this->animationState == JUMPING) 
		{
			this->currentFrame.top = 115.f;
			this->currentFrame.left = 600.f;
			this->animationTimer.restart();
			this->body.setTextureRect(this->currentFrame);
		}
		else if (this->animationState == ATTACK) 
		{

			if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
			{
				this->currentFrame.left = 480.f;
				this->currentFrame.top = 0.f;
				this->currentFrame.left += 140.f;
				if (this->currentFrame.left >= 720)
				{
					this->currentFrame.left = 480.f;
				}
				this->animationTimer.restart();
				this->body.setTextureRect(this->currentFrame);
			}
		}
		else { 
			this->animationTimer.restart();
		}


	}

	void Player::update()
	{
		this->updateMovement();
		this->updateAnimations();
		updatePhysics();
	}

	void Player::save()
	{
		std::ofstream playerFile;

		if (isP1)
		{
			playerFile.open("InclusaoExterna/Saves/Player.txt", std::ios::app);

			if (!playerFile) { std::cout << "ERROR::PLAYER::SAVE::Erro ao abrir arquivo"; exit(1); }

			playerFile << getPosition().x << ' ' << getPosition().y << ' ' << getLifePoints() << ' ' << getExp() << ' ' << std::endl;
			playerFile.close();
		}
		else
		{
			playerFile.open("InclusaoExterna/Saves/Player2.txt", std::ios::app);

			if (!playerFile) { std::cout << "ERROR::PLAYER::SAVE::Erro ao abrir arquivo"; exit(1); }

			playerFile << getPosition().x << ' ' << getPosition().y << ' ' << getLifePoints() << ' ' << getExp() << ' ' << std::endl;
			playerFile.close();
		}
	}
	

}

	