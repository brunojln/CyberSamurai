#pragma once
#include "../Includes/stdafx.h"
#include "Estado.h"


class StateControl
{

protected:
	sID runningState;
	sID lastState;

	std::map<sID, State*> StateMap;
	
public:

	StateControl();
	~StateControl();

	void changeRunningState(sID id);
	void updateRunningState(const float dt);
	void renderRunningState();

	sID getRunningState() const;
	void setState(State* pS);
	sID getLastState() const;
};

