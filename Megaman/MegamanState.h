#pragma once

#include "SpriteState.h"
#include "MegamanData.h"
#include "CaptainKickSprite.h"
#include "CaptainSheildSprite.h"
//#include "Sound.h"

class MegamanState : public SpriteState
{
public:
	MegamanState() {
	
		acceleration = 0.2f;
	}
   
	virtual void transition(MegamanState* state)
	{
		//LogWriter::getInstance()->write(-1, state->pData->iCurrentArr);
		pData->pState = state;
		delete this;
	}
	virtual void onCameraCollision(RectF cameraRect)
	{
		pData->x = max(pData->x, cameraRect.x + 20);
		pData->x = min(pData->x, cameraRect.x + cameraRect.width - 20);
		if (pData->y > cameraRect.y + cameraRect.height)
		{
			pData->y = cameraRect.y + cameraRect.height;
			onDead();
		}
	}

	virtual void createBullet(float x, float y, float angle)
	{
		//3LogWriter::getInstance()->write(" creat new bullet  ");
		float speed = 0.0f;
		switch (pData->bulletType)
		{
		case BulletTypes::SHEILD :
			{
			LogWriter::getInstance()->write("Captain throw f*** sheild");
			speed = 4;
			speed *= (pData->isRapid) ? 1.25 : 1;
		//	pData->Bullets.push_back(new MgmNormalBulletSprite(this->pData->bulletSize, x, y, speed, angle));
		//	pData->Bullets.push_back(new CaptainSheildSprite(this->pData->bulletSize, x, y, speed, angle));
			if (pData->dir.isRight())
			{
				pData->Bullets.at(0)->Trigger(1);
			}
			else
			{
				pData->Bullets.at(0)->Trigger(2);
			}
			return;
		}
		case BulletTypes::KICK :
		{
			LogWriter::getInstance()->write("Captain kiiickkkkkk");
			speed = 4;
			speed *= (pData->isRapid) ? 1.25 : 1;
			pData->Bullets.push_back(new CaptainKickSprite(this->pData->bulletSize, x, y, speed, angle));
			return;
		}
		}
		//thêm các loại đạn ở đây
	}
	virtual void hittableCalculation()
	{
		if (!pData->isHittable)
		{
			pData->hittableCounter++;
			if ((pData->hittableCounter >= pData->nonHittableFrames))
			{
				pData->hittableCounter = 0;
				pData->isHittable = true;

			}
		}
	}
	virtual void undyingCalculation()
	{
		if (pData->isUndying)
		{
			pData->undyingCounter++;
			if ((pData->undyingCounter >= pData->nUndyingFrames))
			{
				pData->undyingCounter = 0;
				pData->isUndying = false;
			}
		}
	}
	

	virtual char getSizeofBullet(int count) {
		
		if (count < MEGAMAN_CHARGE_LIMIT_N) {
			if (MEGAMAN_CHARGE_LIMIT_N - count < 2) {
				Sound::getInstance()->play("MgmCharge", true, 1);
			}
			return MegamanData::NOCHARGE;
		}
		if (count < MEGAMAN_CHARGE_LIMIT_S) {
			return MegamanData::CHARGING1;
		}
		else
			return MegamanData::CHARGING2;
		
	}
protected:
	MegamanData* pData;
	//dùng để check xem khi phím dc release
	Direction tempDir;
	float acceleration; 
};