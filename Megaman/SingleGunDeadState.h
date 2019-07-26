#pragma once
#include "EnemyState.h"
class SingleGunDeadState :
	public EnemyState
{
public:
	SingleGunDeadState(EnemyData *pData);
	void onUpdate();
	~SingleGunDeadState();
};

