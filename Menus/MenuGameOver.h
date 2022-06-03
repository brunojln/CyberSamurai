#pragma once
#include "Menu.h"
#include "../States/Estado.h"
#include "../Includes/stdafx.h"
#include "../Fases/Level.h"

namespace Menus {

	class MenuGameOver : public Menu, public States::State
	{
	private:
		sf::Text title;
		sf::Text points;
		sf::Text name;
		sf::Text playerName;

		sf::Clock typingClock;
		
		std::string StringName;

		Fases::Level* pLevel;
	public:
		MenuGameOver(States::StateControl* pSC = NULL, Fases::Level* pLevel = nullptr);
		~MenuGameOver();

		std::string getString();

		void update(float dt);
		void render();
		void exec();
		void resetState();
		void saveLeaderBoard();

	};

}