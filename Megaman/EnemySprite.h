#pragma once
#include "EnemyData.h"
#include "BulletSprite.h"
#include "Sprite.h"

class EnemySprite : public Sprite
{

protected:
	EnemyData* pData;

public:
	EnemySprite()
	{
		pData = new EnemyData();
	}
	EnemySprite(std::vector < BulletSprite* >& bulletsVector)
	{
		pData = new EnemyData(bulletsVector);
	}

	virtual ~EnemySprite() {}
	virtual RectF getBody() { return pData->getBody(); }
	virtual void setBody(RectF r) { pData->body = r; }
	/*virtual RectF getLastFrameBody() {return pData ->getLastFrameBody();}*/
	virtual float getVx() { return pData->vx; }
	virtual float getVy() { return pData->vy; }
//hcmt 	virtual void onUnsupported() { pData->pState->onFall(); }
	virtual void setPlayerX(int x) { pData->Megaman_X = x; }
	virtual void setPlayerY(int y) { pData->Megaman_Y = y; }
	virtual void setPlayerProperties(float x, float y, bool isDead)
	{
		pData->Megaman_X = x;
		pData->Megaman_Y = y;
		pData->isPlayerDead = isDead;
	}

	virtual void onCollision(RectF r) { pData->pState->onCollision(r); }
	virtual void onCollision(CollisionRectF r) { pData->pState->onCollision(r); }
	virtual SpriteState* getState() { return this->pData->pState; } 

	virtual void update()
	{
		
		for (int i = 0; i < pData->bulletsVector.size(); i++)
		{
			if (pData->bulletsVector[i]->isDesTroyed()) {
				pData->bulletsVector.erase(pData->bulletsVector.begin() + i);
				continue;
			}
			pData->bulletsVector[i]->update();
		}

		pData->pState->onUpdate();
	}

	virtual void draw(Camera *cam)
	{
		if (pData->dir.isRight())
		{
			
			pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
		}
		else
		{
			if (pData->dir.isLeft())
				pData->ppTextureArrays[pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
		}

		for (int i = 0; i < pData->bulletsVector.size(); i++)
		{
			pData->bulletsVector[i]->draw(cam);
		}
	}

	virtual void onUpdate() {}
	virtual void die() {
		pData->pState->onDead(); 
	}
	virtual bool isDesTroyed() { return pData->isDesTroyed; }
	virtual bool isHittable() { return pData->isHittable; }
	virtual void setSupportCollisionRect(CollisionRectF rect)
	{
		pData->cSupportRect = rect;
	}
	virtual std::vector< CollisionRectF >&  getThroughRect()
	{
		return pData->cThroughRect;
	}
	virtual void updateThroughRect()
	{
		for (int i = 0; i < pData->cThroughRect.size(); i++)
		{
			if (!pData->getBody().checkCollision(pData->cThroughRect[i].rect))
			{
				pData->cThroughRect.erase(pData->cThroughRect.begin() + i);
			}
		}
	}
	virtual void playBeShootedEffect()
	{

	}
	virtual bool isThroughable()
	{
		return pData->isThrougable;
	}
	virtual void onCameraCollision(RectF cameraRect)
	{
	/*	if (!pData->getBody().checkCollision(cameraRect))
			pData->isDesTroyed = true;*/
	}
	virtual int getScore()
	{
		return pData->score;
	}
	virtual void beShooted(int damage)
	{
		pData->HP -= damage;
		if (pData->HP <= 0)
		{
			die();
		}
	}
	virtual bool isDead()
	{
		return pData->isDead;
	}
	virtual Direction getAppearDir()
	{
		return pData->appearDir;
	}
	virtual vector < BulletSprite* > getBullets() {
		return  pData->bulletsVector;
	}

};