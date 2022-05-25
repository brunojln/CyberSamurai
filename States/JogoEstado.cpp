#include "JogoEstado.h"
#include "../Menus/MenuEntrada.h"
#include "../Menus/MenuLeaderboard.h"

#define TICK_RATE 0.0078125

Game::Game(): pGM(Managers::GraphicManager::getGraphics())
{
	clock.restart();
	dt = 0;

    
    State* states = new Level(this);
    /*setState(states);

    states = static_cast<State*>(new Menus::PauseMenuState(this, dynamic_cast<States::Level*>(mapOfStates[stateID::playing])));
    setState(states);*/

    states = static_cast<State*>(new EntranceMenu(this));
    setState(states);

    /*
    states = static_cast<State*>(new Menus::SettingsMenu(this));
    setState(states);*/

    states = static_cast<State*>(new MenuLeaderboard(this));
    setState(states);

    /*
    states = static_cast<State*>(new GameOverMenu(this, dynamic_cast<States::Level*>(mapOfStates[stateID::playing])));
    setState(states);*/

    changeRunningState(MainMenu);
    exe(); //Rodar o loop  
}

Game::~Game()
{
    
}


void Game::exe()
{
    
    while (pGM->WindowIsOpen()) {

        pGM->clear();

        if (dt < TICK_RATE) {
            dt += clock.getElapsedTime().asSeconds();
            clock.restart();
        }
        else {
            updateRunningState(0.01);
            dt -= TICK_RATE;
        }

        updateRunningState();

        pGM->display();
    }
}

void Game::end()
{
    pGM->close();
}