#pragma once
#include "BulletState.h"
#include "CaptainSheildData.h"
#include "UI.h"

class CaptainSheildMovingState : public BulletState
{
private:
	float speed;
	bool back;
public:
	CaptainSheildMovingState(CaptainSheildData * pdata, float speed, float angle, int icurent = 0) {

		this->pData = pdata;
		pData->iCurrentArr = icurent;
		this->speed = speed;
		this->back = false;

		pData->vy = sin(angle) * speed;
		pData->vx = cos(angle) * speed;
	}

	virtual void onUpdate() override
	{
		/*if (this->pData->iCurrentArr == MgmNormalBulletData::DESTROY && this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
			this->pData->isDesTroyed = true;
		}*/
		if (this->pData->dir == Direction::createRight()) {
			pData->vx =  speed;
		}
		else
		{
			pData->vx = -speed;
			pData->vy = 0;
		}
		pData->ppTextureArrays[pData->iCurrentArr]->update();
		if (pData->iCurrentArr == CaptainSheildData::HOLD) {
			pData->x = UIComponents::getInstance()->getMegamanX();
			pData->y = UIComponents::getInstance()->getMegamanY();
			return;
		}
		if (pData->iCurrentArr == CaptainSheildData::FLY) {
			if (!this->back) {
				if (abs( pData->x - UIComponents::getInstance()->getMegamanX()) > 150) {
					this->back = true;
				}
			}
			else {
				this->pData->vy = abs((UIComponents::getInstance()->getMegamanY() - this->pData->y) / (UIComponents::getInstance()->getMegamanX() - this->pData->x) *speed);
				this->pData->vy = (UIComponents::getInstance()->getMegamanY() > this->pData->y) ? this->pData->vy : -this->pData->vy;
				this->pData->vx = ((UIComponents::getInstance()->getMegamanX() > this->pData->x) ? 1 : -1)*speed;
				if (abs( UIComponents::getInstance()->getMegamanX() - this->pData->x )  <= 10) {
					this->pData->iCurrentArr = CaptainSheildData::HOLD;
					this->pData->vy = 0;
					this->pData->vy = 0;
					this->back = false;
				}
			}
		}
		pData->x += pData->vx;
		pData->y += pData->vy;
	}

	void onCollision(CollisionRectF rect) override
	{
		/*char* str = _strdup(rect.type.c_str());
		if (str[0]=='e' && str[1] == 'n' && str[2] == 'e' && str[3] == 'm' && str[4] == 'y')
		{
			this->pData->iCurrentArr = MgmNormalBulletData::SpriteArrayIndex::DESTROY;
		}*/
		//if (rect.type == "enemy") {
		//	//this->pData->iCurrentArr = MgmNormalBulletData::SpriteArrayIndex::DESTROY;
		//	this->pData->isDesTroyed = true;

		//}
	}
};
