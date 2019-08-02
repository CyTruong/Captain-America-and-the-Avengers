#include "RocketSoldierRunningState.h"
#include "SingleGunNormalBulletSprite.h"
//#include "BlueSoldierSitState.h"
//+//#include "BlueSoldierBulletSprite.h"
#include <math.h>
#include "RocketSoldierShootState.h"
#include "RocketSoldierRunningState.h"
#include "RocketSoldierData.h"


RocketSoldierRunningState::RocketSoldierRunningState(EnemyData *pData)
{

	LogWriter::getInstance()->write("BlueSoldier Fire State");
	LogWriter::getInstance()->write(6, (int)pData->dir.dir);
	this->pData = pData;
	this->pData->iCurrentArr = RocketSoldierData::RUN;
	fameExits = 0;
	speed = 1;
	gravitaion = 0.2;
	if (this->pData->Megaman_X < this->pData->x) {
		this->pData->dir = Direction::createLeft();
	}
	else
	{
		this->pData->dir = Direction::createRight();
	}

}

void RocketSoldierRunningState::onUpdate()
{
	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	this->pData->vx = this->pData->transform(speed);
	this->pData->x += this->pData->vx;

	if (abs(this->pData->x - this->pData->Megaman_X)<80) {
		transition(new RocketSoldierShootState(this->pData));
	}
	
}

void RocketSoldierRunningState::onCollision(RectF rect)
{


}

void RocketSoldierRunningState::onCollision(CollisionRectF rect)
{


	pData->y -= pData->vy;


}


void RocketSoldierRunningState::createBullet()
{

}

void RocketSoldierRunningState::onDead()
{
	transition(new RocketSoldierRunningState(this->pData));
}

RocketSoldierRunningState::~RocketSoldierRunningState()
{



}