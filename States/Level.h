#pragma once
#include "GerenciadorEstado.h"

class Level : public State
{

private:

public:

	Level(StateControl* pSM = nullptr);
	~Level();

	virtual void update(const float dt);

	virtual void render();

	virtual void resetState();
};

