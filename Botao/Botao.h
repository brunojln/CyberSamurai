#include "../Includes/stdafx.h"
#include "../GraphicManager.h"


class Button
{
private:

	string data;
	sf::Font* fontDefault;
	sf::Font* fontSelected;
	sf::Text text;

public:

	Button(sf::Vector2f position, string string);
	~Button();
	void selected(const bool isSelected);
	void render();

};

