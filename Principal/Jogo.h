#pragma once
#include "../Includes/stdafx.h"
#include "../Entidades/Player.h"
#include "../Menus/MenuSobreOJogo.h"


class Jogo
{
private:
	sf::RenderWindow window;
	sf::Event ev;
	Menu Menu;
	MenuSJ MenuSJ;

	Player* player;

	void initWindow();
	void initPlayer();

public:
	Jogo();
	~Jogo();

	void updatePlayer();
	void updateCollision();
	void run();
	void update();

	void render();

};

