#pragma once
#include "EnemyState.h"
class WizardFlyingAttackState :
	public EnemyState
{
private:
	RectF Range;
	float speed;
	int step;
public:
	WizardFlyingAttackState(EnemyData *enemydata, RectF Range);
	void onUpdate();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);

	void onDead() override;
	~WizardFlyingAttackState();
};

