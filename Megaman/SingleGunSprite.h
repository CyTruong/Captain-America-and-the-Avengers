#pragma once
#include "EnemySprite.h"
#include "BulletSprite.h"
#include "SingleGunData.h"


class SingleGunSprite :
	public EnemySprite
{
public:
	SingleGunSprite(float x, float y, Direction dir, bool isShoter, std::vector<BulletSprite*>& bullet );
	void setCollisionRect(CollisionRectF rect);
	void onCameraCollision(RectF cameraRect);
	~SingleGunSprite();
};

