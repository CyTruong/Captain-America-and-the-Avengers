#include "BoxState.h"
#include "DoubleRocketNormalBulletSprite.h"
#include "BoxData.h"
#include"BoxDeadState.h"
#include <math.h>
BoxState::BoxState(EnemyData * pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = BoxData::PRESENT; 
}

void BoxState::onUpdate()
{
	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();

	pData->vy += 0.2;
	pData->y += pData->vy;







}

void BoxState::onCollision(RectF rect)
{
}

void BoxState::onCollision(CollisionRectF rect)
{


	pData->y -= pData->vy;
	pData->vy -= 0.2;

}

void BoxState::createBullet()
{

}

void BoxState::onDead()
{
	transition(new BoxDeadState(this->pData));
}

BoxState::~BoxState()
{
}
