#pragma once
#include "Menu.h"
#include "../States/Estado.h"
#include "../Includes/stdafx.h"

class MenuGameOver : public Menu, public State
{
private:
	sf::Text title;
	sf::Text points;
	sf::Text name;
	sf::Text playerName;
	
	sf::Clock typingClock;

	std::string StringName;
public:
	MenuGameOver(StateControl* pSC = NULL);
	~MenuGameOver();

	std::string getString();

	void update(float dt);
	void render();
	void exec();
	void resetState();
	void saveLeaderBoard();

};

