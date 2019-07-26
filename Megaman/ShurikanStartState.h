#pragma once
#include "EnemyState.h"
#include "ShurikanData.h"

class ShurikanStartState :
	public EnemyState
{
public:
	ShurikanStartState(EnemyData* pData);
	void onUpdate();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void onDead() override; 

	~ShurikanStartState();
};

