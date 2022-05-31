#pragma once
#include "../Ente.h"
#include "../States/Estado.h"
#include "../Entidades/Characters/Player.h"
#include "../Entidades/Estruturas/Platform.h"
#include "../Entidades/Estruturas/Spikes.h"
#include "../Entidades/Estruturas/Elevator.h"
#include "../Entidades/Characters/Robot.h"
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
        Entities::Player* player;
        Entities::Platform* platform; //uso para testes, colocar em lista posteriormente
        Entities::Spikes* spikes;

        Entities::Elevator* elevator;
        Entities::Robot* robot;

        //Lists::ListEntity enemyList;

        Lists::ListEntity* structureList;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundBody;
        Managers::Collider collider;
        Managers::GraphicManager* pGraphics;
        bool endGame;

    public:
        Level(sID, StateControl* pSC = nullptr);
        ~Level();
        
        void update(const float dt);
        void render();
        void resetState();


        void windowCollision(Entities::Entity* player);
        //void windowCollision(Lists::ListEntity* enemyList);

        
        //void endLevel();
    };


//}

