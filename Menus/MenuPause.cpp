#pragma once
#include "MenuPause.h"

namespace Menus{

	MenuPause::MenuPause(States::StateControl* pSC): Menu(), State((States::StateControl*)(pSC), States::sID::Pause)
	{
		Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();
		Button* button = NULL;

		button = new Button(sf::Vector2f(400, 300), "Retornar a partida");
		button->selected(true);
		ButtonVector.push_back(button);

		button = new Button(sf::Vector2f(400, 350), "Voltar ao Menu");
		ButtonVector.push_back(button);

		text = new sf::Text;
		text->setPosition(150, 60);
		text->setString("Game Paused");
		text->setFont(*pGM->loadFont("InclusaoExterna/Fonte/Cyber.ttf"));
		text->setCharacterSize(120);

		sel = 0;
		max = 1;
	}

	MenuPause::~MenuPause()
	{
		delete text;
	} 

	void MenuPause::render()
	{
		Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();

		pGM->render(background);

		for (iB = ButtonVector.begin(); iB != ButtonVector.end(); iB++)
		{
			(*iB)->render();
		}

		pGM->render(text);

	}

	void MenuPause::resetState()
	{
		for (iB = ButtonVector.begin(); iB != ButtonVector.end(); iB++)
			(*iB)->selected(false);
		sel = 0;
		ButtonVector[sel]->selected(true);
		active = true;
	}

	void MenuPause::exec()
	{
		if (active)
		{
			active = false;
			switch (sel) {
			case 0:
				if(getLState() == States::sID::Level1)
				updateState(States::sID::Level1); 

				if (getLState() == States::sID::Level2)
				updateState(States::sID::Level2);

				break;
			case 1:
				updateState(States::sID::MainMenu);
				break;
			default:
				break;
			}

		}

	}

	void MenuPause::update(float dt)
	{

		if (active == false)
		{
			delay.restart();
		}
		active = true;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && delay.getElapsedTime().asSeconds() >= 0.2) {
			Down();
			delay.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && delay.getElapsedTime().asSeconds() >= 0.2) {
			Up();
			delay.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && delay.getElapsedTime().asSeconds() >= 0.2) {
			exec();
			delay.restart();
		}
		

	}

} 