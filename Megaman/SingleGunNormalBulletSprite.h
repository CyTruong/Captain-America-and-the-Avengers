#pragma once
#include "BulletSprite.h"
#include "SingleGunNormalBulletData.h"

class SingleGunNormalBulletSprite :
	public BulletSprite
{
protected:
	SingelGunNormalBulletData *pData;
public:
	SingleGunNormalBulletSprite(float x, float y, float angle);
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

	~SingleGunNormalBulletSprite();
};

