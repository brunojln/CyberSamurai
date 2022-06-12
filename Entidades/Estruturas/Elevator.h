#pragma once
#include "Structures.h"
#include <iostream>

namespace Entities {

    class Elevator :
        public Structures
    {
    private:
        sf::Color defaultColor;
        void initElevator();

    public:
        Elevator(float x, float y);
        ~Elevator();

        void updateMovement();

        virtual void update();
        virtual void save();
    };

}

