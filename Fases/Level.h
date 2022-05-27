#pragma once
#include "../Ente.h"
#include "../States/Estado.h"
#include "../Entidades/Characters/Player.h"
#include "../Lista/ListEntity.h"
#include "../Gerenciadores/Collider.h"
#include "../Gerenciadores/GraphicManager.h"
#include "../States/Estado.h"
#include "../States/GerenciadorEstado.h"
#include <iostream>

//namespace Fases {

    class Level :
        public State
    {
    protected:
        //Entities::Player* player;
        //Lists::ListEntity enemyList;
        //Lists::ListEntity structureList;
        sf::Texture backgroundTexture;
        Managers::Collider collider;
        Managers::GraphicManager* pGraphics;

    public:
        Level(StateControl *pSC = nullptr);
        ~Level();

        void update();
        void render();

        //void resetState();
        //void endLevel();
    };


//}

