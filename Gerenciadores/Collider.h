#pragma once
#include "SFML/Graphics.hpp"
#include "../Entidades/Estruturas/Platform.h"
#include "../Entidades/Characters/Player.h"
#include "../Entidades/Estruturas/Structures.h"
#include "../Entidades/Entity.h"
#include <list>
#include <vector>


//Referência [1]
namespace Managers {

	class Collider
	{
	private:
		bool isColliding;

	public:
		Collider();
		~Collider();

		bool checkCollision(Entities::Entity* other, Entities::Player *body, float push, bool cross);
	};


}

