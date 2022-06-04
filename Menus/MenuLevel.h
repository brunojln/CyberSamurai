#pragma once
#include "../Includes/stdafx.h"
#include "../States/Estado.h"
#include "Menu.h"



namespace Menus {

	class MenuLevel : public Menu, public States::State
	{

	private:

	public:
		MenuLevel(States::StateControl* pSC=NULL);
		~MenuLevel();

		void render();

		void resetState();

		void exec();

		void update();
	};

}