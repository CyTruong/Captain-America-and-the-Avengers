#pragma once
#include "EnemySprite.h"
#include "DoubleRocketData.h"
class RocketFlySprite :
	public EnemySprite
{
public:
	RocketFlySprite(float x, float y, Direction dir, bool isShoter, std::vector<BulletSprite*>& bullet);
	void setCollisionRect(CollisionRectF rect);
	void onCameraCollision(RectF cameraRect);
	~RocketFlySprite();
};

