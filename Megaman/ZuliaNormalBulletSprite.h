#pragma once
#include "BulletSprite.h"
#include "ZuliaNormalBulletData.h"
class ZuliaNormalBulletSprite :
	public BulletSprite
{
protected:
	ZuliaNormalBulletData * pData;
public:
	ZuliaNormalBulletSprite(float x,float y, float angle, RectF range);
	virtual void draw(Camera * cam);
	virtual void update();
	virtual SpriteState* getState()
	{
		return pData->pState;
	}
	virtual SpriteData* getSpriteData()
	{
		return BulletSprite::pData;
	}
	virtual void onCameraCollision(RectF cameraRect) override {};
	~ZuliaNormalBulletSprite();
};

