#include "WizardData.h"
#include "WizardSprite.h"
#include "WizardStandingState.h"
#include "WizardRunnigState.h"
WizardStandingState::WizardStandingState(EnemyData * pData)
{
	//LogWriter::getInstance()->write("SingleGun Standing State");
	//LogWriter::getInstance()->write(6,(int)pData->dir.dir);
	this->pData = pData;
	this->pData->iCurrentArr = WizardData::STAND;
	this->waittingFrame = 40;
	this->waittingCount = 0;
	this->acceleration = 0.6;
}

void WizardStandingState::onUpdate()
{
	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();

	pData->vy += acceleration;
	pData->y += pData->vy;

	if (pData->Megaman_X > this->pData->x) {
		this->pData->dir = Direction::createRight();
	}
	else
	{
		this->pData->dir = Direction::createLeft();
	}
	LogWriter::getInstance()->write("Wiz ",this->pData->x,this->pData->y);
	if (waittingCount++ > waittingFrame) {
	/*	if (abs(this->pData->Megaman_X - this->pData->x) <= SINGLEGUN_FIRE_RANGE)
		{
			transition(new SingleGunFireState(this->pData));
		}
		else
			transition(new SingleGunJumpingState(this->pData));*/
		transition(new WizardRunningState(this->pData));
	}

}

void WizardStandingState::onCollision(RectF rect)
{

}

void WizardStandingState::onCollision(CollisionRectF rect)
{
	pData->y -= pData->vy;
	pData->vy =0;
}

void WizardStandingState::onDead()

{
	//transition(new SingleGunDeadState(this->pData));
}




WizardStandingState::~WizardStandingState()
{
}
