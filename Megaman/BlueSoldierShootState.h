#pragma once
#include "EnemyState.h"
#include "BlueSoldierData.h"

class BlueSoldierShootState
	:public EnemyState
{

public:
	BlueSoldierShootState(EnemyData *pData);
	void onUpdate();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void createBullet();
	void onDead() override;
	~BlueSoldierShootState();
	float getFameExits() { return fameExits; }

private : 
	float fameExits; 
	float gravitaion; 


};

