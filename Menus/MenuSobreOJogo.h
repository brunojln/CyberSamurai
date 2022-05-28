#pragma once
#include "../Includes/stdafx.h"
#include "../States/Estado.h"
#include "Menu.h"

class Game;

class MenuSobreOJogo : public Menu, public State
{
private:
	sf::Text* text;

public:
	MenuSobreOJogo(Game* pG);
	~MenuSobreOJogo();

	void render();

	void resetState();

	void exec();

	void update(float dt);
};

