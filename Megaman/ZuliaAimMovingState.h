#pragma once
#include "BulletState.h"
#include "EnemyState.h"
#include "ZuliaAimData.h"

class ZuliaAimMovingState : public BulletState
{
private:
	float speed;
	RectF range;
	int waitting4updateVector;
	D3DXVECTOR2 Movingvector;
	float k;
public:
	ZuliaAimMovingState(SpriteData * pdata)
	{

		this->pData = pdata;
		pData->iCurrentArr = ZuliaAimData::FLY;
		this->range = range;
		waitting4updateVector = 0;
		Movingvector.x = 0;
		Movingvector.y = 0;


	}

	virtual void onUpdate() override
	{

		pData->ppTextureArrays[pData->iCurrentArr]->update();

		if (1) {
			float tempx = UIComponents::getInstance()->getMegamanX() - this->pData->x;
			float tempy = UIComponents::getInstance()->getMegamanY() - this->pData->y;
			D3DXVECTOR2 NewVector(tempx, tempy);
			/*Movingvector.x = UIComponents::getInstance()->getMegamanX() - this->pData->x;
			Movingvector.y = UIComponents::getInstance()->getMegamanY() - this->pData->y;*/
			Movingvector.x = (Movingvector.x + NewVector.x) / 2;
			Movingvector.y = (Movingvector.y + NewVector.y) / 2;

			k = sqrt(tempx*tempx + tempy * tempy) / 1.5;
		}
		waitting4updateVector += 1;


		if (this->pData->iCurrentArr == ZuliaAimData::FLY)
		{
			this->pData->x += Movingvector.x / k;
			this->pData->y += Movingvector.y / k;
		}
	}

	void onCollision(CollisionRectF rect) override
	{
		this->pData->isDesTroyed = true;
	}
};

