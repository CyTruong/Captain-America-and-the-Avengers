#include "WizardNormalBulletSprite.h"
#include "WizardNormalBulletMovingState.h"
#include "Sound.h"


WizardNormalBulletSprite::WizardNormalBulletSprite(float x, float y, float angle)
{
	this->pData = new WizardNormalBulletData();
	BulletSprite::pData = pData;
	this->pData->isDesTroyed = false;
	this->pData->ppTextureArrays = new TextureArray*[MgmNormalBulletData::COUNT];

	this->angle = angle;

	Sound::getInstance()->play("SingleGunFire", false, 1);

	this->pData->ppTextureArrays[WizardNormalBulletData::FLY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "WizardNormal_fly2", 1, 5);
	this->pData->ppTextureArrays[WizardNormalBulletData::FLY]->setAnchorPoint(0.5f, 0.5f);

	this->pData->ppTextureArrays[WizardNormalBulletData::DESTROY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "Dust", 5, 5);
	this->pData->ppTextureArrays[WizardNormalBulletData::DESTROY]->setAnchorPoint(0.5f, 0.5f);

	this->pData->body = RectF(-this->pData->ppTextureArrays[WizardNormalBulletData::FLY]->getWidth() / 2,
		-this->pData->ppTextureArrays[WizardNormalBulletData::FLY]->getHeight() / 2,
		this->pData->ppTextureArrays[WizardNormalBulletData::FLY]->getWidth(),
		this->pData->ppTextureArrays[WizardNormalBulletData::FLY]->getHeight()
	);

	this->pData->x = x;
	this->pData->y = y;

	this->pData->pState = new WizardNormalBulletMovingState(this->pData, 3, angle);
}

void WizardNormalBulletSprite::draw(Camera * cam)
{
	if (!this->pData->isDesTroyed)
		pData->ppTextureArrays[this->pData->iCurrentArr]->draw(pData->x, pData->y, cam);
}

void WizardNormalBulletSprite::update()
{
	pData->pState->onUpdate();
}

WizardNormalBulletSprite::~WizardNormalBulletSprite()
{
}
