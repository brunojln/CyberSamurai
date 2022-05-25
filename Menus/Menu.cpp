#include "Menu.h"



Menu::Menu(): sel{0}, min{0}, max{2}, active{false}
{
	Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();
	
	
	background = pGM->loadTexture("InclusaoExterna/Imagens/Background/background_menu.png");

	body.setSize(sf::Vector2f(1280, 720));
	body.setPosition(sf::Vector2f(640,360));
	body.setTexture(background);

	/*
	sf::Texture* image;
	
	image = new sf::Texture;
	image = NULL;

	image->loadFromFile("InclusaoExterna/Imagens/Background/background_menu.png");
	background->setTexture(*image);*/
}
Menu::~Menu()
{  
	Button* aux = NULL;
	while (ButtonVector.size() != 0) {
		aux = ButtonVector.back();
		delete (aux);
		ButtonVector.pop_back();
	}
	ButtonVector.clear();
}


void Menu::Up()
{  
	if (active) //Se o botao estiver selecionado
	{ 
		ButtonVector[sel]->selected(false); //Altera a fonte e tamanho
		sel++;

		if (sel > max)
		{
			sel = min;
		}

		ButtonVector[sel]->selected(true);
	}

}
void Menu::Down()
{ 
	if (active) 
	{
		ButtonVector[sel]->selected(false);

		sel--;

		if (sel < min)
		{
			sel = max;
		}
			
		ButtonVector[sel]->selected(true);
	}

}