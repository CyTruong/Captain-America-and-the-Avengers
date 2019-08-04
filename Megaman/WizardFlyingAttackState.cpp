#include "WizardFlyingAttackState.h"
#include "WizardData.h"
#include "WizardDropdownBulletSprite.h"
#include "WizardStandingState.h"
#include "WizardDropdownBulletSprite.h"
#include "WizardStandingState.h"
#include "WizardData.h"



WizardFlyingAttackState::WizardFlyingAttackState(EnemyData * pData, RectF Range)
{
	this->Range = Range;
	this->pData = pData;
	this->pData->iCurrentArr = WizardData::FLY;

	this->speed = 3;
	this->isshooting = false;
	step = 0;
}

void WizardFlyingAttackState::onUpdate()
{  
	int Vy = 3;
	UIComponents::getInstance()->setShurikanHp(pData->HP);
	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();

	
	if (step == 0) {

		if (this->pData->y + this->pData->vy > Range.y) {
			this->pData->vx = 0;
			this->pData->vy = -Vy;
		}
		else
		{
			step = 1;
		}
	}
	if (step == 1) {
		if (this->pData->x < this->Range.x + this->Range.width / 2) {
			this->pData->dir = Direction::createRight();

		}
		else
		{
			this->pData->dir = Direction::createLeft();
		}
		step = 2;
	}
	if (step == 2) {
		this->pData->vy = 0;
		this->pData->vx = this->pData->transform(this->speed);
		if ((this->pData->x + this->pData->vx < this->Range.x  && this->pData->dir.isLeft())
			|| (this->pData->x + this->pData->vx > this->Range.x + this->Range.width && this->pData->dir.isRight()))
		{
			step = 3;
			this->pData->dir.reverse();
		}
	}
	if (step == 3) {
		this->pData->vx = 0;
		this->pData->vy = Vy;
		if (this->pData->y + this->pData->vy > this->Range.y + this->Range.height) {

			step = 0;
			step = 4;
		}
	}

	if (step == 4) {

		this->pData->y -= 10;
		transition(new WizardStandingState(this->pData));
		return;
	}
	this->pData->x += this->pData->vx;
	this->pData->y += this->pData->vy;

	if (abs(this->pData->x - this->pData->Megaman_X) <= 1.5) {
		this->isshooting = true;
	}

	if (isshooting && this->pData->iCurrentArr == WizardData::FLY) {
		this->pData->iCurrentArr = WizardData::FLYSHOOT;
	}
	if (this->pData->iCurrentArr == WizardData::FLYSHOOT && this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->resetIndex();
		this->pData->iCurrentArr = WizardData::FLY;
		isshooting = false;
		createBullet();
	}
	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();

}

void WizardFlyingAttackState::createBullet()
{
	this->pData->bulletsVector.push_back(new WizardDropdownBulletSprite(this->pData->x, this->pData->y));

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
