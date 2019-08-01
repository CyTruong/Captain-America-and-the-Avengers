#pragma once
#include "EnemyState.h"
#include "WizardData.h"

class WizardGroundShootingState
	:public EnemyState
{
private:
	int bulletcount;
public:
	WizardGroundShootingState(EnemyData *pData);
	void onUpdate();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void createBullet();
	void onDead() override;
	~WizardGroundShootingState();
};

