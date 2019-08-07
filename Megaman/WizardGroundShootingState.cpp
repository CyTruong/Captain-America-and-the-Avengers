#include "WizardGroundShootingState.h"
#include "WizardNormalBulletSprite.h"
#include "WizardStandingState.h"
#include "WizardFlyingAttackState.h"

WizardGroundShootingState::WizardGroundShootingState(EnemyData *pData)
{

	LogWriter::getInstance()->write("Wizard Fire State");
	this->pData = pData;
	this->pData->iCurrentArr = WizardData::STANDSHOOT;
	this->bulletcount = 0;
}

void WizardGroundShootingState::onUpdate()
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
		bulletcount++;
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->resetIndex();
		//transition(new SingleGunStandState(this->pData));
	}
	else
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	if (bulletcount >2) {
		transition(new WizardFlyingAttackState(this->pData, RectF(16,80, 210, 100)));
	}
}

void WizardGroundShootingState::onCollision(RectF rect)
{
}

void WizardGroundShootingState::onCollision(CollisionRectF rect)
{

}


void WizardGroundShootingState::createBullet()
{
	float angle;
	if (pData->dir.isRight()) {
		angle = 0;
	}
	else
	{
		angle = M_PI;
	}
	this->pData->bulletsVector.push_back(new WizardNormalBulletSprite(this->pData->x, this->pData->y - ( this->pData->body.height / 2), angle));
}

void WizardGroundShootingState::onDead()
{
	//transition(new SingleGunDeadState(this->pData));
}

WizardGroundShootingState::~WizardGroundShootingState()
{
}
