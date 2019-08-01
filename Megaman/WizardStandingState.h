#pragma once
#include "EnemyState.h"
#include "WizardData.h"

class WizardStandingState :
	public EnemyState
{

private:
	int waittingFrame;
	int waittingCount;
	float acceleration;
public:
	WizardStandingState(EnemyData *pData);
	void onUpdate();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void onDead() override;
	~WizardStandingState();
};

