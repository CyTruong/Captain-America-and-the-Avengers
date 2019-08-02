#include "WizardDropdownBulletSprite.h"
#include "WizardDropdownBulletMovingState.h"
#include "Sound.h"


WizardDropdownBulletSprite::WizardDropdownBulletSprite(float x, float y)
{
	this->pData = new WizardDropdownBulletData();
	BulletSprite::pData = pData;
	this->pData->isDesTroyed = false;
	this->pData->ppTextureArrays = new TextureArray*[MgmNormalBulletData::COUNT];

	Sound::getInstance()->play("SingleGunFire", false, 1);

	this->pData->ppTextureArrays[WizardDropdownBulletData::FLY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "WizardDropdown_fly", 1, 5);
	this->pData->ppTextureArrays[WizardDropdownBulletData::FLY]->setAnchorPoint(0.5f, 0.5f);

	this->pData->ppTextureArrays[WizardDropdownBulletData::DESTROY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "Dust", 5, 5);
	this->pData->ppTextureArrays[WizardDropdownBulletData::DESTROY]->setAnchorPoint(0.5f, 0.5f);

	this->pData->body = RectF(-this->pData->ppTextureArrays[WizardDropdownBulletData::FLY]->getWidth() / 2,
		-this->pData->ppTextureArrays[WizardDropdownBulletData::FLY]->getHeight() / 2,
		this->pData->ppTextureArrays[WizardDropdownBulletData::FLY]->getWidth(),
		this->pData->ppTextureArrays[WizardDropdownBulletData::FLY]->getHeight()
	);

	this->pData->x = x;
	this->pData->y = y;

	this->pData->pState = new WizardDropdownBulletMovingState(this->pData, 6);
}

void WizardDropdownBulletSprite::draw(Camera * cam)
{
	if (!this->pData->isDesTroyed)
		pData->ppTextureArrays[this->pData->iCurrentArr]->draw(pData->x, pData->y, cam);
}

void WizardDropdownBulletSprite::update()
{
	pData->pState->onUpdate();
}

WizardDropdownBulletSprite::~WizardDropdownBulletSprite()
{
}
