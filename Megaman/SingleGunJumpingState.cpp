#include "SingleGunJumpingState.h"
#include "SingleGunData.h"
#include "SingleGunStandState.h" 


#include "SingleGunDeadState.h"



SingleGunJumpingState::SingleGunJumpingState(EnemyData * pData)
{

	LogWriter::getInstance()->write("SingleGun Jump State");
	LogWriter::getInstance()->write(6, (int)pData->dir.dir);
	this->gravity = 0.2;
	this->pData = pData;
	this->pData->iCurrentArr = SingleGunData::JUMP;
	this->pData->vy = -6.0f;
		pData->vx = pData->transform(SINGLEGUNRUNSPEED);

}

void SingleGunJumpingState::onUpdate()
{

	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	pData->vx = pData->transform(SINGLEGUNRUNSPEED);
	pData->x += pData->vx;

	pData->vy += gravity;
	pData->y += pData->vy;
}

void SingleGunJumpingState::onCollision(CollisionRectF rect)
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
		if (vy > 0.0f)
		{
			float px = right - leftR;
			float py = bottom - topR;
			if (vy * px > vx * py)
			{
				// va chạm phía trên 
				pData->vy = 0.0f;
				pData->y -= py;

				transition(new SingleGunStandState(pData));
				
				
			}
			else
			{
				// va chạm bên phải
				pData->x -= px;
				pData->vx = 0.0f;

			}
		}
		else // vy <= 0.0f
		{
			float px = right - leftR;
			float py = bottomR - top;
			if ((-vy * px) > vx * py)
			{
				////va chạm trên
				//pData->y += py;
				//pData->vy = 0.0f;
			}
			else
			{
				//va chạm bên trái
				pData->x -= px;
				pData->vx = 0.0f;
				transition(new SingleGunStandState(pData));

			}
		}
	}
	else // vx <= 0.0f
	{
		if (vy > 0.0f)
		{
			float px = rightR - left;
			float py = bottom - topR;
			if (vy * px > (-vx * py))
			{
				// top collision

				pData->y -= py;
				pData->vy = 0.0f;

				transition(new SingleGunStandState(pData));
			}
			else
			{
				// side collision
				pData->x += px;
				pData->vx = 0.0f;
			}
		}
		else // vy <= 0.0f
		{
			float px = rightR - left;
			float py = bottomR - top;
			if ((-vy * px) > (-vx * py))
			{
				// top collision
			/*	pData->y += py;
				pData->vy = 0.0f;*/
			}
			else
			{
				// side collision
				pData->x += px;
				pData->vx = 0.0f;
				transition(new SingleGunStandState(pData));

			}
		}
	}
	//transition(new SingleGunStandState(pData));

}

void SingleGunJumpingState::onDead()
{
	transition(new SingleGunDeadState(this->pData));

}

void SingleGunJumpingState::onCollision(RectF rect)
{
}

SingleGunJumpingState::~SingleGunJumpingState()
{
}
