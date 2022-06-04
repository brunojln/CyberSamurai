#pragma once
#include "../Includes/stdafx.h"
#include "../States/Estado.h"
#include "Menu.h"

namespace Menus {


	class MenuNumPlayers : public Menu, public States::State
	{

	private:

	public:
		MenuNumPlayers(States::StateControl* pSC=NULL);
		~MenuNumPlayers();

		void render();

		void resetState();

		void exec();

		void update(float dt);
	};


}
