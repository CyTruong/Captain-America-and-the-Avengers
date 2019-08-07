#include "HPSprite.h"
#include "ObjectState.h"


HPSprite::HPSprite()
{
	/*this->hpBar = hpBar;
	this->index = index;*/

	this->pData = new ObjectData();
	
	this->pData->ppTextureArrays = new TextureArray*[1];
	
	this->pData->ppTextureArrays[0] = new TextureArray(RESOURCE_SPRITE, "UI", "HpDotCaptain", 1,60);
	this->pData->ppTextureArrays[0]->setAnchorPoint(0.5f, 1);

	this->pData->dir = Direction::createRight();

	this->pData->pState = new ObjectState();

	/*this->pData->x = hpBar->getBody().x + index * 5;
	this->pData->y = hpBar->getBody().y + index * 5;*/
}


void HPSprite::onUpdate()
{
	/*this->pData->x = hpBar->getBody().x + index * 5;
	this->pData->y = hpBar->getBody().y + index * 5;*/
}

HPSprite::~HPSprite()
{
}
