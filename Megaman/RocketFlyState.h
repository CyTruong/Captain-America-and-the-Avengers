#pragma once
#include "EnemyState.h"
class RocketFlyState :
	public EnemyState
{
private:
	int gun; // Dùng để xác định súng trên hay súng dưới
	int waittingframe;
public:
	RocketFlyState(EnemyData *pData);
	void onUpdate();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void createBullet();
	void onDead() override;
	~RocketFlyState();
};

