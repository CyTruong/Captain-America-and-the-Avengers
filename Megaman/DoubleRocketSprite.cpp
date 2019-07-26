#include "DoubleRocketSprite.h"
#include "DoubleRocketFireState.h"


DoubleRocketSprite::DoubleRocketSprite(float x, float y, Direction dir, bool isShoter, std::vector<BulletSprite*>& bullet)
{
	if (isShoter) {
		this->pData = new DoubleRocketData(bullet);
	}
	else
	{
		this->pData = new DoubleRocketData();
	}

	this->pData->isDead = false;
	this->pData->isDesTroyed = false;
	this->pData->dir = dir;
	this->pData->isHittable = true;
	this->pData->HP = 2;
	this->pData->isShooter = true;
	this->pData->respawnX = x;
	this->pData->respawnY = y;

	this->pData->ppTextureArrays = new TextureArray*[DoubleRocketData::COUNT];

	this->pData->ppTextureArrays[DoubleRocketData::FIRE_TOP] = new TextureArray(RESOURCE_SPRITE, "DoubleRocket", "Top", 4, 5);
	this->pData->ppTextureArrays[DoubleRocketData::FIRE_TOP]->setAnchorPoint(0.5f, 1);
	this->pData->ppTextureArrays[DoubleRocketData::FIRE_BOT] = new TextureArray(RESOURCE_SPRITE, "DoubleRocket", "Bot", 3, 5);
	this->pData->ppTextureArrays[DoubleRocketData::FIRE_BOT]->setAnchorPoint(0.5f, 1);

	this->pData->ppTextureArrays[DoubleRocketData::DIE] = new TextureArray(RESOURCE_SPRITE, "Destruction", "", 6, 6);
	this->pData->ppTextureArrays[DoubleRocketData::DIE]->setAnchorPoint(0.5f, 1);

	this->pData->body = RectF(-pData->ppTextureArrays[DoubleRocketData::FIRE_TOP]->getWidth() / 2, -pData->ppTextureArrays[DoubleRocketData::FIRE_BOT]->getHeight(), pData->ppTextureArrays[DoubleRocketData::FIRE_BOT]->getWidth(), pData->ppTextureArrays[DoubleRocketData::FIRE_BOT]->getHeight());

	this->pData->x = this->pData->respawnX;
	this->pData->y = this->pData->respawnY;

	this->pData->pState = new DoubleRocketFireState(this->pData);
}

void DoubleRocketSprite::setCollisionRect(CollisionRectF rect)
{
}

void DoubleRocketSprite::onCameraCollision(RectF cameraRect)
{
	if (this->pData->dir.isLeft())
	{
		if (this->pData->x <= cameraRect.x)
		{
			this->pData->isDesTroyed = true;
		}
	}
}

DoubleRocketSprite::~DoubleRocketSprite()
{
}
