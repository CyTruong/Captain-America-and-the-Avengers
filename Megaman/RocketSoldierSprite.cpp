#include "RocketSoldierSprite.h"
//#include "BlueSoldierSitState.h"
#include "RocketSoldierShootState.h"
//#include "BlueSoldierJumpingState.h"

RocketSoldierSprite::RocketSoldierSprite(float x, float y, Direction dir, bool isShoter, std::vector<BulletSprite*>& bullet)
{
	if (isShoter) {
		this->pData = new RocketSoldierData(bullet);
	}
	else
	{
		this->pData = new RocketSoldierData();
	}

	this->pData->isDead = false;
	this->pData->isDesTroyed = false;
	this->pData->dir = dir;
	this->pData->isHittable = true;
	this->pData->HP = 2;
	this->pData->isShooter = true;
	this->pData->respawnX = x;
	this->pData->respawnY = y;


	this->pData->ppTextureArrays = new TextureArray*[RocketSoldierData::COUNT];
	//Nếu muốn thêm cái Recfs thì thêm trong SingelGData
	this->pData->ppTextureArrays[RocketSoldierData::SIT] = new TextureArray(RESOURCE_SPRITE, "RocketSoldier", "Sitting", 1, 10);
	this->pData->ppTextureArrays[RocketSoldierData::SIT]->setAnchorPoint(0.5f, 1.0f);
	this->pData->ppTextureArrays[RocketSoldierData::RUN] = new TextureArray(RESOURCE_SPRITE, "RocketSoldier", "Running", 3, 5);
	this->pData->ppTextureArrays[RocketSoldierData::RUN]->setAnchorPoint(0.5f, 1.0f); 
	this->pData->ppTextureArrays[RocketSoldierData::SHOOT] = new TextureArray(RESOURCE_SPRITE, "RocketSoldier", "StandShoot", 1, 80);
	this->pData->ppTextureArrays[RocketSoldierData::SHOOT]->setAnchorPoint(0.5f, 1.0f);
	this->pData->ppTextureArrays[RocketSoldierData::DIE] = new TextureArray(RESOURCE_SPRITE, "RocketSoldier", "Death", 1, 10);
	this->pData->ppTextureArrays[RocketSoldierData::DIE]->setAnchorPoint(0.5f, 1.0f);

	this->pData->body = RectF(-pData->ppTextureArrays[RocketSoldierData::SHOOT]->getWidth() / 2, -pData->ppTextureArrays[RocketSoldierData::SHOOT]->getHeight(), pData->ppTextureArrays[RocketSoldierData::SHOOT]->getWidth(), pData->ppTextureArrays[RocketSoldierData::SHOOT]->getHeight());

	this->pData->x = this->pData->respawnX;
	this->pData->y = this->pData->respawnY;

	//this->pData->pState = new BlueSoldierStandState(this->pData);
	this->pData->pState = new RocketSoldierShootState(this->pData);

}

void RocketSoldierSprite::setCollisionRect(CollisionRectF crect)
{

}

void RocketSoldierSprite::onCameraCollision(RectF cameraRect)
{
	/*if ((cameraRect.x + cameraRect.width) - this->pData->x  <= BlueSoldier_TURN_RANGE)
	{
		if (this->pData->dir.isRight())
			this->pData->dir = Direction::createLeft();
	}*/


	if (this->pData->x <= cameraRect.x)
	{
		this->pData->isDesTroyed = true;
	}


}



RocketSoldierSprite::~RocketSoldierSprite()
{
}