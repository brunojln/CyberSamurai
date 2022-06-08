#pragma once
#include "../Character.h"
#include "../Player.h"


namespace Entities {

    class Enemy :
        public Character
    {
    private:
        Entities::Player* pPlayer;
        int playerIndex;

    public:
        Enemy(entityID id);
        ~Enemy();

        Entities::Player* getPlayer() { return pPlayer;  }
        int getPlayerIndex() { return playerIndex;  }

        void setPlayer(Entities::Player* p);
        void setPlayerIndex(int i) { playerIndex = i;  }
        void followPlayer();
        void attackPlayer();

        virtual void update();

        virtual void save() = 0;
    };


}
