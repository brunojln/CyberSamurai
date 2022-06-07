#pragma once
#include "../Includes/stdafx.h"
#include "../States/Estado.h"
#include "Menu.h"
#include "../Fases/Level.h"

namespace Menus {


	class MenuNumPlayers : public Menu, public States::State
	{

	private:
		sf::Text* text;
		sf::Text* text2;

		Fases::Level* pLevel;
		Fases::Level* pLevel2;

	public:
		MenuNumPlayers(States::StateControl* pSC = NULL, Fases::Level* pLevel = nullptr, Fases::Level* pLevel2 = nullptr);
		~MenuNumPlayers();

		void render();

		void resetState();

		void exec();

		void update();
	};


}
