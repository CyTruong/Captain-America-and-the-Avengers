#include "DoubleRocketDeadState.h"
#include "DoubleRocketData.h"


DoubleRocketDeadState::DoubleRocketDeadState(EnemyData *pData)
{


	this->pData = pData;
	this->pData->iCurrentArr = DoubleRocketData::DoubleGunArrindex::DIE;
	Sound::getInstance()->play("Enemy_Destroy", false, 1);
}


void DoubleRocketDeadState::onUpdate()
{
	if (this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
		this->pData->isDesTroyed = true;
	}
	else
	{
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	}
}

DoubleRocketDeadState::~DoubleRocketDeadState()
{
}
