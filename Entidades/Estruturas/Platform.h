#pragma once
#include <SFML/Graphics.hpp>
#include "../../Includes/stdafx.h"
#include "Structures.h"

namespace Entities {

	class Platform : public Structures
	{
	private:

	public:
		Platform(bool dmg, int id, sf::Vector2f velocidade, float vMax,
			float vMin, float accel, float dr, float grav, float vMaxY, sf::Vector2f size);
		~Platform();

		void render(sf::RenderTarget& target);

	};

}

