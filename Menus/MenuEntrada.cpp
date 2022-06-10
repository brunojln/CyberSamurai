#include "MenuEntrada.h"

namespace Menus {

	//Tentar a conversao estatica para ponteiro de jogo
	EntranceMenu::EntranceMenu(Game* pointerGame): 
		Menu(), 
		State((States::StateControl*)pointerGame, States::sID::MainMenu),
		pG(pointerGame), 
		title()
	{
		Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();
		Button* button = NULL;

		//Botoes
		button = new Button(sf::Vector2f(100, 200), "Play");
		button->selected(true); //Play como primeiro selecionado
		ButtonVector.push_back(button);

		button = new Button(sf::Vector2f(100, 250), "LeaderBoard");
		ButtonVector.push_back(button);

		button = new Button(sf::Vector2f(100, 300), "Load Save");
		ButtonVector.push_back(button);

		button = new Button(sf::Vector2f(100, 350), "Sobre o jogo");
		ButtonVector.push_back(button);

		button = new Button(sf::Vector2f(100, 400), "Quit");
		ButtonVector.push_back(button);


		//Titulo
		title.setString("CyberSamurai");
		title.setPosition(100, 50);
		title.setCharacterSize(75);

		title.setFont(*pGM->loadFont("InclusaoExterna/Fonte/Cyber.ttf"));

		delay.restart();

		max = 4;
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
		std::ifstream levelFile("InclusaoExterna/Saves/Level.txt", std::ios::in);
		bool level1;

		if (active) //Se o botao estiver ativo
		{
			active = false; //Desativa e entra no escolhido

			switch (sel) {
			case 0:
				updateState(States::sID::NumPlayers);
				break;
			case 1:
				updateState(States::sID::Leaderboard);
			case 2:
				if (!levelFile) { std::cout << "ERROR::carregar jogo salvo"; exit(1); }

				while (!levelFile.eof()) {
					levelFile >> level1;
				}

				if (level1) {
					updateState(States::sID::Level1);
				}
				else {
					updateState(States::sID::Level2);
				}
				break;
			case 3: 
				updateState(States::sID::SobreJogo);
				break;
			case 4:
				pGM->close();
				break;

			default:
				break;
			}

		}

	}

	void EntranceMenu::update()
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
