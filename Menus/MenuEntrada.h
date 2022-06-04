#pragma once
#include "../Includes/stdafx.h"
#include "../States/Estado.h"
#include "Menu.h"



class Game;

namespace Menus {

	class EntranceMenu : public Menu, public States::State
	{
	private:
		Game* pG;
		sf::Text title;

	public:

		EntranceMenu(Game* pointerGame = NULL);
		~EntranceMenu();

		//Funcoes virual void herdadas de State

		void render();

		void resetState();

		void exec();

		void update();

	};


}
