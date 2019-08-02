#pragma once
#include "EnemyState.h"
#include "RocketSoldierData.h"

class RocketSoldierShootState
	:public EnemyState
{

public:
	RocketSoldierShootState(EnemyData *pData);
	void onUpdate();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void createBullet();
	void onDead() override;
	~RocketSoldierShootState();
	float getFameExits() { return fameExits; }

private:
	float fameExits;
	float gravitaion;


};