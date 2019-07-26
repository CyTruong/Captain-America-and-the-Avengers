#include "ZuliaShoot2State.h"
#include "ZuliaData.h"
#include "ZuliaNormalFlyState.h"
#include "ZuliaSpecialBulletSprite.h"
#include "ZuliaAimSprite.h"

float ZuliaShoot2State::getYfromX(float X, int counter)
{
	float value = 35 * sin((X + 10.36) / 20) + 1800;
	if (counter % 2) return -value + 3600;
	return value;
}

ZuliaShoot2State::ZuliaShoot2State(EnemyData * pData, RectF Range)
{
	this->Range = Range;
	mechCounter == 0;
	this->pData = pData;
	this->pData->iCurrentArr = ZuliaData::ZuliaAniIndex::NORMALFLY;
	this->speed = 1;
	this->pData->bulletsVector.push_back(new ZuliaAimSprite(this->pData->x, this->pData->y));

}

void ZuliaShoot2State::onUpdate()
{
	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	this->pData->ppTextureArrays[ZuliaData::WINGS]->update();

	this->pData->vx = this->pData->transform(speed);

	this->pData->x += this->pData->vx;

	this->pData->y = getYfromX(this->pData->x, mechCounter);

	if ((frameCounter++ >= 50) && (this->pData->y <= 1802) && (this->pData->y >= 1797)) {
		frameCounter = 0;
		mechCounter++;
		this->pData->dir.reverse();
	}
	if (frameCounter % 120 == 0 && UIComponents::getInstance()->isTargeting()) {
		createBee();
	}
	if (mechCounter == 10)
		if (this->pData->x < Range.x + Range.width) {
			UIComponents::getInstance()->setisTargeting(false);
			transition(new ZuliaNormalFlyState(this->pData, Range.x +20, Range.y+20, Range, (int)ZuliaData::ZuliaMechIndex::STING_PLAYER));
		}
		else
		{
			UIComponents::getInstance()->setisTargeting(false);
			transition(new ZuliaNormalFlyState(this->pData, Range.x + Range.width -20, Range.y + 20, Range, (int)ZuliaData::ZuliaMechIndex::STING_PLAYER));
		}
}

void ZuliaShoot2State::createBee()
{
	float alpha;
	if (this->pData->dir.isLeft()) {
		alpha = M_PI;
	}
	else
	{
		alpha = 0;
	}

	this->pData->bulletsVector.push_back(new ZuliaSpecialBulletSprite(this->pData->x, this->pData->y));
}

void ZuliaShoot2State::onCollision(RectF rect)
{
}

void ZuliaShoot2State::onCollision(CollisionRectF rect)
{
}

void ZuliaShoot2State::onDead()
{
}

ZuliaShoot2State::~ZuliaShoot2State()
{
}

