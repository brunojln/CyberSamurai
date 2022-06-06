#pragma once
#include "Level.h"

namespace Fases {

    class LevelOne :
        public Level
    {
    private:
        void initLevelOne();

    public:
        LevelOne(States::StateControl* pSC);
        ~LevelOne();

        void resetState();
    };
}



