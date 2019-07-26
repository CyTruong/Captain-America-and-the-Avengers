#pragma once
#include "EnemyState.h"
class DoubleRocketDeadState :
	public EnemyState
{
public:
	DoubleRocketDeadState(EnemyData *pData);
	void onUpdate();
	~DoubleRocketDeadState();
};

