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
        float atkCooldown;
        float atkDistance;
        //ok

    public:
        Character();
        ~Character();

        const int getLifePoints() const;
        const int getExp() const;

        void setLifePoints(int hp);
        void setExp(int xp);

        //virtual void render() = 0;
       // virtual void update();
    };

}


