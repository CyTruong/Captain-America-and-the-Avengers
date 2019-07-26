#pragma once
#pragma once
#include "Sprite.h"
#include "CaptainState.h"
#include "CaptainStandingState.h"
#include "define.h"

#include "Sound.h"

class CaptainSprite : public Sprite {

public:
	CaptainSprite(float respawnX, float respawnY, Direction movedir);
	~CaptainSprite();
	virtual void update();
	virtual void draw(Camera* cam);
	virtual void damaged() {

		Sound::getInstance()->play("MgmTakeDameged", false, 1);
		this->pData->pState->damaged();

	};
	void setCameraTo(Camera* cam);
	virtual SpriteState* getState()
	{
		return pData->pState;
	}
	virtual RectF getBody() { return pData->getBody(); }
	virtual void setBody(RectF r) { pData->body = r; }

	/*virtual std::vector<BulletSprite* >& getBullets() {
		return this->pData->Bullets;
	};*/
	virtual float getVx() { return pData->vx; }
	virtual float getVy() { return pData->vy; }
	virtual float getX() { return pData->x; }
	virtual float getY() { return pData->y; }
	//hcmt 
	virtual Direction getMoveDir() { return pData->movedir; }

	virtual float getCenterX() { return pData->x; }
	virtual float getCenterY() { return pData->y - pData->ppTextureArrays[pData->iCurrentArr]->getHeight() / 2; }

	virtual void onUnsupported() { pData->pState->onFall(); }
	virtual void onCollision(RectF r) { pData->pState->onCollision(r); }
	virtual void onCollision(CollisionRectF r) { pData->pState->onCollision(r); }
	virtual void onDynamicObjectCollision(CollisionRectF* r) { pData->pState->onDynamicObjectCollision(r); }
	virtual void setSupportCollisionRect(CollisionRectF rect)
	{
		pData->cSupportRect = rect;
	}
	virtual void setSupportCollisionRect(CollisionRectF* rect)
	{
		pData->cDynamicSupportRect = rect;
	}
	virtual void updateThroughRect();
	virtual void die();
	virtual void onCameraCollision(RectF cameraRect);
	virtual bool isDesTroyed() { return pData->isDesTroyed; }
	virtual bool isHittable() { return pData->isHittable; }
	virtual int getDamage();

	void setCameraRect(RectF r);

	static void loadResources();

	bool isUndying()
	{
		return pData->isUndying;
	}

private:
	CaptainData* pData;
};