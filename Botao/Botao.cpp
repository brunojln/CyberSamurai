#include "Botao.h"


Button::Button(sf::Vector2f position, string string): data(string)
{
	fontDefault->loadFromFile("InclusaoExterna/Fonte/Cyber.ttf");
	fontSelected->loadFromFile("InclusaoExterna/Fonte/Cyber-BoldRustique.ttf");

	text.setPosition(position);
	text.setFont(*fontDefault);
	text.setString(data);
	text.setCharacterSize(40);
}

Button::~Button()
{

}
void Button::select(const bool isSelected)
{
	if (isSelected)
	{
		text.setFont(*fontSelected);
		text.setCharacterSize(45);
	}
	else
	{
		text.setFont(*fontDefault);
		text.setCharacterSize(40);
	}

}

void Button::render()
{
	//incluir renderizacao
}
