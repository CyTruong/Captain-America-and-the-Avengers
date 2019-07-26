#include "ZuliaAlphaFlyState.h"
#include "ZuliaData.h"
#include "ZuliaNormalFlyState.h"


float ZuliaAlphaFlyState::getYfromX(float X, int counter)
{

	float value = 35 * sin((X + 10.36) / 20) + 1800;
	if (counter % 2) return -value + 3600;
	return value;
}

ZuliaAlphaFlyState::ZuliaAlphaFlyState(EnemyData * pData,RectF Range)
{
	this->Range = Range;
	mechCounter == 0;
	this->pData = pData;
	this->pData->iCurrentArr = ZuliaData::ZuliaAniIndex::NORMALFLY;
	this->speed = 1;
	frameCounter = 50;
}

void ZuliaAlphaFlyState::onUpdate()
{
	UIComponents::getInstance()->setShurikanHp(pData->HP);

	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	this->pData->ppTextureArrays[ZuliaData::WINGS]->update();

	this->pData->vx = this->pData->transform(speed);

	this->pData->x += this->pData->vx;

	this->pData->y = getYfromX(this->pData->x,mechCounter);
	
	if ((frameCounter++>=50)&&(this->pData->y <= 1802) && (this->pData->y >= 1797) && ((this->pData->x >= 7783.5) || (this->pData->x <= 7778.5))) {
		frameCounter = 0;
		mechCounter++;
		this->pData->dir.reverse();
	}

	if (mechCounter == 3)
		transition(new ZuliaNormalFlyState(this->pData, 7781, 1786,Range,(int)ZuliaData::ZuliaMechIndex::TARGETBEESHOOT));
}

void ZuliaAlphaFlyState::onCollision(RectF rect)
{
}

void ZuliaAlphaFlyState::onCollision(CollisionRectF rect)
{
}

void ZuliaAlphaFlyState::onDead()
{
}

ZuliaAlphaFlyState::~ZuliaAlphaFlyState()
{
}
