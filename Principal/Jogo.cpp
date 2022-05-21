#include "Jogo.h"

void Jogo::initWindow()
{
	this->window.create(sf::VideoMode(1000, 800), "Teste Animacao", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}

void Jogo::initPlayer()
{
	this->player = new Player();
}

Jogo::Jogo()
{
	MenuSJ.run_men();
	//Menu.run_menu();
	/*this->initWindow();
	this->initPlayer();*/
}

Jogo::~Jogo()
{
	delete this->player;
}

void Jogo::run()
{
	while (this->window.isOpen()) {
		this->update();
		this->render();
	}
}

void Jogo::updatePlayer()
{
	this->player->update();
}

void Jogo::updateCollision()
{
	//collision bottom screen
	if (this->player->getPosition().y + this->player->getGlobalBounds().height >= this->window.getSize().y)
	{
		this->player->resetVelocityY();
		this->player->setPosition(this->player->getPosition().x,
			this->window.getSize().y - this->player->getGlobalBounds().height);
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

	this->window.display();
}
