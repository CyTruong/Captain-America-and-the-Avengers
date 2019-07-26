#pragma once
#include "BulletSprite.h"
#include "EnemySprite.h"
#include "ZuliaSpecialBulletData.h"
class ZuliaSpecialBulletSprite :
	public BulletSprite
{

public:
	ZuliaSpecialBulletSprite(float x, float y);
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
	~ZuliaSpecialBulletSprite();
};

