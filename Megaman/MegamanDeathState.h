#pragma once
#include "MegamanState.h"
class MegamanDeathState :
	public MegamanState
{
private :
	int nFrame;
	int counter;
public:
	MegamanDeathState(MegamanData*);
	~MegamanDeathState();
	void onUpdate();
};

