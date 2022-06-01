#include "MenuLeaderboard.h"
#include <fstream>

MenuLeaderboard::MenuLeaderboard(StateControl* pSC): Menu(), State(pSC, sID::Leaderboard)
{ 
	Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();
	Button* button = NULL;

	//Unico botao de retornar
	button = new Button(sf::Vector2f(100, 600), "Voltar");
	button->selected(true); //Play como primeiro selecionado
	ButtonVector.push_back(button);

    max = 0;
} 
MenuLeaderboard::~MenuLeaderboard()
{ 

} 


void MenuLeaderboard::render()
{
	Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();

    pGM->render(background);

	for (iB = ButtonVector.begin(); iB != ButtonVector.end(); iB++)
	{
		(*iB)->render();
	}

	for (iP = score.begin(); iP != score.end(); iP++)
	{
		pGM->render(*iP);
	} 
			
} 

void MenuLeaderboard::resetState()
{
	ButtonVector[0]->selected(true);
	for (iP = score.begin(); iP != score.end(); iP++)
	{
		delete (*iP);
	}

	score.clear();
	construct();
} 

void MenuLeaderboard::exec()
{
	if (active) 
	{
		active = false;
		updateState(sID::MainMenu);
	}
} 

void MenuLeaderboard::update(float dt) 
{
    if (active == false)
    {
        delay.restart();
    }
    active = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && delay.getElapsedTime().asSeconds() >= 0.2)
    {
        exec();
        delay.restart();
    }
}

void MenuLeaderboard::construct()
{ 

    std::ifstream arq;

    arq.open("./InclusaoExterna/Leaderboard/LeaderboardSave.txt", std::ios::binary | std::ios::in); //?

    if (!arq)
    {
        std::cout << "ERROR::LEADERBOARDMENU::READINGFILE" << std::endl;
    }

    std::string name;
    std::string textString;
    std::string points;
    sf::Text* text;

    for (int i = 0; i < 10; i++) 
    {
        name = ""; points = ""; 

        std::getline(arq, points);
        std::getline(arq, name);
       
        textString = std::to_string((i + 1) / 10) + std::to_string((i + 1) % 10) + " : " + name + " ";
       
        while (textString.length() + points.length() < 50) {
            textString += ".";
        }
        
        Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();

       
        text = new sf::Text;
        text->setPosition(100, 100 + 40*i);
        text->setFont(*pGM->loadFont("InclusaoExterna/Fonte/NEONLEDLight.otf"));
        text->setLetterSpacing(1.5);
        text->setString(textString + points);
        text->setCharacterSize(30);
        score.push_back(text);
      
    }

    arq.close();
    

} 