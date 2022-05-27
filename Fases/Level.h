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
        sf::Sprite body;
        Managers::Collider collider;
        Managers::GraphicManager* pGraphics;
        bool endGame;

    public:
        Level(StateControl* pSC = nullptr);
        ~Level();

        void update(const float dt);
        void render();

        void resetState();
        //void endLevel();
    };


//}

