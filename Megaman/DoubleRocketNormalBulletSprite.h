#pragma once
#include "BulletSprite.h"
#include "DoubleRocketNormalBulletData.h"

class DoubleRocketNormalBulletSprite : public BulletSprite
{
protected:
	DoubleRocketNormalBulletData* pData;
public:
	DoubleRocketNormalBulletSprite(float x, float y, float angle);
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

	~DoubleRocketNormalBulletSprite();
};
