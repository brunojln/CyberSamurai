#include "../Includes/stdafx.h"
#include "../States/GerenciadorEstado.h"
#include "../Gerenciadores/GraphicManager.h"


class Game : public StateControl
{

private:
	Managers::GraphicManager* pGM;
	sf::Clock clock;
	float dt;

public:

	Game();

	~Game();

	void exe();

	void end();

};

