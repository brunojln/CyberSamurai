#pragma once
#include "Character.h"
#include "Player.h"


namespace Entities {

    class Enemy :
        public Character
    {
    private:
       
    public:
        Enemy(entityID id);
        ~Enemy();

        void followPlayer(Player *pPlayer);
        void attackPlayer(Player* pPlayer, bool isNear);

        void update(Player* pPlayer, bool isNear);
    };


}
