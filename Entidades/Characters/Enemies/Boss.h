#pragma once
#include "Enemy.h"
#include <vector>
#include "../../Entidades/Bullet.h"
#include "../../Gerenciadores/Collider.h"

namespace Entities {

    class Boss :
        public Enemy
    {
    private:
        void initBoss();
        std::vector<Bullet*> bullets;
        float direction;
        Managers::Collider collider; //usado para colidir as balas com o player

    public:
        Boss(float x, float y);
        ~Boss();

        void updateBullets();
        virtual void update();
        virtual void render();
        void updateMovement();

        virtual void save();
    };
}


