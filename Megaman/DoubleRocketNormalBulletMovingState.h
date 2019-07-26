#pragma once
#include "BulletState.h"
#include "DoubleRocketNormalBulletData.h"

class DoubleRocketNormalBulletMovingState : public BulletState {
private:
	float gravity;
public:
	DoubleRocketNormalBulletMovingState(DoubleRocketNormalBulletData * pdata, float speed, float angle, int icurent = 0) {

		this->pData = pdata;
		pData->iCurrentArr = icurent;
		pData->vy = sin(angle) * speed;
		pData->vx = cos(angle) * speed;
		
	}

	virtual void onUpdate() override
	{
		pData->ppTextureArrays[pData->iCurrentArr]->update();

		if (this->pData->iCurrentArr == DoubleRocketNormalBulletData::FLY)
		{
			pData->x += pData->vx;
			pData->y += pData->vy;
		}
		else
		{
			if (this->pData->ppTextureArrays[DoubleRocketNormalBulletData::DESTROY]->isLastTexture()) {
				Sound::getInstance()->play("BulletDestroy2", false, 1);
				this->pData->isDesTroyed = true;
			}
		}
	}

	virtual void onCollision(CollisionRectF rect) override
	{
		this->pData->iCurrentArr = DoubleRocketNormalBulletData::DESTROY;
	}
};

