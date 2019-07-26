#include "ShurikanBounceAttackState.h"
#include "ShurikanWallAttackState.h"
#include "ShurikanDeadState.h"


ShurikanBounceAttackState::ShurikanBounceAttackState(EnemyData * pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = ShurikanData::SurikenAniIndex::BOUNCE_START;
	speed = 3.3;
	this->pData->vy = 1;
	FrameJump = 0;
	FrameRun = 0;
	jumpCount = 0;
}

void ShurikanBounceAttackState::onUpdate()
{
	UIComponents::getInstance()->setShurikanHp(pData->HP);

	if (FrameRun++ > 120) {
		this->pData->iCurrentArr = ShurikanData::SurikenAniIndex::BOUNCE_RUN;
		this->pData->y += -5;
		FrameRun = 0;
		jumpCount++;
	}
	if (jumpCount > 8) {
		transition(new ShurikanWallAttackState(this->pData));
		return; 

	}

	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();


	if (this->pData->iCurrentArr == ShurikanData::SurikenAniIndex::BOUNCE_RUN) {
		this->pData->vx = this->pData->transform(speed);
		this->pData->x += this->pData->vx;

		if (pData->vy != 0) {
			this->pData->vy += 0.8;
		}
		this->pData->y += this->pData->vy;
	}
	

	if (FrameJump++ > 65 && this->pData->iCurrentArr == ShurikanData::SurikenAniIndex::BOUNCE_RUN) {
		FrameJump = 0;
		this->pData->vy = -7;
	}

}

void ShurikanBounceAttackState::onCollision(RectF rect)
{
}

void ShurikanBounceAttackState::onCollision(CollisionRectF rect)
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

void ShurikanBounceAttackState::onDead()
{
	transition(new ShurikanDeadState(this->pData));

}


ShurikanBounceAttackState::~ShurikanBounceAttackState()
{
}
