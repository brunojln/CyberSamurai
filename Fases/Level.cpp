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
		//std::cout << "update";
	}

	void Level::render()
	{
		Managers::GraphicManager* pGraphics = Managers::GraphicManager::getGraphics();
		pGraphics->render(&body);
		//std::cout << "render";
	}

	void Level::resetState()
	{
		if (endGame) {
			std::cout << "Resetar tudo aqui";
		}
	}


//}
