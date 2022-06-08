#pragma once
#include "Characters/Enemies/Enemy.h"


namespace Entities{


    class Bullet :
        public Entity
    {
    private:
        void initBullet();
        sf::Vector2f direction;
        float movementSpeed;

    public:
        Bullet(float pos_x, float pos_y, float dir_x, float dir_y);
        ~Bullet();
        void shoot();

        void update();

        virtual void save();
    };

}

