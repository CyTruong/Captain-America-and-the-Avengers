#pragma once
#include "EnemyState.h"
#include "ShurikanData.h"

class ShurikanBounceAttackState :
	public EnemyState
{
private:
	float speed;
	int FrameJump;
	int FrameRun;
	int jumpCount;
public:
	ShurikanBounceAttackState(EnemyData *  );
	void onUpdate();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void onDead() override;

	~ShurikanBounceAttackState();
};

