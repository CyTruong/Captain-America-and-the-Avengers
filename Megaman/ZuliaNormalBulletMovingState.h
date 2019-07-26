#pragma once
#include "BulletState.h"
#include "ZuliaNormalBulletData.h"

class ZuliaNormalBulletMovingState : public BulletState
{
private:
	float speed;
	RectF range;
	int StandCounter;
public:
	ZuliaNormalBulletMovingState(ZuliaNormalBulletData * pdata, float speed, float angle, RectF range) {

		this->pData = pdata;
		pData->iCurrentArr = ZuliaNormalBulletData::FLY;
		this->speed = speed;
		this->range = range;
		StandCounter = 0;
		pData->vy = sin(angle) * speed;
		pData->vx = cos(angle) * speed;
	}

	virtual void onUpdate() override
	{
		
		pData->ppTextureArrays[pData->iCurrentArr]->update();	

		bool outRange = pData->x < range.x || pData->x > range.x + range.width || pData->y< range.y || pData->y > range.y + range.height;
		if (outRange)
		{
			this->pData->iCurrentArr = ZuliaNormalBulletData::STAND;
		}
		
		if(this->pData->iCurrentArr == ZuliaNormalBulletData::FLY)
		{
			pData->x += pData->vx;
			pData->y += pData->vy;
		}

		if (this->pData->iCurrentArr == ZuliaNormalBulletData::STAND && StandCounter++ > 150) {
			this->pData->iCurrentArr = ZuliaNormalBulletData::DESTROY;
		}

		if (this->pData->iCurrentArr == ZuliaNormalBulletData::DESTROY   && this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture() ) {
			this->pData->isDesTroyed = true;
			Sound::getInstance()->play("BulletDestroy2", false, 1);

		}

	}

	void onCollision(CollisionRectF rect) override
	{
		this->pData->iCurrentArr = ZuliaNormalBulletData::DESTROY;
	}
};

