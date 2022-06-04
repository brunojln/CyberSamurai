#include "LevelTwo.h"

void Fases::LevelTwo::initLevelTwo()
{
	if (!backgroundTexture.loadFromFile("InclusaoExterna/Imagens/Background/2lvlbg.png"))
	{
		std::cout << "ERROR::INITLEVEL::Erro ao carregar textura" << "\n";
	}
	backgroundBody.setTexture(backgroundTexture);


	int randPlayer = rand() % playerList.size();
	Entities::Boss* boss = new Entities::Boss(300, 0);
	boss->setPlayer(playerList[randPlayer]);
	enemyList.push_back(boss);
}

Fases::LevelTwo::LevelTwo(States::StateControl* pSC) :
	Level(States::sID::Level2, pSC)
{
	initLevelTwo();
}

Fases::LevelTwo::~LevelTwo()
{
}
