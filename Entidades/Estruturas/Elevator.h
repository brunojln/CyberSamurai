#pragma once
#include "Structures.h"

namespace Entities {

    class Elevator :
        public Structures
    {
    private:
        void initElevator();

    public:
        Elevator(float x, float y);
        ~Elevator();

        void updateMovement();

        virtual void update();
    };

}

