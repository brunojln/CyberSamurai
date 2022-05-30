#pragma once
#include "LevelOne.h"
//#include "../Entidades/Characters/Player.h"

void LevelOne::initLevel()
{
	if (!backgroundTexture.loadFromFile("InclusaoExterna/Imagens/Background/levelBackground.png"))
	{
		std::cout << "ERROR::INITLEVEL::Erro ao carregar textura" << "\n";
	}
	backgroundBody.setTexture(backgroundTexture);
	backgroundBody.setScale(0.9f, 0.9f);

	spikes = new Entities::Spikes();
	player = new Entities::Player();
	platform = new Entities::Platform(350, 650);

	/*for (int i = 0; i < (rand() % 6 + 2); i++)
	{

	}*/
	//structureList->push_back(platform);

	
}

LevelOne::LevelOne(StateControl* pSC):
	Level(sID::Level1, pSC)
{
	initLevel();
	update(0);
	render();
}

LevelOne::~LevelOne()
{
	delete player;
	delete platform;
	delete spikes;
}
