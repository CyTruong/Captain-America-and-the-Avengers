#pragma once
#include "EnemyState.h"
#include "RocketSoldierData.h"

class RocketSoldierRunningState
	:public EnemyState
{


public:
	RocketSoldierRunningState(EnemyData *pData);
	void onUpdate();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void createBullet();
	void onDead() override;
	~RocketSoldierRunningState();
	float getFameExits() { return fameExits; }


private:
	float speed;
	float fameExits;
	float gravitaion;
};