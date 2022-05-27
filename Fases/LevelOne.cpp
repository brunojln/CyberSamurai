#include "LevelOne.h"

void LevelOne::initLevel()
{
	if (!backgroundTexture.loadFromFile("InclusaoExterna/Imagens/Background/levelBackground.png"))
	{
		std::cout << "ERROR::INITLEVEL::Erro ao carregar textura" << "\n";
	}
	body.setTexture(backgroundTexture);
	body.setScale(0.9f, 0.9f);
}

LevelOne::LevelOne(StateControl* pSC):
	Level(pSC)
{
	initLevel();
	update(0);
	render();
}

LevelOne::~LevelOne()
{
}
