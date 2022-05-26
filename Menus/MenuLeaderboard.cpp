#include "MenuLeaderboard.h"

MenuLeaderboard::MenuLeaderboard(StateControl* pSC): Menu(), State(pSC, sID::Leaderboard)
{ 
	Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();
	Button* button = NULL;

	//Unico botao de retornar
	button = new Button(sf::Vector2f(640, 600), "Voltar");
	button->selected(true); //Play como primeiro selecionado
	ButtonVector.push_back(button);

} 
MenuLeaderboard::~MenuLeaderboard()
{ 

} 


void MenuLeaderboard::render()
{
	Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();
	pGM->render(&body);

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
    active = true;
}

void MenuLeaderboard::construct()
{ 
    /*
    ifstream file;

    file.open(LEADERBOARD_PATH, std::ios::binary | std::ios::in);

    if (!file) {
        std::ofstream writeFile(LEADERBOARD_PATH, std::ios::out | std::ios::trunc);
        writeFile.close();
    }

    int points;
    std::string name;
    std::string textString;
    std::string pointsString;

    sf::Text* txt;

    for (int i = 0; i < 10; i++) {
        name = "";
        points = 0;
        pointsString = "";

        getline(file, pointsString);
        getline(file, name);

        textString = std::to_string((i + 1) / 10) + std::to_string((i + 1) % 10) + " - " + name + " ";

        if (pointsString.length() > 0) {

            points = std::stoi(pointsString);

            pointsString = std::to_string(points / 1000000);
            points %= 1000000;

            pointsString += std::to_string(points / 100000);
            points %= 100000;

            pointsString += std::to_string(points / 10000);
            points %= 10000;

            pointsString += std::to_string(points / 1000);
            points %= 1000;

            pointsString += std::to_string(points / 100);
            points %= 100;

            pointsString += std::to_string(points / 10);
            points %= 10;

            pointsString += std::to_string(points);
        }

        while (textString.length() + pointsString.length() < 50) {
            textString += ".";
        }

        txt = new GraphicalElements::Text(Math::CoordF(Managers::Graphics::getInstance()->getWindowSize().x / 2.0f, 100 + 40 * i), textString + pointsString, LEADERBOARD_FONT_PATH);
        txt->setFontSize(48);
        txt->setTextAlignment(GraphicalElements::TextAlignment::center);
        txt->setTextColor(77.6, 68.2, 44.3);
        allPoints.push_back(txt);
    }

    file.close();
    */

} 