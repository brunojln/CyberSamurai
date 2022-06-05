#pragma once
#include "../Ente.h"
#include "../States/Estado.h"
#include "../Entidades/Characters/Player.h"
#include "../Entidades/Estruturas/Platform.h"
#include "../Entidades/Estruturas/Spikes.h"
#include "../Entidades/Estruturas/Elevator.h"
#include "../Entidades/Characters/Enemies/Robot.h"
#include "../Entidades/Characters/Enemies/Flying.h"
#include "../Entidades/Characters/Enemies/Boss.h"
#include "../Lista/ListEntity.h"
#include "../Gerenciadores/Collider.h"
#include "../Gerenciadores/GraphicManager.h"
#include "../States/Estado.h"
#include "../States/GerenciadorEstado.h"
#include <vector>
#include <iostream>

namespace Fases {

    class Level :
        public 	States::State
    {
    protected:

        Lists::ListEntity enemyList;
        Lists::ListEntity structureList;
        std::vector<Entities::Player*> playerList;

        sf::Texture backgroundTexture;
        sf::Sprite backgroundBody;

        Managers::Collider collider;
        Managers::GraphicManager* pGraphics;

    public:
        Level(States::sID, States::StateControl* pSC = nullptr);
        ~Level();
        
        void update();
        void render();
        void resetState();

        void windowCollision(Entities::Entity* player);
        void updateEnemyList(Entities::Entity *pEntity, unsigned int i);
        void updateStructureList(Entities::Entity* pEntity, unsigned int i);

        const int getPlayerPoints() const;
        void endLevel();

    };

}

