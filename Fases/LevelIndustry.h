#pragma once
#include "Level.h"

namespace Fases {

    class LevelIndustry :
        public Level
    {
    private:
        void initLevelIndustry();

    public:
        LevelIndustry(States::StateControl* pSC);
        ~LevelIndustry();

        void resetState();
    };
}



