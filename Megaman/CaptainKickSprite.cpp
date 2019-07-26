#pragma once;

#include "CaptainKickSprite.h"
#include "CaptainKickActiveState.h"

CaptainKickSprite::CaptainKickSprite(int size, float x, float y, float speed, float angle){
	this->pData = new CaptainKickData();
	this->pData->isDesTroyed = false;
	this->pData->ppTextureArrays = new TextureArray*[CaptainKickData::COUNT];
	this->pData->bodyRects = new RectF[CaptainKickData::COUNT];
	this->angle = angle;

	this->pData->ppTextureArrays[CaptainKickData::ACTIVE] = new TextureArray(RESOURCE_SPRITE, "Bullet", "CaptainKick", 1, 500);
	this->pData->ppTextureArrays[CaptainKickData::ACTIVE]->setAnchorPoint(0.5f, 0.5f);
	this->pData->bodyRects[CaptainKickData::ACTIVE] = RectF(-pData->ppTextureArrays[CaptainKickData::ACTIVE]->getWidth() / 2, -pData->ppTextureArrays[CaptainKickData::ACTIVE]->getHeight(), pData->ppTextureArrays[CaptainKickData::ACTIVE]->getWidth(), pData->ppTextureArrays[CaptainKickData::ACTIVE]->getHeight());
	pData->x = x;
	pData->y = y;

	//lưu ý dòng này để link con trỏ datat đến bullet sprite
	pData->pState = new CaptainKickActiveState(pData, speed, angle, CaptainKickData::ACTIVE);

	BulletSprite::pData = pData;
}
void CaptainKickSprite::draw(Camera * cam)
{
	
		pData->ppTextureArrays[this->pData->iCurrentArr]->draw(pData->x, pData->y, cam);

}


void CaptainKickSprite::update()
{
	pData->pState->onUpdate();

}

void CaptainKickSprite::Trigger(int index)
{
	
}

CaptainKickSprite::~CaptainKickSprite()
{
}
