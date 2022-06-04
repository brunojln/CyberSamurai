#include "MenuGameOver.h"

namespace Menus {
	MenuGameOver::MenuGameOver(States::StateControl* pSC, Fases::Level* pLevel) :
		Menu(), State(pSC, States::sID::GameOver), StringName(""), pLevel(pLevel)
	{
		Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();
		Button* button = NULL;

		//Unico botao de retornar
		button = new Button(sf::Vector2f(400, 570), "Jogar novamente");
		button->selected(true);
		ButtonVector.push_back(button);

		button = new Button(sf::Vector2f(400, 630), "Voltar ao Menu");
		ButtonVector.push_back(button);

		title.setPosition(250, 60);
		title.setString("Game Over");
		title.setFont(*pGM->loadFont("InclusaoExterna/Fonte/Cyber.ttf"));
		title.setCharacterSize(120);

		points.setPosition(500, 300);
		points.setString("Points: " + std::to_string(pLevel->getPlayerPoints()) + "\nName: ");
		points.setFont(*pGM->loadFont("InclusaoExterna/Fonte/NEONLEDLight.otf"));
		points.setCharacterSize(60);

		name.setPosition(700, 363);
		name.setFont(*pGM->loadFont("InclusaoExterna/Fonte/NEONLEDLight.otf"));
		name.setCharacterSize(50);

		sel = 0;
		max = 1;

	}
	MenuGameOver::~MenuGameOver() {}

	std::string MenuGameOver::getString()
	{

		//LETRAS -------------------------------------------------------------------------------------
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "A"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "B"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "C"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "D"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "E"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "F"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "G"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::H) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "H"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "I"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "J"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "K"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "L"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "M"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::N) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "N"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "O"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "P"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "Q"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "R"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "S"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "T"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::U) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "U"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::V) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "V"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "W"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "X"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "Y"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "Z"; typingClock.restart();
		}


		//NUMEROS -----------------------------------------------------------------------------------
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "1"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "2"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "3"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "4"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "5"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "6"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "7"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "8"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "9"; typingClock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + "0"; typingClock.restart();
		}


		//SIMBOLOS -----------------------------------------------------------------------------------
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			try 
			{
				if (StringName.size() > 0)
					StringName.pop_back();
				else
					throw(1);
			}
			catch (int erro)
			{
				std::cout << "ERROR:OUT OF RANGE::ERRROR:" << erro << std::endl;
			}
			typingClock.restart();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && typingClock.getElapsedTime().asSeconds() >= 0.2)
		{
			StringName = StringName + " "; typingClock.restart();
		}

		return StringName;
	}

	void MenuGameOver::update(float dt)
	{
		name.setString(getString());
		points.setString("Points: " + std::to_string(pLevel->getPlayerPoints()) + "\nName: ");

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

	void MenuGameOver::render()
	{
		Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();
		pGM->render(background);

		for (iB = ButtonVector.begin(); iB != ButtonVector.end(); iB++)
		{
			(*iB)->render();
		}

		pGM->render(&title);
		pGM->render(&points);
		pGM->render(&name);
		pGM->render(&playerName);
	}
	void MenuGameOver::exec()
	{
		if (active)
		{
			active = false;
			switch (sel) {
			case 0:
				updateState(States::sID::NumPlayers); //Adaptar para lvl2
				break;
			case 1:
				updateState(States::sID::MainMenu);
				break;
			default:
				break;
			}

			saveLeaderBoard();
		}
	}
	void MenuGameOver::resetState()
	{
		for (iB = ButtonVector.begin(); iB != ButtonVector.end(); iB++)
			(*iB)->selected(false);
		sel = 0;
		ButtonVector[sel]->selected(true);
		active = true;

	}
	void MenuGameOver::saveLeaderBoard()
	{
		int playerPoints = pLevel->getPlayerPoints(); //= plvl->getPlayerPoints();

		std::ifstream readFile;

		readFile.open("./InclusaoExterna/Leaderboard/LeaderboardSave.txt", std::ios::in);

		std::multimap<int, std::string> pointsAndNamesMap;

		if (readFile) {

			unsigned int points;
			std::string name;
			std::string pointsString;

			for (int i = 0; i < 10; i++) {
				std::getline(readFile, pointsString);
				std::getline(readFile, name);
				if (pointsString.length() > 0)
					pointsAndNamesMap.insert(std::pair<int, std::string>(std::stoi(pointsString), name));
			}

			readFile.close();
		}

		/* ================================= Writing File ================================= */
		if (playerPoints != 0 && getString().length() > 1)
			pointsAndNamesMap.insert(std::pair<int, std::string>(playerPoints, getString()));

		std::ofstream writeFile;

		writeFile.open("./InclusaoExterna/Leaderboard/LeaderboardSave.txt", std::ios::out | std::ios::trunc);

		if (!writeFile) {
			std::cout << "ERROR::GAMEOVERMENU::WRITINGFILE" << std::endl;
			exit(1);
		}

		while (pointsAndNamesMap.size() > 10)
			pointsAndNamesMap.erase(pointsAndNamesMap.begin());

		for (auto iT = pointsAndNamesMap.rbegin(); iT != pointsAndNamesMap.rend(); iT++) {
			writeFile << (*iT).first << std::endl;
			writeFile << (*iT).second << std::endl;
		}

		writeFile.close();
	}

}