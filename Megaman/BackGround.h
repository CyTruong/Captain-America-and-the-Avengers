#pragma once
#include "Sprite.h"
#include "MegamanSprite.h"

#define BG_WIDTH 512
#define BG_HEIGHT 256
#define REDUCTION 2

class BackGround : public Sprite 
{
private:
	MegamanSprite * megamanSprite;
public:
	BackGround(MegamanSprite * megamansprite) 
	{
		this->pData = new SpriteData();
		this->megamanSprite = megamansprite;
		this->pData->ppTextureArrays = new TextureArray*[1];
		this->pData->ppTextureArrays[0] = new  TextureArray(RESOURCE_SPRITE, "BG", "2", 5, 5);
		this->pData->ppTextureArrays[0]->setAnchorPoint(0, 0);
	}

	void update() override
	{
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	}
	void draw(Camera* cam) override 
	{
		int x = (int)(this->megamanSprite->getX() / REDUCTION) % BG_WIDTH;
		int y = (int)(this->megamanSprite->getY() / REDUCTION / 1.5) % BG_HEIGHT;
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->draw(cam->getX(), cam->getY(), cam);
	}
	

};