#include "Estado.h"
#include "GerenciadorEstado.h"

namespace States {

	State::State(StateControl* pSC, sID id) : pSC{ pSC }, id{ id }
	{}

	State::~State()
	{
		pSC = NULL;
	}

	sID State::getID() const
	{
		return id;
	}

	void State::setStateControl(StateControl* aux)
	{
		pSC = aux;
	}

	void State::updateState(sID id)
	{
		pSC->changeRunningState(id);
	}

	sID State::getLState()
	{
		return pSC->getLastState();
	}

}