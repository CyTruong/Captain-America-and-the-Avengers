#include "MegamanSlideState.h"
#include "MegamanJumpState.h"
#include "MegamanRunningState.h"
#include "MegamanStandingState.h"


MegamanSlideState::~MegamanSlideState()
{
}

MegamanSlideState::MegamanSlideState(MegamanData* data)
{
	this->pData = data;
	this->pData->setiCurrentArray(MegamanData::SLIDE);
	speedSlideX = 8;
	Friction = 0.35f;
	UIComponents::getInstance()->setSheild_Direction(Direction::createNone());
}

void MegamanSlideState::onMovePressed(Direction dir)
{
	pData->movedir = dir; 
	pData->dir = dir;
}

void MegamanSlideState::onMoveReleased(Direction dir)
{
	
}

void MegamanSlideState::onVeticalDirectionPressed(Direction dir)
{
//	pData->dir = dir;
}

void MegamanSlideState::onVeticalDirectionReleased()
{
	pData->verticalDir = Direction::createNone();
}

void MegamanSlideState::onJumpPressed()
{

}

void MegamanSlideState::onJumpRelease()
{

	transition(new MegamanJumpState(this->pData, true, -4.5f));
}

void MegamanSlideState::onSlidePressed()
{
}

void MegamanSlideState::onUpdate()
{
	hittableCalculation();
	undyingCalculation();
	pData->ppTextureArrays[MegamanData::SLIDE]->update();
	pData->vx = pData->transform(speedSlideX);
	speedSlideX -= Friction;
	pData->x += pData->vx;
	
	pData->movedir = pData->dir; 

	
	if (pData->isCharging) {
		pData->ChargingCount++;
		pData->bulletSize = getSizeofBullet(pData->ChargingCount);
		pData->ppTextureArrays[pData->bulletSize]->update();
	}

	if (pData->isFrire && pData->iCurrentArr == MegamanData::SLIDE) {
		pData->setiCurrentArray(MegamanData::SLIDESHOOT);
	}
	if (!pData->isFrire && pData->iCurrentArr == MegamanData::SLIDESHOOT) {
		pData->setiCurrentArray(MegamanData::SLIDE);
	}

	if (pData->isFrire) {
		pData->FireCountFrames++;
		if (pData->FireCountFrames > FIRE_COUNTING_FRAME) {
			pData->FireCountFrames = 0;
			pData->isFrire = false;
		}
	}

	if(speedSlideX<= 0)
	{
		transition(new MegamanStandingState(pData));

		/*if (pData->vy != 0) 
		{	
			transition(new MegamanJumpState(pData, true, pData->vy));	
		}
		else
		{
			transition(new MegamanStandingState(pData));
		}*/
	}



}

void MegamanSlideState::onCollision(RectF rect)
{
}

void MegamanSlideState::onCollision(CollisionRectF crect)
{
	
}

void MegamanSlideState::onDynamicObjectCollision(CollisionRectF * rect)
{
}

void MegamanSlideState::onFall()
{
}

void MegamanSlideState::onMoveVerticalPressed(Direction dir)
{
}

void MegamanSlideState::onMoveVerticalReleased(Direction dir)
{
}

void MegamanSlideState::onFirePressed()
{
	pData->isCharging = true;

}

void MegamanSlideState::onFireRelease()
{
	/*if (!this->pData->isFrire) {
		pData->isCharging = false;
		pData->isFrire = true;
		pData->ChargingCount = 0;
		pData->isCharging = false;
		pData->isFrire = true;
		pData->ChargingCount = 0;


		float bulletX;
		float bulletY;
		float angle;

		if (pData->dir.isRight())
		{
			bulletX = pData->ppTextureArrays[pData->iCurrentArr]->getWidth() / 2 + pData->x;
		}
		else
		{
			bulletX = -pData->ppTextureArrays[pData->iCurrentArr]->getWidth() / 2 + pData->x;
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
	}*/
}

void MegamanSlideState::onDead()
{
}

void MegamanSlideState::onCameraCollision(RectF cameraRect)
{
}

void MegamanSlideState::createBullet(float x, float y, float angle)
{
}
