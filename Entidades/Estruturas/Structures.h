#pragma once
#include "../Entity.h"
#include "../../Ente.h"
#include "SFML/Graphics.hpp"

namespace Entities {

    class Structures :
        public Entity, public Ente
    {
    protected:
        sf::Sprite StructureSprite;
        sf::Texture StructureTexture;
        //coordenadas de Entity
        bool damaging;

    public:
        Structures();
        ~Structures();

        virtual void run();
    };
}



