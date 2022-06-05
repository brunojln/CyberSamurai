#pragma once
#include "Game.h"
#include "../Menus/MenuEntrada.h"
#include "../Menus/MenuLeaderboard.h"
#include "../Menus/MenuSobreOJogo.h"
#include "../Menus/MenuLevel.h"
#include "../Fases/LevelOne.h"
#include "../Fases/LevelTwo.h"
#include "../Fases/Level.h"
#include "../Menus/MenuGameOver.h"
#include "../Menus/MenuPause.h"
#include "../Menus/MenuNumPlayers.h"


	Game::Game() :
		pGraphics(Managers::GraphicManager::getGraphics())
	{
		States::State* state = dynamic_cast<States::State*>(new Menus::EntranceMenu(this));
		setState(state);

		state = new	Fases::LevelOne(this);
		setState(state);

		state = new Fases::LevelTwo(this);
		setState(state);

		state = dynamic_cast<States::State*>(new Menus::MenuLeaderboard(this));
		setState(state);

		state = dynamic_cast<States::State*>(new Menus::MenuNumPlayers(this));
		setState(state);

		state = dynamic_cast<States::State*>(new Menus::MenuLevel(this));
		setState(state);

		state = dynamic_cast<States::State*>(new Menus::MenuSobreOJogo(this));
		setState(state);

		state = dynamic_cast<States::State*>(new Menus::MenuGameOver(this, dynamic_cast<Fases::Level*>(StateMap[States::sID::Level1])));
		setState(state);

		state = dynamic_cast<States::State*>(new Menus::MenuPause(this));
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

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && (getRunningState() == States::sID::Level1 || getRunningState() == States::sID::Level2) && typingClock.getElapsedTime().asSeconds() >= 0.2)
			{
				changeRunningState(States::sID::Pause);
				typingClock.restart();
			}
			
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && (getRunningState() == States::sID::Pause)&& typingClock.getElapsedTime().asSeconds() >= 0.2)
			{
				if (getLastState() == States::sID::Level1)
				{
					changeRunningState(States::sID::Level1);
					typingClock.restart();
				}
				if (getLastState() == States::sID::Level2)
				{
					changeRunningState(States::sID::Level2);
					typingClock.restart();
				}
				
			}
			
		}
		updateRunningState();
		
	}

	void Game::render()
	{
		pGraphics->clear();

		renderRunningState();

		pGraphics->display();
	}

