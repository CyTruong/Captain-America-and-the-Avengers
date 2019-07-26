#pragma once
#include "EnemyState.h"
class ShurikanWallAttackState :
	public EnemyState
{
private:
	float midX, midY;
	RectF BoundingRect;
	float speed;
	long waitting2changecount;
public:
	ShurikanWallAttackState(EnemyData * );
	void onUpdate();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void onDead() override; 

	~ShurikanWallAttackState();
};

