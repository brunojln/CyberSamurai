#pragma once
#include "../Includes/stdafx.h"
#include "../States/Estado.h"
#include "Menu.h"

namespace Menus {

	class MenuLeaderboard : public Menu, public States::State
	{
	private:
		std::vector<sf::Text*> score;
		std::vector<sf::Text*>::iterator iP;

	public:
		MenuLeaderboard(States::StateControl* pSC=NULL);
		~MenuLeaderboard();

		void render();

		void resetState();

		void exec();

		void construct();

		void update(float dt);

	};

}