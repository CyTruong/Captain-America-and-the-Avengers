#include "MegamanStandShootState.h"
#include "MegamanRunningState.h"


MegamanStandShootState::MegamanStandShootState(MegamanData* data)
{
	this->pData = data;
	this->pData->vx = 0;
	this->pData->setiCurrentArray(MegamanData::STANDSHOOT);
}

void MegamanStandShootState::onMovePressed(Direction d)
{
	pData->dir = d;
	transition(new MegamanRunningState(pData));
}

void MegamanStandShootState::onMoveReleased(Direction d)
{
}

void MegamanStandShootState::onUpdate()
{
	hittableCalculation();
	undyingCalculation();
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	//bắn 1 viên đạn
}

void MegamanStandShootState::onJumpPressed()
{
}

void MegamanStandShootState::onCollision(RectF rect)
{
}

void MegamanStandShootState::onCollision(CollisionRectF rect)
{
	
}

void MegamanStandShootState::onDynamicObjectCollision(CollisionRectF * rect)
{
}

void MegamanStandShootState::onFall()
{

}

void MegamanStandShootState::onFirePressed()
{
}

void MegamanStandShootState::onVeticalDirectionPressed(Direction d)
{
}

void MegamanStandShootState::onVeticalDirectionReleased()
{
}

void MegamanStandShootState::onDead()
{
}



