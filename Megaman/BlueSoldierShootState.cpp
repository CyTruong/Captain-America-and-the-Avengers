#include "BlueSoldierShootState.h"
#include "SingleGunNormalBulletSprite.h"
#include "BlueSoldierSitState.h"
#include "BlueSoldierDeadState.h"
#include "BlueSoldierBulletSprite.h"
#include "BlueSoldierRuningState.h"

BlueSoldierShootState::BlueSoldierShootState(EnemyData *pData)
{

	LogWriter::getInstance()->write("BlueSoldier Fire State");
	LogWriter::getInstance()->write(6, (int)pData->dir.dir);
	this->pData = pData;
	this->pData->iCurrentArr = BlueSoldierData::SHOOT;
	fameExits = 0; 
	gravitaion = 2; 


}

void BlueSoldierShootState::onUpdate()
{
	if (pData->Megaman_X > this->pData->x) {
		this->pData->dir = Direction::createRight();
		// x,y 

	
	}
	else
	{

		
		this->pData->dir = Direction::createLeft();

	}

	this->pData->vy = gravitaion;
	this->pData->y += gravitaion;

	if (this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture())
	{   
	
	    createBullet();
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->resetIndex();
		
	}
	else
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();



	// if transition 
	fameExits++; 
	if (fameExits>90)
	{
		transition(new BlueSoldierRuningState(this->pData)); 

	}


}

void BlueSoldierShootState::onCollision(RectF rect)
{
}

void BlueSoldierShootState::onCollision(CollisionRectF rect)
{
	pData->y -= pData->vy;
}


void BlueSoldierShootState::createBullet()
{
	float angle;
	if (pData->dir.isRight()) {
		angle = -M_PI / 3;
	}
	else
	{
		angle = -2 * M_PI / 3;
	} 
	int speed = 2; 
	this->pData->bulletsVector.push_back(new BlueSoldierBulletSprite(this->pData->x, this->pData->y - this->pData->body.height,speed, angle));
}

void BlueSoldierShootState::onDead()
{
	transition(new BlueSoldierDeadState(this->pData));
}

BlueSoldierShootState::~BlueSoldierShootState()
{
}
