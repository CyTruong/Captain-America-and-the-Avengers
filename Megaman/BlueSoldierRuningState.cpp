#include "BlueSoldierRuningState.h"
#include "SingleGunNormalBulletSprite.h"
#include "BlueSoldierSitState.h"
#include "BlueSoldierDeadState.h"
#include "BlueSoldierBulletSprite.h"
#include <math.h>
#include "BlueSoldierShootState.h"



BlueSoldierRuningState::BlueSoldierRuningState(EnemyData *pData)
{

	LogWriter::getInstance()->write("BlueSoldier Fire State");
	LogWriter::getInstance()->write(6, (int)pData->dir.dir);
	this->pData = pData;
	this->pData->iCurrentArr = BlueSoldierData::RUN;
	fameExits = 0; 
	gravitaion = 0.2; 

}

void BlueSoldierRuningState::onUpdate()
{
	if (pData->Megaman_X > this->pData->x) {
		this->pData->dir = Direction::createRight();
		// x,y 
		
		this->pData->vx =  this->pData->transform(1.5);
		this->pData->x += this->pData->vx;
	}
	else
	{

		this->pData->vx = this->pData->transform(1.5);
		this->pData->x += this->pData->vx;
		this->pData->dir = Direction::createLeft();

	}
	 
	this->pData->vy = gravitaion; 
	this->pData->y += gravitaion; 
	


	//if (this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture())
	//{
	//	createBullet();
	//	this->pData->ppTextureArrays[this->pData->iCurrentArr]->resetIndex();
	//	transition(new BlueSoldierSitState(this->pData));
	//}
	//else
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();

		fameExits++; 

		//if (fameExits >30)
		if (fameExits > 5)
		{
			transition(new BlueSoldierShootState(this->pData));
		}

		


}

void BlueSoldierRuningState::onCollision(RectF rect)
{


}

void BlueSoldierRuningState::onCollision(CollisionRectF rect)
{


	pData->y -= pData->vy;
	

}


void BlueSoldierRuningState::createBullet()
{

}

void BlueSoldierRuningState::onDead()
{
	transition(new BlueSoldierDeadState(this->pData));
}

BlueSoldierRuningState::~BlueSoldierRuningState()
{



}
