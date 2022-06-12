#pragma once
#include "Level.h"

namespace Fases {

    class LevelIndustry :
        public Level
    {
    private:
        Entities::Robot* pGoldenRobot;
        void initLevelIndustry();

    public:

        LevelIndustry(States::StateControl* pSC);
        ~LevelIndustry();

        void resetState();
    };
}



