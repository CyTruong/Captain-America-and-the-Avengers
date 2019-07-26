#pragma once
#include "BulletSprite.h"
#include "CaptainKickData.h"


class CaptainKickSprite :
	public BulletSprite
{
public:
	BulletSize bulletSize;
private:
	CaptainKickData *pData;
public:
	CaptainKickSprite(int size, float x, float y, float speed, float angle);
	virtual void draw(Camera * cam);
	virtual void update();
	virtual SpriteState* getState()
	{
		return pData->pState;
	}
	virtual void Trigger(int index) override;

	~CaptainKickSprite();
};

