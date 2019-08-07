#pragma once

#include "Sprite.h"
#include "MgmNormalBulletData.h"

class BulletSprite : public Sprite 
{
protected:
	float angle;
public :
	BulletSprite() {}
	virtual void draw(Camera * cam) = 0;
	virtual void update() = 0;
	virtual bool isDesTroyed() { return pData->isDesTroyed; }
	virtual bool isHittable() { return pData->isHittable; }
	virtual void destroy() { 
		Sound::getInstance()->play("BulletDestroy", false, 1);
		pData->isDesTroyed = true; 
	}
	//virtual RectF getBulletBodyRect() = 0;
	virtual BulletSize ConvertSizeIndex(int size) { return BulletSize::SMALL;  };
	virtual void Trigger(int index) { };
	virtual SpriteData* getPdata() {
		return this->pData;
	}
};