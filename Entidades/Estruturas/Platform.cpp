#include "Platform.h"

Entities::Platform::Platform() :
	Structures()
{

}

Entities::Platform::~Platform()
{
}

void Entities::Platform::render(sf::RenderTarget& target)
{
	target.draw(body);
}
