#pragma once
#include "Enemy.h"

namespace Entities {

    class Robot :
        public Enemy
    {
    private:
        const float robotDamage;
        bool isGolden;
        void initRobot();

    public:
        Robot(float x, float y, bool isGolden);
        ~Robot();

        virtual void save();
    };

}


