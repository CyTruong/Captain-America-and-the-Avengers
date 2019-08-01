#pragma once
#include "EnemyState.h"
class WizardRunningState :
	public EnemyState
{
private:
	float speed;
	int count;
	int changeStateCount;
public:
	WizardRunningState(EnemyData* pData);
	void onUpdate();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void onDead() override;

	~WizardRunningState();
};

