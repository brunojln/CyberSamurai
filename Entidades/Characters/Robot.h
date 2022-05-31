#pragma once
#include "Enemy.h"

namespace Entities {

    class Robot :
        public Enemy
    {
    private:
        void initRobot();

    public:
        Robot(float x, float y);
        ~Robot();
    };

}


