#include "MenuEntrada.h"

//Tentar a conversao estatica para ponteiro de jogo
EntranceMenu::EntranceMenu(Game* pointerGame) : Menu(), State((StateControl*)pointerGame, sID::EntranceMenu), pG(pointerGame), title()
{
	//Pegar instancia do gerenciador grafico 
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

	sf::Font* fontAux; //Inicializar com parametro
	fontAux->loadFromFile("InclusaoExterna/Fonte/Cyber-BoldRustique.ttf");
	title.setFont(*fontAux);


}
EntranceMenu::~EntranceMenu()
{

}

void EntranceMenu::render()
{  
	//updateScreen();

	//back.render();

	for (iB = ButtonVector.begin(); iB != ButtonVector.end(); iB++)
	{
		(*iB)->render();
	}

	//title.render(); falta o gerenciador grafico

}
void EntranceMenu::resetState()
{ 

	// ButtonVector[sel]->select(false); select do gerenciador grafico
	sel = 0;
	// ButtonVector[sel]->select(true); select do gerenciador grafico

}

void EntranceMenu::exec()
{
	if (active) //Se o botao estiver ativo
	{
		active = false; //Como mudar isso?
		
		switch (sel) {
		case 0:
			updateState(sID::Play);
			break;
		case 1:
			updateState(sID::Leaderboard);
			break;
		case 2:
			updateState(sID::SobreJogo);
			break;
		case 3:
			// pGame->endGame();
			break;

		default:
			break;
		}

	}

}

