#include "Player.h"

namespace Entities {

	void Player::initVariables()
	{
		this->animationState = IDLE;
		this->canJump = true;
		this->jumpHeight = 1000.f;
	
		//this->hitBox.setSize(this->body.);
	}

	void Player::initAnimations()
	{
		this->animationTimer.restart();
	}

	void Player::initPhysics()
	{
		velocityMax = 10.f;
		this->velocityMin = 1.f;
		this->acceleration = 1.f;
		this->drag = 0.9f;
		this->gravity = 2.f;
		this->velocityMaxY = 40.f;
	}

	void Player::initTexture()
	{
		textureSheet = new sf::Texture();

		if (!textureSheet->loadFromFile("InclusaoExterna/Imagens/Personagens/BontenmaruSheet.png")) {
			std::cout << "ERROR::PLAYER::INITTEXTURE::Falha ao carregar textura" << "\n";
		}
	}

	void Player::initSprite()
	{
		this->body.setTexture(textureSheet);
		this->currentFrame = sf::IntRect(0, 0, 125, 100);
		this->body.setTextureRect(this->currentFrame);
		this->body.setSize(sf::Vector2f(125.f, 100.f));
		this->body.setPosition(860.f, 440.f);
	}

	Player::Player(const float atkCd, const float atkDis) : Character(atkCd, atkDis)
	{
		this->initVariables();
		this->initAnimations();
		this->initPhysics();
		this->initTexture();
		this->initSprite();
	}

	Player::Player(int hp, int xp, int atkDmg, const float atkCd, const float atkDis,
		int id, sf::Vector2f velocidade, float vMax, float vMin, float accel, 
		float dr, float grav, float vMaxY, sf::Vector2f size):

		Character(hp, xp, atkDmg, atkCd, atkDis,
			id, velocidade, vMax,vMin, accel, dr, grav, vMaxY, size)
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

	const sf::FloatRect Player::getGlobalBounds() const
	{
		return this->body.getGlobalBounds();
	}


	void Player::setPosition(const float x, const float y)
	{
		this->body.setPosition(x, y);
	}

	void Player::resetVelocityY()
	{
		this->velocity.y = 0.f;
	}

	void Player::move(const float dirX, const float dirY)
	{
		this->velocity.x += dirX * this->acceleration;
		//this->velocity.y += dirY * this->acceleration;

		//limit velocity
		if (std::abs(this->velocity.x) > this->velocityMax) {
			this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
		}
	}

	void Player::setCanJump(bool can_jump)
	{
		this->canJump = can_jump;
	}

	void Player::updatePhysics()
	{
		this->velocity.y += 0.8 * this->gravity;
		if (std::abs(this->velocity.y) > this->velocityMaxY) {
			this->velocity.y = this->velocityMaxY * ((this->velocity.y < 0.f) ? -1.f : 1.f);
		}


		this->velocity *= this->drag;

		if (std::abs(this->velocity.x) < this->velocityMin)
			this->velocity.x = 0.f;
		if (std::abs(this->velocity.y) < this->velocityMin)
			this->velocity.y = 0.f;

		this->body.move(this->velocity);

	}

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
			this->canJump = false;
			this->velocity.y = -sqrtf(2.0f * this->gravity * this->jumpHeight);
			//std::cout << this->velocity.y << std::endl;
			this->animationState = JUMPING;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
			//attack function
			//reset attack cooldown
			this->animationState = ATTACK;
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
			this->body.setScale(2.5f, 2.5f);
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
			this->body.setScale(-2.5f, 2.5f);
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
		this->updatePhysics();
	}

	void Player::render(sf::RenderTarget& target)
	{
		target.draw(this->body);
	}

}

