#pragma once
#include "LevelIndustry.h"

namespace Fases {

void LevelIndustry::initLevelIndustry()
{
	if (!backgroundTexture.loadFromFile("InclusaoExterna/Imagens/Background/1lvlbg.png"))
	{
		std::cout << "ERROR::INITLEVEL::Erro ao carregar textura" << "\n";
	}
	backgroundBody.setTexture(backgroundTexture);
	isLevel1 = true;

	if (isNewLevel){
		int randPlayer = rand() % playerList.size();
		pGoldenRobot = new Entities::Robot(0, 0, true);
		pGoldenRobot->setExp(100);
		pGoldenRobot->setPlayerIndex(randPlayer);
		pGoldenRobot->setPlayer(playerList[randPlayer]);

		enemyList.push_back(pGoldenRobot);
	}
}

LevelIndustry::LevelIndustry(States::StateControl* pSC):
	Level(States::sID::Level1, pSC)
{
}

LevelIndustry::~LevelIndustry()
{
}

void LevelIndustry::resetState()
{
	if (getLState() != States::sID::Pause)
	{
		playerList.clear();
		structureList.clear();
		enemyList.clear();
		initLevel();
		initLevelIndustry();
	}
}

}