#include "CaptainSheildSprite.h"
#include "CaptainSheildMovingState.h"
#include <math.h>

CaptainSheildSprite::CaptainSheildSprite(int size, float x, float y, float speed, float angle)
{

	this->bulletSize = this->ConvertSizeIndex(size);
	this->pData = new CaptainSheildData();
	this->pData->isDesTroyed = false;
	this->pData->ppTextureArrays = new TextureArray*[CaptainSheildData::COUNT];
	this->pData->bodyRects = new RectF[CaptainSheildData::COUNT];

	UIComponents::getInstance()->setisSheildFlying(false);

	this->angle = angle;

	//if (bulletSize == BulletSize::SMALL) {

		Sound::getInstance()->play("MgmBulletNormalSFire", false, 1);

		this->pData->ppTextureArrays[CaptainSheildData::FLY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "CaptainSheild_fly", 1, 500);
		this->pData->ppTextureArrays[CaptainSheildData::FLY]->setAnchorPoint(0.5f, 0.5f);
		this->pData->bodyRects[CaptainSheildData::FLY] = RectF(-pData->ppTextureArrays[CaptainSheildData::FLY]->getWidth() / 2, -pData->ppTextureArrays[CaptainSheildData::FLY]->getHeight(), pData->ppTextureArrays[CaptainSheildData::FLY]->getWidth(), pData->ppTextureArrays[CaptainSheildData::FLY]->getHeight());

		this->pData->ppTextureArrays[CaptainSheildData::DESTROY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "MgmNormalS_des", 1, 500);
		this->pData->ppTextureArrays[CaptainSheildData::DESTROY]->setAnchorPoint(0.5f, 0.5f);
		this->pData->bodyRects[CaptainSheildData::DESTROY] = RectF(-pData->ppTextureArrays[CaptainSheildData::DESTROY]->getWidth() / 2, -pData->ppTextureArrays[CaptainSheildData::DESTROY]->getHeight(), pData->ppTextureArrays[CaptainSheildData::DESTROY]->getWidth(), pData->ppTextureArrays[CaptainSheildData::DESTROY]->getHeight());
	
		this->pData->ppTextureArrays[CaptainSheildData::HOLD] = new TextureArray(RESOURCE_SPRITE, "Bullet", "CaptainSheild_fly", 1, 500);
		this->pData->ppTextureArrays[CaptainSheildData::HOLD]->setAnchorPoint(0.5f, 0.5f);
		this->pData->bodyRects[CaptainSheildData::HOLD] = RectF(-pData->ppTextureArrays[CaptainSheildData::FLY]->getWidth() / 2, -pData->ppTextureArrays[CaptainSheildData::HOLD]->getHeight(), pData->ppTextureArrays[CaptainSheildData::HOLD]->getWidth(), pData->ppTextureArrays[CaptainSheildData::HOLD]->getHeight());

	//}
	/*if (bulletSize == BulletSize::MEDIUM) {

		Sound::getInstance()->play("MgmBulletNormalMFire", false, 1);

		this->pData->ppTextureArrays[CaptainSheildData::FLY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "MgmNormalM_fly", 2, 2);
		this->pData->ppTextureArrays[CaptainSheildData::FLY]->setAnchorPoint(0.5f, 0.5f);
		this->pData->bodyRects[CaptainSheildData::FLY] = RectF(-pData->ppTextureArrays[CaptainSheildData::FLY]->getWidth() / 2, -pData->ppTextureArrays[CaptainSheildData::FLY]->getHeight(), pData->ppTextureArrays[CaptainSheildData::FLY]->getWidth(), pData->ppTextureArrays[CaptainSheildData::FLY]->getHeight());

		this->pData->ppTextureArrays[CaptainSheildData::DESTROY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "MgmNormalM_des", 1, 500);
		this->pData->ppTextureArrays[CaptainSheildData::DESTROY]->setAnchorPoint(0.5f, 0.5f);
		this->pData->bodyRects[CaptainSheildData::DESTROY] = RectF(-pData->ppTextureArrays[CaptainSheildData::DESTROY]->getWidth() / 2, -pData->ppTextureArrays[CaptainSheildData::DESTROY]->getHeight(), pData->ppTextureArrays[CaptainSheildData::DESTROY]->getWidth(), pData->ppTextureArrays[CaptainSheildData::DESTROY]->getHeight());
	}
	if (bulletSize == BulletSize::LARGE) {

		Sound::getInstance()->play("MgmBulletNormalLFire", false, 1);

		this->pData->ppTextureArrays[CaptainSheildData::FLY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "MgmNormalL_fly", 5, 2);
		this->pData->ppTextureArrays[CaptainSheildData::FLY]->setAnchorPoint(0.5f, 0.5f);
		this->pData->bodyRects[CaptainSheildData::FLY] = RectF(-pData->ppTextureArrays[CaptainSheildData::FLY]->getWidth() / 2, -pData->ppTextureArrays[CaptainSheildData::FLY]->getHeight(), pData->ppTextureArrays[CaptainSheildData::FLY]->getWidth(), pData->ppTextureArrays[CaptainSheildData::FLY]->getHeight());

		this->pData->ppTextureArrays[CaptainSheildData::DESTROY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "MgmNormalL_des", 1, 500);
		this->pData->ppTextureArrays[CaptainSheildData::DESTROY]->setAnchorPoint(0.5f, 0.5f);
		this->pData->bodyRects[CaptainSheildData::DESTROY] = RectF(-pData->ppTextureArrays[CaptainSheildData::DESTROY]->getWidth() / 2, -pData->ppTextureArrays[CaptainSheildData::DESTROY]->getHeight(), pData->ppTextureArrays[CaptainSheildData::DESTROY]->getWidth(), pData->ppTextureArrays[CaptainSheildData::DESTROY]->getHeight());
	}
*/

	pData->x = x;
	pData->y = y;


	pData->pState = new CaptainSheildMovingState(pData, speed, angle, CaptainSheildData::HOLD);

	//lưu ý dòng này để link con trỏ datat đến bullet sprite
	BulletSprite::pData = pData;

}

void CaptainSheildSprite::draw(Camera * cam)
{
	if (abs(angle - M_PI) < 0.0001) {
		pData->ppTextureArrays[this->pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
	}
	else
		pData->ppTextureArrays[this->pData->iCurrentArr]->draw(pData->x, pData->y, cam);

}

void CaptainSheildSprite::update()
{
	pData->pState->onUpdate();

}

void CaptainSheildSprite::Trigger(int index)
{
	if (index==1)
	{
		this->pData->dir = Direction::createRight();
	}
	else
	{
		this->pData->dir = Direction::createLeft();
	}
	this->pData->iCurrentArr = CaptainSheildData::FLY;
}

CaptainSheildSprite::~CaptainSheildSprite()
{
}
