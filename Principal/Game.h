#pragma once
#include "../Gerenciadores/GraphicManager.h"
#include "../Gerenciadores/Collider.h"
#include "../Entidades/Estruturas/Platform.h"
#include "../States/GerenciadorEstado.h"

class Game : public StateControl
{
private:

	Managers::GraphicManager* pGraphics;
	Managers::Collider collider;

	sf::Event ev;

public:
	Game();
	~Game();

	void run();

	void update();
	void render();
};

