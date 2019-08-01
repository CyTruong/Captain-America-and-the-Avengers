#pragma once
#include "EnemyState.h"
#include "BlueSoldierData.h"

class BlueSoldierSitState :
	public EnemyState
{

private:
	int waittingFrame;
	int waittingCount;
public:
	BlueSoldierSitState(EnemyData *pData);
	void onUpdate();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void onDead() override;
	~BlueSoldierSitState();
};

