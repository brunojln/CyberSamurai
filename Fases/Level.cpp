#include "Level.h"

namespace Fases {

	Level::Level(States::sID id, States::StateControl* pSC) :
		State(pSC, id),
		pGraphics(Managers::GraphicManager::getGraphics()), twoPlayers(false), isNewLevel(true)
	{
	}

	void Level::endLevel()
	{
		for (int i = 0; i < playerList.size(); i++)
		{
			if (playerList[i]->getLifePoints() <= 0 || enemyList.getSize() <= 0)
			{
				std::cout << "endLevel\n";
				updateState(States::sID::GameOver);
			}
		}
	}

	void Level::setTwoPlayers(bool two_players)
	{
		twoPlayers = two_players;
	}

	void Level::saveLevel()
	{
		std::ofstream clear;

		clear.open("InclusaoExterna/Saves/Player.txt", std::ios::trunc);
		clear.close();
		clear.open("InclusaoExterna/Saves/Player2.txt", std::ios::trunc);
		clear.close();
		clear.open("InclusaoExterna/Saves/Flying.txt", std::ios::trunc);
		clear.close();
		clear.open("InclusaoExterna/Saves/Robot.txt", std::ios::trunc);
		clear.close();
		clear.open("InclusaoExterna/Saves/Boss.txt", std::ios::trunc);
		clear.close();
		clear.open("InclusaoExterna/Saves/Platform.txt", std::ios::trunc);
		clear.close();
		clear.open("InclusaoExterna/Saves/Spikes.txt", std::ios::trunc);
		clear.close();
		clear.open("InclusaoExterna/Saves/Elevator.txt", std::ios::trunc);
		clear.close();
		clear.open("InclusaoExterna/Saves/Level.txt", std::ios::trunc);
		clear.close();

		std::ofstream levelFile;

		levelFile.open("InclusaoExterna/Saves/Level.txt", std::ios::app);

		if (!levelFile) { std::cout << "ERROR::LEVEL::SAVE::Erro ao abrir arquivo"; exit(1); }

		levelFile << twoPlayers << ' ' << isLevel1 << ' ' << std::endl;
		levelFile.close();

		for (auto* player : this->playerList)
		{
			player->save();
			std::cout << "Player salvo\n";
		}

		for (int i = 0; i < enemyList.getSize(); i++)
		{
			enemyList[i]->save();
		}

		for (int i = 0; i < structureList.getSize(); i++)
		{
			structureList[i]->save();
		}
	}

	const int Level::getPlayerPoints() const
	{
		int playerPoints = 0;
		for (int i = 0; i < playerList.size(); i++)
		{
			playerPoints += playerList[i]->getExp();
			std::cout << "Somando pontos " << playerPoints << std::endl;
		}
		std::cout << "\n";
		return playerPoints;
	}

	Level::~Level()
	{
		//pSC = nullptr;
	}

	void Level::update()
	{
		endLevel();

		for (int i = 0; i < playerList.size(); i++)
		{
			playerList[i]->update();
			windowCollision(playerList[i]);
			//std::cout << playerList[i]->getExp() << "\n";
		}

		for (int i = 0; i < structureList.getSize(); i++)
		{
			structureList[i]->update();
			updateStructureList(structureList[i], i);
		}

		for (int i = 0; i < enemyList.getSize(); i++)
		{
			enemyList[i]->update();
			windowCollision(enemyList[i]);
			updateEnemyList(enemyList[i], i);
		}

		endLevel();
		//std::cout << player->getLifePoints() << "\n";
	}

	void Level::render()
	{
		Managers::GraphicManager* pGraphics = Managers::GraphicManager::getGraphics();

		pGraphics->render(&backgroundBody);

		for (int i = 0; i < playerList.size(); i++) {

			playerList[i]->render();
		}

		for (int i = 0; i < structureList.getSize(); i++)
		{
			structureList[i]->render();
		}

		for (int i = 0; i < enemyList.getSize(); i++)
		{
			enemyList[i]->render();
		}
	
	
	}

	void Level::initLevel()
	{
		if (getLState() != States::sID::MainMenu) //significa que entrou no MenuNumPlayers ou MenuLevel
		{
			//cria jogo novo
			isNewLevel = true;
			srand(time(NULL));

			if (twoPlayers) {
				playerList.push_back(new Entities::Player(true));
			}

			playerList.push_back(new Entities::Player(false));

			int randPlayer = 0;

			//criação aleatória de Robot e Flying
			for (int i = 0; i < ((rand() % 7) + 3); i++) {
				Entities::Robot* pRobot = new Entities::Robot((i * 100.f), (i * 100.f), false);

				randPlayer = rand() % playerList.size();

				pRobot->setPlayerIndex(randPlayer);
				pRobot->setPlayer(playerList[randPlayer]);
				enemyList.push_back(pRobot);
				pRobot = NULL;
			}

			for (int i = 0; i < ((rand() % 3) + 3); i++) {
				Entities::Flying* pFlying = new Entities::Flying((i * 100.f), (i * 100.f));

				randPlayer = rand() % playerList.size();

				pFlying->setPlayerIndex(randPlayer);
				pFlying->setPlayer(playerList[randPlayer]);
				enemyList.push_back(pFlying);
				pFlying = NULL;
			}

			//criação aleatória de obstáculos Spikes, Elevator, Platform
			for (int i = 0; i < ((rand() % 1) + 3); i++)
			{
				// * 1.f para tirar warning de conversão int p/ float.
				structureList.push_back(new Entities::Spikes((rand() % 1100) * 1.f, (rand() % 600) * 1.f));
				structureList.push_back(new Entities::Elevator((rand() % 1100) * 1.f, (rand() % 600) * 1.f));
				structureList.push_back(new Entities::Platform((rand() % 11) * 100.f, 300.f));
			}
		}
		else //saiu direto de EntranceMenu (clicou carregar save)
		{
			//carregar jogo previamente salvo
			isNewLevel = false;
			sf::Vector2f position;
			int lifePoints, expPoints, playerIndex;
			//--------------------------------------------------------------------------------
			std::ifstream levelFile("InclusaoExterna/Saves/Level.txt", std::ios::in);
			if (!levelFile) { std::cout << "ERROR::carregar jogo salvo"; exit(1); }

			levelFile >> twoPlayers;

			levelFile.close();
			//--------------------------------------------------------------------------------
			std::ifstream playerFile("InclusaoExterna/Saves/Player.txt", std::ios::in);
			if (!playerFile) { std::cout << "ERROR::carregar jogo salvo"; exit(1); }
		
			playerFile >> position.x >> position.y >> lifePoints >> expPoints;
			Entities::Player* player = new Entities::Player(false);
			player->setLifePoints(lifePoints);
			player->setPosition(position.x, position.y);
			player->setExp(expPoints);

			playerList.push_back(player);
			
			playerFile.close();
			//------------------------------------------------------------------------------
			if (twoPlayers)
			{
				std::ifstream player2File("InclusaoExterna/Saves/Player2.txt", std::ios::in);
				if (!player2File) { std::cout << "ERROR::carregar jogo salvo"; exit(1); }

				player2File >> position.x >> position.y >> lifePoints >> expPoints;
		
				Entities::Player* player2 = new Entities::Player(true);
				player2->setLifePoints(lifePoints);
				player2->setPosition(position.x, position.y);
				player2->setExp(expPoints);

				playerList.push_back(player2);
			
				playerFile.close();
			}
			//------------------------------------------------------------------------------
			std::ifstream spikesFile("InclusaoExterna/Saves/Spikes.txt", std::ios::in);
			if (!spikesFile) { std::cout << "ERROR::carregar jogo salvo"; exit(1); }

			while (spikesFile >> position.x >> position.y) {
				structureList.push_back(new Entities::Spikes(position.x, position.y));
			}
			spikesFile.close();
			//------------------------------------------------------------------------------
			std::ifstream elevatorFile("InclusaoExterna/Saves/Elevator.txt", std::ios::in);
			if (!elevatorFile) { std::cout << "ERROR::carregar jogo salvo"; exit(1); }

			while (elevatorFile >> position.x >> position.y) {
				structureList.push_back(new Entities::Elevator(position.x, position.y));
			}
			elevatorFile.close();
			//------------------------------------------------------------------------------
			std::ifstream platformFile("InclusaoExterna/Saves/Platform.txt", std::ios::in);
			if (!platformFile) { std::cout << "ERROR::carregar jogo salvo"; exit(1); }

			while (platformFile >> position.x >> position.y) {
				structureList.push_back(new Entities::Platform(position.x, position.y));
			}
			platformFile.close();
			//------------------------------------------------------------------------------
			std::ifstream flyingFile("InclusaoExterna/Saves/Flying.txt", std::ios::in);
			if (!flyingFile) { std::cout << "ERROR::carregar jogo salvo"; exit(1); }

			while (flyingFile >> position.x >> position.y >> lifePoints >> playerIndex) {
				Entities::Flying* flying = new Entities::Flying(position.x, position.y);
				flying->setLifePoints(lifePoints);
				std::cout << playerIndex << "\n";
				flying->setPlayer(playerList[playerIndex]);
				enemyList.push_back(flying);
				std::cout << "\n";
			}
			flyingFile.close();
			//------------------------------------------------------------------------------
			std::ifstream robotFile("InclusaoExterna/Saves/Robot.txt", std::ios::in);
			if (!robotFile) { std::cout << "ERROR::carregar jogo salvo"; exit(1); }

			bool isGolden;

			while (robotFile >> position.x >> position.y >> lifePoints >> playerIndex >> isGolden) {
				Entities::Robot* robot = new Entities::Robot(position.x, position.y, isGolden);
				robot->setLifePoints(lifePoints);
				robot->setPlayer(playerList[playerIndex]);
				enemyList.push_back(robot);
			}
			robotFile.close();
			//------------------------------------------------------------------------------
			std::ifstream bossFile("InclusaoExterna/Saves/Boss.txt", std::ios::in);
			if (!bossFile) { std::cout << "ERROR::carregar jogo salvo"; exit(1); }

			while (bossFile >> position.x >> position.y >> lifePoints >> playerIndex) {
				Entities::Boss* boss = new Entities::Boss(position.x, position.y);
				boss->setLifePoints(lifePoints);

				boss->setPlayer(playerList[playerIndex]);
				enemyList.push_back(boss);
			}
			bossFile.close();
			//------------------------------------------------------------------------------
		}
	}

	void Level::windowCollision(Entities::Entity* player)
	{
		Managers::GraphicManager* pGraphics = Managers::GraphicManager::getGraphics();

		if (player->getPosition().y + player->getGlobalBounds().height >= pGraphics->getWindow()->getSize().y)
		{
			player->resetVelocityY();
			player->setPosition(player->getPosition().x,
				pGraphics->getWindow()->getSize().y - player->getGlobalBounds().height);
			player->setCanJump(true);
		}
		//collision top screen
		else if (player->getPosition().y <= 0.f)
		{
			player->resetVelocityY();
			player->setPosition(player->getPosition().x, 0.f);
		}
	}

	void Level::updateEnemyList(Entities::Entity* pEntity, unsigned int i)
	{
		Entities::Character* pChar = static_cast <Entities::Character*>(pEntity);

		for (int i = 0; i < playerList.size(); i++) {

			if (pChar != NULL)
			{
				bool colliding = collider.checkCollision(pChar, playerList[i], 1.0f, false);
				if (pChar->getLifePoints() <= 0)
				{
					playerList[i]->setExp(playerList[i]->getExp() + pChar->getExp());
					std::cout << (*playerList[i]);
					enemyList.EntityDelete(i);
					pChar = NULL;
				}
				else
				{
					pChar->setIsNear(colliding);
					playerList[i]->attack(pChar, colliding);
				}
			}
		}
	}

	void Level::updateStructureList(Entities::Entity* pEntity, unsigned int i)
	{
		for (int i = 0; i < playerList.size(); i++) {

			Entities::Structures* pStruct = static_cast <Entities::Structures*>(pEntity);
			bool colliding = collider.checkCollision(pStruct, playerList[i], 0.0f, false);

			if (pStruct != NULL)
			{
				if (pStruct->isDamaging() && colliding)
				{
					playerList[i]->setisTakingDamage(true);
					playerList[i]->setLifePoints(playerList[i]->getLifePoints() - pStruct->getStructureDamage());
				}
			}
		}
	}
} //namespace fases
