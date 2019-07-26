#include "SingleGunStandState.h"
#include "SingleGunJumpingState.h"
#include "SingleGunNormalBulletSprite.h"
#include "SingleGunFireState.h"
#include "SingleGunDeadState.h"
SingleGunStandState::SingleGunStandState(EnemyData * pData)
{
	//LogWriter::getInstance()->write("SingleGun Standing State");
	//LogWriter::getInstance()->write(6,(int)pData->dir.dir);
	this->pData = pData;
	this->pData->iCurrentArr = SingleGunData::STAND;
	this->waittingFrame =30;
	this->waittingCount = 0;
}

void SingleGunStandState::onUpdate()
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
		if (abs(this->pData->Megaman_X - this->pData->x) <= SINGLEGUN_FIRE_RANGE)
		{
			transition(new SingleGunFireState(this->pData));
		}else
			transition(new SingleGunJumpingState(this->pData));
	}

}

void SingleGunStandState::onCollision(RectF rect)
{



}

void SingleGunStandState::onCollision(CollisionRectF rect)
{
	pData->y -= pData->vy;
	pData->vy -= 0.2;
}

void SingleGunStandState::onDead()

{
	transition(new SingleGunDeadState(this->pData));
}
	



SingleGunStandState::~SingleGunStandState()
{
}
