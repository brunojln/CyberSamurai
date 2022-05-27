#pragma once
#include "SFML/Graphics.hpp"
#include "../Entidades/Estruturas/Platform.h"
#include "../Entidades/Characters/Player.h"
#include "../Entidades/Estruturas/Structures.h"
#include <list>
#include <vector>

namespace Managers {

	class Collider
	{
	private:
		//vector<Enemy> enemyList;
		std::list <Entities::Structures*> structureList;
	public:
		Collider();
		~Collider();

		bool checkCollision(Entities::Platform* other, Entities::Player *body, float push);
	};


}
