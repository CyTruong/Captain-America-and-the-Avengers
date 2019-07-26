#include "MegamanStartState.h"
#include "MegamanStandingState.h"
#include "MegamanJumpState.h"

MegamanStartState::MegamanStartState(MegamanData* data)
{
	this->pData = data;
	this->pData->setiCurrentArray(MegamanData::START);
	this->pData->isUndying = true;
	this->pData->isRespawn = true;
}


MegamanStartState::~MegamanStartState()
{
}

void MegamanStartState::onUpdate()
{
	if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture()) {
		this->pData->isRespawn = false;
		transition(new MegamanJumpState(this->pData, false, 0));
	}
	else {
		hittableCalculation();
		this->pData->ppTextureArrays[pData->iCurrentArr]->update();
	}
	
	
}
