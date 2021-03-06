#include "GerenciadorEstado.h"
namespace States {
	StateControl::StateControl() : runningState{ null }, lastState{ null }
	{

	}

	StateControl::~StateControl()
	{
		std::map<sID, State*>::iterator iterator;

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
	void StateControl::updateRunningState()
	{
		StateMap[runningState]->update();

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
		if (pS == nullptr)
		{
			std::cout << "ERROR::GerenciadorEstado::setState::Ponteiro nulo\n";
			exit(1);
		}

		StateMap.insert(std::pair<sID, State*>(pS->getID(), pS));
	}
	sID StateControl::getLastState() const
	{
		return lastState;
	}

}