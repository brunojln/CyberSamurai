#pragma once
#include "../Includes/stdafx.h"
#include "../States/Estado.h"
#include "Menu.h"

class Game;


class MenuLevel : public Menu, public State
{

private:

public:
	MenuLevel(Game* pG);
	~MenuLevel();

	void render();

	void resetState();

	void exec();

	void update(float dt);
};

