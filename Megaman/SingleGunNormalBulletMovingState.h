#pragma once
#include "BulletState.h"
#include "SingleGunNormalBulletData.h"

class SingleGunNormalBulleMovingState : public BulletState
{
private:
	float gravity;
public:
	SingleGunNormalBulleMovingState(SingelGunNormalBulletData * pdata,float speed, float angle, int icurent = 0) {

		this->pData = pdata;
		pData->iCurrentArr = icurent;
		pData->vy = sin(angle) * speed;
		pData->vx = cos(angle) * speed;
		gravity = 0.5;
	}

	virtual void onUpdate() override
	{
		if (!this->pData->ppTextureArrays[SingelGunNormalBulletData::FLY]->isLastTexture()) {
			pData->ppTextureArrays[pData->iCurrentArr]->update();
		}
		
		if (this->pData->iCurrentArr == SingelGunNormalBulletData::FLY)
		{
			pData->vy += gravity;

			pData->x += pData->vx;

			pData->y += pData->vy;
		}
		else
		{
			if (this->pData->ppTextureArrays[SingelGunNormalBulletData::DESTROY]->isLastTexture()) {
				Sound::getInstance()->play("BulletDestroy", false, 1);
				this->pData->isDesTroyed = true;
			}
		}
	}

	virtual void onCollision(CollisionRectF rect) override
	{
		this->pData->iCurrentArr = SingelGunNormalBulletData::DESTROY;
	}



};

