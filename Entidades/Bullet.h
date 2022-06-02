#pragma once
#include "Characters/Enemies/Enemy.h"


namespace Entities{
class Boss;
    class Bullet :
        public Enemy
    {
    private:
        void initBullet();
        sf::Vector2f direction;
        float movementSpeed;
        Entities::Boss* pBoss;

    public:
        Bullet(float pos_x, float pos_y, float dir_x, float dir_y);
        ~Bullet();
        void shoot();
    };

}

