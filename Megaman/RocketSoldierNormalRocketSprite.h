#pragma once
#include "BulletSprite.h"
#include "EnemySprite.h"
#include "RocketSoldierNormalRocketData.h"
class RocketSoldierNormalRocketSprite :
	public BulletSprite
{

public:
	RocketSoldierNormalRocketSprite(float x, float y);
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
	~RocketSoldierNormalRocketSprite();
};

