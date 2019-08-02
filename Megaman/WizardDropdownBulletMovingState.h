#pragma once
#include "BulletState.h"
#include "WizardDropdownBulletData.h"
#include "Sound.h"

class WizardDropdownBulletMovingState : public BulletState
{
private:
	float speed;
public:
	WizardDropdownBulletMovingState(WizardDropdownBulletData * pdata, float speed, int icurent = 0) {

		this->pData = pdata;
		pData->iCurrentArr = icurent;
		this->speed = speed;
		pData->vy = 1* speed;
	}

	virtual void onUpdate() override
	{
		if (this->pData->iCurrentArr == WizardDropdownBulletData::DESTROY && this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
			this->pData->isDesTroyed = true;
		}
		if (this->pData->iCurrentArr == WizardDropdownBulletData::FLY)
		{
			pData->y += pData->vy;
		}
		pData->ppTextureArrays[pData->iCurrentArr]->update();

	}

	virtual void onCollision(CollisionRectF rect) override
	{
		LogWriter::getInstance()->write("Wizard bullet destroy");
		this->pData->iCurrentArr = WizardDropdownBulletData::DESTROY;
	}



};

