#include "Menu.h"


Menu::Menu(): sel{0}, min{0}, max{2}, active{false}
{
	//Gerar janela

	
	sf::Texture* image;
	/*
	image = new sf::Texture;
	image = NULL;*/

	image->loadFromFile("InclusaoExterna/Imagens/Background/background_menu.png");
	background->setTexture(*image);
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
		ButtonVector[sel]->select(false); //Altera a fonte e tamanho
		sel++;

		if (sel > max)
		{
			sel = min;
		}

		ButtonVector[sel]->select(true);
	}

}
void Menu::Down()
{ 
	if (active) 
	{
		ButtonVector[sel]->select(false);

		sel--;

		if (sel < min)
		{
			sel = max;
		}
			
		ButtonVector[sel]->select(true);
	}

}