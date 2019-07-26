#pragma once
#include "MegamanState.h"
#include "MegamanStandingState.h"

class MegamanStartState : public MegamanState
{
private:


public:
	MegamanStartState(MegamanData * );
	~MegamanStartState();

	void onUpdate();
	
};

