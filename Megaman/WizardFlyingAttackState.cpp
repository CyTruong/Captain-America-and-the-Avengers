#include "WizardFlyingAttackState.h"
#include "WizardData.h"



WizardFlyingAttackState::WizardFlyingAttackState(EnemyData * pData, RectF Range)
{
	this->Range = Range;
	this->pData = pData;
	this->pData->iCurrentArr = WizardData::FLY;
	this->speed = 1;
	step = 0;
}

void WizardFlyingAttackState::onUpdate()
{
	UIComponents::getInstance()->setShurikanHp(pData->HP);
	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	if (step==0) {
		this->pData->vx = 0;
		this->pData->vy = -3;
		if (this->pData->y + this->pData->vy < Range.y) {

		}
	}
	this->pData->x += this->pData->vx;
	this->pData->y += this->pData->vy;
}

void WizardFlyingAttackState::onCollision(RectF rect)
{
}

void WizardFlyingAttackState::onCollision(CollisionRectF rect)
{
	pData->y -= pData->vy;
	pData->vy = 0; 

}

void WizardFlyingAttackState::onDead()
{
}

WizardFlyingAttackState::~WizardFlyingAttackState()
{
}
