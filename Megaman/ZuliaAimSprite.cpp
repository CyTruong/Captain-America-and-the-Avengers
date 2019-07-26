#include "ZuliaAimSprite.h"
#include "ZuliaAimData.h"
#include "ZuliaAimMovingState.h"




ZuliaAimSprite::ZuliaAimSprite(float x, float y)
{
	this->pData = new ZuliaAimData();
	BulletSprite::pData = pData;
	this->pData->isDesTroyed = false;
	this->pData->ppTextureArrays = new TextureArray*[ZuliaAimData::COUNT];

	this->pData->ppTextureArrays[ZuliaAimData::FLY] = new TextureArray(RESOURCE_SPRITE, "Zulia", "Aim", 4, 15);
	this->pData->ppTextureArrays[ZuliaAimData::FLY]->setAnchorPoint(0.5f, 0.5f);

	this->pData->x = x;
	this->pData->y = y;

	this->pData->pState = new ZuliaAimMovingState(this->pData);
}

void ZuliaAimSprite::draw(Camera * cam)
{
	pData->ppTextureArrays[this->pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
}

void ZuliaAimSprite::update()
{
	pData->pState->onUpdate();
}

void ZuliaAimSprite::destroy()
{
	UIComponents::getInstance()->setisTargeting(true);
	this->pData->isDesTroyed = true;
}

ZuliaAimSprite::~ZuliaAimSprite()
{
}
