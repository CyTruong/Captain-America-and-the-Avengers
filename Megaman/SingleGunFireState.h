#pragma once
#include "EnemyState.h"
#include "SingleGunData.h"

class SingleGunFireState
	:public EnemyState
{

public:
	SingleGunFireState(EnemyData *pData);
	void onUpdate();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void createBullet();
	void onDead() override;
	~SingleGunFireState();
};

