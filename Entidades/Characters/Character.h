#pragma once
#include "../Entity.h"

namespace Entities {


    class Character :
        public Entity, public Ente
    {
    protected:
        //core
        int lifePoints;
        int exp; //para o player sera += exp dos inimigos eliminados
        //ok

    public:
        Character();
        ~Character();

        void getLifePoints();
        void getExp();

        void setLifePoints();
        void setExp();

        virtual void render();
        virtual void update();
    };

}


