#include "define.h"
#include "KeyBoard.h"
#include "CaptainRunningState.h"
#include "CaptainStandingState.h"

CaptainRunningState::CaptainRunningState(CaptainData* data)
{
	this->pData = data;

	/*if (pData->isFrire) {
		pData->setiCurrentArray(CaptainData::RUNSHOOT);
	}
	else
	{
		pData->setiCurrentArray(CaptainData::RUN);

	}*/
	pData->setiCurrentArray(CaptainData::RUN);
	pData->vy = 0;
	tempDir = pData->dir;
	LogWriter::getInstance()->write("Running");
}

void CaptainRunningState::onMovePressed(Direction d)
{
	pData->dir = d;
	pData->movedir = d;
	if (d == Direction::createRight()) {
		this->right = 1;
	}
	else {
		if (d == Direction::createLeft()) {
			this->left = 1;
		}
	}

	//LogWriter::getInstance()->write(" press", this->right, this->left);
}

void CaptainRunningState::onMoveReleased(Direction d)
{

	//tempDir = tempDir ^ d;
	if (d == Direction::createRight()) {
		this->right = 0;
	}
	 
		if (d == Direction::createLeft()) {
			this->left = 0;
		}
	

	if (!(tempDir ^ d).isNone())
	{

		//pData -> dir = d;
		// hcmt cam move 
		//pData->movedir = tempDir;
	}
	//else {
	//	if (left > right) {
	//		this->pData->dir = Direction::createLeft();
	//	}
	//	else
	//		if (right > left) {
	//			this->pData->dir = Direction::createRight();
	//		}
	//		else
	//			transition(new CaptainStandingState(pData)); // thả đúng phím
	//}

	LogWriter::getInstance()->write(" release", this->right, this->left);

}

void CaptainRunningState::onUpdate()
{
	// cai nay thay lun OnFall 
	if (pData->vy > 0)
	{
		//transition(new MegamanJumpState(pData, true, pData->vy));
		return;
	}

	/*if (pData->isFrire && pData->iCurrentArr == CaptainData::RUN) {
		pData->setiCurrentArray(CaptainData::RUNSHOOT);
	}

	if ((!pData->isFrire) && pData->iCurrentArr == CaptainData::RUNSHOOT) {
		pData->setiCurrentArray(CaptainData::RUN);
	}*/

	hittableCalculation();
	undyingCalculation();
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	pData->vx = pData->transform(MEGAMANRUNSPEED);
	pData->x += pData->vx;

	pData->vy += acceleration;
	pData->y += pData->vy;
	pData->movedir = pData->dir;


	//if (pData->isCharging) {
	//	pData->ChargingCount++;
	//	//pData->bulletSize = getSizeofBullet(pData->ChargingCount);
	//	pData->ppTextureArrays[pData->bulletSize]->update();
	//}

	//if (pData->isFrire) {
	//	pData->FireCountFrames++;
	//	if (pData->FireCountFrames > FIRE_COUNTING_FRAME) {
	//		pData->FireCountFrames = 0;
	//		pData->isFrire = false;
	//	}
	//}
}


void CaptainRunningState::onJumpPressed()
{
	//transition(new MegamanJumpState(this->pData, true, -4.5f));
}

void CaptainRunningState::onSlidePressed()
{
	//transition(new MegamanSlideState(this->pData));
}

void CaptainRunningState::onCollision(RectF rect)
{
	if (pData->vx > 0)
	{
		pData->x -= pData->getBody().x + pData->getBody().width - rect.x;
		pData->vx = 0;
		pData->vy -= acceleration;
		pData->y -= pData->vy;


	}
	else
	{
		pData->x += rect.x + rect.width - pData->getBody().x;
		pData->vx = 0;
		pData->vy -= acceleration;
		pData->y -= pData->vy;

	}
}

void CaptainRunningState::onCollision(CollisionRectF crect)
{
	//	LogWriter::getInstance()->write("Ruuning state collision");
		//pData->cThroughRect.push_back(crect);
	if (pData->vx > 0)
	{
		pData->x -= pData->getBody().x + pData->getBody().width - crect.rect.x;
		pData->vx = 0;
		pData->y -= pData->vy;
		pData->vy -= acceleration;



	}
	else
	{
		pData->x += crect.rect.x + crect.rect.width - pData->getBody().x;
		pData->vx = 0;
		pData->y -= pData->vy;
		pData->vy -= acceleration;
	}


}

void CaptainRunningState::onDynamicObjectCollision(CollisionRectF * crect)
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

void CaptainRunningState::onFall()
{
}

void CaptainRunningState::onFirePressed()
{
	pData->isCharging = true;

}

void CaptainRunningState::onFireRelease()
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

void CaptainRunningState::onVeticalDirectionPressed(Direction d)
{
	pData->verticalDir = d;
}

void CaptainRunningState::onVeticalDirectionReleased()
{
	pData->verticalDir = Direction::createNone();
}

void CaptainRunningState::onDead()
{
}
