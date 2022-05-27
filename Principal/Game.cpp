#pragma once
#include "Game.h"
#include "../Menus/MenuEntrada.h"
#include "../Menus/MenuLeaderboard.h"

Game::Game() :
	pGraphics(Managers::GraphicManager::getGraphics())
{
	State* state = static_cast<State*>(new Menus::EntranceMenu(this));
	setState(state);

	state = static_cast<State*>(new MenuLeaderboard(this));
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
	
	updateRunningState(0);

	renderRunningState();

	pGraphics->display();
}
