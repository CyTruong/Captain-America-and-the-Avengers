#pragma once

#include "SpriteState.h"
#include "EnemyData.h"

class EnemyState : public SpriteState
{
public:
	EnemyState() {}

	virtual void onUpdate()
	{
		pData->ppTextureArrays[pData->iCurrentArr]->update();
	}

	virtual void transition(SpriteState* state)
	{
		pData->pState = state;
		delete this;
	}
	

	virtual void onCollision() {}
protected:
	EnemyData* pData;
};