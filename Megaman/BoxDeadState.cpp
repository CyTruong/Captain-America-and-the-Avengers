#include "BoxDeadState.h"
#include "RocketFlyData.h"


BoxDeadState::BoxDeadState(EnemyData *pData)
{


	this->pData = pData;
	this->pData->iCurrentArr = RocketFlyData::DIE;

}


void BoxDeadState::onUpdate()
{
	if (this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
		this->pData->isDesTroyed = true;
	}
	else
	{
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	}
}

BoxDeadState::~BoxDeadState()
{
}
