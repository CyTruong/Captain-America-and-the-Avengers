#pragma once
#include "BulletState.h"
#include "EnemyState.h"
#include "RocketSoldierNormalRocketData.h"

class RocketSoldierNormalRocketMovingState : public BulletState
{
private:
	float speed;
	int waitting4updateVector;
	D3DXVECTOR2 Movingvector;
	float k;
public:
	RocketSoldierNormalRocketMovingState(SpriteData * pdata, float speed)
	{

		this->pData = pdata;
		pData->iCurrentArr = RocketSoldierNormalRocketData::FLY;
		waitting4updateVector = 0;
		Movingvector.x = 0;
		Movingvector.y = 0;


	}

	virtual void onUpdate() override
	{

		pData->ppTextureArrays[pData->iCurrentArr]->update();

		if ( waitting4updateVector > 300)
		{
			this->pData->iCurrentArr = RocketSoldierNormalRocketData::DESTROY;
		}
		if (waitting4updateVector % 20 == 0) {
			float tempx = UIComponents::getInstance()->getMegamanX() - this->pData->x;
			float tempy = UIComponents::getInstance()->getMegamanY() - this->pData->y;
			D3DXVECTOR2 NewVector(tempx, tempy);
			/*Movingvector.x = UIComponents::getInstance()->getMegamanX() - this->pData->x;
			Movingvector.y = UIComponents::getInstance()->getMegamanY() - this->pData->y;*/
			Movingvector.x = (Movingvector.x + NewVector.x) / 2;
			Movingvector.y = (Movingvector.y + NewVector.y) / 2;

			k = sqrt(tempx*tempx + tempy * tempy) / 1.8;
		}
		waitting4updateVector += 1;


		if (this->pData->iCurrentArr == RocketSoldierNormalRocketData::FLY)
		{
			this->pData->x += Movingvector.x / k;
			this->pData->y += Movingvector.y / k;

		}


		if (this->pData->iCurrentArr == RocketSoldierNormalRocketData::DESTROY   && this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
			this->pData->isDesTroyed = true;
			Sound::getInstance()->play("BulletDestroy2", false, 1);

		}

	}

	void onCollision(CollisionRectF rect) override
	{
		this->pData->iCurrentArr = RocketSoldierNormalRocketData::DESTROY;
	}
};

