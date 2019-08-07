#include "BlueSoldierBulletSprite.h"
#include "BlueSoldierBulletMovingState.h"
#include <math.h>

BlueSoldierBulletSprite::BlueSoldierBulletSprite( float x, float y, float speed, float angle)
{

	//this->bulletSize = this->ConvertSizeIndex(size);
	this->pData = new BlueSoldierBulletData();
	BulletSprite::pData = pData;
	this->pData->isDesTroyed = false; 
	this->pData->ppTextureArrays = new TextureArray*[BlueSoldierBulletData::COUNT];
	this->speed = speed;
	this->angle = angle;


	  //	Sound::getInstance()->play("MgmBulletNormalSFire", false, 1);

		this->pData->ppTextureArrays[BlueSoldierBulletData::FLY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "BlueSoldierNormal", 1, 10);
		this->pData->ppTextureArrays[BlueSoldierBulletData::FLY]->setAnchorPoint(0.5f, 0.5f);
		this->pData->body = RectF(-pData->ppTextureArrays[BlueSoldierBulletData::FLY]->getWidth() / 2, -pData->ppTextureArrays[BlueSoldierBulletData::FLY]->getHeight(), pData->ppTextureArrays[BlueSoldierBulletData::FLY]->getWidth(), pData->ppTextureArrays[BlueSoldierBulletData::FLY]->getHeight());

		this->pData->ppTextureArrays[BlueSoldierBulletData::DESTROY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "BlueSoldierNormaldes", 1, 10);
		this->pData->ppTextureArrays[BlueSoldierBulletData::DESTROY]->setAnchorPoint(0.5f, 0.5f);
		//this->pData->bodyRects[BlueSoldierBulletData::DESTROY] = RectF(-pData->ppTextureArrays[BlueSoldierBulletData::DESTROY]->getWidth() / 2, -pData->ppTextureArrays[BlueSoldierBulletData::DESTROY]->getHeight(), pData->ppTextureArrays[BlueSoldierBulletData::DESTROY]->getWidth(), pData->ppTextureArrays[BlueSoldierBulletData::DESTROY]->getHeight());
	
		

	pData->x = x;
	pData->y = y;


	pData->pState = new BlueSoldierBulletMovingState(pData, speed, angle, BlueSoldierBulletData::FLY);

	//lưu ý dòng này để link con trỏ datat đến bullet sprite
	//

}

void BlueSoldierBulletSprite::draw(Camera * cam)
{
	/*if (abs(angle - M_PI) < 0.0001) {
		pData->ppTextureArrays[this->pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
	}
	else*/
		pData->ppTextureArrays[this->pData->iCurrentArr]->draw(pData->x, pData->y, cam);

}

void BlueSoldierBulletSprite::update()
{
	pData->pState->onUpdate();

}

void BlueSoldierBulletSprite::Trigger(int index)
{
	if (this->pData->vx != 0 ) {
		this->pData->vy = -this->speed;
		this->pData->vx = -0.1;
	}
}

BlueSoldierBulletSprite::~BlueSoldierBulletSprite()
{

}
