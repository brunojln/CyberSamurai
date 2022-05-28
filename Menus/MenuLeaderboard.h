#pragma once
#include "../Includes/stdafx.h"
#include "../States/Estado.h"
#include "Menu.h"


class MenuLeaderboard : public Menu, public State
{
private:
	std::vector<sf::Text*> score;
	std::vector<sf::Text*>::iterator iP;

public:
	MenuLeaderboard(StateControl* pSC);
	~MenuLeaderboard();

	void render();

	void resetState();

	void exec();

	void construct();

	void update(float dt);

};

