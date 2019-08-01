#pragma once
#include "BulletState.h"
#include "WizardNormalBulletData.h"
#include "Sound.h"

class WizardNormalBulletMovingState : public BulletState
{
private:
	float speed;
public:
	WizardNormalBulletMovingState(WizardNormalBulletData * pdata, float speed, float angle, int icurent = 0) {

		this->pData = pdata;
		pData->iCurrentArr = icurent;
		this->speed = speed;
		pData->vy = sin(angle) * speed;
		pData->vx = cos(angle) * speed;
	}

	virtual void onUpdate() override
	{
		if (this->pData->iCurrentArr == WizardNormalBulletData::DESTROY && this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
			this->pData->isDesTroyed = true;
		}
		if (this->pData->iCurrentArr == WizardNormalBulletData::FLY)
		{
			pData->x += pData->vx;
			pData->y += pData->vy;
		}
		pData->ppTextureArrays[pData->iCurrentArr]->update();

	}

	virtual void onCollision(CollisionRectF rect) override
	{
		LogWriter::getInstance()->write("Wizard bullet destroy");
		this->pData->iCurrentArr = WizardNormalBulletData::DESTROY;
	}



};

