#include "LevelTwo.h"

void Fases::LevelTwo::initLevelTwo()
{
	//alterar isso
	if (!backgroundTexture.loadFromFile("InclusaoExterna/Imagens/Background/levelBackground.png"))
	{
		std::cout << "ERROR::INITLEVEL::Erro ao carregar textura" << "\n";
	}
	backgroundBody.setTexture(backgroundTexture);
	backgroundBody.setScale(0.9f, 0.9f);
	
	spikes = new Entities::Spikes(850, 650);
	platform = new Entities::Platform(350, 650);
	elevator = new Entities::Elevator(1000, 50);

	structureList.push_back(spikes);
	structureList.push_back(platform);
	structureList.push_back(elevator);

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
