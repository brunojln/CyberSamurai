#include "Jogo.h"

void Jogo::initWindow()
{
	this->windowWidth = 1720;
	this->windowHeight = 980;
	this->window.create(sf::VideoMode(windowWidth, windowHeight),"CyberSamurai", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);

	this->texture.loadFromFile("InclusaoExterna/Imagens/Background/city.jpg");
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(0, 0);
	this->sprite.setScale(0.3f, 0.3f);
}

void Jogo::initView()
{
	this->view.setSize(windowWidth, windowHeight);
	this->view.setCenter(window.getSize().x / 2.f, window.getSize().y / 2.f);
	this->canMove = true;
}

void Jogo::initPlayer()
{
	this->player = new Player();
	this->platform1 = new Platform(sf::Vector2f(0.2f, 0.2f), sf::Vector2f(800.0f, 850.0f)); //temporario
	this->platform2 = new Platform(sf::Vector2f(0.2f, 0.2f), sf::Vector2f(-200.0f, 850.0f));
}

Jogo::Jogo() 
{
	this->initWindow();
	this->initView();
	this->initPlayer();
}

Jogo::~Jogo()
{
	delete this->player;
	delete this->platform1;
}
void Jogo::showCoords()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		// left click...
		sf::Vector2i position = sf::Mouse::getPosition();
		std::cout << "X:" << position.x << "\nY:" << position.y << std::endl;
	}
}
/*
Collider Jogo::getCollider()
{
	//mudar isso
	// return Collider(*this->platform1);
}*/

void Jogo::run()
{
	while (this->window.isOpen()) {
		this->update();
		this->render();
	}
}

void Jogo::player_platformCollision(Platform *platform1)
{
	sf::FloatRect playerBounds;
	sf::FloatRect platformBounds;

	playerBounds = this->player->getGlobalBounds();
	platformBounds = this->platform1->getGlobalBounds();
	this->canMove = true;
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
			this->canMove = false;
		}
		//left-right collision
		else if (playerBounds.left > platformBounds.left &&
			playerBounds.left + playerBounds.width > platformBounds.left + platformBounds.width &&
			playerBounds.top < platformBounds.top + platformBounds.height &&
			playerBounds.top + playerBounds.height > platformBounds.top
			)
		{
			this->player->setPosition(platformBounds.left + platformBounds.width, playerBounds.top);
			this->canMove = false;
		}
		
	}
}

void Jogo::updatePlayer()
{
	this->player->update();
}

void Jogo::updateCollision()
{
	this->player_platformCollision(this->platform1);
	//this->player_platformCollision(this->platform2);

	//collision bottom screen
	if (this->player->getPosition().y + this->player->getGlobalBounds().height >= this->window.getSize().y)
	{
		this->player->resetVelocityY();
		this->player->setPosition(this->player->getPosition().x,
			this->window.getSize().y - this->player->getGlobalBounds().height);
		this->player->setCanJump(true);
	} 
	//collision top screen
	else if (this->player->getPosition().y <= 0.f)
	{
		this->player->resetVelocityY();
		this->player->setPosition(this->player->getPosition().x,0.f);
	}

	
	//collision left screen
	/*
	if (this->player->getPosition().x  <= 0.f)
	{
		this->player->setPosition(0.f, this->player->getPosition().y);
	}
	//right side collision screen
	if (this->player->getPosition().x + this->player->getGlobalBounds().width >= this->window.getSize().x)
	{
		this->player->setPosition(this->window.getSize().x - this->player->getGlobalBounds().width,
			this->player->getPosition().y);
	}*/
}

void Jogo::updateView()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && canMove) {
		this->view.move(-9.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && canMove) {
		this->view.move(9.f, 0.f);
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
	this->updateView();
	this->updateCollision();
	this->showCoords(); // temporario
}

void Jogo::render()
{
	this->window.clear();

	this->window.setView(view);
	//rendering
	this->window.draw(this->sprite);
	this->player->render(this->window);
	this->platform1->render(this->window);
	this->platform2->render(this->window);

	this->window.setView(window.getDefaultView());
	this->window.display();
}
