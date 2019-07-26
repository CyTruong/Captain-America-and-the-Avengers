#pragma once
#include "EnemyState.h"
#include "SingleGunData.h"

class SingleGunStandState :
	public EnemyState
{

private:
	int waittingFrame;
	int waittingCount;
public:
	SingleGunStandState(EnemyData *pData);
	void onUpdate();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void onDead() override;
	~SingleGunStandState();
};

