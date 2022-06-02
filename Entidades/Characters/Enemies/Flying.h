#pragma once
#include "Enemy.h"

namespace Entities {

    class Flying :
        public Enemy
    {
    private:
        void initFlying();
        int projectileCount;

    public:
        Flying(float x, float y);
        ~Flying();

        //virtual void update();
    };


}
