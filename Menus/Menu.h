#include "../Includes/stdafx.h"
//#include "../InclusaoExterna/Fonte/Cyber.ttf"
//#include "../InclusaoExterna/Imagens/Background/background_menu.png"
 
/*
#define HEIGH 1280
#define WIDTH 720
#define FONT "../InclusaoExterna/Fonte/Cyber.ttf"
#define BG "../InclusaoExterna/Imagens/Background/background_menu.png"
*/


	class Menu {

	protected:

		int pos;
		bool pressed, selected;

		sf::RenderWindow* window;
		sf::Font* font;
		sf::Font* font2;
		sf::Sprite* background;
		sf::Texture* image;

		vector <const char*> options;
		vector <sf::Vector2f> vectorOfButtons;
		vector <sf::Vector2f> coords;
		vector <sf::Text> text;
		vector <std::size_t> sizes;


	public:

		Menu();
		~Menu();

		void set_values();
		void loop_events();
		void draw();
		void run_menu();

	};


