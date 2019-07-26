#include "ElevatorSprite.h"
#include "ElevatorData.h"
#include "ElevatorWaittingState.h"

ElevatorSprite::ElevatorSprite(float x, float y)
{
	pData = new ObjectData();
	this->pData->objectName = "elevator";
	this->pData->isDesTroyed = false;
	this->pData->isHittable = false;
	this->pData->isPlayerCollisionable = true;
	this->pData->isEnemyCollisionable = true;

	this->pData->ppTextureArrays = new TextureArray*[ElevatorData::COUNT];

	this->pData->ppTextureArrays[ElevatorData::WAITTING] = new TextureArray(RESOURCE_SPRITE, "Elevator", "Waitting", 3, 5);
	this->pData->ppTextureArrays[ElevatorData::WAITTING]->setAnchorPoint(0,1.0f);

	this->pData->ppTextureArrays[ElevatorData::RUNNING] = new TextureArray(RESOURCE_SPRITE, "Elevator", "Running", 1, 50);
	this->pData->ppTextureArrays[ElevatorData::RUNNING]->setAnchorPoint(0, 1.0f);

	this->pData->body = RectF(0, -35, 94.0f, 30.0f);

	this->pData->dir = Direction::createRight();
	this->pData->verticalDir = Direction::createUp();
	
	this->pData->x = x;
	this->pData->y = y;

	this->pData->pState = new ElevatorWaittingState(this->pData);
}

void ElevatorSprite::onUpdate()
{
	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
}


ElevatorSprite::~ElevatorSprite()
{
}
