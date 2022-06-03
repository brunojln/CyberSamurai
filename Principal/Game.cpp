#pragma once
#include "Game.h"
#include "../Menus/MenuEntrada.h"
#include "../Menus/MenuLeaderboard.h"
#include "../Menus/MenuSobreOJogo.h"
#include "../Menus/MenuLevel.h"
#include "../Fases/LevelOne.h"
#include "../Fases/Level.h"
#include "../Menus/MenuGameOver.h"


	Game::Game() :
		pGraphics(Managers::GraphicManager::getGraphics())
	{
		States::State* state = dynamic_cast<States::State*>(new Menus::EntranceMenu(this));
		setState(state);

		state = new	Fases::LevelOne(this);
		setState(state);

		state = dynamic_cast<States::State*>(new Menus::MenuLeaderboard(this));
		setState(state);

		state = dynamic_cast<States::State*>(new Menus::MenuLevel(this));
		setState(state);

		state = dynamic_cast<States::State*>(new Menus::MenuSobreOJogo(this));
		setState(state);

		state = dynamic_cast<States::State*>(new Menus::MenuGameOver(this, dynamic_cast<Fases::Level*>(StateMap[States::sID::Level1])));
		setState(state);

		changeRunningState(States::sID::MainMenu);
	}

	Game::~Game()
	{
	}

	void Game::run()
	{
		while (pGraphics->isWindowOpen())
		{
			update();
			render();
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
		updateRunningState(0);
		
	}

	void Game::render()
	{
		pGraphics->clear();

		renderRunningState();

		pGraphics->display();
	}

