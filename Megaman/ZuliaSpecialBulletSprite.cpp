#include "ZuliaSpecialBulletSprite.h"
#include "ZuliaSpecialBulletMovingState.h"


ZuliaSpecialBulletSprite::ZuliaSpecialBulletSprite(float x, float y)
{
	this->pData = new ZuliaSpecialBulletData();
	BulletSprite::pData = pData;
	this->pData->isDesTroyed = false;
	this->pData->ppTextureArrays = new TextureArray*[ZuliaSpecialBulletData::COUNT];


	//Sound::getInstance()->play("SingleGunFire", false, 1);

	this->pData->ppTextureArrays[ZuliaSpecialBulletData::FLY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "Zulia_fly", 3, 5);
	this->pData->ppTextureArrays[ZuliaSpecialBulletData::FLY]->setAnchorPoint(0.5f, 0.5f);

	this->pData->ppTextureArrays[ZuliaSpecialBulletData::DESTROY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "Zulia_des", 7, 4);
	this->pData->ppTextureArrays[ZuliaSpecialBulletData::DESTROY]->setAnchorPoint(0.5f, 0.5f);


	//body

	this->pData->x = x;
	this->pData->y = y;

	RectF Range = RectF(7673, 1718, 215, 146);
	this->pData->pState = new ZuliaSpecialBulletMovingState(this->pData, 1.0f, Range);

}

void ZuliaSpecialBulletSprite::draw(Camera * cam)
{
	pData->ppTextureArrays[this->pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
}

void ZuliaSpecialBulletSprite::update()
{
	pData->pState->onUpdate();

}

ZuliaSpecialBulletSprite::~ZuliaSpecialBulletSprite()
{
}


