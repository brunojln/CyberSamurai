#pragma once
#include "../Includes/stdafx.h"

class Menu;

class MenuControl
{

private:
	Menu* pM;

public:
    MenuControl(Menu* pMenu = NULL);

    ~MenuControl();

    void Pressed();

    void setMenu(Menu* p);

};

