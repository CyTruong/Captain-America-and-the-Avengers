#pragma once
#include "EnemyState.h"
class BoxDeadState :
	public EnemyState
{
public:
	BoxDeadState(EnemyData *pData);
	void onUpdate();
	~BoxDeadState();
};

