#pragma once
#include "EnemySprite.h"
#include "BulletSprite.h"
#include "BlueSoldierData.h"


class BlueSoldierSprite :
	public EnemySprite
{
public:
	BlueSoldierSprite(float x, float y, Direction dir, bool isShoter, std::vector<BulletSprite*>& bullet);
	void setCollisionRect(CollisionRectF rect);
	void onCameraCollision(RectF cameraRect);
	
	~BlueSoldierSprite();
};

