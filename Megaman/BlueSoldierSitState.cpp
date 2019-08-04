#include "BlueSoldierSitState.h"
//#include "BlueSoldierJumpingState.h"
#include "SingleGunNormalBulletSprite.h"
#include "BlueSoldierShootState.h"
#include "BlueSoldierDeadState.h"
BlueSoldierSitState::BlueSoldierSitState(EnemyData * pData)
{
	//LogWriter::getInstance()->write("BlueSoldier Siting State");
	//LogWriter::getInstance()->write(6,(int)pData->dir.dir);
	this->pData = pData;
	this->pData->iCurrentArr = BlueSoldierData::SIT;
	this->waittingFrame = 30;
	this->waittingCount = 0;
}

void BlueSoldierSitState::onUpdate()
{
	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();

	pData->vy += 0.2;
	pData->y += pData->vy;

	if (pData->Megaman_X > this->pData->x) {
		this->pData->dir = Direction::createRight();
	}
	else
	{
		this->pData->dir = Direction::createLeft();
	}

	if (waittingCount++ > waittingFrame) {
		if (abs(this->pData->Megaman_X - this->pData->x) <= BlueSoldier_FIRE_RANGE)
		{
			transition(new BlueSoldierShootState(this->pData));
		}
		//else
		//	transition(new BlueSoldierJumpingState(this->pData));
	}

}

void BlueSoldierSitState::onCollision(RectF rect)
{



}

void BlueSoldierSitState::onCollision(CollisionRectF rect)
{
	pData->y -= pData->vy;
	pData->vy -= 0.2;
}

void BlueSoldierSitState::onDead()

{
	transition(new BlueSoldierDeadState(this->pData));
}




BlueSoldierSitState::~BlueSoldierSitState()
{
}
