#include "JogoEstado.h"

Game::Game(): pGM(Managers::GraphicManager::getGraphics())
{
	time.restart();
	t = 0;

    /*
    State* states = newLevel(this);
    insertState(states);

    states = static_cast<State*>(new Menus::PauseMenuState(this, dynamic_cast<States::Level*>(mapOfStates[stateID::playing])));
    insertState(states);

    states = static_cast<State*>(new Menus::MainMenuState(this));
    insertState(states);

    states = static_cast<State*>(new Menus::SettingsMenu(this));
    insertState(states);

    states = static_cast<State*>(new Menus::LeaderboardMenu(this));
    insertState(states);

    states = static_cast<State*>(new Menus::GameOverMenu(this, dynamic_cast<States::Level*>(mapOfStates[stateID::playing])));
    insertState(states);

    changeCurrentState(stateID::mainMenu);*/

}

Game::~Game()
{
    
}


void Game::exe()
{
    /*
    while (pGM->WindowIsOpen()) {



        pGM->clear();

        if (dt < TICK_RATE) {
            dt += clock.getElapsedTime().asSeconds();
            clock.restart();
        }
        else {
            updateCurrentState(0.01);
            dt -= TICK_RATE;
        }

        renderCurrentState();

        pGM->display();
    }*/
}

void Game::end()
{
    pGM->close();
}