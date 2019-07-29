#pragma once

#include "MegamanState.h"
#include "Rect.h"
#include "CollisionRect.h"
#include "MegamanDamagedState.h"

class MegamanPunchState : public MegamanState
{
private:
public:
	~MegamanPunchState() {}
	MegamanPunchState(MegamanData* data);
	void onMovePressed(Direction d);
	void onJumpPressed();
	void onSlidePressed();
	void onUpdate();
	// hcmt add physic 
	void onCollision(CollisionRectF cRect);
	void onDynamicObjectCollision(CollisionRectF* rect);
	void onVeticalDirectionPressed(Direction d);
	void onVeticalDirectionReleased();
	void onFirePressed();
	void onFireRelease();
	void onFall();
	virtual void onDead();

	void damaged() override {
		transition(new MegamanDamagedState(this->pData));
	}
};