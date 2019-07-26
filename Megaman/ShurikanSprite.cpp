#include "ShurikanSprite.h"
#include "ShurikanStartState.h"


ShurikanSprite::ShurikanSprite(float x, float y)
{
	this->pData = new ShurikanData();
	this->pData->isDead = false;
	this->pData->isDesTroyed = false;
	this->pData->isHittable = true;
	
	this->pData->HP = 5;
	UIComponents::getInstance()->setShurikanHp(this->pData->HP); 


	this->pData->isShooter = true;
	this->pData->respawnX = x;
	this->pData->respawnY = y;
	if (this->pData->Megaman_X > x) {
		this->pData->dir = Direction::createRight();
	}
	else
		this->pData->dir = Direction::createLeft();

	this->pData->ppTextureArrays = new TextureArray*[ShurikanData::ANI_COUNT];
	
	this->pData->ppTextureArrays[ShurikanData::SurikenAniIndex::BOUNCE_START] = new TextureArray(RESOURCE_SPRITE, "Shuriken", "Bounce", 30, 2);
	this->pData->ppTextureArrays[ShurikanData::SurikenAniIndex::BOUNCE_START]->setAnchorPoint(0.5f, 0.5f);
	this->pData->ppTextureArrays[ShurikanData::SurikenAniIndex::BOUNCE_RUN] = new TextureArray(RESOURCE_SPRITE, "Shuriken", "BounceRun", 19, 1);
	this->pData->ppTextureArrays[ShurikanData::SurikenAniIndex::BOUNCE_RUN]->setAnchorPoint(0.5f, 0.5f);
	this->pData->ppTextureArrays[ShurikanData::SurikenAniIndex::START] = new TextureArray(RESOURCE_SPRITE, "Shuriken", "Spin", 61, 3);
	this->pData->ppTextureArrays[ShurikanData::SurikenAniIndex::START]->setAnchorPoint(0.5f, 0.5f);
	this->pData->ppTextureArrays[ShurikanData::SurikenAniIndex::WALLSPIN] = new TextureArray(RESOURCE_SPRITE, "Shuriken", "WallSpin", 3, 2);
	this->pData->ppTextureArrays[ShurikanData::SurikenAniIndex::WALLSPIN]->setAnchorPoint(0.5f, 0.5f);
	this->pData->ppTextureArrays[ShurikanData::SurikenAniIndex::SPIN] = new TextureArray(RESOURCE_SPRITE, "Shuriken", "Spin_Attack", 10, 1);
	this->pData->ppTextureArrays[ShurikanData::SurikenAniIndex::SPIN]->setAnchorPoint(0.5f, 0.5f);
	
	this->pData->ppTextureArrays[ShurikanData::SurikenAniIndex::DIE] = new TextureArray(RESOURCE_SPRITE, "Shuriken", "Dead", 1, 30);
	this->pData->ppTextureArrays[ShurikanData::SurikenAniIndex::DIE]->setAnchorPoint(0.5f, 0.5f);

	this->pData->body = RectF(-pData->ppTextureArrays[ShurikanData::SurikenAniIndex::SPIN]->getWidth() / 2, -pData->ppTextureArrays[ShurikanData::SurikenAniIndex::SPIN]->getHeight() /2 , pData->ppTextureArrays[ShurikanData::SurikenAniIndex::SPIN]->getWidth(), pData->ppTextureArrays[ShurikanData::SurikenAniIndex::SPIN]->getHeight());

	this->pData->x = this->pData->respawnX;
	this->pData->y = this->pData->respawnY;

	this->pData->pState = new ShurikanStartState(this->pData);
}

void ShurikanSprite::setCollisionRect(CollisionRectF rect)
{
}

void ShurikanSprite::onCameraCollision(RectF cameraRect)
{
}




ShurikanSprite::~ShurikanSprite()
{
}
