#include "MgmNormalBulletSprite.h"
#include "MgmNormalBulletMovingState.h"
#include <math.h>

MgmNormalBulletSprite::MgmNormalBulletSprite(int size, float x, float y, float speed, float angle)
{

	this->bulletSize = this->ConvertSizeIndex(size);
	this->pData = new MgmNormalBulletData();
	this->pData->isDesTroyed = false;
	this->pData->ppTextureArrays = new TextureArray*[MgmNormalBulletData::COUNT ];
	this->pData->bodyRects = new RectF[MegamanData::COUNT];

	this->angle = angle;

	if (bulletSize == BulletSize::SMALL) {

		Sound::getInstance()->play("MgmBulletNormalSFire", false, 1);

		this->pData->ppTextureArrays[MgmNormalBulletData::FLY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "MgmNormalS_fly", 1, 500);
		this->pData->ppTextureArrays[MgmNormalBulletData::FLY]->setAnchorPoint(0.5f, 0.5f);
		this->pData->bodyRects[MgmNormalBulletData::FLY] = RectF(-pData->ppTextureArrays[MgmNormalBulletData::FLY]->getWidth() / 2, -pData->ppTextureArrays[MgmNormalBulletData::FLY]->getHeight(), pData->ppTextureArrays[MgmNormalBulletData::FLY]->getWidth(), pData->ppTextureArrays[MgmNormalBulletData::FLY]->getHeight());

		this->pData->ppTextureArrays[MgmNormalBulletData::DESTROY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "MgmNormalS_des", 1, 500);
		this->pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->setAnchorPoint(0.5f, 0.5f);
		this->pData->bodyRects[MgmNormalBulletData::DESTROY] = RectF(-pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getWidth() / 2, -pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getHeight(), pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getWidth(), pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getHeight());
	}
	if (bulletSize == BulletSize::MEDIUM) {

		Sound::getInstance()->play("MgmBulletNormalMFire", false, 1);
			
		this->pData->ppTextureArrays[MgmNormalBulletData::FLY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "MgmNormalM_fly", 2, 2);
		this->pData->ppTextureArrays[MgmNormalBulletData::FLY]->setAnchorPoint(0.5f, 0.5f);
		this->pData->bodyRects[MgmNormalBulletData::FLY] = RectF(-pData->ppTextureArrays[MgmNormalBulletData::FLY]->getWidth() / 2, -pData->ppTextureArrays[MgmNormalBulletData::FLY]->getHeight(), pData->ppTextureArrays[MgmNormalBulletData::FLY]->getWidth(), pData->ppTextureArrays[MgmNormalBulletData::FLY]->getHeight());

		this->pData->ppTextureArrays[MgmNormalBulletData::DESTROY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "MgmNormalM_des", 1, 500);
		this->pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->setAnchorPoint(0.5f, 0.5f);
		this->pData->bodyRects[MgmNormalBulletData::DESTROY] = RectF(-pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getWidth() / 2, -pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getHeight(), pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getWidth(), pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getHeight());
	}
	if (bulletSize == BulletSize::LARGE) {

		Sound::getInstance()->play("MgmBulletNormalLFire", false, 1);

		this->pData->ppTextureArrays[MgmNormalBulletData::FLY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "MgmNormalL_fly", 5, 2);
		this->pData->ppTextureArrays[MgmNormalBulletData::FLY]->setAnchorPoint(0.5f, 0.5f);
		this->pData->bodyRects[MgmNormalBulletData::FLY] = RectF(-pData->ppTextureArrays[MgmNormalBulletData::FLY]->getWidth() / 2, -pData->ppTextureArrays[MgmNormalBulletData::FLY]->getHeight(), pData->ppTextureArrays[MgmNormalBulletData::FLY]->getWidth(), pData->ppTextureArrays[MgmNormalBulletData::FLY]->getHeight());

		this->pData->ppTextureArrays[MgmNormalBulletData::DESTROY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "MgmNormalL_des", 1, 500);
		this->pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->setAnchorPoint(0.5f, 0.5f);
		this->pData->bodyRects[MgmNormalBulletData::DESTROY] = RectF(-pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getWidth() / 2, -pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getHeight(), pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getWidth(), pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getHeight());
	}

	
	pData->x = x;
	pData->y = y;


	pData->pState = new MgmNormalBulletMovingState(pData, speed ,angle, MgmNormalBulletData::FLY);

	//lưu ý dòng này để link con trỏ datat đến bullet sprite
	BulletSprite::pData = pData;

}

void MgmNormalBulletSprite::draw(Camera * cam)
{
	if (abs( angle - M_PI) < 0.0001) {
		pData->ppTextureArrays[this->pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
	}
	else
		pData->ppTextureArrays[this->pData->iCurrentArr]->draw(pData->x, pData->y, cam);

}

void MgmNormalBulletSprite::update()
{
	pData->pState->onUpdate();

}

MgmNormalBulletSprite::~MgmNormalBulletSprite()
{
}
