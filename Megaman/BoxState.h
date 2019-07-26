#pragma once
#include "EnemyState.h"
class BoxState :
	public EnemyState
{
private:
	
public:
	BoxState(EnemyData *pData);
	void onUpdate();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void createBullet();
	void onDead() override;
	~BoxState();
};

