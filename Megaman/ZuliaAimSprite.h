#pragma once
#include "BulletSprite.h"
#include "UI.h"
class ZuliaAimSprite :
	public BulletSprite
{
public:
	ZuliaAimSprite(float x, float y);
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
	virtual void destroy() override;
	~ZuliaAimSprite();
};

