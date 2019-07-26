#include "RocketFlyDeadState.h"
#include "RocketFlyData.h"


RocketFlyDeadState::RocketFlyDeadState(EnemyData *pData)
{


	this->pData = pData;
	this->pData->iCurrentArr = RocketFlyData::DIE;
	Sound::getInstance()->play("Enemy_Destroy", false, 1);

}


void RocketFlyDeadState::onUpdate()
{
	if (this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
		this->pData->isDesTroyed = true;
	}
	else
	{
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	}
}

RocketFlyDeadState::~RocketFlyDeadState()
{
}
