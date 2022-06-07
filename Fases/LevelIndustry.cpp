#pragma once
#include "LevelIndustry.h"
//#include "../Entidades/Characters/Player.h"

namespace Fases {

void LevelIndustry::initLevelIndustry()
{
	if (!backgroundTexture.loadFromFile("InclusaoExterna/Imagens/Background/1lvlbg.png"))
	{
		std::cout << "ERROR::INITLEVEL::Erro ao carregar textura" << "\n";
	}
	backgroundBody.setTexture(backgroundTexture);
	isLevel1 = true;
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
	playerList.clear();
	structureList.clear();
	enemyList.clear();
	initLevel();
	initLevelIndustry();
}

}