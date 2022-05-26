#include "Menu.h"


Menu::Menu(): sel{0}, min{0}, max{2}, active{false}
{
	Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();


	//background->setTexture(*pGM->loadTexture("InclusaoExterna/Imagens/Background/background_menu.png"));
	//Talvez nao funcione

	
	sf::Texture* image;
	
	image = new sf::Texture();

	if (!image->loadFromFile("InclusaoExterna/Imagens/Background/background_menu.png"))
	{
		std::cout << "ERROR::MENU::Erro ao carregar imagem" << "\n";
	}

	background = new sf::Sprite();

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