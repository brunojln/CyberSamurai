#pragma once
#include "../Gerenciadores/GraphicManager.h"
#include "../Gerenciadores/Collider.h"
#include "../Entidades/Estruturas/Platform.h"
#include "../States/GerenciadorEstado.h"

//Referência [3]

class Game : public States::StateControl
{
private:

	Managers::GraphicManager* pGraphics;

	sf::Event ev;
	sf::Clock typingClock;

public:
	Game();
	~Game();

	void run();

	void update();
	void render();
};

