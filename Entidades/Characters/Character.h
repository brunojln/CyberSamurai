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
        int atkDamage;
        float atkCooldown;
        float atkDistance;
        sf::Clock cooldown;
        //ok
        bool canAttack;
        bool isAttacking;

    public:
        Character(entityID id);
        ~Character();

        const int getLifePoints() const;
        const int getExp() const;

        void setLifePoints(int hp);
        void setExp(int xp);
        void updateCooldown();
        void attack(Entities::Character *pCharacter, bool isNear);
        //virtual void render() = 0;
       // virtual void update();
    };

}


