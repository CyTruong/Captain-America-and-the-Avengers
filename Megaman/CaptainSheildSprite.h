#pragma once
#include "BulletSprite.h"
#include "CaptainSheildData.h"


class CaptainSheildSprite :
	public BulletSprite
{
public:
	BulletSize bulletSize;
private:
	CaptainSheildData *pData;
public:
	CaptainSheildSprite(int size, float x, float y, float speed, float angle);
	virtual void draw(Camera * cam);
	virtual void update();
	virtual SpriteState* getState()
	{
		return pData->pState;
	}
	virtual void Trigger(int index) override;

	~CaptainSheildSprite();
};

