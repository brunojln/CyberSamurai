#include "../Includes/stdafx.h"
#include "../Entidades/Player.h"

class Jogo
{
private:
	sf::RenderWindow window;
	sf::Event ev;

	Player* player;

	void initWindow();
	void initPlayer();

public:
	Jogo();
	~Jogo();

	void updatePlayer();
	void updateCollision();
	void run();
	void update();

	void render();

};

