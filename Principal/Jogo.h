#pragma once
#include "../Includes/stdafx.h"
#include "../Entidades/Player.h"
#include "../Gerenciadores/Platform.h"

class Jogo
{
private:
	sf::RenderWindow window;
	int windowWidth;
	int windowHeight;

	sf::View view;
	sf::Clock deltClock;
	float deltaTime; 
	bool canMove;

	sf::Texture texture;
	sf::Sprite sprite;
	sf::Event ev;

	Player* player;
	Platform* platform1; 


	void initWindow();
	void initView();
	void initPlayer();

public:
	Jogo();
	~Jogo();

	//Collider getCollider();
	void player_platformCollision();

	void updatePlayer();
	void updateCollision();
	void updateView();
	void run();
	void update();

	void render();

};

