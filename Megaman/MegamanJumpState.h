#pragma once
#include "MegamanState.h"
#include "MegamanDamagedState.h"
class MegamanJumpState : public MegamanState
{
private:
	bool isMoving;
	bool isJumpingPress;
	float speedX;

	// hcmt 
	bool isCimping; 


	//float acceleration;
public:
	//MegamanJumpState(MegamanData * data, bool isMoving = false , float vy =-5.0f);
	// hcmt 
	MegamanJumpState(MegamanData *data, bool isMoving = false, float vy = -8.0f, bool isCimping = false);
	~MegamanJumpState();
	void onMovePressed(Direction dir);
	void onMoveReleased(Direction dir);
	// hcmt climping 
	void onJumpPressed(); 
	void onJumpRelease();
	void onSlidePressed();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void onDynamicObjectCollision(CollisionRectF* cRect);

	void onUpdate();
	void onFirePressed();
	void onFireRelease();
	void onVeticalDirectionPressed(Direction d);
	void onVeticalDirectionReleased();
	virtual void onDead();
	void damaged() override {
		transition(new MegamanDamagedState(this->pData));
	}
};

