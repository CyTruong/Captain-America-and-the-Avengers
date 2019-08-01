#include "BlueSoldierSprite.h"
#include "BlueSoldierSitState.h"
#include "BlueSoldierShootState.h"
//#include "BlueSoldierJumpingState.h"

BlueSoldierSprite::BlueSoldierSprite(float x, float y, Direction dir, bool isShoter, std::vector<BulletSprite*>& bullet)
{
	if (isShoter) {
		this->pData = new BlueSoldierData(bullet);
	}
	else
	{
		this->pData = new BlueSoldierData();
	}

	this->pData->isDead = false;
	this->pData->isDesTroyed = false;
	this->pData->dir = dir;
	this->pData->isHittable = true;
	this->pData->HP = 2;
	this->pData->isShooter = true;
	this->pData->respawnX = x;
	this->pData->respawnY = y;


	this->pData->ppTextureArrays = new TextureArray*[BlueSoldierData::COUNT];
	//Nếu muốn thêm cái Recfs thì thêm trong SingelGData
	this->pData->ppTextureArrays[BlueSoldierData::SIT] = new TextureArray(RESOURCE_SPRITE, "BlueSoldier", "Sit", 1, 10);
	this->pData->ppTextureArrays[BlueSoldierData::SIT]->setAnchorPoint(0.5f, 1.0f);
	this->pData->ppTextureArrays[BlueSoldierData::RUN] = new TextureArray(RESOURCE_SPRITE, "BlueSoldier", "Run", 3,	10);
	this->pData->ppTextureArrays[BlueSoldierData::RUN]->setAnchorPoint(0.5f, 1.0f);\
	this->pData->ppTextureArrays[BlueSoldierData::SHOOT] = new TextureArray(RESOURCE_SPRITE, "BlueSoldier", "StandShoot", 1, 80);
	this->pData->ppTextureArrays[BlueSoldierData::SHOOT]->setAnchorPoint(0.5f, 1.0f);
	this->pData->ppTextureArrays[BlueSoldierData::DIE] = new TextureArray(RESOURCE_SPRITE, "BlueSoldier", "Die", 7, 10);
	this->pData->ppTextureArrays[BlueSoldierData::DIE]->setAnchorPoint(0.5f, 1.0f);

	this->pData->body = RectF(-pData->ppTextureArrays[BlueSoldierData::SHOOT]->getWidth() / 2, -pData->ppTextureArrays[BlueSoldierData::SHOOT]->getHeight(), pData->ppTextureArrays[BlueSoldierData::SHOOT]->getWidth(), pData->ppTextureArrays[BlueSoldierData::SHOOT]->getHeight());

	this->pData->x = this->pData->respawnX;
	this->pData->y = this->pData->respawnY;

	//this->pData->pState = new BlueSoldierStandState(this->pData);
	this->pData->pState = new BlueSoldierShootState(this->pData);

}

void BlueSoldierSprite::setCollisionRect(CollisionRectF crect)
{

}

void BlueSoldierSprite::onCameraCollision(RectF cameraRect)
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



BlueSoldierSprite::~BlueSoldierSprite()
{
}
