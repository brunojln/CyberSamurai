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

		comands = new sf::Text;
		comands->setString("Controles Player 1:\nD: Direita\nA: Esquerda\nBarra de Espaco: Pular\nG: Atacar");
		comands->setCharacterSize(30);
		comands->setPosition(100, 500);
		comands->setLineSpacing(1.3);
		comands->setFont(*pGM->loadFont("InclusaoExterna/Fonte/NEONLEDLight.otf"));

		comands2 = new sf::Text;
		comands2->setString("Controles Player 2:\nSeta Direita: Direita\nSeta Esquerda: Esquerda\nSeta Cima: Pular\nK: Atacar");
		comands2->setCharacterSize(30);
		comands2->setPosition(850, 500);
		comands2->setLineSpacing(1.3);
		comands2->setFont(*pGM->loadFont("InclusaoExterna/Fonte/NEONLEDLight.otf"));


		sel = 0;
		max = 1;
	}

	MenuPause::~MenuPause()
	{
		delete text;
		delete comands;
		delete comands2;
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
		pGM->render(comands);
		pGM->render(comands2);

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

	void MenuPause::update()
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