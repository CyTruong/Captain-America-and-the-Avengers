#pragma once
#include "EnemySprite.h"
#include "BulletSprite.h"
#include "RocketSoldierData.h"


class RocketSoldierSprite :
	public EnemySprite
{
public:
	RocketSoldierSprite(float x, float y, Direction dir, bool isShoter, std::vector<BulletSprite*>& bullet);
	void setCollisionRect(CollisionRectF rect);
	void onCameraCollision(RectF cameraRect);

	~RocketSoldierSprite();
};