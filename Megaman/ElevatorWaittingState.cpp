#include "ElevatorWaittingState.h"
#include "Sound.h"


ElevatorWaittingState::ElevatorWaittingState(ObjectData * pdata)
{
	this->pData = pdata;
	this->pData->iCurrentArr = ElevatorData::WAITTING;
	this->pData->vx = 0;
	this->pData->vy = -1;
}

void ElevatorWaittingState::onUpdate()
{  

	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	if (isMegamanStanding) {
		
		this->pData->y += this->pData->vy;
		isMegamanStanding = false;

	}
	else
	{
		Sound::getInstance()->stop("Elevator");
	}
	// hcmt 
	pData->collisionRect = CollisionRectF(pData->getBody(), "elevator", pData->vx, pData->vy);
}

void ElevatorWaittingState::onCollision(RectF rect)
{

}

void ElevatorWaittingState::onCollision(CollisionRectF rect)
{
	if (!isMegamanStanding) {
		Sound::getInstance()->play("Elevator", true, 1);
	}
	if (rect.type == "Megaman") {
		isMegamanStanding = true;
	}
}
