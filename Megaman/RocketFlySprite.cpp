#include "RocketFlySprite.h"
#include "RocketFlyState.h"
#include"RocketFlyData.h"

RocketFlySprite::RocketFlySprite(float x, float y, Direction dir, bool isShoter, std::vector<BulletSprite*>& bullet)
{
	if (isShoter) {
		this->pData = new RocketFlyData(bullet);
	}
	else
	{
		this->pData = new RocketFlyData();
	}

	this->pData->isDead = false;
	this->pData->isDesTroyed = false;
	this->pData->dir = dir;
	this->pData->isHittable = true;
	this->pData->HP = 2;
	this->pData->isShooter = true;
	this->pData->respawnX = x;
	this->pData->respawnY = y;

	this->pData->ppTextureArrays = new TextureArray*[RocketFlyData::COUNT];

	this->pData->ppTextureArrays[RocketFlyData::FIRE] = new TextureArray(RESOURCE_SPRITE, "RocketFly", "", 5, 4);
	this->pData->ppTextureArrays[RocketFlyData::FIRE]->setAnchorPoint(0.5f, 1);

	this->pData->ppTextureArrays[RocketFlyData::DIE] = new TextureArray(RESOURCE_SPRITE, "Destruction", "", 6, 6);
	this->pData->ppTextureArrays[RocketFlyData::DIE]->setAnchorPoint(0.5f, 1); 

	this->pData->body = RectF(-pData->ppTextureArrays[RocketFlyData::FIRE]->getWidth() / 2, -pData->ppTextureArrays[RocketFlyData::FIRE]->getHeight(), pData->ppTextureArrays[RocketFlyData::FIRE]->getWidth(), pData->ppTextureArrays[RocketFlyData::FIRE]->getHeight());

	this->pData->x = this->pData->respawnX;
	this->pData->y = this->pData->respawnY;


	this->pData->pState = new RocketFlyState(this->pData);
}

void RocketFlySprite::setCollisionRect(CollisionRectF rect)
{
}

void RocketFlySprite::onCameraCollision(RectF cameraRect)
{
	if (this->pData->dir.isLeft())
	{
		if (this->pData->x <= cameraRect.x)
		{
			this->pData->isDesTroyed = true;
		}
	}
}

RocketFlySprite::~RocketFlySprite()
{
}
