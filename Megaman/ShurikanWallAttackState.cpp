#include "ShurikanWallAttackState.h"
#include "ShurikanBounceAttackState.h"
#include "ShurikanData.h"
#include"ShurikanDeadState.h"


ShurikanWallAttackState::ShurikanWallAttackState(EnemyData * pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = ShurikanData::SurikenAniIndex::WALLSPIN;
	this->pData->vx = -1;
	this->pData->vy = 0;
	waitting2changecount = 0;
	
	midX = 2432;
	midY = 1120;

	speed = 3;

}

void ShurikanWallAttackState::onUpdate()
{
	this->pData->ppTextureArrays[ShurikanData::SurikenAniIndex::WALLSPIN]->update();
	UIComponents::getInstance()->setShurikanHp(pData->HP);




	this->pData->x += this->pData->vx * speed;
	this->pData->y += this->pData->vy * speed;

	if (waitting2changecount++ > 500   && this->pData->vy ==0 && this->pData->y > midY) {
		transition(new ShurikanBounceAttackState(this -> pData));
	}
}

void ShurikanWallAttackState::onCollision(RectF rect)
{
}

void ShurikanWallAttackState::onCollision(CollisionRectF rect)
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
				LogWriter::getInstance()->write("Va cham tren vy >= 0, vx >0 ");
				pData->y -= py;
				pData->vy = 0.0f;
				if (this->pData->x < midX) {
					this->pData->vx = 1;
				}
				else
				{
					this->pData->vx = -1;
				}
			}
			else
			{
				// va chạm bên phải
				LogWriter::getInstance()->write("Va cham ben phai vy > 0, vx >0 ");

				pData->x -= px;
				this->pData->vx = 0;
				if (this->pData->y < midY) {
					this->pData->vy = 1;
				}
				else
				{
					this->pData->vy = -1;
				}
			}
		}
		else // vy <= 0.0f
		{
			float px = right - leftR;
			float py = bottomR - top;
			if ((-vy * px) > vx * py)
			{
				//va chạm trên
				LogWriter::getInstance()->write("Va cham tren vy <= 0, vx >0 ");

				pData->y += py;
				pData->vy = 0.0f;
				this->pData->vx = 0;
				if (this->pData->x < midX) {
					this->pData->vx = 1;
				}
				else
				{
					this->pData->vx = -1;
				}
			}
			else
			{
				//va chạm bên trái
				LogWriter::getInstance()->write("Va cham ben trai vy <= 0, vx >0 ");

				pData->x -= px;
				this->pData->vx = 0;
				if (this->pData->y < midY) {
					this->pData->vy = 1;
				}
				else
				{
					this->pData->vy = -1;
				}
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
				LogWriter::getInstance()->write("Va cham tren vy > 0, vx <= 0 ");

				pData->y -= py;
				pData->vy = 0.0f;
				if (this->pData->x < midX) {
					this->pData->vx = 1;
				}
				else
				{
					this->pData->vx = -1;
				}
			}
			else
			{
				// side collision
				LogWriter::getInstance()->write("Va cham ben phai vy > 0, vx  <=0 ");

				pData->x += px;
				this->pData->vx = 0;
				if (this->pData->y < midY) {
					this->pData->vy = 1;
				}
				else
				{
					this->pData->vy = -1;
				}
			}
		}
		else // vy <= 0.0f
		{
			float px = rightR - left;
			float py = bottomR - top;
			if ((-vy * px) > (-vx * py))
			{
				// top collision
				LogWriter::getInstance()->write("Va cham tren vy <= 0, vx <= 0 ");

				pData->y += py;
				pData->vy = 0.0f;
				if (this->pData->x < midX) {
					this->pData->vx = 1;
				}
				else
				{
					this->pData->vx = -1;
				}
			}
			else
			{
				// side collision
				LogWriter::getInstance()->write("Va cham ben trai vy <= 0, vx <=0 ");

				pData->x += px;
				this->pData->vx = 0;
				if (this->pData->y < midY) {
					this->pData->vy = 1;
				}
				else
				{
					this->pData->vy = -1;
				}
			}
		}
	}
}

void ShurikanWallAttackState::onDead()
{
	transition(new ShurikanDeadState(this->pData));

}

ShurikanWallAttackState::~ShurikanWallAttackState()
{
}
