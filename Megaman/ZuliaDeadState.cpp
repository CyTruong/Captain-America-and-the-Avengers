#include "ZuliaDeadState.h"
#include"ZuliaData.h"


ZuliaDeadState::ZuliaDeadState(EnemyData *pData)
{


	this->pData = pData;
	this->pData->iCurrentArr = ZuliaData::ZuliaAniIndex::DIE;
	Sound::getInstance()->play("Enemy_Destroy", false, 1);

}


void ZuliaDeadState::onUpdate()
{
	UIComponents::getInstance()->setShurikanHp(0);


	if (this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
		this->pData->isDesTroyed = true;
	}
	else
	{
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	}
}

ZuliaDeadState::~ZuliaDeadState()
{
}
