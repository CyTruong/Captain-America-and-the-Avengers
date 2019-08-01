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

void WizardRunningState::onDead()
{
//	transition(new ShurikanDeadState(this->pData));

}

WizardRunningState::~WizardRunningState()
{
}
