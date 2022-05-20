#include "Player.h"

void Player::initVariables()
{
	this->animationState = IDLE;
}

void Player::initAnimations()
{
	this->animationTimer.restart();
}

void Player::initPhysics()
{
	this->velocityMax = 6.f;
	this->velocityMin = 1.f;
	this->acceleration = 1.f;
	this->drag = 0.9f;
	this->gravity = 4.f;
	this->velocityMaxY = 15.f;
}

void Player::initTexture()
{
	if (!this->textureSheet.loadFromFile("InclusaoExterna/Imagens/Personagens/BontenmaruSheet.png")) {
		std::cout << "ERROR::PLAYER::INITTEXTURE::Falha ao carregar textura" << "\n";
	}
	else { std::cout << "deu boa"; }
}

void Player::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, 125, 115);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(2.5f, 2.5f);
}

Player::Player()
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

const sf::Vector2f Player::getPosition() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
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

void Player::updatePhysics()
{
	this->velocity.y += 1.0 * this->gravity;
	if (std::abs(this->velocity.y) > this->velocityMaxY) {
		this->velocity.y = this->velocityMaxY * ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}


	this->velocity *= this->drag;

	if (std::abs(this->velocity.x) < this->velocityMin)
		this->velocity.x = 0.f;
	if (std::abs(this->velocity.y) < this->velocityMin)
		this->velocity.y = 0.f;

	this->sprite.move(this->velocity);

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
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animationState == MOVING_RIGHT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.25f)
		{
			this->currentFrame.top = 230.f;
			this->currentFrame.left += 120.f;
			if (this->currentFrame.left >= 625)
			{
				this->currentFrame.left = 0;
			}
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
		this->sprite.setScale(2.5f, 2.5f);
		this->sprite.setOrigin(0.f, 0.f);
	}
	else if (this->animationState == MOVING_LEFT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.25f)
		{
			this->currentFrame.top = 230.f;
			this->currentFrame.left += 120.f;
			if (this->currentFrame.left >= 625)
			{
				this->currentFrame.left = 0;
			}
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
		this->sprite.setScale(-2.5f, 2.5f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2.5f, 0.f);
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
	target.draw(this->sprite);
}
