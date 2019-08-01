#pragma once
#include "EnemyState.h"
#include "BlueSoldierData.h"

class BlueSoldierRuningState
	:public EnemyState
{


public:
	BlueSoldierRuningState(EnemyData *pData);
	void onUpdate();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void createBullet();
	void onDead() override;
	~BlueSoldierRuningState();
	float getFameExits() { return fameExits; }


private:  
	float fameExits; 
	float gravitaion ;
};

