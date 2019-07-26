#pragma once
#include "MegamanState.h"
#include "MegamanJumpState.h"
#include "MegamanSlideState.h"
#include "MegamanDamagedState.h"
class MegamanWallClimping :
	public MegamanState
{
public:
	float DownGraviy;
public:
	MegamanWallClimping(MegamanData * data);
	~MegamanWallClimping();
	void onMovePressed(Direction dir);
	void onMoveReleased(Direction dir);
	void onVeticalDirectionPressed(Direction dir);
	void onVeticalDirectionReleased();
	void onJumpPressed();
	void onJumpRelease();
	void onSlidePressed();
	void onUpdate();
	//va chạm vs obj tĩnh
	void onCollision(RectF rect);
	//va chạm vs các obj đông
	void onCollision(CollisionRectF rect);
	void onDynamicObjectCollision(CollisionRectF* rect);
	void onFall();
	void onMoveVerticalPressed(Direction dir);
	void onMoveVerticalReleased(Direction dir);
	void onFirePressed();
	void onFireRelease();
	void onDead();
	void onCameraCollision(RectF cameraRect);
	void damaged() override {
		transition(new MegamanDamagedState(this->pData));
	}
};

