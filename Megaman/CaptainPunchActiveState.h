#pragma once
#include "BulletState.h"
#include "CaptainPunchData.h"
#include "UI.h"

class CaptainPunchActiveState : public BulletState
{
private:
	int count = 0;
	float speed;
	bool back;
public:
	CaptainPunchActiveState(CaptainPunchData * pdata, float speed, float angle, int icurent = 0) {

		this->pData = pdata;
		pData->iCurrentArr = icurent;
		this->speed = speed;
		this->back = false;

		pData->vy = sin(angle) * speed;
		pData->vx = cos(angle) * speed;
	}

	virtual void onUpdate() override
	{
		count++;
		if (count > 10) {
			this->pData->isDesTroyed = true;
		}
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

