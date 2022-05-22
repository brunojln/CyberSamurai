#include "../Includes/stdafx.h"


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
	void select(const bool isSelected);
	void render();

};

