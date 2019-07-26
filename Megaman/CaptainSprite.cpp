#include "CaptainSprite.h"

CaptainSprite::CaptainSprite(float respawnX, float respawnY, Direction movedir)
{
	this->pData = new CaptainData();
	this->pData->bodyRects = new RectF[CaptainData::COUNT];
	this->pData->x = respawnX;
	this->pData->y = respawnY;
	this->pData->movedir = movedir;
	this->pData->ppTextureArrays = new TextureArray*[CaptainData::COUNT];


	this->pData->ppTextureArrays[CaptainData::STAND] = new TextureArray(RESOURCE_SPRITE, "Captain", "Stand", 1, 12);
	this->pData->ppTextureArrays[CaptainData::STAND]->setAnchorPoint(0.5f, 1);
	this->pData->bodyRects[CaptainData::STAND] = RectF(-11, -45, 22, 45);

	//this->pData->ppTextureArrays[CaptainData::STANDSHOOT] = new TextureArray(RESOURCE_SPRITE, "Captain", "Stand_Shoot", 2, 5);
	//this->pData->ppTextureArrays[CaptainData::STANDSHOOT]->setAnchorPoint(0.5f, 0.8f);
	//this->pData->bodyRects[CaptainData::STANDSHOOT] = RectF(-15.0f, -30, 35, 35);

	this->pData->ppTextureArrays[CaptainData::RUN] = new TextureArray(RESOURCE_SPRITE, "Captain", "Run", 4, 3);
	this->pData->ppTextureArrays[CaptainData::RUN]->setAnchorPoint(0.5f, 1);
	this->pData->bodyRects[CaptainData::RUN] = RectF(-12.0f, -44, 24, 44);

	//this->pData->ppTextureArrays[CaptainData::RUNSHOOT] = new TextureArray(RESOURCE_SPRITE, "Captain", "Run_Shoot", 10, 3);
	//this->pData->ppTextureArrays[CaptainData::RUNSHOOT]->setAnchorPoint(0.5f, 0.8f);
	//this->pData->bodyRects[CaptainData::RUNSHOOT] = RectF(-14, -33, 39, 36);

	//this->pData->ppTextureArrays[CaptainData::JUMP] = new TextureArray(RESOURCE_SPRITE, "Captain", "Jump", 7, 10);
	//this->pData->ppTextureArrays[CaptainData::JUMP]->setAnchorPoint(0.5f, 0.8f);
	//this->pData->bodyRects[CaptainData::JUMP] = RectF(-13, -41, 32, 47);

	//this->pData->ppTextureArrays[CaptainData::JUMPSHOOT] = new TextureArray(RESOURCE_SPRITE, "Captain", "Jump_Shoot", 7, 10);
	//this->pData->ppTextureArrays[CaptainData::JUMPSHOOT]->setAnchorPoint(0.5f, 0.8f);
	//this->pData->bodyRects[CaptainData::JUMPSHOOT] = RectF(-17, -43, 41, 43);

	//this->pData->ppTextureArrays[CaptainData::FALL] = new TextureArray(RESOURCE_SPRITE, "Captain", "Fall", 1, 10);
	//this->pData->ppTextureArrays[CaptainData::FALL]->setAnchorPoint(0.5f, 0.8f);
	//this->pData->bodyRects[CaptainData::FALL] = RectF(-13, -41, 32, 47);

	//this->pData->ppTextureArrays[CaptainData::FALLSHOOT] = new TextureArray(RESOURCE_SPRITE, "Captain", "Fall_Shoot", 1, 10);
	//this->pData->ppTextureArrays[CaptainData::FALLSHOOT]->setAnchorPoint(0.5f, 0.8f);
	//this->pData->bodyRects[CaptainData::FALLSHOOT] = RectF(-17, -41, 41, 47);

	//this->pData->ppTextureArrays[CaptainData::SLIDE] = new TextureArray(RESOURCE_SPRITE, "Captain", "Slide", 5, 6);
	//this->pData->ppTextureArrays[CaptainData::SLIDE]->setAnchorPoint(0.5f, 0.8f);
	//this->pData->bodyRects[CaptainData::SLIDE] = RectF(-16.0f, -47, 37, 30);

	//this->pData->ppTextureArrays[CaptainData::SLIDESHOOT] = new TextureArray(RESOURCE_SPRITE, "Captain", "Slide_Shoot", 5, 10);
	//this->pData->ppTextureArrays[CaptainData::SLIDESHOOT]->setAnchorPoint(0.5f, 0.8f);
	//this->pData->bodyRects[CaptainData::SLIDESHOOT] = RectF(-16.0f, -47, 37, 30);

	//this->pData->ppTextureArrays[CaptainData::WALLSLIDE] = new TextureArray(RESOURCE_SPRITE, "Captain", "Wallslide", 2, 20);
	//this->pData->ppTextureArrays[CaptainData::WALLSLIDE]->setAnchorPoint(0.3f, 0.8f);
	//this->pData->bodyRects[CaptainData::WALLSLIDE] = RectF(-12, -30, 22, 35);

	//this->pData->ppTextureArrays[CaptainData::WALLSLIDESHOOT] = new TextureArray(RESOURCE_SPRITE, "Captain", "Wallslide_Shoot", 2, 20);
	//this->pData->ppTextureArrays[CaptainData::WALLSLIDESHOOT]->setAnchorPoint(0.3f, 0.8f);
	//this->pData->bodyRects[CaptainData::WALLSLIDESHOOT] = RectF(-12, -30, 22, 35);

	//this->pData->ppTextureArrays[CaptainData::START] = new TextureArray(RESOURCE_SPRITE, "Captain", "Start", 7, 40);
	//this->pData->ppTextureArrays[CaptainData::START]->setAnchorPoint(0.5f, 0.8f);
	////hcmt 
	//this->pData->bodyRects[CaptainData::START] = RectF(0, -0, 1, 1);
	////this->pData->bodyRects[CaptainData::START] = RectF(-15.0f, -30, 35, 35);

	//this->pData->ppTextureArrays[CaptainData::DEAD] = new TextureArray(RESOURCE_SPRITE, "Captain", "Destroy", 2, 20);
	//this->pData->ppTextureArrays[CaptainData::DEAD]->setAnchorPoint(0.5f, 1.0f);
	//this->pData->bodyRects[CaptainData::DEAD] = RectF(0, -0, 1, 1);

	//this->pData->ppTextureArrays[CaptainData::DAMAGED] = new TextureArray(RESOURCE_SPRITE, "Captain", "Damaged", 2, 60);
	//this->pData->ppTextureArrays[CaptainData::DAMAGED]->setAnchorPoint(0.5f, 0.8f);
	//this->pData->bodyRects[CaptainData::DAMAGED] = RectF(0, -0, 1, 1);

	//this->pData->ppTextureArrays[CaptainData::NOCHARGE] = new TextureArray(RESOURCE_SPRITE, "Captain", "NoCharge", 1, 4);
	//this->pData->ppTextureArrays[CaptainData::NOCHARGE]->setAnchorPoint(0.5f, 0.8f);
	//this->pData->bodyRects[CaptainData::NOCHARGE] = RectF(-25, -55, 55, 55);

	//this->pData->ppTextureArrays[CaptainData::CHARGING1] = new TextureArray(RESOURCE_SPRITE, "Captain", "Charge0", 10, 4);
	//this->pData->ppTextureArrays[CaptainData::CHARGING1]->setAnchorPoint(0.5f, 0.8f);
	//this->pData->bodyRects[CaptainData::CHARGING1] = RectF(-25, -55, 55, 55);

	//this->pData->ppTextureArrays[CaptainData::CHARGING2] = new TextureArray(RESOURCE_SPRITE, "Captain", "Charge1", 10, 4);
	//this->pData->ppTextureArrays[CaptainData::CHARGING2]->setAnchorPoint(0.5f, 0.8f);
	//this->pData->bodyRects[CaptainData::CHARGING2] = RectF(-25, -55, 55, 55);

	//this->pData->ppTextureArrays[CaptainData::CHARGING3] = new TextureArray(RESOURCE_SPRITE, "Captain", "Charge2", 10, 4);
	//this->pData->ppTextureArrays[CaptainData::CHARGING3]->setAnchorPoint(0.5f, 1.0f);
	//this->pData->bodyRects[CaptainData::CHARGING3] = RectF(-25, -55, 55, 55);

	this->pData->dir = Direction::createRight();
	this->pData->verticalDir = Direction::createNone();
	this->pData->pState = new CaptainStandingState(this->pData);
}

CaptainSprite::~CaptainSprite()
{
	//cmt
}

void CaptainSprite::update()
{
	pData->pState->onUpdate();
	/*
	for (int i = 0; i < pData->Bullets.size(); i++)
	{
		if (!pData->Bullets[i]->isDesTroyed()) {
			pData->Bullets[i]->update();
		}
	}
	*/
}

void CaptainSprite::draw(Camera * cam)
{
	int isdraw = 1;
	if (pData->isUndying) {
		isdraw = rand() % 2;
	}

	if (isdraw)
	{

		if (pData->dir.isRight())
			pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
		else if (pData->dir.isLeft())
			pData->ppTextureArrays[pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);

		if (pData->isCharging) {
			pData->ppTextureArrays[pData->bulletSize]->draw(pData->x, pData->y + pData->body.width / 2, cam);
		}


	}
	//Draw nền đỏ
/*	if (pData->dir.isRight())
		pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam, 1.0f, 1.0f, D3DCOLOR_ARGB(255, 255, 0, 60));
	else if (pData->dir.isLeft())
		pData->ppTextureArrays[pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam, 1.0f, 1.0f, D3DCOLOR_ARGB(255, 255, 0, 60));*/
	
	//Draw đạn 20/7
	/*for (int i = 0; i < pData->Bullets.size(); i++)
	{
		if (!pData->Bullets[i]->isDesTroyed()) {
			pData->Bullets[i]->draw(cam);
		}
	}
	*/


}

void CaptainSprite::setCameraTo(Camera * cam)
{
	cam->setPosition(this->pData->x, this->pData->y);
}

void CaptainSprite::loadResources()
{
}

void CaptainSprite::updateThroughRect()
{
}

void CaptainSprite::die()
{
}

void CaptainSprite::onCameraCollision(RectF cameraRect)
{
}

int CaptainSprite::getDamage()
{
	return 0;
}

void CaptainSprite::setCameraRect(RectF r)
{
	pData->cameraRect = r;
}
