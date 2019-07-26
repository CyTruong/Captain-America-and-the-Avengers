#pragma once

#include "SpriteState.h"
#include "CaptainData.h"

class CaptainState :  public SpriteState
{
public:
	CaptainState() {

		acceleration = 0.2f;
	}
	virtual void transition(CaptainState* state)
	{
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
		case BulletTypes::NORMAL:
			{
			speed = 8;
			speed *= (pData->isRapid) ? 1.25 : 1;
			//pData->Bullets.push_back(new MgmNormalBulletSprite(this->pData->bulletSize, x, y, speed, angle));
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



protected:
	CaptainData *pData;
	//dùng để check xem khi phím dc release
	Direction tempDir;
	float acceleration;
};