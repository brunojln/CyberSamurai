#pragma once
#include "../Includes/stdafx.h"
#include "../Botao/Botao.h"


namespace Menus {

	class Menu
	{
	protected:
		std::vector<Button*> ButtonVector;
		std::vector<Button*>::iterator iB;

		int sel;
		int min, max;
		bool active;

		sf::Clock delay;
		sf::RectangleShape body;
		sf::Sprite* background;

	public:

		Menu();
		~Menu();

		virtual void exec() = 0;

		//void updateScreen();

		void Up();
		void Down();
		void update();



	};
}