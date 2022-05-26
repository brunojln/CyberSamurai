#include "../Includes/stdafx.h"
#include "../Botao/Botao.h"

class Menu
{
protected:
	std::vector<Button*> ButtonVector;
	std::vector<Button*>::iterator iB;

	int sel;
	int min, max;
	bool active;

	sf::RectangleShape body;
	sf::Sprite* background;

public:

	Menu();
	~Menu();

	virtual void exec() = 0;

	//void updateScreen();

	void Up();
	void Down();
	


};