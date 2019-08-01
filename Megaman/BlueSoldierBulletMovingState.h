#pragma once
#include "BulletState.h"
#include "BlueSoldierBulletData.h"
class BlueSoldierBulletMovingState : public BulletState
{
private:
	float speed;
public:
	BlueSoldierBulletMovingState(BlueSoldierBulletData * pdata, float speed, float angle, int icurent = 0) {

		this->pData = pdata;

		pData->iCurrentArr = icurent;
		this->speed = speed;

		pData->vy = sin(angle) * speed;
		pData->vx = cos(angle) * speed;
	}

	virtual void onUpdate() override
	{
		/*if (this->pData->iCurrentArr == BlueSoldierBulletData::DESTROY && this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
			this->pData->isDesTroyed = true;
		}*/

		pData->ppTextureArrays[pData->iCurrentArr]->update();

		pData->x += pData->vx;

		pData->y += pData->vy;

	}

	 virtual void onCollision(CollisionRectF rect) override
	{
		/*char* str = _strdup(rect.type.c_str());
		if (str[0]=='e' && str[1] == 'n' && str[2] == 'e' && str[3] == 'm' && str[4] == 'y')
		{
			this->pData->iCurrentArr = BlueSoldierBulletData::SpriteArrayIndex::DESTROY;
		}*/
		this->pData->iCurrentArr = BlueSoldierBulletData::DESTROY;
		//hcmt 8/1 
		//if (rect.type == "enemy") {
		//	//this->pData->iCurrentArr = BlueSoldierBulletData::SpriteArrayIndex::DESTROY;
		//	this->pData->isDesTroyed = true;

		//}
	}
};

