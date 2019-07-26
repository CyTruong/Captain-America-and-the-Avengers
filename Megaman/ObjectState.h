#pragma once
#include "SpriteState.h"
#include "ObjectData.h"
#include  "Object.h"
 class ObjectState : public SpriteState
{
protected:
	ObjectData* pData;

public:
	ObjectState(void) {};
		
	virtual void onUpdate() {};
	virtual void onCollision(RectF rect) {};
	virtual void onCollision(CollisionRectF rect) {};
	virtual void onCollision(Object obj ) {};


	void transition(SpriteState* state)
	{
		pData->pState = state;
		delete this;
	};
	 ~ObjectState() {};
};

