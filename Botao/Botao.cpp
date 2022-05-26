#include "Botao.h"


Button::Button(sf::Vector2f position, std::string string): data(string)
{
	Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();

	fontDefault = pGM->loadFont("InclusaoExterna/Fonte/Cyber.ttf");
	fontSelected = pGM->loadFont("InclusaoExterna/Fonte/Cyber-BoldRustique.ttf");

	text.setPosition(position);
	text.setFont(*fontDefault);
	text.setString(data);
	text.setCharacterSize(40);
}

Button::~Button()
{

}
void Button::selected(const bool isSelected)
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
	Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();

	pGM->render(&text);

}
