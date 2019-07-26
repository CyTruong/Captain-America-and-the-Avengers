#pragma once
#include "EnemyState.h"

class ZuliaShootState :
	public EnemyState
{
private:
	RectF range;
	int counterFrame;
public:
	ZuliaShootState(EnemyData *enemydata, RectF Range);
	void onUpdate();
	void createBee();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void onDead() override;
	~ZuliaShootState();
};

