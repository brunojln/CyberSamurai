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
        Structures();
        ~Structures();

        //virtual void run();
    };
}



