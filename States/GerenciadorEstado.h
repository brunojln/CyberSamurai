#pragma once
#include "Estado.h"
#include <map>

//ReferÍncia [4]
namespace States {

	class StateControl
	{

	protected:
		sID runningState;
		sID lastState;

		std::map<sID, State*> StateMap;

	public:

		StateControl();
		virtual ~StateControl(); 

		void changeRunningState(sID id);
		void updateRunningState();
		void renderRunningState();

		sID getRunningState() const;
		void setState(State* pS);
		sID getLastState() const;
	};

} 