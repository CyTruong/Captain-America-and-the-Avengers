#pragma once
#include "EnemyState.h"
class ZuliaAlphaFlyState :
	public EnemyState
{
private:
	RectF Range;
	float speed;
	float getYfromX(float Y,int counter);
	int mechCounter;
	int frameCounter;
public:
	ZuliaAlphaFlyState(EnemyData *enemydata,RectF Range);
	void onUpdate();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);

	void onDead() override;
	~ZuliaAlphaFlyState();
};

