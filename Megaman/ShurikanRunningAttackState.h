#pragma once
#include "EnemyState.h"
class ShurikanRunningAttackState :
	public EnemyState
{
private:
	float speed;
	int counttingJump;
	int jumptimes;
public:
	ShurikanRunningAttackState(EnemyData* pData);
	void onUpdate();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void onDead() override;

	~ShurikanRunningAttackState();
};

