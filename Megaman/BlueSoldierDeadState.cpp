#include "BlueSoldierDeadState.h"
#include "BlueSoldierData.h"


BlueSoldierDeadState::BlueSoldierDeadState(EnemyData *pData)
{


	this->pData = pData;
	this->pData->iCurrentArr = BlueSoldierData::BlueSoldierArrindex::DIE;
	Sound::getInstance()->play("Enemy_Destroy", false, 1);

}


void BlueSoldierDeadState::onUpdate()
{
	if (this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
		this->pData->isDesTroyed = true;
	}
	else
	{
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	}
}

BlueSoldierDeadState::~BlueSoldierDeadState()
{
}
