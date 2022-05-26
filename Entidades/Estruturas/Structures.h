#pragma once
#include "../Entity.h"
#include "SFML/Graphics.hpp"

namespace Entities {

    class Structures :
        public Entity
    {
    protected:
        //coordenadas de Entity
        bool damaging;

    public:
        Structures(bool dmg, int id, sf::Vector2f velocidade, float vMax, 
            float vMin, float accel, float dr, float grav, float vMaxY, sf::Vector2f size);
        ~Structures();

        //virtual void run();
    };
}



