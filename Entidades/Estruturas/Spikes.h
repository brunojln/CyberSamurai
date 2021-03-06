#pragma once
#include "Structures.h"

namespace Entities {

    class Spikes :
        public Structures
    {
    private:
        void initSpikes();
        const float spikeDamage;

    public:
        Spikes(float x, float y);
        ~Spikes();

        virtual void update();
        virtual void save();
    };

}

