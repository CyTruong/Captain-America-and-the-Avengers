#include "MegamanDamagedState.h"
#include "MegamanJumpState.h"
#include "MegamanRunningState.h"
#include "MegamanJumpState.h"
#include "MegamanSlideState.h"
#include "MegamanStandingState.h"

MegamanDamagedState::MegamanDamagedState(MegamanData * pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = MegamanData::DAMAGED;
	this->pData->isUndying = true;
	this->pData->isHittable = false;
	/*lastY = this->pData->y;
	this->pData->y -= 8;
	this->pData->vy = 1;
	*/
	
}

void MegamanDamagedState::onUpdate()
{
	/*if (this->pData->y < lastY- this->pData->vy) {
		this->pData->y += this->pData->vy;
	}
*/
	hittableCalculation();
	undyingCalculation();
	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	if (this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
		transition(new MegamanStandingState(this->pData));
	}
}

void MegamanDamagedState::onMovePressed(Direction d)
{
	pData->dir = d;
	// hcmt cam move 
	pData->movedir = d;
	transition(new MegamanRunningState(pData));
}


void MegamanDamagedState::onJumpPressed()
{
	transition(new MegamanJumpState(this->pData, false, -4.5f));
}

void MegamanDamagedState::onSlidePressed()
{
	transition(new MegamanSlideState(this->pData));

}


MegamanDamagedState::~MegamanDamagedState()
{
}
