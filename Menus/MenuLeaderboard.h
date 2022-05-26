#pragma once
#include "../Includes/stdafx.h"
#include "../States/Estado.h"
#include "Menu.h"

class MenuLeaderboard : public Menu, public State::State
{
private:
	vector<sf::Text*> score;
	vector<sf::Text*>::iterator iP;

public:
	MenuLeaderboard(StateControl* pSM);
	~MenuLeaderboard();

	void render();

	void resetState();

	void exec();

	void construct();

	void update(float dt)

};

