#include "ZuliaNormalFlyState.h"
#include "ZuliaData.h"
#include "ZuliaAlphaFlyState.h"
#include "ZuliaShoot2State.h"
#include "ZuliaStingState.h"
#include "ZuliaShootState.h"

float ZuliaNormalFlyState::getYfromX(float X)
{
	/*
	Ya = a Xa + b
	Yb = a Xb + b

	=> (Ya - Yb) = a(Xa - Xb)
	=> a= ( Ya - Yb) /( Xa - Xb) 
	=> b= ya - a Xa

	*/

	this->A = (ya - yb) / (xa - xb);
	this->B = yb - A * xb;
	return A * X + B;
}

void ZuliaNormalFlyState::doMech()
{
	if (nextMech == ZuliaData::ZuliaMechIndex::ALPHAFLY) {
		transition(new ZuliaAlphaFlyState(this->pData, Range));
	}
	if (nextMech == ZuliaData::ZuliaMechIndex::STING_PLAYER) {
		transition(new ZuliaStingState(this->pData, Range));
	}
	if (nextMech == ZuliaData::ZuliaMechIndex::BEESHOOT) {
		transition(new ZuliaShootState(this->pData, Range));
	}
	if (nextMech == ZuliaData::ZuliaMechIndex::TARGETBEESHOOT) {
		transition(new ZuliaShoot2State(this->pData, Range));
	}
}

ZuliaNormalFlyState::ZuliaNormalFlyState(EnemyData *pData, float desX, float desY,RectF Range,int nextMech )
{

	LogWriter::getInstance()->write("Zulia bay ts vi tri vs mech",0, nextMech);
	LogWriter::getInstance()->write(desX, desY);
	this->Range = Range;
	this->nextMech =nextMech;

	this->pData = pData;
	this->pData->iCurrentArr = ZuliaData::ZuliaAniIndex::NORMALFLY;
	this->speed = 0.8;
	this->xa = pData->x;
	this->ya = pData->y;
	this->xb = desX;
	this->yb = desY;
	if (xb > xa) {
		this->pData->dir = Direction::createRight();
	}
	else {
		this->pData->dir = Direction::createLeft();
	}
}


void ZuliaNormalFlyState::onUpdate()
{
	UIComponents::getInstance()->setShurikanHp(pData->HP);

	if (1) {
		this->pData->isTargetting = true;
	}

	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	this->pData->ppTextureArrays[ZuliaData::WINGS]->update();

	this->pData->vx = this->pData->transform(speed);

	if (this->pData->x + this->pData->vx > Range.x &&
		this->pData->x + this->pData->vx < Range.x + Range.width &&
		this->pData->y + this->pData->vy > Range.y &&
		this->pData->y + this->pData->vy < Range.y + Range.height)
	{
		this->pData->x += this->pData->vx;
		this->pData->y = getYfromX(this->pData->x);

		if (sqrt( (this->pData->x - xb)*(this->pData->x - xb) + (this->pData->y - yb)*(this->pData->y - yb)) < 5) {
			doMech();
		}
	}
	else 
	{
		doMech();
	}

}

void ZuliaNormalFlyState::onCollision(RectF rect)
{
}

void ZuliaNormalFlyState::onCollision(CollisionRectF rect)
{
}

void ZuliaNormalFlyState::onDead()
{
}


ZuliaNormalFlyState::~ZuliaNormalFlyState()
{
}
