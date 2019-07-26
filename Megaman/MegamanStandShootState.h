#pragma once
#include "MegamanState.h"
class MegamanStandShootState :
	public MegamanState
{
public:
	MegamanStandShootState(MegamanData*);
	void onMovePressed(Direction d);
	void onMoveReleased(Direction d);
	void onUpdate();
	void onJumpPressed();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void onDynamicObjectCollision(CollisionRectF* rect);
	void onFall();
	void onFirePressed();
	void onVeticalDirectionPressed(Direction d);
	void onVeticalDirectionReleased();
	virtual void onDead();
};

