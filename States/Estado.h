#pragma once
#include "../Includes/stdafx.h"


class StateControl;

enum sID
{
	null = -1, MainMenu = 0, Play, Playing, Pause, SobreJogo, Leaderboard, GameOver
};

class State
{
protected:
	StateControl* pSC;
	sID id;	

public:
	State(StateControl* pSC, sID id);
	virtual ~State();

	sID getID() const;

	void setStateControl(StateControl* aux);

	void updateState(sID id);

	//virtual void update(const float dt) = 0;

	virtual void render() = 0;

	virtual void resetState() = 0;

};

