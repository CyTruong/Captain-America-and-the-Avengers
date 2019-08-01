#pragma once
#include "EnemyState.h"
class BlueSoldierDeadState :
	public EnemyState
{
public:
	BlueSoldierDeadState(EnemyData *pData);
	void onUpdate();
	~BlueSoldierDeadState();
};

