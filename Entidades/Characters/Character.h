#pragma once
#include "../Entity.h"

namespace Entities {


    class Character :
        public Entity
    {
    protected:
        //core
        float lifePoints;
        int exp; //para o player sera += exp dos inimigos eliminados

        float atkDamage;
        float atkCooldown;
        sf::Clock cooldown;
  
        bool canAttack;
        bool isAttacking;
        bool isNear;
        bool isTakingDamage;

    public:
        Character(entityID id);
        ~Character();

        const float getLifePoints() const;
        const int getExp() const;
        const bool getIsAttacking() const;

        void setisTakingDamage(bool isDmg);
        void setIsNear(bool near);
        void setLifePoints(float hp);
        void setExp(int xp);

        void updateCooldown();
        void attack(Entities::Character *pCharacter, bool isNear);

        virtual void save() = 0;
    };

}


