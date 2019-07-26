#include "SingleGunSprite.h"
#include "SingleGunStandState.h"
#include "SingleGunJumpingState.h"

SingleGunSprite::SingleGunSprite(float x, float y, Direction dir, bool isShoter, std::vector<BulletSprite*>& bullet)
{
	if (isShoter) {
		this->pData = new SingleGunData(bullet);
	}
	else
	{
		this->pData = new SingleGunData();
	}
	
	this->pData->isDead = false;
	this->pData->isDesTroyed = false;
	this->pData->dir = dir;
	this->pData->isHittable = true;
	this->pData->HP = 2;
	this->pData->isShooter = true;
	this->pData->respawnX = x;
	this->pData->respawnY = y;


	this->pData->ppTextureArrays = new TextureArray*[SingleGunData::COUNT];
	//Nếu muốn thêm cái Recfs thì thêm trong SingelGData
	this->pData->ppTextureArrays[SingleGunData::STAND] = new TextureArray(RESOURCE_SPRITE, "SingleGun", "Stand",1, 20);
	this->pData->ppTextureArrays[SingleGunData::STAND]->setAnchorPoint(0.5f, 1.0f);
	this->pData->ppTextureArrays[SingleGunData::JUMP] = new TextureArray(RESOURCE_SPRITE, "SingleGun", "Jump", 4, 20);
	this->pData->ppTextureArrays[SingleGunData::JUMP]->setAnchorPoint(0.5f, 1.0f);
	this->pData->ppTextureArrays[SingleGunData::FIRE] = new TextureArray(RESOURCE_SPRITE, "SingleGun", "Fire", 4, 15);
	this->pData->ppTextureArrays[SingleGunData::FIRE]->setAnchorPoint(0.5f, 1.0f);
	this->pData->ppTextureArrays[SingleGunData::DIE] = new TextureArray(RESOURCE_SPRITE, "Destruction", "", 6, 6);
	this->pData->ppTextureArrays[SingleGunData::DIE]->setAnchorPoint(0.5f, 1.0f);

	this->pData->body = RectF(-pData->ppTextureArrays[SingleGunData::STAND]->getWidth() / 2 , -pData->ppTextureArrays[SingleGunData::STAND]->getHeight(), pData->ppTextureArrays[SingleGunData::STAND]->getWidth(), pData->ppTextureArrays[SingleGunData::STAND]->getHeight());

	this->pData->x = this->pData->respawnX;
	this->pData->y = this->pData->respawnY;

	this->pData->pState = new SingleGunStandState(this->pData);

}

void SingleGunSprite::setCollisionRect(CollisionRectF crect)
{

}

void SingleGunSprite::onCameraCollision(RectF cameraRect)
{
	/*if ((cameraRect.x + cameraRect.width) - this->pData->x  <= SINGLEGUN_TURN_RANGE)
	{
		if (this->pData->dir.isRight())
			this->pData->dir = Direction::createLeft();
	}*/

	
		if (this->pData->x <= cameraRect.x)
		{
			this->pData->isDesTroyed = true;
		}
	



}



SingleGunSprite::~SingleGunSprite()
{
}
