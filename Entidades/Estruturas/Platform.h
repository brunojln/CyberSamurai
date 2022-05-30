#pragma once
#include "Structures.h"

namespace Entities {

	class Platform : 
		public Structures
	{
	private:
		void initPlatform();

	public:
		Platform(float x, float y);
		~Platform();

		//void render(sf::RenderTarget& target);
	};

}

