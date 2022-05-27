#include "MenuEntrada.h"

namespace Menus {

//Tentar a conversao estatica para ponteiro de jogo
EntranceMenu::EntranceMenu(Game* pointerGame) : Menu(), State((StateControl*)pointerGame, sID::MainMenu), 
pG(pointerGame), title()
{
	Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();
	Button* button = NULL;
	
	//Botoes
	button = new Button(sf::Vector2f(100, 200), "Play");
	button->selected(true); //Play como primeiro selecionado
	ButtonVector.push_back(button);

	button = new Button(sf::Vector2f(100, 250), "LeaderBoard");
	ButtonVector.push_back(button);

	button = new Button(sf::Vector2f(100, 300), "Sobre o jogo");
	ButtonVector.push_back(button);

	button = new Button(sf::Vector2f(100, 350), "Quit");
	ButtonVector.push_back(button);


	//Titulo
	title.setString("CyberSamurai");
	title.setPosition(100, 50);
	title.setCharacterSize(75);

	/*
	sf::Font* fontAux; //Inicializar com parametro
	fontAux->loadFromFile("InclusaoExterna/Fonte/Cyber-BoldRustique.ttf");
	title.setFont(*fontAux);
	*/

	title.setFont(*pGM->loadFont("InclusaoExterna/Fonte/Cyber-BoldRustique.ttf"));

	delay.restart();
	max = 3;
}
EntranceMenu::~EntranceMenu()
{

}

void EntranceMenu::render()
{  
	Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();

	pGM->render(background);

	for (iB = ButtonVector.begin(); iB != ButtonVector.end(); iB++)
	{
		(*iB)->render();
	}

	pGM->render(&title);

}

void EntranceMenu::resetState()
{ 

	ButtonVector[sel]->selected(false); 
	sel = 0;
	ButtonVector[sel]->selected(true); 

}

void EntranceMenu::exec()
{

	Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();

	if (active) //Se o botao estiver ativo
	{
		active = false; //Desativa e entra no escolhido
		
		switch (sel) {
		case 0:
			updateState(sID::Playing);
			break;
		case 1:
			updateState(sID::Leaderboard);
			break;
		case 2:
			updateState(sID::SobreJogo);
			break;
		case 3:
			pGM->close();
			break;

		default:
			break;
		}

	}

}
	
void EntranceMenu::update(float dt)
{
	active = true;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && delay.getElapsedTime().asSeconds() >= 0.2) {
		printf("Down ");
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
