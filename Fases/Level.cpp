#include "Level.h"

//namespace Fases {

	Level::Level(sID id, StateControl* pSC) :
		State(pSC, id),
		pGraphics(Managers::GraphicManager::getGraphics()),
		endGame(false)
	{

		player = new Entities::Player();

		for (int i = 0; i < ((rand() % 7) + 3); i++) {
			Entities::Robot* pRobot = new Entities::Robot((i * 100), (i * 100));

			pRobot->setPlayer(player);
			enemyList.push_back(pRobot);
			pRobot = NULL;
		}

		for (int i = 0; i < ((rand() % 7) + 3); i++) {
			Entities::Flying* pFlying = new Entities::Flying((i * 100), (i * 100));

			pFlying->setPlayer(player);
			enemyList.push_back(pFlying);
			pFlying = NULL;
		}
	}

	void Level::endLevel()
	{
		if (player->getLifePoints() <= 0)
		{
			updateState(sID::MainMenu);
		}
		
	}

	Level::~Level()
	{
		//pSC = nullptr;
	}

	void Level::update(const float dt)
	{
		//percorrer pela lista e chamar o método update de todos
		windowCollision(player);
		windowCollision(spikes);

		player->update();

		for (int i = 0; i < structureList.getSize(); i++)
		{
			collider.checkCollision(structureList[i], player, 0.0f);
			structureList[i]->update();
		}

		//com voador com fica(?)

		for (int i = 0; i < enemyList.getSize(); i++)
		{
			enemyList[i]->update();
			windowCollision(enemyList[i]);
			updateList(enemyList[i], i);
		}
		std::cout << player->getLifePoints() << "\n";
		endLevel();
	}

	void Level::render()
	{
		Managers::GraphicManager* pGraphics = Managers::GraphicManager::getGraphics();

		pGraphics->render(&backgroundBody);

		player->render(); //alterado para chamar pGraphics na Entity.cpp (talvez mudar isso)

		for (int i = 0; i < structureList.getSize(); i++)
		{
			structureList[i]->render();
		}

		for (int i = 0; i < enemyList.getSize(); i++)
		{
			enemyList[i]->render();
		}
	
		//usado para testes
		player->updateHearts(pGraphics->getWindow());
	
	}

	void Level::resetState()
	{
		if (endGame) {
			std::cout << "Resetar tudo aqui";
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

	void Level::updateList(Entities::Entity* pEntity, unsigned int i)
	{
		Entities::Character* pChar = static_cast <Entities::Character*>(pEntity);
		bool colliding = collider.checkCollision(pChar, player, 1.0f);
		if (pChar != NULL)
		{
			if (pChar->getLifePoints() <= 0)
			{
				enemyList.EntityDelete(i);
			}
			else
			{
				pChar->setIsNear(colliding);
				player->attack(pChar,colliding);
			}
		}
	}


//}
