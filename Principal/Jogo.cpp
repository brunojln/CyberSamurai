#include "Jogo.h"

void Jogo::initWindow()
{
	this->window.create(sf::VideoMode(1000, 800), "Teste Animacao", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);

	//this->texture.loadFromFile("InclusaoExterna/Imagens/Background/gameBackground.gif");
	//this->sprite.setTexture(this->texture);
	//this->sprite.setPosition(0, 0);
}

void Jogo::initPlayer()
{
	this->player = new Player();
	this->platform1 = new Platform(sf::Vector2f(0.5f, 0.5f), sf::Vector2f(450.0f, 700.0f));
}

Jogo::Jogo() //: platform1(sf::Vector2f(1.f, 1.f), sf::Vector2f(900.0f, 500.0f))
{
	this->initWindow();
	this->initPlayer();
}

Jogo::~Jogo()
{
	delete this->player;
	delete this->platform1;
}
/*
Collider Jogo::getCollider()
{
	//say whaat, viajei nisso sepa
	// return Collider(*this->platform1);
}*/

void Jogo::run()
{
	while (this->window.isOpen()) {
		this->update();
		this->render();
	}
}

void Jogo::player_platformCollision()
{
	sf::FloatRect playerBounds;
	sf::FloatRect platformBounds;

	playerBounds = this->player->getGlobalBounds();
	platformBounds = this->platform1->getGlobalBounds();

	if (playerBounds.intersects(platformBounds))
	{	//bottom-top collision
		if (playerBounds.top < platformBounds.top &&
			playerBounds.top + playerBounds.height < platformBounds.top + platformBounds.height &&
			playerBounds.left < platformBounds.left + platformBounds.width &&
			playerBounds.left + playerBounds.width > platformBounds.left
			)
		{
			this->player->setPosition(playerBounds.left, platformBounds.top - playerBounds.height);
			this->player->setCanJump(true);
		}
		//top-bottom collision
		else if (playerBounds.top > platformBounds.top &&
			playerBounds.top + playerBounds.height > platformBounds.top + platformBounds.height &&
			playerBounds.left < platformBounds.left + platformBounds.width &&
			playerBounds.left + playerBounds.width > platformBounds.left
			)
		{
			this->player->setPosition(playerBounds.left, platformBounds.top + platformBounds.height);
		}
		
		
		//right-left collision
		if (playerBounds.left < platformBounds.left &&
			playerBounds.left + playerBounds.width < platformBounds.left + platformBounds.width &&
			playerBounds.top < platformBounds.top + platformBounds.height &&
			playerBounds.top + playerBounds.height > platformBounds.top
			)
		{
			this->player->setPosition(platformBounds.left - playerBounds.width, playerBounds.top);
		}
		//left-right collision
		else if (playerBounds.left > platformBounds.left &&
			playerBounds.left + playerBounds.width > platformBounds.left + platformBounds.width &&
			playerBounds.top < platformBounds.top + platformBounds.height &&
			playerBounds.top + playerBounds.height > platformBounds.top
			)
		{
			this->player->setPosition(platformBounds.left + platformBounds.width, playerBounds.top);
		}
	}
}

void Jogo::updatePlayer()
{
	this->player->update();
}

void Jogo::updateCollision()
{
	this->player_platformCollision();

	//collision bottom screen
	if (this->player->getPosition().y + this->player->getGlobalBounds().height >= this->window.getSize().y)
	{
		this->player->resetVelocityY();
		this->player->setPosition(this->player->getPosition().x,
			this->window.getSize().y - this->player->getGlobalBounds().height);
		this->player->setCanJump(true);
	} 
	//collision top screen
	if (this->player->getPosition().y <= 0.f)
	{
		this->player->resetVelocityY();
		this->player->setPosition(this->player->getPosition().x,0.f);
	}
	//collision left screen
	if (this->player->getPosition().x  <= 0.f)
	{
		this->player->setPosition(0.f, this->player->getPosition().y);
	}
	//right side collision screen
	if (this->player->getPosition().x + this->player->getGlobalBounds().width >= this->window.getSize().x)
	{
		this->player->setPosition(this->window.getSize().x - this->player->getGlobalBounds().width,
			this->player->getPosition().y);
	}
}

void Jogo::update()
{
	while (this->window.pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed) {
			this->window.close();
		}
	}
	this->updatePlayer();

	this->updateCollision();
}

void Jogo::render()
{
	this->window.clear();
	//drawing

	this->player->render(this->window);
	this->platform1->render(this->window);

	this->window.display();
}
