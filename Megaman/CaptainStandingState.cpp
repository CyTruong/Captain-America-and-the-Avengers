#pragma once
#include "CaptainStandingState.h"

CaptainStandingState::CaptainStandingState(CaptainData * data)
{
	//đứng thui chứ có làm cc gì nửa đâu
	// má đéo gán đối số :v 
	LogWriter::getInstance()->write("Vào Standing state");
	pData = data;
	pData->setiCurrentArray(CaptainData::STAND);
	pData->vx = 0;
}

void CaptainStandingState::onMovePressed(Direction d)
{
	pData->dir = d;
	// hcmt cam move 
	pData->movedir = d;
	transition(new CaptainRunningState(pData));
}

void CaptainStandingState::onJumpPressed()
{   // hcmt 
	//transition(new MegamanJumpState(this->pData, false, -4.5f));
}

void CaptainStandingState::onSlidePressed()
{
	//transition(new MegamanSlideState(this->pData));
}

void CaptainStandingState::onUpdate()
{
	hittableCalculation();
	undyingCalculation();

	pData->vy += acceleration;
	pData->y += pData->vy;

	if (pData->isFrire && pData->iCurrentArr == CaptainData::STAND) {
		pData->setiCurrentArray(CaptainData::STANDSHOOT);
	}
	if (!pData->isFrire && pData->iCurrentArr == CaptainData::STANDSHOOT) {
		pData->setiCurrentArray(CaptainData::STAND);
	}

	pData->ppTextureArrays[pData->iCurrentArr]->update();

	/*if (pData->isCharging) {
		pData->ChargingCount++;
		pData->bulletSize = getSizeofBullet(pData->ChargingCount);
		pData->ppTextureArrays[pData->bulletSize]->update();
	}
	*/
	if (pData->isFrire) {
		pData->FireCountFrames++;
		if (pData->FireCountFrames > FIRE_COUNTING_FRAME) {
			pData->FireCountFrames = 0;
			pData->isFrire = false;
		}
	}

}

void CaptainStandingState::onCollision(CollisionRectF cRect)
{
	pData->y -= pData->vy;
	pData->vy -= acceleration;
}

void CaptainStandingState::onDynamicObjectCollision(CollisionRectF * rect)
{
	if (rect->type == "elevator") {
		pData->y = pData->y - pData->vy - 1;
		pData->movedir = Direction::createUp();
	}
	else
		pData->y -= pData->vy;

	pData->vy -= acceleration;
}


void CaptainStandingState::onVeticalDirectionPressed(Direction d)
{
	pData->verticalDir = d;
}

void CaptainStandingState::onVeticalDirectionReleased()
{
	pData->verticalDir = Direction::createNone();
	pData->setiCurrentArray(CaptainData::STAND);
}

void CaptainStandingState::onFirePressed()
{
	pData->isCharging = true;
}

void CaptainStandingState::onFireRelease()
{
	if (!this->pData->isFrire) {
		pData->isCharging = false;
		pData->isFrire = true;
		pData->ChargingCount = 0;


		float bulletX;
		float bulletY;
		float angle;

		if (pData->dir.isRight())
		{
			bulletX = pData->ppTextureArrays[pData->iCurrentArr]->getWidth() * 2 / 5 + pData->x;
		}
		else
		{
			bulletX = -pData->ppTextureArrays[pData->iCurrentArr]->getWidth() * 2 / 5 + pData->x;
		}

		bulletY = pData->y - pData->ppTextureArrays[pData->iCurrentArr]->getHeight() * 5 / 12 + 3;


		if (pData->dir.isRight())
		{
			angle = 0.0f;
		}
		else
		{
			angle = M_PI;
		}
		createBullet(bulletX, bulletY, angle);
	}
}

void CaptainStandingState::onFall()
{
	//LogWriter::getInstance()->write("Falling in standing state");
}

void CaptainStandingState::onDead()
{
}

