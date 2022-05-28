#include "Level.h"

//namespace Fases {

	Level::Level(StateControl* pSC) :
		State(pSC, sID::Playing),
		pGraphics(Managers::GraphicManager::getGraphics()),
		endGame(false)
	{

	}

	Level::~Level()
	{
		//pSC = nullptr;
	}

	void Level::update(const float dt)
	{
		//percorrer pela lista e chamar o método update de todos
		player->update();
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
		//usado para testes

		//std::cout << platform->getPosition().x << " " << platform->getPosition().y;
	}

	void Level::resetState()
	{
		if (endGame) {
			std::cout << "Resetar tudo aqui";
		}
	}


//}
