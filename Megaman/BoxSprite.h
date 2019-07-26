#pragma once
#include "EnemySprite.h"
#include "DoubleRocketData.h"
class BoxSprite :
	public EnemySprite
{
public:
	BoxSprite(float x, float y, Direction dir, bool isShoter, std::vector<BulletSprite*>& bullet);
	void setCollisionRect(CollisionRectF rect);
	void onCameraCollision(RectF cameraRect);
	~BoxSprite();
};

