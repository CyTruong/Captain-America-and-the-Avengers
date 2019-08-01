#include "WizardData.h"
#include "WizardRunnigState.h"
#include "WizardGroundShootingState.h"

WizardRunningState::WizardRunningState(EnemyData * pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = WizardData::RUNNING;
	speed = 2;
	this->pData->vy = 1;
	count = 0;
	changeStateCount = 40;
	if (this->pData->Megaman_X < this->pData->x) {
		this->pData->dir = Direction::createLeft();
	}
	else
	{
		this->pData->dir = Direction::createRight();
	}
}

void WizardRunningState::onUpdate()
{
	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	this->pData->vx = this->pData->transform(speed);
	this->pData->x += this->pData->vx;

	pData->vy += 1; 
	pData->y += pData->vy;


	if (count > changeStateCount ) {
		transition(new WizardGroundShootingState(this->pData));
	}
	count++;

}

void WizardRunningState::onCollision(RectF rect)
{

}

void WizardRunningState::onCollision(CollisionRectF rect)
{
	pData->y -= pData->vy;
	pData->vy = 0;
	
}

void WizardRunningState::onDead()
{
//	transition(new ShurikanDeadState(this->pData));

}

WizardRunningState::~WizardRunningState()
{
}
