#pragma once

#include "SpriteData.h"
//#include "SBullet.h"
#include "CollisionRect.h"
#include "Define.h"
#include "BulletSprite.h"
class MegamanData : public SpriteData
{

public:
	RectF* bodyRects;
	
	//std::vector<BulletSprite *> Bullets;
	int count;
	RectF cameraRect;
	BulletTypes bulletType;
	int bulletSize;
	std::vector<BulletSprite *> Bullets;

	int hittableCounter;
	int nonHittableFrames;
	int nUndyingFrames;
	int undyingCounter;
	bool isOver;
	bool isRapid;
	bool isRespawn;
	bool isUndying;
	Direction movedir;

	bool isCharging;
	int ChargingCount;
	bool isFrire;
	int FireCountFrames;
public:
	MegamanData()
	{
		hittableCounter = 0;
		nonHittableFrames = 150;
		nUndyingFrames = 150;
		undyingCounter = 0;
		isOver = false;
		isRapid = false;
		isRespawn = true;
		isDead = false;
		isUndying = false;
	}
	enum SpriteArrayIndex
	{
		STAND,
		STANDSHOOT,
		RUN,
		RUNSHOOT,	
		JUMP,
		JUMPSHOOT,
		FALL,
		FALLSHOOT,
		SLIDE,
		SLIDESHOOT,
		WALLSLIDE,
		WALLSLIDESHOOT,
		START,
		DEAD,
		DAMAGED,
		NOCHARGE,
		CHARGING1,
		CHARGING2,
		CHARGING3,
		SIT,
		COUNT,
	};
	virtual void setiCurrentArray(int index)
	{
		iCurrentArr = index;
		body = bodyRects[index];
	}
	void reset()
	{
		this->x = cameraRect.x + 20;
		if (movedir.isRight())
		{
			this->y = cameraRect.y + 20;
		}
		else
			this->y = cameraRect.y + cameraRect.height / 2;
		this->isRespawn = true;
		this->isUndying = false;
		this->bulletType = BulletTypes::SHEILD;
		this->isDead = false;
	}
	
};