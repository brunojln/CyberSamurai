#include "../Gerenciadores/GraphicManager.h"

namespace Managers{ 

    //Padrao de projeto Singleton(uma instancia global)
    GraphicManager* GraphicManager::instance = nullptr;

    GraphicManager* GraphicManager::getGraphics()
    {  
        if (instance == nullptr) //Verificacao se há alguma instancia criada, caso nao tenha, será criado
        {
            instance = new GraphicManager();
        }

        return instance;
    } 



    GraphicManager::GraphicManager() : 
    window{ new sf::RenderWindow(sf::VideoMode(1280, 720), "CyberSamurai", sf::Style::Titlebar | sf::Style::Close) }, view{ sf::Vector2f(640, 360), sf::Vector2f(1280, 720)}, textureMap(),
    fontMap()
    {
        window->setFramerateLimit(60);
    }

    GraphicManager::~GraphicManager()
    { 
        std::map<const char*, sf::Texture*>::iterator iT;

        for (iT = textureMap.begin(); iT != textureMap.end(); ++iT) {
            delete (iT->second);
        }

        std::map<const char*, sf::Font*>::iterator iF;

        for (iF = fontMap.begin(); iF != fontMap.end(); ++iF) {
            delete (iF->second);
        }

        delete (window);

    } 
    void GraphicManager::render(sf::RectangleShape* shape)
    {   
        window->draw(*shape);
    } 

    void GraphicManager::render(sf::Text* text)
    { 
        window->draw(*text);
    } 

    void GraphicManager::render(sf::Sprite* sprite)
    {
        window->draw(*sprite);
    }

    void GraphicManager::display()
    {     
        window->display();
    } 

    void GraphicManager::clear()
    {
        window->clear();
    } 


    void GraphicManager::close()
    {
        window->close();
    }
    bool GraphicManager::isWindowOpen()
    {
        if (window->isOpen()) {
            return true;
        }
        else {
            return false;
        }
    }

bool GraphicManager::WindowIsOpen() const {
    return window->isOpen();
}

sf::Texture* GraphicManager::loadTexture(const char* path)
{
    std::map<const char*, sf::Texture*>::iterator iT = textureMap.begin();

        while (iT != textureMap.end()) //Verificacao se ja existe a textura carregada
        {
            if (!strcmp(iT->first, path))//Compara o caminho passado com a primeira posicao do iterador, vai verificando por todo o mapa de textura
            {
                return iT->second; //Se existir, retorna a existente
            }
            
            iT++;
        }

        //Caso contrario, carrega
    
        sf::Texture* aux = new sf::Texture();

        if (!aux->loadFromFile(path)) 
        {
            std::cout << "ERRO::MANAGER::GRAPHICMANAGER::TEXTURELOADING " << std::endl;
        }

        textureMap.insert(std::pair<const char*, sf::Texture*>(path, aux));

        return aux;

    } 

    sf::Font* GraphicManager::loadFont(const char* path)
    {  
        std::map<const char*, sf::Font*>::iterator iF = fontMap.begin();

        while (iF != fontMap.end())
        {
            if (!strcmp(iF->first, path))
            {
                return iF->second;
            }
            
            iF++;
        }

        /* If not found, must load it. */
        sf::Font* font = new sf::Font();

        if (!font->loadFromFile(path))
        {
            std::cout << "ERRO::MANAGER::GRAPHICMANAGER::FONTLOADING " << std::endl;
        }

        fontMap.insert(std::pair<const char*, sf::Font*>(path, font));

        return font;
    }
    sf::RenderWindow* GraphicManager::getWindow() const
    {
        return window;
    }


    /*
    float GraphicManager::updateDeltaTime()
    { 

    } 
    */


}