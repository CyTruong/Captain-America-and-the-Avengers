#include "MegamanRunningState.h"
#include "define.h"
#include "MegamanStandingState.h"
#include "MegamanJumpState.h"
#include "KeyBoard.h"
#include "MegamanSlideState.h"

MegamanRunningState::MegamanRunningState(MegamanData* data) 
{
	LogWriter::getInstance()->write("Vào Running state");
	this->pData = data;

	if (pData->isFrire) {
		pData->setiCurrentArray(MegamanData::RUNSHOOT);
	}
	else
	{
		pData->setiCurrentArray(MegamanData::RUN);

	}
	pData->vy = 0;
	tempDir = pData->dir;
}

void MegamanRunningState::onMovePressed(Direction d)
{
	pData->dir = d;
	tempDir = d;
	// hcmt cam move 
	pData->movedir = d; 

}

void MegamanRunningState::onMoveReleased(Direction d)
{
	tempDir = tempDir ^ d;
	if(!tempDir.isNone())
	{		
		pData -> dir = tempDir;

		// hcmt cam move 
		pData->movedir = tempDir;


	}
	else
	transition(new MegamanStandingState(pData)); // thả đúng phím
}

void MegamanRunningState::onUpdate()
{
	// cai nay thay lun OnFall 
	if (pData->vy > 0)
	{
		transition(new MegamanJumpState(pData, true, pData->vy));
		return;
	}

	if (pData->isFrire && pData->iCurrentArr == MegamanData::RUN) {
		pData->setiCurrentArray(MegamanData::RUNSHOOT);
	}

	if ((!pData->isFrire) && pData->iCurrentArr == MegamanData::RUNSHOOT) {
		pData->setiCurrentArray(MegamanData::RUN);
	}

	hittableCalculation();
	undyingCalculation();
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	pData->vx = pData->transform(MEGAMANRUNSPEED);
	pData->x += pData->vx;

	pData->vy += acceleration;
	pData->y += pData->vy;
	pData->movedir = pData->dir;


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


void MegamanRunningState::onJumpPressed()
{
	transition(new MegamanJumpState(this->pData, true, -8.0f));
}

void MegamanRunningState::onSlidePressed()
{
	transition(new MegamanSlideState(this->pData));
}

void MegamanRunningState::onCollision(RectF rect)
{
	if (pData->vx > 0)
	{
		pData->x -= pData->getBody().x + pData->getBody().width - rect.x;
		pData->vx = 0;
		pData->vy -= acceleration; 
		pData->y -=pData-> vy; 


	} 
	else
	{
		pData->x += rect.x + rect.width - pData->getBody().x;
		pData->vx = 0;
		pData->vy -= acceleration;
		pData->y -= pData->vy;

	}
}

void MegamanRunningState::onCollision(CollisionRectF crect)
{
//	LogWriter::getInstance()->write("Ruuning state collision");
	//pData->cThroughRect.push_back(crect);
	if (pData->vx > 0)
	{   //  == wall 
		if (crect.type!="ground") {
			pData->x -= (pData->x + pData->getBody().width - crect.rect.x);

		}
		pData->vx = 0;
		pData->y -= pData->vy;
		pData->vy -= acceleration;
	}
	else
	{  //  == wall 
		if (crect.type != "ground") {
			int a = (crect.rect.x + crect.rect.width - pData->getBody().x); 

			pData->x =pData->x+a;

		}
		pData->vx = 0;
		pData->y -= pData->vy;
		pData->vy -= acceleration;
	}


}

void MegamanRunningState::onDynamicObjectCollision(CollisionRectF * crect)
{
	//pData->dynamicThroughRect.push_back(rect);

	if (pData->vx > 0)
	{
		/*pData->x -= pData->getBody().x + pData->getBody().width - crect->rect.x;
		pData->vx = 0;
		pData->y -= pData->vy;
		pData->vy -= acceleration;
*/


	}
	else
	{
		pData->x += crect->rect.x + crect->rect.width - pData->getBody().x;
		pData->vx = 0;
		pData->y -= pData->vy;
		pData->vy -= acceleration;
	}
}

void MegamanRunningState::onFall()
{
}

void MegamanRunningState::onFirePressed()
{
	//pData->isCharging = true;

}

void MegamanRunningState::onFireRelease()
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

	} 
}

void MegamanRunningState::onVeticalDirectionPressed(Direction d)
{
	pData->verticalDir = d;
}

void MegamanRunningState::onVeticalDirectionReleased()
{
	pData->verticalDir = Direction::createNone();
}

void MegamanRunningState::onDead()
{
}
