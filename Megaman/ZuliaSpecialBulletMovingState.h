#pragma once
#include "BulletState.h"
#include "EnemyState.h"
#include "ZuliaSpecialBulletData.h"

class ZuliaSpecialBulletMovingState : public BulletState
{
private:
	float speed;
	RectF range;
	int waitting4updateVector;
	D3DXVECTOR2 Movingvector;
	float k;
public:
	ZuliaSpecialBulletMovingState(SpriteData * pdata, float speed,RectF range)
	{
		 
		this->pData = pdata;
		pData->iCurrentArr = ZuliaSpecialBulletData::FLY;
		this->range = range;
		waitting4updateVector = 0;
		Movingvector.x = 0;
		Movingvector.y = 0;
	

	}

	virtual void onUpdate() override
	{

		pData->ppTextureArrays[pData->iCurrentArr]->update();

		bool outRange = pData->x < range.x || pData->x > range.x + range.width || pData->y< range.y || pData->y > range.y + range.height;
		if (outRange || waitting4updateVector > 300)
		{
			this->pData->iCurrentArr = ZuliaSpecialBulletData::DESTROY;
		}
		if (waitting4updateVector % 20  == 0) {
			float tempx = UIComponents::getInstance()->getMegamanX() - this->pData->x;
			float tempy = UIComponents::getInstance()->getMegamanY() - this->pData->y;
			D3DXVECTOR2 NewVector(tempx, tempy);
			/*Movingvector.x = UIComponents::getInstance()->getMegamanX() - this->pData->x;
			Movingvector.y = UIComponents::getInstance()->getMegamanY() - this->pData->y;*/
			Movingvector.x = (Movingvector.x + NewVector.x) / 2;
			Movingvector.y = (Movingvector.y + NewVector.y) / 2;

			// 1.8 chinh speed  
			k = sqrt(tempx*tempx + tempy*tempy) / 1.8;
		}
		waitting4updateVector += 1;


		if (this->pData->iCurrentArr == ZuliaSpecialBulletData::FLY)
		{
			this->pData->x += Movingvector.x / k;
			this->pData->y += Movingvector.y / k;

		}


		if (this->pData->iCurrentArr == ZuliaSpecialBulletData::DESTROY   && this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
			this->pData->isDesTroyed = true;
			Sound::getInstance()->play("BulletDestroy2", false, 1);

		}

	}

	void onCollision(CollisionRectF rect) override
	{
		this->pData->iCurrentArr = ZuliaSpecialBulletData::DESTROY;
	}
};

