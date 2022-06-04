#pragma once
#include "Level.h"

namespace Fases {

    class LevelTwo :
        public Level
    {
    private:
        void initLevelTwo();

    public:
        LevelTwo(States::StateControl* pSC);
        ~LevelTwo();
    };

}


