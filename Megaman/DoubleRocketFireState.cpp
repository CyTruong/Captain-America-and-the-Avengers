#include "DoubleRocketFireState.h"
#include "DoubleRocketNormalBulletSprite.h"
#include "DoubleRocketData.h"
#include <math.h>
#include "DoubleRocketDeadState.h"
DoubleRocketFireState::DoubleRocketFireState(EnemyData * pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = DoubleRocketData::DoubleGunArrindex::FIRE_TOP;
	gun = 1;
	waittingframe = 0;
}

void DoubleRocketFireState::onUpdate()
{

	if (pData->Megaman_X > this->pData->x) {
		this->pData->dir = Direction::createRight();
	}
	else
	{
		this->pData->dir = Direction::createLeft();
	}

	if (waittingframe == 1) //cho nó update 1 frame để kịp cập nhật pos X Y 
	{
		if (gun % 2)
		{
			this->pData->iCurrentArr = DoubleRocketData::DoubleGunArrindex::FIRE_TOP;
		}
		else
		{
			this->pData->iCurrentArr = DoubleRocketData::DoubleGunArrindex::FIRE_BOT;
		}
		createBullet();
		gun++;
		waittingframe++;
	}

	if (this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
		if (waittingframe++ > 120) {
			waittingframe = 0;
		}
	}
	else
	{
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	}
}

void DoubleRocketFireState::onCollision(RectF rect)
{
}

void DoubleRocketFireState::onCollision(CollisionRectF rect)
{
}

void DoubleRocketFireState::createBullet()
{
	float x = this->pData->Megaman_X - this->pData->x;
	float y = this->pData->Megaman_Y - this->pData->y;
	float angle = atan(y/x);
	if (x < 0 ) {
		angle += M_PI;
	}
	this->pData->bulletsVector.push_back(new DoubleRocketNormalBulletSprite(this->pData->x, this->pData->y, angle));
}

void DoubleRocketFireState::onDead()
{
	transition(new DoubleRocketDeadState(this->pData)); 

}

DoubleRocketFireState::~DoubleRocketFireState()
{
}
