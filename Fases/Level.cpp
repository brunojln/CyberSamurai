#include "Level.h"

//namespace Fases {

	Level::Level(StateControl* pSC) :
		pGraphics(Managers::GraphicManager::getGraphics()),
		State(pSC, sID::Playing)
	{
		//player = p;
	}

	Level::~Level()
	{
	}

	void Level::update()
	{
	}

	void Level::render()
	{
	}


//}
