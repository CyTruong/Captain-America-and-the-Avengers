

#include"DoorState.h"
#include"UI.h"

DoorState::DoorState(ObjectData * pdata)

{

	this->pData = pdata; 
	isMegamanPassing = false; 
	isMegamanCollision = false; 
	isClosed = false;

	this->pData->iCurrentArr = 0; 
	this->counting = 0; 

	this->pData->vx = 0;
	this->pData->vx = 0;
}

DoorState::~DoorState()
{
}

void DoorState::onUpdate() {
	// 32 == Witgh mgm or door 


	// check va cham voi gate nua 

	if (isMegamanCollision &&UIComponents::getInstance()->getShurikanHp() == 0&&pData->playerX <pData->x)
	{
		// set đang mở -> sau bao nhieu fam ->set mở 	
		this->pData->iCurrentArr = DoorData::OPEN;

	}
	// if megaman pos x > set dang đóng .... (đóng xong 1 lần là đóng ->set đóng )
	  // set biến đã mở và đóng 

	if ((pData->playerX > pData->x  &&UIComponents::getInstance()->getShurikanHp() != 0)||(pData->playerX>159*16&& pData->playerX < 165 * 16 && UIComponents::getInstance()->getShurikanHp() == 0))
	{
		this->pData->iCurrentArr = DoorData::CLOSE;

	}

	if ((this->pData->iCurrentArr==DoorData::OPEN|| this->pData->iCurrentArr == DoorData::CLOSE)&&!this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
		pData->ppTextureArrays[pData->iCurrentArr]->update();
	}
	//this->pData->ppTextureArrays[this->pData->iCurrentArr]->update(); 


	pData->collisionRect = CollisionRectF(pData->getBody(), "door", pData->vx, pData->vy);

	isMegamanCollision = 0; 


}

void DoorState::onCollision(RectF rect)
{


}

void DoorState::onCollision(CollisionRectF crect)
{

	// thay đổi vị trí x,y của mgm 
	// dịch chuyển cam theo với V chậm hơn 
	if (crect.type == "Megaman") {
		isMegamanCollision = true;
	}


}

void DoorState::onCollision(Object obj)
{


}



