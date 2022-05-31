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

		lifePoints = 4;
		atkCooldown = 1.f;
		atkDamage = 1.f;
	}

	void Player::initAnimations()
	{
		this->animationTimer.restart();
	}

	void Player::initPhysics()
	{
		
	}

	void Player::initTexture()
	{
		textureSheet = new sf::Texture();

		if (!textureSheet->loadFromFile("InclusaoExterna/Imagens/Personagens/BontenmaruSheet.png")) {
			std::cout << "ERROR::PLAYER::INITTEXTURE::Falha ao carregar textura" << "\n";
		}

		heartTexture = new sf::Texture();

		if (!heartTexture->loadFromFile("InclusaoExterna/Imagens/Background/heartSprite.png")) {
			std::cout << "ERROR::PLAYER::initTexture::Fallha ao carregar textura" << "\n";
		}
	}

	void Player::initSprite()
	{
		this->body.setTexture(textureSheet);
		this->currentFrame = sf::IntRect(0, 0, 125, 100);
		this->body.setTextureRect(this->currentFrame);
		this->body.setSize(sf::Vector2f(125.f, 100.f));
		this->body.setPosition(860.f, 440.f);

		this->heartSprite.setTexture(*heartTexture);
		this->heartFrame = sf::IntRect(0, 0, 92, 110);
		this->heartSprite.setTextureRect(this->heartFrame);
		this->heartSprite.setPosition(20, 20);
		this->heartSprite.setScale(0.5f, 0.5f);
	}

	Player::Player():
		Character(entityID::player)
	{
		this->initVariables();
		this->initAnimations();
		this->initPhysics();
		this->initTexture();
		this->initSprite();
	}

	Player::~Player()
	{
	}

	void Player::setCanJump(bool can_jump)
	{
		canJump = can_jump;
	}

	/*void Player::updateCooldown()
	{
		if (cooldownClock.getElapsedTime().asSeconds() >= this->atkCooldown)
		{
			this->canAttack = true;
			cooldownClock.restart();
		}
	}*/

	void Player::updateMovement()
	{
		this->animationState = IDLE;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			this->move(-3.f, 0.f);
			this->animationState = MOVING_LEFT;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			this->move(3.f, 0.f);
			this->animationState = MOVING_RIGHT;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump) {
			canJump = false;
			this->velocity.y = -sqrtf(2.0f * GRAVITY * this->jumpHeight);
			this->animationState = JUMPING;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && canAttack) {
			//attack function
			//reset attack cooldown
			isAttacking = true;
			this->animationState = ATTACK;
			//canAttack = false;
		}


	}

	void Player::updateAnimations()
	{
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

	void Player::updateHearts(sf::RenderWindow* window)
	{
		//chamar função para alterar vida do jogador
		window->draw(heartSprite);
	}

	void Player::update()
	{
		this->updateMovement();
		this->updateAnimations();
		updatePhysics();
		updateCooldown();
	}
	

}

