#include "DoubleRocketNormalBulletSprite.h"
#include "DoubleRocketNormalBulletData.h"
#include "DoubleRocketNormalBulletMovingState.h"

DoubleRocketNormalBulletSprite::DoubleRocketNormalBulletSprite(float x, float y, float angle)
{
	this->pData = new DoubleRocketNormalBulletData();
	BulletSprite::pData = pData;
	this->pData->isDesTroyed = false;

	this->pData->ppTextureArrays = new TextureArray*[DoubleRocketNormalBulletData::COUNT];
	this->angle = angle;

	this->pData->ppTextureArrays[DoubleRocketNormalBulletData::FLY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "DoubleRocket_fly",  2,2);
	this->pData->ppTextureArrays[DoubleRocketNormalBulletData::FLY]->setAnchorPoint(0.5f, 0.5f);

	this->pData->ppTextureArrays[DoubleRocketNormalBulletData::DESTROY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "Dust", 6, 3);
	this->pData->ppTextureArrays[DoubleRocketNormalBulletData::DESTROY]->setAnchorPoint(0.5f, 0.5f);
	this->pData->x = x;
	this->pData->y = y;

	this->pData->pState = new DoubleRocketNormalBulletMovingState(this->pData, 2, angle);
}

void DoubleRocketNormalBulletSprite::draw(Camera * cam)
{
	if (angle < M_PI_4) {
		pData->ppTextureArrays[this->pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
	}
	else
		pData->ppTextureArrays[this->pData->iCurrentArr]->draw(pData->x, pData->y, cam);

}

void DoubleRocketNormalBulletSprite::update()
{
	pData->pState->onUpdate();
}

DoubleRocketNormalBulletSprite::~DoubleRocketNormalBulletSprite()
{
}
