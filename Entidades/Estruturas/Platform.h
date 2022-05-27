#pragma once
#include <SFML/Graphics.hpp>
#include "../../Includes/stdafx.h"
#include "Structures.h"

namespace Entities {

	class Platform : public Structures
	{
	private:

	public:
		Platform();
		~Platform();

		void render(sf::RenderTarget& target);

	};

}

