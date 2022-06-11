#pragma once
#include "Enemy.h"

namespace Entities {

    class Robot :
        public Enemy
    {
    private:
        const float robotDamage;
        void initRobot();

    public:
        Robot(float x, float y);
        ~Robot();

        virtual void save();
    };

}


