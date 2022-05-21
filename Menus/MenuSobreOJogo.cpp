#include "MenuSobreOJogo.h"


MenuSJ::MenuSJ()
{

	options = { "Voltar ao menu principal", "O jogo CyberSamurai foi desenvolvido pelos \nalunos Bruno Julian \ne Nathan Yuhei para a materia de Tecnicas de Programacao, ministrado pelo professor Jean Simao, com fim de botar em pratica os conceitos aprendidos sobre C++" };

	text[0].setFont(*font2);
	text[0].setString(options[0]);
	text[0].setCharacterSize(45);
	text[0].setOutlineColor(sf::Color::Black);
	text[0].setPosition(500,500);

	text[1].setFont(*font);
	text[1].setString(options[1]);
	text[1].setCharacterSize(20);
	text[1].setOutlineColor(sf::Color::Black);
	text[1].setPosition(100, 100);


}


MenuSJ::~MenuSJ()
{
	delete window, font2, background, image;
}


void MenuSJ::loop_event()
{

	sf::Event event;

	while (window->pollEvent(event))
	{

		if (event.type == sf::Event::Closed)
		{
			window->close();
		}

		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
		
			//voltar para o principal

		}

	}

}

void MenuSJ::dra()
{
	window->clear();
	window->draw(*background);


	for (auto& t : text)
	{
		window->draw(t);
	}

	window->display();

}

void MenuSJ::run_men()
{
	while (window->isOpen())
	{
		loop_events();
		draw();
	}
}