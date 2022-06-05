#pragma once
#include "../Includes/stdafx.h"
#include "../States/Estado.h"
#include "Menu.h"

namespace Menus{

	class MenuPause : public Menu, public States::State
	{

	private:
		sf::Text* text;

		sf::Text* comands;
		sf::Text* comands2;

	public:

		MenuPause(States::StateControl* pSC = NULL);

		~MenuPause();

		void render();

		void resetState();

		void exec();

		void update();

	};

}