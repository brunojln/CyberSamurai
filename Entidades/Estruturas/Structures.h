#pragma once
#include "../Entity.h"
#include "SFML/Graphics.hpp"

namespace Entities {

    class Structures :
        public Entity
    {
    protected:
        bool damaging;
        float structureDamage;

    public:
        Structures(entityID id);
        ~Structures();

        float getStructureDamage();
        bool isDamaging();
        virtual void update() = 0;
    };
}



