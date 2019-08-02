#include "RocketSoldierDeadState.h"
#include "RocketSoldierData.h"


RocketSoldierDeadState::RocketSoldierDeadState(EnemyData *pData)
{


	this->pData = pData;
	this->pData->iCurrentArr = RocketSoldierData::RocketSoldierArrindex::DIE;
	Sound::getInstance()->play("Enemy_Destroy", false, 1);

}


void RocketSoldierDeadState::onUpdate()
{
	if (this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
		this->pData->isDesTroyed = true;
	}
	else
	{
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	}
}

RocketSoldierDeadState::~RocketSoldierDeadState()
{
}