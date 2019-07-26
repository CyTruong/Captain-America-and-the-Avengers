#pragma once
#include"DoorSprite.h"
#include"DoorData.h"
#include "DoorState.h" 

DoorSprite::DoorSprite(float x, float y )
{


	pData = new ObjectData();
	this->pData->objectName = "door";
	this->pData->isDesTroyed = false;
	this->pData->isHittable = false;
	this->pData->isDesTroyed = false;
	this->pData->isHittable = false;
	this->pData->isPlayerCollisionable = true;
	this->pData->isEnemyCollisionable = true;
	//this->pData->isPlayerCollisionable = true;
	//this->pData->isEnemyCollisionable = true;

	this->pData->ppTextureArrays = new TextureArray*[DoorData::COUNT];

	this->pData->ppTextureArrays[DoorData::PRESENT] = new TextureArray(RESOURCE_SPRITE, "Door", "Present", 1, 20);
	this->pData->ppTextureArrays[DoorData::PRESENT]->setAnchorPoint(0.0, 0);

	this->pData->ppTextureArrays[DoorData::OPENED] = new TextureArray(RESOURCE_SPRITE, "Door", "Opened", 1, 20);
	this->pData->ppTextureArrays[DoorData::OPENED]->setAnchorPoint(0.0, 0);

	this->pData->ppTextureArrays[DoorData::OPEN] = new TextureArray(RESOURCE_SPRITE, "Door", "Open", 9, 20);
	this->pData->ppTextureArrays[DoorData::OPEN]->setAnchorPoint(0.0,0);

	this->pData->ppTextureArrays[DoorData::CLOSE] = new TextureArray(RESOURCE_SPRITE, "Door", "Close", 9, 20);
	this->pData->ppTextureArrays[DoorData::CLOSE]->setAnchorPoint(0.0, 0);

	this->pData->body = RectF(0,  0, pData->ppTextureArrays[DoorData::PRESENT]->getWidth(),  pData->ppTextureArrays[DoorData::PRESENT]->getHeight());
	
	//this->pData->body = RectF(0, -35, 30.0f, 90.0f);
	//this->pData->body = RectF(0, 0, 0, 0); 

	this->pData->dir = Direction::createRight(); 

	
	this->pData->x = x; 
	this->pData->y = y; 


	this->pData->pState = new DoorState (this->pData);
}
void DoorSprite::onUpdate()
{

}

DoorSprite::~DoorSprite()
{
}