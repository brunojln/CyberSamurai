#pragma once
#include "Character.h"
#include "Player.h"


namespace Entities {

    class Enemy :
        public Character
    {
    private:
        Entities::Player* pPlayer;
        
    public:
        Enemy(entityID id);
        ~Enemy();

        void setPlayer(Entities::Player* p);
        void followPlayer();
        void attackPlayer();

        virtual void update();
    };


}
