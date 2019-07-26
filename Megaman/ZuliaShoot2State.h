#pragma once
#include "EnemyState.h"
class ZuliaShoot2State :
	public EnemyState
{
private:
	RectF Range;
	float speed;
	float getYfromX(float Y, int counter);
	int mechCounter;
	int frameCounter;
public:
	ZuliaShoot2State(EnemyData *enemydata, RectF Range);
	void onUpdate();
	void createBee();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);

	void onDead() override;
	~ZuliaShoot2State();
};

