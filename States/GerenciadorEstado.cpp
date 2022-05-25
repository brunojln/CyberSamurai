#include "GerenciadorEstado.h"

StateControl::StateControl(): runningState{null}, lastState{null}
{

}

StateControl::~StateControl()
{  
	map<sID, State*>::iterator iterator;

	for (iterator = StateMap.begin(); iterator != StateMap.end(); iterator++)
	{
		delete(iterator->second); //Deleta a segunda parte do map, o endereco de memoria
	}

}

void StateControl::changeRunningState(sID id)
{  
	lastState = runningState;
	runningState = id;
	StateMap[runningState]->resetState();

}
void StateControl::updateRunningState(const float dt)
{ 
	//StateMap[runningState]->update(dt);
}
void StateControl::renderRunningState()
{  
	StateMap[runningState]->render();
}

sID StateControl::getRunningState() const
{ 
	return runningState;
}

void StateControl::setState(State* pS)
{
	StateMap.insert(pair<sID, State*>(pS->getID(), pS));
}
sID StateControl::getLastState() const
{
	return lastState;
}