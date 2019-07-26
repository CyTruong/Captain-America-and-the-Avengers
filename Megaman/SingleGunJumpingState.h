#pragma once
#include "EnemyState.h"

class SingleGunJumpingState :
	public EnemyState
{
private:
	float gravity;
public:
	SingleGunJumpingState(EnemyData * pData);
	void onUpdate();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void onDead() override;
	~SingleGunJumpingState();
};

