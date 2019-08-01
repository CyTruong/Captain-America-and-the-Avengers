#include "WizardSprite.h"
#include "WizardStandingState.h"
#include"WizardData.h"

WizardSprite::WizardSprite(float x, float y, Direction dir, bool isShoter, std::vector<BulletSprite*>& bullet)
{
	if (isShoter) {
		this->pData = new WizardData(bullet);
	}
	else
	{
		this->pData = new WizardData();
	}

	this->pData->isDead = false;
	this->pData->isDesTroyed = false;
	this->pData->dir = dir;
	this->pData->isHittable = true;
	this->pData->HP = 2;
	this->pData->isShooter = true;
	this->pData->respawnX = x;
	this->pData->respawnY = y;

	this->pData->ppTextureArrays = new TextureArray*[WizardData::COUNT];

	this->pData->ppTextureArrays[WizardData::STAND] = new TextureArray(RESOURCE_SPRITE, "Wizard", "Stand", 1, 21);
	this->pData->ppTextureArrays[WizardData::STAND]->setAnchorPoint(0.5f, 1);

	this->pData->ppTextureArrays[WizardData::RUNNING] = new TextureArray(RESOURCE_SPRITE, "Wizard", "Running", 3, 8);
	this->pData->ppTextureArrays[WizardData::RUNNING]->setAnchorPoint(0.5f, 1);

	this->pData->ppTextureArrays[WizardData::FLY] = new TextureArray(RESOURCE_SPRITE, "Wizard", "Fly", 1, 8);
	this->pData->ppTextureArrays[WizardData::FLY]->setAnchorPoint(0.5f, 1);

	this->pData->ppTextureArrays[WizardData::STANDSHOOT] = new TextureArray(RESOURCE_SPRITE, "Wizard", "StandShoot", 5, 10);
	this->pData->ppTextureArrays[WizardData::STANDSHOOT]->setAnchorPoint(0.5f, 1);

	this->pData->ppTextureArrays[WizardData::FLYSHOOT] = new TextureArray(RESOURCE_SPRITE, "Wizard", "FlyShoot", 3, 10);
	this->pData->ppTextureArrays[WizardData::FLYSHOOT]->setAnchorPoint(0.5f, 1);

	this->pData->ppTextureArrays[WizardData::DIE] = new TextureArray(RESOURCE_SPRITE, "Wizard", "Die", 2, 1000);
	this->pData->ppTextureArrays[WizardData::DIE]->setAnchorPoint(0.5f, 1);

	this->pData->body = RectF(-pData->ppTextureArrays[WizardData::STAND]->getWidth() / 2, -pData->ppTextureArrays[WizardData::STAND]->getHeight(), pData->ppTextureArrays[WizardData::STAND]->getWidth(), pData->ppTextureArrays[WizardData::STAND]->getHeight());

	this->pData->x = this->pData->respawnX;
	this->pData->y = this->pData->respawnY;


	this->pData->pState = new WizardStandingState(this->pData);
}

void WizardSprite::setCollisionRect(CollisionRectF rect)
{
}

void WizardSprite::onCameraCollision(RectF cameraRect)
{
	if (this->pData->dir.isLeft())
	{
		if (this->pData->x <= cameraRect.x)
		{
			this->pData->isDesTroyed = true;
		}
	}
}

WizardSprite::~WizardSprite()
{
}
