#include "RocketSoldierShootState.h"
#include "SingleGunNormalBulletSprite.h"
#include "RocketSoldierNormalRocketSprite.h"
#include "RocketSoldierRunningState.h"
#include "RocketFlyDeadState.h"

RocketSoldierShootState::RocketSoldierShootState(EnemyData *pData)
{

	LogWriter::getInstance()->write("RocketSoldier Fire State");
	LogWriter::getInstance()->write(6, (int)pData->dir.dir);
	this->pData = pData;
	this->pData->iCurrentArr = RocketSoldierData::SHOOT;
	fameExits = 0;
	gravitaion = 2;


}

void RocketSoldierShootState::onUpdate()
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
	if (fameExits > 90)
	{
		transition(new RocketSoldierRunningState(this->pData));

	}


}

void RocketSoldierShootState::onCollision(RectF rect)
{
}

void RocketSoldierShootState::onCollision(CollisionRectF rect)
{
	pData->y -= pData->vy;
}


void RocketSoldierShootState::createBullet()
{
	float angle;
	if (pData->dir.isRight()) {
		angle = 0;
	}
	else
	{
		angle = M_PI;
	}
	int speed = 2;
	this->pData->bulletsVector.push_back(new RocketSoldierNormalRocketSprite(this->pData->x, this->pData->y - this->pData->body.height));
}

void RocketSoldierShootState::onDead()
{
	transition(new RocketFlyDeadState(this->pData));
}

RocketSoldierShootState::~RocketSoldierShootState()
{
}