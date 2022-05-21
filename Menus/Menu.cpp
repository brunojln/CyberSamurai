#include "Menu.h"


	Menu::Menu(){

		window = new sf::RenderWindow();
		font = new sf::Font();
		font2 = new sf::Font();
		background = new sf::Sprite();
		image = new sf::Texture();

		set_values();

	}
	Menu::~Menu() {
		delete window, font, font2, background, image;

	}

	void Menu::set_values() {
		window->create(sf::VideoMode(1280, 720), "Menu");
		window->setPosition(sf::Vector2i(320,180));

		pos = 1; //Play como primeiro selecionado
		selected = false;

		font->loadFromFile("InclusaoExterna/Fonte/Cyber.ttf");
		font2->loadFromFile("InclusaoExterna/Fonte/Cyber-BoldRustique.ttf");
		image->loadFromFile("InclusaoExterna/Imagens/Background/background_menu.png");

		background->setTexture(*image);

		options = {"CyberSamurai", "Play", "Leaderboard","Sobre o jogo", "Quit"};
		text.resize(5);

		coords = {{100, 50}, {100, 200}, {100, 250}, {100,300}, {100,350}};
		sizes = {75,40,40,40, 40};

		for (size_t i{}; i < text.size(); i++)
		{
			text[i].setFont(*font);
			text[i].setString(options[i]);
			text[i].setCharacterSize(sizes[i]);
			//text[i].setOutlineColor(sf::Color::Black);
			text[i].setPosition(coords[i]);
		}
		
		//Inicializa o play como selecionado
		text[1].setFont(*font2);
		text[1].setCharacterSize(45);


	};

	

	void Menu::loop_events() 
	{

		sf::Event event;

		while (window->pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				window->close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed) 
			{
				if (pos < 4) //Ultima opcao do menu
				{
					pos++;
					pressed = true;
			
					text[pos].setFont(*font2);
					text[pos].setCharacterSize(45);

					//Se mudar a opcao
					text[pos - 1].setFont(*font);
					text[pos - 1].setCharacterSize(40);

					pressed = false;
					selected = false;

			
				}

			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed)
			{
				if (pos > 1) //Nao pegar o menu
				{
					--pos;
					pressed = true;

					text[pos].setFont(*font2);
					text[pos].setCharacterSize(45);

					//Se mudar a opcao
					text[pos + 1].setFont(*font);
					text[pos + 1].setCharacterSize(40);

					pressed = false;
					selected = false;
				}

			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !selected)
			{
				selected = true;

				if (pos == 1)
				{

				}
				else if (pos == 2)
				{

				}
				else if (pos == 3)
				{

				}
				else if (pos == 4)
				{
					window->close();
				}

			}

		}

	}

	void Menu::draw()
	{
		window->clear();
		window->draw(*background);
		

		for (auto &t : text) 
		{
			window->draw(t);
		}

		window->display();
		
	}

	void Menu::run_menu()
	{
		while (window->isOpen())
		{
			loop_events();
			draw();
		}
	}



