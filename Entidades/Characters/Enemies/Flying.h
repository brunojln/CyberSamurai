#pragma once
#include "Enemy.h"

namespace Entities {

    class Flying :
        public Enemy
    {
    private:
        const float flyingDamage;
        void initFlying();

    public:
        Flying(float x, float y);
        ~Flying();

        virtual void save();
    };


}
