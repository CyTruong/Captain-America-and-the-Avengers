#pragma once
#include "CaptainState.h"
#include "CaptainData.h"
//#include "MegamanDamagedState.h"
class CaptainRunningState : public CaptainState
{
private:
	int left;
	int right;

public:
	CaptainRunningState(CaptainData* data);
	void onMovePressed(Direction d);
	void onMoveReleased(Direction d);
	void onUpdate();
	void onJumpPressed();
	void onSlidePressed();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void onDynamicObjectCollision(CollisionRectF* rect);
	void onFall();
	void onFirePressed();
	void onFireRelease();
	void onVeticalDirectionPressed(Direction d);
	void onVeticalDirectionReleased();
	virtual void onDead();
	
	void damaged() override {
		//transition(new MegamanDamagedState(this->pData));
	}
};

