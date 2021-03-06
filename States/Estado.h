#pragma once
#include "../Includes/stdafx.h"

//ReferÍncia [4]
namespace States {

	class StateControl;

	enum sID
	{
		null = -1, MainMenu = 0, Level, Level1, Level2, Playing, Pause, SobreJogo, Leaderboard, GameOver, NumPlayers
	};

	class State
	{
	protected:
		StateControl* pSC;
		sID id;

	public:
		State(StateControl* pSC, sID id);
		State() { pSC = NULL; id = null; };
		virtual ~State();

		sID getID() const;

		void setStateControl(StateControl* aux);

		void updateState(sID id); //<----

		sID getLState();

		virtual void update() = 0;

		virtual void render() = 0;

		virtual void resetState() = 0;

	};

}