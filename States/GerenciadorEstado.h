#pragma once
#include "Estado.h"
#include <map>

class StateControl
{

protected:
	sID runningState;
	sID lastState;

	std::map<sID, State*> StateMap;
	
public:

	StateControl();
	virtual ~StateControl(); //virtual 

	void changeRunningState(sID id);
	void updateRunningState(const float dt);
	void renderRunningState();

	sID getRunningState() const;
	void setState(State* pS);
	sID getLastState() const;
};

