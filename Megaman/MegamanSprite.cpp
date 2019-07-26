#include "MegamanSprite.h"

MegamanSprite::MegamanSprite(float respawnX, float respawnY, Direction movedir) 
{
	this->pData = new MegamanData();
	this->pData->bodyRects = new RectF[MegamanData::COUNT];
	this->pData->x = respawnX;
	this->pData->y = respawnY;
	this->pData->movedir = movedir;
	this->pData->ppTextureArrays = new TextureArray*[MegamanData::COUNT];
	
	
	this->pData->ppTextureArrays[MegamanData::STAND] = new TextureArray(RESOURCE_SPRITE, "Captain", "Stand", 1, 12);
	this->pData->ppTextureArrays[MegamanData::STAND]->setAnchorPoint(0.5f, 1);
	this->pData->bodyRects[MegamanData::STAND] = RectF(-11.0f , -45 , 22, 45 );

	this->pData->ppTextureArrays[MegamanData::STANDSHOOT] = new TextureArray(RESOURCE_SPRITE, "Captain", "ThrowSheild", 3, 5);
	this->pData->ppTextureArrays[MegamanData::STANDSHOOT]->setAnchorPoint(0.5f, 1);
	this->pData->bodyRects[MegamanData::STANDSHOOT] = RectF(-17.0f, -36.0f, 35, 35);

	this->pData->ppTextureArrays[MegamanData::RUN] = new TextureArray(RESOURCE_SPRITE, "Captain", "Run", 4, 5);
	this->pData->ppTextureArrays[MegamanData::RUN]->setAnchorPoint(0.5f,1);
	this->pData->bodyRects[MegamanData::RUN] = RectF(-11.0f, -45, 22, 45);
	
	this->pData->ppTextureArrays[MegamanData::RUNSHOOT] = new TextureArray(RESOURCE_SPRITE, "Captain", "ThrowSheild", 3, 3);
	this->pData->ppTextureArrays[MegamanData::RUNSHOOT]->setAnchorPoint(0.5f, 0.8f);
	this->pData->bodyRects[MegamanData::RUNSHOOT] = RectF(-17.0f, -30.0f, 35, 35);

	this->pData->ppTextureArrays[MegamanData::JUMP] = new TextureArray(RESOURCE_SPRITE, "Captain", "Jump", 8, 23);
	this->pData->ppTextureArrays[MegamanData::JUMP]->setAnchorPoint(0.5f, 1);
	this->pData->bodyRects[MegamanData::JUMP] = RectF(-13, -47, 32, 47);

	this->pData->ppTextureArrays[MegamanData::JUMPSHOOT] = new TextureArray(RESOURCE_SPRITE, "Captain", "JumpKick", 1, 10);
	this->pData->ppTextureArrays[MegamanData::JUMPSHOOT]->setAnchorPoint(0.5f, 0.8f);
	this->pData->bodyRects[MegamanData::JUMPSHOOT] = RectF(-17, -43, 41, 43);

	this->pData->ppTextureArrays[MegamanData::FALL] = new TextureArray(RESOURCE_SPRITE, "Captain", "Fall", 1, 10);
	this->pData->ppTextureArrays[MegamanData::FALL]->setAnchorPoint(0.5f, 1);
	this->pData->bodyRects[MegamanData::FALL] = RectF(-13, -41, 32, 47);

	this->pData->ppTextureArrays[MegamanData::FALLSHOOT] = new TextureArray(RESOURCE_SPRITE, "Captain", "JumpKick", 1, 10);
	this->pData->ppTextureArrays[MegamanData::FALLSHOOT]->setAnchorPoint(0.5f, 0.8f);
	this->pData->bodyRects[MegamanData::FALLSHOOT] = RectF(-17, -41, 41, 47);

	this->pData->ppTextureArrays[MegamanData::SLIDE] = new TextureArray(RESOURCE_SPRITE, "Captain", "Slide", 5,6);
	this->pData->ppTextureArrays[MegamanData::SLIDE]->setAnchorPoint(0.5f, 1);
	this->pData->bodyRects[MegamanData::SLIDE] = RectF(-20, -35, 44, 35);

	//this->pData->ppTextureArrays[MegamanData::SLIDESHOOT] = new TextureArray(RESOURCE_SPRITE, "Megaman", "Slide_Shoot", 5, 10);
	//this->pData->ppTextureArrays[MegamanData::SLIDESHOOT]->setAnchorPoint(0.5f, 0.8f);
	//this->pData->bodyRects[MegamanData::SLIDESHOOT] = RectF(-26, -30, 48, 35);

	//this->pData->ppTextureArrays[MegamanData::WALLSLIDE] = new TextureArray(RESOURCE_SPRITE, "Megaman", "Wallslide", 2, 20);
	//this->pData->ppTextureArrays[MegamanData::WALLSLIDE]->setAnchorPoint(0.3f, 0.8f);
	//this->pData->bodyRects[MegamanData::WALLSLIDE] = RectF(-12, -30, 22, 35);
	//
	//this->pData->ppTextureArrays[MegamanData::WALLSLIDESHOOT] = new TextureArray(RESOURCE_SPRITE, "Megaman", "Wallslide_Shoot", 2, 20);
	//this->pData->ppTextureArrays[MegamanData::WALLSLIDESHOOT]->setAnchorPoint(0.5f,0.8f);
	//this->pData->bodyRects[MegamanData::WALLSLIDESHOOT] = RectF(-11, -30, 32, 35);

	//this->pData->ppTextureArrays[MegamanData::START] = new TextureArray(RESOURCE_SPRITE, "Megaman", "Start", 7, 40);
	//this->pData->ppTextureArrays[MegamanData::START]->setAnchorPoint(0.5f, 0.8f);
	////hcmt 
	//this->pData->bodyRects[MegamanData::START] = RectF(0, -0, 1, 1);
	////this->pData->bodyRects[MegamanData::START] = RectF(-15.0f, -30, 35, 35);

	//this->pData->ppTextureArrays[MegamanData::DEAD] = new TextureArray(RESOURCE_SPRITE, "Megaman", "Destroy", 2, 20);
	//this->pData->ppTextureArrays[MegamanData::DEAD]->setAnchorPoint(0.5f, 1.0f);
	//this->pData->bodyRects[MegamanData::DEAD] = RectF(0, -0, 1, 1);

	//this->pData->ppTextureArrays[MegamanData::DAMAGED] = new TextureArray(RESOURCE_SPRITE, "Megaman", "Damaged", 2, 60);
	//this->pData->ppTextureArrays[MegamanData::DAMAGED]->setAnchorPoint(0.5f, 0.8f);
	//this->pData->bodyRects[MegamanData::DAMAGED] = RectF(0, -0, 1, 1);

	//this->pData->ppTextureArrays[MegamanData::SIT] = new TextureArray(RESOURCE_SPRITE,"Captain","Sitting",1,10);
	//this->pData->ppTextureArrays[MegamanData::SIT]->setAnchorPoint(0.5f, 1);
	//this->pData->bodyRects[MegamanData::SIT] = RectF(-11, -27, 22, 27);

	//this->pData->ppTextureArrays[MegamanData::NOCHARGE] = new TextureArray(RESOURCE_SPRITE, "Megaman", "NoCharge", 1, 4);
	//this->pData->ppTextureArrays[MegamanData::NOCHARGE]->setAnchorPoint(0.5f, 0.8f);
	//this->pData->bodyRects[MegamanData::NOCHARGE] = RectF(-25, -55, 55, 55);

	//this->pData->ppTextureArrays[MegamanData::CHARGING1] = new TextureArray(RESOURCE_SPRITE, "Megaman", "Charge0", 10, 4);
	//this->pData->ppTextureArrays[MegamanData::CHARGING1]->setAnchorPoint(0.5f, 0.8f);
	//this->pData->bodyRects[MegamanData::CHARGING1] = RectF(-25, -55, 55, 55);

	//this->pData->ppTextureArrays[MegamanData::CHARGING2] = new TextureArray(RESOURCE_SPRITE, "Megaman", "Charge1", 10, 4);
	//this->pData->ppTextureArrays[MegamanData::CHARGING2]->setAnchorPoint(0.5f, 0.8f);
	//this->pData->bodyRects[MegamanData::CHARGING2] = RectF(-25, -55, 55, 55);

	//this->pData->ppTextureArrays[MegamanData::CHARGING3] = new TextureArray(RESOURCE_SPRITE, "Megaman", "Charge2", 10, 4);
	//this->pData->ppTextureArrays[MegamanData::CHARGING3]->setAnchorPoint(0.5f, 1.0f);
	//this->pData->bodyRects[MegamanData::CHARGING3] = RectF(-25, -55, 55, 55);

	this->pData->dir = Direction::createRight();
	this->pData->verticalDir = Direction::createNone();
	CaptainSheildSprite *sheildbullet = new CaptainSheildSprite(0, 0, 0, 4.5, 0);
	this->pData->Bullets.push_back(sheildbullet);
	this->pData->pState = new MegamanJumpState(this->pData,false,4);
}

MegamanSprite::~MegamanSprite()
{
	//cmt
}

void MegamanSprite::update()
{
	pData->pState->onUpdate();
	for (int i = 0; i < pData->Bullets.size(); i++)
	{
		if (!pData->Bullets[i]->isDesTroyed()) {
			pData->Bullets[i]->update();
		}
	}

}

void MegamanSprite::draw(Camera * cam)
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
	for (int i = 0; i < pData->Bullets.size(); i++)
	{
		if (!pData->Bullets[i]->isDesTroyed()) {
			pData->Bullets[i]->draw(cam);
		}
	}


}

void MegamanSprite::setCameraTo(Camera * cam)
{
	cam->setPosition(this->pData->x, this->pData->y);
}

void MegamanSprite::loadResources()
{
}

void MegamanSprite::updateThroughRect()
{
}

void MegamanSprite::die()
{
}

void MegamanSprite::onCameraCollision(RectF cameraRect)
{
}

int MegamanSprite::getDamage()
{
	return 0;
}

void MegamanSprite::setCameraRect(RectF r)
{
	pData->cameraRect = r;
}
