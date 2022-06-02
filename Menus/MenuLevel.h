#pragma once
#include "../Includes/stdafx.h"
#include "../States/Estado.h"
#include "Menu.h"



namespace Menus {
	class Game;


	class MenuLevel : public Menu, public States::State
	{

	private:

	public:
		MenuLevel(States::StateControl* pSC);
		~MenuLevel();

		void render();

		void resetState();

		void exec();

		void update(float dt);
	};

}