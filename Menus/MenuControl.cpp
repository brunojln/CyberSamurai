#pragma once
#include "MenuControl.h"
#include "../Menus/Menu.h"

MenuControl::MenuControl(Menu* pMenu) : pM{pMenu} 
{

} 

MenuControl::~MenuControl()
{ 
	pM = NULL;
} 

void MenuControl::Pressed()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {   
      
        pM->Down();
    }
        
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        pM->Up();
    }
        
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        pM->exec();
    }
        
      /*if (key == "Escape");
      if (dynamic_cast<PauseMenuState*>(pM) != nullptr)
            dynamic_cast<PauseMenuState*>(pM)->TriggerPauseMenu();*/

} 


void MenuControl::setMenu(Menu* p)
{
    pM = p;
} 