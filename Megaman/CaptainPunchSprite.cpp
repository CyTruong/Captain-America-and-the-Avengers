#pragma once;

#include "CaptainPunchSprite.h"
#include "CaptainPunchActiveState.h"

CaptainPunchSprite::CaptainPunchSprite(int size, float x, float y, float speed, float angle) {
	this->pData = new CaptainPunchData();
	this->pData->isDesTroyed = false;
	this->pData->ppTextureArrays = new TextureArray*[CaptainPunchData::COUNT];
	this->pData->bodyRects = new RectF[CaptainPunchData::COUNT];
	this->angle = angle;

	this->pData->ppTextureArrays[CaptainPunchData::ACTIVE] = new TextureArray(RESOURCE_SPRITE, "Bullet", "CaptainKick", 1, 500);
	this->pData->ppTextureArrays[CaptainPunchData::ACTIVE]->setAnchorPoint(0.5f, 0.5f);
	this->pData->bodyRects[CaptainPunchData::ACTIVE] = RectF(-pData->ppTextureArrays[CaptainPunchData::ACTIVE]->getWidth() / 2, -pData->ppTextureArrays[CaptainPunchData::ACTIVE]->getHeight(), pData->ppTextureArrays[CaptainPunchData::ACTIVE]->getWidth(), pData->ppTextureArrays[CaptainPunchData::ACTIVE]->getHeight());
	pData->x = x;
	pData->y = y;

	//lưu ý dòng này để link con trỏ datat đến bullet sprite
	pData->pState = new CaptainPunchActiveState(pData, speed, angle, CaptainPunchData::ACTIVE);
	BulletSprite::pData = pData;
}
void CaptainPunchSprite::draw(Camera * cam)
{

	pData->ppTextureArrays[this->pData->iCurrentArr]->draw(pData->x, pData->y, cam);

}


void CaptainPunchSprite::update()
{
	pData->pState->onUpdate();

}

void CaptainPunchSprite::Trigger(int index)
{

}

CaptainPunchSprite::~CaptainPunchSprite()
{
}
