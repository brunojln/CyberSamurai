#include "Game.h"
#include "../Menus/MenuEntrada.h"

Game::Game() :
	pGraphics(Managers::GraphicManager::getGraphics())
{
	State* state = static_cast<State*>(new Menus::EntranceMenu(this));
	setState(state);

	changeRunningState(sID::MainMenu);
}

Game::~Game()
{
}

void Game::run()
{
	while (pGraphics->isWindowOpen())
	{
		update();
	}
}

void Game::update()
{
	while (pGraphics->getWindow()->pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed) {
			pGraphics->close();
		}
	}

	pGraphics->clear();
	
	renderRunningState();

	pGraphics->display();
}
