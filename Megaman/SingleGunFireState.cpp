#include "SingleGunFireState.h"
#include "SingleGunNormalBulletSprite.h"
#include "SingleGunStandState.h"
#include "SingleGunDeadState.h"

SingleGunFireState::SingleGunFireState(EnemyData *pData)
{

	LogWriter::getInstance()->write("SingleGun Fire State");
	LogWriter::getInstance()->write(6, (int)pData->dir.dir);
	this->pData = pData;
	this->pData->iCurrentArr = SingleGunData::FIRE;
	
}

void SingleGunFireState::onUpdate()
{
	if (pData->Megaman_X > this->pData->x) {
		this->pData->dir = Direction::createRight();
	}
	else
	{
		this->pData->dir = Direction::createLeft();
	}

	if (this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture())
	{
		createBullet();
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->resetIndex();
		transition(new SingleGunStandState(this->pData));
	}
	else
	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();

}

void SingleGunFireState::onCollision(RectF rect)
{
}

void SingleGunFireState::onCollision(CollisionRectF rect)
{
}


void SingleGunFireState::createBullet()
{
	float angle;
	if (pData->dir.isRight()) {
		angle = -M_PI / 3;
	}
	else
	{
		angle = - 2* M_PI /3 ;
	}
	this->pData->bulletsVector.push_back(new SingleGunNormalBulletSprite(this->pData->x, this->pData->y - this->pData->body.height , angle));
}

void SingleGunFireState::onDead()
{
	transition(new SingleGunDeadState(this->pData));
}

SingleGunFireState::~SingleGunFireState()
{
}
