#include "Level.h"

//namespace Fases {

	Level::Level(sID id, StateControl* pSC) :
		State(pSC, id),
		pGraphics(Managers::GraphicManager::getGraphics()),
		endGame(false)
	{
		//objetos compartilhados por fases
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
		windowCollision(robot);

		collider.checkCollision(platform, player, 0.0f);
		collider.checkCollision(spikes, player, 0.6f);
		collider.checkCollision(elevator, player, 0.0f);

		player->update();
		platform->update();
		elevator->update();
		spikes->update();


		robot->update(player, collider.checkCollision(robot, player, 1.f));

		player->attack(robot, collider.checkCollision(robot, player, 1.f));
		//std::cout << player->getLifePoints() << "\n";
	}

	void Level::render()
	{
		Managers::GraphicManager* pGraphics = Managers::GraphicManager::getGraphics();
		pGraphics->render(&backgroundBody);
		// 
		// 		//renderizar os conteudos das listas
		// 
		spikes->render();
		platform->render();
		player->render(); //alterado para chamar pGraphics na Entity.cpp (talvez mudar isso)
		elevator->render();
		robot->render();
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


//}
