#pragma once
#include "MegamanState.h"
#include "MegamanDamagedState.h"
class MegamanSlideState :
	public MegamanState
{
private:
	float speedSlideX;
	float Friction;
public:
	MegamanSlideState( MegamanData* );
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
	void createBullet(float x, float y, float angle);
	void damaged() override {
		transition(new MegamanDamagedState(this->pData));
	}
	~MegamanSlideState();
};

