#pragma once
#include "EnemySprite.h"
#include "WizardData.h"
class WizardSprite :
	public EnemySprite
{
public:
	WizardSprite(float x, float y, Direction dir, bool isShoter, std::vector<BulletSprite*>& bullet);
	void setCollisionRect(CollisionRectF rect);
	void onCameraCollision(RectF cameraRect);
	~WizardSprite();
};

