#pragma once
#include "MegamanState.h"
#include "MegamanData.h"

class MegamanDamagedState :
	public MegamanState
{
private:
	float lastY;
public:
	MegamanDamagedState(MegamanData *);
	virtual void onUpdate();
	void onMovePressed(Direction d);
	void onJumpPressed();
	void onSlidePressed();
	~MegamanDamagedState();
};

