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
        float atkDistance;
        sf::Clock cooldown;
        //ok
        bool canAttack;
        bool isAttacking;
        bool isNear;

    public:
        Character(entityID id);
        ~Character();

        const float getLifePoints() const;
        const int getExp() const;
        bool getIsAttacking();

        void setIsNear(bool near);
        void setLifePoints(float hp);
        void setExp(int xp);
        void updateCooldown();
        void attack(Entities::Character *pCharacter, bool isNear);
        //virtual void render() = 0;
        //virtual void update() = 0;
    };

}


