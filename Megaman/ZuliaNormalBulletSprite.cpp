#include "ZuliaNormalBulletSprite.h"
#include "ZuliaNormalBulletData.h"
#include "ZuliaNormalBulletMovingState.h"


ZuliaNormalBulletSprite::ZuliaNormalBulletSprite(float x, float y, float angle,RectF range)
{
	this->pData = new ZuliaNormalBulletData();
	BulletSprite::pData = pData;
	
	this->pData->isDesTroyed = false;
	this->pData->ppTextureArrays = new TextureArray*[ZuliaNormalBulletData::COUNT];

	this->angle = angle;

	//Sound::getInstance()->play("SingleGunFire", false, 1);

	this->pData->ppTextureArrays[ZuliaNormalBulletData::FLY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "Zulia_fly",3, 5);
	this->pData->ppTextureArrays[ZuliaNormalBulletData::FLY]->setAnchorPoint(0.5f, 0.5f);

	this->pData->ppTextureArrays[ZuliaNormalBulletData::STAND] = new TextureArray(RESOURCE_SPRITE, "Bullet", "Zulia_fly", 3, 5);
	this->pData->ppTextureArrays[ZuliaNormalBulletData::STAND]->setAnchorPoint(0.5f, 0.5f);

	this->pData->ppTextureArrays[ZuliaNormalBulletData::DESTROY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "Zulia_des", 7, 4);
	this->pData->ppTextureArrays[ZuliaNormalBulletData::DESTROY]->setAnchorPoint(0.5f, 0.5f);


	//body

	this->pData->x = x;
	this->pData->y = y;

	this->pData->pState = new ZuliaNormalBulletMovingState(this->pData, 1.0f, angle, range);

}

void ZuliaNormalBulletSprite::draw(Camera * cam)
{
	if (angle <  M_PI_4 ) {
		pData->ppTextureArrays[this->pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
	}
	else
		pData->ppTextureArrays[this->pData->iCurrentArr]->draw(pData->x, pData->y, cam);

}

void ZuliaNormalBulletSprite::update()
{
	pData->pState->onUpdate();

}

ZuliaNormalBulletSprite::~ZuliaNormalBulletSprite()
{
}
