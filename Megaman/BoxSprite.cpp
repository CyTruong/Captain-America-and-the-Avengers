#include "BoxSprite.h"
#include "BoxState.h"
#include"BoxData.h"

BoxSprite::BoxSprite(float x, float y, Direction dir, bool isShoter, std::vector<BulletSprite*>& bullet)
{
	if (isShoter) {
		this->pData = new BoxData(bullet);
	}
	else
	{
		this->pData = new BoxData();
	}

	this->pData->isDead = false;
	this->pData->isDesTroyed = false;
	this->pData->dir = dir;
	this->pData->isHittable = true;
	this->pData->HP = 3;
	this->pData->isShooter = true;
	this->pData->respawnX = x;
	this->pData->respawnY = y;

	this->pData->ppTextureArrays = new TextureArray*[BoxData::COUNT];

	this->pData->ppTextureArrays[BoxData::PRESENT] = new TextureArray(RESOURCE_SPRITE, "Box", "", 1, 10);
	this->pData->ppTextureArrays[BoxData::PRESENT]->setAnchorPoint(0.0f, 0);

	this->pData->ppTextureArrays[BoxData::DIE] = new TextureArray(RESOURCE_SPRITE, "Destruction", "", 6, 6);
	this->pData->ppTextureArrays[BoxData::DIE]->setAnchorPoint(0.0f, 0);

	this->pData->body = RectF(0, 0,- pData->ppTextureArrays[BoxData::PRESENT]->getWidth(), pData->ppTextureArrays[BoxData::PRESENT]->getHeight());

	this->pData->x = this->pData->respawnX;
	this->pData->y = this->pData->respawnY;


	this->pData->pState = new BoxState(this->pData);
}

void BoxSprite::setCollisionRect(CollisionRectF rect)
{
}

void BoxSprite::onCameraCollision(RectF cameraRect)
{
	if (this->pData->dir.isLeft())
	{
		if (this->pData->x <= cameraRect.x)
		{
			//this->pData->isDesTroyed = true;
		}
	}
}

BoxSprite::~BoxSprite()
{
}
