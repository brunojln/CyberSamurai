#include "Level.h"

Level::Level(StateControl* pSC) :
	pGraphics(Managers::GraphicManager::getGraphics()),
	State(pSC, sID::Playing)
{
	//player = p;
}

Level::~Level()
{
}

