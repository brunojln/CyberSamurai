#pragma once
#include "Level.h"

namespace Fases {

    class LevelCity :
        public Level
    {
    private:
        Entities::Boss* pBoss;
        void initLevelCity();

    public:
        LevelCity(States::StateControl* pSC);
        ~LevelCity();

        void resetState();
    };

}


