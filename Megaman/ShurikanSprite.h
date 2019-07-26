#pragma once
#include "EnemySprite.h"
#include "ShurikanData.h"

class ShurikanSprite :
	public EnemySprite
{
public:
	ShurikanSprite(float x, float y);
	void setCollisionRect(CollisionRectF rect);
	void onCameraCollision(RectF cameraRect) ;
	~ShurikanSprite();
};

