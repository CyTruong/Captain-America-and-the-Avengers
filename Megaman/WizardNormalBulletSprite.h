#pragma once
#include "BulletSprite.h"
#include "WizardNormalBulletData.h"

class WizardNormalBulletSprite :
	public BulletSprite
{
protected:
	WizardNormalBulletData *pData;
public:
	WizardNormalBulletSprite(float x, float y, float angle);
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

	~WizardNormalBulletSprite();
};

