#pragma once
#include "BulletSprite.h"
#include "MgmNormalBulletData.h"
#include "MegamanData.h"



class MgmNormalBulletSprite :
	public BulletSprite
{
public:
	BulletSize bulletSize;
private:
	MgmNormalBulletData *pData;
public:
	MgmNormalBulletSprite(int size, float x, float y ,float speed, float angle);
	virtual void draw(Camera * cam);
	virtual void update();
	virtual SpriteState* getState()
	{
		return pData->pState;
	}

	BulletSize ConvertSizeIndex(int size) override {
		if ((MegamanData::SpriteArrayIndex)size == MegamanData::NOCHARGE ) {
			return BulletSize::SMALL;
		}
		if ((MegamanData::SpriteArrayIndex)size == MegamanData::CHARGING1) {
			return BulletSize::MEDIUM;
		}
		if ((MegamanData::SpriteArrayIndex)size == MegamanData::CHARGING2) {
			return BulletSize::LARGE;
		}
		return BulletSize::SMALL;
		//... tiếp tục convert
	}
	~MgmNormalBulletSprite();
};

