#include "ZuliaShootState.h"
#include "ZuliaData.h"
#include "ZuliaNormalBulletSprite.h"
#include "ZuliaSpecialBulletSprite.h"
#include "ZuliaAimSprite.h"
#include "ZuliaNormalFlyState.h"
#include "EnemyCreator.h"
#include <random>

ZuliaShootState::ZuliaShootState(EnemyData * enemydata, RectF Range)
{
	this->pData = enemydata;
	this->pData->iCurrentArr = ZuliaData::ZuliaAniIndex::SHOOT;
	this->range = Range;
	this->counterFrame = 0;
}

void ZuliaShootState::onUpdate()
{
	UIComponents::getInstance()->setShurikanHp(pData->HP);

	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	this->pData->ppTextureArrays[ZuliaData::WINGS]->update();

	if (this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture())
	{
		if(counterFrame == 0)
			createBee();
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->resetIndex();
		if (counterFrame++ > 5) {
			transition(new ZuliaNormalFlyState(this->pData, 7781, 1786, range, (int)ZuliaData::ZuliaMechIndex::ALPHAFLY));
		}
	}
	else
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
}

void ZuliaShootState::createBee()
{
	float alpha;
	if (this->pData->dir.isLeft()) {
		alpha = M_PI;
	}
	else
	{
		alpha = 0;
	}
	this->pData->bulletsVector.push_back(new ZuliaNormalBulletSprite(this->pData->x,this->pData->y,alpha,range));
	this->pData->bulletsVector.push_back(new ZuliaNormalBulletSprite(this->pData->x, this->pData->y, alpha - M_PI_2 / 9, range));
	this->pData->bulletsVector.push_back(new ZuliaNormalBulletSprite(this->pData->x, this->pData->y, alpha - 2*M_PI_2 / 9, range));
	this->pData->bulletsVector.push_back(new ZuliaNormalBulletSprite(this->pData->x, this->pData->y, alpha + M_PI_2 / 9, range));
	this->pData->bulletsVector.push_back(new ZuliaNormalBulletSprite(this->pData->x, this->pData->y, alpha + 2 * M_PI_2 / 9, range));

	//this->pData->bulletsVector.push_back(new ZuliaSpecialBulletSprite(this->pData->x, this->pData->y));
	//this->pData->bulletsVector.push_back(new ZuliaAimSprite(this->pData->x, this->pData->y));

}

void ZuliaShootState::onCollision(RectF rect)
{
}

void ZuliaShootState::onCollision(CollisionRectF rect)
{
}

void ZuliaShootState::onDead()
{
}

ZuliaShootState::~ZuliaShootState()
{
}
