#pragma once
#include "Level.h"

namespace Fases {

    class LevelOne :
        public Level
    {
    private:
        void initLevel();
    public:
        LevelOne(States::StateControl* pSC);
        ~LevelOne();

    };
}



