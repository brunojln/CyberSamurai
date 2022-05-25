#include "../Includes/stdafx.h"
#include "../States/GerenciadorEstado.h"
#include "../Gerenciadores/GraphicManager.h"


class Game : public StateControl
{

private:
	Managers::GraphicManager* pGM;
	sf::Clock time;
	float t;

public:

	Game();

	~Game();

	void exe();

	void end();

};

