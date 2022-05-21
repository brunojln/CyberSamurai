#pragma once
#include "../Includes/stdafx.h"
#include "../Entidades/Player.h"
#include "../Gerenciadores/Platform.h"

class Jogo
{
private:
	sf::RenderWindow window;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Event ev;

	Player* player;
	Platform* platform1; //talvez fzr isso sem ponteiro


	void initWindow();
	void initPlayer();

public:
	Jogo();
	~Jogo();

	//Collider getCollider();
	void player_platformCollision();

	void updatePlayer();
	void updateCollision();
	void run();
	void update();

	void render();

};

