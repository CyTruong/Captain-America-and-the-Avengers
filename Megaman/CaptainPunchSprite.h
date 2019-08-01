#pragma once
#include "BulletSprite.h"
#include "CaptainPunchData.h"


class CaptainPunchSprite :
	public BulletSprite
{
public:
	BulletSize bulletSize;
private:
	CaptainPunchData *pData;
public:
	CaptainPunchSprite(int size, float x, float y, float speed, float angle);
	virtual void draw(Camera * cam);
	virtual void update();
	virtual SpriteState* getState()
	{
		return pData->pState;
	}
	virtual void Trigger(int index) override;

	~CaptainPunchSprite();
};

