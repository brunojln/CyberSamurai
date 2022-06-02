#include "MenuLevel.h"


namespace Menus {

	MenuLevel::MenuLevel(States::StateControl* pSC) : Menu(), State((pSC), States::sID::Level)
	{
		Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();
		Button* button = NULL;

		//Botoes
		button = new Button(sf::Vector2f(550, 200), "Level I");
		button->selected(true); //Play como primeiro selecionado
		ButtonVector.push_back(button);

		button = new Button(sf::Vector2f(550, 250), "Level II");
		ButtonVector.push_back(button);

		button = new Button(sf::Vector2f(550, 600), "Voltar");
		ButtonVector.push_back(button);

		max = 2;
	}
	MenuLevel::~MenuLevel()
	{

	}

	void MenuLevel::render()
	{
		Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();

		pGM->render(background);

		for (iB = ButtonVector.begin(); iB != ButtonVector.end(); iB++)
		{
			(*iB)->render();
		}
	}

	void MenuLevel::resetState()
	{
		ButtonVector[sel]->selected(false);
		sel = 0;
		ButtonVector[sel]->selected(true);
	}

	void MenuLevel::exec()
	{
		if (active) //Se o botao estiver ativo
		{
			active = false; //Desativa e entra no escolhido

			switch (sel) {
			case 0:
				/*
				Primeira fase*/
				updateState(States::sID::Level1);
				break;
			case 1:
				/*
				Segunda Fase
				updateState(sID::);
				break;*/
			case 2:
				updateState(States::sID::MainMenu);
				break;

			default:
				break;
			}

		}
	}

	void MenuLevel::update(float dt)
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