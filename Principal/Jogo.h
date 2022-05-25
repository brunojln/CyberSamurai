#include "../Includes/stdafx.h"
#include "../Entidades/Characters/Player.h"
#include "../Gerenciadores/Platform.h"
#include "../Menus/MenuEntrada.h"

// namespace entidades {


class Jogo
{
private:
	sf::RenderWindow window;
	int windowWidth;
	int windowHeight;

	sf::View view;
	sf::Clock deltClock;
	float deltaTime; 
	bool canMove;

	sf::Texture texture;
	sf::Sprite sprite;
	sf::Event ev;

	EntranceMenu mainmenu;
	Entities::Player* player;
	Platform* platform1; //criar um map e inserir as plataformas
	Platform* platform2;


	void initWindow();
	void initView();
	void initPlayer();

public:
	Jogo();
	~Jogo();

	void showCoords();
	//Collider getCollider();
	void player_platformCollision(Platform* platform1);

	void updatePlayer();
	void updateCollision();
	void updateView();
	void run();
	void update();

	void render();

};



//}