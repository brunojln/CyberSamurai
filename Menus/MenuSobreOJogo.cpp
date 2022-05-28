#include "MenuSobreOJogo.h"

MenuSobreOJogo::MenuSobreOJogo(Game* pG): Menu(), State((StateControl*)(pG), sID::SobreJogo)
{ 
	Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();
	Button* button = NULL;

	//Unico botao de retornar
	button = new Button(sf::Vector2f(100, 600), "Voltar");
	button->selected(true); //Play como primeiro selecionado
	ButtonVector.push_back(button);

	text = new sf::Text;
	text->setString("O jogo CyberSamurai foi desenvolvido \npelos alunos Bruno Julian e Nathan Yuhei \npara a materia de Tecnicas de Programacao,\nministrado pelo professor Jean Simao, com\nfim de botar em pratica os conceitos \naprendidos sobre C++");
	text->setCharacterSize(40);
	text->setPosition(100, 100);
	text->setLineSpacing(1.3);
	text->setFont(*pGM->loadFont("InclusaoExterna/Fonte/NEONLEDLight.otf"));
	
	max = 0;
}
MenuSobreOJogo::~MenuSobreOJogo()
{
	delete text;
}

void MenuSobreOJogo::render()
{
	Managers::GraphicManager* pGM = Managers::GraphicManager::getGraphics();

	pGM->render(background);

	for (iB = ButtonVector.begin(); iB != ButtonVector.end(); iB++)
	{
		(*iB)->render();
	}

	pGM->render(text);
}

void MenuSobreOJogo::resetState()
{
	ButtonVector[sel]->selected(false);
	sel = 0;
	ButtonVector[sel]->selected(true);
}

void MenuSobreOJogo::exec()
{
	if (active)
	{
		active = false;
		updateState(sID::MainMenu);
	}
}

void MenuSobreOJogo::update(float dt)
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