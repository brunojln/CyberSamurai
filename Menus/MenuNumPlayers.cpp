#include "MenuNumPlayers.h"

namespace Menus {

	MenuNumPlayers::MenuNumPlayers(States::StateControl* pSC): Menu(), State((pSC), States::sID::NumPlayers)
	{ 
		Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();
		Button* button = NULL;

		//Botoes
		button = new Button(sf::Vector2f(550, 200), "I Player");
		button->selected(true); //Play como primeiro selecionado
		ButtonVector.push_back(button);

		button = new Button(sf::Vector2f(550, 250), "II Players");
		ButtonVector.push_back(button);

		button = new Button(sf::Vector2f(550, 600), "Voltar");
		ButtonVector.push_back(button);

		text = new sf::Text;
		text->setString("Controles Player 1:\nD: Direita\nA: Esquerda\nBarra de Espaco: Pular\nG: Atacar");
		text->setCharacterSize(30);
		text->setPosition(100, 500);
		text->setLineSpacing(1.3);
		text->setFont(*pGM->loadFont("InclusaoExterna/Fonte/NEONLEDLight.otf"));

		text2 = new sf::Text;
		text2->setString("Controles Player 2:\nSeta Direita: Direita\nSeta Esquerda: Esquerda\nSeta Cima: Pular\nK: Atacar");
		text2->setCharacterSize(30);
		text2->setPosition(850, 500);
		text2->setLineSpacing(1.3);
		text2->setFont(*pGM->loadFont("InclusaoExterna/Fonte/NEONLEDLight.otf"));
		
		max = 2;
	} 

	MenuNumPlayers::~MenuNumPlayers()
	{
		delete text;
		delete text2;
	} 

	void MenuNumPlayers::render()
	{ 
		Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();

		pGM->render(background);

		for (iB = ButtonVector.begin(); iB != ButtonVector.end(); iB++)
		{
			(*iB)->render();
		}

		pGM->render(text);
		pGM->render(text2);

	} 

	void MenuNumPlayers::resetState()
	{ 
		ButtonVector[sel]->selected(false);
		sel = 0;
		ButtonVector[sel]->selected(true);
	} 

	void MenuNumPlayers::exec()
	{
		if (active) //Se o botao estiver ativo
		{
			active = false; //Desativa e entra no escolhido

			switch (sel) {
			case 0:
				//1 player instanciado
				updateState(States::sID::Level);
				break;
			case 1:
				//2 players instanciados
				updateState(States::sID::Level);
				break;
			case 2:
				updateState(States::sID::MainMenu);
				break;

			default:
				break;
			}

		}
	}

	void MenuNumPlayers::update(float dt)
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