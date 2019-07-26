#include "ZuliaSprite.h"
#include "ZuliaNormalFlyState.h"


ZuliaSprite::ZuliaSprite(float x, float y,Direction dir, std::vector<BulletSprite*>& bullet)
{
	this->pData = new ZuliaData(bullet);
	this->pData->isDead = false;
	this->pData->isDesTroyed = false;
	this->pData->dir = dir;
	this->pData->isHittable = true;
	this->pData->HP = 50;
	this->pData->isShooter = true;
	this->pData->respawnX = x;
	this->pData->respawnY = y;

	this->pData->ppTextureArrays = new TextureArray*[ZuliaData::ZuliaAniIndex::ANICOUNT];

	this->pData->ppTextureArrays[ZuliaData::ZuliaAniIndex::NORMALFLY] = new TextureArray(RESOURCE_SPRITE, "Zulia", "Normal", 1, 500);
	this->pData->ppTextureArrays[ZuliaData::ZuliaAniIndex::NORMALFLY]->setAnchorPoint(0.5f,0.5f);
	this->pData->ppTextureArrays[ZuliaData::ZuliaAniIndex::SHOOT] = new TextureArray(RESOURCE_SPRITE, "Zulia", "Shoot", 5, 10);
	this->pData->ppTextureArrays[ZuliaData::ZuliaAniIndex::SHOOT]->setAnchorPoint(0.5f, 0.5f);
	this->pData->ppTextureArrays[ZuliaData::ZuliaAniIndex::STING] = new TextureArray(RESOURCE_SPRITE, "Zulia", "Sting", 12, 5);
	this->pData->ppTextureArrays[ZuliaData::ZuliaAniIndex::STING]->setAnchorPoint(0.5f, 0.5f);
	this->pData->ppTextureArrays[ZuliaData::ZuliaAniIndex::AIM] = new TextureArray(RESOURCE_SPRITE, "Zulia", "Aim", 4, 15);
	this->pData->ppTextureArrays[ZuliaData::ZuliaAniIndex::AIM]->setAnchorPoint(0.5f, 0.5f);
	this->pData->ppTextureArrays[ZuliaData::ZuliaAniIndex::WINGS] = new TextureArray(RESOURCE_SPRITE, "Zulia", "Wing", 3, 8);
	this->pData->ppTextureArrays[ZuliaData::ZuliaAniIndex::WINGS]->setAnchorPoint(0.5f, 0.5f);

	this->pData->ppTextureArrays[ZuliaData::ZuliaAniIndex::DIE] = new TextureArray(RESOURCE_SPRITE, "Zulia", "Dead", 1, 40);
	this->pData->ppTextureArrays[ZuliaData::ZuliaAniIndex::DIE]->setAnchorPoint(0.5f, 0.5f);

	this->pData->body = RectF(-20, -20, 40, 40);

	this->pData->x = this->pData->respawnX;
	this->pData->y = this->pData->respawnY;

	RectF Range = RectF(7673, 1718, 215, 146);

	this->pData->pState = new ZuliaNormalFlyState(this->pData, Range.x +20 , Range.y + 20  , Range ,ZuliaData::ZuliaMechIndex::STING_PLAYER);

	Sound::getInstance()->play("Boss",true,10);
	Sound::getInstance()->setVolume(50, "Boss");;
} 

void ZuliaSprite::setCollisionRect(CollisionRectF rect)
{
}

void ZuliaSprite::draw(Camera * cam)
{
	
	LogWriter::getInstance()->write(this->pData->x, this->pData->y);

	pData->ppTextureArrays[ZuliaData::WINGS]->draw(pData->x, pData->y - 30, cam);

	if (UIComponents::getInstance()->isTargeting()) {
		pData->ppTextureArrays[ZuliaData::AIM]->draw(pData->Megaman_X, pData->Megaman_Y+5, cam);
		pData->ppTextureArrays[ZuliaData::AIM]->update();
	}

	if (pData->Megaman_X < this->pData->x)
	{

		pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
	}
	else
	{
		pData->ppTextureArrays[pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
	}

	for (int i = 0; i < pData->bulletsVector.size(); i++)
	{
		pData->bulletsVector[i]->draw(cam);
	}
}

ZuliaSprite::~ZuliaSprite()
{
}
