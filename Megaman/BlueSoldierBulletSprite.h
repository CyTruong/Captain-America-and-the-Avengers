#pragma once
#include "BulletSprite.h"
#include "BlueSoldierBulletData.h"
#include "MegamanData.h"



class BlueSoldierBulletSprite :
	public BulletSprite
{
public:
	
private:
	BlueSoldierBulletData *pData;
public:
	BlueSoldierBulletSprite( float x, float y, float speed, float angle);
	virtual void draw(Camera * cam);
	virtual void update();
	virtual SpriteState* getState()
	{
		return pData->pState;
	}

	~BlueSoldierBulletSprite();
};

