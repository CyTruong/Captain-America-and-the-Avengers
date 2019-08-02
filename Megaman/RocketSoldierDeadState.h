#pragma once
#include "EnemyState.h"
class RocketSoldierDeadState :
	public EnemyState
{
public:
	RocketSoldierDeadState(EnemyData *pData);
	void onUpdate();
	~RocketSoldierDeadState();
};
