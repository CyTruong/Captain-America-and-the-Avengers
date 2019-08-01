#include "SingleGunNormalBulletSprite.h"
#include "SingleGunNormalBulletMovingState.h"
#include "Sound.h"


SingleGunNormalBulletSprite::SingleGunNormalBulletSprite( float x, float y,  float angle)
{
	this->pData = new SingelGunNormalBulletData();
	BulletSprite::pData = pData;
	this->pData->isDesTroyed = false;
	this->pData->ppTextureArrays = new TextureArray*[MgmNormalBulletData::COUNT];
	
	this->angle = angle;

	Sound::getInstance()->play("SingleGunFire",false,1);
	
	this->pData->ppTextureArrays[SingelGunNormalBulletData::FLY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "SingleGun_fly", 1, 60);
	this->pData->ppTextureArrays[SingelGunNormalBulletData::FLY]->setAnchorPoint(0.5f, 0.5f);

	this->pData->ppTextureArrays[SingelGunNormalBulletData::DESTROY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "Dust", 6, 3);
	this->pData->ppTextureArrays[SingelGunNormalBulletData::DESTROY]->setAnchorPoint(0.5f, 0.5f);

	this->pData->body = RectF(- this->pData->ppTextureArrays[SingelGunNormalBulletData::FLY]->getWidth() / 2,
							  - this->pData->ppTextureArrays[SingelGunNormalBulletData::FLY]->getHeight() / 2,
								this->pData->ppTextureArrays[SingelGunNormalBulletData::FLY]->getWidth() ,
								this->pData->ppTextureArrays[SingelGunNormalBulletData::FLY]->getHeight()
							);

	this->pData->x = x;
	this->pData->y = y;

	this->pData->pState = new SingleGunNormalBulleMovingState(this->pData, 9, angle);
}

void SingleGunNormalBulletSprite::draw(Camera * cam)
{
	if(!this->pData->isDesTroyed)
		pData->ppTextureArrays[this->pData->iCurrentArr]->draw(pData->x, pData->y, cam);
}

void SingleGunNormalBulletSprite::update()
{
	pData->pState->onUpdate();
}

SingleGunNormalBulletSprite::~SingleGunNormalBulletSprite()
{
}
