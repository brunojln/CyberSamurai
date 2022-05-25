#include "../Includes/stdafx.h"

namespace Managers { 

class GraphicManager
{

private:
	sf::RenderWindow* window;
	sf::View view;
	map <const char*, sf::Texture*> textureMap;
	map <const char*, sf::Font*> fontMap;

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

	sf::Texture* loadTexture(const char* path);

	sf::Font* loadFont(const char* path);

	bool WindowIsOpen() const;

	/*
	float updateDeltaTime();
	*/


};

}