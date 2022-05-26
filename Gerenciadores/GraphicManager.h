#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

namespace Managers { 

	class GraphicManager
	{

	private:
		sf::RenderWindow* window;
		sf::View view;
		std::map <const char*, sf::Texture*> textureMap;
		std::map <const char*, sf::Font*> fontMap;

		static Managers::GraphicManager* instance;
		GraphicManager();

	public:

		~GraphicManager();

		static GraphicManager* getGraphics();

		void render(sf::RectangleShape* shape);

		void render(sf::Text* text);

		void render(sf::Sprite* sprite);

		void display();

		void clear();

		void close();

		bool isWindowOpen();

		sf::Texture* loadTexture(const char* path);

		sf::Font* loadFont(const char* path);

		sf::RenderWindow* getWindow() const;
		/*
		float updateDeltaTime();
		*/
	bool WindowIsOpen() const;

	/*
	float updateDeltaTime();
	*/


	};

}