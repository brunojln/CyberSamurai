#pragma once
#include "../Entity.h"
#include "SFML/Graphics.hpp"
#include <fstream>

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
        virtual void save() = 0;
    };
}



