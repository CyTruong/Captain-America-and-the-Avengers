#include "ShurikanRunningAttackState.h"
#include "ShurikanData.h"
#include "ShurikanWallAttackState.h"
#include "ShurikanBounceAttackState.h"
#include"ShurikanDeadState.h"
ShurikanRunningAttackState::ShurikanRunningAttackState(EnemyData * pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = ShurikanData::SurikenAniIndex::SPIN;
	speed = 3;
	this->pData->vy = 1;
	counttingJump = 0;
}

void ShurikanRunningAttackState::onUpdate()
{
	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	UIComponents::getInstance()->setShurikanHp(pData->HP);


	this->pData->vx = this->pData->transform(speed);
	this->pData->x += this->pData->vx;
	
	if (pData->vy != 0) {
		this->pData->vy += .4;
	}
	this->pData->y += this->pData->vy;

	

	if (counttingJump++ > 100) {
		if (jumptimes++ > 2) {
			transition(new ShurikanWallAttackState(this->pData));
			//transition(new ShurikanBounceAttackState(this->pData));
			return;
		}
		counttingJump = 0;
		this->pData->vy = -8.3;
	}


}

void ShurikanRunningAttackState::onCollision(RectF rect)
{
	
}

void ShurikanRunningAttackState::onCollision(CollisionRectF rect)
{

	// có 4 trường hợp va chạm
	float vx = pData->vx;
	float vy = pData->vy;
	float top = pData->getBody().y;
	float left = pData->getBody().x;
	float right = left + pData->getBody().width;
	float bottom = top + pData->getBody().height;


	float topR = rect.rect.y;
	float leftR = rect.rect.x;
	float rightR = leftR + rect.rect.width;
	float bottomR = topR + rect.rect.height;

	if (vx > 0.0f)
	{
		if (vy >= 0.0f)
		{
			float px = right - leftR;
			float py = bottom - topR;
			if (vy * px > vx * py)
			{
				// va chạm phía trên 
				pData->y -= py;
				pData->vy = 0.0f;

			}
			else
			{
				// va chạm bên phải
				pData->x -= px;
				pData->dir.reverse();

			}
		}
		else // vy <= 0.0f
		{
			float px = right - leftR;
			float py = bottomR - top;
			if ((-vy * px) > vx * py)
			{
				//va chạm trên
				pData->y += py;
				pData->vy = 0.0f;
			}
			else
			{
				//va chạm bên trái
				pData->x -= px;
				pData->dir.reverse();
			}
		}
	}
	else // vx <= 0.0f
	{
		if (vy >= 0.0f)
		{
			float px = rightR - left;
			float py = bottom - topR;
			if (vy * px > (-vx * py))
			{
				// top collision

				pData->y -= py;
				pData->vy = 0.0f;

			}
			else
			{
				// side collision
				pData->x += px;
				pData->dir.reverse();
			}
		}
		else // vy <= 0.0f
		{
			float px = rightR - left;
			float py = bottomR - top;
			if ((-vy * px) > (-vx * py))
			{
				// top collision
				pData->y += py;
				pData->vy = 0.0f;
			}
			else
			{
				// side collision
				pData->x += px;
				pData->dir.reverse();
			}
		}
	}
}

void ShurikanRunningAttackState::onDead()
{
	transition(new ShurikanDeadState(this->pData));

}

ShurikanRunningAttackState::~ShurikanRunningAttackState()
{
}
