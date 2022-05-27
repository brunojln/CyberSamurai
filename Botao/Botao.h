#pragma once
#include "../Includes/stdafx.h"
#include "../Gerenciadores/GraphicManager.h"


class Button
{
private:

	std::string data;
	sf::Font* fontDefault;
	sf::Font* fontSelected;
	sf::Text text;

public:

	Button(sf::Vector2f position, std::string string);
	~Button();
	void selected(const bool isSelected);
	void render();

};

