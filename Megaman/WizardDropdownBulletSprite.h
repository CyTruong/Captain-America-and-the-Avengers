#pragma once
#include "BulletSprite.h"
#include "WizardDropdownBulletData.h"

class WizardDropdownBulletSprite :
	public BulletSprite
{
protected:
	WizardDropdownBulletData *pData;
public:
	WizardDropdownBulletSprite(float x, float y);
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

	~WizardDropdownBulletSprite();
};

