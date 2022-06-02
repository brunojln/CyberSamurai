#pragma once
#include "Enemy.h"
#include <vector>
#include "../../Entidades/Bullet.h"

namespace Entities {

    class Boss :
        public Enemy
    {
    private:
        void initBoss();
        std::vector<Bullet*> bullets;

    public:
        Boss(float x, float y);
        ~Boss();
        void updateBullets();
        virtual void update();
        virtual void render();
    };
}


