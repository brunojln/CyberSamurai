#pragma once
#include "LevelOne.h"
//#include "../Entidades/Characters/Player.h"

namespace Fases {

void LevelOne::initLevel()
{
	if (!backgroundTexture.loadFromFile("InclusaoExterna/Imagens/Background/1lvlbg.png"))
	{
		std::cout << "ERROR::INITLEVEL::Erro ao carregar textura" << "\n";
	}
	backgroundBody.setTexture(backgroundTexture);

}

LevelOne::LevelOne(States::StateControl* pSC):
	Level(States::sID::Level1, pSC)
{
	initLevel();
}

LevelOne::~LevelOne()
{
}

}