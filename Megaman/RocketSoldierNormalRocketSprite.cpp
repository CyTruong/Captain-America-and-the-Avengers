#include "RocketSoldierNormalRocketSprite.h"
#include "RocketSoldierNormalRocketMovingState.h"

RocketSoldierNormalRocketSprite::RocketSoldierNormalRocketSprite(float x, float y)
{
	this->pData = new RocketSoldierNormalRocketData();
	BulletSprite::pData = pData;
	this->pData->isDesTroyed = false;
	this->pData->ppTextureArrays = new TextureArray*[RocketSoldierNormalRocketData::COUNT];


	//Sound::getInstance()->play("SingleGunFire", false, 1);

	this->pData->ppTextureArrays[RocketSoldierNormalRocketData::FLY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "Rocket_fly", 2, 5);
	this->pData->ppTextureArrays[RocketSoldierNormalRocketData::FLY]->setAnchorPoint(0.5f, 0.5f);

	this->pData->ppTextureArrays[RocketSoldierNormalRocketData::DESTROY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "Zulia_des", 7, 4);
	this->pData->ppTextureArrays[RocketSoldierNormalRocketData::DESTROY]->setAnchorPoint(0.5f, 0.5f);


	//body

	this->pData->x = x;
	this->pData->y = y;

	this->pData->pState = new RocketSoldierNormalRocketMovingState(this->pData, 1.0f);

}

void RocketSoldierNormalRocketSprite::draw(Camera * cam)
{
	pData->ppTextureArrays[this->pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
}

void RocketSoldierNormalRocketSprite::update()
{
	pData->pState->onUpdate();

}

RocketSoldierNormalRocketSprite::~RocketSoldierNormalRocketSprite()
{
}


