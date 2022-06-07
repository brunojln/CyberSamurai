#include "Level.h"

namespace Fases {

	Level::Level(States::sID id, States::StateControl* pSC) :
		State(pSC, id),
		pGraphics(Managers::GraphicManager::getGraphics()), twoPlayers(false)
	{
	}

	void Level::endLevel()
	{
		for (int i = 0; i < playerList.size(); i++)
		{
			if (playerList[i]->getLifePoints() <= 0 || enemyList.getSize() == 0)
			{
				updateState(States::sID::GameOver);
			}
		}
	}

	void Level::setTwoPlayers(bool two_players)
	{
		twoPlayers = two_players;
	}

	const int Level::getPlayerPoints() const
	{
		int playerPoints = 0;
		for (int i = 0; i < playerList.size(); i++)
		{
			playerPoints += playerList[i]->getExp();
		}
		return playerPoints;
	}

	Level::~Level()
	{
		//pSC = nullptr;
	}

	void Level::update()
	{

		for (int i = 0; i < playerList.size(); i++)
		{
			playerList[i]->update();
			windowCollision(playerList[i]);
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
		//std::cout << player->getLifePoints() << "\n";
		endLevel();
	}

	void Level::render()
	{
		Managers::GraphicManager* pGraphics = Managers::GraphicManager::getGraphics();

		pGraphics->render(&backgroundBody);

		//player->render(); //alterado para chamar pGraphics na Entity.cpp (talvez mudar isso)
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
		srand(time(NULL));

		if (twoPlayers) {
			playerList.push_back(new Entities::Player(true));
		}

		playerList.push_back(new Entities::Player(false));

		int randPlayer = 0;

		//criação aleatória de Robot e Flying
		for (int i = 0; i < ((rand() % 7) + 3); i++) {
			Entities::Robot* pRobot = new Entities::Robot((i * 100.f), (i * 100.f));

			randPlayer = rand() % playerList.size();

			pRobot->setPlayer(playerList[randPlayer]);
			enemyList.push_back(pRobot);
			pRobot = NULL;
		}

		for (int i = 0; i < ((rand() % 3) + 3); i++) {
			Entities::Flying* pFlying = new Entities::Flying((i * 100.f), (i * 100.f));

			randPlayer = rand() % playerList.size();

			pFlying->setPlayer(playerList[randPlayer]);
			enemyList.push_back(pFlying);
			pFlying = NULL;
		}

		//criação aleatória de obstáculos
		for (int i = 0; i < ((rand() % 1) + 3); i++)
		{
			structureList.push_back(new Entities::Spikes((rand() % 1100), (rand() % 600)));
			structureList.push_back(new Entities::Elevator((rand() % 1100), (rand() % 600)));
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
		for (int i = 0; i < playerList.size(); i++) {

			Entities::Character* pChar = static_cast <Entities::Character*>(pEntity);
			bool colliding = collider.checkCollision(pChar, playerList[i], 1.0f, false);
			if (pChar != NULL)
			{
				if (pChar->getLifePoints() <= 0)
				{
					playerList[i]->setExp(playerList[i]->getExp() + pChar->getExp());
					//std::cout << player->getExp() + pChar->getExp() << "\n";
					enemyList.EntityDelete(i);
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
