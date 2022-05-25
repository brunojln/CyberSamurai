#pragma once
#include "../Entity.h"

namespace Entities {


    class Character :
        public Entity
    {
    protected:
        //core
        int lifePoints;
        int exp; //para o player sera += exp dos inimigos eliminados
        int atkDamage;
        const float atkCooldown;
        const float atkDistance;
        //ok

    public:
        Character(const float atkCd, const float atkDis);
        Character(int hp, int xp, int atkDmg, const float atkCd, const float atkDis,
            int id, sf::Vector2f velocidade, float vMax, float vMin, float accel, float dr, float grav, float vMaxY);
        ~Character();

        const int getLifePoints() const;
        const int getExp() const;

        void setLifePoints(int hp);
        void setExp(int xp);

        //virtual void render() = 0;
       // virtual void update();
    };

}


