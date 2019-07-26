#include "RocketFlyState.h"
#include "DoubleRocketNormalBulletSprite.h"
#include "RocketFlyData.h"
#include"RocketFlyDeadState.h"
#include <math.h>
RocketFlyState::RocketFlyState(EnemyData * pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = RocketFlyData::FIRE;
	gun = 1;
	waittingframe = 0;
}

void RocketFlyState::onUpdate()
{
	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();

	if (pData->Megaman_X > this->pData->x) {
		this->pData->dir = Direction::createRight();
	}
	else
	{
		this->pData->dir = Direction::createLeft();
	}

	if (this->pData->y -this->pData->respawnY <16*4 )
	{
		this->pData->y += 0.5f; 

	}


	if (waittingframe == 1) //cho nó update 1 frame để kịp cập nhật pos X Y 
	{
		

		this->pData->iCurrentArr = RocketFlyData::FIRE; 
		
		createBullet();
		gun++;
		waittingframe++;
	}

	
		if (waittingframe++ > 120) {
			waittingframe = 0;
		}
	
	



}

void RocketFlyState::onCollision(RectF rect)
{
}

void RocketFlyState::onCollision(CollisionRectF rect)
{
}

void RocketFlyState::createBullet()
{
	float x = this->pData->Megaman_X - this->pData->x;
	float y = this->pData->Megaman_Y - this->pData->y;
	float angle = atan(y / x);
	if (x < 0) {
		angle += M_PI;
	}
	this->pData->bulletsVector.push_back(new DoubleRocketNormalBulletSprite(this->pData->x, this->pData->y, angle));
}

void RocketFlyState::onDead()
{
	transition(new RocketFlyDeadState(this->pData));
}

RocketFlyState::~RocketFlyState()
{
}
