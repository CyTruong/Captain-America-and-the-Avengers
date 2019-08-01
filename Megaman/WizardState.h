#pragma once
#include "EnemyState.h"
class WizardState :
	public EnemyState
{
private:
	int gun; 
	int waittingframe;
public:
	WizardState(EnemyData *pData);
	void onUpdate();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void createBullet();
	void onDead() override;
	~WizardState();
};

