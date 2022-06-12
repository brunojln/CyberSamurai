#include "LevelCity.h"

void Fases::LevelCity::initLevelCity()
{
	if (!backgroundTexture.loadFromFile("InclusaoExterna/Imagens/Background/2lvlbg.png"))
	{
		std::cout << "ERROR::INITLEVEL::Erro ao carregar textura" << "\n";
	}
	backgroundBody.setTexture(backgroundTexture);

	isLevel1 = false;

	if (isNewLevel){
		int randPlayer = rand() % playerList.size();
		pBoss = new Entities::Boss(300, 0);

		pBoss->setPlayerIndex(randPlayer);
		pBoss->setPlayer(playerList[randPlayer]);
		enemyList.push_back(pBoss);
	}
}

Fases::LevelCity::LevelCity(States::StateControl* pSC) :
	Level(States::sID::Level2, pSC)
{
	
}

Fases::LevelCity::~LevelCity()
{
	delete pBoss;
	pBoss = NULL;
}

void Fases::LevelCity::resetState()
{
	if (getLState() != States::sID::Pause)
	{
		playerList.clear();
		structureList.clear();
		enemyList.clear();
		initLevel();
		initLevelCity();
		
	}
	
}
