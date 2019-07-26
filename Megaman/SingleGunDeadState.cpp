#include "SingleGunDeadState.h"
#include "SingleGunData.h"


SingleGunDeadState::SingleGunDeadState(EnemyData *pData)
{


	this->pData = pData;
	this->pData->iCurrentArr = SingleGunData::SingleGunArrindex::DIE;
	Sound::getInstance()->play("Enemy_Destroy", false, 1);

}


void SingleGunDeadState::onUpdate()
{
	if (this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
		this->pData->isDesTroyed = true;
	}
	else
	{
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	}
}

SingleGunDeadState::~SingleGunDeadState()
{
}
