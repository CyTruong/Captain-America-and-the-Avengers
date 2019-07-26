#pragma once
#include "MegamanSittingState.h"
#include "MegamanRunningState.h"
#include "MegamanJumpState.h"
#include "MegamanSlideState.h"
#include "MegamanDamagedState.h"
#include "MegamanStandingState.h"

MegamanSittingState::MegamanSittingState(MegamanData * data)
{
	//đứng thui chứ có làm cc gì nửa đâu
	// má đéo gán đối số :v 
//LogWriter::getInstance()->write("Vào Standing state");
	pData = data;
	pData->setiCurrentArray(MegamanData::SIT);
	pData->vx = 0;
}

void MegamanSittingState::onMovePressed(Direction d)
{
	pData->dir = d;
	// hcmt cam move 
	pData->movedir = d;
	transition(new MegamanRunningState(pData));
}

void MegamanSittingState::onJumpPressed()
{   // hcmt 
	transition(new MegamanJumpState(this->pData, false, -8));
}

void MegamanSittingState::onSlidePressed()
{
	transition(new MegamanSlideState(this->pData));
}

void MegamanSittingState::onUpdate()
{
	hittableCalculation();
	undyingCalculation();

	pData->vy += acceleration;
	pData->y += pData->vy;

	if (pData->isFrire && pData->iCurrentArr == MegamanData::SIT) {
		pData->setiCurrentArray(MegamanData::SIT);
	}
	if (!pData->isFrire && pData->iCurrentArr == MegamanData::SIT) {
		pData->setiCurrentArray(MegamanData::SIT);
	}

	pData->ppTextureArrays[pData->iCurrentArr]->update();

	if (pData->isCharging) {
		pData->ChargingCount++;
		pData->bulletSize = getSizeofBullet(pData->ChargingCount);
		pData->ppTextureArrays[pData->bulletSize]->update();
	}

	if (pData->isFrire) {
		pData->FireCountFrames++;
		if (pData->FireCountFrames > FIRE_COUNTING_FRAME) {
			pData->FireCountFrames = 0;
			pData->isFrire = false;
		}
	}

}

void MegamanSittingState::onCollision(CollisionRectF cRect)
{
	pData->y -= pData->vy;
	pData->vy -= acceleration;
}

void MegamanSittingState::onDynamicObjectCollision(CollisionRectF * rect)
{
	if (rect->type == "elevator") {
		pData->y = pData->y - pData->vy - 1;
		pData->movedir = Direction::createUp();
	}
	else
		pData->y -= pData->vy;

	pData->vy -= acceleration;
}


void MegamanSittingState::onVeticalDirectionPressed(Direction d)
{
	pData->verticalDir = d;
}

void MegamanSittingState::onVeticalDirectionReleased()
{
	pData->verticalDir = Direction::createNone();
	/*if (pData->verticalDir == Direction::createUp()) {
		transition(new MegamanStandingState(this->pData));
	}
*/
	transition(new MegamanStandingState(this->pData));

}

void MegamanSittingState::onFirePressed()
{
	//	pData->isCharging = true;
}

void MegamanSittingState::onFireRelease()
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

void MegamanSittingState::onFall()
{
	//LogWriter::getInstance()->write("Falling in standing state");
}

void MegamanSittingState::onDead()
{
}

