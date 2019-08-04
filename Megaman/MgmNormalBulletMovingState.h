#pragma once
#include "BulletState.h"
#include "MgmNormalBulletData.h"
class MgmNormalBulletMovingState : public BulletState
{
private:
	float speed;
public:
	MgmNormalBulletMovingState(MgmNormalBulletData * pdata, float speed, float angle, int icurent = 0) {

		this->pData = pdata;
		pData->iCurrentArr = icurent;
		this->speed = speed;

		pData->vy = sin(angle) * speed;
		pData->vx = cos(angle) * speed;
	}

	virtual void onUpdate() override
	{
		pData->ppTextureArrays[pData->iCurrentArr]->update();
		if (this->pData->iCurrentArr == MgmNormalBulletData::DESTROY && this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
			this->pData->isDesTroyed = true;
		}
		else
		{
			pData->ppTextureArrays[pData->iCurrentArr]->update();

		if (this->pData->iCurrentArr == MgmNormalBulletData::DESTROY && this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
			this->pData->isDesTroyed = true;
		}
		else
		{
			pData->ppTextureArrays[pData->iCurrentArr]->update();

			pData->x += pData->vx;

			pData->y += pData->vy;
		}
	}

	void onCollision(CollisionRectF rect) override
	{	
		/*char* str = _strdup(rect.type.c_str());
		if (str[0]=='e' && str[1] == 'n' && str[2] == 'e' && str[3] == 'm' && str[4] == 'y')
		{
			this->pData->iCurrentArr = MgmNormalBulletData::SpriteArrayIndex::DESTROY;
		}*/
		if (rect.type== "enemy") {
			//this->pData->iCurrentArr = MgmNormalBulletData::SpriteArrayIndex::DESTROY;
			this->pData->isDesTroyed = true;

		}
	}
};

