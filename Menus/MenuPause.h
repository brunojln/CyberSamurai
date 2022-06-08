#pragma once
#include "../Includes/stdafx.h"
#include "../States/Estado.h"
#include "Menu.h"
#include "../Fases/Level.h"

namespace Menus{

	class MenuPause : public Menu, public States::State
	{

	private:
		sf::Text* text;

		sf::Text* comands;
		sf::Text* comands2;

		Fases::Level* pLevel;
		Fases::Level* pLevel2;
	public:

		MenuPause(States::StateControl* pSC = NULL, Fases::Level* pLevel = nullptr, Fases::Level* pLevel2 = nullptr);

		~MenuPause();

		void render();

		void resetState();

		void exec();

		void update();

	};

}